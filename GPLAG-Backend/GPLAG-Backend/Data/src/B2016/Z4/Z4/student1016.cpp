/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include <iomanip>
#include <algorithm>
#include <vector>

class Datum
{
    int dan, mjesec, godina;
public:
    Datum(int d, int m, int g);
    Datum (const Datum& dat);
    Datum operator =(const Datum& dat) {
        this->Postavi(dat.dan, dat.mjesec, dat.godina);
        return *this;
    }
    void Postavi(int d, int m, int g);
    int DajDan() const {
        return dan;
    };
    int& DajDan() {
        return dan;
    }
    int DajMjesec() const {
        return mjesec;
    };
    int& DajMjesec() {
        return mjesec;
    };
    int DajGodinu() const {
        return godina;
    };
    int& DajGodinu() {
        return godina;
    };
    void Ispisi() const {
        std::cout << dan << "/" << mjesec<< "/"<< godina;
    };
};

Datum::Datum (const Datum& dat)
{
    Postavi(dat.dan, dat.mjesec, dat.godina);
}
Datum::Datum(int d, int m, int g)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++;
    int x=m-1;
    if(g < 1 || m < 1 || m > 12 || d < 1 || d > broj_dana[x]) throw std::domain_error("Neispravan datum!");
    dan=d;
    mjesec=m;
    godina=g;
}

void Datum::Postavi(int d, int m, int g)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0)
        broj_dana[1]++;
    int x=m-1;
    if(g < 1 || m < 1 || m > 12 || d < 1 || d > broj_dana[x]) throw std::domain_error("Neispravan datum!");
    dan=d;
    mjesec=m;
    godina=g;
}

