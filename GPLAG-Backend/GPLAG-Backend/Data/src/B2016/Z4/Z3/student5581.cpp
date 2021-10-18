/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <vector>
#include <algorithm>

bool LegalnoIme(std::string ime){
    for(int i=0;i<ime.size();i++){
        if(!((ime[i]>='a'&&ime[i]<='z')||(ime[i]>='A'&&ime[i]<='Z')||ime[i]==' '||ime[i]=='-'||ime[i]=='\''||(ime[i]>='0'&&ime[i]<='9')))
            return false;
    }
    return true;
}
class Datum {
    private:
        int dan, mjesec, godina;
    public:
        Datum(int dan, int mjesec, int godina){Postavi(dan, mjesec,godina);}
        void Postavi(int dan, int mjesec, int godina);//vani
        int DajDan() const {return dan;}
        int DajMjesec() const {return mjesec;}
        int DajGodinu() const {return godina;}
        void Ispisi() const {std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};
void Datum::Postavi(int dan, int mjesec, int godina){
    int dani[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0)
        dani[1]++;
    if(godina<1 || mjesec<1 || mjesec>12 || dan<1 || dan>dani[mjesec-1])
        throw std::domain_error("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}
    
class Kupac{
    private:
        friend bool LegalnoIme(std::string ime);
        std::string ime_i_prezime;
        Datum datum;
    public:
        Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):datum(datum_rodjenja){Postavi(ime_i_prezime,datum_rodjenja);}
        void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
        std::string DajImePrezime() const {return ime_i_prezime;}
        Datum DajDatumRodjenja() const {return datum;}
        void Ispisi() const {std::cout<<ime_i_prezime<<" (";datum.Ispisi();std::cout<<")";}
}; 
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
        if(!LegalnoIme(ime_i_prezime))
            throw std::domain_error("Neispravno ime i prezime");
    datum=datum_rodjenja; Kupac::ime_i_prezime=ime_i_prezime;
}

class Stan{
    private:
        std::string adresa;
        int sprat,broj_soba;
        bool namjesten;
        double kvadratura;
    public:
        Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);}
        void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura); //vani
        std::string DajAdresu() const {return adresa;}
        int DajBrojSoba() const {return broj_soba;}
        int DajSprat() const {return sprat;}
        bool DajNamjesten() const {return namjesten;}
        double DajKvadraturu() const {return kvadratura;}
        void Ispisi() const;
};
void Stan::Postavi (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if(broj_soba<0||sprat<0||kvadratura<0||!LegalnoIme(adresa))
        throw std::domain_error("Neispravan unos podataka");
    Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
}
void Stan::Ispisi() const {
    std::string sobe[]={"soba","sobu","sobe","sobe","sobe","soba","soba","soba","soba","soba"};
    if(broj_soba%100>10&&broj_soba%100<20) for(int i=0;i<10;i++) sobe[i]="soba";
    std::string n[]={"nije", "je"};
    std::cout<<"Stan se nalazi na adresi "<<adresa
    <<" na "<<sprat<<". spratu i ima "<<broj_soba<<" "<<sobe[broj_soba%10]
    <<". Kvadratura stana je "<<kvadratura<<" (m^2) i stan "<<n[int(namjesten)]<<" namjesten.";
}

class Prodaja{
    private:
        std::string ime_agenta_prodaje;
        double cijena_stana;
        Datum datum_prodaje;
        Kupac kupac_stana;
        Stan kupljeni_stan;
        friend bool LegalnoIme(std::string ime);
        
