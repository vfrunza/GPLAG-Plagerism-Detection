/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <vector>
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Datum{                                                                                                                                                                                      
    int d,m,g;
    void TestDatuma(int dan, int mjesec,int godina){                                                                                                                                                                        
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4==0 && godina%100 !=0 )|| godina%400==0) broj_dana[1]++;
        if(godina<1 || dan<1 || mjesec<1 || dan>broj_dana[mjesec-1] || mjesec>12)
            throw std::domain_error("Neispravan datum");
    }
    public:
    Datum(int dan, int mjesec, int godina){                                                                                    
        try{
            TestDatuma(dan,mjesec,godina);
            d=dan; m=mjesec ; g=godina;
        }
        catch(...){
            throw;
        }
    }
    void Postavi(int dan, int mjesec, int godina){
        try{
            TestDatuma(dan,mjesec,godina);
            d=dan; m=mjesec ; g=godina;
        }
        catch(...){
            throw;
        }
    }
    int DajDan() const { return d;}
    int DajMjesec() const{ return m;}
    int DajGodinu() const{ return g;}
    void Ispisi() const{
        std::cout << d << "/" << m << "/" << g;
    }
};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Kupac{                                                                                    
    std::string imeiprezime;
    Datum dr;
    void TestImena(const std::string &s){
        for(auto i=s.begin();i!=s.end();i++){
            if(*i!=' ' && *i!='-' && *i!='\'' && (*i<'0' || (*i>'9' && *i<'A') || (*i>'Z' && *i<'a') || *i>'z'))
                throw std::domain_error("Neispravno ime i prezime");
        }
    }
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):dr(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu()){
        try{
            TestImena(ime_i_prezime);
            imeiprezime=ime_i_prezime;
        }
        catch(...){
            throw;
        }
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
        try{
            TestImena(ime_i_prezime);
            imeiprezime=ime_i_prezime; dr=datum_rodjenja;
        }
        catch(...){
            throw;
        }
    }
    std::string DajImePrezime() const{ return imeiprezime;}
    Datum DajDatumRodjenja() const{ return dr;}
    void Ispisi() const{
        std::cout << imeiprezime << " (" ; dr.Ispisi() ; std::cout << ")";
    }
};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Stan{
    std::string adr;
    int s,bs;
    bool n;
    double k;
    void TestAtributaStana(int sprat,int broj_soba,double kvadratura){
        if(sprat <0 || broj_soba<0 || kvadratura<0)throw std::domain_error("Neispravan unos podataka");
    }
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura){
        try{
            TestAtributaStana(sprat,broj_soba,kvadratura);
            adr=adresa; s=sprat; bs=broj_soba; n=namjesten; k=kvadratura;
        }
        catch(...){
            throw;
        }
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura){
        try{
            TestAtributaStana(sprat,broj_soba,kvadratura);
            adr=adresa; s=sprat; bs=broj_soba; n=namjesten; k=kvadratura;
        }
        catch(...){
            throw;
        }
    }
    std::string DajAdresu() const { return adr; }
    int DajSprat() const { return s; }
    int DajBrojSoba() const { return bs; }
    bool DajNamjesten() const { return n; }
    double DajKvadraturu() const { return k; }
    void Ispisi() const {
        if(bs==1)std::cout << "Stan se nalazi na adresi "<< adr << " na " << s << ". spratu i ima " << bs << " sobu. " ;
        else if(bs==2 || bs==3 || bs==4)std::cout << "Stan se nalazi na adresi "<< adr << " na " << s << ". spratu i ima " << bs << " sobe. " ;
        else std::cout << "Stan se nalazi na adresi "<< adr << " na " << s << ". spratu i ima " << bs << " soba. "; 
        
        if(n)std::cout << "Kvadratura stana je " << k << " (m^2) i stan je namjesten." << std::endl;
        else std::cout << "Kvadratura stana je " << k << " (m^2) i stan nije namjesten." << std::endl;
    }
};
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Prodaja{
        std::string agent;
        double cijena;
        Datum datumprodaje;
        Kupac kupacstana;
        Stan kupljeni;
        void TestImena(const std::string &s){
            for(auto i=s.begin();i!=s.end();i++){
                if(*i!=' ' && *i!='-' && *i!='\'' && (*i<'0' || (*i>'9' && *i<'A') || (*i>'Z' && *i<'a') || *i>'z'))
                    throw std::domain_error("Neispravno ime i prezime");
            }
        }
    public:
        Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan):
            datumprodaje(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()), kupacstana(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja()), 
                kupljeni(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu()){
                    try{
                        TestImena(ime_agenta_prodaje);
                        agent=ime_agenta_prodaje;
                        cijena=cijena_stana;  
                    }
                    catch(...){
                        throw;
                    }
        } 
        Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata):
            datumprodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),kupacstana(ime_kupca,datum_rodjenja_kupca),kupljeni(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){
                try{
                    TestImena(ime_agenta_prodaje);
                    agent=ime_agenta_prodaje;
                    cijena=cijena_stana;
                }
                catch(...){
                    throw;
                }
        }
        void PromijeniAgenta(const std::string &agent007){ 
            try{
                TestImena(agent007);
                agent=agent007;
            }
            catch(...){
                throw;
            }
        }
        void PromijeniKupca(const Kupac &novi_kupac){ kupacstana=novi_kupac;}
        void PromijeniStan(const Stan &novi_stan){ kupljeni=novi_stan;}
        void PromijeniDatumKupovine(const Datum &novi_datum){ datumprodaje=novi_datum;}
        void PromijeniCijenuProdaje(const double &nova_cijena){ cijena=nova_cijena;}
        void PomjeriDanUnaprijed(){ datumprodaje=Datum(datumprodaje.DajDan()+1,datumprodaje.DajMjesec(),datumprodaje.DajGodinu()); }
        void PomjeriDanUnazad() { datumprodaje=Datum(datumprodaje.DajDan()-1,datumprodaje.DajMjesec(),datumprodaje.DajGodinu()); }
        std::string DajImeAgenta() const { return agent; }
        std::string DajImeKupca() const { return kupacstana.DajImePrezime(); }
        Datum DajDatumProdaje() const { return datumprodaje;}
        double DajCijenuStana() const { return cijena; }
        friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
        friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
        void Ispisi() const {
            std::cout << "Ime agenta:                     " << agent << std::endl;
            std::cout << "Ime kupca:                      " ; kupacstana.Ispisi(); std::cout << std::endl;
            std::cout << "Zakazani datum prodaje:         " ; datumprodaje.Ispisi(); std::cout << std::endl;
            std::cout << "Cijena stana:                   " << cijena << std::endl;
            std::cout << "Informacije o stanu:            " << std::endl;
            kupljeni.Ispisi();
        }
};
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Prodaje{
        Prodaja **pok;
        int broj_prodaja;
        int max;
        bool UporediDatume(const Datum &d1,const Datum &d2) const{
            if(d1.DajGodinu()>d2.DajGodinu())return true;
            if(d1.DajGodinu()==d2.DajGodinu()){
                if(d1.DajMjesec()>d2.DajMjesec())return true;
                if(d1.DajMjesec()==d2.DajMjesec()){
                    if(d1.DajDan()>d2.DajDan())return true;
                    return false;
                }
                return false;
            }
            return false;
        }
    public:
        explicit Prodaje(int max_broj_prodaja):pok(new Prodaja*[max_broj_prodaja]{}),broj_prodaja(0),max(max_broj_prodaja){}
        Prodaje(std::initializer_list<Prodaja> spisak_prodaja):pok(new Prodaja*[spisak_prodaja.size()]{}),broj_prodaja(spisak_prodaja.size()),max(spisak_prodaja.size()){
            int j(0);
            for(auto i=spisak_prodaja.begin();i!=spisak_prodaja.end();i++){
                try{
                    pok[j]=new Prodaja(*i);
                }
                catch(...){
                    for(int i=0;i<max;i++){
                        delete pok[i];
                        pok[i]=nullptr;
                    }
                    delete [] pok;
                    throw;
                }
                j++;
            }
        }
        ~Prodaje(){
            for(int i=0;i<max;i++) {
                delete pok[i];
                pok[i]=nullptr;
            }
            delete [] pok;
        }
        Prodaje(const Prodaje &prodaje);
        Prodaje(Prodaje &&prodaje):pok(prodaje.pok),broj_prodaja(prodaje.broj_prodaja){
            prodaje.pok=nullptr; prodaje.broj_prodaja=0;
        }
        Prodaje &operator =(const Prodaje &prodaje);
        Prodaje &operator =(Prodaje &&prodaje){
            std::swap(broj_prodaja,prodaje.broj_prodaja);
            std::swap(pok,prodaje.pok);
            return *this;
        }
        void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan){
            int flag(0);
            try{ 
                for(int i=0;i<max;i++){
                    if(pok[i]==nullptr){
                        pok[i]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
                        broj_prodaja++;
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    throw std::range_error("Dostignut maksimalan broj prodaja");
                }
            }
            catch(...){
                throw;
            }
        }
        void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
            int flag(0);
            try{ 
                for(int i=0;i<max;i++){
                    if(pok[i]==nullptr){
                        pok[i]=new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
                        broj_prodaja++;
                        flag=1;
                        break;
                    }
                }
                if(!flag)throw std::range_error("Dostignut maksimalan broj prodaja");
            }
            catch(...){
                throw;
            }
        }
        void RegistrirajProdaju(Prodaja *prodaja){
            int flag(0);
            for(int i=0;i<max;i++){
                if(pok[i]==nullptr){
                    pok[i]=prodaja;
                    broj_prodaja++;
                    flag=1;
                    break;
                }    
            }
            if(!flag)throw std::range_error("Dostignut maksimalan broj prodaja");
        }
        int DajBrojProdaja() const{ return broj_prodaja;}
        int DajBrojProdajaNaDatum(const Datum &datum) const { return std::count_if(pok,pok+broj_prodaja,[datum](Prodaja *p){ if(datum.DajDan()==p->DajDatumProdaje().DajDan() && datum.DajMjesec()==p->DajDatumProdaje().DajMjesec() && datum.DajGodinu()==p->DajDatumProdaje().DajGodinu())return true; else return false; }); }
        int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const { return std::count_if(pok,pok+broj_prodaja,[ime_agenta](Prodaja *p){ if(ime_agenta==p->DajImeAgenta())return true; else return false; }); }
        Prodaja &DajNajranijuProdaju(){
            auto i=std::min_element(pok,pok+broj_prodaja,[=](Prodaja *d1,Prodaja *d2){
                return !UporediDatume(d1->DajDatumProdaje(),d2->DajDatumProdaje());
            });
            return **i;
        }
        Prodaja DajNajranijuProdaju() const{
            auto i=std::min_element(pok,pok+broj_prodaja,[=](Prodaja *d1,Prodaja *d2){
                return !UporediDatume(d1->DajDatumProdaje(),d2->DajDatumProdaje());
            });
            return **i;
        }
        Prodaja &DajNajskupljuProdaju(){
            auto i=std::max_element(pok,pok+broj_prodaja,[=](Prodaja *p1,Prodaja *p2){
                return p1->DajCijenuStana()>p2->DajCijenuStana();
            });
            return **i;
        }
        Prodaja DajNajskupljuProdaju() const{
            auto i=std::max_element(pok,pok+broj_prodaja,[=](Prodaja *p1,Prodaja *p2){
                return p1->DajCijenuStana()>p2->DajCijenuStana();
            });
            return **i;
        }
        void IsprazniKolekciju(){
            if(broj_prodaja==0)throw std::domain_error("Prazna kolekcija.");
            for(int i=0;i<max;i++){
                delete pok[i];
                pok[i]=nullptr;
            }
            broj_prodaja=0;
        }
        void ObrisiNajranijuProdaju(){
            auto i=std::min_element(pok,pok+broj_prodaja,[=](Prodaja *d1,Prodaja *d2){
                return !UporediDatume(d1->DajDatumProdaje(),d2->DajDatumProdaje());
            });
            broj_prodaja--;
            delete *i;
            *i=nullptr;
        }
        void ObrisiProdajeAgenta(const std::string &ime_agenta){
            int br(0);
            for(int i=0;i<broj_prodaja;i++){
                if(pok[i]->DajImeAgenta()==ime_agenta){
                    delete pok[i];
                    br++;
                    pok[i]=nullptr;
                }    
            }
            broj_prodaja-=br;
        }
        void ObrisiProdajeNaDatum(const Datum &datum){
            int br(0);
            for(int i=0;i<broj_prodaja;i++){
                if(datum.DajDan()==pok[i]->DajDatumProdaje().DajDan() && datum.DajMjesec()==pok[i]->DajDatumProdaje().DajMjesec() && datum.DajGodinu()==pok[i]->DajDatumProdaje().DajGodinu()){
                    delete pok[i];
                    br++;
                    pok[i]=nullptr;
                }
            }
            broj_prodaja-=br;
        }
        void IspisiProdajeNaDatum(const Datum &datum) const {
            std::vector<int> v;
            for(int i=0;i<broj_prodaja;i++){
                if(datum.DajDan()==pok[i]->DajDatumProdaje().DajDan() && datum.DajMjesec()==pok[i]->DajDatumProdaje().DajMjesec() && datum.DajGodinu()==pok[i]->DajDatumProdaje().DajGodinu()){
                    v.push_back(i);
                }
            }
            std::sort(v.begin(),v.end(),[=](int i1,int i2){return UporediDatume(pok[i1]->DajDatumProdaje(),pok[i2]->DajDatumProdaje());});
            for(int i=0;i<v.size();i++) pok[v[i]]->Ispisi();
        }
        void IspisiSveProdaje() const {
            std::sort(pok,pok+broj_prodaja,[=](Prodaja *p1,Prodaja *p2){
                if(p1->DajDatumProdaje().DajDan()==p2->DajDatumProdaje().DajDan() && p1->DajDatumProdaje().DajMjesec()==p2->DajDatumProdaje().DajMjesec() && p1->DajDatumProdaje().DajGodinu()==p2->DajDatumProdaje().DajGodinu()){
                    return p1->DajImeKupca()<p2->DajImeKupca();
                }
                return !UporediDatume(p1->DajDatumProdaje(),p2->DajDatumProdaje());
            });
            for(int i=0;i<broj_prodaja;i++){
                pok[i]->Ispisi();
                std::cout << std::endl;
            }
        }
        Prodaja &DajProdaju(int broj_prodaje){
            return *pok[broj_prodaje-1];
        }
};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Prodaje::Prodaje(const Prodaje &prodaje):pok(new Prodaja*[prodaje.broj_prodaja]),broj_prodaja(prodaje.broj_prodaja){
    try{
        for(int i=0;i<broj_prodaja;i++){
            pok[i]=new Prodaja(*prodaje.pok[i]);
        }
    }
    catch(...){
        for(int i=0;i<max;i++){
            delete pok[i];
            pok[i]=nullptr;
        }
        delete [] pok;
        throw;
    }
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje){
    if(prodaje.broj_prodaja>broj_prodaja){
        try{
            for(int i=broj_prodaja;i<prodaje.broj_prodaja;i++) pok[i]=new Prodaja(*prodaje.pok[i]);
        }
        catch(...){
            for(int i=broj_prodaja;i<prodaje.broj_prodaja;i++) {
                delete pok[i];
                pok[i]=nullptr;
            }    
        }
    }
    else {
        for(int i=prodaje.broj_prodaja;i<broj_prodaja;i++){
            delete pok[i];
            pok[i]=nullptr;
        }
    }
    broj_prodaja=prodaje.broj_prodaja;
    for(int i=0;i<broj_prodaja;i++) *pok[i]=*prodaje.pok[i];
    return *this;
}
    


