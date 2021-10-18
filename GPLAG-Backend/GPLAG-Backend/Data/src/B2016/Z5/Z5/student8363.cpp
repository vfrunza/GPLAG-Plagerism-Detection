/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <utility>
#include <list>

using std::cin;
using std::cout;
using std::endl;

class Temperature{
    int min,max;
    std::list<int> mx_tmp,mn_tmp;
    void throwerr(int i=0){
        switch(i){
            case 0: throw std::range_error("Neispravan indeks");
            case 1: throw std::logic_error("Ilegalna operacija");
        }
    }
    void check(int mn,int mx){
        if(mn>max || mx < min || mn>mx)
            throw std::range_error("Nekorektne temperature");
    }
    public:
    Temperature(std::pair<int,int>);
};
int main ()
{
	return 0;
}