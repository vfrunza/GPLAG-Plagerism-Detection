#include <iostream>
#include <type_traits>
#include <stdexcept>
#include <vector>
#include <deque>
#include <iomanip>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename tip1>
auto IzdvojiDijagonale3D(tip1 kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type {
    int broj_el(kont.at(0).at(0).size()), broj_re(kont.at(0).size());
    for(int i(0); i<kont.size(); i++)
        for(int j(0); j<kont.at(0).size(); j++)
            if(broj_el!=kont.at(i).at(j).size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
    for(int i(0); i<kont.size(); i++)
        if(broj_re!=kont.at(i).size()) throw std::domain_error("Plohe nemaju isti broj redova");
    typename std::remove_reference<decltype(kont.at(0))>::type mat;
    if(smjer==SmjerKretanja::NaprijedNazad) {
        mat.resize(kont.size());
        for(int i(0); i<kont.size(); i++) {
            for(int j(0); j<kont.at(0).size(); j++) {
                for(int k(0); k<kont.at(0).at(0).size(); k++) {
                    if(j==k) mat.at(i).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
    }
    if(smjer==SmjerKretanja::NazadNaprijed) {
        mat.resize(kont.size());
        int l(0);
        for(int i(kont.size()-1); i>=0; i--) {
            for(int j(0); j<kont.at(0).size(); j++) {
                for(int k(0); k<kont.at(0).at(0).size(); k++) {
                    if(j+k==kont.at(0).at(0).size()-1) mat.at(l).push_back(kont.at(i).at(j).at(k));
                }
            }
            l++;
        }
    }
    if(smjer==SmjerKretanja::GoreDolje) {
        mat.resize(kont.at(0).size());
        int l(0);
        for(int j(0); j<kont.at(0).size(); j++) {
            for(int i(kont.size()-1); i>=0; i--) {
                for(int k(0); k<kont.at(0).at(0).size(); k++) {
                    if(i+k==kont.size()-1) mat.at(l).push_back(kont.at(i).at(j).at(k));
                }
            }
            l++;
        }
    }
    if(smjer==SmjerKretanja::DoljeGore) {
        mat.resize(kont.at(0).size());
        int l(0);
        for(int j(kont.at(0).size()-1); j>=0; j--) {
            for(int i(kont.size()-1); i>=0; i--) {
                for(int k(kont.at(0).at(0).size()-1); k>=0; k--) {
                    if(k==i+kont.at(0).at(0).size()-kont.size()) mat.at(l).push_back(kont.at(i).at(j).at(k));
                }
            }
            l++;
        }
    }
    if(smjer==SmjerKretanja::LijevoDesno) {
        mat.resize(kont.at(0).at(0).size());
        int l(0);
        for(int k(0); k<kont.at(0).at(0).size(); k++) {
            for(int i(kont.size()-1); i>=0; i--) {
                for(int j(0); j<kont.at(0).size(); j++) {
                    if(j+i==kont.size()-1) mat.at(l).push_back(kont.at(i).at(j).at(k));
                }
            }
            l++;
        }
    }
    if(smjer==SmjerKretanja::DesnoLijevo) {
        mat.resize(kont.at(0).at(0).size());
        int l(0);
        for(int k(kont.at(0).at(0).size()-1); k>=0; k--) {
            for(int i(0); i<kont.size(); i++) {
                for(int j(0); j<kont.at(0).size(); j++) {
                    if(i==j) mat.at(l).push_back(kont.at(i).at(j).at(k));
                }
            }
            l++;
        }
    }
    return mat;
}

int main () {
    int a, b, c;
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> a >> b >> c;
    if(a<=0 or b<=0 or c<=0) {
        std::cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::vector<std::deque<std::deque<int>>> kont(a, std::deque<std::deque<int>> (b, std::deque<int> (c)));
    std::cout << "Unesite elemente kontejnera: " << std::endl;
    for(int i(0); i<a; i++)
        for(int j(0); j<b; j++)
            for(int k(0); k<c; k++)
                std::cin >> kont[i][j][k];
    int broj;
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    std::cin >> broj;
    if(broj<0 or broj>5) {
        std::cout << "Smjer kretanja nije ispravan!" << std::endl;
        return 0;
    }
    try {
        std::deque<std::deque<int>> mat(IzdvojiDijagonale3D(kont, SmjerKretanja(broj)));
        switch(broj) {
            case 0: {
                std::cout << "NaprijedNazad: " << std::endl;
                break;
            }
            case 1: {
                std::cout << "NazadNaprijed: " << std::endl;
                break;
            }
            case 2: {
                std::cout << "GoreDolje: " << std::endl;
                break;
            }
            case 3: {
                std::cout << "DoljeGore: " << std::endl;
                break;
            }
            case 4: {
                std::cout << "LijevoDesno: " << std::endl;
                break;
            }
            case 5: {
                std::cout << "DesnoLijevo: " << std::endl;
                break;
            }
        }
        for(int i(0); i<mat.size(); i++) {
            for(int j(0); j<mat.at(0).size(); j++)
                std::cout << std::right << std::setw(4) << mat[i][j];
            std::cout << std::endl;
        }
    }
    catch(std::domain_error a) {
        std::cout << "Izuzetak: " << a.what() << std::endl;
    }
	return 0;
}