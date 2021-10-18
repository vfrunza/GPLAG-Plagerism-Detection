/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
#include <algorithm>
#include <new>
bool ispravan_datum(int d,int m,int g){
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0) broj_dana[1]++;
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1]) return false;
    return true;
}

class Datum{
    int dan,mjesec,godina;
    public:
Datum(int dan, int mjesec, int godina){ Postavi(dan,mjesec,godina);}
void Postavi(int dan, int mjesec, int godina);
int DajDan() const{ return dan;}
int DajMjesec() const{return mjesec;}
int DajGodinu() const{return godina;}
void Ispisi() const{std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};
void Datum::Postavi(int dan, int mjesec,int godina){
    if(ispravan_datum(dan,mjesec,godina)){
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
    }
    else throw std::domain_error("Neispravan datum");
}
bool znak(char c){
  if(c>='A'&&c<='Z' || c>='a'&&c<='z'|| c==' ' || c>='0'&&c<='9') return true;
    return false;
}
bool poredidvadatuma(const Datum &d1,const Datum &d2){
    if(d1.DajGodinu()==d2.DajGodinu()&&d1.DajDan()==d2.DajDan()&&d1.DajMjesec()==d2.DajMjesec())return true;
    return false;
}
class Kupac{
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    public:
Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):datum_rodjenja(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu()){ Postavi(ime_i_prezime,datum_rodjenja);}
void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
std::string DajImePrezime() const{ return ime_i_prezime;}
Datum DajDatumRodjenja() const{return datum_rodjenja;}
void Ispisi() const{std::cout<<ime_i_prezime<<" (";datum_rodjenja.Ispisi();std::cout<<")";}
};
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    for(int i{};i<ime_i_prezime.size();i++) if(!znak(ime_i_prezime[i])) throw std::domain_error("Neispravno ime i prezime");
    Kupac::ime_i_prezime=ime_i_prezime; Kupac::datum_rodjenja=datum_rodjenja;
}
class Stan{
    std::string adresa;
    int sprat,broj_soba;
    bool namjesten;
    double kvadratura;
    public:
Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura){Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);}
void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura);
std::string DajAdresu() const{ return adresa;}
int DajSprat() const{ return sprat;}
int DajBrojSoba() const {return broj_soba;}
bool DajNamjesten() const{ return namjesten;}
double DajKvadraturu() const{ return kvadratura;}
void Ispisi() const{ 
    if(broj_soba<=4) std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" sobe. ";
    if(broj_soba>4)  std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" soba. ";
    if(namjesten) std::cout<<"Kvadratura stana je "<<kvadratura<<" (m^2) i stan je namjesten."<<std::endl;
    if(!namjesten) std::cout<<"Kvadratura stana je "<<kvadratura<<" (m^2) i stan nije namjesten."<<std::endl;
}
};
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura){
    if(sprat<0||broj_soba<0||kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
}
class Prodaja{
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
 const Datum &datum_prodaje, const Kupac &kupac_stana,
 const Stan &kupljeni_stan);
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
 int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
 std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
 const std::string &adresa_stana, int sprat_stana, int broj_soba,
 bool namjesten_stan, double broj_kvadrata);
void PromijeniKupca(const Kupac &novi_kupac){kupac_stana=novi_kupac;} 
void PromijeniStan(const Stan &novi_stan){kupljeni_stan=novi_stan;}
void PromijeniDatumKupovine(const Datum &novi_datum){datum_prodaje=novi_datum;}
void PromijeniCijenuProdaje(const double &nova_cijena){cijena_stana=nova_cijena;}
void PromijeniImeAgenta(std::string ime){
    ime_agenta_prodaje=ime;
}
void PomjeriDanUnaprijed();
void PomjeriDanUnazad();
std::string DajImeAgenta() const{ return ime_agenta_prodaje;}
std::string DajImeKupca() const{return kupac_stana.DajImePrezime();}
Datum DajDatumProdaje() const{return datum_prodaje;}
double DajCijenuStana() const{return cijena_stana;}
friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
void Ispisi() const;

};
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    Datum d1=p1.DajDatumProdaje(),d2=p2.DajDatumProdaje();
    if(d1.DajGodinu()<d2.DajGodinu()) return true;
    else if(d1.DajGodinu()==d2.DajGodinu()&&d1.DajMjesec()<d2.DajMjesec()) return true;
    else if(d1.DajGodinu()==d2.DajGodinu()&&d1.DajMjesec()==d2.DajMjesec()&&d1.DajDan()<d2.DajDan()) return true;
    else return false;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan):kupljeni_stan(kupljeni_stan),
