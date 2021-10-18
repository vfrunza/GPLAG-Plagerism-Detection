/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <cstring>

class Datum{
    int d,m,g;
    public:
    Datum(int dan, int mjesec, int godina){
        int br_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4==0 && godina%100!=0) || godina%400==0) br_dana[1]++;
        if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>br_dana[mjesec-1] || godina >2017) throw std::domain_error("Neispravan datum");
        d=dan; m=mjesec; g=godina;
    }
    void Postavi(int dan, int mjesec, int godina){ *this=Datum(dan,mjesec,godina); }
    int DajDan() const { return d; }
    int DajMjesec() const { return m; }
    int DajGodinu() const {return g; }
    void Ispisi() const { std::cout << d << "/" << m << "/" << g; }

};

class Kupac{
    std::string iip;
    Datum d_rodjenja;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): d_rodjenja(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu()){
        for(int i=0;i<ime_i_prezime.size();i++){
            if(!((ime_i_prezime[i]>='a'&& ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='A'&& ime_i_prezime[i]<='Z') || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='-' || ime_i_prezime[i]=='\'' || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9')))
                throw std::domain_error("Neispravno ime i prezime");
        }
        iip=ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) { *this=Kupac(ime_i_prezime,datum_rodjenja); }
    std::string DajImePrezime() const { return iip; }
    Datum DajDatumRodjenja() const { return d_rodjenja; }
    void Ispisi() const { std::cout << iip << " (" << DajDatumRodjenja().DajDan() << "/" << DajDatumRodjenja().DajMjesec() << "/" << DajDatumRodjenja().DajGodinu() << ")" << std::endl; }
};

class Stan {
    std::string a;
    int s, br_soba;
    bool namj;
    double k;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
        a=adresa; s=sprat; br_soba=broj_soba; namj=namjesten; k=kvadratura;
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) { *this=Stan(adresa,sprat,broj_soba,namjesten,kvadratura); }
    std::string DajAdresu() const { return a; }
    int DajSprat() const { return s; }
    int DajBrojSoba() const {return br_soba; }
    bool DajNamjesten() const { return namj; }
    double DajKvadraturu() const { return k; }
    void Ispisi() const;
};

void Stan::Ispisi() const{
    std::cout << "Stan se nalazi na adresi " << a << " na " << s << ".  spratu i ima " << br_soba;
    if(br_soba%10==1) std::cout << " sobu." << std::endl;
    else if(br_soba%10>1 && br_soba%10<4) std::cout << " sobe." << std::endl;
    else std::cout << " soba." << std::endl;
    std::cout << "Kvadratura stana je " << k << " (m^2) i stan ";
    if(namj) std::cout << " je namjesten.";
    else std::cout << "nije namjesten.";
    std::cout << std::endl;
}

class Prodaja{
    std::string ime_agenta;
    double cijena;
    Datum d_prodaje;  
    Kupac kup_stana;
    Stan kuplj_stan;
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):d_prodaje(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()),kup_stana(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja()), kuplj_stan(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu()) {
      ime_agenta=ime_agenta_prodaje; cijena=cijena_stana;
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):
    d_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje), kup_stana(ime_kupca,datum_rodjenja_kupca),kuplj_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){
        ime_agenta=ime_agenta_prodaje; cijena=cijena_stana;
    }
    void PromijeniKupca(const Kupac &novi_kupac){
        kup_stana=Kupac(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja());
    }
    void PromijeniStan(const Stan &novi_stan){
        kuplj_stan=Stan(novi_stan.DajAdresu(),novi_stan.DajSprat(),novi_stan.DajBrojSoba(),novi_stan.DajNamjesten(),novi_stan.DajKvadraturu());
    }
    void PromijeniDatumKupovine(const Datum &novi_datum){
        d_prodaje=Datum(novi_datum.DajDan(),novi_datum.DajMjesec(),novi_datum.DajGodinu());
    }
    void PromijeniCijenuProdaje(const double &nova_cijena){ cijena=nova_cijena; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return ime_agenta; }
    std::string DajImeKupca() const { return kup_stana.DajImePrezime(); }
    Datum DajDatumProdaje() const { return d_prodaje; }
    double DajCijenuStana() const{ return cijena; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if(p1.d_prodaje.DajGodinu()<p2.d_prodaje.DajGodinu()) return true;
    else if(p1.d_prodaje.DajGodinu()>p2.d_prodaje.DajGodinu()) return false;
    else{
        if(p1.d_prodaje.DajMjesec()<p2.d_prodaje.DajMjesec()) return true;
        else if(p1.d_prodaje.DajMjesec()>p2.d_prodaje.DajMjesec()) return false;
        else{
            if(p1.d_prodaje.DajDan()<p2.d_prodaje.DajDan()) return true;
            else if(p1.d_prodaje.DajDan()>p2.d_prodaje.DajDan()) return false;
        }
    }
    return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    if(p1.DajCijenuStana()>p2.DajCijenuStana()) return true;
    return false;
}

