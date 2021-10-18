/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <string>
#include <initializer_list>
#include <iomanip>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::get;

class Datum
{
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi() const;
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (godina % 4 == 0 && godina % 100 == 0 || godina % 400 == 0)
        broj_dana[1]++;
    if (dan < 1 || mjesec < 1 || mjesec > 12 ||godina < 1 || dan > broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum");
    Datum::dan=dan;
    Datum::mjesec=mjesec;
    Datum::godina=godina;
}

std::tuple<int, int, int> Datum::Ocitaj() const
{
    std::tuple<int, int, int> t;
    t=std::make_tuple(dan, mjesec, godina);
    return t;
}

void Datum::Ispisi() const
{
    cout<<dan<<"/"<<mjesec<<"/"<<godina;
}

class Vrijeme
{
    int sati, minute;
    public:
    Vrijeme(int sati, int minute) { Postavi(sati, minute); }
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj () const;
    void Ispisi() const;
    friend class Pregled;
};

void Vrijeme::Postavi(int sati, int minute)
{
    if (sati < 0 || sati > 23 || minute < 0 || minute > 59)
        throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati=sati;
    Vrijeme::minute=minute;
}

std::pair<int, int> Vrijeme::Ocitaj() const
{
    std::pair<int, int> p;
    p=std::make_pair(sati, minute);
    return p;
}

void Vrijeme::Ispisi() const
{
    if (sati<10)
        cout<<"0";
    cout<<sati<<":";
    if (minute<10)
        cout<<"0";
    cout<<minute;    
}
class Pregled
{
    string ime;
    Datum datum;
    Vrijeme vrijeme;
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):ime(ime_pacijenta), datum(datum_pregleda), vrijeme(vrijeme_pregleda){}
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):ime(ime_pacijenta),
     datum(Datum(dan_pregleda, mjesec_pregleda,godina_pregleda)), vrijeme(Vrijeme(sati_pregleda, minute_pregleda)){}
    void PromijeniPacijenta(const std::string &ime_pacijenta) { ime = ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum) { datum = novi_datum; }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { vrijeme = novo_vrijeme; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const { return ime; }
    Datum DajDatumPregleda() const { return datum; }
    Vrijeme DajVrijemePregleda() const { return vrijeme; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};

void Pregled::PomjeriDanUnaprijed()
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (get<2>(datum.Ocitaj()) % 4 == 0 && get<2>(datum.Ocitaj()) % 100 == 0 || get<2>(datum.Ocitaj()) % 400 == 0)
        broj_dana[1]++;
    int d;
    d=get<0>(datum.Ocitaj());
    d++;
    int m, g;
    m=get<1>(datum.Ocitaj());
    g=get<2>(datum.Ocitaj());
    if (d > broj_dana[m - 1])
    {
        d=1;
        m++;
        if (m > 12)
        {
            m=1;
            g++;
        }
    }
    datum.Postavi(d, m ,g);
}

