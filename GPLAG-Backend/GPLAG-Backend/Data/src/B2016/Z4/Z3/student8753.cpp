#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <vector>
class Datum{
    int dan,mjesec,godina;
    public:
    Datum(int dan,int mjesec,int godina);
    void Postavi(int dan,int mjesec,int godina);
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
        std::cout<<std::setfill('0')<<dan<<"/"<<std::setfill('0')<<mjesec<<"/"<<std::setfill('0')<<godina;
    }
    
};

Datum::Datum(int dan,int mjesec,int godina){
	int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if(dan<1 || mjesec<1 || godina<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum.");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}
void Datum::Postavi(int dan,int mjesec,int godina){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if(dan<1 || mjesec<1 || godina<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum.");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}

class Kupac{
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    public:
    Kupac(const std::string &ime_i_prezime,const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja);
    std::string DajImePrezime() const {
        return ime_i_prezime;
    }
    Datum DajDatumRodjenja() const {
        return datum_rodjenja;
    }
    void Ispisi() const {
        ;for(int i=0;i<ime_i_prezime.length();i++) std::cout<<ime_i_prezime[i]; std::cout<<std::endl;
    }
};

Kupac::Kupac(const std::string &ime_i_prezime,const Datum &datum_rodjenja) : datum_rodjenja(datum_rodjenja) {
    for(int i=0;i<ime_i_prezime.length();i++){
        if ((ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || (ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9') || ime_i_prezime[i]=='-' || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='`') continue;
        throw std::domain_error("Neispravno ime i prezime.");
    }
    Kupac::ime_i_prezime=ime_i_prezime;
    
}

void Kupac::Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja){
    for(int i=0;i<ime_i_prezime.length();i++){
        if ((ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || (ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9') || ime_i_prezime[i]=='-' || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='`') continue;
        throw std::domain_error("Neispravno ime i prezime.");
    }
    Kupac::ime_i_prezime=ime_i_prezime;
    Kupac::datum_rodjenja=datum_rodjenja;
}

class Stan{
    std::string adresa;
    int spratovi,sobe;
    bool namjesten;
    double kvadrat;
    public:
    Stan(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura);
    void Postavi(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura);
    std::string DajAdresu() const {
        return adresa;
    }
    int DajSprat() const {
        return spratovi;
    }
    int DajBrojSoba() const {
        return sobe;
    }
    bool DajNamjesten() const {
        return namjesten;
    }
    double DajKvadraturu() const {
        return kvadrat;
    }
    void Ispisi() const;
};

Stan::Stan(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura){
	 for(int i=0;i<adresa.length();i++){
        if ((adresa[i]>='A' && adresa[i]<='Z') || (adresa[i]>='a' && adresa[i]<='z') || (adresa[i]>='0' && adresa[i]<='9') || adresa[i]=='-' || adresa[i]==' ' || adresa[i]=='`') continue;
        else throw std::domain_error("Neispravno ime i prezime.");
    }
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka.");
    Stan::adresa=adresa; Stan::spratovi=sprat; Stan::sobe=broj_soba; Stan::namjesten=namjesten; Stan::kvadrat=kvadratura;
}
void Stan::Postavi(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura){
     for(int i=0;i<adresa.length();i++){
        if ((adresa[i]>='A' && adresa[i]<='Z') || (adresa[i]>='a' && adresa[i]<='z') || (adresa[i]>='0' && adresa[i]<='9') || adresa[i]=='-' || adresa[i]==' ' || adresa[i]=='`') continue;
        else throw std::domain_error("Neispravno ime i prezime.");
    }
    if(spratovi<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka.");
    Stan::adresa=adresa; Stan::spratovi=sprat; Stan::sobe=broj_soba; Stan::namjesten=namjesten; Stan::kvadrat=kvadratura;
}

void Stan::Ispisi() const {
   if(namjesten==true && (sobe==2 || sobe==3 || sobe==4)){
    std::cout<<"Stan se nalazi na adresi ";
    for(int i=0;i<adresa.length();i++) std::cout<<adresa[i]; 
    std::cout<<" na "<<spratovi<<". spratu i ima "<<sobe<<" sobe."
    <<"Kvadratura stana je "<<kvadrat<<" (m^2) i stan je namjesten.";
    return;
   }
   if(namjesten==false && (sobe==2 || sobe==3 || sobe==4)){
    std::cout<<"Stan se nalazi na adresi ";for(int i=0;i<adresa.length();i++) std::cout<<adresa[i];std::cout<<" na "<<spratovi<<". spratu i ima "<<sobe<<" sobe."
    <<"Kvadratura stana je "<<kvadrat<<" (m^2) i stan nije namjesten.";
    return;
   }
   if(namjesten==true && sobe==1){
    std::cout<<"Stan se nalazi na adresi ";for(int i=0;i<adresa.length();i++) std::cout<<adresa[i];std::cout<<" na "<<spratovi<<". spratu i ima "<<sobe<<" sobu."
    <<"Kvadratura stana je "<<kvadrat<<" (m^2) i stan je namjesten.";
    return;
   }
   if(namjesten==false && sobe==1){
    std::cout<<"Stan se nalazi na adresi ";for(int i=0;i<adresa.length();i++) std::cout<<adresa[i];std::cout<<" na "<<spratovi<<". spratu i ima "<<sobe<<" sobu."
    <<"Kvadratura stana je "<<kvadrat<<" (m^2) i stan nije namjesten.";
    return;
   }
   if(namjesten==true){
      std::cout<<"Stan se nalazi na adresi ";for(int i=0;i<adresa.length();i++) std::cout<<adresa[i];std::cout<<" na "<<spratovi<<". spratu i ima "<<sobe<<" soba."
    <<"Kvadratura stana je "<<kvadrat<<" (m^2) i stan je namjesten.";
    return; 
   }
   if(namjesten==false){
      std::cout<<"Stan se nalazi na adresi ";for(int i=0;i<adresa.length();i++) std::cout<<adresa[i];std::cout<<" na "<<spratovi<<". spratu i ima "<<sobe<<" soba."
    <<"Kvadratura stana je "<<kvadrat<<" (m^2) i stan nije namjesten.";
    return; 
   }
}

class Prodaja{
  std::string ime_agenta_prodaje;
  double cijena_stana;
  Datum datum_prodaje;
  Kupac kupac_stana;
  Stan kupljeni_stan;
  public:
  Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan);
  Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,std::string &ime_kupca,
  const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata);
  void PromijeniKupca(const Kupac &novi_kupac){
    kupac_stana=novi_kupac;   
  }
  void PromijeniStan(const Stan &novi_stan){
      kupljeni_stan=novi_stan;
  }
  void PromijeniDatumKupovine(const Datum &novi_datum){
      datum_prodaje=novi_datum;
  }
  void PromijeniCijenuProdaje(const double &nova_cijena){
      if(nova_cijena<0) throw std::domain_error("Neispravan unos podataka.");
      else cijena_stana=nova_cijena;
  }
  void PomjeriDanUnaprijed();
  void PomjeriDanUnazad();
  void PromijeniAgenta(const std::string &novi){
      for(int i=0;i<novi.length();i++){
        if ((novi[i]>='A' && novi[i]<='Z') || (novi[i]>='a' && novi[i]<='z') || (novi[i]>='0' && novi[i]<='9') || novi[i]=='-' || novi[i]==' ' || novi[i]=='`') continue;
        throw std::domain_error("Neispravno ime i prezime.");}
      Prodaja::ime_agenta_prodaje=novi;
  }
  std::string DajImeAgenta() const {
      return ime_agenta_prodaje;
  }
  std::string DajImeKupca() const {
      return kupac_stana.DajImePrezime();
  }
  Datum DajDatumProdaje() const {
      return datum_prodaje;
  }
  double DajCijenuStana() const {
      return cijena_stana;
  }
  friend bool ProdatPrije(const Prodaja &p1,const Prodaja &p2);
  friend bool SkupljiStan(const Prodaja &p1,const Prodaja &p2);
  void Ispisi() const;
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,
const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan) : datum_prodaje(datum_prodaje),
kupac_stana(kupac_stana),kupljeni_stan(kupljeni_stan){
    if(cijena_stana<0) throw std::domain_error("Neispravan unos podataka.");
    for(int i=0;i<ime_agenta_prodaje.length();i++){
        if ((ime_agenta_prodaje[i]>='A' && ime_agenta_prodaje[i]<='Z') || (ime_agenta_prodaje[i]>='a' && ime_agenta_prodaje[i]<='z') || (ime_agenta_prodaje[i]>='0' && ime_agenta_prodaje[i]<='9') || ime_agenta_prodaje[i]=='-' || ime_agenta_prodaje[i]==' ' || ime_agenta_prodaje[i]=='`') continue;
        throw std::domain_error("Neispravno ime i prezime.");
    }
    Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
    Prodaja::cijena_stana=cijena_stana;
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,
int dan_prodaje,int mjesec_prodaje,int godina_prodaje,std::string &ime_kupca,
const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,
int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata) : datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),
kupac_stana(ime_kupca,datum_rodjenja_kupca),kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)
    {
    if(cijena_stana<0) throw std::domain_error("Neispravan unos podataka.");
    for(int i=0;i<ime_agenta_prodaje.length();i++){
        if ((ime_agenta_prodaje[i]>='A' && ime_agenta_prodaje[i]<='Z') || (ime_agenta_prodaje[i]>='a' && ime_agenta_prodaje[i]<='z') || (ime_agenta_prodaje[i]>='0' && ime_agenta_prodaje[i]<='9') || ime_agenta_prodaje[i]=='-' || ime_agenta_prodaje[i]==' ' || ime_agenta_prodaje[i]=='`') continue;
        else throw std::domain_error("Neispravno ime i prezime.");
    }
    Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
    Prodaja::cijena_stana=cijena_stana;
}

void Prodaja::PomjeriDanUnaprijed() {
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((datum_prodaje.DajGodinu()%4==0 && datum_prodaje.DajGodinu()%100!=0) || datum_prodaje.DajGodinu()%400==0) broj_dana[1]++;
    int godina=datum_prodaje.DajGodinu();
    int mjesec=datum_prodaje.DajMjesec();
    int dan=datum_prodaje.DajDan();
    dan++;
    if(dan>broj_dana[mjesec-1]) {
        dan=1; mjesec++;
    }
    if(mjesec>12) {
        mjesec=1; godina++;
    }
    datum_prodaje.Postavi(dan,mjesec,godina);
}

void Prodaja::PomjeriDanUnazad() {
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((datum_prodaje.DajGodinu()%4==0 && datum_prodaje.DajGodinu()%100!=0) || datum_prodaje.DajGodinu()%400==0) broj_dana[1]++;
    int godina=datum_prodaje.DajGodinu();
    int mjesec=datum_prodaje.DajMjesec();
    int dan=datum_prodaje.DajDan();
    dan--;
    if(dan<1) {
        dan=broj_dana[mjesec-2]; mjesec--;
    }
    if(mjesec<1) {
        mjesec=12; godina--;
    }
    datum_prodaje.Postavi(dan,mjesec,godina);
}

bool ProdatPrije(const Prodaja &p1,const Prodaja &p2){
    Datum dat1=p1.DajDatumProdaje();
    Datum dat2=p2.DajDatumProdaje();
    if(dat1.DajGodinu()<dat2.DajGodinu()) return true;
    if(dat1.DajGodinu()==dat2.DajGodinu() && dat1.DajMjesec()<dat2.DajMjesec()) return true;
    if(dat1.DajGodinu()==dat2.DajGodinu() && dat1.DajMjesec()==dat2.DajMjesec() && dat1.DajDan()<dat2.DajDan()) return true;
    return false;
}

bool SkupljiStan(const Prodaja &p1,const Prodaja &p2){
    if (p1.DajCijenuStana()<p2.DajCijenuStana()) return true;
    return false;
}

void Prodaja::Ispisi() const {
    std::cout<<"Ime agenta:                                    "<<ime_agenta_prodaje<<std::endl;
    std::cout<<"Ime kupca:                                     ";kupac_stana.Ispisi();
    std::cout<<"Zakazani datum prodaje:                        ";datum_prodaje.Ispisi();std::cout<<std::endl;
    std::cout<<"Cijena stana:                                  "<<cijena_stana<<std::endl;
    std::cout<<"Informacije o stanu:"<<std::endl;kupljeni_stan.Ispisi();std::cout<<std::endl;
    
}

class Prodaje{
   const int kapacitet;
   int trenutni;
   Prodaja **sve;
   public:
   explicit Prodaje(int max_broj_prodaja);
   Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
   ~Prodaje();
   Prodaje(const Prodaje &prodaje);
   Prodaje(Prodaje &&prodaje);
   Prodaje &operator=(const Prodaje &prodaje);
   Prodaje &operator=(Prodaje &&prodaje);
   void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan);
   void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,
   int dan_prodaje,int mjesec_prodaje,int godina_prodaje,std::string &ime_kupca,
   const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,
   int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata);
   void RegistrirajProdaju(Prodaja *prodaja);
   int DajBrojProdaja() const;
   int DajBrojProdajaNaDatum(const Datum &datum) const;
   int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
   Prodaja &DajNajranijuProdaju();
   Prodaja DajNajranijuProdaju() const ;
   Prodaja &DajNajskupljuProdaju();
   Prodaja DajNajskupljuProdaju() const ;
   Prodaja &DajProdaju(int redni_broj_prodaje);
   void IsprazniKolekciju();
   void ObrisiNajranijuProdaju();
   void ObrisiProdajeAgenta(const std::string &ime_agenta);
   void ObrisiProdajeNaDatum(const Datum &datum);
   void IspisiProdajeNaDatum(const Datum &datum) const;
   void IspisiSveProdaje() const;
   

};

Prodaje::~Prodaje(){
    for(int i=0;i<kapacitet;i++){
        delete sve[i];
    }
    delete[] sve;
}

Prodaje::Prodaje(int max_broj_prodaja) : kapacitet(max_broj_prodaja), trenutni(0), sve(new Prodaja*[max_broj_prodaja]{}) {
}

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : kapacitet(spisak_prodaja.size()),trenutni(spisak_prodaja.size()){
    sve=new Prodaja*[spisak_prodaja.size()]{};
    int brojac(0);
    try{
    for(auto x : spisak_prodaja) sve[brojac]=new Prodaja(x);	
    }
    catch(...){
    	throw;
    }
}
Prodaje::Prodaje(const Prodaje &prodaje) : kapacitet(prodaje.kapacitet),trenutni(prodaje.trenutni){
    sve=new Prodaja*[prodaje.kapacitet]{};
    try{
        for(int i=0;i<prodaje.trenutni;i++){
            sve[i]=new Prodaja(*prodaje.sve[i]);
        }
    }
    catch(...){
        for(int i=0;i<trenutni;i++) delete sve[i];
        delete[] sve; throw;
    }
}

Prodaje::Prodaje(Prodaje &&prodaje) : kapacitet(prodaje.kapacitet),trenutni(prodaje.trenutni),sve(prodaje.sve){
    prodaje.sve=nullptr; prodaje.trenutni=0;
}

Prodaje &Prodaje::operator=(const Prodaje &prodaje){
    if(prodaje.kapacitet!=kapacitet) throw std::logic_error("Nesaglasan broj prodaja");
    if(prodaje.trenutni>trenutni){
        try{
            for(int i=trenutni;i<prodaje.trenutni;i++){
                sve[i]=new Prodaja(*prodaje.sve[i]);
            }
        }
        catch(...){
            for(int i=trenutni;i<prodaje.trenutni;i++){
                delete sve[i]; sve[i]=nullptr;
            }
            throw;
        }
    }
    else {
        for(int i=prodaje.trenutni;i<trenutni;i++){
            delete sve[i]; sve[i]=nullptr;
        }
    }
    trenutni=prodaje.trenutni;
    for(int i=0;i<trenutni;i++){
        *sve[i]=*prodaje.sve[i];
    }
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje){
    if(prodaje.kapacitet!=kapacitet) throw std::logic_error("Nesaglasan broj prodaja");
    std::swap(trenutni,prodaje.trenutni);
    std::swap(sve,prodaje.sve);
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,
const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan){
    if(trenutni==kapacitet) throw std::range_error("Dostignut maksimalni broj prodaja");
        Prodaja *prodaja(nullptr);
        try{
        prodaja=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
        RegistrirajProdaju(prodaja);
        }
        catch(...){
            delete prodaja; prodaja=nullptr;
            throw;
        }

}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,
   int dan_prodaje,int mjesec_prodaje,int godina_prodaje,std::string &ime_kupca,
   const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,
   int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata){
    if(trenutni==kapacitet) throw std::range_error("Dostignut maksimalni broj prodaja");
    Prodaja *prodaja(nullptr);
    try{
        prodaja=new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,
        datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
        RegistrirajProdaju(prodaja);
    }
    catch(...){
        delete prodaja; prodaja=nullptr; throw;
    }
   }

void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(trenutni==kapacitet) throw std::range_error("Dostignut maksimalni broj prodaja");
    sve[trenutni]=prodaja;
    trenutni++;
}

