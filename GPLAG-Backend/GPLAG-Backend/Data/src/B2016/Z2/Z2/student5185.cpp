#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <stdexcept>

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template <typename Kontejner>
auto IzdvojiDijagonale3D(Kontejner Kvadar, SmjerKretanja trenutniSmjer) -> typename std::remove_reference<decltype(Kvadar[0])>::type{
    
    typedef typename std::remove_reference<decltype(Kvadar[0])>::type Kontejner1;
    typedef typename std::remove_reference<decltype(Kvadar[0][0])>::type Kontejner2;
    
    Kontejner1 ElementiDijagonala;
    
    
    
    
    if (trenutniSmjer ==  SmjerKretanja::NaprijedNazad || trenutniSmjer ==  SmjerKretanja::NazadNaprijed) {
        ElementiDijagonala.resize(Kvadar.size());
        if (trenutniSmjer ==  SmjerKretanja::NaprijedNazad) {
            for (int i = 0; i < Kvadar.size(); i++) {
                int k = 0;
                for (int j = 0; j < Kvadar[0].size(); j++) {
                    if (k == Kvadar[0][0].size()) {
                        break;
                    }
                    else{
                        ElementiDijagonala[i].push_back(Kvadar[i][j][k++]);
                    }
                }
            }
        }
        else if (trenutniSmjer ==  SmjerKretanja::NazadNaprijed){
            int o(Kvadar.size()-1);
            for (int i = Kvadar.size()-1; i >= 0; i--) {
                int k = Kvadar[0][0].size()-1;
                
                for (int j = 0; j < Kvadar[0].size(); j++) {
                    if (k == 0) {
                        break;
                    }
                    else{
                        ElementiDijagonala[o].push_back(Kvadar[Kvadar.size()-i-1][j][k--]);
                    }
                }o--;
            }
        } //promjeniti na x y z
    } // Kod za NaprijedNazad i NazadNaprijed
    
    else if(trenutniSmjer ==  SmjerKretanja::GoreDolje || trenutniSmjer ==  SmjerKretanja::DoljeGore){
        ElementiDijagonala.resize(Kvadar[0].size());
        if (trenutniSmjer ==  SmjerKretanja::GoreDolje){
            for (int j = 0; j < Kvadar[0].size(); j++) {
                int o(1);
                for (int i = 0; i < Kvadar.size(); i++) {
                    for (int k = 0; k < Kvadar[0][0].size(); k++) {
                        if (k == i) ElementiDijagonala[j].push_back(Kvadar[i+o][j][i]);
                    }
                    o *= -1;
                }
            }
        }
        else  if (trenutniSmjer ==  SmjerKretanja::DoljeGore){
            for (int j = Kvadar[0].size()-1; j >= 0; j--) {
                int o = Kvadar[0][0].size()-1;
                for (int i = Kvadar.size()-1; i >= 0; i--) {
                    if (o == 0) break;
                    
                    ElementiDijagonala[Kvadar[0].size()-1-j].push_back(Kvadar[i][j][o--]);
                }
            }
        }
    } // Kod za GoreDolje i DoljeGore
    
    else if(trenutniSmjer ==  SmjerKretanja::LijevoDesno || trenutniSmjer ==  SmjerKretanja::DesnoLijevo){
        ElementiDijagonala.resize(Kvadar[0][0].size());
        if (trenutniSmjer ==  SmjerKretanja::LijevoDesno){
            for (int k = 0; k < Kvadar[0][0].size(); k++) {
                for (int j = 0; j < Kvadar[0].size(); j++) {
                    for (int i = Kvadar.size()-1; i >= 0; i--) {
                        if (Kvadar.size()-1-i == j) ElementiDijagonala[k].push_back(Kvadar[i][j][k]);
                        
                    }
                }
            }
        }
        else  if (trenutniSmjer ==  SmjerKretanja::DesnoLijevo){
            for (int k = Kvadar[0][0].size()-1; k >=0; k--) {
                for (int j = 0; j < Kvadar[0].size(); j++) {
                    for (int i = 0; i < Kvadar.size(); i++) {
                        if (i == j) ElementiDijagonala[Kvadar[0][0].size()-1-k].push_back(Kvadar[i][j][k]);
                        
                    }
                }
            } 
        }
    }
   
    return ElementiDijagonala;
}

