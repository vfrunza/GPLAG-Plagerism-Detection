/B16/17 (Zadaća 5, Zadatak 5)

#include <iostream>
#include <list>
#include <utility>
#include <stdexcept>
#include <algorithm>

using std::list;
using std::pair;

class Temperature{
    list<int> minimalne, maksimalne;
    int min, max;
public:
    // { minimalne.insert(--minimalne.end(), temp.first); maksimalne.insert(--maksimalne.end(), temp.second); };
    Temperature(pair<int, int> temp){
        if(temp.first>temp.second) throw std::range_error("Nekorektne temperature");
        min=temp.first;
        max=temp.second;
    }
    
    // Metode
    void Granice(int donja, int gornja){
        if(donja<min || gornja>max || donja>gornja) throw std::range_error("Nekorektne temperature");
    }
    void RegistrirajTemperature(pair<int, int> temp){
        Granice(temp.first, temp.second);
        minimalne.insert(--minimalne.end(), temp.first);
        maksimalne.insert(--maksimalne.end(), temp.second);
    }
    
    /* Kako rastuziti studenta: Student uradi funkcije i tek na kraju procita da se ne smiju koristiti petlje 15 min pred rok :(
    
    void BrisiSve(){
        while(++minimalne.begin()!=minimalne.end()) minimalne.erase(minimalne.begin());
        while(++maksimalne.begin()!=maksimalne.end()) maksimalne.erase(maksimalne.begin());
    }
    void BrisiNegativneTemperature(){
        auto it1(minimalne.begin());
        auto it2(maksimalne.begin());
        
        while(it1!=minimalne.end()){
            if(*it1<0 && *it2<0){
                minimalne.erase(it1);
                maksimalne.erase(it2);
            }
            it1++;
            it2++;
        }
    }
    int DajMinimalnuTemperaturu() const {
        if(minimalne.size()==0) throw std::logic_error("Nema registriranih temperatura");
        auto it(minimalne.begin());
        int min = *it;
        while(it!=minimalne.end()){
            if(*it<min) min = *it;
            it++;
        }
        return min;
    }
    int DajMaksimalnuTemperaturu() const {
        if(minimalne.size()==0) throw std::logic_error("Nema registriranih temperatura");
        auto it(maksimalne.begin());
        int max = *it;
        while(it!=maksimalne.end()){
            if(*it>max) max = *it;
            it++;
        }
        return max;
    }
    int DajBrojTemperaturaManjihOd(int x) const {
        if(minimalne.size()==0) throw std::logic_error("Nema registriranih temperatura");
        auto it(minimalne.begin());
        int br(0);
        while(it!=maksimalne.end()){
            if(*it<x) br++;
            it++;
        }
        return br;
    }
     int DajBrojTemperaturaVecihOd(int x) const {
        if(minimalne.size()==0) throw std::logic_error("Nema registriranih temperatura");
        auto it(maksimalne.begin());
        int br(0);
        while(it!=maksimalne.end()){
            if(*it>x) br++;
            it++;
        }
        return br;
    }
    */
    
    bool operator !(){
        if(maksimalne.size()==0) return true;
        else return false;
    }
    const pair<int, int> operator [](int x){
        if(x<=0 || x>maksimalne.size()) throw std::range_error("Neispravan indeks");
    }
    
};

int main (){
    pair<int,int> x(2,5);
    Temperature t(x);
    Temperature p(x);
    t.RegistrirajTemperature(x);
    std::cout << !p << "    " << !t;
	return 0;
}