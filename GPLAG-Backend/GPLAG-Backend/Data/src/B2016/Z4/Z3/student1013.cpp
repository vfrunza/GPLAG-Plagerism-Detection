/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <algorithm>

bool ProvjeriDatum (int dan, int mjesec, int godina) {
    if(godina<0 or mjesec<=0 or mjesec>12 or dan<=0 or dan>31) return false;
    bool prestupna=false;
    if(godina%4==0 and !(godina%100==0) or godina%400==0) prestupna=true;
    if(mjesec==2) {
        if(prestupna) if(dan>29) return false;
        else {
            if(dan>28) return false;
        }
    }
    else if(mjesec==4 or mjesec==6 or mjesec==9 or mjesec==11) if(dan>30) return false;
    return true;
}

bool JeLiSlovo (char a) {
    return ((a>='a' and a<='z') or (a>='A' and a<='Z'));
}

bool ProvjeriImePrezime(std::string s) {
    for(int i=0;i<s.length();i++) {
        if(!JeLiSlovo(s[i]) and s[i]!=' ' and s[i]!='-' and (s[i]<'0' or s[i]>'9')) return false;
    }
    return true;
}

class Datum {
    int d;
    int m;
    int g;
    public:
        Datum(int dan, int mjesec, int godina);
        void Postavi (int dan, int mjesec, int godina);
        int DajDan() const { return d; }
        int DajMjesec() const { return m; }
        int DajGodinu() const { return g; }
        void Ispisi() const;
};

void Datum::Ispisi() const {
    std::cout << d << "/"<< m << "/" << g;
}

Datum::Datum (int dan, int mjesec, int godina) {
    if(!ProvjeriDatum(dan,mjesec,godina)) throw std::domain_error ("Neispravan datum");
    d=dan;
    m=mjesec;
    g=godina;
}

void Datum::Postavi (int dan, int mjesec, int godina) {
    if(!ProvjeriDatum(dan,mjesec,godina)) throw std::domain_error ("Neispravan datum");
    d=dan;
    m=mjesec;
    g=godina;
}

class Kupac {
    std::string ImePrezime;
    Datum datum{0,0,0};
    public:
        Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
        void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
        std::string DajImePrezime() const { return ImePrezime; }
        Datum DajDatumRodjenja() const { return datum; }
        void Ispisi() const;
};

void Kupac::Ispisi() const {
    std::cout << ImePrezime << "(";
    datum.Ispisi();
    std::cout << ")" ;
}

Kupac::Kupac (const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    if(!ProvjeriImePrezime(ime_i_prezime)) throw std::domain_error ("Neispravno ime i prezime");
    try {
        datum.Postavi(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
    }
    catch(...) {
        throw;
    }
    ImePrezime=ime_i_prezime;
}

void Kupac::Postavi (const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    if(!ProvjeriImePrezime(ime_i_prezime)) throw std::domain_error ("Neispravno ime i prezime");
    try {
        datum.Postavi(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
    }
    catch(...) {
        throw;
    }
    ImePrezime=ime_i_prezime;
}

class Stan {
    std::string adr;
    int spr;
    int sobe;
    bool namj;
    double kvad;
    public:
        Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
        void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
        std::string DajAdresu() const { return adr; }
        int DajSprat() const { return spr; }
        int DajBrojSoba() const { return sobe; }
        bool DajNamjesten() const { return namj; }
        double DajKvadraturu() const { return kvad; }
        void Ispisi() const;
};

void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << adr << "na " << spr << ". spratu i ima " << sobe ;
    if(sobe%10==1) std::cout << " sobu.";
    else if(sobe%10==2 or sobe%10==3 or sobe%10==4) std::cout << "sobe." ;
    else std::cout << " soba.";
    std::cout << std::endl << "Kvadratura stana je " << kvad << " (m^2) i stan ";
    if(namj) std::cout << "je namjesten.";
    else std::cout << "nije namjesten.";
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if(sprat<0 or broj_soba<0 or kvadratura<0) throw std::domain_error ("Neispravan unos podataka");
    adr=adresa;
    spr=sprat;
    sobe=broj_soba;
    namj=namjesten;
    kvad=kvadratura;
}

Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if(sprat<0 or broj_soba<0 or kvadratura<0) throw std::domain_error ("Neispravan unos podataka");
    adr=adresa;
    spr=sprat;
    sobe=broj_soba;
    namj=namjesten;
    kvad=kvadratura;
}

