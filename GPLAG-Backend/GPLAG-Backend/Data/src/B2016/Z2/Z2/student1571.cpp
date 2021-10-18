#include <iostream>
#include <vector>
#include <stdexcept>
#include <type_traits>
#include <deque>
#include <iomanip>
#include <algorithm>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename Tip>
auto IzdvojiDijagonale3D (Tip kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type {
    if (kont.size() == 0 ) {
        typename std::remove_reference <decltype (kont.at(0))>::type pomocni;
        return pomocni;
    }
    for (int i=0; i<kont.size() - 1; i++) {
        if (kont.at(i).size() != kont.at(i+1).size()) throw std::domain_error ("Plohe nemaju isti broj redova");
        for (int j=0; j<kont.at(i).size()-1; j++)
        if (kont.at(i).at(j).size() != kont.at(i).at(j+1).size()) throw std::domain_error ("Redovi nemaju isti broj elemenata");
    }
    if (smjer == SmjerKretanja::NaprijedNazad) {
        typename std::remove_reference <decltype (kont.at(0))>::type pomocni (kont.size());
        for (int i=0; i<kont.size(); i++) {
            for (int j=0; j<kont.at(0).size(); j++) 
                pomocni.at(i).push_back(kont.at(i).at(j).at(j));
        }
        return pomocni;
    }
    else if (smjer == SmjerKretanja::NazadNaprijed) {
        typename std::remove_reference <decltype (kont.at(0))>::type pomocni (kont.at(0).size());
        for (int i=0; i<kont.size(); i++) {
            for (int j=0; j<kont.at(0).size(); j++)
                pomocni.at(i).push_back(kont.at(kont.size() - 1 - i).at(j).at(kont.at(0).size() - j));
        }
        return pomocni;
    }
    else if (smjer == SmjerKretanja::GoreDolje) {
       typename std::remove_reference <decltype (kont.at(0))>::type pomocni (kont.at(0).size());
        for (int i=0; i<kont.at(0).size(); i++) {
            for (int j=kont.size()-1; j>=0; j--) {
                pomocni.at(i).push_back(kont.at(j).at(i).at(kont.size() - j - 1));
            }
        }
        return pomocni;
     }
    else if (smjer == SmjerKretanja::DoljeGore) {
        typename std::remove_reference <decltype (kont.at(0))>::type pomocni (kont.at(0).size());
        int brojac1 (kont.at(0).size() - 1);
        for (int i=0; i<kont.at(0).size(); i++) {
            int brojac(1), brojac2(kont.at(0).at(0).size() - 1);
            for (int j=0; j<kont.size(); j++) {
                pomocni.at(i).push_back(kont.at(brojac).at(brojac1).at(brojac2)); 
                brojac--;
                brojac2--;
            }
            brojac1--;
        }
        return pomocni;
    }
    else if (smjer == SmjerKretanja::LijevoDesno) {
        typename std::remove_reference <decltype (kont.at(0))>::type pomocni (kont.at(0).at(0).size());
        int duzina = kont.at(0).at(0).size();
        int brojac3(0);
        for (int i=0; i<duzina; i++ ) {
            int brojac(kont.size() - 1), brojac1(0);
            for (int j=0; j<kont.size(); j++) {
                pomocni.at(i).push_back(kont.at(brojac).at(brojac1).at(brojac3));
                brojac1++;
                brojac--;
            }
            brojac3++;
        }
        return pomocni;
    }
    else if (smjer == SmjerKretanja::DesnoLijevo) {
        typename std::remove_reference <decltype (kont.at(0))>::type pomocni (kont.at(0).at(0).size());
        int brojac3 (kont.at(0).at(0).size() - 1);
        for (int i=0; i<kont.at(0).at(0).size(); i++) {
            int brojac(0), brojac1(0);
            for (int j=0; j<kont.size(); j++) {
                pomocni.at(i).push_back (kont.at(brojac).at(brojac1).at(brojac3));
                brojac++;
                brojac1++;
            }
            brojac3--;
        }
        return pomocni;
    }
}
int main ()
{
    std::cout << "Unesite dimenzije (x y z): ";
    int x, y, z;
    std::cin >> x >> y >> z;
    if (x < 0 || y < 0 || z < 0) {
        std::cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::cout << "Unesite elemente kontejnera: "<<std::endl;
    std::vector<std::deque<std::deque<int>>> dek (x, std::deque<std::deque<int>> (y, std::deque<int>(z)));
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            for (int k=0; k<z; k++) {
                std::cin >> dek.at(i).at(j).at(k);
            }
        }
    }
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    int smjer;
    std::cin >> smjer;
 
    SmjerKretanja smjer1 = static_cast<SmjerKretanja> (smjer);
    switch (smjer) {
        case (0): {
            std::cout << "NaprijedNazad:";
            break;
        } 
        case (1): {
            std::cout << "NazadNaprijed:";
            break;
        }
        case (2): {
            std::cout << "GoreDolje:";
            break;
        }
        case (3): {
            std::cout << "DoljeGore:";
            break;
        }
        case (4): {
            std::cout << "LijevoDesno:";
            break;
        }
        case (5): {
            std::cout << "DesnoLijevo:";
            break;
        }
        default: { 
            std::cout << "Smjer kretanja nije ispravan!" << std::endl;
            return 0;
        }
    }
    try {
        auto pomocni = IzdvojiDijagonale3D (dek, smjer1);
        std::cout << std::endl;
        for (int i=0; i<pomocni.size(); i++) {
            for (int j=0; j<pomocni.at(i).size(); j++)
                std::cout << std::setw(4) <<pomocni.at(i).at(j);
            std::cout << std::endl;
        }
    }
    catch (std::domain_error poruka) {
        std::cout << poruka.what() << std::endl;
    }
	return 0;
}