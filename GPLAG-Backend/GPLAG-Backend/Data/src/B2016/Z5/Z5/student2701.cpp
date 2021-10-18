/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
#include <stdexcept>

using namespace std;

class Temperature{
list<int> maksimalne;
list<int> minimalne;

public:

Temperature(int temp1, int temp2):{
    if(temp1>temp2) throw range_error("Nekorektne temperature");
}
  
void RegistrirajTemperature(pair<int,int> mojpar);
void BrisiSve();
void BrisiTemperature();
const int DajBrojRegistriranihTemperatura();
const int DajMinimalnuTemperaturu();
const int DajMaksimalnuTemperaturu();
const int DajBrojTemperaturaVecihOd();
const int DajBrojTemperaturaManjihOd();

    
    
    
};

void RegistrirajTemperature(pair<int,int> mojpar){
    
    
    
    
}




int main ()
{
    
    
	return 0;
}