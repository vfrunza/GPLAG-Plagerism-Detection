// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!
#include <iostream>
#include <vector>        //2 3 4
#include <deque>
#include <type_traits>
#include <stdexcept>
#include <iomanip>
enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};
template <typename Kontejner>
auto IzdvojiDijagonale3D(Kontejner &kont, SmjerKretanja smjer) ->decltype(kont[0]) {
    auto cont(kont);
    auto &mat1(kont[0]);
    int x(kont.size());
    int y(kont[0].size());
    int z(kont[0][0].size());
    for(int i(0); i<kont.size(); i++) {
        for(int j(0); j<kont[i].size(); j++) {
            if(kont[0][0].size()!=kont[i][j].size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    for(int i(0); i<kont.size(); i++) {
        if(kont[0].size()!=kont[i].size()) throw std::domain_error("Plohe nemaju isti broj redova");
    }
    if(smjer==SmjerKretanja::NaprijedNazad) {
        auto &mat(kont[0]);
        mat.resize(x);
        for(int i(0); i<x; i++) {
            mat[i].resize(y);
        }
        for(int i(0); i<mat.size(); i++) {
            for(int j(0); j<mat[i].size(); j++) {
                mat[i][j]=cont[i][j][j];
            }
        }
        return mat;
    }
    else if(smjer==SmjerKretanja::NazadNaprijed) {
        auto &mat(kont[0]);
        mat.clear();
        mat.resize(x);
        for(int i(0); i<x; i++) {
            mat[i].resize(y);
        }
        for(int i(0); i<x; i++) {
            for(int j(0); j<y; j++) {
                mat[i][j]=cont[x-1-i][j][z-1-j];            //vazi ako je z>y
            }
        }
        return mat;
    }
    else if(smjer==SmjerKretanja::GoreDolje) {
        auto &mat(kont[0]);
        mat.clear();
        mat.resize(y);
        for(int i(0); i<y; i++) {
            mat[i].resize(x);
        }
        for(int i(0); i<y; i++) {
            for(int j(0); j<x; j++) {
                mat[i][j]=cont[x-1-j][i][j];
            }
        }
        return mat;
    }
    else if(smjer==SmjerKretanja::DoljeGore) {
        auto &mat(kont[0]);
        mat.clear();
        mat.resize(y);
        for(int i(0); i<y; i++) {
            mat[i].resize(x);
        }
        for(int i(0); i<y; i++){
            for(int j(0); j<x; j++){
                mat[i][j]=cont[x-1-j][y-1-i][z-1-j];            //vazi za z>x
            }
        }
        return mat;
    }
    else if(smjer==SmjerKretanja::LijevoDesno) {
        auto &mat(kont[0]);
        mat.clear();
        mat.resize(z);
        for(int i(0); i<z; i++) {
            mat[i].resize(x);
        }
        for(int i(0); i<z; i++){
            for(int j(0); j<x; j++){
                mat[i][j]=cont[x-1-j][j][i];
            }
        }
        return mat;
    }
    else if(smjer==SmjerKretanja::DesnoLijevo) {
        auto &mat(kont[0]);
        mat.clear();
        mat.resize(z);
        for(int i(0); i<z; i++) {
            mat[i].resize(x);
        }
        for(int i(0); i<z; i++) {
            for(int j(0); j<x; j++){
                mat[i][j]=cont[j][j][z-i-1];
            } 
        }
        return mat;
    }
    return mat1;
}
int main (){
    int x, y, z, s;
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> x >> y >> z;
    if(x<0 || y<0 || z<0) {
        std::cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::cout << "Unesite elemente kontejnera: \n";
    std::vector<std::deque<std::deque<int>>> v(x, std::deque<std::deque<int>>(y, std::deque<int>(z)));
    for(int i(0); i<v.size(); i++) {
        for(int j(0); j<v[i].size(); j++) {
            for(int k(0); k<v[i][j].size(); k++) {
                std::cin >> v[i][j][k];
            }
        }
    }
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    std::cin >> s;
    if(s<0 || s>5) std::cout << "Smjer kretanja nije ispravan!\n";
    try {
        if(s==0) {
            std::cout << "NaprijedNazad: \n";
            auto mat(IzdvojiDijagonale3D(v, SmjerKretanja::NaprijedNazad));
            for(int i(0); i<mat.size(); i++) {
                for(int j(0); j<mat[i].size(); j++) {
                    std::cout << std::setw(4) << mat[i][j];
                }
                std::cout << std::endl;
            }
        }
        else if(s==1) {
            std::cout << "NazadNaprijed: \n";
            auto mat(IzdvojiDijagonale3D(v, SmjerKretanja::NazadNaprijed));
            for(int i(0); i<mat.size(); i++) {
                for(int j(0); j<mat[i].size(); j++) {
                    std::cout << std::setw(4) << mat[i][j];
                }
                std::cout << std::endl;
            }
        }   
        else if(s==2) {
            std::cout << "GoreDolje: \n";
            auto mat(IzdvojiDijagonale3D(v, SmjerKretanja::GoreDolje));
            for(int i(0); i<mat.size(); i++) {
                for(int j(0); j<mat[i].size(); j++) {
                    std::cout << std::setw(4) << mat[i][j];
                }
                std::cout << std::endl;
            }
        }
        else if(s==3) {
            std::cout << "DoljeGore: \n";
            auto mat(IzdvojiDijagonale3D(v, SmjerKretanja::DoljeGore));
            for(int i(0); i<mat.size(); i++) {
                for(int j(0); j<mat[i].size(); j++) {
                    std::cout << std::setw(4) << mat[i][j];
                }
                std::cout << std::endl;
            } 
        }
        else if(s==4) {
            std::cout << "LijevoDesno: \n";
            auto mat(IzdvojiDijagonale3D(v, SmjerKretanja::LijevoDesno));
            for(int i(0); i<mat.size(); i++) {
                for(int j(0); j<mat[i].size(); j++) {
                    std::cout << std::setw(4) << mat[i][j];
                }
                std::cout << std::endl;
            }
        }
        else if(s==5) {
            std::cout << "DesnoLijevo: \n";
            auto mat(IzdvojiDijagonale3D(v, SmjerKretanja::DesnoLijevo));
            for(int i(0); i<mat.size(); i++) {
                for(int j(0); j<mat[i].size(); j++) {
                    std::cout << std::setw(4) << mat[i][j]; 
                }
                std::cout << std::endl;
            }
        }
    }
    catch(...) {
        std::cout << "Greska";
    }
	return 0;
}