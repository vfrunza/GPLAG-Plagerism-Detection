#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <new>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <list>
#include <initializer_list>
#include <cstring>
#include <iterator>

class Datum {
    int dan,mjesec,godina;
    
    public:
    Datum(int dan,int mjesec,int godina) {
        Datum::Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan,int mjesec,int godina);
    int DajDan() const {
        return dan;
    }
    int DajMjesec() const {
        return mjesec;
    }
    int DajGodinu() const {
        return godina;
}
void Ispisi() const {
    std::cout<<dan<<"/"<<mjesec<<"/"<<godina<<std::endl;
}
};
void Datum::Postavi(int dan,int mjesec,int godina) {
    int brojdana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0))
    brojdana[1]++;
    if(dan<1 || mjesec<1 || godina<1 || mjesec>12 || dan>brojdana[mjesec-1]) {
        throw std::domain_error("Neispravan datum");
        }
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
}


class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    public:
    Kupac(const std::string &ime_i_prezime,const Datum &datum_rodjenja) : datum_rodjenja(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu()) {
        Kupac::ime_i_prezime=ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja);
std::string DajImePrezime() const {
return ime_i_prezime;
}
    Datum DajDatumRodjenja() const {
        return datum_rodjenja;
    }
    void Ispisi() const {
        std::cout <<DajImePrezime()<<"("<<DajDatumRodjenja().DajDan()<<"/"<<DajDatumRodjenja().DajMjesec()<<"/"<<DajDatumRodjenja().DajGodinu()<<")"<<std::endl;
    }
};

void Kupac::Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja)
{
    for(int i=0;i<Kupac::DajImePrezime().length();i++) {
        if((ime_i_prezime[i]<'a' || ime_i_prezime[i]>'z') && (ime_i_prezime[i]<'A' || ime_i_prezime[i]>'Z') && (ime_i_prezime[i]<'0' || ime_i_prezime[i]>'9') && ime_i_prezime[i]!='-' && ime_i_prezime[i]!=' ')  {
            throw std::domain_error("Neispravno ime i prezime");
        }                                          
    }
    Kupac::ime_i_prezime=ime_i_prezime;
}

class Stan {
    std::string adresa;
    int sprat,broj_soba;
    double kvadratura;
    bool namjesten;
    
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,
 double kvadratura) {
     Postavi (adresa,sprat,broj_soba,namjesten,kvadratura);
 } 
void Postavi(const std::string &adresa, int sprat, int broj_soba,
 bool namjesten, double kvadratura);
std::string DajAdresu() const {
    return adresa;
}
int DajSprat() const {
    return sprat;
}
int DajBrojSoba() const {
    return broj_soba;
}
bool DajNamjesten() const {
    return namjesten;
}
double DajKvadraturu() const {
return kvadratura;
}

void Ispisi() const;
};
void Stan::Ispisi() const {
    std::cout<<"Stan se nalazi na adresi "<<(*this).DajAdresu()<< " na "<<(*this).DajSprat() <<". spratu i ima ";
    if((*this).DajBrojSoba()==1)
    std::cout<<" sobu."<<std::endl;
    else {
        if((*this).DajBrojSoba()>1 && (*this).DajBrojSoba()<5){
            std::cout<<" sobe."<<std::endl;
        }
        else {
            std::cout<<" soba."<<std::endl;
        }
    }
    std::cout<<"Kvadratura stana je "<<(*this).DajKvadraturu()<< " (m^2) i stan ";
    if((*this).DajNamjesten())
    std::cout<<"je namjesten.";
    else 
    std::cout<<" nije namjesten.";
}
void Stan::Postavi(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura) {
    int broj(0);
    if(sprat<0 || broj_soba<0 || kvadratura<0 || broj!=0) {
        throw std::domain_error("Neispravan unos podataka");
    }
  Stan::adresa=adresa;
  Stan::sprat=sprat; Stan::broj_soba=broj_soba;
   Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
}


class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
 const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan);
 
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
 std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,
 bool namjesten_stan, double broj_kvadrata);
