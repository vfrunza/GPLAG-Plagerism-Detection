/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <memory>
#include <new>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <initializer_list>
#include <algorithm>

class Datum
{
  int dan, mjesec, godina;
public:
  Datum(int dan, int mjesec, int godina) {
    Postavi(dan, mjesec, godina);
  }
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
  void Ispisi() const;
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
  int dani[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if( (godina%4==0 && godina%100!=0) || godina%400==0) dani[1]++;
  if(dan<1 || mjesec <1 || mjesec>12 || godina<1 || dan>dani[mjesec-1]) throw std::domain_error("Neispravan datum");
  Datum::dan=dan;
  Datum::mjesec=mjesec;
  Datum::godina=godina;
}

void Datum::Ispisi() const
{
  std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
}

class Kupac
{
  std::string iip;
  Datum dat;

public:
  Kupac(const std::string ime_i_prezime, const Datum &datum_rodjenja): dat(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu()) {
    for(int i=0; i<ime_i_prezime.size(); i++)  if((ime_i_prezime[i]<'A' && ime_i_prezime[i]>'9') || (ime_i_prezime[i]>'Z' && ime_i_prezime[i]<'a') || (ime_i_prezime[i]<'0' && ime_i_prezime[i]!=' ')) throw std::domain_error("Neispravno ime i prezime");
    iip=ime_i_prezime;
  }
  void Postavi(const std::string ime_i_prezime, const Datum &datum_rodjenja) {
    dat.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
    iip=ime_i_prezime;
  }
  std::string DajImePrezime() const {
    return iip;
  }
  Datum DajDatumRodjenja() const {
    return dat;
  }
  void Ispisi() const {
    std::cout<<iip<<" ("<<dat.DajDan()<<"/"<<dat.DajMjesec()<<"/"<<dat.DajGodinu()<<")";
  }
};

class Stan
{
  std::string adresa;
  int sprat, broj_soba;
  bool namjesten;
  double kvadratura;

public:
  Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    Stan::adresa=adresa;
    Stan::sprat=sprat;
    Stan::broj_soba=broj_soba;
    Stan::namjesten=namjesten;
    Stan::kvadratura=kvadratura;
  }
  void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if(sprat<0 ||broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    Stan::adresa=adresa;
    Stan::sprat=sprat;
    Stan::broj_soba=broj_soba;
    Stan::namjesten=namjesten;
    Stan::kvadratura=kvadratura;
  }
  std::string DajAdresu() const {
    return adresa;
  }
  int DajSprat() const {
    return sprat;
  }
  int DajBrojSoba() const {
    return broj_soba;
  }
  bool DajNamjesten() const {
    return namjesten;
  }
  double DajKvadraturu() const {
    return kvadratura;
  }
  void Ispisi() const;
};

void Stan::Ispisi() const
{
  std::cout<<"Stan se nalazi na adresi"<<adresa<<" na "<<sprat<<". spratu i ima ";
  if(broj_soba==2 || broj_soba==3 ||broj_soba==4 || broj_soba%10==2 || broj_soba%10==3 || broj_soba%10==4) std::cout<<broj_soba<<" sobe."<<std::endl;
  else std::cout<<broj_soba<<" soba."<<std::endl;
  std::cout<<"Kvadratura stana je "<<kvadratura<<" (m^2) "<<"i stan ";
  if(namjesten) std::cout<<"je namjesten.";
  else std::cout<<"nije namjesten.";
}

class Prodaja
{
  std::string agent;
  double cijena;
  Datum datum;
  Kupac kupac;
  Stan kupljeni;
public:
  Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
  //  void Ispisi() const;
  Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string ime_kupca,
          const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
  void PromijeniKupca(const Kupac &novi_kupac) {
    kupac=novi_kupac;
  }
  void PromijeniStan(const Stan &novi_stan) {
    kupljeni=novi_stan;
  }
  void PromijeniDatumKupovine(const Datum &novi_datum) {
    datum=novi_datum;
  }
  void PromijeniCijenuProdaje(const double &nova_cijena) {
    cijena=nova_cijena;
  }
  void PomjeriDanUnaprijed() {
    int x=datum.DajDan();
    x++;
    datum.Postavi(x, datum.DajMjesec(), datum.DajGodinu());
  }
  void PomjeriDanUnazad() {
    int x=datum.DajDan();
    x--;
    datum.Postavi(x, datum.DajMjesec(), datum.DajGodinu());
  }
// void IspisiDatuma() { datum.Ispisi(); }
  std::string DajImeAgenta() const {
    return agent;
  }
  std::string DajImeKupca() const {
    return kupac.DajImePrezime();
  }
  Datum DajDatumProdaje() const {
    return datum;
  }
  double DajCijenuStana() const {
    return cijena;
  }
  friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
  friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
  void Ispisi() const;
};

