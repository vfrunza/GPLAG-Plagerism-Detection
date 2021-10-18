// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!

#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <string>

using std::cin; using std::cout; using std::endl; using std::vector;

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};


template <typename Kontejner>
auto IzdvojiDijagonale3D (Kontejner &kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type {
    //Indeksiranje ne smijemo koristiti, podrzano kopiranje i dodjeljivanje
    //size, at i push_back moze
    int x(kont.size()), y(kont.at(0).size()), z(kont.at(0).at(0).size());
    
    typename std::remove_reference<decltype(kont.at(0))>::type mat; //Moras inicijalizovati matricu
    if (smjer==SmjerKretanja::NaprijedNazad) {
        mat.resize(x);
        for (int i=0; i<x; i++) {
            for (int j=0; j<y; j++) {
                for (int k=0; k<z; k++) {
                    if (j==k) mat.at(i).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        return mat;
    }
    else if (smjer==SmjerKretanja::NazadNaprijed) {
        mat.resize(x);
        for (int i=x-1; i>=0; i--) {
            for (int j=0; j<y; j++) {
                for (int k=0; k<z; k++) {
                    if ((j+k)==(z-1)) mat.at(x-i-1).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        return mat;
    }
    else if (smjer==SmjerKretanja::GoreDolje) {
        mat.resize(y);
        for (int j=0; j<y; j++) {
            for (int i=x-1; i>=0; i--) {
                for (int k=0; k<z; k++) {
                    if ((i+k)==(x-1)) mat.at(j).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        return mat;
    }
    else if (smjer==SmjerKretanja::DoljeGore) {
        mat.resize(y);
        for (int j=y-1; j>=0; j--) {
            for (int i=x-1; i>=0; i--) {
                for (int k=0; k<z; k++) {
                    if ((k-i)==x) mat.at(y-j-1).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        return mat;
    }
    
    else if (smjer==SmjerKretanja::LijevoDesno) {
        mat.resize(z);
        for (int k=0; k<z; k++) {
            for (int j=0; j<y; j++) {
                for (int i=x-1; i>=0; i--) {
                    if ((j+i)==(x-1)) mat.at(k).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        return mat;
    }
    else if (smjer==SmjerKretanja::DesnoLijevo) {
        mat.resize(z);
        for (int k=z-1; k>=0; k--) {
            for (int j=0; j<y; j++) {
                for (int i=0; i<x; i++) {
                    if ((i-j)==0) mat.at(z-k-1).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        return mat;
    }
    return mat;
}
//1 2 3 0 3 1 2 5 4 2 1 4 5 2 3 1 3 5 2 5 1 7 7 0
int main () {
    int x, y, z;
    cout << "Unesite dimenzije (x y z): ";
    cin >> x >> y >> z;
    if (x<0 || y<0 || z<0) {
        cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    vector<vector<vector<int>>> vek;
    cout << "Unesite elemente kontejnera: " << endl;
    for (int i=0; i<x; i++) {
        vek.resize(i+1);
        for (int j=0; j<y; j++) {
            vek[i].resize(j+1);
            for (int k=0; k<z; k++) {
                int broj;
                cin >> broj;
                vek[i][j].push_back(broj);
            }
        }
    }
    int smjer;
    cout << "Unesite smjer kretanja [0 - 5]: ";
    cin >> smjer;
    if (smjer<0 || smjer>5) {
        cout << "Smjer kretanja nije ispravan!" << endl;
        return 0;
    }

        auto mat=IzdvojiDijagonale3D(vek, SmjerKretanja(smjer));
        if (smjer==0) cout << "NaprijedNazad: " << endl;
        else if (smjer==1) cout << "NazadNaprijed: " << endl;
        else if (smjer==2) cout << "GoreDolje: " << endl;
        else if (smjer==3) cout << "DoljeGore: " << endl;
        else if (smjer==4) cout << "LijevoDesno: " << endl;
        else if (smjer==5) cout << "DesnoLijevo: " << endl;
        
        for (int i=0; i<mat.size(); i++) {
            for (int j=0; j<mat.at(i).size(); j++) {
                cout << std::setw(4) << mat.at(i).at(j);
            }
            cout << endl;
        }
    
    
	return 0;
}