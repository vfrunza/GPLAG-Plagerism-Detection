/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <memory>
#include <memory>
#include <initializer_list>
#include <algorithm>

class Datum{
    int dan, mjesec,godina;
    public:
    
    Datum(int dan, int mjesec, int godina){Postavi(dan,mjesec,godina);}

    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const{return dan;}
    int DajMjesec() const{return mjesec;}
    int DajGodinu() const{return godina;}
    void Ispisi()const{std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
    
};

void Datum::Postavi(int dan,int mjesec, int godina){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}



class Kupac{
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):datum_rodjenja(datum_rodjenja) {Postavi(ime_i_prezime,datum_rodjenja);}
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const {return ime_i_prezime;}
    Datum DajDatumRodjenja() const {return datum_rodjenja;}
    void Ispisi() const { std::cout<<ime_i_prezime<<" ("; datum_rodjenja.Ispisi(); std::cout<<")";}
};

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    for(int i(0); i<int(ime_i_prezime.size()); i++){
        if( ( (ime_i_prezime.at(i)>='a' && ime_i_prezime.at(i)<='z') || (ime_i_prezime.at(i)>='A' && ime_i_prezime.at(i)<='Z') || (ime_i_prezime.at(i)>='0' && ime_i_prezime.at(i)<='9') )==false 
        && ime_i_prezime.at(i)!=' ' && ime_i_prezime.at(i)!='-' && ime_i_prezime.at(i)!='\'' ) throw std::domain_error ("Neispravno ime i prezime");
    }
    Kupac::ime_i_prezime=ime_i_prezime; Kupac::datum_rodjenja=datum_rodjenja;
}



class Stan{
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
    
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);}
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const {return adresa;}
    int DajSprat() const {return sprat;}
    int DajBrojSoba () const {return broj_soba;}
    bool DajNamjesten() const {return namjesten;}
    double DajKvadraturu() const {return kvadratura;}
    void Ispisi() const;
};

void Stan::Postavi(const std::string &afresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
}

void Stan::Ispisi() const {
    std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba;
    int p(broj_soba%100); if(p<0) p*=(-1);
    if((p<10 ||  p>20) && (p%10==2 || p%10 || p%10==4)) std::cout<<" sobe.";
    else if((p<10 || p>20) && p%10==1) std::cout<<" sobu.";
    else std::cout<<" soba.";
    
    std::cout<<std::endl<<"Kvadratura stana je "<<kvadratura<<" (m^2) i stan ";
    if(namjesten) std::cout<<"je namjesten.";
    else std::cout<<"nije namjesten.";
}



class Prodaja{
    std::string ime_agenta;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
            std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana,
            int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac) {kupac_stana=novi_kupac;}
    void PromijeniStan(const Stan &novi_stan){kupljeni_stan=novi_stan;}
    void PromijeniDatumKupovine(const Datum &novi_datum) {datum_prodaje=novi_datum;}
    void PromijeCijenuProdaje(const double &nova_cijena){cijena_stana=nova_cijena;}
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const {return ime_agenta;}
    std::string DajImeKupca() const {return kupac_stana.DajImePrezime();}
    Datum DajDatumProdaje() const {return datum_prodaje;}
    double DajCijenuStana () const{ return cijena_stana;}
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):
                ime_agenta(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
                std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
                int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):
                ime_agenta(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje),
                kupac_stana(ime_kupca,datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {}

void Prodaja::PomjeriDanUnaprijed(){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((datum_prodaje.DajGodinu()%4==0 && datum_prodaje.DajGodinu()%100!=0) || datum_prodaje.DajGodinu()%400==0) broj_dana[1]++;
    int dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec()), godina(datum_prodaje.DajGodinu());
    dan++;
    if(dan>broj_dana[mjesec-1]) dan=1, mjesec++;
    if(mjesec>12) mjesec=1, godina++;
    datum_prodaje.Postavi(dan,mjesec,godina);
}

