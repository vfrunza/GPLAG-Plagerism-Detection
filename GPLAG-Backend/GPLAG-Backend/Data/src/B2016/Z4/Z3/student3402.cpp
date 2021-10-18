/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <new>
#include <algorithm>

class Datum {
    int dan, mjesec, godina;
    public:
    Datum (int d, int m, int g);
    void Postavi (int d, int m, int g);
    int DajDan() const {return dan;};
    int DajMjesec() const {return mjesec; };
    int DajGodinu() const {return godina;};
    void Ispisi() const;
};

void Datum::Postavi(int d, int m, int g){
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && g%100!=0 || g%400==0 ) broj_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || broj_dana[mjesec-1]<d) throw std::domain_error( "Neispravan datum");
    dan=d; mjesec=m; godina=g;
}

Datum::Datum (int d, int m, int g) { Postavi(d,m,g); }

void Datum::Ispisi() const{
    std::cout << dan<<"/"<<mjesec<<"/"<<godina ;
}

class Kupac{
    std::string ime;
    Datum rodjendan;
    bool NameOk(std::string s);
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : rodjendan(datum_rodjenja) { if(!NameOk(ime_i_prezime)) throw std::domain_error("Neispravno ime i prezime"); ime=ime_i_prezime; };
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const {return ime;};
    Datum DajDatumRodjenja() const {return rodjendan; };
    void Ispisi() const;
};

bool Kupac::NameOk(std::string s){
    bool ok (true);
    for(int i=0; i<s.length(); i++) if(!((s[i]>=65 && s[i]<=90 ) || (s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57) || s[i]==44 || s[i]==45 || s[i]==32)) ok=false;
    return ok;
}

void Kupac::Postavi (const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    if(!NameOk(ime_i_prezime)) throw std::domain_error ("Neispravno ime i prezime");
    rodjendan=datum_rodjenja; ime=ime_i_prezime;
}

void Kupac::Ispisi() const{
    std::cout << ime<< " (" ;
    rodjendan.Ispisi(); std::cout<<")";
}

class Stan{
    std::string ad;
    int sprat, b_soba;
    bool namjesten;
    double kvadrata;
    
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);};
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const {return ad;};
    int DajSprat() const {return sprat;};
    int DajBrojSoba() const {return b_soba;};
    bool DajNamjesten() const {return namjesten;};
    double DajKvadraturu() const {return kvadrata;};
    void Ispisi() const;
};

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error ("Neispravan unos podataka");
    ad=adresa; this->sprat=sprat; b_soba=broj_soba; this->namjesten=namjesten; kvadrata=kvadratura;
}

void Stan::Ispisi() const{
    std::cout << "Stan se nalazi na adresi "<<ad<<" na "<<sprat<<". spratu i ima "<<b_soba;
    if(b_soba%10> 1 && b_soba%10<5 && (b_soba<10 || b_soba>20)) std::cout<<" sobe";
    else std::cout << " soba.";
    std::cout<<std::endl;
    std::cout << "Kvadratura stana je "<<kvadrata<<" (m^2) i stan ";
    if(namjesten) std::cout<<"je namjesten."<<std::endl;
    else std::cout<<"nije namjesten."<<std::endl;
}


