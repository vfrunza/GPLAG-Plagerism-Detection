#include <iostream>
#include <stdexcept>
#include <string>
#include <initializer_list>
#include <algorithm>
class Datum{
  int dan,mjesec,godina;
  public:
  Datum(int dan,int mjesec,int godina){
    Postavi(dan,mjesec,godina);
  }
  void Postavi(int dan,int mjesec,int godina){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
      broj_dana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec-1])
      throw std::domain_error("Neispravan datum");
      Datum::dan=dan;Datum::mjesec=mjesec;Datum::godina=godina;
  }
 int DajDan() const{return dan;}
 int DajMjesec() const{return mjesec;}
 int DajGodinu() const{return godina;}
 void Ispisi() const{std::cout << dan << "/" << mjesec << "/" << godina;}
};
class Kupac{
  std::string ime_i_prezime;
  Datum datum_rodjenja;
  public:
  Kupac(const std::string &ime_i_prezime,const Datum &datum_rodjenja):datum_rodjenja(datum_rodjenja){
    for(int i(0);i < ime_i_prezime.length();i++){
      if(!(ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z' || ime_i_prezime[i] >= 'A' && ime_i_prezime[i] <= 'Z'
      || ime_i_prezime[i] >= '0' && ime_i_prezime[i] <= '9' || ime_i_prezime[i] == ' ' ||
      ime_i_prezime[i] == '-' || ime_i_prezime[i] == '"'))throw std::domain_error("Neispravno prezime");
    }
    Kupac::ime_i_prezime=ime_i_prezime;
  }
  void Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja){
    
  }
  std::string DajIme_IPrezime() const{return ime_i_prezime;}
  Datum DajDatumRodjenja() const{return datum_rodjenja;}
  void Ispisi() const{std::cout << ime_i_prezime << " (";datum_rodjenja.Ispisi();std::cout << ")";}
  };
