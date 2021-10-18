/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <initializer_list>
#include <iomanip>

using namespace std;


class Datum{
    int dan,mjesec,godina;
    public:
    Datum(int dan,int mjesec,int godina);
    void Postavi(int dan,int mjesec,int godina);
    int DajDan() const {return dan;}
    int DajMjesec() const {return mjesec;}
    int DajGodinu() const {return godina;}
    void Ispisi() const { cout<<dan<<"/"<<mjesec<<"/"<<godina; }
};
Datum::Datum(int dan,int mjesec,int godina)
{
   int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
    if(godina<1||dan<1||mjesec<1||mjesec>12||dan>broj_dana[mjesec-1])
    throw std::domain_error("Neispravan datum!");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}
    

void Datum::Postavi(int dan,int mjesec,int godina)
{
      int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
    if(godina<1||dan<1||mjesec<1||mjesec>12||dan>broj_dana[mjesec-1])
    throw std::domain_error("Neispravan datum!");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}
class Kupac{
    string ime_i_prezime;
    Datum datum_rodjenja;
    public:
    Kupac(const string &ime_i_prezime,const Datum &datum_rodjenja);
    void Postavi(const string &ime_i_prezime,const Datum &datum_rodjenja);
    string DajImeIPrezime() const {return ime_i_prezime;}
    Datum DajDatumRodjenja() const {return datum_rodjenja;}
    void Ispisi() const;
};
Kupac::Kupac(const string &ime_i_prezime,const Datum &datum_rodjenja):datum_rodjenja(datum_rodjenja)
{
    for(int i=0;i<ime_i_prezime.length();i++){
        if(!(ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z'|| ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z')&&ime_i_prezime[i]!=' ')
        throw domain_error("Neispravno ime i prezime");
    }
    Kupac::ime_i_prezime=ime_i_prezime;
    
    
}
void Kupac::Postavi(const string &ime_i_prezime,const Datum &datum_rodjenja)
{
    for(int i=0;i<ime_i_prezime.length();i++){
        if(!(ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z'|| ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z')&&ime_i_prezime[i]!=' ')
        throw domain_error("Neispravno ime i prezime");
    }
    Kupac::ime_i_prezime=ime_i_prezime;
    Kupac::datum_rodjenja=datum_rodjenja;
    

}
void Kupac::Ispisi() const
{
    cout<<DajImeIPrezime()<<"("; Kupac::DajDatumRodjenja().Ispisi();cout<<")";
}
class Stan{
    
    string adresa;
    int sprat,broj_soba;
    bool namjesten;
    double kvadratura;
    
    public:
    Stan(const string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura);
    void Postavi(const string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura);
    string DajAdresu() const {return adresa;}
    int DajSprat() const {return sprat;}
    int DajBrojSoba() const {return broj_soba;}
    bool DajNamjesten() const { return namjesten;}
    double DajKvadraturu() const {return kvadratura;}
    void Ispisi() const;
};
Stan::Stan(const string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura)
{
    if(sprat<=0 || broj_soba<=0 || kvadratura<=0) throw domain_error("Neispravan unos podataka");
    Stan::adresa=adresa;
    Stan::sprat=sprat;
    Stan::broj_soba=broj_soba; Stan::namjesten=namjesten;
    Stan::kvadratura=kvadratura;
}
void Stan::Postavi(const string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura)
{
    if(sprat<=0 || broj_soba<=0 || kvadratura<=0) throw domain_error("Neispravan unos podataka");
    Stan::adresa=adresa;
    Stan::sprat=sprat;Stan::broj_soba=broj_soba;Stan::namjesten=namjesten;
    Stan::kvadratura=kvadratura;
}
void Stan::Ispisi() const
{
    cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima ";
    if(DajBrojSoba()==1) cout<<DajBrojSoba()<<" sobu.";
    else if(DajBrojSoba()>1 && DajBrojSoba()<5) cout<<DajBrojSoba()<<" sobe.";
    else cout<<DajBrojSoba()<<" soba.";
    cout<<endl;
    cout<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan ";
    if(DajNamjesten()) cout<<"je namjesten.";
    else cout<<"nije namjesten.";
}
class Prodaja {
    string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    
    public:
    Prodaja(const string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan);
    Prodaja(const string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,string &ime_kupca,const Datum &datum_rodjenja_kupca,
    const string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac);
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje(const double &nova_cijena);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    string DajImeAgenta() const {return ime_agenta_prodaje;}
    string DajImeKupca() const{string ime=kupac_stana.DajImeIPrezime(); return ime;}
    Datum DajDatumProdaje() const {return datum_prodaje;}
    double DajCijenuStana() const {return cijena_stana;}
    friend bool ProdatPrije(const Prodaja &p1,const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1,const Prodaja &p2);
    void Ispisi() const;
    
};
Prodaja::Prodaja(const string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan):cijena_stana(cijena_stana),
datum_prodaje(datum_prodaje),kupac_stana(kupac_stana),kupljeni_stan(kupljeni_stan) {Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;}