class Prodaja{
    std::string agent;
    double cijena;
    Datum dat_prodaje;
    Kupac kupac;
    Stan stan;
    
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan): dat_prodaje(datum_prodaje), kupac(kupac_stana), stan(kupljeni_stan) {agent=ime_agenta_prodaje; cijena=cijena_stana;};
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, 
    int dan_prodaje, int mjesec_prodaje, int godina_prodaje, 
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca, 
    const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata): agent(ime_agenta_prodaje), cijena(cijena_stana), dat_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),
    kupac(ime_kupca, datum_rodjenja_kupca), stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) {};
    void PromijeniKupca(const Kupac &novi_kupac) { kupac.Postavi(novi_kupac.DajImePrezime(), novi_kupac.DajDatumRodjenja());}; 
    void PromijeniStan(const Stan &novi_stan) { stan.Postavi(novi_stan.DajAdresu(), novi_stan.DajSprat(), novi_stan.DajBrojSoba(), novi_stan.DajNamjesten(), novi_stan.DajKvadraturu()); };
    void PromijeniDatumKupovine(const Datum &novi_datum) { dat_prodaje.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(), novi_datum.DajGodinu()); };
    void PromijeniCijenuProdaje(const double &nova_cijena) {cijena=nova_cijena;};
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const {return agent; };
    std::string DajImeKupca() const {return kupac.DajImePrezime(); };
    Datum DajDatumProdaje() const {return dat_prodaje; };
    double DajCijenuStana() const {return cijena;};
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

void Prodaja::PomjeriDanUnazad(){
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    int d=dat_prodaje.DajDan(), m=dat_prodaje.DajMjesec(), g=dat_prodaje.DajGodinu();
    if(g%4==0 && g%100!=0 || g%400==0 ) broj_dana[1]++;
    d-=1;
    if(d<1){
        m-=1;
        if(m<1) g-=1, m=12;
        d=broj_dana[m-1];
    }
    dat_prodaje.Postavi(d,m,g);
}

void Prodaja::PomjeriDanUnaprijed(){
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    int d=dat_prodaje.DajDan(), m=dat_prodaje.DajMjesec(), g=dat_prodaje.DajGodinu();
    if(g%4==0 && g%100!=0 || g%400==0 ) broj_dana[1]++;
    d+=1;
    if(d>broj_dana[m-1]){
        m++;
        if(m>12) g+=1, m=1;
        d=1;
    }
    dat_prodaje.Postavi(d,m,g);
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    return (p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu() || 
       (p1.DajDatumProdaje().DajGodinu()==p2.DajDatumProdaje().DajGodinu() && p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec()) ||
       (p1.DajDatumProdaje().DajGodinu()==p2.DajDatumProdaje().DajGodinu() && p1.DajDatumProdaje().DajMjesec()==p2.DajDatumProdaje().DajMjesec() && p1.DajDatumProdaje().DajDan()<p2.DajDatumProdaje().DajDan())); 
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    return (p1.DajCijenuStana()>p2.DajCijenuStana());
}

void Prodaja::Ispisi() const{
    std::cout<<"Ime agenta: "<<agent<<std::endl;
    std::cout<<"Ime kupca: ";
    kupac.Ispisi();
    std::cout << std::endl;
    std::cout << "Zakazani datum prodaje: " ; DajDatumProdaje().Ispisi();
    std::cout  << std::endl;
    std::cout << "Cijena stana: "<<DajCijenuStana()<<std::endl;
    std::cout << "Informacije o stanu:" << std::endl;
    stan.Ispisi();
}

#include <initializer_list>

class Prodaje {
    int maks, br_prodaja;
    Prodaja **pok;
    
    void Alociraj () {
        pok=new Prodaja* [maks];
        for(int i=0; i<maks; i++) pok[i]=nullptr;
    }
    
    void Dealociraj(){
        for(int i=0; i<br_prodaja; i++) delete pok[i];
        delete pok;
        pok=nullptr;
        br_prodaja=0; maks=0;
    }
    
    public:
    explicit Prodaje(int max_broj_prodaja): maks(max_broj_prodaja), br_prodaja(0) {Alociraj();};
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja); 
    ~Prodaje () {Dealociraj();};
    Prodaje(const Prodaje &prodaje); 
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje); 
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan); 
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata); 
    void RegistrirajProdaju(Prodaja *prodaja); 
    int DajBrojProdaja() const { return br_prodaja; };
    int DajBrojProdajaNaDatum(const Datum &datum) const; 
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const; 
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju();
    Prodaja &DajProdaju( int br);
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta); 
    void ObrisiProdajeNaDatum(const Datum &datum); 
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
    
};

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja){
    maks=spisak_prodaja.size();
    br_prodaja=spisak_prodaja.size();
    Alociraj();
    auto iter= spisak_prodaja.begin();
    int i(0);
    while (iter!=spisak_prodaja.end()) {
        pok[i]=new Prodaja (*iter);
        iter++; i++;
    }
}

