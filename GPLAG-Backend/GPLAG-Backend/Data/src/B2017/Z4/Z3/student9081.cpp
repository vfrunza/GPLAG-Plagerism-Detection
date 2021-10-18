/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <iomanip>
#include <initializer_list>
#include <new>
#include <algorithm>
#include <vector>
#include <string>

class Datum {
    int dan,mjesec,godina;
public:
    Datum (int dan,int mjesec,int godina) {Postavi(dan,mjesec,godina);}
    void Postavi (int dan, int mjesec, int godina);
    std::tuple<int,int,int> Ocitaj () const {return std::make_tuple(dan,mjesec,godina);}
    void Ispisi () const {std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};

void Datum::Postavi (int dan, int mjesec, int godina)
{
    int bd[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if (godina%4==0 && (godina%100!=0 || godina%400==0)) bd[1]++;
    if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>bd[mjesec-1])
        throw std::domain_error ("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}

class Vrijeme {
    int sati,minute;
public:
    Vrijeme (int sati, int minute) {Postavi(sati,minute);}
    void Postavi (int sati,int minute);
    std::pair<int,int> Ocitaj () const {return std::make_pair(sati,minute);}
    void Ispisi() const {std::cout<<std::right<<std::setfill('0')<<std::setw(2)<<sati<<":"<<std::setfill('0')<<std::setw(2)<<minute;}
};

void Vrijeme::Postavi(int sati, int minute)
{
    if (sati<0 || sati>23 || minute<0 || minute>59)
        throw std::domain_error ("Neispravno vrijeme");
    Vrijeme::sati=sati; Vrijeme::minute=minute;
}

class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    static int DajBrojDana (int mjesec, int godina);
public:
    Pregled (const std::string &ime, const Datum &datum, const Vrijeme &vrijeme) : ime_pacijenta(ime),datum_pregleda(datum),vrijeme_pregleda(vrijeme) {}
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
    if (godina %4==0 && (godina%100!=0 || godina%400==0)) bd[1]++;
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

void Pregled::PomjeriDanUnazad()
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

class Pregledi{
    int max_broj_pregleda,broj_pregleda;
    Pregled **pok;
    static void OslobodiMemoriju (Pregled **pokazivac, int broj);
    Pregled **begin() const {return pok;}
    Pregled **end() const {return pok+max_broj_pregleda;}
public:
    explicit Pregledi (int max);
    Pregledi (std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi () {OslobodiMemoriju(pok,max_broj_pregleda);}
    Pregledi (const Pregledi &pregledi);
    Pregledi (Pregledi &&pregledi);
    Pregledi &operator=(const Pregledi &pregledi);
    Pregledi &operator=(Pregledi &&pregledi);
    void RegistrirajPregled (const std::string &ime_pacijenta,const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled (const std::string &ime_pacijenta,int dan, int mjesec, int godina,int sati,int minute);
    void RegistrirajPregled (Pregled *pregled);
    int DajBrojPregleda() const {return broj_pregleda;}
    int DajBrojPregledaNaDatum (const Datum &datum) const;
    Pregled &DajNajranijiPregled ();
    Pregled DajNajranijiPregled () const;
    void IsprazniKolekciju ();
    void ObrisiNajranijiPregled ();
    void ObrisiPregledePacijenta (const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum (const Datum &datum) const;
    void IspisiSvePreglede () const;
};

Pregledi::Pregledi (int max): max_broj_pregleda(max),broj_pregleda(0),pok(new Pregled* [max]{}) {}

void Pregledi::IspisiPregledeNaDatum (const Datum &datum) const
{
    auto t1(datum.Ocitaj());
    std::vector<bool> vec(max_broj_pregleda,false);
    for (int i=0;i<max_broj_pregleda;i++)
    {
        int min(0);
        while (vec[min]==true) min++;
        for (int j=0;j<max_broj_pregleda;j++)
        {
            if (pok[min]!=nullptr && pok[j]!=nullptr && vec[j]==false && Pregled::DolaziPrije(*pok[j],*pok[min]))
            min=j;
            else if (pok[min]==nullptr && pok[j]!=nullptr && vec[j]==false)
            min=j;
        }
        vec[min]=true;
        if (pok[min]!=nullptr)
        {
            auto t2(pok[min]->DajDatumPregleda().Ocitaj());
            if (std::get<0>(t1)==std::get<0>(t2) && std::get<1>(t1)==std::get<1>(t2) && std::get<2>(t1)==std::get<2>(t2))
            pok[min]->Ispisi();
        }
    }
}

void Pregledi::IspisiSvePreglede () const
{
    std::vector<bool> vec(max_broj_pregleda,false);
    for (int i=0;i<max_broj_pregleda;i++)
    {
        int min(0);
        while (vec[min]==true) min++;
        for (int j=0;j<max_broj_pregleda;j++)
        {
            if (pok[min]!=nullptr && pok[j]!=nullptr && vec[j]==false && Pregled::DolaziPrije(*pok[j],*pok[min]))
            min=j;
            else if (pok[min]==nullptr && pok[j]!=nullptr && vec[j]==false)
            min=j;
        }
        vec[min]=true;
        if (pok[min]!=nullptr)
        pok[min]->Ispisi();
    }
}

void Pregledi::ObrisiPregledePacijenta (const std::string &ime_pacijenta)
{
    for (int i=0;i<max_broj_pregleda;i++)
    {
       if (pok[i]!=nullptr)
       {
           if (pok[i]->DajImePacijenta()==ime_pacijenta)
           {
               delete pok[i]; pok[i]=nullptr;
               broj_pregleda--;
           }
       }
    }
}

void Pregledi::ObrisiNajranijiPregled ()
{
    if (DajBrojPregleda()==0)
        throw std::range_error ("Prazna kolekcija");
    auto pok_p(&DajNajranijiPregled());
    for (int i=0;i<max_broj_pregleda;i++)
    {
        if (pok[i]==pok_p)
        {
            delete pok[i]; pok[i]=nullptr;
            broj_pregleda--;
        }
    }
}

void Pregledi::IsprazniKolekciju ()
{
    for (int i=0;i<max_broj_pregleda;i++)
    {
        delete pok[i]; pok[i]=nullptr;
    }
    broj_pregleda=0;
}

Pregled &Pregledi::DajNajranijiPregled ()
{
    if (DajBrojPregleda()==0)
        throw std::domain_error ("Nema registriranih pregleda");
    return **std::min_element(this->begin(),this->end(),[] (Pregled *p1, Pregled *p2)
    {
        if (p1==nullptr) return false;
        if (p1!=nullptr && p2==nullptr) return true;
        return Pregled::DolaziPrije(*p1,*p2);
    });
}

Pregled Pregledi::DajNajranijiPregled() const
{
    if (DajBrojPregleda()==0)
        throw std::domain_error ("Nema registriranih pregleda");
    return **std::min_element(this->begin(),this->end(),[] (Pregled *p1, Pregled *p2)
    {
        if (p1==nullptr) return false;
        if (p1!=nullptr && p2==nullptr) return true;
        return Pregled::DolaziPrije(*p1,*p2);
    });
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    return std::count_if(this->begin(),this->end(),[datum] (Pregled *p) 
    {
        if (p==nullptr) return false;
        auto t1(p->DajDatumPregleda().Ocitaj()),t2(datum.Ocitaj());
        return std::get<0>(t1)==std::get<0>(t2) && std::get<1>(t1)==std::get<1>(t2) && std::get<2>(t1)==std::get<2>(t2);
    });
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    if (DajBrojPregleda()==max_broj_pregleda)
        throw std::range_error ("Dostignut maksimalni broj pregleda");
    for (int i=0;i<max_broj_pregleda;i++)
    {
        if(pok[i]==nullptr)
        {
            pok[i]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
            broj_pregleda++;
            break;
        }
    }
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan, int mjesec, int godina, int sati, int minute)
{
    if (DajBrojPregleda()==max_broj_pregleda)
        throw std::range_error ("Dostignut maksimalni broj pregleda");
    for (int i=0;i<max_broj_pregleda;i++)
    {
        if (pok[i]==nullptr)
        {
            pok[i]=new Pregled(ime_pacijenta,dan,mjesec,godina,sati,minute);
            broj_pregleda++;
            break;
        }
    }
}

void Pregledi::RegistrirajPregled (Pregled *pregled)
{
    if (DajBrojPregleda()==max_broj_pregleda) {
        delete pregled;
        throw std::range_error ("Dostignut maksimalni broj pregleda");}
    for (int i=0;i<max_broj_pregleda;i++)
    {
        if (pok[i]==nullptr && pregled!=nullptr)
        {
            pok[i]=pregled;
            broj_pregleda++;
            break;
        }
    }
}

Pregledi &Pregledi::operator=(const Pregledi &pregledi)
{
    if (&pregledi!=this) {
    Pregled **novi(new Pregled* [pregledi.max_broj_pregleda]{});
    try
    {
        for (int i=0;i<pregledi.max_broj_pregleda;i++)
        {
            if (pregledi.pok[i]!=nullptr)
            novi[i]=new Pregled (*pregledi.pok[i]);
            else
            novi[i]=nullptr;
        }
    }
    catch (std::bad_alloc)
    {
        OslobodiMemoriju(novi,pregledi.max_broj_pregleda);
        throw;
    }
    OslobodiMemoriju(this->pok,this->max_broj_pregleda);
    pok=novi; max_broj_pregleda=pregledi.max_broj_pregleda; broj_pregleda=pregledi.broj_pregleda;}
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi)
{
    std::swap(max_broj_pregleda,pregledi.max_broj_pregleda); std::swap(pok,pregledi.pok); std::swap(broj_pregleda,pregledi.broj_pregleda);
    Pregledi::OslobodiMemoriju(pregledi.pok,pregledi.max_broj_pregleda);
    pregledi.pok=nullptr; pregledi.max_broj_pregleda=0; pregledi.broj_pregleda=0;
    return *this;
}

Pregledi::Pregledi (const Pregledi &pregledi): max_broj_pregleda(pregledi.max_broj_pregleda),broj_pregleda(pregledi.broj_pregleda),pok(new Pregled* [max_broj_pregleda]{})
{
    try
    {
        for (int i=0;i<max_broj_pregleda;i++)
        {
            if (pregledi.pok[i]!=nullptr)
            pok[i]=new Pregled(*pregledi.pok[i]);
            else
            pok[i]=nullptr;
        }
    }
    catch (std::bad_alloc)
    {
        Pregledi::OslobodiMemoriju(pok,max_broj_pregleda);
        throw;
    }
}

Pregledi::Pregledi (Pregledi &&pregledi): max_broj_pregleda(pregledi.max_broj_pregleda),broj_pregleda(pregledi.broj_pregleda),pok(pregledi.pok)
{
    pregledi.pok=nullptr; pregledi.max_broj_pregleda=0; pregledi.broj_pregleda=0;
}

void Pregledi::OslobodiMemoriju (Pregled **pokazivac, int broj)
{
    if (!pokazivac) return;
    for (int i=0;i<broj;i++) delete pokazivac[i];
    delete[] pokazivac;
}

Pregledi::Pregledi (std::initializer_list<Pregled> spisak_pregleda): max_broj_pregleda(spisak_pregleda.size()),broj_pregleda(spisak_pregleda.size()),pok(new Pregled* [max_broj_pregleda]{})
{
    auto it(spisak_pregleda.begin());
    try
    {
        for (int i=0;i<max_broj_pregleda;i++)
        {
            pok[i]=new Pregled(*it);
            it++;
        }
    }
    catch (std::bad_alloc)
    {
        Pregledi::OslobodiMemoriju(pok,max_broj_pregleda);
        throw;
    }
}

int main ()
{
    int n;
    std::cout<<"Unesite maksimalan broj pregleda: ";
    std::cin>>n;
    Pregledi pr(n);
    for (int i=0;i<n;i++)
    {
        std::string ime;
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::cin.ignore(10000,'\n');
        std::getline(std::cin,ime);
        if (ime=="kraj") break;
        int dan,mjesec,godina,sati,minute;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        std::cin>>dan>>mjesec>>godina;
        std::cout<<"Unesite sate i minute pregleda: ";
        std::cin>>sati>>minute;
        pr.RegistrirajPregled(ime,dan,mjesec,godina,sati,minute);
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi \n";
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
        else if (x==4)
        {
            pr.ObrisiNajranijiPregled();
            std::cout<<"Najraniji pregled uspjesno obrisan\n";
        }
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
        else if (x==5)
        {
            int d,m,g;
            std::cout<<"Unesite dan mjesec i godinu : ";
            std::cin>>d>>m>>g;
            std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su: \n";
            pr.IspisiPregledeNaDatum(Datum(d,m,g));
        }
        else if (x==6) pr.IspisiSvePreglede();
        else if (x==7) break;
    }
	return 0;
}
