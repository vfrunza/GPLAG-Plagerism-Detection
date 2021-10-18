/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <exception>
#include <initializer_list>
#include <algorithm>
#include <string>
#include <memory>
#include <vector> 

class Datum{
    int d,m,g;
    public:
    Datum(int dan, int mjesec, int godina){
        if(ProvjeriDatum(dan,mjesec,godina)){d=dan;m=mjesec;g=godina;}
        else throw std::domain_error ("Neispravan datum");
    }
    void Postavi(int dan, int mjesec, int godina){
        if(ProvjeriDatum(dan,mjesec,godina)){d=dan;m=mjesec;g=godina;}
        else throw std::domain_error ("Neispravan datum");
    }
    int DajDan() const{return d;}
    int DajMjesec() const{return m;}
    int DajGodinu() const{return g;}
    void Ispisi() const{std::cout<<d<<"/"<<m<<"/"<<g;}
    static bool ProvjeriDatum(const int dan,const int mjesec,const int godina);
};
class Kupac{
    std::string Ime_i_Prezime;
    Datum Datum_Rodjenja;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):Ime_i_Prezime(ime_i_prezime),
    Datum_Rodjenja(datum_rodjenja) {
        try{ProvjeriImePrezime(Ime_i_Prezime);}
        catch(std::domain_error x){throw x;}
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const{return Ime_i_Prezime;}
    Datum DajDatumRodjenja() const{return Datum_Rodjenja;}
    void Ispisi() const{
        std::cout<<Ime_i_Prezime<<" (";Datum_Rodjenja.Ispisi();std::cout<<")";
    }
    static bool ProvjeriImePrezime(const std::string &ime_i_prezime);
};
class Stan{
    std::string Adresa;
    int Sprat,Broj_soba;
    double Kvadratura;
    bool Namjesten;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,
    double kvadratura){
        if(adresa.size()==0 || sprat<0 || broj_soba<0 || kvadratura<0)throw std::domain_error ("Neispravan unos podataka");
        Adresa=adresa;
        Sprat=sprat;
        Broj_soba=broj_soba;
        Namjesten=namjesten;
        Kvadratura=kvadratura;
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba,
    bool namjesten, double kvadratura){
        if(adresa.size()==0 || sprat<0 || broj_soba<0 ||  kvadratura<0)throw std::domain_error ("Neispravan unos podataka");
        Adresa=adresa;
        Sprat=sprat;
        Broj_soba=broj_soba;
        Namjesten=namjesten;
        Kvadratura=kvadratura;
    }
    std::string DajAdresu() const{return Adresa;}
    int DajSprat() const{return Sprat;}
    int DajBrojSoba() const{return Broj_soba;}
    bool DajNamjesten() const{return Namjesten;}
    double DajKvadraturu() const{return Kvadratura;}
    void Ispisi() const{
        std::cout<<"Stan se nalazi na adresi "<<Adresa<<" na "<<Sprat<<". spratu i ima "<<Broj_soba;
        if(Broj_soba%10==1 && Broj_soba!=11)std::cout<<" sobu.";
        else if(Broj_soba%10>=2 && Broj_soba%10<=4)std::cout<<" sobe.";
        else std::cout<<" soba.";
        std::cout<<" Kvadratura stana je "<<Kvadratura<<" (m^2) i stan ";
        if(Namjesten)std::cout<<"je namjesten.";if(!Namjesten)std::cout<<"nije namjesten.";
    }
};
class Prodaja{
    std::string Ime_Agenta_prodaje;
    double Cijena_stana;
    Datum Datum_prodaje;
    Kupac Kupac_stana;
    Stan Kupljeni_stan;
    public:
    explicit Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan):Datum_prodaje(datum_prodaje),Kupac_stana(kupac_stana),
    Kupljeni_stan(kupljeni_stan){try{
        ProvjeriImePrezime(ime_agenta_prodaje);}catch(std::domain_error x){throw x;}
        Ime_Agenta_prodaje=ime_agenta_prodaje;
        Cijena_stana=cijena_stana;
    }
    explicit Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    int d, int m, int g,std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata):Datum_prodaje(d,m,g),
    Kupac_stana(ime_kupca,datum_rodjenja_kupca),Kupljeni_stan(adresa_stana,sprat_stana,
    broj_soba,namjesten_stan,broj_kvadrata){
        try{ProvjeriImePrezime(ime_agenta_prodaje);}catch(std::domain_error x){throw x;}
        Ime_Agenta_prodaje=ime_agenta_prodaje;
        Cijena_stana=cijena_stana;
    }
    void PromijeniKupca(const Kupac &novi_kupac){Kupac_stana=novi_kupac;}
    void PromijeniStan(const Stan &novi_stan){Kupljeni_stan=novi_stan;}
    void PromijeniDatumKupovine(const Datum &novi_datum){Datum_prodaje=novi_datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena){Cijena_stana=nova_cijena;}
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    Stan DajKupljeniStan()const {return Kupljeni_stan;}
    Kupac DajKupca()const {return Kupac_stana;}
    std::string DajImeAgenta() const{return Ime_Agenta_prodaje;}
    std::string DajImeKupca() const{return Kupac_stana.DajImePrezime();}
    Datum DajDatumProdaje() const{return Datum_prodaje;}
    double DajCijenuStana() const{return Cijena_stana;}
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
    bool ProvjeriImePrezime(const std::string &ime_i_prezime);
};
void Prodaja::Ispisi()const{
    std::cout<<std::setw(32)<<std::left<<"Ime agenta:";std::cout<<DajImeAgenta()<<std::endl;
    std::cout<<std::setw(32)<<std::left<<"Ime kupca:";Kupac_stana.Ispisi();std::cout<<std::endl;
    std::cout<<std::setw(32)<<std::left<<"Zakazani datum prodaje:";Datum_prodaje.Ispisi();std::cout<<std::endl;
    std::cout<<std::setw(32)<<std::left<<"Cijena stana:";std::cout<<DajCijenuStana()<<std::endl;
    std::cout<<std::setw(32)<<"Informacije o stanu:"<<std::endl;Kupljeni_stan.Ispisi();
    std::cout<<std::endl;
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if(p1.Datum_prodaje.DajGodinu()<p2.Datum_prodaje.DajGodinu())return true;
    else if(p1.Datum_prodaje.DajGodinu()==p2.Datum_prodaje.DajGodinu()){
        if(p1.Datum_prodaje.DajMjesec()<p2.Datum_prodaje.DajMjesec())return true;
        else if(p1.Datum_prodaje.DajMjesec()==p2.Datum_prodaje.DajMjesec()){
            if(p1.Datum_prodaje.DajDan()<p2.Datum_prodaje.DajDan())return true;
            else if(p1.Datum_prodaje.DajDan()==p2.Datum_prodaje.DajDan()){
                return p1.DajImeKupca().compare(p2.DajImeKupca())<0;
            }
        }
    }
    return false;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    if(p1.DajCijenuStana()>p2.DajCijenuStana())return true;
    return false;
}

