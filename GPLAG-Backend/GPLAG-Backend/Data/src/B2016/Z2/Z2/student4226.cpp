// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <stdexcept>
#include <type_traits>
#include <algorithm>

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

void IspisiMatricu(std::deque<std::deque<int>> mat, int brredova, int brkolona){
    for(int i(0); i<brredova; i++){
        for(int j(0); j<brkolona; j++)
            std::cout << std::setw(4) << mat[i][j];
        std::cout << std::endl;
    }
}

template <typename kont>
auto IzdvojiDijagonale3D(kont mat, SmjerKretanja smjer) -> typename std::remove_reference<decltype(mat[0])>::type{
    for(int i(0); i<mat.size(); i++)
        for(int j(1);j<mat[i].size(); j++)
            if(mat[i][0].size()!=mat[i][j].size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
    for(int i(1); i<mat.size(); i++)
        if(mat[0].size()!=mat[i].size()) throw std::domain_error("Plohe nemaju isti broj redova");
    
    typename std::remove_reference<decltype(mat[0])>::type mat2d;
    if(smjer == SmjerKretanja::NaprijedNazad){
        mat2d.resize(int(mat.size()));
        for(int i(0); i < mat.size(); i++){
            if(mat[0].size() <= mat[0][0].size())
                for(int j(0); j<mat[0].size(); j++)
                    mat2d[i].push_back(mat[i][j][j]);
            else
                for(int k(0); k<mat[0][0].size(); k++)
                    mat2d[i].push_back(mat[i][k][k]);
        }
    }
    else if(smjer == SmjerKretanja::NazadNaprijed){
        mat2d.resize(int(mat.size()));
        for(int i(0); i < mat.size(); i++){
            if(mat[0].size() <= mat[0][0].size())
                for(int j(0); j<mat[0].size(); j++)
                    mat2d[i].push_back(mat[i][j][mat[0][0].size()-1-j]);
            else
                for(int k(0); k<mat[0][0].size(); k++)
                    mat2d[i].push_back(mat[i][k][mat[0][0].size()-1-k]);
        }
        std::reverse(mat2d.begin(), mat2d.end());
    }
    else if(smjer == SmjerKretanja::GoreDolje){
        mat2d.resize(mat[0].size());
        int brojac(0);
        for(int i(mat.size()-1);i>=0; i--){
            for(int j(0);j<mat[0].size(); j++)
                mat2d[j].push_back(mat[i][j][brojac]);
            brojac++;
        }
    }
    else if(smjer == SmjerKretanja::DoljeGore){
        mat2d.resize(mat[0].size());
        int brojac(mat[0][0].size()-1);
        for(int i(mat.size()-1);i>=0; i--){
            for(int j(0);j<mat[0].size(); j++)
                mat2d[j].push_back(mat[i][j][brojac]);
            brojac--;
        }
        std::reverse(mat2d.begin(), mat2d.end());
    }
    else if(smjer == SmjerKretanja::LijevoDesno){
        mat2d.resize(mat[0][0].size());
        int brojac(0);
        for(int i(mat.size()-1);i>=0; i--){
            for(int k(0);k<mat[0][0].size(); k++)
                mat2d[k].push_back(mat[i][brojac][k]);
            brojac++;
        }
    }
    else if(smjer == SmjerKretanja::DesnoLijevo){
        mat2d.resize(mat[0][0].size());
        int brojac(0);
        for(int i(0);i<mat.size(); i++){
            for(int k(0);k<mat[0][0].size(); k++)
                mat2d[k].push_back(mat[i][brojac][k]);
            brojac++;
        }
        std::reverse(mat2d.begin(), mat2d.end());
    }
    return mat2d;
}

int main (){
    int a, b, c;
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> a >> b >> c;
    if(a<=0 || b<=0 || c<=0){
        std::cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::cout << "Unesite elemente kontejnera: ";
    std::vector<std::deque<std::deque<int>>> belaj;
    belaj.resize(a);
    for(int i(0); i<a; i++){
        belaj[i].resize(b);
        for(int j(0); j<b; j++){
            belaj[i][j].resize(c);
            for(int k(0); k<c; k++){
                std::cin >> belaj[i][j][k];
            }
        }
    }
    int kompas;
    std::cout << std::endl << "Unesite smjer kretanja [0 - 5]: ";
    std::cin >> kompas;
    if(kompas<0 || kompas>5){
        std::cout << "Smjer kretanja nije ispravan!" << std::endl;
        return 0;
    }
    if(kompas==0){
        SmjerKretanja smjer = SmjerKretanja::NaprijedNazad;
        try{
            std::deque<std::deque<int>> dva_de(IzdvojiDijagonale3D(belaj, smjer));
            std::cout << "NaprijedNazad: " << std::endl;
            IspisiMatricu(dva_de, dva_de.size(), dva_de[0].size());
        }
        catch(std::domain_error a){
            std::cout << a.what();
        }
    }
    if(kompas==1){
        SmjerKretanja smjer = SmjerKretanja::NazadNaprijed;
        try{
            std::deque<std::deque<int>> dva_de(IzdvojiDijagonale3D(belaj, smjer));
            std::cout << "NazadNaprijed: " << std::endl;
            IspisiMatricu(dva_de, dva_de.size(), dva_de[0].size());
        }
        catch(std::domain_error b){
            std::cout << b.what();
        }
    }
    if(kompas==2){
        SmjerKretanja smjer = SmjerKretanja::GoreDolje;
        try{
            std::deque<std::deque<int>> dva_de(IzdvojiDijagonale3D(belaj, smjer));
            std::cout << "GoreDolje: " << std::endl;
            IspisiMatricu(dva_de, dva_de.size(), dva_de[0].size());
        }
        catch(std::domain_error c){
            std::cout << c.what();
        }
    }
    if(kompas==3){
        SmjerKretanja smjer = SmjerKretanja::DoljeGore;
        try{
            std::deque<std::deque<int>> dva_de(IzdvojiDijagonale3D(belaj, smjer));
            std::cout << "DoljeGore: " << std::endl;
            IspisiMatricu(dva_de, dva_de.size(), dva_de[0].size());
        }
        catch(std::domain_error d){
            std::cout << d.what();
        }
    }
    if(kompas==4){
        SmjerKretanja smjer = SmjerKretanja::LijevoDesno;
        try{
            std::deque<std::deque<int>> dva_de(IzdvojiDijagonale3D(belaj, smjer));
            std::cout << "LijevoDesno: " << std::endl;
            IspisiMatricu(dva_de, dva_de.size(), dva_de[0].size());
        }
        catch(std::domain_error e){
            std::cout << e.what();
        }
    }
    if(kompas==5){
        SmjerKretanja smjer = SmjerKretanja::DesnoLijevo;
        try{
            std::deque<std::deque<int>> dva_de(IzdvojiDijagonale3D(belaj, smjer));
            std::cout << "DesnoLijevo: " << std::endl;
            IspisiMatricu(dva_de, dva_de.size(), dva_de[0].size());
        }
        catch(std::domain_error f){
            std::cout << f.what();
        }
    }
	return 0;
}