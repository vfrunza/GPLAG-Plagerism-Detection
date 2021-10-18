/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>

bool provjeri_ime(std::string ime){
    for(int i=0; i<ime.size(); i++){
      if( (ime[i] < '0') || (ime[i] > '9' && ime[i] < 'A') || (ime[i] > 'Z' && ime[i] < 'a') || (ime[i] > 'z') ){
        if(ime[i] != ' ' && ime[i] != '-' && ime[i] != 39)
          return false;
      }
    }
    return true;
    
}
bool provjeri_datum(int dan, int mjesec, int godina){
  int broj_dana[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec-1])
      return false;
    return true;
}

class Datum{
  int dan;
  int mjesec;
  int godina;
  public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return Datum::dan; }
    int DajMjesec() const { return Datum::mjesec; }
    int DajGodinu() const { return Datum::godina; }
    void Ispisi() const { std::cout << Datum::dan << "/" << Datum::mjesec << "/" << Datum::godina; }

};
Datum::Datum(int dan, int mjesec, int godina) {
  if(provjeri_datum(dan, mjesec, godina) == false) throw std::domain_error("Neispravan datum"); 
  Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina; 
}

void Datum::Postavi(int dan, int mjesec, int godina){
    if(provjeri_datum(dan, mjesec, godina) == false) throw std::domain_error("“Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}

class Kupac{
  std::string ime;
  Datum datum;
  
  public:
 
  Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
  void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
  std::string DajImePrezime() const { return Kupac::ime; }
  Datum DajDatumRodjenja() const { return Kupac::datum; }
  void Ispisi() const { std::cout << Kupac::ime << " ("; Kupac::datum.Ispisi(); std::cout << ")"; }

};



Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): datum (datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu())
{
  if(provjeri_ime(ime_i_prezime) == false) throw std::domain_error("Neispravno ime i prezime");
  Kupac::ime = ime_i_prezime;
}

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
  Kupac::ime = ime_i_prezime;
  Kupac::datum.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
}

class Stan{
  std::string adresa;
  int sprat; 
  int br_soba;
  bool namjesten; 
  double kvadratura;
  public:
  Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
  void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
  std::string DajAdresu() const { return Stan::adresa; }
  int DajSprat() const { return Stan::sprat; }
  int DajBrojSoba() const { return Stan::br_soba; }
  bool DajNamjesten() const { return Stan::namjesten; }
  double DajKvadraturu() const { return Stan::kvadratura; }
  void Ispisi() const;
};

Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
  if(sprat < 0 || broj_soba < 0 || kvadratura < 0 ) throw std::domain_error("Neispravan unos podataka");
  Stan::adresa = adresa;
  Stan::sprat = sprat;
  Stan::br_soba = broj_soba;
  Stan::namjesten = namjesten;
  Stan::kvadratura = kvadratura;
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
  if(sprat < 0 || broj_soba < 0 || kvadratura < 0 ) throw std::domain_error("Neispravan unos podataka");
  Stan::adresa = adresa;
  Stan::sprat = sprat;
  Stan::br_soba = broj_soba;
  Stan::namjesten = namjesten;
  Stan::kvadratura = kvadratura;
}

void Stan::Ispisi() const {
  if(Stan::namjesten == true){
  if(Stan::br_soba == 1)
  std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobu. Kvadratura stana je " << DajKvadraturu() <<  " (m^2) i stan je namjesten.";
  if(Stan::br_soba == 2 || Stan::br_soba == 3 || Stan::br_soba == 4)
  std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobe. Kvadratura stana je " << DajKvadraturu() <<  " (m^2) i stan je namjesten.";
  else 
  std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " soba. Kvadratura stana je " << DajKvadraturu() <<  " (m^2) i stan je namjesten.";
  }
  if(Stan::namjesten == false){
    if(Stan::br_soba == 1)
  std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobu. Kvadratura stana je " << DajKvadraturu() <<  " (m^2) i stan nije namjesten.";
    if(Stan::br_soba == 2 || Stan::br_soba == 3 || Stan::br_soba == 4)
  std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobe. Kvadratura stana je " << DajKvadraturu() <<  " (m^2) i stan nije namjesten.";
    else 
  std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " soba. Kvadratura stana je " << DajKvadraturu() <<  " (m^2) i stan nije namjesten.";
  }
}

