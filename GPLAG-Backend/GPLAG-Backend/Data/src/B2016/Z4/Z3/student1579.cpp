/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<string>
#include<algorithm>
#include<stdexcept>
#include<iomanip>
#include<initializer_list>
#include<vector>
class Datum
{
    int d,m,g;
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const {
        return d;
    }
    int DajMjesec() const {
        return m;
    }
    int DajGodinu() const {
        return g;
    }
    void Ispisi() const {
        std::cout<<d<<"/"<<m<<"/"<<g;
    }
};
Datum::Datum(int dan, int mjesec, int godina)
{
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum");
    d=dan;
    m=mjesec;
    g=godina;
}
void Datum::Postavi(int dan, int mjesec, int godina)
{
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0) )broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum");
    d=dan;
    m=mjesec;
    g=godina;
}
class Kupac
{
    std::string iip;
    Datum datrodj;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const {
        return iip;
    }
    Datum DajDatumRodjenja() const {
        return datrodj;
    }
    void Ispisi() const {
        std::cout<<iip<<" (";
        datrodj.Ispisi();
        std::cout<<")";
    }
};
Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):datrodj(datum_rodjenja)
{
    for(int i=0; i<ime_i_prezime.length(); i++) {
        //if(ime_i_prezime[i]!=' ' || (ime_i_prezime[i]<'A' &&  ime_i_prezime[i]>'Z') ||(ime_i_prezime[i]<'a' &&  ime_i_prezime[i]>'z') || (ime_i_prezime[i]<'0' &&  ime_i_prezime[i]>'9') || ime_i_prezime[i]!=39 || ime_i_prezime[i]!='-' ) {
        if(!(ime_i_prezime[i]==' ' || (ime_i_prezime[i]>='A' &&  ime_i_prezime[i]<='Z') ||(ime_i_prezime[i]>='a' &&  ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='0' &&  ime_i_prezime[i]<='9') || ime_i_prezime[i]==39 || ime_i_prezime[i]=='-' )) {
            throw std::domain_error("Neispravno ime i prezime");
        }
    }
    iip=ime_i_prezime;
}
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
{
    for(int i=0; i<ime_i_prezime.length(); i++) {
        if(!(ime_i_prezime[i]==' ' || (ime_i_prezime[i]>='A' &&  ime_i_prezime[i]<='Z') ||(ime_i_prezime[i]>='a' &&  ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='0' &&  ime_i_prezime[i]<='9') || ime_i_prezime[i]==39 || ime_i_prezime[i]=='-' )) {
            //if(ime_i_prezime[i]!=' ' || (ime_i_prezime[i]<'A' ||  ime_i_prezime[i]>'Z') ||(ime_i_prezime[i]<'a' ||  ime_i_prezime[i]>'z') || (ime_i_prezime[i]<'0' ||  ime_i_prezime[i]>'9') || ime_i_prezime[i]!=39 || ime_i_prezime[i]!='-' ) {
            throw std::domain_error("Neispravno ime i prezime");
        }
    }
    datrodj.Postavi(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
    iip=ime_i_prezime;
}
class Stan
{
    std::string adr;
    int spr,brsoba;
    bool sredjen;
    double povrsina;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura);
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);

    std::string DajAdresu() const {
        return adr;
    }
    int DajSprat() const {
        return spr;
    }
    int DajBrojSoba() const {
        return brsoba;
    }
    bool DajNamjesten() const {
        return sredjen;
    }
    double DajKvadraturu() const {
        return povrsina;
    }
    void Ispisi() const;
};
Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    if(sprat<0 || broj_soba<0 || kvadratura<0 )
        throw std::domain_error("Neispravan unos podataka");
    adr=adresa;
    spr=sprat;
    brsoba=broj_soba;
    sredjen=namjesten;
    povrsina=kvadratura;
}
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    if(sprat<0 || broj_soba<0 || kvadratura<0)
        throw std::domain_error("Neispravan unos podataka");
    adr=adresa;
    spr=sprat;
    brsoba=broj_soba;
    sredjen=namjesten;
    povrsina=kvadratura;
}
void Stan::Ispisi() const
{
    if((brsoba)%10==1 && brsoba!=11 )
        std::cout<<"Stan se nalazi na adresi "<<adr<<" na "<<spr<<". spratu i ima "<<brsoba<<" sobu. ";
    if(((brsoba)%10==2 && brsoba!=12) || ((brsoba)%10==3 && brsoba!=13)|| ((brsoba)%10==4 && brsoba!=14))
        std::cout<<"Stan se nalazi na adresi "<<adr<<" na "<<spr<<". spratu i ima "<<brsoba<<" sobe. ";
    else
        std::cout<<"Stan se nalazi na adresi "<<adr<<" na "<<spr<<". spratu i ima "<<brsoba<<" soba. ";
    if(sredjen)
        std::cout<<"Kvadratura stana je "<<povrsina<<" (m^2) i stan je namjesten.";
    else
        std::cout<<"Kvadratura stana je "<<povrsina<<" (m^2) i stan nije namjesten.";
}
class Prodaja
{
    std::string agent;
    double cjenstastana;
    Datum datprodaje;
    Kupac kupacstana;
    Stan kupljenistan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata);

    void PromijeniKupca(const Kupac &novi_kupac) {
        kupacstana.Postavi(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja());
    }
    void PromijeniStan(const Stan &novi_stan) {
        kupljenistan.Postavi(novi_stan.DajAdresu(),novi_stan.DajSprat(),novi_stan.DajBrojSoba(),novi_stan.DajNamjesten(),novi_stan.DajKvadraturu());
    }
    void PromijeniDatumKupovine(const Datum &novi_datum) {
        datprodaje.Postavi(novi_datum.DajDan(),novi_datum.DajMjesec(),novi_datum.DajGodinu());
    }
    void PromijeniCijenuProdaje(const double &nova_cijena) {
        cjenstastana=nova_cijena;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const {
        return agent;
    }
    std::string DajImeKupca() const {
        return kupacstana.DajImePrezime();
    }
    Datum DajDatumProdaje() const {
        return datprodaje;
    }
    double DajCijenuStana() const {
        return cjenstastana;
    }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const ;
};
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan):datprodaje(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()),kupacstana(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja()),kupljenistan(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu())
{
    cjenstastana=cijena_stana;
    agent=ime_agenta_prodaje;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string &ime_kupca,
                 const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana,
                 int broj_soba,bool namjesten_stan, double broj_kvadrata):datprodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),kupacstana(ime_kupca,datum_rodjenja_kupca),kupljenistan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)
{
    agent=ime_agenta_prodaje;
    cjenstastana=cijena_stana;
}
void Prodaja::PomjeriDanUnaprijed()
{
    int d=datprodaje.DajDan(),m=datprodaje.DajMjesec(),g=datprodaje.DajGodinu();
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g%4==0 && (g%100!=0 || g%400==0)) broj_dana[1]++;
    if(d==31 && m==12) {
        g++;
        d=1;
        m=1;
    }
    if(d==broj_dana[m-1]) {
        m++;
        d=1;
    } else d++;
    datprodaje.Postavi(d,m,g);
}
void Prodaja::PomjeriDanUnazad()
{
    int d=datprodaje.DajDan(),m=datprodaje.DajMjesec(),g=datprodaje.DajGodinu();
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g%4==0 && (g%100!=0 || g%400==0)) broj_dana[1]++;
    if(d==1 && m==1) {
        g--;
        d=31;
        m=12;
    }
    if(d==1) {
        m--;
        d=broj_dana[m-2];
    } else d++;
    datprodaje.Postavi(d,m,g);
}
void Prodaja::Ispisi() const
{
    std::cout<<std::setw(30)<<std::left<<"Ime agenta: ";
    std::cout<<agent<<std::endl;
    std::cout<<std::setw(30)<<std::left<<"Ime kupca: ";
    kupacstana.Ispisi();
    std::cout<<std::endl;
    std::cout<<std::setw(30)<<std::left<<"Zakazani datum prodaje: ";
    datprodaje.Ispisi();
    std::cout << std::endl;
    std::cout<<std::setw(30)<<std::left<<"Cijena stana: ";
    std::cout<<cjenstastana<<std::endl;
    std::cout << "Informacije o stanu: " << std::endl;
    kupljenistan.Ispisi();
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu()) return true;
    if(p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec()) return true;
    if(p1.DajDatumProdaje().DajDan()<p2.DajDatumProdaje().DajDan()) return true;
    return false;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.cjenstastana>p2.cjenstastana) return true;
    return false;
}


