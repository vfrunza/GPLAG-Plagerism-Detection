/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <algorithm>

class Datum {
    int dan, mjesec, godina; 
    
    public: 
    
    Datum (int dan, int mjesec, int godina);
    void Postavi (int dan, int mjesec, int godina); 
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const { std::cout << dan << "/" << mjesec << "/" << godina; }
}; 

Datum::Datum (int dan, int mjesec, int godina) {
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31}; 
    if (godina%4==0 && godina%10!=0 && godina%400==0) broj_dana[1]++; 
    if (dan<1 || mjesec<1 || godina<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error ("Neispravan datum"); 
    Datum::dan=dan; 
    Datum::mjesec=mjesec;
    Datum::godina=godina; 
}

void Datum::Postavi (int dan, int mjesec, int godina) {
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31}; 
    if (dan<1 || mjesec<1 || godina<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error ("Neispravan datum"); 
    Datum::dan=dan; 
    Datum::mjesec=mjesec;
    Datum::godina=godina; 
}

class Kupac {
    
    Datum datum; 
    std::string ime_i_prezime; 
    public: 
    
    Kupac (const std::string &ime_i_prezime, const Datum &datum_rodjenja); 
    void Postavi (const std::string &ime_i_prezime, const Datum &datum_rodjenja); 
    std::string DajImePrezime() const { return ime_i_prezime; } 
    Datum DajDatumRodjena() const { return datum; } 
    void Ispisi() const { std::cout << ime_i_prezime;
    std::cout << "(" << datum.DajDan() << "/" << datum.DajMjesec() << "/" << datum.DajGodinu() << ")"; }
}; 

Kupac::Kupac (const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datum(datum_rodjenja) {
    for (int i=0; i<ime_i_prezime.size(); i++) {
    if (ime_i_prezime[i]<'A' || ime_i_prezime[i]>'Z' || ime_i_prezime[i]<'a' || ime_i_prezime[i]>'z' || ime_i_prezime[i]<'0' || ime_i_prezime[i]>'9' ||
        ime_i_prezime[i]!='-' || ime_i_prezime[i]!=' ') 
        throw std::domain_error ("Neispravno ime i prezime"); 
    }
    Kupac::ime_i_prezime=ime_i_prezime; 
}

void Kupac::Postavi (const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    for (int i=0; i<ime_i_prezime.size(); i++) {
    if (ime_i_prezime[i]<'A' || ime_i_prezime[i]>'Z' || ime_i_prezime[i]<'a' || ime_i_prezime[i]>'z' || ime_i_prezime[i]<'0' || ime_i_prezime[i]>'9' || 
        ime_i_prezime[i]!='-' || ime_i_prezime[i]!=' ')  
        throw std::domain_error ("Neispravno ime i prezime"); 
    }
     datum.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu()); 
     Kupac::ime_i_prezime=ime_i_prezime;
} 

class Stan {
    std::string adresa; 
    int sprat, broj_soba;
    bool namjesten; 
    double kvadratura; 
    
    public: 
    Stan (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura); 
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; } 
    bool DajNamjesten() const { return namjesten; } 
    double DajKvadraturu() const { return kvadratura; } 
    void Ispisi() const;
}; 