datum_prodaje(datum_prodaje),kupac_stana(kupac_stana){
    Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana; Prodaja::datum_prodaje=datum_prodaje; Prodaja::kupljeni_stan=kupljeni_stan;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata):datum_prodaje(Datum(dan_prodaje,mjesec_prodaje,
godina_prodaje)),kupac_stana(Kupac(ime_kupca,datum_rodjenja_kupca)),kupljeni_stan(Stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)){
    Prodaja::ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana; Prodaja::datum_prodaje=Datum(dan_prodaje,mjesec_prodaje,godina_prodaje);
    Prodaja::kupac_stana=Kupac(ime_kupca,datum_rodjenja_kupca); Prodaja::kupljeni_stan=Stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
}
void Prodaja::PomjeriDanUnaprijed(){
    int dan=datum_prodaje.DajDan(),mjesec=datum_prodaje.DajMjesec(),godina=datum_prodaje.DajGodinu();
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    dan++; 
    if(dan>broj_dana[mjesec-1]){ dan=1; mjesec++;}
    if(mjesec>12){ godina++; mjesec=1;}
    datum_prodaje=Datum(dan,mjesec,godina);
}

void Prodaja::PomjeriDanUnazad(){
    int dan=datum_prodaje.DajDan(),mjesec=datum_prodaje.DajMjesec(),godina=datum_prodaje.DajGodinu();
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    dan--; 
    if(dan<1){ mjesec--;dan=broj_dana[mjesec-1];}
    if(mjesec<1){ godina--; mjesec=12;dan=broj_dana[mjesec-1];}
    datum_prodaje=Datum(dan,mjesec,godina);
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    return p1.cijena_stana>p2.cijena_stana;
}
void Prodaja::Ispisi() const{
    std::cout<<"Ime agenta:                     "<<ime_agenta_prodaje<<std::endl;
    std::cout<<"Ime kupca:                      ";kupac_stana.Ispisi(); std::cout<<std::endl;
    std::cout<<"Zakazani datum prodaje:         ";datum_prodaje.Ispisi();std::cout<<std::endl;
    std::cout<<"Cijena stana:                   "<<DajCijenuStana()<<std::endl;
    std::cout<<"Informacije o stanu: "<<std::endl;
    kupljeni_stan.Ispisi();
}
class Prodaje{
    Prodaja ** p;
    int vel;
    public:
explicit Prodaje(int max_broj_prodaja){
    p=nullptr; 
    p=new Prodaja*[max_broj_prodaja];
    for(int i=0;i<max_broj_prodaja;i++) p[i]=nullptr;
    vel=max_broj_prodaja;

}
Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
~Prodaje();
void SortirajProdaje(){
    for(int i=0;i<vel;i++){
        if(p[i]==nullptr){
            int j{i};
            while(j+1<vel){ p[j]=p[j+1]; j++;}
        }
    }
}
Prodaje(const Prodaje &prodaje);
Prodaje(Prodaje &&prodaje){
    if(this!=&prodaje){
    p=prodaje.p; vel=prodaje.vel;
    prodaje.p=nullptr;
    }
}
Prodaje &operator =(const Prodaje &prodaje){
    if(p!=nullptr){
        
    for(int i=0;i<vel;i++) delete p[i];
    delete []p;}
    p=nullptr; int brojac{};
    p=new Prodaja*[prodaje.vel];
    try{
        for(int i=0;i<prodaje.vel;i++){
            p[i]=nullptr;
            p[i]=new Prodaja(*(prodaje.p[i]));
            brojac++;
        }
    }
    catch(...){
        for(int i=0;i<brojac;i++) delete p[i];
        delete []p;
        throw;
    }
    vel=prodaje.vel;  
    return *this;
}
Prodaje &operator =(Prodaje &&prodaje){
    if(this!=&prodaje){
    p=prodaje.p; vel=prodaje.vel;
    prodaje.p=nullptr;
    }
    return *this;
}
void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
 double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
const Stan &kupljeni_stan);
void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
 const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
 void RegistrirajProdaju(Prodaja *prodaja){
     bool ubacio=false;
    for(int i=0;i<vel;i++)if(p[i]==nullptr){p[i]=prodaja;ubacio=true; break;}
    if(!ubacio) throw std::range_error("Dostignut maksimalni broj prodaja");
 } 
int DajBrojProdaja() const{
    int vel2{}; 
    for(int i=0;i<vel;i++) if(p[i]!=nullptr) vel2++;
    return vel2;}
