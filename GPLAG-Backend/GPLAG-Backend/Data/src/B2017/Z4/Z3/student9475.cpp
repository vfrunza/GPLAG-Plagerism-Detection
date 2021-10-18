/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <utility>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <algorithm>

class Datum    //Zavrseno
{
    int dan, mjesec, godina;
    void TestDatuma(int dan, int mjesec, int godina) {
        int dani[12] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina%4==0 && godina%100!=0 && godina%400==0) dani[1]++;
        if(mjesec<1 || mjesec>12 || dan<1 || dan>dani[mjesec-1] || godina<1) throw std::domain_error("Neispravan datum");
    }
public:
    Datum(int dan, int mjesec, int godina) {
        TestDatuma(dan,mjesec,godina);
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Postavi(int dan, int mjesec, int godina) {
        TestDatuma(dan,mjesec,godina);
        Datum::dan=dan;
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    std::tuple<int, int, int> Ocitaj() const {
        return std::tie(dan,mjesec,godina);
    }
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

class Vrijeme    //Zavrseno
{
    int sati, minute;
public:
    Vrijeme(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    void Postavi(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    std::pair<int, int> Ocitaj () const {
        return {sati,minute};
    }
    void Ispisi() const {
        if(sati/10==0) std::cout << "0" << sati << ":";
        else std::cout << sati << ":";
        if(minute/10==0) std::cout << "0" << minute;
        else std::cout << minute;
    }
};

class Pregled    //Zavrseno
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) :
        datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda), vrijeme_pregleda(sati_pregleda,minute_pregleda) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        datum_pregleda=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_pregleda=novo_vrijeme;
    }

    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();

    std::string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const {
        return datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme_pregleda;
    }

    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);

    void Ispisi() const {
        std::cout << std::left << std::setw(30) << ime_pacijenta;
        datum_pregleda.Ispisi();
        std::cout << " ";
        vrijeme_pregleda.Ispisi();
        std::cout << std::endl;
    }
};

