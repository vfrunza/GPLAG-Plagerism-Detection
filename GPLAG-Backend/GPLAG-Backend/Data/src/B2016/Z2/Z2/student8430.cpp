// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
#include <stdexcept>
using namespace std;

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};


template<typename Tip1>
auto IzdvojiDijagonale3D(Tip1 kont , SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type{
    
    int brojElemenata = kont.at(0).at(0).size();
    
    for(int i = 0 ; i < kont.size() ; i++){
        for(int j = 0 ; j < kont.at(0).size() ; j++){
            if(kont.at(i).at(j).size() != brojElemenata){
                throw domain_error("Redovi nemaju isti broj elemenata");
            }
        }
    }
    
    typename std::remove_reference<decltype(kont.at(0))>::type rez;
    
    if(smjer == SmjerKretanja::NaprijedNazad || smjer == SmjerKretanja::NazadNaprijed){
        typename std::remove_reference<decltype(kont.at(0))>::type pom(kont.size(), typename std::remove_reference<decltype(kont.at(0).at(0))>::type(kont.at(0).size()));
        rez = pom;
    }
    else if(smjer == SmjerKretanja::GoreDolje || smjer == SmjerKretanja::DoljeGore){
        typename std::remove_reference<decltype(kont.at(0))>::type pom(kont.at(0).size(), typename std::remove_reference<decltype(kont.at(0).at(0))>::type(kont.size()));
        rez = pom;
    }
    else {
        typename std::remove_reference<decltype(kont.at(0))>::type pom(kont.at(0).at(0).size(), typename std::remove_reference<decltype(kont.at(0).at(0))>::type(kont.size()));
        rez = pom;
    }
  
    if(smjer == SmjerKretanja::NaprijedNazad || smjer == SmjerKretanja::NazadNaprijed){
        int pomocni_k = 0;
        for(int z = 0 ; z < kont.size() ; z++){
            for(int i = 0 ; i < kont.at(0).size() ; i++){
                for(int j = 0 ; j < kont.at(0).at(0).size() ; j++){
                
                    if(smjer == SmjerKretanja::NaprijedNazad && i == j){
                        rez.at(z).at(i) = kont.at(z).at(i).at(j);
                    }
                    else if(smjer == SmjerKretanja::NazadNaprijed && j == kont.at(0).at(0).size() - pomocni_k - 1){
                        rez.at(kont.size() - 1 - z).at(pomocni_k) = kont.at(z).at(i).at(j);
                        pomocni_k++;
                    }
                }
            }
            pomocni_k = 0;
        }
    }
    else if(smjer == SmjerKretanja::GoreDolje || smjer == SmjerKretanja::DoljeGore || smjer == SmjerKretanja::LijevoDesno){
        int pomocna_j = 0;
        int pomocna_k = kont.at(0).at(0).size();
        int pomocna_i = 0;
        for(int z = kont.size() - 1 ; z >= 0 ; z--){
            for(int i = 0 ; i < kont.at(0).size() ; i++){
                for(int j = 0 ; j < kont.at(0).at(0).size() ; j++){
                
                    if(smjer == SmjerKretanja::GoreDolje && j == pomocna_j){
                        rez.at(i).at(pomocna_j) = kont.at(z).at(i).at(j);
                    }
                    if(smjer == SmjerKretanja::DoljeGore && j == pomocna_k - 1){
                        rez.at(kont.at(0).size() - i - 1).at(pomocna_j) =  kont.at(z).at(i).at(j);
                    }
                    if(smjer == SmjerKretanja::LijevoDesno && i == pomocna_i){
                        rez.at(j).at(pomocna_i) =  kont.at(z).at(i).at(j);
                    }
                    
                }
            }
            pomocna_j++;
            pomocna_k--;
            pomocna_i++;
        }
    }
    else{
        
        int pomocna_i = 0;
        for(int z = 0 ; z < kont.size() ; z++){
            for(int i = 0 ; i < kont.at(0).size() ; i++){
                for(int j = 0 ; j < kont.at(0).at(0).size() ; j++){
                
                    if(i == pomocna_i){
                       rez.at(kont.at(0).at(0).size() - 1 - j).at(z) =  kont.at(z).at(i).at(j);
                    }
                    
                }
            }
            pomocna_i++;
        }
        
    }
    
    return rez;
}


int main ()
{
    
    int x,y,z;
    cout << "Unesite dimenzije (x y z): ";
    cin >> x;
    cin >> y;
    cin >> z;
    
    if(x < 0 || y < 0 || z < 0){
        cout << "Neispravne dimenzije kontejnera!" << endl;
        return 0;
    }
    
    vector<deque<deque<int>>> kont(x , deque<deque<int>>(y , deque<int>(z)));
    cout << "Unesite elemente kontejnera:" << endl;
    
    for(int i = 0; i < x ; i++){
        for(int j = 0 ; j < y ; j++){
            for(int k = 0 ; k < z ; k++){
                cin >> kont.at(i).at(j).at(k);
            }
        }
    }
    
    cout << "Unesite smjer kretanja [0 - 5]: ";
    int smjer;
    cin >> smjer;
    
    if(smjer < 0 || smjer > 5){
        cout << "Smjer kretanja nije ispravan!" << endl;
    }
    
    deque<deque<int>> p;
    try{
        if(smjer == 0){
            p = IzdvojiDijagonale3D(kont , SmjerKretanja::NaprijedNazad);
            cout << "NaprijedNazad:" << endl;
        }
        else if(smjer == 1){
            p = IzdvojiDijagonale3D(kont , SmjerKretanja::NazadNaprijed);
            cout << "NazadNaprijed:" << endl;
        }
        else if(smjer == 2){
            p = IzdvojiDijagonale3D(kont , SmjerKretanja::GoreDolje);
            cout << "GoreDolje:" << endl;
        }
        else if(smjer == 3){
            p = IzdvojiDijagonale3D(kont , SmjerKretanja::DoljeGore);
            cout << "DoljeGore:" << endl;
        }
        else if(smjer == 4){
            p = IzdvojiDijagonale3D(kont , SmjerKretanja::LijevoDesno);
            cout << "LijevoDesno:" << endl;
        }
        else if(smjer == 5){
            p = IzdvojiDijagonale3D(kont , SmjerKretanja::DesnoLijevo);
            cout << "DesnoLijevo:" << endl;
        }
    }
    catch(domain_error e){
        cout << e.what() << endl;
        return 0;
    }
    
    for(int i = 0 ; i < p.size() ; i++){
        for(int j = 0 ; j < p.at(0).size() ; j++){
            cout << "   " <<  p.at(i).at(j);
        }
        cout << endl;
    }

	return 0;
}