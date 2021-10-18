// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdexcept>
#include <deque>

using std::cout;
using std::cin;
using std::vector;
using std::deque;


template <typename TipKontejnera>
auto IzdvojiDijagonale3D(TipKontejnera kutija) -> typename std::remove_reference<decltype(kutija.at(0))>::type {
    auto dijagonala(kutija.at(0).at(0));
    auto matrica(kutija.at(0));
    dijagonala.resize(0);
    matrica.resize(0);
    for(int i=0;i<kutija.size();i++){
        for(int j=0;j<kutija.at(i).size();j++){
            for(int k=0;k<kutija.at(i).at(j).size();k++){
               if(k==j) dijagonala.push_back(kutija.at(i).at(j).at(k));
            } 
        }
        matrica.push_back(dijagonala);
        dijagonala.resize(0);
    }
    return matrica;
}

int main ()
{
    vector<deque<deque<int>>> kutija;
    deque<deque<int>> dek2;
    deque<int> dek1;
    cout << "Unesite dimenzije (x y z): ";
    int x, y, z, el;
    cin >> x >> y >> z;
    cout << "\nUnesite elemente kontejnera: \n";
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                cin >> el;
                dek1.push_back(el);
            }
            dek2.push_back(dek1);
            dek1.resize(0);
            cout << "\n";
        }
        kutija.push_back(dek2);
        dek2.resize(0);
        cout << "\n\n\n";
    }
    deque<deque<int>> matrica(IzdvojiDijagonale3D(kutija));
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
          cout << matrica.at(i).at(j) << " ";
        }
        cout << "\n";
    }
    
	return 0;
}