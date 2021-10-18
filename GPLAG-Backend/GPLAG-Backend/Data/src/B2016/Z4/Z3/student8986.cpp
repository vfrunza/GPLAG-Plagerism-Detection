#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>

bool Slovo(char z) {
    if((z>='A' && z<='Z') || (z>='a' && z<='z') || (z>='0' && z<='9')) return true;
    return false;
}

class Datum {
    int dan, mjesec, godina;
    public:
    Datum(int d, int m, int g) { Postavi(d,m,g); }
    void Postavi(int d, int m, int g);
    void Ispisi() const { std::cout<<dan<<"/"<<mjesec<<"/"<<godina; }
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    friend bool JednakiDatumi(const Datum &d1, const Datum &d2);
};
bool JednakiDatumi(const Datum &d1, const Datum &d2) {
    if(d1.dan==d2.dan && d1.mjesec==d2.mjesec && d1.godina==d2.godina) return true; return false;
}
void Datum::Postavi(int d, int m, int g) {
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if((g%4==0  && g%100!=0) || g%400==0) broj_dana[1]++;
    if(g<1 || m<1 || d<1 || m>12 || d>broj_dana[m-1])
        throw std::domain_error ("Neispravan datum.");
        dan=d; mjesec=m; godina=g;
}

class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    
    bool IspravnoIme(std::string ime) {
        for(int i=0; i<ime.length(); i++) if(ime[i]!= ' ' && ime[i]!='-' && int(ime[i])!=39 && !Slovo(ime[i])) return false;
        return true;
    }
    
    public:
    
    Kupac(const std::string &ime_i_prezime, const Datum datum_rodjenja) : datum_rodjenja(datum_rodjenja) {
        if(!IspravnoIme(ime_i_prezime)) throw std::domain_error ("Neispravno ime i prezime.");
        this->ime_i_prezime=ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum datum_rodjenja) {
        if(!IspravnoIme(ime_i_prezime)) throw std::domain_error ("Neispravno ime i prezime.");
        this->ime_i_prezime=ime_i_prezime; this->datum_rodjenja=datum_rodjenja;
    }
    
    std::string DajImePrezime() const { return ime_i_prezime; }
    Datum DajDatumRodjenja() const { return datum_rodjenja; }
    void Ispisi() const { std::cout<<ime_i_prezime<<" (";datum_rodjenja.Ispisi();std::cout<<")"; }
    friend bool JednakiKupci(const Kupac &k1, const Kupac &k2);
};

bool JednakiKupci(const Kupac &k1, const Kupac &k2) {
    if(k1.ime_i_prezime!=k2.ime_i_prezime || !JednakiDatumi(k1.datum_rodjenja, k2.datum_rodjenja)) return false; return true;
}


class Stan {
    
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
    
    public:
    
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) { Postavi(adresa, sprat, broj_soba, namjesten, kvadratura); }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error ("Neispravan unos podataka.");
        Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
    }
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    void Ispisi() const;
    friend bool JednakoStanovi(const Stan &s1, const Stan &s2);
};
bool JednakoStanovi(const Stan &s1, const Stan &s2) {
    if(s1.adresa!=s2.adresa || s1.sprat!=s2.sprat || s1.broj_soba!=s2.broj_soba || s1.namjesten!=s2.namjesten || s1.kvadratura!=s2.kvadratura)
        return false;
    return true;
}

void Stan::Ispisi() const {
    std::string pom;
    if(namjesten==true) pom="je"; else pom="nije";
    
    if(broj_soba%10==1 && (broj_soba/10)%10!=1 )
        std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" sobu."
        <<" Kvadratura stana je "<<kvadratura<<" (m^2) i stan "<<pom<<" namjesten.";
    else if((broj_soba%10==2 || broj_soba%10==3 || broj_soba%10==4) && (broj_soba/10)%10!=1 )
        std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" sobe."
        <<" Kvadratura stana je "<<kvadratura<<" (m^2) i stan "<<pom<<" namjesten.";
    else
        std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" soba."
        <<" Kvadratura stana je "<<kvadratura<<" (m^2) i stan "<<pom<<" namjesten.";
}

class Prodaja {
    
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
   
    int BrojDana(int mjesec, int godina);
    
    public:
    
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
            const Kupac &kupac_stana, const Stan &kupljeni_stan) : ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana),
            datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {}
    
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
            std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana,
            int broj_soba, bool namjesten_stan, double broj_kvadrata) : ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana),
            datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca),
            kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {}
    
    void PromijeniAgenta(const std::string &ime) { ime_agenta_prodaje=ime; }        
    void PromijeniKupca(const Kupac &novi_kupac) { kupac_stana=novi_kupac; }
    void PromijeniStan(const Stan &novi_stan) { kupljeni_stan=novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum) { datum_prodaje=novi_datum; }
    void PromijeniCijenuProdaje(const double &nova_cijena) { if(nova_cijena<0) throw std::domain_error ("Neispravan unos podataka"); cijena_stana=nova_cijena; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    void Ispisi() const;
    
    std::string DajImeAgenta() const { return ime_agenta_prodaje; }
    std::string DajImeKupca() const { return kupac_stana.DajImePrezime(); }
    Datum DajDatumProdaje() const { return datum_prodaje; }
    double DajCijenuStana() const { return cijena_stana; }
    
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    friend bool JednakeProdaje(const Prodaja &p1, const Prodaja &p2);
};
bool JednakeProdaje(const Prodaja &p1, const Prodaja &p2) {
    if(p1.ime_agenta_prodaje!=p2.ime_agenta_prodaje || p1.cijena_stana!=p2.cijena_stana || !JednakiDatumi(p1.datum_prodaje, p2.datum_prodaje) 
        || !JednakiKupci(p1.kupac_stana, p2.kupac_stana) || !JednakoStanovi(p1.kupljeni_stan, p2.kupljeni_stan)) return false;
    return true;
} 

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    if(p1.cijena_stana>p2.cijena_stana) return true;
    return false;
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    if(p1.datum_prodaje.DajGodinu() <  p2.datum_prodaje.DajGodinu()) return true;
    else if(p1.datum_prodaje.DajGodinu() >  p2.datum_prodaje.DajGodinu()) return false;
    else if(p1.datum_prodaje.DajMjesec() <  p2.datum_prodaje.DajMjesec()) return true;
    else if(p1.datum_prodaje.DajMjesec() >  p2.datum_prodaje.DajMjesec()) return false;
    else if(p1.datum_prodaje.DajDan() <  p2.datum_prodaje.DajDan()) return true;
    else if(p1.datum_prodaje.DajDan() >  p2.datum_prodaje.DajDan()) return false;
    return true;
}

