/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <utility>
#include <list>
using namespace std;

class Temperature {
    list<int> minimalne_temperature;
    list<int> maksimalne_temperature;
public:
    Temperature(int maks_temp, int min_temp) {
        if(min_temp > maks_temp) throw range_error("Nekorektne temperature");
    }
    void RegistrirajTemperature(pair<int, int> temperature)
};
int main ()
{
	return 0;
}