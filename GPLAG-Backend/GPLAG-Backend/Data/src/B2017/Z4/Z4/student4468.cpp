#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <initializer_list>
#include <memory>
#include <algorithm>
#include <vector>

class Datum
{
    int daan, mjeesec, goodina;
    
public:

    Datum (int dan, int mjesec, int godina) {
        Postavi(dan, mjesec, godina);
    }
    
    void Postavi (int dan, int mjesec, int godina);
    
    int DajDan () const {
        return daan;
    }
    
    int DajMjesec () const {
        return mjeesec;
    }
    
    int DajGodinu () const {
        return goodina;
    }
    
    void Ispisi () const {
        std::cout<< daan<< "/"<< mjeesec<< "/"<< goodina;
    }
};

class Vrijeme
{
    
    int sec, min;
    
public:

    Vrijeme (int sati, int minute) {
        Postavi(sati, minute);
    }
    
    void Postavi (int sati, int minute) {
        if (sati<0 || minute<0 || sati>23 || minute>59) 
        throw std::domain_error ("Neispravno vrijeme");
        sec=sati;
        min=minute;
    }
    
    int DajSate () const {
        return sec;
    }
    
    int DajMinute () const {
        return min;
    }
    
    void Ispisi () const {
        std::cout<< std::setfill('0')<< std::setw(2)<< std::right<< sec<< ":"<< std::setw(2)<< std::right<< std::setfill('0')<< min;
    }
};

class Pregled
{
    
    std::string ime;
    Datum pr;
    Vrijeme vr;
    
public:

    Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : ime(ime_pacijenta), pr(datum_pregleda.DajDan(),datum_pregleda.DajMjesec(),datum_pregleda.DajGodinu()),
        vr(vrijeme_pregleda.DajSate(),vrijeme_pregleda.DajMinute()) {}
        
    Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) :
        ime(ime_pacijenta), pr(dan_pregleda, mjesec_pregleda, godina_pregleda), vr(sati_pregleda, minute_pregleda) {}
        
    void PromijeniPacijenta (const std::string &ime_pacijenta) {
        ime=ime_pacijenta;
    }
    
    void PromijeniDatum (const Datum &novi_datum) {
        pr.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(), novi_datum.DajGodinu());
    }
    
    void PromijeniVrijeme (const Vrijeme &novo_vrijeme) {
        vr.Postavi(novo_vrijeme.DajSate(), novo_vrijeme.DajMinute());
    }
    
    void PomjeriDanUnaprijed ();
    
    void PomjeriDanUnazad ();
    
    std::string DajImePacijenta () const {
        return ime;
    }
    
    Datum DajDatumPregleda () const {
        return pr;
    }
    
    Vrijeme DajVrijemePregleda () const {
        return vr;
    }
    
    static bool DolaziPrije (const Pregled &p1, const Pregled &p2) ;
    
    void Ispisi () const;
};

class Pregledi
{
    std::vector<std::shared_ptr<Pregled>> pregl;
    
public:

    Pregledi()=default;
    Pregledi (const Pregledi &pregledi): pregl(pregledi.pregl.size()) {
        for(int i(0); i<pregledi.pregl.size(); i++)
            pregl[i]=std::make_shared<Pregled>(*pregledi.pregl[i]);
    }
    
    Pregledi(std::initializer_list<Pregled> spisak_pregleda) : pregl(spisak_pregleda.size()) {
        auto it(spisak_pregleda.begin());
        for(int i(0); i<pregl.size(); i++)
            pregl[i]=std::make_shared<Pregled>(*it++);
    }
    
    Pregledi (Pregledi &&pregledi)=default;
    Pregledi &operator=(const Pregledi &pregledi);
    Pregledi &operator=(Pregledi &&pregledi) = default;
    
    void RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    
    void RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    
    void RegistrirajPregled (std::shared_ptr<Pregled> pregled) ;
    
    int DajBrojPregleda () const {
        return pregl.size();
    }
    
    int DajBrojPregledaNaDatum (const Datum &datum) const {
        if(pregl.size()==0) throw std::domain_error ("Nema registriranih pregleda");
        auto kopija(pregl);
        return std::count_if(kopija.begin(), kopija.end(), [datum](const std::shared_ptr<Pregled> p1) {
            return (p1->DajDatumPregleda().DajDan()==datum.DajDan() && p1->DajDatumPregleda().DajMjesec()==datum.DajMjesec() && p1->DajDatumPregleda().DajGodinu()==datum.DajGodinu());
        });
    }
    
