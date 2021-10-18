/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>

class Datum {
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina) {
       *this=Datum(dan,mjesec,godina);
    }
    
    int DajDan() const { return dan;}
    int DajMJesec() const { return mjesec; }
    int DajGodinu() const {return godina;}
    void Ispisi() const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};
Datum::Datum(int dan, int mjesec, int godina) {
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && godina%100!=0 || godina%4==0) broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
    throw std::domain_error("Neispravan datum!");
    dan=dan; mjesec=mjesec; godina=godina;
} 

class Kupac {
  std::string ime_i_prezime;
  Datum datum_rodjenja;
  public:
  Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja2) : datum_rodjenja(datum_rodjenja2) {
        
      for(int i=0; i<ime_i_prezime.size(); i++) {
          if(ime_i_prezime[i]<'a' || ime_i_prezime[i]>'A' || ime_i_prezime[i]<0  || ime_i_prezime[i]>9 || ime_i_prezime[i]!='-' || ime_i_prezime[i]!=' '  )
              throw std::domain_error("Neispravno ime i prezime");
          
      }
      Postavi(ime_i_prezime,datum_rodjenja);
  }
  void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja2) {
      datum_rodjenja=datum_rodjenja2;
      *this=Kupac(ime_i_prezime, datum_rodjenja);
  }
  std::string DajImePrezime() const { return ime_i_prezime;}
  Datum DajDatumRodjenja() const { return datum_rodjenja; }
  void Ispisi() const {
      std::cout<<ime_i_prezime;
      std::cout<<" (";
      datum_rodjenja.Ispisi();
      std::cout<<")";
  }
  
};

 
    
 class Stan {
     std::string adresa;
     int sprat, broj_soba;
     bool namjesten;
     double kvadratura;
     
     public:
     Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
         Postavi(adresa, sprat, broj_soba, namjesten, kvadratura); 
     }
     void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
         *this=Stan(adresa, sprat, broj_soba, namjesten, kvadratura);
     }
     std::string DajAdresu() const {return adresa; }
     int DajSprat() const {return sprat;}
     int DajBrojSoba() const {return broj_soba; }
     bool DajNamjesten() const {return namjesten; }
     double DajKvadraturu() const {return kvadratura;}
     void Ispisi() const {
         std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima"<<broj_soba;
         if(broj_soba==1 || broj_soba%10==1)
         std::cout<<"sobu."<<std::endl;
         else if(broj_soba>1 && broj_soba<5 || broj_soba%10>1 && broj_soba%10<5)
         std::cout<<"sobe."<<std::endl;
         else
         std::cout<<"soba."<<std::endl;
         std::cout<<"Kvadratura stana je "<<kvadratura<<" (m^2)";
         if(namjesten)
         std::cout<<" je namjesten.";
         else
         std::cout<<" nije namjesten.";
     }
 };
 class Prodaja {
     std::string ime_agenta_prodaje, ime_kupca;
     double cijena_stana;
     Datum datum_prodaje, datum_rodjenja_kupca;
     Kupac kupac_stana;
     Stan kupljeni_stan;
    int dan_prodaje;
     
     public:
     Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
         
     Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
        
     void PromijeniKupca(const Kupac &novi_kupac) {
         kupac_stana=novi_kupac;
     }
     void PromijeniStan(const Stan &novi_stan) {
         kupljeni_stan=novi_stan;
     }
     void PromijeniDatumKupovine(const Datum &novi_datum) {
         datum_prodaje=novi_datum;
     }
     void PromijeniCijenuProdaje(const double &nova_cijena) {
         cijena_stana=nova_cijena;
     }
  
     std::string DajImeAgenta() const { return ime_agenta_prodaje; }
     std::string DajImeKupca() const { return ime_kupca; }
     Datum DajDatumProdaje() const { return datum_prodaje;}
     
     double DajCijenuStana() const { return cijena_stana;}
     friend bool ProdatiPrije(const Prodaja &p1, const Prodaja &p2) {
         return p1.dan_prodaje<p2.dan_prodaje;
     }
     friend bool SkupljiStan(const Prodaja &p1, Prodaja p2) {
         return p1.cijena_stana>p2.cijena_stana;
     }
     void Ispisi() const {
         std::cout<<"Ime agenta: "<<std::right<<ime_agenta_prodaje<<std::endl;
         std::cout<<"Ime kupca: "<<std::right<<ime_kupca<<" ("; datum_rodjenja_kupca.Ispisi(); 
         std::cout<<")"<<std::endl;
         std::cout<<"Zakazani datum prodaje: "<<std::right; datum_prodaje.Ispisi();
         std::cout<<std::endl;
         std::cout<<"Cijena stana: "<<std::right<<cijena_stana<<std::endl;
         std::cout<<"Informacije o stanu: "<<std::endl;
         kupljeni_stan.Ispisi();
     }
     
 };
int main ()
{
	return 0;
}