void PromijeniKupca(const Kupac &novi_kupac); 
void PromijeniStan(const Stan &novi_stan);
void PromijeniDatumKupovine(const Datum &novi_datum);
void PromijeniCijenuProdaje(const double &nova_cijena);
void PomjeriDanUnaprijed();
void PomjeriDanUnazad();
std::string DajImeAgenta() const {
    return ime_agenta_prodaje;
}
std::string DajImeKupca() const {
    return kupac_stana.DajImePrezime();
}
Datum DajDatumProdaje() const {
    return datum_prodaje;
}
double DajCijenuStana() const {
    return cijena_stana;
}
friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2); 
void Ispisi() const;
};

  Prodaja::Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan) : datum_prodaje(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()), kupac_stana(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja()), 
 kupljeni_stan(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu()) {
     Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
     Prodaja::cijena_stana=cijena_stana;
   }
   Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
 std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,
 bool namjesten_stan, double broj_kvadrata) : datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje), kupac_stana(ime_kupca,datum_rodjenja_kupca) ,kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) {
      Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
      Prodaja::cijena_stana=cijena_stana;
}

void Prodaja::PromijeniKupca(const Kupac &novi_kupac) {
    Prodaja::kupac_stana.Postavi(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja());
}
void Prodaja::PromijeniStan(const Stan &novi_stan) {
    Prodaja::kupljeni_stan.Postavi(novi_stan.DajAdresu(),novi_stan.DajSprat(),novi_stan.DajBrojSoba(),novi_stan.DajNamjesten(),novi_stan.DajKvadraturu());
}
void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum) {
    Prodaja::datum_prodaje.Postavi(novi_datum.DajDan(),novi_datum.DajMjesec(),novi_datum.DajGodinu());
}
void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena) {
      cijena_stana=nova_cijena;
      }
      void Prodaja::PomjeriDanUnaprijed() {
          int n(DajDatumProdaje().DajDan());
          n++;
          Prodaja::datum_prodaje.Postavi(n,DajDatumProdaje().DajMjesec(),DajDatumProdaje().DajGodinu());
      }
void Prodaja::PomjeriDanUnazad() {
    int z(DajDatumProdaje().DajDan());
    z--;
    Prodaja::datum_prodaje.Postavi(z,DajDatumProdaje().DajMjesec(),DajDatumProdaje().DajGodinu());
}
bool ProdatPrije(const Prodaja &p1,const Prodaja &p2) {
    Datum dat1(p1.DajDatumProdaje().DajDan(),p1.DajDatumProdaje().DajMjesec(),p1.DajDatumProdaje().DajGodinu());
    Datum dat2(p2.DajDatumProdaje().DajDan(),p2.DajDatumProdaje().DajMjesec(),p2.DajDatumProdaje().DajGodinu());
    if(dat1.DajGodinu()<dat2.DajGodinu()) {
        return true;
    }
    else {
        if(dat1.DajGodinu()==dat2.DajGodinu()) {
            if(dat1.DajMjesec()<dat2.DajMjesec()) 
            return true;
            else {
                if(dat1.DajMjesec()==dat2.DajMjesec()) {
                    if(dat1.DajDan()<dat2.DajDan()) 
                        return true;
                        else 
                        return false;
                    }
                    else 
                    return false;
                }
            }
            else 
            return false;
        }
    }
