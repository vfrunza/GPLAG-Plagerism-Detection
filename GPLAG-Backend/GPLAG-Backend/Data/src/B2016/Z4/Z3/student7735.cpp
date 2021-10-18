/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <memory>
#include <new>
#include <initializer_list>

class Datum{
    int d,m,g;
    public:
    Datum(int dan,int mjesec,int godina){Postavi(dan,mjesec,godina);};
    void Postavi(int dan,int mjesec,int godina);
    int DajDan() const {return d;};
    int DajMjesec() const {return m;};
    int DajGodinu() const {return g;};
    void Ispisi() const{std::cout << d<<"/"<<m<<"/"<<g;};
};

void Datum::Postavi(int dan,int mjesec,int godina){
    int br_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0) && ((godina%100!=0) || (godina%400==0)))br_dana[1]++;
    if((godina<1)||(dan<1)||(mjesec<1)|| (mjesec>12) || (dan>br_dana[mjesec-1]))throw std::domain_error("Neispravan datum");
    d=dan;m=mjesec;g=godina;
}

class Kupac{
    std::string naziv;
    Datum dat;
    public:
    Kupac (const std::string &ime_i_prezime, const Datum &datum_rodjenja):dat(datum_rodjenja){Postavi(ime_i_prezime,datum_rodjenja);};
    void Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja);
    std::string DajImePrezime()const {return naziv;};
    Datum DajDatumRodjenja()const{return dat;};
    void Ispisi()const;
};

void Kupac::Ispisi()const{
    std::cout << DajImePrezime()<<"(";
    DajDatumRodjenja().Ispisi();
    std::cout << ")" << std::endl;
}

void Kupac::Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja){
   auto it=ime_i_prezime.begin();
   while(it!=ime_i_prezime.end()){
       if(*it<' ' || (*it>' ' && *it<'A') ||(*it>'Z' && *it<'a') || *it>'z')throw std::domain_error ("Neispravno ime i prezime");
       it++;
   }
   naziv=ime_i_prezime;
   dat=datum_rodjenja;
}

class Stan{
    std::string adr;
    int kat,sobe;
    double kvadrata;
    bool sredjen;
    public:
    Stan (const std::string &adresa, int sprat, int broj_soba,bool namjesten,double kvadratura){Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);};
    void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten,double kvadratura);
    std::string DajAdresu()const{return adr;};
    int DajSprat()const{return kat;};
    int DajBrojSoba()const{return sobe;};
    bool DajNamjesten()const{return sredjen;};
    double DajKvadraturu()const{return kvadrata;};
    void Ispisi()const;
    };
    
void Stan::Postavi(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura){
    if(sprat<0 ||broj_soba<0 || kvadratura<0)throw std::domain_error("Neispravan unos podataka.");
    adr=adresa; kat=sprat;sobe=broj_soba;sredjen=namjesten;kvadrata=kvadratura;
}

void Stan::Ispisi()const{
        std::string m;
        if(DajBrojSoba()==2 || DajBrojSoba()==3 || DajBrojSoba()==4 || (DajBrojSoba()>20 && (DajBrojSoba()%10==2 || DajBrojSoba()%10==3 || DajBrojSoba()%10==4)))m="sobe";
        else if(DajBrojSoba()==1 || (DajBrojSoba()>20 && (DajBrojSoba()%10==1)))m="sobu";
        else m="soba";
        
        if(DajNamjesten()==true){
            std::cout << "Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" "<<m <<"."<< " Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan je namjesten.";
        }
        else{
            std::cout << "Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" "<<m <<"."<<" Kvadratura stana je "<<DajKvadraturu() <<" (m^2) i stan nije namjesten.";
        }
    }

class Prodaja{
    std::string agent;
    double cijena;
    Datum dat;
    Kupac klijent;
    Stan  stan;
    public:
    Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,std::string &ime_kupca,const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan,double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac){klijent=novi_kupac;};
    void PromijeniStan(const Stan &novi_stan){stan=novi_stan;};
    void PromijeniDatumKupovine(const Datum &novi_datum){dat=novi_datum;};
    void PromijeniCijenuProdaje(const double &nova_cijena){cijena=nova_cijena;};
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta()const{return agent;};
    std::string DajImeKupca()const{return klijent.DajImePrezime();};
    Datum DajDatumProdaje()const{return dat;};
    double DajCijenuStana()const{return cijena;};
    friend bool ProdatPrije(const Prodaja &p1,const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1,const Prodaja &p2);
    void Ispisi()const;
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan):
    dat(datum_prodaje),klijent(kupac_stana),stan(kupljeni_stan){
        agent=ime_agenta_prodaje;
        cijena=cijena_stana;
    }

