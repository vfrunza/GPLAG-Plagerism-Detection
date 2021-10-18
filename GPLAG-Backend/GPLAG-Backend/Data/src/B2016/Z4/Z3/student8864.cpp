/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <vector>
class Datum{
    int dan,mjesec,godina;
    friend class Prodaja;
    void DanNaprijed();
    void DanNazad();
    void DajDatum(int&g,int&m,int&d)const{g=godina;m=mjesec;d=dan;}
  public:
    Datum(int d, int m, int g);
    void Postavi(int d, int m, int g);
    int DajDan() const{return dan;}
    int DajMjesec() const{return mjesec;}
    int DajGodinu() const{return godina;}
    void Ispisi() const{std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};
void Datum::Postavi(int d,int m, int g){
    int br_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((g%4==0 && g%100!=0) || g%400==0)br_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d>br_dana[m-1])throw std::domain_error("Neispravan datum");
    dan=d; mjesec=m; godina=g;
}
Datum::Datum(int d,int m,int g){
    Postavi(d,m,g);
}
void Datum::DanNaprijed(){
    int br_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    dan++;
    if(dan>br_dana[mjesec-1]){
        dan=1;
        mjesec++;
    }
    if(mjesec==13){
        mjesec=1;
        godina++;
    }
}
void Datum::DanNazad(){
    int br_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    dan--;
    if(dan==0){
        dan=br_dana[mjesec-2];
        mjesec--;
    }
    if(mjesec==0){
        mjesec=12;
        godina--;
    }
    if(godina==0) throw std::domain_error("Godina manja od 1");
}

class Kupac{
    Datum date;
    std::string name;
  public:    
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const{return name;}
    Datum DajDatumRodjenja() const{return date;}
    void Ispisi() const{std::cout<<name<<" ("; date.Ispisi(); std::cout<<")"<<std::endl;}
};
void Kupac::Postavi(const std::string& ime_i_prezime, const Datum& datum_rodjenja){
    auto p(ime_i_prezime.begin());
    while(p!=ime_i_prezime.end()){
        if(!((*p>='a' && *p<='z')||(*p>='A' && *p<='Z')||(*p>='0' && *p<='9')||*p==' '||*p=='-'||*p=='\''))
            throw std::domain_error("Neispravno ime i prezime");
        p++;    
    }
    date=datum_rodjenja;
    name=ime_i_prezime;
}
Kupac::Kupac(const std::string& ime_i_prezime,const Datum& datum_rodjenja):date(datum_rodjenja){
    Postavi(ime_i_prezime,datum_rodjenja);
}

