/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>

class Razlomak {
        long long int brojnik,nazivnik;  
    public:
        Razlomak(long long int brojn, long long int naz=1) {
            if(naz==0) throw std::logic_error ("Nekorektan razlomak");
            long long int veci;
            if(brojn>naz) veci=brojn;
            else veci=naz;
            for(int i(2);i<veci;i++) {
                if(brojn%i==0 && naz%i==0) {        //TRAZENJE NZD-a!!!
                    brojn/=i;
                    naz/=i;
                }
            }
        }
};
int main ()
{
	return 0;
}