void Prodaja::Ispisi() const {
    std::cout<<std::setw(32)<<std::left<<"Ime agenta:"<<std::right<<ime_agenta_prodaje<<std::endl
    <<std::setw(32)<<std::left<<"Ime kupca:"<<std::right; kupac_stana.Ispisi();std::cout<<std::endl
    <<std::setw(32)<<std::left<<"Zakazani datum prodaje:"<<std::right; datum_prodaje.Ispisi();
    std::cout<<std::endl<<std::setw(32)<<std::left<<"Cijena stana:"<<std::right<<cijena_stana<<std::endl
    <<std::setw(32)<<std::left<<"Informacije o stanu:"<<std::endl;
    kupljeni_stan.Ispisi();
}

int Prodaja::BrojDana(int mjesec, int g) {
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if((g%4==0  && g%100!=0) || g%400==0) broj_dana[1]++;
    return broj_dana[mjesec-1];
}

void Prodaja::PomjeriDanUnaprijed() {
    int dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec()), godina(datum_prodaje.DajGodinu());
    dan++;
    if(dan>Prodaja::BrojDana(mjesec, godina)) { dan=1; mjesec++; }
    if(mjesec>12) { mjesec=1; godina++; }
    datum_prodaje=Datum(dan, mjesec, godina);
    
}

void Prodaja::PomjeriDanUnazad() {
    int dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec()), godina(datum_prodaje.DajGodinu());
    dan--;
    if(dan<1) mjesec--;
    if(mjesec<1) { godina--; mjesec=12; dan=BrojDana(mjesec, godina); }
    else if(dan<1) dan=BrojDana(mjesec, godina);
    datum_prodaje=Datum(dan, mjesec, godina);
}

class Prodaje {
    
    Prodaja **prodaje;
    int max_broj_prodaja;
    
    public:
    
    explicit Prodaje(int max_broj_prodaja) : max_broj_prodaja(max_broj_prodaja) { prodaje=new Prodaja*[max_broj_prodaja] {}; }
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &p);
    Prodaje(Prodaje &&p);
    Prodaje &operator=(const Prodaje &p);
    Prodaje &operator=(Prodaje &&p);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
                            const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,
                            int godina_prodaje, std::string &ime_kupca, const Datum datum_rodjenja_kupca,
                            const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
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
    void IspisiSveProdaje() const;
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    Prodaja &DajProdaju(int n);
    
};

Prodaja &Prodaje::DajProdaju(int n) {
    if(n>max_broj_prodaja) throw std::domain_error ("Neispravan broj prodaje");
    for(int i=0; i<max_broj_prodaja; i++) {
        if(i==n-1) return *prodaje[i];
    }
}

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) {
        max_broj_prodaja=spisak_prodaja.size();
        try {
        prodaje=new Prodaja*[spisak_prodaja.size()] {};
        try {
            auto it(spisak_prodaja.begin());
            for(int i=0; i<spisak_prodaja.size(); i++) prodaje[i]=new Prodaja(*it++);
        }
        catch(...) {
            for(int i=0; i<spisak_prodaja.size(); i++) delete prodaje[i]; delete[] prodaje;
            throw;
        }
        }
        catch(...) {throw;}
   
}

Prodaje::~Prodaje() {
    for(int i=0; i<max_broj_prodaja; i++) delete prodaje[i];
    delete[] prodaje;
}

Prodaje::Prodaje(const Prodaje &p) {
    max_broj_prodaja=p.max_broj_prodaja;
    try {
        prodaje=new Prodaja*[max_broj_prodaja] {};
        try {
            for(int i=0; i<max_broj_prodaja; i++)
                prodaje[i]=new Prodaja(*(p.prodaje[i]));
        }
        catch(...) {
            for(int i=0; i<max_broj_prodaja; i++)
                delete prodaje[i]; delete[] prodaje; throw;
        }
    }
    catch(...) { throw; }
}

Prodaje::Prodaje(Prodaje &&p) {
    max_broj_prodaja=p.max_broj_prodaja;
    prodaje=p.prodaje;
    p.max_broj_prodaja=0; //Destruktor ce pokusati obrisati vec obrisane prodaje, ovako nece ni uci u for petlju
    p.prodaje=nullptr;    //Destruktor poslije for petlje ce pokusat obrisati vec obrisani niz pokazivaca, ovako se nece desiti nista
}

Prodaje &Prodaje::operator=(const Prodaje &p) {
    Prodaja **novi_prostor, **pom(prodaje);
    try {
    novi_prostor=new Prodaja*[p.max_broj_prodaja] {};
    prodaje=novi_prostor;
    try {
    for(int i=0; i<p.max_broj_prodaja; i++) {
        if(p.prodaje[i]==nullptr) continue;     //Pazi da ukoliko se dodjeljuje Prodaje koji je samo niz pokazivaca koji ne pokazuje ni na sta, ne dodje do krahiranja i ostalih popratnih atomskih bombi
        prodaje[i]=new Prodaja(*(p.prodaje[i]));
    }
    }
    catch(...) {
        for(int i=0; i<p.max_broj_prodaja; i++) delete prodaje[i]; delete[] prodaje;
        prodaje=pom; throw;
    }
    }
    catch(...) { throw; }
    for(int i=0; i<max_broj_prodaja; i++) delete pom[i]; delete[] pom;
    max_broj_prodaja=p.max_broj_prodaja;
    return *this;
}

