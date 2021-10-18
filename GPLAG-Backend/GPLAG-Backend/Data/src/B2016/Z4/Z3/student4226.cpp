/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

bool ProvjeriDatum(int dan, int mjesec, int godina){
    if(godina<0 || mjesec<=0 || mjesec>12 || dan<0 || dan>31) return false;
    bool prestupna(false);
    if(godina%4 == 0 && !(godina%100==0) || godina%400==0) prestupna=true;
    if(mjesec==2){
        if(prestupna) if(dan<29) return false;
        else { if(dan>28) return false; }
    }
    else if(mjesec == 4 || mjesec == 6 || mjesec==9 || mjesec==11) if(dan>30) return false;
    return true;
}

bool jelslovo(char a){
    return ((a>='a' && a<='z') || (a>='A' && a<='Z'));
}

bool ProvjeriImePrezime(std::string s){
    for(int i(0); i<s.length(); i++)
        if(!jelslovo(s[i]) && (s[i]<'0' || s[i]>'9') && s[i]!=' ' && s[i]!='-') return false;
    return true;
}

class Datum {
private:
    int d;
    int m;
    int g;
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return d; }
    int DajMjesec() const { return m; }
    int DajGodinu() const { return g; }
    void Ispisi() const;
};

void Datum::Ispisi() const{
    std::cout << d << "/" << m << "/" << g;
}

Datum::Datum(int dan, int mjesec, int godina){
    if(!ProvjeriDatum(dan, mjesec, godina)) throw std::domain_error("Neispravan datum");
    d=dan;
    m=mjesec;
    g=godina;
}

void Datum::Postavi(int dan, int mjesec, int godina){
    if(!ProvjeriDatum(dan, mjesec, godina)) throw std::domain_error("Neispravan datum");
    d=dan;
    m=mjesec;
    g=godina;
}

class Kupac {
private:
    std::string ImePrezime;
    Datum datum{0,0,0};
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return ImePrezime; }
    Datum DajDatumRodjenja() const { return datum; }
    void Ispisi() const;
};

void Kupac::Ispisi() const{
    std::cout << ImePrezime << "(";
    datum.Ispisi();
    std::cout<< ")";
}

Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    if(!ProvjeriImePrezime(ime_i_prezime)) throw std::domain_error("Neispravno ime i prezime");
    try{
        datum.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
    }
    catch(...){
        throw;
    }
    ImePrezime = ime_i_prezime;
}

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    if(!ProvjeriImePrezime(ime_i_prezime)) throw std::domain_error("Neispravno ime i prezime");
    try{
        datum.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
    }
    catch(...){
        throw;
    }
    ImePrezime = ime_i_prezime;
}

class Stan {
private:
    std::string adr;
    int spr, sobe;
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
    std::cout << "Stan se nalazi na adresi " << adr << " na " << spr << ". spratu i ima " << sobe;
    if(sobe%10==1) std::cout << " sobu.";
    else if(sobe%10==2 || sobe%10==3 || sobe%10==4) std::cout << " sobe.";
    else std::cout << " soba.";
    std::cout << std::endl << "Kvadratura stana je " << kvad << " (m^2) i stan ";
    if(namj) std::cout << "je namjesten.";
    else std::cout << "nije namjesten.";
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    adr=adresa;
    spr=sprat;
    sobe=broj_soba;
    namj = namjesten;
    kvad = kvadratura;
}

Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    adr=adresa;
    spr=sprat;
    sobe=broj_soba;
    namj = namjesten;
    kvad = kvadratura;
}

