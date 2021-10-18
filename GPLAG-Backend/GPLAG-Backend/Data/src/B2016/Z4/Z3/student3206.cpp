#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <algorithm>

using std::cin;
using std::cout;

int BrojRazmaka(const std::string s){
    int brojac(0);
    for(int i=0;i<s.length();i++)
    if(s[i]==' ')
    brojac++;
    return brojac;
}
class Datum{
    int d,m,g;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const{return d;}
    int DajMjesec() const{return m;}
    int DajGodinu() const{return g;}
    void Ispisi() const;
};

Datum::Datum(int dan,int mjesec,int godina){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
    throw std::domain_error("Neispravan datum");
    d=dan;m=mjesec;g=godina;
}

void Datum::Postavi(int dan,int mjesec, int godina){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
    throw std::domain_error("Neispravan datum");
    d=dan;m=mjesec;g=godina;
}

void Datum::Ispisi() const{
    cout<<d<<"/"<<m<<"/"<<g;
}

class Kupac{
    std::string imeiprezime;
    Datum datumrodj;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const{return imeiprezime;}
    Datum DajDatumRodjenja() const{return datumrodj;}
    void Ispisi() const;
};

Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): datumrodj(datum_rodjenja){
    for(int i=0;i<ime_i_prezime.length();i++){
        if((ime_i_prezime[i]<'A' || ime_i_prezime[i]>'Z') && (ime_i_prezime[i]<'a' || ime_i_prezime[i]>'z') && BrojRazmaka(ime_i_prezime)>1)
        throw std::domain_error("Neispravno ime i prezime");
    }
    imeiprezime=ime_i_prezime;
}

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    datumrodj=datum_rodjenja;
    for(int i=0;i<ime_i_prezime.length();i++){
        if((ime_i_prezime[i]<'A' || ime_i_prezime[i]>'Z') && (ime_i_prezime[i]<'a' || ime_i_prezime[i]>'z'))
        throw std::domain_error("Neispravno ime i prezime");
    }
    imeiprezime=ime_i_prezime;
}

void Kupac::Ispisi() const{
    cout<<imeiprezime<<" (";
    DajDatumRodjenja().Ispisi();
    cout<<")";
}

class Stan{
    std::string adresa1;
    int sprat1,brsoba;
    bool namjesten1;
    double kvadratura1;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const{return adresa1;}
    int DajSprat() const{return sprat1;}
    int DajBrojSoba() const{return brsoba;}
    bool DajNamjesten() const{return namjesten1;}
    double DajKvadraturu() const{return kvadratura1;};
    void Ispisi() const;
};

Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    adresa1=adresa; sprat1=sprat; brsoba=broj_soba; namjesten1=namjesten; kvadratura1=kvadratura;
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    adresa1=adresa; sprat1=sprat; brsoba=broj_soba; namjesten1=namjesten; kvadratura1=kvadratura;
}

void Stan::Ispisi() const{
    cout<<"Stan se nalazi na adresi "<<adresa1<<" na "<<sprat1<<"."<<" spratu i ima ";
    if(brsoba==1)
    cout<<brsoba<<" sobu."<<std::endl;
    else if(brsoba>1 && brsoba<5)
    cout<<brsoba<<" sobe."<<std::endl;
    else
    cout<<brsoba<<" soba."<<std::endl;
    cout<<"Kvadratura stana je "<<kvadratura1<<" i stan ";
    if(namjesten1) cout<<"je namjesten.";
    else cout<<"nije namjesten.";
}

class Prodaja{
    std::string agent;
    double cijena;
    Datum datprodaje;
    Kupac kupac;
    Stan kupljenistan;
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac){kupac=novi_kupac;} 
    void PromijeniStan(const Stan &novi_stan){kupljenistan=novi_stan;}
    void PromijeniDatumKupovine(const Datum &novi_datum){datprodaje=novi_datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena){cijena=nova_cijena;}
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const{return agent;}
    std::string DajImeKupca() const{return kupac.DajImePrezime();}
    Datum DajDatumProdaje() const{return datprodaje;}
    double DajCijenuStana() const{return cijena;}
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan): agent(ime_agenta_prodaje), cijena(cijena_stana), datprodaje(datum_prodaje), kupac(kupac_stana), kupljenistan(kupljeni_stan){}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):agent(ime_agenta_prodaje),cijena(cijena_stana), datprodaje(dan_prodaje,mjesec_prodaje,godina_prodaje), kupac(ime_kupca,datum_rodjenja_kupca), kupljenistan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){}

void Prodaja::PomjeriDanUnaprijed(){
    int dan1(datprodaje.DajDan());
    int mjesec1(datprodaje.DajMjesec());
    int godina1(datprodaje.DajGodinu());
    dan1++;
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina1%4==0 && godina1%100!=0 || godina1%400==0) broj_dana[1]++;
    if(dan1>broj_dana[mjesec1-1]){
        dan1=1;
        mjesec1++;
    }
    if(mjesec1>12){
        mjesec1=1;
        godina1++;
    }
    Datum novidatum(dan1,mjesec1,godina1);
    datprodaje=novidatum;
}

