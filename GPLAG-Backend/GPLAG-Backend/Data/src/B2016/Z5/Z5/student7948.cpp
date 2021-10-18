/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
using namespace std;

class Temperature {
        list<int> min_temp;
        list<int> max_temp;
    public:
        Temperature(int min, int max) {
            if(min>max) throw range_error("Nekorektne temperature");
            min_temp.push_back(min);
            max_temp.push_back(max);
        }
};

int main ()
{
	return 0;
}