class Stan{
  std::string adresa;
  int sprat,broj_soba;
  bool namjesten;
  double kvadratura;
  public:
  Stan(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura){Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);};
  void Postavi(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura){
    if(kvadratura < 0 || broj_soba < 0 || sprat < 0)throw std::domain_error("Neispravan unos podataka");
    Stan::adresa=adresa;Stan::sprat=sprat;Stan::broj_soba=broj_soba;Stan::namjesten=namjesten;Stan::kvadratura=kvadratura;
  }
  std::string DajAdresu() const{return adresa;}
  int DajSprat() const{return sprat;}
  int DajBrojSoba() const{return broj_soba;}
  bool DajNamjesten() const{return namjesten;}
  double DajKvadraturu() const{return kvadratura;}
  void Ispisi() const;
};
void Stan::Ispisi() const{
  std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima ";
      if(broj_soba % 10 == 1 && (broj_soba % 100)/10 != 1)std::cout << broj_soba << " sobu.";
      else if((broj_soba % 10 == 2 || broj_soba % 10 == 3 || broj_soba % 10 == 4) && (broj_soba % 100)/10 != 1)std::cout << broj_soba << " sobe.";
      else std::cout << broj_soba << " soba.";
      std::cout << "\nKvadratura stana je " << kvadratura << " (m^2) i stan ";
      if(!namjesten) std::cout << "ni";
      std::cout << "je namjesten.";
}
class Prodaja{
  std::string ime_agenta_prodaje;
  double cijena_stana;
  Datum datum_prodaje;
  Kupac kupac_stana;
  Stan kupljeni_stan;
  public:
  Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,
  const Stan &kupljeni_stan):datum_prodaje(datum_prodaje),kupac_stana(kupac_stana),kupljeni_stan(kupljeni_stan){
    Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;Prodaja::cijena_stana=cijena_stana;}
    
  Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,
  int godina_prodaje,const std::string &ime_kupca,const Datum &datum_rodjenja_kupca,
  const std::string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata):
  datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),kupac_stana(ime_kupca,datum_rodjenja_kupca),
  kupljeni_stan(adresa_stana,broj_soba,sprat_stana,namjesten_stan,broj_kvadrata){
    Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;Prodaja::cijena_stana=cijena_stana;
  }  
};
class Prodaje{
  Prodaja **spisak_prodaja;
  int max_broj_prodaja,broj_prodaja;
  public:
  explicit Prodaje(int max_broj_prodaja):spisak_prodaja(new Prodaja*[max_broj_prodaja]{}),
  broj_prodaja(0),max_broj_prodaja(max_broj_prodaja){}
  Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
  ~Prodaje();
  Prodaje(const Prodaje &prodaje);
  Prodaje(Prodaje &&prodaje);
  Prodaje &operator =(const Prodaje &prodaje);
  Prodaje &operator =(Prodaje &&prodaje);
  void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,
  const Kupac &kupac_stana,const Stan &kupljeni_stan);
  void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,
  int mjesec_prodaje,int godina_prodaje,std::string ime_kupca,const Datum &datum_rodjenja_kupca,
  const std::string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata);
  void RegistrirajProdaju(Prodaja *prodaja);
  int DajBrojProdaja() const{return broj_prodaja;}
  int DajBrojProdajaNaDatum(const Datum &datum);
};
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja):max_broj_prodaja(spisak_prodaja.size()),
broj_prodaja(spisak_prodaja.size()),spisak_prodaja(new Prodaja*[spisak_prodaja.size()]){
  auto it(spisak_prodaja.begin());
  try{
  for(int i(0);i < spisak_prodaja.size();i++)Prodaje::spisak_prodaja[i]=new Prodaja(*it++);
  }catch(...){
    for(int i(0);i < spisak_prodaja.size();i++)delete Prodaje::spisak_prodaja[i];
    delete[] Prodaje::spisak_prodaja;throw;
  }
}
Prodaje::~Prodaje(){
  for(int i(0);i < broj_prodaja;i++)delete spisak_prodaja[i];
  delete[] spisak_prodaja;
}
Prodaje::Prodaje(const Prodaje &prodaje):spisak_prodaja(new Prodaja*[prodaje.broj_prodaja]),
max_broj_prodaja(prodaje.max_broj_prodaja),broj_prodaja(prodaje.broj_prodaja){
  try{
    for(int i(0);i < broj_prodaja;i++)spisak_prodaja[i]= new Prodaja(*prodaje.spisak_prodaja[i]);   
  }catch(...){
    for(int i(0);i < broj_prodaja;i++)delete spisak_prodaja[i];
    delete spisak_prodaja;throw;
  }
}
Prodaje::Prodaje(Prodaje &&prodaje):spisak_prodaja(prodaje.spisak_prodaja){
  max_broj_prodaja = prodaje.max_broj_prodaja;
  broj_prodaja = prodaje.broj_prodaja;
  prodaje.spisak_prodaja=nullptr;
}
Prodaje &Prodaje::operator =(const Prodaje &prodaje){
  if(this != &prodaje){
    Prodaja **tmp(new Prodaja*[prodaje.broj_prodaja]{});
    try{
      for(int i(0);i < prodaje.broj_prodaja;i++)tmp[i] = new Prodaja(*prodaje.spisak_prodaja[i]);
      for(int i(0);i < broj_prodaja;i++)delete spisak_prodaja[i];
      delete[] spisak_prodaja;
      broj_prodaja=prodaje.broj_prodaja;
      max_broj_prodaja=prodaje.max_broj_prodaja;
      spisak_prodaja=tmp;
    }catch(...){
      for(int i(0);i < prodaje.broj_prodaja;i++)delete tmp[i];
      delete[] tmp;throw;
    }
  }
  return *this;
}
Prodaje &Prodaje::operator =(Prodaje &&prodaje){
  std::swap(spisak_prodaja,prodaje.spisak_prodaja);
  broj_prodaja=prodaje.broj_prodaja;
  max_broj_prodaja=prodaje.max_broj_prodaja;
  return *this;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,
  const Kupac &kupac_stana,const Stan &kupljeni_stan){
    if(broj_prodaja == max_broj_prodaja)throw std::range_error("Dostignut maksimalni broj_prodaja");
    spisak_prodaja[broj_prodaja++]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
  }
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,
  int mjesec_prodaje,int godina_prodaje,std::string ime_kupca,const Datum &datum_rodjenja_kupca,
  const std::string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata){
    if(broj_prodaja==max_broj_prodaja)throw std::range_error("Dostignut maksimalni broj_prodaja");
    Datum datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje);
    Kupac kupac_stana(ime_kupca,datum_rodjenja_kupca);
    Stan kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    RegistrirajProdaju(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
  }
void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
  if(broj_prodaja==max_broj_prodaja)throw std::range_error("Dostignut maksimalni broj_prodaja");
  spisak_prodaja[broj_prodaja]=prodaja;
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum){
  return std::count_if(spisak_prodaja,spisak_prodaja+broj_prodaja,[](Prodaja *p1){
    int d1,m1,g1;
    int d2(datum.DajDan()),m2(datum.DajMjesec()),g2(datum.DajGodinu());
  })
}
int main ()
{
  
  
	return 0;
}