void Prodaja::PomjeriDanUnaprijed(){
    Datum_prodaje.Postavi(Datum_prodaje.DajDan()+1,Datum_prodaje.DajMjesec(),Datum_prodaje.DajGodinu());
    if(Datum::ProvjeriDatum(Datum_prodaje.DajDan(),Datum_prodaje.DajMjesec(),Datum_prodaje.DajGodinu())==false){
        Datum_prodaje.Postavi(1,Datum_prodaje.DajMjesec()+1,Datum_prodaje.DajGodinu());
        if(Datum::ProvjeriDatum(Datum_prodaje.DajDan(),Datum_prodaje.DajMjesec(),Datum_prodaje.DajGodinu())==false){
            Datum_prodaje.Postavi(1,1,Datum_prodaje.DajGodinu()+1);
        }
    }
    
}
void Prodaja::PomjeriDanUnazad(){
    Datum_prodaje.Postavi(Datum_prodaje.DajDan()-1,Datum_prodaje.DajMjesec(),Datum_prodaje.DajGodinu());
    if(Datum::ProvjeriDatum(Datum_prodaje.DajDan(),Datum_prodaje.DajMjesec(),Datum_prodaje.DajGodinu())==false){
        if(Datum_prodaje.DajMjesec()==1)Datum_prodaje.Postavi(31,12,Datum_prodaje.DajGodinu()-1);
        else{
        Datum_prodaje.Postavi(31,Datum_prodaje.DajMjesec()-1,Datum_prodaje.DajGodinu());
        while(Datum::ProvjeriDatum(Datum_prodaje.DajDan(),Datum_prodaje.DajMjesec(),Datum_prodaje.DajGodinu())==false){
            Datum_prodaje.Postavi(Datum_prodaje.DajDan()-1,Datum_prodaje.DajMjesec(),Datum_prodaje.DajGodinu());
        }
    }
    }
}
bool Prestupna(const int godina){
    if(godina%400==0 || (godina%100!=0 && godina%4==0))return true;
    return false;
}
bool Datum::ProvjeriDatum(const int dani,const int mjesec,const int godina){
    if(mjesec>12 || mjesec<0)return false;
    if(dani>31 || dani<0)return false;
    if(mjesec==1 || mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10 || mjesec==12){
        if(dani<1 || dani>31)return false;
    }
    else if(mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11){
        if(dani<1 || dani>30)return false;
    }
    else if(mjesec==2 && Prestupna(godina)==true){
        if(dani>29 || dani<1)return false;
    }
    else if(mjesec==2 && Prestupna(godina)==false){
        if(dani<1 || dani>28)return false;
    }
    return true;
}
bool Kupac::ProvjeriImePrezime(const std::string &ime_i_prezime){
    auto kopija=ime_i_prezime;
    for(auto i:kopija){
        if(i==' ' || i=='-' || i=='\'')continue;
        if(i>='0'&& i<='9')continue;
        if(toupper(i)>'Z' || toupper(i)<'A')throw std::domain_error("Neispravno ime i prezime");
    }
    return true;
}
bool Prodaja::ProvjeriImePrezime(const std::string &ime_i_prezime){
    auto kopija=ime_i_prezime;
    for(auto i:kopija){
        if(i==' ' || i=='-' || i=='\'')continue;
        if(i>='0'&& i<='9')continue;
        if(toupper(i)>'Z' || toupper(i)<'A')throw std::domain_error("Neispravno ime i prezime");
    }
    return true;
}
class Prodaje{
    std::vector<std::shared_ptr<Prodaja>> vek_prodaje; 
    public:
    explicit Prodaje(){};
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja){
        try{
            for(auto i:spisak_prodaja){
                vek_prodaje.push_back(std::shared_ptr<Prodaja>(new Prodaja
                (i.DajImeAgenta(),i.DajCijenuStana(),i.DajDatumProdaje(),
                i.DajKupca(),i.DajKupljeniStan())));
            }
        }catch(...){throw std::domain_error ("Problem sa memorijom");}
    }
    ~Prodaje(){};
    Prodaje(const Prodaje &prodaje);//OK
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);//OK
    Prodaje &operator =(Prodaje &&prodaje);
    void IzmjeniProdaju(std::string &ime_agenta,double cijena,Datum &datum_prodaje,
    Kupac  &kupac,Stan &stan,int index);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
    double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana
    ,int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const{return vek_prodaje.size();}
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;//done
    Prodaja &DajProdaju(int i){return *vek_prodaje[i];}
    Prodaja &DajNajranijuProdaju();//?
    Prodaja DajNajranijuProdaju() const;//ok
    Prodaja &DajNajskupljuProdaju();//?
    Prodaja DajNajskupljuProdaju() const;//?
    void IsprazniKolekciju();//ok
    void ObrisiNajranijuProdaju();//DONE
    void ObrisiProdajeAgenta(const std::string &ime_agenta);//done
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje(int i=0);
};
Prodaje::Prodaje(const Prodaje &p){
    for(int i=0;i<p.vek_prodaje.size();i++){
            vek_prodaje.push_back(std::shared_ptr<Prodaja>(new Prodaja(
            p.vek_prodaje[i]->DajImeAgenta(),p.vek_prodaje[i]->DajCijenuStana(),
            p.vek_prodaje[i]->DajDatumProdaje(),p.vek_prodaje[i]->DajKupca(),
            p.vek_prodaje[i]->DajKupljeniStan())));
        }
    }
