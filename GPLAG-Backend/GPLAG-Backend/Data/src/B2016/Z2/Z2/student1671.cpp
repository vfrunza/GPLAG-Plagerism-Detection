// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <type_traits>
#include <deque>
#include <string>
#include <list>
#include <stdexcept>
#include <iomanip>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Kontejner3D>
auto IzdvojiDijagonale3D(Kontejner3D kontejner, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kontejner.at(0))>::type {
    for (int i = 0; i < kontejner.size(); i++) {
        for (int j = 0; j < kontejner.at(i).size(); j++) if (kontejner.at(i).at(j).size() != kontejner.at(0).at(0).size()) throw std::domain_error ("Redovi nemaju isti broj elemenata");
    if (kontejner.at(i).size() != kontejner.at(0).size()) throw std::domain_error ("Plohe nemaju isti broj redova");   
    }
    typedef typename std::remove_reference<decltype(kontejner.at(0))>::type MojTip;
    MojTip Matrica;
    if (smjer == SmjerKretanja::NaprijedNazad || smjer == SmjerKretanja::NazadNaprijed) {
        Matrica.resize(kontejner.size());
        for (int i = 0; i < kontejner.size(); i++)
            for (int j = 0; j < kontejner.at(i).size(); j++) 
                for (int k = 0; k < kontejner.at(i).at(j).size(); k++) {
                    if (j == k && smjer == SmjerKretanja::NaprijedNazad) Matrica.at(i).push_back(kontejner.at(i).at(j).at(k));
                    if (j + k == kontejner.at(i).at(j).size()-1 && smjer == SmjerKretanja::NazadNaprijed) Matrica.at(kontejner.size()-1-i).push_back(kontejner.at(i).at(j).at(k));
                }
    }
    if (smjer == SmjerKretanja::GoreDolje || smjer == SmjerKretanja::DoljeGore) {
        Matrica.resize(kontejner.at(0).size());
        int red(0);
        for (int i = kontejner.size()-1; i >= 0; i--) {
            for (int j = 0; j < kontejner.at(i).size(); j++) {
                if (smjer == SmjerKretanja::GoreDolje) Matrica.at(j).push_back(kontejner.at(i).at(j).at(red));
                else Matrica.at(kontejner.at(0).size()-1-j).push_back(kontejner.at(i).at(j).at(kontejner.at(i).at(j).size()-1-red));
            }
            red++;
        }
    }
    if (smjer == SmjerKretanja::LijevoDesno || smjer == SmjerKretanja::DesnoLijevo) {
        Matrica.resize(kontejner.at(0).at(0).size());
        int red(0);
        for (int i = 0; i < kontejner.size(); i++) {
            for (int j = 0; j < kontejner.at(0).at(0).size(); j++) {
                if (smjer == SmjerKretanja::DesnoLijevo) Matrica.at(kontejner.at(0).at(0).size()-1-j).push_back(kontejner.at(i).at(red).at(j));
                else Matrica.at(j).push_back(kontejner.at(kontejner.size()-1-i).at(red).at(j));
            }
            red++;
        }
    }
    return Matrica;
}
int main() {
    try {    
        int x, y, z;
        std::cout << "Unesite dimenzije (x y z): ";
        std::cin >> x >> y >> z;
        if (x < 0 || y < 0 || z < 0) {
            std::cout << "Neispravne dimenzije kontejnera!";
            return 0;
        }
        std::vector<std::deque<std::deque<int>>> kontejner(x, std::deque<std::deque<int>>(y, std::deque<int>(z)));
        std::cout << "Unesite elemente kontejnera: " << std::endl;
        for (int i = 0; i < kontejner.size(); i++) 
            for (int j = 0; j < kontejner.at(i).size(); j++) 
                for (int z = 0; z < kontejner.at(i).at(j).size(); z++) std::cin >> kontejner.at(i).at(j).at(z);
        int opcija;
        std::cout << "Unesite smjer kretanja [0 - 5]: "; 
        std::cin >> opcija;
        if (opcija < 0 || opcija > 5) std::cout << "Smjer kretanja nije ispravan!" << std::endl;
        else try {
            auto matrica(IzdvojiDijagonale3D(kontejner, SmjerKretanja(opcija)));
            if (opcija == 0) std::cout << "NaprijedNazad: ";
            else if (opcija == 1) std::cout << "NazadNaprijed: ";
            else if (opcija == 2) std::cout << "GoreDolje: ";
            else if (opcija == 3) std::cout << "DoljeGore: ";
            else if (opcija == 4) std::cout << "LijevoDesno: ";
            else if (opcija == 5) std::cout << "DesnoLijevo: ";
            std::cout << std::endl;
            for (int i = 0; i < matrica.size(); i++) {
                for (int j = 0; j < matrica.at(i).size(); j++) std::cout << std::setw(4) << matrica.at(i).at(j);
                std::cout << std::endl;
            }
        }
        catch (std::domain_error tekst) {
            std::cout << tekst.what(); 
        }
    } catch(...) {
        
    }
    return 0;
}