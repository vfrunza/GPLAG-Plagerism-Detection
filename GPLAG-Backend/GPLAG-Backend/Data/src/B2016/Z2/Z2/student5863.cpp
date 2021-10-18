// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <type_traits>
#include <stdexcept>


enum class SmjerKretanja { NaprijedNazad=0, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };

template<typename kontejner>
bool ImalRedove(kontejner triD) {
    for(int i=0; i< triD.size(); i++)
        if(triD.at(0).size() != triD.at(i).size()) return false;
    
    return true;
}

template<typename kontejner>
bool ImalElemente(kontejner triD) {
    for(int i=0; i< triD.size(); i++) {
        for(int j=0; j< triD.at(i).size(); j++)
        if(triD.at(0).at(0).size() != triD.at(i).at(j).size()) return false;
    }
    return true;
}


template<typename kontejner>
 auto IzdvojiDijagonale3D(kontejner triD, SmjerKretanja smjer) -> typename std::remove_reference<decltype(triD.at(0))>::type { //ako je prazan krahhh
     if( triD.size() <=0 || triD.at(0).size() <= 0 || triD.at(0).at(0).size() <= 0 ) throw std::domain_error("Neispravne dimenzije kontejnera!");
     else if(!ImalElemente(triD)) throw std::domain_error("Redovi nemaju isti broj elemenata");
     else if(/*ImalElemente(triD) &&*/ !ImalRedove(triD)) throw std::domain_error("Plohe nemaju isti broj redova");
   
     typename std::remove_reference<decltype(triD.at(0))>::type dvaD; 
     typename std::remove_reference<decltype(triD.at(0))>::type pomocna;
     int vel=0,l=0;
     int dimenzija,red,kolona;
     
     dimenzija = triD.size();
     red = triD.at(0).size();
     kolona = triD.at(0).at(0).size();
     
     if(smjer == SmjerKretanja::NaprijedNazad) {
         for(int i=0; i < dimenzija; i++) {
            typename std::remove_reference<decltype(triD.at(0).at(0))>::type vek;
             for(int j=0; j < red; j++) {
                 for(int k=0; k < kolona; k++)
                     if(j == k) vek.push_back(triD.at(i).at(j).at(k));
             }
            dvaD.push_back(vek);
         }
     }
     else if( smjer == SmjerKretanja::NazadNaprijed) {
          for(int i=dimenzija-1; i>=0; i--) {
            typename std::remove_reference<decltype(triD.at(0).at(0))>::type vek;
             for(int j=0; j < red; j++) {
                 for(int k=0; k < kolona; k++)
                     if(j+k == red) vek.push_back(triD.at(i).at(j).at(k));
                 
             }
           dvaD.push_back(vek);
         }
         
         }
     else if(smjer == SmjerKretanja::GoreDolje) {
         vel = dimenzija -1;
         
     for(int i=dimenzija-1; i>=0; i--) {
              typename std::remove_reference<decltype(triD.at(0).at(0))>::type vek;
                     for(int k=0; k < kolona; k++) {
                     for(int j=0; j < red; j++) 
                     if(i == vel && k==l) vek.push_back(triD.at(i).at(j).at(k));
                    
             }
                     vel--;
                      l++;  
                      pomocna.push_back(vek);
                    
                    
                 
             }
             
             int l=0;
             for(int i=0; i< pomocna.at(0).size(); i++) {
                 typename std::remove_reference<decltype(pomocna.at(0))>::type vek;
                 for(int j=0; j< pomocna.size(); j++)
                 if(i == l) vek.push_back(pomocna.at(j).at(i));
                 dvaD.push_back(vek);
                 l++;
             }
             
             
            
         }
     else if(smjer ==SmjerKretanja::DoljeGore) {
             vel = dimenzija-1;
             l = kolona-1;
             for(int i= dimenzija-1; i>=0; i--) {
                typename std::remove_reference<decltype(triD.at(0).at(0))>::type vek;
                 for(int j= red-1; j>=0; j--) {
                     for(int k=kolona-1; k>=0; k--)
                     if(i ==vel && k==l) vek.push_back(triD.at(i).at(j).at(k));
                    
                 }
                     vel--;
                     l--;
                     pomocna.push_back(vek);
                 
             }
             
             l=0;
             for(int i=0; i< pomocna.at(0).size(); i++) {
                 typename std::remove_reference<decltype(pomocna.at(0))>::type vek;
                 for(int j=0; j< pomocna.size(); j++)
                 if(i == l) vek.push_back(pomocna.at(j).at(i));
                 dvaD.push_back(vek);
                 l++;
             }
          
         }
     else if(smjer == SmjerKretanja::LijevoDesno) {
         vel = dimenzija-1;
         l=0;
        
         for(int i= dimenzija-1; i>=0; i--) {
            typename std::remove_reference<decltype(triD.at(0).at(0))>::type vek;
             for(int j=0; j< red; j++) {
                 for(int k=0; k<kolona; k++)
                 if(i == vel && j == l) vek.push_back(triD.at(i).at(j).at(k));
             }
             vel--;
             l++;
             pomocna.push_back(vek);
         }
         
         l=0;
         for(int i=0; i< pomocna.at(0).size(); i++) {
             typename std::remove_reference<decltype(pomocna.at(0))>::type vek;
             for(int j=0; j< pomocna.size(); j++)
             if(i == l) vek.push_back(pomocna.at(j).at(i));
             dvaD.push_back(vek);
             l++;
         }
         
     }
     else if(smjer == SmjerKretanja::DesnoLijevo) {
         vel =0;
         l=0;
         
         for(int i=0; i< dimenzija; i++) {
            typename std::remove_reference<decltype(triD.at(0).at(0))>::type vek;
             for(int j=0; j<red; j++) {
                 for(int k=kolona-1; k>=0; k--)
                 if(i==vel && j==l) vek.push_back(triD.at(i).at(j).at(k));
         }
         vel++;
         l++;
         pomocna.push_back(vek);
     }
     l=0;
     for(int i=0; i< pomocna.at(0).size(); i++) {
         typename std::remove_reference<decltype(pomocna.at(0))>::type vek;
         for(int j=0; j< pomocna.size(); j++)
         if( i == l) vek.push_back(pomocna.at(j).at(i));
         dvaD.push_back(vek);
         l++;
     }
     }
         
     
     return dvaD;
     
 }

