/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
using namespace std;
class Datum {
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const { cout << dan << "/" << mjesec << "/" << godina; }
};

///////////////////////KLASA DATUM///////////////////////////////////
Datum::Datum(int dan, int mjesec, int godina) {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw domain_error("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw domain_error("Neispravan datum");
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
class Kupac {
    string imeprezime;
    Datum datum_rodjenja;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return imeprezime; }
    Datum DajDatumRodjenja() const { return datum_rodjenja; }
    void Ispisi() const { 
};  
int main ()
{
	return 0;
}