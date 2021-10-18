//PROVJERITI KADA SAM GET KORISTIO ZA TUPLE NEGDJE SAM POMJESAO SATE I MINUTE
#include <iostream>
#include <tuple>
#include <utility>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <vector>

class Datum
{
    int dan,mjesec,godina;
    public:
        Datum(int dan, int mjesec, int godina);
        void Postavi(int dan, int mjesec, int godina);
        std::tuple<int, int, int> Ocitaj() const { return std::make_tuple(dan,mjesec,godina); };
        void Ispisi() const;
};
class Vrijeme
{
    int sati,minute;
    public:
        Vrijeme(int sati, int minute);
        void Postavi(int sati, int minute);
        std::pair<int, int> Ocitaj () const { return std::make_pair(sati,minute); };
        void Ispisi() const;
};
class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    public:
        Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
        Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
        void PromijeniPacijenta(const std::string &ime_pacijenta) { Pregled::ime_pacijenta=ime_pacijenta; }
        void PromijeniDatum(const Datum &novi_datum) { Pregled::datum_pregleda=novi_datum; }
        void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { Pregled::vrijeme_pregleda=novo_vrijeme; }
        void PomjeriDanUnaprijed();
        void PomjeriDanUnazad();
        std::string DajImePacijenta() const{return ime_pacijenta;}
        Datum DajDatumPregleda() const{return datum_pregleda;}
        Vrijeme DajVrijemePregleda() const{return vrijeme_pregleda;}
        static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
        void Ispisi() const;
};

class Pregledi
{
    std::vector<std::shared_ptr<Pregled>> p;
    void Brisi();
    public:
        explicit Pregledi() :  p(0) {}
        Pregledi(std::initializer_list<Pregled> spisak_pregleda);
        //~Pregledi() {for(int i=0;i<br_pregleda;i++) delete (*(p+i)); delete[] p;}
        Pregledi(const Pregledi &pregledi);
        Pregledi(Pregledi &&pregledi);
        Pregledi &operator =(const Pregledi &pregledi);
        Pregledi &operator =(Pregledi &&pregledi);
        void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
        void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
        void RegistrirajPregled(std::shared_ptr<Pregled> pregled);
        int DajBrojPregleda() const {return p.size();}
        int DajBrojPregledaNaDatum(const Datum &datum) const;
        Pregled &DajNajranijiPregled();
        Pregled DajNajranijiPregled() const;
        void IsprazniKolekciju(){p.clear();};
        void ObrisiNajranijiPregled();
        void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
        void IspisiPregledeNaDatum(const Datum &datum) const;
        void IspisiSvePreglede() const;
};
/************************************DATUM*************************************/
Datum::Datum(int d, int m, int g)
{
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++;
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1])
        throw std::domain_error("Neispravan datum");
    dan = d; mjesec = m; godina = g;
}
void Datum::Postavi(int d, int m, int g)
{
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0)  || g % 400 == 0) broj_dana[1]++;
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1])
        throw std::domain_error("Neispravan datum");
    dan = d; mjesec = m; godina = g;
}
void Datum::Ispisi() const 
{
    std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
}
/******************************************************************************/

/**********************************VRIJEME*************************************/
Vrijeme::Vrijeme(int s, int m)
{
    if(s < 0 || s > 23 || m < 0 || m > 59) throw std::domain_error("Neispravno vrijeme");
    sati = s; minute = m;
}
void Vrijeme::Postavi(int s, int m)
{
    if(s < 0 || s > 23 || m < 0 || m > 59) throw std::domain_error("Neispravno vrijeme");
    sati = s; minute = m;
}
void Vrijeme::Ispisi() const
{
    std::cout<<std::setfill('0');
    std::cout<<std::right<<std::setw(2)<<sati<<":"<<std::setw(2)<<minute;
    std::cout<<std::setfill(' ');
}
/******************************************************************************/

