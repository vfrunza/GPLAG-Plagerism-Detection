/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
class Datum{
  int d,m,g;
  bool Provjeri(int dan, int mjesec, int godina){
      int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
      if(godina%4==0 && (godina % 100!=0 || godina % 400 ==0)) broj_dana[1]++;
      if(godina<1 || mjesec<1 || mjesec>12 || dan <1 || dan>broj_dana[mjesec-1]) return false;
      return true;
  
  }
  public:
    Datum(int dan, int mjesec, int godina){
      if(!(Provjeri(dan,mjesec,godina))) throw std::domain_error("Neispravan datum");
      d=dan;
      m=mjesec;
      g=godina;
  }
  void Postavi(int dan, int mjesec, int godina){
      if(!(Provjeri(dan,mjesec,godina))) throw std::domain_error("Neispravan datum");
      d=dan;
      m=mjesec;
      g=godina;
  }
  int DajDan()const  {return d;}
  int DajMjesec()const {return m; }
  int DajGodinu()const{ return g;}
  void Ispisi()const{
      std::cout<<d<<"/"<<m<<"/"<<g<<std::endl;
  }
};
class Kupac{
  std::string ime; 
  Datum dat;
  bool Provjeri(std::string a){
    for(int i=0;i<a.length();i++){
     if(!(a[i]>='A' && a[i]<='Z') || (a[i]<='a' && a[i]<='z') || a[i]==' ' || a[i]=='-'  || a[i]==44 || (a[i]>='0' && a[i]<='9')) return false;
    }
    return true;
  }
  public:
  
  Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): ime(ime_i_prezime),dat(datum_rodjenja){
      if(!(Provjeri(ime_i_prezime))) throw std::domain_error("Neispravno ime i prezime");
  }
  void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
      if(!(Provjeri(ime_i_prezime))) throw std::domain_error("Neispravno ime i prezime")
      ;
      ime=ime_i_prezime;
      dat=datum_rodjenja;
  }
  std::string DajImePrezime()const {
      return ime;
  }
  Datum DajDatumRodjenja()const{
      return dat;
  }
  void Ispisi()const{
      std::cout<<ime<<"(";
      DajDatumRodjenja().Ispisi();
      std::cout<<")"<<std::endl;
  }
};

class Stan{
  std::string adresa1;
  int sprat1, broj_soba1;
  bool namjesten1;
  double kvadratura1;
  
  public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if( sprat<0 || broj_soba<0 || namjesten<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    adresa1=adresa;
    sprat1=sprat;
    broj_soba1=broj_soba;
    namjesten1=namjesten;
    kvadratura1=kvadratura;
  }
  void Postavi (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if( sprat<0 || broj_soba<0 || namjesten<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    adresa1=adresa;
    sprat1=sprat;
    broj_soba1=broj_soba;
    namjesten1=namjesten;
    kvadratura1=kvadratura;
  }
  std::string DajAdresu()const { return adresa1;}
  int DajSprat()const { return sprat1;}
  int DajBrojSoba()const {return broj_soba1;}
  bool DajNamjesten()const {return namjesten1;}
  double DajKvadratura()const {return kvadratura1;}
  void Ispisi()const{
    std::cout<<"Stan se nalazi na adresi "<<adresa1<<" na "<<sprat1<<". spratu i ima "<<broj_soba1;
    if(broj_soba1==1) std::cout<<" sobu."<<std::endl;
    if(broj_soba1>=2 && broj_soba1<=4) std::cout<<" sobe."<<std::endl;
    if(broj_soba1>=5) std::cout<<" soba."<<std::endl;
    std::cout<<"Kvadratura stana je "<<kvadratura1<<" (m^2) i stan ";
    if(namjesten1) std::cout<<"je namjesten.";
    else std::cout<<"nije namjesten.";
}
};
class Prodaja{
std::string ime_agenta_prodaje1;
double cijena_stana1;
Datum datum_prodaje1;
Kupac kupac_stana1;
Stan kupljeni_stan1;


Datum Povecaj(Datum a){
   int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
  if(a.DajGodinu()%4==0 && (a.DajGodinu() % 100!=0 || a.DajGodinu() % 400 ==0)) broj_dana[1]++;
   a.Postavi(a.DajDan()+1,a.DajMjesec(),a.DajGodinu());
   if(a.DajDan()>broj_dana[a.DajMjesec()-1]){
     a.Postavi(1,a.DajMjesec()+1,a.DajGodinu());
    if(a.DajMjesec()==13){
      a.Postavi(a.DajDan(),1,a.DajGodinu()+1);
    }
   }
   return a;
}
Datum Vrati(Datum a){
  int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
  if(a.DajGodinu()%4==0 && (a.DajGodinu() % 100!=0 || a.DajGodinu() % 400 ==0)) broj_dana[1]++;
  a.Postavi(a.DajDan()-1,a.DajMjesec(),a.DajGodinu());
  if(a.DajDan()==0){
    a.Postavi(broj_dana[a.DajMjesec()-1],a.DajMjesec()-1,a.DajGodinu());
    if(a.DajMjesec()==0){
   a.Postavi(a.DajDan(),12,a.DajGodinu()-1);
    }
  }
  return a;
}

public:
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):
ime_agenta_prodaje1(ime_agenta_prodaje),cijena_stana1(cijena_stana),datum_prodaje1(datum_prodaje),kupac_stana1(kupac_stana),kupljeni_stan1(kupljeni_stan)
{ }
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):
        ime_agenta_prodaje1(ime_agenta_prodaje),cijena_stana1(cijena_stana),datum_prodaje1(dan_prodaje,mjesec_prodaje,godina_prodaje),
        kupac_stana1(ime_kupca,datum_rodjenja_kupca),kupljeni_stan1(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)
{} 
void PromijeniKupca(const Kupac &novi_kupac){
  kupac_stana1=novi_kupac;
}
void PromijeniStan(const Stan &novi_stan){
  kupljeni_stan1=novi_stan;
}
void PromijeniDatumKupovine(const Datum &novi_datum){
  datum_prodaje1=novi_datum;
}
void PromijeniCijenuProdaje(const double &nova_cijena){
  cijena_stana1=nova_cijena;
}
std::string DajImeAgenta() const{ return ime_agenta_prodaje1; }
std::string DajImeKupca() const {return kupac_stana1.DajImePrezime(); }
Datum DajDatumProdaje() const {return datum_prodaje1;}
double DajCijenuStana() const {return cijena_stana1;}

