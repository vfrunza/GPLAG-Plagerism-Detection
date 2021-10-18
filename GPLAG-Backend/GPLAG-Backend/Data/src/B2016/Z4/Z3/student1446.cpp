#include <iostream>
#include <stdexcept>
#include <string>
class Datum{
    int dan,mjesec,godina;
    public:
    Datum(int dan, int mjesec, int godina){
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const{
        return dan;
    }
    int DajMjesec() const{
        return mjesec;
    }
    int DajGodinu() const{
        return godina;
    }
    void Ispisi() const;
};
void Datum::Postavi(int dan, int mjesec, int godina){
    try{
    if(dan<0 || dan>31 || mjesec<0 || mjesec>12)throw std::domain_error ("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec;   Datum::godina=godina;
    }
    catch(std::domain_error greska){
        std::cout<<greska.what()<<std::endl;
    }
}
void Datum::Ispisi() const{
    std::cout<<dan<<"/"<<mjesec<<"/"<<godina<<std::endl;
}
class Vrijeme{
    int sati,minute;
    public:
    Vrijeme(int sati, int minute){
        Postavi(sati,minute);
    }
    void Postavi(int sati, int minute);
    int DajSate() const{
        return sati;
    }
    int DajMinute() const{
        return minute;
    }
    void Ispisi() const;
};
void Vrijeme::Postavi(int sati, int minute){
    try{
        if(sati<0 || sati>23 || minute<0 || minute>59)throw std::domain_error ("Neispravno vrijeme");
        Vrijeme::sati=sati; Vrijeme::minute=minute;
    }
     catch(std::domain_error greska){
        std::cout<<greska.what()<<std::endl;
    }
}
void Vrijeme::Ispisi()const{
    std::cout<<sati<<":"<<minute<<std::endl;
}
class Pregled{
    Datum d_p;
    Vrijeme v_p;
    std::string ime_pacijenta;
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
    const Vrijeme &vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta(const std::string &ime_pacijenta);
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    friend bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};
Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):d_p=datum_pregleda,v_p=vrijeme_pregleda{
        Pregled::ime_pacijenta=ime_pacijenta;
    }
int main() {
    std::cout<<"greska"<<std::endl;

    return 0;
}