/**********************************PREGLED*************************************/
Pregled::Pregled(const std::string &ip, const Datum &dp, const Vrijeme &vp) : ime_pacijenta(ip), datum_pregleda(dp), vrijeme_pregleda(vp)
{
}
Pregled::Pregled(const std::string &ip, int dp, int mp, int gp, int sp, int minp) : ime_pacijenta(ip), datum_pregleda(Datum(dp,mp,gp)), vrijeme_pregleda(Vrijeme(sp,minp))
{
}
void Pregled::PomjeriDanUnazad()
{
    std::tuple<int, int, int> datum(datum_pregleda.Ocitaj());
    int d(std::get<0>(datum)),m(std::get<1>(datum)),g(std::get<2>(datum));
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0)  || g % 400 == 0) broj_dana[1]++;
    
    if(d>1) d--;
    else
    {
        if(m>1) 
        {
            m--;
            d=broj_dana[m-1];
        }
        else
        {
            g--;
            m=12;
            d=broj_dana[11];
        }
    }
    datum_pregleda.Postavi(d,m,g);
}
void Pregled::PomjeriDanUnaprijed()
{
    std::tuple<int, int, int> datum(datum_pregleda.Ocitaj());
    int d(std::get<0>(datum)),m(std::get<1>(datum)),g(std::get<2>(datum));
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0)  || g % 400 == 0) broj_dana[1]++;
    
    if(d<broj_dana[m-1]) d++;
    else
    {
        if(m<12) 
        {
            m++;
            d=1;
        }
        else
        {
            g++;
            m=1;
            d=1;
        }
    }
    datum_pregleda.Postavi(d,m,g);
}
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    auto d1(p1.datum_pregleda.Ocitaj());
    auto d2(p2.datum_pregleda.Ocitaj());
    auto v1(p1.vrijeme_pregleda.Ocitaj());
    auto v2(p2.vrijeme_pregleda.Ocitaj());
    int dan1(std::get<0>(d1)),mjesec1(std::get<1>(d1)),godina1(std::get<2>(d1));
    int dan2(std::get<0>(d2)),mjesec2(std::get<1>(d2)),godina2(std::get<2>(d2));
    int minute1(std::get<1>(v1)),sati1(std::get<0>(v1));
    int minute2(std::get<1>(v2)),sati2(std::get<0>(v2));
    if(godina1!=godina2) return godina1<godina2;
    if(mjesec1!=mjesec2) return mjesec1<mjesec2;
    if(dan1!=dan2) return dan1<dan2;
    if(sati1!=sati2) return sati1<sati2;
    if(minute1!=minute2) return minute1<minute2;
    return false;
}
void Pregled::Ispisi() const
{
    std::cout<<std::setw(30)<<std::left<<ime_pacijenta;
    datum_pregleda.Ispisi();
    std::cout<<" ";
    vrijeme_pregleda.Ispisi();
    std::cout<<std::endl;
}
/******************************************************************************/