int Prodaje::DajBrojProdaja() const {
    return trenutni;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    int brojac=std::count_if(sve,sve+trenutni,[datum] (const Prodaja *prodaja){
        Datum dat=prodaja->DajDatumProdaje();
        if (datum.DajGodinu()==dat.DajGodinu() && datum.DajMjesec()==dat.DajMjesec() && datum.DajDan()== dat.DajDan()) return true;
        return false;
    }
    );
    return brojac;
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
	int brojac=std::count_if(sve,sve+trenutni,[ime_agenta] (const Prodaja *prodaja){
        std::string ime=prodaja->DajImeAgenta();
        if (ime==ime_agenta) return true;
        return false;
    }
    );
    return brojac;
}

Prodaja &Prodaje::DajNajranijuProdaju() {
   if(trenutni==0) throw std::domain_error("Nema registriranih prodaja");
     auto pok=std::min_element(sve,sve+trenutni,[] (Prodaja *prodaja1,Prodaja *prodaja2){
    Datum dat1=prodaja1->DajDatumProdaje();
    Datum dat2=prodaja2->DajDatumProdaje(); 
    if(dat1.DajGodinu()<dat2.DajGodinu()) return true;
    if(dat1.DajGodinu()==dat2.DajGodinu() && dat1.DajMjesec()<dat2.DajMjesec()) return true;
    if(dat1.DajGodinu()==dat2.DajGodinu() && dat1.DajMjesec()==dat2.DajMjesec() && dat1.DajDan()<dat2.DajDan()) return true;
    return false; });
    return *(*pok);
}