void Prodaja::PomjeriDanUnazad(){
    int dan1(datprodaje.DajDan());
    int mjesec1(datprodaje.DajMjesec());
    int godina1(datprodaje.DajGodinu());
    dan1--;
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina1%4==0 && godina1%100!=0 || godina1%400==0) broj_dana[1]++;
    if(dan1==0){
        mjesec1--;
        if(mjesec1==0){
        mjesec1=12;
        godina1--;
        }
        dan1=broj_dana[mjesec1-1];
    }
    Datum novidatum(dan1,mjesec1,godina1);
    datprodaje=novidatum;
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if(p1.datprodaje.DajGodinu()<p2.datprodaje.DajGodinu()) return true;
    else if(p1.datprodaje.DajGodinu()>p2.datprodaje.DajGodinu()) return false;
    else{
        if(p1.datprodaje.DajMjesec()<p2.datprodaje.DajMjesec()) return true;
        else if(p1.datprodaje.DajMjesec()>p2.datprodaje.DajMjesec()) return false;
        else{
            if(p1.datprodaje.DajDan()<p2.datprodaje.DajDan()) return true;
            else return false;
        }
    }
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    if(p1.cijena>p2.cijena) return true;
    return false;
}

void Prodaja::Ispisi() const{
    cout<<std::left<<std::setw(30)<<"Ime agenta:";
    cout<<agent<<std::endl;
    cout<<std::left<<std::setw(30)<<"Ime kupca:";
    kupac.Ispisi();
    cout<<std::endl;
    cout<<std::left<<std::setw(30)<<"Zakazani datum prodaje:";
    datprodaje.Ispisi();
    cout<<std::endl;
    cout<<std::left<<std::setw(30)<<"Cijena stana:";
    cout<<cijena<<std::endl;
    cout<<"Informacije o stanu:"<<std::endl;
    kupljenistan.Ispisi();
    cout<<std::endl;
}

class Prodaje{
    int max_br_prodaja,broj_prodaja;
    Prodaja** prodajE;
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const{return broj_prodaja;}
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

Prodaje::Prodaje(int max_broj_prodaja){
    broj_prodaja=0;
    max_br_prodaja=max_broj_prodaja;
    prodajE=new Prodaja*[max_br_prodaja];
}

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja){
    broj_prodaja=spisak_prodaja.size();
    max_br_prodaja=spisak_prodaja.size();
    prodajE=new Prodaja*[spisak_prodaja.size()];
    int i(0);
    for(auto it=spisak_prodaja.begin();it!=spisak_prodaja.end();it++){
        prodajE[i]=new Prodaja(*it);
        i++;
    }
}

Prodaje::~Prodaje(){
    for(int i=0;i<broj_prodaja;i++) delete prodajE[i];
    delete[] prodajE;
}

Prodaje::Prodaje(const Prodaje &prodaje){
    max_br_prodaja=prodaje.max_br_prodaja;
    broj_prodaja=prodaje.broj_prodaja;
    prodajE=new Prodaja*[max_br_prodaja];
    for(int i=0;i<broj_prodaja;i++) prodajE[i]=new Prodaja(*prodaje.prodajE[i]);
}

Prodaje::Prodaje(Prodaje &&prodaje){
    max_br_prodaja=prodaje.max_br_prodaja;
    broj_prodaja=prodaje.broj_prodaja;
    prodajE=prodaje.prodajE;
    prodaje.prodajE=nullptr;
    prodaje.broj_prodaja=0;
}

Prodaje & Prodaje::operator =(const Prodaje &prodaje){
    max_br_prodaja=prodaje.max_br_prodaja;
    if(prodaje.broj_prodaja>broj_prodaja)
    for(int i=broj_prodaja;i<prodaje.broj_prodaja;i++) prodajE[i]=new Prodaja(*prodaje.prodajE[i]);
    broj_prodaja=prodaje.broj_prodaja;
    for(int i=0;i<broj_prodaja;i++) *prodajE[i]=*(prodaje.prodajE[i]);
    return *this;
}

