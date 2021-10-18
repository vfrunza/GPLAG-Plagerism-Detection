/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
class NepreklapajucaKugla{
    double x, y, z, r;
    NepreklapajucaKugla *veza, *pocetak(nullptr), *prethodni;
    
    public:
    NepreklapajucaKugla(double X, double Y, double Z, double R){
        NepreklapajucaKugla *novi({X, Y, Z, R, nullptr});
        if(!=pocetak) pocetak=novi;
        else prethodni->veza=novi;
        prethodni=novi;
    }
}
int main ()
{
	return 0;
}