Prodaja Prodaje::DajNajranijuProdaju() const {
   if(trenutni==0) throw std::domain_error("Nema registriranih prodaja");
    auto pok=std::min_element(sve,sve+trenutni,[] (Prodaja *prodaja1,Prodaja *prodaja2){
    Datum dat1=prodaja1->DajDatumProdaje();
    Datum dat2=prodaja2->DajDatumProdaje(); 
    if(dat1.DajGodinu()<dat2.DajGodinu()) return true;
    if(dat1.DajGodinu()==dat2.DajGodinu() && dat1.DajMjesec()<dat2.DajMjesec()) return true;
    if(dat1.DajGodinu()==dat2.DajGodinu() && dat1.DajMjesec()==dat2.DajMjesec() && dat1.DajDan()<dat2.DajDan()) return true;
    return false; });
    return **pok;
}

Prodaja &Prodaje::DajNajskupljuProdaju(){
   if(trenutni==0) throw std::domain_error("Nema registriranih prodaja");
    auto pok=std::max_element(sve,sve+trenutni,[] (const Prodaja *prodaja1,const Prodaja *prodaja2) {
        return prodaja1->DajCijenuStana()>prodaja2->DajCijenuStana();
    });
    return *(*pok);
}

Prodaja Prodaje::DajNajskupljuProdaju() const {
    if(trenutni==0) throw std::domain_error("Nema registriranih prodaja");
    auto pok=std::max_element(sve,sve+trenutni,[] (const Prodaja *prodaja1,const Prodaja *prodaja2) {
        return prodaja1->DajCijenuStana()>prodaja2->DajCijenuStana();
    });
    return *(*pok);
}