void Prodaja::Ispisi() const
{
  std::cout<<std::setw(50)<<std::left<<std::setfill(' ')<<"Ime agenta: "<<agent<<std::endl;
  std::cout<<std::setw(50)<<std::left<<std::setfill(' ')<<"Ime kupca: "<<kupac.DajImePrezime();
  std::cout<<" (";
  kupac.DajDatumRodjenja().Ispisi();
  std::cout<<")"<<std::endl;
  std::cout<<std::setw(50)<<std::left<<std::setfill(' ')<<"Zakazani datum prodaje: ";
  datum.Ispisi();
  std::cout<<std::endl;
  std::cout<<std::setw(50)<<std::left<<std::setfill(' ')<<"Cijena stana: "<<cijena<<std::endl;
  std::cout<<"Informacije o stanu: "<<std::endl;
  kupljeni.Ispisi();
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
  if(p1.DajCijenuStana()>p2.DajCijenuStana()) return true;
  else return false;
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
  Datum d1=p1.DajDatumProdaje();
  Datum d2=p2.DajDatumProdaje();
  int x=d1.DajGodinu();
  int y=d2.DajGodinu();
  if(x<y) return true;
  if(x>y) return false;
  else {
    int mj1=d1.DajMjesec();
    int mj2=d2.DajMjesec();
    if(mj1<mj2) return true;
    if(mj1>mj2) return false;
    else {
      int dan1=d1.DajDan(), dan2=d2.DajDan();
      if(dan1<dan2) return true;
      if(dan1>dan2) return false;
    }
  }
  return 0;
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):
  datum(datum_prodaje), kupac(kupac_stana), kupljeni(kupljeni_stan)
{
  agent=ime_agenta_prodaje;
  cijena=cijena_stana;
}
// void Prodaja::Ispisi() const { std::cout<<agent<<" "<<cijena<<" "; datum.Ispisi(); kupac.Ispisi(); kupljeni.Ispisi(); }

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string ime_kupca,
                 const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):
  datum(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac(ime_kupca, datum_rodjenja_kupca), kupljeni(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)
{
  agent=ime_agenta_prodaje;
  cijena=cijena_stana;
  //  datum(dan_prodaje, mjesec_prodaje, godina_prodaje);
// kupac(ime_kupca, datum_rodjenja_kupca);
  //  kupljeni(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
}

class Prodaje
{
  int maxbr;
  int trenutno;
  Prodaja **pr;
 // static bool RanijiDatum(Prodaja *p1, Prodaja *p2);
public:
  explicit Prodaje(int max_broj_prodaja) {
    pr=nullptr;
    maxbr=max_broj_prodaja;
    pr=new Prodaja *[maxbr];
  }
  Prodaje(std::initializer_list<Prodaja> spisak_prodaja) {
    trenutno=spisak_prodaja.size();
    pr=new Prodaja *[spisak_prodaja.size()];
    int i(0);
    for(auto x : spisak_prodaja) {
      pr[i]=new Prodaja(x);
      i++;
    }
  }
  ~Prodaje() {
    for(int i=0; i<trenutno; i++) delete pr[i];
    delete [] pr;
  }

  Prodaje(const Prodaje &prodaje);
  Prodaje(Prodaje &&prodaje);
  Prodaje &operator =(const Prodaje &prodaje);
  Prodaje &operator =(Prodaje && prodaje);
  void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
  void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
    if(trenutno==maxbr) throw std::range_error("Dostignut maksimlani broj prodaja");
    for(int i=0; i<maxbr; i++) if(pr[i]==nullptr) pr[i]=new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
  }
  void RegistrirajProdaju(Prodaja *prodaja) {
    if(trenutno==maxbr) throw std::range_error("Dostignut maksimlani broj prodaja");
    for(int i=0; i<maxbr; i++) if(pr[i]==nullptr) pr[i]=prodaja;
  }
  int DajBrojProdaja() const {
    return trenutno;
  }
  int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    int br=0;
    for(int i=0; i<trenutno; i++)
      if(pr[i]->DajImeAgenta()==ime_agenta) br++;
    return br;
  }
  void IsprazniKolekciju();
};
void Prodaje::IsprazniKolekciju()
{
  for(int i=0; i<trenutno; i++) {
    delete pr[i];
    pr[i]=nullptr;
  }
  delete [] pr;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan)
{
  if(trenutno==maxbr) throw std::range_error("Dostignut maksimlani broj prodaja");
  for(int i=0; i<maxbr; i++) if(pr[i]==nullptr) pr[i]=new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
}