void Prodaja::PomjeriDanUnaprijed(){
        int dan=this->d_prodaje.DajDan();
        int mjesec=this->d_prodaje.DajMjesec();
        int godina=this->d_prodaje.DajGodinu();
        int broj_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
        dan++;
        if(dan>broj_dana[mjesec-1]) dan=1,mjesec++;
        if(mjesec>12) mjesec=1,godina++;
        d_prodaje=Datum(dan,mjesec,godina);
}

void Prodaja::PomjeriDanUnazad(){
        int dan=this->DajDatumProdaje().DajDan();
        int mjesec=this->DajDatumProdaje().DajMjesec();
        int godina=this->DajDatumProdaje().DajGodinu();
        int broj_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4==0 && godina%100!=100) || godina%400==0) broj_dana[1]++;
        dan--;
        if(dan==0) mjesec--;
        if(mjesec==0) mjesec=12,godina--;
        dan=broj_dana[mjesec-1];
        d_prodaje=Datum(dan,mjesec,godina);
}

 void Prodaja::Ispisi() const {
        std::cout << std::left << std::setw(30) << "Ime agenta:" << DajImeAgenta() << std::endl;
        std::cout << std::left << std::setw(30) << "Ime kupca:" ; kup_stana.Ispisi(); std::cout << std::endl;
        std::cout << std::left << std::setw(30) << "Zakazani datum prodaje:"; d_prodaje.Ispisi(); 
        std::cout << std::endl << std::left << std::setw(30) << "Cijena stana:" << cijena << std::endl;
        std::cout << "Informacije o stanu: " << std::endl;
        kuplj_stan.Ispisi();
        std::cout << std::endl;
}

class Prodaje{
    int s,k;
    Prodaja ** pok=nullptr;
    public:
    explicit Prodaje(int max_broj_prodaja){
        //šta ako unese negativan broj??
        s=0; k=max_broj_prodaja; pok=new Prodaja* [max_broj_prodaja];
    }
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja){
        s=spisak_prodaja.size(); k=s; pok=new Prodaja *[k];
        auto it=spisak_prodaja.begin();
        for(int i=0;i<s;i++) {
            pok[i]=new Prodaja(*it);
            it++;
        }
    }
    ~Prodaje(){
        for(int i=0;i<s;i++) delete pok[i];
        delete []pok;
    }
    Prodaje(const Prodaje &prodaje){
        s=prodaje.s; k=prodaje.k;
        pok=new Prodaja* [k];
        for(int i=0;i<s;i++) pok[i]=new Prodaja(*prodaje.pok[i]);
    }
    Prodaje(Prodaje &&prodaje){
        s=prodaje.s; k=prodaje.k;
        pok=prodaje.pok;
        prodaje.s=0;
        prodaje.pok=nullptr;
    }
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje); 
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan); 
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata); 
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const { return s; }
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const; 
    Prodaja &DajNajskupljuProdaju(); 
    Prodaja DajNajskupljuProdaju() const;
    Prodaja &DajProdaju(int indeks) const;
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const; 
    void IspisiSveProdaje() const;
};

Prodaje &Prodaje::operator =(const Prodaje &prodaje){
    if(this==&prodaje) return *this;
    for(int i=0;i<s;i++) delete pok[i];
    delete []pok;
    s=prodaje.s; k=prodaje.k;
    pok= new Prodaja* [k];
    for(int i=0;i<s;i++) pok[i]=new Prodaja(*prodaje.pok[i]);
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje){
    if(this==&prodaje) return *this;
    for(int i=0;i<s;i++) delete pok[i];
    delete [] pok;
    s=prodaje.s;
    k=prodaje.k;
    pok=prodaje.pok;
    prodaje.s=0;
    prodaje.pok=nullptr;     
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan){
    if(s<k){
        pok[s++]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
    }else{
        throw std::range_error("Dostignut maksimalni broj prodaja");
    }
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
    Datum datum_prodaje=Datum(dan_prodaje,mjesec_prodaje,godina_prodaje);
    Kupac kupac_stana=Kupac(ime_kupca,datum_rodjenja_kupca);
    Stan kupljeni_stan=Stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    if(s<k) pok[s++]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
    else throw std::range_error("Dostignut maksimalni brojprodaja");
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(s<k) pok[s++]=prodaja;
    else throw std::range_error("Dostignut maksimalni brojprodaja");
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
     int c=std::count_if(pok,pok+s,[datum](Prodaja* d){
         return (d->DajDatumProdaje().DajDan()==datum.DajDan() && d->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && d->DajDatumProdaje().DajGodinu()==datum.DajGodinu());
     });
     return c;
 }

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
     return std::count_if(pok,pok+s,[ime_agenta](Prodaja* d){return d->DajImeAgenta()==ime_agenta;});
 }

