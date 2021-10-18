/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <iomanip>
class Datum
{
    int dan, mjesec,godina;
public:
    Datum(int dan, int mjesec, int godina) {
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Postavi(int dan, int mjesec, int godina) {
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    std::tuple<int, int, int> Ocitaj() const {
        std::tuple<int,int,int> beze;
        beze=std::make_tuple(dan,mjesec,godina);
        return beze;
    }
    void Ispisi() const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }

};
class Vrijeme
{
    int sati,minute;
public:
    Vrijeme(int sati, int minute){
        Postavi(sati,minute);
    }
    void Postavi(int sati, int minute){
        if (sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    std::pair<int, int> Ocitaj () const{
        std::pair<int,int> beze;
        beze=std::make_pair(sati,minute);
        return beze;
    }
    void Ispisi() const{
        std::cout<<std::setw(2)<<std::setfill('0')<<sati<<":"<<std::setw(2)<<std::setfill('0')<<minute;
    }

};
class Pregled{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
private:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): Pregled::datum_pregleda(datum_pregleda), Pregled::vrijeme_pregleda(vrijeme_pregleda){
        Pregled::ime_pacijenta=ime_pacijenta;
    }
Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda): Pregled::ime_pacijenta(ime_pacijenta),Pregled::datum_pregleda(dan_pregleda,mjesec_pregleda),Pregled::vrijeme_pregleda(sati_pregleda,minute_pregleda){}
void PromijeniPacijenta(const std::string &ime_pacijenta){
    Pregled::ime_pacijenta=ime_pacijenta;
}
void PromijeniDatum(const Datum &novi_datum){
    Pregled::datum_pregleda=novi_datum;
}
void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
    Pregled::vrijeme_pregleda=novo_vrijeme;
}
void PomjeriDanUnaprijed(){
    
}
void PomjeriDanUnazad();
std::string DajImePacijenta() const{
    return ime_pacijenta;
}
Datum DajDatumPregleda() const{
    return datum_pregleda;
}
Vrijeme DajVrijemePregleda() const{
    return vrijeme_pregleda;
}
static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
    }
}
};
int main ()
{
    return 0;
}