    Pregled &DajNajranijiPregled() ;
    Pregled DajNajranijiPregled() const;
    void IprazniKolekciju() {
        for(int i(0); i<pregl.size(); i++)
            pregl[i]=nullptr;
    }
    
    void ObrisiNajranijiPregled ();
    void ObrisiPregledePacijenta (const std::string &ime_pacijenta) ;
    void IspisiPregledeNaDatum (Datum &datum) const;
    void IspisiSvePreglede () const;
};

int main()
{
    
    try {
        try {
            int broj_pacijenata;
            std::cout<< "Unesite broj pacijenata: ";
            std::cin>> broj_pacijenata;
            Pregledi pregledi;
            for(int i(0); i<broj_pacijenata; i++) {
                std::cout<< "Unesi ime pacijenata: ";
                std::string ime;
                std::cin>> ime;
                std::cout<< "Unesi datum pregleda (d m g): "<< std::endl;
                int d, m, g;
                std::cin>> d>> m>> g;
                std::cout<< "Unesi vrijeme pregleda (h m): "<< std::endl;
                int h, min;
                std::cin>>h>>min;
                pregledi.RegistrirajPregled(ime, {d, m, g}, {h, min});
            }
            pregledi.IspisiSvePreglede();
        } catch(std::range_error izuzetak) {
            std::cout<<izuzetak.what();
        }
    } catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    }
    return 0;
}

void Datum::Postavi (int dan, int mjesec, int godina)
{
    int br_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) br_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>br_dana[mjesec-1])
        throw std::domain_error ("Neispravan datum");
    daan=dan;
    mjeesec=mjesec;
    goodina=godina;
}

void Pregled::PomjeriDanUnaprijed ()
{
    try {
        Datum dat(DajDatumPregleda());
        dat.Postavi(dat.DajDan()+1, dat.DajMjesec(), dat.DajGodinu());
        pr=dat;
    } catch(...) {
        try {
            Datum dat(DajDatumPregleda());
            dat.Postavi(1, dat.DajMjesec()+1, dat.DajGodinu());
            pr=dat;
        } catch(...) {
            Datum dat(DajDatumPregleda());
            dat.Postavi(1, 1, dat.DajGodinu()+1);
            pr=dat;
        }
    }

}

void Pregled::PomjeriDanUnazad ()
{
    try {
        Datum dat(DajDatumPregleda());
        dat.Postavi(dat.DajDan()-1, dat.DajMjesec(), dat.DajGodinu());
        pr=dat;
    } catch(...) {
        try {
            int br_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            Datum dat(DajDatumPregleda());
            if(dat.DajGodinu()%4==0 && (dat.DajGodinu()%100!=0 || dat.DajGodinu()%400==0)) br_dana[1]++;
            dat.Postavi(br_dana[dat.DajMjesec()-2], dat.DajMjesec()-1, dat.DajGodinu());
            pr=dat;
        } catch(...) {
            Datum dat(DajDatumPregleda());
            dat.Postavi(31, 12, dat.DajGodinu()-1);
            pr=dat;
        }
    }
}

