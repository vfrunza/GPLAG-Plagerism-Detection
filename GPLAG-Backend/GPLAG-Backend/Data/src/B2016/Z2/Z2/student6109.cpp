// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

std::vector<std::vector<int>>IzdvojiDijagonale3D(std::vector<std::vector<std::vector<int>>>kont, ) {
    int red;
    int kolona;
    int dubina;
    
    red=kont.size();
    kolona=kont[0].size();
    dubina=kont[0][0].size();
    
    if(red!=kolona) throw domain_error ("Redovi nemaju isti broj elemenata");
    if(red!=dubina) throw domain_error ("Plohe nemaju isti broj redova");
    std::vector<std::vector<int>>Trazeno;
    
    for(int )
    
    return Trazeno;
}

int main () {
    try {
    int x, y, z;
    int broj;
    
    std::vector<std::vector<std::vector<int>>> Matrica;
    std::cout << "Unesite dimenzije (x, y, z): ";
    std::cin >> x >> y >> z;

    Matrica.resize(y);
    for(int i=0; i<y; i++) {
        Matrica[i].resize(z);
        for(int j=0; j<z; j++) {
            Matrica[i][j].resize(x);
        }
    }
    
    std::cout << "Unesite elemente kontejnera: " << std::endl;
    for(int i=0; i<z; i++) {
        for(int j=0; j<y; j++) {
            for(int k=0; k<x; k++) {
                std::cin >> broj;
                Matrica[i][j][k]=broj;
            }
        }
    }
    std::cout << "Unesite smjer kretanja [0-5]: ";
    int smjer;
    std::cin >> smjer;
    std::cout << SmjerKretanja::smjer;
    std::vector<std::vector<int>>Rez;
    rez=IzdvojiDijagonale3D(Matrica, smjer);
    
    } catch (std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    for(int i=0; i<rez.size(); i++) {
        for(int j=0; j<rez[i].size(); j++) {
            std::cout << std::setw(4) << std::right << rez[i][j];
        }
        std::cout << std::endl;
    }
	return 0;
}