Prodaja::Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,std::string &ime_kupca,const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan,double broj_kvadrata):
                dat(Datum(dan_prodaje,mjesec_prodaje,godina_prodaje)),klijent(Kupac(ime_kupca,datum_rodjenja_kupca)),stan(Stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)){
                    agent=ime_agenta_prodaje;
                    cijena=cijena_stana;
                }

void Prodaja::PomjeriDanUnaprijed(){
    int dan,mjesec,godina;
    dan=dat.DajDan();
    mjesec=dat.DajMjesec();
    godina=dat.DajGodinu();
    
    int dani[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0))dani[1]++;
    
    if((dan+1)<=dani[mjesec-1])dat.Postavi(dan+1,mjesec,godina);
    else if((dan+1)>dani[mjesec-1]){
        dan=1;
        if(mjesec+1<=12){
            mjesec++;
            dat.Postavi(dan,mjesec,godina);
        }
        else if((mjesec+1)>12){
            mjesec=1;
            godina++;
            dat.Postavi(dan,mjesec,godina);
        }
    }
}
void Prodaja::PomjeriDanUnazad(){
    int dan,mjesec,godina;
    dan=dat.DajDan();
    mjesec=dat.DajMjesec();
    godina=dat.DajGodinu();
    int dani[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0))dani[1]++;

    if((dan-1)>0)dat.Postavi(dan-1,mjesec,godina);
    else if((dan-1)==0){
        if((mjesec-1)>=1){
            mjesec--;
            dan=dani[mjesec-1];
            dat.Postavi(dan,mjesec,godina);
        }
        else if(mjesec-1==0){
            mjesec=12;
            dan=31;
            godina--;
            dat.Postavi(dan,mjesec,godina);
        }
    }
}

bool ProdatPrije(const Prodaja &p1,const Prodaja &p2){
    Datum d1=p1.DajDatumProdaje();
    Datum d2=p2.DajDatumProdaje();
    if(d1.DajGodinu()<d2.DajGodinu())return true;
    else if(d1.DajGodinu()>d2.DajGodinu())return false;
    else if(d1.DajGodinu()==d2.DajGodinu()){
        if(d1.DajMjesec()<d2.DajMjesec())return true;
        else if(d1.DajMjesec()>d2.DajMjesec())return false;
        else if(d1.DajMjesec()==d2.DajMjesec()){
            if(d1.DajDan()<d2.DajDan())return true;
            else if(d1.DajDan()>d2.DajDan())return false;
        }
    }
}
bool SkupljiStan(const Prodaja &p1,const Prodaja &p2){
    double stan1=p1.DajCijenuStana();
    double stan2=p2.DajCijenuStana();
    if(stan1>stan2)return true;
    else return false;
}

void Prodaja::Ispisi()const{
    std::cout << "Ime agenta: "<< std::setw(30)<<std::left<<DajImeAgenta()<< std::endl;   
    std::cout << "Ime kupca: "<<std::setw(30)<<std::left;
    klijent.Ispisi();
    std::cout << std::endl;
    std::cout << "Zakazani datum prodaje: "<<std::setw(30)<<std::left;
    DajDatumProdaje().Ispisi();
    std::cout << std::endl;
    std::cout << "Cijena stana: "<<std::setw(30)<<std::left<<DajCijenuStana() << std::endl;
    std::cout << "Informacije o stanu: " << std::endl;
    stan.Ispisi();
}