class Prodaja{
  std::string ime_agenta;
  double cijena;
  Datum datum_prodaje;
  Kupac kupac;
  Stan stan;
  
  public:
  Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
  Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
  const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
  void PromijeniKupca(const Kupac &novi_kupac) { Prodaja::kupac = novi_kupac; }
  void PromijeniStan(const Stan &novi_stan) {Prodaja::stan = novi_stan;}
  void PromijeniDatumKupovine(const Datum &novi_datum) { Prodaja::datum_prodaje = novi_datum; }
  void PromijeniCijenuProdaje(const double &nova_cijena) { Prodaja::cijena = nova_cijena; }
  void PomjeriDanUnaprijed() { Prodaja::datum_prodaje.Postavi(datum_prodaje.DajDan()+1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()); }
  void PomjeriDanUnazad() { Prodaja::datum_prodaje.Postavi(datum_prodaje.DajDan()-1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()); }
  std::string DajImeAgenta() const { return Prodaja::ime_agenta; }
  std::string DajImeKupca() const { return Prodaja::kupac.DajImePrezime(); }
  Datum DajDatumProdaje() const { return Prodaja::datum_prodaje; }
  double DajCijenuStana() const { return Prodaja::cijena; }
  friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
  friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
  void Ispisi() const;
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):
datum_prodaje(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()), kupac(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja()), 
stan(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu())
{
  Prodaja::ime_agenta = ime_agenta_prodaje;
  Prodaja::cijena = cijena_stana;
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
  const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):
  datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje), kupac(ime_kupca,datum_rodjenja_kupca), stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)
  {
    Prodaja::ime_agenta = ime_agenta_prodaje;
    Prodaja::cijena = cijena_stana;
  }

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
  
  if(p1.datum_prodaje.DajGodinu() > p2.datum_prodaje.DajGodinu()) 
    return true;
    
  if(p1.datum_prodaje.DajGodinu() == p2.datum_prodaje.DajGodinu())
    if(p1.datum_prodaje.DajMjesec() > p2.datum_prodaje.DajMjesec()) 
      return true;
      
  if(p1.datum_prodaje.DajGodinu() == p2.datum_prodaje.DajGodinu())
    if(p1.datum_prodaje.DajMjesec() == p2.datum_prodaje.DajMjesec())
      if(p1.datum_prodaje.DajDan() == p2.datum_prodaje.DajDan()) 
        return true;
        
  return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
  if(p1.cijena > p2.cijena) return true;
  return false;
}

void Prodaja::Ispisi() const {
  std::cout << "Ime agenta:                     ";std::cout << ime_agenta << std::endl;
  std::cout << "Ime kupca:                      ";kupac.Ispisi();   
  std::cout << "Zakazani datum prodaje:         ";datum_prodaje.Ispisi();     
  std::cout << "Cijena stana:                   ";std::cout << cijena << std::endl;
  std::cout << "Informacije o stanu: " << std::endl;	     
  stan.Ispisi();
}

class Prodaje{
  Prodaja** prodaje;
  int maxBrojProdaja;
  int brojProdaja;
  
  public:
  
  explicit Prodaje(int max_broj_prodaja) { maxBrojProdaja = max_broj_prodaja; brojProdaja = 0; prodaje = new Prodaja*[maxBrojProdaja]; } 
  Prodaje(std::initializer_list<Prodaja> spisak_prodaja); 
  ~Prodaje(); 
  Prodaje(const Prodaje &prodaje); 
  Prodaje(Prodaje &&prodaje); 
  Prodaje &operator =(const Prodaje &prodaje);
  Prodaje &operator =(Prodaje &&prodaje);
  void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan); 
  void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
  int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
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

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja){
    prodaje = new Prodaja*[spisak_prodaja.size()];
    int i(0);
    for(const auto x : spisak_prodaja){
      prodaje[i++] = new Prodaja(x);
    }
    maxBrojProdaja = spisak_prodaja.size();
    brojProdaja = spisak_prodaja.size();
}

Prodaje::~Prodaje(){
  for(int i=0; i<maxBrojProdaja; i++)
    delete prodaje[i];
  delete [] prodaje;
}




