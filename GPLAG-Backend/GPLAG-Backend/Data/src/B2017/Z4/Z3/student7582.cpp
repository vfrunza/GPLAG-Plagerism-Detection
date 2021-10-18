#include <iostream>
#include <tuple>
#include <utility>
#include <stdexcept>
#include <string>
using namespace std;
class Datum{
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    tuple<int,int,int> Ocitaj() const;
    void Ispisi() const;
};
class Vrijeme{
    int sati, minute;
    public:
    Vrijeme(int sati, int minute);
    void Postavi(int sati, int minute);
    pair<int,int> Ocitaj() const;
    void Ispisi() const;
};
void Datum::Postavi(int dan, int mjesec, int godina){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 || godina%100!=0 || godina%400==0)
    broj_dana[1]++;
    if(godina<1 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1]) throw domain_error("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}
Datum::Datum(int dan, int mjesec, int godina){
    Postavi(dan,mjesec,godina);
}
tuple<int,int,int> Datum::Ocitaj() const{
    return make_tuple(dan,mjesec,godina);
}
void Datum::Ispisi() const{
    cout<<dan<<"/"<<mjesec<<"/"<<godina;
}
void Vrijeme::Postavi(int sati, int minute){
    if(sati<0 || sati>23 || minute<0 || minute>59) throw domain_error("Neispravno vrijeme");
    Vrijeme::sati=sati;
    Vrijeme::minute=minute;
}
Vrijeme::Vrijeme(int sati, int minute){
    Postavi(sati,minute);
}
pair<int,int> Vrijeme::Ocitaj() const{
    return {sati,minute};
}
void Vrijeme::Ispisi() const{
    cout<<sati<<":"<<minute;
}
class Pregled{
    string ime;
    Datum datum;
    Vrijeme vrijeme;
    public:
    Pregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    Pregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta(const string &ime_pacijenta);
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    string DajImePacijenta() const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};
Pregled::Pregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):ime(ime_pacijenta),datum(datum_pregleda),vrijeme(vrijeme_pregleda){}
Pregled::Pregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):datum(Datum(dan_pregleda, mjesec_pregleda, godina_pregleda)),vrijeme(Vrijeme(sati_pregleda, minute_pregleda)){
    ime=ime_pacijenta;
}
void Pregled::PromijeniPacijenta(const string &ime_pacijenta){
    ime=ime_pacijenta;
}
void Pregled::PromijeniDatum(const Datum &novi_datum){
    datum=novi_datum;
}
void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme){
    vrijeme=novo_vrijeme;
}
void Pregled::PomjeriDanUnaprijed(){
    tuple<int,int,int> t(datum.Ocitaj());
    datum.Postavi(get<0>(t)+1,get<1>(t),get<2>(t));
}
void Pregled::PomjeriDanUnazad(){
    tuple<int,int,int> t(datum.Ocitaj());
    datum.Postavi(get<0>(t)-1,get<1>(t),get<2>(t));
}
string Pregled::DajImePacijenta() const{
    return ime;
}
Datum Pregled::DajDatumPregleda() const{
    return datum;
}
Vrijeme Pregled::DajVrijemePregleda() const{
    return vrijeme;
}
/*bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2){
    if(p1.datum==p2.datum){
        if(p1.vrijeme.sati==p2.vrijeme.sati)
        return p1.vrijeme.minute<p2.vrijeme.minute;
        else return p1.vrijeme.sati<p2.vrijeme.sati;
    }
    else if(p1.datum.godina==p2.datum.godina){
        if(p1.datum.mjesec==p2.datum.mjesec){
            return p1.datum.dan<p2.datum.dan;
        }
        return p1.datum.mjesec<p2.datum.mjesec;
    }
    else return p1.datum.godina<p2.datum.godina;
}
void Ispisi() const{
    
}*/
int main ()
{
	return 0;
}