int DajBrojProdajaNaDatum(const Datum &datum) const{
     return std::count_if(p,p+vel,[datum](Prodaja *pok){
        if(pok!=nullptr)if(poredidvadatuma(pok->DajDatumProdaje(),datum)) return true;
        return false;
    });
}
int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    return std::count_if(p,p+vel,[ime_agenta](Prodaja *pok){
        if(pok!=nullptr)if(pok->DajImeAgenta()==ime_agenta) return true;
        return false;
    });
}
Prodaja &DajNajranijuProdaju(){
        int vel2{};
    for(int i=0;i<vel;i++){
        if(p[i]!=nullptr) vel2++;
        else break;
    }
     auto pok=std::min_element(p,p+vel2,[](Prodaja *p1,Prodaja *p2){
        return ProdatPrije(*p1,*p2);
    });
     if(pok==p+vel2) throw std::domain_error("Nema registriranih prodaja");
    return **pok;
}
Prodaja DajNajranijuProdaju() const{
        int vel2{};
    for(int i=0;i<vel;i++){
        if(p[i]!=nullptr) vel2++;
        else break;
    }
     auto pok=std::min_element(p,p+vel2,[](Prodaja *p1,Prodaja *p2){
        return ProdatPrije(*p1,*p2);
    });
    if(pok==p+vel2) throw std::domain_error("Nema registriranih prodaja");
    return **pok;
}
Prodaja &DajNajskupljuProdaju(){
    int vel2{};
    for(int i=0;i<vel;i++){
        if(p[i]!=nullptr) vel2++;
        else break;
    }
     auto pok=std::max_element(p,p+vel2,[](Prodaja *p1,Prodaja *p2){
        return SkupljiStan(*p1,*p2);
    });
     if(pok==p+vel2) throw std::domain_error("Nema registriranih prodaja");
    return **pok;
}
 Prodaja DajNajskupljuProdaju()const{
    int vel2{};
    for(int i=0;i<vel;i++){
        if(p[i]!=nullptr) vel2++;
        else break;
    }
     auto pok=std::max_element(p,p+vel2,[](Prodaja *p1,Prodaja *p2){
        return SkupljiStan(*p1,*p2);
    });
    if(pok==p+vel2) throw std::domain_error("Nema registriranih prodaja");
    return **pok;
}
void IsprazniKolekciju();
void ObrisiNajranijuProdaju(){
    try{
    auto pok=DajNajranijuProdaju();
    bool obrisan=false;
    for(int i=0;i<vel;i++) if(p[i]!=nullptr&& &pok!=nullptr)if(p[i]->DajImeAgenta()==pok.DajImeAgenta()&&poredidvadatuma(p[i]->DajDatumProdaje(),pok.DajDatumProdaje())&&
    p[i]->DajCijenuStana()==pok.DajCijenuStana()) {delete p[i]; p[i]=nullptr; obrisan=true;}
    if(!obrisan) throw std::range_error("Prazna kolekcija");
    SortirajProdaje();
}
    catch(...){
        throw std::range_error("Prazna kolekcija");
    }
}
void ObrisiProdajeAgenta(const std::string &ime_agenta){
    for(int i=0;i<vel;i++) if(p[i]!=nullptr)if(p[i]->DajImeAgenta()==ime_agenta){ delete p[i]; p[i]=nullptr;}
    SortirajProdaje();
}
void ObrisiProdajeNaDatum(const Datum &datum){
    for(int i=0;i<vel;i++) if(p[i]!=nullptr)if(poredidvadatuma(p[i]->DajDatumProdaje(),datum)){ delete p[i]; p[i]=nullptr;}
    SortirajProdaje();
}
void IspisiProdajeNaDatum(const Datum &datum){
    for(int i=0;i<vel;i++) if(p[i]!=nullptr)if(poredidvadatuma(p[i]->DajDatumProdaje(),datum)) p[i]->Ispisi();
}
void IspisiSveProdaje() const{
std::vector<Prodaja> pr;
for(int i=0;i<vel;i++){
    if(p[i]!=nullptr) pr.emplace_back(*p[i]);
    else break;
}
std::sort(pr.begin(),pr.end(),[](Prodaja p1,Prodaja p2){
            if(poredidvadatuma(p1.DajDatumProdaje(),p2.DajDatumProdaje())) return p1.DajImeKupca()<p2.DajImeKupca();
            return (ProdatPrije(p1,p2));
        return false;
    });
    for(int i=0;i<pr.size();i++){pr[i].Ispisi(); std::cout<<std::endl;}
}
void IspisiSveProdaje2() const{
    int vel2{};
    for(int i=0;i<vel;i++){
        if(p[i]!=nullptr) vel2++;
        else break;
    }
    for(int i=0;i<vel2;i++){
        std::cout<<i+1<<"."<<std::endl;
        p[i]->Ispisi();
        if(i<vel2-1) std::cout<<std::endl;
    } 
    
}
Prodaja& DajProdaju(int indeks){
    int j{};
    for(int i=0;i<vel;i++){
        if(j==indeks&&p[i]!=nullptr) return *p[i];
        if(p[i]!=nullptr)j++;
     }
     throw std::domain_error("Prodaja se ne nalazi u kolekciji");
}
};
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja){
    p=nullptr; int brojac{};
    auto it=spisak_prodaja.begin();
    p=new Prodaja*[spisak_prodaja.size()];
    try{
        for(int i=0;i<spisak_prodaja.size();i++){
            p[i]=nullptr;
            p[i]=new Prodaja(*it++);
            brojac++;
        }
    }
    catch(...){
        for(int i=0;i<brojac;i++) delete p[i];
        delete []p;
        throw;
    }
    vel=spisak_prodaja.size();
    SortirajProdaje();
}
Prodaje::~Prodaje(){
    if(p!=nullptr){
    for(int i=0;i<vel;i++) delete p[i];
    delete []p;
    }
}
Prodaje::Prodaje(const Prodaje &prodaje){
     p=nullptr; int brojac{};
    p=new Prodaja*[prodaje.vel];
    try{
        for(int i=0;i<prodaje.vel;i++){
            p[i]=nullptr;
            p[i]=new Prodaja(*(prodaje.p[i]));
            brojac++;
        }
    }
    catch(...){
        for(int i=0;i<brojac;i++) delete p[i];
        delete []p;
        throw;
    }
    vel=prodaje.vel;
    SortirajProdaje();
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan){
    bool nasao=false;
    for(int i=0;i<vel;i++)if(p[i]==nullptr){
            p[i]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);;
       nasao=true; break;}
    if(!nasao) throw std::range_error("Dostignut maksimalni broj prodaja");
    SortirajProdaje();
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
 const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
     RegistrirajProdaju(ime_agenta_prodaje,cijena_stana,Datum(dan_prodaje,mjesec_prodaje,godina_prodaje),Kupac(ime_kupca,datum_rodjenja_kupca),Stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata));
 }
