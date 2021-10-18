// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <type_traits>
#include <iomanip>


enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Tip3D>
auto IzdvojiDijagonale3D (Tip3D Kocka,const SmjerKretanja &smjer) -> typename std::remove_reference<decltype(Kocka[0])>::type {
    typename std::remove_reference<decltype(Kocka[0])>::type Matrica(0);
    bool flag1(true),flag2(true);
    int duzina(0),sirina(0);

    for (auto i : Kocka) {
        if (flag1) {
            duzina = i.size();
            flag1 = false;
        } else if (duzina != i.size()) throw std::domain_error ("Plohe nemaju isti broj redova");
        for (auto i2 : i) {
            if (flag2) {
                sirina = i2.size();
                flag2 = false;
            } else if (sirina != i2.size()) throw std::domain_error ("Redovi nemaju isti broj elemenata");
        }
    }
    if (Kocka.size()== 0 or Kocka[0].size() == 0 or Kocka[0][0].size() == 0) return Matrica;

    if (smjer == SmjerKretanja::NaprijedNazad or smjer == SmjerKretanja::NazadNaprijed ) {
        Matrica.resize(Kocka.size());
        for (auto &i : Matrica) {
            i.resize(Kocka[0].size());
        }
    } else if (smjer == SmjerKretanja::GoreDolje or smjer == SmjerKretanja::DoljeGore ) {
        Matrica.resize(Kocka[0].size());
        for (auto &i : Matrica) {
            i.resize(Kocka.size());
        }
    } else if (smjer == SmjerKretanja::DesnoLijevo or smjer == SmjerKretanja::LijevoDesno ) {
        Matrica.resize(Kocka[0][0].size());
        for (auto &i : Matrica) {
            i.resize(Kocka.size());
        }
    }

    for (int i = 0; i < Kocka.size(); i++) {
        for (int j = 0; j < Kocka[i].size(); j++) {
            for (int k = 0; k < Kocka[i][j].size(); k++) {
                if (i == j and smjer == SmjerKretanja::LijevoDesno) Matrica[k][i] = Kocka[Kocka.size()-1-i][j][k];// LijevoDesno
                if (i == j and smjer == SmjerKretanja::DesnoLijevo) Matrica[k][i] = Kocka[i][j][Kocka[i][j].size()-1-k];// DesnoLijevo
                if (i == k and smjer == SmjerKretanja::GoreDolje) Matrica[j][i] = Kocka[Kocka.size()-1-i][j][k];// GOREDOLJE
                if (i == k and smjer == SmjerKretanja::DoljeGore) Matrica[j][i] = Kocka[Kocka.size()-1-i][Kocka[i].size()-1-j][Kocka[i][j].size()-1-k]; //DOLJEGORE
                if (j == k and smjer == SmjerKretanja::NazadNaprijed) Matrica[i][j] = Kocka[Kocka.size()-1-i][j][Kocka[i][j].size()-1-k]; // NAZADNAP
                if (j == k and smjer == SmjerKretanja::NaprijedNazad) Matrica[i][j] = Kocka[i][j][k]; // NAPRIJED NAZAD
            }
        }
    }
    return Matrica;
}

int main ()
{
    std::cout << "Unesite dimenzije (x y z): ";
    int x,y,z;
    std::cin >> x >> y >> z;
    if (x < 0 or y < 0 or z < 0) {
        std::cout << "Neispravne dimenzije kontejnera!" << std::endl;
        return 0;
    }
    std::vector<std::deque<std::deque<int> > > Kocka(x,std::deque<std::deque<int> >(y,std::deque<int>(z)));
    std::cout << "Unesite elemente kontejnera: " << std::endl;
    for (auto &i : Kocka) {
        for (auto &i2 : i) {
            for (auto &i3 : i2) {
                std::cin >> i3;
            }
        }
    }
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    int n;
    std::cin >> n;
    if (n < 0 or n > 5) {
        std::cout << "Smjer kretanja nije ispravan!" << std::endl;
        return 0;
    }
    try {
        /* code */


        std::deque<std::deque<int>> Matrica(IzdvojiDijagonale3D(Kocka,SmjerKretanja(n)));
        switch (n) {
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

        }
        for (auto i : Matrica) {
            for (auto i2 : i) {
                std::cout << std::setw(4) << i2;
            }
            std::cout  << std::endl;
        }
    } catch (std::domain_error e) {

    }
}
