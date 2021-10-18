/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector> 
#include <algorithm>
#include <initializer_list>
#include <iomanip>
#include <cstdlib>
#include <memory>
#include <iterator>

class Datum {                                                                                                                      //DATUM
    int dan; 
    int mjesec;
    int godina;
    bool provjeraDatuma(int d, int m, int g);
    
    
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const;
    int DajMjesec() const;
    int DajGodinu() const;
    void Ispisi() const;

};

   bool Datum::provjeraDatuma(int d, int m, int g) {                                               // PROVJERA DATUMA
       int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
       if(g % 4 == 0 && (g % 100 != 0 || g % 400 == 0)) broj_dana[1]++;
       if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1]) return false;
       return true;
   }
   
   
   
   Datum::Datum(int dan, int mjesec, int godina ) {
       if(!Datum::provjeraDatuma(dan,mjesec,godina)) throw std::domain_error("Neispravan datum. Molimo unesite opet.");
       Datum::dan = dan;
       Datum::mjesec = mjesec;
       Datum::godina = godina;
   }
   
   void Datum::Postavi(int dan, int mjesec, int godina) {
       if(!Datum::provjeraDatuma(dan,mjesec,godina)) throw std::domain_error("Neispravan datum. Molimo unesite opet.");
       Datum::dan = dan;
       Datum::mjesec = mjesec;
       Datum::godina = godina;
   }
   
   
   int Datum::DajDan() const {
       return Datum::dan;
   }
   
   int Datum::DajMjesec() const {
       return Datum::mjesec;
   }
   
   int Datum::DajGodinu() const {
       return godina;
   }
   
   void Datum::Ispisi() const {
       std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
   }
   
   class Kupac {                                                                                                                              //KUPAC
     std::string ime_i_prezime;
     Datum datum_rodjenja;
     bool jelLegalnoIme(std::string ime_i_prezime);
     
     public:
     Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
     void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
     std::string DajImePrezime() const;
     Datum DajDatumRodjenja() const;
     void Ispisi() const;
 };
 
 bool Kupac::jelLegalnoIme(std::string ime_i_prezime) {
     for(int i = 0; i < ime_i_prezime.length(); i++) 
      if( !( (ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z') || (ime_i_prezime[i] >= 'A' && ime_i_prezime[i] <= 'Z') || (ime_i_prezime[i] >= '0' && ime_i_prezime[i] <= '9') || ime_i_prezime[i] == ' ' || ime_i_prezime[i] == '\'' || ime_i_prezime[i] == '-' ) ) return false;
      
      return true;
 }
 
    Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datum_rodjenja(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu()) {
        if(!Kupac::jelLegalnoIme(ime_i_prezime)) throw std::domain_error("Neispravno ime i prezime. Molimo unesite opet.");
        Kupac::ime_i_prezime = ime_i_prezime;
        ;
    }
    
    
    void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) { 
         if(!Kupac::jelLegalnoIme(ime_i_prezime)) throw std::domain_error("Neispravno ime i prezime. Molimo unesite opet.");
         Kupac::ime_i_prezime = ime_i_prezime;
         Kupac::datum_rodjenja = datum_rodjenja;
     }
     
     
    std::string Kupac::DajImePrezime() const {
         return ime_i_prezime;
     }
     
     
    Datum Kupac::DajDatumRodjenja() const {
         return datum_rodjenja;
     }
     
    void Kupac::Ispisi() const {
         std::cout<<ime_i_prezime<<" (";
         datum_rodjenja.Ispisi();
         std::cout<<")";
     }
     
     
    class Stan {                                                                                                                        //STAN
     std::string adresa;
     int sprat;
     int broj_soba;
     bool namjesten;
     double kvadratura;
     
     void ispisSobe() const;
     
     
     public:
     Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
     void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
     std::string DajAdresu() const;
     int DajSprat() const;
     int DajBrojSoba() const;
     bool DajNamjesten() const;
     double DajKvadraturu() const;
     void Ispisi() const;
 };
 
    Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool  namjesten, double kvadratura) {
        if(sprat < 0 || broj_soba < 0 || kvadratura < 0) throw std::domain_error("Neispravan unos podataka. Molimo unesite opet.");
        Stan::adresa = adresa;
        Stan::sprat = sprat;
        Stan::broj_soba = broj_soba;
        Stan::namjesten = namjesten;
        Stan::kvadratura = kvadratura;
    } 
 
    void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        if( sprat < 0 || broj_soba < 0 || kvadratura < 0) throw std::domain_error("Neispravan unos podataka. Molimo unesite opet.");
        Stan::adresa = adresa;
        Stan::sprat = sprat;
        Stan::broj_soba = broj_soba;
        Stan::namjesten = namjesten;
        Stan::kvadratura = kvadratura;
    }
 
    std::string Stan::DajAdresu() const {
        return adresa;
    }
 
 
     int Stan::DajSprat() const {
         return sprat;
     }
     
     int Stan::DajBrojSoba() const {
         return broj_soba;
     }
     
     
     bool Stan::DajNamjesten() const {
         return namjesten;
     }
     
     
     double Stan::DajKvadraturu() const {
         return kvadratura;
     }
     
     
     void Stan::ispisSobe() const {
         std::vector<int> soba = {12,13,14,112,113,114,212,213,214,312,313,314,412,413,414,512,513,514,612,613,614}; //...
         int prvi = 2, drugi = 4;
         bool jel = false;
         if(broj_soba == 1)  {std::cout<<" sobu."; jel = true; }
         while (!jel) {
             auto d = std::find(soba.begin(),soba.end(),prvi); 
             if( d == soba.end()) d--;
             if( (broj_soba >=prvi && broj_soba <= drugi) && prvi != *d ) { std::cout<<" sobe."; jel = true; break; }
             prvi += 10; 
             drugi += 10;
             if( broj_soba < prvi ) break;
         }
           if(!jel) std::cout<<" soba.";
         
     }
     
     
     void Stan::Ispisi() const {
         std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba;
         Stan::ispisSobe();
      
         std::cout<<"Kvadratura stana je "<<kvadratura<<" (m^2) i stan ";
         if(namjesten) std::cout<<"je";
         else std::cout<<"nije";
         std::cout<<" namjesten.\n";
     }
     
     
     
     class Prodaja {                                                                                                                                                              //PRODAJA
         std::string ime_agenta_prodaje;
         double cijena_stana;
         Datum datum_prodaje;
         Kupac kupac_stana;
         Stan kupljeni_stan;
         
         public:
         Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
         Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
         void PromijeniKupca(const Kupac &novi_kupac); 
         void PromijeniStan(const Stan &novi_stan);
         void PromijeniDatumKupovine(const Datum &novi_datum);
         void PromijeniCijenuProdaje(const double &nova_cijena);
         void PomjeriDanUnaprijed();
         void PomjeriDanUnazad();
         std::string DajImeAgenta() const;
         std::string DajImeKupca() const;
         Datum DajDatumProdaje() const;
         double DajCijenuStana() const;
         friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
         friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
         void Ispisi() const;
         void PromijeniAgenta(const std::string &agent) {
             ime_agenta_prodaje = agent;
         }
     };
     
     Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) : datum_prodaje(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()) , kupac_stana(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja()), kupljeni_stan(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu())
     {
         Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
         Prodaja::cijena_stana = cijena_stana;
     }
     
     
     Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) 
     : datum_prodaje(Datum(dan_prodaje,mjesec_prodaje,godina_prodaje)) , kupac_stana(Kupac(ime_kupca,datum_rodjenja_kupca)) , kupljeni_stan(Stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata))
     {
         Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
         Prodaja::cijena_stana = cijena_stana;
         
     }
     
     void Prodaja::PromijeniKupca( const Kupac &novi_kupac) {
         Prodaja::kupac_stana = novi_kupac;
     }
     
     void Prodaja::PromijeniStan(const Stan &novi_stan) {
         Prodaja::kupljeni_stan = novi_stan;
     }
     
     void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum) {
         Prodaja::datum_prodaje = novi_datum;
     }
     
     void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena) {
         Prodaja::cijena_stana = nova_cijena;
     }
     
     void Prodaja::PomjeriDanUnaprijed() {
          int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
          if(datum_prodaje.DajGodinu() % 4 == 0 && (datum_prodaje.DajGodinu() % 100 != 0 || datum_prodaje.DajGodinu() % 400 == 0)) broj_dana[1]++;
          int dan = datum_prodaje.DajDan(), mjesec = datum_prodaje.DajMjesec(), godina = datum_prodaje.DajGodinu();
          dan++;
          if(datum_prodaje.DajDan() > broj_dana[datum_prodaje.DajMjesec() - 1]) dan = 1, mjesec++;
          if(datum_prodaje.DajMjesec() > 12) mjesec = 1, godina++;
          this->datum_prodaje.Postavi(dan,mjesec,godina);
     }
     
     void Prodaja::PomjeriDanUnazad() {
         int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
         if( datum_prodaje.DajGodinu()%4 == 0 && (datum_prodaje.DajGodinu() % 100 !=0 || datum_prodaje.DajGodinu() % 400 == 0)) broj_dana[1]++;
         int dan = datum_prodaje.DajDan(), mjesec = datum_prodaje.DajMjesec(), godina = datum_prodaje.DajGodinu();
         dan--;
         if(datum_prodaje.DajDan() <= 0) dan = broj_dana[mjesec -2], mjesec--;
         if(datum_prodaje.DajMjesec() <= 0 ) mjesec = 12, godina--;
         
         this->datum_prodaje.Postavi(dan,mjesec,godina);
     }
     
     std::string Prodaja::DajImeAgenta() const {
         return ime_agenta_prodaje;
     }
     
     
     std::string Prodaja::DajImeKupca() const {
         return kupac_stana.DajImePrezime();
     }
     
     Datum Prodaja::DajDatumProdaje() const {
         return datum_prodaje;
     }
     
     double Prodaja::DajCijenuStana() const {
         return cijena_stana;
     }
     
      bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
          
          if(p2.datum_prodaje.DajGodinu() > p1.datum_prodaje.DajGodinu() ) return false;
          if(p1.datum_prodaje.DajGodinu() > p2.datum_prodaje.DajGodinu()) return true;
      
          if( p1.datum_prodaje.DajGodinu() >= p2.datum_prodaje.DajGodinu() && p1.datum_prodaje.DajMjesec() >= p2.datum_prodaje.DajMjesec() && p1.datum_prodaje.DajDan() > p2.datum_prodaje.DajDan()) return true;
          
          return false;
          
      }
      
       bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
           if(p1.DajCijenuStana() > p2.DajCijenuStana()) return true;
           return false;
       }
       
       
       void Prodaja::Ispisi() const {
          std::cout<<"Ime agenta:                     "<<ime_agenta_prodaje<<std::endl;
           std::cout<<"Ime kupca:                      ";
           kupac_stana.Ispisi();
           std::cout<<std::endl;
           std::cout<<"Zakazani datum prodaje:         ";
           datum_prodaje.Ispisi();
           std::cout<<std::endl;
           std::cout<<"Cijena stana:                   "<<cijena_stana<<std::endl;
           std::cout<<"Informacije o stanu: \n";
           kupljeni_stan.Ispisi();
       }
         
 
    class Prodaje {                                                                                                                              //PRODAJE 
        std::vector<std::shared_ptr<Prodaja>> pro;
        
        static bool Datumcici(const Datum &p, const Datum &t) {
            if(p.DajDan() == t.DajDan() && p.DajMjesec() == t.DajMjesec() && p.DajGodinu() == t.DajGodinu() ) return true;
            return false;
        }
        
        
        public:
        explicit Prodaje() = default;
        Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
        ~Prodaje();
        Prodaje(const Prodaje &prodaje); //kopirajuci
        Prodaje(Prodaje &&prodaje) = default;
        Prodaje &operator =(const Prodaje &prodaje);
        Prodaje &operator =(Prodaje &&prodaje) = default;
        void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan);
        void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
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
        Prodaja &DajProdaju(int broj){
            if(broj > pro.size()) throw std::domain_error("Nema toliko prodaja!");
            return *pro[broj];
        }
       
    
    };
    
   Prodaje::~Prodaje() {
       for(int i = 0; i < pro.size(); i++)
         pro[i] = nullptr;
   }
   



    
    Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) {
       
        for(auto it = spisak_prodaja.begin(); it != spisak_prodaja.end(); it++){
           std::shared_ptr<Prodaja> x = std::make_shared<Prodaja>(*it);
           pro.emplace_back(x);
        }
    }
    
    Prodaje::Prodaje(const Prodaje &prodaje) {
        pro.resize(prodaje.pro.size());
        for(int i = 0; i < prodaje.pro.size(); i++)
          pro[i] = std::make_shared<Prodaja>(*prodaje.pro[i]);
       
    }
    
    Prodaje &Prodaje::operator =(const Prodaje &prodaje) {
        pro.resize(prodaje.pro.size());
        std::copy(prodaje.pro.begin(), prodaje.pro.end(), pro.begin());
        return *this;
        }
        
        
       
        void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan) {
            std::shared_ptr<Prodaja> p = std::make_shared<Prodaja>(Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan));
            pro.emplace_back(p);
          
        }
        
       void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
             std::shared_ptr<Prodaja> p = std::make_shared<Prodaja>(Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata));
             pro.emplace_back(p);
        }
        
        
        void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
            std::shared_ptr<Prodaja> p = std::make_shared<Prodaja>(*prodaja);
            pro.emplace_back(p);
        }
        
        int Prodaje::DajBrojProdaja() const {
            return pro.size();
        }
        
        
        int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
            int prodajeDatuma = 0;
            prodajeDatuma = std::count_if(pro.begin(),pro.end(), [datum](std::shared_ptr<Prodaja> p) {
                if(Datumcici(p->DajDatumProdaje(),datum)) return true;
                return false;
            });
            
            return prodajeDatuma;
        }
        
        
       int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
            int agy = 0;
            agy = std::count_if(pro.begin(), pro.end(), [ime_agenta](std::shared_ptr<Prodaja> p) {
                if(p->DajImeAgenta() == ime_agenta) return true;
                return false;
            });
            return agy;
        }
        
        
        Prodaja &Prodaje::DajNajranijuProdaju() {
            auto mi =std::min_element(pro.begin(),pro.end(),[](const std::shared_ptr<Prodaja> p,const std::shared_ptr<Prodaja> t) { 
                return !ProdatPrije(*p,*t);
                
            });
            return **mi;
        }
        
        
        Prodaja Prodaje::DajNajranijuProdaju() const {
            if(pro.size() == 0) throw std::domain_error("Nema registriranih prodaja");
           return **(std::min_element(pro.begin(),pro.end(),[](const std::shared_ptr<Prodaja> p,const std::shared_ptr<Prodaja> t) { return !ProdatPrije(*p,*t); }));
        }
        
        
        Prodaja &Prodaje::DajNajskupljuProdaju() {
            if(pro.size() == 0) throw std::domain_error("Nema registriranih prodaja");
            return **(std::max_element(pro.begin(), pro.end(),[](const std::shared_ptr<Prodaja> p, const std::shared_ptr<Prodaja> t) { return !SkupljiStan(*p,*t); }));
        }
        
        
       Prodaja Prodaje::DajNajskupljuProdaju() const {
           if(pro.size() == 0) throw std::domain_error("Nema registriranih prodaja");
          return **(std::max_element(pro.begin(), pro.end(),[](const std::shared_ptr<Prodaja> p, const std::shared_ptr<Prodaja> t) { return !SkupljiStan(*p,*t); }));
          
       }
       
       
        void Prodaje::IsprazniKolekciju() {
            for(int i = 0; i < pro.size(); i++)
               pro[i] = nullptr;
              pro.resize(0);
        }
        
        void Prodaje::ObrisiNajranijuProdaju() {
            if(pro.size() == 0) throw std::range_error("Prazna kolekcija");
            for(int i = 0; i < pro.size(); i++) {
        if (pro[i]->DajDatumProdaje().DajDan() == this->DajNajranijuProdaju().DajDatumProdaje().DajDan() && pro[i]->DajDatumProdaje().DajMjesec() == this->DajNajranijuProdaju().DajDatumProdaje().DajMjesec() && pro[i]->DajDatumProdaje().DajGodinu() == this->DajNajranijuProdaju().DajDatumProdaje().DajGodinu()) {
            for (int j = i; j < pro.size()-1; j++) {
                Prodaja p (*pro[j]);
                *pro[j] = *pro[j+1];
                *pro[j+1] = p;
            }
        }
    }
            pro.resize(pro.size()-1);
        }
        
        
        void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
            if(Prodaje::DajBrojProdajaOdAgenta(ime_agenta) == 0) return;
            int bo = 0;
            std::for_each(pro.begin(),pro.end(), [ime_agenta, &bo](std::shared_ptr<Prodaja> &p){
                if(p->DajImeAgenta() == ime_agenta) { p = nullptr; bo++; }
            });
            pro.resize(pro.size()-bo);
            
        }
        
        void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
            if(Prodaje::DajBrojProdajaNaDatum(datum) == 0) return;
            int bo = 0;
            std::for_each(pro.begin(),pro.end(),[datum, &bo](std::shared_ptr<Prodaja> &p) {
                if(Datumcici(p->DajDatumProdaje(),datum) ) {  p = nullptr; bo++; }
            });
           pro.resize(pro.size() - bo);
        }
        
        
        void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
            Prodaje svaProdaj(*this);
            std::sort(svaProdaj.pro.begin(),svaProdaj.pro.end(),[](const std::shared_ptr<Prodaja> p, const std::shared_ptr<Prodaja> t){
               if(p->DajImeKupca()[0] < t->DajImeKupca()[0]) return true;
               return false;
            });
            
            std::for_each(svaProdaj.pro.begin(),svaProdaj.pro.end(),[datum](const std::shared_ptr<Prodaja> p) {
                if(Datumcici(p->DajDatumProdaje(),datum)) p->Ispisi();
            });
        }
        
        
        void Prodaje::IspisiSveProdaje() const {
            Prodaje svaProdaj(*this);
            std::sort(svaProdaj.pro.begin(),svaProdaj.pro.end(),[](const std::shared_ptr<Prodaja> p, const std::shared_ptr<Prodaja> t) {
                if(Datumcici(p->DajDatumProdaje(),t->DajDatumProdaje()) && p->DajImeKupca()[0] < t->DajImeKupca()[0] ) return true;
                if(ProdatPrije(*p,*t)) return true;
                return false;
                
            });
            
           std::for_each(svaProdaj.pro.begin(), svaProdaj.pro.end(),[](const std::shared_ptr<Prodaja> p) {
                p->Ispisi();
            });
            
          
            
        }



 void unesiStan(std::vector<Stan> &stanovi) {
       while (true) {
                   try{
                       std::cout<<"Unesite adresu: ";
                       std::string adresa;
                       std::cin.ignore(1000,'\n');
                       std::getline(std::cin,adresa);
                       std::cout<<"Unesite sprat: ";
                       int sprat;
                       std::cin>>sprat;
                       std::cout<<"Unesite broj soba: ";
                       int broj_soba;
                       std::cin>>broj_soba;
                       std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                       int zaBool;
                       std::cin>>zaBool;
                       std::cout<<"Unesite kvadraturu: ";
                       double kvadratura = 0;
                       std::cin>>kvadratura;
                       if(zaBool != 0 && zaBool != 1) throw std::domain_error("Neispravan unos podataka");
                       Stan nov = Stan(adresa,sprat,broj_soba,bool(zaBool),kvadratura);
                       stanovi.push_back(nov);
                       
                       std::cout<<"Stan je uspjesno dodan!\n \n";
                       break;
                   }catch(std::domain_error d) {
                       std::cout <<"Izuzetak: "<< d.what() <<". Molimo unesite opet."<< std::endl;
                   }
                   
                   }
   }