bool SkupljiStan(const Prodaja &p1,const Prodaja &p2) {
    return p1.DajCijenuStana()>p2.DajCijenuStana();
}
void Prodaja::Ispisi() const {
    std::cout<<"Ime agenta: "<<std::left<<DajImeAgenta()<<std::endl;
    std::cout<<"Ime kupca: "<<std::left<<kupac_stana.DajImePrezime()<<std::endl;
    std::cout<<"Zakazani datum prodaje: "<<std::left<<datum_prodaje.DajDan()<<"/"<<datum_prodaje.DajMjesec()<<"/"<<datum_prodaje.DajGodinu()<<std::endl;
    std::cout<<"Cijena stana: "<<std::left<<DajCijenuStana()<<std::endl;
    std::cout<<"Informacije o stanu: "<<std::endl<<"Stan se nalazi na adresi "<<kupljeni_stan.DajAdresu()<< " na "<<kupljeni_stan.DajSprat() <<". spratu i ima ";
    if(kupljeni_stan.DajBrojSoba()==1)
    std::cout<<" sobu."<<std::endl;
    else {
        if(kupljeni_stan.DajBrojSoba()>1 && kupljeni_stan.DajBrojSoba()<5){
            std::cout<<" sobe."<<std::endl;
        }
        else {
            std::cout<<" soba."<<std::endl;
        }
    }
    std::cout<<"Kvadratura stana je "<<kupljeni_stan.DajKvadraturu()<< " (m^2) i stan ";
    if(kupljeni_stan.DajNamjesten())
    std::cout<<"je namjesten.";
    else 
    std::cout<<" nije namjesten.";
}