Prodaje & Prodaje::operator =(Prodaje &&prodaje){
    broj_prodaja=prodaje.broj_prodaja;
    prodajE=prodaje.prodajE;
    prodaje.prodajE=nullptr;
    prodaje.broj_prodaja=0;
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
    if(broj_prodaja==max_br_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    prodajE[broj_prodaja]=new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
    broj_prodaja++;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
    if(broj_prodaja==max_br_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    prodajE[broj_prodaja]=new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    broj_prodaja++;
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(broj_prodaja==max_br_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    prodajE[broj_prodaja]=prodaja;
    broj_prodaja++;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    return std::count_if(prodajE,prodajE+broj_prodaja,[datum](Prodaja* p){
       if((*p).DajDatumProdaje().DajDan()==datum.DajDan() && (*p).DajDatumProdaje().DajMjesec()==datum.DajMjesec() && (*p).DajDatumProdaje().DajGodinu()==datum.DajGodinu()) return true;
       return false;
    });
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    int brojac(0);
    for(int i=0;i<broj_prodaja;i++){
        if((*prodajE[i]).DajImeAgenta()==ime_agenta) brojac++;
    }
    return brojac;
}

Prodaja &Prodaje::DajNajranijuProdaju(){
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::min_element(prodajE,prodajE+broj_prodaja,[](Prodaja* p1,Prodaja* p2){
       if((*p1).DajDatumProdaje().DajGodinu()<(*p2).DajDatumProdaje().DajGodinu()) return true;
        else if((*p1).DajDatumProdaje().DajGodinu()>(*p2).DajDatumProdaje().DajGodinu()) return false;
        else{
            if((*p1).DajDatumProdaje().DajMjesec()<(*p2).DajDatumProdaje().DajMjesec()) return true;
            else if((*p1).DajDatumProdaje().DajMjesec()>(*p2).DajDatumProdaje().DajMjesec()) return false;
            else{
                if((*p1).DajDatumProdaje().DajDan()<(*p2).DajDatumProdaje().DajDan()) return true;
                else return false;
            }
        } 
    });
    return **it;
}

Prodaja Prodaje::DajNajranijuProdaju() const{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::min_element(prodajE,prodajE+broj_prodaja,[](Prodaja* p1,Prodaja* p2){
       if((*p1).DajDatumProdaje().DajGodinu()<(*p2).DajDatumProdaje().DajGodinu()) return true;
        else if((*p1).DajDatumProdaje().DajGodinu()>(*p2).DajDatumProdaje().DajGodinu()) return false;
        else{
            if((*p1).DajDatumProdaje().DajMjesec()<(*p2).DajDatumProdaje().DajMjesec()) return true;
            else if((*p1).DajDatumProdaje().DajMjesec()>(*p2).DajDatumProdaje().DajMjesec()) return false;
            else{
                if((*p1).DajDatumProdaje().DajDan()<(*p2).DajDatumProdaje().DajDan()) return true;
                else return false;
            }
        } 
    });
    return **it;
}

Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::max_element(prodajE,prodajE+broj_prodaja,[](Prodaja* p1,Prodaja* p2){
       if((*p1).DajCijenuStana()<(*p2).DajCijenuStana()) return true;
       return false;
    });
    return **it;
}

Prodaja Prodaje::DajNajskupljuProdaju() const{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::max_element(prodajE,prodajE+broj_prodaja,[](Prodaja* p1,Prodaja* p2){
       if((*p1).DajCijenuStana()<(*p2).DajCijenuStana()) return true;
       return false;
    });
    return **it;
}

void Prodaje::IsprazniKolekciju(){
    for(int i=0;i<broj_prodaja;i++) delete prodajE[i];
    broj_prodaja=0;
}

void Prodaje::ObrisiNajranijuProdaju(){
    if(broj_prodaja==0) throw std::range_error("Prazna kolekcija");
    for(int i=0;i<broj_prodaja;i++)
    if((*prodajE[i]).DajDatumProdaje().DajDan()==DajNajranijuProdaju().DajDatumProdaje().DajDan() && (*prodajE[i]).DajDatumProdaje().DajMjesec()==DajNajranijuProdaju().DajDatumProdaje().DajMjesec() && (*prodajE[i]).DajDatumProdaje().DajGodinu()==DajNajranijuProdaju().DajDatumProdaje().DajGodinu()){
        delete prodajE[i];
        for(int j=i+1;j<broj_prodaja;j++){
            prodajE[j-1]=prodajE[j];
        }
        broj_prodaja--;
        break;
    }
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    if(broj_prodaja==0) throw std::range_error("Prazna kolekcija");
    for(int i=0;i<broj_prodaja;i++){
        if((*prodajE[i]).DajImeAgenta()==ime_agenta){
            delete prodajE[i];
            for(int j=i+1;j<broj_prodaja;j++){
                prodajE[j-1]=prodajE[j];
            }
            broj_prodaja--;
            i--;
        }
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    if(broj_prodaja==0) throw std::range_error("Prazna kolekcija");
    for(int i=0;i<broj_prodaja;i++){
        if((*prodajE[i]).DajDatumProdaje().DajDan()==datum.DajDan() && (*prodajE[i]).DajDatumProdaje().DajMjesec()==datum.DajMjesec() && (*prodajE[i]).DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
            delete prodajE[i];
            for(int j=i+1;j<broj_prodaja;j++){
                prodajE[j-1]=prodajE[j];
            }
            broj_prodaja--;
            i--;
        }
    }
}

int main ()
{
    Datum d(19,2,1998);
    Kupac k("Nedim Zaimovic",d);
    Datum d1(4,4,1997);
    Datum d2(1,1,2010);
    Datum d4(10,5,2010);
    Stan s("Zagrebacka 1",1,3,false,50);
    Kupac k1("Hamza Hadzic",d1);
    std::string l("Emir Merdic");
    Prodaja p1("Murga",75000,11,5,2012,l,d1,"Zagrebacka 15",2,5,false,108);
    Prodaja p2("Murga",75020,11,5,2012,l,d1,"Zagrebacka 15",2,5,false,108);
    if(SkupljiStan(p1,p2)) cout<<"Da";
    else cout<<"Ne";
	return 0;
}