/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <initializer_list>
#include <iomanip>
#include <memory>
#include <vector>

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
    vector<shared_ptr<Prodaja>>prodaje;
    
    public:
    explicit Prodaje();
    Prodaje(initializer_list<Prodaja>spisak_prodaja);
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje)=default;
    Prodaje &operator=(const Prodaje &prodaje);
    Prodaje &operator=(Prodaje &&prodaje)=default;
    void RegistrirajProdaju(const string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan);
    void RegistrirajProdaju(const string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,string &ime_kupca,const Datum &datum_rodjenja_kupca,
    const string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata);
    void RegistrirajProdaju (shared_ptr<Prodaja>prodaja);
    int DajBrojProdaja() const {return prodaje.size();}
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju() {prodaje.resize(0);}
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
    Prodaja &DajProdaju(int broj){return *prodaje[broj];}
};
Prodaje::Prodaje(const Prodaje &prodaje):prodaje(prodaje.prodaje.size()){
    for(int i=0;i<prodaje.prodaje.size();i++)
    this->prodaje[i]=make_shared<Prodaja>(*prodaje.prodaje[i]);
}
Prodaje &Prodaje::operator=(const Prodaje &prodaje){
    Prodaje::prodaje.resize(prodaje.prodaje.size());
    for(int i=0;i<prodaje.prodaje.size();i++)
    this->prodaje[i]=make_shared<Prodaja>(*prodaje.prodaje[i]);
    
    return *this;
}
void Prodaje::RegistrirajProdaju (shared_ptr<Prodaja>prodaja){
    prodaje.push_back(prodaja);
}
void Prodaje::RegistrirajProdaju(const string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,
const Kupac &kupac_stana,const Stan &kupljeni_stan){
    Prodaje::prodaje.push_back(make_shared<Prodaja>(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan));
}
void Prodaje::RegistrirajProdaju(const string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,string &ime_kupca,const Datum &datum_rodjenja_kupca,
    const string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata){
        Prodaje::prodaje.push_back(make_shared<Prodaja>(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,
        adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata));
    }
Prodaje::Prodaje(initializer_list<Prodaja>spisak_prodaja){
    Prodaje::prodaje.resize(spisak_prodaja.size());
    int brojac(0);
    for(const auto &x: spisak_prodaja)
    prodaje[brojac++]=make_shared<Prodaja>(x);
    
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {

    return count_if(prodaje.begin(),prodaje.end(),[datum](shared_ptr<Prodaja>p1)->bool {
        int dan1,mjesec1,godina1;
        dan1=datum.DajDan();mjesec1=datum.DajMjesec();godina1=datum.DajGodinu();
        Datum dat2(p1->DajDatumProdaje());
        int dan2,mjesec2,godina2;
        dan2=dat2.DajDan();mjesec2=dat2.DajMjesec();godina2=dat2.DajGodinu();
        return(dan1==dan2 && mjesec1==mjesec2 && godina1==godina2);
    });
}
int Prodaje::DajBrojProdajaOdAgenta(const string &ime_agenta) const{
    return count_if(prodaje.begin(),prodaje.end(),[ime_agenta](shared_ptr<Prodaja>p1)->bool {
        return(ime_agenta==p1->DajImeAgenta());
    });
}
Prodaja &Prodaje::DajNajranijuProdaju() {
    
    return **min_element(prodaje.begin(),prodaje.end(),[](shared_ptr<Prodaja>p1,shared_ptr<Prodaja>p2){
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
    
    return **min_element(prodaje.begin(),prodaje.end(),[](shared_ptr<Prodaja>p1,shared_ptr<Prodaja>p2){
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
    
    return **max_element(prodaje.begin(),prodaje.end(),[](shared_ptr<Prodaja>p1,shared_ptr<Prodaja>p2){
        return p1->DajCijenuStana()>p2->DajCijenuStana();
    });
}
Prodaja Prodaje::DajNajskupljuProdaju() const {
    
    return **max_element(prodaje.begin(),prodaje.end(),[](shared_ptr<Prodaja>p1,shared_ptr<Prodaja>p2){
        return p1->DajCijenuStana()>p2->DajCijenuStana();
    });
}
void Prodaje::ObrisiNajranijuProdaju(){
    Datum dat2=DajNajranijuProdaju().DajDatumProdaje();
    int dan2=dat2.DajDan(),mjesec2=dat2.DajMjesec(),godina2=dat2.DajGodinu();
    for(int i=0;i<prodaje.size();i++){
        Datum dat=prodaje[i]->DajDatumProdaje();
        int dan1=dat.DajDan(),mjesec1=dat.DajMjesec(),godina1=dat.DajGodinu();
        if(dan1==dan2 && mjesec2==mjesec1 && godina1==godina2){
            for(int j=i;j<prodaje.size()-1;j++)
            {
                prodaje[j]=prodaje[j+1];
            }
            i--;
            prodaje.resize(prodaje.size()-1);
        }
        
    
    }
}
void Prodaje::ObrisiProdajeAgenta(const string &ime_agenta){
    
    for(int i=0;i<prodaje.size();i++){
        if(ime_agenta==prodaje[i]->DajImeAgenta())
        {prodaje[i]=prodaje[prodaje.size()-1];
            prodaje.resize(prodaje.size()-1);
        }
        
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    
    int dan1,mjesec1,godina1;
    dan1=datum.DajDan();mjesec1=datum.DajMjesec();godina1=datum.DajGodinu();
    for(int i=0;i<prodaje.size();i++){
        int dan2,mjesec2,godina2;
        Datum dat=prodaje[i]->DajDatumProdaje();
        dan2=dat.DajDan();mjesec2=dat.DajMjesec();godina2=dat.DajGodinu();
        if(dan1==dan2 && mjesec1==mjesec2 && godina1==godina2)
        prodaje[i]=prodaje[prodaje.size()-1];
        prodaje.resize(prodaje.size()-1);
    
    }
}





int main ()
{
	return 0;
}