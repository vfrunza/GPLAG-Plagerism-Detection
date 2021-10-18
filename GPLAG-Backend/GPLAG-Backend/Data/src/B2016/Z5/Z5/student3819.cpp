/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <utility>
#include <stdexcept>
class Temeperature {
    std::list<int> max;
    std::list<int> min;
    public:
        Temeperature(int min, int max){
            if(min>max) throw std::range_error("Nekorektne temperature");
            Temeperature::max.push_back(max); Temeperature::min.push_back(min);
        }
        void RegistrirajTemperature(std::pair<int, int> par);
        void BrisiSve() { max.clear(); min.clear();}
};
int main ()
{
	return 0;
}