Prodaje::Prodaje(const Prodaje &prodaje) : maks(prodaje.maks), br_prodaja(prodaje.br_prodaja) {
    Alociraj();
    for(int i=0; i<br_prodaja; i++) pok[i]=new Prodaja (*prodaje.pok[i]);
}

Prodaje::Prodaje (Prodaje &&prodaje): maks(prodaje.maks), br_prodaja(prodaje.br_prodaja) {
    pok=prodaje.pok;
    prodaje.pok=nullptr;
    prodaje.br_prodaja=0; prodaje.maks=0;
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje){
    if(pok != prodaje.pok){
        Dealociraj();
        maks=prodaje.maks;
        br_prodaja=prodaje.br_prodaja;
        Alociraj();
        for(int i=0; i<br_prodaja; i++) pok[i]=new Prodaja (*prodaje.pok[i]);
    }
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje){
    if(pok!=prodaje.pok){
        Dealociraj();
        maks=prodaje.maks; 
        Alociraj();
        br_prodaja=prodaje.br_prodaja;
        pok=prodaje.pok;
        prodaje.pok=nullptr; prodaje.maks=0; prodaje.br_prodaja=0;
    }
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
    if(br_prodaja==maks) throw std::range_error ("Dostignut maksimalni broj prodaja");
    pok[br_prodaja]=new Prodaja (ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
    br_prodaja++;
} 

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
    if(br_prodaja==maks) throw std::range_error ("Dostignut maksimalni broj prodaja");
    pok[br_prodaja]=new Prodaja (ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba, namjesten_stan, broj_kvadrata);
    br_prodaja++;
} 

void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(br_prodaja==maks) { delete prodaja; throw std::range_error ("Dostignut maksimalni broj prodaja"); }
    pok[br_prodaja]=prodaja; br_prodaja++;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    return std::count_if(pok, pok+br_prodaja, [datum] ( Prodaja *p) { return (p->DajDatumProdaje().DajDan() == datum.DajDan() && p->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && p->DajDatumProdaje().DajGodinu()==datum.DajGodinu() ); });
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    return std::count_if (pok, pok+br_prodaja, [ime_agenta] (Prodaja *p) { return p->DajImeAgenta() == ime_agenta; } );
}

Prodaja &Prodaje::DajNajranijuProdaju(){
    if(br_prodaja==0) throw std::domain_error ("Nema registriranih prodaja");
    return **std::min_element(pok, pok+br_prodaja, [] (Prodaja *p1, Prodaja *p2) { return ProdatPrije(*p1, *p2); });
}

Prodaja Prodaje::DajNajranijuProdaju() const{
    if(br_prodaja==0) throw std::domain_error ("Nema registriranih prodaja");
    return **std::min_element(pok, pok+br_prodaja, [] (Prodaja *p1, Prodaja *p2) { return ProdatPrije(*p1, *p2); });
}

Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(br_prodaja==0) throw std::domain_error ( "Nema registriranih prodaja");
    return **std::max_element(pok, pok +br_prodaja, [] (Prodaja *p1, Prodaja* p2) { return SkupljiStan(*p1,*p2); });
}

Prodaja Prodaje::DajNajskupljuProdaju() const {
    if(br_prodaja==0) throw std::domain_error ( "Nema registriranih prodaja");
    return **std::max_element(pok, pok +br_prodaja, [] (Prodaja *p1, Prodaja* p2) { return SkupljiStan(*p1,*p2); });
}

void Prodaje::IsprazniKolekciju(){
    for(int i=0; i<br_prodaja; i++) delete pok[i];
    for(int i=0; i<br_prodaja; i++) pok[i]=nullptr;
    br_prodaja=0;
}

