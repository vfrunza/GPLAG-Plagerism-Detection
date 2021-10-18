#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <string>
#include <type_traits>
#include <stdexcept>
//
enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template <typename T>
    auto IzdvojiDijagonale3D (T kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type {
        
        typedef typename std::remove_reference<decltype(kont.at(0))>::type Tip;
        Tip vrati;
        
        int tabla, red, kolona;
        try { // dim (0,0,0)
            tabla = kont.size();
            red = kont.at(0).size();
            kolona = kont.at(0).at(0).size();
        } catch(std::out_of_range err) {
            return vrati;
        }
        
        //uvjeti
        for (int i = 0; i < kont.size(); i++) {
            for (int j = 0; j < kont.at(i).size(); j++) {
                int rfr = kont.at(0).at(0).size();
                int num = kont.at(i).at(j).size();
                if (num!=rfr) throw std::domain_error("Redovi nemaju isti broj elemenata");
            }
        }
        for (int i = 0; i < kont.size(); i++) {
            int ref = kont.at(0).size();        //broj redova u plohi 0
            int tmp = kont.at(i).size();
            if (ref != tmp) throw std::domain_error("Plohe nemaju isti broj redova");
        }
        /*
        int tabla, red, kolona;
        try {
            tabla   = kont.size();              //broj ploha/tabli
            red     = kont.at(0).size();        //broj redova u plohi 0
            kolona  = kont.at(0).at(0).size();  //broj kolona u plohi 0 u redu 0
        } catch (std::out_of_range err) {
            return vrati;
        }
        */
        if (smjer == SmjerKretanja::NaprijedNazad) {
            vrati.resize(tabla);
            for (int i = 0; i < tabla; i++) for (int j = 0; j < red; j++) for (int k = 0; k < kolona; k++)
                    if (j == k) vrati.at(i).push_back(kont.at(i).at(j).at(k));
        }
        if (smjer == SmjerKretanja::NazadNaprijed) {
            vrati.resize(tabla);
            for (int i = tabla-1; i >= 0; i--) for (int j = 0; j < red; j++) for (int k = kolona-1; k >= 0; k--) 
                    if (j+k == kolona-1) vrati.at(tabla-1-i).push_back(kont.at(i).at(j).at(k));
        }
        if (smjer == SmjerKretanja::GoreDolje) {
            vrati.resize(red);
            for (int i = tabla-1; i >= 0; i--) for (int j = 0; j < red; j++) for (int k = 0; k < tabla; k++)
                    if (tabla-1 == k+i) vrati.at(j).push_back(kont.at(i).at(j).at(k)); 
        }
        if (smjer == SmjerKretanja::DoljeGore) {
            vrati.resize(red);
            for (int i = tabla-1; i >=0; i--) for (int j = red-1; j >= 0; j--) for (int k = kolona-1; k >= kolona-tabla; k--)
                    if ((i+k)%2==0) vrati.at(red-1-j).push_back(kont.at(i).at(j).at(k)); //%tabla zamijenjeno sa %2
        }
        if (smjer == SmjerKretanja::LijevoDesno) { 
            vrati.resize(kolona);
            for (int i = tabla-1; i >=0; i--) for (int j = 0; j < tabla; j++) for (int k = 0; k < kolona; k++)
                    if (i+j == tabla-1) vrati.at(k).push_back(kont.at(i).at(j).at(k));
        }
        if (smjer == SmjerKretanja::DesnoLijevo) {
            vrati.resize(kolona);
            for (int i = 0; i < tabla; i++) for (int j = 0; j < tabla; j++) for (int k = kolona-1; k >= 0; k--)
                    if (i==j) vrati.at(kolona-1-k).push_back(kont.at(i).at(j).at(k));
        }
        
        return vrati;
    }

int main () {

    std::cout << "Unesite dimenzije (x y z): ";
    int x, y, z;
    std::cin >> x >> y >> z;
    if (x < 0 || y < 0 || z < 0) {
        std::cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    
    std::vector<std::deque<std::deque<int>>> kontejner(x, std::deque<std::deque<int>>(y, std::deque<int>(z)));
    std::cout << "Unesite elemente kontejnera: " << std::endl;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++)
                std::cin >> kontejner.at(i).at(j).at(k);
    
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    int smjer_int;
    std::cin >> smjer_int;
    SmjerKretanja smjer;
    
    if (smjer_int == 0) {
        smjer = SmjerKretanja::NaprijedNazad;
        std::cout << "NaprijedNazad:" << std::endl;
    } else if (smjer_int == 1) {
        smjer = SmjerKretanja::NazadNaprijed;
        std::cout << "NazadNaprijed:" << std::endl;
    } else if (smjer_int == 2) {
        smjer = SmjerKretanja::GoreDolje;
        std::cout << "GoreDolje:" << std::endl;
    } else if (smjer_int == 3) {
        smjer = SmjerKretanja::DoljeGore;
        std::cout << "DoljeGore:" << std::endl;
    } else if (smjer_int == 4) {
        smjer = SmjerKretanja::LijevoDesno;
        std::cout << "LijevoDesno:" << std::endl;
    } else if (smjer_int == 5) {
        smjer = SmjerKretanja::DesnoLijevo;
        std::cout << "DesnoLijevo:" << std::endl;
    } else {
        std::cout << "Smjer kretanja nije ispravan!" << std::endl;
        return 0;
    }
    
    /* //manualno testiranje
    std::deque<std::vector<std::deque<std::string>>> kontejner = {
        {
            {"AT6", "Dva"},
            {"AT4", "Cetiri"},
            {"AT2", "Sest"}
        },
        {
            {"Jedan", "AT5"},
            {"Tri", "AT3"},
            {"Pet", "AT1"}
        }
    };
    
    auto smjer = SmjerKretanja::DoljeGore;*/
    try {
        auto ispisi = IzdvojiDijagonale3D(kontejner, smjer);
        for (int i = 0; i < ispisi.size(); i++) {
            for (int j = 0; j < ispisi.at(i).size(); j++) {
                std::cout << std::setw(4) << ispisi.at(i).at(j);
            }
            std::cout << std::endl;
        }
    } catch (std::domain_error err) {
        std::cout << "IZUZETAK: " << err.what() << std::endl;
    }
	return 0;
}