class Kupac
{
    std::string ime;
    Datum datum;
    static void TestImena(std::string s) {
        for(int i=0; i<s.length(); i++) {
            if(!((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z') or (s[i]>='0' and s[i]<='9') or s[i]=='-' or s[i]==39))
                throw std::domain_error ("Neispravno ime i prezime");
        }
    };
public:
    Kupac(const std::string& ime_i_prezime, const Datum& datum_rodjenja): ime(ime_i_prezime), datum(datum_rodjenja) {};
    Kupac operator=(const Kupac&k) {
        this->Postavi(k.ime, k.datum);
        return *this;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    Kupac(const Kupac&k): datum(k.datum) {
        Postavi(k.ime, k.datum);
    }
    std::string DajImePrezime() const {
        return ime;
    };
    Datum DajDatumRodjenja() const {
        return datum;
    };
    void Ispisi() const {
        std::cout << ime << " (";
        datum.Ispisi();
        std::cout << ")\n ";
    };
};

void Kupac::Postavi(const std::string& ime_i_prezime, const Datum& datum_rodjenja)
{
    datum.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
    TestImena(ime_i_prezime);
    ime=ime_i_prezime;
}



class Stan
{
    std::string adress;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan(const std::string &adresa, int sprat1, int broj_soba1, bool namjesten1,double kvadratura1): adress(adresa), sprat(sprat1), broj_soba(broj_soba1), namjesten(namjesten1), kvadratura(kvadratura1) {
        if(sprat1<0 or broj_soba1<0 or kvadratura1<0) throw std::domain_error ("Neispravan unos podataka");
    };
    Stan(const Stan& s) {
        Postavi(s.adress, s.sprat, s.broj_soba, s.namjesten, s.kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const {
        return adress;
    };
    int DajSprat() const {
        return sprat;
    };
    int DajBrojSoba() const {
        return broj_soba;
    };
    bool DajNamjesten() const {
        return namjesten;
    };
    double DajKvadraturu() const {
        return kvadratura;
    };
    std::string& DajAdresu() {
        return adress;
    };
    int& DajSprat() {
        return sprat;
    };
    int& DajBrojSoba() {
        return broj_soba;
    };
    bool& DajNamjesten() {
        return namjesten;
    };
    double& DajKvadraturu() {
        return kvadratura;
    };
    void Ispisi() const;

};

void Stan::Postavi(const std::string &adresa, int sprat1, int broj_soba1, bool namjesten1, double kvadratura1)
{
    if(sprat1<0 or broj_soba1<0 or kvadratura1<0) throw std::domain_error ("Neispravan unos podataka");
    adress=adresa;
    sprat=sprat1;
    broj_soba=broj_soba1;
    namjesten=namjesten1;
    kvadratura=kvadratura1;
}

void Stan::Ispisi() const
{
    std::cout << "Stan se nalazi na adresi " << adress <<"  na "<<sprat<<" spratu i ima "<<broj_soba;
    if(broj_soba%10==1) std::cout << " sobu";
    else if(broj_soba%10>=2 and broj_soba%10<=4) std::cout << " sobe";
    else std::cout << " soba";
    std::cout << ". Kvadratura stana je "<<std::setprecision(2) <<kvadratura<<"(m^2) i stan ";
    if(namjesten) std::cout << "je namjesten.\n";
    else std::cout << "nije namjesten.\n";
}

class Prodaja
{
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan): ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {

    };
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
            std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba,
            bool namjesten_stan, double broj_kvadrata): ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje),
        kupac_stana(ime_kupca,datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {};
    void PromijeniKupca(const Kupac &novi_kupac) {
        kupac_stana=novi_kupac;
    };
    void PromijeniStan(const Stan &novi_stan) {
        kupljeni_stan.Postavi(novi_stan.DajAdresu(), novi_stan.DajSprat(), novi_stan.DajBrojSoba(), novi_stan.DajNamjesten(), novi_stan.DajKvadraturu());
    };
    Kupac DajKupca(){ return kupac_stana;}
    Stan DajStan(){ return kupljeni_stan;}
    void PromijeniDatumKupovine(const Datum &novi_datum) {
        
        datum_prodaje.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(), novi_datum.DajGodinu());
    };
    void PromijeniCijenuProdaje(const double &nova_cijena) {
        cijena_stana=nova_cijena;
    };
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    
    std::string DajImeAgenta() const {
        return ime_agenta_prodaje;
    };
    std::string& DajImeAgenta() {
        return ime_agenta_prodaje;
    };
    std::string DajImeKupca() const {
        return kupac_stana.DajImePrezime();
    };
    Datum DajDatumProdaje() const {
        return datum_prodaje;
    };
    Datum& DajDatumProdaje() {
        return datum_prodaje;
    };
    double DajCijenuStana() const {
        return cijena_stana;
    };
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;

};

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    return p1.DajCijenuStana()>p2.DajCijenuStana();
};

void Prodaja::PomjeriDanUnaprijed()
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int g=datum_prodaje.DajGodinu();
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++;
    int dan, mj(datum_prodaje.DajMjesec());
    if(datum_prodaje.DajDan()+1>broj_dana[datum_prodaje.DajMjesec()-1]) {
        dan=1;
        mj=datum_prodaje.DajMjesec()+1;
        if(mj>12) {
            g++;
        }
    } else dan=datum_prodaje.DajDan()+1;
    datum_prodaje=Datum(dan,mj,g);
}

void Prodaja::PomjeriDanUnazad()
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int g(datum_prodaje.DajGodinu());
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++;
    int dan(datum_prodaje.DajDan()-1), mj(datum_prodaje.DajMjesec());
    if(dan==0) {
        dan=broj_dana[mj-2];
        mj--;
        if(--mj==0) g--;
    }
    datum_prodaje=Datum(dan, mj, g);
}

void Prodaja::Ispisi() const
{
    std::cout << std::setw(20) << std::left << "Ime agenta: " << ime_agenta_prodaje << std::endl;
    std::cout << std::setw(20) << std::left << "Ime kupca: ";
    kupac_stana.Ispisi();
    std::cout << std::setw(20) << "Zakazani datum prodaje: ";
    datum_prodaje.Ispisi();
    std::cout << std::endl;
    std::cout << std::setw(20) << std::left << "Cijena stana: " << cijena_stana<< std::endl << "Informacije o stanu: \n";
    kupljeni_stan.Ispisi();

}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.DajDatumProdaje().DajGodinu()==p2.DajDatumProdaje().DajGodinu()) {
        if(p1.DajDatumProdaje().DajMjesec()==p2.DajDatumProdaje().DajMjesec()) {
            return p1.DajDatumProdaje().DajDan()<p2.DajDatumProdaje().DajDan();
        } else return p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec();
    } else return p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu();
};