void PomjeriDanUnaprijed(){
datum_prodaje1=Povecaj(DajDatumProdaje());
}
void PomjeriDanUnazad(){
datum_prodaje1 = Vrati(DajDatumProdaje());
}
friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2); 

void Ispisi()const{
  std::cout<<"Ime agenta:          "<<ime_agenta_prodaje1<<std::endl<<"Ime kupca: ";
  kupac_stana1.Ispisi();
  std::cout<<std::endl;
  std::cout<<"Zakazani datum prodaje: ";
  datum_prodaje1.Ispisi();
  std::cout<<std::endl;
  std::cout<<"Cijena stana: "<<cijena_stana1<<std::endl<<"Informacije o stanu: ";
  kupac_stana1.Ispisi();
}
};

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
  if(p1.datum_prodaje1.DajGodinu()<p2.datum_prodaje1.DajGodinu()) return true;
  if(p1.datum_prodaje1.DajGodinu()==p2.datum_prodaje1.DajGodinu()){
    if(p1.datum_prodaje1.DajMjesec()<p2.datum_prodaje1.DajMjesec()) return true;
    if(p1.datum_prodaje1.DajMjesec()==p2.datum_prodaje1.DajMjesec()){
     if(p1.datum_prodaje1.DajDan()<p2.datum_prodaje1.DajDan()) return true;
    }
  }
  return false;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
  if(p1.cijena_stana1<p2.cijena_stana1) return true;
  return false;
}
class Prodaje{
  
public:
explicit Prodaje(int max_broj_prodaja);
Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
~Prodaje();
Prodaje(const Prodaje &prodaje);
Prodaje(Prodaje &&prodaje);
Prodaje &operator=(const Prodaje &prodaje);
Prodaje &operator=(Prodaje &&prodaje);
void RegistrirajProdaju( const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac kupac_stana,
const Stan &kupljeni_stan);
void RegistrirajProdaju( const std::string &ime_agenta_prodaje,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
std::string &ime_kupca, const Datum datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba
,bool namjesten_stan, double broj_kvadrata);
void RegistrirajProdaju(Prodaja *prodaja);
int DajBrojProdaja() const;
int DajBrojProdajaNaDatum(const Datum &datum) const;
int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
Prodaja &DajNajranijuProdaju();
Prodaja DajNajranijuProdaju() const;
Prodaja &DajNajskupljuProdaju();
Prodaja DajNajskupljuProdaju() const;
void IsprazniKolekciju();
void ObrisiNajranijuProdaju();
void ObrisiProdajeAgenta(const std::string &ime_agenta);
void ObrisiProdajeNaDatum(const Datum &datum);
void IspisiProdajeNaDatum(const Datum &datum) const;
void IspisiSveProdaje() const;
};
int main ()
{
	return 0;
}