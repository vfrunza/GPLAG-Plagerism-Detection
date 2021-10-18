/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <string>
#include <iomanip>

class Datum
{
    int Dan, Mjesec, Godina;

    friend class Pregled;
    int DajDan() const {
        return Dan;
    }
    int DajMjesec() const {
        return Mjesec;
    }
    int DajGodinu() const {
        return Godina;
    }

public:

    Datum (int dan, int mjesec, int godina) {
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
        if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
            throw std::domain_error ("Neispravan datum");
        Dan=dan;
        Mjesec=mjesec;
        Godina=godina;
    }

    void Postavi (int dan, int mjesec, int godina) {
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
        if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
            throw std::domain_error ("Neispravan datum");
        Dan=dan;
        Mjesec=mjesec;
        Godina=godina;
    }

    std::tuple<int, int, int> Ocitaj() const {
        std::tuple<int, int, int> t;
        t=std::make_tuple(Dan, Mjesec, Godina);
        return t;
    }

    void Ispisi() const {
        std::cout<<Dan<<"/"<<Mjesec<<"/"<<Godina;
    }
};

class Vrijeme
{
    friend class Pregled;

    int Sati, Minute;

    int DajSate() const {
        return Sati;
    }

    int DajMinute() const {
        return Minute;
    }

public:

    Vrijeme(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59)
            throw std::domain_error ("Neispravno vrijeme");
        Sati=sati;
        Minute=minute;
    }

    void Postavi(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59)
            throw std::domain_error ("Neispravno vrijeme");
        Sati=sati;
        Minute=minute;
    }

    std::pair<int, int> Ocitaj() const {
        std::pair<int, int> p;
        p=std::make_pair(Sati, Minute);
        return p;
    }

    void Ispisi() const {
        std::cout<<Sati<<":"<<Minute;
    }
};

class Pregled
{
    std::string Ime_Pacijenta;
    Datum Datum_Pregleda;
    Vrijeme Vrijeme_Pregleda;

public:

    Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);

    Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);

    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Ime_Pacijenta=ime_pacijenta;
    }

    void PromijeniDatum(const Datum &novi_datum) {
        Datum_Pregleda=novi_datum;
    }

    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        Vrijeme_Pregleda=novo_vrijeme;
    }

    void PomjeriDanUnaprijed() {
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        std::tuple<int, int, int> Datum(Datum_Pregleda.Ocitaj());
        int dan(std::get<0>(Datum)), mjesec(std::get<1>(Datum)), godina(std::get<2>(Datum));
        if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
        dan++;
        if(dan>broj_dana[mjesec-1]) {
            dan=1;
            mjesec++;;
        }
        if(mjesec>12) {
            mjesec=1;
            godina++;
        }
        Datum_Pregleda.Postavi(dan, mjesec, godina);
    }

    void PomjeriDanUnazad() {
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        std::tuple<int, int, int> Datum(Datum_Pregleda.Ocitaj());
        int dan(std::get<0>(Datum)), mjesec(std::get<1>(Datum)), godina(std::get<2>(Datum));
        if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
        dan--;
        if(dan<1) {
            dan=broj_dana[mjesec-1];
            mjesec--;
        }
        if(mjesec<0) {
            mjesec=12;
            godina--;
        }
        Datum_Pregleda.Postavi(dan, mjesec, godina);
    }

    std::string DajImePacijenta() const {
        return Ime_Pacijenta;
    }

    Datum DajDatumPregleda() const {
        return Datum_Pregleda;
    }

    Vrijeme DajVrijemePregleda() const {
        return Vrijeme_Pregleda;
    }

    static bool DolaziPrije (const Pregled &p1, const Pregled &p2) {
        Datum d1(p1.DajDatumPregleda()), d2(p2.DajDatumPregleda());
        Vrijeme v1(p1.DajVrijemePregleda()), v2(p2.DajVrijemePregleda());

        if(d1.DajGodinu()<d2.DajGodinu())
            return true;
        else if(d1.DajGodinu()>d2.DajGodinu())
            return false;

        if(d1.DajMjesec()<d2.DajMjesec())
            return true;
        else if(d1.DajMjesec()>d2.DajMjesec())
            return false;

        if(d1.DajDan()<d2.DajDan())
            return true;
        else if(d1.DajDan()>d2.DajDan())
            return false;

        if(v1.DajSate()<v2.DajSate())
            return true;
        else if(v1.DajSate()>v2.DajSate())
            return false;

        if(v1.DajMinute()<v2.DajMinute())
            return true;
        else return false;
    }

    void Ispisi() const {
        std::tuple<int, int, int> Datum(Datum_Pregleda.Ocitaj());
        int dan(std::get<0>(Datum)), mjesec(std::get<1>(Datum)), godina(std::get<2>(Datum));
        std::pair<int, int> Vrijeme(Vrijeme_Pregleda.Ocitaj());
        int sati(std::get<0>(Vrijeme)), minute(std::get<1>(Vrijeme));

        std::cout<<std::setw(30)<<Ime_Pacijenta<<" "<<dan<<"/"<<mjesec<<"/"<<godina<<" "<<sati<<":"<<minute<<std::endl;
    }
};

Pregled::Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):
    Ime_Pacijenta(ime_pacijenta),
    Datum_Pregleda(datum_pregleda),
    Vrijeme_Pregleda(vrijeme_pregleda)
{
}

Pregled::Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):
    Ime_Pacijenta(ime_pacijenta),
    Datum_Pregleda(Datum(dan_pregleda, mjesec_pregleda, godina_pregleda)),
    Vrijeme_Pregleda(Vrijeme(sati_pregleda,minute_pregleda))
{
}

class Pregledi
{

};

int main ()
{
    return 0;
}