void Prodaja::PomjeriDanUnazad(){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    int dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec()), godina(datum_prodaje.DajGodinu());
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    dan--;
    if(dan==0){
        mjesec--;
        if(mjesec==0){mjesec=12; godina--;}
        dan=broj_dana[mjesec-1];
    }
    datum_prodaje.Postavi(dan,mjesec,godina);
}         

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if(p1.datum_prodaje.DajGodinu()<p2.datum_prodaje.DajGodinu()) return true;
    if(p1.datum_prodaje.DajGodinu()==p2.datum_prodaje.DajGodinu()){
        if(p1.datum_prodaje.DajMjesec()<p2.datum_prodaje.DajMjesec()) return true;
        if(p1.datum_prodaje.DajMjesec()==p2.datum_prodaje.DajMjesec()){
            if(p1.datum_prodaje.DajDan()<p2.datum_prodaje.DajDan()) return true;
        }
    }
    return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    return p1.cijena_stana>p2.cijena_stana;
}

void Prodaja::Ispisi()const{
    std::cout<<std::setw(30)<<"Ime agenta:"<<ime_agenta
             <<std::setw(30)<<"Ime kupca:"; kupac_stana.Ispisi();
    std::cout<<std::setw(30)<<"Zakazani datum prodaje:"; datum_prodaje.Ispisi();
    std::cout<<std::setw(30)<<"Cijena stana:"<<cijena_stana
             <<std::setw(30)<<"Informacije o stanu:"<<std::endl; kupljeni_stan.Ispisi();
}



class Prodaje{
    
    std::vector<std::shared_ptr<Prodaja>> kolekcija;
    
    static bool ProvjeraDatuma( Datum d1, Datum d2){
        if(d1.DajGodinu()==d2.DajGodinu()){
            if(d1.DajMjesec()==d2.DajMjesec()){
                if(d1.DajDan()==d2.DajDan()) return true;
            }
        }
        return false;
    }
    
    
    
    public:
    explicit Prodaje(){}
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje)=default;
    Prodaje &operator=(const Prodaje &prodaje);
    Prodaje &operator=(Prodaje &&prodaje)=default;
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
                            std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana,
                            int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(std::shared_ptr<Prodaja> prodaja);
    int DajBrojProdaja() const {return int(kolekcija.size());}
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajProdaju(int redni_broj);
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju()const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju()const;
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja){
    auto it(spisak_prodaja.begin());
    while(spisak_prodaja.begin()!=spisak_prodaja.end()){
        kolekcija.push_back(std::make_shared<Prodaja>(*it));
        it++;
    }
}

Prodaje::Prodaje(const Prodaje &prodaje){
    kolekcija.resize(0);
    for(int i(0); i<int(prodaje.kolekcija.size()); i++){
        kolekcija.push_back(std::make_shared<Prodaja>(*prodaje.kolekcija.at(i)));
    }
}

Prodaje &Prodaje::operator=(const Prodaje &prodaje) {
    kolekcija.resize(0);
    for(int i(0); i<int(prodaje.kolekcija.size()); i++){
        kolekcija.push_back(std::make_shared<Prodaja>(*prodaje.kolekcija.at(i)));
    }
    return *this;
}


void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
    kolekcija.push_back(std::make_shared<Prodaja>(Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje, kupac_stana,kupljeni_stan)));
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
                                std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
                                int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
    kolekcija.push_back(std::make_shared<Prodaja>(Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca,
                        adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata  )));                                    
}

void Prodaje::RegistrirajProdaju(std::shared_ptr<Prodaja> prodaja) {
    kolekcija.push_back(prodaja);
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    
    int brojac(0);
    for(int i(0); i<int(kolekcija.size()); i++){
        if( ProvjeraDatuma( kolekcija.at(i)->DajDatumProdaje(), datum ) ) brojac++;
    }
    return brojac;
    
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    int brojac(0);
    for(int i(0); i<int(kolekcija.size()); i++){
        if(kolekcija.at(i)->DajImeAgenta()==ime_agenta) brojac++;
    }
    return brojac;
}

