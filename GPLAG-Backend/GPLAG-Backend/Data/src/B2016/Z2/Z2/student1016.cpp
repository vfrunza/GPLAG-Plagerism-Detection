// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!
#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <string>
#include <iomanip>
#include <string>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template< typename Kontejner>
auto IzdvojiDijagonale3D (Kontejner kont, SmjerKretanja smjer )-> typename std::remove_reference<decltype(kont.at(0))>::type {
    typename std::remove_reference<decltype(kont.at(0))>::type matrica;
    if(kont.size()==0) return matrica;
    for(int i=0; i<kont.size(); i++){
        if(kont.at(i).size()==0) return matrica;
        for(int j=0; j<kont.at(i).size(); j++){
            if(kont.at(i).at(j).size()==0) return matrica;
        }
    }
    int x(((kont.at(0)).at(0)).size());
    int y((kont.at(0)).size());
    for(int k=0; k<kont.size(); k++){
        for(int i=0; i<(kont.at(k)).size(); i++){
            if(((kont.at(k)).at(i)).size()!=x) throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
        if((kont.at(k)).size()!=y) throw std::domain_error("Plohe nemaju isti broj redova");
    }

    if(smjer==SmjerKretanja::NaprijedNazad) {
        for(int k=0; k<kont.size(); k++) {
            typename std::remove_reference<decltype((kont.at(0)).at(0))>::type vektor;
            for(int i=0; i<(kont.at(k)).size(); i++) {
                for(int j=0; j<((kont.at(k)).at(i)).size(); j++) {
                    if(i==j) {
                        vektor.push_back(((kont.at(k)).at(i)).at(j));
                    }
                }
            }
            matrica.push_back(vektor);
        }
    } else if(smjer==SmjerKretanja::NazadNaprijed) {
        for(int k=int(kont.size()-1); k>=0; k--) {
            typename std::remove_reference<decltype((kont.at(0)).at(0))>::type vektor;
            for(int i=0; i<(kont.at(k)).size(); i++) {
                for(int j=int(((kont.at(k)).at(i)).size()-1); j>=0; j--) {
                    if(i+j==int(((kont.at(k)).at(i)).size()-1)) {
                        vektor.push_back(((kont.at(k)).at(i)).at(j));
                    }
                }
            }
            matrica.push_back(vektor);
        }
    } else if(smjer==SmjerKretanja::GoreDolje) {
        for(int i=0; i<(kont.at(0)).size(); i++) {
            typename std::remove_reference<decltype((kont.at(0)).at(0))>::type vektor;
            for(int j=0; j<((kont.at(0)).at(i)).size(); j++) {
                for(int k=0; k<kont.size(); k++) {
                    if(j+k==int(kont.size()-1)) vektor.push_back(((kont.at(k)).at(i)).at(j));
                }
            }
            matrica.push_back(vektor);
        }
    } else if(smjer==SmjerKretanja::DoljeGore) {
        for(int i=int((kont.at(0)).size()-1); i>=0; i--) {
            typename std::remove_reference<decltype((kont.at(0)).at(0))>::type vektor;
            for(int k=int(kont.size()-1); k>=0; k--) {
                for(int j=int(((kont.at(k)).at(i)).size()-1); j>=0; j--) {
                     if(j-k==((kont.at(k)).at(i)).size()-kont.size()) vektor.push_back(((kont.at(k)).at(i)).at(j)); //kad stavim kont.size()-2 radi at na zamgeru

                }
            }
            matrica.push_back(vektor);
        }
        

        
        
    } else if(smjer==SmjerKretanja::LijevoDesno) {
        for(int j=0; j<((kont.at(0)).at(0)).size(); j++) {
            typename std::remove_reference<decltype((kont.at(0)).at(0))>::type vektor;
            for(int i=0; i<(kont.at(0)).size(); i++) {
                for(int k=int(kont.size()-1); k>=0; k--) {
                    if(i+k==int(kont.size()-1)) vektor.push_back(((kont.at(k)).at(i)).at(j));
                }
            }
            matrica.push_back(vektor);
        }
    } else if(smjer==SmjerKretanja::DesnoLijevo) {
        for(int j=int(((kont.at(0)).at(0)).size()-1); j>=0; j--) {
            typename std::remove_reference<decltype((kont.at(0)).at(0))>::type vektor;
            for(int k=0; k<kont.size(); k++) {
                for(int i=0; i<(kont.at(0)).size(); i++) {
                    if(i==k) vektor.push_back(((kont.at(k)).at(i)).at(j));
                }
            }
            matrica.push_back(vektor);
        }
    }
    return matrica;
}

using std::cin;
using std::cout;

int main ()
{
    std::vector<SmjerKretanja> smjerovi {SmjerKretanja::NaprijedNazad, SmjerKretanja::NazadNaprijed,SmjerKretanja::GoreDolje, SmjerKretanja::DoljeGore, SmjerKretanja::LijevoDesno, SmjerKretanja::DesnoLijevo};
    std::vector<std::string> smjerovitekst{ "NaprijedNazad", "NazadNaprijed", "GoreDolje", "DoljeGore", "LijevoDesno", "DesnoLijevo"};
    std::vector<std::deque<std::deque<int>>> kont;
    SmjerKretanja smjer;
    int x,y,z;
    cout << "Unesite dimenzije (x y z): ";
    cin >> x >> y >> z;
    if(x<=0 or y<=0 or z<=0) {
        cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    cout << "Unesite elemente kontejnera: "<< std::endl;
    for(int k=0; k<x; k++) {
        std::deque<std::deque<int>> mat;
        for(int i=0; i<y; i++) {
            std::deque<int> vektor;
            for(int j=0; j<z; j++) {
                int a;
                cin >> a;
                vektor.push_back(a);
            }
            mat.push_back(vektor);
        }
        kont.push_back(mat);
    }
    cout << "Unesite smjer kretanja [0 - 5]: ";
    int n;
    cin >> n;
    if(n<0 or n>5){ 
        cout << "Smjer kretanja nije ispravan!"<< std::endl;
        return 0;
    }
    smjer=smjerovi[n];
    std::deque<std::deque<int>> rezult;
    try {
        rezult=IzdvojiDijagonale3D(kont, smjer);
    } catch(std::domain_error izuzetak) {
        cout << izuzetak.what();
        return 0;
    }
    cout <<smjerovitekst[n]<<": "<< std::endl;
    for(int i=0; i<rezult.size(); i++) {
        for(int j=0; j<rezult[0].size(); j++) {
            cout<< std::setw(4) << rezult[i][j];
        }
        cout << std::endl;
    }
    return 0;
}