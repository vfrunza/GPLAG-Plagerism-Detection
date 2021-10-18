#include <iostream>
#include <stdexcept>
#include <list>
#include <cmath>

class Temperature{
    std::list<int> mini;
    std::list<int> maxi;
    public:
    Temperature(int t1,int t2){
         if(abs(t1)>t2){
            throw std::range_error("Nekorektne temperature");
        }
        mini.push_back(t1);
        maxi.push_back(t2);
    }
    void RegistrirajTemperature(std::pair<int,int> p){
         if(abs(p.first)>p.second){
        throw std::range_error("Nekorektne temperature");
    } 
     mini.push_back(p.first);
     maxi.push_back(p.second);
   
    }
    
    
    
    
};


int main ()
{
	return 0;
}