/* Safe copy{
std::deque<std::vector<int>> IzdvojiDijagonale3D(std::vector<std::deque<std::vector<int>>> Kvadar, SmjerKretanja trenutniSmjer){
    std::deque<std::vector<int>> ElementiDijagonala;
    
    bool ekvidistantni(true);
    int duzina = Kvadar[0].size();
    for (int i = 0; i < Kvadar[i].size(); i++) {
        if (Kvadar[i].size() != duzina) {
            ekvidistantni = false;
            break;
        }
    }
    if (!ekvidistantni) {
        throw std::domain_error ("Plohe nemaju isti broj redova");
    }
    
    int duzina = Kvadar[0][0].size();
    for (int i = 0; i < Kvadar.size(); i++) {
        for (int j = 0; j < Kvadar[i].size(); j++) {
            if (duzina != Kvadar[i][j]) {
                ekvidistantni = false;
                break;
            }
        }
            
    }
    
    
    if (trenutniSmjer ==  SmjerKretanja::NaprijedNazad || trenutniSmjer ==  SmjerKretanja::NazadNaprijed) {
        ElementiDijagonala.resize(Kvadar.size());
        if (trenutniSmjer ==  SmjerKretanja::NaprijedNazad) {
            for (int i = 0; i < Kvadar.size(); i++) {
                int k = 0;
                for (int j = 0; j < Kvadar[0].size(); j++) {
                    if (k == Kvadar[0][0].size()) {
                        break;
                    }
                    else{
                        ElementiDijagonala[i].push_back(Kvadar[i][j][k++]);
                    }
                }
            }
        }
        else if (trenutniSmjer ==  SmjerKretanja::NazadNaprijed){
            int o(Kvadar.size()-1);
            for (int i = Kvadar.size()-1; i >= 0; i--) {
                int k = Kvadar[0][0].size()-1;
                
                for (int j = 0; j < Kvadar[0].size(); j++) {
                    if (k == 0) {
                        break;
                    }
                    else{
                        ElementiDijagonala[o].push_back(Kvadar[Kvadar.size()-i-1][j][k--]);
                    }
                }o--;
            }
        } //promjeniti na x y z
    } // Kod za NaprijedNazad i NazadNaprijed
    
    else if(trenutniSmjer ==  SmjerKretanja::GoreDolje || trenutniSmjer ==  SmjerKretanja::DoljeGore){
        ElementiDijagonala.resize(Kvadar[0].size());
        if (trenutniSmjer ==  SmjerKretanja::GoreDolje){
            for (int j = 0; j < Kvadar[0].size(); j++) {
                int o(1);
                for (int i = 0; i < Kvadar.size(); i++) {
                    for (int k = 0; k < Kvadar[0][0].size(); k++) {
                        if (k == i) ElementiDijagonala[j].push_back(Kvadar[i+o][j][i]);
                    }
                    o *= -1;
                }
            }
        }
        else  if (trenutniSmjer ==  SmjerKretanja::DoljeGore){
            for (int j = Kvadar[0].size()-1; j >= 0; j--) {
                int o = Kvadar[0][0].size()-1;
                for (int i = Kvadar.size()-1; i >= 0; i--) {
                    if (o == 0) break;
                    
                    ElementiDijagonala[Kvadar[0].size()-1-j].push_back(Kvadar[i][j][o--]);
                }
            }
        }
    } // Kod za GoreDolje i DoljeGore
    
    else if(trenutniSmjer ==  SmjerKretanja::LijevoDesno || trenutniSmjer ==  SmjerKretanja::DesnoLijevo){
        ElementiDijagonala.resize(Kvadar[0][0].size());
        if (trenutniSmjer ==  SmjerKretanja::LijevoDesno){
            for (int k = 0; k < Kvadar[0][0].size(); k++) {
                for (int j = 0; j < Kvadar[0].size(); j++) {
                    for (int i = Kvadar.size()-1; i >= 0; i--) {
                        if (Kvadar.size()-1-i == j) ElementiDijagonala[k].push_back(Kvadar[i][j][k]);
                        
                    }
                }
            }
        }
        else  if (trenutniSmjer ==  SmjerKretanja::DesnoLijevo){
            for (int k = Kvadar[0][0].size()-1; k >=0; k--) {
                for (int j = 0; j < Kvadar[0].size(); j++) {
                    for (int i = 0; i < Kvadar.size(); i++) {
                        if (i == j) ElementiDijagonala[Kvadar[0][0].size()-1-k].push_back(Kvadar[i][j][k]);
                        
                    }
                }
            } 
        }
    }
   
    return ElementiDijagonala;
}

}*/

int main (){
    int x, y, z;
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> x >> y >> z;
    
    if (x <= 0 || y <= 0 || z <= 0) {
        std::cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    
    
    std::cout << "Unesite elemente kontejnera: " << std::endl;
    std::deque<std::vector<int>> Y(y, std::vector<int>(z));
    std::vector<std::deque<std::vector<int>>> Kvadar(x, Y);
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                std::cin >> Kvadar[i][j][k];
            }
        }
    }  //Elementi sigurno uspjesno ucitani
    
    int s;
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    std::cin >> s;
    
    if (s < 0 || s > 5) {
        std::cout << "Smjer kretanja nije ispravan!" << std::endl;
        return 0;
    }
    
    
    try{
        Y = IzdvojiDijagonale3D (Kvadar, SmjerKretanja(s));
        
        if (s == 0) std::cout << "NaprijedNazad: " << std::endl;
        else if (s == 1)  std::cout << "NazadNaprijed: " << std::endl;
        else if (s == 2)  std::cout << "GoreDolje: " << std::endl;
        else if (s == 3)  std::cout << "DoljeGore: " << std::endl;
        else if (s == 4)  std::cout << "LijevoDesno: " << std::endl;
        else if (s == 5)  std::cout << "DesnoLijevo: " << std::endl;
        
        for (int i = 0; i < Y.size(); i++) {
            for (int j = 0; j < Y[0].size(); j++) {
                std::cout << std::setw(4) << Y[i][j];
            }
            std::cout  << std::endl;
        }
    }
    catch (...){
        std::cout << "Nesto se neocekivano desilo" << std::endl;
    }
	return 0;
}