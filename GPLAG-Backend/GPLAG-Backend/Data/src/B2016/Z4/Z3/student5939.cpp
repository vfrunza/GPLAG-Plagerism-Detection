/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <new>
#include <vector>

class Datum{
    int dan,mjesec,godina;
    public:
    Datum(int d, int m, int g){Postavi(d,m,g);}
    void Postavi(int d, int m, int g);
    int DajDan() const{return dan;}
    int DajMjesec() const{return mjesec;};
    int DajGodinu() const{return godina;};
    void Ispisi() const{std::cout<<dan<<"/"<<mjesec<<"/"<<godina;};
};

void Datum::Postavi(int d, int m, int g){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && g%100!=0 || g%400==0){broj_dana[1]++;}
    if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1])throw std::domain_error("Neispravan datum");
    dan = d; mjesec = m;godina = g;
}

class Kupac{
    private:
    std::string imeprez;
    Datum datumrodjenja{1,1,2001};
    static bool jeLiSlovo(char c){
        if((c>='a' && c<='z') || (c>='A' && c<='Z') )return true;
        else return false;
    }
    static bool JeLibroj(char c){
        if((c>='0' && c<='9'))return true;
        else return false;
    }
    public:
    Kupac(const std::string &ime_i_prezime,const Datum &datum_rodjenja){Postavi(ime_i_prezime,datum_rodjenja);}
    void Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja);
    std::string DajImePrezime() const{return imeprez;};
    Datum DajDatumRodjenja() const{return datumrodjenja;};
    void Ispisi()const{std::cout<<imeprez<<" (";this->datumrodjenja.Ispisi();std::cout<<")";};
};

void Kupac::Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja){
    for(int i(0);i<ime_i_prezime.size();i++){            //USLOV ZA IME PREPRAVITI !!!!!!!!!!!!!!!!!!!!!!!!!!!!
    
        if(ime_i_prezime[i]!='-' && ime_i_prezime[i]!='\'' && ime_i_prezime[i]!=' ' && (jeLiSlovo(ime_i_prezime[i])==false && JeLibroj(ime_i_prezime[i])==false))throw std::domain_error("Neispravno ime i prezime");
    }
    imeprez = ime_i_prezime;
   // datumrodjenja=datum_rodjenja;
   datumrodjenja.Postavi(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
}


class Stan{
    std::string adr;
    int spr;
    int brojsoba;
    bool namj;
    double kvdr;
    
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);}
    void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura);
    std::string DajAdresu() const{return adr;}
    int DajSprat() const{return spr;}
    int DajBrojSoba() const {return brojsoba;};
    bool DajNamjesten() const{return namj;};
    double DajKvadraturu() const{return kvdr;}
    void Ispisi() const;
    
};

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura){
    if(sprat<0 || broj_soba<0 || kvadratura<0)throw std::domain_error("Neispravan unos podataka");
    adr = adresa; spr = sprat; brojsoba= broj_soba; namj=namjesten; kvdr=kvadratura;
}

void Stan::Ispisi()const{
    std::cout<<"Stan se nalazi na adresi "<<adr<< " na "<<spr<<". spratu i ima "<<brojsoba;
    if(brojsoba==1)std::cout<<" sobu.";
    else if(brojsoba==2 || brojsoba==3 || brojsoba==4)std::cout<<" sobe.";
    else{ std::cout<<" soba.";}
   
    std::cout<<" Kvadratura stana je "<<kvdr<< " (m^2) i stan ";if(namj)std::cout<<"je namjesten.";else std::cout<<"nije namjesten.";
    
    
}


class Prodaja{
    private:
    std::string agent;
    double cijena_stana;
    Datum datum_prodaje{1,1,2000};
    Kupac kupac_stana{"sda",{1,2,3}};
    Stan kupljeni_stan{"sd",2,3,true,2};
    
    int BrojDana(int mjesec,int godina); 
    
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje,
    const Kupac &kupac_stana,const Stan &kupljeni_stan);
    
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
     std::string &ime_kupca, const Datum &datum_rodjenja_kupca,                  //da li ovdje const string ide
     const std::string &adresa_stana, int sprat_stana, int broj_soba,
     bool namjesten_stan, double broj_kvadrata);
     
    void PromijeniKupca(const Kupac &novi_kupac);
    void PromijeniAgenta(const std::string &novi_agent){agent=novi_agent;};
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje(const double &nova_cijena);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const{return agent;};
    std::string DajImeKupca() const{return kupac_stana.DajImePrezime();};
    Datum DajDatumProdaje() const{return datum_prodaje;};
    double DajCijenuStana() const{return cijena_stana;};
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

//DA LI KOD KONSTRUKTORA TREBA ATRIBUT BITI const std::string imekupca ILI NE !!!!!!!
//prvi konstruktor
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje,
    const Kupac &kupac_stana,const Stan &kupljeni_stan){
        agent = ime_agenta_prodaje;
        this->cijena_stana =cijena_stana;
        (this->datum_prodaje).Postavi(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu());
        (this->kupac_stana).Postavi(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja());
        (this->kupljeni_stan).Postavi(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu());
}

//drugi konstuktor
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
     std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
     const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata){
       agent = ime_agenta_prodaje;
       this->cijena_stana =cijena_stana;
       (this->datum_prodaje).Postavi(dan_prodaje,mjesec_prodaje,godina_prodaje);
        (this->kupac_stana).Postavi(ime_kupca,datum_rodjenja_kupca);
        (this->kupljeni_stan).Postavi(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
}
     
     
void Prodaja::PromijeniKupca(const Kupac &novi_kupac){
    kupac_stana.Postavi(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja());
}

void Prodaja::PromijeniStan(const Stan &novi_stan){
   kupljeni_stan.Postavi(novi_stan.DajAdresu(),novi_stan.DajSprat(),novi_stan.DajBrojSoba(),novi_stan.DajNamjesten(),novi_stan.DajKvadraturu());

}

void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum){
    (this->datum_prodaje).Postavi(novi_datum.DajDan(),novi_datum.DajMjesec(),novi_datum.DajGodinu());
}

