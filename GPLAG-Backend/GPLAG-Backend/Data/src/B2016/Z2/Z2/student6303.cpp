// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <stdexcept>
#include <type_traits>

using namespace std;

enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };

template<typename t>
t obrlati(t mat)
{
    t mat1;
    mat1.resize(mat[0].size());
    for(int i=0; i<mat1.size(); i++) mat1[i].resize(mat.size());
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat[i].size(); j++) mat1[j][i]=mat[i][j];
    return mat1;
}

template<typename t>
t duploobrlati(t mat)
{
    mat=obrlati(mat);
    for(int i=0; i<mat.size()/2; i++)
    {
        for(int j=0; j<mat[i].size(); j++)
        {
            auto pom=mat[i][j];
            mat[i][j]=mat[mat.size()-1-i][j];
            mat[mat.size()-i-1][j]=pom;
        }
    }
    return mat;
}

template<typename kont>
auto IzdvojiDijagonale3D(kont m, SmjerKretanja s) -> typename remove_reference<decltype(m[0])>::type
{
    for(int i=0; i<m.size(); i++)
    {
        for(int j=0; j<m[i].size(); j++)
        {
            if(m[i][j].size()!=m[0][0].size()) throw domain_error("Plohe nemaju isti broj elemenata");
        }
    }
    for(int i=0; i<m.size(); i++) if(m[i].size()!=m[0].size()) throw domain_error("Plohe nemaju isti broj redova");
    typename remove_reference<decltype(m[0])>::type dva;
    int br=0;
    if(s==SmjerKretanja::NaprijedNazad)
    {
        while(br!=m.size())
        {
            typename remove_reference<decltype(m[0][0])>::type pom;
            for(int j=0; j<m[br].size(); j++)
            {
                for(int k=0; k<m[br][j].size(); k++)
                {
                    if(j==k) pom.push_back(m[br][j][k]);
                }
            }
            dva.push_back(pom);
            br++;
        }
    }
    if(s==SmjerKretanja::NazadNaprijed)
    {
        while(br!=m.size())
        {
            typename remove_reference<decltype(m[0][0])>::type pom;
            for(int j=0; j<m[br].size(); j++)
            {
                for(int k=0; k<m[br][j].size(); k++)
                {
                    if(j+k==m[br][j].size()-1) pom.push_back(m[m.size()-br-1][j][k]);
                }
            }
            dva.push_back(pom);
            br++;
        }
    }
    if(s==SmjerKretanja::GoreDolje)
    {
        while(br!=m.size())
        {
            typename remove_reference<decltype(m[0][0])>::type pom;
            for(int j=0; j<m[br].size(); j++)
            {
                for(int k=0; k<m[br][j].size(); k++)
                {
                    if(br==k) pom.push_back(m[br][j][k]);
                }
            }
            dva.push_back(pom);
            br++;
        }
        dva=obrlati(dva);
    }
    if(s==SmjerKretanja::DoljeGore)
    {
        while(br!=m.size())
        {
            typename remove_reference<decltype(m[0][0])>::type pom;
            for(int j=0; j<m[br].size(); j++)
            {
                for(int k=0; k<m[br][j].size(); k++)
                {
                    if(k+br==m[br][j].size()-1) pom.push_back(m[m.size()-br-1][m[br].size()-j-1][k]);
                }
            }
            dva.push_back(pom);
            br++;
        }
        dva=obrlati(dva);
    }
    if(s==SmjerKretanja::LijevoDesno)
    {
        while(br!=m.size())
        {
            typename remove_reference<decltype(m[0][0])>::type pom;
            for(int j=0; j<m[br].size(); j++)
            {
                for(int k=0; k<m[br][j].size(); k++)
                {
                    if(j+br==m[br].size()-1) pom.push_back(m[m.size()-br-1][m[br].size()-j-1][m[br][j].size()-k-1]);
                }
            }
            dva.push_back(pom);
            br++;
        }
        dva=duploobrlati(dva);
    }
    if(s==SmjerKretanja::DesnoLijevo)
    {
        while(br!=m.size())
        {
            typename remove_reference<decltype(m[0][0])>::type pom;
            for(int j=0; j<m[br].size(); j++)
            {
                for(int k=0; k<m[br][j].size(); k++)
                {
                    if(br==j) pom.push_back(m[br][j][k]);
                }
            }
            dva.push_back(pom);
            br++;
        }
        dva=duploobrlati(dva);
    }
    return dva;
}

