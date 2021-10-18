// B 16/17, Zadaća 2, Zadatak 2

#include <iostream>
#include <vector>
#include <type_traits>
#include <iomanip>
#include <deque>
#include <stdexcept>
#include <string>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename TipKontejnera>
    auto IzdvojiDijagonale3D (TipKontejnera kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type {
        typedef typename std::remove_reference<decltype(kont.at(0))>::type PovratniTip;
        PovratniTip matrica(0);
        typedef typename std::remove_reference<decltype(kont.at(0).at(0))>::type Red;
        Red rez(0);
        
        for(int i=0; i<kont.size(); i++){	       
        	for(int j=1; j<kont.at(i).size(); j++){
        		if(kont.at(i).at(j).size() != kont.at(i).at(j-1).size()) throw std::domain_error ("Redovi nemaju isti broj elemenata");
        	}
        }
        for(int i=1; i<kont.size(); i++) if(kont.at(i).size()!=kont.at(i-1).size()) throw std::domain_error ("Plohe nemaju isti broj redova");
    
        if(smjer == SmjerKretanja::NaprijedNazad){

            for(int i=0; i<kont.size(); i++){
                for(int j=0; j<kont.at(i).size(); j++){
                    for(int k=0; k<kont.at(i).at(j).size(); k++){
                        if(k==j){
                            rez.push_back(kont.at(i).at(j).at(k));
                        }
                    }
                }
                matrica.push_back(rez);
        		rez.resize(0);
            }
        }
            
        if(smjer == SmjerKretanja::NazadNaprijed){
            
            for(int i=kont.size()-1; i>=0; i--){
                for(int j=0; j<kont.at(i).size(); j++){
                    for(int k=0; k<kont.at(i).at(j).size(); k++){
                            if(j+k==kont.at(i).size()){
                                rez.push_back(kont.at(i).at(j).at(k));
                            } 
                    }
                }
                matrica.push_back(rez);
        		rez.resize(0);
            }
        }
        
        if(smjer == SmjerKretanja::DesnoLijevo){
            
            for(int i=0; i<kont.size()/2; i++){
                for(int j=0; j<(kont.at(i).size()-1)/2; j++){
                    for(int k=kont.at(i).at(j).size()-1; k>=0; k--){
                            	rez.push_back(kont.at(i).at(j).at(k));
                            	rez.push_back(kont.at(kont.size()-1).at(j+1).at(k));
								matrica.push_back(rez);
								rez.resize(0);
                    }
                }
            }
        }
        
        if(smjer == SmjerKretanja::LijevoDesno){
        	
        	for(int i=kont.size()/2; i>0; i--){
        		for(int j=0; j<(kont.at(i).size()-1)/2; j++){
        			for(int k=0; k<kont.at(i).at(j).size(); k++){
        				rez.push_back(kont.at(i).at(j).at(k));
        				rez.push_back(kont.at(i-1).at(j+1).at(k));
        				matrica.push_back(rez);
        				rez.resize(0);
        			}
        		}
        	}
        }
        
        if(smjer == SmjerKretanja::GoreDolje){
        	
        	for(int i=kont.size()/2; i>0; i--){
        		for(int j=0; j<kont.at(i).size(); j++){
        			for(int k=0; k!=(kont.at(i).at(j).size()-1)/2; k++){
        				rez.push_back(kont.at(i).at(j).at(k));
        				rez.push_back(kont.at(i-1).at(j).at(k+1));;
        			}
        			 matrica.push_back(rez);
        			 rez.resize(0);
        		}
        	}
        }
        
        if(smjer == SmjerKretanja::DoljeGore){
        	
        	for(int i=kont.size()-1; i>0; i--){
        		for(int j=kont.at(i).size()-1; j>=0; j--){
        			for(int k=kont.at(i).at(j).size()-1; k!=kont.at(i).at(j).size()/2; k--){
        				rez.push_back(kont.at(i).at(j).at(k));
        				rez.push_back(kont.at(i-1).at(j).at(k-1));
        			}
        			matrica.push_back(rez);
        			rez.resize(0);
        		}
        	}
        }
        return matrica;
    }

int main ()
{
	std::vector<std::vector<std::vector<int>>> grdoba;
	int prva(0), druga(0), treca(0), smjer(0);
	
	try{
	    std::cout << "Unesite dimenzije (x y z): ";
    	std::cin >> prva >> druga >> treca;
	    if(prva <=0 || druga <=0 || treca <=0) throw ("Neispravne dimenzije kontejnera!");  
	
	    grdoba.resize(prva);
	    
	    for(int i=0; i<grdoba.size(); i++) grdoba[i].resize(druga);
	    
	    for(int i=0; i<prva; i++){
	        for(int j=0; j<druga; j++){
	            grdoba[i][j].resize(treca);
	        }
	    }
	
	    std::cout << "Unesite elemente kontejnera: " << std::endl;
	    for(int i=0; i<prva; i++){
	        for(int j=0; j<druga; j++){
	            for(int k=0; k<treca; k++){
	                std::cin >> grdoba[i][j][k];
	            }
	        }
	    }
	
	    std::cout << "Unesite smjer kretanja [0 - 5]: ";
	    std::cin >> smjer;
	    if(smjer<0 || smjer>5) std::cout << "Smjer kretanja nije ispravan!" << std::endl;
	
	    auto mat (IzdvojiDijagonale3D(grdoba, SmjerKretanja(smjer)));
	    	 
	    switch(smjer){
	        case 0:
	            std::cout << "NaprijedNazad: " << std::endl;
	            break;
	        case 1:
	            std::cout << "NazadNaprijed: " << std::endl;
	            break;
	        case 2:
	            std::cout << "GoreDolje: " << std::endl;
	            break;
	        case 3:
	            std::cout << "DoljeGore: " << std::endl;
	            break;
	        case 4:
	            std::cout << "LijevoDesno: " << std::endl;
	            break;
	        case 5:
	            std::cout << "DesnoLijevo: "  << std::endl;
	            break;
 	    }
 	    
	    for(int i=0; i<mat.size(); i++) {
	        for(int j=0; j<mat[i].size(); j++) {
	        std::cout << std::setw(4) << mat[i][j];
	    	}
	    std::cout << std::endl;
	    }
	 }
	 catch(std::domain_error izuzetak){
	    std::cout << izuzetak.what();
	 }
	 catch(const char poruka[]){
	     std::cout << poruka;
	 }
	 catch(...){
		
	 }
	return 0;
}