Prodaja &Prodaje::DajProdaju( int br){
    if(br<1 || br>br_prodaja) throw std::domain_error ("Nepostojeca prodaja");
    return *pok[br-1];
}

void Prodaje::ObrisiNajranijuProdaju(){
    if(br_prodaja==0) throw std::range_error ("Prazna kolekcija");
    auto najranija= std::min_element(pok, pok+br_prodaja, [] (Prodaja *p1, Prodaja *p2) {return ProdatPrije(*p1,*p2);});
    delete *najranija;
    while (najranija+1 != pok+br_prodaja){
        *najranija=*(najranija+1);
        najranija++;
    }
    delete pok[br_prodaja-1];
    pok[br_prodaja]=nullptr;
    br_prodaja--;
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    auto p_na_ag= std::find_if(pok, pok+br_prodaja, [ime_agenta] (Prodaja *p) { return p->DajImeAgenta()==ime_agenta; });
    while(p_na_ag != pok+br_prodaja){
        int razmak=p_na_ag-pok;
        delete pok[razmak];
        while(p_na_ag+1!=pok+br_prodaja){
            pok[razmak]=pok[razmak+1];
            razmak++;
        }
        delete pok[br_prodaja-1];//
        pok[br_prodaja-1]=nullptr;//
        br_prodaja--;
        p_na_ag=std::find_if(pok, pok+br_prodaja, [ime_agenta] (Prodaja *p) { return p->DajImeAgenta()==ime_agenta; });
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    auto pnd = std::find_if(pok, pok+br_prodaja, [datum] (Prodaja *p) {return (p->DajDatumProdaje().DajDan()==datum.DajDan() && p->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && p->DajDatumProdaje().DajGodinu()==datum.DajGodinu()); });
    while (pnd!=pok+br_prodaja) {
        int razmak=pnd-pok;
        delete pok[razmak];
        while (pnd+1!=pok+br_prodaja) {
            pok[razmak]=pok[razmak+1];
            razmak++;
        }
        delete pok[br_prodaja-1];
        pok[br_prodaja-1]=nullptr;
        br_prodaja--;
        pnd = std::find_if(pok, pok+br_prodaja, [datum] (Prodaja *p) {return (p->DajDatumProdaje().DajDan()==datum.DajDan() && p->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && p->DajDatumProdaje().DajGodinu()==datum.DajGodinu()); });
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    Prodaje novo (Prodaje(0));
    novo = *this;
    std::sort (novo.pok, novo.pok+br_prodaja, [] (Prodaja *p1, Prodaja *p2) { return p1->DajImeKupca()<p2->DajImeKupca() ; });
    std::for_each(novo.pok, novo.pok+br_prodaja, [datum] (Prodaja *p) {if(p->DajDatumProdaje().DajDan()==datum.DajDan() && p->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && p->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) p->DajDatumProdaje().Ispisi();});
    novo.Dealociraj();
}

void Prodaje::IspisiSveProdaje() const{
    Prodaje novo(Prodaje(0));
    novo=*this;
    
    std::sort(novo.pok, novo.pok+br_prodaja, [] (Prodaja *p1, Prodaja *p2) { 
        if( ProdatPrije(*p1,*p2)) return true;
        else if( p1->DajDatumProdaje().DajDan()== p2->DajDatumProdaje().DajDan() && p1->DajDatumProdaje().DajMjesec()== p2->DajDatumProdaje().DajMjesec() && p1->DajDatumProdaje().DajGodinu()== p2->DajDatumProdaje().DajGodinu() && p1->DajImeKupca()<p2->DajImeKupca()) return true;
        return false;
    });
    std::for_each(novo.pok, novo.pok+br_prodaja, [] (Prodaja *p){p->Ispisi();});
    novo.Dealociraj();
}










int main ()
{
    
	return 0;
}