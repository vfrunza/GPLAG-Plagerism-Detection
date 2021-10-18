#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <type_traits>
#include <string>
#include <iomanip>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
std::string SmjerKretanjaTekst[] {
        "NaprijedNazad", "NazadNaprijed", "GoreDolje", "DoljeGore", "LijevoDesno", "DesnoLijevo"
};
template <typename Kontejner3D>
auto IzdvojiDijagonale3D(Kontejner3D ludara, SmjerKretanja smjer) -> typename std::remove_reference<decltype(ludara.at(0))>::type {
    typedef typename std::remove_reference<decltype(ludara.at(0))>::type MatTip;
    MatTip dijagonale;
    // Provjera
    if(!ludara.size()) return dijagonale;
    int broj_redova(-1), broj_kolona(-1);
    for(int i(0); i < ludara.size(); i++){
        //Provjera da li matrice imaju isti broj redova
        if(broj_redova == -1) broj_redova = ludara.at(i).size();
        if(ludara.at(i).size() != broj_redova) throw std::domain_error("Plohe nemaju isti broj redova");
        int broj_kolona_matrice(-1);
        //Provjera da je matrica pravilna
        for(int j(0); j < ludara.at(i).size(); j++){
            if(broj_kolona_matrice == -1) broj_kolona_matrice = ludara.at(i).at(j).size();
            if(broj_kolona_matrice != ludara.at(i).at(j).size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
        //Provjera da li matrice imaju isti broj kolona
        if (broj_kolona == -1) broj_kolona = broj_kolona_matrice;
        if(broj_kolona != broj_kolona_matrice) throw std::domain_error("Redovi nemaju isti broj elemenata");
    }
    //////////////////////////////////////
    if(!broj_redova || !broj_kolona) return dijagonale;
    int index_dijagonale(0);
    int index_kolone(0);
    int index_reda(0);
    switch(int(smjer)){
        case 0:
            dijagonale.resize(ludara.size());
            for(int i(0); i < ludara.size(); i++){
                for(int j(0); j < ludara.at(0).size(); j++){
                    if(j >= ludara.at(i).at(j).size()) break;
                    dijagonale.at(i).push_back(ludara.at(i).at(j).at(j));
                }
            }
            break;
        case 1:
            dijagonale.resize(ludara.size());
            for(int i(ludara.size()-1); i >= 0; i--){
                index_kolone = broj_kolona-1;
                for(int j(0); j < ludara.at(i).size(); j++){
                    if(index_kolone < 0) break;
                    dijagonale.at(index_dijagonale).push_back(ludara.at(i).at(j).at(index_kolone));
                    index_kolone--;
                }
                index_dijagonale++;
            }
            break;
        case 2:
            dijagonale.resize(broj_redova);
            index_kolone = 0;
            for(int i(ludara.size()-1); i >= 0; i--){
                if(index_kolone >= broj_kolona) break;
                for(int j(0); j < ludara.at(i).size(); j++){
                    dijagonale.at(j).push_back(ludara.at(i).at(j).at(index_kolone));
                }
                index_kolone++;
            }
            break;
        case 3:
            dijagonale.resize(broj_redova);
            index_kolone = broj_kolona-1;
            for(int i(ludara.size()-1); i >= 0; i--){
                if(index_kolone < 0) break;
                index_dijagonale = 0;
                for(int j(broj_redova - 1); j >= 0; j--){
                    dijagonale.at(index_dijagonale).push_back(ludara.at(i).at(j).at(index_kolone));
                    index_dijagonale++;
                }
                index_kolone--;
            }
            break;
        case 4:
            dijagonale.resize(broj_kolona);
            index_reda = 0;
            for(int i(ludara.size()-1); i >= 0; i--){
                if(index_reda >= broj_redova) break;
                for(int j(0); j < broj_kolona; j++){
                    dijagonale.at(j).push_back(ludara.at(i).at(index_reda).at(j));
                }
                index_reda++;
            }
            break;
        case 5:
            dijagonale.resize(broj_kolona);
            for(int i(0); i < ludara.size(); i++){
                index_dijagonale = 0;
                if(i >= broj_redova) break;
                for(int j(broj_kolona-1); j >= 0; j--){
                    dijagonale.at(index_dijagonale).push_back(ludara.at(i).at(i).at(j));
                    index_dijagonale++;
                }
            }
            break;
    }
    return dijagonale;
}
int main () {
    std::deque<std::vector<std::vector<int>>> ludara;
    std::cout << "Unesite dimenzije (x y z): ";
    int x, y, z;
    std::cin >> x >> y >> z;
    // validiraj dimenzije kontejnera
    if (x < 1 || y < 1 || z < 1) {
        std::cout << "Neispravne dimenzije kontejnera!" << std::endl;
        return 0;
    }
    // unesi elemente kontejnera
    ludara.resize(x);
    std::cout << "Unesite elemente kontejnera:";
    for(int i(0); i < x; i++){
        ludara.at(i).resize(y);
        for(int j(0); j < y; j++){
            ludara.at(i).at(j).resize(z);
            for(int k(0); k < z; k++){
                std::cin >> ludara.at(i).at(j).at(k);
            }
        }
    }
    // unesi smjer
    std::cout << std::endl << "Unesite smjer kretanja [0 - 5]: ";
    int smjer;
    std::cin >> smjer;
    // validiraj smjer
    if (smjer > 5 || smjer < 0) {
        std::cout << "Smjer kretanja nije ispravan!" << std::endl;
        return 0;
    }
    // pozovi funkciju
    auto dijagonale(IzdvojiDijagonale3D(ludara, SmjerKretanja(smjer)));
    // ispisi rezultat
    std::cout << SmjerKretanjaTekst[smjer] << ":" << std::endl;
    for(int i(0); i < dijagonale.size(); i++){
        for(int j(0); j < dijagonale.at(i).size(); j++){
            std::cout << std::setw(4) << dijagonale.at(i).at(j);
        }
        std::cout << std::endl;
    }
    return 0;
}