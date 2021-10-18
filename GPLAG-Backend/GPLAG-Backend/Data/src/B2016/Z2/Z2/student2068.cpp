// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <type_traits>
#include <stdexcept>
#include <vector>
#include <deque>
#include <string>
#include <iomanip>

enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };

int min(int x, int y) { if(x<y) return x; return y; }

void Koordinatizuj(int &a, int &b, int &c, SmjerKretanja smjer, int dubina, int visina, int sirina) {
    if(smjer==SmjerKretanja::NazadNaprijed) {
        a=dubina-1-a; c=sirina-1-c;
    }
    else if(smjer==SmjerKretanja::GoreDolje) {
        int pomocna(b);
        b=a; a=dubina-1-pomocna;
    }
    else if(smjer==SmjerKretanja::DoljeGore) {
        int pomocna(b);
        b=visina-1-a; a=dubina-1-pomocna; c=sirina-1-c;
    }
    else if(smjer==SmjerKretanja::LijevoDesno) {
        int pomocna(c);
        c=a; a=dubina-1-pomocna;
    }
    else if(smjer==SmjerKretanja::DesnoLijevo) {
        int pomocna(c);
        c=sirina-1-a; a=pomocna;
    }
}

template <typename Tip> 
auto IzdvojiDijagonale3D(Tip kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type {
    typename std::remove_reference<decltype(kont.at(0))>::type matrica;
    int dubina(kont.size()), visina, sirina;
    
    if(dubina==0) return matrica;
    visina=kont.at(0).size();
    
    for(int i=1; i<dubina; i++)  if(kont.at(i).size() != visina) throw std::domain_error("Plohe nemaju isti broj redova");
    
    if(visina==0) return matrica;
    sirina=kont.at(0).at(0).size();
    
    for(int i=1; i<dubina; i++) {
        for(int j=0; j<visina; j++) {
            if(kont.at(i).at(j).size() != sirina) throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    
    if(sirina==0) return matrica;
    
    int max_dubina(0), max_2(0);
     
    if(smjer==SmjerKretanja::NaprijedNazad || smjer==SmjerKretanja::NazadNaprijed) {
        max_dubina=dubina; max_2=min(visina, sirina);
    }
    else if(smjer==SmjerKretanja::GoreDolje || smjer==SmjerKretanja::DoljeGore) {
        max_dubina=visina; max_2=min(dubina, sirina);
    }
    else if(smjer==SmjerKretanja::LijevoDesno || smjer==SmjerKretanja::DesnoLijevo) {
        max_dubina=sirina; max_2=min(visina, dubina);
    }
    
    for(int i=0; i<max_dubina; i++) {
        
        typename std::remove_reference<decltype(kont.at(0).at(0))>::type red;
        
        for(int j=0; j<max_2; j++) {
            int prva(i), druga(j), treca(j);
            Koordinatizuj(prva, druga, treca, smjer, dubina, visina, sirina);
            red.push_back(kont.at(prva).at(druga).at(treca));
        }
        matrica.push_back(red);
    }
    return matrica;
}

int main () {
    std::cout << "Unesite dimenzije (x y z): ";
    int x, y, z; std::cin >> x >> y >> z;
    if(x<=0 || y<=0 || z<=0) {
        std::cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::cout << "Unesite elemente kontejnera: \n";
    std::vector<std::deque<std::deque<int>>>kontejner;
    
    kontejner.resize(x);
    for(int i=0; i<x; i++) kontejner.at(i).resize(y);
    for(int i=0; i<x; i++) for(int j=0; j<y; j++) kontejner.at(i).at(j).resize(z);
    
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            for(int k=0; k<z; k++) {
                std::cin >> kontejner.at(i).at(j).at(k);
            }
        }
    }
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    int u; std::cin >> u; 
    if(u<0 || u>5) {
        std::cout << "Smjer kretanja nije ispravan!\n";
        return 0;
    }
    std::string s="NaprijedNazad: ";
    SmjerKretanja smjer=SmjerKretanja::NaprijedNazad;
    if(u==1) { smjer=SmjerKretanja::NazadNaprijed; s="NazadNaprijed: "; }
    else if(u==2) { smjer=SmjerKretanja::GoreDolje; s="GoreDolje: "; }
    else if(u==3) { smjer=SmjerKretanja::DoljeGore; s="DoljeGore: "; }
    else if(u==4) { smjer=SmjerKretanja::LijevoDesno; s="LijevoDesno: "; }
    else if(u==5) { smjer=SmjerKretanja::DesnoLijevo; s="DesnoLijevo: "; }
    
    auto matrica=IzdvojiDijagonale3D(kontejner, smjer);
    
    std::cout << s << "\n";
    for(int i=0; i<matrica.size(); i++) {
        for(int j=0; j<matrica.at(0).size(); j++) {
            std::cout << std::setw(4) << matrica.at(i).at(j);
        }
        std::cout << "\n";
    }
    return 0;
}