class Prodaja {
private:
    std::string imeAgenta;
    double cijena;
    Datum datum{0,0,0};
    Kupac kupac{"",Datum{0,0,0}};
    Stan stan{"",0,0,false,0};
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac) { kupac.Postavi(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja()); }
    void PromijeniStan(const Stan &novi_stan) { stan.Postavi(novi_stan.DajAdresu(), novi_stan.DajSprat(), novi_stan.DajBrojSoba(), novi_stan.DajNamjesten(), novi_stan.DajKvadraturu()); }
    void PromijeniDatumKupovine(const Datum &novi_datum) { datum.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(), novi_datum.DajGodinu()); }
    void PromijeniCijenuProdaje(const double &nova_cijena) { cijena=nova_cijena; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return imeAgenta; }
    std::string DajImeKupca() const  { return kupac.DajImePrezime(); }
    Datum DajDatumProdaje() const { return datum; }
    double DajCijenuStana() const { return cijena; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    return p1.cijena > p2.cijena;
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if(p1.datum.DajGodinu() < p2.datum.DajGodinu()) return true;
    else if(p1.datum.DajGodinu() > p2.datum.DajGodinu()) return false;
    else{
        if(p1.datum.DajMjesec() < p2.datum.DajMjesec()) return true;
        else if(p1.datum.DajMjesec() > p2.datum.DajMjesec()) return false;
        else{
            if(p1.datum.DajDan() < p2.datum.DajDan()) return true;
            else return false;
        }
    }
}

void Prodaja::Ispisi() const {
    std::cout << std::setw(30) << std::left << "Ime agenta: ";
    std::cout << imeAgenta <<std::endl;
    std::cout << std::setw(30) << std::left << "Ime kupca: ";
    kupac.Ispisi();
    std::cout << std::endl << std::setw(30) << std::left << "Zakazani datum prodaje: ";
    datum.Ispisi();
    std::cout << std::endl << std::setw(30) << std::left << "Cijena stana: " << cijena << std::endl;
    std::cout << "Informacije o stanu: ";
    stan.Ispisi();
    std::cout << std::endl;
}

void Prodaja::PomjeriDanUnaprijed() {
    if(datum.DajMjesec()==2) {
        if(datum.DajGodinu()%4==0 && !(datum.DajGodinu()%100==0) || datum.DajGodinu()%400==0) {
            if(datum.DajDan()==29) datum.Postavi(1,3,datum.DajGodinu());
            else datum.Postavi(datum.DajDan()+1, datum.DajMjesec(), datum.DajGodinu());
        }
        else {
            if(datum.DajDan()==28) datum.Postavi(1,3,datum.DajGodinu());
            else datum.Postavi(datum.DajDan()+1, datum.DajMjesec(), datum.DajGodinu());
        }
    }
    else if(datum.DajMjesec()==4 || datum.DajMjesec()==6 || datum.DajMjesec()==9 || datum.DajMjesec()==11) {
        if(datum.DajDan()==30) datum.Postavi(1, datum.DajMjesec()+1, datum.DajGodinu());
        else datum.Postavi(datum.DajDan()+1, datum.DajMjesec(), datum.DajGodinu());
    }
    else {
        if(datum.DajDan()==31) {
            if(datum.DajMjesec()==12) datum.Postavi(1,1,datum.DajGodinu()+1);
            else datum.Postavi(1,datum.DajMjesec()+1, datum.DajGodinu());
        }
        else datum.Postavi(datum.DajDan()+1,datum.DajMjesec(),datum.DajGodinu());
    }
}