Prodaja &Prodaje::DajNajranijuProdaju(){
    if(s==0) throw std::domain_error("Nema registriranih prodaja");
    auto i=std::min_element(pok,pok+s,[](Prodaja* a,Prodaja* b){ return ProdatPrije(*a,*b); });
    return **i;
}

Prodaja& Prodaje::DajProdaju(int indeks) const{
    if(indeks>s) throw std::range_error("Greska");
    return *(pok[indeks-1]);
}

Prodaja Prodaje::DajNajranijuProdaju() const{
    if(s==0) throw std::domain_error("Nema registriranih prodaja");
     auto i=std::min_element(pok,pok+s,[](Prodaja* a,Prodaja* b){return ProdatPrije(*a,*b);});
     return **i;
}

Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(s==0) throw std::domain_error("Nema registriranih prodaja");
    return **( std::max_element(pok,pok+s,[](Prodaja* a, Prodaja* b){ return a->DajCijenuStana()<b->DajCijenuStana(); }));
}

Prodaja Prodaje::DajNajskupljuProdaju() const{
    if(s==0) throw std::domain_error("Nema registriranih prodaja");
    auto t=std::max_element(pok,pok+s,[](Prodaja* a, Prodaja* b){ return a->DajCijenuStana()<b->DajCijenuStana(); });
    return **t;
}

void Prodaje::IsprazniKolekciju(){
    for(int i=0;i<s;i++) delete pok[i];
    delete []pok;
    pok=nullptr;
    s=0;k=0;
}

void Prodaje::ObrisiNajranijuProdaju(){
    if(s==0) throw std::range_error("Prazna kolekcija");
    if(s==1) IsprazniKolekciju();
    else{
        int mini=0;
        for(int i=0;i<s;i++){
            if(ProdatPrije(*pok[i],*pok[mini])) mini=i;
        }
        delete pok[mini];
        if(mini!=s-1)pok[mini]=pok[s-1];
        pok[s-1]=nullptr;
        s--;
    }
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    if(s==0) throw std::range_error("Prazna kolekcija");
    if(s==1) IsprazniKolekciju();
    else{
        for(int i=0;i<s;i++){
            if(ime_agenta==pok[i]->DajImeAgenta()) {
                delete pok[i];
                if(i!=s-1) pok[i]=pok[s-1]; 
                pok[s-1]=nullptr; s--; i--;
            }
        }
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    for(int i=0;i<s;i++){
        if(datum.DajDan()==pok[i]->DajDatumProdaje().DajDan() && datum.DajMjesec()==pok[i]->DajDatumProdaje().DajMjesec() && datum.DajGodinu()==pok[i]->DajDatumProdaje().DajGodinu()){
            if(s==1) IsprazniKolekciju();
            else{
                delete pok[i];
                if(i!=s-1) pok[i]=pok[s-1];
                pok[s-1]=nullptr; s--;i--;
            }
        } 
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    std::sort(pok,pok+s,[](Prodaja* a, Prodaja* b){ return a->DajImeKupca()<b->DajImeKupca();});
    for(int i=0;i<s;i++){
        if(datum.DajDan()==pok[i]->DajDatumProdaje().DajDan() && datum.DajMjesec()==pok[i]->DajDatumProdaje().DajMjesec() && datum.DajGodinu()==pok[i]->DajDatumProdaje().DajGodinu()) pok[i]->Ispisi();
    }
}

void Prodaje::IspisiSveProdaje() const{
    std::sort(pok,pok+s,[](Prodaja* a, Prodaja* b){
        if(a->DajDatumProdaje().DajDan()==b->DajDatumProdaje().DajDan() && a->DajDatumProdaje().DajMjesec()==b->DajDatumProdaje().DajMjesec() && a->DajDatumProdaje().DajGodinu()==b->DajDatumProdaje().DajGodinu()) return a->DajImeKupca()<b->DajImeKupca();
        return ProdatPrije(*a,*b); 
    });
    for(int i=0;i<s;i++) pok[i]->Ispisi();
}

int main ()
{
    std::cout << "Dobrodosli!" << std::endl << std::endl;
    std::cout << "Dovidjenja!";
	return 0;
}