class Prodaja {
private:
    std::string ImeAgenta;
    double cijena;
    Datum datum{0,0,0};
    Kupac kupac {"",Datum{0,0,0}};
    Stan stan{"",0,0,false,0};
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac) { kupac.Postavi(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja()); }
    void PromijeniStan(const Stan &novi_stan) { stan.Postavi(novi_stan.DajAdresu(), novi_stan.DajSprat(), novi_stan.DajBrojSoba(), novi_stan.DajNamjesten(),novi_stan.DajKvadraturu()); }
    void PromijeniDatumKupovine(const Datum &novi_datum) { datum.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(), novi_datum.DajGodinu()); }
    void PromijeniCijenuProdaje(const double &nova_cijena) { cijena=nova_cijena; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return ImeAgenta; }
    std::string DajImeKupca() const { return kupac.DajImePrezime(); }
    Datum DajDatumProdaje() const { return datum; }
    double DajCijenuStana() const { return cijena; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan (const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

void Prodaja::Ispisi() const {
    std::cout << "Ime agenta:                " << ImeAgenta;
    std::cout << "Ime kupca:                 " ;
    kupac.Ispisi();
    std::cout << std::endl << "Zakazani datum prodaje:   ";
    datum.Ispisi();
    std::cout << std::endl << "Cijena stana:             " << cijena;
    std::cout << std::endl << "Informacije o stanu:      " << std::endl;
    stan.Ispisi();
    std::cout << std::endl;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    return p1.cijena>p2.cijena;
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    if(p1.datum.DajGodinu()<p2.datum.DajGodinu()) return true;
    else if(p1.datum.DajGodinu()>p2.datum.DajGodinu()) return false;
    else {
        if(p1.datum.DajMjesec()<p2.datum.DajMjesec()) return true;
        else if(p1.datum.DajMjesec()>p2.datum.DajMjesec()) return false;
        else {
            if(p1.datum.DajDan()<p2.datum.DajDan()) return true;
            else return false;
        }
    }
}

void Prodaja::PomjeriDanUnaprijed() {
    if(datum.DajMjesec()==2) {
        if(datum.DajGodinu()%4==0 and !(datum.DajGodinu()%100==0) or datum.DajGodinu()%400==0) {
            if(datum.DajDan()==29) datum.Postavi(1,3,datum.DajGodinu());
            else datum.Postavi(datum.DajDan()+1,datum.DajMjesec(),datum.DajGodinu());
        }
        else {
            if(datum.DajDan()==28) datum.Postavi(1,3,datum.DajGodinu());
            else datum.Postavi(datum.DajDan()+1,datum.DajMjesec(),datum.DajGodinu());
        }
    }
    else if(datum.DajMjesec()==4 or datum.DajMjesec()==6 or datum.DajMjesec()==9 or datum.DajMjesec()==11) {
        if(datum.DajDan()==30) datum.Postavi(1,datum.DajMjesec()+1,datum.DajGodinu());
        else datum.Postavi(datum.DajDan()+1,datum.DajMjesec(),datum.DajGodinu());
    }
    else {
        if(datum.DajDan()==31) {
            if(datum.DajMjesec()==12) datum.Postavi(1,1,datum.DajGodinu()+1);
            else datum.Postavi(1,datum.DajMjesec()+1,datum.DajGodinu());
        }
        else datum.Postavi(datum.DajDan()+1,datum.DajMjesec(), datum.DajGodinu());
    }
}

void Prodaja::PomjeriDanUnazad() {
    if(datum.DajMjesec()==3) {
        if(datum.DajGodinu()%4==0 and !(datum.DajGodinu()%100==0) or datum.DajGodinu()%400==0) {
            if(datum.DajDan()==1) datum.Postavi(29,2,datum.DajGodinu());
            else datum.Postavi(datum.DajDan()-1,datum.DajMjesec(),datum.DajGodinu());
        }
        else {
            if(datum.DajDan()==1) datum.Postavi(28,2,datum.DajGodinu());
            else datum.Postavi(datum.DajDan()-1, datum.DajMjesec(),datum.DajGodinu());
        }
    }
    else if(datum.DajMjesec()==4 or datum.DajMjesec()==6 or datum.DajMjesec()==9 or datum.DajMjesec()==11) {
        if(datum.DajDan()==1) datum.Postavi(31,datum.DajMjesec()-1,datum.DajGodinu());
        else datum.Postavi(datum.DajDan()-1,datum.DajMjesec(),datum.DajGodinu());
    }
    else {
        if(datum.DajDan()==1) {
            if(datum.DajMjesec()==1) datum.Postavi(31,12,datum.DajGodinu()-1);
            else datum.Postavi(31,datum.DajMjesec()-1,datum.DajGodinu());
        }
        else datum.Postavi(datum.DajDan()-1,datum.DajMjesec(),datum.DajGodinu());
    }
}

Prodaja::Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
    if(!ProvjeriImePrezime(ime_agenta_prodaje) or cijena_stana<0) throw std::domain_error("Neispravan unos parametara");
    ImeAgenta=ime_agenta_prodaje;
    cijena=cijena_stana;
    try {
        datum.Postavi(dan_prodaje,mjesec_prodaje,godina_prodaje);
        kupac.Postavi(ime_kupca,datum_rodjenja_kupca);
        stan.Postavi(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    }
    catch(...) {
        throw;
    }
}

Prodaja::Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    if(!ProvjeriImePrezime(ime_agenta_prodaje) or cijena_stana<0) throw std::domain_error("Neispravan unos parametara");
    ImeAgenta=ime_agenta_prodaje;
    cijena=cijena_stana;
    try {
        datum.Postavi(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu());
        kupac.Postavi(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja());
        stan.Postavi(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu());
    }
    catch(...) {
        throw;
    }   
}

class Prodaje {
    Prodaja** p;
    int brojProdaja;
    int kapacitet;
public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje() { for(int i=0;i<brojProdaja;i++) delete p[i]; delete [] p; }
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator=(const Prodaje &prodaje);
    Prodaje &operator=(Prodaje &&Prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,const Kupac &kupac_stana, const Stan &kupljeni_stan) ;
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const { return brojProdaja; }
    Prodaja &DajProdaju(int redni_broj);
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

void Prodaje::IsprazniKolekciju() {
    for(int i=0;i<brojProdaja;i++) delete p[i];
    delete[] p;
    brojProdaja=0;
    p= new Prodaja*[kapacitet];
}

Prodaja Prodaje::DajNajskupljuProdaju() const {
    if(brojProdaja==0) throw std::domain_error ("Nema registriranih prodaja");
    return **std::max_element(p,p+brojProdaja,[](Prodaja *p1,Prodaja *p2) { return SkupljiStan(*p1,*p2);});
}

Prodaja &Prodaje::DajNajskupljuProdaju() {
    if(brojProdaja==0) throw std::domain_error ("Nema registriranih prodaja");
    return **std::max_element(p,p+brojProdaja,[](Prodaja *p1,Prodaja *p2) { return SkupljiStan(*p1,*p2);});
}
Prodaja Prodaje::DajNajranijuProdaju() const {
    if(brojProdaja==0) throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(p,p+brojProdaja, [](Prodaja *p1, Prodaja *p2) { return ProdatPrije(*p1,*p2);});
}
Prodaja &Prodaje::DajNajranijuProdaju() {
    if(brojProdaja==0) throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(p,p+brojProdaja, [](Prodaja *p1, Prodaja *p2) { return ProdatPrije(*p1,*p2);});
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    return std::count_if(p,p+brojProdaja, [datum](Prodaja* prodaja) { return (prodaja->DajDatumProdaje().DajDan()==datum.DajDan() and prodaja->DajDatumProdaje().DajMjesec()==datum.DajMjesec() and prodaja->DajDatumProdaje().DajGodinu()==datum.DajGodinu()); });
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    return std::count_if(p,p+brojProdaja,[ime_agenta](Prodaja* prodaja) { return ime_agenta==prodaja->DajImeAgenta(); });
}



int main ()
{
	return 0;
}