Prodaje::Prodaje(Prodaje &&pprodaje): maxBrojProdaja(pprodaje.maxBrojProdaja), brojProdaja(pprodaje.brojProdaja)
{
  prodaje = pprodaje.prodaje;
  pprodaje.prodaje = nullptr;
}

Prodaje &Prodaje::operator =(Prodaje &&pprodaje){
  if(&pprodaje != this){
    for(int i=0; i<maxBrojProdaja; i++)
        delete prodaje[i];
    delete [] prodaje;
    maxBrojProdaja = pprodaje.maxBrojProdaja;
    brojProdaja = pprodaje.brojProdaja;
    prodaje = pprodaje.prodaje;
    pprodaje.prodaje = nullptr;
  }
return *this;
}


Prodaje::Prodaje(const Prodaje &pprodaje): maxBrojProdaja(pprodaje.maxBrojProdaja), brojProdaja(pprodaje.brojProdaja){
   this -> prodaje = new Prodaja*[maxBrojProdaja];
   
   for(int i=0; i<maxBrojProdaja; i++) {
      this -> prodaje[i] = new Prodaja(*pprodaje.prodaje[i]);
   }
 }


Prodaje &Prodaje::operator =(const Prodaje &pprodaje){
  if(&pprodaje != this){
    for(int i=0; i<maxBrojProdaja; i++)
        delete prodaje[i];
    delete [] prodaje;
    maxBrojProdaja = pprodaje.maxBrojProdaja;
    brojProdaja = pprodaje.brojProdaja;
    prodaje = new Prodaja*[maxBrojProdaja];
    for(int i=0; i<maxBrojProdaja; i++){
        this -> prodaje[i] = new Prodaja(*pprodaje.prodaje[i]);
    }
  }
  return *this;
}


void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
  if(brojProdaja < maxBrojProdaja)
      prodaje[brojProdaja++] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
  else throw std::range_error("Dostignut maksimalni broj prodaja");
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
  int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
  
    if(brojProdaja < maxBrojProdaja)
        prodaje[brojProdaja++] = new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    else throw std::range_error("Dostignut maksimalni broj prodaja");
  }

 void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
   
   if(brojProdaja < maxBrojProdaja)
        prodaje[brojProdaja++] = new Prodaja(*prodaja);
    else throw std::range_error("Dostignut maksimalni broj prodaja");
 }


int Prodaje::DajBrojProdaja() const{ 
  if(brojProdaja == 0) throw std::domain_error("Nema registriranih prodaja"); 
return brojProdaja; 
  
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
  if(brojProdaja == 0) throw std::domain_error("Nema registriranih prodaja");
  return std::count_if(prodaje[0], prodaje[maxBrojProdaja], [datum](Prodaja pr1) {
    return pr1.DajDatumProdaje().DajDan() == datum.DajDan() && pr1.DajDatumProdaje().DajMjesec() == datum.DajMjesec() && pr1.DajDatumProdaje().DajGodinu() == datum.DajGodinu();
  });
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
  int brojac(0);
  for(int i=0; i<maxBrojProdaja; i++){
    if( prodaje[i] -> DajImeAgenta() == ime_agenta)
      brojac++;
  }
  return brojac;
}

Prodaja &Prodaje::DajNajranijuProdaju(){
  return *std::min_element(prodaje[0], prodaje[maxBrojProdaja], [] (Prodaja pr1, Prodaja pr2) {  
    if(pr1.DajDatumProdaje().DajDan() < pr2.DajDatumProdaje().DajDan() ) return true;
    else if( pr1.DajDatumProdaje().DajDan() == pr2.DajDatumProdaje().DajDan() && pr1.DajDatumProdaje().DajMjesec() < pr2.DajDatumProdaje().DajMjesec() ) return true;
    else if(pr1.DajDatumProdaje().DajDan() == pr2.DajDatumProdaje().DajDan() && pr1.DajDatumProdaje().DajMjesec() == pr2.DajDatumProdaje().DajMjesec() && pr1.DajDatumProdaje().DajGodinu() < pr2.DajDatumProdaje().DajGodinu()) return true;
    return false;
  });
}

