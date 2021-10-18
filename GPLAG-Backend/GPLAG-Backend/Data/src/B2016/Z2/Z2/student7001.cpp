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

template <typename Tip3D>
auto IzdvojiDijagonale3D(Tip3D kont, SmjerKretanja izbor) -> typename std::remove_reference<decltype(kont.at(0))>::type {
    typename std::remove_reference<decltype(kont.at(0))>::type rezultujuci2D;
    int duzina1=kont.size();
    if (duzina1==0) return rezultujuci2D;
    int duzina2=kont.at(0).size();
    if (duzina2==0) return rezultujuci2D;
    int duzina3=kont.at(0).at(0).size();
    if (duzina3==0) return rezultujuci2D;
    for (int i=0; i<kont.size(); i++) {
        if (duzina2!=kont.at(i).size()) throw std::domain_error("Plohe nemaju isti broj elemenata");
        for (int j=1; j<kont.at(i).size(); j++)
            if (duzina3!=kont.at(i).at(j).size()) throw std::domain_error("Redovi nemaju isti broj elemenata;");
    }
    if (izbor==SmjerKretanja::NaprijedNazad) {
        for (int i=0; i<duzina1; i++) {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type pomocni1D;
            for (int j=0; j<duzina2; j++) {
                for (int k=0; k<duzina3; k++) {
                    if (j==k) pomocni1D.push_back(kont.at(i).at(j).at(k));
                }
            }
            rezultujuci2D.push_back(pomocni1D);
        }
        return rezultujuci2D;
    }
    else if (izbor==SmjerKretanja::NazadNaprijed) {
        for (int i=duzina1-1; i>=0; i--) {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type pomocni1D;
            for (int j=0; j<duzina2; j++) {
                for (int k=0; k<duzina3; k++) {
                    if (j==duzina3-1-k) pomocni1D.push_back(kont.at(i).at(j).at(k));
                }
            }
            rezultujuci2D.push_back(pomocni1D);
        }
        return rezultujuci2D;
    }
    else if (izbor==SmjerKretanja::GoreDolje) {
        for (int i=0; i<duzina2; i++) {
            typename std::remove_reference<decltype(kont.at(0))>::type pomocni2D;
            for (int j=duzina1-1; j>=0; j--)
                pomocni2D.push_back(kont.at(j).at(i));
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type pomocni1D;
            for (int k=0; k<pomocni2D.size(); k++)
                for (int l=0; l<pomocni2D.at(k).size(); l++)
                    if (k==l) pomocni1D.push_back(pomocni2D.at(k).at(l));
            rezultujuci2D.push_back(pomocni1D);
        }
        return rezultujuci2D;
    }
    else if (izbor==SmjerKretanja::DoljeGore) {
        for (int i=duzina2-1; i>=0; i--) {
            typename std::remove_reference<decltype(kont.at(0))>::type pomocni2D;
            for (int j=duzina1-1; j>=0; j--)
                pomocni2D.push_back(kont.at(j).at(i));
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type pomocni1D;
            for (int k=0; k<pomocni2D.size(); k++)
                for (int l=0; l<pomocni2D.at(k).size(); l++)
                    if (l==pomocni2D.at(k).size()-1-k) pomocni1D.push_back(pomocni2D.at(k).at(l));
            rezultujuci2D.push_back(pomocni1D);
        }
        return rezultujuci2D;
    }
    else if (izbor==SmjerKretanja::LijevoDesno) {
        for (int i=0; i<duzina3; i++) {
            typename std::remove_reference<decltype(kont.at(0))>::type pomocni2D;
            for (int j=0; j<duzina2; j++) {
                typename std::remove_reference<decltype(kont.at(0).at(0))>::type tmp1D;
                for (int k=0; k<duzina1; k++)
                    tmp1D.push_back(kont.at(k).at(j).at(i));
                pomocni2D.push_back(tmp1D);
            }
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type pomocni1D;
            for (int l=0; l<pomocni2D.size(); l++)
                for (int m=0; m<pomocni2D.at(l).size(); m++)
                    if (m==pomocni2D.at(l).size()-1-l) pomocni1D.push_back(pomocni2D.at(l).at(m));
            rezultujuci2D.push_back(pomocni1D);
        }
        return rezultujuci2D;
    }
    else if (izbor==SmjerKretanja::DesnoLijevo) {
        for (int i=duzina3-1; i>=0; i--) {
            typename std::remove_reference<decltype(kont.at(0))>::type pomocni2D;
            for (int j=0; j<duzina2; j++) {
                typename std::remove_reference<decltype(kont.at(0).at(0))>::type tmp1D;
                for (int k=0; k<duzina1; k++)
                    tmp1D.push_back(kont.at(k).at(j).at(i));
                pomocni2D.push_back(tmp1D);
            }
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type pomocni1D;
            for (int l=0; l<pomocni2D.size(); l++)
                for (int m=0; m<pomocni2D.at(l).size(); m++)
                    if (m==l) pomocni1D.push_back(pomocni2D.at(l).at(m));
            rezultujuci2D.push_back(pomocni1D);
        }
        return rezultujuci2D;
    }
}
    
int main () {
    try {
        int x{}, y{}, z{};
        std::cout << "Unesite dimenzije (x y z): ";
        std::cin >> x >> y >> z;
        if (x<0 || y<0 || z<0) {
            std::cout << "Neispravne dimenzije kontejnera!";
            return 0;
        }
        std::cout << "Unesite elemente kontejnera: " << std::endl;
        std::vector<std::deque<std::deque<int>>> vdd (x, std::deque<std::deque<int>> (y, std::deque<int> (z)));
        for (int i=0; i<x; i++) {
            for (int j=0; j<y; j++)
                for (int k=0; k<z; k++)
                    std::cin >> vdd.at(i).at(j).at(k);
        }
        std::cout << "Unesite smjer kretanja [0 - 5]: ";
        int izbor{};
        std::cin >> izbor;
        SmjerKretanja smjer=static_cast<SmjerKretanja>(izbor);
        auto rezultat=IzdvojiDijagonale3D(vdd, smjer);
        switch(izbor) {
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
                std::cout << "DesnoLijevo: " << std::endl;
                break;
            default:
                std::cout << "Smjer kretanja nije ispravan!" << std::endl;
                break;
        }
        for (int i=0; i<rezultat.size(); i++) {
            for (int j=0; j<rezultat.at(i).size(); j++)
                std::cout << std::right << std::setw(4) << rezultat.at(i).at(j);
            std::cout << std::endl;
        }
    }
    catch(std::domain_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
	return 0;
}