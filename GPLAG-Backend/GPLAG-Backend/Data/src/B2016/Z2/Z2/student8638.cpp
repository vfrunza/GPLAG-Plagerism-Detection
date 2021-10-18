// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <iomanip>
#include <deque>

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
/*
template<typename tip1, typename tip2>
auto IzdvojiDijagonale3D( tip1<tip2>>> kont, SmjerKretanja smjer){
    
}
*/

int main (){
    std::cout << "Unesite dimenzije (x y z): ";
    int x, y, z;
    std::cin >> x >> y >> z;
    
    std::vector<std::deque<std::deque<int>>> kont;
    std::deque<int> temp1;
    std::deque<std::deque<int>> temp2;
    int element;
    
    std::cout << "Unesite elemente kontejnera: ";
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                std::cin >> element;
                temp1.push_back(element);
            }
            temp2.push_back(temp1);
            temp1.clear();
        }
        kont.push_back(temp2);
        temp2.clear();
    }
    
    
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    std::cin >> element;
    SmjerKretanja smjer;
    
    if(element == 0){
        smjer = SmjerKretanja::NaprijedNazad;
        std::cout << "NaprijedNazad: ";
    }
    if(element == 1){
        smjer = SmjerKretanja::NazadNaprijed;
        std::cout << "NazadNaprijed: ";
    }
    if(element == 2){
        smjer = SmjerKretanja::GoreDolje;
        std::cout << "GoreDolje: ";
    }
    if(element == 3){
        smjer = SmjerKretanja::DoljeGore;
        std::cout << "DoljeGore: ";
    }
    if(element == 4){
        smjer = SmjerKretanja::LijevoDesno;
        std::cout << "LijevoDesno: ";
    }
    if(element == 5){
        smjer = SmjerKretanja::DesnoLijevo;
        std::cout << "DesnoLijevo: ";
    }
    
    
	return 0;
}