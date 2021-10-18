#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <type_traits>
#include <iomanip>

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

typedef std::deque<std::vector<int>> matrica;

template <typename kontejner3d>                                                      // size ,at ,push_back //
auto IzdvojiDijagonale3D (kontejner3d kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type{
    
   if(kont.size()==0||kont.at(0).size()==0 || kont.at(0).at(0).size()==0){
       typename std::remove_reference<decltype(kont.at(0))>::type kont2;
       return kont2;
   }
   
    for(int i=0;i<kont.size();i++){
     for(int j=0;j<kont.at(0).size();j++){  
        if(kont.at(i).at(j).size()!=kont.at(0).at(0).size()) throw std::domain_error ("Redovi nemaju isti broj elemenata");
    }  
    }
    for(int i=0;i<kont.size();i++){
        if(kont.at(i).size()!=kont.at(0).size()) throw std::domain_error ("Plohe nemaju isti broj redova");
    }
    
    switch(smjer){
        case SmjerKretanja::NaprijedNazad:
        {
            typename std::remove_reference<decltype(kont.at(0))>::type kont2(kont.size());
            int min;
            if(kont.at(0).size()<kont.at(0).at(0).size())
                 min=kont.at(0).size();
                else  min=kont.at(0).at(0).size();
            
            for(int i=0;i<kont.size();i++){
                for(int j=0;j<min;j++){
                    kont2.at(i).push_back(kont.at(i).at(j).at(j));
                }
                
            }
            return kont2;
    }    
       case SmjerKretanja::NazadNaprijed:{
            typename std::remove_reference<decltype(kont.at(0))>::type kont2(kont.size());
            int min;
                if(kont.at(0).size()<kont.at(0).at(0).size())
                 min=kont.at(0).size();
                else  min=kont.at(0).at(0).size();
        
            for(int i=kont.size()-1;i>=0;i--){
                for(int j=0;j<min;j++){
                    kont2.at(kont.size()-1-i).push_back(kont.at(i).at(j).at(kont.at(0).at(0).size()-1-j));
                }
                
                
            }
            return kont2;
            
       }
        case SmjerKretanja::GoreDolje:
        {
          typename std::remove_reference<decltype(kont.at(0))>::type kont2(kont.at(0).size());
            int min;
             if(kont.size()<kont.at(0).at(0).size())
                 min=kont.size();
                else  min=kont.at(0).at(0).size();
            
            
            for(int i=0;i<kont.at(0).size();i++){
                for(int j=0;j<min;j++){
                    kont2.at(i).push_back(kont.at(kont.size()-1-j).at(i).at(j));
                }
                
                
            }
            return kont2;
            
       }
     
      case SmjerKretanja::DoljeGore:{
       typename std::remove_reference<decltype(kont.at(0))>::type kont2(kont.at(0).size());
            int min;
             if(kont.size()<kont.at(0).at(0).size())
                 min=kont.size();
                else  min=kont.at(0).at(0).size();
            
            
            for(int i=kont.at(0).size()-1;i>=0;i--){
                for(int j=0;j<min;j++){
                    kont2.at(kont.at(0).size()-1-i).push_back(kont.at(kont.size()-1-j).at(i).at(kont.at(0).at(0).size()-j-1));
                }
                
                
            }
            return kont2;
      }
      case SmjerKretanja::LijevoDesno:
       {
          typename std::remove_reference<decltype(kont.at(0))>::type kont2(kont.at(0).at(0).size());
            int min;
             if(kont.at(0).size()<kont.size())
                 min=kont.at(0).size();
                else  min=kont.size();
            
            
            for(int i=0;i<kont.at(0).at(0).size();i++){
                for(int j=0;j<min;j++){
                    kont2.at(i).push_back(kont.at(kont.size()-1-j).at(j).at(i));
                }
                
                
            }
            return kont2;
            
       }
        case SmjerKretanja::DesnoLijevo:{
         typename std::remove_reference<decltype(kont.at(0))>::type kont2(kont.at(0).at(0).size());
            int min;
             if(kont.at(0).size()<kont.size())
                 min=kont.at(0).size();
                else  min=kont.size();
            
            
            for(int i=kont.at(0).at(0).size()-1;i>=0;i--){
                for(int j=0;j<min;j++){
                    kont2.at(kont.at(0).at(0).size()-1-i).push_back(kont.at(j).at(j).at(i));
                }
                
                
            }
            return kont2;
        }}
    
}




int main ()
{
    try{
    std::cout <<"Unesite dimenzije (x y z): ";

    int x,y,z;
    std::cin >> x >> y >> z;
    if(x<0 || y<0 || z <0) throw std::domain_error ("Neispravne dimenzije kontejnera!");
    
    std::cout << "Unesite elemente kontejnera: " << std::endl;
    std::deque<matrica> kont(x,matrica(y,std::vector<int> (z))) ;
    for(int i=0; i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                    std::cin >> kont.at(i).at(j).at(k);
            }
          
        }
    }
    
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    int smjer;
    std::cin >> smjer;
    if(smjer <0 || smjer > 5) throw std::domain_error ("Smjer kretanja nije ispravan!") ;
    
	std::vector<SmjerKretanja> Smjerovi1{SmjerKretanja::NaprijedNazad,  SmjerKretanja::NazadNaprijed, SmjerKretanja::GoreDolje, SmjerKretanja::DoljeGore ,SmjerKretanja::LijevoDesno,SmjerKretanja::DesnoLijevo} ;
    std::vector<std::string> Smjerovi2{ "NaprijedNazad", "NazadNaprijed", "GoreDolje", "DoljeGore", "LijevoDesno","DesnoLijevo"} ;
    
    
	matrica Dijagonale(IzdvojiDijagonale3D(kont,Smjerovi1[smjer])) ;
	std::cout << Smjerovi2[smjer] << ": " << std::endl;
	for(int i=0;i<Dijagonale.size();i++){
	    for(int j=0;j<Dijagonale.at(0).size();j++)
	    std::cout << std::setw(4) << std::right << Dijagonale.at(i).at(j);
	
	    std::cout << std::endl;
	}   
	
    }
    catch(std::domain_error gres){
        std::cout << gres.what()<< std::endl;
    }
    return 0;
}