Prodaja::Prodaja(const string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,string &ime_kupca,const Datum &datum_rodjenja_kupca,
    const string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata):cijena_stana(cijena_stana),
    datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),kupac_stana(ime_kupca,datum_rodjenja_kupca),kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)
    {Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;}

void Prodaja::PromijeniKupca(const Kupac &novi_kupac)
{
    Prodaja::kupac_stana.Postavi(novi_kupac.DajImeIPrezime(),novi_kupac.DajDatumRodjenja());   
}
void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum)
{
    Prodaja::datum_prodaje.Postavi(novi_datum.DajDan(),novi_datum.DajMjesec(),novi_datum.DajGodinu());
}
void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena)
{
    Prodaja::cijena_stana=nova_cijena;
}
void Prodaja::PomjeriDanUnaprijed()
{
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(Prodaja::datum_prodaje.DajGodinu()%4==0 && Prodaja::datum_prodaje.DajGodinu()%100!=0 || Prodaja::datum_prodaje.DajGodinu()%400==0)
    broj_dana[1]++;
    int a=Prodaja::datum_prodaje.DajDan()+1;
    if(a>broj_dana[Prodaja::datum_prodaje.DajMjesec()-1])
    {
        if(Prodaja::datum_prodaje.DajMjesec()==12) {Prodaja::datum_prodaje.Postavi(1,1,Prodaja::datum_prodaje.DajGodinu()+1);}
        else Prodaja::datum_prodaje.Postavi(1,Prodaja::datum_prodaje.DajMjesec()+1,Prodaja::datum_prodaje.DajGodinu());
    }
    else Prodaja::datum_prodaje.Postavi(a,Prodaja::datum_prodaje.DajMjesec(),Prodaja::datum_prodaje.DajGodinu());
}
void Prodaja::PomjeriDanUnazad()
{
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(Prodaja::datum_prodaje.DajGodinu()%4==0 && Prodaja::datum_prodaje.DajGodinu()%100!=0 || Prodaja::datum_prodaje.DajGodinu()%400==0)
    broj_dana[1]++;
    int a=Prodaja::datum_prodaje.DajDan()-1;
    if(a<1)
    {
        if(Prodaja::datum_prodaje.DajMjesec()==1) Prodaja::datum_prodaje.Postavi(broj_dana[12-1],12,Prodaja::datum_prodaje.DajGodinu()-1);
        else Prodaja::datum_prodaje.Postavi(broj_dana[Prodaja::datum_prodaje.DajMjesec()-2],Prodaja::datum_prodaje.DajMjesec()-1,Prodaja::datum_prodaje.DajGodinu());
        
    }
    else Prodaja::datum_prodaje.Postavi(a,Prodaja::datum_prodaje.DajMjesec(),Prodaja::datum_prodaje.DajGodinu());
    
}
bool ProdatPrije(const Prodaja &p1,const Prodaja &p2)
{
    Datum dat1(p1.DajDatumProdaje()),dat2(p2.DajDatumProdaje());
    int dan1(dat1.DajDan()),mjesec1(dat1.DajMjesec()),godina1(dat1.DajGodinu());
    int dan2(dat2.DajDan()),mjesec2(dat2.DajMjesec()),godina2(dat2.DajGodinu());
    if(godina1<godina2) return true;
    else if(godina1>godina2) return false;
    else if(godina1==godina2 && mjesec1<mjesec2) return true;
    else if(godina1==godina2 && mjesec1>mjesec2) return false;
    else if(godina1==godina2 && mjesec1==mjesec2 && dan1<dan2) return true;
    else return false;
    
}
bool SkupljiStan(const Prodaja &p1,const Prodaja &p2)
{
    return p1.cijena_stana>p2.cijena_stana;
}
void Prodaja::Ispisi() const
{
    cout<<"Ime agenta:"<<setw(30)<<DajImeAgenta()<<endl;
    cout<<"Ime kupca:"<<setw(32); Prodaja::kupac_stana.Ispisi();
    cout<<endl<<"Zakazani datum prodaje:"<<setw(7); Prodaja::datum_prodaje.Ispisi();
    cout<<endl<<"Cijena stana:"<<setw(21)<<DajCijenuStana();
    cout<<endl<<"Informacije o stanu:"<<endl; 
    Prodaja::kupljeni_stan.Ispisi();
    cout<<endl;
}
class Prodaje{
    int max_broj_prodaja;
    int broj_evidentiranih;
    Prodaja **prodaje;
    void AlocirajMemoriju(int velicina);
    void DealocirajMemoriju();
    