class Prodaje
{
    Prodaja **poknaprodaju;
    int velniza;
    const int dimenzija;
    void Oslobodimem() {
        if(poknaprodaju==nullptr) return;
        for(int i=0; i<dimenzija; i++)
            delete poknaprodaju[i];
        delete [] poknaprodaju;
    }

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
    int DajBrojProdaja() const {
        return velniza;
    }
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
Prodaje::Prodaje(int max_broj_prodaja):poknaprodaju(nullptr),dimenzija(max_broj_prodaja)
{
    try {
        poknaprodaju=new Prodaja *[max_broj_prodaja];
        for(int i=0; i<max_broj_prodaja; i++)
            poknaprodaju[i]=nullptr;
    } catch(...) {
        Oslobodimem();
        throw;
    }
    velniza=0;
}
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja):poknaprodaju(nullptr),velniza(spisak_prodaja.size()),dimenzija(spisak_prodaja.size())
{
    try {
        poknaprodaju=new Prodaja*[spisak_prodaja.size()];
        for(int i=0; i<velniza; i++)
            poknaprodaju[i]=nullptr;
    } catch(...) {
        Oslobodimem();
        throw;
    }
    auto it=spisak_prodaja.begin();
    for(int i=0; i<velniza; i++) {
        try {
            poknaprodaju[i]=new Prodaja(*it++);
        } catch(...) {
            Oslobodimem();
            throw;
        }
    }
}
Prodaje::~Prodaje()
{
    for(int i=0; i<dimenzija; i++)
        delete poknaprodaju[i];
    delete [] poknaprodaju;
}

