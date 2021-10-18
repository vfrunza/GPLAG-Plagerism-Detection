// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <vector>
#include <deque>
#include <iostream>
#include <type_traits>
#include <iomanip>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo  
};

template
<typename KonTip>
void ispisi2DKont(KonTip ulaz, SmjerKretanja smjer);

template
<typename KonTip>
auto IzdvojiDijagonale3D(KonTip ulaz, SmjerKretanja smjer) -> typename std::remove_reference<decltype(ulaz.at(0))>::type;

int main ()
{
    int x_dim, y_dim, z_dim, smjer_kretanja;
    std::vector<std::deque<std::deque<int>>> ulaz;
    
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> x_dim >> y_dim >> z_dim;
    
    if (x_dim <= 0 || y_dim <= 0 || z_dim <= 0) {
        std::cout << "Neispravne dimenzije kontejnera!" << std::endl;
        return 0;
    }
    
    std::cout << "Unesite elemente kontejnera: " << std::endl;
    for (int i = 0; i < x_dim; i++) {
        std::deque<std::deque<int>> kont;
        
        for (int j = 0; j < y_dim; j++) {
            std::deque<int> red;
            
            for (int k = 0; k < z_dim; k++) {
                int unos;
                std::cin >> unos;
                red.push_back(unos);
            }
            
            kont.push_back(red);
            std::cout << std::endl;
        }
        
        ulaz.push_back(kont);
        std::cout << std::endl;
    }
    
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    std::cin >> smjer_kretanja;
    
    switch (smjer_kretanja) {
        case 0:
            std::cout << "NaprijedNazad: " << std::endl;
            ispisi2DKont(ulaz, SmjerKretanja::NaprijedNazad);
            break;
        case 1:
            std::cout << "NazadNaprijed: " << std::endl;
            ispisi2DKont(ulaz, SmjerKretanja::NazadNaprijed);
            break;
        case 2:
            std::cout << "GoreDolje: " << std::endl;
            ispisi2DKont(ulaz, SmjerKretanja::GoreDolje);
            break;
        case 3:
            std::cout << "DoljeGore: " << std::endl;
            ispisi2DKont(ulaz, SmjerKretanja::DoljeGore);
            break;
        case 4:
            std::cout << "LijevoDesno: " << std::endl;
            ispisi2DKont(ulaz, SmjerKretanja::LijevoDesno);
            break;
        case 5:
            std::cout << "DesnoLijevo: " << std::endl;
            ispisi2DKont(ulaz, SmjerKretanja::DesnoLijevo);
            break;
        default:
            std::cout << "Smjer kretanja nije ispravan!" << std::endl;
            break;
    }
          
	return 0;
}

template
<typename KonTip>
void ispisi2DKont(KonTip ulaz, SmjerKretanja smjer) {
    auto noviKont = IzdvojiDijagonale3D(ulaz, smjer);
    
    for (int i = 0; i < noviKont.size(); i++) {
        for (int j = 0; j < noviKont.at(i).size(); j++) {
            std::cout << std::setw(4) << noviKont.at(i).at(j);
        }
        std::cout << std::endl;
    }
}

template
<typename KonTip>
auto IzdvojiDijagonale3D(KonTip ulaz, SmjerKretanja smjer) -> typename std::remove_reference<decltype(ulaz.at(0))>::type {
    typedef typename std::remove_reference<decltype(ulaz.at(0))>::type IzlazniTip;
    typedef typename std::remove_reference<decltype(ulaz.at(0).at(0))>::type TipReda;
    
    const int br_kon = ulaz.size();             // broj kontejnera
    const int br_red = ulaz.at(0).size();       // broj redova
    const int br_kol = ulaz.at(0).at(0).size(); // broj kolona
    
    IzlazniTip izlaz;
    
    switch (smjer) {
        case SmjerKretanja::NaprijedNazad:
            for (int i = 0; i < br_kon; i++) {
                TipReda red;
                
                for (int j = 0; j < br_red; j++) 
                    red.push_back(ulaz.at(i).at(j).at(j));
                    
                izlaz.push_back(red);
            }
            
            return izlaz;
            break;
        case SmjerKretanja::NazadNaprijed:
            for (int i = 0; i < br_kon; i++) {
                TipReda red;
                
                for (int j = 0; j < br_red; j++) 
                    red.push_back(ulaz.at(br_kon - 1 - i).at(j).at(br_kol - 1 - j));
                    
                izlaz.push_back(red);
            }
            
            return izlaz;
            break;
        case SmjerKretanja::LijevoDesno:
            for (int i = 0; i < br_kol; i++) {
                TipReda red;
                
                for (int j = 0; j < br_kon; j++) 
                    red.push_back(ulaz.at(br_kon - 1 - j).at(j).at(i));
                    
                izlaz.push_back(red);
            }
            
            return izlaz;
            break;
        case SmjerKretanja::DesnoLijevo:
            for (int i = 0; i < br_kol; i++) {
                TipReda red;
                
                for (int j = 0; j < br_kon; j++) 
                    red.push_back(ulaz.at(j).at(j).at(br_kol - 1 - i));
                    
                izlaz.push_back(red);
            }
            
            return izlaz;
            break;
        case SmjerKretanja::GoreDolje:
            for (int i = 0; i < br_red; i++) {
                TipReda red;
                
                for (int j = 0; j < br_kon; j++) 
                    red.push_back(ulaz.at(br_kon - 1 - j).at(i).at(j));
                    
                izlaz.push_back(red);
            }
            
            return izlaz;
            break;
        case SmjerKretanja::DoljeGore:
            for (int i = 0; i < br_red; i++) {
                TipReda red;
                
                for (int j = 0; j < br_kon; j++) 
                    red.push_back(ulaz.at(br_kon - 1 - j).at(br_red - 1 - i).at(br_kol - 1 - j));
                    
                izlaz.push_back(red);
            }
            
            return izlaz;
            break;
        default:
            break;
    }
    
    return ulaz.at(0);
}