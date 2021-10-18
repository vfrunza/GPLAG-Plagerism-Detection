/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <iomanip>
class Datum{
  int dan,mjesec,godina;
  public:
  Datum(int d,int m,int g){
      int broj_dana[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      if(g % 4 == 0 &&( g % 100 != 0 || g % 400 == 0)) broj_dana[1]++;
     if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1])throw std::domain_error("Neispravan datum");
      dan = d; mjesec = m; godina = g;
  }
  void Postavi(int d,int m,int g){
      int broj_dana[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      if(g % 4 == 0 &&( g % 100 != 0 || g % 400 == 0)) broj_dana[1]++;
      if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1])throw std::domain_error("Neispravan datum");
      dan = d; mjesec = m; godina = g;
  }
  int DajDan()const{return dan;}
  int DajMjesec()const{return mjesec;}
  int DajGodinu()const{return godina;}
  void Ispisi()const{
      std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
  }
};
class Kupac{
  std::string ime_i_prezime;
  Datum danas;
  public:
  Kupac(const std::string& ime,const Datum& dan_rodjenja):danas(dan_rodjenja){
      int br=0;
      for(int i(0);i<ime.length();i++){
          if((ime[i]>='0' && ime[i]<='9') || (ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || ime[i]==' ' || ime[i]=='`' || ime[i]=='-')br++;
      }
      if(br!=ime.length())throw std::domain_error("Neispravno ime i prezime");
      else ime_i_prezime=ime;
  }
  void Postavi(const std::string& ime,const Datum& dan_rodjenja){
      danas.Postavi(dan_rodjenja.DajDan(),dan_rodjenja.DajMjesec(),dan_rodjenja.DajGodinu());
      int br=0;
      for(int i(0);i<ime.length();i++){
          if((ime[i]>='0' && ime[i]<='9') || (ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || ime[i]==' ' || ime[i]=='`' || ime[i]=='-')br++;
      }
      if(br!=ime.length())throw std::domain_error("Neispravno ime i prezime");
      else ime_i_prezime=ime;
  }
  std::string DajImePrezime()const{return ime_i_prezime;}
  Datum DajDatumRodjenja()const{return danas;}
  void Ispisi()const{
      std::cout<<ime_i_prezime<<" (";
      danas.Ispisi();
      std::cout<<")";
  }
};
class Stan{
    std::string adresa;
    int sprat,broj_soba;
    bool namjesten;
    double kvadratura;
    public:
    Stan(const std::string& adres,int spr,int broj_sob, bool namjeste,double kvadratur){
      if(spr<0 || broj_sob<0 || kvadratur<0)throw std::domain_error("Neispravan unos podataka");
      sprat=spr;
      adresa=adres;
      sprat=spr;
      broj_soba=broj_sob;
      namjesten=namjeste;
      kvadratura=kvadratur;
    }
    void Postavi(const std::string& adres,int spr,int broj_sob, bool namjeste,double kvadratur){
      if(spr<0 || broj_sob<0 || kvadratur<0)throw std::domain_error("Neispravan unos podataka");
      sprat=spr;
      adresa=adres;
      sprat=spr;
      broj_soba=broj_sob;
      namjesten=namjeste;
      kvadratura=kvadratur;
    }
    std::string DajAdresu()const{return adresa;}
    int DajSprat()const{return sprat;}
    int DajBrojSoba()const{return broj_soba;}
    bool DajNamjesten()const{return namjesten;}
    double DajKvadraturu()const{return kvadratura;}
    void Ispisi()const{
      std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba;
      int a=broj_soba;
      if(a%10==1)std::cout<<" sobu.";
      else if(a%10==2 || a%10==3 || a%10==4)std::cout<<" sobe.";
      else std::cout<<" soba.";
      std::cout<<" Kvadratura stana je "<<kvadratura<<" (m^2) i stan";
      if(namjesten)std::cout<<" je namjesten.";
      else std::cout<<" nije namjesten.";
      
    }
};
class Prodaja{
  std::string ime_agenta_prodaje;
  double cijena_stana;
  Datum datum_prodaje;
  Kupac kupac_stana;
  Stan kupljeni_stan;
  public:
  Prodaja(const std::string& ime_agenta,double cijena,
  const Datum& dan_prodaje,const Kupac& kupac,const Stan& kupljeni):datum_prodaje(dan_prodaje),kupac_stana(kupac),kupljeni_stan(kupljeni){
            cijena_stana=cijena;
            ime_agenta_prodaje=ime_agenta;
  } 
  Prodaja( const std::string& ime_agent_prodaje,double cijena,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
 std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
 const std::string &adresa_stana, int sprat_stana, int broj_soba,
 bool namjesten_stan, double broj_kvadrata):datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),kupac_stana(ime_kupca,datum_rodjenja_kupca),
 kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){
     ime_agenta_prodaje=ime_agent_prodaje;
     cijena_stana=cijena;
 }
 void PromijeniKupca(const Kupac &novi_kupac){
     kupac_stana.Postavi(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja());
 }
 void PromijeniStan(const Stan& novi_stan){
     kupljeni_stan.Postavi(novi_stan.DajAdresu(),novi_stan.DajSprat(),novi_stan.DajBrojSoba(),novi_stan.DajNamjesten(),novi_stan.DajKvadraturu());
 }
 void PromijeniDatumKupovine(const Datum& novi_datum){
     datum_prodaje.Postavi(novi_datum.DajDan(),novi_datum.DajMjesec(),novi_datum.DajGodinu());
 }
 void PromijeniCijenuProdaje(const double& nova_cijena){
     cijena_stana=nova_cijena;
 }
 std::string DajImeAgenta()const{return ime_agenta_prodaje;}
 std::string DajImeKupca()const{return kupac_stana.DajImePrezime();}
 Datum DajDatumProdaje()const{return datum_prodaje;}
 double DajCijenuStana()const{return cijena_stana;}
 friend bool ProdatPrije(const Prodaja& p1,const Prodaja &p2){
     if(p1.datum_prodaje.DajGodinu()>p2.datum_prodaje.DajGodinu())return false;
     else if(p1.datum_prodaje.DajGodinu()<p2.datum_prodaje.DajGodinu())return true;
     else if(p1.datum_prodaje.DajMjesec()<p2.datum_prodaje.DajMjesec())return true;
     else if(p1.datum_prodaje.DajMjesec()>p2.datum_prodaje.DajMjesec())return false;
     else if(p1.datum_prodaje.DajDan()>p2.datum_prodaje.DajDan())return false;
     else return true;
 }
 friend bool SkupljiStan(const Prodaja& p1,const Prodaja &p2){
     if(p1.cijena_stana>p2.cijena_stana)return true;
     return false;
 }
 void Ispisi()const{
     std::cout<<"Ime agenta:                     "<<DajImeAgenta();
     std::cout<<"\nIme kupca:                      "<<DajImeKupca()<<" ("<<kupac_stana.DajDatumRodjenja().DajDan()<<"/"<<kupac_stana.DajDatumRodjenja().DajMjesec()<<"/"<<kupac_stana.DajDatumRodjenja().DajGodinu()<<")";
     std::cout<<"\nZakazani datum prodaje:         "<<DajDatumProdaje().DajDan()<<"/"<<DajDatumProdaje().DajMjesec()<<"/"<<DajDatumProdaje().DajGodinu();
     std::cout<<"\nCijena stana:                   "<<cijena_stana;
     std::cout<<"\nInformacije o stanu:            \n";
      std::cout<<"Stan se nalazi na adresi "<<kupljeni_stan.DajAdresu()<<" na "<<kupljeni_stan.DajSprat()<<". spratu i ima "<<kupljeni_stan.DajBrojSoba();
      int a=kupljeni_stan.DajBrojSoba();
      if(a%10==1)std::cout<<" sobu.";
      else if(a%10==2 || a%10==3 || a%10==4)std::cout<<" sobe.";
      else std::cout<<" soba.";
      std::cout<<" Kvadratura stana je "<<kupljeni_stan.DajKvadraturu()<<" (m^2) i stan";
      if(kupljeni_stan.DajNamjesten())std::cout<<" je namjesten.\n";
      else std::cout<<" nije namjesten.\n";
 }
};
class Prodaje{
    Prodaja* niz[];
    public:
    explicit Prodaje(int max_broj_prodaja){
        Prodaja*niz[ma]
    }
    
};
int main (){
    return 0;
}