Prodaje &Prodaje::operator=(Prodaje &&p) {
    if(&p!=this) {
        for(int i=0; i<max_broj_prodaja; i++) delete prodaje[i]; delete[] prodaje;
        prodaje=p.prodaje;
        max_broj_prodaja=p.max_broj_prodaja;
        p.max_broj_prodaja=0;
        p.prodaje=nullptr;
    }
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
                            const Kupac &kupac_stana, const Stan &kupljeni_stan) {
      int i;
      for(i=0; i<max_broj_prodaja; i++) {
          if(prodaje[i]==nullptr) {
              prodaje[i]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje, kupac_stana, kupljeni_stan);
              break;
          }
      }
      if(i==max_broj_prodaja) throw std::range_error ("Dostignut maksimalni broj prodaja");
        
    }

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,
                            int godina_prodaje, std::string &ime_kupca, const Datum datum_rodjenja_kupca,
                            const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
     
      int i;
      for(i=0; i<max_broj_prodaja; i++) {
          if(prodaje[i]==nullptr) {
              prodaje[i]=new Prodaja(ime_agenta_prodaje,cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca,
                                     datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
              break;
          }
      }
      if(i==max_broj_prodaja) throw std::range_error ("Dostignut maksimalni broj prodaja");
        
    }                         
   
void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
        int i;
      for(i=0; i<max_broj_prodaja; i++) {
          if(prodaje[i]==nullptr) {
              prodaje[i]=prodaja;
              break;
          }
      }
      if(i==max_broj_prodaja) throw std::range_error ("Dostignut maksimalni broj prodaja");
        
    }

int Prodaje::DajBrojProdaja() const {
    int broj(0);
    for(int i=0; i<max_broj_prodaja; i++) {
        if(prodaje[i]!=nullptr) broj++;
    }
    return broj;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    int broj(0);
    
    for(int i=0; i<max_broj_prodaja; i++) {
        if(prodaje[i]==nullptr) continue;
        Datum pom(prodaje[i]->DajDatumProdaje());
        if(pom.DajDan()==datum.DajDan() && pom.DajMjesec()==datum.DajMjesec() && pom.DajGodinu()==datum.DajGodinu()) broj++;
    }
    return broj;
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
     int broj(0);
    
    for(int i=0; i<max_broj_prodaja; i++) {
        if(prodaje[i]==nullptr) continue;
        std::string ime(prodaje[i]->DajImeAgenta());
        if(ime==ime_agenta) broj++;
    }
    return broj;
}

Prodaja &Prodaje::DajNajranijuProdaju() {
    if(DajBrojProdaja()==0) throw std::domain_error ("Nema registriranih prodaja");
    Prodaja **pom;
    pom=std::min_element(prodaje, prodaje+max_broj_prodaja, [] (Prodaja *x, Prodaja *y) {
        if(x==nullptr) return false;
        if(y==nullptr) return true;
        return ProdatPrije(*x, *y);
    });
    return **pom;
}
Prodaja Prodaje::DajNajranijuProdaju() const {
    if(DajBrojProdaja()==0) throw std::domain_error ("Nema registriranih prodaja");
    Prodaja **pom;
    pom=std::min_element(prodaje, prodaje+max_broj_prodaja, [] (Prodaja *x, Prodaja *y) {
        if(x==nullptr) return false;
        if(y==nullptr) return true;
        return ProdatPrije(*x, *y);
    });
    return **pom;
}
Prodaja &Prodaje::DajNajskupljuProdaju() {
    if(DajBrojProdaja()==0) throw std::domain_error ("Nema registriranih prodaja");
    Prodaja **pom;
    pom=std::min_element(prodaje, prodaje+max_broj_prodaja, [] (Prodaja *x, Prodaja *y) {
        if(x==nullptr) return false;
        if(y==nullptr) return true;
        return SkupljiStan(*x, *y);
    });
    return **pom;
}
Prodaja Prodaje::DajNajskupljuProdaju() const {
    if(DajBrojProdaja()==0) throw std::domain_error ("Nema registriranih prodaja");
    Prodaja **pom;
    pom=std::min_element(prodaje, prodaje+max_broj_prodaja, [] (Prodaja *x, Prodaja *y) {
        if(x==nullptr) return false;
        if(y==nullptr) return true;
        return SkupljiStan(*x, *y);
    });
    return **pom;
}
void Prodaje::IsprazniKolekciju() {
    for(int i=0; i<max_broj_prodaja; i++) {
        if(prodaje[i]==nullptr) continue;
        delete prodaje[i];
        prodaje[i]=nullptr;
        
    }
}

void Prodaje::ObrisiNajranijuProdaju() {
    if(DajBrojProdaja()==0) throw std::range_error ("Kolekcija prazna");
    Prodaja najranija{DajNajranijuProdaju()};
    for(int i=0; i<max_broj_prodaja; i++) {
        if(prodaje[i]==nullptr) continue;
        Prodaja pom{*prodaje[i]};
        if(JednakeProdaje(pom,najranija)) {
            delete prodaje[i];
            prodaje[i]=nullptr;
            break;
        }
    }
}

