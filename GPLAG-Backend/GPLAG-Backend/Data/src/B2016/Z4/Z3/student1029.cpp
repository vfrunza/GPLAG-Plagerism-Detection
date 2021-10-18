/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;

bool ProvjeriDatum(int d,int m,int g)
{
    bool dobar_datum=true;

    if(g<1 || m<1 || m>12) dobar_datum=false;

    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) {
        if(d<1 || d>31) {
            dobar_datum=false;
        }
    }

    if(m==2) {
        if(g%4==0 && g%400==0 && g%100!=0) { //prestupna godina
            if(d<1 || d>29) {
                dobar_datum=false;
            }
        }

        else {
            if(d<1 || d>28) {
                dobar_datum=false;
            }
        }
    }

    if(m==4 || m==6 || m==9 || m==11) {
        if(d<1 || d>30) {
            dobar_datum=false;
        }
    }

    return dobar_datum;
}

class Datum
{
    int dan,mjesec,godina;
public:
    friend class Prodaja;
    friend class Prodaje;
    Datum (int dan, int mjesec, int godina) {
        if(ProvjeriDatum(dan,mjesec,godina)==false) throw std::domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Postavi(int dan,int mjesec, int godina) {
        if(ProvjeriDatum(dan,mjesec,godina)==false) throw std::domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
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
        cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
    friend class Kupac;
};

bool ProvjeriImeiPrezime(string s)
{
    bool dobra_rijec=true;
    for(int i=0; i<s.size(); i++) {
        if(s[i]!='-' || s[i]!=' ' || s[i]!=39 || s[i]<'0' || s[i]>'9' || s[i]<'a' || s[i]>'z' || s[i]<'A' || s[i]>'Z') {
            dobra_rijec=false;
            break;
        }
    }

    return dobra_rijec;
}

class Kupac
{
    string ime_i_prezime;
    Datum datum_rodjenja;
public:
    friend class Prodaja;
    friend class Prodaje;
    Kupac(const string &ime_i_prezime , const Datum &datum_rodjenja):
        datum_rodjenja(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu()) {
        if(ProvjeriImeiPrezime(ime_i_prezime)==false) throw std::domain_error("Neispravno ime i prezime");
        Kupac::ime_i_prezime=ime_i_prezime;
        Kupac::datum_rodjenja=datum_rodjenja;
    }

    void Postavi(const string &ime_i_prezime, const Datum &datum_rodjenja) {
        if(ProvjeriDatum(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu())==false) throw std::domain_error("Neispravan datum");
        if(ProvjeriImeiPrezime(ime_i_prezime)==false) throw std::domain_error("Neispravno ime i prezime");
        Kupac::ime_i_prezime=ime_i_prezime;
        Kupac::datum_rodjenja=datum_rodjenja;
    }

    string DajImePrezime() const {
        return ime_i_prezime;
    }

    Datum DajDatumRodjenja() const {
        return datum_rodjenja;
    }

    void Ispisi() const {
        cout<<ime_i_prezime<<"("<<datum_rodjenja.DajDan()<<"/"<<datum_rodjenja.DajMjesec()<<"/"<<datum_rodjenja.DajGodinu()<<")";
    }
    friend class Datum;
};

class Stan
{
    string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
public:
    friend class Prodaja;
    friend class Prodaje;
    Stan (const string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka.");
        if(namjesten!=0 || namjesten!=1) throw std::domain_error("Neispravan unos podataka.");
        Stan::adresa=adresa;
        Stan::sprat=sprat;
        Stan::broj_soba=broj_soba;
        Stan::namjesten=namjesten;
        Stan::kvadratura=kvadratura;
    }
    void Postavi(const string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka.");
        if(namjesten!=0 || namjesten!=1) throw std::domain_error("Neispravan unos podataka.");
        Stan::adresa=adresa;
        Stan::sprat=sprat;
        Stan::broj_soba=broj_soba;
        Stan::namjesten=namjesten;
        Stan::kvadratura=kvadratura;
    }
    string DajAdresu() const {
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

    void Ispisi() const {
        cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba();
        int n=DajBrojSoba();
        if(n==1) cout<<" sobu.";
        if(n>=5) cout<<" soba.";
        if(n>1 && n<5) cout<<" sobe.";
        cout<<endl<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan "<<DajNamjesten()<<" namjesten.";
    }
};

class Prodaja
{
    string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
public:
    friend class Prodaja;
    friend class Datum;
    friend class Kupac;
    friend class Prodaje;
    Prodaja(const string &ime_agenta_prodaje , double cijena_stana, const Datum &datum_prodaje , const Kupac &kupac_stana, const Stan &kupljeni_stan):
        datum_prodaje(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()),
        kupac_stana(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja()),
        kupljeni_stan(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu()) {
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
        Prodaja::cijena_stana=cijena_stana;
    }

    Prodaja (const string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje , int mjesec_prodaje, int godina_prodaje,
             string &ime_kupca, const Datum &datum_rodjenja_kupca , const string &adresa_stana, int sprat_stana, int broj_soba ,
             bool namjesten_stan, double broj_kvadrata):
        datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),
        kupac_stana(ime_kupca,datum_rodjenja_kupca),
        kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) {
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
        Prodaja::cijena_stana=cijena_stana;
    }

    void PromijeniKupca (const Kupac &novi_kupac) {
        kupac_stana.ime_i_prezime=novi_kupac.ime_i_prezime;
        kupac_stana.datum_rodjenja.dan=novi_kupac.datum_rodjenja.dan;
        kupac_stana.datum_rodjenja.mjesec=novi_kupac.datum_rodjenja.mjesec;
        kupac_stana.datum_rodjenja.godina=novi_kupac.datum_rodjenja.godina;
    }

    void PromijeniStan (const Stan &novi_stan) {
        kupljeni_stan.adresa=novi_stan.adresa;
        kupljeni_stan.sprat=novi_stan.sprat;
        kupljeni_stan.broj_soba=novi_stan.broj_soba;
        kupljeni_stan.namjesten=novi_stan.namjesten;
        kupljeni_stan.kvadratura=novi_stan.kvadratura;
    }

    void PromijeniDatumKupovine (const Datum &novi_datum) {
        datum_prodaje.dan=novi_datum.dan;
        datum_prodaje.mjesec=novi_datum.mjesec;
        datum_prodaje.godina=novi_datum.godina;
    }

    void PromijeniCijenuProdaje (const double &nova_cijena) {
        cijena_stana=nova_cijena;
    }

    void PomjeriDanUnaprijed() {
        datum_prodaje.dan++;
        int dani_u_mj[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
        if(datum_prodaje.godina%4==0 && datum_prodaje.godina%400==0 && datum_prodaje.godina%100!=0) dani_u_mj[1]++;
        if(datum_prodaje.dan>dani_u_mj[datum_prodaje.mjesec-1]) {
            datum_prodaje.dan-=dani_u_mj[datum_prodaje.mjesec-1];
            datum_prodaje.mjesec++;
        }
        if(datum_prodaje.mjesec>12) {
            datum_prodaje.mjesec=1;
            datum_prodaje.godina++;
        }
        ProvjeriDatum(datum_prodaje.dan, datum_prodaje.mjesec, datum_prodaje.godina);
    }

    void PomjeriDanUnazad() {
        datum_prodaje.dan--;
        int dani_u_mj[12]= {31,28,31,30,31,300,31,31,30,32,30,31};
        if(datum_prodaje.godina%4==0 && datum_prodaje.godina%400==0 && datum_prodaje.godina%100!=0) dani_u_mj[1]++;
        if(datum_prodaje.dan<1) {
            datum_prodaje.dan=dani_u_mj[datum_prodaje.mjesec-2]-datum_prodaje.dan;
            datum_prodaje.mjesec--;
        }
        if(datum_prodaje.mjesec<1) {
            datum_prodaje.mjesec=12;
            datum_prodaje.godina--;
        }
        ProvjeriDatum(datum_prodaje.dan,datum_prodaje.mjesec,datum_prodaje.godina);
    }

    string DajImeAgenta() const {
        return ime_agenta_prodaje;
    }

    string DajImeKupca() const {
        return kupac_stana.ime_i_prezime;
    }

    Datum DajDatumProdaje() const {
        return datum_prodaje;
    }

    double DajCijenuStana() const {
        return cijena_stana;
    }

    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
        if(p1.datum_prodaje.godina<p2.datum_prodaje.godina) return true;
        if(p1.datum_prodaje.godina==p2.datum_prodaje.godina) {
            if(p1.datum_prodaje.mjesec<p2.datum_prodaje.mjesec) return true;
            if(p1.datum_prodaje.mjesec==p2.datum_prodaje.mjesec) {
                if(p1.datum_prodaje.dan<p2.datum_prodaje.dan) return true;
            }
        } else return false;
    }

    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
        if(p1.cijena_stana>p2.cijena_stana) return true;
        else return false;
    }

