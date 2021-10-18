/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

using namespace std;


class Datum
{
    int dan,mjesec,godina;
public:
    Datum(int d, int m, int g);
    void Postavi(int d, int m, int g);
    int DajDan() const {
        return dan;
    }
    int DajMjesec() const {
        return mjesec;
    }
    int DajGodinu() const {
        return godina;
    }
    void Ispisi() const{
        cout<<DajDan()<<"/"<<DajMjesec()<<"/"<<DajGodinu();
    }
};

Datum::Datum(int d,int m,int g) //konstuktor klase datum//
{
    
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;
    if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0)
        broj_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1])
        throw domain_error("Neispravan datum!");
    dan = d;
    mjesec = m;
    godina = g;
}

void Datum::Postavi(int d,int m,int g)
{
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;
    if(g % 4 == 0 &&  g % 100 != 0 || g % 400 == 0)
        broj_dana[1]++;
    if(g < 1 || d < 1 || m < 1 || m > 12 || d> broj_dana[m-1] )
        throw domain_error("Neispravan datum!");
    this->dan = d;
    this->mjesec = m;
    this->godina = g;

}


/*
class Kupac
{
    string ime_i_prezime;
    Datum datum_rodjenja;
    public:
    Kupac(const string ime, const datum);
    ime(ime_i_prezime),datum(datum_rodjenja){};

    void Postavi(const string &ime_i_prezime, const Datum &datum_rodjenja);
    string DajImePrezime() const {
        return ime_i_prezime;
    }
    Datum DajDatumRodjenja() const {
        return datum_rodjenja;
    }
    void Ispisi() const {
        cout<<DajImePrezime()<<" "<<DajDan()<<"/"<<DajMjesec()<<"/"<<DajGodinu();
    }
};





/*
class Stan
{
    string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan(const string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura);
    void Postavi(const string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura);

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
        if(namjesten==true) return 1;
        return -1;
    }
    double DajKvadraturu() const {
        return kvadratura;
    }

    void Ispisi() const {
        cout<<"Stan se nalazi na adresi"<<DajAdresu()<<"na"<<DajSprat()<<"spratu i ima"<<DajBrojSoba()<<"soba."<<endl;
        if(DajNamjesten()==true)
            cout<<"Kvadratura stana je"<<DajKvadraturu()<<"m2 i stan je namjesten";
        else cout<<"Kvadratura stana je"<<DajKvadraturu()<<"m2 i stan nije namjesten";
    }
};

Stan::Stan(const string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura):
    adresa(adresa),sprat(sprat),broj_soba(broj_soba),namjesten(namjesten),kvadratura(kvadratura) {};

void Stan::Postavi(const string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura)
{
    if(sprat<=0) throw domain_error("Neispravan unos podataka");
    if(broj_soba<=0) throw domain_error("Neispravan unos podataka");
    if(kvadratura<=0) throw domain_error("Neispravan unos podataka");
    namjesten=false;
}




class Prodaja
{
    string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    int dan_prodaje;
    int mjesec_prodaje;
    int godina_prodaje;
    string ime_kupca;
    string adresa_stana;
    int sprat_stana;
    int broj_soba;
    bool namjesten_stan;
    double broj_kvadrata;

public:
    Prodaja(const string &ime_agenta_prodaje, double cijena_stana,
            const Datum &datum_prodaje, const Kupac &kupac_stana,
            const Stan &kupljeni_stan);
    Prodaja(const string &ime_agenta_prodaje, double cijena_stana,
            int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
            string &ime_kupca, const Datum &datum_rodjenja_kupca,
            const string &adresa_stana, int sprat_stana, int broj_soba,
            bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac);
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje(const double &nova_cijena);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    string DajImeAgenta() const {
        return ime_agenta_prodaje;
    }
    string DajImeKupca() const {
        return ime_kupca;
    }
    Datum DajDatumProdaje() const {
        return Datum datum_prodaje;
    }
    double DajCijenuStana() const {
        return cijena_stana;
    }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;

};

Prodaja::Prodaja(const string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan):
ime_agenta_prodaje(ime_agenta_prodaje),cijena_stana(cijena_stana),

Prodaja::Prodaja(const string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,string &ime_kupca, const Datum &datum_rodjenja_kupca,
            const string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata):
            ime_agenta_prodaje(ime_agenta_prodaje),cijena_stana(cijena_stana),dan_prodaje(dan_prodaje),mjesec_prodaje(mjesec_prodaje),godina_prodaje(godina_prodaje)
            ime_kupca(ime_kupca),adresa_stana(adresa_stana),sprat_stana(sprat_stana),broj_soba(broj_soba),namjesten_stan(namjesten_stan),broj_kvadrata(broj_kvadrata){};

void Prodaja::PromijeniKupca(const Kupac &novi_kupac)
{

}
void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena)
{

}
*/


int main ()
{
    int d,m,g;
    cin>>d>>m>>g;
    Datum b(d,m,g);
    b.Postavi(d,m,g);
    b.Ispisi();

    return 0;
}