Prodaja Prodaje::DajNajranijuProdaju() const{
    return *std::min_element(prodaje[0], prodaje[maxBrojProdaja], [] (Prodaja pr1, Prodaja pr2) {  
    if(pr1.DajDatumProdaje().DajDan() < pr2.DajDatumProdaje().DajDan() ) return true;
    else if( pr1.DajDatumProdaje().DajDan() == pr2.DajDatumProdaje().DajDan() && pr1.DajDatumProdaje().DajMjesec() < pr2.DajDatumProdaje().DajMjesec() ) return true;
    else if(pr1.DajDatumProdaje().DajDan() == pr2.DajDatumProdaje().DajDan() && pr1.DajDatumProdaje().DajMjesec() == pr2.DajDatumProdaje().DajMjesec() && pr1.DajDatumProdaje().DajGodinu() < pr2.DajDatumProdaje().DajGodinu()) return true;
    return false;
  }); }
  
Prodaja &Prodaje::DajNajskupljuProdaju(){
    return *std::max_element(prodaje[0], prodaje[maxBrojProdaja], [] (Prodaja pr1, Prodaja pr2){
      return pr1.DajCijenuStana() < pr2.DajCijenuStana();
    });
  }
  
Prodaja Prodaje::DajNajskupljuProdaju() const{
    return *std::max_element(prodaje[0], prodaje[maxBrojProdaja], [] (Prodaja pr1, Prodaja pr2){
      return pr1.DajCijenuStana() < pr2.DajCijenuStana();
    });
  }

void Prodaje::IsprazniKolekciju() {
    for(int i=0; i<maxBrojProdaja; i++)
      delete prodaje[i];
      brojProdaja = 0;
  }

void Prodaje::ObrisiNajranijuProdaju(){
  if(brojProdaja == 0) throw std::range_error("Prazna kolekcija");
   auto x = std::min_element(prodaje[0], prodaje[maxBrojProdaja], [] (Prodaja pr1, Prodaja pr2) {  
    if(pr1.DajDatumProdaje().DajDan() < pr2.DajDatumProdaje().DajDan() ) return true;
    else if( pr1.DajDatumProdaje().DajDan() == pr2.DajDatumProdaje().DajDan() && pr1.DajDatumProdaje().DajMjesec() < pr2.DajDatumProdaje().DajMjesec() ) return true;
    else if(pr1.DajDatumProdaje().DajDan() == pr2.DajDatumProdaje().DajDan() && pr1.DajDatumProdaje().DajMjesec() == pr2.DajDatumProdaje().DajMjesec() && pr1.DajDatumProdaje().DajGodinu() < pr2.DajDatumProdaje().DajGodinu()) return true;
    return false;
  });
  for(int i=0; i<maxBrojProdaja; i++){
   if(x == prodaje[i]){
    delete prodaje[i]; prodaje[i] = nullptr; 
    for(int j=i; j<maxBrojProdaja-1; j++)
        prodaje[j] = prodaje[j+1];
   }
  }
  brojProdaja--;
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
  for(int i=0; i<maxBrojProdaja; i++){
    if(prodaje[i] -> DajImeAgenta() == ime_agenta){
      delete prodaje[i]; prodaje[i] = nullptr;
        for(int j=i; j<maxBrojProdaja-1; j++)
        prodaje[j] = prodaje[j+1];
        brojProdaja--;
    }
  }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
  for(int i=0; i<maxBrojProdaja; i++){
    if(prodaje[i] -> DajDatumProdaje().DajDan() == datum.DajDan() && prodaje[i] -> DajDatumProdaje().DajMjesec() == datum.DajMjesec() && prodaje[i] -> DajDatumProdaje().DajGodinu() == datum.DajGodinu() ){
      delete prodaje[i]; prodaje[i] = nullptr;
        for(int j=i; j<maxBrojProdaja-1; j++)
        prodaje[j] = prodaje[j+1];
        brojProdaja--;
    }
  }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
  std::vector<Prodaja> vek;
  for(int i=0; i<maxBrojProdaja; i++){
    if(prodaje[i] -> DajDatumProdaje().DajDan() == datum.DajDan() && prodaje[i] -> DajDatumProdaje().DajMjesec() == datum.DajMjesec() && prodaje[i] -> DajDatumProdaje().DajGodinu() == datum.DajGodinu())
      vek.push_back(*prodaje[i]);
  }
  std::sort(vek.begin(), vek.end(), [] (Prodaja pr1, Prodaja pr2) -> bool { 
    return (pr1.DajImeKupca() < pr2.DajImeKupca());
  });
  for(int i=0; i<vek.size(); i++)
    vek[i].Ispisi();
}

