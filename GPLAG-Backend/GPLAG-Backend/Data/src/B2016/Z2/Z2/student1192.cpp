// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <deque>
#include <vector>
#include <stdexcept>
using std:: cout;
using std:: cin;
using std :: endl;
using std :: vector;


enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};
 
template <typename kont>
auto IzdvojiDijagonale3D (kont m, SmjerKretanja s) -> typename std:: remove_reference<decltype(m[0])>::type{
   for (int i=0; i<m.size(); i++){
       if(m[i].size()!=m[0].size()) {throw std::domain_error ("Plohe nemaju isti broj redova");}
       for (int j=0; j<m[i].size(); j++) {
           if (m[i][j].size()!= m[0][0].size()) {throw std::domain_error ("Redovi nemaju isti broj elemenata");}
       }
   }
   typename std:: remove_reference<decltype(m[0])>::type n;
    int d1(0), d2(0);
    if(s== SmjerKretanja::NaprijedNazad || s==SmjerKretanja:: NazadNaprijed){
        d1= m.size();
        d2= m[0].size();
    }
    if (s==SmjerKretanja:: GoreDolje || s == SmjerKretanja::DoljeGore){
        d1= m[0].size();
        d2= m.size();
    }
    if(s== SmjerKretanja::LijevoDesno || s==SmjerKretanja::DesnoLijevo){
        d1=m[0][0].size();
        d2=m.size();
    }
    n.resize(d1);
    for( int i=0; i< d1; i++)
        n[i].resize(d2);
        
   for (int i=0; i< m.size(); i++){
       for (int j=0; j<m[0].size(); j++){
           for(int k=0; k<m[0][0].size(); k++){
               if(s==SmjerKretanja::NaprijedNazad){
                   if(j==k) n[i][j]=m[i][j][k];
               }
               if(s== SmjerKretanja::NazadNaprijed){
                   if(k==m[0][0].size()-1-j)
                   n[m.size()-1-i][j]=m[i][j][k];
               }
               if(s== SmjerKretanja::GoreDolje){
                   if(k==m.size()-1-i)
                       n[j][m.size()-1-i]=m[i][j][k];
                   
               }
               if(s==SmjerKretanja::DoljeGore){
                   if(k== m[0][0].size()-(m.size()-1-i)-1)
                   n[m[0].size()-1-j][m.size()-1-i]=m[i][j][k];
               }
               if(s==SmjerKretanja:: LijevoDesno){
                   if(j==m.size()-1-i)
                   n[k][m.size()-1-i]=m[i][j][k];
               }
               if(s== SmjerKretanja::DesnoLijevo){
                   if(j==i){
                       n[m[0][0].size()-k-1][i]=m[i][j][k];
                   }
               }
           }
       }
   }
       return n;
   
    
} 
int main ()
{
    
    cout << "Unesite dimenzije (x y z): ";
    int x, y, z;
    cin>> x >> y>> z;
    if(x<0 || y<0 || z<0) {cout << "Neispravne dimenzije kontejnera!"; return 0;}
    cout << "Unesite elemente kontejnera: " << endl;
    std::vector<std::deque<std::deque<int>>> m ;
    m.resize(x);
    for(int i=0; i<x; i++) {
        m[i].resize(y);
        for (int j=0; j<y; j++){
            m[i][j].resize(z);
        }
    }
    
    for (int i=0; i<x; i++){
        for (int j=0; j<y;j++){
            for (int k=0; k<z; k++){
                int a; 
                cin >> a;
                m[i][j][k]=a;
            }
        }
    }
     SmjerKretanja s;
    cout << "Unesite smjer kretanja [0 - 5]: ";
    int b;
    cin >> b;
    if(b<0 || b>5){ cout << "Smjer kretanja nije ispravan!" << endl; return 0;}
    
    try{
    s= SmjerKretanja(b);
    
     auto n(IzdvojiDijagonale3D(m,s));
     if (s==SmjerKretanja::NaprijedNazad) cout << "NaprijedNazad"; if(s==SmjerKretanja::NazadNaprijed) cout << "NazadNaprijed"; if (s==SmjerKretanja::GoreDolje) cout << "GoreDolje";if (s==SmjerKretanja::DoljeGore) cout << "DoljeGore";if (s==SmjerKretanja::LijevoDesno) cout << "LijevoDesno";
     if (s==SmjerKretanja::DesnoLijevo) cout << "DesnoLijevo";
     cout << ": " << endl;
    
  for (const auto &red : n)
        {
            for (const auto &x : red)
                std::cout.width (4), std::cout << x;
            std::cout << std::endl;
        }
    }
    catch (std:: domain_error e){
        cout << e.what();    }

  

	return 0;
}