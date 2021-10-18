// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <iomanip>
#include <type_traits>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Kontejner>
auto IzdvojiDijagonale3D ( Kontejner  &kont, SmjerKretanja smjer ) -> typename std::remove_reference<decltype(kont.at(0))>::type   {
    
   for(int i(0); i<int(kont.size()); i++){
       for(int j(0); j<int(kont.at(i).size()); j++){
           if(int(kont.at(i).at(j).size())!=int(kont.at(0).at(0).size())) throw std::domain_error ("Redovi nemaju isti broj elemenata");
       }
       if(int(kont.at(i).size())!=int(kont.at(0).size()) ) throw std::domain_error ("Plohe nemaju isti broj redova");
   }
   
  int n(0);
  if(smjer==SmjerKretanja::NaprijedNazad || smjer==SmjerKretanja::NazadNaprijed){
      n=int(kont.size());
  }
  if(smjer==SmjerKretanja::GoreDolje || smjer==SmjerKretanja::DoljeGore){
      n=int(kont.at(0).size());
  }
  if(smjer==SmjerKretanja::LijevoDesno || smjer==SmjerKretanja::DesnoLijevo){
      n=int(kont.at(0).at(0).size());
  }
  typename std::remove_reference<decltype(kont.at(0))>::type d(n);
  if(smjer==SmjerKretanja::NazadNaprijed || smjer==SmjerKretanja::NaprijedNazad ){
      
      for(int i(0); i<int(kont.size()); i++){
          for(int j(0); j<int(kont.at(0).size()) && j<int(kont.at(i).at(0).size()); j++  ){
              if(smjer==SmjerKretanja::NaprijedNazad) d.at(i).push_back(kont.at(i).at(j).at(j));
              if(smjer==SmjerKretanja::NazadNaprijed) d.at(i).push_back(kont.at(int(kont.size())-1-i).at(j).at(int(kont.at(i).size())-j ) );
          }
      }
  }
  
  if(smjer==SmjerKretanja::GoreDolje || smjer==SmjerKretanja::DoljeGore){
      for(int j(0); j<int(kont.at(0).size()); j++ ){
         
          for( int i(0); i<int(kont.size()) && i<int(kont.at(0).at(0).size()); i++ ){
              if(smjer==SmjerKretanja::GoreDolje) d.at(j).push_back(kont.at(int(kont.size())-1-i ).at(j).at(i));
              if(smjer==SmjerKretanja::DoljeGore) d.at(j).push_back(kont.at(int(kont.size())-1-i).at(int(kont.at(0).size())-1-j ).at(int(kont.at(0).at(0).size())-1-i)  );
          }
      }
  }
  if(smjer==SmjerKretanja::LijevoDesno || smjer==SmjerKretanja::DesnoLijevo){
      for(int k(0); k<int(kont.at(0).at(0).size()); k++){
           for(int j(0); j<int(kont.size()) && j<(int(kont.at(0).size())); j++ ){
              if(smjer==SmjerKretanja::LijevoDesno) d.at(k).push_back( kont.at(int(kont.size())-1-j).at(j).at(k) );
              if(smjer==SmjerKretanja::DesnoLijevo) d.at(k).push_back( kont.at(j).at(j).at( int(kont.at(0).at(0).size())-k-1 ) );
          }
      }
  }
    
    return d;
}


int main ()
{   
    try{
         
        
        std::cout<<"Unesite dimenzije (x y z): ";
        int x, y, z;
        std::cin>>x>>y>>z;
        if(x<0 || y<0 || z<0) throw ("Neispravne dimenzije kontejnera!");
        std::vector<std::vector<std::deque<int>>> kont;
        kont.resize(x);
        for(int i(0); i<x; i++){
            kont.at(i).resize(y);
        }
        
        std::cout<<"Unesite elemente kontejnera: ";
        for(int i(0); i<x; i++){
            for(int j(0); j<y; j++){
                    
                for(int k(0); k<z; k++){
                    int n;
                    std::cin>>n;
                    kont.at(i).at(j).push_back(n);
                }
            }
        }
    
        std::cout<<std::endl<<"Unesite smjer kretanja [0 - 5]: ";
        int n;
        std::cin>>n;
        if(n<0 || n>5) throw ("Smjer kretanja nije ispravan!");
        SmjerKretanja smjer=SmjerKretanja::NaprijedNazad;
        smjer=SmjerKretanja(n);
    
        std::vector<std::string> s(6);
        s.at(0)="NaprijedNazad"; s.at(1)="NazadNaprijed"; s.at(2)="GoreDolje"; s.at(3)="DoljeGore";
        s.at(4)="LijevoDesno"; s.at(5)="DesnoLijevo";
        std::cout<<s.at(n)<<": "<<std::endl;
    
        std::vector<std::deque<int>> d(IzdvojiDijagonale3D(kont,smjer));
        
        for(int i(0); i<int(d.size()); i++){
            for(int j(0); j<int(d.at(i).size()); j++)
            std::cout<<std::setw(4)<<d.at(i).at(j);
            std::cout<<std::endl;
        }
    }
    catch(const char izuzetak[]){
        std::cout<<izuzetak<<std::endl;
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
	return 0;
}