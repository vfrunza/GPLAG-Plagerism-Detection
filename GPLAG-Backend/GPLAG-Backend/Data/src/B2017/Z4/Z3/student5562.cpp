/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <tuple>
using namespace std;

class Datum{
private:
    int d,m,g;
public:
    Datum(int dan=0, int mjesec=0, int godina=0) { 
        //if(???USLOV) throw domain_error("Neispravan datum");
        d=dan; m=mjesec; g=godina;}
    void Postavi(int dan, int mjesec, int godina){
        //if(???USLOV) throw domain_error("Neispravan datum");
        d=dan; m=mjesec; g=godina;
    }
    std::tuple<int, int, int> Ocitaj() const{
        return make_tuple(d,m,g);
    }
    void Ispisi() const{
        cout<<d<<"/"<<m<<"/"<<endl;
    }
};

class Vrijeme{
private:
    int s,m;
public:
    Vrijeme(int sati=0, int minute=0){
        if(sati<0 || sati>23 || minute<0 || minute>60) throw domain_error("Neispravno vrijeme");
        s=sati; m=minute;
    }
    void Postavi(int sati, int minute){
        if(sati<0 || sati>23 || minute<0 || minute>60) throw domain_error("Neispravno vrijeme");
        s=sati; m=minute;
    }
    std::pair<int, int> Ocitaj () const{
        return make_pair(s,m);
    }
    void Ispisi() const{
        cout<<s<<":"<<m<<endl;
    }
};

class Pregled{
private:
    string ime;
    Datum dat;
    Vrijeme vr;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda){
        ime=ime_pacijenta;
        dat=datum_pregleda;
        vr=vrijeme_pregleda;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda){
        ime=ime_pacijenta;
        dat=Datum(dan_pregleda,mjesec_pregleda,godina_pregleda);
        vr=Vrijeme(sati_pregleda,minute_pregleda);
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta){
        ime=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum){
        dat.Postavi(get<0>(novi_datum.Ocitaj()), get<1>(novi_datum.Ocitaj()),get<2>(novi_datum.Ocitaj()));
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
        vr.Postavi(novo_vrijeme.Ocitaj().first,novo_vrijeme.Ocitaj().second);
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const { return ime;}
    Datum DajDatumPregleda() const{return dat;}
    Vrijeme DajVrijemePregleda() const {return vr;}
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};


int main ()
{
	return 0;
}
