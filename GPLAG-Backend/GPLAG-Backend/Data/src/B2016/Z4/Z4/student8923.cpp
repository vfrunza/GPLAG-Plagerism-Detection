#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <memory>
#include <cmath>
using std::vector;
using std::cout;
using std::cin;
using std::string;
class Datum
{
private:

int cdan,cmjesec,cgodina;
public:
Datum(int dan, int mjesec, int godina);
void Postavi(int dan, int mjesec, int godina);
int DajDan() const {return cdan;}
int DajMjesec() const {return cmjesec;}
int DajGodinu() const {return cgodina;}
void Ispisi() const {cout<<cdan<<"/"<<cmjesec<<"/"<<cgodina;}
};
Datum::Datum(int dan,int mjesec,int godina)
{
    int broj_dana[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) 
    broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
    throw std::domain_error("Neispravan datum");
    cdan=dan;
    cmjesec=mjesec;
    cgodina=godina;
}
void Datum::Postavi(int dan,int mjesec,int godina)
{
    int broj_dana[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) 
    broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
    throw std::domain_error("Neispravan datum");
    cdan=dan;
    cmjesec=mjesec;
    cgodina=godina;
}
class Kupac
{
private:
string cime_i_prezime;
Datum cdatum_rodjenja;
bool ProvjeraImena(string ime);
public:
Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
std::string DajImePrezime() const{ return cime_i_prezime;}
Datum DajDatumRodjenja() const{ return cdatum_rodjenja;}
void Ispisi() const{cout<<cime_i_prezime<<" ("<<cdatum_rodjenja.DajDan()<<"/"<<cdatum_rodjenja.DajMjesec()<<"/"<<cdatum_rodjenja.DajGodinu()<<")";}
};
bool Kupac::ProvjeraImena(string ime)
{
    for(int i=0;i<ime.size();i++)
    {
        if(!((ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9') || ime[i]=='-' || ime[i]==' ' || ime[i]==27))
        return false;
    }
    return true;
}
Kupac::Kupac(const string &ime_i_prezime,const Datum &datum_rodjenja) : cdatum_rodjenja(datum_rodjenja.Datum::DajDan(),datum_rodjenja.Datum::DajMjesec(),datum_rodjenja.Datum::DajGodinu())
{
    if(!Kupac::ProvjeraImena(ime_i_prezime))
    throw std::domain_error("Neispravno ime i prezime");
   cime_i_prezime=ime_i_prezime;
}
void Kupac::Postavi(const string &ime_i_prezime,const Datum &datum_rodjenja)
{
    try
    {
    *this=Kupac(ime_i_prezime,datum_rodjenja);
    }
    catch(...)
    {
    throw;
    }
}
class Stan
{
private:   
string cadresa;
int csprat,cbroj_soba;
bool cnamjesten;
double ckvadratura;
public:
Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);}
void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
std::string DajAdresu() const{return cadresa;}
int DajSprat() const{return csprat;}
int DajBrojSoba() const{return cbroj_soba;}
bool DajNamjesten() const{return cnamjesten;}
double DajKvadraturu() const{return ckvadratura;}
void Ispisi() const;
};
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    if(sprat<0 || broj_soba<0 || kvadratura<0)
    throw std::domain_error("Neispravan unos podataka");
    cadresa=adresa;
    csprat=sprat;
    cbroj_soba=broj_soba;
    cnamjesten=namjesten;
    ckvadratura=kvadratura;
}
void Stan::Ispisi() const
{
    vector<string> gramatika{" soba."," sobu."," sobe."," sobe."," sobe."," soba."," soba."," soba."," soba."," soba."};
    int pom(cbroj_soba%10);
    if(cnamjesten)
    cout<<"Stan se nalazi na adresi "<<cadresa<<" na "<<csprat<<". spratu i ima "<<cbroj_soba<<gramatika[pom]<<" Kvadratura stana je "<<ckvadratura<<" (m^2) i stan je namjesten.";
    else
    cout<<"Stan se nalazi na adresi "<<cadresa<<" na "<<csprat<<". spratu i ima "<<cbroj_soba<<gramatika[pom]<<" Kvadratura stana je "<<ckvadratura<<" (m^2) i stan nije namjesten.";
}
class Prodaja
{
private:
string cime_agenta_prodaje;
double ccijena_stana;
Datum cdatum_prodaje;
Kupac ckupac_stana;
Stan ckupljeni_stan;
public:
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
void PromijeniKupca(const Kupac &novi_kupac){ckupac_stana=novi_kupac;}
void PromijeniStan(const Stan &novi_stan){ckupljeni_stan=novi_stan;}
void PromijeniAgenta(const string ime){cime_agenta_prodaje=ime;}
void PromijeniDatumKupovine(const Datum &novi_datum){cdatum_prodaje=novi_datum;}
void PromijeniCijenuProdaje(const double &nova_cijena){ccijena_stana=nova_cijena;}
void PomjeriDanUnaprijed();
void PomjeriDanUnazad();
std::string DajImeAgenta() const{return cime_agenta_prodaje;}
std::string DajImeKupca() const{return ckupac_stana.Kupac::DajImePrezime();}
Datum DajDatumProdaje() const{return cdatum_prodaje;}
double DajCijenuStana() const{return ccijena_stana;}
friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
void Ispisi() const;
};
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan):cdatum_prodaje(datum_prodaje.Datum::DajDan(),datum_prodaje.Datum::DajMjesec(),datum_prodaje.Datum::DajGodinu()),ckupac_stana(kupac_stana.Kupac::DajImePrezime(),kupac_stana.Kupac::DajDatumRodjenja()),
ckupljeni_stan(kupljeni_stan.Stan::DajAdresu(),kupljeni_stan.Stan::DajSprat(),kupljeni_stan.Stan::DajBrojSoba(),kupljeni_stan.Stan::DajNamjesten(),kupljeni_stan.Stan::DajKvadraturu())
{
  cime_agenta_prodaje=ime_agenta_prodaje;
  ccijena_stana=cijena_stana;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):