int main ()
{
       // std::vector<std::deque<std::deque<char>>> v ={ {{'a','b','c','d'},{'e',' ','g','h'},{'i','j','k','l'}},{{'a','b','c','d'},{'e','f','g','h'},{'i','j','k','l'}}};
     // std::deque<std::vector<std::deque<long long int>>> v ={ {{1,2,3,0},{3,-1,2,5},{4,2,1,4}},{{5,2,3,1},{3,5,3,5},{1,7,7,0}}};
    try{
   std::cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
    std::cin>>x>>y>>z;
    if( x<=0 || y<=0 || z<=0) throw std::domain_error("Neispravne dimenzije kontejnera!");
    std::cout<<"Unesite elemente kontejnera: ";
    int broj;
    std::vector<std::deque<std::deque<int>>> v;
    
  
    for(int i=0; i<x; i++) {
        std::deque<std::deque<int>> matr;
        for(int j=0; j<y; j++) {
           
          std::deque<int> red;
            for(int k=0; k<z; k++) {
                std::cin>>broj;
                red.push_back(broj);
            }
            matr.push_back(red);
        }
        v.push_back(matr);
    }

    std::cout<<std::endl<<"Unesite smjer kretanja [0 - 5]: ";
    int smjer;
   
    std::cin>>smjer;
    SmjerKretanja unos  = (SmjerKretanja)smjer;
   auto mat = IzdvojiDijagonale3D(v,unos);
     
     switch(smjer){
         case 0: std::cout<<"NaprijedNazad: "<<std::endl; break;
         case 1: std::cout << "NazadNaprijed: " << std::endl; break;
         case 2: std::cout << "GoreDolje: " << std::endl; break;
         case 3: std::cout << "DoljeGore: " << std::endl; break;
         case 4: std::cout << "LijevoDesno: " << std::endl; break;
         case 5: std::cout << "DesnoLijevo: " << std::endl; break;
        default: std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
     }
    
    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat.at(i).size(); j++) {
            std::cout.width(4);
            std::cout<<mat.at(i).at(j);
        }
            std::cout<<std::endl;
            }
    }catch(std::domain_error d) {
        std::cout << d.what() << std::endl;
    }
    catch(std::logic_error l) {
        std::cout << l.what() << std::endl;
    }
    catch(std::out_of_range o) {
        std::cout << o.what() << std::endl;
    }
    
  	return 0;
}