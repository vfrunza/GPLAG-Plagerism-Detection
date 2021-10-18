// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <type_traits>
#include <stdexcept>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo,
};

template <typename tip>
 void Ispisi(tip mat) {
     for(int i=0; i<mat.size(); i++) {
         for(int j=0; j<mat.at(i).size(); j++)
            std::cout<<std::setw(4)<<mat.at(i).at(j);
        std::cout<<std::endl;
     }
 }
template <typename tip1>
auto IzdvojiDijagonale3D(tip1 kont, SmjerKretanja smjer) ->typename std::remove_reference<decltype(kont.at(0))>::type {
    typename std::remove_reference<decltype(kont.at(0))>::type mat;
    int x(kont.size());
    int y(0),z(0);
    if(x) y = kont.at(0).size();
    if(x && y) z = kont.at(0).at(0).size();
    if(!x || !y || !z) return mat;
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            if(kont.at(i).at(j).size() != z)
                throw std::domain_error("Redovi nemaju isti broj elemenata");
    for(int i=0; i<x; i++)
        if(kont.at(i).size() != y)
            throw std::domain_error("Plohe nemaju isti broj redova");
    if(smjer == SmjerKretanja::NaprijedNazad) {
        for(int i=0; i<x; i++) {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type tmp;
            for(int j=0; j<y; j++)
                for(int k=0; k<z; k++)
                    if(j == k)
                        tmp.push_back(kont.at(i).at(j).at(k));
            mat.push_back(tmp);
        }
        return mat;
    }
    if(smjer == SmjerKretanja::NazadNaprijed) {
        for(int i=x-1; i>=0; i--) {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type tmp;
            for(int j=0; j<y; j++)
                for(int k=0; k<z; k++)
                    if(j == z-k-1)
                        tmp.push_back(kont.at(i).at(j).at(k));
            mat.push_back(tmp);
        }
        return mat;
    }
    if(smjer == SmjerKretanja::GoreDolje) {
        for(int i=0; i<y; i++) {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type tmp;
            for(int j=0; j<z; j++)
                for(int k=x-1; k>=0; k--)
                    if(j == x-k-1) {
                        tmp.push_back(kont.at(k).at(i).at(j)); 
                    }
        mat.push_back(tmp);
        }
        return mat;
    }
    if(smjer == SmjerKretanja::DoljeGore) {
        for(int i=y-1; i>=0; i--) {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type tmp;
            for(int j=x-1; j>=0; j--)
                for(int k=z-1; k>=0; k--)
                    if(x-j == z-k)
                        tmp.push_back(kont.at(j).at(i).at(k));
            mat.push_back(tmp);
        }
        return mat;
    }
    if(smjer == SmjerKretanja::LijevoDesno) {
        for(int i=0; i<z; i++) {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type tmp;
            for(int j=0; j<y; j++)
                for(int k=x-1; k>=0; k--)
                    if(j == x-k-1)
                        tmp.push_back(kont.at(k).at(j).at(i));
            mat.push_back(tmp);
        }
        return mat;
    }
    if(smjer == SmjerKretanja::DesnoLijevo) {
        for(int i=z-1; i>=0; i--) {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type tmp;
            for(int j=0; j<x; j++)
                for(int k=0; k<y; k++)
                    if(k == j)
                        tmp.push_back(kont.at(j).at(k).at(i));
            mat.push_back(tmp);
        }
        return mat;
    }
    return mat;
}

int main ()
{
    try{
    std::cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
    std::cin>>x>>y>>z;
    if(x<0 || y<0 || z<0) {
        std::cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::vector<std::deque<std::deque<int>>> kont (x, std::deque<std::deque<int>> (y, std::deque<int>(z)));
    std::cout<<"Unesite elemente kontejnera: "<<std::endl;
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            for(int k=0; k<z; k++)
                std::cin>>kont.at(i).at(j).at(k);
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    int n;
    std::cin>>n;
    if(n<0 || n>5) {
        std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
        return 0;
    }
    if(n == 0) {
        auto mat(IzdvojiDijagonale3D(kont, SmjerKretanja::NaprijedNazad));
        std::cout<<"NaprijedNazad: "<<std::endl;
        Ispisi(mat);   
    }
    if(n == 1) {
        auto mat(IzdvojiDijagonale3D(kont, SmjerKretanja::NazadNaprijed));
        std::cout<<"NazadNaprijed: "<<std::endl;
        Ispisi(mat);
    }
    if(n == 2) {
        auto mat(IzdvojiDijagonale3D(kont, SmjerKretanja::GoreDolje));
        std::cout<<"GoreDolje: "<<std::endl;
        Ispisi(mat);
    }
    if(n == 3) { 
        auto mat(IzdvojiDijagonale3D(kont, SmjerKretanja::DoljeGore));
        std::cout<<"DoljeGore: "<<std::endl;
        Ispisi(mat);
    }
    if(n == 4) {
        auto mat(IzdvojiDijagonale3D(kont, SmjerKretanja::LijevoDesno));
        std::cout<<"LijevoDesno: "<<std::endl;
        Ispisi(mat);
    }
    if(n == 5) {
        auto mat(IzdvojiDijagonale3D(kont, SmjerKretanja::DesnoLijevo));
        std::cout<<"DesnoLijevo: "<<std::endl;
        Ispisi(mat);
    }
    }
    catch(std::domain_error e) {
        std::cout<<e.what();
    }
    return 0;
}