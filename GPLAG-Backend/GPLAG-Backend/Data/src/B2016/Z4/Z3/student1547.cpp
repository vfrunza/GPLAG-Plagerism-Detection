/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
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
    int max;
    int broj_prodaja;
    Prodaja** prodaje;
public:
    explicit Prodaje(int max_broj_prodaja): max(max_broj_prodaja), broj_prodaja(0) {
        prodaje=new Prodaja*[max_broj_prodaja];
        for(int i=0; i<max_broj_prodaja; i++) {
            prodaje[i]=nullptr;
        }
    };
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja): max(spisak_prodaja.size()), broj_prodaja(spisak_prodaja.size()) {
        prodaje=new Prodaja*[spisak_prodaja.size()];
        int i(0);
        for(auto it=spisak_prodaja.begin(); it!=spisak_prodaja.end(); it++) {
            prodaje[i]=new Prodaja(*it);
            i++;
        }
    };
    ~Prodaje() {
        for(int i=0; i<max; i++) delete prodaje[i];
        delete[] prodaje;
    };
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
                            double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
                            const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje, double cijena_stana, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {

        if(broj_prodaja==max) throw std::range_error ("Dostignut maksimalni broj prodaja");
        prodaje[broj_prodaja]=new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
        broj_prodaja++;

    };
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const {
        return broj_prodaja;
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

Prodaje::Prodaje(const Prodaje &p): max(p.max), broj_prodaja(p.broj_prodaja)
{
    prodaje=new Prodaja*[p.max];
    for(int i=0; i<max; i++) {
        prodaje[i]=new Prodaja(*p.prodaje[i]);
    }
}

Prodaje::Prodaje(Prodaje &&p): max(p.max)
{
    prodaje=new Prodaja*[p.max];
    for(int i=0; i< max; i++) {
        prodaje[i]=p.prodaje[i];
        p.prodaje[i]=nullptr;
    }
}
Prodaje &Prodaje::operator =(const Prodaje &p)
{
    prodaje=new Prodaja*[p.max];
    for(int i=0; i<max; i++) {
        prodaje[i]=new Prodaja(*p.prodaje[i]);
    }
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&p)
{
    prodaje=new Prodaja*[p.max];
    for(int i=0; i< max; i++) {
        prodaje[i]=p.prodaje[i];
        p.prodaje[i]=nullptr;
    }
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan)
{
    if(broj_prodaja==max) throw std::range_error ("Dostignut maksimalni broj prodaja");
    prodaje[broj_prodaja]=new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
    broj_prodaja++;
}


void Prodaje::RegistrirajProdaju(Prodaja *prodaja)
{
    if(broj_prodaja==max) throw std::range_error ("Dostignut maksimalni broj prodaja");
    prodaje[broj_prodaja]=prodaja;
    broj_prodaja++;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const
{
    int br(0);
    for(int i=0; i<broj_prodaja; i++) {
        if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() and prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() and prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu() ) {
            br++;
        }
    }
    return br;
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const
{
    int br(0);
    for(int i=0; i<broj_prodaja; i++) {
        if(prodaje[i]->DajImeAgenta()==ime_agenta) br++;
    }
    return br;
}

Prodaja &Prodaje::DajNajranijuProdaju()
{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::min_element(prodaje, prodaje+broj_prodaja,  [](Prodaja* p1, Prodaja*p2) {
        return ProdatPrije(*p1, *p2);
    });
    return **it;
}

Prodaja Prodaje::DajNajranijuProdaju() const
{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    return DajNajranijuProdaju();
}

Prodaja &Prodaje::DajNajskupljuProdaju()
{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::max_element(prodaje, prodaje+broj_prodaja, [](Prodaja* p1, Prodaja*p2) {
        return SkupljiStan(*p1, *p2);
    });
    return **it;
};
Prodaja Prodaje::DajNajskupljuProdaju() const
{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto it=std::max_element(prodaje, prodaje+broj_prodaja,  [](Prodaja* p1, Prodaja*p2) {
        return SkupljiStan(*p1, *p2);
    });
    return **it;
}

void Prodaje::IsprazniKolekciju()
{
    for(int i=0; i<broj_prodaja; i++) {
        delete prodaje[i];
        prodaje[i]=nullptr;
    }
}
void Prodaje::ObrisiNajranijuProdaju()
{
    auto it=&DajNajranijuProdaju();
    delete it;
    it=nullptr;
    broj_prodaja--;
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta)
{
    for(int i=0; i< broj_prodaja; i++) {
        if(prodaje[i]->DajImeAgenta()==ime_agenta) {
            delete prodaje[i];
            prodaje[i]=nullptr;
             broj_prodaja--;
        }
       
    };
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
{
    for(int i=0; i<broj_prodaja; i++) {
        if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() and prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() and prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu() ) {
            delete prodaje[i];
            prodaje[i]=nullptr;
            broj_prodaja--;
        }
    }
};
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const
{
    for(int i=0; i<broj_prodaja; i++) {
        if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() and prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() and prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu() ) {
            prodaje[i]->Ispisi();
        }
    };
}
void Prodaje::IspisiSveProdaje() const
{
    for(int i=0; i<broj_prodaja; i++) {
        prodaje[i]->Ispisi();
    }
};

using std::cout;
using std::cin;
using std::endl;

void UnesiStan(std::string& adresa,int & sprat,int& broj_soba, int& namjesten,double& kvadratura)
{
    cout << "Unesite adresu: ";
    std::getline(cin, adresa);
    cout << "Unesite sprat: ";
    cin >> sprat;
    cout << "Unesite broj soba: ";
    cin>> broj_soba;
    cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
    cin >> namjesten;
    cout << "Unesite kvadraturu: ";
    cin >> kvadratura;
    cin.ignore(1000, '\n');
}
void UnesiKupca(std::string & ime, int &d, int&m, int&g)
{
    cout << "Unesite ime kupca: \n";
    std::getline(cin, ime);
    cout << "Unesite datum rodjenja (formata dan/mjesec/godina): \n";
    char znak;
    cin >> d >> znak >> m >> znak >>g;
    cin.ignore(1000, '\n');
}
int main ()
{
    cout << "Dobrodosli!"<< std::endl << endl << endl;
    for(;;) {
        int x;
        std::vector<Stan> stanovi;
        std::vector<Kupac> kupci;
        std::vector<Prodaja> p;
        cout << "Izaberite opciju: \n 0 - kraj\n 1 - uredjivanje stanova\n 2 - uredjivanje kupaca\n 3 - uredjivanje prodaja\n";
        cin >> x;
        if(x==0) break;
        else if(x==1) {
            for(;;) {
                int y;
                cout << "Izaberite opciju: \n 0 - nazad\n 1 - dodavanje stana\n 2 - uredjivanje stanova\n 3 - ispis svih stanova\n 4 - kraj\n";
                cin>> y;
                std::cin.ignore(10000, '\n');
                if(y==0) break;
                else if(y==1) {
                    bool gotovo(0);
                    while(!gotovo) {
                        int sprat, broj_soba;
                        std::string adresa;
                        int namjesten;
                        double kvadratura;
                        UnesiStan(adresa, sprat, broj_soba, namjesten, kvadratura);
                        if(namjesten!=0 and namjesten!=1){
                            cout << "Izuzetak: Neispravni podaci. Molimo unesite opet.\n";
                            continue;
                        }
                        try {
                            stanovi.push_back(Stan(adresa, sprat, broj_soba, namjesten, kvadratura));
                            gotovo=1;
                            cout << "Stan je uspjesno dodan!\n"<< endl;
                        } catch(std::domain_error izuz) {
                            cout << "Izuzetak: " << izuz.what() << ". Molimo unesite opet.\n";
                        }
                    }
                } else if(y==2) {
                    int z;
                    cout << "Odaberite stan. Dostupni stanovi su: \n";
                    for(int i=0; i<stanovi.size(); i++) {
                        cout << i+1 << " - ";
                        stanovi[i].Ispisi();
                    }
                    cin >> z;
                    cin.ignore(1000, '\n');
                    for(;;) {
                        cout << "Odaberite polje koji zelite urediti: 0 - nazad\n 1 - adresa\n 2 - sprat\n 3 - broj soba\n 4 - da li je stan namjesten\n 5 - kvadratura\n 6 - sve\n";
                        if(z==0) break;
                        else if(z==1) {
                            std::string adres;
                            cout << "Unesite adresu: \n";
                            std::getline(cin, adres);
                            stanovi[z-1].DajAdresu()=adres;
                            cout << "Stan je uspjesno izmijenjen!\n";
                        } else if(z==2) {
                            bool gotov(0);
                            while(!gotov) {
                                int sprat;
                                cout << "Unesite sprat: \n";
                                cin >> sprat;
                                cin.ignore(1000, '\n');
                                if(sprat>=0) {
                                    stanovi[z-1].DajSprat()=sprat;
                                    cout << "Stan je uspjesno izmijenjen!\n";
                                    gotov=1;
                                } else {
                                    cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                                }
                            }
                        } else if(z==3) {
                            bool gotov(0);
                            while(!gotov) {
                                int broj_soba;
                                cout << "Unesite sprat: \n";
                                cin >> broj_soba;
                                cin.ignore(1000, '\n');
                                if(broj_soba>=0) {
                                    stanovi[z-1].DajBrojSoba()=broj_soba;
                                    cout << "Stan je uspjesno izmijenjen!\n";
                                    gotov=1;
                                } else {
                                    cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                                }
                            }
                        } else if(z==4) {
                            cout << "Da li je stan namjesten (1 - da, 0 - ne): \n";
                            bool namjesten;
                            cin >> namjesten;
                            stanovi[z-1].DajNamjesten()=namjesten;
                        } else if(z==5) {
                            bool gotov(0);
                            while(!gotov) {
                                double kvadratura;
                                cout << "Unesite kvadraturu: \n";
                                cin >> kvadratura;
                                cin.ignore(1000, '\n');
                                if(kvadratura>0) {
                                    stanovi[z-1].DajKvadraturu()=kvadratura;
                                    cout << "Stan je uspjesno izmijenjen!\n";
                                    gotov=1;
                                } else {
                                    cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n";
                                }
                            }
                        } else if(z==6) {
                            bool gotovo(0);
                            while(!gotovo) {
                                std::string adresa;
                                int broj_soba, sprat;
                                double kvadratura;
                                int namjesten;
                                UnesiStan(adresa, sprat, broj_soba, namjesten, kvadratura);
                                if(namjesten!=0 and namjesten!=1){
                                    cout << "Izuzetak: Neispravni podaci. Molimo unesite opet.\n";
                                    continue;
                                }
                                try {
                                    stanovi[z-1].Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
                                    gotovo=1;
                                    cout << "Stan je uspjesno izmijenjen!\n"<< endl;
                                } catch(std::domain_error izuz) {
                                    cout << "Izuzetak: " << izuz.what() << ". Molimo unesite opet.\n" << endl;
                                }
                            }
                        }
                    }
                } else if (y==3) {
                    for(int i=0; i<stanovi.size(); i++) {
                        cout << i+1 << ". ";
                        stanovi[i].Ispisi();
                    }
                    cout << endl;
                } else if (y==4) {
                    cout << endl << endl << endl;
                    cout << "Dovidjenja!";
                    return 0;
                }
            }
        } else if(x==2) {
            for(;;) {
                int y;
                cout << "Izaberite opciju: \n 0 - nazad\n 1 - dodavanje kupca\n 2 - uredjivanje kupaca\n 3 - ispis svih kupaca\n 4 - kraj\n";
                cin >> y;
                cin.ignore(1000, '\n');
                if(y==0) break;
                else if(y==1) {
                    bool gotovo(0);
                    while(!gotovo) {
                        std::string ime;
                        int d,m,g;
                        UnesiKupca(ime, d, m ,g);
                        try {
                            Datum dat(d,m,g);
                            kupci.push_back(Kupac(ime, dat));
                            gotovo=1;
                            cout << "Kupac je uspjesno dodan!\n";
                        } catch (std::domain_error izuz) {
                            cout << "Izuzetak: " << izuz.what() << ". Molimo unesite opet.\n";
                        }
                    }
                } else if(y==2) {
                    cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:\n";
                        for(int i=0; i<kupci.size(); i++) {
                        cout << i+1 <<" - ";
                        kupci[i].Ispisi();
                    }
                     int z;
                     cin >> z;
                     cin.ignore(1000, '\n');
                     std::string ime;
                     int d, m, g;
                     bool gotovo=0;
                     while(!gotovo) {
                        UnesiKupca(ime, d,m,g);
                        try {
                            Datum dat(d,m,g);
                            kupci[z-1].Postavi(ime,dat);
                            cout << "Kupac je uspjesno izmijenjen!";
                        } catch(std::domain_error izuz) {
                            cout << "Izuzetak: " << izuz.what() << ". Molimo unesite opet.\n";
                        }
                    }
                } else if(y==3){
                    for(int i=0; i<kupci.size(); i++){
                        cout << i+1 << ". ";
                        kupci[i].Ispisi();
                    }
                } else if(y==4){
                    cout << endl << endl << endl;
                    cout << "Dovidjenja!";
                    return 0;
                }
            }
        } else if(x==3){
            for(;;){
                int y;
                cout << "Izaberite opciju: \n 0 - nazad\n 1 - dodavanje prodaje\n 2 - uredjivanje prodaje\n 3 - ispis prodaja\n 4 - brisanje prodaja\n 5 - kraj\n";
                cin >> y;
                if(y==0) break;
                else if(y==1){
                    for(;;){
                    cout << "Izaberite opciju: \n 0 - nazad\n 1 - dodavanje potpuno nove prodaje\n 2 - dodavanje nove prodaje na osnovu arhive\n 3 - kraj";
                    int z;
                    cin >> z;
                    cin.ignore(1000, '\n');
                    if(z==0) break;
                    else if(z==1){
                        bool dobar=0;
                        while(!dobar){
                        std::string agent, kupac, adresa;
                        double cijena, kvadratura;
                        int dp, mp, gp, d,m,g, sprat, brsoba, namjesten;
                        cout << "Unesite ime i prezime agenta prodaje: ";
                        std::getline(cin, agent);
                        cout << "Unesite datum prodaje (formata d/m/g): ";
                        char znak;
                        cin >> dp >> znak >> mp >> znak >> gp;
                        cout << "Unesite cijenu stana: ";
                        cin >> cijena;
                        cin.ignore(1000,'\n');
                        UnesiKupca(kupac, d, m, g);
                        UnesiStan(adresa, sprat, brsoba, namjesten, kvadratura);
                        if(namjesten!=0 and namjesten!=1){
                            cout << "Izuzetak: Neispravni podaci. Molimo unesite opet.\n";
                            continue;
                        }
                        try{
                            Datum dat1(d,m,g);
                            Kupac k(kupac,dat1);
                            Datum dat(dp, mp, gp);
                            Stan stan(adresa, sprat, brsoba, namjesten, kvadratura);
                            p.push_back(Prodaja(agent, cijena, dat, k, stan));
                            dobar=1;
                            cout << "Prodaja uspjesno dodana!\n"<< endl;
                        } catch(std::domain_error izuz){
                            cout <<  "Izuzetak: "<< izuz.what() << ". Molimo unesite opet.\n";
                        }
                        }
                    }
                    else if(z==2){
                        bool dobar=0;
                        while(!dobar){
                        std::string agent;
                        int dp, mp, gp;
                        double cijena;
                        cout << "Unesite ime i prezime agenta prodaje: ";
                        std::getline(cin, agent);
                        cout << "Unesite datum prodaje (formata d/m/g): ";
                        char znak;
                        cin >> dp >> znak >> mp >> znak >> gp;
                        cout << "Unesite cijenu stana: ";
                        cin >> cijena;
                        cout << "Odaberite kupca. Dostupni kupci su: \n";
                        for(int i=0; i<kupci.size(); i++) {
                            cout << i+1 <<" - ";
                            kupci[i].Ispisi();
                        }
                        int w;
                        cin >> w;
                        cin.ignore(1000, '\n');
                        Kupac k(kupci[w-1]);
                        cout << "Odaberite stan. Dostupni stanovi su: \n";
                        for(int i=0; i<stanovi.size(); i++) {
                            cout << i+1 << " - ";
                            stanovi[i].Ispisi();
                        }
                        int q;
                        cin >> q;
                        cin.ignore(1000, '\n');
                        Stan s(stanovi[q-1]);
                        try{
                            Datum dat(dp, mp, gp);
                            p.push_back(Prodaja(agent, cijena, dat, k, s));
                            dobar=1;
                            cout << "Prodaja uspjesno dodana!\n"<< endl;
                        } catch(std::domain_error izuz){
                            cout <<  "Izuzetak: "<< izuz.what() << ". Molimo unesite opet.\n";
                        }
                        }
                    }
                    else if(z==3){
                        cout << endl << endl << endl;
                        cout << "Dovidjenja!";
                        return 0;
                    }
                }
                }
                else if(y==2){
                    cout << "Odaberite prodaju koju želite urediti. Dostupne prodaje su: \n";
                    for(int i=0; i<p.size(); i++){
                        cout << i+1 << " - ";
                        p[i].Ispisi();
                    }
                    int z;
                    cin >> z;
                    cin.ignore(1000, '\n');
                    cout << "Izaberite opciju: \n 0 - nazad\n 1 - izmjena agenta\n 2 - izmjena datuma prodaje\n 3 - izmjena kupca\n 4 - izmjena stana\n 5 - izmjena cijene stana\n";
                    int q;
                    cin >> q;
                    cin.ignore(1000, '\n');
                    if(q==0) continue;
                    else if(q==1){
                        std::string agent;
                        cout << "Unesite ime i prezime agenta prodaje: ";
                        getline(cin, agent);
                        p[z-1].DajImeAgenta()=agent;
                        cout << "Prodaja je uspjesno izmijenjena!";
                    }
                    else if(q==2){
                        int d, m ,g;
                        char znak;
                        cout << "Unesite datum prodaje (formata d/m/g): ";
                        bool dobar=0;
                        while(!dobar){
                        cin >> d >> znak >> m >> znak >> g;
                        cin.ignore(10000, 'n');
                        try{
                        p[z-1].PromijeniDatumKupovine(Datum(d,m,g));
                        dobar=1;
                        cout << "Promjena uspjesno izmijenjena!";
                        } catch(std::domain_error izuz){
                            cout << "Izuzetak: " << izuz.what() << ". Molimo unesite opet.\n";
                        }
                        }
                    }
                    else if(q==3){
                        std::string kupac;
                        int d, m ,g;
                        UnesiKupca(kupac, d, m, g);
                        Datum dat(d,m,g);
                        Kupac k(kupac, dat);
                        p[z-1].PromijeniKupca(k);
                    }
                    else if(q==3){
                        double cijena;
                        cout << "Unesite cijenu stana: ";
                        cin >> cijena;
                        cin.ignore(10000, 'n');
                        p[z-1].PromijeniCijenuProdaje(cijena);
                    }
                }
            }
        }
    }
 return 0;
}