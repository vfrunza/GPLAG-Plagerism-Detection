/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!



#include <iostream>



class Datum{
  Datum(int dan, int mjesec, int godina);
  void Postavi( int dan, int mjesec, int godina);
  int DajDan() const;
  int DajMjesec() const;
  int DajGodinu() const;
  void Ispisi() const;
};

class Kupac{
  Kupac(const string &ime_i_prezime, const Datum &datum_rodjenja);
  void Postavi(const string &ime_i_prezime, const Datum &datum_rodjenja);
  string DajImePrezime() const;
  Datum DajDatumRodjenja() const;
  void Ispisi() const;
};

class Stan{
    Stan(const string &adresa, int sprat, int broj_soba, bool namjesten, kvadratura);
    void Postavi(string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    string DajAdresu() const;
    int DajSprat() const;
    int DajBrojSoba() const;
    bool DajNamjesten() const;
    double DajKvadraturu() const;
    void Ispisi() const;
};


int main (){
	return 0;
}