Prodaja &Prodaje::DajProdaju(int redni_broj){
    if(redni_broj<1 || redni_broj>int(kolekcija.size()) ) throw;
    return *(kolekcija.at(redni_broj-1));
}

Prodaja &Prodaje::DajNajranijuProdaju(){
    if(int(kolekcija.size())==0) throw std::domain_error ("Nema registriranih prodaja");
    auto it=std::min_element(kolekcija.begin(), kolekcija.end(), [](std::shared_ptr<Prodaja> t1, std::shared_ptr<Prodaja> t2){ return ProdatPrije(*t1, *t2); });
    return *(*it);
    
}

Prodaja Prodaje::DajNajranijuProdaju()const {
    if(int(kolekcija.size())==0) throw std::domain_error ("Nema registriranih prodaja");
    auto it=std::min_element(kolekcija.begin(), kolekcija.end(), [](std::shared_ptr<Prodaja> t1, std::shared_ptr<Prodaja> t2) {return ProdatPrije(*t1,*t2); });
    return *(*it);
}

Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(int(kolekcija.size())==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::max_element(kolekcija.begin(), kolekcija.end(), [](std::shared_ptr<Prodaja> t1, std::shared_ptr<Prodaja> t2) {return SkupljiStan(*t1, *t2);});
    return *(*it);
}

Prodaja Prodaje::DajNajskupljuProdaju()const{
    if(int(kolekcija.size())==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::max_element(kolekcija.begin(), kolekcija.end(), [](std::shared_ptr<Prodaja> t1, std::shared_ptr<Prodaja> t2) {return SkupljiStan(*t1,*t2);} );
    return *(*it);
}

void Prodaje::IsprazniKolekciju(){
    kolekcija.resize(0);
}

void Prodaje::ObrisiNajranijuProdaju(){
    if(int(kolekcija.size())==0) throw std::range_error ("Prazna kolekcija");
    auto it=std::min_element(kolekcija.begin(), kolekcija.end(), [](std::shared_ptr<Prodaja> t1, std::shared_ptr<Prodaja> t2) {return ProdatPrije(*t1, *t2);} );
    (*it)=nullptr;
    for(int i(0); i<int(kolekcija.size()); i++){
        if(kolekcija.at(i)==nullptr) {kolekcija.erase(kolekcija.begin()+i); i--;}
    }
    
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    for(int i(0); i<int(kolekcija.size()); i++){
        if(kolekcija.at(i)->DajImeAgenta()==ime_agenta) {kolekcija.erase(kolekcija.begin()+i); i--;}
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    for(int i(0); i<int(kolekcija.size()); i++){
        if(ProvjeraDatuma(datum,kolekcija.at(i)->DajDatumProdaje())) kolekcija.erase(kolekcija.begin()+i); i--;
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    std::vector<std::shared_ptr<Prodaja>> temp;
    for(int i(0); i<int(kolekcija.size()); i++){
        if(ProvjeraDatuma(datum, kolekcija.at(i)->DajDatumProdaje())) temp.push_back(kolekcija.at(i));
    }
    std::sort(temp.begin(), temp.end(), [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2 ) { return p1->DajImeAgenta()<p2->DajImeAgenta(); } );
    
    for(int i(0); i<int(temp.size()); i++){
        temp.at(i)->Ispisi();
        std::cout<<std::endl;
    }
}

void Prodaje::IspisiSveProdaje() const{
    std::vector<std::shared_ptr<Prodaja>> temp;
    for(int i(0); i<int(kolekcija.size()); i++){
        temp.push_back(kolekcija.at(i));
    }
    
    std::sort(temp.begin(), temp.end(), [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2)
                                            { if(ProdatPrije(*p1,*p2)==ProdatPrije(*p2, *p1)) return p1->DajImeKupca()<p2->DajImeKupca();
                                                return ProdatPrije(*p1,*p2);
                                            });
    for(int i(0); i<int(kolekcija.size()); i++){
        kolekcija.at(i)->Ispisi();
        std::cout<<std::endl;
    }
}


         
            
int main(){
    
   std::cout<<".";
    
}