class Stan{
    std::string adresa;
    int sprat,br_soba,br_kvadrata;
    bool namjestenost;
  public:
    Stan(const std::string &adresa, int spratovi, int broj_soba, bool namjesten, double kvadratura);
    void Postavi(const std::string &adress, int spratovi, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const{return adresa;}
    int DajSprat() const{return sprat;}
    int DajBrojSoba() const{return br_soba;}
    bool DajNamjesten() const{return namjestenost;}
    double DajKvadraturu() const{return br_kvadrata;}
    void Ispisi() const{std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<br_soba;
    if(br_soba==1) std::cout<<" sobu. ";
    else if(br_soba==2 || br_soba==3 || br_soba==4)std::cout<<" sobe. ";
    else std::cout<<" soba. ";
    std::cout<<"Kvadratura stana je "<<br_kvadrata<<" (m^2) i stan ";
    if(namjestenost)std::cout<<"je";
    else std::cout<<"nije";
    std::cout<<" namjesten.\n";} 
};
void Stan::Postavi(const std::string& adress,int spratovi,int broj_soba, bool namjesten,double kvadratura){
    if(spratovi<=0 || broj_soba<=0 || kvadratura<=0)throw std::domain_error("Neispravan unos podataka");
    adresa=adress; sprat=spratovi; br_soba=broj_soba; br_kvadrata=kvadratura; namjestenost=namjesten;
}
Stan::Stan(const std::string& adress,int spratovi,int broj_soba,bool namjesten,double kvadratura){
    Postavi(adress,spratovi,broj_soba,namjesten,kvadratura);
}

class Prodaja{
    std::string agent;
    double cijena;
    Datum datum;
    Kupac kupac;
    Stan stan;
    void DatumProdaje(int&a,int&b,int&c)const{
        datum.DajDatum(a,b,c);
    }
  public:    
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata);
    void PromijeniAgenta(const std::string& ime_agenta){agent=ime_agenta;}
    void PromijeniKupca(const Kupac &novi_kupac){kupac=novi_kupac;}
    void PromijeniStan(const Stan &novi_stan){stan=novi_stan;}
    void PromijeniDatumKupovine(const Datum &novi_datum){datum=novi_datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena){cijena=nova_cijena;}
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const{return agent;}
    std::string DajImeKupca() const{return kupac.DajImePrezime();}
    Datum DajDatumProdaje() const{return datum;}
    double DajCijenuStana() const{return cijena;}
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan):datum(datum_prodaje),kupac(kupac_stana),stan(kupljeni_stan){
        agent=ime_agenta_prodaje; cijena=cijena_stana;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata)
    :datum(dan_prodaje,mjesec_prodaje,godina_prodaje),kupac(ime_kupca,datum_rodjenja_kupca),stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){
    agent=ime_agenta_prodaje;
    cijena=cijena_stana;
}
void Prodaja::PomjeriDanUnaprijed(){ datum.DanNaprijed();}
void Prodaja::PomjeriDanUnazad(){datum.DanNazad();}
bool SkupljiStan(const Prodaja &p1, const Prodaja&p2){
    if(p1.cijena>p2.cijena) return true;
    return false;
}
bool ProdatPrije(const Prodaja &p1,const Prodaja &p2){
    int g1,g2,m1,m2,d1,d2;
    p1.DatumProdaje(g1,m1,d1);
    p2.DatumProdaje(g2,m2,d2);
    if(g1>g2) return true;
    if(g1<g2) return false;
    if(m1>m2) return true;
    if(m1<m2) return false;
    if(d1>d2) return true;
    return false;
}
void Prodaja::Ispisi()const{
    std::cout<<std::setw(20)<<"Ime agenta:"<<agent<<std::endl
    <<std::setw(20)<<"Ime kupca:"<<kupac.DajImePrezime()<<std::endl
    <<std::setw(20)<<"Zakazani datum prodaje:";
}

