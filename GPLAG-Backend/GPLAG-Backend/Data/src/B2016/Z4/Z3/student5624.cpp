/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
class Datum{
    int d, m, g;
    
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const;
    int DajMjesec() const;
    int DajGodinu() const;
    void Ispisi() const;
};
int DatumPP(Datum d1, Datum d2){
    if(d1.DajGodinu()>d2.DajGodinu()) return 1;
    if(d1.DajGodinu()==d2.DajGodinu() && d1.DajMjesec()>d2.DajMjesec()) return 1;
    if(d1.DajGodinu()==d2.DajGodinu() && d1.DajMjesec()==d2.DajMjesec() && d1.DajDan()>d2.DajDan()) return 1;
    if(d1.DajGodinu()<d2.DajGodinu()) return -1;
    if(d1.DajGodinu()==d2.DajGodinu() && d1.DajMjesec()<d2.DajMjesec()) return -1;
    if(d1.DajGodinu()==d2.DajGodinu() && d1.DajMjesec()==d2.DajMjesec() && d1.DajDan()<d2.DajDan()) return -1;
    if(d1.DajGodinu()==d2.DajGodinu() && d1.DajMjesec()==d2.DajMjesec() && d1.DajDan()==d2.DajDan()) return 0;
}
Datum::Datum(int dan, int mjesec, int godina){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0 )|| godina%400==0)
        broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 ||mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum");
        d=dan;
        m=mjesec; 
        g=godina;
}
void Datum::Postavi(int dan, int mjesec, int godina){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0 )|| godina%400==0)
        broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 ||mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum");
        d=dan;
        m=mjesec; 
        g=godina;
}
int Datum::DajDan() const{
    return d;
}
int Datum::DajGodinu() const{
    return g;
}
int Datum::DajMjesec() const{
    return m;
}
void Datum::Ispisi() const{
    std::cout<<"("<<d<<"/"<<m<<"/"<<g<<")";
}
bool IstiDatumi(Datum dat1, Datum dat2){
    if(dat1.DajDan()==dat2.DajDan() && dat1.DajMjesec()==dat2.DajMjesec() && dat1.DajGodinu()==dat2.DajGodinu()) return true;
    return false;
}
class Kupac{
    std::string ip;
    Datum d;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const;
    Datum DajDatumRodjenja() const;
    void Ispisi() const;
};
Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):
d(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu()){
    ip=ime_i_prezime;
    //provjera imena
}
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    int dan(datum_rodjenja.DajDan()), mjesec(datum_rodjenja.DajMjesec()), godina(datum_rodjenja.DajGodinu());
    d.Postavi(dan, mjesec, godina);
    ip=ime_i_prezime;/*
    for(int i=0; i<ime_i_prezime.length();i++)
        if(ime_i_prezime[i]) //a A zz*/
}
std::string Kupac::DajImePrezime() const{
    return ip;
}
Datum Kupac::DajDatumRodjenja() const{
    return d;
}
void Kupac::Ispisi() const{
    std::cout<<ip<<" ("<<d.DajDan()<<"/"<<d.DajMjesec()<<"/"<<d.DajGodinu()<<")";
}
class Stan{
    std::string ad;
    int s, brs;
    double kv;
    bool namj;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    void Postavi( const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const;
    int DajSprat() const;
    int DajBrojSoba() const;
    bool DajNamjesten() const;
    double DajKvadraturu() const;
    void Ispisi() const;
};
Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    ad=adresa; if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    s=sprat; brs=broj_soba; namj=namjesten; kv=kvadratura;
}
void Stan::Postavi( const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    ad=adresa; if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    s=sprat; brs=broj_soba; namj=namjesten; kv=kvadratura;
}
std::string Stan::DajAdresu() const{
    return ad;
}
int Stan::DajSprat() const{
    return s;
}
int Stan::DajBrojSoba() const{
    return brs;
}
bool Stan::DajNamjesten() const{
    return namj;
}
double Stan::DajKvadraturu() const{
    return kv;
}
void Stan::Ispisi() const{
    if(brs==1){
       std::cout<<"Stan se nalazi na adresi "<<ad<<" na "<<s<<" spratu i ima 1 sobu."<<std::endl; 
    }
    if(brs==2 || brs==3 || brs==4){
        std::cout<<"Stan se nalazi na adresi "<<ad<<" na "<<s<<" spratu i ima "<<brs<<" sobe."<<std::endl;  
    }
    else {
        std::cout<<"Stan se nalazi na adresi "<<ad<<" na "<<s<<" spratu i ima "<<brs<<" soba."<<std::endl;
    }
    if(namj){
        std::cout<<"Kvadratura stana je "<<kv<<" (m^2) i stan je namjesten.";
    }
    if(!namj){
        std::cout<<"Kvadratura stana je "<<kv<<" (m^2) i stan nije namjesten.";
    }
}
class Prodaja{
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan&kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac);
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje(const double &nova_cijena);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const;
    std::string DajImeKupca() const;
    Datum DajDatumProdaje() const;
    double DajCijenuStana() const;
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan&kupljeni_stan)
:datum_prodaje(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()),kupac_stana(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja()),
kupljeni_stan(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu()){
    Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
    Prodaja::cijena_stana=cijena_stana;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):
datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata){
    Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
    Prodaja::cijena_stana=cijena_stana;
}
void Prodaja::PromijeniKupca(const Kupac &novi_kupac){
    kupac_stana.Postavi(novi_kupac.DajImePrezime(), novi_kupac.DajDatumRodjenja());
}
void Prodaja::PromijeniStan(const Stan &novi_stan){
    kupljeni_stan.Postavi(novi_stan.DajAdresu(), novi_stan.DajSprat(), novi_stan.DajBrojSoba(), novi_stan.DajNamjesten(), novi_stan.DajKvadraturu());
}
void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum){
    datum_prodaje.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(), novi_datum.DajGodinu());
}
void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena){
    cijena_stana=nova_cijena;
}
void Prodaja::PomjeriDanUnaprijed(){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    int dan=datum_prodaje.DajDan(), mjesec=datum_prodaje.DajMjesec(), godina=datum_prodaje.DajGodinu();
    if((godina%4==0 &&godina%100!=0) ||godina%400==0)
        broj_dana[1]++;
    dan++;
    if(dan>broj_dana[mjesec-1]) dan=1, mjesec++;
    if(mjesec>12) mjesec=1, godina++;
    datum_prodaje.Postavi(dan, mjesec, godina);
}
void Prodaja::PomjeriDanUnazad(){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    int dan=datum_prodaje.DajDan(), mjesec=datum_prodaje.DajMjesec(), godina=datum_prodaje.DajGodinu();
    if((godina%4==0 &&godina%100!=0) ||godina%400==0)
        broj_dana[1]++;
    dan--;
    if(dan>0) dan=broj_dana[mjesec-2], mjesec--;
    if(mjesec<0) mjesec=12, godina--;
    datum_prodaje.Postavi(dan, mjesec, godina);
    
}
std::string Prodaja::DajImeAgenta() const{
    return ime_agenta_prodaje;
}
std::string Prodaja::DajImeKupca() const{
    return kupac_stana.DajImePrezime();
}
Datum Prodaja::DajDatumProdaje() const{
    return datum_prodaje;
}
double Prodaja::DajCijenuStana() const{
    return cijena_stana;
}
void Prodaja::Ispisi() const{
    //ispis poravnanje
    std::cout<<"Ime agenta"<<ime_agenta_prodaje<<std::endl;
    std::cout<<"Ime kupca";
    kupac_stana.Ispisi();
    std::cout<<std::endl;
    std::cout<<"Zakazani datum prodaje";
    datum_prodaje.Ispisi();
    std::cout<<"Cijena stana: "<<cijena_stana<<std::endl;
    std::cout<<"Informacije o stanu: "<<std::endl;
    kupljeni_stan.Ispisi();
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if(DatumPP(p1.DajDatumProdaje(), p2.DajDatumProdaje())==-1) return true;
    return false;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    if(p1.DajCijenuStana()>p2.DajCijenuStana()) return true;
    return false;
}
class Prodaje{
    int stanje, kapacitet;
    Prodaja **pok;
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator=(const Prodaje&prodaje){
        if(this==&prodaje) return *this;
        for(int i=0; i<stanje; i++) delete pok[i];
        delete [] pok;
        stanje=prodaje.DajBrojProdaja(); kapacitet=prodaje.DajBrojProdaja();
        pok=new Prodaja*[kapacitet];
        for(int i=0; i<stanje; i++) pok[i]=new Prodaja(*prodaje.pok[i]);
        return *this;
    }
    Prodaje &operator=(Prodaje&&prodaje){
        if(this==&prodaje) return *this;
        for(int i=0; i<stanje; i++) delete pok[i];
        delete [] pok;
        stanje=prodaje.stanje;
        kapacitet=prodaje.kapacitet;
        pok=prodaje.pok;
        prodaje.pok=nullptr;
        prodaje.stanje=0;
        return *this;
    }
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
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
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
    Prodaja& DajProdaju(int n){
        if(n-1>stanje) throw std::domain_error("Ne postoji toliko prodaja");
        return *pok[n-1];
    }
};
Prodaje::Prodaje(int max_broj_prodaja){
    kapacitet=max_broj_prodaja;
    stanje=0;
    pok= new Prodaja*[max_broj_prodaja];
}
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja){
    kapacitet=spisak_prodaja.size();
    stanje=kapacitet;
    pok=new Prodaja *[kapacitet];
    for( int i=0; i<kapacitet; i++) pok[i]=nullptr;
    auto it=spisak_prodaja.begin();
    for(int i=0; i<stanje; i++){
        pok[i]=new Prodaja(*it);
        it++;
    }
}
Prodaje::~Prodaje(){
    for(int i=0; i<stanje; i++) delete pok[i];
    delete [] pok;
    }