Stan::Stan (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if (sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka"); 
    Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura; 
}

void Stan::Postavi (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if (sprat<0 ||broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka"); 
    Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura; 
}

void Stan::Ispisi() const {
    if (DajNamjesten()==1) {
        if (DajBrojSoba()==1) {
        std::cout <<"Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobu."; 
        std::cout << std::endl << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan je namjesten";
        }
        else if (DajBrojSoba()==2 || DajBrojSoba()==3 || DajBrojSoba()==4) {
        std::cout <<"Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobe."; 
        std::cout << std::endl << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan je namjesten";
        }
        else {
        std::cout <<"Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " soba."; 
        std::cout << std::endl << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan je namjesten";
        }
    }
    else {
        if (DajBrojSoba()==1) {
        std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobu."; 
        std::cout << std::endl << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan nije namjesten";
        }
        else if (DajBrojSoba()==2 || DajBrojSoba()==3 || DajBrojSoba()==4) {
        std::cout <<"Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobe."; 
        std::cout << std::endl << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan nije namjesten";
        }
        else {
        std::cout <<"Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " soba."; 
        std::cout << std::endl << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan je namjesten";
        }
    }
}

class Prodaja {
   std::string ime_agenta_prodaje, adresa_stana; 
   double cijena_stana; 
   Datum datum_prodaje; 
   Kupac kupac_stana; 
   Stan kupljeni_stan; 
   int dan_prodaje, mjesec_prodaje, godina_prodaje;
   std::string ime_kupca;
   Datum datum_rodjenja_kupca; 
   int sprat_stana;
   int broj_soba; 
   bool namjesten_stan; 
   double broj_kvadrata; 
    
   public: 
   
   Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
   Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
            const Datum &datum_rodjenja_kupca, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata); 
   void PromijeniKupca (const Kupac &novi_kupac) { kupac_stana=novi_kupac; }    
   void PromijeniStan (const Stan &novi_stan) { kupljeni_stan=novi_stan; }
   void PromijeniDatumKupovine (const Datum &novi_datum) { datum_prodaje=novi_datum; }
   void PromijeniCijenuProdaje (const double &nova_cijena) { cijena_stana=nova_cijena; }
   void PomjeriDanUnaprijed() { dan_prodaje++; }
   void PomjeriDanUnazad() { dan_prodaje--; }
   std::string DajImeAgenta() const { return ime_agenta_prodaje; } 
   std::string DajImeKupca() const { return ime_kupca; } 
   Datum DajDatumProdaje() const { return datum_prodaje; }
   double DajCijenuStana() const { return cijena_stana; }
   
   friend bool ProdatPrije (const Prodaja &p1, const Prodaja &p2); 
   friend bool SkupljiStan (const Prodaja &p1, const Prodaja &p2); 
   void Ispisi() const; 
}; 

Prodaja::Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan): 
datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan), datum_rodjenja_kupca(datum_rodjenja_kupca) {
    Prodaja::cijena_stana=cijena_stana; Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; 
}

Prodaja::Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
                  const Datum &datum_rodjenja_kupca, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) :
                  datum_rodjenja_kupca(datum_rodjenja_kupca), datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {
                      Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana; Prodaja::dan_prodaje=dan_prodaje; 
                      Prodaja::mjesec_prodaje=mjesec_prodaje; Prodaja::godina_prodaje=godina_prodaje; 
                      Prodaja::ime_kupca=ime_kupca; Prodaja::sprat_stana=sprat_stana;Prodaja::broj_soba=broj_soba; 
                      Prodaja::namjesten_stan=namjesten_stan; Prodaja::broj_kvadrata=broj_kvadrata; 
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    if (p1.DajDatumProdaje().DajGodinu()>p2.DajDatumProdaje().DajGodinu()) return true; 
    else if (p1.DajDatumProdaje().DajGodinu()==p2.DajDatumProdaje().DajGodinu()) {
        if (p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec()) return true; 
        else if (p1.DajDatumProdaje().DajMjesec()==p2.DajDatumProdaje().DajMjesec()) {
            if (p1.DajDatumProdaje().DajDan()<p2.DajDatumProdaje().DajDan()) return true; 
            else return false; 
        }
    }
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    if (p1.DajCijenuStana()>p2.DajCijenuStana()) return true; 
    else return false; 
}

