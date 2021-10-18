/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>

using namespace std;

class Temperature {
    list<int>max_temp;
    list<int>min_temp;
    public:
    Temperature(int mx_t,int mn_t);
    void RegistrirajTemperature(pair<int,int>temperature);
};
Temperature::Temperature(int mx_t,int mn_t){
    if(mn_t>mx_t)throw range_error("Nekorektne temperature");
    max_temp.push_back(mx_t);
    min_temp.push_back(mn_t);
}
void Temperature::RegistrirajTemperature(pair<int,int>temperature){
    
}
int main ()
{
	return 0;
}