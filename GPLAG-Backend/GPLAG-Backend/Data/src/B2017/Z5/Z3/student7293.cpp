/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>

class Datum {
    int dan, mjesec, godina;
    public:
    enum Mjeseci {Januar=1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar }
    enum Dani { Ponedjeljak=1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja }
    Datum (int d, Mjeseci m, int g);
    Datum (int dan, Mjeseci mj, int g);
    int DajDan() const { return dan; }
    Mjeseci DajMjesec() {
        return Mjeseci(mjesec);
    }
    int DajGodinu() const { return godina; }
    char* DajImeMjeseca() const;
    Dani DajImeDanaUSedmici() { return Dani(dan); }
};

Datum::Datum (int dan, int mjesec, int godina) {
    int broj_dana [12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1] || godina<1800) throw std::domain_error ("Neispravan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

Datum::Datum (int dan, Mjeseci m, int godina) {
    int mjesec = std::static_cast<int> (m);
    int broj_dana [12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1] || godina<1800) throw std::domain_error ("Neispravan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

int main ()
{
	return 0;
}
