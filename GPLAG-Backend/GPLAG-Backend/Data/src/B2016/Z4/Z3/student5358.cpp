/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;
class Datum{
    int d,m,g;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
int DajDan() const{
    return d;
}
int DajMjesec() const{
    return m;
}
int DajGodinu() const{
    return g;
}
void Ispisi() const{
    cout<<d<<"/"<<m<<"/"<<g;
}

};
Datum::Datum(int dan, int mjesec, int godina){
    int broj_dana[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0 )|| godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw domain_error("Neispravan datum.");
    Datum::d = dan;
    Datum::m = mjesec;
    Datum::g = godina;
}
void Datum::Postavi(int dan, int mjesec, int godina){
    Datum::d=dan;
    Datum::m=mjesec;
    Datum::g=godina;
}
class Kupac{
    string ime_prezime;
    Datum datum_rodjenja;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
std::string DajImePrezime() const{
    return ime_prezime;
}
Datum DajDatumRodjenja() const{
    return datum_rodjenja;
}
void Ispisi() const{
    cout<<ime_prezime<<" (";datum_rodjenja.Ispisi();cout<<")"<<endl;
}

};
Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):datum_rodjenja(datum_rodjenja){
    string s=ime_i_prezime;
    //cout<<ime_i_prezime;
    for(int i=0;i<s.length();i++){
        if( ((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) || s[i]==' ' || s[i]==39 || s[i]=='-');
        else
        throw std::domain_error("Neispravno ime i prezime.");
    }
    Kupac::ime_prezime=ime_i_prezime;
    //this->datum_rodjenja=datum_rodjenja;
}
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    ime_prezime=ime_i_prezime;
    this->datum_rodjenja=datum_rodjenja;
}
class Stan{
    string adresa;
    int sprat,broj_soba;
    bool namjesten;
    double kvadratura;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,
 double kvadratura);
void Postavi(const std::string &adresa, int sprat, int broj_soba,
 bool namjesten, double kvadratura);