Prodaje &Prodaje::operator =(const Prodaje &p){
    for(int i=0;i<p.vek_prodaje.size();i++){vek_prodaje[i]=nullptr;}
    vek_prodaje.resize(0);
        for(int i=0;i<p.vek_prodaje.size();i++){
            vek_prodaje.push_back(std::shared_ptr<Prodaja>(new Prodaja(
            p.vek_prodaje[i]->DajImeAgenta(),p.vek_prodaje[i]->DajCijenuStana(),
            p.vek_prodaje[i]->DajDatumProdaje(),p.vek_prodaje[i]->DajKupca(),
            p.vek_prodaje[i]->DajKupljeniStan())));
        }
    return *this;
}
Prodaje::Prodaje(Prodaje &&p){
    for(int i=0;i<p.vek_prodaje.size();i++){
            vek_prodaje.push_back(std::shared_ptr<Prodaja>(new Prodaja(
            p.vek_prodaje[i]->DajImeAgenta(),p.vek_prodaje[i]->DajCijenuStana(),
            p.vek_prodaje[i]->DajDatumProdaje(),p.vek_prodaje[i]->DajKupca(),
            p.vek_prodaje[i]->DajKupljeniStan())));
            p.vek_prodaje[i]=nullptr;
        }
    p.vek_prodaje.resize(0);
}
Prodaje &Prodaje::operator =(Prodaje &&p){
    for(int i=0;i<p.vek_prodaje.size();i++){vek_prodaje[i]=nullptr;}
    vek_prodaje.resize(0);
    for(int i=0;i<p.vek_prodaje.size();i++){
            vek_prodaje.push_back(std::shared_ptr<Prodaja>(new Prodaja(
            p.vek_prodaje[i]->DajImeAgenta(),p.vek_prodaje[i]->DajCijenuStana(),
            p.vek_prodaje[i]->DajDatumProdaje(),p.vek_prodaje[i]->DajKupca(),
            p.vek_prodaje[i]->DajKupljeniStan())));
            p.vek_prodaje[i]=nullptr;
        }
    p.vek_prodaje.resize(0);
    return *this;
}

