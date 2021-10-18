/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>
#include <utility>
#include <vector> 
#include <cstdio>

bool testdatuma(int dan, int mjesec, int godina){
    int dani[]{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4!=0 || godina%400==0)dani[1]--;
    return !(dan<1 || mjesec<1 || godina<1 || dan>dani[mjesec-1] || mjesec>12);
}
bool testimena(const std::string &a){
    for(auto i:a)if(i!='\'' && i!=' ' && i!='-' && !(i>='0' && i<='9') && !((i>='a' && i<='z') || (i>='A' && i<='Z')))return false;
    return true;
}

class Datum{
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina){Postavi(dan, mjesec, godina);}
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const{return dan;}
    int DajMjesec() const{return mjesec;}
    int DajGodinu() const{return godina;}
    void Ispisi() const{std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};
void Datum::Postavi(int dan, int mjesec, int godina){
    if(!testdatuma(dan, mjesec, godina))throw std::domain_error("Neispravan datum");
    this->dan=dan;
    this->mjesec=mjesec;
    this->godina=godina;
}

Datum mjenjajdatum(int dan, int mjesec, int godina, int a){
    dan+=a;
    int dani[]{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4!=0 || godina%400==0)dani[1]=28;
    if(dan==0){
        mjesec--;
        if(mjesec==0){
            mjesec=12;
            godina--;
        }
        if(godina%4!=0 || godina%400==0)dani[1]=28;
        dan=dani[mjesec-1];
    } else if(dan>dani[mjesec-1]){
        dan=1;
        mjesec++;
        if(mjesec==13){
            mjesec=1;
            godina++;
        }
    }
    return {dan, mjesec, godina};
}
bool provjeridatume(const Datum &d1, const Datum &d2){
    if(d1.DajDan()!=d2.DajDan())return false;
    if(d1.DajMjesec()!=d2.DajMjesec())return false;
    if(d1.DajGodinu()!=d2.DajGodinu())return false;
    return true;
}

class Kupac{
    std::string ime_i_prezime;
    Datum datum_rodjenja;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): datum_rodjenja(datum_rodjenja){
        Postavi(ime_i_prezime, datum_rodjenja);
    } 
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const{return ime_i_prezime;}
    Datum DajDatumRodjenja() const{return datum_rodjenja;}
    void Ispisi() const{std::cout<<ime_i_prezime<<" (";datum_rodjenja.Ispisi();std::cout<<")";}
};
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    if(!testimena(ime_i_prezime))throw std::domain_error("Neispravno ime i prezime");
    this->datum_rodjenja=datum_rodjenja;
    this->ime_i_prezime=ime_i_prezime;
}

class Stan{
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    int DajSprat() const{return sprat;}
    int DajBrojSoba() const{return broj_soba;}
    bool DajNamjesten() const{return namjesten;}
    double DajKvadraturu() const{return kvadratura;}
    std::string DajAdresu() const{return adresa;}
    void Ispisi() const;
};
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if(sprat<0 || broj_soba<0 || kvadratura<0)throw std::domain_error("Neispravan unos podataka");
    this->adresa=adresa;
    this->sprat=sprat;
    this->broj_soba=broj_soba;
    this->namjesten=namjesten;
    this->kvadratura=kvadratura;
}
void Stan::Ispisi() const{
    std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" ";
    if((broj_soba>9 && broj_soba<15) || broj_soba%10>4 || broj_soba%10==0)std::cout<<"soba"; else {
        if(broj_soba%10==1)std::cout<<"sobu";
        if(broj_soba%10>1 && broj_soba%10<5)std::cout<<"sobe";
    }
    std::cout<<". ";
    std::cout<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan ";
    if(!namjesten)std::cout<<"ni";
    std::cout<<"je namjesten.";
}

class Prodaja{
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    friend void PromijeniAgenta(std::string s, Prodaja &p){
        p.ime_agenta_prodaje=s;
    }
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, 
    const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, 
    const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac){kupac_stana=novi_kupac;}
    void PromijeniStan(const Stan &novi_stan){kupljeni_stan=novi_stan;}
    void PromijeniDatumKupovine(const Datum &datum){datum_prodaje=datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena){cijena_stana=nova_cijena;}
    void PomjeriDanUnaprijed(){datum_prodaje=mjenjajdatum(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu(), 1);}
    void PomjeriDanUnazad(){datum_prodaje=mjenjajdatum(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu(), -1);}
    std::string DajImeAgenta() const{return ime_agenta_prodaje;}
    std::string DajImeKupca() const{return kupac_stana.DajImePrezime();}
    Datum DajDatumProdaje() const{return datum_prodaje;}
    double DajCijenuStana() const{return cijena_stana;}
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){return p1.DajCijenuStana()<p2.DajCijenuStana();}
    void Ispisi() const;
};
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if(p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu())return true;
    if(p1.DajDatumProdaje().DajGodinu()>p2.DajDatumProdaje().DajGodinu())return false;
    if(p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec())return true;
    if(p1.DajDatumProdaje().DajMjesec()>p2.DajDatumProdaje().DajMjesec())return false;
    return p1.DajDatumProdaje().DajDan()>p2.DajDatumProdaje().DajDan();
}
void Prodaja::Ispisi() const{
    std::cout<<"Ime agenta:                     "<<DajImeAgenta()<<'\n';
    std::cout<<"Ime kupca:                      "<<DajImeKupca()<<" (";kupac_stana.DajDatumRodjenja().Ispisi();std::cout<<")\n";
    std::cout<<"Zakazani datum prodaje:         ";DajDatumProdaje().Ispisi();std::cout<<"\n";
    std::cout<<"Cijena stana:                   "<<DajCijenuStana()<<'\n';
    std::cout<<"Informacije o stanu:            \n";
    kupljeni_stan.Ispisi();
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, 
const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):
    ime_agenta_prodaje(ime_agenta_prodaje),
    cijena_stana(cijena_stana),
    datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), 
    kupac_stana(ime_kupca, datum_rodjenja_kupca),
    kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata){}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, 
