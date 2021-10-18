// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <stdexcept>
#include <deque>
#include <vector>
#include <iomanip>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename TreeDee>
auto IzdvojiDijagonale3D(TreeDee z, SmjerKretanja smjer) -> typename std::remove_reference<decltype(z.at(0))>::type {
    
    if (z.size()==0 || z.at(0).size() == 0 || z.at(0).at(0).size() == 0){
        typename std::remove_reference<decltype(z.at(0))>::type zaVratit;
        return zaVratit;
    }
    
    int duzina = z.at(0).size();
    int sirina = z.at(0).at(0).size();
    for(int i=0; i < z.size(); i++){
        int brojKolonaSvakeMatrice(-1);
        for(int j=0; j < z.at(i).size(); j++){
            if(brojKolonaSvakeMatrice == -1) brojKolonaSvakeMatrice = z.at(i).at(j).size();
            if(z.at(i).at(j).size() != brojKolonaSvakeMatrice) throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
        if(brojKolonaSvakeMatrice != sirina) throw std::domain_error("Redovi nemaju isti broj elemenata");
        if(z.at(i).size() !=  duzina) throw std::domain_error("Plohe nemaju isti broj redova");
    }
    
    typename std::remove_reference<decltype(z.at(0).at(0))>::type JedanDee;
    typename std::remove_reference<decltype(z.at(0))>::type DvaDee;
    int k(0);
    int kolona(0);
    switch(int(smjer)){
        case 0:
        for(int i=0; i < z.size(); i++){
            DvaDee.push_back(JedanDee);
            for(int j=0; j < z.at(0).size(); j++){
                if(j >= z.at(i).at(j).size()) break;
                DvaDee.at(i).push_back(z.at(i).at(j).at(j));
            }
        }
        break;
        case 1:
        for(int i=z.size()-1; i >= 0; i--){
            DvaDee.push_back(JedanDee);
            kolona = sirina-1;
            for(int j=0; j < duzina; j++){
                if(kolona < 0) break;
                DvaDee.at(k).push_back(z.at(i).at(j).at(kolona));
                kolona--;
            }
            k++;
        }
        break;
        
        case 2:
        for(int i=0; i < duzina; i++){
            DvaDee.push_back(JedanDee);
            for(int j=z.size()-1; j >= 0; j--){
                if(k >= sirina) break;
                DvaDee.at(i).push_back(z.at(j).at(i).at(k));
                k++;
            }
            k=0;
        }
        break;
        
        case 3:
        for(int i=0; i < duzina; i++){
            DvaDee.push_back(JedanDee);
            for(int j=z.size()-1; j >= 0; j--){
                if(k >= sirina) break;
                DvaDee.at(i).push_back(z.at(j).at(duzina-i-1).at(sirina-1-k));
                k++;
            }
            k=0;
        }
        break;
        
        case 4:
        for(int i=0; i<sirina; i++){
            DvaDee.push_back(JedanDee);
            for(int j=z.size()-1; j>=0; j--){
                if(k >= duzina) break;
                DvaDee.at(i).push_back(z.at(j).at(k).at(i));
                k++;
            }
            k=0;
        }
        break;
        
        case 5:
        for(int i=0; i < z.size(); i++){
            if (i >= duzina) break;
            for(int j = sirina-1; j >= 0; --j){
                DvaDee.push_back(JedanDee);
                DvaDee.at(k).push_back(z.at(i).at(i).at(j));
                k++;
            }
            k = 0;
        }
        break;
        
        default: std::cout << "Smjer kretanja nije ispravan!" << std::endl;
        break;
    }
    
    return DvaDee;
}

std::deque<std::deque<int>> KreirajMatricu(int br_redova, int br_kolona)
{
    return std::deque<std::deque<int>> (br_redova, std::deque<int>(br_kolona));
}

int main ()
{   
    int x, y, z;
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> x >> y >> z;
    if(x<0 || y<0 || z<0) { std::cout << "Neispravne dimenzije kontejnera!"; return 0; }
    
    typedef std::deque<std::deque<int>> Matrix;
    std::vector<Matrix> babo(x, Matrix(y, std::deque<int>(z)));
    std::cout << "Unesite elemente kontejnera: " << std::endl;
    for(int i=0; i < x; i++){
        for(int j=0; j < y; j++){
            for(int k=0; k < z; k++){
                std::cin >> babo.at(i).at(j).at(k);
            }
        }
    }
    std::deque<std::deque<int>> sinko;
    int halo;
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    std::cin >> halo; 
    try {
     sinko = IzdvojiDijagonale3D(babo, SmjerKretanja(halo));
    switch(halo){
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
        default: break;
    }
    for(int i=0; i < sinko.size(); i++){
        for(int j=0; j < sinko[i].size(); j++){
            std::cout << std::setw(4) << sinko.at(i).at(j);
        }
        std::cout << std::endl;
    }
    }catch(std::domain_error exec){
        std::cout << exec.what() << std::endl;
    }
    
	return 0;
}