class Prodaje{
    int max_prodaja;
    int br_prodaja;
    Prodaja **niz_prodaja;
    public:
    explicit Prodaje(int max_broj_prodaja){
        max_prodaja=max_broj_prodaja;
        br_prodaja=0;
        try{
            niz_prodaja=new Prodaja*[max_broj_prodaja]{};
        }catch(std::bad_alloc){
            throw ("Alokacija nije uspjela");
        }
    };
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
   ~Prodaje(){for(int i=0;i<max_prodaja;i++){delete niz_prodaja[i];niz_prodaja[i]=nullptr;}delete [] niz_prodaja; max_prodaja=br_prodaja=0;};
   Prodaje(const Prodaje &prodaje);
   Prodaje(Prodaje &&prodaje);
   Prodaje &operator =(const Prodaje &prodaje);
   Prodaje &operator =(Prodaje &&prodaje);
   void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
     double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,
     const Stan &kupljeni_stan);
   void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
     double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,std::string &ime_kupca,
     const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba,bool namjesten_stan,double broj_kvadrata);
   void RegistrirajProdaju(Prodaja *prodaja);
   int DajBrojProdaja()const{return br_prodaja;};
   int DajBrojProdajaNaDatum(const Datum &datum)const;
   int DajBrojProdajaOdAgenta(const std::string &ime_agenta)const;
   Prodaja &DajProdaju(int redni_broj_prodaje);
   Prodaja &DajNajranijuProdaju();
   Prodaja DajNajranijuProdaju()const;
   Prodaja &DajNajskupljuProdaju();
   Prodaja DajNajskupljuProdaju()const;
   void IsprazniKolekciju();
   void ObrisiNajranijuProdaju();
   void ObrisiProdajeAgenta(const std::string&ime_agenta);
   void ObrisiProdajeNaDatum(const Datum &datum);
   void IspisiProdajeNaDatum(const Datum &datum);
   void IspisiSveProdaje()const;
  
};
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja){
    try{
        niz_prodaja=new Prodaja*[spisak_prodaja.size()]{};
        br_prodaja=spisak_prodaja.size();
        max_prodaja=br_prodaja;
        int brojac=0;
        auto pocetak=spisak_prodaja.begin();
        while(pocetak!=spisak_prodaja.end()){
            niz_prodaja[brojac]=new Prodaja(*pocetak);
            pocetak++;
            brojac++;
        }
    }catch(std::bad_alloc){
        for(int i=0;i<spisak_prodaja.size();i++){
            delete niz_prodaja[i];
        }
        delete[]niz_prodaja;
        throw("Alokacija nije uspjela");
    }
}
Prodaje::Prodaje(const Prodaje &prodaje){
    try{
        br_prodaja=prodaje.br_prodaja;
        max_prodaja=prodaje.br_prodaja;
        niz_prodaja=new Prodaja*[max_prodaja];
        for(int i=0;i<br_prodaja;i++)niz_prodaja[i]=new Prodaja(*prodaje.niz_prodaja[i]);
    }
    catch(std::bad_alloc){
        
        for(int i=0;i<br_prodaja;i++)delete niz_prodaja[i];
        delete[] niz_prodaja;
        throw("Alokacija nije uspjela");
    }
    
}
Prodaje::Prodaje(Prodaje &&prodaje){
    br_prodaja=prodaje.br_prodaja;
    max_prodaja=prodaje.max_prodaja;
    niz_prodaja=prodaje.niz_prodaja;
    prodaje.niz_prodaja=nullptr;
    prodaje.br_prodaja=0;
}
Prodaje &Prodaje::operator =(const Prodaje &prodaje){
    if(max_prodaja==prodaje.max_prodaja){
        max_prodaja=prodaje.max_prodaja;
        for(int i=0;i<br_prodaja;i++){
            delete niz_prodaja[i];
            niz_prodaja[i]=nullptr;}
        for(int i=0;i<br_prodaja;i++){
            niz_prodaja[i]=new Prodaja(*prodaje.niz_prodaja[i]);
        }
    }
    else if(max_prodaja>prodaje.max_prodaja){
        for(int i=0;i<br_prodaja;i++){
            delete niz_prodaja[i];
            niz_prodaja[i]=nullptr;
        }
        for(int i=0;i<prodaje.br_prodaja;i++){
            niz_prodaja[i]=new Prodaja(*prodaje.niz_prodaja[i]);
        }
        max_prodaja=prodaje.max_prodaja;
    }
    else if(max_prodaja<prodaje.max_prodaja){
        for(int i=0;i<br_prodaja;i++){
            delete niz_prodaja[i];
            niz_prodaja[i]=nullptr;
        }
        delete[]niz_prodaja;
        niz_prodaja=new Prodaja*[prodaje.max_prodaja]{};
        for(int i=0;i<prodaje.br_prodaja;i++){
            niz_prodaja[i]=new Prodaja(*prodaje.niz_prodaja[i]);
        }
        br_prodaja=prodaje.br_prodaja;
        max_prodaja=prodaje.max_prodaja;
    }
}
Prodaje &Prodaje::operator =(Prodaje &&prodaje){
    if(&prodaje==this) return *this;
    else{
        for(int i=0;i<br_prodaja;i++){
            delete niz_prodaja[i];
            niz_prodaja[i]=nullptr;
        }
        delete[] niz_prodaja;
        br_prodaja=prodaje.br_prodaja;
        max_prodaja=prodaje.max_prodaja;
        prodaje.niz_prodaja=nullptr;
        prodaje.br_prodaja=0;
    }
} 

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum)const{
    int br=std::count_if(niz_prodaja,niz_prodaja+br_prodaja,[datum](Prodaja* p){
        Datum d=p->DajDatumProdaje();
        return (datum.DajDan()==d.DajDan() && datum.DajMjesec()==d.DajMjesec() && datum.DajGodinu()==d.DajGodinu());
    });
    return br;
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta)const{
    int br=std::count_if(niz_prodaja,niz_prodaja+br_prodaja,[ime_agenta](Prodaja *p){
        std::string age=p->DajImeAgenta();
        return(age==p->DajImeAgenta());
    });
    return br;
}

