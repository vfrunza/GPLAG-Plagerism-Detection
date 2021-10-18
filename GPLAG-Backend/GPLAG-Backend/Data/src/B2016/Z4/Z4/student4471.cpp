/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <memory>
#include <new>

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
    
        if(ime_i_prezime[i]!='-' && ime_i_prezime[i]!='\'' && jeLiSlovo(ime_i_prezime[i])==false && JeLibroj(ime_i_prezime[i])==false)throw std::domain_error("Neispravno ime i prezime");
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
    std::cout<<std::endl;
    std::cout<<"Kvadratura stana je "<<kvdr<< " (m^2) i stan ";if(namj)std::cout<<"je namjesten.";else std::cout<<"nije namjesten.";
    
    
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
    std::vector<std::shared_ptr<Prodaja>>pok_prodaja;
  
    int broj_prodaja;
   
    
    public:
    explicit Prodaje();
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    
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
    
    void RegistrirajProdaju(std::shared_ptr<Prodaja> prodaja);
    
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
Prodaje::Prodaje():broj_prodaja(0){

}

//sekvencijalni konstruktor
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja):broj_prodaja(spisak_prodaja.size()){
    pok_prodaja.resize(spisak_prodaja.size());
    int br(0);  //da li treba da brojim broj alociranih ili  su svi nullptr
    try{
        for(auto i=spisak_prodaja.begin();i!=spisak_prodaja.end();i++){
            pok_prodaja[br] = std::shared_ptr<Prodaja>();
            br++;
        }
    }catch(...){
       throw;
    }
    
}

Prodaje::Prodaje(const Prodaje &prodaje):broj_prodaja(prodaje.broj_prodaja){
    try{
    pok_prodaja.resize(prodaje.broj_prodaja);
    try{
        for(int i=0;i<prodaje.broj_prodaja;i++){
            //pok_prodaja[i] = std::shared_ptr<Prodaja>(*(prodaje.pok_prodaja[i]));
            pok_prodaja[i] = std::shared_ptr<Prodaja>(prodaje.pok_prodaja[i]);
        }
    }catch(...){
        
        throw;
    }
    }catch(...){throw;}
}