void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena){
    this->cijena_stana =nova_cijena;
}

int Prodaja::BrojDana(int mjesec,int godina){               //staticka fja clanica ove klase
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && godina%100!=0 || godina%400==0){broj_dana[1]++;}
    return broj_dana[mjesec-1];
}
void Prodaja::PomjeriDanUnaprijed(){
    //datum prodaje pomjera za dan unaprijed !!!
    int dan = datum_prodaje.DajDan();
    int mjesec = datum_prodaje.DajMjesec();
    int godina = datum_prodaje.DajGodinu();
    dan++;
    if(dan>BrojDana(mjesec,godina)){
        dan =1;mjesec++;
    }
    if(mjesec>12){
        mjesec =1;godina++;
    }
    datum_prodaje.Postavi(dan,mjesec,godina);
}

void Prodaja::PomjeriDanUnazad(){
    int dan = datum_prodaje.DajDan();
    int mjesec = datum_prodaje.DajMjesec();
    int godina = datum_prodaje.DajGodinu();
    dan--;
    if(dan<0){
        mjesec--; if(mjesec<1){mjesec=12;godina--;}dan = BrojDana(mjesec,godina);
    }
    datum_prodaje.Postavi(dan,mjesec,godina);
}

//ove dvije fje vracaju true ako je prvi "ispred" drugog
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    int dan1 = p1.datum_prodaje.DajDan(),mjesec1=p1.datum_prodaje.DajMjesec(),godina1=p1.datum_prodaje.DajGodinu();
    int dan2 = p2.datum_prodaje.DajDan(),mjesec2=p2.datum_prodaje.DajMjesec(),godina2=p2.datum_prodaje.DajGodinu();
    
    if(godina1<godina2 || (godina1==godina2 && ( (mjesec1<mjesec2) || (mjesec1==mjesec2 && dan1<dan2)) ))return true;
    return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    return p1.DajCijenuStana()>p2.DajCijenuStana();
}

void Prodaja::Ispisi()const{
    std::cout<<std::setw(30)<<std::left<<"Ime agenta:";std::cout<<DajImeAgenta();std::cout<<std::endl;
    std::cout<<std::setw(30)<<std::left<<"Ime kupca:";kupac_stana.Ispisi();std::cout<<std::endl; //ovdje NOVI RED ????
    std::cout<<std::setw(30)<<std::left<<"Zakazani datum prodaje:";datum_prodaje.Ispisi();std::cout<<std::endl;
    std::cout<<std::setw(30)<<std::left<<"Cijena stana:";std::cout<<cijena_stana;std::cout<<std::endl;
    std::cout<<"Informacije o stanu:\n";
    kupljeni_stan.Ispisi(); std::cout<<std::endl;   //MOZDA OVDJE NE TREBA NOVI RED AKO GA GORE DODAMO U CLASU STAN !!
}

//klasa Prodaje !!!

class Prodaje{
    private:
    Prodaja **pok_prodaja;
    int max_broj_prodaja;
    int broj_prodaja;
    void DealocirajMemoriju(){
        for(int i=0;i<broj_prodaja;i++)delete pok_prodaja[i];             //da li treba []
        delete [] pok_prodaja;
    };
    
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje(){
        this->DealocirajMemoriju();
    }
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
    double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    
    void RegistrirajProdaju(Prodaja *prodaja);
    
    int DajBrojProdaja()const{return broj_prodaja;};
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    Prodaja &DajProdaju(int ind){if(ind<1 || ind>broj_prodaja)throw std::domain_error("Neispravan broj prodaje"); return *pok_prodaja[ind];}
   //da li treba konstantna verzija gornje metode!!!
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
    
};

//eksplicitni konstruktor
Prodaje::Prodaje(int max_broj_prodaja):max_broj_prodaja(max_broj_prodaja),broj_prodaja(0),pok_prodaja(new Prodaja*[max_broj_prodaja]{}){
    
}

//sekvencijalni konstruktor
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja):max_broj_prodaja(spisak_prodaja.size()),broj_prodaja(spisak_prodaja.size()),pok_prodaja(new Prodaja*[spisak_prodaja.size()]{}){
    int br(0);  //da li treba da brojim broj alociranih ili  su svi nullptr
    try{
        for(auto i=spisak_prodaja.begin();i!=spisak_prodaja.end();i++){
            pok_prodaja[br] = new Prodaja(*i);
            br++;
        }
    }catch(...){
       this->DealocirajMemoriju();
       throw;
    }
    
}

Prodaje::Prodaje(const Prodaje &prodaje):max_broj_prodaja(prodaje.max_broj_prodaja),broj_prodaja(prodaje.broj_prodaja),pok_prodaja(new Prodaja*[prodaje.max_broj_prodaja]{}){
    
    try{
        for(int i=0;i<prodaje.max_broj_prodaja;i++){
            pok_prodaja[i] = new Prodaja(*(prodaje.pok_prodaja[i]));
        }
    }catch(...){
        this->DealocirajMemoriju();
        throw;
    }
}

