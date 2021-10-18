/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <string>
#include <iomanip>
class Datum
{
    int d,mj,god;
public:
    Datum(int dan,int mjesec,int godina) {
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan,int mjesec,int godina);
    std::tuple<int,int,int>Ocitaj()const;
    void Ispisi()const {
        std::cout << d<< "/" <<mj<< "/"<<god;
    }
};
void Datum::Postavi(int dan,int mjesec,int godina)
{
    int br_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && godina%100!=0 || godina%400==0)br_dana[1]++;
    if(godina<1 || mjesec<1 || dan<1 || mjesec>12 || dan>br_dana[mjesec-1])throw std::domain_error("Neispravan datum");
    d=dan;
    mj=mjesec;
    god=godina;
}
std::tuple<int,int,int>Datum:: Ocitaj()const
{
    std::tuple<int,int,int>dmg;
    std::get<0>(dmg)=d;
    std::get<1>(dmg)=mj;
    std::get<2>(dmg)=god;
    return dmg;
}

class Vrijeme
{
    int h,min;
public:
    Vrijeme(int sati,int minute) {
        Postavi(sati,minute);
    }
    void Postavi(int sati,int minute);
    std::pair<int,int>Ocitaj()const;
    void Ispisi()const {
        std::cout<<std::setfill('0')<<std::setw(2)<<h<<":"<<std::setfill('0')<<std::setw(2)<<min;
    }
};
void Vrijeme::Postavi(int sati,int minute)
{
    if(minute<0 || minute>59 || sati<0 || sati>23)throw std::domain_error("Neispravno vrijeme");
    h=sati;
    min=minute;
}
std::pair<int,int>Vrijeme::Ocitaj()const
{
    std::pair<int,int>sm;
    sm.first=h;
    sm.second=min;
    return sm;
}

class Pregled
{
    std::string ime_pac;
    Datum dat;
    Vrijeme vr;
public:
    Pregled(const std::string &ime_pacijenta,const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda);
   Pregled(const std::string &ime_pacijenta,int dan_pregleda,int mjesec_pregleda,int godina_pregleda,int sati_pregleda,int minute_pregleda);
    void PromijeniPacijenta(const std::string &ime_pacijenta);
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;

};
Pregled::Pregled(const std::string &ime_pacijenta,const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda):ime_pac(ime_pacijenta),dat(datum_pregleda),vr(vrijeme_pregleda){}
Pregled::Pregled(const std::string &ime_pacijenta,int dan_pregleda,int mjesec_pregleda,int godina_pregleda,int sati_pregleda,int minute_pregleda):ime_pac(ime_pacijenta),dat({dan_pregleda,mjesec_pregleda,godina_pregleda}),vr({sati_pregleda,minute_pregleda}){}
void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta){ime_pac=ime_pacijenta;}
void Pregled::PromijeniDatum(const Datum &novi_datum){dat=novi_datum;}
void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme){vr=novo_vrijeme;}





int main ()
{
    return 0;
}