void Prodaje::IsprazniKolekciju(){
    for(int i=0;i<vel;i++){
        delete p[i];
        p[i]=nullptr;
    }
}
void UnesiDatum(int &dan,int &mjesec, int &godina){
    std::cin>>dan;
    char znak;
    znak=std::cin.get();
    std::cin>>mjesec;
    znak=std::cin.get();
    std::cin>>godina;
}

/*
int main(){
    try{
        Prodaje p(20);
        
       std::cout<<"Dobrodosli!\n\n\n";
    std::vector<Stan> stanovi;
    std::vector<Kupac> kupci;
    for(;;){
        std::cout<<"Izaberite opciju:"<<std::endl;
        std::cout<<" 0 - kraj"<<std::endl;
        std::cout<<" 1 - uredjivanje stanova"<<std::endl;
        std::cout<<" 2 - uredjivanje kupaca"<<std::endl;
        std::cout<<" 3 - uredjivanje prodaja"<<std::endl;
        int n; std::cin>>n;
        if(n==0){  std::cout<<std::endl<<std::endl<<"Dovidjenja!"; return 0;}
        if(n==1){
            while(true){
            std::cout<<"Izaberite opciju:"<<std::endl;
            std::cout<<" 0 - nazad"<<std::endl;
            std::cout<<" 1 - dodavanje stana"<<std::endl;
            std::cout<<" 2 - uredjivanje stanova"<<std::endl;
            std::cout<<" 3 - ispis svih stanova"<<std::endl;    
            std::cout<<" 4 - kraj"<<std::endl;
            int m; std::cin>>m;
            if(m==0) break;
            if(m==4){ std::cout<<std::endl<<std::endl<<"Dovidjenja!"; return 0;}
            if(m==1){
                // dodavanje stana
                while(true){
                std::string adresa; int sprat,brojsoba; int namjesten;  double kvadratura;
                std::cin.ignore(1000,'\n');
                std::cout<<"Unesite adresu: ";
                std::getline(std::cin,adresa);
                std::cout<<"Unesite sprat: ";
                std::cin>>sprat;
                std::cout<<"Unesite broj soba: ";
                std::cin>>brojsoba;
                std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                std::cin>>namjesten;
                std::cout<<"Unesite kvadraturu: ";
                std::cin>>kvadratura;
                try{
                    if(namjesten!=0&&namjesten!=1) throw std::domain_error("Neispravan unos podataka");
                    stanovi.emplace_back(Stan(adresa,sprat,brojsoba,namjesten,kvadratura));
                    std::cout<<"Stan je uspjesno dodan!"<<std::endl<<std::endl;
                    break;
                    }
                catch(std::domain_error e){
                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                    }
                }
            }
            if(m==3){
                for(int i=0;i<stanovi.size();i++){
                    std::cout<<i+1<<". "; 
                    stanovi[i].Ispisi();
                }
                std::cout<<std::endl;
            }
            if(m==2){
                std::cout<<"Odaberite stan. Dostupni stanovi su: "<<std::endl;
                for(int i=0;i<stanovi.size();i++){
                    std::cout<<" "<<i+1<<" - ";
                    stanovi[i].Ispisi();
                }
                std::cout<<std::endl;
                int koji_stan; std::cin>>koji_stan;
                std::cout<<"Odaberite polje koje zelite urediti: "<<std::endl;
                std::cout<<" 0 - nazad"<<std::endl;
                std::cout<<" 1 - adresa"<<std::endl;
                std::cout<<" 2 - sprat"<<std::endl;
                std::cout<<" 3 - broj soba"<<std::endl;
                std::cout<<" 4 - da li je stan namjesten"<<std::endl;
                std::cout<<" 5 - kvadratura"<<std::endl;
                std::cout<<" 6 - sve"<<std::endl;
                int polje;std::cin>>polje;
                while(1){
                    std::string adresa=stanovi[koji_stan-1].DajAdresu();
                    int sprat=stanovi[koji_stan-1].DajSprat(),brojsoba=stanovi[koji_stan-1].DajBrojSoba();
                    int namjesten=stanovi[koji_stan-1].DajNamjesten();
                    double kvadratura=stanovi[koji_stan-1].DajKvadraturu();
                    if(polje==1||polje==6){std::cout<<"Unesite adresu: "; std::cin.ignore(1000,'\n'); std::getline(std::cin,adresa);}
                    if(polje==2||polje==6){std::cout<<"Unesite sprat: "; std::cin>>sprat;}
                    if(polje==3||polje==6){std::cout<<"Unesite broj soba: ";std::cin>>brojsoba;}
                    if(polje==4||polje==6){std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): "; std::cin>>namjesten;}
                    if(polje==5||polje==6){std::cout<<"Unesite kvadraturu: "; std::cin>>kvadratura;}
                    try{
                        if(namjesten!=0&&namjesten!=1)throw std::domain_error("Neispravan unos podataka");
                        stanovi[koji_stan-1].Postavi(adresa,sprat,brojsoba,namjesten,kvadratura);
                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl;
                        break;
                    }
                    catch(std::domain_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                    }
                }
            }
            }
        } // n==1 kraj
        if(n==2){
            // kupci
            while(true){
                std::cout<<"Izaberite opciju: "<<std::endl;
                std::cout<<" 0 - nazad "<<std::endl;
                std::cout<<" 1 - dodavanje kupca "<<std::endl;
                std::cout<<" 2 - uredjivanje kupaca "<<std::endl;
                std::cout<<" 3 - ispis svih kupaca "<<std::endl;
                std::cout<<" 4 - kraj "<<std::endl;
                int m; std::cin>>m;
                if(m==0) break;
                if(m==4){ std::cout<<std::endl<<std::endl<<"Dovidjenja!"; return 0;}
                if(m==1){ // dodaj kupca
                    while(true){
                    std::string ime;
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Unesite ime i prezime kupca: ";
                    std::getline(std::cin,ime);
                    std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                    int dan,mjesec,godina;
                    UnesiDatum(dan,mjesec,godina);
                    try{
                        kupci.emplace_back(Kupac(ime,Datum(dan,mjesec,godina)));
                        std::cout<<"Kupac je uspjesno dodan!"<<std::endl<<std::endl;
                        break;
                    }
                    catch(std::domain_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                    }
                    }
                }
                if(m==2){
                    std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su: "<<std::endl;
                    for(int i=0;i<kupci.size();i++){
                        std::cout<<" "<<i+1<<" - "; kupci[i].Ispisi(); std::cout<<std::endl;
                    }
                    int polje; std::cin>>polje;
                    while(true){
                    std::string ime;
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Unesite ime i prezime kupca: ";
                    std::getline(std::cin,ime);
                    std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                    int dan,mjesec,godina;
                    UnesiDatum(dan,mjesec,godina);
                    try{
                        kupci[polje-1].Postavi(ime,Datum(dan,mjesec,godina));
                        std::cout<<"Kupac je uspjesno izmijenjen! "<<std::endl<<std::endl;
                        break;
                    }
                    catch(std::domain_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl<<std::endl;
                    }
                    }
                }
                if(m==3){
                    for(int i=0;i<kupci.size();i++) {kupci[i].Ispisi(); std::cout<<std::endl; }
                    std::cout<<std::endl;
                }
            }
        } // kupci kraj
        if(n==3){
            while(true){
            std::cout<<"Izaberite opciju: "<<std::endl;
            std::cout<<" 0 - nazad"<<std::endl;
            std::cout<<" 1 - dodavanje prodaje"<<std::endl;
            std::cout<<" 2 - uredjivanje prodaje"<<std::endl;
            std::cout<<" 3 - ispis prodaja"<<std::endl;
            std::cout<<" 4 - brisanje prodaja"<<std::endl;
            std::cout<<" 5 - kraj"<<std::endl;
            int m; std::cin>>m;
            if(m==0) break;
            if(m==5){ std::cout<<std::endl<<std::endl<<"Dovidjenja!"; return 0;}
            if(m==1){
                while(true){
                    std::cout<<"Izaberite opciju: "<<std::endl;
                    std::cout<<" 0 - nazad"<<std::endl;
                    std::cout<<" 1 - dodavanje potpuno nove prodaje"<<std::endl;
                    std::cout<<" 2 - dodavanje nove prodaje na osnovu arhive"<<std::endl;
                    std::cout<<" 3 - kraj"<<std::endl;
                    int polje; std::cin>>polje;
                    if(polje==0) break;
                    if(polje==3) { std::cout<<std::endl<<std::endl<<"Dovidjenja!"; return 0;}
                    if(polje==1){ // dodavanje potpuno nove
                        while(true){
                        std::cout<<"Unesite ime i prezime agenta prodaje: ";
                        std::string ime; std::cin.ignore(1000,'\n');
                        std::getline(std::cin,ime);
                        std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                        int dan,mjesec,godina;
                        UnesiDatum(dan,mjesec,godina);
                        std::cout<<"Unesite cijenu stana: ";
                        double cijenastana; std::cin>>cijenastana;
                        std::cout<<"Unesite ime kupca: "; std::cin.ignore(1000,'\n');
                        std::string imekupca; std::getline(std::cin,imekupca);
                        std::cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
                        int dank,mjeseck,godinak;
                        UnesiDatum(dank,mjeseck,godinak);
                        std::cout<<"Unesite adresu: ";
                        std::cin.ignore(1000,'\n'); std::string adresa;
                        std::getline(std::cin,adresa);
                        std::cout<<"Unesite sprat: ";
                        int sprat; std::cin>>sprat;
                        std::cout<<"Unesite broj soba: ";
                        int brsoba; std::cin>>brsoba;
                        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                        int namjesten; std::cin>>namjesten;
                        double kvadratura;
                        std::cout<<"Unesite kvadraturu: ";
                        std::cin>>kvadratura;
                        try{
                             if(namjesten!=0&&namjesten!=1)throw std::domain_error("Neispravan unos podataka");
                             try{
                            p.RegistrirajProdaju(ime,cijenastana,Datum(dan,mjesec,godina),Kupac(imekupca,Datum(dank,mjeseck,godinak)),Stan(adresa,sprat,brsoba,namjesten,kvadratura));
                            std::cout<<"Prodaja uspjesno dodana!"<<std::endl<<std::endl;
                            kupci.emplace_back(Kupac(imekupca,Datum(dank,mjeseck,godinak)));
                            stanovi.emplace_back(Stan(adresa,sprat,brsoba,namjesten,kvadratura));
                            break;
                             }
                             catch(std::range_error e){
                                 std::cout<<"Izuzetak: "<<e.what()<<"."<<std::endl;
                                 break;
                             }
                        }
                        catch(std::domain_error e){
                            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                        }
                        }
                    } // potpuno nova prodaja
                    if(polje==2){ // dodavanje nove prodaje na osnovu arhive
                        while(true){
                        std::cout<<"Unesite ime i prezime agenta prodaje: ";
                        std::string ime; std::cin.ignore(1000,'\n');
                        std::getline(std::cin,ime);
                        std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                        int dan,mjesec,godina;
                        std::cin>>dan;
                        char znak;
                        znak=std::cin.get();
                        std::cin>>mjesec;
                        znak=std::cin.get();
                        std::cin>>godina;
                        std::cout<<"Unesite cijenu stana: ";
                        double cijenastana; std::cin>>cijenastana;
                        std::cout<<"Odaberite kupca. Dostupni kupci su: "<<std::endl;
                        for(int i=0;i<kupci.size();i++){
                            std::cout<<" "<<i+1<<" - "; kupci[i].Ispisi(); std::cout<<std::endl;
                        }
                        int f; std::cin>>f;
                        Kupac tmp(kupci[f-1]);
                
                        std::cout<<"Odaberite stan. Dostupni stanovi su: "<<std::endl;
                        for(int i=0;i<stanovi.size();i++){
                            std::cout<<" "<<i+1<<" - ";stanovi[i].Ispisi(); 
                        }
                        int g; std::cin>>g;
                        Stan tmp2=stanovi[g-1];
                        try{
                            p.RegistrirajProdaju(ime,cijenastana,Datum(dan,mjesec,godina),tmp,tmp2);
                            std::cout<<"Prodaja uspjesno dodana!"<<std::endl<<std::endl;
                            break;
                        }
                        catch(std::domain_error e){
                            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                        }
                        catch(std::bad_alloc){
                             return 0;
                        }
                        catch(std::range_error e){
                            std::cout<<"Izuzetak: "<<e.what()<<"."<<std::endl;
                            break;
                        }
                    }
                }
            }
            }// prodaje sugave
            if(m==2){ // uredjivanje prodaja
                std::cout<<"Odaberite prodaju koju želite urediti. Dostupne prodaje su: "<<std::endl;
                p.IspisiSveProdaje2();
                int koja; std::cin>>koja;
                std::cout<<"Izaberite opciju: "<<std::endl;
                std::cout<<" 0 - nazad"<<std::endl;
                std::cout<<" 1 - izmjena agenta"<<std::endl;
                std::cout<<" 2 - izmjena datuma prodaje"<<std::endl;
                std::cout<<" 3 - izmjena kupca"<<std::endl;
                std::cout<<" 4 - izmjena stana"<<std::endl;
                std::cout<<" 5 - izmjena cijene stana"<<std::endl;
                int opcija; std::cin>>opcija;
                if(opcija==3){
                    std::cout<<"Izaberite opciju: "<<std::endl;
                    std::cout<<" 0 - nazad"<<std::endl;
                    std::cout<<" 1 - odabir postojeceg kupca"<<std::endl;
                    std::cout<<" 2 - dodavanje novog kupca"<<std::endl;
                    int opcija2;std::cin>>opcija2;
                    if(opcija2==2){
                        while(true){
                            std::cout<<"Unesite ime i prezime kupca: ";
                            std::string ime;
                            std::cin.ignore(1000,'\n');
                            std::getline(std::cin,ime);
                            std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                            int dank,mjeseck,godinak;
                            UnesiDatum(dank,mjeseck,godinak);
                            try{
                                p.DajProdaju(koja-1).PromijeniKupca(Kupac(ime,Datum(dank,mjeseck,godinak)));
                                std::cout<<"Prodaja je uspjesno izmijenjena! "<<std::endl<<std::endl;
                                break;
                            }
                            catch(std::domain_error e){
                                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                            }
                        }   
                    }
                    if(opcija2==1){
                        std::cout<<"Odaberite kupca. Dostupni kupci su: "<<std::endl;
                        for(int i=0;i<kupci.size();i++){
                            std::cout<<" "<<i+1<<" - "; kupci[i].Ispisi(); std::cout<<std::endl;
                        }
                        int koga; std::cin>>koga;
                        p.DajProdaju(koja-1).PromijeniKupca(Kupac(kupci[koga-1]));
                        std::cout<<"Prodaja je uspjesno izmijenjenja! "<<std::endl<<std::endl;
                    }

                    }
                if(opcija==1){
                        std::cout<<"Unesite ime i prezime agenta prodaje: ";
                        std::string ime;
                        std::cin.ignore(1000,'\n');
                        std::getline(std::cin,ime);
                        p.DajProdaju(koja-1).PromijeniImeAgenta(ime);
                        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                }
                if(opcija==2){
                    std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                    while(true){
                    int dan,mjesec,godina;
                    UnesiDatum(dan,mjesec,godina);
                    try{
                        p.DajProdaju(koja-1).PromijeniDatumKupovine(Datum(dan,mjesec,godina));
                        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                        break;
                    }
                    catch(std::domain_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                    }
                    }
                }
                if(opcija==4){
                    std::cout<<"Izaberite opciju:"<<std::endl;
                    std::cout<<" 0 - nazad"<<std::endl;
                    std::cout<<" 1 - odabir postojeceg stana"<<std::endl;
                    std::cout<<" 2 - dodavanje novog stana"<<std::endl;
                    int opcija2; std::cin>>opcija2;
                    if(opcija2==1){
                        std::cout<<"Odaberite stan. Dostupni stanovi su: "<<std::endl;
                        int koji;
                        for(int i=0;i<stanovi.size();i++){
                            std::cout<<i+1<<" - "; stanovi[i].Ispisi(); std::cout<<std::endl;
                        }
                        std::cin>>koji;
                     
                        p.DajProdaju(koja-1).PromijeniStan(stanovi[koji-1]);
                        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                    }
                    if(opcija2==2){
                        while(true){
                        std::cout<<"Unesite adresu: ";
                        std::string adresa;
                        std::cin.ignore(1000,'\n');
                        std::getline(std::cin,adresa);
                        std::cout<<"Unesite sprat: ";
                        int sprat; std::cin>>sprat;
                        std::cout<<"Unesite broj soba: ";
                        int sobe; 
                        std::cin>>sobe;
                        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne):";
                        int namjesten; std::cin>>namjesten;
                        std::cout<<"Unesite kvadraturu: ";
                        double kvadrat; std::cin>>kvadrat;
                        try{
                            if(namjesten!=0&&namjesten!=1)throw std::domain_error("Neispravan unos podataka");
                            p.DajProdaju(koja-1).PromijeniStan(Stan(adresa,sprat,sobe,namjesten,kvadrat));
                            std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                            break;
                        }
                        catch(std::domain_error e){
                            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                        }
                        
                        }
                    }
                }
                if(opcija==5){
                    while(true){
                    std::cout<<"Unesite cijenu stana: ";
                    double cijena; std::cin>>cijena;
                    try{
                        p.DajProdaju(koja-1).PromijeniCijenuProdaje(cijena);
                        std::cout<<"Prodaja je uspjesno izmijenjena! "<<std::endl<<std::endl;
                        break;
                    }
                    catch(std::domain_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.";
                    }
                    }
                }
                }
                if(m==3){
                    while(true){
                    std::cout<<"Izaberite opciju:"<<std::endl;
                    std::cout<<" 0 - nazad"<<std::endl;
                    std::cout<<" 1 - ispis svih prodaja"<<std::endl;
                    std::cout<<" 2 - ispis prodaja na datum"<<std::endl;
                    std::cout<<" 3 - ispis najranije prodaje"<<std::endl;
                    std::cout<<" 4 - ispis najskuplje prodaje"<<std::endl;
                    std::cout<<" 5 - ispis broja prodaja"<<std::endl;
                    std::cout<<" 6 - ispis broja prodaja po datumu"<<std::endl;
                    std::cout<<" 7 - ispis broja prodaja po agentu"<<std::endl;
                    std::cout<<" 8 - kraj"<<std::endl;
                    int opcija;
                    std::cin>>opcija;
                    if(opcija==0) break;
                    if(opcija==8){ std::cout<<std::endl<<std::endl<<"Dovidjenja!"; return 0;}
                    if(opcija==1){
                        p.IspisiSveProdaje();
                    }
                    if(opcija==2){
                        std::cout<<"Unesite datum (d/m/g): ";
                        int dan,mjesec,godina;
                        while(1){
                        UnesiDatum(dan,mjesec,godina);
                        try{
                            auto d(Datum(dan,mjesec,godina));
                            std::cout<<"Prodaje na datum ";d.Ispisi();std::cout<<" su:"<<std::endl;
                        p.IspisiProdajeNaDatum(d);
                        break;
                        }
                        catch(std::domain_error e){
                            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet"<<std::endl;
                        }
                        }
                    }
                    if(opcija==3){
                        try{
                        p.DajNajranijuProdaju().Ispisi();
                        }
                        catch(std::domain_error e){
                            std::cout<<e.what()<<"."<<std::endl;
                        }
                    }
                    if(opcija==4){
                        try{
                        p.DajNajskupljuProdaju().Ispisi();
                        }
                          catch(std::domain_error e){
                            std::cout<<e.what()<<"."<<std::endl;
                        }
                    }
                    if(opcija==5){
                        std::cout<<"Broj prodaja: "<<p.DajBrojProdaja()<<std::endl;
                    }
                    if(opcija==6){
                        std::cout<<"Unesite datum (d/m/g): ";
                        int dan,mjesec,godina;
                        while(1){
                        UnesiDatum(dan,mjesec,godina);
                        try{
                            auto d(Datum(dan,mjesec,godina));
                            std::cout<<"Broj prodaja na uneseni datum: "<<p.DajBrojProdajaNaDatum(d)<<std::endl;
                        break;
                        }
                        catch(std::domain_error e){
                            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet"<<std::endl;
                        }
                        }  
                    }
                    if(opcija==7){
                        std::cout<<"Unesite ime agenta: ";
                        std::string ime; 
                        std::cin.ignore(1000,'\n');
                        std::getline(std::cin,ime);
                        std::cout<<"Broj prodaja: "<<p.DajBrojProdajaOdAgenta(ime)<<std::endl;
                    }
                    }
                }
                if(m==4){
                    while(true){
                    std::cout<<"Izaberite opciju:"<<std::endl;
                    std::cout<<"0 - nazad"<<std::endl;
                    std::cout<<"1 - brisanje najranije prodaje"<<std::endl;
                    std::cout<<"2 - brisanje prodaja agenta"<<std::endl;
                    std::cout<<"3 - brisanje prodaja po datumu"<<std::endl;
                    std::cout<<"4 - brisanje svih prodaja"<<std::endl;
                    int opcija; std::cin>>opcija;
                    if(opcija==0) break;
                    if(opcija==4){
                        p.IsprazniKolekciju();
                        std::cout<<"Sve prodaje su obrisane."<<std::endl;
                    }
                    if(opcija==1){
                        try{
                        p.ObrisiNajranijuProdaju();
                        std::cout<<"Najranija prodaja je obrisana!"<<std::endl;
                        }
                        catch(std::range_error e){
                            std::cout<<"Izuzetak: "<<e.what()<<"."<<std::endl;
                        }
                    }
                    if(opcija==3){
                        std::cout<<"Unesite datum: ";
                        int dan,mjesec,godina;
                        while(true){
                            try{
                                UnesiDatum(dan,mjesec,godina);
                                auto d(Datum(dan,mjesec,godina));
                                p.ObrisiProdajeNaDatum(d);
                                std::cout<<"Sve prodaje na taj datum su obrisane."<<std::endl;
                                break;
                            }
                            catch(std::domain_error e){
                                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                            }
                        }
                    }
                    if(opcija==2){
                        std::cout<<"Unesite ime agenta: ";
                        std::string ime; std::cin.ignore(1000,'\n');
                        std::getline(std::cin,ime);
                        p.ObrisiProdajeAgenta(ime);
                        std::cout<<"Sve prodaje tog agenta su obrisane."<<std::endl;
                    }
                    
                    }
                }
                
            }

        }

    }
    }
    catch(...){
        return 0;
    }
	return 0;

}    */