Prodaje::Prodaje(Prodaje &&prodaje):max_broj_prodaja(prodaje.max_broj_prodaja),broj_prodaja(prodaje.broj_prodaja),pok_prodaja(prodaje.pok_prodaja){
    prodaje.broj_prodaja=0;
    prodaje.pok_prodaja=nullptr;
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje){
    
    if(max_broj_prodaja != prodaje.max_broj_prodaja)throw std::logic_error("Nesaglasni kapaciteti");
    
    if(broj_prodaja>=prodaje.broj_prodaja){
        for(int i=prodaje.broj_prodaja;i<broj_prodaja;i++){
            delete pok_prodaja[i]; pok_prodaja[i] = nullptr ;   //radi destruktora
        }
    }else{
       //mozemo samo djelimocno nadogradit one sto fale ili izbrisat sve, ovdje idemo na drugu opciju 
       
       try{
           Prodaja **novi_pok(new Prodaja*[prodaje.broj_prodaja]);
           this->DealocirajMemoriju();
           pok_prodaja = novi_pok;
       }catch(...){
           throw;   //da li treba bacati ovdje izuzetak
       }
    }
    
    broj_prodaja = prodaje.broj_prodaja;
    for(int i=0;i<prodaje.broj_prodaja;i++)*(pok_prodaja[i])=*(prodaje.pok_prodaja[i]);
    
    return *this;
}


Prodaje &Prodaje::operator =(Prodaje &&prodaje){
     if(max_broj_prodaja != prodaje.max_broj_prodaja)throw std::logic_error("Nesaglasni kapaciteti");
    std::swap(broj_prodaja,prodaje.broj_prodaja);
    std::swap(pok_prodaja,prodaje.pok_prodaja);
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,
                                 const Kupac &kupac_stana,const Stan &kupljeni_stan){
                                     
    if(broj_prodaja==max_broj_prodaja)throw std::range_error("Dostignut maksimalni broj prodaja");
    
    try{
        //ili kreirati novi POK pa ga dodijeliti pokprodaja[brojprodaja]
        for(int i=0;i<broj_prodaja;i++){
            if(pok_prodaja[i]==nullptr){
        pok_prodaja[i] = new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
        broj_prodaja++;}
        }
    }catch(...){
        throw;
    }
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
        
        if(broj_prodaja==max_broj_prodaja)throw std::range_error("Dostignut maksimalni broj prodaja");
    
    try{
        //ili kreirati novi POK pa ga dodijeliti pokprodaja[brojprodaja]
        for(int i=0;i<broj_prodaja;i++){
            if(pok_prodaja[i]==nullptr){
        pok_prodaja[i] = new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,
        ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
        broj_prodaja++;}break;}
    }catch(...){
        throw;
    }
        
    }

void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(broj_prodaja==max_broj_prodaja)throw std::range_error("Dostignut maksimalni broj prodaja");
    //pok_prodaja[broj_prodaja] = prodaja;  //da li ovdje treba alocirat memoriju !!!
    for(int i=0;i<broj_prodaja;i++){
        if(pok_prodaja[i]==nullptr){pok_prodaja[i]=prodaja;break;}
    }
    broj_prodaja++;
}


int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    int brojac = std::count_if(pok_prodaja,pok_prodaja+broj_prodaja,[datum](Prodaja *pok){
        return pok->DajDatumProdaje().DajDan()==datum.DajDan() && pok->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pok->DajDatumProdaje().DajGodinu()==datum.DajGodinu(); });
    return brojac;
}


int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    int brojac = std::count_if(pok_prodaja,pok_prodaja+broj_prodaja,[ime_agenta](Prodaja *pok){
        return ime_agenta==pok->DajImeAgenta();
    });
    return brojac;
}


