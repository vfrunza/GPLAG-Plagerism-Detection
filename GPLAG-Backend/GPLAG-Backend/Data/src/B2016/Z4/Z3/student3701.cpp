/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <string>
#include <algorithm>
                                                                    //KLASA DATUM
class Datum {
    int m,d,g;
    public:
        Datum(int dan, int mjesec, int godina);
        void Postavi(int dan, int mjesec, int godina);
        int DajDan() const;
        int DajMjesec() const;
        int DajGodinu() const;
        void Ispisi() const;
};

bool Ispravan_datum (int dan, int mjesec, int godina) {
    int broj_dana[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (godina%4==0 && godina%100!=0 && godina%400==0) broj_dana[1]++;
    if (godina<1 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1]) return false;
    return true;
}
    
Datum::Datum (int dan, int mjesec, int godina) {
    if (!Ispravan_datum(dan,mjesec,godina)) throw std::domain_error ("Neispravan datum");
    Datum::d=dan; Datum::m=mjesec; Datum::g=godina;
}

void Datum::Postavi (int dan, int mjesec, int godina) {
    if (!Ispravan_datum(dan,mjesec,godina)) throw std::domain_error ("Neispravan datum");
    Datum::d=dan; Datum::m=mjesec; Datum::g=godina;
}

int Datum::DajDan() const{
    return Datum::d;
}

int Datum::DajMjesec() const{
    return Datum::m;
}

int Datum::DajGodinu() const{
    return Datum::g;
}

void Datum::Ispisi() const{
    std::cout<<DajDan()<<"/"<<DajMjesec()<<"/"<<DajGodinu();
}
                                                                //KLASA KUPAC 
class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    public:
        Kupac(const std::string & ime_i_prezime, const Datum & datum_rodjenja);
        void Postavi(const std::string & ime_i_prezime, const Datum & datum_rodjenja);
        std::string DajImePrezime() const;
        Datum DajDatumRodjenja() const;
        void Ispisi() const;
};

bool Ispravno_ime(std::string ime) {
    for(int i=0; i<ime.size(); i++)
        if(ime[i]!=' ' && ime[i]!='-' && ime[i]!='"' && !(ime[i]>='0' && ime[i]<='9') && !(ime[i]>='A' && ime[i]<='Z') && !(ime[i]>='a' && ime[i]<='z')) return false;
    return true;
}

Kupac::Kupac (const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datum_rodjenja(datum_rodjenja) {
    if (!Ispravno_ime(ime_i_prezime)) throw std::domain_error ("Neispravno ime i prezime");
    Kupac::ime_i_prezime=ime_i_prezime;
    Kupac::datum_rodjenja=datum_rodjenja;
}

void Kupac::Postavi (const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    if (!Ispravno_ime(ime_i_prezime)) throw std::domain_error ("Neispravno ime i prezime");
    Kupac::ime_i_prezime=ime_i_prezime;
    Kupac::datum_rodjenja=datum_rodjenja;
}

std::string Kupac::DajImePrezime() const {
    return Kupac::ime_i_prezime;
}

Datum Kupac::DajDatumRodjenja() const {
    return Kupac::datum_rodjenja;
}

void Kupac::Ispisi() const {
    std::cout<<Kupac::DajImePrezime()<<"(";
    datum_rodjenja.Ispisi();
    std::cout<<")";
}
                                                        // KLASA STAN
class Stan {
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
    public:
        Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
        void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
        std::string DajAdresu() const;
        int DajSprat() const;
        int DajBrojSoba() const;
        bool DajNamjesten() const;
        double DajKvadraturu() const;
        void Ispisi() const;
};

Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if (sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    Stan::adresa=adresa;
    Stan::sprat=sprat;
    Stan::broj_soba=broj_soba;
    Stan::namjesten=namjesten;
    Stan::kvadratura=kvadratura;
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if (sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    Stan::adresa=adresa;
    Stan::sprat=sprat;
    Stan::broj_soba=broj_soba;
    Stan::namjesten=namjesten;
    Stan::kvadratura=kvadratura;
}

std::string Stan::DajAdresu() const {
    return Stan::adresa;
}

int Stan::DajSprat() const {
    return Stan::sprat;
}

int Stan::DajBrojSoba() const {
    return Stan::broj_soba;
}

bool Stan::DajNamjesten() const {
    return Stan::namjesten;
}

double Stan::DajKvadraturu() const {
    return Stan::kvadratura;
}

void Stan::Ispisi() const {
    int br_s=DajBrojSoba();
    std::string s="soba",n="je";
    if ((br_s%10==2 || br_s%10==3 || br_s%10==4) && br_s%100!=12 && br_s%100!=13 && br_s%100!=14) s="sobe";
    if (!DajNamjesten()) n="nije"; 
    std::cout<<"Stan se nalazi na adresi "<<Stan::DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" "<<s<<".\nKvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan "<<n<<" namjesten.";
}

class Prodaja {
    std::string ime_agenta;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac);
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje(const double &nova_cijena);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const;
    std::string DajImeKupca() const;
    Datum DajDatumProdaje() const;
    double DajCijenuStana() const;
    friend bool ProdajPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan): datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {
    Prodaja::ime_agenta=ime_agenta_prodaje;
    Prodaja::cijena_stana=cijena_stana;
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca), kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) {
    Prodaja::ime_agenta=ime_agenta_prodaje;
    Prodaja::cijena_stana=cijena_stana;
}