Prodaja &Prodaje::DajProdaju(int redni_broj_prodaje) {
    if(redni_broj_prodaje<1 || redni_broj_prodaje>trenutni) throw std::logic_error("Neispravan redni broj prodaje");
    if(trenutni==0) throw std::domain_error("Nema registriranih prodaja");
    return *(sve[redni_broj_prodaje-1]);
}

void Prodaje::IsprazniKolekciju(){
    for(int i=0;i<trenutni;i++){
        delete sve[i]; sve[i]=nullptr;
    }
}

void Prodaje::ObrisiNajranijuProdaju(){
    if(trenutni==0) throw std::range_error("Prazna kolekcija");
    auto nova=DajNajranijuProdaju();
    auto dat2=nova.DajDatumProdaje();
    for(int i=0;i<trenutni;i++){
        auto dat1=sve[i]->DajDatumProdaje();
        if(dat1.DajGodinu()==dat2.DajGodinu() && dat1.DajMjesec()==dat2.DajMjesec() && dat1.DajDan()==dat2.DajDan()) {
            delete sve[i]; sve[i]=nullptr;
            
        }
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    for(int i=0;i<trenutni;i++){
        Datum dat=sve[i]->DajDatumProdaje();
        if(dat.DajGodinu()==datum.DajGodinu() && dat.DajMjesec()==datum.DajMjesec() && dat.DajDan()==datum.DajDan()){
            delete sve[i]; sve[i]=nullptr;
        }
    }
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    for(int i=0;i<trenutni;i++){
        if(sve[i]->DajImeAgenta()==ime_agenta){
            delete sve[i]; sve[i]=nullptr;
        }
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    for(int i=0;i<trenutni;i++){
       Datum dat=sve[i]->DajDatumProdaje();
       if(dat.DajGodinu()==datum.DajGodinu() && dat.DajMjesec()==datum.DajMjesec() && dat.DajDan()==datum.DajDan()){
           sve[i]->Ispisi();
       }
    }
}

void Prodaje::IspisiSveProdaje() const {
    for(int i=0;i<trenutni;i++){
        sve[i]->Ispisi();
    }
}


int main ()
{
	std::cout<<"Dobrodosli!"<<std::endl<<std::endl<<std::endl;
	std::vector<Stan> stanovi; std::vector<Kupac> kupci; Prodaje prodaje(20);
	int opcija_pocetni,opcija_stan,opcija_kupac,opcija_prodaja;
	  for(;;) {
	  	std::cout<<"Izaberite opciju:"<<std::endl
	    <<" 0 - kraj"<<std::endl
	    <<" 1 - uredjivanje stanova"<<std::endl
	    <<" 2 - uredjivanje kupaca"<<std::endl
	    <<" 3 - uredjivanje prodaja"<<std::endl;
	    std::cin>>opcija_pocetni;
	    if(opcija_pocetni==0) {std::cout<<std::endl<<std::endl; return 0;}
	    if(opcija_pocetni==1){
	    for(;;){
	    	std::cout<<"Izaberite opciju:"<<std::endl
	    <<" 0 - nazad"<<std::endl
	    <<" 1 - dodavanje stana"<<std::endl
	    <<" 2 - uredjivanje stanova"<<std::endl
	    <<" 3 - ispis svih stanova"<<std::endl
	    <<" 4 - kraj"<<std::endl;
	    std::cin>>opcija_stan;
	    if(opcija_stan==1){
	      for(;;){
	      	std::string adresa;
	      int sprat,broj_soba;
	      double kvadratura;
	      bool namjesten;
	      int jel;
	      std::cout<<"Unesite adresu: ";std::cin.ignore(1000,'\n'); std::getline(std::cin,adresa); std::cout<<"Unesite sprat: ";
	      std::cin>>sprat; std::cout<<"Unesite broj soba: "; std::cin>>broj_soba;
	      std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): "; std::cin>>jel;
	      std::cout<<"Unesite kvadraturu: "; std::cin>>kvadratura;
	      if(jel!=1 && jel!=0) {std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl; goto label1;}
	      if(jel==1) namjesten=true; if(jel==0) namjesten=false;
	      try{
	        Stan stan(adresa,sprat,broj_soba,namjesten,kvadratura);
	        stanovi.push_back(stan);
	        std::cout<<"Stan je uspjesno dodan!"<<std::endl<<std::endl; break;
	        
	      }
	      catch(std::domain_error e){
	          std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
	      }
	      label1: ;
	      }
	      
	    }
	    if(opcija_stan==2){
	      for(;;){
	      	int i; 
	      	std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
	      for(int j=0;j<stanovi.size();j++){
	           std::cout<<" "<<j+1<<" - ";
	           stanovi[j].Ispisi(); std::cout<<std::endl;
	       }
	       std::cin>>i; i--;
	       std::cout<<"Odaberite polje koje zelite urediti:"<<std::endl
	       <<" 0 - nazad"<<std::endl
	       <<" 1 - adresa"<<std::endl
	       <<" 2 - sprat"<<std::endl
	       <<" 3 - broj soba"<<std::endl
	       <<" 4 - da li je stan namjesten"<<std::endl
	       <<" 5 - kvadratura"<<std::endl
	       <<" 6 - sve"<<std::endl;
	       int polje; std::cin>>polje;
	       if(polje==0) break;
	       if(polje==1){
	       for(;;) {   std::string adresa;
	           std::cin.ignore(1000,'\n');std::cout<<"Unesite adresu: ";
	           std::getline(std::cin,adresa); 
	        int sprat=stanovi[i].DajSprat(); int broj_soba=stanovi[i].DajBrojSoba();
	      double kvadratura=stanovi[i].DajKvadraturu();
	      bool namjesten=stanovi[i].DajNamjesten();
	      try{
	          stanovi[i].Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
	          std::cout<<"Stan je uspjesno izmijenjen"<<std::endl<<std::endl; break;
	      }
	      catch(std::domain_error e){
	          std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
	      }
	       }
	       break;
	       }
	       if(polje==2){
	        for(;;){  int sprat;
	          std::cout<<"Unesite sprat: "; 
	          std::cin>>sprat;
	             std::string adresa=stanovi[i].DajAdresu();
	      int broj_soba=stanovi[i].DajBrojSoba();
	      double kvadratura=stanovi[i].DajKvadraturu();
	      bool namjesten=stanovi[i].DajNamjesten();
	      try{
	          stanovi[i].Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
	          std::cout<<"Stan je uspjesno izmijenjen"<<std::endl<<std::endl; break;
	      }
	      catch(std::domain_error e){
	          std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
	      }
	       }
	       break;
	       }
	       if(polje==3){
	         for(;;){  int broj_soba;
	           std::cout<<"Unesite broj soba: ";
	           std::cin>>broj_soba;
	              std::string adresa=stanovi[i].DajAdresu();
	        int sprat=stanovi[i].DajSprat();
	      double kvadratura=stanovi[i].DajKvadraturu();
	      bool namjesten=stanovi[i].DajNamjesten();
	      try{
	          stanovi[i].Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
	          std::cout<<"Stan je uspjesno izmijenjen"<<std::endl<<std::endl; break; 
	      }
	      catch(std::domain_error e){
	          std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl; 
	      }
	       }
	       break;
	       }
	       if(polje==4){
	       for(;;){    int jel;
	           std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
	           std::cin>>jel;
	              std::string adresa=stanovi[i].DajAdresu();
	              int broj_soba=stanovi[i].DajBrojSoba();
	        int sprat=stanovi[i].DajSprat();
	      double kvadratura=stanovi[i].DajKvadraturu();
	      bool namjesten; if(jel==1) namjesten=true; else namjesten=false;if(jel!=1 && jel!=0) {std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl; goto label4;}
	      try{
	          stanovi[i].Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
	          std::cout<<"Stan je uspjesno izmijenjen"<<std::endl<<std::endl; break;
	      }
	      catch(std::domain_error e){
	          std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
	      }
	      label4: ;
	       }
	       break;
	       }
	       if(polje==5){
	       for(;;){    double kvadratura;
	           std::cout<<"Unesite kvadraturu: ";
	           std::cin>>kvadratura;
	           int broj_soba=stanovi[i].DajBrojSoba();
	              std::string adresa=stanovi[i].DajAdresu();
	        int sprat=stanovi[i].DajSprat();
	      bool namjesten=stanovi[i].DajNamjesten();
	      try{
	          stanovi[i].Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
	          std::cout<<"Stan je uspjesno izmijenjen"<<std::endl<<std::endl; break;
	      }
	      catch(std::domain_error e){
	          std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
	      }
	       }
	       break;
	       }
	       if(polje==6){
	     for(;;){  std::string adresa;
	      int sprat,broj_soba;
	      double kvadratura;
	      bool namjesten;
	      int jel;
	      std::cin.ignore(1000,'\n');std::cout<<"Unesite adresu: "; std::getline(std::cin,adresa); 
	      std::cout<<"Unesite sprat: ";
	      std::cin>>sprat; std::cout<<"Unesite broj soba: "; std::cin>>broj_soba;
	      std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): "; std::cin>>jel; if(jel==1) namjesten=true; if(jel==0) namjesten=false;if(jel!=1 && jel!=0) {std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl; goto label5;}
	      std::cout<<"Unesite kvadraturu: "; std::cin>>kvadratura;
	      try{
	        stanovi[i].Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
	        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl; break;
	        
	      }
	      catch(std::domain_error e){
	          std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl; 
	      }
	      label5: ;
	   
	       }
	       break;
	       }
	      }
	       
	    }
	    if(opcija_stan==3){
	       for(int i=0;i<stanovi.size();i++){
	           std::cout<<i+1<<". ";
	           stanovi[i].Ispisi(); std::cout<<std::endl;
	       } 
	    }
	    if(opcija_stan==4){
	        std::cout<<std::endl<<std::endl<<std::endl<<"Dovidjenja!"; return 0;
	    }
	    if(opcija_stan==0) break;
	    }
	    }
	    if(opcija_pocetni==2){
	     for(;;) {  std::cout<<"Izaberite opciju:"<<std::endl
	    <<" 0 - nazad"<<std::endl
	    <<" 1 - dodavanje kupca"<<std::endl
	    <<" 2 - uredjivanje kupaca"<<std::endl
	    <<" 3 - ispis svih kupaca"<<std::endl
	    <<" 4 - kraj"<<std::endl;
	    std::cin>>opcija_kupac;
	    if(opcija_kupac==4) {std::cout<<std::endl<<std::endl<<std::endl<<"Dovidjenja!"; return 0;}
	    if(opcija_kupac==0) break;
	    if(opcija_kupac==3){
	        for(int i=0;i<kupci.size();i++){
	            kupci[i].Ispisi(); std::cout<<std::endl;
	        }
	    }
	    if(opcija_kupac==1){
	    for(;;){    std::string ime_kupca; int dan,mjesec,godina;
	        std::cin.ignore(1000,'\n'); std::cout<<"Unesite ime i prezime kupca: ";
	        std::getline(std::cin,ime_kupca);
	        std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
	   
	        std::cin>>dan;  std::cin.ignore(2,'/');std::cin>>mjesec; std::cin.ignore(2,'/');std::cin>>godina;
	        try{
	            Datum dat(dan,mjesec,godina);
	            Kupac kupac(ime_kupca,dat);
	            kupci.push_back(kupac);
	            std::cout<<"Kupac je uspjesno dodan!"<<std::endl<<std::endl; break;
	        }
	        catch(std::domain_error e){
	            std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
	        }
	    }
	    }
	    if(opcija_kupac==2){
	       for(;;){ std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<std::endl;
	        for(int i=0;i<kupci.size();i++){
	            std::cout<<" "<<i+1<<" - ";
	            kupci[i].Ispisi();
	        }
	        int i; std::cin>>i;
	        std::string ime_kupca; int dan,mjesec,godina;
	        std::cin.ignore(1000,'\n');std::cout<<"Unesite ime i prezime kupca: ";
	        std::getline(std::cin,ime_kupca); 
	        std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
	        std::cin>>dan;  std::cin.ignore(2,'/');std::cin>>mjesec; std::cin.ignore(2,'/');std::cin>>godina;
	        try{
	            Datum dat(dan,mjesec,godina);
	            Kupac kupac(ime_kupca,dat);
	            kupci[i-1]=kupac;
	            std::cout<<"Kupac je uspjesno izmijenjen!"<<std::endl<<std::endl; break;
	        }
	        catch(std::domain_error e){
	            std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
	        }
	    }
	    }
	    }
	    }
	    if(opcija_pocetni==3){
	    for(;;){    std::cout<<"Izaberite opciju:"<<std::endl
	    <<" 0 - nazad"<<std::endl
	    <<" 1 - dodavanje prodaje"<<std::endl
	    <<" 2 - uredjivanje prodaje"<<std::endl
	    <<" 3 - ispis prodaja"<<std::endl
        <<" 4 - brisanje prodaja"<<std::endl
	    <<" 5 - kraj"<<std::endl;
	    std::cin>>opcija_prodaja;
	    if(opcija_prodaja==0) break;
	    if(opcija_prodaja==4) {std::cout<<std::endl<<std::endl<<std::endl<<"Dovidjenja!"; return 0;}
	    if(opcija_prodaja==1){
	     for(;;){ int n;
	        std::cout<<"Izaberite opciju:"<<std::endl
	    <<" 0 - nazad"<<std::endl
	    <<" 1 - dodavanje potpuno nove prodaje"<<std::endl
	    <<" 2 - dodavanje nove prodaje na osnovu arhive"<<std::endl
	    <<" 3 - kraj"<<std::endl;
	    std::cin>>n;
	    if(n==0) break;
	    if(n==3) {std::cout<<std::endl<<std::endl<<std::endl<<"Dovidjenja!"; return 0;}
	    if(n==1){
	     for(;;){   std::string ime_agenta_prodaje,ime_kupca,adresa; int dan_prodaje,mjesec_prodaje,godina_prodaje,dan,mjesec,godina;
	        double cijena_stana,kvadratura; int sprat,broj_soba,jel; bool namjesten;
	         std::cin.ignore(1000,'\n');std::cout<<"Unesite ime i prezime agenta prodaje: "; std::getline(std::cin,ime_agenta_prodaje);
	        std::cout<<"Unesite datum prodaje (formata d/m/g): "; std::cin>>dan_prodaje;  std::cin.ignore(2,'/');std::cin>>mjesec_prodaje; std::cin.ignore(2,'/');std::cin>>godina_prodaje;
	        std::cout<<"Unesite cijenu stana: "; std::cin>>cijena_stana;
	        std::cin.ignore(1000,'\n');std::cout<<"Unesite ime kupca: "; std::getline(std::cin,ime_kupca);
	        std::cout<<"Unesite datum rodjenja kupca (formata d/m/g): "; std::cin>>dan;  std::cin.ignore(2,'/');std::cin>>mjesec; std::cin.ignore(2,'/');std::cin>>godina;
	        std::cin.ignore(1000,'\n');std::cout<<"Unesite adresu: "; std::getline(std::cin,adresa); std::cout<<"Unesite sprat: ";
	      std::cin>>sprat; std::cout<<"Unesite broj soba: "; std::cin>>broj_soba;
	      std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): "; std::cin>>jel; if(jel==1) namjesten=true; if(jel==0) namjesten=false;if(jel!=1 && jel!=0) {std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl; goto label2;}
	      std::cout<<"Unesite kvadraturu: "; std::cin>>kvadratura;
	      try{
	          Datum datum_rodjenja_kupca(dan,mjesec,godina);
	          Kupac kupac(ime_kupca,datum_rodjenja_kupca);
	          kupci.push_back(kupac);
	          Stan stan(adresa,sprat,broj_soba,namjesten,kvadratura);
	          stanovi.push_back(stan);
	          prodaje.RegistrirajProdaju(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,
            datum_rodjenja_kupca,adresa,sprat,broj_soba,namjesten,kvadratura);
            std::cout<<"Prodaja uspjesno dodana!"<<std::endl<<std::endl; break; 
	      }
	      catch(std::domain_error e){
	          std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet.";
	      }
	      label2: ;
	    }  
	    }
	    if(n==2){
	    for(;;){  std::string ime_agenta_prodaje; double cijena_stana; int dan_prodaje,mjesec_prodaje,godina_prodaje;
	      std::cin.ignore(1000,'\n');std::cout<<"Unesite ime i prezime agenta prodaje: "; std::getline(std::cin,ime_agenta_prodaje); 
	        std::cout<<"Unesite datum prodaje (formata d/m/g): "; std::cin>>dan_prodaje;  std::cin.ignore(2,'/');std::cin>>mjesec_prodaje; std::cin.ignore(2,'/');std::cin>>godina_prodaje;
	        std::cout<<"Unesite cijenu stana: "; std::cin>>cijena_stana;
	 
	        int n,m;
	        std::cout<<"Odaberite kupca. Dostupni kupci su:"<<std::endl;
	        for(int i=0;i<kupci.size();i++){
	            std::cout<<" "<<i+1<<" - ";
	            kupci[i].Ispisi();
	        }
	        std::cin>>n; n--;
	        std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
	      for(int i=0;i<stanovi.size();i++){
	           std::cout<<" "<<i+1<<" - ";
	           stanovi[i].Ispisi(); std::cout<<std::endl;
	       }
	       std::cin>>m; m--;
	       try{
	         Datum dat(dan_prodaje,mjesec_prodaje,godina_prodaje);
	         prodaje.RegistrirajProdaju(ime_agenta_prodaje,cijena_stana,dat,kupci[n],stanovi[m]);  
	         std::cout<<"Prodaja uspjeno dodana!"<<std::endl<<std::endl; break;
	       }
	       catch(std::domain_error e){
	          std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl; 
	      }
	    } 
	    }
	    }
	    }
	    if(opcija_prodaja==2){
		  int i;
	      std::cout<<"Odaberite prodaju koju zelite urediti. Dostupne prodaje su:"<<std::endl;
	      prodaje.IspisiSveProdaje();
	      std::cin>>i;
	       int izmjenaprodaje;
	      std::cout<<"Izaberite opciju:"<<std::endl
	    <<" 0 - nazad"<<std::endl
	    <<" 1 - izmjena agenta"<<std::endl
	    <<" 2 - izmjena datuma prodaje"<<std::endl
	    <<" 3 - izmjena kupca"<<std::endl
        <<" 4 - izmjena stana"<<std::endl
	    <<" 5 - izmjena cijene stana"<<std::endl
	    <<" 6 - kraj"<<std::endl;
	      std::cin>>izmjenaprodaje;
	      if(izmjenaprodaje==0) break;
	      if(izmjenaprodaje==6) {std::cout<<std::endl<<std::endl<<std::endl<<"Dovidjenja!"; return 0;}
	      if(izmjenaprodaje==1){
	      for(;;){    std::string noviagent;
	          std::cin.ignore(1000,'\n');std::cout<<"Unesite ime i prezime agenta prodaje: ";
	          std::getline(std::cin,noviagent); 
	          try{
	              
	              auto prodaja=prodaje.DajProdaju(i);
	              prodaja.PromijeniAgenta(noviagent);
	              std::cout<<"Prodaja je uspijesno izmijenjena!"<<std::endl<<std::endl; break;
	          }
	          catch(std::domain_error e){
	              std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
	          }
	      } 
	      }
	      if(izmjenaprodaje==2){
	      for(;;){    int dan,mjesec,godina;
	          std::cout<<"Unesite datum prodaje (formata d/m/g): ";
	          std::cin>>dan;  std::cin.ignore(2,'/');std::cin>>mjesec; std::cin.ignore(2,'/');std::cin>>godina;
	          try{
	          Datum dat(dan,mjesec,godina);
	          auto prodaja=prodaje.DajProdaju(i);
	          
	            prodaja.PromijeniDatumKupovine(dat); 
	            std::cout<<"Prodaja je uspijesno izmijenjena!"<<std::endl<<std::endl; break;
	          }
	          catch(std::domain_error e){
	              std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl; 
	          }
	      }
	      }
	       if(izmjenaprodaje==3){
	      for(;;){   int x;
	          std::cout<<"Izaberite opciju:"<<std::endl
	          <<" 0 - nazad"<<std::endl
	    <<" 1 - odabir postojeceg kupca"<<std::endl
	    <<" 2 - dodavanje novog kupca"<<std::endl;
	    std::cin>>x;
	    if(x==0) break;
	    if(x==1) {
	        int n;
	        std::cout<<"Odaberite kupca. Dostupni kupci su:"<<std::endl;
	        for(int i=0;i<kupci.size();i++){
	            std::cout<<" "<<i+1<<" - ";
	            kupci[i].Ispisi(); std::cout<<std::endl;
	        }
	        std::cin>>n; n--;
	        auto prodaja=prodaje.DajProdaju(i);
	        prodaja.PromijeniKupca(kupci[n]);
	        std::cout<<"Prodaja je uspijesno izmijenjena!"<<std::endl<<std::endl; break;
	    }
	    if(x==2){
	      for(;;){  std::string ime_kupca; int dan,mjesec,godina;
	        std::cin.ignore(1000,'\n');std::cout<<"Unesite ime i prezime kupca: ";
	        std::getline(std::cin,ime_kupca);
	        std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
	        std::cin>>dan;  std::cin.ignore(2,'/');std::cin>>mjesec; std::cin.ignore(2,'/');std::cin>>godina;
	        try{
	            Datum dat(dan,mjesec,godina);
	            Kupac kupac(ime_kupca,dat);
	            auto prodaja=prodaje.DajProdaju(i);
	            prodaja.PromijeniKupca(kupac);
	            std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl; break;
	        }
	        catch(std::domain_error e){
	            std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl; 
	        }
	    }
	    }
	       }
	      }
	      if(izmjenaprodaje==4){
	     for(;;){     int x;
	          std::cout<<"Izaberite opciju:"<<std::endl
	          <<" 0 - nazad"<<std::endl
	    <<" 1 - odabir postojeceg stana"<<std::endl
	    <<" 2 - dodavanje novog stana"<<std::endl;
	    std::cin>>x;
	    if(x==0) break;
	    if(x==1){
	       int n;
	        std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
	      for(int i=0;i<stanovi.size();i++){
	           std::cout<<" "<<i+1<<" - ";
	           stanovi[i].Ispisi(); std::cout<<std::endl;
	       }
	       std::cin>>n; n--;
	       auto prodaja=prodaje.DajProdaju(i);
	       prodaja.PromijeniStan(stanovi[n]); std::cout<<"Prodaja uspijesno izmijenjena!"<<std::endl<<std::endl; break;
	    }
	    if(x==2){
	     for(;;){   std::string adresa;
	      int sprat,broj_soba;
	      double kvadratura;
	      bool namjesten;
	      int jel;
	      std::cin.ignore(1000,'\n');std::cout<<"Unesite adresu: "; std::getline(std::cin,adresa); std::cout<<"Unesite sprat: ";
	      std::cin>>sprat; std::cout<<"Unesite broj soba: "; std::cin>>broj_soba;
	      std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): "; std::cin>>jel; if(jel==1) namjesten=true; if(jel==0) namjesten=false;if(jel!=1 && jel!=0) {std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl; goto label3;}
	      std::cout<<"Unesite kvadraturu: "; std::cin>>kvadratura;
	      try{
	        Stan stan(adresa,sprat,broj_soba,namjesten,kvadratura);
	        auto prodaja=prodaje.DajProdaju(i);
	        prodaja.PromijeniStan(stan);
	        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl; break;
	        
	      }
	      catch(std::domain_error e){
	          std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
	      }
	      label3: ;
	    }
	    }
	      }
	      }
	      if(izmjenaprodaje==5){
	       for(;;){   double nova;
	          std::cout<<"Unesite cijenu stana:";
	          std::cin>>nova;
	          try{
	              auto prodaja=prodaje.DajProdaju(i);
	              prodaja.PromijeniCijenuProdaje(nova);
	              std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl; break;
	          }
	          catch(std::domain_error e){
	              std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet.";
	          }
	      }
	      }
	    
	    }
	   if(opcija_prodaja==3){
	    for(;;){    int ops;
	        std::cout<<"Izaberite opciju:"<<std::endl
	    <<" 0 - nazad"<<std::endl
	    <<" 1 - ispis svih prodaja"<<std::endl
	    <<" 2 - ispis prodaja na datum"<<std::endl
	    <<" 3 - ispis najranije prodaje"<<std::endl
        <<" 4 - ispis najskuplje prodaje"<<std::endl
	    <<" 5 - ispis broja prodaja"<<std::endl
	    <<" 6 - ispis broja prodaja po datumu"<<std::endl
	    <<" 7 - ispis broja prodaja po agentu"<<std::endl
	    <<" 8 - kraj"<<std::endl;
	    std::cin>>ops;
	    if(ops==0) break;
	    if(ops==8) {std::cout<<std::endl<<std::endl<<std::endl<<"Dovidjenja!"; return 0;}
	    if(ops==1){
	        prodaje.IspisiSveProdaje(); 
	    }
	    if(ops==2){
	        int dan,mjesec,godina;
	        std::cout<<"Unesite datum (d/m/g):";
	        std::cin>>dan;  std::cin.ignore(2,'/');std::cin>>mjesec; std::cin.ignore(2,'/');std::cin>>godina;
	        Datum dat(dan,mjesec,godina);
	        std::cout<<"Prodaje na datum "; dat.Ispisi(); std::cout<<" su:";
	        prodaje.IspisiProdajeNaDatum(dat);std::cout<<std::endl;
	    }
	    if(ops==3){
	        auto prodaja=prodaje.DajNajranijuProdaju();
	        prodaja.Ispisi(); 
	    }
	    if(ops==4){
	       auto prodaja=prodaje.DajNajskupljuProdaju();
	       prodaja.Ispisi(); 
	    }
	    if(ops==5){
	        int br=prodaje.DajBrojProdaja();
	        std::cout<<"Broj prodaja: "<<br<<std::endl<<std::endl; break; 
	    }
	    if(ops==6){
	        int dan,mjesec,godina;
	        std::cout<<"Unesite datum (d/m/g): ";
	        std::cin>>dan;  std::cin.ignore(2,'/');std::cin>>mjesec; std::cin.ignore(2,'/');std::cin>>godina;
	        Datum dat(dan,mjesec,godina);
	        
	        
	        std::cout<<"Broj prodaja na uneseni datum: "<<prodaje.DajBrojProdajaNaDatum(dat)<<std::endl<<std::endl; break; 
	    }
	    if(ops==7){
	        std::string novi;
	        std::cin.ignore(1000,'\n');std::cout<<"Unesite ime agenta: ";
	        std::getline(std::cin,novi); 
	        std::cout<<"Broj prodaja unesenog agenta: "<<prodaje.DajBrojProdajaOdAgenta(novi)<<std::endl<<std::endl; break; 
	    }
	   }
	    
	    }
	    if(opcija_prodaja==4){
	    for(;;){  int brisanje;
	       std::cout<<"Izaberite opciju:"<<std::endl
	    <<" 0 - nazad"<<std::endl
	    <<" 1 - brisanje najranije prodaje"<<std::endl
	    <<" 2 - brisanje prodaja agenta"<<std::endl
	    <<" 3 - brisanje prodaja po datumu"<<std::endl
        <<" 4 - brisanje svih prodaja"<<std::endl;
        std::cin>>brisanje;
        if(brisanje==0) break;
        if(brisanje==1){
            prodaje.ObrisiNajranijuProdaju(); std::cout<<"Najranija prodaja je obrisana!"<<std::endl<<std::endl; break;
        }
        if(brisanje==2){
            std::string agent;
           std::cin.ignore(1000,'\n'); std::cout<<"Unesite ime agenta: ";
	        std::getline(std::cin,agent); 
	        prodaje.ObrisiProdajeAgenta(agent); std::cout<<"Sve prodaje tog agenta su obrisane."<<std::endl<<std::endl; break;
        }
        if(brisanje==3){
            int dan,mjesec,godina;
            std::cout<<"Unesite datum: ";
	        std::cin>>dan;  std::cin.ignore(2,'/');std::cin>>mjesec; std::cin.ignore(2,'/');std::cin>>godina;
	        Datum dat(dan,mjesec,godina); prodaje.ObrisiProdajeNaDatum(dat); std::cout<<"Sve prodaje na taj datum su obrisane."<<std::endl<<std::endl; break;
        }
        if(brisanje==4){
            prodaje.IsprazniKolekciju(); std::cout<<"Sve su obrisane."<<std::endl<<std::endl; break;
        }
	    }
	    }
	    }
	    }
	  }
	
	return 0;
}