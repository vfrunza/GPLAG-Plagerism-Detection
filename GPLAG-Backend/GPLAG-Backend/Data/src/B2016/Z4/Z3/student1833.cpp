#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>
#include <algorithm>
#include <vector>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;
class  Datum
{
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina);
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
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};
void Datum::Postavi(int dan,int mjesec,int godina)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0 ) broj_dana[1]++;
    if( godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1]) throw std::domain_error("Neispravan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}
bool JednakiDatumi(const Datum &d1, const Datum &d2)
{
    return d1.DajDan()==d2.DajDan() && d1.DajMjesec()==d2.DajMjesec() && d1.DajGodinu()==d2.DajGodinu();
}
class Kupac
{
    std::string _ime_i_prezime;
    Datum _datum_rodjenja;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : _datum_rodjenja(datum_rodjenja) {
        Postavi(ime_i_prezime, datum_rodjenja);
    }
    void Ispisi() const {
        std::cout << DajImePrezime() << " (";
        DajDatumRodjenja().Ispisi();
        std::cout << ")" << std::endl;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const {
        return _ime_i_prezime;
    }
    Datum DajDatumRodjenja() const {
        return _datum_rodjenja;
    }
};
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
{
    _datum_rodjenja=datum_rodjenja;
    std::locale loc;
    for(auto it=ime_i_prezime.begin(); it!=ime_i_prezime.end(); it++)
        if(!(std::isalnum(*it,loc) || *it=='-' || *it==39 || *it==' ')) throw std::domain_error("Neispravno ime i prezime");
    _ime_i_prezime=ime_i_prezime;
}
bool JednakiKupci(const Kupac &k1, const Kupac &k2)
{
    return k1.DajImePrezime()==k2.DajImePrezime() && JednakiDatumi(k1.DajDatumRodjenja(),k2.DajDatumRodjenja());
}
class Stan
{
    int _sprat,_broj_soba;
    double _kvadratura;
    bool _namjesten;
    std::string _adresa;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    double DajKvadraturu() const {
        return _kvadratura;
    }
    std::string DajAdresu() const {
        return _adresa;
    }
    bool DajNamjesten() const {
        return _namjesten;
    }
    int DajBrojSoba() const {
        return _broj_soba;
    }
    int DajSprat() const {
        return _sprat;
    }
    void Ispisi() const {
        std::cout<<"Stan se nalazi na adresi "<< DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba();
        if(DajBrojSoba()%10>1 && DajBrojSoba()%10<5) std::cout<<" sobe";
        else if(DajBrojSoba()%10 ==1) std::cout<<" sobu";
        else std::cout<<" soba";
        std::cout<<". Kvadratura stana je "<< DajKvadraturu()<<" (m^2) i stan ";
        if(!DajNamjesten()) std::cout<<"ni";
        std::cout<<"je namjesten."<<std::endl;
    }

};
void Stan::Postavi(const std::string &adresa,int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    if(sprat<0 || broj_soba <0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");

    _kvadratura=kvadratura;
    _broj_soba=broj_soba;
    _namjesten=namjesten;
    _adresa=adresa;
    _sprat=sprat;
}

bool JednakiStanovi(const Stan &k1, const Stan &k2)
{
    return k1.DajSprat()==k2.DajSprat() && k1.DajBrojSoba()==k2.DajBrojSoba() && k1.DajNamjesten() == k2.DajNamjesten() && k1.DajAdresu()==k2.DajAdresu() && fabs(k1.DajKvadraturu()-k2.DajKvadraturu())< 1e-6;
}
class Prodaja
{
    std::string _ime_agenta_prodaje;
    double _cijena_stana;
    Datum _datum_prodaje;
    Kupac _kupac_stana;
    Stan _kupljeni_stan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac) {
        _kupac_stana = novi_kupac;
    }
    void PromijeniStan(const Stan &novi_stan) {
        _kupljeni_stan = novi_stan;
    }
    void PromijeniDatumKupovine(const Datum &novi_datum) {
        _datum_prodaje = novi_datum;
    }
    void PromijeniCijenuProdaje(const double &nova_cijena) {
        _cijena_stana = nova_cijena;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    double DajCijenuStana() const {
        return _cijena_stana;
    }
    Datum DajDatumProdaje() const {
        return _datum_prodaje;
    }
    std::string DajImeAgenta() const {
        return _ime_agenta_prodaje;
    }
    std::string DajImeKupca() const {
        return _kupac_stana.DajImePrezime();
    }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):_datum_prodaje(datum_prodaje), _kupac_stana(kupac_stana), _kupljeni_stan(kupljeni_stan)
{
    if(cijena_stana<0) throw std::domain_error("Neispravna cijena strana");
    _ime_agenta_prodaje=ime_agenta_prodaje;
    _cijena_stana=cijena_stana;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):_datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), _kupac_stana(ime_kupca, datum_rodjenja_kupca),
    _kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)
{
    if(cijena_stana<0) throw std::domain_error("Neispravna cijena strana");
    _ime_agenta_prodaje=ime_agenta_prodaje;
    _cijena_stana=cijena_stana;
}
void Prodaja::PomjeriDanUnaprijed()
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( _datum_prodaje.DajGodinu() % 4 == 0 && _datum_prodaje.DajGodinu() % 100 != 0 || _datum_prodaje.DajGodinu() % 400 == 0 ) broj_dana[1]++;
    if(_datum_prodaje.DajDan() < broj_dana[_datum_prodaje.DajMjesec() - 1]) _datum_prodaje.Postavi(_datum_prodaje.DajDan() + 1, _datum_prodaje.DajMjesec(), _datum_prodaje.DajGodinu());
    else { //Ako je jednak
        if(_datum_prodaje.DajMjesec() < 12) _datum_prodaje.Postavi(1, _datum_prodaje.DajMjesec() + 1, _datum_prodaje.DajGodinu());
        else _datum_prodaje.Postavi(1, 1, _datum_prodaje.DajGodinu() + 1); //Nova godina :D
    }
}
void Prodaja::PomjeriDanUnazad()
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( _datum_prodaje.DajGodinu() % 4 == 0 && _datum_prodaje.DajGodinu() % 100 != 0 || _datum_prodaje.DajGodinu() % 400 == 0 ) broj_dana[1]++;
    if(_datum_prodaje.DajDan() > 1) _datum_prodaje.Postavi(_datum_prodaje.DajDan() - 1, _datum_prodaje.DajMjesec(), _datum_prodaje.DajGodinu());
    else { //Ako je jednak
        if(_datum_prodaje.DajMjesec() > 1) _datum_prodaje.Postavi(broj_dana[_datum_prodaje.DajMjesec() - 1], _datum_prodaje.DajMjesec() - 1, _datum_prodaje.DajGodinu());
        else _datum_prodaje.Postavi(broj_dana[11], 12, _datum_prodaje.DajGodinu() - 1); //Nova godina :D
    }
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    Datum d1(p1.DajDatumProdaje()),d2(p2.DajDatumProdaje());
    if(d1.DajGodinu()<d2.DajGodinu()) return true;
    else if(d1.DajGodinu()==d2.DajGodinu()) {
        if(d1.DajMjesec() < d2.DajMjesec()) return true;
        else if(d1.DajMjesec()==d2.DajMjesec()) return d1.DajDan() < d2.DajDan();
    }
    return false;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    return p1.DajCijenuStana()<p2.DajCijenuStana();
}
void Prodaja::Ispisi()const
{
    std::cout<<"Ime agenta:                 "<<DajImeAgenta()<<std::endl;
    std::cout<<"Ime kupca:                  ";
    _kupac_stana.Ispisi();
    std::cout<< "Zakazani datum prodaje:     ";
    _datum_prodaje.Ispisi();
    std::cout << std::endl;
    std::cout<< "Cijena stana:               " << DajCijenuStana() << std::endl;
    std::cout<< "Informacije o stanu:" << std::endl;
    _kupljeni_stan.Ispisi();
}
class Prodaje
{
    int broj_prodaja;
    int max_broj_prodaja;
    Prodaja **prodaje;
    void Dealociraj() {
        for(int i=0; i<broj_prodaja; i++) delete prodaje[i];
        delete []prodaje;
    }
public:
    explicit Prodaje(int max_prodaja) : broj_prodaja(0), max_broj_prodaja(max_prodaja), prodaje(new Prodaja*[max_prodaja] {}) {}
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje() {
        Dealociraj();
    }
    Prodaje(const Prodaje &p);
    Prodaje(Prodaje &&p);
    Prodaje &operator=(const Prodaje &p);
    Prodaje &operator=(Prodaje &&p);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, const std::string &ime_kupca, const Datum & datum_rodjenja_kupca, const std::string & adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const {
        return broj_prodaja;
    }
    int DajBrojProdajaNaDatum(const Datum & datum) const {
        return std::count_if(prodaje, prodaje + broj_prodaja, [datum](Prodaja *p) {
            return JednakiDatumi(datum, p->DajDatumProdaje());
        });
    }
    int DajBrojProdajaOdAgenta(const std::string & ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju() {
        Dealociraj();
        broj_prodaja = 0;
    }
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum & datum);
    void IspisiProdajeNaDatum(const Datum & datum) const;
    void IspisiSveProdaje() const;
};
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja): broj_prodaja(spisak_prodaja.size()), max_broj_prodaja(spisak_prodaja.size()), prodaje(new Prodaja*[spisak_prodaja.size()] {})
{
    try {
        for(int i=0; i<broj_prodaja; i++) prodaje[i]=new Prodaja(spisak_prodaja.begin()[i]);
    } catch(...) {
        Dealociraj();
    }
}
Prodaje::Prodaje(const Prodaje &p) : broj_prodaja(p.broj_prodaja), max_broj_prodaja(p.max_broj_prodaja), prodaje(new Prodaja*[p.max_broj_prodaja] {})
{
    try {
        for(int i=0; i<broj_prodaja; i++) prodaje[i]=new Prodaja(*p.prodaje[i]);
    } catch(...) {
        Dealociraj();
    }
}
Prodaje::Prodaje(Prodaje &&p) :broj_prodaja(p.broj_prodaja),max_broj_prodaja(p.max_broj_prodaja),prodaje(p.prodaje)
{
    p.broj_prodaja=0;
    p.prodaje=nullptr;
}
Prodaje &Prodaje::operator=(const Prodaje &p)
{
    if(&p!=this) {
        Dealociraj();
        max_broj_prodaja=p.max_broj_prodaja;
        broj_prodaja=p.broj_prodaja;
        prodaje=nullptr;
        prodaje=new Prodaja*[max_broj_prodaja];
        int j(0);
        try {
            for(; j<broj_prodaja; j++) prodaje[j]=new Prodaja(*p.prodaje[j]);
        } catch(...) {
            for(int i=broj_prodaja; i<j; i++) {
                delete prodaje[i];
                prodaje[i]=nullptr;
            }
            throw;
        }
    }
    return *this;
}
Prodaje &Prodaje::operator=(Prodaje &&p)
{
    std::swap(max_broj_prodaja,p.max_broj_prodaja);
    std::swap(broj_prodaja,p.broj_prodaja);
    std::swap(prodaje,p.prodaje);
    p.prodaje=nullptr;
    p.broj_prodaja=0;
    return *this;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan)
{
    if(broj_prodaja == max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    prodaje[broj_prodaja++] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, const std::string &ime_kupca, const Datum & datum_rodjenja_kupca, const std::string & adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
    if(broj_prodaja==max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    prodaje[broj_prodaja++]=new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
}
void Prodaje::RegistrirajProdaju(Prodaja *prodaja)
{
    if(broj_prodaja == max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    prodaje[broj_prodaja++] = prodaja;
}
Prodaja &Prodaje::DajNajranijuProdaju()
{
    if(DajBrojProdaja()==0) throw std::domain_error ("Nema registriranih prodaja");
    return **std::min_element(prodaje,prodaje+broj_prodaja,[](Prodaja *p1, Prodaja *p2) {
        return ProdatPrije(*p1,*p2);
    });
}
Prodaja Prodaje::DajNajranijuProdaju() const
{
    if(DajBrojProdaja()==0) throw std::domain_error ("Nema registriranih prodaja");
    return **std::min_element(prodaje,prodaje+broj_prodaja,[](Prodaja *p1, Prodaja *p2) {
        return ProdatPrije(*p1,*p2);
    });
}
Prodaja &Prodaje::DajNajskupljuProdaju()
{
    if(DajBrojProdaja()==0) throw std::domain_error ("Nema registriranih prodaja");
    return **std::min_element(prodaje,prodaje+broj_prodaja,[](Prodaja *p1, Prodaja *p2) {
        return SkupljiStan(*p1,*p2);
    });
}
Prodaja Prodaje::DajNajskupljuProdaju() const
{
    if(DajBrojProdaja()==0) throw std::domain_error ("Nema registriranih prodaja");
    return **std::min_element(prodaje,prodaje+broj_prodaja,[](Prodaja *p1, Prodaja *p2) {
        return SkupljiStan(*p1,*p2);
    });
}
void Prodaje::ObrisiNajranijuProdaju()
{
    Prodaja najranija(DajNajranijuProdaju());
    for(int i=0; i<broj_prodaja; i++) {
        Prodaja p=*prodaje[i];
        if(JednakiDatumi(najranija.DajDatumProdaje(), p.DajDatumProdaje()) && najranija.DajImeAgenta() == p.DajImeAgenta() && najranija.DajImeKupca() == p.DajImeKupca() && fabs(najranija.DajCijenuStana() - p.DajCijenuStana()) < 1e-6) {
            for(int j=i; j< broj_prodaja-1; j++) std::swap(prodaje[j],prodaje[j+1]);
            delete prodaje[broj_prodaja-1];
            broj_prodaja--;
            break;
        }
    }
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta)
{
    for(int i = 0; i < broj_prodaja; i++) {
        if(prodaje[i]->DajImeAgenta() == ime_agenta) {
            for(int j=i; j<broj_prodaja-1; j++) std::swap(prodaje[j], prodaje[j+1]);
            delete prodaje[broj_prodaja-1];
            broj_prodaja--;
            i--;
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum & datum)
{
    for(int i=0; i<broj_prodaja; i++) {
        if(JednakiDatumi(prodaje[i]->DajDatumProdaje(),datum)) {
            for(int j=i; j<broj_prodaja-1; j++ ) std::swap(prodaje[j],prodaje[j+1]);
            delete prodaje[broj_prodaja-1];
            broj_prodaja--;
            i--;
        }
    }
}
void Prodaje::IspisiProdajeNaDatum(const Datum & datum) const
{
    std::vector<Prodaja> ispis;
    for(int i=0; i<DajBrojProdaja(); i++)
        if(JednakiDatumi(prodaje[i]->DajDatumProdaje(),datum)) ispis.push_back(*prodaje[i]);
    std::sort(ispis.begin(),ispis.end(),ProdatPrije);
    for(int i=0; i<ispis.size(); i++) ispis[i].Ispisi();
}
void Prodaje::IspisiSveProdaje() const
{
    std::vector<Prodaja> ispis;
    for(int i=0; i<DajBrojProdaja(); i++) ispis.push_back(*prodaje[i]);
    std::sort(ispis.begin(),ispis.end(), ProdatPrije);
    for(int i=0; i<ispis.size(); i++) ispis[i].Ispisi();
}

int main ()
{
    std::cout<<"Dobrodosli!"<<std::endl<<std::endl<<endl;
    int n,m;
    std::vector<Stan> stanovi;
    Prodaje prodaja(1000);
    std::vector<Kupac> kupci;
    std::string adresa,ime_i_prezime,datum,ime_agenta,datum_prodaje;
    int sprat,namjesten_int;
    int broj_soba;
    bool namjesten;
    double kvadratura,cijena_stana;
    for(;;) {
        cin.clear();
        cout<<"Izaberite opciju:"<<endl<<" 0 - kraj"<<endl;
        cout<<" 1 - uredjivanje stanova"<<endl<<" 2 - uredjivanje kupaca"<<endl<<" 3 - uredjivanje prodaja";
        cin>>n;
        if(n==0) break;
        else if(n==1) {
            for(;;) {

                cout<<endl<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl;
                cout<<" 1 - dodavanje stana"<<endl<<" 2 - uredjivanje stanova"<<endl<<" 3 - ispis svih stanova"<<endl<<" 4 - kraj"<<endl;
                cin>>m;
                if(m==0) break;
                if(m==1) {
                    bool izuzetak=false;
                    do {
                        try {
                            izuzetak=false;
                            cout<<"Unesite adresu: ";
                            std::cin.clear();
                            std::cin.ignore(100,'\n');
                            std::getline(std::cin,adresa);
                            cout<<"Unesite sprat: ";
                            cin>>sprat;
                            cout<<"Unesite broj soba: ";
                            cin>>broj_soba;
                            cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                            cin>>namjesten_int;
                            cout<<"Unesite kvadraturu: ";
                            cin>>kvadratura;
                            if(namjesten_int!=0 && namjesten_int !=1)
                                throw std::logic_error ("Izuzetak");
                            else {
                                if(namjesten_int==1)
                                    namjesten=true;
                                else namjesten=false;
                            }
                            stanovi.push_back({adresa,sprat,broj_soba,namjesten,kvadratura});
                        } catch(...) {
                            izuzetak=true;
                            cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<endl;
                        }
                    } while(izuzetak);
                    cout<<"Stan je uspjesno dodan!"<<endl;

                } else if(m==2) {
                    cout<<"Odaberite stan. Dostupni stanovi su:"<<endl;
                    int indeks_stana;
                    for(int i=0; i<stanovi.size(); i++) {
                        cout<<" "<<i+1<<" - ";
                        stanovi[i].Ispisi();
                    }
                    cin >> indeks_stana;
                    int opcija;
                    indeks_stana--;
                    std::cout << endl<<"Odaberite polje koje zelite urediti:" << std::endl;
                    std::cout << " 0 - nazad\n 1 - adresa\n 2 - sprat\n 3 - broj soba\n 4 - da li je stan namjesten\n 5 - kvadratura\n 6 - sve" << std::endl;
                    cin >> opcija;
                    for(;;) {

                        bool izuzetak=false;
                        do {
                            try {

                                izuzetak=false;


                                if(opcija == 0) break;
                                else if(opcija == 1) {
                                    std::cin.clear();
                                    std::cin.ignore(100,'\n');
                                    std::getline(std::cin,adresa);
                                    stanovi[indeks_stana].Postavi(adresa, stanovi[indeks_stana].DajSprat(), stanovi[indeks_stana].DajBrojSoba(),stanovi[indeks_stana].DajNamjesten(), stanovi[indeks_stana].DajKvadraturu());
                                } else if(opcija == 2) {
                                    std::cin >> sprat;
                                    stanovi[indeks_stana].Postavi(stanovi[indeks_stana].DajAdresu(), sprat, stanovi[indeks_stana].DajBrojSoba(),stanovi[indeks_stana].DajNamjesten(), stanovi[indeks_stana].DajKvadraturu());

                                } else if(opcija == 3) {
                                    std::cin >> broj_soba;
                                    stanovi[indeks_stana].Postavi(stanovi[indeks_stana].DajAdresu(), stanovi[indeks_stana].DajSprat(), broj_soba,stanovi[indeks_stana].DajNamjesten(), stanovi[indeks_stana].DajKvadraturu());

                                } else if(opcija == 4) {
                                    std::cin >>namjesten;
                                    stanovi[indeks_stana].Postavi(stanovi[indeks_stana].DajAdresu(), stanovi[indeks_stana].DajSprat(), stanovi[indeks_stana].DajBrojSoba(),namjesten, stanovi[indeks_stana].DajKvadraturu());

                                } else if(opcija == 5) {
                                    cout<<"Unesite kvadraturu: ";
                                    std::cin >> kvadratura;
                                    stanovi[indeks_stana].Postavi(stanovi[indeks_stana].DajAdresu(), stanovi[indeks_stana].DajSprat(), stanovi[indeks_stana].DajBrojSoba(),stanovi[indeks_stana].DajNamjesten(), kvadratura);

                                } else if(opcija == 6) {

                                    cout<<"Unesite adresu: ";
                                    std::cin.clear();
                                    std::cin.ignore(100,'\n');
                                    std::getline(std::cin,adresa);
                                    cout<<"Unesite sprat: ";
                                    cin>>sprat;
                                    cout<<"Unesite broj soba: ";
                                    cin>>broj_soba;
                                    cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                                    cin>>namjesten_int;
                                    cout<<"Unesite kvadraturu: ";
                                    cin>>kvadratura;
                                    if(namjesten_int!=0 && namjesten_int !=1)
                                        throw std::logic_error ("Izuzetak");
                                    else {
                                        if(namjesten_int==1)
                                            namjesten=true;
                                        else namjesten=false;
                                    }
                                    stanovi[indeks_stana].Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
                                }
                            } catch(...) {
                                izuzetak=true;
                                cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<endl;
                            }
                        } while(izuzetak);
                        cout<<"Stan je uspjesno izmijenjen!"<<endl;
                        break;
                    }
                } else if(m==3) {
                    for(int i=0; i<stanovi.size(); i++) {
                        cout<<i+1<<". ";
                        stanovi[i].Ispisi();
                    }
                }

            }
        }

        else if(n==2) {
            for(;;) {
                cout<<endl<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl;
                cout<<" 1 - dodavanje kupca"<<endl<<" 2 - uredjivanje kupaca"<<endl<<" 3 - ispis svih kupaca"<<endl<<" 4 - kraj"<<endl;
                cin>>m;
                std::cin.ignore(100,'\n');

                if(m==0) break;
                if(m==1) {
                    bool izuzetak=false;
                    do {
                        try {

                            izuzetak=false;
                            cout<<"Unesite ime i prezime kupca: ";
                            std::getline(std::cin,ime_i_prezime);
                            cout<<"Unesite datum rodjenja (formata d/m/g): ";
                            std::getline(std::cin,datum);
                            int godina,dan,mjesec;
                            try {
                                godina = std::stoi ( datum.substr( 5, 4 ));
                                dan = std::stoi ( datum.substr( 0, '/' ));
                                mjesec = std::stoi ( datum.substr( 2, '/' ));
                                if(godina-1000<0)
                                    throw;
                            } catch(...) {
                                try {
                                    godina = std::stoi ( datum.substr( 6, 4 ));
                                    dan = std::stoi ( datum.substr( 0, '/' ));
                                    mjesec = std::stoi ( datum.substr( 3, '/' ));
                                    if(godina-1000<0)
                                        throw;
                                } catch(...) {
                                    try {
                                        godina = std::stoi ( datum.substr( 4, 4 ));
                                        dan = std::stoi ( datum.substr( 0, '/' ));
                                        mjesec = std::stoi ( datum.substr( 2, '/' ));
                                        if(godina-1000<0)
                                            throw;
                                    }

                                    catch(...) {
                                        godina = std::stoi ( datum.substr( 5, 4 ));
                                        dan = std::stoi ( datum.substr( 0, '/' ));
                                        mjesec = std::stoi ( datum.substr( 3, '/' ));
                                    }
                                }

                            }

                            Datum D(dan,mjesec,godina);
                            kupci.push_back({ime_i_prezime,D});
                        } catch(std::logic_error e) {
                            izuzetak=true;
                            cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;
                        }
                    } while(izuzetak);
                    cout<<"Kupac je uspjesno dodan!"<<endl;

                } else if(m==2) {
                    cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<endl;
                    int indeks_kupca;
                    for(int i=0; i<kupci.size(); i++) {
                        cout<<" "<<i+1<<" - ";
                        kupci[i].Ispisi();
                    }
                    cin >> indeks_kupca;
                    indeks_kupca--;
                    std::cin.ignore(100,'\n');

                    for(;;) {

                        bool izuzetak=false;
                        do {
                            try {

                                izuzetak=false;
                                cout<<"Unesite ime i prezime kupca: ";
                                std::getline(std::cin,ime_i_prezime);
                                cout<<"Unesite datum rodjenja (formata d/m/g): ";
                                std::getline(std::cin,datum);
                                int godina,dan,mjesec;
                                try {
                                    godina = std::stoi ( datum.substr( 5, 4 ));
                                    dan = std::stoi ( datum.substr( 0, '/' ));
                                    mjesec = std::stoi ( datum.substr( 3, '/' ));
                                    if(godina-1000<0)
                                        throw;

                                } catch(...) {
                                    try {
                                        godina = std::stoi ( datum.substr( 6, 4 ));
                                        dan = std::stoi ( datum.substr( 0, '/' ));
                                        mjesec = std::stoi ( datum.substr( 3, '/' ));
                                        if(godina-1000<0)
                                            throw;

                                    } catch(...) {
                                        try {
                                            godina = std::stoi ( datum.substr( 5, 4 ));
                                            dan = std::stoi ( datum.substr( 0, '/' ));
                                            mjesec = std::stoi ( datum.substr( 2, '/' ));
                                            if(godina-1000<0)
                                                throw;
                                        }

                                        catch(...) {
                                            godina = std::stoi ( datum.substr( 4, 4 ));
                                            dan = std::stoi ( datum.substr( 0, '/' ));
                                            mjesec = std::stoi ( datum.substr( 2, '/' ));

                                        }
                                    }

                                }

                                Datum D(dan,mjesec,godina);
                                kupci[indeks_kupca].Postavi(ime_i_prezime,D);


                            } catch(std::logic_error e) {
                                izuzetak=true;
                                cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;
                            }
                        } while(izuzetak);
                        cout<<"Kupac je uspjesno izmijenjen!"<<endl;
                        break;
                    }
                } else if(m==3) {
                    for(int i=0; i<kupci.size(); i++)
                        kupci[i].Ispisi();
                }
            }
        } else if(n==3) {

            for(;;) {
                cout<<endl<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl;
                cout<<" 1 - dodavanje prodaje"<<endl<<" 2 - uredjivanje prodaje"<<endl<<" 3 - ispis prodaja"<<endl<<" 4 - brisanje prodaja"<<endl<<" 5 - kraj"<<endl;
                cin>>m;

                if(!std::cin) break;
                if(m==0) break;
                if(m==1) {
                    for(;;){
                        
                    
                    cout<<endl<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl;
                    cout<<" 1 - dodavanje potpuno nove prodaje"<<endl<<" 2 - dodavanje nove prodaje na osnovu arhive"<<endl<<" 3 - kraj"<<endl;
                    int opcija;
                    cin >> opcija;
                    if(opcija==0) break;

                    if(opcija != 0) {
                                                   bool izuzetak=false;

                        
                        do {
                                            if(!std::cin) break;

                            try {

                                if(opcija == 1) {

                                                        std::cin.ignore(100,'\n');

                                    izuzetak=false;
                                    int dan,godina,mjesec;
                                    cout<<"Unesite ime i prezime agenta prodaje: ";
                                    std::getline(std::cin,ime_agenta);
                                    cout<<"Unesite datum prodaje (formata d/m/g): ";
                                    std::getline(std::cin,datum_prodaje);
                                    cout<<"Unesite cijenu stana: ";
                                    cin>>cijena_stana;
                                    std::cin.ignore(100,'\n');

                                    cout<<"Unesite ime kupca: ";
                                    std::getline(std::cin,ime_i_prezime);
                                    std::cout <<"Unesite datum rodjenja kupca (formata d/m/g): ";
                                    std::getline(std::cin,datum);
                                    cout<<"Unesite adresu: ";
                                    std::getline(std::cin,adresa);
                                    cout<<"Unesite sprat: ";
                                    cin>>sprat;
                                    cout<<"Unesite broj soba: ";
                                    cin>>broj_soba;
                                    cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                                    cin>>namjesten_int;
                                    cout<<"Unesite kvadraturu: ";
                                    cin>>kvadratura;
                                    if(namjesten_int!=0 && namjesten_int !=1)
                                        throw std::logic_error ("Izuzetak");
                                    else {
                                        if(namjesten_int==1)
                                            namjesten=true;
                                        else namjesten=false;
                                    }

                                    try {
                                        godina = std::stoi ( datum.substr( 5, 4 ));
                                        dan = std::stoi ( datum.substr( 0, '/' ));
                                        mjesec = std::stoi ( datum.substr( 3, '/' ));
                                        if(godina-1000<0)
                                            throw;

                                    } catch(...) {
                                        try {
                                            godina = std::stoi ( datum.substr( 6, 4 ));
                                            dan = std::stoi ( datum.substr( 0, '/' ));
                                            mjesec = std::stoi ( datum.substr( 3, '/' ));
                                            if(godina-1000<0)
                                                throw;

                                        } catch(...) {
                                            try {
                                                godina = std::stoi ( datum.substr( 5, 4 ));
                                                dan = std::stoi ( datum.substr( 0, '/' ));
                                                mjesec = std::stoi ( datum.substr( 2, '/' ));
                                                if(godina-1000<0)
                                                    throw;
                                            }

                                            catch(...) {
                                                godina = std::stoi ( datum.substr( 4, 4 ));
                                                dan = std::stoi ( datum.substr( 0, '/' ));
                                                mjesec = std::stoi ( datum.substr( 2, '/' ));

                                            }
                                        }

                                    }
                                    Datum D(dan,mjesec,godina);
                                    kupci.push_back({ime_i_prezime,D});
                                    try {
                                        godina = std::stoi ( datum_prodaje.substr( 5, 4 ));
                                        dan = std::stoi ( datum_prodaje.substr( 0, '/' ));
                                        mjesec = std::stoi ( datum_prodaje.substr( 3, '/' ));
                                        if(godina-1000<0)
                                            throw;

                                    } catch(...) {
                                        try {
                                            godina = std::stoi ( datum_prodaje.substr( 6, 4 ));
                                            dan = std::stoi ( datum_prodaje.substr( 0, '/' ));
                                            mjesec = std::stoi ( datum_prodaje.substr( 3, '/' ));
                                            if(godina-1000<0)
                                                throw;

                                        } catch(...) {
                                            try {
                                                godina = std::stoi ( datum_prodaje.substr( 5, 4 ));
                                                dan = std::stoi ( datum_prodaje.substr( 0, '/' ));
                                                mjesec = std::stoi ( datum_prodaje.substr( 2, '/' ));
                                                if(godina-1000<0)
                                                    throw;
                                            }

                                            catch(...) {
                                                godina = std::stoi ( datum_prodaje.substr( 4, 4 ));
                                                dan = std::stoi ( datum_prodaje.substr( 0, '/' ));
                                                mjesec = std::stoi ( datum_prodaje.substr( 2, '/' ));

                                            }
                                        }

                                    }
                                    Datum D1(dan,mjesec,godina);

                                    stanovi.push_back({adresa,sprat,broj_soba,namjesten,kvadratura});

                                    prodaja.RegistrirajProdaju(ime_agenta,cijena_stana,D1,kupci[kupci.size()-1],stanovi[stanovi.size()-1]);

                                } else if(opcija == 2) {
                                    izuzetak=false;
                                                        std::cin.ignore(100,'\n');

                                    int dan,godina,mjesec;
                                    cout<<"Unesite ime i prezime agenta prodaje: ";
                                    std::getline(std::cin,ime_agenta);
                                    cout<<"Unesite datum prodaje (formata d/m/g): ";
                                    std::getline(std::cin,datum_prodaje);
                                    cout<<"Unesite cijenu stana: ";
                                    cin>>cijena_stana;
                                    try {
                                        godina = std::stoi ( datum_prodaje.substr( 5, 4 ));
                                        dan = std::stoi ( datum_prodaje.substr( 0, '/' ));
                                        mjesec = std::stoi ( datum_prodaje.substr( 3, '/' ));
                                        if(godina-1000<0)
                                            throw;

                                    } catch(...) {
                                        try {
                                            godina = std::stoi ( datum_prodaje.substr( 6, 4 ));
                                            dan = std::stoi ( datum_prodaje.substr( 0, '/' ));
                                            mjesec = std::stoi ( datum_prodaje.substr( 3, '/' ));
                                            if(godina-1000<0)
                                                throw;

                                        } catch(...) {
                                            try {
                                                godina = std::stoi ( datum_prodaje.substr( 5, 4 ));
                                                dan = std::stoi ( datum_prodaje.substr( 0, '/' ));
                                                mjesec = std::stoi ( datum_prodaje.substr( 2, '/' ));
                                                if(godina-1000<0)
                                                    throw;
                                            }

                                            catch(...) {
                                                godina = std::stoi ( datum_prodaje.substr( 4, 4 ));
                                                dan = std::stoi ( datum_prodaje.substr( 0, '/' ));
                                                mjesec = std::stoi ( datum_prodaje.substr( 2, '/' ));

                                            }
                                        }

                                    }
                                    Datum D1(dan,mjesec,godina);
                                    cout<<"Odaberite kupca. Dostupni kupci su:"<<endl;

                                    int indeks_kupca;
                                    for(int i=0; i<stanovi.size(); i++) {
                                        cout<<" "<<i+1<<" - ";
                                        kupci[i].Ispisi();
                                    }
                                    cin >> indeks_kupca;

                                    cout<<"Odaberite stan. Dostupni stanovi su:"<<endl;
                                    int indeks_stana;
                                    for(int i=0; i<stanovi.size(); i++) {
                                        cout<<" "<<i+1<<" - ";
                                        stanovi[i].Ispisi();
                                    }
                                    cin >> indeks_stana;
                                    prodaja.RegistrirajProdaju(ime_agenta,cijena_stana,D1,kupci[indeks_kupca-1],stanovi[indeks_stana-1]);

                                }

                            }  catch(std::logic_error e) {
                                izuzetak=true;
                                cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;
                            }
                        } while(izuzetak);
                        if(opcija!=3) cout<<"Prodaja uspjesno dodana!"<<endl;
                    
                    }}
                }
            }
        }
    }



    cout<<endl<<endl<<endl<<"Dovidjenja!";
    return 0;
}