void Prodaje::IsprazniKolekciju(){
    for(int i=0;i<br_prodaja;i++){
        delete niz_prodaja[i];
        niz_prodaja[i]=nullptr;
    }
    br_prodaja=0;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan){
    if(br_prodaja==max_prodaja)throw std::range_error("Dostignut maksimalan broj prodaja");
    else{
        try{
            niz_prodaja[br_prodaja]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
            br_prodaja++;
        }catch(std::bad_alloc){
            throw ("Alokacija nije uspjela");
        }
    }
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,std::string &ime_kupca,const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata){
    if(br_prodaja==max_prodaja)throw std::range_error("Dostignut maskimalan broj prodaja");
    else{
        try{
            niz_prodaja[br_prodaja]=new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
            br_prodaja++;
        }catch(std::bad_alloc){
            throw ("Alokacija nije uspjela");
        }
    }
}
void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(br_prodaja>=max_prodaja){
        delete prodaja; throw std::range_error("Dostignut maksimalan broj pregleda");
    }
    else{
        niz_prodaja[br_prodaja]=prodaja;
        br_prodaja++;
    }
}

Prodaja &Prodaje::DajProdaju(int redni_broj_prodaje){
    if(br_prodaja==0 || redni_broj_prodaje<0)throw std::domain_error("Nema registriranih prodaja");
    for(int i=0;i<br_prodaja;i++){
        if (redni_broj_prodaje==(i+1))return *niz_prodaja[i];
    }
}

