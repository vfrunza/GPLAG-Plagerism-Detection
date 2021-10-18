/*
    Manje od 2 i po sata do isteka roka :O
    Hajmo da vidimo koliko se moze stici
    
    Wish me luck ^_^
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <list>
#include <stdexcept>

class Temperature{
        int najmanja, najveca;
        std::list<int> maxTemp, minTemp;
        void BaciRangeError(){
            throw std::range_error ("Nekorektne temperature");
        }
    public:
        Temperature (int najmanja, int najveca){
            if(najmanja > najveca) BaciRangeError();
            Temperature::najmanja = najmanja; Temperature::najveca = najveca;
        }
        void RegistrirajTemperature (std::pair<int, int> minMax){
            //        vr manja od minimuma    vr veca od maximuma          max vr manja od minimuma   min vr veca od maksimuma
            if (minMax.first < najmanja || minMax.second > najveca || minMax.second < najmanja || minMax.first > najveca || minMax.first > minMax.second) BaciRangeError();
            minTemp.emplace_back (minMax.first);    maxTemp.emplace_back (minMax.second);
        } 
        void BrisiSve(){
            maxTemp.clear();
            minTemp.clear();
        }
        void BrisiTemperature(std::pair<int, int> parZaBrisanje){
            std::list<std::pair<int, int>> a;
            std::transform(minTemp.begin(), minTemp.end(), maxTemp.begin(), a.begin(), [parZaBrisanje] (int b, int c){
                if ()
            });
            if (maxTemp.empty) throw std::logic_error ("Takve temperature nisu registrovane");
        }
};

int main (){
	
	return 0;
}