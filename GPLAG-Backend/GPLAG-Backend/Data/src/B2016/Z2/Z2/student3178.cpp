#include <type_traits>
#include <iostream>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iomanip>

enum class SmjerKretanja{NaprijedNazad,NazadNaprijed,GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template <typename Tip>
auto IzdvojDijagonale3D(Tip kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type
{
    int br{-1};
    for(int i=0; i<kont.size(); i++){
        for(int j=0; j<(kont.at(i)).size(); j++){
            if(br == -1) br = (kont.at(i).at(j)).size();
            
               if( br != (kont.at(i).at(j)).size()) throw
               std::domain_error("Redovi nemaju isti broj elemenata");
        }   
    }    
    
    br = -1;
    for(int i=0; i<kont.size(); i++){
        if(br== -1) br = (kont.at(i)).size();
        
           if(br != kont.at(i).size()) throw 
             std::domain_error("Plohe nemaju isti broj redova");    
    }
    typename std::remove_reference<decltype(kont.at(0))>::type forReturn;
	
	if(smjer == SmjerKretanja::NaprijedNazad){
	    for(int k{0}; k<kont.size(); k++){
	 typename std::remove_reference<decltype((kont.at(0)).at(0))>::type tmp; 
	        for(int i=0; i< (kont.at(k)).size(); i++){
	            if(i<((kont.at(k)).at(i)).size())
	            tmp.push_back(((kont.at(k)).at(i)).at(i));
	        }
	        forReturn.push_back(tmp);
	    }
	}
		if(smjer == SmjerKretanja::NazadNaprijed){
	    for(int k=kont.size()-1; k>=0; k--){
	 typename std::remove_reference<decltype((kont.at(0)).at(0))>::type tmp; 
	        for(int i=0; i< (kont.at(k)).size(); i++){
	            int j = ((kont.at(k)).at(i)).size() - 1 -i;
	            if(j >= 0)
	            tmp.push_back(((kont.at(k)).at(i)).at(j));
	        }
	        forReturn.push_back(tmp);
	    }
	}
	
		if(smjer == SmjerKretanja::GoreDolje){
	    for(int i=0; i<kont[0].size(); i++){
	 typename std::remove_reference<decltype((kont.at(0)).at(0))>::type tmp; 
	        for(int k=kont.size()-1; k>=0; k--){
	            
	            int j = kont.size() - 1 -k;
	            if(j < kont[0][0].size())
	            tmp.push_back(((kont.at(k)).at(i)).at(j));
	        }
	        forReturn.push_back(tmp);
	    }
	}

		if(smjer == SmjerKretanja::DoljeGore){
	    for(int i=kont[0].size()-1; i>=0; i--){
	 typename std::remove_reference<decltype((kont.at(0)).at(0))>::type tmp; 
	    int j = ((kont.at(0)).at(0)).size() - 1;
	        for(int k=kont.size()-1; k>=0; k--){
	            if(j >=0)
	               tmp.push_back(kont[k][i][j]);
	            j--;
	        }
	        forReturn.push_back(tmp);
	    }
	}
    
    	if(smjer == SmjerKretanja::DesnoLijevo){
	    for(int kol=((kont.at(0)).at(0)).size()-1; kol>=0; kol--){
	 typename std::remove_reference<decltype((kont.at(0)).at(0))>::type tmp; 
	 
	        for(int red=0; red<(kont.at(0)).size(); red++){
	            if(red>=kont.size()) break;
	            
	               tmp.push_back(((kont.at(red)).at(red)).at(kol));
	        }
	        
	        forReturn.push_back(tmp);
	    }
	}
    
    if(smjer == SmjerKretanja::LijevoDesno){
	    for(int kol=0; kol<kont[0][0].size(); kol++){
	 typename std::remove_reference<decltype((kont.at(0)).at(0))>::type tmp; 
	 int k =kont.size()-1;
	        for(int red=0; red<kont[0].size(); red++){
	            if(k<0) break;
	               tmp.push_back(((kont.at(k)).at(red)).at(kol));
	               k--;
	        }
	        
	        forReturn.push_back(tmp);
	    }
	}
	
	return forReturn;
	
}

int main ()
{
   int x,y,z;
   try{
   std::cout<< "Unesite dimenzije (x y z): ";
   std::cin >> x >> y >> z;
   if(x<0 || y<0|| z<0) throw std::range_error("Neispravne dimenzije kontejnera!");
   std::cout << "Unesite elemente kontejnera: "<< std::endl;
   
   std::vector<std::deque<std::deque<int>>> vdd;
   for(int i{0}; i<x; i++){
       std::deque<std::deque<int>> dd;
       for(int j=0; j<y; j++){
           std::deque<int> d;
           for(int k=0; k<z; k++){
               int t;
               std::cin>>t;
               d.push_back(t);
           }
          dd.push_back(d);
       }
       vdd.push_back(dd);
   }
   
   std::cout<< "Unesite smjer kretanja [0 - 5]: ";
   std::deque<std::deque<int>> dijagonala;
   int smjer;
   std::cin>>smjer;
   
   switch(smjer){
       case 0:
       dijagonala = IzdvojDijagonale3D(vdd,SmjerKretanja::NaprijedNazad);
       std::cout<<"NaprijedNazad: "<<std::endl;
       break;
       case 1:
       dijagonala = IzdvojDijagonale3D(vdd,SmjerKretanja::NazadNaprijed);
       std::cout<<"NazadNaprijed: "<<std::endl;
       break;
        case 2:
       dijagonala = IzdvojDijagonale3D(vdd,SmjerKretanja::GoreDolje);
       std::cout<<"GoreDolje: "<<std::endl;
       break;
        case 3:
       dijagonala = IzdvojDijagonale3D(vdd,SmjerKretanja::DoljeGore);
       std::cout<<"DoljeGore: "<<std::endl;
       break;
        case 4:
       dijagonala = IzdvojDijagonale3D(vdd,SmjerKretanja::LijevoDesno);
       std::cout<<"LijevoDesno: "<<std::endl;
       break;
        case 5:
       dijagonala = IzdvojDijagonale3D(vdd,SmjerKretanja::DesnoLijevo);
       std::cout<<"DesnoLijevo: "<<std::endl;
       break;
       
       default:
       break;
   }
   
   for(std::deque<int> d : dijagonala){
       for(int k: d) std::cout << std::setw(4) << k;
       std::cout <<  std::endl;
   }
}
   catch(std::range_error e){
       std::cout << e.what() << std::endl;
   }
	return 0;
}