Prodaja &Prodaje::DajNajranijuProdaju(){
    if(br_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    auto rano=std::min_element(niz_prodaja,niz_prodaja+br_prodaja,[](Prodaja *p1,Prodaja *p2){
        return ProdatPrije(*p1,*p2);
    });
    return **rano;
}
Prodaja Prodaje::DajNajranijuProdaju()const{
    if(br_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    auto rano=std::min_element(niz_prodaja,niz_prodaja+br_prodaja,[](Prodaja *p1,Prodaja *p2){
        return ProdatPrije(*p1,*p2);
    });
    return **rano;
}

Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(br_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    auto skuplji=std::max_element(niz_prodaja,niz_prodaja+br_prodaja,[](Prodaja *p1,Prodaja *p2){
        return SkupljiStan(*p1,*p2);
    });
    return **skuplji;
}
Prodaja Prodaje::DajNajskupljuProdaju()const{
    if(br_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    auto skuplji=std::max_element(niz_prodaja,niz_prodaja+br_prodaja,[](Prodaja *p1,Prodaja *p2){
        return SkupljiStan(*p1,*p2);
    });
    return **skuplji;
}

void Prodaje::ObrisiNajranijuProdaju(){
    if(br_prodaja==0) throw std::range_error ("Prazna kolekcija");
    Prodaja obrisi=DajNajranijuProdaju();
    
    Datum dat2=obrisi.DajDatumProdaje();
    for(int i=0;i<br_prodaja;i++){
        Datum dat1=niz_prodaja[i]->DajDatumProdaje();
        if(niz_prodaja[i]->DajImeKupca()==obrisi.DajImeKupca() && dat2.DajDan()==dat1.DajDan() && dat1.DajMjesec()==dat2.DajMjesec() && dat1.DajGodinu()==dat2.DajGodinu()){
            delete niz_prodaja[i];
            niz_prodaja[i]=nullptr;
        }
    }
    std::remove_if(niz_prodaja,niz_prodaja+br_prodaja,[obrisi](Prodaja *p){
        return p=nullptr;
    });
    niz_prodaja[br_prodaja]=nullptr;
    br_prodaja--;
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    int b=std::count_if(niz_prodaja,niz_prodaja+br_prodaja,[ime_agenta](Prodaja *p){
        return p->DajImeAgenta()==ime_agenta;
    });
    
    for(int i=0;i<br_prodaja;i++){
        if(niz_prodaja[i]->DajImeAgenta()==ime_agenta){
            delete niz_prodaja[i];
            niz_prodaja[i]=nullptr;
        }
    }
    std::remove_if(niz_prodaja,niz_prodaja+br_prodaja,[ime_agenta](Prodaja *p){
        return p=nullptr;
    });
    for(int i=0;i<b;i++)niz_prodaja[br_prodaja-i]=nullptr;
    br_prodaja=br_prodaja-b;
    
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    int n=std::count_if(niz_prodaja,niz_prodaja+br_prodaja,[datum](Prodaja *p){
        return((p->DajDatumProdaje()).DajDan()==datum.DajDan() && (p->DajDatumProdaje().DajMjesec())==datum.DajMjesec() && (p->DajDatumProdaje()).DajGodinu()==datum.DajGodinu());
    });
    for(int i=0;i<br_prodaja;i++){
        if((niz_prodaja[i]->DajDatumProdaje()).DajDan()==datum.DajDan() && (niz_prodaja[i]->DajDatumProdaje()).DajMjesec()==datum.DajMjesec() && (niz_prodaja[i]->DajDatumProdaje()).DajGodinu()==datum.DajGodinu()){
            delete niz_prodaja[i];
            niz_prodaja[i]=nullptr;
        }
    }
    std::remove_if(niz_prodaja,niz_prodaja+br_prodaja,[datum](Prodaja *p){
        return p=nullptr;
    });
    br_prodaja=br_prodaja-n;
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum){
    int br=DajBrojProdajaNaDatum(datum);
    Prodaja**pomoc=new Prodaja*[br];
    std::remove_copy_if(niz_prodaja,niz_prodaja+br,pomoc,[datum](Prodaja *p){
        Datum dat1=p->DajDatumProdaje();
        if(dat1.DajDan()==datum.DajDan() && dat1.DajMjesec()==datum.DajMjesec() && dat1.DajGodinu()==datum.DajGodinu())return false;
        return true;
    });
    std::sort(pomoc,pomoc+br,[](Prodaja *p1,Prodaja *p2){
        return p1->DajImeKupca()<p2->DajImeKupca();
    });
    for(int i=0;i<br;i++){
        pomoc[i]->Ispisi();
    }
    delete[]pomoc;
}
void Prodaje::IspisiSveProdaje()const{
    Prodaja**pomoc=new Prodaja*[br_prodaja];
    
    for(int i=0;i<br_prodaja;i++){
        pomoc[i]=new Prodaja(*niz_prodaja[i]);
    }
    
    std::sort(pomoc,pomoc+br_prodaja,[](Prodaja *p1,Prodaja *p2){
        if((p1->DajDatumProdaje()).DajDan()==(p2->DajDatumProdaje()).DajDan() && (p1->DajDatumProdaje()).DajMjesec()==(p2->DajDatumProdaje()).DajMjesec() &&
        (p1->DajDatumProdaje()).DajGodinu()==(p2->DajDatumProdaje()).DajGodinu()){
            return p1->DajImeKupca()<p2->DajImeKupca();
        }
        else return ProdatPrije(*p1,*p2);
    });
    for(int i=0;i<br_prodaja;i++){
        pomoc[i]->Ispisi();
    }
    for(int i=0;i<br_prodaja;i++){
        delete pomoc[i];
    }
    delete[] pomoc;
}    

int main ()
{   
    return 0;
    /*int izbor,opcija;
    std::cout << "Dobrodosli!" << std::endl;
    std::cout << std::endl;
    for(;;){
    std::cout << "Izaberite opciju:" << std::endl;
    std::cout << " 0 - kraj" << std::endl;
    std::cout << " 1 - uredjivanje stanova" << std::endl;
    std::cout << " 2 - uredjivanje kupaca" << std::endl;
    std::cout << " 3 - uredjivanje prodaja" << std::endl;
    std::cin >>izbor ;
    if(izbor==0){
        std::cout  << std::endl;
        std::cout  << std::endl;
        std::cout << "Dovidjenja";
        break;
    }
    else if(izbor==1){
        std::vector<Stan> v ;
       while(-1<0){
        {std::cout << "Izaberite opciju:" << std::endl;
        std::cout << " 0 - nazad" << std::endl;
        std::cout << " 1 - dodavanje stana" << std::endl;
        std::cout << " 2 - uredjivanje stanova" << std::endl;
        std::cout << " 3 - ispis svih stanova" << std::endl;
        std::cout << " 4 - kraj" << std::endl;
        }
        std::cin >> opcija;
        std::cin.ignore(100,'\n');
        if(opcija==0)break;
        if(opcija==1){
            std::string adr;int sprat,broj_soba,nmjstn; bool namjesten=false; double kvadratura;
            std::cout << "Unesite adresu: ";
            std::getline(std::cin,adr);
            std::cout << "Unesite sprat: ";
            std::cin >> sprat; std::cin.ignore(1000,'\n');
            std::cout << "Unesite broj soba: ";
            std::cin >> broj_soba; std::cin.ignore(1000,'\n');
            std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
            std::cin >> nmjstn;std::cin.ignore(1000,'\n');
            std::cout << "Unesite kvadraturu: ";
            std::cin >> kvadratura;std::cin.ignore(1000,'\n');
            if(nmjstn==1)namjesten=true;
            else if(nmjstn==0)namjesten=false;
            else {sprat=(-5);};
            try{Stan stan(adr,sprat,broj_soba,namjesten,kvadratura);
            std::cout << "Stan je uspjesno dodan!" << std::endl;
            std::cout  << std::endl;
            v.push_back(stan);
            }catch(std::domain_error e){
                std::cout << "Izuzetak: "<<e.what()<<" Molimo unesite opet." << std::endl;
            }
        }//if za opciju==1
        if(opcija==2){
        std::cout << "Odaberite stan. Dostupni stanovi su: " << std::endl;
        for(int i=0;i<v.size();i++){
            std::cout <<" "<<i+1<<" - ";
            v[i].Ispisi();
            std::cout  << std::endl;
        }
        int odaberi;
        std::cin >> odaberi;
        std::cin.ignore(1000,'\n');
        int br=0;
        for(int i=0;i<v.size();i++){
            if(odaberi==i+1)br=i;break;
        }
        Stan stan_za_urediti=v[br];
        std::cout << "Odaberite polje koji zelite urediti:" << std::endl;
        std::cout << " 0 - nazad"<<std::endl;
        std::cout << " 1 - adresa"<< std::endl;
        std::cout << " 2 - sprat" << std::endl;
        std::cout << " 3 - broj soba" << std::endl;
        std::cout << " 4 - da li je stan namjesten" << std::endl;
        std::cout << " 5 - kvadratura"<<std::endl;
        std::cout << " 6 - sve" << std::endl;
        
        int urediti;
        std::cin >> urediti;
        std::cin.ignore(1000,'\n');
                        if(urediti==0)break;
                        if(urediti==1){//adresa;
                            std::string adresoni;
                            std::cout << "Unesite adresu: ";
                            std::getline(std::cin,adresoni);
                            std::cin.ignore(1000,'\n');
                            stan_za_urediti.Postavi(adresoni,stan_za_urediti.DajSprat(),stan_za_urediti.DajBrojSoba(),stan_za_urediti.DajNamjesten(),stan_za_urediti.DajKvadraturu());
                        }
    
        }
        if(opcija==3){
            for(int i=0;i<v.size();i++){
               std::cout<<i+1<<". ";
               v[i].Ispisi();
               std::cout  << std::endl;
            }
        }
        if(opcija==4){
            std::cout  << std::endl;
            std::cout  << std::endl;
            std::cout << "Dovidjenja";
            break;
        }
    }//beskon.petlja2
    if(opcija==4)break;
    }
    }//beskon.petlja1
    return 0;*/
}