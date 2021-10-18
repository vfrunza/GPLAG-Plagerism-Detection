// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
#include <stdexcept>
#include <iomanip>
#include <string>


enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Kont>
auto NaprijedNazad(Kont kontejner) -> typename std::remove_reference<decltype(kontejner[0])>::type {
    typename std::remove_reference<decltype(kontejner[0])>::type matrica;
    matrica.resize(kontejner.size());
    for(int i=0; i<kontejner.size(); i++){
        for(int j=0; j<kontejner.at(0).size(); j++){
            for(int k=0; k<kontejner.at(0).at(0).size(); k++){
                if(k==j) {matrica[i].push_back(kontejner.at(i).at(j).at(k)); break;}
            }
        }
    }
    return matrica;
}

template <typename Kont>
auto NazadNaprijed(Kont kontejner) -> typename std::remove_reference<decltype(kontejner[0])>::type {
    typename std::remove_reference<decltype(kontejner[0])>::type matrica;
    matrica.resize(kontejner.size());
    for(int i=kontejner.size()-1; i>=0; i--){
        for(int j=0; j<kontejner.at(i).size(); j++){
            for(int k=kontejner.at(i).at(j).size()-1; k>=0; k--){
                if(k==kontejner.at(i).at(j).size()-1-j) {matrica[kontejner.size()-1-i].push_back(kontejner.at(i).at(j).at(k)); break;}
            }
        }
    }
    return matrica;
}

template <typename Kont>
auto GoreDolje(Kont kontejner) -> typename std::remove_reference<decltype(kontejner[0])>::type {
    typename std::remove_reference<decltype(kontejner[0])>::type matrica;
    matrica.resize(kontejner.at(0).size());
    for(int i=kontejner.size()-1; i>=0; i--){
        for(int j=0; j<kontejner.at(0).size(); j++){
            for(int k=0; k<kontejner.at(0).at(0).size(); k++){
                if(i==kontejner.size()-1 && k==0){matrica.at(j).push_back(kontejner.at(kontejner.size()-1).at(j).at(0)); break;}
                else if(i!=kontejner.size()-1 && k==kontejner.size()-1-i) {matrica.at(j).push_back(kontejner.at(i).at(j).at(k)); break;}
            }
        }
    }
    return matrica;
}

template <typename Kont>
auto DoljeGore(Kont kontejner) -> typename std::remove_reference<decltype(kontejner[0])>::type {//string
    typename std::remove_reference<decltype(kontejner[0])>::type matrica;
    matrica.resize(kontejner.at(0).size());
    for(int i=kontejner.size()-1; i>=0; i--){
        for(int j=kontejner.at(0).size()-1; j>=0; j--){
            for(int k=0; k<kontejner.at(0).at(0).size(); k++){
                std::cout << i<<" "<<j<<" "<<k << std::endl;
                if(i==kontejner.size()-1 && k==kontejner.at(0).at(0).size()-1){matrica.at(kontejner.at(0).size()-1-j).push_back(kontejner.at(kontejner.size()-1).at(j).at(kontejner.at(0).at(0).size()-1)); break;}
                else if(i!=kontejner.size()-1 && k==kontejner.at(0).size()-1-i) {matrica.at(kontejner.at(0).size()-1-j).push_back(kontejner.at(i).at(j).at(k)); break;}
            }
        }
    }
    return matrica;
}

template <typename Kont>
auto LijevoDesno(Kont kontejner) -> typename std::remove_reference<decltype(kontejner[0])>::type {
    typename std::remove_reference<decltype(kontejner[0])>::type matrica;
    matrica.resize(kontejner.at(0).at(0).size());
    for(int i=kontejner.size()-1; i>=0; i--){
        for(int j=0; j<kontejner.at(0).size(); j++){
            for(int k=0; k<kontejner.at(0).at(0).size(); k++){
                if(i==kontejner.size()-1 && j==0){matrica.at(k).push_back(kontejner.at(i).at(j).at(k));}
                else if(i!=kontejner.size()-1 && j==kontejner.size()-1-i) {matrica.at(k).push_back(kontejner.at(i).at(j).at(k));}
            }
        }
    }
    return matrica;
}