    public:
    explicit Prodaje(int max_broj_prodaja):max_broj_prodaja(max_broj_prodaja),broj_evidentiranih(0){AlocirajMemoriju(max_broj_prodaja);}
    Prodaje(initializer_list<Prodaja>spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator=(const Prodaje &prodaje);
    Prodaje &operator=(Prodaje &&prodaje);
    void RegistrirajProdaju(const string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan);
    void RegistrirajProdaju(const string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,string &ime_kupca,const Datum &datum_rodjenja_kupca,
    const string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const {return broj_evidentiranih;}
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
    Prodaja &DajProdaju(int broj);
    
};
void Prodaje::AlocirajMemoriju(int velicina){
    prodaje=nullptr;
    try{
        prodaje=new Prodaja*[velicina];
    }
    catch(...){
        DealocirajMemoriju();
        throw;
    }
}
void Prodaje::IsprazniKolekciju(){
    if(prodaje==nullptr) return;
    for(int i=0;i<broj_evidentiranih;i++) delete prodaje[i];
    delete [] prodaje;
    broj_evidentiranih=0;
}
Prodaje::~Prodaje(){
    for(int i=0;i<broj_evidentiranih;i++) delete prodaje[i];
    delete [] prodaje;
}
Prodaje::Prodaje(initializer_list<Prodaja>spisak_prodaja):broj_evidentiranih(spisak_prodaja.size()),max_broj_prodaja(spisak_prodaja.size()),
prodaje(nullptr){
    int brojac(0);
    try{
        AlocirajMemoriju(max_broj_prodaja);
        for(const auto &x:spisak_prodaja)
        prodaje[brojac++]=new Prodaja(x);
    }
    catch(...){
        DealocirajMemoriju();
        throw;
    }
}
Prodaje::Prodaje(const Prodaje &prodaje):prodaje(new Prodaja*[prodaje.max_broj_prodaja]),max_broj_prodaja(prodaje.max_broj_prodaja),
broj_evidentiranih(prodaje.broj_evidentiranih){
    try{
    for(int i=0;i<prodaje.broj_evidentiranih;i++)
    this->prodaje[i]=new Prodaja(*prodaje.prodaje[i]);
    }
    catch(...)
    {
        DealocirajMemoriju();
        throw;
    }
}
Prodaje::Prodaje(Prodaje &&prodaje):prodaje(prodaje.prodaje),max_broj_prodaja(prodaje.max_broj_prodaja),broj_evidentiranih(prodaje.broj_evidentiranih){
    prodaje.prodaje=nullptr; prodaje.broj_evidentiranih=0;
}
Prodaje &Prodaje::operator=(const Prodaje &prodaje){
    if(prodaje.max_broj_prodaja!=max_broj_prodaja)
    throw logic_error("Prodaje nisu saglasne za dodjelu!");
    if(&prodaje!=this){
        for(int i=0;i<broj_evidentiranih;i++) delete Prodaje::prodaje[i];
        for(int i=0;i<prodaje.broj_evidentiranih;i++)
        this->prodaje[i]=new Prodaja(*prodaje.prodaje[i]);
        broj_evidentiranih=prodaje.broj_evidentiranih;
    }
    return *this;
}
Prodaje &Prodaje::operator=(Prodaje &&prodaje){
    if(prodaje.max_broj_prodaja!=max_broj_prodaja)
    throw logic_error("Prodaje nisu saglasne za dodjelu!");
    if(&prodaje!=this){
        for(int i=0;i<broj_evidentiranih;i++) delete Prodaje::prodaje[i];
        delete [] Prodaje::prodaje;
        Prodaje::prodaje=prodaje.prodaje; broj_evidentiranih=prodaje.broj_evidentiranih;
        prodaje.prodaje=nullptr;prodaje.broj_evidentiranih=0;
    }
    return *this;
}
void Prodaje::DealocirajMemoriju(){
    if(prodaje==nullptr) return;
    for(int i=0;i<broj_evidentiranih;i++) delete prodaje[i];
    delete [] prodaje;
}
void Prodaje::RegistrirajProdaju(const string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,
const Kupac &kupac_stana,const Stan &kupljeni_stan){
    if(broj_evidentiranih==max_broj_prodaja)
    throw range_error("Dostignut maksimalan broj prodaja");
    try{
        prodaje[broj_evidentiranih++]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
    }
    catch(...){
        broj_evidentiranih--;
        throw;
    }
}
void Prodaje::RegistrirajProdaju(const string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,
int godina_prodaje,string &ime_kupca,const Datum &datum_rodjenja_kupca,const string &adresa_stana,int sprat_stana,
int broj_soba,bool namjesten_stan,double broj_kvadrata){
    
    if(broj_evidentiranih==max_broj_prodaja)
    throw range_error("Dostignut maksimalan broj prodaja");
    try{
        prodaje[broj_evidentiranih++]=new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,
        ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    }
    catch(...){
        broj_evidentiranih--;
        throw;
    }
}
void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(broj_evidentiranih==max_broj_prodaja)
    throw range_error("Dostignut maksimalan broj prodaja");
    try{
    prodaje[broj_evidentiranih++]=prodaja;
    }
    catch(...){
        broj_evidentiranih--;
        throw;
    }
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {

    return count_if(prodaje,prodaje+broj_evidentiranih,[datum](const Prodaja *p1)->bool {
        int dan1,mjesec1,godina1;
        dan1=datum.DajDan();mjesec1=datum.DajMjesec();godina1=datum.DajGodinu();
        Datum dat2(p1->DajDatumProdaje());
        int dan2,mjesec2,godina2;
        dan2=dat2.DajDan();mjesec2=dat2.DajMjesec();godina2=dat2.DajGodinu();
        return(dan1==dan2 && mjesec1==mjesec2 && godina1==godina2);
    });
}
int Prodaje::DajBrojProdajaOdAgenta(const string &ime_agenta) const{
    return count_if(prodaje,prodaje+broj_evidentiranih,[ime_agenta](const Prodaja *p1)->bool {
        return(ime_agenta==p1->DajImeAgenta());
    });
}
Prodaja &Prodaje::DajNajranijuProdaju() {
    if(broj_evidentiranih==0)
    throw domain_error("Nema registriranih prodaja");
    return **min_element(prodaje,prodaje+broj_evidentiranih,[](const Prodaja *p1,const Prodaja *p2){
        Datum dat1(p1->DajDatumProdaje()),dat2(p2->DajDatumProdaje());
    int dan1(dat1.DajDan()),mjesec1(dat1.DajMjesec()),godina1(dat1.DajGodinu());
    int dan2(dat2.DajDan()),mjesec2(dat2.DajMjesec()),godina2(dat2.DajGodinu());
    if(godina1<godina2) return true;
    else if(godina1>godina2) return false;
    else if(godina1==godina2 && mjesec1<mjesec2) return true;
    else if(godina1==godina2 && mjesec1>mjesec2) return false;
    else if(godina1==godina2 && mjesec1==mjesec2 && dan1<dan2) return true;
    else return false;
        
    });
    
}
Prodaja Prodaje::DajNajranijuProdaju() const {
    if(broj_evidentiranih==0)
    throw domain_error("Nema registriranih prodaja");
    return **min_element(prodaje,prodaje+broj_evidentiranih,[](const Prodaja *p1,const Prodaja *p2){
        Datum dat1(p1->DajDatumProdaje()),dat2(p2->DajDatumProdaje());
    int dan1(dat1.DajDan()),mjesec1(dat1.DajMjesec()),godina1(dat1.DajGodinu());
    int dan2(dat2.DajDan()),mjesec2(dat2.DajMjesec()),godina2(dat2.DajGodinu());
    if(godina1<godina2) return true;
    else if(godina1>godina2) return false;
    else if(godina1==godina2 && mjesec1<mjesec2) return true;
    else if(godina1==godina2 && mjesec1>mjesec2) return false;
    else if(godina1==godina2 && mjesec1==mjesec2 && dan1<dan2) return true;
    else return false;
        
    });
}
Prodaja &Prodaje::DajNajskupljuProdaju() {
    if(broj_evidentiranih==0)
    throw domain_error("Nema registriranih prodaja");
    return **max_element(prodaje,prodaje+broj_evidentiranih,[](const Prodaja *p1,const Prodaja *p2){
        return p1->DajCijenuStana()>p2->DajCijenuStana();
    });
}
Prodaja Prodaje::DajNajskupljuProdaju() const {
    if(broj_evidentiranih==0)
    throw domain_error("Nema registriranih prodaja");
    return **max_element(prodaje,prodaje+broj_evidentiranih,[](const Prodaja *p1,const Prodaja *p2){
        return p1->DajCijenuStana()>p2->DajCijenuStana();
    });
}
void Prodaje::ObrisiNajranijuProdaju(){
    if(broj_evidentiranih==0)
    throw range_error("Prazna kolekcija");
    DajNajranijuProdaju()=*prodaje[broj_evidentiranih-1];
    delete prodaje[--broj_evidentiranih];
}
void Prodaje::ObrisiProdajeAgenta(const string &ime_agenta){
    if(broj_evidentiranih==0) return;
    for(int i=0;i<broj_evidentiranih;i++){
        if(ime_agenta==prodaje[i]->DajImeAgenta())
        prodaje[i]=prodaje[broj_evidentiranih-1];
        delete prodaje[--broj_evidentiranih];
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    if(broj_evidentiranih==0) return;
    int dan1,mjesec1,godina1;
    dan1=datum.DajDan();mjesec1=datum.DajMjesec();godina1=datum.DajGodinu();
    for(int i=0;i<broj_evidentiranih;i++){
        int dan2,mjesec2,godina2;
        Datum dat=prodaje[i]->DajDatumProdaje();
        dan2=dat.DajDan();mjesec2=dat.DajMjesec();godina2=dat.DajGodinu();
        if(dan1==dan2 && mjesec1==mjesec2 && godina1==godina2)
        prodaje[i]=prodaje[broj_evidentiranih-1];
        delete prodaje[--broj_evidentiranih];
    
    }
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    sort(prodaje,prodaje+broj_evidentiranih,[](const Prodaja *p1,const Prodaja *p2){
        return p1->DajImeKupca()<p2->DajImeKupca();
    });
    
    for(int i=0;i<broj_evidentiranih;i++){
        Datum dat(prodaje[i]->DajDatumProdaje());
        if(dat.DajDan()==datum.DajDan() && dat.DajMjesec()==datum.DajMjesec() && dat.DajGodinu()==datum.DajGodinu())
        prodaje[i]->Ispisi();
    }
    
}
void Prodaje::IspisiSveProdaje() const{
    if(broj_evidentiranih==0) return;
    sort(prodaje,prodaje+broj_evidentiranih,[](const Prodaja *p1,const Prodaja *p2){
        Datum dat1(p1->DajDatumProdaje()),dat2(p2->DajDatumProdaje());
    int dan1(dat1.DajDan()),mjesec1(dat1.DajMjesec()),godina1(dat1.DajGodinu());
    int dan2(dat2.DajDan()),mjesec2(dat2.DajMjesec()),godina2(dat2.DajGodinu());
    if(godina1<godina2) return true;
    else if(godina1>godina2) return false;
    else if(godina1==godina2 && mjesec1<mjesec2) return true;
    else if(godina1==godina2 && mjesec1>mjesec2) return false;
    else if(godina1==godina2 && mjesec1==mjesec2 && dan1<dan2) return true;
    else return p1->DajImeKupca()<p2->DajImeKupca();
       
    });
    for(int i=0;i<broj_evidentiranih;i++) prodaje[i]->Ispisi();
}
Prodaja &Prodaje::DajProdaju(int broj){
    if(broj<0 || broj>max_broj_prodaja) throw domain_error("Nelegalan parametar");
    return *prodaje[broj];
}


    

    

int main ()
{
    
    
	return 0;
}