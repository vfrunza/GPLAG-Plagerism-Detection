// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <type_traits>
#include <iomanip>
#include <stdexcept>

using namespace std;

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};


template<typename t>
t Rotiraj(t mat)
{ 
    t pom(mat[0].size());
    for(int i=0;i<pom.size();i++)
        pom[i].resize(mat.size());
        
    for(int i=0;i<pom.size();i++)
    {
        for(int j=0;j<pom[i].size();j++)
        {
            pom[i][j]=mat[j][i];
        }
    }
    return pom;
}

template <typename kont>
auto IzdvojiDijagonale3D(kont Kontejner,SmjerKretanja s)->typename remove_reference<decltype(Kontejner[0])>::type
{   
    
    for(int i=0;i<Kontejner.size();i++)
    {
        for(int j=0;j<Kontejner[i].size();j++)
        {
                if(Kontejner[0][0].size()!=Kontejner[i][j].size())
                    throw domain_error("Redovi nemaju isti broj elemenata! ");
        }
        if(Kontejner[0].size()!=Kontejner[i].size())
                    throw domain_error("Plohe nemaju isti broj redova! ");
    }
    
    
    typedef typename remove_reference<decltype(Kontejner[0])>::type x;
    typedef typename remove_reference<decltype(Kontejner[0][0])>::type x1;
    
    x mat;
                
                for(int i=0;i<Kontejner.size();i++)
                {   x1 v;
                    for(int j=0;j<Kontejner[i].size();j++)
                    {   
                        for(int k=0;k<Kontejner[i][j].size();k++)
                        {
                            if(s==SmjerKretanja::NaprijedNazad)
                            {
                                if(j==k) v.push_back(Kontejner[i][j][k]);
                            }
                            if(s==SmjerKretanja::NazadNaprijed)
                            {
                                if(j+k==Kontejner[i].size()) v.push_back(Kontejner[Kontejner.size()-1-i][j][k]);
                            }
                            if(s==SmjerKretanja::LijevoDesno)
                            {
                                if(i==j)
                                {
                                    v.push_back(Kontejner[Kontejner.size()-1-i][j][k]);
                                }
                                
                            }
                            if(s==SmjerKretanja::DesnoLijevo)
                            {
                                if(i+j==Kontejner.size())
                                {
                                    v.push_back(Kontejner[i][Kontejner[i].size()-1-j][Kontejner[i][j].size()-1-k]);
                                }
                            }
                            if(s==SmjerKretanja::GoreDolje)
                            {
                                if(i==k)
                                {
                                    v.push_back(Kontejner[Kontejner.size()-1-i][j][k]);
                                }
                                
                            }
                            if(s==SmjerKretanja::DoljeGore)
                            {
                                if(i+k==Kontejner[i][j].size()-1)
                                {
                                    v.push_back(Kontejner[Kontejner.size()-1-i][Kontejner[i].size()-1-j][k]);
                                }
                                
                            }
                        }
                    }
                    mat.push_back(v);
                }
           
    if(s==SmjerKretanja::GoreDolje || s==SmjerKretanja::DoljeGore || s==SmjerKretanja::LijevoDesno || s==SmjerKretanja::DesnoLijevo)
                 mat=Rotiraj(mat);   
                
    return mat;
}
template <typename t>
void Ispisi(t mat)
{
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[i].size();j++)
            cout<<setw(4)<<mat[i][j];
        cout<<endl;
    }
}
int main ()
{   
    
    cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
    cin>>x>>y>>z;
    if(x<0 || y<0 || z<0){ cout<<"Neispravne dimenzije kontejnera! "; return 0;}
    vector<deque<deque<int>>> Kont(x);
    
    for(int i=0;i<Kont.size();i++)
	    Kont[i].resize(y);
	 
	 for(int i=0;i<Kont.size();i++)
	    for(int j=0;j<Kont[i].size();j++)
	            Kont[i][j].resize(z);
	            
	  cout<<"Unesite elemente kontejnera: "<<endl;
	  for(int i=0;i<Kont.size();i++)
	    for(int j=0;j<Kont[i].size();j++)
	        for(int k=0;k<Kont[i][j].size();k++)
	            cin>>Kont[i][j][k];
	            
	  cout<<"Unesite smjer kretanja [0 - 5]: ";
      int n;
      cin>>n;
      try{
      switch(n)
      {
          case 0:cout<<"NaprijedNazad: "<<endl;Ispisi(IzdvojiDijagonale3D(Kont,SmjerKretanja::NaprijedNazad));break;
          case 1:cout<<"NazadNaprijed: "<<endl;Ispisi(IzdvojiDijagonale3D(Kont,SmjerKretanja::NazadNaprijed));break;
          case 2:cout<<"GoreDolje: "<<endl;Ispisi(IzdvojiDijagonale3D(Kont,SmjerKretanja::GoreDolje));break;
          case 3:cout<<"DoljeGore: "<<endl;Ispisi(IzdvojiDijagonale3D(Kont,SmjerKretanja::DoljeGore));break;
          case 4:cout<<"LijevoDesno: "<<endl;Ispisi(IzdvojiDijagonale3D(Kont,SmjerKretanja::LijevoDesno));break;
          case 5:cout<<"DesnoLijevo: "<<endl;Ispisi(IzdvojiDijagonale3D(Kont,SmjerKretanja::DesnoLijevo));break;
          default:cout<<"Smjer kretanja nije ispravan! "<<endl;break;
      }
      }catch(domain_error e){cout<<e.what();}
    
      
	return 0;
}