Prodaje &Prodaje::operator =(Prodaje &&prodaje)
{
  std::swap(trenutno, prodaje.trenutno);
  std::swap(maxbr, prodaje.maxbr);
  return *this;
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje)
{
  if(prodaje.trenutno>trenutno) {
    try  {
      for(int i=trenutno; i<prodaje.trenutno; i++) pr[i]=new Prodaja(*prodaje.pr[i]);
    } catch(...) {
      for(int i=trenutno; i<prodaje.trenutno; i++) {
        delete pr[i];
        pr[i]=nullptr;
      }
      throw;
    }
  } else {
    for(int i=prodaje.trenutno; i<trenutno; i++) {
      delete pr[i];
      pr[i]=nullptr;
    }
  }
  trenutno=prodaje.trenutno;
  for(int i=0; i<trenutno; i++) *pr[i]=*prodaje.pr[i];
  return *this;
}


Prodaje::Prodaje(const Prodaje &prodaje): maxbr(prodaje.maxbr), trenutno(prodaje.trenutno), pr(new Prodaja *[prodaje.maxbr])
{
  // trenutno=prodaje.trenutno; maxbr=prodaje.maxbr;
  // pr=new Prodaja*[maxbr];
  try {
    for(int i=0; i<trenutno; i++) pr[i]=new Prodaja(*prodaje.pr[i]);
  } catch(...) {
    for(int i=0; i<prodaje.trenutno; i++) delete pr[i];
    delete [] pr;
    throw;
  }
}


Prodaje::Prodaje(Prodaje &&prodaje): maxbr(prodaje.maxbr), trenutno(prodaje.trenutno), pr(prodaje.pr)
{
  // trenutno=prodaje.trenutno; maxbr=prodaje.maxbr; pr=prodaje.pr;
  prodaje.trenutno=0;
  prodaje.pr=nullptr;
}

//Prodaje &Prodaje::operator =(const Prodaja &prodaje) {
// if(this!=prodaje) {
//   trenutno=prodaje.trenutno; maxbr=prodaje.maxbr; pr=prodaje.pr; // ????
//  }
// return *this; }



int main ()
{
  Kupac Ajdin("Ajd2i Zorlak", {12,2,2000});
  Ajdin.Ispisi();
  std::cout<<std::endl;
  Ajdin.Postavi("ZOka", {2,3,3000});
  Ajdin.Ispisi();
  std::cout<<std::endl;
  Stan stancic("Hamdije C 14", 4, 4, 1, 39.22);
// stancic.Ispisi();
  std::cout<<std::endl;
  Prodaja pr("Kenan K", 30000, {2,3,1999}, Ajdin, stancic); //pr.Ispisi();
// Prodaja pr("Kenan K", 3000, 22, 10, 1999, "Kupac", {22, 3, 1977}, "Adresa stana je ovo", 4, 3, 1, 55);
// pr.Ispisi();
// pr.IspisiDatuma(); std::cout<<"      ";
// pr.PomjeriDanUnaprijed(); // pr.IspisiDatuma();
// std::cout<<pr.DajImeAgenta()<<"   "<<pr.DajImeKupca();
//pr.DajDatumProdaje().Ispisi();
  //bool a;
//	Prodaja pr2("Aaab", 200220, {2, 2, 1999}, Ajdin, stancic);
//	a=SkupljiStan(pr2, pr);
  //std::cout<<a;
  pr.Ispisi();



  return 0;
}