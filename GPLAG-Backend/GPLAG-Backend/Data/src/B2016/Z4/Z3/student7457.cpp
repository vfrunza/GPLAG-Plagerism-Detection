/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <iomanip>

class Datum {
    int dan, mjesec, godina;
    static void ProvjeriDatum(int dan, int mjesec, int godina);
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const {
        return dan;
    }
    int DajMjesec() const {
        return mjesec;
    }
    int DajGodinu() const {
        return godina;
    }
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};
void Datum::ProvjeriDatum(int dan, int mjesec, int godina) {
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1]) throw std::logic_error("Neispravan datum");
}
Datum::Datum(int dan, int mjesec, int godina) {
    Postavi(dan, mjesec, godina); //baca izuzetak
}
void Datum::Postavi(int dan, int mjesec, int godina) {
    ProvjeriDatum(dan, mjesec, godina); //baca izuzetak
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
public:
    Kupac(const std::string & ime_i_prezime, const Datum & datum_rodjenja);
    void Postavi(const std::string & ime_i_prezime, const Datum & datum_rodjenja);
    std::string DajImePrezime() const;
    Datum DajDatumRodjenja() const;
    void Ispisi() const;
};
void Kupac::Postavi(const std::string & ime_i_prezime, const Datum & datum_rodjenja) {
    Kupac::datum_rodjenja.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
    
}
int main () {
    return 0;
}