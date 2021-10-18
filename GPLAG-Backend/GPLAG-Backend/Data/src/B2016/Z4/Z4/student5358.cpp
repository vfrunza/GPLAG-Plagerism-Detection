#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <memory>

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
        throw std::domain_error("Neispravno ime.");
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
    if(((broj_soba%10==2 && broj_soba%100!=12) ||( broj_soba%10==3 && broj_soba%100!=13) || (broj_soba%10==4 &&broj_soba%100!=14)))cout<<" sobe."<<endl;
    else std::cout <<" soba."  << std::endl;
    cout<<"Kvadratura stana je "<<kvadratura<<"  (m^2) i stan ";
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
     cout<<setw(30)<<left<<"Ime agenta:";cout<<this->DajImeAgenta()<<endl;
     cout<<setw(30)<<"Ime kupca:";this->kupac_stana.Ispisi();;
     cout<<setw(30)<<"Zakazani datum prodaje:";this->datum_prodaje.Ispisi();cout<<endl;
     cout<<setw(30)<<"Cijena stana:";cout<<this->DajCijenuStana()<<endl;
     cout<<setw(30)<<"Informacije o stanu:";cout<<endl;
     this->kupljeni_stan.Ispisi();cout<<endl;
 }
 class Prodaje{
     //const int max_broj_prodaja;
     int broj_reg_prodaja;
     //Prodaja ** prodaj;
     std::vector<shared_ptr<Prodaja>>prodaj ;
     public:
   Prodaje()=default;
Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
~Prodaje()=default;
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
void RegistrirajProdaju(shared_ptr<Prodaja> prodaja);
int DajBrojProdaja() const{
    return prodaj.size();
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
 
 Prodaje::Prodaje(const Prodaje &prodaje):broj_reg_prodaja(prodaje.broj_reg_prodaja){
     for(int i(0);i<prodaje.prodaj.size();i++) {
        prodaj.push_back(prodaje.prodaj[i]);
    }
 }
 Prodaje::Prodaje (Prodaje &&prodaje): broj_reg_prodaja(prodaje.broj_reg_prodaja),prodaj(std::move(prodaje.prodaj)) {
}
 Prodaje &Prodaje::operator =(const Prodaje &prodaje){
    prodaj.resize(0);
    for(int i(0);i<prodaj.size();i++) prodaj.push_back(std::make_shared<Prodaja>(*prodaje.prodaj[i]));
    return *this;
 }
 Prodaje &Prodaje::operator =(Prodaje &&prodaje){
prodaj=std::move(prodaje.prodaj);
    return *this;

 }
 Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) {
    for(auto a : spisak_prodaja) {
        prodaj.push_back(std::make_shared<Prodaja>(a));
    }
}
 void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,
 double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
const Stan &kupljeni_stan){
    prodaj.push_back(make_shared<Prodaja>(Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan)));
    broj_reg_prodaja++;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,
int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
 const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
 int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
     //if(broj_reg_prodaja==max_broj_prodaja) throw range_error("Dostignut maksimalni broj prodaja.");
     Datum datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje);
     Kupac kupac_stana(ime_kupca,datum_rodjenja_kupca);
     Stan kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
     prodaj.push_back(make_shared<Prodaja>(Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan)));
     broj_reg_prodaja++;
 }
void Prodaje::RegistrirajProdaju(shared_ptr<Prodaja> prodaja){
    //if(broj_reg_prodaja==max_broj_prodaja) throw range_error("Dostignut maksimalni broj prodaja.");
    prodaj.push_back(prodaja);
    broj_reg_prodaja++;
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    
    Prodaje temp(*this);
    std::sort(&temp.prodaj[0], &temp.prodaj[prodaj.size()], [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) { return ProdatPrije(*p1,*p2); });
    for(int i(0);i<temp.prodaj.size();i++) {
        if(temp.prodaj[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu() && temp.prodaj[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && temp.prodaj[i]->DajDatumProdaje().DajDan()==datum.DajDan()) {
            temp.prodaj[i]->Ispisi();
        }
    }
}
void Prodaje::IspisiSveProdaje() const{
    
    Prodaje temp(*this);
    std::sort(&temp.prodaj[0], &temp.prodaj[prodaj.size()], [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) { return ProdatPrije(*p1,*p2); });
    int i(0);
    for(auto x : prodaj) {
        temp.prodaj[i]->Ispisi();
        i++;
    }
}
Prodaja Prodaje::DajNajranijuProdaju() const{
    Prodaje temp(*this);
    auto najraniji(std::min_element(&temp.prodaj[0], &temp.prodaj[prodaj.size()], [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) { return ProdatPrije(*p1,*p2); }));
    return **najraniji;
}
Prodaja &Prodaje::DajNajranijuProdaju() {
    Prodaje temp(*this);
    return **std::min_element(&temp.prodaj[0], &temp.prodaj[prodaj.size()], [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) { return ProdatPrije(*p1,*p2); });
}
Prodaja &Prodaje::DajNajskupljuProdaju(){
    auto a=std::max_element(prodaj.begin(),prodaj.end(),[](const shared_ptr<Prodaja >p1,const shared_ptr<Prodaja >p2){
                            if(p1->DajCijenuStana()<p2->DajCijenuStana())return true;
     return false;});
    return **a;
}
Prodaja Prodaje::DajNajskupljuProdaju() const{
    auto a=std::max_element(prodaj.begin(),prodaj.end(),[](const shared_ptr<Prodaja >p1,const shared_ptr<Prodaja >p2){
                            if(p1->DajCijenuStana()<p2->DajCijenuStana())return true;
     return false;});
    return **a;
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
        return std::count_if(&prodaj[0], &prodaj[prodaj.size()], [datum] (std::shared_ptr<Prodaja> pr) { return (pr->DajDatumProdaje().DajGodinu()==datum.DajGodinu() && pr->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pr->DajDatumProdaje().DajDan()==datum.DajDan()); });

}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    if(broj_reg_prodaja==0)throw std::domain_error("Nema registriranih prodaja.");
    return std::count_if(prodaj.begin(),prodaj.end(),[ime_agenta](shared_ptr<Prodaja >p1){
        if(p1->DajImeAgenta()==ime_agenta)return true;
        return false;
    });
}
void Prodaje::ObrisiNajranijuProdaju(){
    if(broj_reg_prodaja==0)throw std::range_error("Prazna kolekcija.");
    std::sort(&prodaj[0], &prodaj[prodaj.size()], [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) { return ProdatPrije(*p1,*p2); });
    prodaj.erase(prodaj.begin()+0);
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    for(int i(0);i<prodaj.size();i++) {
        if(prodaj[i]->DajImeAgenta()==ime_agenta) {
            prodaj.erase(prodaj.begin()+i);
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    if(broj_reg_prodaja==0)throw std::range_error("Prazna kolekcija.");
    int br=0;
    for(int i=0;i<broj_reg_prodaja;i++){
        if(prodaj[i]->DajDatumProdaje().DajDan()==datum.DajDan()){
            if(prodaj[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec()){
                if(prodaj[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
                    //delete prodaj[i];
                    prodaj[i]=nullptr;
                    br++;
                }
            }
        }
    }
    remove(prodaj.begin(),prodaj.end(),nullptr);
    broj_reg_prodaja=broj_reg_prodaja-br;
}
void Prodaje::IsprazniKolekciju(){
    for(int i(0);i<prodaj.size();i++) {
        prodaj.erase(prodaj.begin()+i);
    }
}
int main(){
    return 0;
}