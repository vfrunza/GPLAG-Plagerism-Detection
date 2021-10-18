/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <initializer_list>
#include <algorithm>

class Datum {
    int dan,mjesec,godina;
public:
    Datum (int dan, int mjesec, int godina) {Postavi(dan,mjesec,godina);}
    void Postavi (int dan, int mjesec, int godina);
    std::tuple<int,int,int> Ocitaj() const {return std::make_tuple(dan,mjesec,godina);}
    void Ispisi () const {std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};

void Datum::Postavi (int dan, int mjesec, int godina)
{
    int bd[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if (godina%4==0 && (godina%100!=0 || godina%400==0)) bd[1]++;
    if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>bd[mjesec-1]) throw std::domain_error ("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}

class Vrijeme {
    int sati,minute;
public:
    Vrijeme (int sati, int minute) {Postavi(sati,minute);}
    void Postavi (int sati,int minute);
    std::pair<int,int> Ocitaj () const {return std::make_pair(sati,minute);}
    void Ispisi () const {std::cout<<std::right<<std::setfill('0')<<std::setw(2)<<sati<<":"<<std::setfill('0')<<std::setw(2)<<minute;}
};

void Vrijeme::Postavi (int sati, int minute)
{
    if (sati<0 || sati>23 || minute<0 || minute>59)
        throw std::domain_error ("Neispravno vrijeme");
    Vrijeme::sati=sati; Vrijeme::minute=minute;
}

class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    static int DajBrojDana (int mjesec,int godina);
public:
    Pregled (const std::string &ime, const Datum &datum, const Vrijeme &vrijeme): ime_pacijenta(ime),datum_pregleda(datum),vrijeme_pregleda(vrijeme) {}
    Pregled (const std::string &ime, int dan, int mjesec, int godina, int sati, int minute): ime_pacijenta(ime),datum_pregleda(Datum(dan,mjesec,godina)),vrijeme_pregleda(Vrijeme(sati,minute)) {}
    void PromijeniPacijenta (const std::string &ime) {ime_pacijenta=ime;}
    void PromijeniDatum (const Datum &novi_datum) {datum_pregleda=novi_datum;}
    void PromijeniVrijeme (const Vrijeme &novo_vrijeme) {vrijeme_pregleda=novo_vrijeme;}
    void PomjeriDanUnaprijed ();
    void PomjeriDanUnazad ();
    std::string DajImePacijenta () const {return ime_pacijenta;}
    Datum DajDatumPregleda () const {return datum_pregleda;}
    Vrijeme DajVrijemePregleda () const {return vrijeme_pregleda;}
    static bool DolaziPrije (const Pregled &p1, const Pregled &p2);
    void Ispisi () const {std::cout<<std::left<<std::setw(30)<<std::setfill(' ')<<ime_pacijenta; datum_pregleda.Ispisi(); std::cout<<" "; vrijeme_pregleda.Ispisi(); std::cout<<std::endl;}
};

bool Pregled::DolaziPrije (const Pregled &p1, const Pregled &p2)
{
    auto par1(p1.vrijeme_pregleda.Ocitaj()),par2(p2.vrijeme_pregleda.Ocitaj());
    auto tup1(p1.datum_pregleda.Ocitaj()),tup2(p2.datum_pregleda.Ocitaj());
    if (std::get<2>(tup1)==std::get<2>(tup2))
    {
        if (std::get<1>(tup1)==std::get<1>(tup2))
        {
            if (std::get<0>(tup1)==std::get<0>(tup2))
            {
                if (par1.first==par2.first)
                {
                    return par1.second<par2.second;
                }
                return par1.first<par2.first;
            }
            return std::get<0>(tup1)<std::get<0>(tup2);
        }
        return std::get<1>(tup1)<std::get<1>(tup2);
    }
    return std::get<2>(tup1)<std::get<2>(tup2);
}

int Pregled::DajBrojDana (int mjesec, int godina)
{
    int bd[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if (godina%4==0 && (godina%100!=0 || godina%400==0)) bd[1]++;
    return bd[mjesec-1];
}

void Pregled::PomjeriDanUnaprijed()
{
    std::tuple<int,int,int> t(datum_pregleda.Ocitaj());
    std::get<0>(t)++;
    if (std::get<0>(t)>DajBrojDana(std::get<1>(t),std::get<2>(t))) std::get<0>(t)=1,std::get<1>(t)++;
    if (std::get<1>(t)>12) std::get<1>(t)=1,std::get<2>(t)++;
    datum_pregleda.Postavi(std::get<0>(t),std::get<1>(t),std::get<2>(t));
}

void Pregled::PomjeriDanUnazad ()
{
    std::tuple<int,int,int> t(datum_pregleda.Ocitaj());
    std::get<0>(t)--;
    if (std::get<0>(t)==0)
    {
        std::get<1>(t)--;
        if (std::get<1>(t)==0) std::get<1>(t)=12,std::get<2>(t)--;
        std::get<0>(t)=DajBrojDana(std::get<1>(t),std::get<2>(t));
    }
    datum_pregleda.Postavi(std::get<0>(t),std::get<1>(t),std::get<2>(t));
}

class Pregledi {
    std::vector<std::shared_ptr<Pregled>> pregledi;
public:
    explicit Pregledi () {}
    Pregledi (std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi () = default;
    Pregledi (const Pregledi &pregledi);
    Pregledi (Pregledi &&p): pregledi(p.pregledi) {p.pregledi.resize(0);}
    Pregledi &operator=(const Pregledi &p);
    Pregledi &operator=(Pregledi &&p) {std::swap(pregledi,p.pregledi); p.pregledi.resize(0); return *this;}
    void RegistrirajPregled (const std::string &s, const Datum &d, const Vrijeme &v);
    void RegistrirajPregled (const std::string &s, int dan, int mjesec, int godina, int sati, int minute);
    void RegistrirajPregled (std::shared_ptr<Pregled> p);
    int DajBrojPregleda () const {return pregledi.size();}
    int DajBrojPregledaNaDatum (const Datum &d) const;
    Pregled &DajNajranijiPregled ();
    Pregled DajNajranijiPregled () const;
    void IsprazniKolekciju () {pregledi.resize(0);}
    void ObrisiNajranijiPregled ();
    void ObrisiPregledePacijenta (const std::string &ime);
    void IspisiPregledaNaDatum (const Datum &d) const;
    void IspisiSvePreglede () const;
};

void Pregledi::IspisiPregledaNaDatum (const Datum &d) const
{
    std::vector<bool> vec(pregledi.size(),false);
    auto t1(d.Ocitaj());
    for (int i=0;i<pregledi.size();i++)
    {
        int min(0);
        while (vec[min]==true) min++;
        for (int j=0;j<pregledi.size();j++)
        {
            if (vec[j]==false && Pregled::DolaziPrije(*pregledi[j],*pregledi[min]))
            min=j;
        }
        vec[min]=true;
        auto t2(pregledi[min]->DajDatumPregleda().Ocitaj());
        if (std::get<0>(t1)==std::get<0>(t2) && std::get<1>(t1)==std::get<1>(t2) && std::get<2>(t1)==std::get<2>(t2))
            pregledi[min]->Ispisi();
    }
}

void Pregledi::IspisiSvePreglede () const
{
    std::vector<bool> vec(pregledi.size(),false);
    for (int i=0;i<pregledi.size();i++)
    {
        int min(0);
        while (vec[min]==true) min++;
        for (int j=0;j<pregledi.size();j++)
        {
            if (vec[j]==false && Pregled::DolaziPrije(*pregledi[j],*pregledi[min]))
            min=j;
        }
        vec[min]=true;
        pregledi[min]->Ispisi();
    }
}

void Pregledi::ObrisiPregledePacijenta (const std::string &ime)
{
    for (int i=0;i<pregledi.size();++i)
    {
        if (pregledi[i]->DajImePacijenta()==ime)
        {
            pregledi[i]=nullptr;
            pregledi.erase(pregledi.begin()+i);
            i--;
        }
    }
}

void Pregledi::ObrisiNajranijiPregled ()
{
    if (pregledi.size()==0) throw std::range_error ("Prazna kolekcija");
    auto p(&DajNajranijiPregled());
    for (int i=0;i<pregledi.size();i++)
    {
        if (pregledi[i].get()==p)
        {
            pregledi[i]=nullptr;
            pregledi.erase(pregledi.begin()+i);
        }
    }
}

Pregled Pregledi::DajNajranijiPregled() const
{
    if (pregledi.size()==0) throw std::domain_error ("Nema registriranih pregleda");
    return **std::min_element(pregledi.begin(),pregledi.end(),[](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2)
    {
        return Pregled::DolaziPrije(*p1,*p2);
    });
}

Pregled &Pregledi::DajNajranijiPregled ()
{
    if (pregledi.size()==0) throw std::domain_error ("Nema registriranih pregleda");
    return **std::min_element(pregledi.begin(),pregledi.end(),[] (std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2)
    {
        return Pregled::DolaziPrije(*p1,*p2);
    });
}

int Pregledi::DajBrojPregledaNaDatum (const Datum &d) const
{
    return std::count_if(pregledi.begin(),pregledi.end(),[d] (std::shared_ptr<Pregled> p)
    {
        auto t1(p->DajDatumPregleda().Ocitaj()),t2(d.Ocitaj());
        return std::get<0>(t1)==std::get<0>(t2) && std::get<1>(t1)==std::get<1>(t2) && std::get<2>(t1)==std::get<2>(t2);
    });
}

void Pregledi::RegistrirajPregled (std::shared_ptr<Pregled> p)
{

    pregledi.resize(pregledi.size()+1);
    pregledi[pregledi.size()-1]=p;
}

void Pregledi::RegistrirajPregled (const std::string &s, int dan, int mjesec, int godina, int sati, int minute)
{

    pregledi.resize(pregledi.size()+1);
    pregledi[pregledi.size()-1]=std::make_shared<Pregled> (s,dan,mjesec,godina,sati,minute);
}

void Pregledi::RegistrirajPregled (const std::string &s, const Datum &d, const Vrijeme &v)
{
    pregledi.resize(pregledi.size()+1);
    pregledi[pregledi.size()-1]=std::make_shared<Pregled> (s,d,v);
}

Pregledi &Pregledi::operator=(const Pregledi &p)
{
    if (&p!=this) {
        std::vector<std::shared_ptr<Pregled>> novi(p.pregledi.size());
        for (int i=0;i<p.pregledi.size();i++)
            novi[i]=std::make_shared<Pregled> (*p.pregledi[i]);
        pregledi=novi;
    }
    return *this;
}

Pregledi::Pregledi(const Pregledi &p)
{
    pregledi.resize(p.pregledi.size());
    for (int i=0;i<pregledi.size();i++)
        pregledi[i]=std::make_shared<Pregled> (*p.pregledi[i]);
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda)
{
    pregledi.resize(spisak_pregleda.size());
    auto it(spisak_pregleda.begin());
    for (int i=0;i<pregledi.size();i++)
    {
        pregledi[i]=std::make_shared<Pregled> (*it);
        it++;
    }
}

int main ()
{
    Pregledi pr;
    for (;;)
    {
        std::string ime;
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::getline(std::cin,ime);
        if (ime=="kraj") break;
        int dan,mjesec,godina,sati,minute;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        std::cin>>dan>>mjesec>>godina;
        std::cout<<"Unesite sate i minute pregleda: ";
        std::cin>>sati>>minute;
        std::cin.ignore(10000,'\n');
        pr.RegistrirajPregled(ime,dan,mjesec,godina,sati,minute);
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi\n";
    pr.IspisiSvePreglede();
    for (;;)
    {
        int x;
        std::cout<<"\nOdaberite jednu od sljedecih opcija\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n";
        std::cout<<"4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n";
        std::cin>>x;
        if (x==1)
        {
            int d,m,g;
            std::cout<<"Unesite dan mjesec i godinu : ";
            std::cin>>d>>m>>g;
            std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<pr.DajBrojPregledaNaDatum(Datum(d,m,g))<<std::endl;
        }
        else if (x==2) {std::cout<<"Najraniji pregled je:\n"; pr.DajNajranijiPregled().Ispisi();}
        else if (x==3)
        {
            std::string ip;
            std::cout<<"Unesite ime pacijenta: ";
            std::cin.ignore(10000,'\n');
            std::getline(std::cin,ip);
            int broj(pr.DajBrojPregleda());
            pr.ObrisiPregledePacijenta(ip);
            std::cout<<"Uspjesno obrisano "<<broj-pr.DajBrojPregleda()<<" pregleda\n";
        }
        else if (x==4)
        {
            pr.ObrisiNajranijiPregled();
            std::cout<<"Najraniji pregled uspjesno obrisan\n";
        }
        else if (x==5)
        {
            int d,m,g;
            std::cout<<"Unesite dan mjesec i godinu : ";
            std::cin>>d>>m>>g;
            std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su: \n";
            pr.IspisiPregledaNaDatum(Datum(d,m,g));
        }
        else if (x==6) pr.IspisiSvePreglede();
        else if (x==7) break;
    }
	return 0;
}