Prodaje::Prodaje(Prodaje &&prodaje):broj_prodaja(prodaje.broj_prodaja),pok_prodaja(prodaje.pok_prodaja){
    prodaje.broj_prodaja=0;
    prodaje.pok_prodaja.resize(0);
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje){
    
    if(broj_prodaja>=prodaje.broj_prodaja){
        for(int i=prodaje.broj_prodaja;i<broj_prodaja;i++){
             pok_prodaja[i] = nullptr ;   //radi destruktora
        }
    }else{
       //mozemo samo djelimocno nadogradit one sto fale ili izbrisat sve, ovdje idemo na drugu opciju 
       
       try{
           //Prodaja **novi_pok(new Prodaja*[prodaje.broj_prodaja]);
           std::vector<std::shared_ptr<Prodaja>> novi_pok(prodaje.broj_prodaja);
           for(int i=0;i<broj_prodaja;i++)pok_prodaja[i]=nullptr;
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
     
    std::swap(broj_prodaja,prodaje.broj_prodaja);
    std::swap(pok_prodaja,prodaje.pok_prodaja);
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,
                                 const Kupac &kupac_stana,const Stan &kupljeni_stan){
                                     
    
    try{
        //ili kreirati novi POK pa ga dodijeliti pokprodaja[brojprodaja]
        int flag=0;
    for(int i=0;i<broj_prodaja;i++){
        if(pok_prodaja[i]==nullptr){
            pok_prodaja[i] =  std::make_shared<Prodaja>(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
            flag =1;
        }
    }
    
    if(flag==0){
    pok_prodaja.push_back( std::make_shared<Prodaja>(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan));
        broj_prodaja++;
    
    }
        
    }catch(...){
        throw;
    }
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
        
       
    
    try{
        //ili kreirati novi POK pa ga dodijeliti pokprodaja[brojprodaja]
        int flag=0;
    for(int i=0;i<broj_prodaja;i++){
        if(pok_prodaja[i]==nullptr){
            pok_prodaja[i] =  std::make_shared<Prodaja>(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,
        ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) ;
            flag =1;
        }
    }
    
    if(flag==0){
   
    
        pok_prodaja.push_back( std::make_shared<Prodaja>(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,
        ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) );
        broj_prodaja++;}
    }catch(...){
        throw;
    }
        
    }

void Prodaje::RegistrirajProdaju(std::shared_ptr<Prodaja> prodaja){
  
    //pok_prodaja[broj_prodaja] = prodaja;  //da li ovdje treba alocirat memoriju !!!
    //pok_prodaja.push_back(prodaja);
    int flag=0;
    for(int i=0;i<broj_prodaja;i++){
        if(pok_prodaja[i]==nullptr){
            pok_prodaja[i] = prodaja;
            flag =1;
        }
    }
    
    if(flag==0){
    pok_prodaja.push_back(prodaja);
    broj_prodaja++;}
}


int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    int brojac = std::count_if(pok_prodaja.begin(),pok_prodaja.begin()+broj_prodaja,[datum](std::shared_ptr<Prodaja>pok){
        return pok->DajDatumProdaje().DajDan()==datum.DajDan() && pok->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pok->DajDatumProdaje().DajGodinu()==datum.DajGodinu(); });
    return brojac;
}


int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    int brojac = std::count_if(pok_prodaja.begin(),pok_prodaja.begin()+broj_prodaja,[ime_agenta](std::shared_ptr<Prodaja>pok){
        return ime_agenta==pok->DajImeAgenta();
    });
    return brojac;
}


Prodaja &Prodaje::DajNajranijuProdaju(){
    if(broj_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    
    return **std::min_element(pok_prodaja.begin(),pok_prodaja.begin()+broj_prodaja,[](std::shared_ptr<Prodaja>pok1,std::shared_ptr<Prodaja>pok2){
        return ProdatPrije(*pok1,*pok2);
    });
 
}


Prodaja Prodaje::DajNajranijuProdaju() const{
    if(broj_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    
    return **std::min_element(pok_prodaja.begin(),pok_prodaja.begin()+broj_prodaja,[](std::shared_ptr<Prodaja>pok1,std::shared_ptr<Prodaja>pok2){
        return ProdatPrije(*pok1,*pok2);
    });
}

Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(broj_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(pok_prodaja.begin(),pok_prodaja.begin()+broj_prodaja,[](std::shared_ptr<Prodaja>pok1,std::shared_ptr<Prodaja>pok2){
       return SkupljiStan(*pok1,*pok2); 
    });
}

Prodaja Prodaje::DajNajskupljuProdaju() const{
    if(broj_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(pok_prodaja.begin(),pok_prodaja.begin()+broj_prodaja,[](std::shared_ptr<Prodaja>pok1,std::shared_ptr<Prodaja>pok2){
       return SkupljiStan(*pok1,*pok2); 
    });
}

void Prodaje::IsprazniKolekciju(){
    for(int i=0;i<broj_prodaja;i++){pok_prodaja[i]=nullptr;}
    pok_prodaja.resize(0);
    broj_prodaja=0;
}


void Prodaje::ObrisiNajranijuProdaju(){
    if(broj_prodaja==0)throw std::range_error("Prazna kolekcija");
    
    auto t= *std::min_element(pok_prodaja.begin(),pok_prodaja.begin()+broj_prodaja,[](std::shared_ptr<Prodaja>pok1,std::shared_ptr<Prodaja>pok2){
        return ProdatPrije(*pok1,*pok2);
    });
    
   t=nullptr;
    
    broj_prodaja--;         //da li treba one iznad sad naslagat preko ovog poka
}
 
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    int broj = DajBrojProdajaOdAgenta(ime_agenta);
    if(broj!=0){
    for(int i=0;i<broj_prodaja;i++){
        if(pok_prodaja[i]->DajImeAgenta()==ime_agenta){pok_prodaja[i]=nullptr;/*pok_prodaja.erase(pok_prodaja.begin()+i);i--;*/}
    }
    broj_prodaja-=broj;
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    int broj = DajBrojProdajaNaDatum(datum);
    if(broj!=0){
    for(int i=0;i<broj_prodaja;i++){
        if(pok_prodaja[i]->DajDatumProdaje().DajDan()==datum.DajDan() && pok_prodaja[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec()
        && pok_prodaja[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){pok_prodaja[i]=nullptr; /*pok_prodaja.erase(pok_prodaja.begin()+i);i--;*/   }
    }
    broj_prodaja-=broj;
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    int broj_prodaja_datum = DajBrojProdajaNaDatum(datum);
    //pok->DajDatumProdaje().DajDan()==datum.DajDan() && pok->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pok->DajDatumProdaje().DajGodinu()==datum.DajGodinu(); });
    try{
        //Prodaja **novi_pok(new Prodaja*[broj_prodaja_datum]);
        std::vector<std::shared_ptr<Prodaja>>novi_pok(broj_prodaja_datum);
        int br = 0;
        for(int i=0;i<broj_prodaja;i++)if(pok_prodaja[i]->DajDatumProdaje().DajDan()==datum.DajDan() && pok_prodaja[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() &&
        pok_prodaja[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){novi_pok[br]=pok_prodaja[i];br++;}
        std::sort(novi_pok.begin(),novi_pok.begin()+broj_prodaja_datum,[](std::shared_ptr<Prodaja>pok1,std::shared_ptr<Prodaja>pok2){return pok1->DajImeKupca()<pok2->DajImeKupca();});
        for(int i=0;i<br;i++){
            novi_pok[i]->Ispisi();novi_pok[i]=nullptr;
        }
        
       
    }catch(...){
        
    }
}

void Prodaje::IspisiSveProdaje() const{
    try{
        //Prodaja **novi_pok(new Prodaja*[broj_prodaja]);
    std::vector<std::shared_ptr<Prodaja>>novi_pok(broj_prodaja);
        for(int i=0;i<broj_prodaja;i++)novi_pok[i]=pok_prodaja[i];
        std::sort(novi_pok.begin(),novi_pok.begin()+broj_prodaja,[](std::shared_ptr<Prodaja>pok1,std::shared_ptr<Prodaja>pok2){if(pok1->DajDatumProdaje().DajDan()==pok2->DajDatumProdaje().DajDan() && 
      pok1->DajDatumProdaje().DajMjesec()==pok2->DajDatumProdaje().DajMjesec() && pok1->DajDatumProdaje().DajGodinu()==pok2->DajDatumProdaje().DajGodinu()){return pok1->DajImeKupca()<pok2->DajImeKupca();}
       return ProdatPrije(*pok1,*pok2);});
        for(int i=0;i<broj_prodaja;i++){
            novi_pok[i]->Ispisi();novi_pok[i]=nullptr;
        }
        
        //da li treba alocirat ostale pokazivace
    }catch(...){
        
    }
}


/*
(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
    */
int main(){
    Prodaje pok;
    std::string s("ddd");
    pok.RegistrirajProdaju("ds",3,3,3,3,s,{1,1,2},"Dole",5,5,true,23);
    pok.RegistrirajProdaju("sd",3,2,1,1,s,{1,1,1},"gre",5,5,1,24);
    pok.IspisiSveProdaje();
    
    return 0;
}