class Pregledi
{
    Pregled **pregledi {};
    int max_broj_pregleda;
    int broj_registriranih;
public:
    explicit Pregledi(int max_broj_pregleda) {
        Pregledi::max_broj_pregleda=max_broj_pregleda;
        broj_registriranih=0;
        pregledi=new Pregled*[max_broj_pregleda] {};
    }
    Pregledi(std::initializer_list<Pregled> spisak_pregleda) {
        if(spisak_pregleda.size()>max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        broj_registriranih=spisak_pregleda.size();
        pregledi=new Pregled*[max_broj_pregleda] {};
        auto it(spisak_pregleda.begin());
        for(int i=0; i<max_broj_pregleda; i++) {
            (*pregledi)[i]=*it;
        }
    }
    ~Pregledi() {
        for(int i=0; i<max_broj_pregleda; i++) delete pregledi[i];
        delete[] pregledi;
    }

    Pregledi(const Pregledi &p);
    Pregledi(Pregledi &&p);
    Pregledi &operator =(const Pregledi &p);
    Pregledi &operator =(Pregledi &&pi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *p);

    int DajBrojPregleda() const {
        return broj_registriranih;
    }

    int DajBrojPregledaNaDatum(const Datum &datum) const;        //Zavrseno
    Pregled &DajNajranijiPregled();                              //Zavrseno
    Pregled DajNajranijiPregled() const;                        //Zavrseno

    void IsprazniKolekciju() {
        for(int i=0; i<max_broj_pregleda; i++) delete pregledi[i];
        delete[] pregledi;
        pregledi=nullptr;                                       //Upitno
    }

    void ObrisiNajranijiPregled();                              //Zavrseno
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

void Pregled::PomjeriDanUnaprijed()
{
    std::tuple<int,int,int> datum(datum_pregleda.Ocitaj());
    int dan(std::get<0>(datum)+1), mjesec(std::get<1>(datum)), godina(std::get<2>(datum));
    int dani[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && godina%100!=0 && godina%400==0) dani[1]++;
    if(dan==dani[mjesec-1]+1) {
        dan=1;
        mjesec++;
        if(mjesec==13) {
            mjesec=1;
            godina++;
        }
    }
    datum_pregleda.Postavi(dan,mjesec,godina);
}

void Pregled::PomjeriDanUnazad()
{
    std::tuple<int,int,int> datum(datum_pregleda.Ocitaj());
    int dan(std::get<0>(datum)-1), mjesec(std::get<1>(datum)), godina(std::get<2>(datum));
    int dani[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && godina%100!=0 && godina%400==0) dani[1]++;
    if(dan==0) {
        mjesec--;
        if(mjesec>0) dan=dani[mjesec-1];
        else if(mjesec==0) {
            godina--;
            if(godina<0) throw std::domain_error("Neispravan datum");
            mjesec=12;
            dan=31;
        }
    }
    datum_pregleda.Postavi(dan,mjesec,godina);
}

bool DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    std::tuple<int,int,int> dat1(p1.DajDatumPregleda().Ocitaj()), dat2(p2.DajDatumPregleda().Ocitaj());
    if(std::get<2>(dat1)<std::get<2>(dat2)) return true;
    else if(std::get<1>(dat1)<std::get<1>(dat2)) return true;
    else if(std::get<0>(dat1)<std::get<0>(dat2)) return true;
    return false;
}

Pregledi::Pregledi(const Pregledi &p) ::pregledi(new Pregled*[p.max_broj_pregleda] {}),
         max_broj_pregleda(p.max_broj_pregleda), broj_registriranih(p.broj_registriranih)
{
    try {
        for(int i=0; i<p.broj_registriranih; i++) {
            pregledi[i]=new Pregled[*p.pregledi[i]];
        }
    } catch(...) {
        for(int i=0; i<p.broj_registriranih; i++) delete pregledi[i];
        delete[] pregledi;
        throw;
    }
}

Pregledi::Pregledi(Pregledi &&p) : pregledi(p.pregledi), max_broj_pregleda(p.max_broj_pregleda), broj_registriranih(p.broj_registriranih)
{
    p.pregledi=nullptr;
    p.broj_registriranih=0;
}

Pregledi &Pregledi::operator =(const Pregledi &p)
{
    if(p.max_broj_pregleda!=max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    if(p.broj_registriranih>broj_registriranih) {
        try {
            for(int i=broj_registriranih; i<broj_registriranih; i++)
                pregledi[i]=new Pregled(*p.pregledi[i]);
        } catch(...) {
            for(int i=broj_registriranih; i<r.broj_registriranih; i++) {
                delete pregledi[i];
                pregledi[i]=nullptr;
            }
            throw;
        }
    } else {
        for(int i=p.broj_registriranih; i<broj_registriranih; i++) {
            delete pregledi[i];
            pregledi[i]=nullptr;
        }
    }
    broj_registriranih=p.broj_registriranih;
    for(int i=0; i<broj_registriranih; i++) *pregledi[i]=*p.pregledi[i];
    return *this;

}

Pregledi &Pregledi::operator =(Pregledi &&p)
{
    if(p.max_broj_pregleda!=max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    std::swap(broj_registriranih, p.broj_registriranih);
    std::swap(pregledi, p.pregledi);
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) 
{
    if(broj_registriranih>=max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    Pregled *p=new Pregled()
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    
}
void Pregledi::RegistrirajPregled(Pregled *pregled);

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    std::tuple<int,int,int> dat1(datum.Ocitaj());
    int br_zakazanih_pregleda;
    br_zakazanih_pregleda=std::count_if(*pregledi,*pregledi+broj_registriranih, [dat1](Pregled pregled) {
        std::tuple<int,int,int> dat2(pregled.DajDatumPregleda().Ocitaj());
        if(std::get<0>(dat1)==std::get<0>(dat2) && std::get<1>(dat1)==std::get<1>(dat2) &&std::get<2>(dat1)==std::get<2>(dat2)) return true;
        return false;
    });
    return br_zakazanih_pregleda;
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if(max_broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    Pregled *pregled=std::min_element(*pregledi,*pregledi+max_broj_pregleda, [](Pregled p1, Pregled p2) {
        std::tuple<int,int,int> dat1(p1.DajDatumPregleda().Ocitaj());
        std::tuple<int,int,int> dat2(p2.DajDatumPregleda().Ocitaj());
        if(std::get<2>(dat1)<std::get<2>(dat2)) return true;
        else if(std::get<1>(dat1)<std::get<1>(dat2)) return true;
        else if(std::get<0>(dat1)<std::get<0>(dat2)) return true;
        return false;
    });

    return *pregled;
}

Pregled Pregledi::DajNajranijiPregled() const
{
    if(broj_registriranih==0) throw std::domain_error("Nema registriranih pregleda");
    Pregled *pregled=std::min_element(*pregledi,*pregledi+broj_registriranih, [](Pregled p1, Pregled p2) {
        std::tuple<int,int,int> dat1(p1.DajDatumPregleda().Ocitaj());
        std::tuple<int,int,int> dat2(p2.DajDatumPregleda().Ocitaj());
        if(std::get<2>(dat1)<std::get<2>(dat2)) return true;
        else if(std::get<1>(dat1)<std::get<1>(dat2)) return true;
        else if(std::get<0>(dat1)<std::get<0>(dat2)) return true;
        return false;
    });

    return *pregled;
}

void Pregledi::ObrisiNajranijiPregled()
{
    if(broj_registriranih==0) throw std::range_error("Prazna kolekcija");
    Pregled **pregled(new Pregled*[max_broj_pregleda] {});
    Pregled najraniji_pregled(DajNajranijiPregled());
    std::tuple<int,int,int> dat1(najraniji_pregled.DajDatumPregleda().Ocitaj());
    std::pair<int, int> vr1(najraniji_pregled.DajVrijemePregleda().Ocitaj());
    int indeks(0);
    for(int i=0; i<broj_registriranih; i++) {
        bool isti_datum(false), isto_vrijeme(false);
        std::tuple<int,int,int> dat2(pregledi[indeks]->DajDatumPregleda().Ocitaj());
        std::pair<int, int> vr2(pregledi[indeks]->DajVrijemePregleda().Ocitaj());

        if(std::get<0>(dat1)==std::get<0>(dat2) && std::get<1>(dat1)==std::get<1>(dat2) &&std::get<2>(dat1)==std::get<2>(dat2)) isti_datum=true;
        if(vr1.first==vr2.first && vr1.second==vr2.second) isto_vrijeme=true;
        if(najraniji_pregled.DajImePacijenta()!=pregled[indeks]->DajImePacijenta() || !isti_datum || !isto_vrijeme)  {
            pregled[indeks]=new Pregled(pregledi[i]->DajImePacijenta(), pregledi[i]->DajDatumPregleda(), pregledi[i]->DajVrijemePregleda());     //Kriticno
            indeks++;
        }
    }
    for(int i=0; i<max_broj_pregleda; i++) delete pregledi[i];
    delete pregledi;

    pregledi=pregled;
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    int isto_ime(0);
    for(int i=0; i<broj_registriranih; i++) {
        if(pregledi[i]->DajImePacijenta()==ime_pacijenta) isto_ime++;
    }

    Pregled **pregled(new Pregled*[isto_ime] {});
    int indeks=0;
    for(int i=0; i<broj_registriranih; i++) {
        if(pregledi[i]->DajImePacijenta()!=ime_pacijenta)  {
            pregled[indeks]=new Pregled(pregledi[i]->DajImePacijenta(), pregledi[i]->DajDatumPregleda(), pregledi[i]->DajVrijemePregleda());     //Kriticno
            indeks++;
        }
    }
    for(int i=0; i<max_broj_pregleda; i++) delete pregledi[i];
    delete pregledi;

    pregledi=pregled;
}

void IspisiPregledeNaDatum(const Datum &datum) const
{


}

void IspisiSvePreglede() const
{

}

int main ()
{
    return 0;
}
