/*/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>

int main ()
{
	return 0;
}
*/

//CETVRTI ZADATAK

#include <iostream>
#include <list>
#include <memory>
#include <algorithm>
#include <vector>

class Skup {
    std::vector<double> vektor;
public:
    Skup() : vektor;
    Skup(std::initializer_list<double> lista): vektor(lista) {}; //KOSTUR SEKVENCIJSKOG //kopira sve, ali treba napraviti da izostavi duplikate
    /*Skup(std::initializer_list<double> lista): {
      std::initializer_list<double> nova_lista;
      auto *it = nova_lista;
      for(auto *it1 = lista.begin(); it1 != lista.end(); it1++){
        if (*it1 == *(it1+1)) continue;
        else nova_lista.insert(*it1);
      }
      vektor(nova_lista);
    };*/
    int Velicina() const { return vektor.size();}
    void Dodaj(double x) {
        for(int i = 0 ; i < vektor.size(); i++){
            if(x == vektor[i])) continue;
            vektor.push_back(x);
        }
        std::sort(std::begin(vektor),std::end(vektor));
    }
    void Izbrisi(double x);
    bool ImaLiGa(double x) {
        int brojac(0);
        for(int i = 0 ; i < vektor.size(); i++){
            if( x == vektor[i]) brojac++;
        }
        if(brojac > 0) return true;
        else return false;
    }
    void Ispisi() const {
        std::sort(std::begin(vektor),std::end(vektor));
        for(int i = 0 ; i < vektor.size(); i++){
            std::cout << vektor[i] << " ";
        }
    }
};

void Skup::Izbrisi(double x){
    for(int i = 0 ; i < vektor.size(); i++){
        if( x == vektor[i]){
            vektor[i] == vektor[vektor.size()-1];
        }
        vektor.resize();
        i--;
    }
    std::sort(std::begin(vektor),std::end(vektor));
}

int main()
{
    return 0;
}
