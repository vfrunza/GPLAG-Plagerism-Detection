/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>

class Datum{
    int dan, int mjesec, int godina;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina){
    };
    int DajDan() const {return dan;}
    int DajMjesec() const {return mjesec;}
    int DajGodinu() const {return godina;}
    void Ispisi() const{
      std::cout << dan <<"/"<< mjesec <<"/"<< godina;
    };
};



class Kupac{
  Kupac(const std::string &ime_i_prezime, const Datum &datuma_rodjenja);
  void Postavi (const std::string &ime_i_prezime, const Datum &datuma_rodjenja);
  std::string DajImePrezime() const;
  void Ispisi() const{
    
  };
  
};



class Stan{
 Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
   
 };
 void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
 std::string DajAdresu() const;
 int DajSprat() const { return sprat; }
 int DajBrojSoba() const { return broj_soba; }
 bool DajNamjesten() const { return namjesten; }
 double DajKvadraturu() const { return kvadratura; }
 void Ispisi() const;
};


class Prodaja{
  Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
  const Kupac &kupac_Stana, const Stan &kupljeni_stan)
}

int main ()
{
	return 0;
}