void Prodaja::Ispisi() const {
    std::cout << "Ime agenta: " << std::setw(20) << DajImeAgenta() << std::endl; 
   // std::cout << "Ime kupca: " << std::setw(20) << DajImeKupca() << " (" <<  << ")" << std::endl; 
   // std::cout << "Zakazani datum prodaje: " << std::setw(20) << DajDatumProdaje() << std::endl; 
    std::cout << "Cijena stana: " << std::setw(20) << DajCijenuStana() << std::endl; 
    std::cout << "Informacije o stanu: " << std::endl; 
  //  std::cout << Prodaja::kupljeni_stan.Ispisi(); 
}

class Prodaje {
    int max_broj_prodaja; 
    int broj_prodaja; 
    Prodaja **p; 
    
    public: 
    
    explicit Prodaje (int max_broj_prodaja) : max_broj_prodaja(max_broj_prodaja), broj_prodaja(0), p(new Prodaja*[broj_prodaja]) {}; 
    explicit Prodaje (std::initializer_list<Prodaja> spisak_prodaja): max_broj_prodaja(spisak_prodaja.size()), broj_prodaja(spisak_prodaja.size()), 
                       p(new Prodaja*[spisak_prodaja.size()]{}) {
                           auto it=spisak_prodaja.begin(); 
                           for (auto i=0; i<broj_prodaja; i++) {
                               p[i]=new Prodaja(*it++); 
                           }
                       }
    ~Prodaje();   
    Prodaje (const Prodaje &prodaje); 
    Prodaje (Prodaje &&prodaje); 
    
Prodaje &operator =(const Prodaje &prodaje) {
        
    if (this==&prodaje) return *this; 
    for (int i=0; i<prodaje.broj_prodaja; i++) 
              delete p[i];
              delete[]p; 
    
    max_broj_prodaja=prodaje.broj_prodaja; 
    broj_prodaja=prodaje.broj_prodaja; 
    p=new Prodaja*[prodaje.broj_prodaja];
    
        try {
            for (int i=0; i<prodaje.broj_prodaja; i++) 
            p[i]=new Prodaja(*prodaje.p[i]); 
        }
        catch (...) {
            for (int i=0; i<prodaje.broj_prodaja; i++) 
            delete p[i]; 
            delete[] p;
            throw; 
    }
    return *this;
} 

    Prodaje &operator =(Prodaje &&prodaje) {
        std::swap(broj_prodaja, prodaje.broj_prodaja); 
        std::swap(p, prodaje.p); 
        return *this; 
    }  
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan); 
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
                            const Datum &datum_rodjenja_kupca, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const { return broj_prodaja; } 
    int DajBrojProdajaNaDatum(const Datum &datum) const;  
}; 

Prodaje::~Prodaje() {
    for (int i=0; i<broj_prodaja; i++) 
    delete p[i]; 
    delete[] p; 
}

Prodaje::Prodaje (const Prodaje &prodaje) : max_broj_prodaja(prodaje.broj_prodaja), broj_prodaja(prodaje.broj_prodaja), 
                  p(new Prodaja*[prodaje.broj_prodaja]) {
                      try {
                          for (int i=0; i<prodaje.broj_prodaja; i++) 
                          p[i]=new Prodaja(*prodaje.p[i]); 
                      }
                      catch(...) {
                          for (int i=0; i<prodaje.broj_prodaja; i++) 
                          delete p[i]; 
                          delete[] p; 
                          throw; 
                      }
}

Prodaje::Prodaje (Prodaje &&prodaje) : max_broj_prodaja(prodaje.max_broj_prodaja), broj_prodaja(prodaje.broj_prodaja), p(prodaje.p) {
    prodaje.p=nullptr; 
    broj_prodaja=0; 
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
    if (Prodaje::broj_prodaja>=Prodaje::max_broj_prodaja) throw std::range_error ("Dostignut maksimalni broj prodaja"); 
    
    Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan); 
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
                                 const Datum &datum_rodjenja_kupca,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
    if (Prodaje::broj_prodaja>=Prodaje::max_broj_prodaja) throw std::range_error ("Dostignut maksimalni broj prodaja"); 
    
    Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    }


int main ()
{
   
	return 0;
}