const Stan &kupljeni_stan): datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan){
    this->ime_agenta_prodaje=ime_agenta_prodaje;
    this->cijena_stana=cijena_stana;
}

class Prodaje{
    Prodaja **niz_prodaja;
    int max_broj_prodaja;
    int trenutni_broj_prodaja;
    void sortirajpodatumu();
    void sortirajpoimenukupca();
public:
    explicit Prodaje(int max_broj_prodaja){
        niz_prodaja=new Prodaja*[max_broj_prodaja];
        for(int i=0;i<max_broj_prodaja;i++){
            niz_prodaja[i]=nullptr;
        }
        this->max_broj_prodaja=max_broj_prodaja;
        this->trenutni_broj_prodaja=0;
    }
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
    const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,
    int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const{return trenutni_broj_prodaja;}
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    Prodaja &DajProdaju(int indeks);
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};
void Prodaje::sortirajpodatumu(){
    std::sort(niz_prodaja, niz_prodaja+trenutni_broj_prodaja, [](const Prodaja *p1, const Prodaja *p2){
         if(ProdatPrije(*p1, *p2))return false;
         if(ProdatPrije(*p2, *p1))return true;
         return p1->DajImeKupca()<p2->DajImeKupca();
    });
}
void Prodaje::sortirajpoimenukupca(){
    std::sort(niz_prodaja, niz_prodaja+trenutni_broj_prodaja, [](const Prodaja *p1, const Prodaja *p2){
         return p1->DajImeKupca()<p2->DajImeKupca();
    });
}
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja){
    niz_prodaja=new Prodaja*[spisak_prodaja.size()];
    for(int i=0;i<spisak_prodaja.size();i++){
        niz_prodaja[i]=nullptr;
    }
    try{
        int i=0;
        for(auto p=spisak_prodaja.begin();p!=spisak_prodaja.end();p++){
            niz_prodaja[i]=new Prodaja(*p);
            i++;
        }
        max_broj_prodaja=spisak_prodaja.size();
        trenutni_broj_prodaja=spisak_prodaja.size();
    }
    catch(...){
        for(int i=0;i<spisak_prodaja.size();i++){
            delete niz_prodaja[i];
        }
        delete[] niz_prodaja;
        throw;
    }
}
Prodaje::~Prodaje(){
    for(int i=0;i<trenutni_broj_prodaja;i++){
        delete niz_prodaja[i];
    }
    delete[] niz_prodaja;
}
Prodaje::Prodaje(const Prodaje &prodaje){
    niz_prodaja=new Prodaja*[prodaje.max_broj_prodaja];
    for(int i=0;i<prodaje.max_broj_prodaja;i++){
        niz_prodaja[i]=nullptr;
    }
    try{
        for(int i=0;i<prodaje.trenutni_broj_prodaja;i++){
            niz_prodaja[i]=new Prodaja(*prodaje.niz_prodaja[i]);
        }
        max_broj_prodaja=prodaje.max_broj_prodaja;
        trenutni_broj_prodaja=prodaje.trenutni_broj_prodaja;
    }
    catch(...){
        for(int i=0;i<prodaje.max_broj_prodaja;i++){
            delete niz_prodaja[i];
        }
        delete[] niz_prodaja;
        throw;
    }
}
Prodaje::Prodaje(Prodaje &&prodaje){
    niz_prodaja=prodaje.niz_prodaja;
    prodaje.niz_prodaja=nullptr;
    max_broj_prodaja=prodaje.max_broj_prodaja;
    trenutni_broj_prodaja=prodaje.trenutni_broj_prodaja;
    prodaje.max_broj_prodaja=0;
    prodaje.trenutni_broj_prodaja=0;
}
Prodaje &Prodaje::operator =(const Prodaje &prodaje){
    Prodaja **temp=new Prodaja*[prodaje.max_broj_prodaja];
    for(int i=0;i<prodaje.max_broj_prodaja;i++){
        temp[i]=nullptr;
    }
    try{
        for(int i=0;i<prodaje.trenutni_broj_prodaja;i++){
            temp[i]=new Prodaja(*prodaje.niz_prodaja[i]);
        }
        for(int i=0;i<trenutni_broj_prodaja;i++){
            delete niz_prodaja[i];
        }
        delete niz_prodaja;
        niz_prodaja=temp;
        max_broj_prodaja=prodaje.max_broj_prodaja;
        trenutni_broj_prodaja=prodaje.trenutni_broj_prodaja;
        return *this;
    }
    catch(...){
        for(int i=0;i<prodaje.max_broj_prodaja;i++){
            delete temp[i];
        }
        delete[] temp;
        throw;
    }
}
Prodaje &Prodaje::operator =(Prodaje &&prodaje){
    for(int i=0;i<trenutni_broj_prodaja;i++){
        delete niz_prodaja[i];
    }
    delete[] niz_prodaja;
    niz_prodaja=prodaje.niz_prodaja;
    prodaje.niz_prodaja=nullptr;
    max_broj_prodaja=prodaje.max_broj_prodaja;
    trenutni_broj_prodaja=prodaje.trenutni_broj_prodaja;
    prodaje.max_broj_prodaja=0;
    prodaje.trenutni_broj_prodaja=0;
    return *this;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
    const Kupac &kupac_stana, const Stan &kupljeni_stan){
        if(trenutni_broj_prodaja==max_broj_prodaja)throw std::range_error("Dostignut maksimalni broj prodaja");
        niz_prodaja[trenutni_broj_prodaja]=new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
        trenutni_broj_prodaja++;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,
    int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
        if(trenutni_broj_prodaja==max_broj_prodaja)throw std::range_error("Dostignut maksimalni broj prodaja");
        niz_prodaja[trenutni_broj_prodaja]=new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje,
        godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
        trenutni_broj_prodaja++;
}
void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(trenutni_broj_prodaja==max_broj_prodaja)throw std::range_error("Dostignut maksimalni broj prodaja");
    niz_prodaja[trenutni_broj_prodaja]=prodaja;
    trenutni_broj_prodaja++;
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    int k=std::count_if(niz_prodaja, (niz_prodaja+trenutni_broj_prodaja), [datum](const Prodaja *pro){
        return provjeridatume(pro->DajDatumProdaje(), datum);
    });
    return k;
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    int k=std::count_if(niz_prodaja, (niz_prodaja+trenutni_broj_prodaja), [ime_agenta](const Prodaja *pro){
        return ime_agenta==pro->DajImeAgenta();
    });
    return k;
}
Prodaja &Prodaje::DajNajranijuProdaju(){
    if(trenutni_broj_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(niz_prodaja, niz_prodaja+trenutni_broj_prodaja, [](const Prodaja *pro, const Prodaja *pro1){
          return !ProdatPrije(*pro, *pro1);
    });  
}
Prodaja Prodaje::DajNajranijuProdaju() const{
    if(trenutni_broj_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(niz_prodaja, niz_prodaja+trenutni_broj_prodaja, [](const Prodaja *pro, const Prodaja *pro1){
          return !ProdatPrije(*pro, *pro1);
    }); 
}
Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(trenutni_broj_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(niz_prodaja, niz_prodaja+trenutni_broj_prodaja, [](const Prodaja *pro, const Prodaja *pro1){
          return SkupljiStan(*pro, *pro1);
    }); 
}
Prodaja Prodaje::DajNajskupljuProdaju() const{
    if(trenutni_broj_prodaja==0)throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(niz_prodaja, niz_prodaja+trenutni_broj_prodaja, [](const Prodaja *pro, const Prodaja *pro1){
          return SkupljiStan(*pro, *pro1);
    }); 
}
Prodaja &Prodaje::DajProdaju(int indeks){
    if(indeks<1 || indeks>trenutni_broj_prodaja)throw std::range_error("indeks ne valja");
    return *niz_prodaja[indeks-1];
}
void Prodaje::IsprazniKolekciju(){
    for(int i=0;i<trenutni_broj_prodaja;i++){
        delete niz_prodaja[i];
        niz_prodaja[i]=nullptr;
    }
    trenutni_broj_prodaja=0;
}
void Prodaje::ObrisiNajranijuProdaju(){
    if(trenutni_broj_prodaja==0)throw std::range_error("Prazna kolekcija");
    auto p=*std::min_element(niz_prodaja, niz_prodaja+trenutni_broj_prodaja, [](const Prodaja *pro, const Prodaja *pro1){
          return !ProdatPrije(*pro, *pro1);
    });
    for(int i=0;i<trenutni_broj_prodaja;i++){
        if(p==niz_prodaja[i]){
            delete niz_prodaja[i];
            for(int j=i;j<trenutni_broj_prodaja-1;j++){
                niz_prodaja[j]=niz_prodaja[j+1];
            }
            niz_prodaja[trenutni_broj_prodaja-1]=nullptr;
            trenutni_broj_prodaja--;
            break;
        }
    }
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    for(int i=0;i<trenutni_broj_prodaja;i++){
        if(ime_agenta==niz_prodaja[i]->DajImeAgenta()){
            delete niz_prodaja[i];
            for(int j=i;j<trenutni_broj_prodaja-1;j++){
                niz_prodaja[j]=niz_prodaja[j+1];
            }
            niz_prodaja[trenutni_broj_prodaja-1]=nullptr;
            trenutni_broj_prodaja--;
            i--;
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    for(int i=0;i<trenutni_broj_prodaja;i++){
        if(provjeridatume(datum, niz_prodaja[i]->DajDatumProdaje())){
            delete niz_prodaja[i];
            for(int j=i;j<trenutni_broj_prodaja-1;j++){
                niz_prodaja[j]=niz_prodaja[j+1];
            }
            niz_prodaja[trenutni_broj_prodaja-1]=nullptr;
            trenutni_broj_prodaja--;
            i--;
        }
    }
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    Prodaje p=*this;
    p.sortirajpoimenukupca();
    for(int i=0;i<trenutni_broj_prodaja;i++){
        if(provjeridatume(datum, p.niz_prodaja[i]->DajDatumProdaje())){
            p.niz_prodaja[i]->Ispisi();
            std::cout<<"\n";
        }
    }
}
void Prodaje::IspisiSveProdaje() const{
    Prodaje p=*this;
    p.sortirajpodatumu();
    for(int i=0;i<trenutni_broj_prodaja;i++){
        p.niz_prodaja[i]->Ispisi();
        std::cout<<"\n";
        if(i!=trenutni_broj_prodaja-1)std::cout<<"\n";
    }
}

std::vector<Stan> stanovi;
std::vector<Kupac> kupci;
Prodaje prodaje=Prodaje(20);

void meni1();
Stan dodavanjestana();
void ispissvihstanova(std::string c, std::string a);
void uredjivanjestanova1();
void uredjivanjestanova2();
void uredjivanjestanova3(int indeks);
void uredjivanjekupaca();
void uredjivanjekupaca1();
void uredjivanjeprodaja();
Kupac dodavanjekupca(std::string ss);
void ispissvihkupaca(int t=0);
void uredjivanjekupaca2(int indeks);
void dodavanjeprodaje();
void uredjivanjeprodaje();
void uredjivanjeprodaje1(int indeks);
void ispisprodaja();
void brisanjeprodaja();
void dodavanjepotpunonoveprodaje();
void dodavanjenoveprodajenaosnovuarhive();
void ispissvihprodaja();
void ispisprodajanadatum();
void ispisnajranijeprodaje();
void ispisnajskupljeprodaje();
void ispisbrojaprodaja();
void ispisbrojaprodajapodatumu();
void ispisbrojaprodajapoagentu();
void brisanjenajranijeprodaje();
void brisanjeprodajaagenta();
void brisanjeprodajapodatumu();
void brisanjesvihprodaja();
void meni1(){
    std::cout<<"\n";
    do{
        std::cout<<"Izaberite opciju:\n";
        std::cout<<" 0 - kraj\n";
        std::cout<<" 1 - uredjivanje stanova\n";
        std::cout<<" 2 - uredjivanje kupaca\n";
        std::cout<<" 3 - uredjivanje prodaja\n";
        int n;
        std::cin>>n;
        if(n==0)throw std::invalid_argument("kraj");
        if(n==1)uredjivanjestanova1();
        if(n==2)uredjivanjekupaca();
        if(n==3)uredjivanjeprodaja();
    }while(true);
}
void uredjivanjestanova1(){
    do{
        std::cout<<"Izaberite opciju:\n";
        std::cout<<" 0 - nazad\n";
        std::cout<<" 1 - dodavanje stana\n";
        std::cout<<" 2 - uredjivanje stanova\n";
        std::cout<<" 3 - ispis svih stanova\n";
        std::cout<<" 4 - kraj\n";
        int n;
        std::cin>>n;
        if(n==0)return;
        if(n==1){
            stanovi.push_back(dodavanjestana());
            std::cout<<"Stan je uspjesno dodan!\n\n";
        }
        if(n==2)uredjivanjestanova2();
        if(n==3)ispissvihstanova("", ". ");
        if(n==4)throw std::invalid_argument("kraj");
    }while(true);
}
Stan dodavanjestana(){
    do{
        try{
            std::cout<<"Unesite adresu: ";
            std::string s;
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, s, '\n');
            std::cout<<"Unesite sprat: ";
            int sprat, soba, n;
            bool namjesten=true;
            double kvadratura;
            std::cin>>sprat;
            std::cout<<"Unesite broj soba: ";
            std::cin>>soba;
            std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
            std::cin>>n;
            if(n==0)namjesten=false;
            std::cout<<"Unesite kvadraturu: ";
            std::cin>>kvadratura;
            if(n!=0 && n!=1)throw std::domain_error("Neispravan unos podataka");
            return Stan(s, sprat, soba, namjesten, kvadratura);
        }
        catch(std::domain_error gg){
            std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
        }
    }while(true);
}
void ispissvihstanova(std::string c, std::string a){
    for(int i=0;i<stanovi.size();i++){
        std::cout<<c<<i+1<<a;
        stanovi[i].Ispisi();
        std::cout<<"\n";
    }
}
void uredjivanjestanova2(){
    std::cout<<"Odaberite stan. Dostupni stanovi su:\n";
    ispissvihstanova(" ", " - ");
    int n;
    std::cin>>n;
    if(n<1 || n>stanovi.size())throw std::domain_error("index ne valja");
    uredjivanjestanova3(n-1);
}
void uredjivanjestanova3(int indeks){
    std::cout<<"Odaberite polje koje zelite urediti:\n";
    std::cout<<" 0 - nazad\n";
    std::cout<<" 1 - adresa\n";
    std::cout<<" 2 - sprat\n";
    std::cout<<" 3 - broj soba\n";
    std::cout<<" 4 - da li je stan namjesten\n";
    std::cout<<" 5 - kvadratura\n";
    std::cout<<" 6 - sve\n";
    int n;
    std::cin>>n;
    if(n==0)return;
    if(n==1){
        do{
            try{
                std::cout<<"Unesite adresu: ";
                std::string s;
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, s, '\n');
                stanovi[indeks]=Stan(s, stanovi[indeks].DajSprat(), stanovi[indeks].DajBrojSoba(), stanovi[indeks].DajNamjesten(), stanovi[indeks].DajKvadraturu());
                std::cout<<"Stan je uspjesno izmijenjen!\n\n";
                return;
            }
            catch(std::domain_error gg){
                std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
            }
        }while(true);
    }
    if(n==2){
        do{
            try{
                std::cout<<"Unesite sprat: ";
                int sprat;
                std::cin>>sprat;
                stanovi[indeks]=Stan(stanovi[indeks].DajAdresu(), sprat, stanovi[indeks].DajBrojSoba(), stanovi[indeks].DajNamjesten(), stanovi[indeks].DajKvadraturu());
                std::cout<<"Stan je uspjesno izmijenjen!\n\n";
                return;
            }
            catch(std::domain_error gg){
                std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
            }
        }while(true);
    }
    if(n==3){
        do{
            try{
                std::cout<<"Unesite broj soba: ";
                int sobe;;
                std::cin>>sobe;
                stanovi[indeks]=Stan(stanovi[indeks].DajAdresu(), stanovi[indeks].DajSprat(), sobe, stanovi[indeks].DajNamjesten(), stanovi[indeks].DajKvadraturu());
                std::cout<<"Stan je uspjesno izmijenjen!\n\n";
                return;
            }
            catch(std::domain_error gg){
                std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
            }
        }while(true);
    }
    if(n==4){
        do{
            try{
                std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                int nam;
                bool namjesten=true;
                std::cin>>nam;
                if(nam==0)namjesten=false;
                if(nam!=0 && nam!=1)throw std::domain_error("Neispravan unos podataka");
                stanovi[indeks]=Stan(stanovi[indeks].DajAdresu(), stanovi[indeks].DajSprat(), stanovi[indeks].DajBrojSoba(), namjesten, stanovi[indeks].DajKvadraturu());
                std::cout<<"Stan je uspjesno izmijenjen!\n\n";
                return;
            }
            catch(std::domain_error gg){
                std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
            }
        }while(true);
    }
    if(n==5){
        do{
            try{
                std::cout<<"Unesite kvadraturu: ";
                double kvadratura;
                std::cin>>kvadratura;
                stanovi[indeks]=Stan(stanovi[indeks].DajAdresu(), stanovi[indeks].DajSprat(), stanovi[indeks].DajBrojSoba(), stanovi[indeks].DajNamjesten(), kvadratura);
                std::cout<<"Stan je uspjesno izmijenjen!\n\n";
                return;
            }
            catch(std::domain_error gg){
                std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
            }
        }while(true);
    }
    if(n==6){
        stanovi[indeks]=dodavanjestana();
        std::cout<<"Stan je uspjesno izmijenjen!\n\n";
    }
}
void uredjivanjekupaca(){
    do{
        std::cout<<"Izaberite opciju:\n";
        std::cout<<" 0 - nazad\n";
        std::cout<<" 1 - dodavanje kupca\n";
        std::cout<<" 2 - uredjivanje kupaca\n";
        std::cout<<" 3 - ispis svih kupaca\n";
        std::cout<<" 4 - kraj\n";
        int n;
        std::cin>>n;
        if(n==0)return;
        if(n==1){
            kupci.push_back(dodavanjekupca(""));
            std::cout<<"Kupac je uspjesno dodan!\n\n";
        }
        if(n==2)uredjivanjekupaca1();
        if(n==3)ispissvihkupaca();
        if(n==4)throw std::invalid_argument("kraj");
    }while(true);
}
Kupac dodavanjekupca(std::string ss){
    do{
        try{
            std::cout<<"Unesite ime ";
            if(ss!=" kupca")std::cout<<"i prezime ";
            std::cout<<"kupca: ";
            std::cin.ignore(1000, '\n');
            std::string a;
            std::getline(std::cin, a, '\n');
            std::cout<<"Unesite datum rodjenja"<<ss<<" (formata d/m/g): ";
            int dan, mjesec, godina;
            std::scanf("%d/%d/%d", &dan, &mjesec, &godina);
            return Kupac(a, Datum(dan, mjesec, godina));
        }
        catch(std::domain_error gg){
            std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
        }
    }while(true);
}
void ispissvihkupaca(int t){
    for(int i=0;i<kupci.size();i++){
        if(t!=0)std::cout<<" "<<i+1<<" - ";
        kupci[i].Ispisi();
        std::cout<<'\n';
    }
    if(t==0)std::cout<<"\n";
}
void uredjivanjekupaca1(){
    std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:\n";
    ispissvihkupaca(1);
    int n;
    std::cin>>n;
    if(n<1 || n>kupci.size())throw std::domain_error("index ne valja");
    uredjivanjekupaca2(n-1);
}
void uredjivanjekupaca2(int indeks){
    kupci[indeks]=dodavanjekupca("");
    std::cout<<"Kupac je uspjesno izmijenjen!\n\n";
}
void uredjivanjeprodaja(){
    do{
        std::cout<<"Izaberite opciju:\n";
        std::cout<<" 0 - nazad\n";
        std::cout<<" 1 - dodavanje prodaje\n";
        std::cout<<" 2 - uredjivanje prodaje\n";
        std::cout<<" 3 - ispis prodaja\n";
        std::cout<<" 4 - brisanje prodaja\n";
        std::cout<<" 5 - kraj\n";
        int n;
        std::cin>>n;
        if(n==0)return;
        if(n==1)dodavanjeprodaje();
        if(n==2)uredjivanjeprodaje();
        if(n==3)ispisprodaja();
        if(n==4)brisanjeprodaja();
        if(n==5)throw std::invalid_argument("kraj");
    }while(true);
}
void dodavanjeprodaje(){
    do{
        std::cout<<"Izaberite opciju:\n";
        std::cout<<" 0 - nazad\n";
        std::cout<<" 1 - dodavanje potpuno nove prodaje\n";
        std::cout<<" 2 - dodavanje nove prodaje na osnovu arhive\n";
        std::cout<<" 3 - kraj\n";
        int n;
        std::cin>>n;
        if(n==0)return;
        if(n==1){
            dodavanjepotpunonoveprodaje();
            std::cout<<"Prodaja uspjesno dodana!\n\n";
        }
        if(n==2){
            dodavanjenoveprodajenaosnovuarhive();
            std::cout<<"Prodaja uspjesno dodana!\n\n";
        }
        if(n==3)throw std::invalid_argument("kraj");
    }while(true);
}
void dodavanjepotpunonoveprodaje(){
    do{
        try{
            std::string imeagenta;
            std::cout<<"Unesite ime i prezime agenta prodaje: ";
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, imeagenta, '\n');
            std::cout<<"Unesite datum prodaje (formata d/m/g): ";
            int dan, mjesec, godina;
            std::scanf("%d/%d/%d", &dan, &mjesec, &godina);
            std::cout<<"Unesite cijenu stana: ";
            double cijena;
            std::cin>>cijena;
            Kupac kupac=dodavanjekupca(" kupca");
            Stan stan=dodavanjestana();
            prodaje.RegistrirajProdaju(new Prodaja(imeagenta, cijena, Datum(dan, mjesec, godina), kupac, stan));
            stanovi.push_back(stan);
            kupci.push_back(kupac);
            return;
        }
        catch(std::domain_error gg){
            std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
        }
    }while(true);
}
void dodavanjenoveprodajenaosnovuarhive(){
    do{
        try{
            std::string imeagenta;
            std::cout<<"Unesite ime i prezime agenta prodaje: ";
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, imeagenta, '\n');
            std::cout<<"Unesite datum prodaje (formata d/m/g): ";
            int dan, mjesec, godina;
            std::scanf("%d/%d/%d", &dan, &mjesec, &godina);
            std::cout<<"Unesite cijenu stana: ";
            double cijena;
            std::cin>>cijena;
            std::cout<<"Odaberite kupca. Dostupni kupci su:\n";
            ispissvihkupaca(1);
            int indekskupca;
            std::cin>>indekskupca;
            if(indekskupca<1 || indekskupca>kupci.size())throw std::domain_error("index ne valja");
            std::cout<<"Odaberite stan. Dostupni stanovi su:\n";
            ispissvihstanova(" ", " - ");
            int indeksstana;
            std::cin>>indeksstana;
            if(indeksstana<1 || indeksstana>stanovi.size())throw std::domain_error("index ne valja");
            prodaje.RegistrirajProdaju(new Prodaja(imeagenta, cijena, Datum(dan, mjesec, godina), kupci[indekskupca-1], stanovi[indeksstana-1]));
            return;
        }
        catch(std::domain_error gg){
            std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
        }
    }while(true);
}
void uredjivanjeprodaje(){
    std::cout<<"Odaberite prodaju koju želite urediti. Dostupne prodaje su:\n";
    for(int i=0;i<prodaje.DajBrojProdaja();i++){
        std::cout<<i+1<<".\n";
        prodaje.DajProdaju(i+1).Ispisi();
        std::cout<<"\n";
        if(i!=prodaje.DajBrojProdaja()-1)std::cout<<"\n";
    }
    int n;
    std::cin>>n;
    if(n<1 || n-1>prodaje.DajBrojProdaja())throw std::range_error("ne valja index");
    uredjivanjeprodaje1(n-1);
}
void uredjivanjeprodaje1(int indeks){
    do{
        std::cout<<"Izaberite opciju:\n";
        std::cout<<" 0 - nazad\n";
        std::cout<<" 1 - izmjena agenta\n";
        std::cout<<" 2 - izmjena datuma prodaje\n";
        std::cout<<" 3 - izmjena kupca\n";
        std::cout<<" 4 - izmjena stana\n";
        std::cout<<" 5 - izmjena cijene stana\n";
        int n;
        std::cin>>n;
        if(n==0)return;
        if(n==1){
            std::cout<<"Unesite ime i prezime agenta prodaje: ";
            std::cin.ignore(1000, '\n');
            std::string a;
            std::getline(std::cin, a, '\n');
            PromijeniAgenta(a, prodaje.DajProdaju(indeks+1));
            std::cout<<"Prodaja je uspjesno izmijenjena!\n\n";
            return;
        }
        if(n==2){
            do{
                try{
                    std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                    int dan, mjesec, godina;
                    std::scanf("%d/%d/%d", &dan, &mjesec, &godina);
                    prodaje.DajProdaju(indeks+1).PromijeniDatumKupovine(Datum(dan, mjesec, godina));
                    std::cout<<"Prodaja je uspjesno izmijenjena!\n\n";
                    return;
                }
                catch(std::domain_error gg){
                    std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
                }
            }while(true);
        }
        if(n==3){
            std::cout<<"Izaberite opciju:\n";
            std::cout<<" 0 - nazad\n";
            std::cout<<" 1 - odabir postojeceg kupca\n";
            std::cout<<" 2 - dodavanje novog kupca\n";
            int k;
            std::cin>>k;
            if(k==0)continue;
            if(k==1){
                std::cout<<"Odaberite kupca. Dostupni kupci su:\n";
                ispissvihkupaca(1);
                int ind;
                std::cin>>ind;
                if(ind<1 || ind>kupci.size())throw std::range_error("ne valja index");
                prodaje.DajProdaju(indeks+1).PromijeniKupca(kupci[ind-1]);
                std::cout<<"Prodaja je uspjesno izmijenjena!\n\n";
                return;
            }
            if(k==2){
                do{
                    try{
                        std::cout<<"Unesite ime i prezime kupca: ";
                        std::cin.ignore(1000, '\n');
                        std::string a;
                        std::getline(std::cin, a, '\n');
                        std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                        int dan, mjesec, godina;
                        std::scanf("%d/%d/%d", &dan, &mjesec, &godina);
                        Kupac k=Kupac(a, Datum(dan, mjesec, godina));
                        prodaje.DajProdaju(indeks+1).PromijeniKupca(k);
                        kupci.push_back(k);
                        std::cout<<"Prodaja je uspjesno izmijenjena!\n\n";
                        return;
                    }
                    catch(std::domain_error gg){
                        std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
                    }
                }while(true);
            }
        }
        if(n==4){
            std::cout<<"Izaberite opciju:\n";
            std::cout<<" 0 - nazad\n";
            std::cout<<" 1 - odabir postojeceg stana\n";
            std::cout<<" 2 - dodavanje novog stana\n";
            int k;
            std::cin>>k;
            if(k==0)continue;
            if(k==1){
                std::cout<<"Odaberite stan. Dostupni stanovi su:\n";
                ispissvihstanova(" ", " - ");
                int ind;
                std::cin>>ind;
                if(ind<1 || ind>stanovi.size())throw std::range_error("ne valja index");
                prodaje.DajProdaju(indeks+1).PromijeniStan(stanovi[ind-1]);
                std::cout<<"Prodaja je uspjesno izmijenjena!\n\n";
                return;
            }
            if(k==2){
                Stan s=dodavanjestana();
                prodaje.DajProdaju(indeks+1).PromijeniStan(s);
                stanovi.push_back(s);
                std::cout<<"Prodaja je uspjesno izmijenjena!\n\n";
                return;
            }
        }
        if(n==5){
            do{
                try{
                    std::cout<<"Unesite cijenu stana: ";
                    double cijena;
                    std::cin>>cijena;
                    if(cijena<0)throw std::domain_error("Neispravan unos podataka");
                    prodaje.DajProdaju(indeks+1).PromijeniCijenuProdaje(cijena);
                    std::cout<<"Prodaja je uspjesno izmijenjena!\n\n";
                    return;
                }
                catch(std::domain_error gg){
                    std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
                }
            }while(true);
        }
    }while(true);
}
void ispisprodaja(){
    do{
        std::cout<<"Izaberite opciju:\n";
        std::cout<<" 0 - nazad\n";
        std::cout<<" 1 - ispis svih prodaja\n";
        std::cout<<" 2 - ispis prodaja na datum\n";
        std::cout<<" 3 - ispis najranije prodaje\n";
        std::cout<<" 4 - ispis najskuplje prodaje\n";
        std::cout<<" 5 - ispis broja prodaja\n";
        std::cout<<" 6 - ispis broja prodaja po datumu\n";
        std::cout<<" 7 - ispis broja prodaja po agentu\n";
        std::cout<<" 8 - kraj\n";
        int n;
        std::cin>>n;
        if(n==0)return;
        if(n==1)ispissvihprodaja();
        if(n==2)ispisprodajanadatum();
        if(n==3)prodaje.DajNajranijuProdaju().Ispisi();
        if(n==4)prodaje.DajNajskupljuProdaju().Ispisi();
        if(n==5)std::cout<<"Broj prodaja: "<<prodaje.DajBrojProdaja()<<"\n\n";
        if(n==6)ispisbrojaprodajapodatumu();
        if(n==7)ispisbrojaprodajapoagentu();
        if(n==8)throw std::invalid_argument("kraj");
    }while(true);
}
void ispissvihprodaja(){
    prodaje.IspisiSveProdaje();
    return;
    std::vector<bool> indeksi(prodaje.DajBrojProdaja(), false);
    for(int j=0;j<prodaje.DajBrojProdaja();j++){
        int najm=0;
        while(indeksi[najm])najm++;
        for(int i=0;i<prodaje.DajBrojProdaja();i++){
            if(!indeksi[i]){
                if(prodaje.DajProdaju(najm+1).DajImeKupca()>prodaje.DajProdaju(i+1).DajImeKupca())najm=i;
            }
        }
        prodaje.DajProdaju(najm+1).Ispisi();
        std::cout<<"\n";
        indeksi[najm]=true;
        if(j==prodaje.DajBrojProdaja()-1)std::cout<<"\n";
    }
}
void ispisprodajanadatum(){
    do{
        try{
            std::cout<<"Unesite datum: ";
            int dan, mjesec, godina;
            std::scanf("%d/%d/%d", &dan, &mjesec, &godina);
            Datum d(dan, mjesec, godina);
            std::cout<<"Prodaje na datum ";d.Ispisi();std::cout<<" su:";
            prodaje.IspisiProdajeNaDatum(d);
            break;
        }
        catch(std::domain_error gg){
            std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
        }
    }while(true);
}
void ispisbrojaprodajapodatumu(){
    do{
        try{
            std::cout<<"Unesite datum (d/m/g): ";
            int dan, mjesec, godina;
            std::scanf("%d/%d/%d", &dan, &mjesec, &godina);
            Datum d(dan, mjesec, godina);
            std::cout<<"Broj prodaja na uneseni datum: "<<prodaje.DajBrojProdajaNaDatum(d)<<"\n\n";
            break;
        }
        catch(std::domain_error gg){
            std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
        }
    }while(true);
}
void ispisbrojaprodajapoagentu(){
    std::string a;
    std::cout<<"Unesite ime agenta: ";
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, a, '\n');
    std::cout<<"Broj prodaja unesenog agenta: "<<prodaje.DajBrojProdajaOdAgenta(a)<<"\n\n";
}
void brisanjeprodaja(){
    do{
    std::cout<<"Izaberite opciju:\n";
    std::cout<<" 0 - nazad\n";
    std::cout<<" 1 - brisanje najranije prodaje\n";
    std::cout<<" 2 - brisanje prodaja agenta\n";
    std::cout<<" 3 - brisanje prodaja po datumu\n";
    std::cout<<" 4 - brisanje svih prodaja\n";
    int n;
    std::cin>>n;
    if(n==0)return;
    if(n==1)brisanjenajranijeprodaje();
    if(n==2)brisanjeprodajaagenta();
    if(n==3)brisanjeprodajapodatumu();
    if(n==4)brisanjesvihprodaja();
    }while(true);
}
void brisanjenajranijeprodaje(){
    try{
        prodaje.ObrisiNajranijuProdaju();
        std::cout<<"Najranija prodaja je obrisana!\n\n";
    }
    catch(std::range_error gg){
        std::cout<<"Izuzetak: "<<gg.what()<<".\n\n";
        return;
    }
}
void brisanjeprodajaagenta(){
    std::string a;
    std::cout<<"Unesite ime agenta: ";
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, a, '\n');
    try{
        prodaje.ObrisiProdajeAgenta(a);
    }
    catch(std::range_error gg){
        std::cout<<"Izuzetak: "<<gg.what()<<".\n\n";
        return;
    }
    std::cout<<"Sve prodaje tog agenta su obrisane.\n\n";
}
void brisanjeprodajapodatumu(){
    do{
        try{
            std::cout<<"Unesite datum: ";
            int dan, mjesec, godina;
            std::scanf("%d/%d/%d", &dan, &mjesec, &godina);
            Datum d(dan, mjesec, godina);
            prodaje.ObrisiProdajeNaDatum(d);
            std::cout<<"Sve prodaje na taj datum su obrisane.\n\n";
            break;
        }
        catch(std::domain_error gg){
            std::cout<<"Izuzetak: "<<gg.what()<<". Molimo unesite opet.\n";
        }
        catch(std::range_error gg){
            std::cout<<"Izuzetak: "<<gg.what()<<".\n\n";
            return;
        }
    }while(true);
}
void brisanjesvihprodaja(){
    try{
        prodaje.IsprazniKolekciju();
    }
    catch(std::range_error gg){
        std::cout<<"Izuzetak: "<<gg.what()<<".\n\n";
        return;
    }
    std::cout<<"Sve prodaje su obrisane.\n\n";
}

int main ()
{
    {
        auto a=Prodaja("falja", 1, 1, 1, 2014, "far", Datum(1, 1, 2000), "zmajevac", 3, 5, true, 64);
        Prodaje g{Prodaja("agent agentic", 10, 29, 5, 2017, "neko nekic", Datum(1, 1, 2000), "zmajevac", 3, 5, true, 64),
                     Prodaja("agent agentic", 11, 29, 5, 2017, "niko nikic", Datum(1, 1, 2000), "zmajevac", 3, 5, true, 64),
                     Prodaja("agent agentic", 11, 19, 5, 2017, "marko markovic", Datum(1, 1, 2000), "zmajevac", 3, 5, true, 64)
        };
    }
    std::cout<<"Dobrodosli!\n\n";
    try{
        meni1();
    }
    catch(std::invalid_argument gg){
    }
    std::cout<<"\nDovidjenja!";
}