cdatum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje), ckupac_stana(ime_kupca,datum_rodjenja_kupca), ckupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)
{
    cime_agenta_prodaje=ime_agenta_prodaje;
    ccijena_stana=cijena_stana;
}
void Prodaja::PomjeriDanUnaprijed()
{
int dan(cdatum_prodaje.Datum::DajDan()),mjesec(cdatum_prodaje.Datum::DajMjesec()),godina(cdatum_prodaje.Datum::DajGodinu());
int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 if((godina%4==0 && godina%100!=0) || godina%400==0)
 broj_dana[1]++;
 dan++;
 if(dan>broj_dana[mjesec-1]) 
 {
 dan=1;
 mjesec++;
 }
 if(mjesec>12) 
 {
mjesec=1;
godina++;
}
cdatum_prodaje.Datum::Postavi(dan,mjesec,godina);
}
void Prodaja::PomjeriDanUnazad()
{
int dan(cdatum_prodaje.Datum::DajDan()),mjesec(cdatum_prodaje.Datum::DajMjesec()),godina(cdatum_prodaje.Datum::DajGodinu());
int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 if((godina%4==0 && godina%100!=0) || godina%400==0)
 broj_dana[1]++;
 dan--;
 if(dan==0)
 mjesec--;
 if(mjesec!=0)
 dan=broj_dana[mjesec-1];
 else
 {
    godina--;
   mjesec=12;
   dan=broj_dana[mjesec-1];
 }
 cdatum_prodaje.Datum::Postavi(dan,mjesec,godina);
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.cdatum_prodaje.Datum::DajGodinu()<p2.cdatum_prodaje.Datum::DajGodinu())
    return true;
    if(p1.cdatum_prodaje.Datum::DajMjesec()<p2.cdatum_prodaje.Datum::DajMjesec())
    return true;
    if(p1.cdatum_prodaje.Datum::DajDan()<p2.cdatum_prodaje.Datum::DajDan())
    return true;
    return false;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.ccijena_stana>p2.ccijena_stana)
    return true;
    return false;
}
void Prodaja::Ispisi() const
{
    cout<<"Ime agenta:                     "<<cime_agenta_prodaje<<std::endl;
    cout<<"Ime kupca:                      ";
    ckupac_stana.Kupac::Ispisi();
    cout<<std::endl;
    cout<<"Zakazani datum prodaje:         ";
    cdatum_prodaje.Datum::Ispisi();
    cout<<std::endl;
    cout<<"Cijena stana:                   "<<ccijena_stana<<std::endl;
    cout<<"Informacije o stanu:            "<<std::endl;
    ckupljeni_stan.Stan::Ispisi();
}
class Prodaje
{
private:

vector<std::shared_ptr<Prodaja>> cpok;
public:
explicit Prodaje():cpok(cpok.size()){}
Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
~Prodaje()=default;
Prodaje(const Prodaje &prodaje);
Prodaje(Prodaje &&prodaje)=default;
Prodaje &operator =(const Prodaje &prodaje);
Prodaje &operator =(Prodaje &&prodaje)=default;
void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
void RegistrirajProdaju(std::shared_ptr<Prodaja> prodaja);
int DajBrojProdaja() const{return cpok.size();}
int DajBrojProdajaNaDatum(const Datum &datum) const;
int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
Prodaja &DajProdaju(int broj_prodaje);
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
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : cpok(spisak_prodaja.size())
{
    int i(0);
        for(auto it=spisak_prodaja.begin();it!=spisak_prodaja.end();it++)
        {
            cpok[i]=std::make_shared<Prodaja>(*it);
            i++;
            
        }
    
}

Prodaje::Prodaje(const Prodaje &prodaje) :cpok(prodaje.cpok.size())
{
    
        for(int i=0;i<prodaje.cpok.size();i++)
        {
            cpok[i]=std::make_shared<Prodaja>(*prodaje.cpok[i]);
        }
    
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje) //
{
    if(&prodaje!=this)
    {
    cpok.resize(prodaje.cpok.size());
    for(int i=0;i<prodaje.cpok.size();i++)
    cpok[i]=std::make_shared<Prodaja>(*prodaje.cpok[i]);
    }
    return *this;
}


void Prodaje::IsprazniKolekciju()
{
    cpok.resize(0);
}
void Prodaje::RegistrirajProdaju(std::shared_ptr<Prodaja> prodaja)
{
   cpok.push_back(prodaja);
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan)
{
   
    try
    {
        std::shared_ptr<Prodaja> pom(std::make_shared<Prodaja>(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan));
       cpok.push_back(pom);
    }
    catch(...)
    {
        throw;
    }
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
   
    try
    {
        std::shared_ptr<Prodaja> pom(std::make_shared<Prodaja>(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata));
        cpok.push_back(pom);
    }
    catch(...)
    {
        throw;
    }
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const
{
    int pom;
    pom=std::count_if(cpok.begin(),cpok.end(),[=](std::shared_ptr<Prodaja>prodaja) {
    Datum datum2=prodaja->Prodaja::DajDatumProdaje();
    if(datum2.Datum::DajDan()==datum.Datum::DajDan() && datum2.Datum::DajMjesec()==datum.Datum::DajMjesec() && datum2.Datum::DajGodinu()==datum.Datum::DajGodinu())
    return true;
    return false;});
    return pom;
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const
{
    int pom;
    pom=std::count_if(cpok.begin(),cpok.end(),[=](std::shared_ptr<Prodaja> prodaja){
    string ime_agenta2=prodaja->Prodaja::DajImeAgenta();
    if(ime_agenta2==ime_agenta)
    return true;
    return false;
    });
    return pom;
}
Prodaja &Prodaje::DajProdaju(int broj_prodaje)
{
   if(broj_prodaje>cpok.size()) 
   throw std::range_error("Nema toliko registriranih prodaja");
   return *cpok[broj_prodaje-1];
}
Prodaja &Prodaje::DajNajranijuProdaju()
{
    if(cpok.size()==0)
    throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(cpok.begin(),cpok.end(),[] (std::shared_ptr<Prodaja> prodaja1,std::shared_ptr<Prodaja> prodaja2)
    {
        Datum datum1=prodaja1->Prodaja::DajDatumProdaje(),datum2=prodaja2->Prodaja::DajDatumProdaje();
        if(datum1.Datum::DajGodinu()>datum2.Datum::DajGodinu()) return true;
        if(datum1.Datum::DajGodinu()<datum2.Datum::DajGodinu()) return false;
        if(datum1.Datum::DajMjesec()>datum2.Datum::DajMjesec()) return true;
        if(datum1.Datum::DajMjesec()<datum2.Datum::DajMjesec()) return false;
        if(datum1.Datum::DajDan()>datum2.Datum::DajDan()) return true;
        return false;
    });
}
Prodaja Prodaje::DajNajranijuProdaju() const
{
    if(cpok.size()==0)
    throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(cpok.begin(),cpok.end(),[] (std::shared_ptr<Prodaja> prodaja1,std::shared_ptr<Prodaja> prodaja2)
    {
        Datum datum1=prodaja1->Prodaja::DajDatumProdaje(),datum2=prodaja2->Prodaja::DajDatumProdaje();
        if(datum1.Datum::DajGodinu()>datum2.Datum::DajGodinu()) return true;
        if(datum1.Datum::DajGodinu()<datum2.Datum::DajGodinu()) return false;
        if(datum1.Datum::DajMjesec()>datum2.Datum::DajMjesec()) return true;
        if(datum1.Datum::DajMjesec()<datum2.Datum::DajMjesec()) return false;
        if(datum1.Datum::DajDan()>datum2.Datum::DajDan()) return true;
        return false;
    });
}
Prodaja &Prodaje::DajNajskupljuProdaju()
{
    if(cpok.size()==0)
    throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(cpok.begin(),cpok.end(),[](std::shared_ptr<Prodaja> prodaja1,std::shared_ptr<Prodaja> prodaja2)
    {
        double cijena1,cijena2;
        cijena1=prodaja1->Prodaja::DajCijenuStana();
        cijena2=prodaja2->Prodaja::DajCijenuStana();
        if(cijena2>cijena1)
        return true;
        return false;
    });
}
Prodaja Prodaje::DajNajskupljuProdaju() const
{
    if(cpok.size()==0)
    throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(cpok.begin(),cpok.end(),[](std::shared_ptr<Prodaja> prodaja1,std::shared_ptr<Prodaja> prodaja2)
    {
        double cijena1,cijena2;
        cijena1=prodaja1->Prodaja::DajCijenuStana();
        cijena2=prodaja2->Prodaja::DajCijenuStana();
        if(cijena2>cijena1)
        return true;
        return false;
    });
}
void Prodaje::ObrisiNajranijuProdaju()
{
   if(cpok.size()==0)
   throw std::range_error("Prazna kolekcija");
   Prodaja pom_prodaja=(*this).Prodaje::DajNajranijuProdaju();
   Datum pom_datum=pom_prodaja.Prodaja::DajDatumProdaje();
   string pom_ime_agenta=pom_prodaja.Prodaja::DajImeAgenta();
   double pom_cijena=pom_prodaja.Prodaja::DajCijenuStana();
   for(int i=0;i<cpok.size();i++)
   {
       Datum datum=(*this).cpok[i]->Prodaja::DajDatumProdaje();
       string ime_agenta=(*this).cpok[i]->Prodaja::DajImeAgenta();
       double cijena=(*this).cpok[i]->Prodaja::DajCijenuStana();
       if(pom_ime_agenta==ime_agenta && std::fabs(pom_cijena-cijena)<0.00000000001 && pom_datum.Datum::DajDan()==datum.Datum::DajDan() && pom_datum.Datum::DajMjesec()==datum.Datum::DajMjesec() && pom_datum.Datum::DajGodinu()==datum.Datum::DajGodinu())
       {
           cpok[i]=cpok[cpok.size()-1];
           cpok[cpok.size()-1]=nullptr;
           cpok.resize(cpok.size()-1);
           
       }
   }
   
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta)
{
    for(int i=0;i<cpok.size();i++)
    {
        if((*this).cpok[i]->Prodaja::DajImeAgenta()==ime_agenta)
        {
            cpok[i]=cpok[cpok.size()-1];
           cpok[cpok.size()-1]=nullptr;
           cpok.resize(cpok.size()-1);
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
{
    for(int i=0;i<cpok.size();i++)
    {
    Datum pom_datum=(*this).cpok[i]->Prodaja::DajDatumProdaje();
    if(pom_datum.Datum::DajDan()==datum.Datum::DajDan() && pom_datum.Datum::DajMjesec()==datum.Datum::DajMjesec() && pom_datum.Datum::DajGodinu()==datum.Datum::DajGodinu())
    {
        cpok[i]=cpok[cpok.size()-1];
           cpok[cpok.size()-1]=nullptr;
           cpok.resize(cpok.size()-1);
    }
    }
}
void Prodaje::IspisiSveProdaje() const
{
    Prodaje pom_prodaje=*this;
    std::sort(pom_prodaje.cpok.begin(),pom_prodaje.cpok.end(),[](std::shared_ptr<Prodaja> prodaja1,std::shared_ptr<Prodaja> prodaja2)
    {
         Datum datum1=prodaja1->Prodaja::DajDatumProdaje(),datum2=prodaja2->Prodaja::DajDatumProdaje();
        if(datum1.Datum::DajGodinu()<datum2.Datum::DajGodinu()) return true;
        if(datum1.Datum::DajGodinu()>datum2.Datum::DajGodinu()) return false;
        if(datum1.Datum::DajMjesec()<datum2.Datum::DajMjesec()) return true;
        if(datum1.Datum::DajMjesec()>datum2.Datum::DajMjesec()) return false;
        if(datum1.Datum::DajDan()<datum2.Datum::DajDan()) return true;
        if(datum1.Datum::DajDan()>datum2.Datum::DajDan()) return false;
        return(prodaja1->Prodaja::DajImeKupca()<prodaja2->Prodaja::DajImeKupca());
    });
    for(int i=0;i<cpok.size();i++)
    {
        pom_prodaje.cpok[i]->Prodaja::Ispisi();
        cout<<std::endl;
    }
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const
{
    Prodaje pom_prodaje=*this;
    std::sort(pom_prodaje.cpok.begin(),pom_prodaje.cpok.end(),[](std::shared_ptr<Prodaja> prodaja1,std::shared_ptr<Prodaja> prodaja2)
    {
        return(prodaja1->Prodaja::DajImeKupca()<prodaja2->Prodaja::DajImeKupca());
    });
    for(int i=0;i<cpok.size();i++)
    {
    Datum pom_datum=(*this).cpok[i]->Prodaja::DajDatumProdaje();
        if(pom_datum.Datum::DajDan()==datum.Datum::DajDan() && pom_datum.Datum::DajMjesec()==datum.Datum::DajMjesec() && pom_datum.Datum::DajGodinu()==datum.Datum::DajGodinu())
        pom_prodaje.cpok[i]->Prodaja::Ispisi();
    }
}
int main ()
{
    
  cout<<"Dobrodosli!"<<std::endl<<" "<<std::endl<<" ";
     vector<Kupac> vekk;
    vector<Stan> veks;
    vector<Prodaja> vekp;
   // Prodaje prodaje(20);
    while(true)
    {
    cout<<std::endl<<"Izaberite opciju:"<<std::endl;
    cout<<" 0 - kraj"<<std::endl<<" 1 - uredjivanje stanova"<<std::endl<<" 2 - uredjivanje kupaca"<<std::endl<<" 3 - uredjivanje prodaja"<<std::endl;
    int opcija;
    cin>>opcija;
    if(opcija==0)
    {
        cout<<std::endl<<"Dovidjenja!";
        return 0;
    }
    if(opcija==1)
    {
    while(true)
    { 
        cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - dodavanje stana"<<std::endl<<" 2 - uredjivanje stanova"<<std::endl<<" 3 - ispis svih stanova"<<std::endl<<" 4 - kraj"<<std::endl;
       int opc1;
       cin>>opc1;
       if(opc1==0)
       break;
       if(opc1==4)
       {
    cout<<std::endl<<"Dovidjenja!";
       return 0;
       }
       if(opc1==1)
       {
           unos:
           cout<<"Unesite adresu: ";
           string adresa;
           cin.ignore(10000,'\n');
           std::getline(cin,adresa);
           cout<<"Unesite sprat: ";
           int sprat;
           cin>>sprat;
           cout<<"Unesite broj soba: ";
           int broj_soba;
           cin>>broj_soba;
           cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
           int n;
           cin>>n;
           bool namjesten(false);
           if(n==1)
           namjesten=true;
           cout<<"Unesite kvadraturu: ";
           double kvadratura;
           cin>>kvadratura;
           try
           {
               if(n!=1 && n!=0)
               throw std::domain_error("Neispravan unos podataka");
               Stan novis(adresa,sprat,broj_soba,namjesten,kvadratura);
               veks.push_back(novis);
               cout<<"Stan je uspjesno dodan!"<<std::endl<<" "<<std::endl;
           }
           catch(std::domain_error izuzetak)
           {
               cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
               goto unos;
           }
       }
       if(opc1==3)
       {
          for(int i=0;i<veks.size();i++)
          {
              cout<<i+1<<". ";
              veks[i].Stan::Ispisi();
              cout<<std::endl;
               if(i==veks.size()-1)
               cout<<" "<<std::endl;
          }
       }
       if(opc1==2)
       {
           cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
           for(int i=0;i<veks.size();i++)
           {
               cout<<" "<<i+1<<" - ";
               veks[i].Stan::Ispisi();
               cout<<std::endl;
           }
           int odaberis;
           cin>>odaberis;
           odaberis--;
           cout<<" "<<std::endl;
           cout<<"Odaberite polje koje zelite urediti:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - adresa"<<std::endl<<" 2 - sprat"<<std::endl<<" 3 - broj soba"<<std::endl<<" 4 - da li je stan namjesten"<<std::endl<<" 5 - kvadratura"<<std::endl<<" 6 - sve"<<std::endl;
       int odaberiu;
       cin>>odaberiu;
       if(odaberiu==0)
       break;
       if(odaberiu==1)
       {
        unos1:
       cout<<"Unesite adresu: ";
       string adres;
       cin.ignore(10000,'\n');
       std::getline(cin,adres);
       try
       {
           veks[odaberis].Stan::Postavi(adres,veks[odaberis].Stan::DajSprat(),veks[odaberis].Stan::DajBrojSoba(),veks[odaberis].Stan::DajNamjesten(),veks[odaberis].Stan::DajKvadraturu());
           cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<" "<<std::endl;
       }
       catch(std::domain_error izuzetak)
       {
           cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
           goto unos1;
       }
       }
       if(odaberiu==2)
       {
           unos2:
           cout<<"Unesite sprat: ";
           int spra;
           cin>>spra;
        try
       {
           veks[odaberis].Stan::Postavi(veks[odaberis].Stan::DajAdresu(),spra,veks[odaberis].Stan::DajBrojSoba(),veks[odaberis].Stan::DajNamjesten(),veks[odaberis].Stan::DajKvadraturu());
           cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<" "<<std::endl;
       }
       catch(std::domain_error izuzetak)
       {
           cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
           goto unos2;
       }
       }
       if(odaberiu==3)
       {
           unos3:
           cout<<"Unesite broj soba: ";
           int br_soba;
           cin>>br_soba;
        try
       {
           veks[odaberis].Stan::Postavi(veks[odaberis].Stan::DajAdresu(),veks[odaberis].Stan::DajSprat(),br_soba,veks[odaberis].Stan::DajNamjesten(),veks[odaberis].Stan::DajKvadraturu());
           cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<" "<<std::endl;
       }
       catch(std::domain_error izuzetak)
       {
           cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
           goto unos3;
       }
       }
       if(odaberiu==4)
       {
           unos4:
           cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
           int n2;
           cin>>n2;
           bool namjes(false);
           if(n2==1)
           namjes=true;
        try
       {
           if(n2!=0 && n2!=1)
           throw std::domain_error("Neispravan unos podataka");
           veks[odaberis].Stan::Postavi(veks[odaberis].Stan::DajAdresu(),veks[odaberis].Stan::DajSprat(),veks[odaberis].Stan::DajBrojSoba(),namjes,veks[odaberis].Stan::DajKvadraturu());
           cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<" "<<std::endl;
       }
       catch(std::domain_error izuzetak)
       {
           cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
           goto unos4;
       }
       }
       if(odaberiu==5)
       {
           unos5:
           cout<<"Unesite kvadraturu: ";
           double kvadrata;
           cin>>kvadrata;
        try
       {
           veks[odaberis].Stan::Postavi(veks[odaberis].Stan::DajAdresu(),veks[odaberis].Stan::DajSprat(),veks[odaberis].Stan::DajBrojSoba(),veks[odaberis].Stan::DajNamjesten(),kvadrata);
           cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<" "<<std::endl;
       }
       catch(std::domain_error izuzetak)
       {
           cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
           goto unos5;
       }
       }
       if(odaberiu==6)
       {
           unos6:
          cout<<"Unesite adresu: ";
           string adres;
           cin.ignore(10000,'\n');
           std::getline(cin,adres);
           cout<<"Unesite sprat: ";
           int spra;
           cin>>spra;
           cout<<"Unesite broj soba: ";
           int br_soba;
           cin>>br_soba;
           cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
           int n2;
           cin>>n2;
           bool namjes(false);
           if(n2==1)
           namjes=true;
           cout<<"Unesite kvadraturu: ";
           double kvadrata;
           cin>>kvadrata; 
        try
       {
           if(n2!=1 && n2!=0)
           throw std::domain_error("Neispravan unos podataka");
           veks[odaberis].Stan::Postavi(adres,spra,br_soba,namjes,kvadrata);
           cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<" "<<std::endl;
       }
       catch(std::domain_error izuzetak)
       {
           cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
           goto unos6;
       }
       }
       }
    } 
    }
    if(opcija==2)
    {
    while(true)
    {
        cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - dodavanje kupca"<<std::endl<<" 2 - uredjivanje kupaca"<<std::endl<<" 3 - ispis svih kupaca"<<std::endl<<" 4 - kraj"<<std::endl;
        int opck;
        cin>>opck;
        if(opck==0)
        break;
        if(opck==4)
        {
            cout<<std::endl<<"Dovidjenja!";
           return 0; 
        }
        if(opck==1)
        {
            unosk1:
            cout<<"Unesite ime i prezime kupca: ";
            string imek;
            cin.ignore(10000,'\n');
            std::getline(cin,imek);
            cout<<"Unesite datum rodjenja (formata d/m/g): ";
            int d,m,g;
            char znak1,znak2;
            cin>>d>>znak1>>m>>znak2>>g;
            try
            {
                Datum dat(d,m,g);
                Kupac kup(imek,dat);
                vekk.push_back(kup);
                cout<<"Kupac je uspjesno dodan!"<<std::endl<<std::endl;
            }
            catch(std::domain_error izuzetak)
            {
                cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
                goto unosk1;
            }
        }
        if(opck==3)
        {
            for(int i=0;i<vekk.size();i++)
            {
                vekk[i].Kupac::Ispisi();
                cout<<std::endl;
                 if(i==vekk.size()-1)
               cout<<std::endl;
            }
        }
        if(opck==2)
        {
            cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<std::endl;
            for(int i=0;i<vekk.size();i++)
            {
                cout<<" "<<i+1<<" - ";
                vekk[i].Kupac::Ispisi();
                cout<<std::endl;
                if(i==vekk.size()-1)
                cout<<std::endl;
            }
            int odaberik;
            cin>>odaberik;
            odaberik--;
            unosnk:
            cout<<"Unesite ime i prezime kupca: ";
            string nime;
            cin.ignore(10000,'\n');
            std::getline(cin,nime);
            cout<<"Unesite datum rodjenja (formata d/m/g): ";
            int nd,nm,ng;
            char nznak1,nznak2;
            cin>>nd>>nznak1>>nm>>nznak2>>ng;
            try
            {
                Datum ndat(nd,nm,ng);
                vekk[odaberik].Kupac::Postavi(nime,ndat);
                cout<<"Kupac je uspjesno izmijenjen!"<<std::endl<<" "<<std::endl;
            }
            catch(std::domain_error izuzetak)
            {
                cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
                goto unosnk;
            }
        }
    }
        
    }
    if(opcija==3)
    {
        while(true)
        {
        cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - dodavanje prodaje"<<std::endl<<" 2 - uredjivanje prodaje"<<std::endl<<" 3 - ispis prodaja"<<std::endl<<" 4 - brisanje prodaja"<<std::endl<<" 5 - kraj"<<std::endl;
       int opcprod;
       cin>>opcprod;
       if(opcprod==0)
       break;
       if(opcprod==2)
       {
           cout<<"Odaberite prodaju koju želite urediti. Dostupne prodaje su:"<<std::endl;
            for(int i=0;i<vekp.size();i++)
               {
                   cout<<i+1<<"."<<std::endl;
                   vekp[i].Prodaja::Ispisi();
                   cout<<std::endl<<std::endl;
               }
            int izmijenip;
            cin>>izmijenip;
            izmijenip--;
            
cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - izmjena agenta"<<std::endl<<" 2 - izmjena datuma prodaje"<<std::endl<<" 3 - izmjena kupca"<<std::endl<<" 4 - izmjena stana"<<std::endl<<" 5 - izmjena cijene stana"<<std::endl;
       int opcizm;
       cin>>opcizm;
       if(opcizm==0)
       break;
       if(opcizm==1)
       {
            cout<<"Unesite ime i prezime agenta prodaje: ";
            string imea;
            cin.ignore(10000,'\n');
            std::getline(cin,imea);
             vekp[izmijenip].Prodaja::PromijeniAgenta(imea);
             cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
       }
       if(opcizm==2)
       {
           izmijenid:
           cout<<"Unesite datum prodaje (formata d/m/g): ";
            int d,m,g;
            char znak1,znak2;
            cin>>d>>znak1>>m>>znak2>>g;
            try
            {
                Datum dat(d,m,g);
                vekp[izmijenip].Prodaja::PromijeniDatumKupovine(dat);
                cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
            }
            catch(std::domain_error izuzetak)
            {
               cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
                goto izmijenid; 
            }
       }
       if(opcizm==3)
       {
           cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - odabir postojeceg kupca"<<std::endl<<" 2 - dodavanje novog kupca"<<std::endl;
           int k;
           cin>>k;
           if(k==0)
           break;
           if(k==2)
           {
           izmijenik:
           cout<<"Unesite ime i prezime kupca: ";
            string imek;
            cin.ignore(10000,'\n');
            std::getline(cin,imek);
            cout<<"Unesite datum rodjenja (formata d/m/g): ";
            int dk,mk,gk;
            char kznak1,kznak2;
            cin>>dk>>kznak1>>mk>>kznak2>>gk;
            try
            {
                Datum datk(dk,mk,gk);
                Kupac kupac(imek,datk);
                vekp[izmijenip].Prodaja::PromijeniKupca(kupac);
                 cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
            }
            catch(std::domain_error izuzetak)
            {
                cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
                goto izmijenik; 
            }
           }
       }
       if(opcizm==4)
       {
           izmijenis:
            string adresak;
            cout<<"Unesite adresu: ";
            cin.ignore(10000,'\n');
            std::getline(cin,adresak);
            int sprat,broj_soba;
            cout<<"Unesite sprat: ";
            cin>>sprat;
            cout<<"Unesite broj soba: ";
            cin>>broj_soba;
            int n;
            cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
            cin>>n;
            bool namjesten(false);
            if(n==1)
            namjesten=true;
            cout<<"Unesite kvadraturu: ";
            double kvadratura;
            cin>>kvadratura;
            try
            {
                Stan nstan(adresak,sprat,broj_soba,namjesten,kvadratura);
                vekp[izmijenip].Prodaja::PromijeniStan(nstan);
                cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
            }
            catch(std::domain_error izuzetak)
            {
                cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
                goto izmijenis;  
            }
       }
       if(opcizm==5)
       {
         cout<<"Unesite cijenu stana: ";
            double cijena;
            cin>>cijena;
            vekp[izmijenip].Prodaja::PromijeniCijenuProdaje(cijena);
       }
       }
       if(opcprod==5)
       {
           cout<<std::endl<<"Dovidjenja!";
           return 0;
       }
       if(opcprod==3)
       {
         while(true)
         {
           cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - ispis svih prodaja"<<std::endl<<" 2 - ispis prodaja na datum"<<std::endl<<" 3 - ispis najranije prodaje"<<std::endl<<" 4 - ispis najskuplje prodaje"<<std::endl<<" 5 - ispis broja prodaja"<<std::endl<<" 6 - ispis broja prodaja po datumu"<<std::endl<<" 7 - ispis broja prodaja po agentu"<<std::endl<<" 8 - kraj"<<std::endl;
           int ispisp;
           cin>>ispisp;
           if(ispisp==0)
           break;
           if(ispisp==8)
           {
              cout<<std::endl<<"Dovidjenja!";
           return 0;    
           }
           if(ispisp==1)
           {
               std::sort(vekp.begin(),vekp.end(),[](Prodaja prodaja1,Prodaja prodaja2)
    {
         Datum datum1=prodaja1.Prodaja::DajDatumProdaje(),datum2=prodaja2.Prodaja::DajDatumProdaje();
        if(datum1.Datum::DajGodinu()<datum2.Datum::DajGodinu()) return true;
        if(datum1.Datum::DajGodinu()>datum2.Datum::DajGodinu()) return false;
        if(datum1.Datum::DajMjesec()<datum2.Datum::DajMjesec()) return true;
        if(datum1.Datum::DajMjesec()>datum2.Datum::DajMjesec()) return false;
        if(datum1.Datum::DajDan()<datum2.Datum::DajDan()) return true;
        if(datum1.Datum::DajDan()>datum2.Datum::DajDan()) return false;
        return(prodaja1.Prodaja::DajImeKupca()<prodaja2.Prodaja::DajImeKupca());
    });
               for(int i=0;i<vekp.size();i++)
               {
                   vekp[i].Prodaja::Ispisi();
                   cout<<std::endl<<std::endl;
               }
           }
         }
      }
        if(opcprod==1)
        {
    while(true)
    {
        cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - dodavanje potpuno nove prodaje"<<std::endl<<" 2 - dodavanje nove prodaje na osnovu arhive"<<std::endl<<" 3 - kraj"<<std::endl;
        int opcp;
        cin>>opcp;
        if(opcp==0)
        break;
        if(opcp==3)
        {
            cout<<std::endl<<"Dovidjenja!";
           return 0; 
        }
        if(opcp==1)
        {
            unosnp:
            cout<<"Unesite ime i prezime agenta prodaje: ";
            string imea;
            cin.ignore(10000,'\n');
            std::getline(cin,imea);
            cout<<"Unesite datum prodaje (formata d/m/g): ";
            int d,m,g;
            char znak1,znak2;
            cin>>d>>znak1>>m>>znak2>>g;
            cout<<"Unesite cijenu stana: ";
            double cijena;
            cin>>cijena;
            cout<<"Unesite ime kupca: ";
            string imek;
            cin.ignore(10000,'\n');
            std::getline(cin,imek);
            cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
            int dk,mk,gk;
            char kznak1,kznak2;
            cin>>dk>>kznak1>>mk>>kznak2>>gk;
            string adresak;
            cout<<"Unesite adresu: ";
            cin.ignore(10000,'\n');
            std::getline(cin,adresak);
            int sprat,broj_soba;
            cout<<"Unesite sprat: ";
            cin>>sprat;
            cout<<"Unesite broj soba: ";
            cin>>broj_soba;
            int n;
            cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
            cin>>n;
            bool namjesten(false);
            if(n==1)
            namjesten=true;
            cout<<"Unesite kvadraturu: ";
            double kvadratura;
            cin>>kvadratura;
            try
            {
              Datum datk(dk,mk,gk);
              if(n!=0 && n!=1)
              throw std::domain_error("Neispravni podaci");
Kupac kup(imek,datk);
Stan stan(adresak,sprat,broj_soba,namjesten,kvadratura);
Prodaja pro(imea,cijena,d,m,g,imek,datk,adresak,sprat,broj_soba,namjesten,kvadratura);
vekp.push_back(pro);
veks.push_back(stan);
vekk.push_back(kup);
//prodaje.Prodaje::RegistrirajProdaju(&pro);
cout<<"Prodaja uspjesno dodana!"<<std::endl<<std::endl;
            }
            catch(std::domain_error izuzetak)
            {
                 cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
                goto unosnp;
            }
        }
          if(opcp==2)  
          {
              unosnpa:
            cout<<"Unesite ime i prezime agenta prodaje: ";
            string imea;
            cin.ignore(10000,'\n');
            std::getline(cin,imea);
            cout<<"Unesite datum prodaje (formata d/m/g): ";
            int d,m,g;
            char znak1,znak2;
            cin>>d>>znak1>>m>>znak2>>g;
            cout<<"Unesite cijenu stana: ";
            double cijena;
            cin>>cijena;
            cout<<"Odaberite kupca. Dostupni kupci su:"<<std::endl;
            for(int i=0;i<vekk.size();i++)
            {
                cout<<" "<<i+1<<" - ";
                vekk[i].Kupac::Ispisi();
                cout<<std::endl;
                if(i==vekk.size()-1)
                cout<<std::endl;
            }
            int odaberik;
            cin>>odaberik;
            odaberik--;
            cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
            for(int i=0;i<veks.size();i++)
           {
               cout<<" "<<i+1<<" - ";
               veks[i].Stan::Ispisi();
               cout<<std::endl;
               if(i==veks.size()-1)
               cout<<std::endl;
           }
           int odaberis;
           cin>>odaberis;
           odaberis--;
           try
           {
               Datum datpro(d,m,g);
               Prodaja nprod(imea,cijena,datpro,vekk[odaberik],veks[odaberis]);
              // prodaje.Prodaje::RegistrirajProdaju(&nprod);
vekp.push_back(nprod);
               cout<<"Prodaja uspjesno dodana!"<<std::endl<<std::endl;
           }
           catch(std::domain_error izuzetak)
           {
               cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<std::endl;
                goto unosnpa; 
           }
          }
        }
        }
        }
    }
        
}
    
	return 0;
}