Prodaje::Prodaje(const Prodaje &prodaje){
    stanje=prodaje.stanje;
    kapacitet=prodaje.kapacitet;
    pok=new Prodaja*[kapacitet];
    for(int i=0; i<stanje; i++)
        pok[i]=new Prodaja(*prodaje.pok[i]);
}
Prodaje::Prodaje(Prodaje &&prodaje){
    stanje=prodaje.stanje;
    kapacitet=prodaje.kapacitet;
    pok=prodaje.pok;
    prodaje.pok=nullptr;
    prodaje.stanje=0;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
    if(stanje +1>kapacitet) throw std::range_error("Dostignut maksimalan broj prodaja");
    pok[stanje]=new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
    stanje++;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
    if(stanje +1>kapacitet) throw std::range_error("Dostignut maksimalan broj prodaja");
    pok[stanje]=new Prodaja(ime_agenta_prodaje, cijena_stana, Datum(dan_prodaje, mjesec_prodaje, godina_prodaje), Kupac(ime_kupca, datum_rodjenja_kupca), Stan(adresa_stana,sprat_stana, broj_soba, namjesten_stan, broj_kvadrata));
    stanje++;
}
void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(stanje +1>kapacitet) throw std::range_error("Dostignut maksimalan broj prodaja");
    pok[stanje]=new Prodaja(*prodaja);
    stanje++;
}
int Prodaje::DajBrojProdaja() const{
    return stanje;
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    int a=std::count_if(pok, pok+stanje, [datum](Prodaja *p){
        if(IstiDatumi(p->DajDatumProdaje(), datum)) return true;
        return false;
    });
    return a;
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    int br=0;
    for(int i=0; i<stanje; i++){
        if(pok[i]->DajImeAgenta()==ime_agenta) br++;
    }
    return br;
}
Prodaja& Prodaje::DajNajranijuProdaju(){
    if(stanje==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::min_element(pok, pok+stanje, [](Prodaja *p1, Prodaja *p2){
        if(DatumPP(p1->DajDatumProdaje(),p2->DajDatumProdaje())==-1) return true;
        return false;
    });
    return **it;
}
Prodaja Prodaje::DajNajranijuProdaju() const{
    if(stanje==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::min_element(pok, pok+stanje, [](Prodaja *p1, Prodaja *p2){
        if(DatumPP(p1->DajDatumProdaje(),p2->DajDatumProdaje())==-1) return true;
        return false;
    });
    return **it;
}
Prodaja& Prodaje::DajNajskupljuProdaju(){
    if(stanje==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::max_element(pok, pok+stanje, [](Prodaja *p1, Prodaja *p2){
        return p1->DajCijenuStana()<p2->DajCijenuStana();
    });
    return **it;
    /*int maxi=0;
    for(int i=0; i<stanje; i++){
        if(pok[maxi]->DajCijenuStana()<pok[i]->DajCijenuStana()) maxi=i;
    }
    return *pok[maxi];*/
}
Prodaja Prodaje::DajNajskupljuProdaju() const{
    if(stanje==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::max_element(pok, pok+stanje, [](Prodaja *p1, Prodaja *p2){
        return p1->DajCijenuStana()<p2->DajCijenuStana();
    });
    return **it;
}
void Prodaje::IsprazniKolekciju(){
    for(int i=0; i<stanje; i++) delete pok[i];
    delete [] pok;
    }
void Prodaje::ObrisiNajranijuProdaju(){
    if(stanje==0) throw std::range_error("Prazna kolekcija");
    Datum dat(1,1,1);
    int mini=0;
    if(stanje==0) throw std::range_error("Prazna kolekcija");
    for(int i=0; i<stanje; i++){
        if(DatumPP(pok[i]->DajDatumProdaje(), dat)==-1){
            dat=pok[i]->DajDatumProdaje();
            mini=i;
        }
    }
    delete pok[mini];
    for(int i=mini; i<stanje-1; i++){
        pok[i]=pok[i+1];
    }
    stanje--;
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    for(int i=0; i<stanje; i++){
        if(pok[i]->DajImeAgenta()==ime_agenta){
            delete pok[i];
            for(int j=i; j<stanje-1; j++) pok[j]=pok[j+1];
            stanje--;
            i--;
        }
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    for(int i=0; i<stanje; i++){
        if(IstiDatumi(pok[i]->DajDatumProdaje(), datum)){
            delete pok[i];
            for(int j=i; j<stanje-1; j++) pok[j]=pok[j+1];
            stanje--;
            i--;
        }
    }
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    std::vector<Prodaja> v;
    for(int i=0; i<stanje; i++){
        if(IstiDatumi(pok[i]->DajDatumProdaje(), datum)){
            v.push_back(*pok[i]);
        }
    }
    for(int i=0; i<v.size(); i++){
       v[i].Ispisi();
    }
}
void Prodaje::IspisiSveProdaje() const{
    std::sort(pok, pok+stanje, [](Prodaja *p1, Prodaja *p2){
        if(DatumPP(p1->DajDatumProdaje(), p2->DajDatumProdaje())==-1) return true;
        return false;
    });
    for(int i=0; i<stanje; i++)
        pok[i]->Ispisi();
}
int main ()
{
	return 0;
}