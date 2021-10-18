#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};


template <typename tip>
auto makni_referencu(tip &referenca, tip bez_reference) -> decltype(bez_reference) {
    return bez_reference;
}

template <typename Kontejner>
auto IzdvojiDijagonale3D(Kontejner kont, SmjerKretanja smjer) -> decltype(makni_referencu(kont.at(0), kont.at(0))) {
    decltype(makni_referencu(kont.at(0), kont.at(0))) r;
    if (kont.size() == 0) return r;
    if (kont.at(0).size() == 0) return r;
    if (kont.at(0).at(0).size() == 0) return r;
    
    for (int i = 1; i < kont.size(); i++) {
        if (kont.at(i).size() != kont.at(0).size()) throw std::domain_error("Plohe nemaju isti broj redova");
    }
    for (int i = 0; i < kont.size(); i++) {
        for (int j = 0; j < kont.at(0).size(); j++) {
            if (kont.at(i).at(j).size() != kont.at(0).at(0).size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }

    int X(kont.size()), Y(kont.at(0).size()), Z(kont.at(0).at(0).size());
    int s = (int) smjer, n, m, i, j;

    if (s < 2) n = X, m = std::min(Y, Z);
    else if (s < 4) n = Y, m = std::min(X, Z);
    else n = Z, m = std::min(X, Y);
    
    decltype(makni_referencu(kont.at(0).at(0), kont.at(0).at(0))) prazan1d;
    for (int i = 0; i < n; i++) r.push_back(prazan1d);
    
    if (smjer == SmjerKretanja::NaprijedNazad)
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                r[i].push_back(kont.at(i).at(j).at(j));
            }
        }
    else if (smjer == SmjerKretanja::NazadNaprijed)
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                r[i].push_back(kont.at(X - i - 1).at(j).at(Z - j - 1));
            }
        }
    else if (smjer == SmjerKretanja::GoreDolje)
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                r[i].push_back(kont.at(X - j - 1).at(i).at(j));
            }
        }
    else if (smjer == SmjerKretanja::DoljeGore)
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                r[i].push_back(kont.at(X - j - 1).at(Y - i - 1).at(Z - j - 1));
            }
        }
    else if (smjer == SmjerKretanja::LijevoDesno)
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                r[i].push_back(kont.at(X - j - 1).at(j).at(i));
            }
        }
    else if (smjer == SmjerKretanja::DesnoLijevo)
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                r[i].push_back(kont.at(j).at(j).at(Z - i - 1));
            }
        }
        
    return r;
}

int main() {
    int a, b, c;
    std::cout << "Unesite dimenzije (x y z): ";
    
    while (std::cin >> a >> b >> c, a < 1 || b < 1 || c < 1) {
    	std::cout << "Neispravne dimenzije kontejnera!" << std::endl;
    	return 0;
	}
	
    std::cout << "Unesite elemente kontejnera:\n";
    std::vector<std::deque<std::deque<int>>> wuhu(a, std::deque<std::deque<int>>(b, std::deque<int>(c)));
    
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            for (int k = 0; k < c; k++) std::cin >> wuhu[i][j][k];
            
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    int s;
    while (std::cin >> s, s < 0 || s > 5) {
        std::cout << "Smjer kretanja nije ispravan!" << std::endl;
        return 0;
    }
    
    if (s == 0) std::cout << "NaprijedNazad";
    else if (s == 1) std::cout << "NazadNaprijed";
    else if (s == 2) std::cout << "GoreDolje";
    else if (s == 3) std::cout << "DoljeGore";
    else if (s == 4) std::cout << "LijevoDesno";
    else if (s == 5) std::cout << "DesnoLijevo";
    std::cout << ":" << std::endl;

    try {
        auto r = IzdvojiDijagonale3D(wuhu, (SmjerKretanja) s);
        for (int i = 0; i < r.size(); i++) {
            for (int j = 0; j < r[i].size(); j++) {
                std::cout << std::setw(4) << r[i][j];
            }
            
            std::cout << std::endl;
        }
    }
    catch (std::domain_error e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}