    void Ispisi() const {
        cout<<"Ime agenta: "<<setprecision(10)<<DajImeAgenta()<<endl;
        cout<<"Ime kupca: "<<setprecision(10)<<DajImeKupca()<<endl;
        cout<<"Zakazani datum prodaje: "<<endl;
        cout<<"Cijena stana: "<<endl;
        cout<<"Informacije o stanu: "<<endl;
        cout<<"Stan se nalazi na adresi "<<kupljeni_stan.DajAdresu()<<" na "<<kupljeni_stan.DajSprat()<<". spratu i ima "<<kupljeni_stan.DajBrojSoba();
        int n=kupljeni_stan.DajBrojSoba();
        if(n==1) cout<<" sobu.";
        if(n>=5) cout<<" soba.";
        if(n>1 && n<5) cout<<" sobe.";
        cout<<endl<<"Kvadratura stana je "<<kupljeni_stan.DajKvadraturu()<<" (m^2) i stan "<<kupljeni_stan.DajNamjesten()<<" namjesten.";
    }

};

class Prodaje
{
    int stanje, kapacitet;
    Prodaja **pok;
public:
    explicit Prodaje(int max_broj_prodaja) {
        kapacitet=max_broj_prodaja;
        stanje=0;
        pok= new Prodaja *[max_broj_prodaja];
    }
    /*    Prodaje(std::initializer_list<Prodaja> spisak_prodaja) {
            int i=0;
            pok=new Prodaja *[spisak_prodaja.end()-spisak_prodaja.begin()];
            for(auto it=spisak_prodaja.begin(); it<spisak_prodaja.end(); ) {
                pok[i]=*it;
                i++;
                it++;
            }
        } */