void Prodaja::PromijeniKupca(const Kupac &novi_kupac) {
    Prodaja::kupac_stana.Postavi(novi_kupac.DajImePrezime(), novi_kupac.DajDatumRodjenja());
}

void Prodaja::PromijeniStan(const Stan &novi_stan) {
    Prodaja::kupljeni_stan.Postavi(novi_stan.DajAdresu(),novi_stan.DajSprat(),novi_stan.DajBrojSoba(),novi_stan.DajNamjesten(),novi_stan.DajKvadraturu());
}

void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum) {
    Prodaja::datum_prodaje.Postavi(novi_datum.DajDan(),novi_datum.DajMjesec(),novi_datum.DajGodinu());
}

void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena) {
    Prodaja::cijena_stana=nova_cijena;
}

void Prodaja::PomjeriDanUnaprijed() {
    Prodaja::datum_prodaje.Postavi(datum_prodaje.DajDan()+1, datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu());
}

void Prodaja::PomjeriDanUnazad() {
    Prodaja::datum_prodaje.Postavi(datum_prodaje.DajDan()-1,datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu());
}

std::string Prodaja::DajImeAgenta() const {
    return Prodaja::ime_agenta;
}

std::string Prodaja::DajImeKupca() const {
    return Prodaja::kupac_stana.DajImePrezime();
}

Datum Prodaja::DajDatumProdaje() const {
    return Prodaja::datum_prodaje;
}

double Prodaja::DajCijenuStana() const {
    return Prodaja::cijena_stana;
}

long long int Pretvori_u_dane (const Datum d) {
    return d.DajDan()+d.DajMjesec()*30+d.DajGodinu()*365;
}

