/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <utility>
#include <memory>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <iterator>

class Datum
{
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    };
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj () const {
        return std::make_tuple(dan, mjesec, godina);
    };
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    };
};

class Vrijeme
{
    int sati,minute;
public:
    Vrijeme(int sati, int minute) {
        Postavi(sati,minute);
    };
    void Postavi(int sati, int minute) {
        if(sati < 0 || minute < 0 || sati > 23 || minute > 59 ) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati = sati;
        Vrijeme::minute = minute;
    };
    std::pair<int, int> Ocitaj () const {
        return std::make_pair(sati, minute);
    };
    void Ispisi() const {
        if(sati<10) std::cout << "0" ;
        std::cout<<sati<<":";
        if(minute<10) std::cout << "0" ;
        std::cout<<minute;
    };
};

class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):
        ime_pacijenta(ime_pacijenta), datum_pregleda(std::get<0>(datum_pregleda.Ocitaj()),std::get<1>(datum_pregleda.Ocitaj()),std::get<2>(datum_pregleda.Ocitaj())),
        vrijeme_pregleda(std::get<0>(vrijeme_pregleda.Ocitaj()),std::get<1>(vrijeme_pregleda.Ocitaj())) {};
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):
        ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda) {};
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta = ime_pacijenta;
    };
    void PromijeniDatum(const Datum &novi_datum) {
        datum_pregleda.Postavi(std::get<0>(novi_datum.Ocitaj()),std::get<1>(novi_datum.Ocitaj()),std::get<2>(novi_datum.Ocitaj()));
    };
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_pregleda.Postavi(novo_vrijeme.Ocitaj().first,novo_vrijeme.Ocitaj().second);
    };
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const {
        return ime_pacijenta;
    };
    Datum DajDatumPregleda() const {
        return datum_pregleda;
    };
    Vrijeme DajVrijemePregleda() const {
        return vrijeme_pregleda;
    };
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};

