// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	


#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <type_traits>
#include <iomanip>
#include <stdexcept>

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};


template <typename tip1>
auto IzdvojiDijagonale3D (tip1 kont, SmjerKretanja s) -> typename std::remove_reference<decltype(kont.at(0))>::type {
    
    int duz1 = kont.size();
    int duz2 = (kont.at(0)).size();
    int duz3 = ((kont.at(0)).at(0)).size();
    
    for (int i = 1; i < duz1; i++) if ( (kont.at(i)).size() != duz2 ) throw std::domain_error ("Plohe nemaju isti broj redova");
    for (int i = 0; i < duz1; i++) {
        for (int j = 1; j <duz2; j++) {
            if ( ((kont.at(i)).at(j)).size() != duz3 ) throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    
    
    typename std::remove_reference< decltype(kont.at(0))>::type d;
    
    if (s == SmjerKretanja::NaprijedNazad) {
        
        for (int i = 0; i < duz1; i++) {
            typename std::remove_reference< decltype(((kont.at(0)).at(0)))>::type v;
            for (int j = 0; j < duz2; j++) {
                for (int k = 0; k < duz3; k++) {
                    if (j < duz2 && k < duz3 && k == j) v.push_back(((kont.at(i)).at(j)).at(k));
                }
            }
            d.push_back(v);
        }
        
    }
    
    
    if (s == SmjerKretanja::NazadNaprijed) {
        
        for (int i = duz1-1; i >= 0; i--) {
            typename std::remove_reference< decltype(((kont.at(0)).at(0)))>::type v;
            for (int j = 0; j < duz2; j++) {
                for (int k = 0; k < duz3; k++) {
                    if (j < duz2 && k < duz3 && k+j==duz3-1) v.push_back(((kont.at(i)).at(j)).at(k));
                }
            }
            d.push_back(v);
        }
        
    }
    
    
    if (s == SmjerKretanja::DesnoLijevo) {
        
        for (int k = duz3-1; k >= 0; k--) {
            typename std::remove_reference< decltype(((kont.at(0)).at(0)))>::type v;
            for (int j = 0; j < duz2; j++) {
                for (int i = 0; i < duz1; i++) {
                    if (j < duz2 && i < duz1 && i == j) v.push_back(((kont.at(i)).at(j)).at(k));
                }
            }
            d.push_back(v);
        }
        
    }
    
    
     if (s == SmjerKretanja::LijevoDesno) {
        
        for (int k = 0; k < duz3; k++) {
            typename std::remove_reference< decltype(((kont.at(0)).at(0)))>::type v;
            for (int j = 0; j < duz2; j++) {
                for (int i = 0; i < duz1; i++) {
                    if (j < duz2 && i < duz1 && i+j == duz1-1) v.push_back(((kont.at(i)).at(j)).at(k));
                }
            }
            d.push_back(v);
        }
        
    }
    
    

     if (s == SmjerKretanja::GoreDolje) {
        
        for (int j = 0; j < duz2; j++) {
            typename std::remove_reference< decltype(((kont.at(0)).at(0)))>::type v;
            for (int i = duz1-1; i >= 0; i--) {
                for (int k = 0; k < duz3; k++) {
                    if (i < duz1 && k < duz3 && k+i == 1) v.push_back(((kont.at(i)).at(j)).at(k));
                }
            }
            d.push_back(v);
        }
        
    }

    
    if (s == SmjerKretanja::DoljeGore) {
        
        for (int j = duz2-1; j >= 0; j--) {
            typename std::remove_reference< decltype(((kont.at(0)).at(0)))>::type v;
            for (int i = duz1-1; i >= 0; i--) {
                for (int k = 0; k < duz3; k++) {
                    if (i < duz1 && k < duz3 && k-i == duz3-duz1) v.push_back(((kont.at(i)).at(j)).at(k));
                }
            }
            d.push_back(v);
        }
        
    }
    
    return d;
}



int main () {
    
    
    std::vector<std::deque<std::deque<int>>> v;
    
    int a, b, c, n;
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    if (a < 0 || b < 0 || c < 0) { std::cout << "Neispravne dimenzije kontejnera!" <<std::endl; return 0; }
    
    v.resize(a);
    for (int i = 0; i < a; i++) v[i].resize(b);
    
    std::cout << "Unesite elemente kontejnera: ";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                int x;
                std::cin >> x;
                (v[i][j]).push_back(x);
            }
        }
    }
    
    
    std::cout << std::endl << "Unesite smjer kretanja [0 - 5]: ";
    std::cin >> n;
    
    SmjerKretanja s(SmjerKretanja::NaprijedNazad);
    if (n == 0) { s = SmjerKretanja::NaprijedNazad; std::cout << "NaprijedNazad: " << std::endl; }
    else if (n == 1) { s = SmjerKretanja::NazadNaprijed; std::cout << "NazadNaprijed: " << std::endl; }
    else if (n == 2) { s = SmjerKretanja::GoreDolje; std::cout << "GoreDolje: " << std::endl; }
    else if (n == 3) { s = SmjerKretanja::DoljeGore; std::cout << "DoljeGore: " << std::endl; }
    else if (n == 4) { s = SmjerKretanja::LijevoDesno; std::cout << "LijevoDesno: " << std::endl; }
    else if (n == 5) { s = SmjerKretanja::DesnoLijevo; std::cout << "DesnoLijevo: " << std::endl; }
    else { std::cout << "Smjer kretanja nije ispravan!" << std::endl; return 0; }
    std::deque<std::deque<int>> v1 = IzdvojiDijagonale3D(v, s);
    
        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v1[0].size(); j++) {
                    std::cout << std::setw(4) << v1[i][j];
            }
            std::cout << std::endl;
        }
    
	return 0;
}