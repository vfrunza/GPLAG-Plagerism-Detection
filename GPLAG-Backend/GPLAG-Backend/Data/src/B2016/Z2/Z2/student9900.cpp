// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>

enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };

auto IzdvojiDijagonale3D (Tip kont, SmjerKretanja(x)) -> decltype ()

int main () {
    int x, y, z;
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> x >> y >> z;
    std::vector<std::deque<std::deque<int>>> kont (x, std::deque<std::deque<int>> (y, std::deque<int> (z)));
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            for (int k=0; k<z; k++) {
                int x;
                std::cin >> x;
                kont[i][j][k]=x;
            }
        }
    }
    int d;
    std::cout << "Unesite smjer kretanja [0-5]: ";
    std::cin >> d;
    std::cout << std::endl << "DoljeGore" << ":" << std::endl;
    std::deque<std::deque<int>> m (IzdvojiDijagonale3D(kont, SmjerKretanja(d)));
    for (int i=0; i<m.size(); i++) {
        for (int j=0; j<m[i].size(); j++) {
            std::cout << std::setw(4) << m[i][j];
        }
        std::cout << std::endl;
    }
	return 0;
}