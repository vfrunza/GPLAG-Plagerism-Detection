// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
#include <stdexcept>
#include <iomanip>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Tip>
auto IzdvojiDijagonale3D(Tip kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont[0])>::type {
    // Izuzeci
    for(unsigned int i(0); i < kont.size(); i++) {
        if(kont.at(i).size() != kont.at(0).size()) throw std::domain_error("Plohe nemaju isti broj redova");
        for(unsigned int j(0); j < kont.at(i).size(); j++)
            if(kont.at(i).at(j).size() != kont.at(0).at(0).size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
    }
    
    typename std::remove_reference<decltype(kont.at(0))>::type dijagonale; 
    if(kont.size() == 0 || kont.at(0).size() == 0 || kont.at(0).at(0).size() == 0) return dijagonale;
    
    if(smjer == SmjerKretanja::NaprijedNazad) {
        for(int i(0); i < kont.size(); i++) {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type element; 
            for(int j(0); j < kont.at(i).size(); j++)
                for(int k(0); k < kont.at(i).at(j).size(); k++)
                    if(j == k) element.push_back(kont.at(i).at(j).at(k));
            dijagonale.push_back(element);
        }
        return dijagonale;
    }
    else if(smjer == SmjerKretanja::NazadNaprijed) {
        for(int i(kont.size() - 1); i < kont.size(); i--) {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type element;
            for(int j(0); j < kont.at(i).size(); j++)
                for(int k(0); k < kont.at(i).at(j).size(); k++)
                    if(j + k == kont.at(i).at(j).size() - 1) element.push_back(kont.at(i).at(j).at(k));
            dijagonale.push_back(element);
        }
        return dijagonale;
    }
    else if(smjer == SmjerKretanja::GoreDolje) {
        int i(kont.size() - 1);
        for(int j(0); j < kont.at(0).size(); j++) {
            i = kont.size() - 1;
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type element;
            for(int k(0); k < kont.at(0).at(j).size(); k++)
                if(k == 0) {
                    element.push_back(kont.at(i).at(j).at(k));
                    i--; k++;
                    while(i >= 0 && k < kont.at(0).at(j).size()) {
                        element.push_back(kont.at(i).at(j).at(k));
                        i--; k++;
                    }
                }
            dijagonale.push_back(element);
        }
        return dijagonale;
    }
    else if(smjer == SmjerKretanja::DoljeGore) {
        int i(kont.size() - 1);
        for(int j(kont.at(0).size() - 1); j >= 0; j--) {
            i = kont.size() - 1;
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type element;
            for(int k(0); k < kont.at(0).at(j).size(); k++)
                if(k == kont.at(0).at(j).size() - 1) {
                    element.push_back(kont.at(i).at(j).at(k));
                    i--; k--;
                    while(i >= 0 && k >= 0) {
                        element.push_back(kont.at(i).at(j).at(k));
                        i--; k--;
                    }
                    break;
                }
            dijagonale.push_back(element);
        }
        return dijagonale;
    }
    else if(smjer == SmjerKretanja::LijevoDesno) {
        for(int k(0); k < kont.at(0).at(0).size(); k++){
            int i (kont.size() - 1);
            int j(0);
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type element;
            element.push_back(kont.at(i).at(j).at(k));
                i--;j++;
                while(i >= 0 && j < kont.at(0).size()) {
                    element.push_back(kont.at(i).at(j).at(k));
                    i--;j++;
                }
            dijagonale.push_back(element);
        }
        return dijagonale;
    }
          else {
        for(int k(kont.at(0).at(0).size() - 1); k >= 0; k--) {
            int i = 0;
            int j = 0;
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type element; // Jedan elemente kontejnera sa dijagonalama
                element.push_back(kont.at(i).at(j).at(k));
                i++;j++;
                while(i < kont.size() && j < kont.at(0).size()) {
                    element.push_back(kont.at(i).at(j).at(k));
                    i++;j++;
                }
            dijagonale.push_back(element);
        }
        return dijagonale;
    }
}

int main()
{
    try {
        int x, y, z;
        std::cout << "Unesite dimenzije (x y z): ";
        std::cin >> x >> y >> z;
        std::vector<std::vector<std::deque<int>>> kontejner(x, std::vector<std::deque<int>>(y, std::deque<int>(z)));
        std::cout << "Unesite elemente kontejnera: " << std::endl;
        for(unsigned int i(0); i < kontejner.size(); i++)
            for(unsigned int j(0); j < kontejner.at(i).size(); j++)
                for(unsigned int k(0); k < kontejner.at(i).at(j).size(); k++)
                    std::cin >> kontejner.at(i).at(j).at(k);
        int smjer;
        std::cout << "Unesite smjer kretanja [0 - 5]: ";
        std::cin >> smjer;
        if(smjer < 0 || smjer > 5) std::cout << "Smjer kretanja nije ispravan!" << std::endl;
        std::vector<std::deque<int>> dijagonale;
        
        if(smjer == 0) {
            dijagonale = IzdvojiDijagonale3D(kontejner, SmjerKretanja::NaprijedNazad);
            std::cout << "NaprijedNazad: " << std::endl;
        }
        if(smjer == 1) {
            dijagonale = IzdvojiDijagonale3D(kontejner, SmjerKretanja::NazadNaprijed);
            std::cout << "NazadNaprijed: " << std::endl;
        }
        if(smjer == 2) {
            dijagonale = IzdvojiDijagonale3D(kontejner, SmjerKretanja::GoreDolje);
            std::cout << "GoreDolje: " << std::endl;
        }
        if(smjer == 3) {
            dijagonale = IzdvojiDijagonale3D(kontejner, SmjerKretanja::DoljeGore);
            std::cout << "DoljeGore: " << std::endl;
        }
        if(smjer == 4) {
            dijagonale = IzdvojiDijagonale3D(kontejner, SmjerKretanja::LijevoDesno);
            std::cout << "LijevoDesno: " << std::endl;
        }
        if(smjer == 5) {
            dijagonale = IzdvojiDijagonale3D(kontejner, SmjerKretanja::DesnoLijevo);
            std::cout << "DesnoLijevo: " << std::endl;
        }

        for(std::deque<int> x : dijagonale) {
            std::cout << " ";
            for(int y : x) std::cout << std::setw(3) << std::right << y << " ";
            std::cout << std::endl;
        }
    }
    catch(std::domain_error izuzetak) {
        std::cout << izuzetak.what();
    }
    catch(std::bad_alloc izuzetak) {
        std::cout << "Neispravne dimenzije kontejnera!" << std::endl;
    }
    catch(...) {}
    return 0;
}
