/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cmath>
#include <vector>

class Razlomak {
long long int brojnik;
long long int nazivnik;
public:
Razlomak(long long int brojnik1, long long int nazivnik1) {
    if(nazivnik1==0) throw std::logic_error("Nekorektan razlomak");
    if(nazivnik1>brojnik1) long long int temp(nazivnik1%brojnik1);
    else if(brojnik1>nazivnik1) long long int temp(brojnik1%nazivnik1);
    if((brojnik1%temp==0) && (nazivnik1%temp==0)) {
        if(brojnik1>0 && nazivnik1>0) {
            brojnik=brojnik1/temp;
            nazivnik=nazivnik1/temp;
        } else {
            if(brojnik1>0 && nazivnik1<0) {
                brojnik=-(brojnik1/temp);
                nazivnik=abs(nazivnik1)/temp;
            } else {
                if(brojnik1<0 && nazivnik1<0) {
                    brojnik=abs(brojnik1)/temp;
                    nazivnik=abs(nazivnik1)/temp;
                } else {
                    if(brojnik1<0 && nazivnik1>0) {
                        brojnik=-(abs(brojnik1)/temp);
                        nazivnik=nazivnik1;
                    }
                }
            }
        } 
    } else {
        brojnik=brojnik1;
        nazivnik=nazivnik1;
    }
}
}

int main () {
    
	return 0;
}