bool ProdajPrije(const Prodaja &p1, const Prodaja &p2) {
    if (Pretvori_u_dane(p1.DajDatumProdaje())<Pretvori_u_dane(p2.DajDatumProdaje())) return true;
    return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    if (p1.DajCijenuStana()>p2.DajCijenuStana()) return true;
    return false;
}
void Prodaja::Ispisi() const {
    std::cout<<"Ime agenta: "<<DajImeAgenta()<<std::endl;
    std::cout<<"Ime kupca: "; kupac_stana.Ispisi(); std::cout<<std::endl;
    std::cout<<"Zakazani datum prodaje: "; datum_prodaje.Ispisi(); std::cout<<std::endl;
    std::cout<<"Cijena stana: "<<DajCijenuStana()<<std::endl;
    std::cout<<"Informacije o stanu: \n";
    kupljeni_stan.Ispisi();
}
class Prodaje {
    const int max_broj_prodaja;
    int broj_prodaja;
    Prodaja **pok_na_niz=nullptr;
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje & operator =(Prodaje && prodaje);
    void RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju (const std::string &ime_agenta_prodaje, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju (Prodaja *prodaja);
    int DajBrojProdaja() const;
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};

Prodaje::Prodaje (int max_broj_prodaja) : max_broj_prodaja(max_broj_prodaja) {
    broj_prodaja=0;
    pok_na_niz=new Prodaja*[max_broj_prodaja] {};
}

Prodaje::Prodaje (std::initializer_list<Prodaja> spisak_prodaja) : max_broj_prodaja(spisak_prodaja.size()),broj_prodaja(spisak_prodaja.size()), pok_na_niz(new Prodaja*[spisak_prodaja.size()]{}) {
    int brojac=0, i=0;
    try {
        for (auto it=spisak_prodaja.begin(); it!=spisak_prodaja.end(); it++,i++) {
            pok_na_niz[i]=new Prodaja (*it);
            brojac++;
        }
    }
    catch (...) {
        for (int k=0; k<brojac; k++) 
            delete[] pok_na_niz[k];
        delete[] pok_na_niz;
        throw;
    }
}

Prodaje::~Prodaje() {
    if (pok_na_niz!=nullptr) {
        for (int i=0; i<broj_prodaja; i++) 
            delete pok_na_niz [i];
        delete[] pok_na_niz;
        pok_na_niz=nullptr;
    }
}

Prodaje::Prodaje(const Prodaje &prodaje) : max_broj_prodaja(prodaje.max_broj_prodaja) {
    try {
        broj_prodaja=prodaje.broj_prodaja;
        pok_na_niz= new Prodaja* [prodaje.max_broj_prodaja]{};
        for (int i=0; i<prodaje.broj_prodaja; i++) 
            pok_na_niz[i]=new Prodaja(*prodaje.pok_na_niz[i]);
    }
    catch (...) {
        for (int i=0; i<prodaje.broj_prodaja; i++) 
            delete pok_na_niz[i];
        delete[] pok_na_niz;
        throw;
    }
}

Prodaje::Prodaje(Prodaje && prodaje) : max_broj_prodaja(prodaje.max_broj_prodaja), pok_na_niz(prodaje.pok_na_niz) {
    broj_prodaja=prodaje.broj_prodaja;
    prodaje.pok_na_niz=nullptr;
    prodaje.broj_prodaja=0;
}

Prodaje &Prodaje::operator =(const Prodaje & prodaje){
    if (prodaje.broj_prodaja!=broj_prodaja) {
        try {
            for (int i=broj_prodaja; i<prodaje.broj_prodaja; i++) 
                pok_na_niz[i]=new Prodaja(*prodaje.pok_na_niz[i]);
        }
        catch (...) {
            for (int i=broj_prodaja; i<prodaje.broj_prodaja; i++) {
                delete pok_na_niz[i];
                pok_na_niz[i]=nullptr;
            }
            throw;
        }
    }
    else {
        for (int i=prodaje.broj_prodaja; i<broj_prodaja; i++) {
            delete pok_na_niz[i];
            pok_na_niz[i]=nullptr;
        }
    } 
    broj_prodaja=prodaje.broj_prodaja;
    for (int i=0; i<broj_prodaja; i++)
        *pok_na_niz[i]=*prodaje.pok_na_niz[i];
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje && prodaje) {
    if (prodaje.broj_prodaja!=broj_prodaja) throw ("502");
    std::swap (broj_prodaja, prodaje.broj_prodaja);
    std::swap (pok_na_niz, prodaje.pok_na_niz);
    return *this;
}

void RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    
}
int main ()
{
	return 0;
}