void Prodaja::PomjeriDanUnazad() {
    if(datum.DajMjesec()==3) {
        if(datum.DajGodinu()%4==0 && !(datum.DajGodinu()%100==0) || datum.DajGodinu()%400==0) {
            if(datum.DajDan()==1) datum.Postavi(29,2,datum.DajGodinu());
            else datum.Postavi(datum.DajDan()-1, datum.DajMjesec(), datum.DajGodinu());
        }
        else {
            if(datum.DajDan()==1) datum.Postavi(28,2,datum.DajGodinu());
            else datum.Postavi(datum.DajDan()-1, datum.DajMjesec(), datum.DajGodinu());
        }
    }
    else if(datum.DajMjesec()==4 || datum.DajMjesec()==6 || datum.DajMjesec()==9 || datum.DajMjesec()==11) {
        if(datum.DajDan()==1) datum.Postavi(31, datum.DajMjesec()-1, datum.DajGodinu());
        else datum.Postavi(datum.DajDan()-1, datum.DajMjesec(), datum.DajGodinu());
    }
    else {
        if(datum.DajDan()==1) {
            if(datum.DajMjesec()==1) datum.Postavi(31,12,datum.DajGodinu()-1);
            else datum.Postavi(31,datum.DajMjesec()-1, datum.DajGodinu());
        }
        else datum.Postavi(datum.DajDan()-1,datum.DajMjesec(),datum.DajGodinu());
    }
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
    if(!ProvjeriImePrezime(ime_agenta_prodaje) || cijena_stana<0) throw std::domain_error("Neispravan unos parametara");
    imeAgenta = ime_agenta_prodaje;
    cijena = cijena_stana;
    try{
        datum.Postavi(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
        kupac.Postavi(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja());
        stan.Postavi(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu());
    }
    catch(...){
        throw;
    }
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
    if(!ProvjeriImePrezime(ime_agenta_prodaje) || cijena_stana<0) throw std::domain_error("Neispravan unos parametara");
    imeAgenta = ime_agenta_prodaje;
    cijena = cijena_stana;
    try{
        datum.Postavi(dan_prodaje, mjesec_prodaje, godina_prodaje);
        kupac.Postavi(ime_kupca, datum_rodjenja_kupca);
        stan.Postavi(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    }
    catch(...){
        throw;
    }
}

class Prodaje {
private:
    Prodaja** p;
    int brojProdaja, kapacitet;
public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje() { for(int i(0); i<brojProdaja; i++) delete p[i]; delete[] p; }
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
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

void Prodaje::IspisiSveProdaje() const {
     std::sort(p, p+brojProdaja, [](Prodaja *p1, Prodaja *p2) {
        Datum datum1 = p1->DajDatumProdaje(); 
        Datum datum2 = p2->DajDatumProdaje();
        if(datum1.DajGodinu() == datum2.DajGodinu()) {
            if(datum1.DajMjesec() == datum2.DajMjesec()){
                return datum1.DajDan() < datum2.DajDan();
            }
            return datum1.DajMjesec() < datum2.DajMjesec();
        }
        return (datum1.DajGodinu() < datum2.DajGodinu());
        return false; 
     });
     for(int i(0); i<brojProdaja; i++) {
        p[i]->Ispisi();
        std::cout << std::endl;
    }
}


void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    Prodaja **pok = nullptr;
    pok = new Prodaja*[brojProdaja];
    int k(0);
    for(int i(0); i<brojProdaja; i++) {
        if(datum.DajDan() == p[i]->DajDatumProdaje().DajDan() && datum.DajMjesec() == p[i]->DajDatumProdaje().DajMjesec() && datum.DajGodinu() == p[i]->DajDatumProdaje().DajGodinu()) {
            pok[k] = new Prodaja(*p[i]);
        }
    }
    std::sort(pok, pok+k, [](Prodaja *p1, Prodaja *p2) {
        if(p1->DajImeKupca() < p2->DajImeKupca()) return true;
        return false;
    });
    for(int i(0); i<k; i++) {
        pok[i]->Ispisi();
        std::cout << std::endl;
    }
}


void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
    if(brojProdaja == 0) throw std::range_error("Prazna kolekcija");
    for(int i(0); i<brojProdaja; i++) {
        Datum pomocni = p[i]->DajDatumProdaje();
        if(pomocni.DajDan() == datum.DajDan() && pomocni.DajMjesec() == datum.DajMjesec() && pomocni.DajGodinu() == datum.DajGodinu()) {
            delete p[i];
            p[i] = nullptr;
        }
    }
}


void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
    if(brojProdaja == 0) throw std::range_error("Prazna kolekcija");
    for(int i(0); i<brojProdaja; i++) {
        if(ime_agenta == p[i]->DajImeAgenta()) {
            delete p[i];
            p[i] = nullptr;
        }
    }
}


void Prodaje::ObrisiNajranijuProdaju() {
    if(brojProdaja == 0) throw std::range_error("Prazna kolekcija");
    Prodaja najranija = DajNajranijuProdaju();
    for(int i(0); i<brojProdaja; i++) {
        if(&najranija == p[i]) {
            delete p[i];
            p[i]=nullptr;
        }
    }
}


void Prodaje::IsprazniKolekciju() {
    for(int i(0); i<brojProdaja; i++) delete p[i];
    delete[] p;
    brojProdaja=0;
    p=new Prodaja*[kapacitet];
}