void Prodaje::IzmjeniProdaju(std::string &ime_agenta,double cijena,Datum &datum_prodaje,
    Kupac  &kupac,Stan &stan,int index){
        vek_prodaje[index]=nullptr;
        vek_prodaje[index]=std::shared_ptr<Prodaja>(new Prodaja
        (ime_agenta,cijena,datum_prodaje,kupac,stan));
    }
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,
    double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan){
        try{
        vek_prodaje.push_back(std::shared_ptr<Prodaja>(new Prodaja(ime_agenta_prodaje,
        cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan)));
        }
        catch(std::domain_error x){throw x;}
    }
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana,
    int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
        try{
        vek_prodaje.push_back(std::shared_ptr<Prodaja>(new Prodaja(ime_agenta_prodaje,
        dan_prodaje,cijena_stana,mjesec_prodaje,godina_prodaje,ime_kupca,
        datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,
        namjesten_stan,broj_kvadrata)));
        }
        catch(std::domain_error x){throw x;}
    }
void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    try{
        vek_prodaje.push_back(std::shared_ptr<Prodaja>(new Prodaja(prodaja->DajImeAgenta(),
        prodaja->DajCijenuStana(),prodaja->DajDatumProdaje(),prodaja->DajKupca(),
        prodaja->DajKupljeniStan())));
    }
    catch(std::domain_error x){throw x;}
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    int brojac(0);
    std::count_if(&vek_prodaje[0],&vek_prodaje[vek_prodaje.size()],[datum,&brojac]
    (std::shared_ptr<Prodaja> a){
        if(a->DajDatumProdaje().DajDan()==datum.DajDan() && 
        a->DajDatumProdaje().DajMjesec()==datum.DajMjesec()&&
        a->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){brojac++;return true;}
        return false;
    });
    return brojac;
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    return count_if(vek_prodaje.begin(),vek_prodaje.end(),[ime_agenta](std::shared_ptr<Prodaja> a){
        if(a->DajImeAgenta()==ime_agenta){return true;}
        return false;
    });
}
Prodaja Prodaje::DajNajranijuProdaju() const{
    return **(std::min_element(vek_prodaje.begin(),vek_prodaje.end(),[](std::shared_ptr<Prodaja> a,
    std::shared_ptr<Prodaja> b){
        return ProdatPrije(*a,*b);
    }));
}
Prodaja &Prodaje::DajNajranijuProdaju(){
    return **(std::min_element(vek_prodaje.begin(),vek_prodaje.end(),[](std::shared_ptr<Prodaja> a,
    std::shared_ptr<Prodaja> b){
        return ProdatPrije(*a,*b);
    }));

}
Prodaja &Prodaje::DajNajskupljuProdaju(){
    return **(std::max_element(vek_prodaje.begin(),vek_prodaje.end(),[](std::shared_ptr<Prodaja> a,
    std::shared_ptr<Prodaja> b){
        return (a->DajCijenuStana()>b->DajCijenuStana());
    }));

}
Prodaja Prodaje::DajNajskupljuProdaju()const{
    return **(std::max_element(vek_prodaje.begin(),vek_prodaje.end(),[](std::shared_ptr<Prodaja> a,
    std::shared_ptr<Prodaja> b){
        return (a->DajCijenuStana()>b->DajCijenuStana());
    }));
}
void Prodaje::IsprazniKolekciju(){
    for(int i=0;i<vek_prodaje.size();i++){
        vek_prodaje[i]=nullptr;
    }
    vek_prodaje.resize(0);
}
void Prodaje::ObrisiNajranijuProdaju(){
   auto c=DajNajranijuProdaju();
    std::remove_copy_if(vek_prodaje.begin(),vek_prodaje.end(),vek_prodaje.begin(),
    [c](std::shared_ptr<Prodaja> a){
        if(&(*a)==&c){a=nullptr;return true;}
        return false;
    });
    vek_prodaje.resize(vek_prodaje.size()-1);
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    int brojac=0;
    std::remove_copy_if(vek_prodaje.begin(),vek_prodaje.end(),vek_prodaje.begin(),
    [ime_agenta,&brojac](std::shared_ptr<Prodaja> a){
        if(a->DajImeAgenta()==ime_agenta){a=nullptr;brojac++;return true;}
        return false;
    });
    vek_prodaje.resize(vek_prodaje.size()-brojac);
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    int brojac=0;
    std::remove_copy_if(vek_prodaje.begin(),vek_prodaje.end(),vek_prodaje.begin(),
    [datum,&brojac](std::shared_ptr<Prodaja> a){
        if(a->DajDatumProdaje().DajDan()==datum.DajDan() &&
        a->DajDatumProdaje().DajMjesec()==datum.DajMjesec() &&
        a->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
            a=nullptr;brojac++;return true;}
            return false;
    });
    vek_prodaje.resize(vek_prodaje.size()-brojac);
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    std::for_each(vek_prodaje.begin(),vek_prodaje.end(),[datum]
    (std::shared_ptr<Prodaja> a){
        if(a->DajDatumProdaje().DajDan()==datum.DajDan() &&
        a->DajDatumProdaje().DajMjesec()==datum.DajMjesec() &&
        a->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
            a->Ispisi();
        }
    });
}
void Prodaje::IspisiSveProdaje(int i) {
    int brojac=1;
    if(i==1){
        std::sort(vek_prodaje.begin(),vek_prodaje.end(),[]
        (std::shared_ptr<Prodaja> a,std::shared_ptr<Prodaja> b){
            return ProdatPrije(*a,*b);
        });
    }
    std::for_each(vek_prodaje.begin(),vek_prodaje.end(),[&brojac,i]
    (std::shared_ptr<Prodaja> a){
        if(i==0)std::cout<<brojac<<"."<<std::endl;
        a->Ispisi();
        brojac++;
    });
}
void IspisiStanove(std::vector<Stan> stan,int def=0){
    int brojac=1;
    for(auto i:stan){
        if(def==1)std::cout<<" "<<brojac<<" - ";
        if(def==0)std::cout<<brojac<<". ";
        i.Ispisi();std::cout<<std::endl;
        brojac++;
    }
    std::cout<<std::endl;
}
void IspisiKupce(std::vector<Kupac> kupac,int def=0){
    int brojac=1;
    for(auto i:kupac){
        if(def==1)std::cout<<" "<<brojac<<" - ";
        i.Ispisi();std::cout<<std::endl;
        brojac++;
    }
}
int PrviUnos(){
    std::cout<<"Izaberite opciju:"<<std::endl;
    std::cout<<" 0 - kraj"<<std::endl;
    std::cout<<" 1 - uredjivanje stanova"<<std::endl;
    std::cout<<" 2 - uredjivanje kupaca"<<std::endl;
    std::cout<<" 3 - uredjivanje prodaja"<<std::endl;
    int x;
    std::cin>>x;
    return x;

}
int DrugiUnos(){
    std::cout<<"Izaberite opciju:"<<std::endl;
    std::cout<<" 0 - nazad"<<std::endl;
    std::cout<<" 1 - dodavanje potpuno nove prodaje"<<std::endl;
    std::cout<<" 2 - dodavanje nove prodaje na osnovu arhive"<<std::endl;
    std::cout<<" 3 - kraj"<<std::endl;
    int x;
    std::cin>>x;
    return x;
}
int Opcija1(){
    std::cout<<"Izaberite opciju:";
    std::cout<<std::endl<<" 0 - nazad";
    std::cout<<std::endl<<" 1 - dodavanje stana";
    std::cout<<std::endl<<" 2 - uredjivanje stanova";
    std::cout<<std::endl<<" 3 - ispis svih stanova";
    std::cout<<std::endl<<" 4 - kraj"<<std::endl;
    int x;
    std::cin>>x;
    return x;
}
int Opcija2(){
    std::cout<<"Izaberite opciju:";
    std::cout<<std::endl<<" 0 - nazad";
    std::cout<<std::endl<<" 1 - dodavanje kupca";
    std::cout<<std::endl<<" 2 - uredjivanje kupaca";
    std::cout<<std::endl<<" 3 - ispis svih kupaca";
    std::cout<<std::endl<<" 4 - kraj"<<std::endl;
    int x;
    std::cin>>x;
    return x;
}
int Opcija3(){
    std::cout<<"Izaberite opciju:";
    std::cout<<std::endl<<" 0 - nazad";
    std::cout<<std::endl<<" 1 - dodavanje prodaje";
    std::cout<<std::endl<<" 2 - uredjivanje prodaje";
    std::cout<<std::endl<<" 3 - ispis prodaja";
    std::cout<<std::endl<<" 4 - brisanje prodaja";
    std::cout<<std::endl<<" 5 - kraj"<<std::endl;
    int x;
    std::cin>>x;
    return x;
}
int OpcijaIspisiProdaje(){
    std::cout<<"Izaberite opciju:\n";
    std::cout<<" 0 - nazad\n";
    std::cout<<" 1 - ispis svih prodaja\n";
    std::cout<<" 2 - ispis prodaja na datum\n";
    std::cout<<" 3 - ispis najranije prodaje\n";
    std::cout<<" 4 - ispis najskuplje prodaje\n";
    std::cout<<" 5 - ispis broja prodaja\n";
    std::cout<<" 6 - ispis broja prodaja po datumu\n";
    std::cout<<" 7 - ispis broja prodaja po agentu\n";
    std::cout<<" 8 - kraj"<<std::endl;
    int x;
    std::cin>>x;
    return x;
}
Stan DodajStan(){
        std::cin.ignore(10000,'\n');
        std::string adresa_stana;
        int sprat,broj_soba; 
        bool namjesten;int namj;
        double kvadratura;
        std::cout<<"Unesite adresu: ";
        std::getline(std::cin,adresa_stana);
        std::cout<<"Unesite sprat: ";std::cin>>sprat;
        std::cout<<"Unesite broj soba: ";std::cin>>broj_soba;
        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
        std::cin>>namj;
        std::cout<<"Unesite kvadraturu: ";std::cin>>kvadratura;
        if(namj<0 || namj>1)throw std::domain_error("Neispravan unos podataka");
        namjesten=bool(namj);
        Stan vrati=Stan(adresa_stana,sprat,broj_soba,namjesten,kvadratura);
        return vrati;
}
Kupac DodajKupac(int i=0){
    std::cin.ignore(1000,'\n');
    char s;
    std::string ime_i_prezime;
    int d;int m;int g;
    if(i==0)std::cout<<"Unesite ime i prezime kupca: ";
    if(i==1)std::cout<<"Unesite ime kupca: ";
    std::getline(std::cin,ime_i_prezime);
    if(i==0)std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
    if(i==1)std::cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
    std::cin>>d;
    std::cin.get(s);
    std::cin>>m;
    std::cin.get(s);
    std::cin>>g;
    Datum datum(d,m,g);
    Kupac vrati=Kupac(ime_i_prezime,datum);
    return vrati;
}
void DodajProdaje1(Prodaje &prodaje,std::vector<Kupac> &kupac,std::vector<Stan> &stan){
    std::cin.ignore(1000,'\n');
    std::string ime_agenta;
    int dp;int mp;int gp;
    int cijena;
    std::string ime_kupca;
    std::string adresa;
    try{
    std::cout<<"Unesite ime i prezime agenta prodaje: ";
    std::getline(std::cin,ime_agenta);
    std::cout<<"Unesite datum prodaje (formata d/m/g): "; 
    std::cin>>dp;std::cin.get();std::cin>>mp;std::cin.get();std::cin>>gp;
    Datum datum_prodaje=Datum(dp,mp,gp);
    std::cout<<"Unesite cijenu stana: ";
    std::cin>>cijena;
    Kupac dodajk=DodajKupac(1);
    Stan dodajs=DodajStan();
    prodaje.RegistrirajProdaju(ime_agenta,cijena,datum_prodaje,dodajk,dodajs);
    kupac.push_back(dodajk);
    stan.push_back(dodajs);
    }
    catch(std::domain_error x){throw x;}
    catch(std::range_error y){throw y;}

}
void DodajProdaje2(Prodaje &prodaje,std::vector<Kupac> kupac,std::vector<Stan> stan){
    std::cin.ignore(1000,'\n');
    std::string ime_agenta;
    int dp;int mp;int gp;
    int cijena;
    std::string ime_kupca;
    std::string adresa;try{
    std::cout<<"Unesite ime i prezime agenta prodaje: ";
    std::getline(std::cin,ime_agenta);
    std::cout<<"Unesite datum prodaje (formata d/m/g): "; 
    std::cin>>dp;std::cin.get();std::cin>>mp;std::cin.get();std::cin>>gp;
    Datum datum_prodaje=Datum(dp,mp,gp);
    std::cout<<"Unesite cijenu stana: ";
    std::cin>>cijena;
    std::cout<<"Odaberite kupca. Dostupni kupci su:"<<std::endl;
    IspisiKupce(kupac,1);
    int ind_kupc;
    std::cin>>ind_kupc;
    std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
    IspisiStanove(stan,1);
    int ind_stan;
    std::cin>>ind_stan;
    prodaje.RegistrirajProdaju(ime_agenta,cijena,datum_prodaje,kupac[ind_kupc-1],stan[ind_stan-1]);
    }
    catch(std::domain_error x){throw x;}
    catch(std::range_error y){throw y;}
}

