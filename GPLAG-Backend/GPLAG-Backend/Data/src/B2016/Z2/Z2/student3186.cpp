// B 16/17, Zadaća 2, Zadatak 2
#include <type_traits>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Kont_Tip>
    void Obrni (Kont_Tip &kont_2D) {
        for (int i=0, k=kont_2D.size()-1; i<(kont_2D.size()/2); ++i, --k)
            for (int j=0; j<kont_2D[i].size(); ++j)
                std::swap (kont_2D[i][j], kont_2D[k][j]);
    }

template <typename Kont_Tip>
    auto IzdvojiDijagonale3D (Kont_Tip kont_3D, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont_3D[0])>::type
    {
        typename std::remove_reference<decltype(kont_3D[0])>::type kont_2D;
        if (smjer == SmjerKretanja::NaprijedNazad or smjer == SmjerKretanja::NazadNaprijed) {
            for (int i=0; i<kont_3D.size(); ++i) {
                typename std::remove_reference<decltype(kont_3D[0][0])>::type temp;
                for (int j=0; j<kont_3D[i].size(); ++j) {
                    for (int k=0; k<kont_3D[i][j].size(); ++k) {
                        if (smjer == SmjerKretanja::NaprijedNazad and j == k) 
                            temp.push_back(kont_3D[i][j][k]);
                        else if (smjer == SmjerKretanja::NazadNaprijed and j == kont_3D[i][j].size() - k - 1) 
                            temp.push_back(kont_3D[i][j][k]);
                    }
                }   kont_2D.push_back(temp);
            }   if (smjer == SmjerKretanja::NazadNaprijed)  Obrni(kont_2D);
        }
        else if (smjer == SmjerKretanja::GoreDolje or smjer == SmjerKretanja::DoljeGore) {
            for (int j=0; j<kont_3D[0].size(); ++j) {
                typename std::remove_reference<decltype(kont_3D[0][0])>::type temp;
                for (int i=kont_3D.size()-1; i>=0; --i) {
                    for (int k=0; k<kont_3D[0][0].size(); ++k) {
                        if (smjer == SmjerKretanja::GoreDolje and k == kont_3D.size() - i - 1)
                            temp.push_back(kont_3D[i][j][k]);
                        else if (smjer == SmjerKretanja::DoljeGore and (kont_3D[0][0].size() - k - 1 == kont_3D.size() - i - 1))
                            temp.push_back(kont_3D[i][j][k]);
                    }
                }   kont_2D.push_back(temp);
            }   if (smjer == SmjerKretanja::DoljeGore)  Obrni(kont_2D);
        }
        else if (smjer == SmjerKretanja::LijevoDesno or smjer == SmjerKretanja::DesnoLijevo) {
            for (int k=0; k<kont_3D[0][0].size(); ++k) {
                typename std::remove_reference<decltype(kont_3D[0][0])>::type temp;
                for (int j=0; j<kont_3D[0].size()-1; ++j) {
                    for (int i=kont_3D.size()-1; i>=0; --i) {
                        if (smjer == SmjerKretanja::LijevoDesno and (j == kont_3D.size() - i - 1))
                            temp.push_back(kont_3D[i][j][k]);
                        else if (smjer == SmjerKretanja::DesnoLijevo and j == i)
                            temp.push_back(kont_3D[i][j][k]);
                    }
                }   kont_2D.push_back(temp);
            }   if (smjer == SmjerKretanja::DesnoLijevo)  Obrni(kont_2D);   
        }
        return kont_2D;
    }

int main ()
{
    int x,y,z;
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> x >> y >> z;
    
    if (x < 0 or y < 0 or z < 0)    std::cout << "Neispravne dimenzije kontejnera!";
    else {      // Input..
        std::vector<std::deque<std::deque<int>>> input (x, std::deque<std::deque<int>> (y, std::deque<int> (z)));
        std::cout << "Unesite elemente kontejnera: " << std::endl;
        for (int i=0; i<x; ++i)
            for (int j=0; j<y; ++j)
                for (int k=0; k<z; ++k)
                    std::cin >> input[i][j][k];
        
        int broj_smjera;
        SmjerKretanja smjer;
        std::cout << "Unesite smjer kretanja [0 - 5]: ";
        std::cin >> broj_smjera;
        
        if (broj_smjera == 0)       smjer = SmjerKretanja::NaprijedNazad;
        else if (broj_smjera == 1)  smjer = SmjerKretanja::NazadNaprijed;
        else if (broj_smjera == 2)  smjer = SmjerKretanja::GoreDolje;
        else if (broj_smjera == 3)  smjer = SmjerKretanja::DoljeGore;
        else if (broj_smjera == 4)  smjer = SmjerKretanja::LijevoDesno;
        else if (broj_smjera == 5)  smjer = SmjerKretanja::DesnoLijevo;
        else {  std::cout << "Smjer kretanja nije ispravan!" << std::endl;  return 0;   }
        
        if (broj_smjera == 0)       std::cout << "NaprijedNazad: " << std::endl;
        else if (broj_smjera == 1)  std::cout << "NazadNaprijed: " << std::endl;
        else if (broj_smjera == 2)  std::cout << "GoreDolje: "     << std::endl;
        else if (broj_smjera == 3)  std::cout << "DoljeGore: "     << std::endl;
        else if (broj_smjera == 4)  std::cout << "LijevoDesno: "   << std::endl;
        else if (broj_smjera == 5)  std::cout << "DesnoLijevo: "   << std::endl;
        // Izlaz na ekran..
        for (const auto &red : IzdvojiDijagonale3D (input, smjer)) {
            for (const auto &x : red)   std::cout << std::setw(4) << x;
            std::cout << std::endl;
        }
    }   return 0;
}