void Prodaje::IspisiSveProdaje() const {
    Prodaja **pomocni (new Prodaja*[DajBrojProdaja()]);
    int j(0);
    for(int i=0; i<max_broj_prodaja; i++) {
        if(prodaje[i]==nullptr) continue;
        pomocni[j]=prodaje[i];
        j++;
    }
    std::sort(pomocni, pomocni+DajBrojProdaja(), [] (Prodaja *x, Prodaja *y) {
        if(!JednakiDatumi(x->DajDatumProdaje(), y->DajDatumProdaje())) return ProdatPrije(*x,*y);
        else return x->DajImeKupca() < y->DajImeKupca();
    });
    for(int i=0; i<DajBrojProdaja(); i++) {
        pomocni[i]->Ispisi(); std::cout<<std::endl;
    }
    delete[] pomocni;
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
    
    for(int i=0; i<max_broj_prodaja; i++) {
        if(prodaje[i]==nullptr) continue;
        if(prodaje[i]->DajImeAgenta()==ime_agenta) {
            delete prodaje[i];
            prodaje[i]=nullptr;
        }
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
    for(int i=0; i<max_broj_prodaja; i++) {
        if(prodaje[i]==nullptr) continue;
        Datum pom(prodaje[i]->DajDatumProdaje());
        if(pom.DajDan()==datum.DajDan() && pom.DajMjesec()==datum.DajMjesec() && pom.DajGodinu()==datum.DajGodinu()) {
            delete prodaje[i];
            prodaje[i]=nullptr;
        }
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    Prodaja **pomocni (new Prodaja*[DajBrojProdaja()]);
    int j(0);
    for(int i=0; i<max_broj_prodaja; i++) {
        if(prodaje[i]==nullptr) continue;
        pomocni[j]=prodaje[i];
        j++;
    }
    std::sort(pomocni, pomocni+DajBrojProdaja(), [] (Prodaja *x, Prodaja *y) {
        return x->DajImeKupca() < y->DajImeKupca();
    });
    
    for(int i=0; i<DajBrojProdaja(); i++) {
        
        Datum pom(pomocni[i]->DajDatumProdaje());
        if(JednakiDatumi(pom,datum)) {
            pomocni[i]->Ispisi();
        }
    }
    delete[] pomocni;
}

//Ispod su funkcije za rad sa main-om

void DodavanjeStana(std::vector<Stan> &stanovi) {
    std::string adresa;
    int sprat, broj_soba, pom;
    bool namjesten;
    double kvadratura;
    bool unos_zavrsen(true);
    for(;;) {
        std::cin.ignore(1000, '\n');
        std::cout<<"Unesite adresu: ";
        std::getline(std::cin, adresa);
        
        std::cout<<"Unesite sprat: ";
        std::cin>>sprat;
        std::cout<<"Unesite broj soba: ";
        std::cin>>broj_soba;
        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
        std::cin>>pom; if(pom==1) namjesten=true; else if(pom==0) namjesten=false;
        std::cout<<"Unesite kvadraturu: ";
        std::cin>>kvadratura;
        try { 
            if(pom!=1 && pom!=0) throw std::domain_error("Neispravan unos podataka.");
            Stan privremeni(adresa, sprat, broj_soba, namjesten, kvadratura);
            stanovi.push_back(privremeni);
            unos_zavrsen=true;
        }
        catch(std::domain_error greska) {
            std::cout<<"Izuzetak: "<<greska.what()<<" Molimo unesite opet.\n";
            unos_zavrsen=false;
        }
        if(unos_zavrsen) {
            break;
        }
    
    }
}

void IspisSvihStanova(const std::vector<Stan> &stanovi) {
    for(int i=0; i<stanovi.size(); i++) {
        std::cout<<i+1<<". "; stanovi[i].Ispisi();
        std::cout<<std::endl;
    }
}

void UredjivanjeStanova(std::vector<Stan> &stanovi) {
    std::cout<<"Odaberite stan. Dostupni stanovi su:\n";
    int opcija(-1), opcija2;
    for(int i=0; i<stanovi.size(); i++) {
        std::cout<<" "<<i+1<<" - "; stanovi[i].Ispisi();
        std::cout<<std::endl;
    }
    
    std::cin>>opcija;
    std::cout<<"\nOdaberite polje koje zelite urediti:\n"<<
                " 0 - nazad\n"<<
                " 1 - adresa\n"<<
                " 2 - sprat\n"<<
                " 3 - broj soba\n"<<
                " 4 - da li je stan namjesten\n"<<
                " 5 - kvadratura\n"<<
                " 6 - sve\n";
    std::cin>>opcija2;
    if(opcija2==0) return;
    else if(opcija2==1) {
        bool unos_zavrsen;
        for(;;) {
        std::string adresa;
        std::cin.ignore(1000, '\n');
        std::cout<<"Unesite adresu: ";
        std::getline(std::cin,adresa);
        try {
        stanovi[opcija-1]=Stan(adresa, stanovi[opcija-1].DajSprat() ,stanovi[opcija-1].DajBrojSoba(), stanovi[opcija-1].DajNamjesten(), stanovi[opcija-1].DajKvadraturu());
        unos_zavrsen=true;
        }
        catch(std::domain_error greska) {
            std::cout<<"Izuzetak: "<<greska.what()<<" Molimo unesite opet.\n";
            unos_zavrsen=false;
        }
        if(unos_zavrsen) {
            std::cout<<"Stan je uspjesno izmijenjen!\n";
            break;
        }
        }
    }
    else if(opcija2==2) {
        bool unos_zavrsen;
        for(;;) {
        int sprat;
        std::cout<<"Unesite sprat: ";
        std::cin>>sprat;
        try {
        stanovi[opcija-1]=Stan(stanovi[opcija-1].DajAdresu(), sprat ,stanovi[opcija-1].DajBrojSoba(), stanovi[opcija-1].DajNamjesten(), stanovi[opcija-1].DajKvadraturu());
        unos_zavrsen=true;
        }
        catch(std::domain_error greska) {
            std::cout<<"Izuzetak: "<<greska.what()<<" Molimo unesite opet.\n";
            unos_zavrsen=false;
        }
        if(unos_zavrsen) {
            std::cout<<"Stan je uspjesno izmijenjen!\n";
            break;
        }
        }
    }
    else if(opcija2==3) {
        bool unos_zavrsen;
        for(;;) {
        int broj_soba;
        std::cout<<"Unesite broj soba: ";
        std::cin>>broj_soba;
        try {
        stanovi[opcija-1]=Stan(stanovi[opcija-1].DajAdresu(), stanovi[opcija-1].DajSprat() ,broj_soba, stanovi[opcija-1].DajNamjesten(), stanovi[opcija-1].DajKvadraturu());
        unos_zavrsen=true;
        }
        catch(std::domain_error greska) {
            std::cout<<"Izuzetak: "<<greska.what()<<" Molimo unesite opet.\n";
            unos_zavrsen=false;
        }
        if(unos_zavrsen) {
            std::cout<<"Stan je uspjesno izmijenjen!\n";
            break;
        }
        }
    }
    else if(opcija2==4) {
        bool unos_zavrsen;
        for(;;) {
        int pom;
        bool namjesten(true);
        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
        std::cin>>pom;
        try {
        if(pom!=1 && pom!=0) throw std::domain_error ("Neispravan unos podataka.");
        if(pom==1) namjesten=true; else if(pom==0) namjesten=false;
        stanovi[opcija-1]=Stan(stanovi[opcija-1].DajAdresu(), stanovi[opcija-1].DajSprat() ,stanovi[opcija-1].DajBrojSoba(), namjesten, stanovi[opcija-1].DajKvadraturu());
        unos_zavrsen=true;
        }
        catch(std::domain_error greska) {
            std::cout<<"Izuzetak: "<<greska.what()<<" Molimo unesite opet.\n";
            unos_zavrsen=false;
        }
        if(unos_zavrsen) {
            std::cout<<"Stan je uspjesno izmijenjen!\n";
            break;
        }
        }
    }
    else if(opcija2==5) {
        bool unos_zavrsen;
        for(;;) {
        double kvadratura;
        std::cout<<"Unesite kvadraturu: ";
        std::cin>>kvadratura;
        try {
        stanovi[opcija-1]=Stan(stanovi[opcija-1].DajAdresu(), stanovi[opcija-1].DajSprat() ,stanovi[opcija-1].DajBrojSoba(), stanovi[opcija-1].DajNamjesten(), kvadratura);
        unos_zavrsen=true;
        }
        catch(std::domain_error greska) {
            std::cout<<"Izuzetak: "<<greska.what()<<" Molimo unesite opet.\n";
            unos_zavrsen=false;
        }
        if(unos_zavrsen) {
            std::cout<<"Stan je uspjesno izmijenjen!\n";
            break;
        }
        }
    }
    else if(opcija2==6) {
        std::string adresa;
    int sprat, broj_soba, pom;
    bool namjesten;
    double kvadratura;
    bool unos_zavrsen(true);
    for(;;) {
        std::cin.ignore(1000, '\n');
        std::cout<<"Unesite adresu: ";
        std::getline(std::cin,adresa);
        std::cout<<"Unesite sprat: ";
        std::cin>>sprat;
        std::cout<<"Unesite broj soba: ";
        std::cin>>broj_soba;
        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
        std::cin>>pom; if(pom==1) namjesten=true; else if(pom==0) namjesten=false;
        std::cout<<"Unesite kvadraturu: ";
        std::cin>>kvadratura;
        try { 
            if(pom!=1 && pom!=0) throw std::domain_error("Neispravan unos podataka.");
            Stan privremeni(adresa, sprat, broj_soba, namjesten, kvadratura);
            stanovi[opcija-1]=privremeni;
            unos_zavrsen=true;
        }
        catch(std::domain_error greska) {
            std::cout<<"Izuzetak: "<<greska.what()<<" Molimo unesite opet.\n";
            unos_zavrsen=false;
        }
        if(unos_zavrsen) {
            std::cout<<"Stan je uspjesno izmijenjen!\n";
            break;
        }
    
    }
        
    }

}

bool Meni1(std::vector<Stan> &stanovi) {
    int opcija(-1);
    while(opcija!=0) {
        
       std::cout<<"\nIzaberite opciju:\n"<<
                    " 0 - nazad\n"<<
                    " 1 - dodavanje stana\n"<<
                    " 2 - uredjivanje stanova\n"<<
                    " 3 - ispis svih stanova\n"<<
                    " 4 - kraj\n"; 
        std::cin>>opcija;
        
        if(opcija==0) return true;
        if(opcija==4) return false;
        if(opcija==1) { 
            DodavanjeStana(stanovi);
            std::cout<<"Stan je uspjesno dodan!\n";
        }
        if(opcija==3) {
            IspisSvihStanova(stanovi);
        }
        if(opcija==2) {
            UredjivanjeStanova(stanovi);
        }
    }
    return true;
}

void DodavanjeKupaca(std::vector<Kupac> &kupci) {
    std::string ime;
    int dan,mjesec,godina;
    bool unos_zavrsen;
    for(;;) {
    std::cin.ignore(1000, '\n');
    std::cout<<"Unesite ime i prezime kupca: ";
    std::getline(std::cin, ime);
    std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
    std::cin>>dan;
    std::cin.ignore(1);
    std::cin>>mjesec;
    std::cin.ignore(1);
    std::cin>>godina;
    
    try {
        Kupac privremeni(ime, {dan, mjesec, godina});
        kupci.push_back(privremeni);
        unos_zavrsen=true;
    }
    catch(std::domain_error greska) {
        std::cout<<"Izuzetak: "<<greska.what()<<" Molimo unesite opet.\n";
        unos_zavrsen=false;
    }
    if(unos_zavrsen) {
        
        break;
    }
    }
}

void IspisSvihKupaca(const std::vector<Kupac> &kupci) {
    for(int i=0; i<kupci.size(); i++) {
        kupci[i].Ispisi(); std::cout<<std::endl;
    }
} 

void UredjivanjeKupaca(std::vector<Kupac> &kupci) {
    std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:\n";
    int opcija(-1);
    for(int i=0; i<kupci.size(); i++) {
        std::cout<<" "<<i+1<<" - "; kupci[i].Ispisi();
        std::cout<<std::endl;
    }
    
    std::cin>>opcija;
    
    std::string ime;
    int dan,mjesec,godina;
    bool unos_zavrsen;
    for(;;) {
    std::cin.ignore(1000, '\n');
    std::cout<<"Unesite ime i prezime kupca: ";
    std::getline(std::cin, ime);
    std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
    std::cin>>dan;
    std::cin.ignore(1);
    std::cin>>mjesec;
    std::cin.ignore(1);
    std::cin>>godina;
    
    try {
        Kupac privremeni(ime, {dan, mjesec, godina});
        kupci[opcija-1]=privremeni;
        unos_zavrsen=true;
    }
    catch(std::domain_error greska) {
        std::cout<<"Izuzetak: "<<greska.what()<<" Molimo unesite opet.\n";
        unos_zavrsen=false;
    }
    if(unos_zavrsen) {
        std::cout<<"Kupac je uspjesno izmijenjen!\n";
        break;
    }
    }
    
}

bool Meni2(std::vector<Kupac> &kupci) {
    int opcija(-1);
    while(opcija!=0) {
        std::cin.ignore(10000, '\n');
       std::cout<<"\nIzaberite opciju:\n"<<
                    " 0 - nazad\n"<<
                    " 1 - dodavanje kupca\n"<<
                    " 2 - uredjivanje kupaca\n"<<
                    " 3 - ispis svih kupaca\n"<<
                    " 4 - kraj\n"; 
        std::cin>>opcija;
        
        if(opcija==0) return true;
        if(opcija==4) return false;
        if(opcija==1) { 
            DodavanjeKupaca(kupci);
            std::cout<<"Kupac je uspjesno dodan!\n";
        }
        if(opcija==3) {
            IspisSvihKupaca(kupci);
        }
        if(opcija==2) {
            UredjivanjeKupaca(kupci);
        }
    }
    return true;
}

bool DodavanjeProdaje(Prodaje &prodaje, std::vector<Stan> &stanovi, std::vector<Kupac> &kupci) {
    int opcija(-1);
    while(opcija!=0) {
        std::cin.ignore(10000, '\n');
       std::cout<<"\nIzaberite opciju:\n"<<
                    " 0 - nazad\n"<<
                    " 1 - dodavanje potpuno nove prodaje\n"<<
                    " 2 - dodavanje nove prodaje na osnovu arhive\n"<<
                    " 3 - kraj\n"; 
        std::cin>>opcija;
        if(opcija==0) return true;
        if(opcija==3) return 0;
        if(opcija==1) {
            std::string ime_agenta, ime_kupca, adresa;
            int danp, mjesecp, godinap, danr, mjesecr,godinar, sprat, broj_soba, pom ;
            double cijena_stana, kvadratura;
            bool namjesten, unos_zavrsen;
            for(;;) {
                std::cin.ignore(1000, '\n');
                std::cout<<"Unesite ime i prezime agenta prodaje: "; std::getline(std::cin,ime_agenta);
                std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                std::cin>>danp; std::cin.ignore(1); std::cin>>mjesecp; std::cin.ignore(1); std::cin>>godinap;
                std::cout<<"Unesite cijenu stana: "; std::cin>>cijena_stana;
                std::cin.ignore(1000, '\n');
                std::cout<<"Unesite ime kupca: "; std::getline(std::cin, ime_kupca);
                std::cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
                std::cin>>danr; std::cin.ignore(1); std::cin>>mjesecr; std::cin.ignore(1); std::cin>>godinar;
                std::cin.ignore(1000, '\n');
                std::cout<<"Unesite adresu: "; std::getline(std::cin, adresa);
                std::cout<<"Unesite sprat: "; std::cin>>sprat;
                std::cout<<"Unesite broj soba: "; std::cin>>broj_soba;
                std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): "; std::cin>>pom;
                std::cout<<"Unesite kvadraturu: "; std::cin>>kvadratura;
                try {
                    if(pom!=1 && pom!=0) throw std::domain_error("Neispravan unos podataka.");
                    if(pom==1) namjesten=true; else if(pom==0) namjesten=false;
                    prodaje.RegistrirajProdaju(ime_agenta, cijena_stana, danp, mjesecp, godinap, ime_kupca, {danr,mjesecr,godinar},
                                                adresa, sprat, broj_soba, namjesten, kvadratura);
                    kupci.push_back(Kupac(ime_kupca, {danr,mjesecr, godinar}));
                    stanovi.push_back(Stan(adresa, sprat, broj_soba, namjesten,kvadratura));
                    unos_zavrsen=true;
                    
                }
                catch(std::domain_error greska) {
                    std::cout<<"Izuzetak: "<<greska.what()<<" Molimo unesite opet.\n";
                    unos_zavrsen=false;
                }
                if(unos_zavrsen) {
                    std::cout<<"Prodaja uspjesno dodana!\n";
                    break;
                }
            }
        }
        if(opcija==2) {
            for(;;) {
                int k,s, danp, mjesecp, godinap; bool unos_zavrsen;
                std::string ime_agenta; double cijena_stana;
                std::cin.ignore(1000, '\n');
                std::cout<<"Unesite ime i prezime agenta prodaje: "; std::getline(std::cin,ime_agenta);
                std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                std::cin>>danp; std::cin.ignore(1); std::cin>>mjesecp; std::cin.ignore(1); std::cin>>godinap;
                std::cout<<"Unesite cijenu stana: "; std::cin>>cijena_stana;
                std::cout<<"Odaberite kupca. Dostupni kupci su:\n";
                for(int i=0; i<kupci.size(); i++) {
                    std::cout<<" "<<i+1<<" - "; kupci[i].Ispisi(); std::cout<<std::endl;
                }
                std::cin>>k;
                std::cout<<"Odaberite stan. Dostupni stanovi su:\n";
                for(int i=0; i<stanovi.size(); i++) {
                    std::cout<<" "<<i+1<<" - "; stanovi[i].Ispisi(); std::cout<<std::endl;
                }
                std::cin>>s;
                try {
                    prodaje.RegistrirajProdaju(ime_agenta, cijena_stana, {danp, mjesecp, godinap}, kupci[k-1], stanovi[s-1]);
                    unos_zavrsen=true;
                }
                catch(std::domain_error greska) {
                    std::cout<<"Izuzetak: "<<greska.what()<<" Molimo unesite opet.";
                    unos_zavrsen=false;
                }
                if(unos_zavrsen) {
                    std::cout<<"Prodaja uspjesno dodana!\n";
                    break;
                }
            
            }
        }
        
    }
    return true;
}

bool UredjivanjeProdaje(Prodaje &prodaje, std::vector<Stan> &stanovi, std::vector<Kupac> &kupci) {
    int opcija_prodaja, opcija;
    std::cout<<"Odaberite prodaju koju želite urediti. Dostupne prodaje su:\n";
    for(int i=1; i<=prodaje.DajBrojProdaja(); i++) {
        std::cout<<i<<".\n"; prodaje.DajProdaju(i).Ispisi(); std::cout<<std::endl;
    }
    std::cin>>opcija_prodaja;
    std::cout<<"\nIzaberite opciju:\n"<<
                    " 0 - nazad\n"<<
                    " 1 - izmjena agenta\n"<<
                    " 2 - izmjena datuma prodaje\n"<<
                    " 3 - izmjena kupca\n"<<
                    " 4 - izmjena stana\n"<<
                    " 5 - izmjena cijene stana\n"; 
        std::cin>>opcija;
    if(opcija==0) return true;
    if(opcija==1) {
        std::string ime_agenta;
        std::cin.ignore(1000, '\n');
        std::cout<<"Unesite ime i prezime agenta prodaje: "; std::getline(std::cin, ime_agenta);
        prodaje.DajProdaju(opcija_prodaja).PromijeniAgenta(ime_agenta);
    }
    if(opcija==2) {
        for(;;) {
        int d,m,g; bool unos_zavrsen;
        std::cout<<"Unesite datum prodaje (formata d/m/g): ";
        std::cin>>d; std::cin.ignore(1); std::cin>>m; std::cin.ignore(1); std::cin>>g;
        try {
        prodaje.DajProdaju(opcija_prodaja).PromijeniDatumKupovine({d,m,g});
        unos_zavrsen=true;
        }
        catch(std::domain_error g) {
            std::cout<<"Izuzetak: "<<g.what()<<" Molimo unesite opet.\n";
            unos_zavrsen=false;
        }
        if(unos_zavrsen) break;
        }
    }
    if(opcija==3) {
        int opcija_kupac,k;
        std::cout<<"Izaberite opciju:\n"<<
                    " 0 - nazad\n"<<
                    " 1 - odabir postojeceg kupca\n"<<
                    " 2 - dodavanje novog kupca\n";
        std::cin>>opcija_kupac;
        if(opcija_kupac==0) return true;
        if(opcija_kupac==1) {
            std::cout<<"Odaberite kupca. Dostupni kupci su:\n";
            for(int i=0; i<kupci.size(); i++) {
                std::cout<<" "<<i+1<<" - "; kupci[i].Ispisi(); std::cout<<std::endl;
            }
            std::cin>>k;
            prodaje.DajProdaju(opcija_prodaja).PromijeniKupca(kupci[k-1]);
            
        }
        if(opcija_kupac==2) {
            bool unos_zavrsen;
            for(;;) {
            try {
            DodavanjeKupaca(kupci);
            prodaje.DajProdaju(opcija_prodaja).PromijeniKupca(kupci[kupci.size()-1]);
            unos_zavrsen=true;
            }
            catch(std::domain_error g) {
                std::cout<<"Izuzetak: "<<g.what()<<" Molimo unesite opet.\n";
                unos_zavrsen=false;
            }
            if(unos_zavrsen) break;
            }
            
        }
    }
    if(opcija==4) {
         int opcija_stan,s;
        std::cout<<"Izaberite opciju:\n"<<
                    " 0 - nazad\n"<<
                    " 1 - odabir postojeceg stana\n"<<
                    " 2 - dodavanje novog stana\n";
        std::cin>>opcija_stan;
        if(opcija_stan==0) return true;
        if(opcija_stan==1) {
            std::cout<<"Odaberite stan. Dostupni stanovi su:\n";
            for(int i=0; i<stanovi.size(); i++) {
                std::cout<<" "<<i+1<<" - "; stanovi[i].Ispisi(); std::cout<<std::endl;
            }
            std::cin>>s;
            prodaje.DajProdaju(opcija_prodaja).PromijeniStan(stanovi[s-1]);
            
        }
        if(opcija_stan==2) {
            bool unos_zavrsen;
            for(;;) {
            try {
            DodavanjeStana(stanovi);
            prodaje.DajProdaju(opcija_prodaja).PromijeniStan(stanovi[stanovi.size()-1]);
            unos_zavrsen=true;
            }
            catch(std::domain_error g) {
                std::cout<<"Izuzetak: "<<g.what()<<" Molimo unesite opet.\n";
                unos_zavrsen=false;
            }
            if(unos_zavrsen) break;
            }
            
        }
    }
    
    if(opcija==5) {
        double cijena; bool unos_zavrsen;
        for(;;) {
            std::cout<<"Unesite cijenu stana: ";
            std::cin>>cijena;
            try {
                prodaje.DajProdaju(opcija_prodaja).PromijeniCijenuProdaje(cijena);
                unos_zavrsen=true;
            }
            catch(std::domain_error g) {
                std::cout<<"Izuzetak: "<<g.what()<<" Molimo unesite opet.\n";
                unos_zavrsen=false;
            }
            if(unos_zavrsen) break;
        }
    }
    
    std::cout<<"Prodaja je uspjesno izmijenjena!\n";
    return true;
}

bool IspisProdaja(const Prodaje &prodaje) {
    int opcija(-1);
    while(opcija!=0) {
        
       std::cout<<"\nIzaberite opciju:\n"<<
                    " 0 - nazad\n"<<
                    " 1 - ispis svih prodaja\n"<<
                    " 2 - ispis prodaja na datum\n"<<
                    " 3 - ispis najranije prodaje\n"<<
                    " 4 - ispis najskuplje prodaje\n"<<
                    " 5 - ispis broja prodaja\n"<<
                    " 6 - ispis broja prodaja po datumu\n"<<
                    " 7 - ispis broja prodaja po agentu\n"<<
                    " 8 - kraj\n";
        std::cin>>opcija;
        if(opcija==0) return true;
        if(opcija==8) return false;
        if(opcija==1) prodaje.IspisiSveProdaje();
        if(opcija==2) {
            int d,m,g;
            std::cout<<"Unesite datum (d/m/g): ";
            std::cin>>d; std::cin.ignore(1); std::cin>>m; std::cin.ignore(1); std::cin>>g;
            Datum pom(d,m,g);
            std::cout<<"Prodaje na datum: "; pom.Ispisi(); std::cout<<" su:\n";
            prodaje.IspisiProdajeNaDatum(pom);
        }
        if(opcija==3) {
            prodaje.DajNajranijuProdaju().Ispisi();
        }
        if(opcija==4) {
            prodaje.DajNajskupljuProdaju().Ispisi();
        }
        if(opcija==5) {
            std::cout<<"Broj prodaja: "<<prodaje.DajBrojProdaja();
        }
        if(opcija==6) {
           int d,m,g;
            std::cout<<"Unesite datum (d/m/g): ";
            std::cin>>d; std::cin.ignore(1); std::cin>>m; std::cin.ignore(1); std::cin>>g;
            std::cout<<"Broj prodaja na uneseni datum: "<<prodaje.DajBrojProdajaNaDatum({d,m,g});
            
        }
        if(opcija==7) {
            std::string ime;
            std::cout<<"Unesite ime agenta: ";
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, ime);
            std::cout<<"Broj prodaja: "<<prodaje.DajBrojProdajaOdAgenta(ime);
            
        }
        
    }
    return true;
}