bool PorediDatume(const Datum &d1,const Datum &d2){
    if(d1.DajGodinu()>d2.DajGodinu())return false;
    if(d1.DajGodinu()==d2.DajGodinu()){
        if(d1.DajMjesec()>d2.DajMjesec())return false;
        if(d1.DajMjesec()==d2.DajMjesec()){
            if(d1.DajDan()>d2.DajDan())return false;
            return true;
        }
        return true;
    }
    return true;
}

bool ProdatPrije(const Prodaja &p1,const Prodaja &p2){
    return PorediDatume(p1.DajDatumProdaje(),p2.DajDatumProdaje());
}

bool SkupljiStan(const Prodaja &p1,const Prodaja &p2){
    return p1.DajCijenuStana() > p2.DajCijenuStana(); 
}

int main ()
{
    std::cout << "Dobrodosli!" << std::endl;
    int a;
    std::vector <Stan> stanovi;
    std::vector <Kupac> kupci;
    Prodaje SPISAK_PRODAJA(20);
    
    std::cout << std::endl << std::endl;
    
    do{
    
    std::cout << "Izaberite opciju:" << std::endl;
    
    std::cout << " 0 - kraj" << std::endl;
    std::cout << " 1 - uredjivanje stanova" << std::endl;
    std::cout << " 2 - uredjivanje kupaca" << std::endl;
    std::cout << " 3 - uredjivanje prodaja" << std::endl;
    
    std::cin >> a ;
        
       
        //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        if(a==1){ 
            int b;
            do{
                std::cout << "Izaberite opciju:" << std::endl;
    
                std::cout << " 0 - nazad" << std::endl;
                std::cout << " 1 - dodavanje stana" << std::endl;
                std::cout << " 2 - uredjivanje stanova" << std::endl;
                std::cout << " 3 - ispis svih stanova" << std::endl;
                std::cout << " 4 - kraj" << std::endl;
            
                std::cin >> b ;
                
                if(b==1){
                    for(int i=0;i<1;i++){
                        std::string adresa;
                        std::cout << "Unesite adresu: ";
                        std::cin.ignore(100,'\n');
                        std::getline(std::cin,adresa);
                        
                            int sprat;
                            std::cout << "Unesite sprat: ";
                            std::cin >> sprat;
                                
                                int broj_soba;
                                std::cout << "Unesite broj soba: ";
                                std::cin >> broj_soba;
                                
                                    bool x;int flag(0),c;
                                    std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                    std::cin >> c;
                                    if(c==1 || c==0)x=c;
                                    else flag=1;
                                    
                                        double kvadratura;
                                        std::cout << "Unesite kvadraturu: ";
                                        std::cin >> kvadratura;
                                        
                                            try{
                                                if(flag)throw std::domain_error("Neispravan unos podataka");
                                                Stan s(adresa,sprat,broj_soba,x,kvadratura);
                                                stanovi.push_back(s);
                                                std::cout << "Stan je uspjesno dodan!" << std::endl; 
                                                std::cout << std::endl ;
                                            }
                                            catch(std::domain_error e){
                                                std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                                i--;
                                            }
                    }
                }
                else if(b==2){
                    std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                    for(int i=0;i<stanovi.size();i++){
                        std::cout << " " << i+1 << " - ";
                        stanovi[i].Ispisi();
                    }
                    std::cout << std::endl ;
                    
                        int x;
                        std::cin >> x ;
                        int x1;
                            
                            std::cout << "Odaberite polje koje zelite urediti:" << std::endl;
                            
                            std::cout << " 0 - nazad" << std::endl;
                            std::cout << " 1 - adresa" << std::endl;
                            std::cout << " 2 - sprat" << std::endl;
                            std::cout << " 3 - broj soba" << std::endl;
                            std::cout << " 4 - da li je stan namjesten" << std::endl;
                            std::cout << " 5 - kvadratura" << std::endl;
                            std::cout << " 6 - sve" << std::endl;
                            
                            std::cin >> x1;
                            
                                    if(x1==1){
                                        for(int i=0;i<1;i++){
                                            std::string adresa;
                                            std::cout << "Unesite adresu: ";
                                            std::cin.ignore(100,'\n');
                                            std::getline(std::cin,adresa);
                                                try{
                                                    stanovi[x-1]=Stan(adresa,stanovi[x-1].DajSprat(),stanovi[x-1].DajBrojSoba(),stanovi[x-1].DajNamjesten(),stanovi[x-1].DajKvadraturu());
                                                    std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                                    std::cout << std::endl ;
                                                }
                                                catch(std::domain_error e){
                                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                                    i--;
                                                }
                                        }        
                                    }
                                    else if(x1==2){
                                        for(int i=0;i<1;i++){
                                            int sprat;
                                            std::cout << "Unesite sprat: ";
                                            std::cin >> sprat;
                                                try{
                                                    stanovi[x-1]=Stan(stanovi[x-1].DajAdresu(),sprat,stanovi[x-1].DajBrojSoba(),stanovi[x-1].DajNamjesten(),stanovi[x-1].DajKvadraturu());
                                                    std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                                    std::cout << std::endl ;
                                                }
                                                catch(std::domain_error e){
                                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                                    i--;
                                                }
                                        }        
                                    }
                                    else if(x1==3){
                                        for(int i=0;i<1;i++){
                                            int broj_soba;
                                            std::cout << "Unesite broj soba: ";
                                            std::cin >> broj_soba;
                                                try{
                                                    stanovi[x-1]=Stan(stanovi[x-1].DajAdresu(),stanovi[x-1].DajSprat(),broj_soba,stanovi[x-1].DajNamjesten(),stanovi[x-1].DajKvadraturu());
                                                    std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                                    std::cout << std::endl ;
                                                }
                                                catch(std::domain_error e){
                                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                                    i--;
                                                }
                                        }        
                                    }
                                    else if(x1==4){
                                        for(int i=0;i<1;i++){
                                            bool x;int flag(0),c;
                                            std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                            std::cin >> c;
                                            if(c==1 || c==0)x=c;
                                            else flag=1;
                                                try{
                                                    if(flag)throw std::domain_error("Neispravan unos");
                                                    stanovi[x-1]=Stan(stanovi[x-1].DajAdresu(),stanovi[x-1].DajSprat(),stanovi[x-1].DajBrojSoba(),x,stanovi[x-1].DajKvadraturu());
                                                    std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                                    std::cout << std::endl ;
                                                }
                                                catch(std::domain_error e){
                                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                                    i--;
                                                }
                                        }        
                                    }
                                    else if(x1==5){
                                        for(int i=0;i<1;i++){
                                            double kvadratura;
                                            std::cout << "Unesite kvadraturu: ";
                                            std::cin >> kvadratura;
                                                try{
                                                    stanovi[x-1]=Stan(stanovi[x-1].DajAdresu(),stanovi[x-1].DajSprat(),stanovi[x-1].DajBrojSoba(),stanovi[x-1].DajNamjesten(),kvadratura);
                                                    std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                                    std::cout << std::endl ;
                                                }
                                                catch(std::domain_error e){
                                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                                    i--;
                                                }
                                        }        
                                    }
                                    else if(x1==6){
                                        for(int i=0;i<1;i++){
                                            std::string adresa;
                                            std::cout << "Unesite adresu: ";
                                            std::cin.ignore(100,'\n');
                                            std::getline(std::cin,adresa);
                        
                                                int sprat;
                                                std::cout << "Unesite sprat: ";
                                                std::cin >> sprat;
                                
                                                    int broj_soba;
                                                    std::cout << "Unesite broj soba: ";
                                                    std::cin >> broj_soba;
                                
                                                        bool x;int flag(0),c;
                                                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                                        std::cin >> c;
                                                        if(c==1 || c==0)x=c;
                                                        else flag=1;
                                    
                                                            double kvadratura;
                                                            std::cout << "Unesite kvadraturu: ";
                                                            std::cin >> kvadratura;
                                        
                                                                try{
                                                                    if(flag)throw std::domain_error("Neispravan unos");
                                                                    stanovi[x-1]= Stan(adresa,sprat,broj_soba,x,kvadratura);
                                                                    std::cout << "Stan je uspjesno izmijenjen!" << std::endl; 
                                                                    std::cout << std::endl ;
                                                                }
                                                                catch(std::domain_error e){
                                                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                                                    i--;
                                                                }
                                        }
                                    }
                           
                }
                else if(b==3){
                    for(int i=0;i<stanovi.size();i++){
                        std::cout << i+1 << ". ";
                        stanovi[i].Ispisi();
                    }
                    std::cout << std::endl ;
                }
                else if(b==4){
                    return 0;
                }
                
            }while(b!=0);    
        
         //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        }
        else if(a==2){
            int b;
            do{
                std::cout << "Izaberite opciju:" << std::endl;
    
                std::cout << " 0 - nazad" << std::endl;
                std::cout << " 1 - dodavanje kupca" << std::endl;
                std::cout << " 2 - uredjivanje kupaca" << std::endl;
                std::cout << " 3 - ispis svih kupaca" << std::endl;
                std::cout << " 4 - kraj" << std::endl;
            
                std::cin >> b ;
                
                if(b==1){
                    for(int i=0;i<1;i++){
                        
                        std::string ime;
                        std::cout << "Unesite ime i prezime kupca: " ;
                        std::cin.ignore(100,'\n');
                        std::getline(std::cin,ime);
                        
                            int d,m,g;
                            char z;
                            std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                            std::cin >> d >> z >> m >> z >> g ;
                            
                            try{
                                Kupac k(ime,Datum(d,m,g));
                                kupci.push_back(k);
                                std::cout << "Kupac je uspjesno dodan!" << std::endl;
                                std::cout << std::endl ;
                            }
                            catch(std::domain_error e){
                                std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet."<<std::endl;
                                i--;
                            }
                    }
                }
                else if(b==2){
                    int x1;
                    std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:" << std::endl;
                    
                        for(int i=0;i<kupci.size();i++){
                            std::cout << " " << i+1 << " - ";
                            kupci[i].Ispisi();
                            std::cout << std::endl;
                        }
                          
                            std::cin >> x1;
                            
                                for(int i=0;i<1;i++){
                        
                                    std::string ime;
                                    std::cout << "Unesite ime i prezime kupca: " ;
                                    std::cin.ignore(100,'\n');
                                    std::getline(std::cin,ime);
                        
                                        int d,m,g;
                                        char z;
                                        std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                                        std::cin >> d >> z >> m >> z >> g ;
                            
                                        try{
                                            kupci[x1-1]=Kupac(ime,Datum(d,m,g));
                                            std::cout << "Kupac je uspjesno izmijenjen!" << std::endl;
                                            std::cout << std::endl;
                                        }
                                        catch(std::domain_error e){
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet."<<std::endl;
                                            i--;
                                        }
                                }
                }
                else if(b==3){
                    for(int i=0;i<kupci.size();i++){
                        kupci[i].Ispisi();
                        std::cout << std::endl;
                    }
                    std::cout << std::endl ;
                }
                else if(b==4){
                    return 0;
                }
            }while(b!=0);    
        }
        //------------------------------------------------------------------------------------------------------------------------------------------------------------
        else if(a==3){
            int b;
                do{
                    std::cout << "Izaberite opciju:" << std::endl;
            
                    std::cout << " 0 - nazad" << std::endl;
                    std::cout << " 1 - dodavanje prodaje" << std::endl;
                    std::cout << " 2 - uredjivanje prodaje" << std::endl;
                    std::cout << " 3 - ispis prodaja" << std::endl;
                    std::cout << " 4 - brisanje prodaja" << std::endl;
                    std::cout << " 5 - kraj" << std::endl;
                    
                    std::cin >> b;
                    
                        if(b==1){
                           
                            int x;
                            do{
                                std::cout << "Izaberite opciju:" << std::endl;
                               
                                std::cout << " 0 - nazad" << std::endl;
                                std::cout << " 1 - dodavanje potpuno nove prodaje" << std::endl;
                                std::cout << " 2 - dodavanje nove prodaje na osnovu arhive" << std::endl;
                                std::cout << " 3 - kraj" << std::endl;
                               
                                std::cin >> x ;
                               
                                    if(x==1){
                                        for(int i=0;i<1;i++){
                                            
                                            std::string ime_agenta;
                                            std::cout << "Unesite ime i prezime agenta prodaje: ";
                                            std::cin.ignore(100,'\n');
                                            std::getline(std::cin,ime_agenta);
                                            
                                                int d,m,g;
                                                char z;
                                                std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                                std::cin >> d >> z >> m >> z >> g ;
                                                
                                                    int cijena;
                                                    std::cout << "Unesite cijenu stana: ";
                                                    std::cin >> cijena;
                                                    
                                                        std::string ime_kupca;
                                                        std::cout << "Unesite ime kupca: ";
                                                        std::cin.ignore(100,'\n');
                                                        std::getline(std::cin,ime_kupca);
                                                        
                                                            int d1,m1,g1;
                                                            char z1;
                                                            std::cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                                                            std::cin >> d1 >> z1 >> m1 >> z1 >> g1;
                                                            
                                                                std::string adresa;
                                                                std::cout << "Unesite adresu: ";
                                                                std::cin.ignore(100,'\n');
                                                                std::getline(std::cin,adresa);
                                                                
                                                                    int sprat;
                                                                    std::cout << "Unesite sprat: ";
                                                                    std::cin >> sprat;
                                                                    
                                                                        int broj_soba;
                                                                        std::cout << "Unesite broj soba: ";
                                                                        std::cin >> broj_soba;
                                                                        
                                                                            bool n;int flag(0),c;
                                                                            std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                                                            std::cin >> c;
                                                                            if(c==1 || c==0)n=c;
                                                                            else flag=1;
                                                                            
                                                                                double kvadratura;
                                                                                std::cout << "Unesite kvadraturu: ";
                                                                                std::cin >> kvadratura;
                                                                                
                                                                                    try{
                                                                                        if(flag)throw std::domain_error("Neispravan unos");
                                                                                        kupci.push_back(Kupac(ime_kupca,Datum(d1,m1,g1)));
                                                                                        stanovi.push_back(Stan(adresa,sprat,broj_soba,n,kvadratura));
                                                                                        SPISAK_PRODAJA.RegistrirajProdaju(ime_agenta,cijena,d,m,g,ime_kupca,Datum(d1,m1,g1),adresa,sprat,broj_soba,n,kvadratura);
                                                                                        std::cout << "Prodaja uspjesno dodana!" << std::endl;
                                                                                        std::cout << std::endl;
                                                                                    }
                                                                                    catch(std::range_error e){
                                                                                        std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                                                                        i--;
                                                                                    }
                                                                                    catch(std::domain_error e){
                                                                                        std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                                                                        i--;
                                                                                    }
                                        }    
                                    }
                                    else if(x==2){
                                        
                                        for(int i=0;i<1;i++){
                                            
                                            std::string ime_agenta;
                                            std::cout << "Unesite ime i prezime agenta prodaje: ";
                                            std::cin.ignore(100,'\n');
                                            std::getline(std::cin,ime_agenta);
                                           
                                                int d,m,g;
                                                char z;
                                                std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                                std::cin >> d >> z >> m >> z >> g ;
                                                
                                                    int cijena;
                                                    std::cout << "Unesite cijenu stana: ";
                                                    std::cin >> cijena;
                                                    
                                                        std::cout << "Odaberite kupca. Dostupni kupci su:" << std::endl;
                                                        
                                                        for(int j=0;j<kupci.size();j++){
                                                            std::cout << " " << j+1 << " - ";
                                                            kupci[j].Ispisi();
                                                            std::cout << std::endl;
                                                        }
                                                        
                                                        int k;
                                                        std::cin >> k;
                                                        
                                                            std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                                                            
                                                            for(int j=0;j<stanovi.size();j++){
                                                                std::cout << " " << j+1 << " - ";
                                                                stanovi[j].Ispisi();
                                                            }
                                                            
                                                            int s;
                                                            std::cin >> s;
                                                            
                                                                try{
                                                                    SPISAK_PRODAJA.RegistrirajProdaju(ime_agenta,cijena,Datum(d,m,g),kupci[k-1],stanovi[s-1]);
                                                                    std::cout << "Prodaja uspjesno dodana!" << std::endl;
                                                                     std::cout << std::endl;
                                                                }
                                                                catch(std::range_error e){
                                                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                                                    i--;
                                                                }
                                                                catch(std::domain_error e){
                                                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                                                    i--;
                                                                }
                                        }
                                    }
                                    else if(x==3){
                                        return 0;
                                    }
                            }while(x!=0);
                        }
                       
                        else if(b==2){
                            
                            std::cout << "Odaberite prodaju koju želite urediti. Dostupne prodaje su:" << std::endl;
                            
                            for(int i=0;i<SPISAK_PRODAJA.DajBrojProdaja();i++){
                                std::cout << i+1 << "." << std::endl;
                                SPISAK_PRODAJA.DajProdaju(i+1).Ispisi();
                                std::cout << std::endl;
                            }
                            
                            int x;
                            std::cin >> x ;
                            
                                std::cout << "Izaberite opciju:" << std::endl;
                                
                                std::cout << " 0 - nazad" << std::endl;
                                std::cout << " 1 - izmjena agenta" << std::endl;
                                std::cout << " 2 - izmjena datuma prodaje" << std::endl;
                                std::cout << " 3 - izmjena kupca" << std::endl;
                                std::cout << " 4 - izmjena stana" << std::endl;
                                std::cout << " 5 - izmjena cijene stana" << std::endl;
                                
                                int x1;
                                std::cin >> x1;
                                
                                    if(x1==1){
                                        for(int i=0;i<1;i++){
                                            std::string ime_agenta;
                                            std::cout << "Unesite ime i prezime agenta prodaje: ";
                                            std::cin.ignore(100,'\n');
                                            std::getline(std::cin,ime_agenta);
                                        
                                                try{
                                                    SPISAK_PRODAJA.DajProdaju(x).PromijeniAgenta(ime_agenta);
                                                    std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                                                    std::cout << std::endl ;
                                                }
                                                catch(std::domain_error e){
                                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                                    i--;
                                                }
                                        }        
                                    }
                                    else if(x1==2){
                                        for(int i=0;i<1;i++){
                                            int d,m,g;
                                            char z;
                                            std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                            std::cin >> d >> z >> m >> z >> g ;
                                            
                                                try{
                                                    SPISAK_PRODAJA.DajProdaju(x).PromijeniDatumKupovine(Datum(d,m,g));
                                                    std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                                                    std::cout << std::endl ;
                                                }
                                                catch(std::domain_error e){
                                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                                    i--;
                                                }
                                        }
                                    }
                                    else if(x1==3){
                                        std::cout << "Izaberite opciju:" << std::endl;
                                        
                                        std::cout << " 0 - nazad" << std::endl;
                                        std::cout << " 1 - odabir postojeceg kupca" << std::endl;
                                        std::cout << " 2 - dodavanje novog kupca" << std::endl;
                                        
                                        int x2;
                                        std::cin >> x2;
                                            
                                            if(x2==1){
                                                std::cout << "Odaberite kupca. Dostupni kupci su:" << std::endl;
                                                for(int i=0;i<kupci.size();i++){
                                                    std::cout << " " << i+1 << " - ";
                                                    kupci[i].Ispisi();
                                                    std::cout << std::endl;
                                                }
                                                int k;
                                                std::cin>> k;
                                                    
                                                    try{
                                                        SPISAK_PRODAJA.DajProdaju(x).PromijeniKupca(kupci[k-1]);
                                                        std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                                                        std::cout << std::endl;
                                                    }
                                                    catch(std::domain_error e){
                                                        std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                                    }
                                            }
                                            else if(x2==2){
                                                for(int i=0;i<1;i++){
                                                std::string ime;
                                                std::cout << "Unesite ime i prezime kupca: " ;
                                                std::cin.ignore(100,'\n');
                                                std::getline(std::cin,ime);
                        
                                                    int d,m,g;
                                                    char z;
                                                    std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                                                    std::cin >> d >> z >> m >> z >> g ;
                                                    
                                                    try{
                                                        SPISAK_PRODAJA.DajProdaju(x).PromijeniKupca(Kupac(ime,Datum(d,m,g)));
                                                        kupci.push_back(Kupac(ime,Datum(d,m,g)));
                                                        std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl; 
                                                    }
                                                    catch(std::domain_error e){
                                                        std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                                        i--;
                                                    }
                                                }    
                                            }
                                    }
                                    else if(x1==4){
                                        std::cout << "Izaberite opciju:" << std::endl;
                                        
                                        std::cout << " 0 - nazad" << std::endl;
                                        std::cout << " 1 - odabir postojeceg stana" << std::endl;
                                        std::cout << " 2 - dodavanje novog stana" << std::endl;
                                        
                                        int x2;
                                        std::cin >> x2;
                                        
                                        if(x2==1){
                                            std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                                            
                                            for(int i=0;i<stanovi.size();i++){
                                                std::cout << " " << i+1 << " - ";
                                                stanovi[i].Ispisi();
                                                std::cout << std::endl;
                                            }
                                            
                                                int s;
                                                std::cin >> s;
                                                
                                                    try{
                                                        SPISAK_PRODAJA.DajProdaju(x).PromijeniStan(stanovi[s-1]);
                                                        std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                                                    }
                                                    catch(std::domain_error e){
                                                        std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                                    }
                                        }
                                        
                                        else if(x2==2){
                                            for(int i=0;i<1;i++){
                                                std::string adresa;
                                                std::cout << "Unesite adresu: ";
                                                std::cin.ignore(100,'\n');
                                                std::getline(std::cin,adresa);
                                                                
                                                    int sprat;
                                                    std::cout << "Unesite sprat: ";
                                                    std::cin >> sprat;
                                                                    
                                                        int broj_soba;
                                                        std::cout << "Unesite broj soba: ";
                                                        std::cin >> broj_soba;
                                                                        
                                                            bool n;int flag(0),c;
                                                            std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                                            std::cin >> c;
                                                            if(c==1 || c==0)n=c;
                                                            else flag=1;
                                                                                                
                                                                            
                                                                double kvadratura;
                                                                std::cout << "Unesite kvadraturu: ";
                                                                std::cin >> kvadratura;
                                                            
                                                                    try{
                                                                        if(flag)throw std::domain_error("Neispravan unos");
                                                                        SPISAK_PRODAJA.DajProdaju(x).PromijeniStan(Stan(adresa,sprat,broj_soba,n,kvadratura));
                                                                        std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                                                                    }
                                                                    catch(std::domain_error e){
                                                                        std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                                                        i--;
                                                                    }
                                            }
                                        }
                                    }
                                    else if(x1==5){
                                    for(int i=0;i<1;i++){    
                                            int cijena;
                                            std::cout << "Unesite cijenu stana: ";
                                            std::cin >> cijena;
                                            
                                                try{
                                                    SPISAK_PRODAJA.DajProdaju(x).PromijeniCijenuProdaje(cijena);
                                                    std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                                                }
                                                catch(std::domain_error e){
                                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                                    i--;
                                                }
                                        } 
                                    }
                        }
                        else if(b==3){
                            int x1;
                            do{
                            std::cout << "Izaberite opciju:" << std::endl;
                            
                            std::cout << " 0 - nazad" << std::endl;
                            std::cout << " 1 - ispis svih prodaja" << std::endl;
                            std::cout << " 2 - ispis prodaja na datum" << std::endl;
                            std::cout << " 3 - ispis najranije prodaje" << std::endl;
                            std::cout << " 4 - ispis najskuplje prodaje" << std::endl;
                            std::cout << " 5 - ispis broja prodaja" << std::endl;
                            std::cout << " 6 - ispis broja prodaja po datumu" << std::endl;
                            std::cout << " 7 - ispis broja prodaja po agentu" << std::endl;
                            std::cout << " 8 - kraj" << std::endl;
                            
                    
                                std::cin >> x1 ;
                                
                                if(x1==1){
                                    SPISAK_PRODAJA.IspisiSveProdaje();
                                }
                                else if(x1==2){
                                    for(int i=0;i<1;i++){
                                        int d,m,g;
                                        char z;
                                        std::cout << "Unesite datum (d/m/g): " ;
                                        std::cin >> d >> z >> m >> z >> g ;
                                        
                                        try{
                                            std::cout << "Prodaje na datum";
                                            Datum(d,m,g).Ispisi() ;
                                            std::cout << " su: " << std::endl;
                                            SPISAK_PRODAJA.IspisiProdajeNaDatum(Datum(d,m,g));
                                        }
                                        catch(std::domain_error e){
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                            i--;
                                        }
                                    }
                                }
                                else if(x1==3){
                                    SPISAK_PRODAJA.DajNajranijuProdaju().Ispisi();
                                }
                                else if(x1==4){
                                    SPISAK_PRODAJA.DajNajskupljuProdaju().Ispisi();
                                }    
                                else if(x1==5){
                                    std::cout << "Broj prodaja: "   << SPISAK_PRODAJA.DajBrojProdaja() << std::endl;                              
                                }
                                else if(x1==6){
                                    for(int i=0;i<1;i++){
                                        int d,m,g;
                                        char z;
                                        std::cout << "Unesite datum (d/m/g): " ;
                                        std::cin >> d >> z >> m >> z >> g ;
                                        
                                        try{
                                            std::cout << "Broj prodaja na uneseni datum: " << SPISAK_PRODAJA.DajBrojProdajaNaDatum(Datum (d,m,g)) << std::endl;
                                        }
                                        catch(std::domain_error e){
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                            i--;
                                        }
                                    }
                                }
                                else if(x1==7){
                                    for(int i=0;i<1;i++){
                                        std::string ime;
                                        std::cout << "Unesite ime agenta: " ;
                                        std::cin.ignore(10,'\n');
                                        std::getline(std::cin,ime);
                                        
                                        try{
                                            std::cout << "Broj prodaja unesenog agenta: " << SPISAK_PRODAJA.DajBrojProdajaOdAgenta(ime) << std::endl;
                                        }
                                        catch(std::domain_error e){
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                            i--;
                                        }
                                    }
                                }
                                else if(x1==8){
                                    return 0;
                                }    
                            }while(x1!=0);
                        }
                        else if(b==4){
                            int x1;
                            do{
                            std::cout << "Izaberite opciju:" << std::endl;
                            
                            std::cout << " 0 - nazad" << std::endl;
                            std::cout << " 1 - brisanje najranije prodaje" << std::endl;
                            std::cout << " 2 - brisanje prodaja agenta" << std::endl;
                            std::cout << " 3 - brisanje prodaja po datumu" << std::endl;
                            std::cout << " 4 - brisanje svih prodaja" << std::endl;
                            
                                std::cin >> x1;
                                
                                if(x1==1){
                                    if(SPISAK_PRODAJA.DajBrojProdaja()==0)std::cout << "Najranija prodaja je obrisana!" << std::endl;
                                    else {
                                        SPISAK_PRODAJA.ObrisiNajranijuProdaju();
                                        std::cout << "Najranija prodaja je obrisana!" << std::endl;
                                    }    
                                }
                                else if(x1==2){
                                    for(int i=0;i<1;i++){
                                        std::string ime;
                                        std::cout << "Unesite ime agenta: " ;
                                        std::cin.ignore(10,'\n');
                                        std::getline(std::cin,ime);
                                        
                                        try{
                                            if(SPISAK_PRODAJA.DajBrojProdajaOdAgenta(ime)==0)std::cout << "Sve prodaje tog agenta su obrisane." <<std::endl;
                                            else SPISAK_PRODAJA.ObrisiProdajeAgenta(ime);
                                        }
                                        catch(std::domain_error e){
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                            i--;
                                        }
                                    }
                                }
                                else if(x1==3){
                                    for(int i=0;i<1;i++){
                                        int d,m,g;
                                        char z;
                                        std::cout << "Unesite datum (d/m/g): " ;
                                        std::cin >> d >> z >> m >> z >> g ;
                                        
                                        try{
                                            if(SPISAK_PRODAJA.DajBrojProdajaNaDatum(Datum (d,m,g))==0)std::cout << "Sve prodaje na taj datum su obrisane." << std::endl;
                                            else SPISAK_PRODAJA.ObrisiProdajeNaDatum(Datum (d,m,g));
                                        }
                                        catch(std::domain_error e){
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite ponovo." << std::endl;
                                            i--;
                                        }
                                    }
                                }
                                else if(x1==4){
                                    try{
                                        SPISAK_PRODAJA.IsprazniKolekciju();
                                        std::cout << "Sve prodaje su obrisane." << std::endl;
                                    }
                                    catch(std::domain_error e){
                                        std::cout << "Izuzetak: " << e.what() << std::endl;
                                    }
                                }
                            
                            }while(x1!=0);
                            
                            
                        }
                        else if(b==5){
                            return 0;
                        }
                }while(b!=0);    
        }
        
    }while(a!=0); 
    
    std::cout <<std::endl << "Dovidjenja!" << std::endl;
 	return 0;
}