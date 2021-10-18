// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <stdexcept>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo   
};

template <typename kont>
    auto IzdvojiDijagonale3D(kont kontejner3d, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kontejner3d.at(0))>::type {
    typename std::remove_reference<decltype(kontejner3d.at(0))>::type kontejner2d;
    
    //DODO 29.4. prije isteka roka // kad je neka od dimenzija nula vracaj prazan kontejner da ne bi bilo kraha xD
    
    if(kontejner3d.size()==0 || kontejner3d.at(0).size()==0 || kontejner3d.at(0).at(0).size()==0) return kontejner2d;
    
    //
    
    //provjera ispravnosti proslijeđene matrice - da li svi redovi u svim plohama imaju isti broj elemenata
    for(int i=0; i<kontejner3d.size(); i++){
        for(int j=0; j<kontejner3d.at(i).size()-1; j++){
            if(kontejner3d.at(i).at(j).size()!=kontejner3d.at(i).at(j+1).size())throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    //provjera ispravnosti proslijeđene matrice - da li sve plohe imaju isti broj redova(ide odvojeno jer se tek provjerava nakon onog gore, tako zadato u zadatku)
    for(int i=0; i<kontejner3d.size()-1; i++){
        if(kontejner3d.at(i).size()!=kontejner3d.at(i+1).size())throw std::domain_error("Plohe nemaju isti broj redova");
    }
    
    if(smjer==SmjerKretanja::NaprijedNazad || smjer==SmjerKretanja::NazadNaprijed){
        for(int i=0; i<kontejner3d.size(); i++){
            kontejner2d.resize(kontejner2d.size()+1);
            int zapamtivrijednost(i);
            if(smjer==SmjerKretanja::NazadNaprijed){
                i=kontejner3d.size()-i-1;
            }
        
            for(int j=0; j<kontejner3d.at(i).size(); j++){
                for(int k=0; k<kontejner3d.at(i).at(j).size(); k++){
                    if(k==kontejner3d.at(i).at(j).size()-j-1 && smjer==SmjerKretanja::NazadNaprijed)kontejner2d.at(zapamtivrijednost).push_back(kontejner3d.at(i).at(j).at(k));
                    if(j==k && smjer==SmjerKretanja::NaprijedNazad)kontejner2d.at(i).push_back(kontejner3d.at(i).at(j).at(k));
                }
            }
            i=zapamtivrijednost;
        }
    }
    else if(smjer==SmjerKretanja::GoreDolje || smjer==SmjerKretanja::DoljeGore){
        for(int i=kontejner3d.size()-1, br=0; i>=0; i--, br++){
            for(int j=0; j<kontejner3d.at(i).size(); j++){
                kontejner2d.resize(kontejner2d.size()+1);
                int zapamtivrijednost(j);
                if(smjer==SmjerKretanja::DoljeGore){
                    j=kontejner3d.at(i).size()-j-1;
                }
                
                for(int k=0; k<kontejner3d.at(i).at(j).size(); k++){
                    if(k==kontejner3d.at(i).at(j).size()-br-1 && smjer==SmjerKretanja::DoljeGore)kontejner2d.at(zapamtivrijednost).push_back(kontejner3d.at(i).at(j).at(k));
                    if(k==br && smjer==SmjerKretanja::GoreDolje)kontejner2d.at(j).push_back(kontejner3d.at(i).at(j).at(k));
                }
                j=zapamtivrijednost;
            }
        }
    }
    else if(smjer==SmjerKretanja::LijevoDesno || smjer==SmjerKretanja::DesnoLijevo){
        for(int i=kontejner3d.size()-1, br=0; i>=0; i--, br++){
            int zapamtivrijednost(i);
            if(smjer==SmjerKretanja::DesnoLijevo){
                i=kontejner3d.size()-1-i;
            }
            for(int j=0; j<kontejner3d.at(i).size(); j++){
                for(int k=0; k<kontejner3d.at(i).at(j).size(); k++){
                    int zapamtik(k);
                    kontejner2d.resize(kontejner2d.size()+1);
                    if(j==br && smjer==SmjerKretanja::DesnoLijevo){
                        k=kontejner3d.at(i).at(j).size()-k-1;
                        kontejner2d.at(zapamtik).push_back(kontejner3d.at(i).at(j).at(k));
                        k=zapamtik;
                    }
                    if(j==br && smjer==SmjerKretanja::LijevoDesno)kontejner2d.at(k).push_back(kontejner3d.at(i).at(j).at(k));
                    
                }
            }
            i=zapamtivrijednost;
        }
        
    }
    
    
    return kontejner2d;
    }

int main (){
    int x, y, z;
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> x >> y >> z;
    if(x<0 || y<0 || z<0){ //DODO mijenjo 29.4. pred kraj roka x<=0, y<=0 i z<=0 je bilo 
        std::cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::vector<std::deque<std::deque<int>>> kontejner3d(x);
    std::cout << "Unesite elemente kontejnera: ";
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            kontejner3d.at(i).resize(kontejner3d.at(i).size()+1);
            for(int k=0; k<z; k++){
                int x;
                std::cin >> x;
                kontejner3d.at(i).at(j).push_back(x);
            }
        }
        if(i!=x-1)std::cout << std::endl;
    }
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    int SmjerBroj;
    SmjerKretanja smjer;
    std::cin >> SmjerBroj;
    if(SmjerBroj<0 || SmjerBroj>5){
        std::cout << "Smjer kretanja nije ispravan!\n";
        return 0;
    }
    if(SmjerBroj==0){
        std::cout << "NaprijedNazad: ";
        smjer=SmjerKretanja::NaprijedNazad;
    }
    else if(SmjerBroj==1){
        std::cout << "NazadNaprijed: ";
        smjer=SmjerKretanja::NazadNaprijed;
    }
    else if(SmjerBroj==2){
        std::cout << "GoreDolje: ";
        smjer=SmjerKretanja::GoreDolje;
    }
    else if(SmjerBroj==3){
        std::cout << "DoljeGore: ";
        smjer=SmjerKretanja::DoljeGore;
    }
    else if(SmjerBroj==4){
        std::cout << "LijevoDesno: ";
        smjer=SmjerKretanja::LijevoDesno;
    }
    else if(SmjerBroj==5){
        std::cout << "DesnoLijevo: ";
        smjer=SmjerKretanja::DesnoLijevo;
    }
    
    //ispis unesenog kontejnera
    
 /*   for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                std::cout << kontejner3d[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        if(i!=x-1)std::cout << std::endl;
    } */
    
    try{
    std::deque<std::deque<int>> kontejner2d(IzdvojiDijagonale3D(kontejner3d, smjer));
    
        // ispis kontejner 2d;
    
        std::cout << std::endl;
        for(int i=0; i<kontejner2d.size(); i++){
            for(int j=0; j<kontejner2d.at(i).size(); j++){
                std::cout << std::setw(4) << kontejner2d.at(i).at(j);    
            }   
            std::cout << "\n";
        }
    }
    catch(const std::domain_error& e){
        std::cout << e.what() << std::endl;
    }
	return 0;
}