template <typename Kont>
auto DesnoLijevo(Kont kontejner) -> typename std::remove_reference<decltype(kontejner[0])>::type {
    typename std::remove_reference<decltype(kontejner[0])>::type matrica;
    matrica.resize(kontejner.at(0).at(0).size());
    for(int i=0; i<kontejner.size(); i++){
        for(int j=0; j<kontejner.at(0).size(); j++){
            for(int k=kontejner.at(i).at(j).size()-1; k>=0; k--){
                if(i==0 && j==0) {matrica.at(kontejner.at(i).at(j).size()-1-k).push_back(kontejner.at(i).at(j).at(k));}
                else if(i!=0 && j==i) {matrica.at(kontejner.at(i).at(j).size()-1-k).push_back(kontejner.at(i).at(j).at(k));}
            }
        }
    }
    return matrica;
}

template <typename Kont>
auto IzdvojiDijagonale3D(Kont kontejner, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kontejner[0])>::type {
    typename std::remove_reference<decltype(kontejner[0])>::type matrica;
    for(int i=1; i<kontejner.size(); i++){ if(kontejner.at(i).size()!=kontejner.at(i-1).size()){throw std::domain_error("Plohe nemaju isti broj redova"); break;} }
    for(int i=1; i<kontejner.size(); i++){
        for(int j=1; j<kontejner.at(i).size(); j++){
            if(kontejner.at(i).at(j).size()!=kontejner.at(i).at(j-1).size()){ throw std::domain_error("Redovi nemaju isti broj elemenata"); break;}
        }
    }
    
         if(smjer==SmjerKretanja::NaprijedNazad) matrica = NaprijedNazad(kontejner);
    else if(smjer==SmjerKretanja::NazadNaprijed) matrica = NazadNaprijed(kontejner);
    else if(smjer==SmjerKretanja::GoreDolje) matrica = GoreDolje(kontejner);
    else if(smjer==SmjerKretanja::DoljeGore) matrica = DoljeGore(kontejner);
    else if(smjer==SmjerKretanja::LijevoDesno) matrica = LijevoDesno(kontejner);
    else if(smjer==SmjerKretanja::DesnoLijevo) matrica = DesnoLijevo(kontejner);
    return matrica;
}

int main ()
{
    std::cout << "Unesite dimenzije (x y z): ";
    int x(0), y(0), z(0);
    std::cin >> x >> y >> z;
    if(x<0 || y<0 || z<0) {std::cout << "Neispravne dimenzije kontejnera!"; return 1;}
    std::cout << "Unesite elemente kontejnera: "<< std::endl;
    std::vector<std::deque<std::deque<int>>> kont;
    kont.resize(x);
    for(int i=0; i<x; i++) kont.at(i).resize(y);
    for(int i=0; i<x; i++) for(int j=0; j<y; j++) kont.at(i).at(j).resize(z);
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                std::cin >> kont.at(i).at(j).at(k);
            }
        }
    }
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    int smjer(0);
    std::cin >> smjer;
    if(smjer<0||smjer>5) std::cout << "Smjer kretanja nije ispravan!" << std::endl;
    std::deque<std::deque<int>> matrica;
    if(smjer==0){
        matrica = IzdvojiDijagonale3D(kont, SmjerKretanja::NaprijedNazad);
        std::cout << "NaprijedNazad: " << std::endl;
    }
    if(smjer==1){
        matrica = IzdvojiDijagonale3D(kont, SmjerKretanja::NazadNaprijed);
        std::cout << "NazadNaprijed: " << std::endl;
    }
    if(smjer==2){
        matrica = IzdvojiDijagonale3D(kont, SmjerKretanja::GoreDolje);
        std::cout << "GoreDolje: " << std::endl;
    }
    if(smjer==3){
        matrica = IzdvojiDijagonale3D(kont, SmjerKretanja::DoljeGore);
        std::cout << "DoljeGore: " << std::endl;
    }
    if(smjer==4){
        matrica = IzdvojiDijagonale3D(kont, SmjerKretanja::LijevoDesno);
        std::cout << "LijevoDesno: " << std::endl;
    }
    if(smjer==5){
        matrica = IzdvojiDijagonale3D(kont, SmjerKretanja::DesnoLijevo);
        std::cout << "DesnoLijevo: " << std::endl;
    }
    for(int i=0; i<matrica.size(); i++){
        for(int j=0; j<matrica[0].size(); j++){
            std::cout <<std::setw(4)<< matrica[i][j];
        }
        std::cout << std::endl;
    }
	return 0;
}