void UrediIspisi(){
    std::cout<<" 0 - nazad"<<std::endl;
    std::cout<<" 1 - adresa"<<std::endl;
    std::cout<<" 2 - sprat"<<std::endl;
    std::cout<<" 3 - broj soba"<<std::endl;
    std::cout<<" 4 - da li je stan namjesten"<<std::endl;
    std::cout<<" 5 - kvadratura"<<std::endl;
    std::cout<<" 6 - sve"<<std::endl;
}
int UrediIspisiProdaju(){
    std::cout<<"Izaberite opciju:"<<std::endl;
    std::cout<<" 0 - nazad"<<std::endl;
    std::cout<<" 1 - izmjena agenta"<<std::endl;
    std::cout<<" 2 - izmjena datuma prodaje"<<std::endl;
    std::cout<<" 3 - izmjena kupca"<<std::endl;
    std::cout<<" 4 - izmjena stana"<<std::endl;
    std::cout<<" 5 - izmjena cijene stana"<<std::endl;
    int x;
    std::cin>>x;
    return x;

}
Stan UrediStan(int polje,Stan *stan){
    std::string adresa=stan->DajAdresu();
    int sprat=stan->DajSprat();
    int broj_soba=stan->DajBrojSoba();
    bool namjesten=stan->DajNamjesten();
    double kvadratura=stan->DajKvadraturu();
    Stan vrati=*stan;
    try{
    if(polje==1 || polje==6){
        std::cout<<"Unesite adresu: ";
        std::cin.ignore(1000,'\n');
        std::getline(std::cin,adresa);
    }
    if(polje==2 || polje==6){
        std::cout<<"Unesite sprat: ";
        std::cin>>sprat;
    }
    if(polje==3 || polje==6){
        std::cout<<"Unesite broj soba: ";
        std::cin>>broj_soba;
    }
    if(polje==4 || polje==6){
        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
        int pretvori;
        std::cin>>pretvori;
        if(pretvori>1 || pretvori<0)throw std::domain_error("Neispravan unos.");
        namjesten=int(pretvori);
    }
    if(polje==5 || polje==6){
        std::cout<<"Unesite kvadraturu: ";
        std::cin>>kvadratura;
    }
    vrati=Stan(adresa,sprat,broj_soba,namjesten,kvadratura);
    }
    catch(std::domain_error x){throw x;}
    return vrati;
}
int UrediProdaju(Prodaje &prodaja,int i,int index,std::vector<Stan> &sst
    ,std::vector<Kupac> kkup ,int slucaj=0){
    std::cin.ignore(1000,'\n');
    std::string ime_agenta=prodaja.DajProdaju(index).DajImeAgenta();
    int dp;int mp;int gp;
    Datum datum_prodaje=prodaja.DajProdaju(index).DajDatumProdaje();
    int cijena=prodaja.DajProdaju(index).DajCijenuStana();
    Kupac kupac=prodaja.DajProdaju(index).DajKupca();
    Stan stan=prodaja.DajProdaju(index).DajKupljeniStan();
    try{
    if(i==1){
    std::cout<<"Unesite ime i prezime agenta prodaje: ";
    std::getline(std::cin,ime_agenta);}
    if(i==2){
    std::cout<<std::endl<<"Unesite datum prodaje (formata d/m/g): "; 
    std::cin>>dp;std::cin.get();std::cin>>mp;std::cin.get();std::cin>>gp;
    datum_prodaje=Datum(dp,mp,gp);}
    if(i==5){
    std::cout<<std::endl<<"Unesite cijenu stana: ";
    std::cin>>cijena;}
    if(i==3 && slucaj==0)kupac=DodajKupac(1);
    if(i==3 && slucaj==1){
        std::cout<<"Izaberite opciju:\n";
        std::cout<<" 0 - nazad\n";
        std::cout<<" 1 - odabir postojeceg kupca\n";
        std::cout<<" 2 - dodavanje novog kupca\n";
        int brkup;
        std::cin>>brkup;if(brkup==0)return 0;
        if(brkup==2)kupac=DodajKupac();
    }
    if(i==4)stan=DodajStan();
    //MOZDA TREBA DELETE
    prodaja.DajProdaju(index)=Prodaja(ime_agenta,cijena,datum_prodaje,kupac,stan);
    kkup.push_back(kupac);
    sst.push_back(stan);
    }
    catch(std::domain_error x){throw x;}
    catch(std::range_error y){throw y;}
    return 1;
}
    