bool BrisanjeProdaja(Prodaje &prodaje) {
    int opcija(-1);
    while(opcija!=0) {
        
       std::cout<<"\nIzaberite opciju:\n"<<
                    " 0 - nazad\n"<<
                    " 1 - brisanje najranije prodaje\n"<<
                    " 2 - brisanje prodaja agenta\n"<<
                    " 3 - brisanje prodaja po datumu\n"<<
                    " 4 - brisanje svih prodaja\n";
        std::cin>>opcija;
        
        if(opcija==0) return true;
        if(opcija==1) {
            try {
            prodaje.ObrisiNajranijuProdaju();
            std::cout<<"Najranija prodaja je obrisana!";
            }
            catch(std::range_error g) {
                std::cout<<"Izuzetak: "<<g.what();
            }
        }
        if(opcija==3) {
           int d,m,g;
            std::cout<<"Unesite datum: ";
            std::cin>>d; std::cin.ignore(1); std::cin>>m; std::cin.ignore(1); std::cin>>g; 
            prodaje.ObrisiProdajeNaDatum({d,m,g});
            std::cout<<"Sve prodaje na taj datum su obrisane.";
        }
        if(opcija==2) {
            std::string ime;
            std::cout<<"Unesite ime agenta: ";
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, ime);
            prodaje.ObrisiProdajeAgenta(ime);
            std::cout<<"Sve prodaje tog agenta su obrisane.";
        }
        if(opcija==4) {
            prodaje.IsprazniKolekciju();
            std::cout<<"Sve prodaje su obrisane.";
        }
    }
    return true;
}