/*class Prodaje {
    int max_broj_prodaja;
    Prodaja** pok_na_prodaju=nullptr;
    public:
      explicit Prodaje(int max_broj_prodaja) {
          pok_na_prodaju=new  Prodaja*[max_broj_prodaja];
          for(int j=0;j<max_broj_prodaja;j++) {
              pok_na_prodaju[j]=nullptr;
          }
          Prodaje::max_broj_prodaja=max_broj_prodaja;
      }
Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : max_broj_prodaja(spisak_prodaja.size()), pok_na_prodaju(new Prodaja* [spisak_prodaja.size()]) {
    std::copy(spisak_prodaja.begin(),spisak_prodaja.end(),*pok_na_prodaju);
}
    
~Prodaje() {
    if(pok_na_prodaju) {
    for(int i=0;i<max_broj_prodaja;i++) 
    delete[] pok_na_prodaju[i];
    delete [] pok_na_prodaju;
    pok_na_prodaju=nullptr;
    max_broj_prodaja=0;
}
}
Prodaje(const Prodaje &prodaje);
Prodaje(Prodaje &&prodaje);
Prodaje &operator =(const Prodaje &prodaje);
Prodaje &operator =(Prodaje &&prodaje);
void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
 double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
const Stan &kupljeni_stan);
void RegistrirajProdaju(Prodaja *prodaja);
int DajBrojProdaja() const;
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
};


Prodaje::Prodaje(const Prodaje &prodaje) : max_broj_prodaja(prodaje.max_broj_prodaja), pok_na_prodaju(new Prodaja* [prodaje.max_broj_prodaja]) {
    std::copy(**prodaje.pok_na_prodaju,*(*prodaje.pok_na_prodaju+max_broj_prodaja),**pok_na_prodaju);
}
Prodaje::Prodaje(Prodaje &&prodaje): max_broj_prodaja(prodaje.max_broj_prodaja), pok_na_prodaju(prodaje.pok_na_prodaju) {
prodaje.pok_na_prodaju=nullptr;
}
Prodaje &Prodaje:: operator=(const Prodaje &prodaje) {
    if(&prodaje!=this) {
        delete [] Prodaje::pok_na_prodaju;
        max_broj_prodaja=prodaje.max_broj_prodaja;
        pok_na_prodaju=new Prodaja* [max_broj_prodaja];
        std::copy(*prodaje.pok_na_prodaju,*prodaje.pok_na_prodaju+max_broj_prodaja,*pok_na_prodaju);
    }
    return *this;
}

Prodaje &Prodaje:: operator=(Prodaje &&prodaje) {
    if(&prodaje!=this) {
        max_broj_prodaja=prodaje.max_broj_prodaja;
        pok_na_prodaju=prodaje.pok_na_prodaju;
        prodaje.pok_na_prodaju=nullptr;
    }
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan) {
    int i;
    for(i=0;i<max_broj_prodaja;i++) {
        if(pok_na_prodaju[i]==nullptr) {
            pok_na_prodaju[i]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
            break;
        }
    }
    if(i==max_broj_prodaja)
    throw std::range_error("Dostignut maksimalan broj prodaja");
}


void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
    int i;
for(i=0;i<max_broj_prodaja;i++) {
    if(pok_na_prodaju[i]==nullptr) {
        pok_na_prodaju[i]=prodaja;
        break;
    }
}
if(i==max_broj_prodaja) 
throw std::range_error("Dostignut maksimalan broj prodaja");
}
int Prodaje::DajBrojProdaja() const {
    int broj(0);
    for(int i=0;i<max_broj_prodaja;i++) {
        if(pok_na_prodaju[i]!=nullptr) 
        broj++;
    }
    return broj;
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    return std::count_if(pok_na_prodaju,pok_na_prodaju+max_broj_prodaja,[&datum](Prodaja *p) {
        return p->DajDatumProdaje().DajDan()==datum.DajDan() && p->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && p->DajDatumProdaje().DajGodinu()==datum.DajGodinu();
    });
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    int broj(0);
    for(int i=0;i<max_broj_prodaja;i++) {
        if(pok_na_prodaju[i]->DajImeAgenta()==ime_agenta) 
        broj++;
    }
    return broj;
}

Prodaja Prodaje::DajNajranijuProdaju() const {
      if(Prodaje::max_broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
      int indeks(0);
      for(int i=0;i<max_broj_prodaja;i++) {
          for(int j=0;j<max_broj_prodaja;j++) {
              if(i!=j && ProdatPrije(*pok_na_prodaju[i],*pok_na_prodaju[j]))
              indeks=i;
          }
      }
      return *pok_na_prodaju[indeks];
}
Prodaja &Prodaje::DajNajskupljuProdaju() {
    if(Prodaje::max_broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    return *std::max_element(*pok_na_prodaju,*pok_na_prodaju+max_broj_prodaja,[](Prodaja p1,Prodaja p2) {
        return (p1).DajCijenuStana()>(p2).DajCijenuStana();
    });
}
Prodaja  Prodaje::DajNajskupljuProdaju() const {
    if(Prodaje::max_broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    int indeks(0);
    for(int i=0;i<DajBrojProdaja();i++) {
        for(int j=0;j<DajBrojProdaja();j++) {
            if(i!=j && SkupljiStan(*pok_na_prodaju[i],*pok_na_prodaju[j])) {
                indeks=i;
            }
        }
    }
    return *pok_na_prodaju[indeks];
}
void Prodaje::IsprazniKolekciju() {
     
}

void Prodaje::ObrisiNajranijuProdaju() {
      Prodaja* pok(&DajNajranijuProdaju());
      delete pok;
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
    for(int i=0;i<DajBrojProdaja();i++) {
        if((*pok_na_prodaju[i]).DajImeAgenta()==ime_agenta) {
            delete pok_na_prodaju[i];
            pok_na_prodaju[i]=nullptr;
        }
}
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
    for(int i=0;i<DajBrojProdaja();i++) {
        if((pok_na_prodaju[i])->DajDatumProdaje().DajDan()==datum.DajDan() && (pok_na_prodaju[i])->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && (pok_na_prodaju[i])->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) {
            delete pok_na_prodaju[i];
            pok_na_prodaju=nullptr;
        }
}
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum)  const {
    for(int i=0;i<DajBrojProdaja();i++) {
        Datum dat(datum.DajDan(),datum.DajMjesec(),datum.DajGodinu());
        if((pok_na_prodaju[i])->DajDatumProdaje().DajDan()==dat.DajDan() && (pok_na_prodaju[i])->DajDatumProdaje().DajMjesec()==dat.DajMjesec() && (pok_na_prodaju[i])->DajDatumProdaje().DajGodinu()==dat.DajGodinu()) {
            datum.Ispisi();
        }
    }
}
void Prodaje::IspisiSveProdaje() const {
    for(int i=0;i<max_broj_prodaja;i++) {
        if(pok_na_prodaju[i]) {
            (*pok_na_prodaju[i]).Ispisi();
        }
    }
}*/
int main ()
{
    std::cout<<"Unesite sta hocete";
	return 0;
}