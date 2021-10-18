#include <iostream>
#include <stdexcept>

const char* imena[] = {"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};

class Datum {
    int dan, mjesec, godina;
    static void ProvjeraDatuma(int dan, int mjesec, int godina) {
        int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
        if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
            broj_dana[1]++;
        if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
            throw std::domain_error("Neispravan datum");
    }
public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    Datum (int d, Mjeseci m, int g) {
        ProvjeraDatuma(d, int(m), g);
        dan=d;
        mjesec=int(m);
        std::cout << int(m) << std::endl;
        godina=g;
    }
    
    
};

int main ()
{
    Datum(1, Datum::Mjeseci::Februar , 1990);
	return 0;
}