bool Meni3(Prodaje &prodaje, std::vector<Stan> &stanovi, std::vector<Kupac> &kupci) {
    int opcija(-1);
    while(opcija!=0) {
        
       std::cout<<"\nIzaberite opciju:\n"<<
                    " 0 - nazad\n"<<
                    " 1 - dodavanje prodaje\n"<<
                    " 2 - uredjivanje prodaje\n"<<
                    " 3 - ispis prodaja\n"<<
                    " 4 - brisanje prodaja\n"<<
                    " 5 - kraj\n"; 
        std::cin>>opcija;
        
        if(opcija==0) return true;
        if(opcija==5) return false;
        if(opcija==1) { 
            if(!DodavanjeProdaje(prodaje, stanovi, kupci)) return false;
        }
       if(opcija==2) {
            if(!UredjivanjeProdaje(prodaje, stanovi, kupci)) return false;
        }
        if(opcija==3) {
            if(!IspisProdaja(prodaje)) return false;
        }
        if(opcija==4) {
            if(!BrisanjeProdaja(prodaje)) return false;
        }
    }
    return true;
}

int main ()
{ 

    std::vector<Stan> stanovi;
    std::vector<Kupac> kupci;
    Prodaje prodaje(20);
    
    
    std::cout<<"Dobrodosli!\n\n";
    
    int opcija(-1);
    while(opcija!=0) {
        std::cout<<"\nIzaberite opciju:\n"<<
                    " 0 - kraj\n"<<
                    " 1 - uredjivanje stanova\n"<<
                    " 2 - uredjivanje kupaca\n"<<
                    " 3 - uredjivanje prodaja\n";
        std::cin>>opcija;
        if(opcija==0) break;
        if(opcija==1) if(!Meni1(stanovi)) break;
        if(opcija==2) if(!Meni2(kupci)) break;
        if(opcija==3) if(!Meni3(prodaje,stanovi,kupci)) break;
    }
    
    std::cout<<"Dovidjenja!";


    
	return 0;
}