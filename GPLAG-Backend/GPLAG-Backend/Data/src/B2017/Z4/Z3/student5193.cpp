//PROVJERITI KADA SAM GET KORISTIO ZA TUPLE NEGDJE SAM POMJESAO SATE I MINUTE
#include <iostream>
#include <tuple>
#include <utility>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
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
    int max_broj_pregleda;
    int br_pregleda;
    Pregled** p;
    void Brisi();
    public:
        explicit Pregledi(int max_broj_pregleda) : max_broj_pregleda(max_broj_pregleda), br_pregleda(0), p(new Pregled*[max_broj_pregleda]){}
        Pregledi(std::initializer_list<Pregled> spisak_pregleda);
        ~Pregledi() {for(int i=0;i<br_pregleda;i++) delete (*(p+i)); delete[] p;}
        Pregledi(const Pregledi &pregledi);
        Pregledi(Pregledi &&pregledi);
        Pregledi &operator =(const Pregledi &pregledi);
        Pregledi &operator =(Pregledi &&pregledi);
        void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
        void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
        void RegistrirajPregled(Pregled *pregled);
        int DajBrojPregleda() const {return br_pregleda;}
        int DajBrojPregledaNaDatum(const Datum &datum) const;
        Pregled &DajNajranijiPregled();
        Pregled DajNajranijiPregled() const;
        void IsprazniKolekciju(){this->~Pregledi(); p=new Pregled*[max_broj_pregleda]; br_pregleda=0;};
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
Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda): max_broj_pregleda(spisak_pregleda.size()), br_pregleda(spisak_pregleda.size()), p(new Pregled*[spisak_pregleda.size()])
{
    auto it=spisak_pregleda.begin();
    try
    {
        for(int i=0;i<br_pregleda;i++)
        {
            *(p+i)=new Pregled(*it);
            it++;
        }
    }
    catch(...)
    {
        for(int i=0;i<br_pregleda;i++) delete p[i];
        delete[] p; throw;
    }
}
Pregledi::Pregledi(const Pregledi &pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda), br_pregleda(pregledi.br_pregleda), p(new Pregled*[pregledi.max_broj_pregleda])
{
    try
    {
        for(int i=0;i<br_pregleda;i++)
        {
            p[i]=new Pregled(*pregledi.p[i]);
        }
    }
    catch(...)
    {
        for(int i=0;i<br_pregleda;i++) delete p[i];
        delete[] p; throw;
    }
}
Pregledi::Pregledi(Pregledi &&pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda),br_pregleda(pregledi.br_pregleda), p(pregledi.p)
{
    pregledi.p=nullptr;
    pregledi.br_pregleda=0;
}
Pregledi &Pregledi::operator=(const Pregledi &pregledi)
{
    if(max_broj_pregleda<pregledi.max_broj_pregleda && br_pregleda<pregledi.br_pregleda) //po mogucnosti napraviti i ovdje zastitu pri izuzecima, ali pointeri su i malo zauzimaju
    {
        auto pom=p;
        delete[] p;
        p=new Pregled*[pregledi.max_broj_pregleda];
        for(int i=0;i<br_pregleda;i++) p[i]=pom[i];
    }
    max_broj_pregleda=pregledi.max_broj_pregleda;
    if(br_pregleda<pregledi.br_pregleda) 
    {
        try
        {
            for(int i=br_pregleda;i<pregledi.br_pregleda;i++)
            {
                p[i]=new Pregled(*pregledi.p[i]);
            }
        }
        catch(...)
        {
            for(int i=br_pregleda;i<pregledi.br_pregleda;i++) { delete p[i]; p[i]=nullptr; }
            throw;
        }
    }
    else
    {
        for(int i=pregledi.br_pregleda;i<br_pregleda;i++) { delete p[i]; p[i]=nullptr;}
    }
    br_pregleda=pregledi.br_pregleda;
    for(int i=0;i<pregledi.br_pregleda;i++)
    {
        *p[i]=*pregledi.p[i];
    }
    return *this;
}
Pregledi &Pregledi::operator=(Pregledi &&pregledi)
{
    this->~Pregledi();
    max_broj_pregleda=pregledi.max_broj_pregleda;
    br_pregleda=pregledi.br_pregleda;
    p=pregledi.p;
    pregledi.p=nullptr;
    pregledi.br_pregleda=0;
    return *this;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    if(br_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    p[br_pregleda]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
    br_pregleda++;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    if(br_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    p[br_pregleda]=new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
    br_pregleda++;
}
void Pregledi::RegistrirajPregled(Pregled *pregled)
{
    if(br_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    p[br_pregleda]=pregled;
    br_pregleda++;
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    auto gl_datum=datum.Ocitaj();
    int n=std::count_if(p,p+br_pregleda,[&gl_datum](const Pregled *pregled)
    {
        auto pr_datum=pregled->DajDatumPregleda().Ocitaj();
        return (std::get<0>(pr_datum)==std::get<0>(gl_datum) && std::get<1>(pr_datum)==std::get<1>(gl_datum) && std::get<2>(pr_datum)==std::get<2>(gl_datum));
    });
    return n;
}
Pregled &Pregledi::DajNajranijiPregled()
{
    if(br_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    auto pok = std::min_element(p,p+br_pregleda,[](const Pregled *p1,const Pregled *p2)
    {
        return Pregled::DolaziPrije(*p1,*p2);
    });
    return **pok;
}
Pregled Pregledi::DajNajranijiPregled() const
{
    if(br_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    auto pok = std::min_element(p,p+br_pregleda,[](const Pregled *p1, const Pregled *p2)
    {
        return Pregled::DolaziPrije(*p1,*p2);
    });
    Pregled pregled=**pok;
    return pregled;
}
void Pregledi::ObrisiNajranijiPregled()
{
    if(br_pregleda==0) throw std::range_error("Prazna kolekcija");
    auto pok = std::min_element(p,p+br_pregleda,[](const Pregled *p1,const Pregled *p2)
    {
        return Pregled::DolaziPrije(*p1,*p2);
    });
    for(int i=0;i<br_pregleda;i++)
    {
        if(*pok == p[i])
        {
            delete p[i];
            for(int j=i;j<br_pregleda-1;j++)
            {
                p[j]=p[j+1];
            }
            break;
        }
    }
    br_pregleda--;
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    for(int i=0;i<br_pregleda;i++)
    {
        if(p[i]->DajImePacijenta()==ime_pacijenta)
        {
            delete p[i];
            for(int j=i;j<br_pregleda-1;j++)
            {
                p[j]=p[j+1];
            }
            br_pregleda--;
            i--;
        }
    }
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    auto gl_datum(datum.Ocitaj());
    int gl_dan(std::get<0>(gl_datum)),gl_mjesec(std::get<1>(gl_datum)),gl_godina(std::get<2>(gl_datum));
    Pregled** pregledi(new Pregled*[this->DajBrojPregleda()]);
    int n(DajBrojPregledaNaDatum(datum));
    int br(0);
    for(int i=0;i<br_pregleda;i++)
    {
        auto datum(p[i]->DajDatumPregleda().Ocitaj());
        int dan(std::get<0>(datum)),mjesec(std::get<1>(datum)),godina(std::get<2>(datum));
        if(dan==gl_dan && mjesec==gl_mjesec && godina==gl_godina) pregledi[br++]=p[i];
    }
    
    std::sort(pregledi,pregledi+n,[](const Pregled *pregled1, const Pregled *pregled2)
    {
        return Pregled::DolaziPrije(*pregled1,*pregled2);
    });
    std::for_each(pregledi,pregledi+n,[](const Pregled *pregledi1){pregledi1->Ispisi();});
    delete[] pregledi;
}
void Pregledi::IspisiSvePreglede() const
{
    Pregled** pregledi(new Pregled*[this->DajBrojPregleda()]);
    int br(0);
    for(int i=0;i<br_pregleda;i++)
    {
        pregledi[br++]=p[i];
    }
    std::sort(pregledi,pregledi+br_pregleda,[](const Pregled *pregled1, const Pregled *pregled2)
    {
        return Pregled::DolaziPrije(*pregled1,*pregled2);
    });
    std::for_each(pregledi,pregledi+br_pregleda,[](const Pregled *pregledi1){pregledi1->Ispisi();});
    delete[] pregledi;
}
/******************************************************************************/
int main ()
{
    Pregled pregled1("Edis Krsmanovic",27,5,2018,1,0);
    Pregled pregled2("Mujo Mujic",29,6,2018,10,20);
    Pregled pregled3("Hasna Hasic",27,5,2018,9,10);
    Pregled pregled4("Buba Bubic",26,5,2018,9,9);
    Pregled pregled5("Juso Jusic",30,1,2019,11,00);
    Pregled pregled6("Hasna H",27,5,2018,10,00);
    Pregled pregled7("Suljo Suljic",27,5,2018,9,1);
    Pregledi pregledi({pregled1,pregled2,pregled3,pregled4,pregled5,pregled6,pregled7});
    pregledi.IspisiSvePreglede();
    /*
    std::cout<<"Unesite maksimalan broj pregleda: ";
    int n;
    std::cin>>n;
    Pregledi pregledi(n);
    int br(0);
    while(true)
    {
        if(br==n) break;
        std::cin.ignore(10000, '\n');
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
        Pregled* pregled=new Pregled(ime,dan,mjesec,godina,sati,minute);
        pregledi.RegistrirajPregled(pregled);
        br++;
        
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
    }*/
    return 0;
}