void Pregled::PomjeriDanUnazad()
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (get<2>(datum.Ocitaj()) % 4 == 0 && get<2>(datum.Ocitaj()) % 100 == 0 || get<2>(datum.Ocitaj()) % 400 == 0)
        broj_dana[1]++;
    int d, m ,g;
    d=get<0>(datum.Ocitaj());
    m=get<1>(datum.Ocitaj());
    g=get<2>(datum.Ocitaj());
    d--;
    if (d < 1)
    {
        if (m==1)
        {
            d=broj_dana[11];
            m=12;
            g--;
        }
        else
        {
            d=broj_dana[m-2];
            m--;
        }
    }
    datum.Postavi(d, m, g);
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    Datum dat_1(p1.DajDatumPregleda()), dat_2(p2.DajDatumPregleda());
    Vrijeme vri_1(p1.DajVrijemePregleda()), vri_2(p2.DajVrijemePregleda());
    
   /* dat_1=p1.DajDatumPregleda();
    vri_1=p1.DajVrijemePregleda();
    
    dat_2=p2.DajDatumPregleda();
    vri_2=p2.DajVrijemePregleda();*/
    
    int dat1_d, dat1_m, dat1_g, dat2_d, dat2_m, dat2_g;
    dat1_d=get<0>(dat_1.Ocitaj());
    dat1_m=get<1>(dat_1.Ocitaj());
    dat1_g=get<2>(dat_1.Ocitaj());
    
    dat2_d=get<0>(dat_2.Ocitaj());
    dat2_m=get<1>(dat_2.Ocitaj());
    dat2_g=get<2>(dat_2.Ocitaj());
    
    int vri1_sat, vri1_min, vri2_sat, vri2_min;
    
    vri1_sat = vri_1.Ocitaj().first;
    vri1_min = vri_1.Ocitaj().second;
    
    vri2_sat = vri_2.Ocitaj().first;
    vri2_min = vri_2.Ocitaj().second;
    
    if (dat1_g < dat2_g)
        return true;
    else if (dat1_g > dat2_g)
        return false;
    else if(dat1_g == dat2_g)
    {
        if (dat1_m < dat2_m)
            return true;
        else if (dat1_m > dat2_m)
            return false;
        else if(dat1_m == dat2_m)
        {
            if (dat1_d < dat2_d)
                return true;
            else if (dat1_d > dat2_d)
                return false;
            else if(dat1_d == dat2_d)
            {
                if (vri1_sat < vri2_sat)
                    return true;
                else if (vri1_sat > vri2_sat)
                    return false;
                else if(vri1_sat == vri2_sat)
                {
                    if (vri1_min < vri2_min)
                        return true;
                    else if (vri1_min > vri2_min)
                        return false;
                    //else if(p1.vrijeme.minute==p2.vrijeme.minute)
                }
            }
        }
    }
}

void Pregled::Ispisi() const
{
    cout<<std::left<<std::setw(30)<<DajImePacijenta();
    DajDatumPregleda().Ispisi();
    cout<<" ";
    DajVrijemePregleda().Ispisi();
    cout<<"\n";
}