class Prodaje{
    int dimenzija,max_dimenzija;
    Prodaja **pok;
  public:    
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, 
    const Kupac &kupac_stana,const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, 
    std::string &ime_kupca,const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const{return dimenzija;}
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
    void IspisiProdaju()const;
};
Prodaje::Prodaje(int max_broj_prodaja):max_dimenzija(max_broj_prodaja){
    pok=new Prodaja*[max_dimenzija]{};
    dimenzija=0;
}
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja):max_dimenzija(spisak_prodaja.size()),pok(new Prodaja*[max_dimenzija]){
    //std::copy(spisak_prodaja.begin(),spisak_prodaja.end(),pok);
    auto it(spisak_prodaja.begin());
    for(int i=0;i<max_dimenzija;i++){
        pok[i]=new Prodaja(*it++);
    }
    dimenzija=max_dimenzija;
}
Prodaje::~Prodaje(){
    for(int i=0;i<dimenzija;i++)delete pok[i];
    delete[]pok;
}
Prodaje::Prodaje(const Prodaje& prodaje):dimenzija(prodaje.dimenzija),max_dimenzija(prodaje.max_dimenzija),pok(new Prodaja*[max_dimenzija]{}){
    try{
        for(int i=0;i<dimenzija;i++) pok[i]=new Prodaja(*prodaje.pok[i]);
    }catch(...){
        for(int i=0;i<dimenzija;i++) delete pok[i];
        delete[] pok;
        throw;
    }
}
Prodaje::Prodaje(Prodaje&&prodaje):dimenzija(prodaje.dimenzija),max_dimenzija(prodaje.max_dimenzija),pok(prodaje.pok){
    prodaje.pok=nullptr; prodaje.dimenzija=0;
}
Prodaje &Prodaje::operator =(const Prodaje&prodaje){
    if(max_dimenzija!=prodaje.max_dimenzija) throw std::domain_error("pogresne dimenzije");
    if(prodaje.dimenzija>dimenzija){
        try{
            for(int i=dimenzija;i<prodaje.dimenzija;i++){
                pok[i]=new Prodaja(*prodaje.pok[i]);
            }
        }catch(...){
            for(int i=dimenzija;i<prodaje.dimenzija;i++){ delete pok[i]; pok[i]=nullptr;}
            throw;
        }
    }
    else{
        for(int i=prodaje.dimenzija;i<dimenzija;i++){
            delete pok[i];pok[i]=nullptr;
        }
    }
    dimenzija=prodaje.dimenzija;
    for(int i=0;i<dimenzija;i++){
        *pok[i]=*prodaje.pok[i];
    }
    return *this;
}
Prodaje &Prodaje::operator =(Prodaje &&prodaje){
    if(prodaje.max_dimenzija!=max_dimenzija)throw std::domain_error("pogresna dimenzija");
    std::swap(dimenzija,prodaje.dimenzija);
    std::swap(pok,prodaje.pok);
    return *this;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, 
const Kupac &kupac_stana,const Stan &kupljeni_stan){
    if(dimenzija==max_dimenzija)throw std::range_error("Dostignut maksimalni broj prodaja");
    pok[dimenzija]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
    dimenzija++;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, 
    std::string &ime_kupca,const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata){
        if(dimenzija==max_dimenzija)throw std::range_error("Dostignut maksimalni broj prodaja");
        pok[dimenzija]=new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,
        broj_soba,namjesten_stan,broj_kvadrata);
        dimenzija++;
    }
