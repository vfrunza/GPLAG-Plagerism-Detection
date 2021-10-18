// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <stdexcept>
#include <type_traits>

enum class SmjerKretanja {NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo};

template<typename Tip>
auto IzdvojiDijagonale3D(Tip kont, SmjerKretanja s) -> decltype(kont.at(0)) {
    
    for(int i(0); i<kont.size(); i++){
        
        if(kont.at(i).size() != kont.at(0).size()) throw std::domain_error("Plohe nemaju isti broj redova");
        
        for(int j(0); j<kont.at(i).size(); j++){
            if(kont.at(i).at(j).size() != kont.at(i).at(0).size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
        
        if(kont.at(i).at(0).size() != kont.at(0).at(0).size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
    }
    
    typename std::remove_reference<decltype(kont.at(0))>::type rez;
    
    if(s == SmjerKretanja::NaprijedNazad){
        
        for(int i(0); i<kont.size(); i++){
            
            rez.push_back({});
            int k(0);
            
            for(int j(0); j<kont.at(i).size(); j++){
                
                if(k == kont.at(i).at(j).size()) break;
                rez.at(rez.size()-1).push_back(kont.at(i).at(j).at(k));
                k++;
            }
        }
    }
    
    return rez;
}

int main ()
{
    int x, y, z;
    
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> x >> y >> z;
    
    std::vector<std::deque<std::deque<int>>> kont3D(x, std::deque<std::deque<int>>(y, std::deque<int>(z)));
    
    std::cout << "Unesite elemente kontejnera: " << std::endl;
    
    for(int i(0); i<x; i++){
        for(int j(0); j<y; j++){
            for(int k(0); k<z; k++){
                std::cin >> kont3D[i][j][k];
            }
        }
    }
    
    int smjer;
    std::cout << "Unesite smjer kretanja [0-5]: ";
    std::cin >> smjer;
    
    auto kont2D = IzdvojiDijagonale3D(kont3D,SmjerKretanja(smjer));
    
    for(int i(0); i<kont2D.size(); i++){
        for(int j(0); j<kont2D[i].size(); j++) std::cout << std::setw(4) << kont2D[i][j];
        std::cout << std::endl;
    }
    
    
    
    
    
    
	return 0;
}