int main(){
    try
    {
        Datum d{29, 2, 1988};
        std::string imePrezime{"Niko Nikic"};
        Kupac k1{imePrezime, d};
        Kupac k2{"Marko Markovic", {12,4,1972}};
    }
    catch (std::domain_error &e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }

    try
    {
        Kupac k3{"Ana Anic", {12, -4,1972}};
    }
    catch (std::domain_error &e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
   
    try
    {
        Kupac k1{"Ana-Marija Anic", {12, 4,1972}};
        std::cout << k1.DajImePrezime() << " ";
        k1.DajDatumRodjenja().Ispisi();
        std::cout << std::endl;
        k1.Ispisi();
        std::cout << std::endl;
        k1.Postavi("Ana-Ana Anic", {15,5,1994});
        k1.Ispisi();
        std::cout << std::endl;
    }
    catch (std::domain_error &e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    
    try
    {
        Kupac k1{"Ana*Marija Anic", {12, 4,1972}};
    }
    catch (std::domain_error &e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
   
    try
    {
        Kupac k1{"Ana_Marija Anic", {12, 4,1972}};
    }
    catch (std::domain_error &e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    
    try
    {
        Kupac k1{"Ana@Marija Anic", {12, 4,1972}};
    }
    catch (std::domain_error &e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
}  
