// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename KontTip>
auto IzdvojiDijagonale3D(KontTip kont, SmjerKretanja sm) -> typename std::remove_reference<decltype(kont.at(0))>::type {
    for(int i(0); i < kont.size(); i++){
        if(kont.at(0).size() != kont.at(i).size()) throw std::domain_error ("Plohe nemaju isti broj redova");
    }
    for(int i(0); i < kont.size(); i++){
        for(int j(0); j < kont.at(i).size(); j++){
            if(kont.at(i).at(0).size() != kont.at(i).at(j).size()) throw std::domain_error ("Redovi nemaju isti broj elemenata");
        }
    }
    
    typename std::remove_reference<decltype(kont.at(0))>::type rezultantna_Matrica;
    
    if(sm==SmjerKretanja::NaprijedNazad) {
    for( int i(0); i < kont.size(); i++){
        for(int j(0); j < (kont.at(i)).size(); j++ ){
            for(int k(0); k < ((kont.at(i)).at(j)).size(); k++ ){
                if( k == j){
                    
                    rezultantna_Matrica.push_back(typename std::remove_reference<decltype(kont.at(0).at(0))>::type());
                    auto nesto = kont.at(i).at(j).at(k);
                    
                    rezultantna_Matrica.at(i).push_back(nesto);
                }
            }
        }
    }
    }
    int brojac=0;
    if(sm==SmjerKretanja::NazadNaprijed) {
    for( int i=kont.size()-1; i >=0; i--){
        for(int j=0; j <(kont.at(i)).size(); j++){
            for(int k=((kont.at(i)).at(j)).size()-1 ; k >= 0 ; k-- ){
                if( ((kont.at(i)).at(j)).size()-1 - k   == j){
                    
                    rezultantna_Matrica.push_back(typename std::remove_reference<decltype(kont.at(0).at(0))>::type());
                    auto nesto = kont.at(i).at(j).at(k);
                    
                    rezultantna_Matrica.at(brojac).push_back(nesto);
                }
            }
            
        }
        brojac++;
    }
    }
    brojac=0;
    if(sm==SmjerKretanja::DesnoLijevo) {
        for(int k=kont.at(0).at(0).size() - 1; k >=0; k--){
            
        for(int j(0); j < kont.at(0).size(); j++){
            for( int i(0); i < kont.size(); i++){
                if( i == j){
                   
                    rezultantna_Matrica.push_back(typename std::remove_reference<decltype(kont.at(0).at(0))>::type());
                    auto nesto = kont.at(i).at(j).at(k);
                    
                    rezultantna_Matrica.at(brojac).push_back(nesto);
                }
            }
            
        }
        brojac++;
    }
        
    }
    if(sm==SmjerKretanja::LijevoDesno) {
        for(int k=0; k < kont.at(0).at(0).size(); k++){
            
        for(int j(0); j <kont.at(0).size(); j++){
            for( int i= kont.size() - 1; i >= 0; i--){
                if( kont.size() - 1 - i == j){
                    
                    rezultantna_Matrica.push_back(typename std::remove_reference<decltype(kont.at(0).at(0))>::type());
                    auto nesto = kont.at(i).at(j).at(k);
                    
                    rezultantna_Matrica.at(brojac).push_back(nesto);
                }
            }
            
        }
        brojac++;
    }
        
    }
    if(sm==SmjerKretanja::GoreDolje) {
        for(int j=0; j < kont.at(0).size(); j++){
            
        for(int k(0); k <kont.at(0).at(0).size(); k++){
            for( int i= kont.size() - 1; i >= 0; i--){
                if( kont.size() - 1 - i == k){
                    
                    rezultantna_Matrica.push_back(typename std::remove_reference<decltype(kont.at(0).at(0))>::type());
                    auto nesto = kont.at(i).at(j).at(k);
                    
                    rezultantna_Matrica.at(brojac).push_back(nesto);
                }
            }
            
        }
        brojac++;
    }
        
    }
    if(sm==SmjerKretanja::DoljeGore) {
        for(int j=kont.at(0).size() -1; j >= 0; j--){
            
        for(int k= kont.at(0).at(0).size() - 1; k >=0; k--){
            for(int i= kont.size() - 1; i >= 0; i--){
                if( kont.size() - 1 - i == kont.at(0).at(0).size() - 1 -k){
                    
                    rezultantna_Matrica.push_back(typename std::remove_reference<decltype(kont.at(0).at(0))>::type());
                    auto nesto = kont.at(i).at(j).at(k);
                    
                    rezultantna_Matrica.at(brojac).push_back(nesto);
                }
            }
            
        }
        brojac++;
    }
        
    }
        
    
    return rezultantna_Matrica;
}

int main ()
{
    
    std::cout << "Unesite dimenzije (x y z): ";
    int br1, br2, br3;
    std::cin >> br1 >> br2 >>br3;
    if(br1 < 1 || br2 < 1 || br3 < 1){ std::cout<<"Neispravne dimenzije kontejnera!\n"; return 0; }
    
    std::vector<std::deque<std::deque<int>>> kont;
    int element;
    std::cout << "Unesite elemente kontejnera: " << std::endl;
    for(int i=0; i<br1; i++) {
        kont.resize(kont.size() + 1);
        for(int j=0; j<br2; j++) {
            kont[i].resize( kont[i].size() + 1);
            for(int z=0; z<br3; z++) {
                std::cin >> element;
                kont[i][j].push_back(element);
            }
        }
    }
    int br;
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    
    std::cin >> br;
    if(br < 0 || br > 5){ std::cout<<"Smjer kretanja nije ispravan!\n"; return 0; }
    
    SmjerKretanja a= static_cast<SmjerKretanja>(br); // ovo je deklaracija
    
try{
    std::deque<std::deque<int>> matrica = IzdvojiDijagonale3D(kont, a); 

    switch( int(a) ){  // ovdje preko ovog switcha 
        
        case 0 : std::cout<<"NaprijedNazad: "; break;
        case 1 : std::cout<<"NazadNaprijed: "; break;
        case 2 : std::cout<<"GoreDolje: "; break;
        case 3 : std::cout<<"DoljeGore: "; break;
        case 4 : std::cout<<"LijevoDesno: "; break;
        case 5 : std::cout<<"DesnoLijevo: "; 
    }
    std::cout<<"\n";
    for(auto red: matrica){
        for(auto broj : red){
            std::cout<< std::setw(4) << broj;
        }
        std::cout<<"\n";
    }
}catch(std::domain_error e){
    std::cout<<"Izuzetak: "<<e.what();
}
	return 0;
}