Prodaja Prodaje::DajNajskupljuProdaju() const {
    if(brojProdaja==0) throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(p, p+brojProdaja, [](Prodaja *p1, Prodaja *p2) { return SkupljiStan(*p1,*p2); });
}

Prodaja &Prodaje::DajNajskupljuProdaju() {
    if(brojProdaja==0) throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(p, p+brojProdaja, [](Prodaja *p1, Prodaja *p2) { return SkupljiStan(*p1,*p2); });
}

Prodaja Prodaje::DajNajranijuProdaju() const {
    if(brojProdaja==0) throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(p, p+brojProdaja, [](Prodaja *p1, Prodaja *p2) { return ProdatPrije(*p1,*p2); });
}

Prodaja &Prodaje::DajNajranijuProdaju() {
    if(brojProdaja==0) throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(p, p+brojProdaja, [](Prodaja *p1, Prodaja *p2) { return ProdatPrije(*p1,*p2); });
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    return std::count_if(p, p+brojProdaja, [ime_agenta](Prodaja* prodaja) { return ime_agenta==prodaja->DajImeAgenta(); });
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    return std::count_if(p, p+brojProdaja, [datum](Prodaja* prodaja) { return (prodaja->DajDatumProdaje().DajDan()==datum.DajDan() && prodaja->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && prodaja->DajDatumProdaje().DajGodinu()==datum.DajGodinu()); });
}

Prodaja &Prodaje::DajProdaju(int redni_broj) {
    if(redni_broj<0 || redni_broj>brojProdaja) throw std::range_error("Neispravan parametar");
    return *p[redni_broj];
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
    if(brojProdaja==kapacitet) throw std::range_error("Dostignut maksimalni broj prodaja");
    p[brojProdaja]=new Prodaja(*prodaja);
    brojProdaja++;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
    if(brojProdaja==kapacitet) throw std::range_error("Dostignut maksimalni broj prodaja");
    p[brojProdaja]=new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    brojProdaja++;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan) {
    if(brojProdaja==kapacitet) throw std::range_error("Dostignut maksimalni broj prodaja");
    p[brojProdaja]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
    brojProdaja++;
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje) {
    kapacitet=prodaje.kapacitet;
    brojProdaja=prodaje.kapacitet;
    p=prodaje.p;
    return *this;
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje) {
    if(prodaje.kapacitet!=kapacitet) throw std::logic_error("Nesaglasni kapaciteti");
    if(prodaje.brojProdaja>brojProdaja) {
        for(int i(brojProdaja);i<prodaje.brojProdaja;i++) {
            p[i]=new Prodaja(*prodaje.p[i]);
        }
    }
    else {
        for(int i(prodaje.brojProdaja);i<brojProdaja;i++) {
            delete p[i];
            p[i]=nullptr;
        }
    }
    brojProdaja=prodaje.brojProdaja;
    for(int i(0);i<brojProdaja;i++) {
        *p[i]=*prodaje.p[i];
    }
    return *this;
}

Prodaje::Prodaje(Prodaje &&prodaje) {
    kapacitet=prodaje.kapacitet;
    brojProdaja=prodaje.brojProdaja;
    p=prodaje.p;
}

Prodaje::Prodaje(const Prodaje &prodaje) {
    kapacitet=prodaje.kapacitet;
    brojProdaja=prodaje.brojProdaja;
    p=new Prodaja*[kapacitet];
    for(int i(0);i<brojProdaja;i++) {
        p[i]=new Prodaja(*prodaje.p[i]);
    }
}

Prodaje::Prodaje(int max_broj_prodaja) {
    if(max_broj_prodaja<0) throw std::domain_error("Neispravan kapacitet");
    kapacitet=max_broj_prodaja;
    brojProdaja=0;
    p=new Prodaja*[max_broj_prodaja];
}

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) {
    kapacitet=spisak_prodaja.size();
    p=new Prodaja*[kapacitet];
    brojProdaja=0;
    int i(0);
    for(auto it(spisak_prodaja.begin()); it!=spisak_prodaja.end();it++) {
        p[i]=new Prodaja(*it);
        brojProdaja++;
        i++;
    }
}

int main (){
	return 0;
}