std::string DajAdresu() const{
    return adresa;
}
int DajSprat() const{
    return sprat;
}
int DajBrojSoba() const{
    return broj_soba;
}
bool DajNamjesten() const{
    return namjesten;
}
double DajKvadraturu() const{
    return kvadratura;
}
void Ispisi() const{
    cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba;
    if(((broj_soba%10==2 && broj_soba%100!=12) ||( broj_soba%10==3 && broj_soba%100!=13) || (broj_soba%10==4 &&broj_soba%100!=14)))cout<<" sobe. ";
    else std::cout <<" soba. " ;
    cout<<"Kvadratura stana je "<<kvadratura<<" (m^2) i stan ";
    if(namjesten)std::cout << "je namjesten." << std::endl;
    else std::cout << "nije namjesten." << std::endl;
}
};
Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,
 double kvadratura){
     if(sprat<1 || broj_soba<1 || kvadratura<=0)throw domain_error("Neispravan unos podataka.");
     this->adresa=adresa;
     Stan::sprat=sprat;
     Stan::broj_soba=broj_soba;
     Stan::namjesten=namjesten;
     Stan::kvadratura=kvadratura;
 }
 void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba,
 bool namjesten, double kvadratura){
     if(sprat<1 || broj_soba<1 || kvadratura<=0)throw domain_error("Neispravan unos podataka.");
     this->adresa=adresa;
     Stan::sprat=sprat;
     Stan::broj_soba=broj_soba;
     Stan::namjesten=namjesten;
     Stan::kvadratura=kvadratura;
 }
 class Prodaja{
     string ime_agenta_prodaje;
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
void PromijeniKupca(const Kupac &novi_kupac){
    kupac_stana=novi_kupac;
} 
void PromijeniStan(const Stan &novi_stan){
    kupljeni_stan=novi_stan;
}
void PromijeniImeAgenta(const std::string novo_ime){
    ime_agenta_prodaje=novo_ime;
}
void PromijeniDatumKupovine(const Datum &novi_datum){
    datum_prodaje=novi_datum;
}
void PromijeniCijenuProdaje(const double &nova_cijena){
    cijena_stana=nova_cijena;
}
void PomjeriDanUnaprijed();
void PomjeriDanUnazad();
std::string DajImeAgenta() const{
    return ime_agenta_prodaje;
}
std::string DajImeKupca() const{
    return kupac_stana.DajImePrezime();
}
Datum DajDatumProdaje() const{
    return datum_prodaje;
}
double DajCijenuStana() const{
    return cijena_stana;
}
friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
void Ispisi() const;

 };
 Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
 const Datum &datum_prodaje, const Kupac &kupac_stana,
 const Stan &kupljeni_stan):datum_prodaje(datum_prodaje),kupac_stana(kupac_stana),kupljeni_stan(kupljeni_stan){
     Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
     Prodaja::cijena_stana=cijena_stana;
 }
 Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
 int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
 std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
 const std::string &adresa_stana, int sprat_stana, int broj_soba,
 bool namjesten_stan, double broj_kvadrata):datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),kupac_stana(ime_kupca,datum_rodjenja_kupca),
 kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)
 {
     Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
     Prodaja::cijena_stana=cijena_stana;
 }
 void Prodaja::PomjeriDanUnaprijed(){
     int a=datum_prodaje.DajDan();
     try{
         datum_prodaje.Postavi(a+1,datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu());
     }
     catch(domain_error){
         try{
         datum_prodaje.Postavi(1,datum_prodaje.DajMjesec()+1,datum_prodaje.DajGodinu());
         }
         catch(domain_error){
             datum_prodaje.Postavi(1,1,datum_prodaje.DajGodinu()+1);
         }
     }
 }
 int BrojDana(int mjesec, int godina) {
 int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
 broj_dana[1]++;
 return broj_dana[mjesec - 1];
}

 void Prodaja::PomjeriDanUnazad(){
     int a=datum_prodaje.DajDan();
     try{
         datum_prodaje.Postavi(a-1,datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu());
     }
     catch(domain_error){
         try{
             int c=BrojDana(datum_prodaje.DajMjesec()-1,datum_prodaje.DajGodinu());
         datum_prodaje.Postavi(c,datum_prodaje.DajMjesec()-1,datum_prodaje.DajGodinu());
         }
         catch(domain_error){
             datum_prodaje.Postavi(31,12,datum_prodaje.DajGodinu()-1);
         }
     }
 }
 bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
     if(p1.datum_prodaje.DajGodinu()<p2.datum_prodaje.DajGodinu())return true;
     else if(p1.datum_prodaje.DajGodinu()==p2.datum_prodaje.DajGodinu()){
         if(p1.datum_prodaje.DajMjesec()< p2.datum_prodaje.DajMjesec())return true;
         else if(p1.datum_prodaje.DajMjesec()== p2.datum_prodaje.DajMjesec()){
            if( p1.datum_prodaje.DajDan()<p2.datum_prodaje.DajDan()) return true;
         }
     }
     return false;
 }
 bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
     return p1.cijena_stana<p2.cijena_stana;
 }
 void Prodaja::Ispisi() const{
     cout<<setw(32)<<left<<"Ime agenta:";cout<<this->DajImeAgenta()<<endl;
     cout<<setw(32)<<"Ime kupca:";this->kupac_stana.Ispisi();;
     cout<<setw(32)<<"Zakazani datum prodaje:";this->datum_prodaje.Ispisi();cout<<endl;
     cout<<setw(32)<<"Cijena stana:";cout<<this->DajCijenuStana()<<endl;
     cout<<setw(32)<<"Informacije o stanu:";cout<<endl;
     this->kupljeni_stan.Ispisi();cout<<endl;
 }
 class Prodaje{
     const int max_broj_prodaja;
     int broj_reg_prodaja;
     Prodaja ** prodaj;
     public:
   explicit Prodaje(int max_broj_prodaja);
Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
~Prodaje();
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
void RegistrirajProdaju(Prodaja *prodaja);
int DajBrojProdaja() const{
    return broj_reg_prodaja;
}
int DajBrojProdajaNaDatum(const Datum &datum) const;
int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
Prodaja &DajProdaju(int a){
    if(a<0 || a>broj_reg_prodaja)throw("nesta");
    return *prodaj[a];
}
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

 };
 Prodaje::Prodaje(int max_broj_prodaja):max_broj_prodaja(max_broj_prodaja),broj_reg_prodaja(0){
     prodaj=new Prodaja*[max_broj_prodaja];
     for(int i=0;i<max_broj_prodaja;i++)prodaj[i]=0;
 }
 Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : max_broj_prodaja(spisak_prodaja.size()), broj_reg_prodaja(max_broj_prodaja) {
    prodaj=new Prodaja*[spisak_prodaja.size()];
    for(int i(0);i<spisak_prodaja.size();i++) {
        prodaj[i]=nullptr;
    }
    int i(0);
    for(auto it(spisak_prodaja.begin());it!=spisak_prodaja.end();it++) {
        prodaj[i]=new Prodaja(*it);
        i++;
    }
}
 Prodaje::~Prodaje(){
     for(int i=0;i<broj_reg_prodaja;i++)delete prodaj[i];
     delete []prodaj;
 }
 Prodaje::Prodaje(const Prodaje &prodaje):max_broj_prodaja(prodaje.max_broj_prodaja),broj_reg_prodaja(prodaje.broj_reg_prodaja){
     Prodaje::prodaj=new Prodaja*[max_broj_prodaja];
     for(int i=0;i<max_broj_prodaja;i++)Prodaje::prodaj[i]=0;
     for(int i=0;i<broj_reg_prodaja;i++)Prodaje::prodaj[i]=new Prodaja(*prodaje.prodaj[i]);
 }
 Prodaje::Prodaje (Prodaje &&prodaje): max_broj_prodaja(prodaje.max_broj_prodaja),broj_reg_prodaja(prodaje.broj_reg_prodaja),prodaj(prodaje.prodaj) {
    prodaje.prodaj = nullptr;
    prodaje.broj_reg_prodaja = 0;
}
 Prodaje &Prodaje::operator =(const Prodaje &prodaje){
     if(max_broj_prodaja!=prodaje.max_broj_prodaja) throw "Izovrisni i odredisni objekat nisu istog kapaciteta.";
    if(&prodaje==this) return *this;
    IsprazniKolekciju();
    for(int i(0); i<max_broj_prodaja; i++) Prodaje::prodaj[i]=0;
    for(int i(0); i<prodaje.broj_reg_prodaja; i++) Prodaje::prodaj[i]=new Prodaja(*prodaje.prodaj[i]);
    Prodaje::broj_reg_prodaja=prodaje.broj_reg_prodaja;
    return *this;
 }
 Prodaje &Prodaje::operator =(Prodaje &&prodaje){
     if(prodaje.max_broj_prodaja != max_broj_prodaja)
 throw std::logic_error("Prodaje nesaglasnih kapaciteta!");
 std::swap(broj_reg_prodaja, prodaje.broj_reg_prodaja);
 std::swap(prodaj, prodaje.prodaj);
 return *this;

 }
 void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,
 double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
const Stan &kupljeni_stan){
    if(broj_reg_prodaja==max_broj_prodaja) throw range_error("Dostignut maksimalni broj prodaja.");
    prodaj[broj_reg_prodaja++]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,
int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
 const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
 int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
     if(broj_reg_prodaja==max_broj_prodaja) throw range_error("Dostignut maksimalni broj prodaja.");
     Datum datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje);
     Kupac kupac_stana(ime_kupca,datum_rodjenja_kupca);
     Stan kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
     prodaj[broj_reg_prodaja++]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
 }