int main ()
{
   std::cout<<"Dobrodosli!\n \n \n";
    std::vector<Stan> stan;
    std::vector<Kupac> kupac;
    Prodaje prodaje;
    int u1(0);
    while(1){
        u1=PrviUnos();
        if(u1==0)break;
        if(u1==1){//STANOVI
            while(1){
                int u2=Opcija1();
                if(u2==1){
                    while(1){
                        try{
                            stan.push_back(DodajStan());
                        }
                        catch(std::domain_error x){std::cout<<"Izuzetak: "<<
                        x.what()<<". Molimo unesite opet."<<std::endl;
                        continue;
                        }
                        std::cout<<"Stan je uspjesno dodan!"<<std::endl<<std::endl;
                        break;
                    }
                }
                else if(u2==2){
                    std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
                    IspisiStanove(stan,1);
                    int br_stana;
                    std::cin>>br_stana;
                    std::cout<<"Odaberite polje koje zelite urediti:"<<std::endl;
                    UrediIspisi();
                    int polje;
                    std::cin>>polje;
                    if(polje==0)break;
                    while(1){
                        try{
                            stan[br_stana-1]=UrediStan(polje,&stan[br_stana-1]);
                        }
                        catch(std::domain_error x){std::cout<<"Izuzetak: "<<
                        x.what()<<". Molimo unesite opet."<<std::endl;
                        continue;
                        }
                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl;
                        break;
                    }
                    
                }
                else if(u2==3){
                    
                    IspisiStanove(stan);
                    continue;
                }
                else if(u2==0)break;
            }
            continue;
        }
        if(u1==2){//Kupci
        while(2){
            int u2=Opcija2();
            if(u2==1){
                while(1){
                    try{
                        kupac.push_back(DodajKupac());
                    }
                    catch(std::domain_error x){std::cout<<"Izuzetak: "<<
                            x.what()<<". Molimo unesite opet."<<std::endl;
                            continue;
                            }
                    std::cout<<"Kupac je uspjesno dodan!"<<std::endl<<std::endl;
                    break;
                }
            }
            else if(u2==2){
                std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:";
                std::cout<<std::endl;
                IspisiKupce(kupac,1);
                int broj_kupca;
                std::cin>>broj_kupca;
                while(1){
                    try{
                        kupac[broj_kupca-1]=(DodajKupac());
                    }
                    catch(std::domain_error x){std::cout<<"Izuzetak: "<<
                            x.what()<<". Molimo unesite opet."<<std::endl;
                            continue;
                            }
                    std::cout<<"Kupac je uspjesno izmijenjen!"<<std::endl<<std::endl;
                break;
                }
            continue;
            }
            else if(u2==3){
                IspisiKupce(kupac);
                continue;
            }
            else if(u2==0)break;
        }
    }
    if(u1==3){
            while(3){//PRODAJE
            int u2=Opcija3();
            if(u2==1){
                while(3){
                int u3=DrugiUnos();
                if(u3==1){
                    while(1){
                        try{
                            DodajProdaje1(prodaje,kupac,stan);
                        }
                        catch(std::domain_error x){
                            std::cout<<"Izuzetak: "<<x.what();
                            continue;
                        }
                        catch(std::range_error x){
                            std::cout<<"Izuzetak: "<<x.what();
                            continue;
                        }
                        std::cout<<"Prodaja uspjesno dodana!"<<std::endl<<std::endl;
                        break;
                    }
                }
                if(u3==2){
                    while(1){
                        try{
                            DodajProdaje2(prodaje,kupac,stan);
                        }
                        catch(std::domain_error x){
                            std::cout<<"Izuzetak: "<<x.what();
                            continue;
                        }
                        catch(std::range_error x){
                            std::cout<<"Izuzetak: "<<x.what();
                            continue;
                        }
                        std::cout<<"Prodaja uspjesno dodana!"<<std::endl<<std::endl;
                        break;
                    }
                }
                if(u3==0)break;
                
            continue;
            }
            }
            if(u2==2){
                int u3(0);
                std::cout<<"Odaberite prodaju koju želite urediti. Dostupne prodaje su:"
                <<std::endl;prodaje.IspisiSveProdaje();
                std::cin>>u3;
                while(1){
                    int brojedita=UrediIspisiProdaju();
                    if(brojedita==0)break;
                    try{
                            int i=0;
                            if(brojedita==3){i=1;}
                            if(UrediProdaju(prodaje,brojedita,u3-1,stan,kupac,i)==0)continue;
                        }
                        catch(std::domain_error x){
                            std::cout<<"Izuzetak: "<<x.what();
                            continue;
                        }
                        catch(std::range_error x){
                            std::cout<<"Izuzetak: "<<x.what();
                            continue;
                        }
                        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                        break;
                }
                
            }
            if(u2==3){
                while(3){try{
                int prod=OpcijaIspisiProdaje();
                if(prod==0)break;
                else if(prod==1){prodaje.IspisiSveProdaje(1);}
                else if(prod==2){
                    std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                    int d,m,g;
                    std::cin>>d;std::cin.get();std::cin>>m;std::cin.get();
                    std::cin>>g;std::cin.get();
                    Datum dat(d,m,g);
                    prodaje.IspisiProdajeNaDatum(dat);
                }
                else if(prod==3)prodaje.DajNajranijuProdaju().Ispisi();
                else if(prod==4)prodaje.DajNajskupljuProdaju().Ispisi();
                else if(prod==5)std::cout<<prodaje.DajBrojProdaja();
                else if(prod==6){
                    std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                    int d,m,g;
                    std::cin>>d;std::cin.get();std::cin>>m;std::cin.get();
                    std::cin>>g;std::cin.get();
                    Datum dat(d,m,g);
                    std::cout<<prodaje.DajBrojProdajaNaDatum(dat);
                }
                else if(prod==7){
                    std::cout<<"Unesite ime i prezime agenta prodaje: ";
                    std::cin.ignore(1000,'\n');
                    std::string ime;
                    std::getline(std::cin,ime,'\n');
                    std::cout<<prodaje.DajBrojProdajaOdAgenta(ime);
                }
                else if(prod==8)return 0;
                }
                catch(std::domain_error x){
                    std::cout<<"Izuzetak: "<<x.what();
                    continue;
                }}
            }
            if(u2==0)break;
        
        }
    }
    if(u1==0)break;
    }
    std::cout<<std::endl<<std::endl<<"Dovidjenja!";
	return 0;
}