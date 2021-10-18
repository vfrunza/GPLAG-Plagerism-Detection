#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <type_traits>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

typedef std::vector<std::deque<std::deque<int>>> TipMain;

template<typename _3D>
auto IzdvojiDijagonale3D (_3D kont, SmjerKretanja smjer) 
    -> std::vector<std::deque<typename std::remove_reference<decltype(kont[0][0][0])>::type>> {
    // test matrice
    for(int i = 0; i < kont.size(); i++) {
        for(int j = 0; j < kont[0].size(); j++) {
            if(kont[0][0].size() != kont[i][j].size()) 
                throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    for(int i = 0; i < kont.size(); i++) {
        if(kont[0].size() != kont[i].size()) 
            throw std::domain_error("Plohe nemaju isti broj redova");
    }
    
    std::vector<std::deque<typename std::remove_reference<decltype(kont[0][0][0])>::type>> m;
    std::deque<typename std::remove_reference<decltype(kont[0][0][0])>::type> pomocni;
    
    if(smjer == SmjerKretanja::NaprijedNazad) {
        for(int i = 0; i < kont.size(); i++) {
            for(int j = 0; j < kont[0].size(); j++) {
                for(int k = 0; k < kont[0][0].size(); k++) {
                    if(j == k) pomocni.push_back(kont[i][j][k]);
                }
            }
            m.push_back(pomocni);
            pomocni.erase(pomocni.begin(), pomocni.end());
        }
    }
    else if(smjer == SmjerKretanja::NazadNaprijed) {
        for(int i = kont.size()-1; i >=0; i--) {
            for(int j = 0; j < kont[0].size(); j++) {
                for(int k = 0; k < kont[0][0].size() ; k++) {
                    if(j+k == kont[0][0].size()-1) pomocni.push_back(kont[i][j][k]);
                }
            }
            m.push_back(pomocni);
            pomocni.erase(pomocni.begin(), pomocni.end());
        }        
    }
    else if(smjer == SmjerKretanja::GoreDolje) {
        bool zavrseno = false;
        for(int i = kont.size()-1; i >= 0 ; i--) {
            for(int j = 0; j < kont[0][0].size(); j++) {
                for(int k = 0; k < kont[0].size(); k++) {
                    if(j == 0) {
                        pomocni.push_back(kont[i][k][j]);
                        pomocni.push_back(kont[i-1][k][j+1]);
                        m.push_back(pomocni);
                        pomocni.erase(pomocni.begin(), pomocni.end());
                    }
                    if(j > 0) zavrseno = true;
                }
            }
            if(zavrseno == true) break;
        }
    }
    else if(smjer == SmjerKretanja::DoljeGore) {
        bool zavrseno = false;
        for(int i = kont.size()-1; i >= 0 ; i--) {
            for(int j = kont[0][0].size()-1; j >=0 ; j--) {
                for(int k = kont[0].size()-1; k >=0;  k--) {
                    if(j == kont[0][0].size()-1) {
                        pomocni.push_back(kont[i][k][j]);
                        pomocni.push_back(kont[i-1][k][j-1]);
                        m.push_back(pomocni);
                        pomocni.erase(pomocni.begin(), pomocni.end());
                    }
                    if(j < kont[i][0].size()-1) zavrseno = true;
                }
            }
            if(zavrseno == true) break;
        }
    }
    else if(smjer == SmjerKretanja::LijevoDesno) {
        for(int k = 0; k < kont[0][0].size(); k++) {
                for(int i = kont.size() - 1, j = 0; i >= 0 && j < kont[0].size(); i--, j++) {
                    pomocni.push_back(kont[i][j][k]);
                }
                m.push_back(pomocni);
                pomocni.erase(pomocni.begin(), pomocni.end());
            }
    }
    else if(smjer == SmjerKretanja::DesnoLijevo) {
        for(int k = kont[0][0].size()-1; k >=0 ; k--) {
            for(int i = 0, j = 0; i < kont.size() && j < kont[0].size(); i++, j++) {
                pomocni.push_back(kont[i][j][k]);
            }
            m.push_back(pomocni);
            pomocni.erase(pomocni.begin(), pomocni.end());
        }
    }
    
    return m;
}

int main() {
    std::cout << "Unesite dimenzije (x y z): ";
    int x; int y; int z;
    std::cin >> x >> y >> z;
    
    if(x < 0 || y < 0 || z < 0) {
        std::cout << "Neispravne dimenzije kontejnera!\n";
        return 0;
    }
    
    TipMain kont(x, std::deque<std::deque<int>>(y, std::deque<int> (z)));
    std::cout << "Unesite elemente kontejnera:\n";
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            for(int k = 0; k < z; k++) {
                std::cin >> kont[i][j][k];
            }
        }
    }
    
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    int smjer_broj;
    std::cin >> smjer_broj;
    auto m = IzdvojiDijagonale3D(kont, SmjerKretanja::NaprijedNazad);
    if(smjer_broj == 0) {
        m = IzdvojiDijagonale3D(kont, SmjerKretanja::NaprijedNazad);
        std::cout << "NaprijedNazad:\n";
    }
    else if(smjer_broj == 1) {
        m = IzdvojiDijagonale3D(kont, SmjerKretanja::NazadNaprijed);
        std::cout << "NazadNaprijed:\n";
    }
    else if(smjer_broj == 2) {
        m = IzdvojiDijagonale3D(kont, SmjerKretanja::GoreDolje);
        std::cout << "GoreDolje:\n";
    }
    else if(smjer_broj == 3) {
        m = IzdvojiDijagonale3D(kont, SmjerKretanja::DoljeGore);
        std::cout << "DoljeGore:\n";
    }
    else if(smjer_broj == 4) {
        m = IzdvojiDijagonale3D(kont, SmjerKretanja::LijevoDesno);
        std::cout << "LijevoDesno:\n";
    }
    else if(smjer_broj == 5) {
        m = IzdvojiDijagonale3D(kont, SmjerKretanja::DesnoLijevo);
        std::cout << "DesnoLijevo:\n";        
    }
    else {
        std::cout << "Smjer kretanja nije ispravan!\n";
        return 0;
    }
    
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            std::cout << std::setw(4) << m[i][j];
        }
        std::cout << std::endl;
    }
    
    return 0;
}