void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(broj_reg_prodaja==max_broj_prodaja) throw range_error("Dostignut maksimalni broj prodaja.");
    prodaj[broj_reg_prodaja++]=prodaja;
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    //int r=0;
    cout<<"Prodaje na datum ";datum.Ispisi();cout<<" su:"<<endl;
    for(int i=0;i<broj_reg_prodaja;i++){
        if(prodaj[i]!=nullptr){
            if(prodaj[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu() && prodaj[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && prodaj[i]->DajDatumProdaje().DajDan()==datum.DajDan()){
            //cout<<r<<"."<<endl;
        prodaj[i]->Ispisi();
        //r++;
            }
        }
    }
}
void Prodaje::IspisiSveProdaje() const{
    sort(prodaj,prodaj+DajBrojProdaja(),[](const Prodaja *p1,const Prodaja *p2){
                            if(p1->DajDatumProdaje().DajGodinu()<p2->DajDatumProdaje().DajGodinu())return true;
     else if(p1->DajDatumProdaje().DajGodinu()==p2->DajDatumProdaje().DajGodinu()){
         if(p1->DajDatumProdaje().DajMjesec()< p2->DajDatumProdaje().DajMjesec())return true;
         else if(p1->DajDatumProdaje().DajMjesec()== p2->DajDatumProdaje().DajMjesec()){
            if( p1->DajDatumProdaje().DajDan()<p2->DajDatumProdaje().DajDan()) return true;
            else if(p1->DajDatumProdaje().DajDan()==p2->DajDatumProdaje().DajDan()){
                if(p1->DajImeKupca()<p2->DajImeKupca())return true;
            }
         }
     }
     return false;});
    for(int i=0;i<broj_reg_prodaja;i++){
        //if(prodaj[i]!=nullptr){
            //cout<<i+1<<"."<<endl;
        prodaj[i]->Ispisi();
    }
}
Prodaja Prodaje::DajNajranijuProdaju() const{
    auto a=std::min_element(prodaj,prodaj+DajBrojProdaja(),[](const Prodaja *p1,const Prodaja *p2){
                            if(p1->DajDatumProdaje().DajGodinu()<p2->DajDatumProdaje().DajGodinu())return true;
     else if(p1->DajDatumProdaje().DajGodinu()==p2->DajDatumProdaje().DajGodinu()){
         if(p1->DajDatumProdaje().DajMjesec()< p2->DajDatumProdaje().DajMjesec())return true;
         else if(p1->DajDatumProdaje().DajMjesec()== p2->DajDatumProdaje().DajMjesec()){
            if( p1->DajDatumProdaje().DajDan()<p2->DajDatumProdaje().DajDan()) return true;
         }
     }
     return false;});
    return **a;
}
Prodaja &Prodaje::DajNajranijuProdaju() {
    auto a=std::min_element(prodaj,prodaj+DajBrojProdaja(),[](const Prodaja *p1,const Prodaja *p2){
                            if(p1->DajDatumProdaje().DajGodinu()<p2->DajDatumProdaje().DajGodinu())return true;
     else if(p1->DajDatumProdaje().DajGodinu()==p2->DajDatumProdaje().DajGodinu()){
         if(p1->DajDatumProdaje().DajMjesec()< p2->DajDatumProdaje().DajMjesec())return true;
         else if(p1->DajDatumProdaje().DajMjesec()== p2->DajDatumProdaje().DajMjesec()){
            if( p1->DajDatumProdaje().DajDan()<p2->DajDatumProdaje().DajDan()) return true;
         }
     }
     return false;});
    return **a;
}
Prodaja &Prodaje::DajNajskupljuProdaju(){
    auto a=std::max_element(prodaj,prodaj+DajBrojProdaja(),[](const Prodaja *p1,const Prodaja *p2){
                            if(p1->DajCijenuStana()<p2->DajCijenuStana())return true;
     return false;});
    return **a;
}
Prodaja Prodaje::DajNajskupljuProdaju() const{
    auto a=std::max_element(prodaj,prodaj+DajBrojProdaja(),[](const Prodaja *p1,const Prodaja *p2){
                            if(p1->DajCijenuStana()<p2->DajCijenuStana())return true;
     return false;});
    return **a;
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    if(broj_reg_prodaja==0)throw std::domain_error("Nema registriranih prodaja.");
    return std::count_if(prodaj,prodaj+broj_reg_prodaja,[datum](Prodaja *p1){
        if(p1->DajDatumProdaje().DajDan()==datum.DajDan()){
            if(p1->DajDatumProdaje().DajMjesec()==datum.DajMjesec()){
                if(p1->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
                    return true;
                }
            }
        }
        return false;
    });
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    if(broj_reg_prodaja==0)throw std::domain_error("Nema registriranih prodaja.");
    return std::count_if(prodaj,prodaj+broj_reg_prodaja,[ime_agenta](Prodaja *p1){
        if(p1->DajImeAgenta()==ime_agenta)return true;
        return false;
    });
}
void Prodaje::ObrisiNajranijuProdaju(){
    if(broj_reg_prodaja==0)throw std::range_error("Prazna kolekcija.");
    Datum datum=this->DajNajranijuProdaju().DajDatumProdaje();
    int br=0;
    for(int i=0;i<broj_reg_prodaja;i++){
        if(prodaj[i]->DajDatumProdaje().DajDan()==datum.DajDan()){
            if(prodaj[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec()){
                if(prodaj[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
                    delete prodaj[i];
                    prodaj[i]=nullptr;
                    br++;
                }
            }
        }
    }
    remove(prodaj,prodaj+broj_reg_prodaja,nullptr);
    broj_reg_prodaja=broj_reg_prodaja-br;
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    if(broj_reg_prodaja==0)throw std::range_error("Prazna kolekcija.");
    int br=0;
    for(int i=0;i<broj_reg_prodaja;i++){
        if(prodaj[i]->DajImeAgenta()==ime_agenta){
            delete prodaj[i];
            prodaj[i]=nullptr;
            br++;
        }
    }
    remove(prodaj,prodaj+broj_reg_prodaja,nullptr);
    broj_reg_prodaja=broj_reg_prodaja-br;
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    if(broj_reg_prodaja==0)throw std::range_error("Prazna kolekcija.");
    int br=0;
    for(int i=0;i<broj_reg_prodaja;i++){
        if(prodaj[i]->DajDatumProdaje().DajDan()==datum.DajDan()){
            if(prodaj[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec()){
                if(prodaj[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
                    delete prodaj[i];
                    prodaj[i]=nullptr;
                    br++;
                }
            }
        }
    }
    remove(prodaj,prodaj+broj_reg_prodaja,nullptr);
    broj_reg_prodaja=broj_reg_prodaja-br;
}
void Prodaje::IsprazniKolekciju(){
    for(int i(0); i<broj_reg_prodaja; i++) delete prodaj[i];
    broj_reg_prodaja=0;
}
int main()
{
    /*Datum d(31,3,1997);
    //d.Ispisi();
    Kupac adem("adem cogic",{31,3,1997});
    //adem.Ispisi();
    std::cout  << std::endl;
    Stan lamijin("Hamdije Cemerlica 16",5,13,true,78.05);
    //lamijin.Ispisi();
    Prodaja s("huso",78000,d,adem,lamijin);
    s.Ispisi();*/
    std::vector<Stan>s ;
    std::vector<Kupac>v;
    Prodaje p(20);
    cout<<"Dobrodosli!";
    cout<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    POCETAK:
    cout<<"Izaberite opciju:"<<endl;
 cout<<" 0 - kraj"<<endl;
 cout<<" 1 - uredjivanje stanova"<<endl;
 cout<<" 2 - uredjivanje kupaca"<<endl;
 cout<<" 3 - uredjivanje prodaja"<<endl;
 int opcija;
 cin>>opcija;
 switch(opcija){
 case 0:{
     cout<<endl<<endl<<"Dovidjenja!"<<endl;
     return 0;
 }
 case 1:{
     NASTAN:
     cout<<"Izaberite opciju:"<<endl;
 cout<<" 0 - nazad"<<endl;
 cout<<" 1 - dodavanje stana"<<endl;
 cout<<" 2 - uredjivanje stanova"<<endl;
 cout<<" 3 - ispis svih stanova"<<endl;
 cout<<" 4 - kraj"<<endl;
 int opcija;
 cin>>opcija;
 switch(opcija){
     case 0:{
         goto POCETAK;
     }
     case 1:{
         PONOVOUNESI:
         //bool unesen_ispravno=false;
         //while(unesen_ispravno){
         cout<<"Unesite adresu: ";
         string adresa;
         cin.clear();
         cin.ignore(10000,'\n');
         getline(cin,adresa);
         cout<<"Unesite sprat: ";
         int sprat;
         cin>>sprat;
         cout<<"Unesite broj soba: ";
         int broj_soba;
         cin>>broj_soba;
         cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
         int nam;
         cin>>nam;
         cout<<"Unesite kvadraturu: ";
         double kvadratura;
         cin>>kvadratura;
         bool namjesten=true;
         if(nam==0)namjesten=false;
         try{
             if(nam>1 || nam<0)throw domain_error("Neispravan unos podataka.");
             Stan novi_stan(adresa,sprat,broj_soba,namjesten,kvadratura);
             //unesen_ispravno=true;
             cout<<"Stan je uspjesno dodan!"<<endl;
             cout<<" "<<endl;
             s.push_back(novi_stan);
             goto NASTAN;
         }
         catch(domain_error e){
             cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             goto PONOVOUNESI;
         }
         //}
     }
     case 2:{
         cout<<"Odaberite stan. ";
        cout<<"Dostupni stanovi su:"<<endl;
        for(int i=0;i<s.size();i++){
                cout<<" "<<i+1<<" - ";
            s[i].Ispisi();
        }
        cout<<" "<<endl;
        int koji;
        cin>>koji;
        GLUPOST:
        cout<<"Odaberite polje koje zelite urediti:"<<endl;
cout<<" 0 - nazad"<<endl;
cout<<" 1 - adresa"<<endl;
cout<<" 2 - sprat"<<endl;
cout<<" 3 - broj soba"<<endl;
cout<<" 4 - da li je stan namjesten"<<endl;
cout<<" 5 - kvadratura"<<endl;
cout<<" 6 - sve"<<endl;
int opcija;
cin>>opcija;
        switch(opcija){
            case 0:{
                goto NASTAN;
            }
            case 1:{
                PONADRESA:
                cout<<"Unesite adresu: ";
                string nova_adresa;
                cin.clear();
                cin.ignore(100000,'\n');
                getline(cin,nova_adresa);
                try{
                s[koji-1].Postavi(nova_adresa,s[koji-1].DajSprat(),s[koji-1].DajBrojSoba(),s[koji-1].DajNamjesten(),s[koji-1].DajKvadraturu());
                cout<<"Stan je uspjesno izmijenjen!"<<endl;
                cout<<" "<<endl;
                goto NASTAN;
                }
                catch(domain_error e){
                    cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             goto PONADRESA;
                }
            }
            case 2:{
                PONSPRAT:
                cout<<"Unesite sprat: ";
                int novi_sprat;
                cin>>novi_sprat;
                try{
                s[koji-1].Postavi(s[koji-1].DajAdresu(),novi_sprat,s[koji-1].DajBrojSoba(),s[koji-1].DajNamjesten(),s[koji-1].DajKvadraturu());
                cout<<"Stan je uspjesno izmijenjen!"<<endl;
                cout<<" "<<endl;
                goto NASTAN;
                }
                catch(domain_error e){
                    cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             goto PONSPRAT;
                }
            }
            case 3:{
                PONBRSOBA:
                cout<<"Unesite broj soba: ";
                int novi_broj_soba;
                cin>>novi_broj_soba;
                try{
                s[koji-1].Postavi(s[koji-1].DajAdresu(),s[koji-1].DajSprat(),novi_broj_soba,s[koji-1].DajNamjesten(),s[koji-1].DajKvadraturu());
                cout<<"Stan je uspjesno izmijenjen!"<<endl;
                cout<<" "<<endl;
                goto NASTAN;
                }
                catch(domain_error e){
                    cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             goto PONBRSOBA;
                }
            }
            case 4:{
                PONNAMJESTEN:
                cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                int nam;
                cin>>nam;
                bool namjesten=true;
                if(nam==0)namjesten=false;
                //else if(nam==1)namjesten=true;
                try{
                    if(nam>1 || nam<0)throw domain_error("Neispravan unos podataka.");
                s[koji-1].Postavi(s[koji-1].DajAdresu(),s[koji-1].DajSprat(),s[koji-1].DajBrojSoba(),namjesten,s[koji-1].DajKvadraturu());
                cout<<"Stan je uspjesno izmijenjen!"<<endl;
                cout<<" "<<endl;
                goto NASTAN;
                }
                catch(domain_error e){
                    cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             goto PONNAMJESTEN;
                }
            }
            case 5:{
                PONKVADRATURA:
                cout<<"Unesite kvadraturu: ";
                double kvadratura;
                cin>>kvadratura;
                try{
                s[koji-1].Postavi(s[koji-1].DajAdresu(),s[koji-1].DajSprat(),s[koji-1].DajBrojSoba(),s[koji-1].DajNamjesten(),kvadratura);
                cout<<"Stan je uspjesno izmijenjen!"<<endl;
                cout<<" "<<endl;
                goto NASTAN;
                }
                catch(domain_error e){
                    cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             goto PONKVADRATURA;
                }
            }
            case 6:{
                PONOVOSVE:
                cout<<"Unesite adresu: ";
         string adresa;
         cin.clear();
         cin.ignore(10000,'\n');
         getline(cin,adresa);
         cout<<"Unesite sprat: ";
         int sprat;
         cin>>sprat;
         cout<<"Unesite broj soba: ";
         int broj_soba;
         cin>>broj_soba;
         cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
         int nam;
         cin>>nam;
         cout<<"Unesite kvadraturu: ";
         double kvadratura;
         cin>>kvadratura;
         cin.clear();
         //cin.ignore(10000,'\n');
         bool namjesten;
         if(nam==0)namjesten=false;
         else if(nam==1)namjesten=true;
         try{
             if(nam>1)throw domain_error("Neispravan unos podataka");
             s[koji-1].Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
             cout<<"Stan je uspjesno izmijenjen!"<<endl;
             cout<<" "<<endl;
             goto NASTAN;
         }
         catch(domain_error e){
             cout<<"Izuzetak: "<<e.what()<<endl;
             goto PONOVOSVE;
         }
            }
        }
     }
     case 3:{
         for(int i=0;i<s.size();i++){
                cout<<i+1<<". ";
            s[i].Ispisi();
        //cout<<endl;
        }
        cout<<" "<<endl;
        goto NASTAN;
     }
     case 4:{
         cout<<"Dovidjenja!";
        return 0;
     }
 }
 }
 case 2:{
     NAKUPAC:
     cout<<"Izaberite opciju:"<<endl;
cout<<" 0 - nazad"<<endl;
cout<<" 1 - dodavanje kupca"<<endl;
cout<<" 2 - uredjivanje kupaca"<<endl;
cout<<" 3 - ispis svih kupaca"<<endl;
cout<<" 4 - kraj"<<endl;
     int opcija;
     cin>>opcija;
     switch(opcija){
         case 0:{
             goto POCETAK;
         }
         case 1:{
             PONKUPAC:
             cout<<"Unesite ime i prezime kupca: ";
             string ime;
             cin.clear();
             cin.ignore(100000,'\n');
             getline(cin,ime);
             cout<<"Unesite datum rodjenja (formata d/m/g): ";
             int dan,mjesec,godina;
             char c1,c2;
             cin>>dan;
             cin>>c1;
             cin>>mjesec;
             cin>>c2;
             cin>>godina;
             if(c1!='/' || c2!='/')throw domain_error("Neispravan datum.");
             try{
             Datum datum_rodjenja(dan,mjesec,godina);
             }
             catch(domain_error e){
                 cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             goto PONKUPAC;
             }
             try{
             Kupac k(ime,{dan,mjesec,godina});
             cout<<"Kupac je uspjesno dodan!"<<endl<<endl;
             v.push_back(k);
             goto NAKUPAC;
             }
             catch(domain_error e){
                 cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             goto PONKUPAC;
             }
             
         }
         case 2:{
             cout<<"Odaberite kupca kojeg zelite urediti. ";
             cout<<"Dostupni kupci su:"<<endl;
             for(int i=0;i<v.size();i++){
                cout<<" "<<i+1<<" - ";
            v[i].Ispisi();
        }
        int koji;
        cin>>koji;
        PONUREDJIVANJE:
        cout<<"Unesite ime i prezime kupca: ";
        string novo_ime;
        cin.clear();
        cin.ignore(10000,'\n');
        getline(cin,novo_ime);
        cout<<"Unesite datum rodjenja (formata d/m/g): ";
        int dan,mjesec,godina;
             char c1,c2;
             cin>>dan;
             cin>>c1;
             cin>>mjesec;
             cin>>c2;
             cin>>godina;
             if(c1!='/' || c2!='/')throw domain_error("Neispravan datum.");
             try{
                 v[koji-1].Postavi(novo_ime,{dan,mjesec,godina});
                 cout<<"Kupac je uspjesno izmijenjen!"<<endl<<endl;
                 goto NAKUPAC;
             }
             catch(domain_error e){
                 cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             goto PONUREDJIVANJE;
             }
             
         }
         case 3:{
             for(int i=0;i<v.size();i++){
                //cout<<i+1<<".";
            v[i].Ispisi();
        //cout<<endl;
        }
        cout<<endl;
        goto NAKUPAC;
         }
         case 4:{
             cout<<"Dovidjenja!";
             return 0;
         }
     }
 }
 case 3:{
     NAZAD1:
     cout<<"Izaberite opciju:"<<endl;
cout<<" 0 - nazad"<<endl;
cout<<" 1 - dodavanje prodaje"<<endl;
cout<<" 2 - uredjivanje prodaje"<<endl;
cout<<" 3 - ispis prodaja"<<endl;
cout<<" 4 - brisanje prodaja"<<endl;
cout<<" 5 - kraj"<<endl;
int opcija;
cin>>opcija;
switch(opcija){
    case 0:{
        goto POCETAK;
    }
    case 1:{
        NOVPRODAJE:
        cout<<"Izaberite opciju:"<<endl;
cout<<" 0 - nazad"<<endl;
cout<<" 1 - dodavanje potpuno nove prodaje"<<endl;
cout<<" 2 - dodavanje nove prodaje na osnovu arhive"<<endl;
cout<<" 3 - kraj"<<endl;
int opcija;
cin>>opcija;
switch(opcija){
    case 0:{
        goto NAZAD1;
    }
    case 1:{
        PONURD:
        cout<<"Unesite ime i prezime agenta prodaje: ";
        string ime_agenta_prodaje;
        cin.clear();
        cin.ignore(10000,'\n');
        getline(cin,ime_agenta_prodaje);
        cout<<"Unesite datum prodaje (formata d/m/g): ";
        int dan,mjesec,godina;
             char c1,c2;
             cin>>dan;
             cin>>c1;
             cin>>mjesec;
             cin>>c2;
             cin>>godina;
             if(c1!='/' || c2!='/')throw domain_error("Neispravan datum.");
             try{
             Datum datum_prodaje(dan,mjesec,godina);
             }
             catch(domain_error e){
                 cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             //goto PONKUPAC;
             }
             cout<<"Unesite cijenu stana: ";
             int cijena_stana;
             cin>>cijena_stana;
             cout<<"Unesite ime kupca: ";
             string ime_kupca;
        cin.clear();
        cin.ignore(10000,'\n');
        getline(cin,ime_kupca);
        cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
        int dan1,mjesec1,godina1;
             char c3,c4;
             cin>>dan1;
             cin>>c3;
             cin>>mjesec1;
             cin>>c4;
             cin>>godina1;
             if(c3!='/' || c4!='/')throw domain_error("Neispravan datum.");
             try{
             Datum datum_rodjenja_kupca(dan,mjesec,godina);
             }
             catch(domain_error e){
                 cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             //goto PONKUPAC;
             }
             cout<<"Unesite adresu: ";
             string adresa;
        cin.clear();
        cin.ignore(10000,'\n');
        getline(cin,adresa);
        cout<<"Unesite sprat: ";
        int sprat;
        cin>>sprat;
        cout<<"Unesite broj soba: ";
        int broj_soba;
        cin>>broj_soba;
        cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
        int nam;
        bool namjesten=true;
        cin>>nam;
        if(nam==0)namjesten=false;
         //else if(nam==1)namjesten=true;
         cout<<"Unesite kvadraturu: ";
         double kvadratura;
         cin>>kvadratura;
         try{
             if(nam<0 || nam>1)throw domain_error("Neispravan");
             p.RegistrirajProdaju(ime_agenta_prodaje,cijena_stana,{dan,mjesec,godina},{ime_kupca,{dan1,mjesec1,godina1}},{adresa,sprat,broj_soba,namjesten,kvadratura});
            cout<<"Prodaja uspjesno dodana!"<<endl<<endl;
            s.push_back({adresa,sprat,broj_soba,namjesten,kvadratura});
            v.push_back({ime_kupca,{dan1,mjesec1,godina1}});
            goto NOVPRODAJE;
             
         }
         catch(domain_error e){
             cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             goto PONURD;
         }
    }
    case 2:{
        cout<<"Unesite ime i prezime agenta prodaje: ";
        string ime_agenta_prodaje;
        cin.clear();
        cin.ignore(10000,'\n');
        getline(cin,ime_agenta_prodaje);
        cout<<"Unesite datum prodaje (formata d/m/g): ";
        int dan,mjesec,godina;
             char c1,c2;
             cin>>dan;
             cin>>c1;
             cin>>mjesec;
             cin>>c2;
             cin>>godina;
             if(c1!='/' || c2!='/')throw domain_error("Neispravan datum.");
             try{
             Datum datum_prodaje(dan,mjesec,godina);
             }
             catch(domain_error e){
                 cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             //goto PONKUPAC;
             }
             cout<<"Unesite cijenu stana: ";
             int cijena_stana;
             cin>>cijena_stana;
             cout<<"Odaberite kupca. ";
             cout<<"Dostupni kupci su:"<<endl;
             for(int i=0;i<v.size();i++){
                cout<<" "<<i+1<<" - ";
            v[i].Ispisi();
        //cout<<endl;
        }
        int koji;
        cin>>koji;
        cout<<"Odaberite stan. ";
        cout<<"Dostupni stanovi su:"<<endl;
        for(int i=0;i<s.size();i++){
                cout<<" "<<i+1<<" - ";
            s[i].Ispisi();
        }
        int koji_stan;
        cin>>koji_stan;
        p.RegistrirajProdaju(ime_agenta_prodaje,cijena_stana,{dan,mjesec,godina},{v[koji-1].DajImePrezime(),v[koji-1].DajDatumRodjenja()},{s[koji_stan-1].DajAdresu(),s[koji_stan-1].DajSprat(),s[koji_stan-1].DajBrojSoba(),s[koji_stan-1].DajNamjesten(),s[koji_stan-1].DajKvadraturu()});
        cout<<"Prodaja uspjesno dodana!"<<endl<<endl;
            goto NOVPRODAJE;
    }
    case 3:{
            cout<<"Dovidjenja!"<<endl;
    }
}
    }
    case 2:{
        cout<<"Odaberite prodaju koju želite urediti. ";
        cout<<"Dostupne prodaje su:"<<endl;
        for(int i=0;i<p.DajBrojProdaja();i++){
            cout<<i+1<<"."<<endl;
            Prodaja pom=p.DajProdaju(i);
            pom.Ispisi();
            cout<<endl;
        }
        int koja_prodaja;
        cin>>koja_prodaja;
        cout<<"Izaberite opciju:"<<endl;
cout<<" 0 - nazad"<<endl;
cout<<" 1 - izmjena agenta"<<endl;
cout<<" 2 - izmjena datuma prodaje"<<endl;
cout<<" 3 - izmjena kupca"<<endl;
cout<<" 4 - izmjena stana"<<endl;
cout<<" 5 - izmjena cijene stana"<<endl;
int opcija;
cin>>opcija;
switch(opcija){
    case 0:{
        goto NAZAD1;
    }
    case 1:{
            cout<<"Unesite ime i prezime agenta prodaje: ";
            string ime_agenta_prodaje;
            cin.clear();
            cin.ignore(10000,'\n');
            getline(cin,ime_agenta_prodaje);
            p.DajProdaju(koja_prodaja-1).PromijeniImeAgenta(ime_agenta_prodaje);
            cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
                 goto NAZAD1;
    }
    case 2:{
        cout<<"Unesite datum prodaje (formata d/m/g): ";
        int dan,mjesec,godina;
             char c1,c2;
             cin>>dan;
             cin>>c1;
             cin>>mjesec;
             cin>>c2;
             cin>>godina;
             if(c1!='/' || c2!='/')throw domain_error("Neispravan datum.");
             try{
                 p.DajProdaju(koja_prodaja-1).PromijeniDatumKupovine({dan,mjesec,godina});
                 cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
                 goto NAZAD1;
             }
             catch(domain_error e){
                 cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             }
    }
    case 3:{
        cout<<"Izaberite opciju:"<<endl;
cout<<" 0 - nazad"<<endl;
cout<<" 1 - odabir postojeceg kupca"<<endl;
cout<<" 2 - dodavanje novog kupca"<<endl;
int opcija;
cin>>opcija;
switch(opcija){
    case 0:{
        goto NAZAD1;
    }
    case 1:{
        cout<<"Odaberite kupca. ";
             cout<<"Dostupni kupci su:"<<endl;
             for(int i=0;i<v.size();i++){
                cout<<i+1<<".";
            v[i].Ispisi();
        //cout<<endl;
        }
        int koji_ku;
        cin>>koji_ku;
        p.DajProdaju(koja_prodaja-1).PromijeniKupca(v[koji_ku-1]);
        cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
        goto NAZAD1;
    }
    case 2:{
        PON26:
        cout<<"Unesite ime i prezime kupca: ";
             string ime;
             cin.clear();
             cin.ignore(100000,'\n');
             getline(cin,ime);
             cout<<"Unesite datum rodjenja (formata d/m/g): ";
             int dan,mjesec,godina;
             char c1,c2;
             cin>>dan;
             cin>>c1;
             cin>>mjesec;
             cin>>c2;
             cin>>godina;
             if(c1!='/' || c2!='/')throw domain_error("Neispravan datum.");
             try{
             Datum datum_rodjenja(dan,mjesec,godina);
             }
             catch(domain_error e){
                 cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             goto PON26;
             }
             try{
             Kupac k(ime,{dan,mjesec,godina});
             v.push_back(k);
             p.DajProdaju(koja_prodaja-1).PromijeniKupca(k);
             cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
             goto NAZAD1;
             }
             catch(domain_error e){
                 cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             goto PON26;
             }
    }
}
    }
    case 4:{
        cout<<"Izaberite opciju:"<<endl;
cout<<" 0 - nazad"<<endl;
cout<<" 1 - odabir postojeceg stana"<<endl;
cout<<" 2 - dodavanje novog stana"<<endl;
int opcija;
cin>>opcija;
switch(opcija){
    case 0:{
        goto NAZAD1;
    }
    case 1:{
        cout<<"Odaberite stan. ";
        cout<<"Dostupni stanovi su: "<<endl;
        for(int i=0;i<s.size();i++){
                cout<<i+1<<".";
            s[i].Ispisi();
        }
        int koji;
        cin>>koji;
        p.DajProdaju(koja_prodaja-1).PromijeniStan(s[koji-1]);
        cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
        goto NAZAD1;
    }
    case 2:{
        PONOVOUNESI56:
        cout<<"Unesite adresu: ";
         string adresa;
         cin.clear();
         cin.ignore(10000,'\n');
         getline(cin,adresa);
         cout<<"Unesite sprat: ";
         int sprat;
         cin>>sprat;
         cout<<"Unesite broj soba: ";
         int broj_soba;
         cin>>broj_soba;
         cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
         int nam;
         cin>>nam;
         cout<<"Unesite kvadraturu: ";
         double kvadratura;
         cin>>kvadratura;
         bool namjesten=true;
         if(nam==0)namjesten=false;
         try{
             if(nam>1 || nam<0)throw domain_error("Neispravan unos podataka.");
             Stan novi_stan(adresa,sprat,broj_soba,namjesten,kvadratura);
             //unesen_ispravno=true;
             s.push_back(novi_stan);
             p.DajProdaju(koja_prodaja-1).PromijeniStan(novi_stan);
             cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
             goto NAZAD1;
         }
         catch(domain_error e){
             cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             goto PONOVOUNESI56;
         }
    }
}
    }
    case 5:{
        cout<<"Unesite cijenu stana: ";
        int nova_cijena;
        cin>>nova_cijena;
        p.DajProdaju(koja_prodaja-1).PromijeniCijenuProdaje(nova_cijena);
        cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
        goto NAZAD1;
    }
}
    }
    case 3:{
        VELIKI:
        cout<<"Izaberite opciju:"<<endl;
cout<<" 0 - nazad"<<endl;
cout<<" 1 - ispis svih prodaja"<<endl;
cout<<" 2 - ispis prodaja na datum"<<endl;
cout<<" 3 - ispis najranije prodaje"<<endl;
cout<<" 4 - ispis najskuplje prodaje"<<endl;
cout<<" 5 - ispis broja prodaja"<<endl;
cout<<" 6 - ispis broja prodaja po datumu"<<endl;
cout<<" 7 - ispis broja prodaja po agentu"<<endl;
cout<<" 8 - kraj"<<endl;
int opcija;
cin>>opcija;
switch(opcija){
    case 0:{
        goto NAZAD1;
    }
    case 1:{
        p.IspisiSveProdaje();
        goto VELIKI;
    }
    case 2:{
        PON654:
        cout<<"Unesite datum (d/m/g): ";
        int dan,mjesec,godina;
             char c1,c2;
             cin>>dan;
             cin>>c1;
             cin>>mjesec;
             cin>>c2;
             cin>>godina;
             if(c1!='/' || c2!='/')throw domain_error("Neispravan datum.");
             try{
             Datum datum(dan,mjesec,godina);
             }
             catch(domain_error e){
                 cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             goto PON654;
             }
             p.IspisiProdajeNaDatum({dan,mjesec,godina});
             goto VELIKI;
    }
    case 3:{
            p.DajNajranijuProdaju().Ispisi();
            cout<<endl;
            goto VELIKI;
    }
    case 4:{
            p.DajNajskupljuProdaju().Ispisi();
            cout<<endl;
            goto VELIKI;
    }
    case 5:{
            cout<<"Broj prodaja: "<<p.DajBrojProdaja()<<endl<<endl;
            goto VELIKI;
    }
    case 6:{
            cout<<"Unesite datum (d/m/g): ";
            int dan,mjesec,godina;
             char c1,c2;
             cin>>dan;
             cin>>c1;
             cin>>mjesec;
             cin>>c2;
             cin>>godina;
             if(c1!='/' || c2!='/')throw domain_error("Neispravan datum.");
             try{
             Datum datum(dan,mjesec,godina);
             cout<<"Broj prodaja na uneseni datum: "<<p.DajBrojProdajaNaDatum(datum)<<endl<<endl;
             goto VELIKI;
             }
             catch(domain_error e){
                 cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             //goto PON654;
             }
    }
    case 7:{
        cout<<"Unesite ime agenta: ";
        string ime;
        cin.clear();
        cin.ignore(10000,'\n');
        getline(cin,ime);
        cout<<"Broj prodaja: "<<p.DajBrojProdajaOdAgenta(ime)<<endl<<endl;
        goto VELIKI;
    }
    case 8:{
        cout<<"Dovidjenja!";
        return 0;
    }
}
    }
    case 4:{
        PODVAR:
        cout<<"Izaberite opciju:"<<endl;
cout<<" 0 - nazad"<<endl;
cout<<" 1 - brisanje najranije prodaje"<<endl;
cout<<" 2 - brisanje prodaja agenta"<<endl;
cout<<" 3 - brisanje prodaja po datumu"<<endl;
cout<<" 4 - brisanje svih prodaja"<<endl;
int opcija;
cin>>opcija;
switch(opcija){
    case 0:{
        goto NAZAD1;
    }
    case 1:{
        try{
            p.ObrisiNajranijuProdaju();
            cout<<"Najranija prodaja je obrisana!"<<endl;
            goto PODVAR;
        }
        catch(std::range_error e){
            cout<<"Izuzetak: "<<e.what()<<endl;
            goto PODVAR;
        }
    }
    case 2:{
        cout<<"Unesite ime agenta: ";
        string ime;
        cin.clear();
        cin.ignore(10000,'\n');
        getline(cin,ime);
        try{
            p.ObrisiProdajeAgenta(ime);
            cout<<"Sve prodaje tog agenta su obrisane."<<endl;
            goto PODVAR;
        }
        catch(range_error e){
            cout<<"Izuzetak: "<<e.what()<<endl;
            goto PODVAR;
        }
    }
    case 3:{
        cout<<"Unesite datum: ";
        int dan,mjesec,godina;
             char c1,c2;
             cin>>dan;
             cin>>c1;
             cin>>mjesec;
             cin>>c2;
             cin>>godina;
             if(c1!='/' || c2!='/')throw domain_error("Neispravan datum.");
             try{
             Datum datum(dan,mjesec,godina);
             p.ObrisiProdajeNaDatum(datum);
             cout<<"Sve prodaje na taj datum su obrisane."<<endl;
             goto PODVAR;
             }
             catch(domain_error e){
                 cout<<"Izuzetak: "<<e.what();
             cout<<" Molimo unesite opet."<<endl;
             //goto PON654;
             }
             catch(range_error e){
                 cout<<"Izuzetak: "<<e.what()<<endl;
                 goto PODVAR;
             }
    }
    case 4:{
        try{
            p.IsprazniKolekciju();
            cout<<"Sve prodaje su obrisane."<<endl;
            goto PODVAR;
        }
        catch(range_error e){
            cout<<"Izuzetak: "<<e.what()<<endl;
            goto PODVAR;
        }
    }
}
    }
    case 5:{
        cout<<"Dovidjenja!";
        return 0;
    }
}
 }
 }
    return 0;
}