/**********************************PREGLEDI************************************/
Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda): p(0)
{
    auto it=spisak_pregleda.begin();
    try
    {
        for(int i=0;i<spisak_pregleda.size();i++)
        {
            p.push_back(std::shared_ptr<Pregled>(new Pregled(*it)));
            it++;
        }
    }
    catch(...)
    {
        p.clear();
    }
}
Pregledi::Pregledi(const Pregledi &pregledi) : p(0)
{
    try
    {
        for(int i=0;i<pregledi.p.size();i++)
        {
            p.push_back(std::shared_ptr<Pregled>(new Pregled(*pregledi.p.at(i))));
        }
    }
    catch(...)
    {
        p.clear();
    }
}
Pregledi::Pregledi(Pregledi &&pregledi) : p(pregledi.p)
{
    pregledi.p.clear();
}
Pregledi &Pregledi::operator=(const Pregledi &pregledi)
{
    p.clear();
    for(int i=0;i<pregledi.p.size();i++)
    {
        p.push_back(std::shared_ptr<Pregled>(new Pregled(*pregledi.p.at(i))));
    }
    return *this;
}
Pregledi &Pregledi::operator=(Pregledi &&pregledi)
{
    p=pregledi.p;
    pregledi.p.clear();
    return *this;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    p.push_back(std::shared_ptr<Pregled>(new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda)));
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    p.push_back(std::shared_ptr<Pregled>(new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda)));
}
void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled)
{
    p.push_back(pregled);
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    auto gl_datum=datum.Ocitaj();
    int n=std::count_if(p.begin(),p.end(),[&gl_datum](const std::shared_ptr<Pregled> pregled)
    {
        auto pr_datum=pregled->DajDatumPregleda().Ocitaj();
        return (std::get<0>(pr_datum)==std::get<0>(gl_datum) && std::get<1>(pr_datum)==std::get<1>(gl_datum) && std::get<2>(pr_datum)==std::get<2>(gl_datum));
    });
    return n;
}
Pregled &Pregledi::DajNajranijiPregled()
{
    if(p.size()==0) throw std::domain_error("Nema registriranih pregleda");
    auto pok = std::min_element(p.begin(),p.end(),[](const std::shared_ptr<Pregled> p1,const std::shared_ptr<Pregled> p2)
    {
        return Pregled::DolaziPrije(*p1,*p2);
    });
    return **pok;
}
Pregled Pregledi::DajNajranijiPregled() const
{
    if(p.size()==0) throw std::domain_error("Nema registriranih pregleda");
    auto pok = std::min_element(p.begin(),p.end(),[](const std::shared_ptr<Pregled> p1, const std::shared_ptr<Pregled> p2)
    {
        return Pregled::DolaziPrije(*p1,*p2);
    });
    Pregled pregled=**pok;
    return pregled;
}
void Pregledi::ObrisiNajranijiPregled()
{
    if(p.size()==0) throw std::range_error("Prazna kolekcija");
    auto pok = std::min_element(p.begin(),p.end(),[](const std::shared_ptr<Pregled> p1,const std::shared_ptr<Pregled> p2)
    {
        return Pregled::DolaziPrije(*p1,*p2);
    });
    for(int i=0;i<p.size();i++)
    {
        if(*pok == p[i])
        {
            for(int j=i;j<p.size()-1;j++)
            {
                p.at(j)=p.at(j+1);
            }
            p.resize(p.size()-1);
            break;
        }
    }
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    for(int i=0;i<p.size();i++)
    {
        if(p[i]->DajImePacijenta()==ime_pacijenta)
        {
            for(int j=i;j<p.size()-1;j++)
            {
                p.at(j)=p.at(j+1);
            }
            i--;
            p.resize(p.size()-1);
        }
    }
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{/*
    bool nasao(false);
    auto pok = std::min_element(p,p+br_pregleda,[&datum,&nasao](const Pregled *p1,const Pregled *p2)
    {
        auto datumm(datum.Ocitaj());
        int dan(std::get<0>(datumm)),mjesec(std::get<1>(datumm)),godina(std::get<2>(datumm));
        auto datum1(p1->DajDatumPregleda().Ocitaj());
        auto datum2(p2->DajDatumPregleda().Ocitaj());
        int dan1(std::get<0>(datum1)),mjesec1(std::get<1>(datum1)),godina1(std::get<2>(datum1));
        int dan2(std::get<0>(datum2)),mjesec2(std::get<1>(datum2)),godina2(std::get<2>(datum2));
        if(dan1==dan && mjesec1==mjesec && godina1==godina) 
        {
            nasao=true;
            if(dan2==dan && mjesec2==mjesec && godina2==godina) return Pregled::DolaziPrije(*p1,*p2);
            return true;
        }
        return false;
    });
    if(!nasao) return;
    (**pok).Ispisi();
    int n(DajBrojPregledaNaDatum(datum));
    for(int i=1;i<n;i++)
    {
        std::cout<<"_______________"<<std::endl;
        auto pok2 = std::min_element(p,p+br_pregleda,[pok,&nasao](const Pregled *p1,const Pregled *p2)
        {
            (*p1).Ispisi();
            (*p2).Ispisi();
            auto datumm((**pok).DajDatumPregleda().Ocitaj());
            int dan(std::get<0>(datumm)),mjesec(std::get<1>(datumm)),godina(std::get<2>(datumm));
            auto datum1(p1->DajDatumPregleda().Ocitaj());
            auto datum2(p2->DajDatumPregleda().Ocitaj());
            int dan1(std::get<0>(datum1)),mjesec1(std::get<1>(datum1)),godina1(std::get<2>(datum1));
            int dan2(std::get<0>(datum2)),mjesec2(std::get<1>(datum2)),godina2(std::get<2>(datum2));
            if(dan1==dan && mjesec1==mjesec && godina1==godina) 
            {
                if(dan2==dan && mjesec2==mjesec && godina2==godina) 
                {
                    if(Pregled::DolaziPrije(*p1,**pok)) {std::cout<<"CCCCCC"<<std::endl;return false;}
                    else
                    {
                        
                    }
                    if(Pregled::DolaziPrije(*p1,*p2)) {std::cout<<"BBBBB"<<std::endl;return true;}
                    else {std::cout<<"AAAAAA"<<std::endl; return false;}
                }
                std::cout<<"EEEEEE"<<std::endl;
                return true;
            }
            std::cout<<"DDDDDDD"<<std::endl;
            return false;
        });
        std::cout<<"_______________"<<std::endl;
        (**pok2).Ispisi();
        pok=pok2;
    }*/
    
    auto gl_datum(datum.Ocitaj());
    int gl_dan(std::get<0>(gl_datum)),gl_mjesec(std::get<1>(gl_datum)),gl_godina(std::get<2>(gl_datum));
    std::vector<std::shared_ptr<Pregled>> pomv;
    for(int i=0;i<p.size();i++)
    {
        auto datum(p.at(i)->DajDatumPregleda().Ocitaj());
        int dan(std::get<0>(datum)),mjesec(std::get<1>(datum)),godina(std::get<2>(datum));
        if(dan==gl_dan && mjesec==gl_mjesec && godina==gl_godina) pomv.push_back(p.at(i));
    }
    
    std::sort(pomv.begin(),pomv.end(),[](const std::shared_ptr<Pregled> pregled1, const std::shared_ptr<Pregled> pregled2)
    {
        return Pregled::DolaziPrije(*pregled1,*pregled2);
    });
    std::for_each(pomv.begin(),pomv.end(),[](const std::shared_ptr<Pregled> pregledi1){pregledi1->Ispisi();});
}
void Pregledi::IspisiSvePreglede() const
{
    auto pomv=p;
    std::sort(pomv.begin(),pomv.end(),[](const std::shared_ptr<Pregled> pregled1, const std::shared_ptr<Pregled> pregled2)
    {
        return Pregled::DolaziPrije(*pregled1,*pregled2);
    });
    std::for_each(pomv.begin(),pomv.end(),[](const std::shared_ptr<Pregled> pregledi1){pregledi1->Ispisi();});
}
/******************************************************************************/
int main ()
{
    Pregledi pregledi;
    while(true)
    {
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string ime;
        std::getline(std::cin,ime);
        if(ime=="kraj") break;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        int dan,mjesec,godina;
        std::cin>>dan>>mjesec>>godina;
        std::cout<<"Unesite sate i minute pregleda: ";
        int sati,minute;
        std::cin>>sati>>minute;
        std::getchar();
        std::shared_ptr<Pregled> pregled=std::shared_ptr<Pregled>(new Pregled(ime,dan,mjesec,godina,sati,minute));
        pregledi.RegistrirajPregled(pregled);
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
    pregledi.IspisiSvePreglede();
    while(true)
    {
        try
        {
            std::cout<<std::endl<<"Odaberite jednu od sljedecih opcija"<<std::endl;
            std::cout<<"1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n";
            int n;
            std::cin>>n;
            std::cin.ignore(10000, '\n');
            if(n==1) 
            {
                std::cout<<"Unesite dan mjesec i godinu : ";
                int dan,mjesec,godina;
                std::cin>>dan>>mjesec>>godina;
                std::cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je: "<<pregledi.DajBrojPregledaNaDatum({dan,mjesec,godina})<<std::endl;
            }
            if(n==2)
            {
                std::cout<<"Najraniji pregled je: "<<std::endl;
                pregledi.DajNajranijiPregled().Ispisi();
            }
            if(n==3)
            {
                int broj1(pregledi.DajBrojPregleda());
                std::cout<<"Unesite ime pacijenta: ";
                std::string ime;
                std::getline(std::cin,ime);
                pregledi.ObrisiPregledePacijenta(ime);
                int broj2(pregledi.DajBrojPregleda());
                std::cout<<"Uspjesno obrisano "<<broj1-broj2<<" pregleda"<<std::endl;
            }
            if(n==4)
            {
                pregledi.ObrisiNajranijiPregled();
                std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
            }
            if(n==5)
            {
                std::cout<<"Unesite dan mjesec i godinu : ";
                int dan,mjesec,godina;
                std::cin>>dan>>mjesec>>godina;
                std::cout<<"Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su:"<<std::endl;
                pregledi.IspisiPregledeNaDatum({dan,mjesec,godina});
            }
            if(n==6)
            {
                pregledi.IspisiSvePreglede();
            }
            if(n==7) break;
        }
        catch(std::domain_error izuzetak)
        {
            std::cout<<"IZUETAK: "<<izuzetak.what()<<std::endl;
        }
        catch(std::range_error izuzetak)
        {
            std::cout<<"IZUETAK: "<<izuzetak.what()<<std::endl;
        }
    }
    return 0;
}