int main ()
{
	int x,y,z;
	cout<<"Unesite dimenzije (x y z): ";
	cin>>x>>y>>z;
	if(x<0) {cout<<"Neispravne dimenzije kontejnera!"; return 0;}
	if(y<0) {cout<<"Neispravne dimenzije kontejnera!"; return 0;}
	if(z<0) {cout<<"Neispravne dimenzije kontejnera!"; return 0;}
	deque<vector<deque<int>>> k;
	k.resize(x);
	for(int i=0; i<k.size(); i++) k[i].resize(y);
	for(int i=0; i<k.size(); i++)
	    for(int j=0; j<k[i].size(); j++) k[i][j].resize(z);
	cout<<"Unesite elemente kontejnera: "<<endl;
	for(int i=0; i<k.size(); i++)
	    for(int j=0; j<k[i].size(); j++)
	        for(int l=0; l<k[i][j].size(); l++) cin>>k[i][j][l];
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	vector<deque<int>> r;
	cin>>x;
	try
	{
	    switch(x)
	    {
	        case 0:
	            r=IzdvojiDijagonale3D(k, SmjerKretanja::NaprijedNazad);
	            cout<<"NaprijedNazad: "<<endl;
	            for(int i=0; i<r.size(); i++)
	            {
	                for(int j=0; j<r[i].size(); j++)
	                {
	                    cout<<setw(4)<<right<<r[i][j];
	                } cout<<endl;
	            }
	            break;
	        case 1:
	            r=IzdvojiDijagonale3D(k, SmjerKretanja::NazadNaprijed);
	            cout<<"NazadNaprijed: "<<endl;
	            for(int i=0; i<r.size(); i++)
	            {
	                for(int j=0; j<r[i].size(); j++)
	                {
	                    cout<<setw(4)<<right<<r[i][j];
	                } cout<<endl;
	            }
	            break;
	       case 2:
	       r=IzdvojiDijagonale3D(k, SmjerKretanja::GoreDolje);
	       cout<<"GoreDolje: "<<endl;
	            for(int i=0; i<r.size(); i++)
	            {
	                for(int j=0; j<r[i].size(); j++)
	                {
	                    cout<<setw(4)<<right<<r[i][j];
	                } cout<<endl;
	            }
	            break;
	       case 3:
	       r=IzdvojiDijagonale3D(k, SmjerKretanja::DoljeGore);
	       cout<<"DoljeGore: "<<endl;
	            for(int i=0; i<r.size(); i++)
	            {
	                for(int j=0; j<r[i].size(); j++)
	                {
	                    cout<<setw(4)<<right<<r[i][j];
	                } cout<<endl;
	            }
	            break;
	      case 4:
	      r=IzdvojiDijagonale3D(k, SmjerKretanja::LijevoDesno);
	      cout<<"LijevoDesno: "<<endl;
	            for(int i=0; i<r.size(); i++)
	            {
	                for(int j=0; j<r[i].size(); j++)
	                {
	                    cout<<setw(4)<<right<<r[i][j];
	                } cout<<endl;
	            }
	            break;
	     case 5:
	     r=IzdvojiDijagonale3D(k, SmjerKretanja::DesnoLijevo);
	     cout<<"DesnoLijevo: "<<endl;
	            for(int i=0; i<r.size(); i++)
	            {
	                for(int j=0; j<r[i].size(); j++)
	                {
	                    cout<<setw(4)<<right<<r[i][j];
	                } cout<<endl;
	            }
	            break;
	     default: cout<<"Smjer kretanja nije ispravan!"<<endl;
	    }
	    return 0;
	}
	catch(domain_error izuz) {cout<<izuz.what();}
}