Prodaje::Prodaje(const Prodaje &prodaje):poknaprodaju(nullptr),velniza(prodaje.velniza),dimenzija(prodaje.dimenzija)
{
    try {
        poknaprodaju=new Prodaja *[velniza];
    } catch(...) {
        Oslobodimem();
        throw;
    }
    try {
        for(int i=0; i<velniza; i++) {
            this->poknaprodaju[i]=new Prodaja (*prodaje.poknaprodaju[i]);
        }
    } catch(...) {
        Oslobodimem();
        throw;
    }
}
Prodaje::Prodaje(Prodaje &&prodaje):poknaprodaju(nullptr),velniza(prodaje.velniza),dimenzija(prodaje.dimenzija)
{
    poknaprodaju=prodaje.poknaprodaju;
    prodaje.poknaprodaju=nullptr;
}
Prodaje &Prodaje::operator =(const Prodaje &prodaje)
{
    if(dimenzija!=prodaje.dimenzija) {
        throw std::range_error("Dostignut maksimalni broj prodaja");
    }
    if(&prodaje!=this) return *this;

    for(int i=0; i<velniza; i++)
        delete poknaprodaju[i];
    velniza=prodaje.velniza;
    try {
        for(int i=0; i<velniza; i++) {
            poknaprodaju[i]=new Prodaja (*prodaje.poknaprodaju[i]);
        }
    } catch(...) {
        Oslobodimem();
        throw;
    }
    return *this;
}
Prodaje &Prodaje::operator =(Prodaje &&prodaje)
{
    if(velniza!=prodaje.velniza) {
        throw std::range_error("Dostignut maksimalni broj prodaja");
    }
    if(&prodaje!=this) return *this;

    poknaprodaju=prodaje.poknaprodaju;
    velniza=prodaje.velniza;
    prodaje.poknaprodaju=nullptr;
    return *this;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan)
{
    if(velniza==dimenzija) {
        throw std::range_error("Dostignut maksimalni broj prodaja");
    }
    try {
        poknaprodaju[velniza++]=new Prodaja({ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan});
    } catch(...) {
        velniza--;
        Oslobodimem();
        throw;
    }
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,
                                 int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
                                 const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
                                 int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
    if(velniza==dimenzija) {
        throw std::range_error("Dostignut maksimalni broj prodaja");
    }
    try {
        poknaprodaju[velniza++]=new Prodaja({ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata});
    } catch(...) {
        velniza--;
        Oslobodimem();
        throw;
    }
}
void Prodaje::RegistrirajProdaju(Prodaja *prodaja)
{
    if(velniza==dimenzija) {
        throw std::range_error("Dostignut maksimalni broj prodaja");
    }
    poknaprodaju[velniza++]=prodaja;
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const
{
    Datum pom=datum;
    int ima=std::count_if(poknaprodaju,poknaprodaju+velniza,[pom](Prodaja *prod) {
        if(prod->DajDatumProdaje().DajDan()==pom.DajDan() && prod->DajDatumProdaje().DajMjesec()==pom.DajMjesec() && prod->DajDatumProdaje().DajDan()==pom.DajDan()) return true;

        return false;
    });
    return ima;
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const
{

    int ima=std::count_if(poknaprodaju,poknaprodaju+velniza,[ime_agenta](Prodaja *prod) {
        if(ime_agenta==prod->DajImeAgenta()) return true;

        return false;
    });
    return ima;
}
Prodaja Prodaje::DajNajranijuProdaju() const
{
    if(DajBrojProdaja()==0) {
        throw std::domain_error("Nema registriranih prodaja");
    }
    Prodaja min=**(std::min_element(poknaprodaju,poknaprodaju+velniza,[](Prodaja *prodaja1,Prodaja *prodaja2) {
        if(prodaja1->DajDatumProdaje().DajGodinu()<prodaja2->DajDatumProdaje().DajGodinu()) {
            return true;
        }

        if(prodaja1->DajDatumProdaje().DajGodinu()==prodaja2->DajDatumProdaje().DajGodinu() && prodaja1->DajDatumProdaje().DajMjesec()<prodaja2->DajDatumProdaje().DajMjesec()) {
            return true;
        }
        if(prodaja1->DajDatumProdaje().DajGodinu()==prodaja2->DajDatumProdaje().DajGodinu() && prodaja1->DajDatumProdaje().DajMjesec()==prodaja2->DajDatumProdaje().DajMjesec() && prodaja1->DajDatumProdaje().DajDan()<prodaja2->DajDatumProdaje().DajDan()) {
            return true;
        }
        return false;
    }));

    return min;
}
Prodaja &Prodaje::DajNajranijuProdaju()
{
    if(DajBrojProdaja()==0) {
        throw std::domain_error("Nema registriranih prodaja");
    }
    auto min=(std::min_element(poknaprodaju,poknaprodaju+velniza,[](Prodaja *prodaja1,Prodaja *prodaja2) {
        if(prodaja1->DajDatumProdaje().DajGodinu()<prodaja2->DajDatumProdaje().DajGodinu()) {
            return true;
        }
        if(prodaja1->DajDatumProdaje().DajGodinu()==prodaja2->DajDatumProdaje().DajGodinu() && prodaja1->DajDatumProdaje().DajMjesec()<prodaja2->DajDatumProdaje().DajMjesec()) {
            return true;
        }
        if(prodaja1->DajDatumProdaje().DajGodinu()==prodaja2->DajDatumProdaje().DajGodinu() && prodaja1->DajDatumProdaje().DajMjesec()==prodaja2->DajDatumProdaje().DajMjesec() && prodaja1->DajDatumProdaje().DajDan()<prodaja2->DajDatumProdaje().DajDan()) {
            return true;
        }
        return false;
    }));
    auto p=poknaprodaju;
    while(p!=(p+velniza)) {
        if(p==min) {
            poknaprodaju=p;
            break;
        }
        p++;
    }
    return **p;
}
Prodaja Prodaje::DajNajskupljuProdaju() const
{
    if(DajBrojProdaja()==0) {
        throw std::domain_error("Nema registriranih prodaja");
    }
    Prodaja max=**(std::max_element(poknaprodaju,poknaprodaju+velniza,[](Prodaja *prodaja1,Prodaja *prodaja2) {
        if(prodaja1->DajCijenuStana()>prodaja2->DajCijenuStana())
            return true;
        return false;
    }));
    return max;
}
Prodaja &Prodaje::DajNajskupljuProdaju()
{
    if(DajBrojProdaja()==0) {
        throw std::domain_error("Nema registriranih prodaja");
    }
    auto max=(std::max_element(poknaprodaju,poknaprodaju+velniza,[](Prodaja *prodaja1,Prodaja *prodaja2) {
        if(prodaja1->DajCijenuStana()>prodaja2->DajCijenuStana())
            return true;
        return false;
    }));
    auto p=poknaprodaju;
    while(p!=(p+velniza)) {
        if(p==max) {
            poknaprodaju=p;
            break;
        }
        p++;
    }
    return **p;
}
void Prodaje::IsprazniKolekciju()
{
    for(int i=0; i<velniza; i++) {
        delete poknaprodaju[i];
        poknaprodaju[i]=nullptr;
    }
    delete [] poknaprodaju ;
    poknaprodaju=nullptr;
    velniza=0;
}
void Prodaje::ObrisiNajranijuProdaju()
{
    Prodaja max=DajNajranijuProdaju();
    for(int i=0; i<velniza; i++) {
        if(&max==poknaprodaju[i]) {
            delete poknaprodaju[i];
            poknaprodaju[i]=nullptr;
        }
    }
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta)
{

    for(int i=0; i<velniza; i++) {
        if(ime_agenta==poknaprodaju[i]->DajImeAgenta()) {
            delete poknaprodaju[i];
            poknaprodaju[i]=nullptr;
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
{
    for(int i=0; i<velniza; i++) {
        if(datum.DajDan()==poknaprodaju[i]->DajDatumProdaje().DajDan() && datum.DajMjesec()==poknaprodaju[i]->DajDatumProdaje().DajMjesec() && datum.DajGodinu()==poknaprodaju[i]->DajDatumProdaje().DajGodinu()) {
            delete poknaprodaju[i];
            poknaprodaju[i]=nullptr;
        }
    }
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const
{
    Prodaja **pom=nullptr;
    pom=new Prodaja*[velniza];
    int j=0;
    for(int i=0; i<velniza; i++) {
        if(datum.DajDan()==poknaprodaju[i]->DajDatumProdaje().DajDan() && datum.DajMjesec()==poknaprodaju[i]->DajDatumProdaje().DajMjesec() && datum.DajGodinu()==poknaprodaju[i]->DajDatumProdaje().DajGodinu()) {
            pom[j]=new Prodaja(*poknaprodaju[i]);
            j++;
        }
    }
    std::sort(pom,pom+j,[](Prodaja *p1,Prodaja *p2) {
        if(p1->DajImeKupca()<p2->DajImeKupca()) return true;
        return false;
    });
    for(int i=0; i<j; i++) {
        pom[i]->Ispisi();
        std::cout<<std::endl;
    }
}
void Prodaje::IspisiSveProdaje() const
{
    std::sort(poknaprodaju,poknaprodaju+velniza,[](Prodaja *prodaja1,Prodaja *prodaja2) {
        if(prodaja1->DajDatumProdaje().DajGodinu()<prodaja2->DajDatumProdaje().DajGodinu()) {
            return true;
        }
        if(prodaja1->DajDatumProdaje().DajGodinu()==prodaja2->DajDatumProdaje().DajGodinu() && prodaja1->DajDatumProdaje().DajMjesec()<prodaja2->DajDatumProdaje().DajMjesec()) {
            return true;
        }
        if(prodaja1->DajDatumProdaje().DajGodinu()==prodaja2->DajDatumProdaje().DajGodinu() && prodaja1->DajDatumProdaje().DajMjesec()==prodaja2->DajDatumProdaje().DajMjesec() && prodaja1->DajDatumProdaje().DajDan()<prodaja2->DajDatumProdaje().DajDan()) {
            return true;
        }
        return false;
    });
    for(int i=0; i<velniza; i++) {
        poknaprodaju[i]->Ispisi();
        std::cout<<std::endl;
    }
}
int main ()
{
    std::vector<Stan> stanovi;
    std::vector<Kupac> kupci;
    std::vector<Prodaja> prodaja ;
    std::vector<Prodaje> prodaje;
    std::cout << "Dobrodosli!" << std::endl<<std::endl<<std::endl;
    for(;;) {
        std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - kraj"<<std::endl<<" 1 - uredjivanje stanova"<<std::endl<<" 2 - uredjivanje kupaca"<<std::endl<<" 3 - uredjivanje prodaja"<<std::endl;
        int x;
        std::cin>>x;
        if(x==0) {
            std::cout<< std::endl<<std::endl<<"Dovidjenja!";
            break;
        }
        if(x==1) {

            for(;;) {
g7:
                std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - dodavanje stana"<<std::endl<<" 2 - uredjivanje stanova"<<std::endl<<" 3 - ispis svih stanova"<<std::endl<<" 4 - kraj" <<std::endl;
                int x1;
                std::cin>>x1;
                if(x1==0) {
                    break;
                }
                if(x1==4) {
                    std::cout<< std::endl<<std::endl<<"Dovidjenja!";
                    return 0;
                }
                if(x1==1) {
g1:
                    std::cin.ignore(10000000,'\n');
                    std::cout<<"Unesite adresu: ";
                    std::string adresa;
                    std::getline(std::cin,adresa);
                    std::cout<<"Unesite sprat: ";
                    int sprat;
                    std::cin>>sprat;
                    std::cout<<"Unesite broj soba: ";
                    int brsoba;
                    std::cin>>brsoba;
                    std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                    try {
                        int namjesten;
                        std::cin>>namjesten;
                        std::cout<<"Unesite kvadraturu: ";
                        double kvadratura;
                        std::cin>>kvadratura;
                        if( namjesten!=1 && namjesten!=0) {
                            throw std::domain_error("Neispravan unos podataka");
                        }
                        Stan pom(adresa,sprat,brsoba,namjesten,kvadratura);
                        stanovi.push_back(pom);
                        std::cout<<"Stan je uspjesno dodan!"<<std::endl<<std::endl;
                    } catch(std::domain_error x) {
                        std::cout<<"Izuzetak: "<<x.what()<<". Molimo unesite opet."<<std::endl;
                        goto g1;
                    }
                }
                if(x1==2) {
                    std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                    for(int i=0; i<stanovi.size(); i++) {
                        std::cout<<" "<<i+1<<" - ";
                        stanovi[i].Ispisi();
                        std::cout<<std::endl;
                    }
                    std::cout<<std::endl;
                    int x11;
                    std::cin>>x11;
                    Stan preuredujese=stanovi[x11-1];
                    std::cout<<"Odaberite polje koje zelite urediti:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - adresa"<<std::endl<<" 2 - sprat"<<std::endl<<" 3 - broj soba"<<std::endl<<" 4 - da li je stan namjesten"<<std::endl<<" 5 - kvadratura"<<std::endl<<" 6 - sve"<<std::endl;
                    int x12;
                    std::cin>>x12;
                    if(x12==0) {
                        goto g7;
                    }
                    if(x12==1) {
                        std::cin.ignore(10000,'\n');
g4:
                        std::cout<<"Unesite adresu: ";
                        std::string adresa1;
                        std::getline(std::cin,adresa1);
                        try {
                            preuredujese.Postavi(adresa1,preuredujese.DajSprat(),preuredujese.DajBrojSoba(),preuredujese.DajNamjesten(),preuredujese.DajKvadraturu());
                            stanovi[x11-1]=preuredujese;
                            std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                        } catch(std::domain_error x) {
                            std::cout<<"Izuzetak: "<<x.what()<<". Molimo unesite opet."<<std::endl;
                            goto g4;
                        }
                    }
                    if(x12==2) {

g8:
                        std::cout<<"Unesite sprat: ";
                        int sprat1;
                        std::cin>>sprat1;
                        try {
                            preuredujese.Postavi(preuredujese.DajAdresu(),sprat1,preuredujese.DajBrojSoba(),preuredujese.DajNamjesten(),preuredujese.DajKvadraturu());
                            stanovi[x11-1]=preuredujese;
                            std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                        } catch(std::domain_error x) {
                            std::cout<<"Izuzetak: "<<x.what()<<". Molimo unesite opet."<<std::endl;
                            goto g8;
                        }
                    }
                    if(x12==3) {

g5:
                        std::cout<<"Unesite broj soba: ";
                        int brsoba1;
                        std::cin>>brsoba1;
                        try {
                            preuredujese.Postavi(preuredujese.DajAdresu(),preuredujese.DajSprat(),brsoba1,preuredujese.DajNamjesten(),preuredujese.DajKvadraturu());
                            stanovi[x11-1]=preuredujese;
                            std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                        } catch(std::domain_error x) {
                            std::cout<<"Izuzetak: "<<x.what()<<". Molimo unesite opet."<<std::endl;
                            goto g5;
                        }
                    }
                    if(x12==4) {

g6:
                        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                        try {
                            int namjesten1;
                            std::cin>>namjesten1;
                            if( namjesten1!=1 && namjesten1!=0) {
                                throw std::domain_error("Neispravan unos podataka");
                            }

                            preuredujese.Postavi(preuredujese.DajAdresu(),preuredujese.DajSprat(),preuredujese.DajBrojSoba(),namjesten1,preuredujese.DajKvadraturu());
                            stanovi[x11-1]=preuredujese;
                            std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                        } catch(std::domain_error x) {
                            std::cout<<"Izuzetak: "<<x.what()<<". Molimo unesite opet."<<std::endl;
                            goto g6;
                        }
                    }
                    if(x12==5) {

g2:
                        std::cout<<"Unesite kvadraturu: ";
                        double kvadr;
                        std::cin>>kvadr;
                        try {
                            preuredujese.Postavi(preuredujese.DajAdresu(),preuredujese.DajSprat(),preuredujese.DajBrojSoba(),preuredujese.DajNamjesten(),kvadr);
                            stanovi[x11-1]=preuredujese;
                            std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                        } catch(std::domain_error x) {
                            std::cout<<"Izuzetak: "<<x.what()<<". Molimo unesite opet."<<std::endl;
                            goto g2;
                        }
                    }
                    if(x12==6) {

                        std::cin.ignore(10000,'\n');
g3:
                        std::cout<<"Unesite adresu: ";
                        std::string adresa1;
                        std::getline(std::cin,adresa1);
                        std::cout<<"Unesite sprat: ";
                        int sprat1;
                        std::cin>>sprat1;
                        std::cout<<"Unesite broj soba: ";
                        int brsoba1;
                        std::cin>>brsoba1;
                        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                        try {
                            int namjesten1;
                            std::cin>>namjesten1;
                            std::cout<<"Unesite kvadraturu: ";
                            double kvadratura1;
                            std::cin>>kvadratura1;
                            if( namjesten1!=1 && namjesten1!=0) {
                                throw std::domain_error("Neispravan unos podataka");
                            }
                            Stan pom(adresa1,sprat1,brsoba1,namjesten1,kvadratura1);
                            stanovi[x11-1]=pom;
                            std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl;
                        } catch(std::domain_error x) {
                            std::cout<<"Izuzetak: "<<x.what()<<". Molimo unesite opet."<<std::endl;
                            goto g3;
                        }
                    }

                }
                if(x1==3) {
                    for(int i=0; i<stanovi.size(); i++) {
                        std::cout<<i+1<<". ";
                        stanovi[i].Ispisi();
                        std::cout<<std::endl;
                    }
                    std::cout<<std::endl;
                }
            }

        }
        if(x==2) {
            for(;;) {
                std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - dodavanje kupca"<<std::endl<<" 2 - uredjivanje kupaca"<<std::endl<<" 3 - ispis svih kupaca"<<std::endl<<" 4 - kraj"<<std::endl;
                int x2;
                std::cin>>x2;
                if(x2==0) {
                    break;
                }
                if(x2==1) {
                    std::cin.ignore(10000,'\n');
g10:
                    std::cout<<"Unesite ime i prezime kupca: ";
                    std::string imeiprezime;
                    std::getline(std::cin,imeiprezime);
                    std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                    //std::cin.ignore(10000,'\n');
                    std::string datum;
                    std::getline(std::cin,datum);
                    int dan=0,mjesec=0,godina=0;
                    for(int i=0; i<datum.size(); i++) {
                        int poc;
                        if(i==0) {
                            poc=i;
                            while(datum[i]!='/')i++;
                            for(int j=poc; j<i; j++) {
                                dan=dan*10+(datum[j]-'0');
                            }
                        }
                        if(datum[i]=='/') {
                            i++;
                            poc=i;
                            while(datum[i]!='/')i++;
                            for(int j=poc; j<i; j++) {
                                mjesec=mjesec*10+(datum[j]-'0');
                            }
                            i++;
                            poc=i;
                            while(i!=datum.size())i++;
                            for(int j=poc; j<i; j++) {
                                godina=godina*10+(datum[j]-'0');
                            }
                            i--;
                        }

                    }
                    try {
                        Kupac pom(imeiprezime, {dan,mjesec,godina});
                        kupci.push_back(pom);
                        std::cout<<"Kupac je uspjesno dodan!"<<std::endl<<std::endl;
                    } catch(std::domain_error x) {
                        std::cout<<"Izuzetak: "<<x.what()<<". Molimo unesite opet."<<std::endl;
                        goto g10;
                    }
                }
                if(x2==2) {
                    std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<std::endl;
                    for(int i=0; i<kupci.size(); i++) {
                        std::cout<<" "<<i+1<<" - ";
                        kupci[i].Ispisi();
                        std::cout<<std::endl;
                    }
                    int x21;
                    std::cin>>x21;
                    Kupac mjenjamo=kupci[x21-1];
                    std::cin.ignore(10000,'\n');
g11:
                    std::cout<<"Unesite ime i prezime kupca: ";
                    std::string imeiprezime1;
                    std::getline(std::cin,imeiprezime1);
                    std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                    int dan1=0,mjesec1=0,godina1=0;
                    //std::cin.ignore(10000,'\n');
                    std::string datum1;
                    std::getline(std::cin,datum1);
                    for(int i=0; i<datum1.size(); i++) {
                        int poc;
                        if(i==0) {
                            poc=i;
                            while(datum1[i]!='/')i++;
                            for(int j=poc; j<i; j++) {
                                dan1=dan1*10+(datum1[j]-'0');
                            }
                        }
                        if(datum1[i]=='/') {
                            i++;
                            poc=i;
                            while(datum1[i]!='/')i++;
                            for(int j=poc; j<i; j++) {
                                mjesec1=mjesec1*10+(datum1[j]-'0');
                            }
                            i++;
                            poc=i;
                            while(i!=datum1.size())i++;
                            for(int j=poc; j<i; j++) {
                                godina1=godina1*10+(datum1[j]-'0');
                            }
                            i--;
                        }
                        //  std::cout<<dan1<<"    "<<mjesec1<<"    "<<godina1<<std::endl;
                    }
                    try {
                        Kupac pom(imeiprezime1, {dan1,mjesec1,godina1});
                        kupci[x21-1]=pom;
                        std::cout<<"Kupac je uspjesno izmijenjen!"<<std::endl;
                    } catch(std::domain_error x) {
                        std::cout<<"Izuzetak: "<<x.what()<<". Molimo unesite opet."<<std::endl;
                        goto g11;
                    }
                }
                if(x2==3) {
                    for(int i=0; i<kupci.size(); i++) {
                        kupci[i].Ispisi();
                        std::cout<<std::endl;
                    }
                    std::cout<<std::endl;
                }
                if(x2==4) {
                    std::cout<< std::endl<<std::endl<<"Dovidjenja!";
                    return 0;
                }
            }
        }//kraj x==2
        if(x==3) {
            for(;;) {
g31:
                std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - dodavanje prodaje"<<std::endl<<" 2 - uredjivanje prodaje"<<std::endl<<" 3 - ispis prodaja"<<std::endl<<" 4 - brisanje prodaja"<<std::endl<<" 5 - kraj"<<std::endl;
                int x3;
                std::cin>>x3;
                if(x3==0) {
                    break;
                }
                if(x3==5) {
                    std::cout<< std::endl<<std::endl<<"Dovidjenja!";
                    return 0;
                }
                if(x3==1) {
g32:
                    std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - dodavanje potpuno nove prodaje"<<std::endl<<" 2 - dodavanje nove prodaje na osnovu arhive"<<std::endl<<" 3 - kraj"<<std::endl;
                    int x31;
                    std::cin>>x31;
                    if(x31==0) {
                        goto g31;
                    }
                    if(x31==3) {
                        std::cout<< std::endl<<std::endl<<"Dovidjenja!";
                        return 0;
                    }
                    if(x31==1) {
g30:
                        std::cout<<"Unesite ime i prezime agenta prodaje: ";
                        std::string agent;
                        std::cin.ignore(10000,'\n');
                        std::getline(std::cin,agent);
                        std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                        std::string datum;
                        // std::cin.ignore(10000,'\n');
                        std::getline(std::cin,datum);
                        int dan=0,mjesec=0,godina=0;
                        for(int i=0; i<datum.size(); i++) {
                            int poc;
                            if(i==0) {
                                poc=i;
                                while(datum[i]!='/')i++;
                                for(int j=poc; j<i; j++) {
                                    dan=dan*10+(datum[j]-'0');
                                }
                            }
                            if(datum[i]=='/') {
                                i++;
                                poc=i;
                                while(datum[i]!='/')i++;
                                for(int j=poc; j<i; j++) {
                                    mjesec=mjesec*10+(datum[j]-'0');
                                }
                                i++;
                                poc=i;
                                while(i!=datum.size())i++;
                                for(int j=poc; j<i; j++) {
                                    godina=godina*10+(datum[j]-'0');
                                }
                                i--;
                            }
                        }//for
                        std::cout<<"Unesite cijenu stana: ";
                        double cijena;
                        std::cin>>cijena;
                        std::cin.ignore(10000,'\n');
                        std::cout<<"Unesite ime kupca: ";
                        std::string imeiprezime1;
                        std::getline(std::cin,imeiprezime1);
                        std::cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
                        int dan1=0,mjesec1=0,godina1=0;
                        //std::cin.ignore(10000,'\n');
                        std::string datum1;
                        std::getline(std::cin,datum1);
                        for(int i=0; i<datum1.size(); i++) {
                            int poc;
                            if(i==0) {
                                poc=i;
                                while(datum1[i]!='/')i++;
                                for(int j=poc; j<i; j++) {
                                    dan1=dan1*10+(datum1[j]-'0');
                                }
                            }
                            if(datum1[i]=='/') {
                                i++;
                                poc=i;
                                while(datum1[i]!='/')i++;
                                for(int j=poc; j<i; j++) {
                                    mjesec1=mjesec1*10+(datum1[j]-'0');
                                }
                                i++;
                                poc=i;
                                while(i!=datum1.size())i++;
                                for(int j=poc; j<i; j++) {
                                    godina1=godina1*10+(datum1[j]-'0');
                                }
                                i--;
                            }
                        }
                        std::cout<<"Unesite adresu: ";
                        std::string adresa1;
                        std::getline(std::cin,adresa1);
                        std::cout<<"Unesite sprat: ";
                        int sprat1;
                        std::cin>>sprat1;
                        std::cout<<"Unesite broj soba: ";
                        int brsoba1;
                        std::cin>>brsoba1;
                        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                        int namjesten1;
                        std::cin>>namjesten1;
                        std::cout<<"Unesite kvadraturu: ";
                        double kvadratura1;
                        std::cin>>kvadratura1;
                        try {
                            if( namjesten1!=1 && namjesten1!=0) {
                                throw std::domain_error("Neispravan unos podataka");
                            }
                            Prodaja pom(agent,cijena,dan,mjesec,godina,imeiprezime1, {dan1,mjesec1,godina1},adresa1,sprat1,brsoba1,namjesten1,kvadratura1);
                            prodaja.push_back(pom);
                            std::cout<<"Prodaja uspjesno dodana!"<<std::endl;
                            goto g32;
                        } catch(std::domain_error x) {
                            std::cout<<"Izuzetak: "<<x.what()<<". Molimo unesite opet."<<std::endl;
                            goto g30;
                        }
                    }//NORMALNO DODAVANJE
                    if(x31==2) {
g33:
                        std::cout<<"Unesite ime i prezime agenta prodaje: ";
                        std::string agent;
                        std::cin.ignore(10000,'\n');
                        std::getline(std::cin,agent);
                        std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                        std::string datum;
                        // std::cin.ignore(10000,'\n');
                        std::getline(std::cin,datum);
                        int dan=0,mjesec=0,godina=0;
                        for(int i=0; i<datum.size(); i++) {
                            int poc;
                            if(i==0) {
                                poc=i;
                                while(datum[i]!='/')i++;
                                for(int j=poc; j<i; j++) {
                                    dan=dan*10+(datum[j]-'0');
                                }
                            }
                            if(datum[i]=='/') {
                                i++;
                                poc=i;
                                while(datum[i]!='/')i++;
                                for(int j=poc; j<i; j++) {
                                    mjesec=mjesec*10+(datum[j]-'0');
                                }
                                i++;
                                poc=i;
                                while(i!=datum.size())i++;
                                for(int j=poc; j<i; j++) {
                                    godina=godina*10+(datum[j]-'0');
                                }
                                i--;
                            }
                        }//for
                        std::cout<<"Unesite cijenu stana: ";
                        double cijena;
                        std::cin>>cijena;
                        std::cout<<"Odaberite kupca. Dostupni kupci su:";
                        for(int i=0; i<kupci.size(); i++) {
                            std::cout<<" 1 - ";
                            kupci[i].Ispisi();
                            std::cout<<std::endl;
                        }
                        int kojikupac;
                        std::cin>>kojikupac;
                        std::cout<<"Odaberite stan. Dostupni stanovi su:";
                        for(int i=0; i<stanovi.size(); i++) {
                            std::cout<<" 1 - ";
                            stanovi[i].Ispisi();
                            std::cout<<std::endl;
                        }
                        int kojistan;
                        std::cin>>kojistan;
                        try {
                            Prodaja pom(agent,cijena, {dan,mjesec,godina},kupci[kojikupac-1],stanovi[kojistan-1]);
                            prodaja.push_back(pom);
                            
                            std::cout<<"Prodaja uspjesno dodana!"<<std::endl;
                        } catch(std::domain_error x) {
                            std::cout<<"Izuzetak: "<<x.what()<<". Molimo unesite opet."<<std::endl;
                            goto g33;
                        }
                    }//iz arhive
                }//DODAVANJE
                if(x3==2){
                    for(int i=0;i<prodaja.size();i++){
                       // prodaje[i].RegistrirajProdaju(prodaja[i]);
                    }
                    std::cout << "Odaberite prodaju koju želite urediti. Dostupne prodaje su:" << std::endl;
                    for(int i=0;i<prodaje.size();i++){
                        std::cout << i+1<<"." << std::endl;
                        prodaje[i].IspisiSveProdaje();
                        std::cout<<std::endl;
                    }
                    int mjenjamoprodaju;
                    std::cin>>mjenjamoprodaju;
                    std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - izmjena agenta"<<std::endl<<" 2 - izmjena datuma prodaje"<<std::endl<<" 3 - izmjena kupca"<<std::endl<<" 4 - izmjena stana"<<std::endl<<" 5 - izmjena cijene stana"<<std::endl;
                    int opcija;
                    std::cin>>opcija;
                    if(opcija==1){
                        std::cout<<"Unesite ime i prezime agenta prodaje: ";
                        std::string agent2;
                        std::cin.ignore(10000,'\n');
                        std::getline(std::cin,agent2);
                       // Prodaja pom(agent2,prodaje[mjenjamoprodaju-1].DajCijenuStana(),prodaje[mjenjamoprodaju-1].DajDatumProdaje(),{prodaje[mjenjamoprodaju-1].DajImeKupca(),prodaje[mjenjamoprodaju-1].DajDatumRodjenja()},{prodaje[mjenjamoprodaju-1].DajAdresu(),prodaje[mjenjamoprodaju-1].DajSprat(),prodaje[mjenjamoprodaju-1].DajBrojSoba(),prodaje[mjenjamoprodaju-1].DajNamjesten(),prodaje[mjenjamoprodaju-1].DajKvadraturu()});
                    }
                }
                if(x3==4) {
                    std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - brisanje najranije prodaje"<<std::endl<<" 2 - brisanje prodaja agenta"<<std::endl<<" 3 - brisanje prodaja po datumu"<<std::endl<<" 4 - brisanje svih prodaja"<<std::endl;
                    int x31;
                    std::cin>>x31;
                    if(x31==0) {
                        break;
                    }
                }

            }
        }
    }
    return 0;
}