class Prodaje
{
    std::vector<std::shared_ptr<Prodaja>> prodaje;
public:
    explicit Prodaje() {
    };
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja) {
        for(auto it=spisak_prodaja.begin(); it!=spisak_prodaja.end(); it++) {
            prodaje.push_back(std::make_shared<Prodaja>(*it));
        }
    };
    ~Prodaje() {    };
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
                            double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
                            const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje, double cijena_stana, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
        prodaje.push_back(std::make_shared<Prodaja>(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata));
    };
    void RegistrirajProdaju(std::shared_ptr<Prodaja> prodaja);
    int DajBrojProdaja() const {
        return prodaje.size();
    };
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

Prodaje::Prodaje(const Prodaje &p)
{
    for(int i=0; i<p.prodaje.size(); i++) {
        prodaje.push_back(std::make_shared<Prodaja>(*p.prodaje[i]));
    }
}

Prodaje::Prodaje(Prodaje &&p)
{
    for(int i=0; i< p.prodaje.size(); i++) {
        prodaje.push_back(p.prodaje[i]);
        p.prodaje[i]=nullptr;
    }
}
Prodaje &Prodaje::operator =(const Prodaje &p)
{
    for(int i=0; i<p.prodaje.size(); i++) {
        prodaje.push_back(std::make_shared<Prodaja>(*p.prodaje[i]));
    }
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&p)
{
    for(int i=0; i< p.prodaje.size(); i++) {
        prodaje.push_back(p.prodaje[i]);
        p.prodaje[i]=nullptr;
    }
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan)
{
    prodaje.push_back(std::make_shared<Prodaja>(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan));
}


void Prodaje::RegistrirajProdaju(std::shared_ptr<Prodaja> prodaja)
{
    prodaje.push_back(prodaja);
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const
{
    int br(0);
    for(int i=0; i<prodaje.size(); i++) {
        if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() and prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() and prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu() ) {
            br++;
        }
    }
    return br;
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const
{
    int br(0);
    for(int i=0; i<prodaje.size(); i++) {
        if(prodaje[i]->DajImeAgenta()==ime_agenta) br++;
    }
    return br;
}

Prodaja &Prodaje::DajNajranijuProdaju()
{
    if(prodaje.size()==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::min_element(prodaje.begin(), prodaje.end(),  [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) {
        return ProdatPrije(*p1, *p2);
    });
    return **it;
}

Prodaja Prodaje::DajNajranijuProdaju() const
{
    if(prodaje.size()==0) throw std::domain_error("Nema registriranih prodaja");
    return DajNajranijuProdaju();
}

Prodaja &Prodaje::DajNajskupljuProdaju()
{
    if(prodaje.size()==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::max_element(prodaje.begin(), prodaje.end(), [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) {
        return SkupljiStan(*p1, *p2);
    });
    return **it;
};
Prodaja Prodaje::DajNajskupljuProdaju() const
{
    if(prodaje.size()==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::max_element(prodaje.begin(), prodaje.end(),  [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) {
        return SkupljiStan(*p1, *p2);
    });
    return **it;
}

void Prodaje::IsprazniKolekciju()
{
    for(int i=0; i<prodaje.size(); i++) {
        prodaje[i]=nullptr;
    }
}
void Prodaje::ObrisiNajranijuProdaju()
{
    auto it=&DajNajranijuProdaju();
    it=nullptr;
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta)
{
    for(int i=0; i< prodaje.size(); i++) {
        if(prodaje[i]->DajImeAgenta()==ime_agenta) {
            prodaje[i]=nullptr;
        }
    };
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
{
    for(int i=0; i<prodaje.size(); i++) {
        if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() and prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() and prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu() ) {
            prodaje[i]=nullptr;
        }
    }
};
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const
{
    for(int i=0; i<prodaje.size(); i++) {
        if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() and prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() and prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu() ) {
            prodaje[i]->Ispisi();
        }
    };
}
void Prodaje::IspisiSveProdaje() const
{
    for(int i=0; i<prodaje.size(); i++) {
        prodaje[i]->Ispisi();
    }
};
int main(){
    return 0;
}