Prodaja &Prodaje::DajNajranijuProdaju(){
    if(broj_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    
    return **std::min_element(pok_prodaja,pok_prodaja+broj_prodaja,[](Prodaja *pok1,Prodaja *pok2){
        return ProdatPrije(*pok1,*pok2);
    });
 
}


Prodaja Prodaje::DajNajranijuProdaju() const{
    if(broj_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    
    return **std::min_element(pok_prodaja,pok_prodaja+broj_prodaja,[](Prodaja *pok1,Prodaja *pok2){
        return ProdatPrije(*pok1,*pok2);
    });
}

Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(broj_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(pok_prodaja,pok_prodaja+broj_prodaja,[](Prodaja *pok1,Prodaja *pok2){
       return SkupljiStan(*pok1,*pok2); 
    });
}

Prodaja Prodaje::DajNajskupljuProdaju() const{
    if(broj_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(pok_prodaja,pok_prodaja+broj_prodaja,[](Prodaja *pok1,Prodaja *pok2){
       return SkupljiStan(*pok1,*pok2); 
    });
}

void Prodaje::IsprazniKolekciju(){
    for(int i=0;i<broj_prodaja;i++){delete pok_prodaja[i];pok_prodaja[i]=nullptr;}
    broj_prodaja=0;
}


void Prodaje::ObrisiNajranijuProdaju(){
    if(broj_prodaja==0)throw std::range_error("Prazna kolekcija");
    
    delete *std::min_element(pok_prodaja,pok_prodaja+broj_prodaja,[](Prodaja *pok1,Prodaja *pok2){
        return ProdatPrije(*pok1,*pok2);
    });
    broj_prodaja--;         //da li treba one iznad sad naslagat preko ovog poka
}
 
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    int broj = DajBrojProdajaOdAgenta(ime_agenta);
    if(broj!=0){
    for(int i=0;i<broj_prodaja;i++){
        if(pok_prodaja[i]->DajImeAgenta()==ime_agenta){delete pok_prodaja[i];pok_prodaja[i]=nullptr;}
    }
    broj_prodaja-=broj;
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    int broj = DajBrojProdajaNaDatum(datum);
    if(broj!=0){
    for(int i=0;i<broj_prodaja;i++){
        if(pok_prodaja[i]->DajDatumProdaje().DajDan()==datum.DajDan() && pok_prodaja[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec()
        && pok_prodaja[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){delete pok_prodaja[i];pok_prodaja[i]=nullptr;}
    }
    broj_prodaja-=broj;
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    int broj_prodaja_datum = DajBrojProdajaNaDatum(datum);
    //pok->DajDatumProdaje().DajDan()==datum.DajDan() && pok->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pok->DajDatumProdaje().DajGodinu()==datum.DajGodinu(); });
    try{
        Prodaja **novi_pok(new Prodaja*[broj_prodaja_datum]);
        int br = 0;
        for(int i=0;i<broj_prodaja;i++)if(pok_prodaja[i]->DajDatumProdaje().DajDan()==datum.DajDan() && pok_prodaja[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() &&
        pok_prodaja[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){novi_pok[br]=pok_prodaja[i];br++;}
        std::sort(novi_pok,novi_pok+broj_prodaja_datum,[](Prodaja *pok1,Prodaja *pok2){return pok1->DajImeKupca()<pok2->DajImeKupca();});
        for(int i=0;i<br;i++){
            novi_pok[i]->Ispisi();novi_pok[i]=nullptr;
        }
        
        delete[] novi_pok; novi_pok=nullptr;
    }catch(...){
        
    }
}

void Prodaje::IspisiSveProdaje() const{
    try{
        Prodaja **novi_pok(new Prodaja*[broj_prodaja]);
    
        for(int i=0;i<broj_prodaja;i++)novi_pok[i]=pok_prodaja[i];
        std::sort(novi_pok,novi_pok+broj_prodaja,[](Prodaja *pok1,Prodaja *pok2){if(pok1->DajDatumProdaje().DajDan()==pok2->DajDatumProdaje().DajDan() && 
        pok1->DajDatumProdaje().DajMjesec()==pok2->DajDatumProdaje().DajMjesec() && pok1->DajDatumProdaje().DajGodinu()==pok2->DajDatumProdaje().DajGodinu()){return pok1->DajImeKupca()<pok2->DajImeKupca();}
        return ProdatPrije(*pok1,*pok2);});
        for(int i=0;i<broj_prodaja;i++){
            novi_pok[i]->Ispisi();novi_pok[i]=nullptr;
        }
        
        delete[] novi_pok; novi_pok=nullptr; //da li treba alocirat ostale pokazivace
    }catch(...){
        
    }
}


int main ()
{
   
    
    int unos,unos2;
    bool kraj(true);
    Prodaje kolekcija(20);
    std::vector<std::shared_ptr<Stan>> v1;std::vector<std::shared_ptr<Kupac>> v2;
    std::cout<<"Dobrodosli!\n"<<std::endl;
    std::cout<<std::endl;
    
    do{
        std::cout<<"Izaberite opciju:"<<std::endl;
        std::cout<<" 0 - kraj"<<std::endl;
        std::cout<<" 1 - uredjivanje stanova"<<std::endl;
        std::cout<<" 2 - uredjivanje kupaca"<<std::endl;
        std::cout<<" 3 - uredjivanje prodaja"<<std::endl;
        std::cin>>unos;
        
        //prvi dio
        if(unos==0){
            kraj=false;
            break;
        
        //drugi dio    
        }else if(unos==1){
            
            int treba_novi_red(0);
            do{
                
            //if(treba_novi_red)std::cout<<std::endl;
            std::cout<<"Izaberite opciju:"<<std::endl;
            std::cout<<" 0 - nazad"<<std::endl;
            std::cout<<" 1 - dodavanje stana"<<std::endl;
            std::cout<<" 2 - uredjivanje stanova"<<std::endl;
            std::cout<<" 3 - ispis svih stanova"<<std::endl;
            std::cout<<" 4 - kraj"<<std::endl;
            std::cin>>unos2;
            
            if(unos2==0){
                
            }else if(unos2==1){
                bool unos3(false);
                std::string adresa;
                int sprat,broj_soba,namjesten;
                double kvadratura;
                int treba_novi_red2(0);
                
                do{
                    
                    //if(treba_novi_red2)std::cout<<std::endl;
                    std::cout<<"Unesite adresu: ";
                    unos3=false;
                    std::cin.ignore(150,'\n');
                    std::getline(std::cin,adresa);
                    std::cout<<"Unesite sprat: ";
                    std::cin>>sprat;
                    std::cout<<"Unesite broj soba: ";
                    std::cin>>broj_soba;
                    std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                    std::cin>>namjesten;
                    std::cout<<"Unesite kvadraturu: ";
                    std::cin>>kvadratura;
                    
                    try{
                        if(namjesten <0 || namjesten>1)throw std::domain_error("2");
                        v1.push_back(std::make_shared<Stan>(adresa,sprat,broj_soba,namjesten,kvadratura));
                        std::cout<<"Stan je uspjesno dodan!"<<std::endl;
                        treba_novi_red=1;
                    }/*catch(std::exception &izuzetak){
                        std::cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
                        unos3=true;
                        std::cin.clear();
                       // std::cin.ignore(150,'\n');
                    }*/catch(...){
                        std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl;
                        unos3=true;
                        std::cin.clear();
                        treba_novi_red2=1;
                    }
                }while(unos3);
                
            }else if(unos2==2){
                if(v1.empty()){
                    std::cout<<"Nema dostupnih stanova"<<std::endl;break;
                }
                
                std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
                for(int i(0);i<v1.size();i++){
                    std::cout<<i+1<<" - ";
                    v1[i]->Ispisi();
                    std::cout<<std::endl;
                }
                
                int broj_stana, opcija_stan;
                std::cin>>broj_stana;
                
                if(broj_stana<1 || broj_stana>v1.size()){
                    std::cout<<"Neispravan broj stana"<<std::endl; break;
                }
                
                std::cout<<std::endl;
                std::cout<<"Odaberite polje koje zelite urediti:"<<std::endl;
                
                std::cout<<" 0 - nazad"<<std::endl;
                std::cout<<" 1 - adresa"<<std::endl;
                std::cout<<" 2 - sprat"<<std::endl;
                std::cout<<" 3 - broj soba"<<std::endl;
                std::cout<<" 4 - da li je stan namjesten"<<std::endl;
                std::cout<<" 5 - kvadratura"<<std::endl;
                std::cout<<" 6 - sve"<<std::endl;
                
                std::cin>>opcija_stan;
                
                if(opcija_stan==0){
                    
                }else if(opcija_stan==1){
                    bool unos3(false);
                    std::string adresa;
                    
                    do{
                        std::cout<<"Unesite adresu: ";
                        std::cin.ignore(150,'\n');
                        std::getline(std::cin,adresa);
                        unos3=false;
                        
                        try{
                            v1[broj_stana-1]->Postavi(adresa,v1[broj_stana-1]->DajSprat(),v1[broj_stana-1]->DajBrojSoba(),v1[broj_stana-1]->DajNamjesten(),v1[broj_stana-1]->DajKvadraturu());
                            std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                        }catch(...){
                            std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl;
                            unos3=true;
                        }
                        
                    }while(unos3);
                    
                }else if(opcija_stan==2){
                    int sprat;
                    bool unos3(false);
                    
                    do{
                        std::cout<<"Unesite sprat: ";
                        std::cin>>sprat;
                        unos3=false;
                        
                        try{
                            v1[broj_stana-1]->Postavi(v1[broj_stana-1]->DajAdresu(),sprat,v1[broj_stana-1]->DajBrojSoba(),v1[broj_stana-1]->DajNamjesten(),v1[broj_stana-1]->DajKvadraturu());
                            std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                        }catch(...){
                            std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl;
                            unos3=true;
                        }
                        
                    }while(unos3);
                    
                }else if(opcija_stan==3){
                    int br_soba;
                    bool unos3(false);
                    
                    do{
                        std::cout<<"Unesite broj soba: ";
                        std::cin>>br_soba;
                        unos3=false;
                        
                        try{
                            v1[broj_stana-1]->Postavi(v1[broj_stana-1]->DajAdresu(),v1[broj_stana-1]->DajSprat(),br_soba,v1[broj_stana-1]->DajNamjesten(),v1[broj_stana-1]->DajKvadraturu());
                            std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                        }catch(...){
                            std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl;
                            unos3=true;
                        }
                        
                    }while(unos3);
                    
                }else if(opcija_stan==4){
                    int namjesten;
                    bool unos3(false);
                    
                    do{
                        //std::cout<<"Unesite broj soba: ";
                        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                        std::cin>>namjesten;
                        unos3=false;
                        
                        try{
                            v1[broj_stana-1]->Postavi(v1[broj_stana-1]->DajAdresu(),v1[broj_stana-1]->DajSprat(),v1[broj_stana-1]->DajBrojSoba(),namjesten,v1[broj_stana-1]->DajKvadraturu());
                            std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                        }catch(...){
                            std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl;
                            unos3=true;
                        }
                        
                    }while(unos3);
                    
                }else if(opcija_stan==5){
                    double kvadratura;
                    bool unos3(false);
                    
                    do{
                        std::cout<<"Unesite kvadraturu: ";
                        std::cin>>kvadratura;
                        unos3=false;
                        
                        try{
                            v1[broj_stana-1]->Postavi(v1[broj_stana-1]->DajAdresu(),v1[broj_stana-1]->DajSprat(),v1[broj_stana-1]->DajBrojSoba(),v1[broj_stana-1]->DajNamjesten(),kvadratura);
                            std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                        }catch(...){
                            std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl;
                            unos3=true;
                        }
                        
                    }while(unos3);
                    
                }else if(opcija_stan==6){
                    std::string adresa;
                    int sprat,br_soba;
                    bool namjesten;
                    double kvadratura;
                    
                    bool unos3(false);
                    
                    do{
                        std::cout<<"Unesite adresu: ";
                        unos3=false;
                        std::cin.ignore(150,'\n');
                        std::getline(std::cin,adresa);
                        std::cout<<"Unesite sprat: ";
                        std::cin>>sprat;
                        std::cout<<"Unesite broj soba: ";
                        std::cin>>br_soba;
                        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                        std::cin>>namjesten;
                        std::cout<<"Unesite kvadraturu: ";
                        std::cin>>kvadratura;
                        
                        
                        try{
                            v1[broj_stana-1]->Postavi(adresa,sprat,br_soba,namjesten,kvadratura);
                            std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                        }catch(...){
                            std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl;
                            unos3=true;
                        }
                        
                    }while(unos3);
                    
                }
                
            }else if(unos2==3){
                if(v1.empty()){
                    std::cout<<"Nema dostupni stanova"<<std::endl;
                    break;
                }
                
                for(int i(0);i<v1.size();i++){
                    std::cout<<i+1<<". ";
                    v1[i]->Ispisi();
                    std::cout<<std::endl;
                }
                
            }else if(unos2==4){
                kraj=false;
            }
            
            }while(unos2!=0 && unos2!=4);
            
            //UREDIVANJE KUPACA !!!! 2 SLUCAJ    
        }else if(unos==2){
            int treba_novi_red2(0);
            do{
                if(treba_novi_red2)std::cout<<std::endl;
               std::cout<<"Izaberite opciju:"<<std::endl;
                std::cout<<" 0 - nazad"<<std::endl;
                std::cout<<" 1 - dodavanje kupca"<<std::endl;
                std::cout<<" 2 - uredjivanje kupaca"<<std::endl;
                std::cout<<" 3 - ispis svih kupaca"<<std::endl;
                std::cout<<" 4 - kraj"<<std::endl;
                std::cin>>unos2; 
                
                if(unos2==0){
                    
                }else if(unos2==1){
                    
                    bool unos3(false);
                    std::string ime_i_prezime;
                    int dan,mjesec,godina;
                    char znak;
                    
                    do{
                        unos3=false;
                        std::cout<<"Unesite ime i prezime kupca: ";
                        std::cin.ignore(150,'\n');
                        std::getline(std::cin,ime_i_prezime);
                        std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                        std::cin>>dan>>znak>>mjesec>>znak>>godina;
                        
                        try{
                            v2.push_back(std::make_shared<Kupac>(ime_i_prezime,Datum(dan,mjesec,godina)));
                            std::cout<<"Kupac je uspjesno dodan!";std::cout<<std::endl;
                            treba_novi_red2=1;
                        }catch(std::domain_error izuzetak){
                            std::cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
                            unos3=true;
                            std::cin.clear();
                           
                        }
                        
                    }while(unos3);
                    
                }else if(unos2==2){
                    if(v2.empty()){
                        std::cout<<"Nema dostupnih kupaca"<<std::endl;
                        break;
                    }
                    
                    std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<std::endl;
                    for(int i=0;i<v2.size();i++){
                        std::cout<<" "<<i+1<<" - ";
                        v2[i]->Ispisi();
                        std::cout<<std::endl;
                    }
                    
                    int indeks_kupca;
                    std::cin>>indeks_kupca;
                    if(indeks_kupca<1 || indeks_kupca>v2.size()){
                        std::cout<<"Neispravan broj kupca"<<std::endl;break;
                    }
                    
                    bool unos3(false);
                    std::string ime_i_prezime;
                    int dan,mjesec,godina;
                    char znak;
                    
                    do{
                        unos3=false;
                        std::cin.ignore(150,'\n');
                        std::cout<<"Unesite ime i prezime kupca: ";
                        
                        std::getline(std::cin,ime_i_prezime);
                        std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                        std::cin>>dan>>znak>>mjesec>>znak>>godina;
                        
                        try{
                            v2[indeks_kupca-1]->Postavi(ime_i_prezime,Datum(dan,mjesec,godina));
                            std::cout<<"Kupac je uspjesno izmijenjen!";std::cout<<std::endl;
                        }catch(std::domain_error izuzetak){
                            std::cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
                            unos3=true;
                            std::cin.clear();
                            std::cin.ignore(150,'\n');
                        }
                        
                    }while(unos3);
                    
                }else if(unos2==3){
                    if(v2.empty()){
                        std::cout<<"Nema dostupnih kupaca"<<std::endl;
                        break;
                    }
                    
                   
                    for(int i=0;i<v2.size();i++){
                        
                        v2[i]->Ispisi();
                        std::cout<<std::endl;
                    }
                    
                }else if(unos2==4){
                    kraj=false;
                }
                
            }while(unos2!=0 && unos2!=4);
            
            //3 dio 
        }else if(unos==3){
             do{
                std::cout<<"Izaberite opciju:"<<std::endl;
                std::cout<<" 0 - nazad"<<std::endl;
                std::cout<<" 1 - dodavanje prodaje"<<std::endl;
                std::cout<<" 2 - uredjivanje prodaje"<<std::endl;
                std::cout<<" 3 - ispis prodaja"<<std::endl;
                std::cout<<" 4 - brisanje prodaja"<<std::endl;
                std::cout<<" 5 - kraj"<<std::endl;
                std::cin>>unos2;
                
                if(unos2==0){
                    
                }else if(unos2==1){
                    int op3;
                    
                    int treba_novi_red2(0);
                    do{
                        if(treba_novi_red2)std::cout<<std::endl;
                        std::cout<<"Izaberite opciju:"<<std::endl;
                        std::cout<<" 0 - nazad"<<std::endl;
                        std::cout<<" 1 - dodavanje potpuno nove prodaje"<<std::endl;
                        std::cout<<" 2 - dodavanje nove prodaje na osnovu arhive"<<std::endl;
                        std::cout<<" 3 - kraj"<<std::endl;
                        std::cin>>op3;
                        
                        if(op3==0){
                            
                        }else if(op3==1){
                            std::string ime_agenta_prodaje;
                            int d1,m1,g1,d2,m2,g2;
                            int cijena_stana,sprat,broj_soba;
                            bool namjesten;
                            double kvadratura;
                            char znak;
                            std::string ime_kupca,adresa;
                            bool unos3(false);
                            
                            do{
                                unos3=false;
                                std::cout<<"Unesite ime i prezime agenta prodaje: ";
                                std::cin.ignore(150,'\n');
                                std::getline(std::cin,ime_agenta_prodaje);
                                std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                                std::cin>>d1>>znak>>m1>>znak>>g1;
                                std::cout<<"Unesite cijenu stana: ";
                                std::cin>>cijena_stana;
                                std::cout<<"Unesite ime kupca: ";
                                std::cin.ignore(150,'\n');
                                std::getline(std::cin,ime_kupca);
                                std::cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
                                std::cin>>d2>>znak>>m2>>znak>>g2;
                                std::cout<<"Unesite adresu: ";
                                std::cin.ignore(150,'\n');
                                std::getline(std::cin,adresa);
                                std::cout<<"Unesite sprat: ";
                                std::cin>>sprat;
                                std::cout<<"Unesite broj soba: ";
                                std::cin>>broj_soba;
                                std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                                std::cin>>namjesten;
                                std::cout<<"Unesite kvadraturu: ";
                                std::cin>>kvadratura;
                                
                                try{
                                    //prvo dodajmoe u ova dva vektora sljedece elemnte
                                    //prvo dodaj kupca
                                    v2.push_back(std::make_shared<Kupac>(ime_kupca,Datum(d2,m2,g2)));
                                    //dodaj stan
                                    v1.push_back(std::make_shared<Stan>(adresa,sprat,broj_soba,namjesten,kvadratura));
                                    //u kolekciju trpaj ovo 
                                    kolekcija.RegistrirajProdaju(ime_agenta_prodaje,cijena_stana,d1,m1,g1,ime_kupca,Datum(d2,m2,g2),adresa,sprat,broj_soba,namjesten,kvadratura);
                                    std::cout << "Prodaja uspjesno dodana!" << std::endl;
                                    treba_novi_red2=1;
                                }catch(std::range_error e){
                                    std::cout << "Izuzetak: "<< e.what() << std::endl;
                                    break;
                                }catch(...){
                                    std::cout<<"Neispravan unos. Unesite ponovo."<<std::endl;
                                    unos3=true;
                                }
                            }while(unos3);
                            
                        }else if(op3==2){
                            std::string ime_agenta_prodaje;
                            double cijena_stana;
                            int dan,mjesec,godina;
                            char znak;
                            
                            std::cout<<"Unesite ime i prezime agenta prodaje: ";
                            std::cin.ignore(150,'\n');
                            std::getline(std::cin,ime_agenta_prodaje);
                            std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                            std::cin>>dan>>znak>>mjesec>>znak>>godina;
                            std::cout<<"Unesite cijenu stana: ";
                            std::cin>>cijena_stana;
                            if(v2.empty()){
                                std::cout << "Nema dostupni kupaca" << std::endl;
                                break;
                            }
                            
                            std::cout<<"Odaberite kupca. Dostupni kupci su:"<<std::endl;
                            for(int i=0;i<v2.size();i++){
                                std::cout<<i+1<<" - ";
                                v2[i]->Ispisi();
                                std::cout<<std::endl;
                            }
                            
                            int broj_kupca;
                            std::cin>>broj_kupca;
                            if (broj_kupca < 1 || broj_kupca > v2.size()) {
                                std::cout << "Neispravan broj kupca" << std::endl;
                                break;
                            }
                            
                            if (v1.empty()) {
                                std::cout << "Nema dostupni stanova" << std::endl;
                                break;
                            }
                            
                            std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
                            for(int i(0);i<v1.size();i++){
                                std::cout<<i+1<<" - ";
                                v1[i]->Ispisi();
                                std::cout<<std::endl;
                            }
                            
                            int broj_stana;
                            std::cin>>broj_stana;
                            if (broj_stana < 1 || broj_stana > v1.size()) {
                                std::cout << "Neispravan broj stana" << std::endl;
                                break;
                            }
                            
                            try{
                                    kolekcija.RegistrirajProdaju(ime_agenta_prodaje,cijena_stana,Datum(dan,mjesec,godina),*v2[broj_kupca-1],*v1[broj_kupca-1]);
                                    std::cout << "Prodaja uspjesno dodana!" << std::endl;
                            }catch(std::range_error e){
                                    std::cout << "Izuzetak: "<< e.what() << std::endl;
                                    break;
                            }catch(std::domain_error e){
                                    std::cout << "Izuzetak: "<< e.what() << std::endl;
                                    break;
                            }
                            
                            
                        }else if(op3==3){
                            kraj=false;
                        }
                        
                    }while(op3 != 0 && op3!=3);
                 
                 //uredivanje prodaja   
                }else if(unos2==2){
                    
                    std::cout<<"Odaberite prodaju koju želite urediti. Dostupne prodaje su:"<<std::endl;
                   // if(kolekcija.DajBrojProdaja()==0){
                     //   std::cout<<"Nema dostupni prodaja"<<std::endl;
                       // break;
                        
                //    }
                    
                    kolekcija.IspisiSveProdaje();
                    int broj_prodaje;
                    std::cin>>broj_prodaje;
                    if(broj_prodaje<1 || broj_prodaje>kolekcija.DajBrojProdaja()){
                        std::cout<<"Neispravan broj prodaje"<<std::endl;
                        break;
                    }
                    
                    int izmjena_prodaje;
                    std::cout<<"Izaberite opciju:"<<std::endl;
                    std::cout << " 0 - nazad" << std::endl;
                    std::cout << " 1 - izmjena agenta" << std::endl;
                    std::cout << " 2 - izmjena datuma prodaje" << std::endl;
                    std::cout << " 3 - izmjena kupca" << std::endl;
                    std::cout << " 4 - izmjena stana" << std::endl;
                    std::cout << " 5 - izmjena cijene stana" << std::endl;
                    std::cin>>izmjena_prodaje;
                    
                    if(izmjena_prodaje==0){
                        
                    }else if(izmjena_prodaje==1){
                        std::string ime_agenta_prodaje;
                        bool unos3(false);
                        
                        do{
                            std::cout<<"Unesite ime i prezime agenta prodaje: ";
                            std::cin.ignore(150,'\n');
                            std::getline(std::cin,ime_agenta_prodaje);
                            unos3=false;
                            
                            try{
                                kolekcija.DajProdaju(broj_prodaje).PromijeniAgenta(ime_agenta_prodaje);
                                std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                            }catch(...){
                                std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << std::endl;
                                unos3 = true;
                            }
                        }while(unos3);
                    }else if(izmjena_prodaje==2){
                        
                        int dan,mjesec,godina;
                        char znak;
                        bool unos3(false);
                        
                        do{
                            std::cout << "Unesite datum prodaje (formata d/m/g): ";
                            std::cin>>dan>>znak>>mjesec>>znak>>godina>>znak;
                            unos3=false;
                            
                            try{
                                kolekcija.DajProdaju(broj_prodaje).PromijeniDatumKupovine(Datum(dan,mjesec,godina));
                                std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                            }catch(...){
                                std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << std::endl;
                                unos3 = true;
                            }
                        }while(unos3);
                        
                    }else if(izmjena_prodaje==3){
                        std::cout << "Izaberite opciju:" << std::endl;
                        std::cout << " 0 - nazad" << std::endl;
                        std::cout << " 1 - odabir postojeceg kupca" << std::endl;
                        std::cout << " 2 - dodavanje novog kupca" << std::endl;
                        int opcija3;
                        
                        std::cin>>opcija3;
                        if(opcija3==0){
                            
                        }else if(opcija3==1){
                            if(v2.empty()){
                                std::cout<<"Nema dostupni kupaca"<<std::endl;break;
                            }
                            
                            std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<std::endl;
                            for(int i=0;i<v2.size();i++){
                                std::cout<<i+1<<" - ";
                                v2[i]->Ispisi();
                                std::cout<<std::endl;
                            }
                            
                            int broj_kupca;
                            std::cin>>broj_kupca;
                            if (broj_kupca < 1 || broj_kupca > v2.size()) {
                                std::cout << "Neispravan broj kupca" << std::endl;
                                break;
                            }
                            
                            try{
                                kolekcija.DajProdaju(broj_prodaje).PromijeniKupca(*v2[broj_kupca-1]);
                                std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                            }catch(...){
                                std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << std::endl;
                                break;
                            }
                            
                        }else if(opcija3==2){
                            int dan,mjesec,godina;
                            char znak;
                            std::string ime_kupca;
                            bool unos3(false);
                        
                            do{
                                std::cout<<"Unesite ime kupca: ";
                                std::cin.ignore(150,'\n');
                                std::getline(std::cin,ime_kupca);
                                std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                std::cin>>dan>>znak>>mjesec>>znak>>godina>>znak;
                                unos3=false;
                                
                                try{
                                    kolekcija.DajProdaju(broj_prodaje).PromijeniKupca(Kupac(ime_kupca,Datum(dan,mjesec,godina)));
                                    v2.push_back(std::make_shared<Kupac>(ime_kupca,Datum(dan,mjesec,godina)));
                                    std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                                }catch(...){
                                    std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << std::endl;
                                    unos3 = true;
                                }
                            }while(unos3);
                        }
                    }else if(izmjena_prodaje==4){
                        std::cout << "Izaberite opciju:" << std::endl;
                        std::cout << " 0 - nazad" << std::endl;
                        std::cout << " 1 - odabir postojeceg kupca" << std::endl;
                        std::cout << " 2 - dodavanje novog stana" << std::endl;
                        int opcija3;
                        std::cin>>opcija3;
                        
                        if(opcija3==0){
                            
                        }else if(opcija3==1){
                            if (v1.empty()) {
                                std::cout << "Nema dostupni stanova" << std::endl;
                                break;
                            }
                            
                            std::cout<<"Odaberite stan. Dostupni stanovi su: "<<std::endl;
                            for(int i(0);i<v1.size();i++){
                                std::cout<<i+1<<" - ";
                                v1[i]->Ispisi();
                                std::cout<<std::endl;
                            }
                            
                            int broj_stana;
                            std::cin>>broj_stana;
                            if (broj_stana < 1 || broj_stana > v1.size()) {
                                std::cout << "Neispravan broj stana" << std::endl;
                                break;
                            }
                            
                            try{
                                kolekcija.DajProdaju(broj_prodaje).PromijeniStan(*v1[broj_stana-1]);
                                std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                            }catch(...){
                                std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << std::endl;
                                
                            }
                        }else if(opcija3==2){
                            
                        }
                        
                    }else if(izmjena_prodaje==5){
                        //izmjena cijene stana !!
                    }
                    
                }else if(unos2==3){
                    
                }else if(unos2==4){
                    
                }else if(unos2==5){
                    
                }
            
            }while(unos2!=0 && unos2!=2);
        }
        
    }while(kraj);
    
    std::cout<<"Dovidjenja!";
   
	return 0;
}

























































































































































/*
Standardni ulaz:	1
1
Zagrebacka 5
3
-1
1
76.5
Zagrebacka 5
3
5
3
76.5
Zagrebacka 5
3
5
1
-76.5
Zagrebacka 5
3
5
1
76.5
1
Lozionicka 15
2
3
0
87.2
1
Alije Nametka 17
1
4
1
102.98
3
2
2
5
-88.2
88.2
2
1
6
Zagrebacka 6
2
6
1
106.7
3
0
2
1
Niko Nikic
12/8/1981
1
Mujo Mujic
74/15/1976
Mujo Muj&c
13/5/1976
Mujo Mujic
13/5/1976
1
Ana Anic
11/8/1993
3
2
1
Niko Nikic
14/8/1981
0
3
1
1
Agent Agentic
29/5/2017
87985
Neko Nekic
19/3/1988
Hamdije Cemerlica 14
3
4
1
87.9
1
Agent Agentic
19/5/2017
142563
Marko Markovic
17/4/1977
Stupsko brdo 19
5
6
1
128.79
2
Agent Agentic
28/5/2017
65874
1
2
0
2
2
1
Agent Agentic
2
2
2
29/5/2017
2
2
3
1
3
2
2
3
2
Vaso Vasic
34/2/1969
Vaso Vasic
19/2/1969
2
2
4
1
1
2
2
4
2
Zagrebacka 5
3
-1
1
76.5
Okrugla 21
2
5
1
76.5
2
1
5
87986
3
2
29/5/2017
1
2
29/5/2017
3
4
5
6
14/9/2015
7
Agent Agentic
0
4
1
3
17/8/2016
2
Agent Agentic
4
1
0
0
0
*/



















































































































































































































