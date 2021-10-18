// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	


#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>

using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::deque;
using std::domain_error;
/*
enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};
    
template <typename kont, typename tip>
auto IzdvojiDijagonale3D (kont<kont<kont<tip>>> Kocka, SmjerKretanja::smjer) -> typename std::remove_reference<decltype(kont[0])>{
    std::remove_reference<decltype(kont[0])>::type Matrica;
    
    // IZUZECI
    if(Kocka.size()==0) return {};
    
    for(int i=0; i<Kocka.size(); i++){
        for(int j=i; j<Kocka.size(); j++){
           if(Kocka[i].size()!=Kocka[j].size()){
               throw domain_error ("“Plohe nemaju isti broj redova");
           } 
        }
    }
    for(int i=0; i<Kocka.size(); i++){
        for(int j=i; j<Kocka[i].size; j++){
            for(int k=j; k<Kocka[i].size; k++){
                if(Kocka[i][j].size()!=Kocka[i][k].size()){
                    throw domain_error ("“Redovi nemaju isti broj elemenata");
                }
            }
        }
    }
    
    // SLUCAJEVI
    
    switch(smjer):
    
    // NAPRIJED NAZAD
    case (NaprijedNazad):
    for(int i=0; i<Kocka.size(); i++){
        for(j=0; j<Kocka[i].size(); j++){
            Matrica[i][j]=Kocka[i][j][j];
        }
    }
    return Matrica;
        
    // NAZAD NAPRIJED
    case(NazadNaprijed):
    for(int i=Kocka.size()-1; i>=0; i--){
        for(int j=Kocka[i].size()-1; j>=0; j--){
            Matrica[i-Kocka.size()+1][j-Kocka[i].size()+1]=Kocka[i][j][j];
        }
    }
    return Matrica;
    
    // GORE DOLJE
    case(GoreDolje):
    
    break;
    
    // DOLJE GORE
    case(DoljeGore):
    
    break;
    
    // LIJEVO DESNO
    case(LijevoDesno):
    
    break;
    
    // DESNO LIJEVO
    case(DesnoLijevo):
    
    break;
    
    
}
*/
int main ()
{
    vector<deque<deque<int>>> Kocka;
    int x,y,z;
    cout<<"Unesite dimenzije (x y z): ";
    cin>>x>>y>>z;
    cout<<"Unesite elemente kontejnera: ";
    for(int i=0; i<x; i++){
        Kocka.push_back(deque<deque<int>>);
        for(int j=0; j<y; j++){
            Kocka[i].push_back(deque<int>);
            for(int k=0; k<z; k++){
                int element; 
                cin>>element;
                Kocka[i][j].push_back(element);
            }
        }
        
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                cout<<Kocka[i][j][k]<<"  ";
            }
        cout<<endl;
        }
        cout<<endl<<endl;
    }

	return 0;
}