class Pregledi
{
    Pregled **pr;
    int broj_pregleda;
    int max_broj_pregleda;

public:
    explicit Pregledi(int max_broj_pregleda) :pr(new Pregled*[max_broj_pregleda] {}), broj_pregleda(0) , max_broj_pregleda(max_broj_pregleda) {};
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const {
        return broj_pregleda;
    };
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;

};
Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda):broj_pregleda(spisak_pregleda.size()), max_broj_pregleda(spisak_pregleda.size())
{
    pr = nullptr;
    try {
        pr = new Pregled*[max_broj_pregleda];
        for (int i = 0; i < max_broj_pregleda; i++) pr[i] = nullptr;

        int i(0);
        for (auto it = spisak_pregleda.begin(); it != spisak_pregleda.end(); it++) {
            *(pr+i) = new Pregled(*it);
            i++;
        }
    } catch(...) {
        for(int i=0; i<broj_pregleda; i++) delete pr[i];
        delete [] pr;
        throw;
    }
}
Pregledi::~Pregledi()
{
    for(int i=0 ; i<broj_pregleda ; i++) delete pr[i];
    delete[] pr;

}
Pregledi::Pregledi(const Pregledi &pregledi): pr(new Pregled*[pregledi.max_broj_pregleda] {}),  broj_pregleda(pregledi.broj_pregleda), max_broj_pregleda(pregledi.max_broj_pregleda)
{
    try {
        for(int i=0 ; i<broj_pregleda ; i++)
            pr[i]= new Pregled(*pregledi.pr[i]);
    } catch(...) {
        for(int i=0 ; i<pregledi.broj_pregleda ; i++) delete pr[i];
        delete[] pr;
        throw;
    }

}
Pregledi::Pregledi(Pregledi &&pregledi): pr(pregledi.pr), broj_pregleda(pregledi.broj_pregleda), max_broj_pregleda(pregledi.max_broj_pregleda)
{
    pregledi.pr = nullptr;
}
Pregledi &Pregledi::operator =(const Pregledi &pregledi)
{
    if(pregledi.broj_pregleda > broj_pregleda) {
        try {
            for(int i = broj_pregleda ; i < pregledi.broj_pregleda ; i++)
                pr[i] = new Pregled(*pregledi.pr[i]);
        } catch(...) {
            for(int i = broj_pregleda ; i < pregledi.broj_pregleda ; i++) {
                delete pr[i];
                pr = nullptr;
            }
            throw;
        }
    } else {
        for(int i = pregledi.broj_pregleda ; i < broj_pregleda ; i++) {
            delete pr[i] ;
            pr = nullptr;
        }
    }
    broj_pregleda=pregledi.broj_pregleda;
    for(int i = 0 ; i < broj_pregleda ; i++) *pr[i] = *pregledi.pr[i];
    return *this;
}
Pregledi &Pregledi::operator =(Pregledi &&pregledi)
{
    if(&pregledi != this) {
        for(int i=0 ; i<pregledi.broj_pregleda ; i++) delete pr[i];
        delete[] pr;
        max_broj_pregleda = pregledi.max_broj_pregleda;
        broj_pregleda = pregledi.broj_pregleda;
        for(int i=0 ; i<pregledi.broj_pregleda ; i++) pregledi.pr[i] = nullptr;
        pregledi.pr = nullptr;
    }
    return *this;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    if(broj_pregleda >= max_broj_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
    Pregled *pregled(nullptr);
    try {
        pregled = new Pregled(ime_pacijenta,datum_pregleda, vrijeme_pregleda);
    } catch(...) {
        delete pregled;
        throw;
    }
    pr[broj_pregleda++] = pregled;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    if(broj_pregleda >= max_broj_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
    Pregled *pregled(nullptr);
    try {
        pregled = new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    } catch(...) {
        delete pregled;
        throw;
    }
    pr[broj_pregleda++] = pregled;
}
void Pregledi::RegistrirajPregled(Pregled *pregled)
{
    if(broj_pregleda >= max_broj_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
    pr[broj_pregleda++] = pregled;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{

    int br(std::count_if(pr, pr+broj_pregleda, [datum] (Pregled * preg) {
        if(std::get<0>(preg->DajDatumPregleda().Ocitaj())==std::get<0>(datum.Ocitaj()) && std::get<1>(preg->DajDatumPregleda().Ocitaj())==std::get<1>(datum.Ocitaj()) &&
                std::get<2>(preg->DajDatumPregleda().Ocitaj())==std::get<2>(datum.Ocitaj())) return true;
        return false;
    }));
    if(br==0) throw std::domain_error ("Nema registriranih pregleda");
    return br;
}
Pregled &Pregledi::DajNajranijiPregled()
{
    if(broj_pregleda==0) throw std::domain_error ("Nema registriranih pregleda");
    return *(*(std::min_element(pr, pr+broj_pregleda, [](Pregled *p1, Pregled *p2) {
        return Pregled::DolaziPrije(*p1,*p2);
    })));

}
Pregled Pregledi::DajNajranijiPregled() const
{
    if(broj_pregleda==0) throw std::domain_error ("Nema registriranih pregleda");
    return *(*(std::min_element(pr, pr+broj_pregleda, [](Pregled *p1, Pregled *p2) {
        return Pregled::DolaziPrije(*p1,*p2);
    })));
}

void Pregledi::IsprazniKolekciju()
{
    for(int i = 0; i<broj_pregleda ; i++) pr[i] = nullptr;
    pr=nullptr;
    broj_pregleda=0;
}
void Pregledi::ObrisiNajranijiPregled()
{
    if(broj_pregleda==0) throw std::domain_error ("Prazna kolekcija");
    for(int i = 0 ; i< broj_pregleda; i++) {
        if(std::get<0>(pr[i]->DajDatumPregleda().Ocitaj()) == std::get<0>(this->DajNajranijiPregled().DajDatumPregleda().Ocitaj())
                && std::get<1>(pr[i]->DajDatumPregleda().Ocitaj()) == std::get<1>(this->DajNajranijiPregled().DajDatumPregleda().Ocitaj())
                && std::get<2>(pr[i]->DajDatumPregleda().Ocitaj()) == std::get<2>(this->DajNajranijiPregled().DajDatumPregleda().Ocitaj())) {
            for( int j = i ; j< broj_pregleda-1 ; j++) {
                Pregled p(*(pr[j]));
                *pr[j]=*pr[j+1];
                *pr[j+1]=p;
            }

        }
    }
    delete pr[broj_pregleda-1];
    broj_pregleda --;
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    int br=0;
    for(int i = 0 ; i< broj_pregleda-br; i++) {
        if(pr[i]->DajImePacijenta()==ime_pacijenta) {
            for( int j = i ; j< broj_pregleda-1 ; j++) {
                Pregled p(*pr[j]);
                *pr[j]=*pr[j+1];
                *pr[j+1]=p;
            }
            br++;
        }
    }
    for(int i = broj_pregleda-1 ; i> broj_pregleda-br-1 ; i--) delete pr[i];
    broj_pregleda -= br;
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    Pregled** preg (nullptr);
    int j(0);
    try {
        preg = new Pregled*[broj_pregleda];
        for (int i = 0; i < broj_pregleda; i++) {
            if (std::get<0>(pr[i]->DajDatumPregleda().Ocitaj())==std::get<0>(datum.Ocitaj()) && std::get<1>(pr[i]->DajDatumPregleda().Ocitaj())==std::get<1>(datum.Ocitaj()) &&
                    std::get<2>(pr[i]->DajDatumPregleda().Ocitaj())==std::get<2>(datum.Ocitaj())) {
                preg[j] = new Pregled(pr[i]->DajImePacijenta(), pr[i]->DajDatumPregleda(), pr[i]->DajVrijemePregleda());
                j++;
            }
        }
        std::sort(preg, preg+j, [](Pregled* p1, Pregled* p2) {
            return Pregled::DolaziPrije(*p1, *p2);
        });
        for (int i = 0; i < j; i++) preg[i]->Ispisi();

        for (int i = 0; i < j; i++) delete preg[i];
        delete [] preg;
    } catch (...) {
        for (int i = 0; i < j; i++) delete preg[i];
        delete [] preg;
    }
}
void Pregledi::IspisiSvePreglede() const
{
    Pregled** pr1 (pr);
    std::sort(pr1, pr1+broj_pregleda, [](Pregled* p1, Pregled* p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    });
    for (int i = 0; i < broj_pregleda; i++) pr1[i]->Ispisi();
}
int main ()
{
    int n;
    std::cout<<"Unesite maksimalan broj pregleda: ";
    std::cin>>n;
    int br(0);
    Pregledi pregledi(n);
    while(1) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string ime;
        std::getline(std::cin, ime);
        if(ime=="kraj") break;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        int d, m, g;
        std::cin>>d >>m >>g;
        std::cout<<"Unesite sate i minute pregleda: ";
        int sat,min;
        std::cin>>sat >>min;
        try {
            pregledi.RegistrirajPregled(ime,d,m,g,sat,min);
        } catch(std::range_error e) {
            std::cout<<e.what();
        }
        br++;
        if(br==n) break;
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
    pregledi.IspisiSvePreglede();
    while(1) {
        std::cout<<std::endl<<"Odaberite jednu od sljedecih opcija"<<std::endl<<"1 - Broj pregleda na datum"<<std::endl<<"2 - Najraniji pregled"<<std::endl<<"3 - Obrisi pregled pacijenta"<<std::endl
                 <<"4 - Obrisi najraniji pregled"<<std::endl<<"5 - Ispisi sve pregleda na datum"<<std::endl<<"6 - Ispisi sve preglede"<<std::endl<<"7 - Kraj programa"<<std::endl;
        int a;
        std::cin>>a;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        if(a==5) {
            std::cout<<"Unesite dan mjesec i godinu : ";
            int d1, m1, g1;
            std::cin>>d1 >>m1 >>g1;
            std::cout<<"Pregledi na datum "<<d1<<" "<<m1<<" "<<g1<<" su:"<<std::endl;
            pregledi.IspisiPregledeNaDatum(Datum(d1, m1, g1));
            std::cout<<std::endl;
        }
        if(a==4) {
            try {
                pregledi.ObrisiNajranijiPregled();
                std::cout<<"Najraniji pregled uspjesno obrisan";
            } catch(std::domain_error e) {
                std::cout<<e.what();
            }
            std::cout<<std::endl;
        }
        if(a==3) {

            int b(pregledi.DajBrojPregleda());

            std::cout<<"Unesite ime pacijenta: ";
            std::string ime1;
            std::getline(std::cin, ime1);
            pregledi.ObrisiPregledePacijenta(ime1);
            int c(pregledi.DajBrojPregleda());
            std::cout<<"Uspjesno obrisano "<<b-c<<" pregleda";
            std::cout<<std::endl;

        }
        if(a==2) {
            try {
                std::cout<<"Najraniji pregled je:" <<std::endl;
                pregledi.DajNajranijiPregled().Ispisi();
            } catch(std::domain_error e) {
                std::cout<<e.what();
            }
            std::cout<<std::endl;
        }
        if(a==1) {
            std::cout<<"Unesite dan mjesec i godinu : ";
            int d1, m1, g1;
            std::cin>>d1 >>m1 >>g1;
            try {
                std::cout<<"Broj pregleda na datum "<<d1<<" "<<m1<<" "<<g1<<" je: "<<pregledi.DajBrojPregledaNaDatum(Datum(d1, m1, g1));
            } catch(std::domain_error e) {
                std::cout<<e.what();
            }
            std::cout<<std::endl;
        }
        if(a==7) break;
        if(a==6) {
            pregledi.IspisiSvePreglede();
            std::cout<<std::endl;
        }
    }
    return 0;
}
void Datum::Postavi(int dan, int mjesec, int godina)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}
void Pregled::PomjeriDanUnaprijed()
{
    int dan(std::get<0>(datum_pregleda.Ocitaj()));
    int mjesec(std::get<1>(datum_pregleda.Ocitaj()));
    int godina(std::get<2>(datum_pregleda.Ocitaj()));
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    dan++;
    if(dan>broj_dana[mjesec-1]) {
        dan=1;
        mjesec++;
    }
    if(mjesec>12) {
        mjesec=1;
        godina++;
    }
    this->datum_pregleda.Postavi(dan,mjesec,godina);
}
void Pregled::PomjeriDanUnazad()
{
    int dan(std::get<0>(datum_pregleda.Ocitaj()));
    int mjesec(std::get<1>(datum_pregleda.Ocitaj()));
    int godina(std::get<2>(datum_pregleda.Ocitaj()));
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    dan--;
    if(dan<1) {
        if(mjesec==1) dan=broj_dana[11];
        dan=broj_dana[mjesec-2];
        mjesec--;
    }
    if(mjesec<1) {
        mjesec = 12;
        godina--;
    }
    this->datum_pregleda.Postavi(dan,mjesec,godina);

}
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    int dan1(std::get<0>(p1.datum_pregleda.Ocitaj())), dan2(std::get<0>(p2.datum_pregleda.Ocitaj()));
    int mjesec1(std::get<1>(p1.datum_pregleda.Ocitaj())),mjesec2(std::get<1>(p2.datum_pregleda.Ocitaj()));
    int godina1(std::get<2>(p1.datum_pregleda.Ocitaj())),godina2(std::get<2>(p2.datum_pregleda.Ocitaj()));
    int s1(p1.vrijeme_pregleda.Ocitaj().first), s2(p2.vrijeme_pregleda.Ocitaj().first);
    int min1(p1.vrijeme_pregleda.Ocitaj().second), min2(p2.vrijeme_pregleda.Ocitaj().second);
    if(godina1<godina2 ) return true;
    if(godina1==godina2) {
        if(mjesec1<mjesec2 ) return true;
        if(mjesec1==mjesec2) {
            if(dan1<dan2 ) return true;
            if(dan1==dan2) {
                if(s1<s2 ) return true;
                if(s1==s2) {
                    if(min1<min2 ) return true;

                }

            }

        }
    }
    return false;
}
void Pregled::Ispisi() const
{
    std::cout << std::left << std::setw(30) << ime_pacijenta;
    datum_pregleda.Ispisi();
    std::cout << " ";
    vrijeme_pregleda.Ispisi();
    std::cout << std::endl;
}