void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(dimenzija==max_dimenzija)throw std::range_error("Dostignut maksimalni broj prodaja");
    pok[dimenzija]=prodaja;
    dimenzija++;
}
int Prodaje::DajBrojProdajaNaDatum(const Datum& datum)const{
    Datum date(datum);
    return std::count_if(*pok,*pok+dimenzija,[date](Prodaja p){
        if(p.DajDatumProdaje().DajGodinu()==date.DajGodinu()&&p.DajDatumProdaje().DajMjesec()==date.DajMjesec()&&
        p.DajDatumProdaje().DajDan()==date.DajDan()) return true;return false;});
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string&ime_agenta)const{
    int brojac(0);
    for(int i=0;i<dimenzija;i++){
        if(pok[i]->DajImeAgenta()==ime_agenta)brojac++;
    }
    return brojac;
}
Prodaja& Prodaje::DajNajranijuProdaju(){
    auto p=pok[0];
    for(int i=0;i<dimenzija;i++){
        if(ProdatPrije(*pok[i],*p))p=pok[i];
    }
    return *p;
}
Prodaja Prodaje::DajNajranijuProdaju()const{
    auto p(pok[0]);
    for(int i=0;i<dimenzija;i++){
        if(ProdatPrije(*pok[i],*p))p=pok[i];
    }
    return *p;
}
Prodaja& Prodaje::DajNajskupljuProdaju(){
    auto p(pok[0]);
    for(int i=0;i<dimenzija;i++){
        if(SkupljiStan(*pok[i],*p))p=pok[i];
    }
    return *p;
}
Prodaja Prodaje::DajNajskupljuProdaju()const{
    auto p(pok[0]);
    for(int i=0;i<dimenzija;i++){
        if(SkupljiStan(*pok[i],*p))p=pok[i];
    }
    return *p;
}
void Prodaje::IsprazniKolekciju(){
    for(int i=0;i<dimenzija;i++){
        delete pok[i];
        pok[i]=nullptr;
    }
}
void Prodaje::ObrisiNajranijuProdaju(){
    if(dimenzija==0)throw std::range_error("Prazna kolekcija");
    int indeks(0);
    for(int i=0;i<dimenzija;i++){
        if(ProdatPrije(*pok[i],*pok[indeks]))indeks=i;
    }
    delete pok[indeks];
    pok[indeks]=pok[dimenzija-1];
    delete pok[dimenzija-1];
    pok[dimenzija-1]=nullptr;
    dimenzija--;
}
void Prodaje::ObrisiProdajeAgenta(const std::string&ime_agenta){
    for(int i=0;i<dimenzija;i++){
        if(pok[i]->DajImeAgenta()==ime_agenta){
            delete pok[i];
            pok[i]=pok[dimenzija-1];
            delete pok[dimenzija-1];
            pok[dimenzija-1]=nullptr;
            dimenzija--; i--;
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum&datum){
    for(int i=0;i<dimenzija;i++){
        if(pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()&&pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec()
        &&pok[i]->DajDatumProdaje().DajDan()==datum.DajDan()){
            delete pok[i];
            pok[i]=pok[dimenzija-1];
            delete pok[dimenzija-1];
            pok[dimenzija-1]=nullptr;
            dimenzija--; i--;
        }
    }
}
void Prodaje::IspisiProdajeNaDatum(const Datum&datum)const{
    for(int i=0;i<dimenzija;i++){
        if(pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()&&pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec()
        &&pok[i]->DajDatumProdaje().DajDan()==datum.DajDan()) std::cout<<"Ispisi na datum";
    }
}
void Prodaje::IspisiSveProdaje()const{
    for(int i=0;i<dimenzija;i++){
        std::cout<<i+1<<".\n";
        
    }
    std::cout<<"Ispisi sve prodaje";
}
void Prodaje::IspisiProdaju()const{
    
}
int main (){
    std::cout<<"Dobrodosli!"<<std::endl;
    std::vector<Stan> stanovi;
    std::vector<Kupac> kupci;
    Prodaje sveprodaje(100);
    int opcija1,opcija2,opcija3;
    do{
        std::cout<<"Izaberite opciju:\n"<<"0 - kraj\n"<<"1 - uredjivanje stanova\n"<<"2 - uredjivanje kupaca\n"<<"3 - uredjivanje prodaja\n";
        std::cin>>opcija1;
        //Uredjivanje stanova
        if(opcija1==1){
            do{
                std::cout<<"Izaberite opciju:\n"<<"0 - nazad\n"<<"1 - dodavanje stana\n"<<"2 - uredjivanje stanova\n"<<"3 - ispis svih stanova\n"<<"4 - kraj\n";
                std::cin>>opcija2;
                //Dodavanje stana
                if(opcija2==1){
                    bool ispravan(false);
                    while(ispravan==false){
                        ispravan=true;
                        std::cout<<"Unesite adresu: Unesite sprat: Unesite broj soba: Da li je stan namjesten (1 - da, 0 - ne): Unesite kvadraturu: ";
                        std::string adresa;
                        std::cin.ignore(1000,'\n');
                        std::getline(std::cin,adresa);
                        int sprat,sobe,namjesten;
                        double kvadratura;
                        std::cin>>sprat>>sobe>>namjesten>>kvadratura;
                        if(!(namjesten==0 || namjesten==1)){
                            std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                            ispravan=false;
                            continue;
                        }
                        bool namjestenost(namjesten);
                        try{
                            Stan novistan(adresa,sprat,sobe,namjestenost,kvadratura);
                        }catch(std::domain_error a){std::cout<<"Izuzetak: "<<a.what()<<". Molimo unesite opet.\n";ispravan=false; }
                        if(ispravan){
                            std::cout<<"Stan je uspjesno dodan!\n";
                            Stan novistan(adresa,sprat,sobe,namjestenost,kvadratura);
                            stanovi.push_back(novistan);
                        }
                    }
                }
                //Uredjivanje stanova
                if(opcija2==2){
                    std::cout<<"Odaberite stan. Dostupni stanovi su:\n";
                    for(int i=0;i<stanovi.size();i++){
                        std::cout<<i+1<<" - "; stanovi[i].Ispisi();
                    }
                    int k;
                    std::cin>>k;
                    std::cout<<"Odaberite polje koje zelite urediti:\n"<<"0 - nazad\n"<<"1 - adresa\n"<<"2 - sprat\n"<<"3 - broj soba\n"<<"4 - da li je stan namjesten\n"<<"5 - kvadratura\n"<<"6 - sve\n";
                    std::cin>>opcija3;
                    if(opcija3==1){
                        bool ispravan(false);
                        while (ispravan==false){
                            ispravan=true;
                            std::cout<<"Unesite adresu: ";
                           std::string adresa;
                            std::cin.ignore(1000,'\n');
                            std::getline(std::cin,adresa);
                            stanovi[k-1].Postavi(adresa,stanovi[k-1].DajSprat(),stanovi[k-1].DajBrojSoba(),stanovi[k-1].DajNamjesten(),stanovi[k-1].DajKvadraturu());
                        }
                    }
                    if(opcija3==2){
                        bool ispravan(false);
                        while (ispravan==false){
                            ispravan=true;
                            std::cout<<"Unesite broj sprata: ";
                            int sprat;
                            std::cin>>sprat;
                            if(sprat<0){
                                std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet.";
                                ispravan=false;
                            }
                            else stanovi[k-1].Postavi(stanovi[k-1].DajAdresu(),sprat,stanovi[k-1].DajBrojSoba(),stanovi[k-1].DajNamjesten(),stanovi[k-1].DajKvadraturu());
                        }
                    }
                    if(opcija3==3){
                        bool ispravan(false);
                        while (ispravan==false){
                            ispravan=true;
                            std::cout<<"Unesite broj soba: ";
                            int soba;
                            std::cin>>soba;
                            if(soba<0){
                                std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet.";
                                ispravan=false;
                            }
                            else stanovi[k-1].Postavi(stanovi[k-1].DajAdresu(),stanovi[k-1].DajSprat(),soba,stanovi[k-1].DajNamjesten(),stanovi[k-1].DajKvadraturu());
                        }
                    }
                    if(opcija3==4){
                        bool ispravan(false);
                        while (ispravan==false){
                            ispravan=true;
                            std::cout<<"Unesite namjestenost: ";
                            int namjestenost;
                            std::cin>>namjestenost;
                            if(!(namjestenost==0 || namjestenost==1)){
                                std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet.";
                                ispravan=false;
                            }
                            else{
                                bool n(namjestenost);
                                stanovi[k-1].Postavi(stanovi[k-1].DajAdresu(),stanovi[k-1].DajSprat(),stanovi[k-1].DajBrojSoba(),n,stanovi[k-1].DajKvadraturu());
                            }
                        }
                    }
                    if(opcija3==5){
                        bool ispravan(false);
                        while (ispravan==false){
                            ispravan=true;
                            std::cout<<"Unesite kvadraturu: ";
                            double kvadrat;
                            std::cin>>kvadrat;
                            if(kvadrat<0){
                                std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                                ispravan=false;
                            }
                            else {
                                stanovi[k-1].Postavi(stanovi[k-1].DajAdresu(),stanovi[k-1].DajSprat(),stanovi[k-1].DajBrojSoba(),stanovi[k-1].DajNamjesten(),kvadrat);
                                std::cout<<"Stan je uspjesno izmijenjen!\n";
                            }
                        }
                    }
                    if(opcija3==6){
                        std::cout<<"Unesite adresu: ";
                        std::cin.ignore(1000,'\n');
                        std::string adresa;
                        std::getline(std::cin,adresa);
                        std::cout<<"Unesite sprat: Unesite broj soba: Da li je stan namjesten (1 - da, 0 - ne): Unesite kvadraturu: ";
                        int sprat,sobe;
                        bool namjesten;
                        double kvadratura;
                        std::cin>>sprat>>sobe>>namjesten>>kvadratura;
                        stanovi[k-1].Postavi(adresa,sprat,sobe,namjesten,kvadratura);
                        std::cout<<"Stan je uspjesno izmjenjen!\n";
                    }
                }
                if(opcija2==3){
                    for(int i=0;i<stanovi.size();i++){
                        std::cout<<i+1<<". "; stanovi[i].Ispisi();
                    }
                }
                if(opcija2==4){
                    std::cout<<std::endl<<"Dovidjenja!";
                    return 0;
                }
            }while (opcija2!=0);
        }
        //uredjivanje kupaca
        if(opcija1==2){
            do{
                std::cout<<"Izaberite opciju:\n"<<"0 - nazad\n"<<"1 - dodavanje kupca\n"<<"2 - uredjivanje kupaca\n"<<"3 - ispis svih kupaca\n"<<"4 - kraj\n";
                std::cin>>opcija2;
                if(opcija2==1){
                    bool ispravan(false);
                    while (ispravan==false){
                        ispravan=true;
                        std::cout<<"Unesite ime i prezime kupca: ";
                        std::cin.ignore(1000,'\n');
                        std::string imeprezime;
                        std::getline(std::cin,imeprezime);
                        std::cout<<"Unesite datum rodjenja (formata dan/mjesec/godina): ";
                        int d,m,g;
                        char znak;
                        std::cin>>d>>znak>>m>>znak>>g;
                        try{
                            Datum test1(d,m,g);
                            Kupac test2(imeprezime,test1);
                        }catch(std::domain_error a){
                            std::cout<<"Izuzetak: "<<a.what()<<". Molimo unesite opet.\n";
                            ispravan=false;
                        }
                        if(ispravan){
                            Datum dat(d,m,g);
                            Kupac kup(imeprezime,dat);
                            kupci.push_back(kup);
                            std::cout<<"Kupac je uspjesno dodan!\n";
                        }
                    }
                }
                if(opcija2==2){
                    std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su: \n";
                    for(int i=0;i<kupci.size();i++){
                        std::cout<<i+1<<" - ";kupci[i].Ispisi();
                    }
                    int k;
                    std::cin>>k;
                    bool ispravan(false);
                    while (ispravan==false){
                        ispravan=true;
                        std::cout<<"Unesite ime i prezime kupca: ";
                        std::cin.ignore(1000,'\n');
                        std::string imeprezime;
                        std::getline(std::cin,imeprezime);
                        std::cout<<"Unesite datum rodjenja (formata dan/mjesec/godina): ";
                        int d,m,g;
                        char znak;
                        std::cin>>d>>znak>>m>>znak>>g;
                        try{
                            Datum test1(d,m,g);
                            Kupac test2(imeprezime,test1);
                        }catch(std::domain_error a){
                            std::cout<<"Izuzetak: "<<a.what()<<". Molimo unesite opet.\n";
                            ispravan=false;
                        }
                        if(ispravan){
                            Datum dat(d,m,g);
                            Kupac kup(imeprezime,dat);
                            kupci[k-1]=kup;
                            std::cout<<"Kupac je uspjesno izmijenjen!\n";
                        }
                    }
                }
                if(opcija2==3){
                    for(int i=0;i<kupci.size();i++){
                        kupci[i].Ispisi();
                    }
                }
                if(opcija2==4){
                    std::cout<<std::endl<<"Dovidjenja!";
                    return 0;
                }
            }while(opcija2!=0);
        }
        if(opcija1==3){
            do{
                std::cout<<"Izaberite opciju:\n"<<"0 - nazad\n"<<"1 - dodavanje prodaje\n"<<"2 - uredjivanje prodaje\n"<<"3 - ispis prodaja\n"<<"4 - brisanje prodaja"<<"5 - kraj\n";
                std::cin>>opcija2;
                if(opcija2==1){
                    do{
                        std::cout<<"Izaberite opciju:\n"<<"0 - nazad\n"<<"1 - dodavanje potpuno nove prodaje\n"<<"2 - dodavanje nove prodaje na osnovu arhive\n"<<"3 - kraj\n";
                        std::cin>>opcija3;
                        if(opcija3==1){
                            std::cout<<"Unesite ime i prezime agenta prodaje: ";
                            std::string agent;
                            std::cin.ignore(1000,'\n');
                            std::getline(std::cin,agent);
                            std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                            int d1,m1,g1;
                            char znak;
                            std::cin>>d1>>znak>>m1>>znak>>g1;
                            std::cout<<"Unesite cijenu stana: ";
                            double cijena;
                            std::cin>>cijena;
                            std::cout<<"Unesite ime kupca: ";
                            std::cin.ignore(1000,'\n');
                            std::string imekupca;
                            std::getline(std::cin,imekupca);
                            std::cout<<"Unesite datum rodjenja kupca: ";
                            int d2,m2,g2;
                            std::cin>>d2>>m2>>g2;
                            Datum rodjenjekupca(d2,m2,g2);
                            std::cout<<"Unesite adresu: ";
                            std::string adresa;
                            std::cin.ignore(1000,'\n');
                            std::getline(std::cin,adresa);
                            std::cout<<"Unesite sprat: Unesite broj soba: Da li je stan namjesten (1 - da, 0 - ne): Unesite kvadraturu: ";
                            int sprat,soba,nam;
                            double kvadrat;
                            bool namjesten;
                            std::cin>>sprat>>soba>>nam>>kvadrat;
                            namjesten=nam;
                            sveprodaje.RegistrirajProdaju(agent,cijena,d1,m1,g1,imekupca,rodjenjekupca,adresa,sprat,soba,namjesten,kvadrat);
                            std::cout<<"Prodaja uspjesno dodana!";
                        }
                        if(opcija3==2){
                            std::cout<<"Unesite ime i prezime agenta prodaje: ";
                            std::string agent;
                            std::cin.ignore(1000,'\n');
                            std::getline(std::cin,agent);
                            std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                            int d1,m1,g1;
                            char znak;
                            std::cin>>d1>>znak>>m1>>znak>>g1;
                            std::cout<<"Unesite cijenu stana: ";
                            double cijena;
                            std::cin>>cijena;
                            std::cout<<"Odaberite kupca. Dostupni kupci su: ";
                            for(int i=0;i<kupci.size();i++){
                                std::cout<<i+1<<" - ";kupci[i].Ispisi();
                            }
                            int brkupca;
                            std::cin>>brkupca;
                            std::cout<<"Odaberite stan. Dostupni stanovi su: ";
                            for(int i=0;i<stanovi.size();i++){
                                std::cout<<i+1<<" - "; stanovi[i].Ispisi();
                            }
                            int brstana;
                            std::cin>>brstana;
                            Datum novi(d1,m1,g1);
                            sveprodaje.RegistrirajProdaju(agent,cijena,novi,kupci[brkupca-1],stanovi[brstana-1]);
                            std::cout<<"Prodaja uspjesno dodana!";
                        }
                        if(opcija3==3){
                            std::cout<<std::endl<<"Dovidjenja!";
                            return 0;
                        }
                    }while(opcija3!=0);
                }
                if(opcija2==2){
                    std::cout<<"Odaberite prodaju koju zelite urediti. Dostupne prodaje su: ";
                    sveprodaje.IspisiSveProdaje();
                    int brprodaje;
                    std::cin>>brprodaje;
                        std::cout<<"Izaberite opciju:\n0 - nazad\n 1 - izmjena agenta\n2 - izmjena datuma prodaje\n3 - izmjena kupca\n4 - izmjena stana\n5 - izmjena cijene stana\n";
                        std::cin>>opcija3;
                        if(opcija3==1){
                            std::cout<<"Unesite ime i prezime agenta prodaje: ";
                            std::string agent;
                            std::cin.ignore(1000,'\n');
                            std::getline(std::cin,agent);
                            sveprodaje[brprodaje-1].PromijeniAgenta(agent);
                            std::cout<<"Prodaja je uspjesno izmijenjena!";
                        }
                        if(opcija3==2){
                            return 0;
                        }
                        if(opcija3==3){
                            return 0;
                        }
                        if(opcija3==4){
                            return 0;
                        }
                        if(opcija3==5){
                            return 0;
                        }
                }
                if(opcija2==3){
                    return 0;
                }
                if(opcija2==4){
                    return 0;
                }
                if(opcija2==5){
                    std::cout<<std::endl<<"Dovidjenja!";
                    return 0;
                }
            }while(opcija2!=0);
        }
    }while(opcija1!=0);
    std::cout<<std::endl<<"Dovidjenja!";
	return 0;
}