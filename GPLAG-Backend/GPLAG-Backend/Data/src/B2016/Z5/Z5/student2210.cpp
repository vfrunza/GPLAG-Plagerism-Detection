#include <iostream>
#include <stdexcept>
#include <list>

class Temperature{
    std::list<int> minimalne;
    std::list<int> maksimalne;
public:
    Temperature(int min, int max){
        if(min>max) throw std::range_error("Nekorektne temperature");
        minimalne.push_back(min); maksimalne.push_back(max);
    }
    void RegistrirajTemperature(std::pair<int, int> p){
        for(auto it=minimalne.begin(); it!=minimalne.end(); it++)
            if(p.first<*it)throw std::range_error("Nekorektne temperature");
        for(auto it=maksimalne.begin(); it!=maksimalne.end(); it++)
            if(p.second>*it)throw std::range_error("Nekorektne temperature");
        if(p.first>p.second)throw std::range_error("Nekorektne temperature");
        minimalne.push_back(p.first); maksimalne.push_back(p.second);
    }
    void BrisiSve(){
            minimalne.erase(minimalne.begin(), minimalne.end());
            maksimalne.erase(maksimalne.begin(), maksimalne.end());
    }
    void BrisiNegativneTemperature(){
        auto it1(minimalne.begin()); auto it2(maksimalne.begin());
        while(it1!=minimalne.end()){
            if(*it1<0 && *it2<0){minimalne.erase(it1); maksimalne.erase(it2);}
            it1++; it2++;
        }
    }
    int DajBrojRegistriranihTemperatura(){
        return minimalne.size();
    }
    int DajMinimalnuTemperaturu(){
        int min(*minimalne.begin());
        for(auto it=minimalne.begin(); it!=minimalne.end(); it++){
            if(*it<min) min=*it;
        }return min;
    }
    int DajMaksimalnuTemperaturu(){
        int max(*maksimalne.begin());
        for(auto it=maksimalne.begin(); it!=maksimalne.end(); it++){
            if(*it>max) max=*it;
        }return max;
    }
    int DajBrojTemperaturaVecihOd(int v){
        
    }
};

int main (){
    
	return 0;
}