int main ()
{
    
    try{
        std::vector<Stan> stanovi;
        std::vector<Kupac> kupci;
        std::vector<Prodaja> prodaje;
        Prodaje pr;
        std::cout<<"Dobrodosli!\n\n\n";
        while (true) {
           int opcija=1,opcija1=0,opcija3=0,opcija4 = 0,opcija5=0,opcija6 = 0,opcija7 = 0,opcija8 = 0,opcija9 = 0,op=0,o=0,hocelKraj = 0,plsKraj = 0,joj = 0,fu = 0,izabran = 0,nemamViseImenaZaVar = 0,mybZadnja=0;
          
           std::cout<<"Izaberite opciju:\n 0 - kraj\n 1 - uredjivanje stanova\n 2 - uredjivanje kupaca\n 3 - uredjivanje prodaja\n";
           std::cin>>opcija;
           
           if(opcija == 0)  {std::cout<<"\n\nDovidjenja!"; break; }
           else if( opcija == 1 ){
               while (true) {
               std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje stana\n 2 - uredjivanje stanova\n 3 - ispis svih stanova\n 4 - kraj\n";
              
               std::cin>>opcija1;
              
               
               if(opcija1 == 0){  break; }
               else if(opcija1 == 1){
                   unesiStan(stanovi);
               }
               else if(opcija1 == 2) {
                   std::cout<<"Odaberite stan. Dostupni stanovi su: \n";
                   for(int i = 0; i < stanovi.size(); i++)
                   {
                       std::cout<<" "<< i+1<<" - ";
                       stanovi[i].Ispisi();
                      
                   }
                   std::cout<<std::endl;
                   std::cin>>opcija3;
                   std::cout<<"Odaberite polje koje zelite urediti:\n 0 - nazad\n 1 - adresa\n 2 - sprat\n 3 - broj soba\n 4 - da li je stan namjesten\n 5 - kvadratura\n 6 - sve\n";
                   std::cin>>opcija4;
                   if(opcija4 == 0) break;
                   else if(opcija4 == 1) {
                       while(true) {
                       try{
                       std::cout<<"Unesite adresu: ";
                       std::string adresa;
                       std::cin.ignore(1000,'\n');
                       std::getline(std::cin,adresa);
                       stanovi[opcija3-1].Postavi(adresa, stanovi[opcija3-1].DajSprat(), stanovi[opcija3-1].DajBrojSoba(), stanovi[opcija3-1].DajNamjesten(), stanovi[opcija3-1].DajKvadraturu() );
                       std::cout<<"Stan je uspjesno izmijenjen!\n \n";
                       break;
                       }catch(std::domain_error d) {
                           std::cout <<"Izuzetak: "<< d.what() << ". Molimo unesite opet."<<std::endl;
                       }
                       
                       }
                   }
                       else if(opcija4 == 2) {
                           while(true) {
                               try{
                               std::cout<<"Unesite sprat: ";
                               int sprat;
                               std::cin>>sprat;
                               stanovi[opcija3-1].Postavi(stanovi[opcija3-1].DajAdresu(), sprat, stanovi[opcija3-1].DajBrojSoba(), stanovi[opcija3-1].DajNamjesten(), stanovi[opcija3-1].DajKvadraturu() );
                               std::cout<<"Stan je uspjesno izmijenjen!\n \n";
                               break;
                               }catch(std::domain_error s) {
                                   std::cout << "Izuzetak: "<<s.what() <<". Molimo unesite opet."<< std::endl;
                               }
                           }
                       } 
                       else if(opcija4 == 3) {
                           while (true) {
                               try{
                            std::cout<<"Unesite broj soba: ";
                            int broj_soba;
                            std::cin>>broj_soba;
                            stanovi[opcija3-1].Postavi(stanovi[opcija3-1].DajAdresu(), stanovi[opcija3-1].DajSprat(), broj_soba, stanovi[opcija3-1].DajNamjesten(), stanovi[opcija3-1].DajKvadraturu() );
                            std::cout<<"Stan je uspjesno izmijenjen!\n \n";
                            break;
                       }catch(std::domain_error d){
                           std::cout << "Izuzetak: "<<d.what() <<". Molimo unesite opet."<< std::endl;
                       }
                           }
                       
                   }else if(opcija4 == 4) {
                       while (true) {
                           try{
                       
                       std::cout<<"Da li je stan namjesten (1 - da, 0 - ne):";
                       int zaBool;
                       std::cin>>zaBool;
                       if(zaBool != 0 && zaBool != 1) throw std::domain_error("Neispravan unos podataka. Molimo unesite opet.");
                       stanovi[opcija3-1].Postavi(stanovi[opcija3-1].DajAdresu(), stanovi[opcija3-1].DajSprat(), stanovi[opcija3-1].DajBrojSoba(), bool(zaBool), stanovi[opcija3-1].DajKvadraturu() );
                       std::cout<<"Stan je uspjesno izmijenjen!\n \n";
                       break;
                           }catch(std::domain_error d) {
                               std::cout << "Izuzetak: "<<d.what() <<". Molimo unesite opet."<< std::endl;
                           }
                       }
                   }
                   else if(opcija4 == 5) {
                       
                       while (true) {
                       try{    
                       std::cout<<"Unesite kvadraturu: ";
                       double kvadratura;
                       std::cin>>kvadratura;
                       stanovi[opcija3-1].Postavi(stanovi[opcija3-1].DajAdresu(), stanovi[opcija3-1].DajSprat(), stanovi[opcija3-1].DajBrojSoba(),stanovi[opcija3-1].DajNamjesten(),kvadratura );
                       std::cout<<"Stan je uspjesno izmijenjen!\n \n";
                       break;
                       
                       }catch(std::domain_error d) {
                           std::cout << "Izuzetak: "<<d.what() <<". Molimo unesite opet."<< std::endl;
                       }
                   }
                   }
                   else if(opcija4 == 6) {
                       while(true){
                           try{
                       std::cout<<"Unesite adresu: ";
                       std::string adresa;
                       std::cin.ignore(1000,'\n');
                       std::getline(std::cin,adresa);
                       std::cout<<"Unesite sprat: ";
                       int sprat;
                       std::cin>>sprat;
                       std::cout<<"Unesite broj soba: ";
                       int broj_soba;
                       std::cin>>broj_soba;
                       std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                       int zaBool;
                       std::cin>>zaBool;
                       std::cout<<"Unesite kvadraturu: ";
                       double kvadratura;
                       std::cin>>kvadratura;
                       if(zaBool != 0 && zaBool != 1) throw std::domain_error("Neispravan unos podataka");
                       stanovi[opcija3-1].Postavi(adresa, sprat, broj_soba,bool(zaBool),kvadratura );
                       std::cout<<"Stan je uspjesno izmijenjen!\n \n";
                       break;
                           }
                           catch(std::domain_error d) {
                               std::cout << "Izuzetak: "<<d.what() <<". Molimo unesite opet."<< std::endl ;
                           }
                       }
                   }
                   
                   
               }
               else if(opcija1 == 3) {
                   for(int i = 0; i < stanovi.size(); i++) {
                       std::cout<<i+1<<". ";
                    stanovi[i].Ispisi();
                   }
                   std::cout<<" \n";
               }
               else if(opcija1 == 4) return 0;
               }
               
           }
           else if(opcija == 2) {
               while(true) {
               std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje kupca\n 2 - uredjivanje kupaca\n 3 - ispis svih kupaca\n 4 - kraj\n";
               std::cin>>opcija5;
               if(opcija5 == 0) break;
               else if(opcija5 == 1) {
                   while (true) {
                   try{    
                   
                   std::cout<<"Unesite ime i prezime kupca: ";
                   std::string ime_kupca;
                   std::cin.ignore(1000,'\n');
                   std::getline(std::cin,ime_kupca);
                   std::cout<<"Unesite datum rodjenja (formata d/m/g): ";                                                                                                                    //koji format d/m/g il ovo
                   int dan,mjesec,godina;
                   char j,de;
                   std::cin>>dan>>j>>mjesec>>de>>godina;
                   Datum d = Datum(dan,mjesec,godina);
                   Kupac k = Kupac(ime_kupca,d);
                   kupci.emplace_back(k);
                   std::cout<<"Kupac je uspjesno dodan!\n\n";
                   break;
                   }catch(std::domain_error d) {
                       std::cout << "Izuzetak: "<<d.what() << ". Molimo unesite opet."<<std::endl;
                   }

               }
           }
               else if(opcija5 == 2) {
               std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su: \n";
               for(int i = 0; i < kupci.size(); i++) {
                   std::cout<<" "<<i+1<<" - ";
                   kupci[i].Ispisi();
                   std::cout<<std::endl;
               }
               std::cin>>opcija6;
               while (true) {
                   try{
                   std::cout<<"Unesite ime i prezime kupca: ";
                   std::string ime_kupca;
                   std::cin.ignore(1000,'\n');
                   std::getline(std::cin,ime_kupca);
                   std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                   int dan,mjesec,godina;
                   char j,de;
                   std::cin>>dan>>j>>mjesec>>de>>godina;
                   Datum d = Datum(dan,mjesec,godina);
                   kupci[opcija6-1].Postavi(ime_kupca,d);
                   std::cout<<"Kupac je uspjesno izmijenjen!\n\n";
                   break;
                   }catch(std::domain_error d) {
                       std::cout << "Izuzetak: "<< d.what() << ". Molimo unesite opet."<<std::endl;
                   }
               }
           }
               else if(opcija5 == 3) {
               for(int i = 0; i < kupci.size(); i++) {
                 kupci[i].Ispisi();
                 std::cout<<std::endl; //treba gore dodat
               }
               std::cout<<std::endl;
           }
               else if(opcija5 == 4) return 0; //hocel?
               }
    }
           else if(opcija  == 3) {
               while(true) {
               std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje prodaje\n 2 - uredjivanje prodaje\n 3 - ispis prodaja\n 4 - brisanje prodaja\n 5 - kraj\n";
               std::cin>>opcija7;
               if(opcija7 == 0) break;
               else if(opcija7 == 1) {
                   while (true) {
                      
                   
                   std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje potpuno nove prodaje\n 2 - dodavanje nove prodaje na osnovu arhive\n 3 - kraj\n";
                   std::cin>>opcija8;
                   if(opcija8 == 0) break;
                   else if(opcija8 == 1) {
                       while (true) {
                       try{    
                       
                    std::cout<<"Unesite ime i prezime agenta prodaje: ";
                    std::string agent;
                    std::cin.ignore(1000,'\n');
                    std::getline(std::cin,agent);
                    std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                    int dan,mjesec,godina;
                    char j,dw;
                    std::cin>>dan>>j>>mjesec>>dw>>godina;
                    Datum da = Datum(dan,mjesec,godina);
                    std::cout<<"Unesite cijenu stana: ";
                    double cijena_stana;
                    std::cin>>cijena_stana;
                    std::cout<<"Unesite ime kupca: ";
                    std::string ime_kupca;
                    std::cin.ignore(1000,'\n');
                    std::getline(std::cin,ime_kupca);
                    std::cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
                    int d,m,g;
                    char je,de;
                    std::cin>>d>>je>>m>>de>>g;
                    Datum dat = Datum(d,m,g);
                    Kupac k = Kupac(ime_kupca,dat);
                    kupci.emplace_back(k);
                    std::cout<<"Unesite adresu: ";
                    std::string adresa;
                    std::cin.ignore(10000,'\n');
                    std::getline(std::cin,adresa);
                    std::cout<<"Unesite sprat: ";
                    int sprat;
                    std::cin>>sprat;
                    std::cout<<"Unesite broj soba: ";
                    int broj_soba;
                    std::cin>>broj_soba;
                    std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                    int zaBool;
                    std::cin>>zaBool;
                    std::cout<<"Unesite kvadraturu: ";
                    double kvadratura;
                    std::cin>>kvadratura;
                    if(zaBool != 0 && zaBool != 1) throw std::domain_error("Neispravan unos podataka. Molimo unesite opet.");
                    Stan s = Stan(adresa,sprat,broj_soba,bool(zaBool),kvadratura);
                    stanovi.emplace_back(s);
                   
                    pr.RegistrirajProdaju(agent,cijena_stana,da,k,s);
                    std::cout<<"Prodaja uspjesno dodana!\n\n";
                    break;
                      }catch(std::domain_error d) {
                          std::cout << "Izuzetak: "<< d.what() <<". Molimo unesite opet."<< std::endl;
                      }
                      }
                   }
                   else if(opcija8 == 2) {
                          while (true) {
                   try{    
                   
                 std::cout<<"Unesite ime i prezime agenta prodaje: ";
                 std::string agent;
                 std::cin.ignore(1000,'\n');
                 std::getline(std::cin,agent);
                 std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                 int d,m,g;
                 char j,de;
                 std::cin>>d>>j>>m>>de>>g;
                 Datum da = Datum(d,m,g);
                 std::cout<<"Unesite cijenu stana: ";
                 double cijena_stana;
                 std::cin>>cijena_stana;
                 std::cout<<"Odaberite kupca. Dostupni kupci su: \n";
                 for(int i = 0; i < kupci.size(); i++) {
                     std::cout<<" "<<i+1<<" - ";
                     kupci[i].Ispisi();
                     std::cout<<std::endl;
                 }
                 std::cin>>opcija9;
                 std::cout<<"Odaberite stan. Dostupni stanovi su:\n";
                 for(int i = 0; i < stanovi.size(); i++) {
                     std::cout<<" "<<i+1<<" - ";
                     stanovi[i].Ispisi();
                                                                                                            //il ne treba? probat!!!!
                 }
                 
                 std::cin>>op;
           
                 pr.RegistrirajProdaju(agent,cijena_stana,da,kupci[opcija9-1],stanovi[op-1]);
                 std::cout<<"Prodaja uspjesno dodana!\n\n";
                 break;
                   }catch(std::domain_error d) {
                       std::cout << "Izuzetak: "<<d.what() <<". Molimo unesite opet."<< std::endl ;             //trebal
                   }
                   }
                 
                   }
                   else if(opcija8 == 3) return 0; 
                   
               }
               }
               else if(opcija7 == 2) {
                  // Prodaje lepe(pr);
                   std::cout<<"Odaberite prodaju koju želite urediti. Dostupne prodaje su:\n";
                
                       
                       
                       /* std::sort(pr.DajSveProdaje(),pr.DajSveProdaje() + pr.DajBrojProdaja(),[](const Prodaja *p, const Prodaja *t) {
                            if(p->DajDatumProdaje().DajGodinu() == t->DajDatumProdaje().DajGodinu() && p->DajDatumProdaje().DajMjesec() == t->DajDatumProdaje().DajMjesec() && p->DajDatumProdaje().DajDan() == t->DajDatumProdaje().DajDan() && p->DajImeKupca()[0] < t->DajImeKupca()[0] ) return true;
                            if(!ProdatPrije(*p,*t)) return true;
                            return false;
                            });*/
                            for(int i = 0; i < pr.DajBrojProdaja(); i++) {
                                std::cout<<i+1<<".\n";
                                pr.DajProdaju(i).Ispisi();
                              
                                std::cout<<std::endl; 
                                }
                  
                   
                     
                  
                   std::cin>>o;
                 
                   
                   std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - izmjena agenta\n 2 - izmjena datuma prodaje\n 3 - izmjena kupca\n 4 - izmjena stana\n 5 - izmjena cijene stana\n";
                   std::cin>>hocelKraj;
                   if(hocelKraj == 0) break;
                   else if(hocelKraj == 1) {
                       
                        while(true) {   
                        try{
                        std::cout<<"Unesite ime i prezime agenta prodaje: ";
                        std::string agent;
                        std::cin.ignore(1000,'\n');
                        std::getline(std::cin,agent);
                        pr.DajProdaju(o-1).PromijeniAgenta(agent);  //errrrrrrrrrrrrrrorrr
                        std::cout<<"Prodaja je uspjesno izmijenjena!\n \n";
                        break;
                        }catch(std::domain_error d) {
                            std::cout << "Izuzetak: "<< d.what() <<". Molimo unesite opet."<< std::endl;      //trebal1
                        }
                        }
                        
                       
                   }
                   else if(hocelKraj == 2) {
                      while(true) {
                           try{
                                std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                                int d,m,g;
                                char j,de;
                                std::cin>>d>>j>>m>>de>>g;
                                Datum da = Datum(d,m,g);
                               
                               pr.DajProdaju(o-1).PromijeniDatumKupovine(da);
                                 std::cout<<"Prodaja je uspjesno izmijenjena!\n\n";
                        break;
                        }catch(std::domain_error d) {
                            std::cout << "Izuzetak: "<< d.what() <<". Molimo unesite opet."<< std::endl; // trebal1
                        }
                      }
                          
                       
                       
                   }
                   else if(hocelKraj == 3) {
                       std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - odabir postojeceg kupca\n 2 - dodavanje novog kupca\n";
                       std::cin>>plsKraj;
                       if(plsKraj == 0) break;
                       else if(plsKraj == 1) {
                           
                           std::cout<<"Odaberite kupca. Dostupni kupci su: \n";
                           for(int i = 0; i < kupci.size(); i++){
                               std::cout<<i+1<<" - ";
                               kupci[i].Ispisi();
                               std::cout<<std::endl;
                           }
                           std::cin>>joj;
                           pr.DajProdaju(o-1).PromijeniKupca(kupci[joj-1]);
                           std::cout<<"Prodaja je uspjesno izmijenjena!\n \n";
                          
                       }
                       else if(plsKraj == 2) {
                            while (true) {
                   try{    
                   
                   std::cout<<"Unesite ime i prezime kupca: ";
                   std::string ime_kupca;
                   std::cin.ignore(1000,'\n');
                   std::getline(std::cin,ime_kupca);
                   std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                   int dan,mjesec,godina;
                   char j,de;
                   std::cin>>dan>>j>>mjesec>>de>>godina;
                   Datum d = Datum(dan,mjesec,godina);
                   Kupac k = Kupac(ime_kupca,d);
                   kupci.emplace_back(k);
                   pr.DajProdaju(o-1).PromijeniKupca(k); 
                   std::cout<<"Prodaja je uspjesno izmijenjena!\n \n";
                   break;
                   }catch(std::domain_error d) {
                       std::cout << "Izuzetak: "<<d.what() <<". Molimo unesite opet."<< std::endl;
                   }

               }
                           
                       }
                   }
                   else if(hocelKraj == 4) {
                       std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - odabir postojeceg stana\n 2 - dodavanje novog stana\n";
                       std::cin>>fu;
                       if(fu == 0) break;
                       else if(fu == 1) {
                           std::cout<<"Odaberite stan. Dostupni stanovi su:\n";
                           for(int i = 0; i < stanovi.size(); i++) {
                               std::cout<<i+1<<" - ";
                               stanovi[i].Ispisi();
                           }
                           std::cin>>izabran;
                          pr.DajProdaju(o-1).PromijeniStan(stanovi[izabran-1]);
                           std::cout<<"Prodaja je uspjesno izmijenjena!\n \n";
                           
                       }
                       else if(fu == 2) {
                            while (true) {
                   try{
                       std::cout<<"Unesite adresu: ";
                       std::string adresa;
                       std::cin.ignore(1000,'\n');
                       std::getline(std::cin,adresa);
                       std::cout<<"Unesite sprat: ";
                       int sprat;
                       std::cin>>sprat;
                       std::cout<<"Unesite broj soba: ";
                       int broj_soba;
                       std::cin>>broj_soba;
                       std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                       int zaBool;
                       std::cin>>zaBool;
                       std::cout<<"Unesite kvadraturu: ";
                       double kvadratura;
                       std::cin>>kvadratura;
                       if(zaBool != 0 && zaBool != 1) throw std::domain_error("Neispravan unos podataka. Molimo unesite opet.");
                       Stan nov = Stan(adresa,sprat,broj_soba,bool(zaBool),kvadratura);
                       stanovi.emplace_back(nov);
                       pr.DajProdaju(o-1).PromijeniStan(nov);
                       std::cout<<"Prodaja je uspjesno izmijenjena!\n \n";
                       break;
                   }catch(std::domain_error d) {
                       std::cout <<"Izuzetak: "<< d.what() <<". Molimo unesite opet."<< std::endl <<std::endl; //trebal1
                   }
                           
                       }
                   }
                

                   
               }
                   else if(hocelKraj == 5) {
                       std::cout<<"Unesite cijenu stana: ";
                       double cijena;
                       std::cin>>cijena;
                       pr.DajProdaju(o-1).PromijeniCijenuProdaje(cijena);
                       std::cout<<"Prodaja je uspjesno izmijenjena!\n \n";
                       
                   }
                   
               }
               else if(opcija7 == 3) {
                   while(true) {
                   std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - ispis svih prodaja\n 2 - ispis prodaja na datum\n 3 - ispis najranije prodaje\n 4 - ispis najskuplje prodaje\n 5 - ispis broja prodaja\n";
                   std::cout<<" 6 - ispis broja prodaja po datumu\n 7 - ispis broja prodaja po agentu\n 8 - kraj\n";
                  // std::cin.ignore(1000,'\n');
                   std::cin>>nemamViseImenaZaVar;
                   if(nemamViseImenaZaVar == 0 ) break;
                   else if(nemamViseImenaZaVar == 1) {
                       pr.IspisiSveProdaje();
                       std::cout<<std::endl;
                   }
                   else if(nemamViseImenaZaVar == 2) {
                      std::cout<<"Unesite datum (d/m/g): ";
                                int d,m,g;
                                char j,de;
                                std::cin>>d>>j>>m>>de>>g;
                                Datum da = Datum(d,m,g);
                                std::cout<<"Prodaje na datum ";
                                da.Ispisi();
                                std::cout<<" su:\n";
                       pr.IspisiProdajeNaDatum(da);
                       std::cout<<std::endl;
                       
                   }
                   else if(nemamViseImenaZaVar == 3) {
                       pr.DajNajranijuProdaju().Ispisi();
                       std::cout<<std::endl;
                       
                   }
                   else if(nemamViseImenaZaVar == 4) {
                       pr.DajNajskupljuProdaju().Ispisi();
                       std::cout<<std::endl;
                       
                   }
                   else if(nemamViseImenaZaVar == 5) {
                       std::cout<<"Broj prodaja: "<<pr.DajBrojProdaja()<<std::endl<<std::endl;
                       
                   }
                   else if(nemamViseImenaZaVar == 6) {
                     std::cout<<"Unesite datum (d/m/g): ";
                                int d,m,g;
                                char j,de;
                                std::cin>>d>>j>>m>>de>>g;
                                Datum da = Datum(d,m,g);
                       std::cout<<"Broj prodaja na uneseni datum: "<<pr.DajBrojProdajaNaDatum(da)<<std::endl<<std::endl;
                   }
                   else if(nemamViseImenaZaVar == 7) {
                       std::cout<<"Unesite ime agenta: ";
                       std::string agent;
                       std::cin.ignore(1000,'\n');
                       std::getline(std::cin,agent);
                       std::cout<<"Broj prodaja unesenog agenta: "<<pr.DajBrojProdajaOdAgenta(agent)<<std::endl<<std::endl;
                   }
                   else if( nemamViseImenaZaVar == 8) return 0;

                   }
                   
               }
               else if(opcija7 == 4) {
                   while(true) {
                   std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - brisanje najranije prodaje\n 2 - brisanje prodaja agenta\n 3 - brisanje prodaja po datumu\n 4 - brisanje svih prodaja\n";
                   std::cin>>mybZadnja;
                   if(mybZadnja == 0) break;
                   else if(mybZadnja == 1) {
                       try{
                       pr.ObrisiNajranijuProdaju();
                       std::cout<<"Najranija prodaja je obrisana!\n \n";
                       }catch(std::range_error r) {
                           std::cout << "Izuzetak: "<<r.what() << std::endl;
                       }
                       
                   }
                   else if(mybZadnja == 2) {
                       try{
                       std::cout<<"Unesite ime agenta: ";
                       std::string agent;
                       std::cin.ignore(1000,'\n');
                       std::getline(std::cin,agent);
                       pr.ObrisiProdajeAgenta(agent);
                       std::cout<<"Sve prodaje tog agenta su obrisane.\n \n";
                       }catch(std::range_error r) {
                           std::cout << "Izuzetak: "<<r.what() << std::endl;
                       }
                       
                   }
                   else if(mybZadnja == 3) {
                       try{
                        std::cout<<"Unesite datum: ";
                                int d,m,g;
                               char j,de;
                                std::cin>>d>>j>>m>>de>>g;
                                Datum da = Datum(d,m,g);
                                pr.ObrisiProdajeNaDatum(da);
                                std::cout<<"Sve prodaje na taj datum su obrisane.\n \n";
                        }catch(std::range_error r) {
                           std::cout << "Izuzetak: "<<r.what() << std::endl;
                       }
                                
                   }
                   else if(mybZadnja == 4) {
                       try{
                      pr.IsprazniKolekciju();
                      std::cout<<"Sve prodaje su obrisane.\n \n";
                      }catch(std::range_error d) {
                          std::cout<<"Izuzetak: "<<d.what()<<std::endl;
                      }// treba izuzetak
                        
                   }

                   }
               }
               else if(opcija7 == 5) return 0;
               
           }
           }
        }
    }catch(std::domain_error d) {
        std::cout << d.what() << std::endl;
    }
    
    
	return 0;
}