bool DolaziPrije (const Pregled &p1, const Pregled &p2)
{
    if(p1.DajDatumPregleda().DajGodinu()<p2.DajDatumPregleda().DajGodinu())
        return true;
    if(p1.DajDatumPregleda().DajGodinu()==p2.DajDatumPregleda().DajGodinu()) {
        if(p1.DajDatumPregleda().DajMjesec()<p2.DajDatumPregleda().DajMjesec())
            return true;
        if(p1.DajDatumPregleda().DajMjesec()==p2.DajDatumPregleda().DajMjesec()) {
            if(p1.DajDatumPregleda().DajDan()<p2.DajDatumPregleda().DajDan())
                return true;
            if(p1.DajDatumPregleda().DajDan()==p2.DajDatumPregleda().DajDan()) {
                if(p1.DajVrijemePregleda().DajSate()<p2.DajVrijemePregleda().DajSate())
                    return true;
                if(p1.DajVrijemePregleda().DajSate()==p2.DajVrijemePregleda().DajSate()) {
                    if(p1.DajVrijemePregleda().DajMinute()<p2.DajVrijemePregleda().DajMinute())
                        return true;
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    return false;
}

void Pregled::Ispisi () const
{
    std::cout<< std::setw(30)<< std::setfill (' ')<< std::left<< ime;
    pr.Ispisi();
    std::cout<< " ";
    vr.Ispisi();
    std::cout<< std::endl;
}

Pregledi &Pregledi::operator=(const Pregledi &pregledi)
{
    pregl.resize(pregledi.pregl.size());
    for(int i(0); i<pregledi.pregl.size(); i++)
        pregl[i]=std::make_shared<Pregled>(*pregledi.pregl[i]);
    return *this;
} 

void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    std::shared_ptr<Pregled> pregled;
    pregled=std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    pregl.push_back(pregled);
}

void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    std::shared_ptr<Pregled> pregled;
    pregled=std::make_shared<Pregled>(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    pregl.push_back(pregled);
}

void Pregledi::RegistrirajPregled (std::shared_ptr<Pregled> pregled)
{
    std::shared_ptr<Pregled> pr(pregled);
    pregl.push_back(pr);
}

Pregled &Pregledi::DajNajranijiPregled ()
{
    if(pregl.size()==0)
        throw std::domain_error ("Nema registriranih pregleda");
    auto kopija(pregl);
    return **std::min_element(kopija.begin(), kopija.end(), [](const std::shared_ptr<Pregled> p1, const std::shared_ptr<Pregled> p2) {
        return DolaziPrije(*p1, *p2);
    });
}

Pregled Pregledi::DajNajranijiPregled () const
{
    if(pregl.size()==0)
        throw std::domain_error ("Nema registriranih pregleda");
    auto kopija(pregl);
    return **std::min_element(kopija.begin(), kopija.end(), [](const std::shared_ptr<Pregled> p1, const std::shared_ptr<Pregled> p2) {
        return DolaziPrije(*p1, *p2);
    });
}

void Pregledi::ObrisiNajranijiPregled ()
{
    if(pregl.size()==0)
        throw std::range_error ("Prazna kolekcija");
    for(int i(0); i<pregl.size(); i++) {
        if(pregl[i]->DajDatumPregleda().DajDan()==DajNajranijiPregled().DajDatumPregleda().DajDan() &&
                pregl[i]->DajDatumPregleda().DajMjesec()==DajNajranijiPregled().DajDatumPregleda().DajMjesec() &&
                pregl[i]->DajDatumPregleda().DajGodinu()==DajNajranijiPregled().DajDatumPregleda().DajGodinu()) {
            pregl[i]=nullptr;
            for(int j(i); j<pregl.size()-1; j++)
                pregl[j]=pregl[j+1];
        }
    }
}

void Pregledi::ObrisiPregledePacijenta (const std::string &ime_pacijenta)
{
    for(int i(0); i<pregl.size(); i++) {
        if(pregl[i]->DajImePacijenta()==ime_pacijenta) {
            pregl[i]=nullptr;
            for(int j(i); j<pregl.size()-1; j++)
                pregl[j]=pregl[j+1];
        }
    }
}

void Pregledi::IspisiPregledeNaDatum (Datum &datum) const
{
    auto kopija(pregl);
    std::sort(kopija.begin(), kopija.end(), [](std::shared_ptr<Pregled> v1, std::shared_ptr<Pregled> v2) {
        return DolaziPrije(*v1, *v2);
    });
    std::for_each(kopija.begin(), kopija.end(), [datum](const std::shared_ptr<Pregled> p) {
        if(p->DajDatumPregleda().DajDan()==datum.DajDan() &&
                p->DajDatumPregleda().DajMjesec()==datum.DajMjesec() &&
                p->DajDatumPregleda().DajGodinu()==datum.DajGodinu())
            p->Ispisi();
    });
}

void Pregledi::IspisiSvePreglede () const
{
    auto kopija(pregl);
    std::sort(kopija.begin(), kopija.end(), [](const std::shared_ptr<Pregled> p1, const std::shared_ptr<Pregled> p2) {
        return DolaziPrije(*p1, *p2);
    });
    for(int i(0); i<kopija.size(); i++)
        kopija[i]->Ispisi();
}