class Pregledi
{
    int max;
    Pregled **pok;
    public:
    explicit Pregledi(int max_broj_pregleda):max(max_broj_pregleda), pok(new Pregled*[max_broj_pregleda]{}) {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda):max(spisak_pregleda.size()), pok(new Pregled*[spisak_pregleda.size()]{})
{
    try
    {
        int i=0;
        for(Pregled neki:spisak_pregleda)
        {
            pok[i]=new Pregled(neki);
            i++;
        }
    }
    catch(...)
    {
        for(int i=0; i<spisak_pregleda.size(); i++)
            delete pok[i];
        delete[] pok;    
    }
}

Pregledi::~Pregledi()
{
    if (pok==nullptr)
        return;
    for(int i=0; i<max; i++)
        delete pok[i];
    delete[] pok;    
}

Pregledi::Pregledi(const Pregledi &pregledi):max(pregledi.max)
{
    try
    {
        pok=new Pregled*[pregledi.max]{};
        for(int i=0; i<pregledi.max; i++)
            pok[i]=new Pregled(*(pregledi.pok[i]));
    }
    catch(...)
    {
        for(int i=0; i<pregledi.max; i++)
            delete pok[i];
        delete[] pok;    
    }
}

Pregledi::Pregledi(Pregledi &&pregledi):max(pregledi.max), pok(pregledi.pok)
{
    pregledi.pok=nullptr;
}

Pregledi &Pregledi::operator=(const Pregledi &pregledi)
{
    if (pregledi.max != max)
        throw std::logic_error("Nesaglasni kapaciteti");
    if (&pregledi!=this)
    {
        for(int i=0; i<max; i++)
            delete pok[i];
        delete[] pok ;
        
        pok=new Pregled*[pregledi.max]{};
        for(int i=0; i<pregledi.max; i++)
            pok[i]=new Pregled(*(pregledi.pok[i]));
    }
    return *this;
}

Pregledi &Pregledi::operator=(Pregledi &&pregledi)
{
    if (pregledi.max != max)
        throw std::logic_error("Nesaglasni kapaciteti");
    std::swap(pok, pregledi.pok);
    return *this;    
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    bool ima_mjesta=false;
    for(int i=0; i<max; i++)
        if(pok[i] == nullptr)
        {
            ima_mjesta=true;
            break;
        }
    if (ima_mjesta == false)
        throw std::range_error("Dostignut maksimalni broj pregleda");
    else
    {
        for(int i=0; i<max; i++)
            if (pok[i] == nullptr)
            {
                pok[i]= new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
                break;
            }
    }
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    bool ima_mjesta=false;
    for(int i=0; i<max; i++)
        if (pok[i] == nullptr)
        {
            ima_mjesta=true;
            break;
        }
    if (ima_mjesta == false)
        throw std::range_error("Dostignut maksimalni broj pregleda");
    else
    {
        for(int i=0; i<max; i++)
            if (pok[i] == nullptr)
            {
                pok[i]=new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
                break;
            }
    }
}

void Pregledi::RegistrirajPregled(Pregled *pregled)
{
    bool ima_mjesta=false;
    for(int i=0; i<max; i++)
        if (pok[i] == nullptr)
        {
            ima_mjesta=true;
            break;
        }
    if (ima_mjesta == false)
        throw std::range_error("Dostignut maksimalni broj pregleda");
    else
    {
        for(int i=0; i<max; i++)
            if (pok[i] == nullptr)
            {
                pok[i]= pregled;
                break;
            }
    }
}

int Pregledi::DajBrojPregleda() const
{
    int brojac(0);
    for(int i=0; i<max; i++)
    {
        if (pok[i] == nullptr)
            continue;
        brojac++;    
    }
    return brojac;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    int br=DajBrojPregleda();
    return std::count_if(pok, pok + br, [datum] (Pregled *p1)
    {
        return p1->DajDatumPregleda().Ocitaj()==datum.Ocitaj();
    });
}

Pregled &Pregledi::DajNajranijiPregled()
{
    int br=DajBrojPregleda();
    if (br == 0)
        throw std::domain_error("Nema registriranih pregleda");
    auto p=std::min_element(pok, pok+br, [](Pregled *p1, Pregled *p2)
    {
        if(!p1)
            return false;
        if(!p2)
            return true;
        return Pregled::DolaziPrije(*p1, *p2); /////UPITNIK
    });
    return **p;
}


Pregled Pregledi::DajNajranijiPregled() const
{
    int br=DajBrojPregleda();
    if (br == 0)
        throw std::domain_error("Nema registriranih pregleda");
     auto p=std::min_element(pok, pok+br, [](Pregled *p1, Pregled *p2)
    {
        if(!p1)
            return false;
        if(!p2)
            return true;
        return Pregled::DolaziPrije(*p1, *p2); /////UPITNIK
    }); 
    return **p;
}

void Pregledi::IsprazniKolekciju()
{
    if (pok == nullptr)
        return;
    for(int i=0; i<max; i++)
    {
        delete pok[i];
        pok[i]=nullptr;
    }    
    delete[] pok;
    pok=nullptr;
}

void Pregledi::ObrisiNajranijiPregled()
{
    int br=DajBrojPregleda();
    if (br == 0)
        throw std::range_error("Prazna kolekcija");    
    Pregled &rani=DajNajranijiPregled();
    for(int i=0; i<max; i++)
    {
        if (pok[i] == nullptr)
            continue;
        else if (pok[i]== &rani)
        {
            delete pok[i];
            pok[i]=nullptr;
        }    
    }        
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    for(int i=0; i<max; i++)
    {
        if (pok[i] && pok[i]->DajImePacijenta() == ime_pacijenta)
        {
            delete pok[i];
            pok[i]=nullptr;
        }    
    }        
           
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    std::vector<Pregled*> vek;
    for(int i=0; i<max; i++)
    {
        if (pok[i] && pok[i]->DajDatumPregleda().Ocitaj() == datum.Ocitaj())
            vek.push_back(pok[i]);
            
    }
      std::sort(vek.begin(), vek.end(), [](Pregled *pok1, Pregled *pok2)
    {
        return Pregled::DolaziPrije(*pok1, *pok2);
    });
    for(int i=0; i<vek.size(); i++)
        vek[i]->Ispisi();
        
}

void Pregledi::IspisiSvePreglede() const
{
    std::vector<Pregled*> vek;
    for(int i=0; i<max; i++)
    {
        if (pok[i] == nullptr)
            continue;
        else
            vek.push_back(pok[i]);
    }
    std::sort(vek.begin(), vek.end(), [](Pregled *pok1, Pregled *pok2)
    {
        return Pregled::DolaziPrije(*pok1, *pok2);
    });
    for(int i=0; i<vek.size(); i++)
        vek[i]->Ispisi();
}

int main ()
{
    int max;
    cout<<"Unesite maksimalan broj pregleda: ";
    cin>>max;
    Pregledi p(max);
    for(int i=0; i<max; i++)
    {
        string pacijent, ispravnost;
        cout<<"Unesite ime novog pacijenta ili \'kraj\' za zavrsetak unosa: ";
        cin>>pacijent;
        ispravnost={"kraj"};
        if (pacijent == ispravnost)
            break;
        int dan, mjesec, godina;
        cout<<"Unesite dan mjesec i godinu pregleda: ";
        cin>>dan>>mjesec>>godina;
        cout<<"Unesite sate i minute pregleda: ";
        int sat, min;
        cin>>sat>>min;
        try
        {
        p.RegistrirajPregled(pacijent, dan, mjesec, godina, sat, min);
        }
        catch(std::range_error izuzetak)
        {
            cout<<izuzetak.what();
        }
    }
    cout<<"Trenutno su registrovani sljedeci pregledi\n";
    p.IspisiSvePreglede();
    while(1)
    {
        int odabir(0);
        cout<<"\nOdaberite jednu od sljedecih opcija\n";
        cout<<"1 - Broj pregleda na datum\n";
        cout<<"2 - Najraniji pregled\n";
        cout<<"3 - Obrisi pregled pacijenta\n";
        cout<<"4 - Obrisi najraniji pregled\n";
        cout<<"5 - Ispisi sve pregleda na datum\n";
        cout<<"6 - Ispisi sve preglede\n";
        cout<<"7 - Kraj programa\n";
        cin>>odabir;
        try
        {
            if (odabir == 7)
                break;
            if (odabir == 1) 
            {
                cout<<"Unesite dan mjesec i godinu : ";
                int dan, mjesec, godina;
                cin>>dan>>mjesec>>godina;
                cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je: "<<p.DajBrojPregledaNaDatum(Datum(dan,mjesec,godina))<<"\n";
            }
            else if(odabir == 2)
            {
                cout<<"Najraniji pregled je:\n";
                p.DajNajranijiPregled().Ispisi();
                
            }
            else if (odabir == 3)
            {
                string ime;
                int br1=p.DajBrojPregleda();
                cout<<"Unesite ime pacijenta: ";
                cin>>ime;
                p.ObrisiPregledePacijenta(ime);
                cout<<"Uspjesno obrisano "<<br1 - p.DajBrojPregleda()<<" pregleda\n";
            }
            else if(odabir == 4)
            {
              p.ObrisiNajranijiPregled();
              cout<<"Najraniji pregled uspjesno obrisan\n";
            }
            else if(odabir == 5)
            {
                int dan, mjesec, godina;
                cout<<"Unesite dan mjesec i godinu : ";
                cin>>dan>>mjesec>>godina;
                cout<<"Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su:\n";
                p.IspisiPregledeNaDatum(Datum(dan,mjesec,godina));
            }
            else if(odabir == 6)
            {
                p.IspisiSvePreglede();
            }
        }
        catch(std::exception izuzetak)
        {
            cout<<izuzetak.what();
        }
    }
	return 0;
}