    ~Prodaje() {
        for(int i=0; i<stanje; i++) delete pok[i];
        delete[] pok;
    }

    Prodaje(const Prodaje &prodaje) {
        stanje=prodaje.stanje;
        kapacitet=prodaje.kapacitet;
        pok=new Prodaja *[prodaje.kapacitet];
        for(int i=0; i<stanje; i++) {
            pok[i]=new Prodaja (*prodaje.pok[i]);
        }
    }

    Prodaje(Prodaje &&prodaje) {
        stanje=prodaje.stanje;
        kapacitet=prodaje.kapacitet;
        pok=prodaje.pok;
        prodaje.pok=nullptr;
        prodaje.stanje=0;
    }

    Prodaje &operator = (const Prodaje &prodaje) {
        if(pok==prodaje.pok) return *this; //da nema rekurzije
        for(int i=0; i<prodaje.stanje; i++) delete prodaje.pok[i];
        delete[] prodaje.pok;
        stanje=prodaje.stanje;
        kapacitet=prodaje.kapacitet;
        pok=new Prodaja *[prodaje.kapacitet];
        for(int i=0; i<stanje; i++) {
            pok[i]= new Prodaja (*prodaje.pok[i]);
        }
        return *this;
    }

    Prodaje &operator = (Prodaje &&prodaje) {
        if(pok==prodaje.pok) return *this;
        for(int i=0; i<prodaje.stanje; i++) delete prodaje.pok[i];
        delete[] prodaje.pok;
        stanje=prodaje.stanje;
        kapacitet=prodaje.kapacitet;
        pok=prodaje.pok;
        prodaje.pok=nullptr;
        prodaje.stanje=0;
        return *this;
    }

    friend class Datum;
    friend class Kupac;
    friend class Stan;
    friend class Prodaja;

    /*   void RegistrirajProdaju(const string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,const Kupac &kupac_stana, const Stan &kupljeni_stan):

       {

       } */



};


int main ()
{
    cout<<"Dobrodosli!"<<endl;
    cout<<"Izaberite opciju:"<<endl;
    cout<<" 0 - kraj"<<endl<<" 1 - uredjivanje stanova"<<endl<<" 2 - uredjivanje kupaca"<<endl<<" 3 - uredjivanje prodaja";
    int unos;
    cout<<endl;
    cin>>unos;
    if(unos==0) return 0;
    if(unos==1) {
            cout<<"Izaberite opciju:"<<endl;
            cout<<" 0 - nazad"<<endl<<" 1 - dodavanje stanova"<<endl<<" 2 - uredjivanje stanova"<<endl<<" 3 - ispis svih stanova"<<endl<<" 4 - kraj"<<endl;
            int a;
            cin>>a;
            if(a==1) {
                bool dobar_unos;
                do {
                    dobar_unos=true;
                    cout<<"Unesite adresu: ";
                    string adresa;
                    cin.ignore(1000,'\n');
                    getline(cin,adresa);
                    cout<<"Unesite sprat: ";
                    int sprat;
                    cin>>sprat;
                    cout<<"Unesite broj soba: ";
                    int broj_soba;
                    cin>>broj_soba;
                    cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                    int namjesten;
                    cin>>namjesten;
                    cout<<"Unesite kvadraturu: ";
                    double kvadratura;
                    cin>>kvadratura;
                    try {
                        Stan novi(adresa,sprat,broj_soba,namjesten,kvadratura);
                        dobar_unos=true;
                        cout<<"Stan je uspjesno dodan!";
                    } catch(std::domain_error izuzetak) {
                        dobar_unos=false;
                        cout<<"Izuzetak: "<<izuzetak.what()<<" Molimo unesite opet."<<endl;
                    }
                } while(dobar_unos==false);
            }
        }
        return 0;
    }