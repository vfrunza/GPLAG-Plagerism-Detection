// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
#include <iomanip>
#include <stdexcept>
using namespace std;

enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };

template<typename kont>
auto IzdvojiDijagonale3D(kont kocka, SmjerKretanja smjer) -> typename remove_reference<decltype(kocka[0])>::type
{
    
    int n=kocka[0].size();
    for(int i=0; i<kocka.size(); i++) if(kocka[i].size()!=n) throw domain_error("Plohe nemaju isti broj redova");
    n=kocka[0][0].size();
    for(int i=0; i<kocka.size(); i++)
        for(int j=0; j<kocka[i].size(); j++)
            if(kocka[i][j].size()!=n) throw domain_error("Plohe nemaju isti broj elemenata");
    typedef typename remove_reference<decltype(kocka[0])>::type mat;
    typedef typename remove_reference<decltype(kocka[0][0])>::type vektor;
    mat rez;
    switch(smjer)
    {
        
        case SmjerKretanja::DesnoLijevo :
            for(int i=0; i<kocka.size(); i++)
            {
                vektor d;
                for(int j=0; j<kocka[i].size(); j++)
                    for(int k=0; k<kocka[i][j].size(); k++)
                        if(j==i) d.push_back(kocka[i][j][k]);
                rez.push_back(d);
            }
            
            break;
        
        case SmjerKretanja::LijevoDesno :
        {
            for(int i=0; i<kocka.size(); i++)
            {
                vektor d;
                for(int j=0; j<kocka[i].size(); j++)
                    for(int k=0; k<kocka[i][j].size(); k++)
                        if(i+j==kocka[i].size()-1) d.push_back(kocka[kocka.size()-1-i][kocka[i].size()-1-j][kocka[i][j].size()-1-k]);
                rez.push_back(d);
            }
            mat pom;
            pom.resize(rez[0].size());
            for(int i=0; i<pom.size(); i++) pom[i].resize(rez.size());
            for(int i=0; i<rez.size(); i++)
                for(int j=0; j<rez[i].size(); j++) pom[j][i]=rez[i][j];
            rez=pom;
            for(int i=0; i<rez.size()/2; i++)
                for(int j=0; j<rez[i].size(); j++)
                {
                    auto temp=rez[i][j];
                    rez[i][j]=rez[rez.size()-1-i][j];
                    rez[rez.size()-1-i][j]=temp;
                }
            break;
        }
        
        case SmjerKretanja::NazadNaprijed :
            for(int i=0; i<kocka.size(); i++)
            {
                vektor d;
                for(int j=0; j<kocka[i].size(); j++)
                    for(int k=0; k<kocka[i][j].size(); k++)
                        if(j+k==kocka[i][j].size()-1) d.push_back(kocka[kocka.size()-1-i][j][k]);
                rez.push_back(d);
            }
            break;
        case SmjerKretanja::NaprijedNazad :
            for(int i=0; i<kocka.size(); i++)
            {
                vektor d;
                for(int j=0; j<kocka[i].size(); j++)
                    for(int k=0; k<kocka[i][j].size(); k++)
                        if(j==k) d.push_back(kocka[i][j][k]);
                rez.push_back(d);
            }
            break;
        case SmjerKretanja::GoreDolje :
            for(int i=0; i<kocka.size(); i++)
            {
                vektor d;
                for(int j=0; j<kocka[i].size(); j++)
                    for(int k=0; k<kocka[i][j].size(); k++)
                        if(i==k) d.push_back(kocka[i][j][k]);
                rez.push_back(d);
            }
            break;
        case SmjerKretanja::DoljeGore :
            for(int i=0; i<kocka.size(); i++)
            {
                vektor d;
                for(int j=0; j<kocka[i].size(); j++)
                    for(int k=0; k<kocka[i][j].size(); k++)
                        if(i+k==kocka[i][j].size()-1) d.push_back(kocka[kocka.size()-1-i][kocka[i].size()-1-j][k]);
                rez.push_back(d);
            }
            mat pom;
            pom.resize(rez[0].size());
            for(int i=0; i<pom.size(); i++) pom[i].resize(rez.size());
            for(int i=0; i<rez.size(); i++)
                for(int j=0; j<rez[i].size(); j++) pom[j][i]=rez[i][j];
            rez=pom;
            break;
        
    }
    if(smjer==SmjerKretanja::GoreDolje)
    {
        mat pom;
            pom.resize(rez[0].size());
            for(int i=0; i<pom.size(); i++) pom[i].resize(rez.size());
            for(int i=0; i<rez.size(); i++)
                for(int j=0; j<rez[i].size(); j++) pom[j][i]=rez[i][j];
            rez=pom;
    }
    if(smjer==SmjerKretanja::DesnoLijevo)
    {
         mat pom;
            pom.resize(rez[0].size());
            for(int i=0; i<pom.size(); i++) pom[i].resize(rez.size());
            for(int i=0; i<rez.size(); i++)
                for(int j=0; j<rez[i].size(); j++) pom[j][i]=rez[i][j];
            rez=pom;
            for(int i=0; i<rez.size()/2; i++)
                for(int j=0; j<rez[i].size(); j++)
                {
                    auto temp=rez[i][j];
                    rez[i][j]=rez[rez.size()-1-i][j];
                    rez[rez.size()-1-i][j]=temp;
                }
    }
    return rez;
}

int main ()
{
	cout<<"Unesite dimenzije (x y z): ";
	int x,y,z;
	cin>>x>>y>>z;
	if(x<0 || y<0 || z<0) {cout<<"Neispravne dimenzije kontejnera!"; return 0;}
	cout<<"Unesite elemente kontejnera: ";
	vector<vector<vector<int>>> mat;
	mat.resize(x);
	for(int i=0; i<x; i++) mat[i].resize(y);
	for(int i=0; i<x; i++)
	    for(int j=0; j<y; j++) mat[i][j].resize(z);
	for(int i=0; i<x; i++)
	    for(int j=0; j<y; j++)
	        for(int k=0; k<z; k++) cin>>mat[i][j][k];
	SmjerKretanja s;
	cout<<endl<<"Unesite smjer kretanja [0 - 5]: ";
	int n; cin>>n;
	vector<vector<int>> rez;
	try
	{
	    if(n<0 || n>5) {cout<<"Smjer kretanja nije ispravan!"<<endl; return 0;}
	    if(n==0) {rez=IzdvojiDijagonale3D(mat,SmjerKretanja::NaprijedNazad); cout<<"NaprijedNazad: "<<endl;}
	    if(n==1) {rez=IzdvojiDijagonale3D(mat,SmjerKretanja::NazadNaprijed); cout<<"NazadNaprijed: "<<endl;}
	    if(n==2) {rez=IzdvojiDijagonale3D(mat,SmjerKretanja::GoreDolje); cout<<"GoreDolje: "<<endl;}
	    if(n==3) {rez=IzdvojiDijagonale3D(mat,SmjerKretanja::DoljeGore); cout<<"DoljeGore: "<<endl;}
	    if(n==4) {rez=IzdvojiDijagonale3D(mat,SmjerKretanja::LijevoDesno); cout<<"LijevoDesno: "<<endl;}
	    if(n==5) {rez=IzdvojiDijagonale3D(mat,SmjerKretanja::DesnoLijevo); cout<<"DesnoLijevo: "<<endl; }
	    for(int i=0; i<rez.size(); i++)
	    {
	        for(int j=0; j<rez[i].size(); j++)
	       {
	           cout<<setw(4)<<right<<rez[i][j];
	       }
	       cout<<endl;
	    }
 	}
	catch(domain_error d) {cout<<d.what();}
}