void Prodaje::IspisiSveProdaje() const{
  std::vector<Prodaja> vek;
  for(int i=0; i<maxBrojProdaja; i++)
    vek.push_back(*prodaje[i]);
  
  std::sort(vek.begin(), vek.end(), [] (Prodaja pr1, Prodaja pr2) -> bool { if(pr1.DajDatumProdaje().DajDan() < pr2.DajDatumProdaje().DajDan() ) return true;
    else if( pr1.DajDatumProdaje().DajDan() == pr2.DajDatumProdaje().DajDan() && pr1.DajDatumProdaje().DajMjesec() < pr2.DajDatumProdaje().DajMjesec() ) return true;
    else if(pr1.DajDatumProdaje().DajDan() == pr2.DajDatumProdaje().DajDan() && pr1.DajDatumProdaje().DajMjesec() == pr2.DajDatumProdaje().DajMjesec() && pr1.DajDatumProdaje().DajGodinu() < pr2.DajDatumProdaje().DajGodinu()) return true;
    else return (pr1.DajImeKupca() < pr2.DajImeKupca());
});
  for(int i=0; i<vek.size(); i++)
    vek[i].Ispisi();
}

int main (){


    std::vector<Kupac> vek_kupaca;
    std::vector<Stan> vek_stan;
    
    std::cout << "Dobrodosli!" << std::endl << std::endl << std::endl;
    
    for(; ;){
    int meni;
    std::cout << "Izaberite opciju:" << std::endl;
    std::cout << " 0 - kraj" <<  std::endl;
    std::cout << " 1 - uredjivanje stanova" << std::endl;
    std::cout << " 2 - uredjivanje kupaca" << std::endl;
    std::cout << " 3 - uredjivanje prodaja" << std::endl;
    
    std::cin >> meni;
      if(meni == 0) break;
      
      if(meni == 1){
        for(; ;) {
          
          bool unos(true);
          bool pogresan_bool(true);
          
          std::cout<< "Izaberite opciju:" << std::endl;
          std::cout << " 0 - nazad" << std::endl;
          std::cout << " 1 - dodavanje stana" << std::endl;
          std::cout << " 2 - uredjivanje stanova" << std::endl;
          std::cout << " 3 - ispis svih stanova" << std::endl;
          std::cout << " 4 - kraj" << std::endl;
          int opcija_meni_1;
          std::cin >> opcija_meni_1;
          
            if(opcija_meni_1 == 0) break;
          
            if(opcija_meni_1 == 1){
            
            ponovi_unos_stana:
            
            std::cout << "Unesite adresu: ";
            std::string adresa;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, adresa);
            
            std::cout << "Unesite sprat: ";
            int sprat;
            std::cin >> sprat;
            
            std::cout << "Unesite broj soba: ";
            int broj_soba;
            std::cin >> broj_soba;
            
            std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
            int namjesten;
            std::cin >> namjesten;
            if(namjesten < 0 || namjesten > 1)  pogresan_bool = false;
            
            std::cout << "Unesite kvadraturu: ";
            double kvadratura;
            std::cin >> kvadratura;
            
            try{
              if(pogresan_bool == false){
              pogresan_bool = true; 
              throw std::domain_error("Neispravan unos podataka");
              }
              Stan s = Stan(adresa, sprat, broj_soba, namjesten, kvadratura);
              vek_stan.push_back(s);
              std::cout << "Stan je uspjesno dodan!" << std::endl;
            }
            catch(std::domain_error e1){
               
               unos = false;
               std::cout << "Izuzetak: " << e1.what() << ". Molimo unesite opet." << std::endl;
            }
            
            }
          
            if(opcija_meni_1 == 2){
              std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
              for(int i=0; i<vek_stan.size(); i++){
                std::cout << " " << i+1 << " - " ; vek_stan[i].Ispisi(); std::cout << std::endl;
              }
              
              int izmjena;
              std::cin >> izmjena;
              
              std::cout << "Odaberite polje koje zelite urediti:" << std::endl;
              std::cout << " 0 - nazad" << std::endl;
              std::cout << " 1 - adresa" << std::endl;
              std::cout << " 2 - sprat" << std::endl;
              std::cout << " 3 - broj soba" << std::endl;
              std::cout << " 4 - da li je stan namjesten" << std::endl;
              std::cout << " 5 - kvadratura" << std::endl;
              std::cout << " 6 - sve" << std::endl;
              int polje;
              std::cin >> polje;
              
              if(polje == 0) break;
              if(polje == 1){
                izmjena_1:
                std::cout << "Unesite adresu: ";
                std::string adresa;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::getline(std::cin, adresa);
                 try{
                   vek_stan[izmjena-1].Postavi(adresa, vek_stan[izmjena-1].DajSprat(), vek_stan[izmjena-1].DajBrojSoba(), vek_stan[izmjena-1].DajNamjesten(), vek_stan[izmjena-1].DajKvadraturu());
                   std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                 }
                 catch(std::domain_error e1){
                   std::cout << "Izuzetak: " << e1.what() << ". Molimo unesite opet." << std::endl;
                   goto izmjena_1;
                 }
                
              }
              if(polje == 2){
                izmjena_2:
                std::cout << "Unesite sprat: ";
                int sprat;
                std::cin >> sprat;
                try{
                   vek_stan[izmjena-1].Postavi(vek_stan[izmjena-1].DajAdresu(), sprat, vek_stan[izmjena-1].DajBrojSoba(), vek_stan[izmjena-1].DajNamjesten(), vek_stan[izmjena-1].DajKvadraturu());
                   std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                 }
                 catch(std::domain_error e1){
                   std::cout << "Izuzetak: " << e1.what() << ". Molimo unesite opet." << std::endl;
                   goto izmjena_2;
                 }
                
              }
              if(polje == 3){
                izmjena_3:
                std::cout << "Unesite broj soba: ";
                int broj_soba;
                std::cin >> broj_soba;
                 try{
                   vek_stan[izmjena-1].Postavi(vek_stan[izmjena-1].DajAdresu(), vek_stan[izmjena-1].DajSprat(), broj_soba, vek_stan[izmjena-1].DajNamjesten(), vek_stan[izmjena-1].DajKvadraturu());
                   std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                 }
                 catch(std::domain_error e1){
                   std::cout << "Izuzetak: " << e1.what() << ". Molimo unesite opet." << std::endl;
                   goto izmjena_3;
                 }
                
              }
              if(polje == 4){
               izmjena_4:
               std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
               bool namjesten;
               std::cin >> namjesten;
               try{
                   vek_stan[izmjena-1].Postavi(vek_stan[izmjena-1].DajAdresu(), vek_stan[izmjena-1].DajSprat(), vek_stan[izmjena-1].DajBrojSoba(), namjesten, vek_stan[izmjena-1].DajKvadraturu());
                   std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                 }
                 catch(std::domain_error e1){
                   std::cout << "Izuzetak: " << e1.what() << ". Molimo unesite opet." << std::endl;
                   goto izmjena_4;
                 }
                
              }
               if(polje == 5){
               izmjena_5:
               std::cout << "Unesite kvadraturu: ";
               double kvadratura;
               std::cin >> kvadratura;
                try{
                   vek_stan[izmjena-1].Postavi(vek_stan[izmjena-1].DajAdresu(), vek_stan[izmjena-1].DajSprat(), vek_stan[izmjena-1].DajBrojSoba(), vek_stan[izmjena-1].DajNamjesten(), kvadratura);
                   std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                 }
                 catch(std::domain_error e1){
                   std::cout << "Izuzetak: " << e1.what() << ". Molimo unesite opet." << std::endl;
                   goto izmjena_5;
                 }
                
              }
              if(polje == 6){
                 izmjena_6:
                 std::cout << "Unesite adresu: ";
                 std::string adresa;
                 std::cin.clear();
                 std::cin.ignore(10000, '\n');
                 std::getline(std::cin, adresa);
            
                 std::cout << "Unesite sprat: ";
                 int sprat;
                 std::cin >> sprat;
            
                 std::cout << "Unesite broj soba: ";
                 int broj_soba;
                 std::cin >> broj_soba;
            
                 std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                 bool namjesten;
                 std::cin >> namjesten;
            
                 std::cout << "Unesite kvadraturu: ";
                 double kvadratura;
                 std::cin >> kvadratura;
                 try{
                   vek_stan[izmjena-1].Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
                   std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                 }
                 catch(std::domain_error e1){
                   std::cout << "Izuzetak: " << e1.what() << ". Molimo unesite opet." << std::endl;
                   goto izmjena_6;
                 }
              }
              
            }
            
            if(unos == false) { 
              unos = true;
              goto ponovi_unos_stana;
            }
            
            if(opcija_meni_1 == 3){
              for(int i=0; i<vek_stan.size(); i++){
                std::cout << i+1 << ". ";
                vek_stan[i].Ispisi(); std::cout << std::endl;
              }
            }
          
            if(opcija_meni_1 == 4){
              std::cout << std::endl;
              std::cout << "Dovidjenja!";
              return 0;
            }
          
        }
      } 
        if(meni == 2){
          for(; ;){
            
          bool unos(true);
          bool izmjena(true);
          
          
          std::cout<< "Izaberite opciju:" << std::endl;
          std::cout << " 0 - nazad" << std::endl;
          std::cout << " 1 - dodavanje kupca" << std::endl;
          std::cout << " 2 - uredjivanje kupaca" << std::endl;
          std::cout << " 3 - ispis svih kupaca" << std::endl;
          std::cout << " 4 - kraj" << std::endl;
          int opcija_meni_2;
          std::cin >> opcija_meni_2;
            
            if(opcija_meni_2 == 0) break;
            
            if(opcija_meni_2 == 1){
              ponovi_unos_kupca:
              
              std::string ime;
              std::cout << "Unesite ime i prezime kupca: ";
              std::cin.clear();
              std::cin.ignore(10000, '\n');
              std::getline(std::cin, ime);
              std::cout << "Unesite datum rodjenja (formata d/m/g): ";
              int d,m,g;
              char znak;
              std::cin >> d >> znak >> m >> znak >> g;
              
                try{
                  Datum dat = Datum(d,m,g);
                  Kupac k = Kupac(ime, dat);
                  vek_kupaca.push_back(k);
                  std::cout << "Kupac je uspjesno dodan!" << std::endl;
                }
                catch(std::domain_error e1){
                  unos = false;
                  std::cout << "Izuzetak: " << e1.what() << ". Molimo unesite opet." << std::endl;
                  
                }
                
            }
            if(unos == false) { 
              unos = true;
              goto ponovi_unos_kupca;
            }
            else if(izmjena == false) {
              unos = true;
              goto ponovi_izmjenu_kupca;
            }
            
            
            if(opcija_meni_2 == 2){
              std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su: " << std::endl;
                for(int i=0; i<vek_kupaca.size(); i++){
                  std::cout << " " << i + 1 << " - "; vek_kupaca[i].Ispisi(); std::cout << std::endl;
                }
              int izmjena;
              std::cin >> izmjena;
              ponovi_izmjenu_kupca:
              std::string novo_ime;
              std::cin.clear();
              std::cin.ignore(10000, '\n');
              std::cout << "Unesite ime i prezime kupca: ";
              std::getline(std::cin, novo_ime);
              std::cout << "Unesite datum rodjenja (formata d/m/g): ";
              int d,m,g;
              char znak;
              std::cin >> d >> znak >> m >> znak >> g;
                try{
                  Datum novi_dat = Datum(d,m,g);
                  Kupac k = Kupac(novo_ime, novi_dat);
                  vek_kupaca[izmjena-1].Postavi(novo_ime, novi_dat);
                  std::cout << "Kupac je uspjesno izmijenjen!" << std::endl;
                }
                catch(std::domain_error e1){
                  izmjena = false;
                  std::cout << "Izuzetak: " << e1.what() << ". Molimo unesite opet." << std::endl;
                }
                
            }
            
            if(opcija_meni_2 == 3){
              for(int i=0; i<vek_kupaca.size(); i++){
                vek_kupaca[i].Ispisi(); std::cout << std::endl;
              }
            }
            
            if(opcija_meni_2 == 4){
              std::cout << std::endl;
              std::cout << "Dovidjenja!";
              return 0;
            }
          }
        }
        if(meni == 3) break;
        if(meni == 4) break;
        
    }
    
    std::cout << std::endl;
    std::cout << "Dovidjenja!";
    
    
	return 0;
}