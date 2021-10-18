/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>

class Datum {
    int dan, mjesec, godina;
    void TestDatuma (int d, int m, int g) {
        int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(g % 4 == 0 && (g % 100 != 0 || g % 400 == 0)) broj_dana[1]++;
        if(g < 1800 || d < 1 || m < 1 || m > 12 || d > broj_dana[m-1])
            throw std::domain_error("Nelegalan datum");
    }
public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    Datum(int dan, Mjeseci mjesec, int godina) {
        TestDatuma(dan, mjesec, godina);
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }
    Datum(int dan, int mjesec, int godina) {
        TestDatuma(dan, mjesec, godina);
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }
    void Postavi (int dan, Mjeseci mjesec, int godina) {
        TestDatuma(dan, mjesec, godina);
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }
    void Postavi (int dan, int mjesec, int godina) {
        TestDatuma(dan, mjesec, godina);
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }
    int DajDan() const {
        return dan;
    }
    Mjeseci DajMjesec() const {
        return Mjeseci(mjesec);
    }
    int DajGodinu() const {
        return godina;
    }
    const char *DajImeMjeseca() const {
        const char *imena_mjeseci[]{"Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"};
        return imena_mjeseci[mjesec-1];
    }
    Dani DanUSedmici() const {
       
    }
    const char *DajImeDanaUSedmici() const {
        const char *imena_dana[]{"Ponedeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};
        
        
        return imena_dana[dan-1];
    }
    friend Datum &operator ++(Datum &dat){
      
    }
    friend Datum operator ++(Datum &dat, int){}
    
};

int main ()
{
	return 0;
}
