/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <algorithm>
#include <initializer_list>
#include <vector>
class Datum{
    int dan, mjesec, godina;
    public:
      Datum(int dan, int mjesec, int godina){ Postavi(dan, mjesec, godina);}
      void Postavi(int dan, int mjesec, int godina);
      int DajDan() const {return dan;}
      int DajMjesec() const {return mjesec;}
      int DajGodinu() const {return godina;}
      void Ispisi() const {std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};

void Datum::Postavi (int dan, int mjesec, int godina){
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
      throw std::domain_error ("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}

class Kupac{
  std::string ime_i_prezime;
  Datum datum;
  public:
    Kupac (const std::string &ime_i_prezime,const Datum &datum_rodjenja):datum(datum_rodjenja){
      for(int i=0; i<ime_i_prezime.length(); i++)
      if(! ((ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || (ime_i_prezime[i]>=0 && ime_i_prezime[i]<=9 ) || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='-' || ime_i_prezime[i]==39) )
        throw std::domain_error("Neispravno ime i prezime");
      Kupac::ime_i_prezime = ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const {return ime_i_prezime;}
    Datum DajDatumRodjenja() const {return datum;}
    void Ispisi() const {std::cout<<ime_i_prezime<<" "<<"("<<datum.DajDan()<<"/"<<datum.DajMjesec()<<"/"<<datum.DajGodinu()<<")";}
  
};

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
  for (int i=0; i<ime_i_prezime.length(); i++){
    if(!((ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9') || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='-' || ime_i_prezime[i]==39))
       throw std::domain_error("Neispravno ime i prezime");
  }
    Kupac::datum.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
    Kupac::ime_i_prezime = ime_i_prezime;
}

class Stan{
  std::string adresa;
  int sprat;
  int broj_soba;
  bool namjesten;
  double kvadratura;
  public:
   Stan(const std::string &adresa,int sprat, int broj_soba, bool namjesten, double kvadratura){Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);}
   void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
   std::string DajAdresu() const {return adresa;}
   int DajSprat() const {return sprat;}
   int DajBrojSoba() const {return broj_soba;}
   bool DajNamjesten() const {return namjesten;}
   double DajKvadraturu() const {return kvadratura;}
   void Ispisi() const;
  
};

void  Stan::Postavi(const std::string &adresa,int sprat, int broj_soba, bool namjesten, double kvadratura){
  if(broj_soba<0 || kvadratura<0)
    throw std::domain_error("Neispravan unos podataka");
  Stan::adresa = adresa;
  Stan::broj_soba = broj_soba;
  Stan::namjesten = namjesten;
  Stan::kvadratura = kvadratura;
  Stan::sprat = sprat;
}

void Stan::Ispisi() const{
  std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<< sprat<<". spratu i ima "<<broj_soba;
  if(broj_soba>=5 && broj_soba<=20)
    std::cout<<" soba.";
  else if(broj_soba%10==1)
    std::cout <<" sobu.";
  else if(broj_soba%10==2 || broj_soba%10==3 || broj_soba%10==4)
    std::cout<<" sobe.";
  std::cout<<" Kvadratura stana je "<<kvadratura<<" (m^2) i stan ";
  if(namjesten)
   std::cout<<"je ";
  else
    std::cout<<"nije ";
  std::cout<<"namjesten.";
}

class Prodaja{
  std::string ime_agenta_prodaje;
  double cijena_stana;
  Datum datum_prodaje;
  Kupac kupac_stana;
  Stan kupljeni_stan;
  public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac) {kupac_stana = novi_kupac;}
    void PromijeniStan(const Stan &novi_stan) {kupljeni_stan = novi_stan;}
    void PromijeniDatumKupovine(const Datum &novi_datum) {datum_prodaje = novi_datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena) {cijena_stana = nova_cijena;}
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const {return ime_agenta_prodaje;}
    std::string DajImeKupca() const {return kupac_stana.DajImePrezime();}
    Datum DajDatumProdaje() const {return datum_prodaje;}
    double DajCijenuStana() const {return cijena_stana;}
    friend bool ProdatPrije (const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
  
};

Prodaja::Prodaja (const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) : datum_prodaje(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()), kupac_stana(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja()), kupljeni_stan(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu()) {
  Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
  Prodaja::cijena_stana = cijena_stana;
  
}

Prodaja::Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata){
   Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
   Prodaja::cijena_stana = cijena_stana;
}

void Prodaja::PomjeriDanUnaprijed() {
  int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30, 31};
  if((datum_prodaje.DajGodinu()%4==0 && datum_prodaje.DajGodinu()%100!=0) || datum_prodaje.DajGodinu()%400==0)
    broj_dana[1]++;
  int dan (datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec()), godina(datum_prodaje.DajGodinu());
  dan++;
  if(dan>broj_dana[mjesec-1]){
    dan=1;
    mjesec++;
  }
  if(mjesec>12){
    mjesec = 1;
    godina++;
  }
  datum_prodaje.Postavi(dan, mjesec, godina);
}

void Prodaja::PomjeriDanUnazad() {
  int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec()), godina(datum_prodaje.DajGodinu());
  if((godina%4==0 && godina%100!=0) || godina%400==0)
    broj_dana[1]++;
  dan--;
  if(dan<1){
    mjesec--;
    if(mjesec>=1){
      dan = broj_dana[mjesec - 1];
    }
    else{
      mjesec = 12;
      dan = 31;
      godina--;
    }
    
  }
  datum_prodaje.Postavi(dan, mjesec, godina);
}

bool ProdatPrije (const Prodaja &p1, const Prodaja &p2){
  if(p1.datum_prodaje.DajGodinu()<p2.datum_prodaje.DajGodinu())
    return true;
  else if(p1.datum_prodaje.DajGodinu()>p2.datum_prodaje.DajGodinu())
    return false;
  if(p1.datum_prodaje.DajMjesec()<p2.datum_prodaje.DajMjesec())
    return true;
  else if(p1.datum_prodaje.DajMjesec()>p2.datum_prodaje.DajMjesec())
    return false;
  if(p1.datum_prodaje.DajDan()<p2.datum_prodaje.DajDan())
    return true;
  return false;
}

bool SkupljiStan (const Prodaja &p1, const Prodaja &p2){
  return p1.cijena_stana>p2.cijena_stana;
}

void Prodaja::Ispisi() const{
  std::cout<<std::setw(25)<<"Ime agenta: "<<std::left<<std::setw(30)<<ime_agenta_prodaje<<std::endl;
  std::cout<<std::right<<std::setw(25)<<"Ime kupca: "<<std::left<<std::setw(30)<<kupac_stana.DajImePrezime()<<std::endl;
  std::cout<<std::right<<std::setw(25)<<"Zakazani datum prodaje: "<<std::left<<std::setw(30); datum_prodaje.Ispisi(); std::cout<<std::endl;
  std::cout<<std::right<<std::setw(25)<<"Cijena stana: "<<std::left<<std::setw(30)<<cijena_stana<<std::endl;
  std::cout<<std::right<<std::setw(25)<<"Informacije o stanu: "<<std::endl;
  kupljeni_stan.Ispisi();
  
}

class Prodaje{
  const int max_br_prodaja;
  int broj_registriranih;
  Prodaja **prodaje;
  static bool IstiDatum(const Datum &d1, const Datum &d2){
    return (d1.DajDan()==d2.DajDan() && d1.DajMjesec()==d2.DajMjesec() && d1.DajGodinu()==d2.DajGodinu());
  }
  public:
    explicit Prodaje(int max_br_prodaja) : max_br_prodaja(max_br_prodaja), broj_registriranih(0), prodaje(new Prodaja *[max_br_prodaja]) {}
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator= (const Prodaje &prodaje);
    Prodaje &operator= (Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const {return broj_registriranih;}
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

Prodaje::Prodaje (std::initializer_list<Prodaja> lista) : max_br_prodaja(lista.size()), broj_registriranih(lista.size()), prodaje(new Prodaja *[lista.size()]){
    auto p(lista.begin());
    for(int i=0; i<lista.size(); i++){
      prodaje[i] = new Prodaja(*p);
      p++;
    }
}

Prodaje::~Prodaje(){
  for(int i=0; i<broj_registriranih; i++) delete prodaje[i];
  delete[] prodaje;
}

Prodaje::Prodaje(const Prodaje &p) : prodaje(new Prodaja*[p.max_br_prodaja]{}), max_br_prodaja(p.max_br_prodaja), broj_registriranih(p.broj_registriranih){
  try{
    for(int i=0; i<p.broj_registriranih; i++)
      prodaje[i] = new Prodaja(*p.prodaje[i]);
  }
  catch(...){
    for(int i=0; i<p.broj_registriranih; i++)
      delete prodaje[i];
    delete[] prodaje;
    throw;
  }
  
}

Prodaje::Prodaje (Prodaje &&p) : prodaje(p.prodaje), max_br_prodaja(p.max_br_prodaja), broj_registriranih(p.broj_registriranih){
   p.prodaje = nullptr;
   p.broj_registriranih = 0;
}

Prodaje &Prodaje::operator=(const Prodaje &p){
  if(p.max_br_prodaja !=max_br_prodaja)
    throw std::domain_error("Nesaglasne velicine nizova");
  if(p.broj_registriranih > broj_registriranih){
    try{
    for(int i=broj_registriranih; i<p.broj_registriranih; i++){
       prodaje[i] = new Prodaja(*p.prodaje[i]);
    }
    }
    catch(...){
      for(int i=broj_registriranih; i<p.broj_registriranih; i++){
        delete prodaje[i];
        prodaje[i] = nullptr;
      }
      throw;
    }
  }
  else{
    for(int i=p.broj_registriranih; i<broj_registriranih; i++){
      delete prodaje[i];
      prodaje[i] = nullptr;
    }
    
  }
  broj_registriranih = p.broj_registriranih;
  for(int i=0; i<broj_registriranih; i++) *prodaje[i] = *p.prodaje[i];
  return *this;
  
}

Prodaje &Prodaje::operator=(Prodaje &&p){
  if(p.max_br_prodaja!=max_br_prodaja)
     throw std::domain_error("Razliciti kapaciteti nizova");
  std::swap(broj_registriranih, p.broj_registriranih);
  std::swap(prodaje, p.prodaje);
  return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
  Prodaja p(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
  if(broj_registriranih==max_br_prodaja)
    throw std::range_error("Dostignut maksimalni broj prodaja");
  try{
    prodaje[broj_registriranih++] = new Prodaja(p);
  }
  catch(...){
    //broj_registriranih--;
    throw;
    
  }
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
  if(broj_registriranih==max_br_prodaja)
    throw std::range_error("Dostignut maksimalni broj prodaja");
  Prodaja p(ime_agenta_prodaje,cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
  try{
    prodaje[broj_registriranih++] = new Prodaja(p);
  }
  catch(...){
    //broj_registriranih--;
    throw;
    
  }
}

void Prodaje::RegistrirajProdaju(Prodaja *p){
  if(broj_registriranih==max_br_prodaja)
    throw std::range_error("Dostignut maksimalni broj prodaja");
  try{
    prodaje[broj_registriranih++] = new Prodaja(*p);
    
  }
  catch(...){
    
    //broj_registriranih--;
    throw;
  }
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
  int brojac(0);
 
  brojac = std::count_if(prodaje, prodaje + broj_registriranih, [datum] (Prodaja *p1)->bool {
    if(p1->DajDatumProdaje().DajDan()==datum.DajDan() && p1->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && p1->DajDatumProdaje().DajGodinu()==datum.DajGodinu()  )
      return true;
    return false;
  });
  return brojac;
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
  int brojac(0);
  for(int i=0; i<broj_registriranih; i++){
    if(prodaje[i]->DajImeAgenta()==ime_agenta)
      brojac++;
  }
  return brojac;
}

Prodaja &Prodaje::DajNajranijuProdaju() {
  if(broj_registriranih==0)
    throw std::domain_error("Nema registriranih prodaja");

  auto prva = std::min_element(prodaje, prodaje + broj_registriranih, [] (Prodaja *p1, Prodaja *p2){
    if(ProdatPrije(*p1, *p2))
      return true;
    return false;
  });
  auto p(*prva);
  return *p;
}

Prodaja Prodaje::DajNajranijuProdaju() const{
   if(broj_registriranih==0)
    throw std::domain_error("Nema registriranih prodaja");
  auto prva = std::min_element(prodaje, prodaje + broj_registriranih, [] (Prodaja *p1, Prodaja *p2){
    if(ProdatPrije(*p1, *p2))
      return true;
    return false;
  });
  auto p(*prva);
  return *(p);
}

Prodaja &Prodaje::DajNajskupljuProdaju() {
  if(broj_registriranih==0)
    throw std::domain_error("Nema registriranih prodaja");
  auto najskuplja = std::max_element(prodaje, prodaje + broj_registriranih, [] (Prodaja *p1, Prodaja *p2){
    if(SkupljiStan(*p1, *p2))
      return true;
    return false;
  });
  auto p(*najskuplja);
  return *p;
}


Prodaja Prodaje::DajNajskupljuProdaju() const{
    if(broj_registriranih==0)
    throw std::domain_error("Nema registriranih prodaja");
  auto najskuplja = std::max_element(prodaje, prodaje + broj_registriranih, [] (Prodaja *p1, Prodaja *p2){
    if(SkupljiStan(*p1, *p2))
      return true;
    return false;
  });
  auto p(*najskuplja);
  return *p;
}

void Prodaje::IsprazniKolekciju(){
  for(int i=0; i<broj_registriranih; i++)
    prodaje[i] = nullptr;
  broj_registriranih = 0;
}

void Prodaje::ObrisiNajranijuProdaju(){
  if(broj_registriranih==0)
   throw std::range_error("Prazna kolekcija");
  int prva(0);
  for(int i=1; i<broj_registriranih; i++){
    if(ProdatPrije(*prodaje[i], *prodaje[prva]))
      prva = i;
  }
  for(int j=prva; j<broj_registriranih - 1; j++){
    prodaje[j] = prodaje[j+1];
  }
  prodaje[broj_registriranih-1]=nullptr;
  broj_registriranih--;
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
  for(int i=0; i<broj_registriranih; i++){
    if(prodaje[i]->DajImeAgenta()==ime_agenta){
      for(int j=i; j<broj_registriranih-1; j++){
        prodaje[j] = prodaje[j+1];
      }
      broj_registriranih--;
    }
  }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
  for(int i=0; i<broj_registriranih; i++){
    if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() && prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
      for(int j=i; j<broj_registriranih - 1; j++){
        prodaje[j] = prodaje[j+1];
      }
      broj_registriranih--;
    }
  }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
  Prodaje p(*this);
  std::sort(p.prodaje, p.prodaje + broj_registriranih, [] (Prodaja *p1, Prodaja *p2) {
    if(p1->DajImeKupca()<p2->DajImeKupca())
      return true;
    return false;
  });
  for(int i=0; i<broj_registriranih; i++){
    
    if(Prodaje::IstiDatum(p.prodaje[i]->DajDatumProdaje(), datum))
      p.prodaje[i]->Ispisi();
  }
}

void Prodaje::IspisiSveProdaje() const{
  Prodaje p(*this);
  std::sort(p.prodaje, p.prodaje + broj_registriranih, [] (Prodaja *p1, Prodaja *p2){
    if(ProdatPrije((*p1), (*p2)))
      return true;
    else if(p1->DajDatumProdaje().DajDan()==p2->DajDatumProdaje().DajDan() && p1->DajDatumProdaje().DajMjesec()==p2->DajDatumProdaje().DajMjesec() && p1->DajDatumProdaje().DajGodinu()==p2->DajDatumProdaje().DajGodinu() && p1->DajImeKupca()<p2->DajImeKupca())
      return true;
    return false;
  });
  for(int i=0; i<broj_registriranih; i++)
    p.prodaje[i]->Ispisi();
}


int main ()
{
  
  
  Prodaje baza_prodaja(20);
  std::vector<Stan> stanovi;
  std::vector<Kupac> kupci;
  int prva_opcija;
  std::cout<<"Dobrodosli!\n";
  do{
    std::cout<<"\nIzaberite opciju:\n 0 - kraj\n 1 - uredjivanje stanova\n 2 - uredjivanje kupaca\n 3 - uredjivanje prodaja\n";
    std::cin>>prva_opcija;
    if(prva_opcija==0){
      std::cout<<"\nDovidjenja!";
      return 0;
    }
    if(prva_opcija==1){
      int druga_opcija;
      do{
        std::cout<<"\n\nIzaberite opciju:\n 0 - nazad\n 1 - dodavanje stana\n 2 - uredjivanje stanova\n 3 - ispis svih stanova\n 4 - kraj\n";
        std::cin>>druga_opcija;
        if(druga_opcija==4){
          std::cout<<"\nDovidjenja!";
          return 0;
        }
        if(druga_opcija==0)
          break;
        if(druga_opcija==1){
          bool pogresan_unos(true);
          while(pogresan_unos){
          try{
            std::string adresa;
            int sprat;
            int broj_soba;
            int namjesten;
            double kvadratura;
            std::cout<<"Unesite adresu: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, adresa);
            std::cout<<"Unesite sprat: ";
            std::cin>>sprat;
            if(!std::cin){
              std::cin.clear();
              std::cin.ignore(10000, '\n');
              throw std::domain_error("Neispravan unos");
            }
            std::cout<<"Unesite broj soba: ";
            std::cin>>broj_soba;
            std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
            std::cin>>namjesten;
            
            std::cout<<"Unesite kvadraturu: ";
            std::cin>>kvadratura;
            if(namjesten!=0 && namjesten!=1)
              throw std::domain_error("Neispravan unos podataka");
            Stan stan(adresa, sprat, broj_soba, namjesten, kvadratura);
            stanovi.push_back(stan);
            pogresan_unos = false;
            std::cout<<"Stan je uspjesno dodan!\n";
          }
          catch(std::domain_error e){
            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.\n";
          }
          }
        }
        
        if(druga_opcija==3){
          for(int i=0; i<stanovi.size(); i++){
            std::cout<<i+1<<". ";
            stanovi[i].Ispisi();
            std::cout<<std::endl;
          }
        }
        if(druga_opcija==2){
          int treca_opcija;
          int k;
          std::cout<<"\nOdaberite stan. Dostupni stanovi su:\n";
          for(int i=0; i<stanovi.size(); i++){
            std::cout<<" "<<i+1<<" - ";
            stanovi[i].Ispisi();
            std::cout<<std::endl;
          }
          std::cin>>k;
          std::cout<<"\nOdaberite polje koje zelite urediti:\n 0 - nazad\n 1 - adresa\n 2 - sprat\n 3 - broj soba\n 4 - da li je stan namjesten\n 5 - kvadratura\n 6 - sve\n";
          std::cin>>treca_opcija;
          if(treca_opcija==0)
            break;
          if(treca_opcija==1){
            
            bool pogresan_unos(true);
            std::string adresa;
            while (pogresan_unos) {
              try{
                std::cout<<"Unesite adresu: ";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::getline(std::cin, adresa);
                Stan novi_stan(adresa, stanovi[k-1].DajSprat(), stanovi[k-1].DajBrojSoba(), stanovi[k-1].DajNamjesten(), stanovi[k-1].DajKvadraturu());
                stanovi[k-1] = novi_stan;
                pogresan_unos = false;
              }catch(std::domain_error e){
                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.\n";
              }
            }
            std::cout<<"Stan je uspjesno izmijenjen!\n";
          }
          
          if(treca_opcija==2){
            bool pogresan_unos(true);
            while (pogresan_unos) {
              try{
                int novi_sprat;
                std::cout<<"Unesite sprat: ";
                std::cin>>novi_sprat;
                if(!std::cin)
                 throw std::domain_error("Neispravan unos podataka");
                Stan novi_stan(stanovi[k-1].DajAdresu(), novi_sprat, stanovi[k-1].DajBrojSoba(), stanovi[k-1].DajNamjesten(), stanovi[k-1].DajKvadraturu());
                stanovi[k-1] = novi_stan;
                pogresan_unos = false;
                std::cout<<"Stan je uspjesno izmijenjen!\n";
              }catch(std::domain_error e){
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.\n";
              }
            }
          }
          if(treca_opcija==3){
            bool pogresan_unos(true);
            while (pogresan_unos) {
              try{
                int broj_soba;
                std::cout<<"Unesite broj soba: ";
                std::cin>>broj_soba;
                if(!broj_soba)
                  throw std::domain_error("Neispravan unos podataka");
                Stan novi_stan(stanovi[k-1].DajAdresu(), stanovi[k-1].DajSprat(), broj_soba, stanovi[k-1].DajNamjesten(), stanovi[k-1].DajKvadraturu());
                stanovi[k-1] = novi_stan;
                pogresan_unos = false;
                std::cout<<"Stan je uspjesno izmijenjen!\n";
              }catch(std::domain_error e){
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.\n";
              }
            }
          }
          if(treca_opcija==4){
            bool pogresan_unos(true);
            while (pogresan_unos) {
              try{
                int namjesten;
                std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                std::cin >> namjesten;
                if(namjesten!=0 && namjesten!=1)
                  throw std::domain_error("Neispravan unos podataka");
                Stan novi_stan(stanovi[k-1].DajAdresu(), stanovi[k-1].DajSprat(), stanovi[k-1].DajBrojSoba(), namjesten, stanovi[k-1].DajKvadraturu());
                stanovi[k-1] = novi_stan;
                pogresan_unos = false;
                std::cout<<"Stan je uspjesno izmijenjen!\n";
              }catch(std::domain_error e){
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.\n";
                }
            }
          }
          
          if(treca_opcija==5){
            bool pogresan_unos(true);
            while (pogresan_unos) {
              try{
                double kvadratura;
                std::cout<<"Unesite kvadraturu: ";
                std::cin>>kvadratura;
                if(!std::cin || kvadratura<0)
                  throw std::domain_error("Neispravan unos podataka");
                Stan novi_stan(stanovi[k-1].DajAdresu(), stanovi[k-1].DajSprat(), stanovi[k-1].DajBrojSoba(), stanovi[k-1].DajNamjesten(), kvadratura);
                stanovi[k-1] = novi_stan;
                pogresan_unos = false;
                std::cout<<"Stan je uspjesno izmijenjen!\n";
              }catch(std::domain_error e){
                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.\n";
              }
            }
          }
          
          if(treca_opcija==6){
            bool pogresan_unos(true);
            while (pogresan_unos) {
              try{
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::string nova_adresa;
                int novi_sprat, novi_broj_soba, novi_namjesten;
                double nova_kvadratura;
                std::cout<<"Unesite adresu: ";
                std::getline(std::cin, nova_adresa);
                std::cout<<"Unesite sprat: ";
                std::cin>>novi_sprat;
                if(!std::cin || novi_sprat<0)
                  throw std::domain_error("Neispravan unos podataka");
                std::cout<<"Unesite broj soba: ";
                std::cin>>novi_broj_soba;
                if(!std::cin || novi_broj_soba<0)
                  throw std::domain_error("Neispravan unos podataka");
                std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                std::cin>>novi_namjesten;
                if(!std::cin || (novi_namjesten!=0 && novi_namjesten!=1))
                  throw std::domain_error("Neispravan unos podataka");
                std::cout<<"Unesite kvadraturu: ";
                std::cin>>nova_kvadratura;
                if(!std::cin || nova_kvadratura<0)
                  throw std::domain_error("Neispravan unos podataka");
                stanovi[k-1] = Stan(nova_adresa, novi_sprat, novi_broj_soba, novi_namjesten, nova_kvadratura);
                pogresan_unos = false;
                std::cout<<"Stan je uspjesno izmijenjen!\n";
              }catch(std::domain_error e){
                
                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.\n";
              }
            }
          }
        }
      }while(druga_opcija);
      
    }
    
    if(prva_opcija==2){
      int cetvrta_opcija;
      do{
      std::cout<<"\nIzaberite opciju:\n 0 - nazad\n 1 - dodavanje kupca\n 2 - uredjivanje kupaca\n 3 - ispis svih kupaca\n 4 - kraj\n";
      std::cin>>cetvrta_opcija;
      if(cetvrta_opcija==0)
        break;
      if(cetvrta_opcija==4){
        std::cout<<"\nDovidjenja!";
        return 0;
      }
      if(cetvrta_opcija==1){
        bool pogresan_unos(true);
        while (pogresan_unos) {
          try{
            std::string ime_i_prezime;
            int dan, mjesec, godina;
            char znak1, znak2;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Unesite ime i prezime kupca: ";
            std::getline(std::cin, ime_i_prezime);
            std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
            
            std::cin>>dan>>znak1>>mjesec>>znak2>>godina;
            //Datum dat(dan, mjesec, godina);
            if(znak1!='/' || znak2!='/')
              throw std::domain_error("Neispravan unos podataka");
            //std::cout<<"\n\n"<<dan<<"  "<<mjesec<<"  "<<godina<<"\n\n";
            Datum dat(dan, mjesec, godina);
            Kupac kupac(ime_i_prezime, dat);
            kupci.push_back(kupac);
            pogresan_unos = false;
            std::cout<<"Kupac je uspjesno dodan!";
            
          }catch(std::domain_error e){
            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.\n";
          }
        }
      }
     if(cetvrta_opcija==3){
       for(int i=0; i<kupci.size(); i++){
         kupci[i].Ispisi();
         std::cout<<std::endl;
       }
     }
     
     if(cetvrta_opcija==2){
       std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:\n";
       for(int i=0; i<kupci.size(); i++){
         std::cout<<" "<<i+1<<" - ";
         kupci[i].Ispisi();
         std::cout<<std::endl;
       }
       int k1;
       std::cin>>k1;
       bool pogresan_unos(true);
       while (pogresan_unos) {
         try{
           std::string ime_i_prezime;
           int dan, mjesec, godina;
           char znak1, znak2;
           std::cout<<"Unesite ime i prezime kupca: ";
           std::cin.clear();
           std::cin.ignore(10000, '\n');
           std::getline(std::cin, ime_i_prezime);
           std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
           std::cin>>dan>>znak1>>mjesec>>znak2>>godina;
           if(znak1!='/' || znak2!='/')
             throw std::domain_error("Neispravan unos podataka");
            Datum d(dan, mjesec, godina);
           kupci[k1-1] = Kupac(ime_i_prezime, d);
           pogresan_unos = false;
           std::cout<<"Kupac je uspjesno izmijenjen!\n";
         }catch(std::domain_error e){
           std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.\n";
         }
       }
     }
    }while(cetvrta_opcija);
    }
    if(prva_opcija==3){
      int sesta_opcija;
      do{
      std::cout<<"\nIzaberite opciju:\n 0 - nazad\n 1 - dodavanje prodaje\n 2 - uredjivanje prodaje\n 3- ispis prodaja\n 4- brisanje prodaja\n 5 - kraj\n";
      std::cin>>sesta_opcija;
      if(sesta_opcija==0)
        break;
      if(sesta_opcija==5){
        std::cout<<"Dovidjenja!";
        return 0;
      }
      if(sesta_opcija==1){
        int sedma_opcija;
        do{
          std::cout<<"\nIzaberite opciju:\n 0 - nazad\n 1 - dodavanje potpuno nove prodaje\n 2 - dodavanje nove prodaje na osnovu arhive\n 3 - kraj\n";
          std::cin>>sedma_opcija;
          if(sedma_opcija==0)
            break;
          if(sedma_opcija==3){
            std::cout<<"Dovidjenja!";
            return 0;
          }
          
          if(sedma_opcija==1){
            bool pogresan_unos(true);
            while (pogresan_unos) {
            std::string ime_agenta, ime_kupca, adresa;
            int danp, mjesecp, godinap, danr,mjesecr, godinar;
            double cijena, kvadratura;
            int sprat, broj_soba, namjesten;
            char znak1, znak2;
            try{
            std::cout<<"Unesite ime i prezime agenta prodaje: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, ime_agenta);
            std::cout<<"Unesite datum prodaje (formata d/m/g): ";
            std::cin>>danp>>znak1>>mjesecp>>znak2>>godinap;
            if(!std::cin || znak1!='/' || znak2!='/')
              throw std::domain_error("Neispravan unos podataka");
            //Datum datum_prodaje(danp, mjesecp, godinap);
            std::cout<<"Unesite cijenu stana: ";
            std::cin>>cijena;
            if(!std::cin || cijena<0)
              throw std::domain_error("Neispravan unos podataka");
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Unesite ime kupca: ";
            std::getline(std::cin, ime_kupca);
            std::cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
            std::cin>>danr>>znak1>>mjesecr>>znak2>>godinar;
            
            if(!std::cin || znak1!='/' || znak2!='/')
              throw std::domain_error("Neispravan unos podataka");
            std::cout<<"Unesite adresu: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, adresa);
            std::cout<<"Unesite sprat: ";
            std::cin>>sprat;
            if(!std::cin)
              throw std::domain_error("Neispravan unos podataka");
            std::cout<<"Unesite broj soba: ";
            std::cin>>broj_soba;
            if(!std::cin)
              throw std::domain_error("Neispravan unos podataka");
            std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
            std::cin>>namjesten;
            if(!std::cin)
              throw std::domain_error("Neispravan unos podataka");
            std::cout<<"Unesite kvadraturu: ";
            std::cin>>kvadratura;
            if(!std::cin)
              throw std::domain_error("Neispravan unos podataka");
            Datum datum_rodjenja(danr, mjesecr, godinar);
            Datum datum_prodaje(danp, mjesecp, godinap);
            baza_prodaja.RegistrirajProdaju(ime_agenta,cijena, danp, mjesecp, godinap, ime_kupca, datum_rodjenja, adresa, sprat, broj_soba, namjesten, kvadratura);
            pogresan_unos = false;
            std::cout<<"Prodaja uspjesno dodana!\n";
            kupci.push_back(Kupac(ime_kupca, datum_rodjenja));
            stanovi.push_back(Stan(adresa, sprat, broj_soba, namjesten, kvadratura));
            }catch(std::domain_error e){
              std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.\n";
              std::cin.clear();
              std::cin.ignore(10000, '\n');
            }
              
            }
          }
          if(sedma_opcija==2){
            bool pogresan_unos(true);
            while (pogresan_unos) {
              try{
                std::string ime_agenta;
                int danp, mjesecp, godinap;
                double cijena;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout<<"Unesite ime agenta prodaje: ";
                std::getline(std::cin, ime_agenta);
                std::cout<<"Unesite datum (formata d/m/g): ";
                char znak1, znak2;
                std::cin>>danp>>znak1>>mjesecp>>znak2>>godinap;
                //std::cout<<"\n"<<danp<<"  "<<mjesecp<<"  "<<godinap;
                if(znak1!='/' || znak2!='/')
                  throw std::domain_error("Neispravan unos podataka");
                std::cout<<"Unesite cijenu: ";
                std::cin>>cijena;
                std::cout<<"Odaberite kupca. Dostupni kupci su:\n";
                for(int i=0; i<kupci.size(); i++){
                  std::cout<<" "<<i+1<<" - ";
                  kupci[i].Ispisi();
                  std::cout<<std::endl;
                }
                int kupac;
                std::cin>>kupac;
                std::cout<<"Odaberite stan. Dostupni stanovi su:\n";
                for(int i=0; i<stanovi.size(); i++){
                  std::cout<<" "<<i+1<<" - ";
                  stanovi[i].Ispisi();
                  std::cout<<std::endl;
                  
                }
                int stan;
                std::cin>>stan;
                Datum datum(danp, mjesecp, godinap);
              
                baza_prodaja.RegistrirajProdaju(ime_agenta, cijena, datum, kupci[kupac - 1], stanovi[stan-1]);
                pogresan_unos = false;
                std::cout<<"Prodaja uspjesno dodana!\n";
              }catch(std::domain_error e){
                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.\n";
              }
            }
          }
          
        }while(sedma_opcija);
      }
      
      if(sesta_opcija==2){
        std::cout<<"\nOdaberite prodaju koju zelite urediti. Dostupne prodaje su:\n";
        baza_prodaja.IspisiSveProdaje();
        int osma_opcija;
        std::cin>>osma_opcija;
        std::cout<<"\nIzaberite opciju:\n 0 - nazad\n 1 - izmjena agenta\n 2 - izmjena datuma prodaje\n 3 - izmjena kupca\n 4 - izmjena stana\n 5 - izmjena cijena stana\n";
        int deveta_opcija;
        std::cin>>deveta_opcija;
        
        
      }
      
      
      
      }while(sesta_opcija);
    }
    
     
  }while (prva_opcija);
  

	return 0;
}