    public: 
        Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
        Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje,const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
        void PromijeniKupca(const Kupac &novi_kupac){kupac_stana=novi_kupac;}
        void PromijeniStan(const Stan &novi_stan){kupljeni_stan=novi_stan;}
        void PromijeniDatumKupovine(const Datum &novi_datum){datum_prodaje=novi_datum;}
        void PromijeniCijenuProdaje(const double &nova_cijena){if(nova_cijena<0) throw std::domain_error("Neispravan unos podataka"); cijena_stana=nova_cijena;}
        void PomjeriDanUnaprijed();
        void PomjeriDanUnazad();
        void PromijeniAgenta(const std::string &agent){ime_agenta_prodaje=agent;}
        std::string DajImeAgenta() const {return ime_agenta_prodaje;}
        std::string DajImeKupca() const {return kupac_stana.DajImePrezime();}
        Datum DajDatumProdaje() const {return datum_prodaje;}
        double DajCijenuStana() const {return cijena_stana;}
        friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
        friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
        void Ispisi() const;
};
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan):datum_prodaje(datum_prodaje),kupac_stana(kupac_stana),kupljeni_stan(kupljeni_stan){
    if(!LegalnoIme(ime_agenta_prodaje))
        throw std::domain_error("Neispravno ime i prezime");
    if(cijena_stana<0)
        throw std::domain_error("Neispravan unos podataka");
    Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),kupac_stana(ime_kupca,datum_rodjenja_kupca),kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){
    if(!LegalnoIme(ime_agenta_prodaje))
        throw std::domain_error("Neispravno ime i prezime");
    if(cijena_stana<0)
        throw std::domain_error("Neispravan unos podataka");
    Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana;
}
void Prodaja::PomjeriDanUnazad(){
    try{datum_prodaje=Datum(datum_prodaje.DajDan()-1,datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu());}
    catch(...){
        try{datum_prodaje=Datum(31,datum_prodaje.DajMjesec()-1,datum_prodaje.DajGodinu());}
        catch(...){
            try{datum_prodaje=Datum(30,datum_prodaje.DajMjesec()-1,datum_prodaje.DajGodinu());}
            catch(...){
                try{datum_prodaje=Datum(29,datum_prodaje.DajMjesec()-1,datum_prodaje.DajGodinu());}
                catch(...){
                    try{datum_prodaje=Datum(28,datum_prodaje.DajMjesec()-1,datum_prodaje.DajGodinu());}
                    catch(...){
                        try{datum_prodaje=Datum(31,12,datum_prodaje.DajGodinu()-1);}
                        catch(...)  {throw;}
                    }
                }
        
            }
        }
    }
}
void Prodaja::PomjeriDanUnaprijed(){
    try{datum_prodaje=Datum(datum_prodaje.DajDan()+1,datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu());}
    catch(...){
        try{datum_prodaje=Datum(1,datum_prodaje.DajMjesec()+1,datum_prodaje.DajGodinu());}
        catch(...){
            datum_prodaje=Datum(1,1,datum_prodaje.DajGodinu()+1);
        }
    }
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if(p1.datum_prodaje.DajGodinu()<p2.datum_prodaje.DajGodinu()) return true;
    else if(p1.datum_prodaje.DajGodinu()>p2.datum_prodaje.DajGodinu()) return false;
    else {
        if(p1.datum_prodaje.DajMjesec()<p2.datum_prodaje.DajMjesec()) return true;
        else if(p1.datum_prodaje.DajMjesec()>p2.datum_prodaje.DajMjesec()) return false;
        else {
            if(p1.datum_prodaje.DajDan()<p2.datum_prodaje.DajDan()) return true;
            else return false;
        }
    }
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    if(p1.DajCijenuStana()>p2.DajCijenuStana()) 
        return true;
    return false;
}
void Prodaja::Ispisi() const {
    std::cout<<std::left<<std::setw(32)<<"Ime agenta:"<<ime_agenta_prodaje<<std::endl;
    std::cout<<std::left<<std::setw(32)<<"Ime kupca:"; kupac_stana.Ispisi(); std::cout<<std::endl;
    std::cout<<std::left<<std::setw(32)<<"Zakazani datum prodaje: "; datum_prodaje.Ispisi(); std::cout<<std::endl;
    std::cout<<std::left<<std::setw(32)<<"Cijena stana:"<<cijena_stana<<std::endl;
    std::cout<<std::left<<std::setw(32)<<"Informacije o stanu: "<<std::endl;
    kupljeni_stan.Ispisi();
}

class Prodaje{
    private:
        int broj_prodaja;
        const int max_broj_prodaja;
        Prodaja** p_prodaje;
        
        static int Datumi(const Prodaja &p1, const Prodaja &p2){
        if(ProdatPrije(p1,p2)) return 1;
        else if(ProdatPrije(p2,p1)) return 3;
        else return 2;
    }
        friend bool JednakDatum(const Datum &d1, const Datum &d2);
    
    public:
        explicit Prodaje(int max_broj_prodaja);
        Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
        ~Prodaje();
        Prodaje(const Prodaje &prodaje);
        Prodaje(Prodaje &&prodaje);
        Prodaje &operator =(const Prodaje &prodaje);
        Prodaje &operator =(Prodaje &&prodaje);
        void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
        void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const  std::string &adresa_stana, int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata);
        void RegistrirajProdaju(Prodaja *prodaja);
        int DajBrojProdaja() const{return broj_prodaja;}
        int DajBrojProdajaNaDatum(const Datum &datum) const;
        int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
        Prodaja &DajNajranijuProdaju();
        Prodaja DajNajranijuProdaju() const;
        Prodaja &DajNajskupljuProdaju();
        Prodaja DajNajskupljuProdaju() const;
        Prodaja &DajProdaju(int redni_broj);
        void IsprazniKolekciju();
        void ObrisiNajranijuProdaju();
        void ObrisiProdajeAgenta(const std::string &ime_agenta);
        void ObrisiProdajeNaDatum(const Datum &datum);
        void IspisiProdajeNaDatum(const Datum &datum) const;
        void IspisiSveProdaje() const;
};
bool JednakDatum(const Datum &d1, const Datum &d2){
    return(d1.DajDan()==d2.DajDan()&&d1.DajMjesec()==d2.DajMjesec()&&d1.DajGodinu()==d2.DajGodinu());
}

Prodaje::Prodaje(int max_broj_prodaja):broj_prodaja(0),max_broj_prodaja(max_broj_prodaja),p_prodaje(new Prodaja*[max_broj_prodaja]{}){
}
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja):broj_prodaja(spisak_prodaja.size()),max_broj_prodaja(spisak_prodaja.size()){
    p_prodaje=new Prodaja*[max_broj_prodaja];
    std::fill(p_prodaje,p_prodaje+broj_prodaja,nullptr);
    auto it=spisak_prodaja.begin();
    int i=0;
    try{while(it!=spisak_prodaja.end()){
        p_prodaje[i]=new Prodaja(*it);
        i++;
        it++;
    }}
    catch(...){
        for(int i=0;i<max_broj_prodaja;i++)
            delete p_prodaje[i];
        delete[] p_prodaje;
        throw;
    }
}
Prodaje::~Prodaje(){
    if(p_prodaje){
    for(int i=0;i<broj_prodaja;i++)
        delete p_prodaje[i];
    delete[] p_prodaje;}
}
Prodaje::Prodaje(const Prodaje &prodaje): broj_prodaja(prodaje.broj_prodaja),max_broj_prodaja(prodaje.max_broj_prodaja),p_prodaje(new Prodaja* [prodaje.max_broj_prodaja]{}){
    try{
        for(int i=0 ; i<prodaje.broj_prodaja ; i++)
            p_prodaje[i] = new Prodaja(*prodaje.p_prodaje[i]);
    }
    catch(...){
        for(int i=0; i<prodaje.broj_prodaja;i++) delete p_prodaje[i];
        delete[] p_prodaje;
        throw;
    }
}
Prodaje::Prodaje(Prodaje &&prodaje):broj_prodaja(prodaje.broj_prodaja),max_broj_prodaja(prodaje.max_broj_prodaja),p_prodaje(prodaje.p_prodaje){
    prodaje.p_prodaje=nullptr; prodaje.broj_prodaja=0;
}
Prodaje &Prodaje::operator =(const Prodaje &prodaje){
    if(prodaje.max_broj_prodaja!=max_broj_prodaja){
        throw std::logic_error("Nesaglasan maksimalan broj prodaja!");
    }
    if(prodaje.broj_prodaja>broj_prodaja){
        try{
            for(int i = broj_prodaja; i<prodaje.broj_prodaja;i++){
                p_prodaje[i]= new Prodaja(*prodaje.p_prodaje[i]);
            }
        }
        catch(...) {
            for(int i=broj_prodaja ; i<prodaje.broj_prodaja ; i++){
                delete p_prodaje[i]; p_prodaje[i] = nullptr;
            }
            throw;
        }
    }
    else {
        for(int i=prodaje.broj_prodaja; i<broj_prodaja;i++){
            delete p_prodaje[i]; p_prodaje[i]=nullptr;
        }
    }
    broj_prodaja=prodaje.broj_prodaja;
    for(int i=0 ; i<broj_prodaja;i++)
        *p_prodaje[i]=*prodaje.p_prodaje[i];
    return *this;
}
Prodaje &Prodaje::operator =(Prodaje &&prodaje){
    if(prodaje.broj_prodaja!=broj_prodaja)
        throw std::logic_error("Nesaglasan maksimalan broj prodaja!");
    std::swap(broj_prodaja,prodaje.broj_prodaja);
    std::swap(p_prodaje,prodaje.p_prodaje);
    return *this;
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    return std::count_if(p_prodaje,p_prodaje+broj_prodaja,[datum](Prodaja* p){
        if(p && JednakDatum(datum,p->DajDatumProdaje())) return true;
            return false;
    });
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    return std::count_if(p_prodaje,p_prodaje+broj_prodaja,[ime_agenta](Prodaja* p){
        if(p && ime_agenta==p->DajImeAgenta())
            return true;
        return false;
    });
}
Prodaja &Prodaje::DajProdaju(int redni_broj){
    if(redni_broj>broj_prodaja)
        throw std::domain_error("Neispravan redni broj");
    return *p_prodaje[redni_broj-1];
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    int obrisano=0;
    for(int i=0;i<broj_prodaja;i++){
            if(p_prodaje[i]->DajImeAgenta()==ime_agenta){
                obrisano++;
                delete p_prodaje[i];
                p_prodaje[i]=nullptr;
            }
    }
    auto pok=std::remove(p_prodaje,p_prodaje+broj_prodaja,nullptr);
    std::fill(pok,p_prodaje+broj_prodaja,nullptr);
    broj_prodaja-=obrisano;
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    int obrisano=0;
    for(int i=0;i<broj_prodaja;i++){
            if(JednakDatum(datum,p_prodaje[i]->DajDatumProdaje())){
                delete p_prodaje[i];
                p_prodaje[i]=nullptr;
                obrisano++;
            }
    }
    auto pok=std::remove(p_prodaje,p_prodaje+broj_prodaja,nullptr);
    std::fill(pok,p_prodaje+broj_prodaja,nullptr);
    broj_prodaja-=obrisano;
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum)const {
    std::vector<Prodaja> pom;
    for(int i=0;i<broj_prodaja;i++){
            if(JednakDatum(datum,p_prodaje[i]->DajDatumProdaje()))
                pom.push_back(*p_prodaje[i]);
    }
    
    std::sort(pom.begin(),pom.end(),[](Prodaja p1, Prodaja p2){
        if(p1.DajImeKupca()<p2.DajImeKupca())
            return true;
        return false;
    });
    
    for(int i=0;i<pom.size();i++){
        pom[i].Ispisi(),std::cout<<std::endl;
    }
}
void Prodaje::IspisiSveProdaje()const{
    std::vector<Prodaja> pom;
    if(!p_prodaje) return;
    for(int i=0;i<broj_prodaja;i++){
            pom.push_back(*p_prodaje[i]);
    }
    std::sort(pom.begin(),pom.end(),[](Prodaja p1, Prodaja p2){
        if(ProdatPrije(p1,p2)) return true;
        else if(Datumi(p1,p2)==2){
            if(p1.DajImeKupca()<p2.DajImeKupca()){
                return true;
            }
        }
        return false;
    });
    
    for(int i=0;i<pom.size();i++){
        pom[i].Ispisi(), std::cout<<std::endl;
    }
}
void Prodaje::IsprazniKolekciju(){
    if(!p_prodaje) return;
    for(int i=0;i<broj_prodaja;i++){
        delete p_prodaje[i];
        p_prodaje[i]=nullptr;
    }
}
Prodaja Prodaje::DajNajranijuProdaju()const {
    if(DajBrojProdaja()==0)
        throw std::domain_error("Nema registriranih prodaja");
    auto pok=std::min_element(p_prodaje,p_prodaje+broj_prodaja,[](Prodaja* p1, Prodaja* p2){
        if(ProdatPrije(*p1,*p2)) return true;
        return false;});
    return **pok;
}
Prodaja &Prodaje::DajNajranijuProdaju(){
    if(DajBrojProdaja()==0)
        throw std::domain_error("Nema registriranih prodaja");
    auto pok=std::min_element(p_prodaje,p_prodaje+broj_prodaja,[](Prodaja *p1, Prodaja *p2){
        if(ProdatPrije(*p1,*p2)) return true;
        return false;
    });
    return **pok;
}
Prodaja Prodaje::DajNajskupljuProdaju() const{
    if(DajBrojProdaja()==0)
        throw std::domain_error("Nema registriranih prodaja");
    auto pok=std::max_element(p_prodaje,p_prodaje+broj_prodaja,[](Prodaja* p1, Prodaja* p2){
        if(!SkupljiStan(*p1,*p2)) return true;
        return false;
    });
    return **pok;
}
Prodaja& Prodaje::DajNajskupljuProdaju(){
    if(DajBrojProdaja()==0)
        throw std::domain_error("Nema registriranih prodaja");
    auto pok=std::max_element(p_prodaje,p_prodaje+broj_prodaja,[](Prodaja *p1, Prodaja *p2){
        if(!SkupljiStan(*p1,*p2)) return true;
        return false;
    });
    return **pok;
}
void Prodaje::ObrisiNajranijuProdaju(){
    if(DajBrojProdaja()==0)
        throw std::range_error("Prazna kolekcija");
    auto pok=std::min_element(p_prodaje,p_prodaje+broj_prodaja,[](Prodaja* p1, Prodaja* p2){
        if(ProdatPrije(*p1,*p2)) return true;
        return false;
    });
    
    Datum za_brisat((**pok).DajDatumProdaje());
    ObrisiProdajeNaDatum(za_brisat);
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
    if(broj_prodaja>=max_broj_prodaja)
        throw std::range_error("Dostignut maksimalan broj prodaja");
    p_prodaje[broj_prodaja++]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
}
void Prodaje::RegistrirajProdaju(Prodaja* prodaja){
    if(broj_prodaja>=max_broj_prodaja)
        throw std::range_error("Dostignut maksimalan broj prodaja");
    p_prodaje[broj_prodaja++]=prodaja;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
    if(broj_prodaja>=max_broj_prodaja)
        throw std::range_error("Dostignut maksimalan broj prodaja");
    p_prodaje[broj_prodaja++]=new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
}
int main ()
{
    std::cout<<"Dobrodosli!"<<std::endl<<std::endl;
    int opcija;
    std::vector<Stan> stanovi;
    std::vector<Kupac> kupci;
    Prodaje prodaje(20);
    
    for( ; ; ){
        
        std::cout<<"\nIzaberite opciju:\n 0 - kraj\n 1 - uredjivanje stanova\n 2 - uredjivanje kupaca\n 3 - uredjivanje prodaja"<<std::endl;
        std::cin>>opcija;
        if(opcija==0) break;
        if(opcija==1){
            int opcija_za_stan;
            for( ; ; ){
                std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje stana\n 2 - uredjivanje stanova\n 3 - ispis svih stanova\n 4 - kraj"<<std::endl;
                std::cin>>opcija_za_stan;
                std::cin.ignore(1000,'\n');
                if(opcija_za_stan==0) break;
                if(opcija_za_stan==1){
                    bool neispravan;
                    do{
                        neispravan=false;
                    std::string adresa;
                    std::cout<<"Unesite adresu: ";
                    std::getline(std::cin,adresa);
                    int sprat;
                    std::cout<<"Unesite sprat: ";
                    std::cin>>sprat;
                    int broj_soba;
                    std::cout<<"Unesite broj soba: ";
                    std::cin>>broj_soba;
                    int namjesten;
                    std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                    std::cin>>namjesten;
                    double kvadratura;
                    std::cout<<"Unesite kvadraturu: ";
                    std::cin>>kvadratura;
                    try{
                        if(namjesten!=0&&namjesten!=1)
                            throw std::domain_error("Neispravan unos podataka");
                        Stan stan(adresa,sprat,broj_soba,namjesten,kvadratura);
                        stanovi.push_back(stan);
                    }
                    catch(std::domain_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                        neispravan=true;
                        std::cin.ignore(100,'\n');
                    }
                    }
                    while(neispravan);
                    
                    std::cout<<"Stan je uspjesno dodan!"<<std::endl;
                }
                if(opcija_za_stan==2){
                    std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
                    for(int i=0;i<stanovi.size();i++){
                        std::cout<<" "<<i+1<<" - ";stanovi[i].Ispisi();std::cout<<std::endl;
                    }
                    int s_opcija;
                    std::cin>>s_opcija;
                    
                    std::cout<<"Odaberite polje koje zelite urediti:\n 0 - nazad\n 1 - adresa\n 2 - sprat\n 3 - broj soba\n 4 - da li je stan namjesten\n 5 - kvadratura\n 6 - sve"<<std::endl;
                    int broj;
                    std::cin>>broj;
                    std::cin.ignore(100,'\n');
                    if(broj==0) break;
                    if(broj==1){
                        bool neispravan2;
                        do{neispravan2=false;
                            std::cout<<"Unesite adresu: ";
                            std::string adresa;
                            std::getline(std::cin,adresa);
                            try{
                                stanovi[s_opcija-1]=Stan(adresa,stanovi[s_opcija-1].DajSprat(),stanovi[s_opcija-1].DajBrojSoba(),stanovi[s_opcija-1].DajNamjesten(),stanovi[s_opcija-1].DajKvadraturu());
                            }
                            catch(std::domain_error e){
                                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                neispravan2=true;
                            }
                        }
                        while(neispravan2);
                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                    }//izmjena adrese
                    if(broj==2){
                        bool neispravan2;
                        do{neispravan2=false;
                            std::cout<<"Unesite sprat: ";
                            int sp;
                            std::cin>>sp;
                            try{
                                stanovi[s_opcija-1]=Stan(stanovi[s_opcija-1].DajAdresu(),sp,stanovi[s_opcija-1].DajBrojSoba(),stanovi[s_opcija-1].DajNamjesten(),stanovi[s_opcija-1].DajKvadraturu());
                            }
                            catch(std::domain_error e){
                                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                neispravan2=true;
                            }
                        }
                        while(neispravan2);
                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                    }//izmjena sprata
                    if(broj==3){
                        bool neispravan2;
                        do{
                            neispravan2=false;
                            std::cout<<"Unesite broj soba: ";
                            int so;
                            std::cin>>so;
                            try{stanovi[s_opcija-1]=Stan(stanovi[s_opcija-1].DajAdresu(),stanovi[s_opcija-1].DajSprat(),so,stanovi[s_opcija-1].DajNamjesten(),stanovi[s_opcija].DajKvadraturu());}
                           catch(std::domain_error e){
                            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                            neispravan2=true;
                        }}
                        while(neispravan2);
                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                    }//izmjena sobe
                    if(broj==4){
                        bool neispravan2;
                        do{
                            neispravan2=false;
                            try{std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                            int namj;
                            std::cin>>namj;
                            if(namj!=0&&namj!=1)
                                throw std::domain_error("Neispravan unos podataka");
                            stanovi[s_opcija-1]=Stan(stanovi[s_opcija-1].DajAdresu(),stanovi[s_opcija-1].DajSprat(),stanovi[s_opcija-1].DajBrojSoba(),namj,stanovi[s_opcija-1].DajKvadraturu());
                            }
                            catch(std::domain_error e){
                                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                neispravan2=true;
                            }
                        }
                        while(neispravan2);
                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                    }//izmjena je li namjesten
                    if(broj==5){
                        bool neispravan2;
                        do{
                            neispravan2=false;
                            std::cout<<"Unesite kvadraturu: ";
                            double kv;
                            std::cin>>kv;
                            try{
                                stanovi[s_opcija-1]=Stan(stanovi[s_opcija-1].DajAdresu(),stanovi[s_opcija-1].DajSprat(),stanovi[s_opcija-1].DajBrojSoba(),stanovi[s_opcija-1].DajNamjesten(),kv);
                            }
                            catch(std::domain_error e){
                                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                                neispravan2=true;
                            }
                        }
                        while(neispravan2);
                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                    }//izmjena kvadrature
                    if(broj==6){
                        bool neispravan2;
                        do{
                        neispravan2=false;
                        std::string adresa;
                        int sp,so,nam;
                        double kv;
                        std::cout<<"Unesite adresu: ";
                        std::getline(std::cin,adresa);
                        std::cout<<"Unesite sprat: ";
                        std::cin>>sp;
                        std::cout<<"Unesite broj soba: ";
                        std::cin>>so;
                        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                        std::cin>>nam;
                        std::cout<<"Unesite kvadraturu: ";
                        std::cin>>kv;
                        try{
                            if(nam!=1&&nam!=0)
                                throw std::domain_error("Neispravan unos podataka");
                            stanovi[s_opcija-1]=Stan(adresa,sp,so,nam,kv);
                        }
                        catch(std::domain_error e){
                            std::cout<<"Izutetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                            neispravan2=true;
                            std::cin.ignore(100,'\n');
                        }}
                        while(neispravan2);
                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                    }
                }//izmjene
                if(opcija_za_stan==3){
                    for(int i=0;i<stanovi.size();i++){
                        std::cout<<i+1<<". "; stanovi[i].Ispisi();std::cout<<std::endl;
                    }
                }//
                if(opcija_za_stan==4){std::cout<<"Dovidjenja!"; return 0;}
            }
            
        }//stanovi
        if(opcija==2){
            int opcija_za_kupce;
            for( ; ; ){
                
                std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje kupca\n 2 - uredjivanje kupaca\n 3 - ispis svih kupaca\n 4 - kraj"<<std::endl;
                std::cin>>opcija_za_kupce;
                std::cin.ignore();
                if(opcija_za_kupce==0) break;
                if(opcija_za_kupce==1){
                    bool neispravan;
                    do{
                    neispravan=false;
                    std::string ime;
                    int d,m,g;
                    char znak;
                    std::cout<<"Unesite ime i prezime kupca: ";
                    std::getline(std::cin,ime);
                    std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                    std::cin>>d>>znak>>m>>znak>>g;
                    try{
                        Kupac kup(ime,Datum(d,m,g));
                        kupci.push_back(kup);
                    }
                    catch(std::domain_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                        neispravan=true;
                        std::cin.ignore();
                    }
                    }
                    while(neispravan);
                    std::cout<<"Kupac je uspjesno dodan!"<<std::endl;
                }//dodavanje kupca
                if(opcija_za_kupce==2){
                    std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su: "<<std::endl;
                    for(int i=0;i<kupci.size();i++){
                        std::cout<<" "<<i+1<<" - ";kupci[i].Ispisi(); std::cout<<std::endl;
                    }
                    int opc;
                    std::cin>>opc;
                    std::cin.ignore();
                    bool neispravan;
                    do{
                        std::string ipk;
                        int dd,mm,gg;
                        char z;
                        neispravan=false;
                        std::cout<<"Unesite ime i prezime kupca: ";
                        std::getline(std::cin,ipk);
                        std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                        std::cin>>dd>>z>>mm>>z>>gg;
                        try{kupci[opc-1]=Kupac(ipk,Datum(dd,mm,gg));}
                        catch(std::domain_error e){
                            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                            neispravan=true;
                            std::cin.ignore();
                        }
                    }
                    while(neispravan);
                    std::cout<<"Kupac je uspjesno izmijenjen!"<<std::endl;
                }//uredjivanje kupaca
                if(opcija_za_kupce==3){
                    for(int i=0;i<kupci.size();i++){
                      kupci[i].Ispisi(); std::cout<<std::endl;
                    }
                }//ispisivanje kupca
                if(opcija_za_kupce==4){std::cout<<"Dovidjenja!"; return 0;}
                
            }
        }//kupci
        if(opcija==3){
            
            int opcija_za_prodaju;
            for( ; ; ){
                std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje prodaje\n 2 - uredjivanje prodaje\n 3 - ispis prodaja\n 4 - brisanje prodaja\n 5 - kraj"<<std::endl;
                        std::cin>>opcija_za_prodaju;
                        if(opcija_za_prodaju==0) break;
                        if(opcija_za_prodaju==5){
                            std::cout<<"Dovidjenja!"; return 0;
                        }
                        if(opcija_za_prodaju==1){
                            int opcija_za_dodavanje;
                            for( ; ; ){
                                std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje potpuno nove prodaje\n 2 - dodavanje nove prodaje na osnovu arhive\n 3 - kraj"<<std::endl;
                                std::cin>>opcija_za_dodavanje;
                                if(opcija_za_dodavanje==0) break;
                                if(opcija_za_dodavanje==3){std::cout<<"Dovidjenja!"; return 0;}
                                if(opcija_za_dodavanje==1){
                                    bool neispravan;
                                    
                                    
                                    do{
                                        neispravan=false;
                                        try{std::string ime_agenta;
                                        std::cin.ignore();
                                        std::cout<<"Unesite ime i prezime agenta prodaje: ";
                                        std::getline(std::cin,ime_agenta);
                                        int dp,mp,gp;
                                        char znak;
                                        double cijena,kvad;
                                        std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                                        std::cin>>dp>>znak>>mp>>znak>>gp;
                                        std::cout<<"Unesite cijenu stana: ";
                                        std::cin>>cijena;
                                        std::cin.ignore();
                                        std::string imek,adresa;
                                        int dk,mk,gk,spr,sob,nam;
                                        std::cout<<"Unesite ime kupca: ";
                                        std::getline(std::cin,imek);
                                        std::cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
                                        std::cin>>dk>>znak>>mk>>znak>>gk;
                                        std::cin.ignore();
                                        std::cout<<"Unesite adresu: ";
                                        std::getline(std::cin,adresa);
                                        std::cout<<"Unesite sprat: ";
                                        std::cin>>spr;
                                        std::cout<<"Unesite broj soba: ";
                                        std::cin>>sob;
                                        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                                        std::cin>>nam;
                                        std::cout<<"Unesite kvadraturu: ";
                                        std::cin>>kvad;
                                        if(nam!=1&&nam!=0)
                                            throw std::domain_error("Neispravan unos podataka");
                                        prodaje.RegistrirajProdaju(ime_agenta,cijena,{dp,mp,gp},{imek,{dk,mk,gk}},{adresa,spr,sob,bool(nam),kvad});
                                        kupci.push_back({imek,{dk,mk,gk}});
                                        stanovi.push_back({adresa,spr,sob,bool(nam),kvad});
                                        }
                                        catch(std::domain_error e){std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite ponovo."<<std::endl;
                                            neispravan=true;
                                        }
                                        catch(std::range_error e){
                                            std::cout<<"Izuzetak: "<<e.what()<<std::endl;
                                        }
                                    }
                                    while(neispravan);
                                    
                                    std::cout<<"Prodaja uspjesno dodana!"<<std::endl;
                                }
                                if(opcija_za_dodavanje==2){
                                    try{
                                    std::string agent;
                                    std::cin.ignore();
                                    std::cout<<"Unesite ime i prezime agenta prodaje: ";
                                    std::getline(std::cin,agent);
                                    int d,m,g;
                                    char z;
                                    std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                                    std::cin>>d>>z>>m>>z>>g;
                                    double cijena3;
                                    std::cout<<"Unesite cijenu stana: ";
                                    std::cin>>cijena3;
                                    std::cout<<"Odaberite kupca. Dostupni kupci su:"<<std::endl;
                                
                                    for(int i=0;i<kupci.size();i++){
                                        std::cout<<" "<<i+1<<" - "; kupci[i].Ispisi(); std::cout<<std::endl;
                        
                                    }
                                    int op;
                                    std::cin>>op;
                                    Kupac k=kupci[op-1];
                                    std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
                                    for(int i=0;i<stanovi.size();i++){
                                        std::cout<<" "<<i+1<<" - ";stanovi[i].Ispisi(); std::cout<<std::endl;
                                    }
        
                                    std::cin>>op;
                                    Stan s=stanovi[op-1];
                                   prodaje.RegistrirajProdaju(agent,cijena3,{d,m,g},k,s);
                                   std::cout<<"Prodaja uspjesno dodana!"<<std::endl;
                                }
                                catch(std::range_error e){
                                    std::cout<<"Izuzetak: "<<e.what()<<std::endl;
                                }
                                    
                                }
                                
                            }}//dodavanje
                        if(opcija_za_prodaju==3){
                            int opcija_za_ispis;
                            for (;;){
                            std::cout<<"\nIzaberite opciju:\n 0 - nazad\n 1 - ispis svih prodaja\n 2 - ispis prodaja na datum\n"
                            <<" 3 - ispis najranije prodaje\n 4 - ispis najskuplje prodaje\n 5 - ispis broja prodaja\n"
                            <<" 6 - ispis broja prodaja po datumu\n 7 - ispis broja prodaja po agentu\n 8 - kraj"<<std::endl;
                            std::cin>>opcija_za_ispis;
                            if(opcija_za_ispis==0) break;
                            if(opcija_za_ispis==8){std::cout<<"Dovidjenja!";return 0;}
                            if(opcija_za_ispis==1){
                                prodaje.IspisiSveProdaje();
                            }//sve prodaje
                            if(opcija_za_ispis==3){
                                try{prodaje.DajNajranijuProdaju().Ispisi();}
                                catch(std::domain_error e){
                                    std::cout<<"Izuzetak: "<<e.what()<<std::endl;
                                }
                                
                            }
                            if(opcija_za_ispis==4){
                                
                                try{prodaje.DajNajskupljuProdaju().Ispisi();}
                                catch(std::domain_error e){
                                    std::cout<<"Izuzetak: "<<e.what()<<std::endl;
                                }
                                
                            }
                            if(opcija_za_ispis==2){
                                std::cout<<"Unesite datum (d/m/g): ";
                                int d,m,g;
                                char z;
                                std::cin>>d>>z>>m>>z>>g;
                                prodaje.IspisiProdajeNaDatum({d,m,g});
                            }
                            if(opcija_za_ispis==5){std::cout<<prodaje.DajBrojProdaja();}
                            if(opcija_za_ispis==6){
                            std::cout<<"Unesite datum (d/m/g): ";
                            int d,m,g,z;
                            std::cin>>d>>z>>m>>z>>g;
                            std::cout<<"Broj prodaja na uneseni datum: "<<prodaje.DajBrojProdajaNaDatum({d,m,g});}
                            if(opcija_za_ispis==7){
                                std::cin.ignore();
                                std::string agent;
                                std::cout<<"Unesite ime agenta: ";
                                std::getline(std::cin,agent);
                                std::cout<<"Broj prodaja: "<<prodaje.DajBrojProdajaOdAgenta(agent);
                            }
                            }
                        }//ispis
                        if(opcija_za_prodaju==4){
                            int opcija_za_brisanje;
                            for( ; ; ){
                                std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - brisanje najranije prodaje\n"
                                <<" 2 - brisanje prodaja agenta\n 3 - brisanje prodaja po datumu\n 4 - brisanje svih prodaja"<<std::endl;
                                std::cin>>opcija_za_brisanje;
                                if(opcija_za_brisanje==0) break;
                                if(opcija_za_brisanje==1){
                                    try{prodaje.ObrisiNajranijuProdaju();}
                                    catch(std::range_error e){
                                        std::cout<<"Izuzetak: "<<e.what()<<std::endl;
                                    }
                                }//najranija
                                if(opcija_za_brisanje==4){prodaje.IsprazniKolekciju();}
                                if(opcija_za_brisanje==3){
                                    std::cout<<"Unesite datum (d/m/g): ";
                                    int d,m,g,z;
                                    std::cin>>d>>z>>m>>z>>g;
                                    prodaje.ObrisiProdajeNaDatum({d,m,g});
                                    std::cout<<"Sve prodaje na taj datum su obrisane."<<std::endl;
                                }
                                if(opcija_za_brisanje==2){
                                    std::cin.ignore();
                                    std::cout<<"Unesite ime agenta: ";
                                    std::string agent;
                                    prodaje.ObrisiProdajeAgenta(agent);
                                    std::cout<<"Sve prodaje tog agenta su obrisane."<<std::endl;
                                }
                                
                            }
                        }//brisanje
                        if(opcija_za_prodaju==2){
                            
                            std::cout<<"Odaberite prodaju koju želite urediti. Dostupne prodaje su:"<<std::endl;
                            
                            for(int i=1;i<=prodaje.DajBrojProdaja();i++){
                                std::cout<<i<<"."<<std::endl;
                                prodaje.DajProdaju(i).Ispisi();
                                std::cout<<std::endl;
                            }
                            int prodaja;
                            std::cin>>prodaja;
                            std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - izmjena agenta\n 2 - izmjena datuma prodaje\n 3 - izmjena kupca"
                            <<"\n 4 - izmjena stana\n 5 - izmjena cijene stana"<<std::endl;
                            int opcija_za_izmjenu;
                            std::cin>>opcija_za_izmjenu;
                            if(opcija_za_izmjenu==0) break;
                            if(opcija_za_izmjenu==3){
                                std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - odabir postojeceg kupca\n 2 - dodavanje novog kupca"<<std::endl;
                                int kopcija;
                                std::cin>>kopcija;
                                if(kopcija==0) break;
                                if(kopcija==1){
                                    std::cout<<"Odaberite kupca. Dostupni kupci su:"<<std::endl;
                                    for(int i=0;i<kupci.size();i++){
                                        std::cout<<" "<<i+1<<" - ";kupci[i].Ispisi(); std::cout<<std::endl;
                                    }
                                    int kpc;
                                    std::cin>>kpc;
                                    prodaje.DajProdaju(prodaja).PromijeniKupca(kupci[kpc-1]);
                                    std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                                
                                }//postojeci kupac
                                if(kopcija==2){
                                    bool neispravan;
                                    do{
                                        try{neispravan=false;
                                        std::cin.ignore();
                                        std::cout<<"Unesite ime i prezime kupca: ";
                                        std::string kk;
                                        std::getline(std::cin,kk);
                                        std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                                        int d,m,g;
                                        char z;
                                        std::cin>>d>>z>>m>>z>>g;
                                            prodaje.DajProdaju(prodaja).PromijeniKupca({kk,{d,m,g}});
                                        }
                                        catch(std::domain_error e){
                                            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite ponovo."<<std::endl;
                                            neispravan=true;
                                        }
                                    }
                                    while(neispravan);
                                    std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                                }//novi kupac
                            }//kupac
                            if(opcija_za_izmjenu==4){
                                std::cout<<"Izaberite opciju:\n 0 - nazad\n 1 - odabir postojeceg stana\n 2 - dodavanje novog stana"<<std::endl;
                                int sopcija;
                                std::cin>>sopcija;
                                if(sopcija==0) break;
                                if(sopcija==1){
                                    std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
                                    for(int i=0;i<stanovi.size();i++){
                                        std::cout<<" "<<i+1<<" - ";stanovi[i].Ispisi(); std::cout<<std::endl;
                                    }
                                    int ss;
                                    std::cin>>ss;
                                    prodaje.DajProdaju(prodaja).PromijeniStan(stanovi[ss-1]);
                                    std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                                    
                                }
                                if(sopcija==2){
                                    bool neispravan3;
                                    
                                    do{try{
                                        std::string adr;
                                        int sobb,sprr,namm;
                                        double kvadd;
                                        std::cout<<"Unesite adresu: ";
                                        std::cin.ignore();
                                        std::getline(std::cin,adr);
                                        std::cout<<"Unesite sprat: ";
                                        std::cin>>sprr;
                                        std::cout<<"Unesite broj soba: ";
                                        std::cin>>sobb;
                                        std::cout<<"Da li je stan namjesten(1 - da, 0 - ne): ";
                                        std::cin>>namm;
                                        std::cout<<"Unesite kvadraturu: ";
                                        std::cin>>kvadd;
                                        if(namm!=1&&namm!=0){
                                            throw std::domain_error("Neispravan unos podataka");
                                        }
                                       
                                    }
                                    catch(std::domain_error e){
                                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite ponovo."<<std::endl;
                                        neispravan3=true;
                                    }}
                                    while(neispravan3);
                                }
                            }//stan
                            if(opcija_za_izmjenu==5){
                                std::cout<<"Unesite cijenu stana: ";
                                double cij;
                                std::cin>>cij;
                                prodaje.DajProdaju(prodaja).PromijeniCijenuProdaje(cij);
                                std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                                
                            }//cijena
                            if(opcija_za_izmjenu==1){
                                std::string na;
                                std::cout<<"Unesite ime i prezime agenta prodaje: ";
                                std::cin.ignore();
                                std::getline(std::cin,na);
                                prodaje.DajProdaju(prodaja).PromijeniAgenta(na);
                                std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                            }//kupac
                            if(opcija_za_izmjenu==2){
                                bool neispravan3;
                                do{neispravan3=false;
                                    try{int dd,mm,gg;
                                    char zz;
                                    std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                                    std::cin>>dd>>zz>>mm>>zz>>gg;
                                        prodaje.DajProdaju(prodaja).PromijeniDatumKupovine(Datum(dd,mm,gg));
                                        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                                    }
                                    catch(std::domain_error e){std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite ponovo."<<std::endl;
                                        neispravan3=true;
                                    }
                                    
                                }
                                while(neispravan3);
                            }
                            
                            
                        }
            
            }
        } 
        
    }   
        
    std::cout<<std::endl<<std::endl<<"Dovidjenja!";
    
    

return 0;
}