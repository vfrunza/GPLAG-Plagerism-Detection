/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <utility>

struct Korisnik
{
    std::string ime, prezime, adresa, telefon;

};

class Knjiga
{
    friend class Biblioteka;
    std::string naslov,ime_pisca,zanr;
    int godina;
    Korisnik* korisnik;
public:

    Knjiga(std::string naslov, std::string ime_pisca,std::string zanr, int godina ):
    naslov(naslov),ime_pisca(ime_pisca),zanr(zanr),godina(godina),korisnik(nullptr){};
    
    std::string DajNaslov() const
    {
        return naslov;
    }
    
    std::string DajAutora() const
    {
        return ime_pisca;
    }
    
    std::string DajZanr() const
    {
        return zanr;
    }
    
    int DajGodinuIzdavanja() const
    {
        return godina;
    }
    
    Korisnik* DajKodKogaJe() const
    {
        return korisnik;
    }
    
    void ZaduziKnjigu(Korisnik &k)
    {
        korisnik=&k;
    }
    
    void RazduziKnjigu()
    {
        korisnik=nullptr;
    }
    
    bool DaLiJeZaduzena() const
    {
        if(!korisnik)return false;
        else return true;
    }
};

class Biblioteka
{
    std::map<int,Korisnik*> mkorisnik;
    std::map<int,Knjiga*> mknjiga;
public:
    Biblioteka(){};
    Biblioteka(const Biblioteka &b);
    Biblioteka( Biblioteka &&b);
    Biblioteka &operator=(const Biblioteka &b);
    Biblioteka &operator =(Biblioteka &&b);
    ~Biblioteka();
    void RegistrirajNovogKorisnika(int clbroj, std::string ime, std::string prezime, std::string adresa, std::string brtel);
    void RegistrirajNovuKnjigu(int evbroj, std::string naslov, std::string pisac, std::string zanr, int godina);
    Korisnik& NadjiKorisnika(int clbroj) const;
    Knjiga& NadjiKnjigu(int evbroj) const;
    void IzlistajKorisnike();
    void IzlistajKnjige();
    void ZaduziKnjigu(int evbroj, int clbroj);
    void RazduziKnjigu(int evbroj);
    void PrikaziZaduzenja(int clbroj);
};

void Biblioteka::PrikaziZaduzenja(int clbroj)
{
    int brojac(0);
    auto k(mkorisnik.find(clbroj));
    for(auto it=mknjiga.begin();it!=mknjiga.end();it++)
    {
        if((it->second->korisnik)==k->second)
        {
            brojac++;
             std::cout<<"Evidencijski broj: "<<it->first<<std::endl
        <<"Naslov: "<<(it->second)->DajNaslov()<<std::endl
        <<"Pisac: "<<(it->second)->DajAutora()<<std::endl
        <<"Zanr: "<<(it->second)->DajZanr()<<std::endl
        <<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja();
        std::cout<<std::endl<<std::endl;
            
        }
    }
    if(brojac==0)
        std::cout<<"Nema zaduzenja za tog korisnika!";
}

void Biblioteka::ZaduziKnjigu(int evbroj, int clbroj)
{
    NadjiKnjigu(evbroj);
    NadjiKorisnika(clbroj);
    auto a(mknjiga.find(evbroj));
    auto b(mkorisnik.find(clbroj));
    if(a->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    a->second->ZaduziKnjigu(*(b->second));
}

void Biblioteka::RazduziKnjigu(int evbroj)
{
    NadjiKnjigu(evbroj);
    auto a(mknjiga.find(evbroj));
    if(!(a->second->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
    a->second->RazduziKnjigu();
}

void Biblioteka::IzlistajKorisnike()
{
    for(auto it=mkorisnik.begin();it!=mkorisnik.end();it++)
    {
        std::cout<<"Clanski broj: "<<it->first<<std::endl
        <<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<std::endl
        <<"Adresa: "<<(it->second)->adresa<<std::endl
        <<"Broj telefona: "<<(it->second)->telefon<<std::endl<<std::endl;
    }
}

void Biblioteka::IzlistajKnjige()
{
    for(auto it=mknjiga.begin();it!=mknjiga.end();it++)
    {
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl
        <<"Naslov: "<<(it->second)->DajNaslov()<<std::endl
        <<"Pisac: "<<(it->second)->DajAutora()<<std::endl
        <<"Zanr: "<<(it->second)->DajZanr()<<std::endl
        <<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja();
        if(((it->second)->DaLiJeZaduzena())==true)
            std::cout<<std::endl<<"Zaduzena kod korisnika: "<<((it->second)->DajKodKogaJe())->ime<<" "<<((it->second)->DajKodKogaJe())->prezime;
        std::cout<<std::endl<<std::endl;
    }
}

Korisnik& Biblioteka::NadjiKorisnika(int clbroj) const
{
    if(mkorisnik.find(clbroj)==mkorisnik.end())
        throw std::logic_error("Korisnik nije nadjen");
    auto it(mkorisnik.find(clbroj));
    return *(it->second);
}

Knjiga& Biblioteka::NadjiKnjigu(int evbroj) const
{
    if(mknjiga.find(evbroj)==mknjiga.end())
        throw std::logic_error("Knjiga nije nadjena");
    auto it(mknjiga.find(evbroj));
    return *(it->second);
}

void Biblioteka::RegistrirajNovogKorisnika(int clbroj, std::string ime, std::string prezime, std::string adresa, std::string brtel)
{
    if(mkorisnik.find(clbroj)!=mkorisnik.end())
        throw std::logic_error("Korisnik vec postoji");
    Korisnik*pok(nullptr);
    try
    {
    pok = new Korisnik{ime,prezime,adresa,brtel};
    }
    catch(...)
    {
        std::cout<<"Problemi sa memorijom";
    }
    mkorisnik.insert(std::make_pair(clbroj,pok));
}

void Biblioteka::RegistrirajNovuKnjigu(int evbroj, std::string naslov, std::string pisac, std::string zanr, int godina)
{
    if(mknjiga.find(evbroj)!=mknjiga.end())
        throw std::logic_error("Knjiga vec postoji");
    Knjiga*pok(nullptr);
    try
    {
    pok= new Knjiga(naslov,pisac,zanr,godina);
    }
    catch(...)
    {
        std::cout<<"Problemi sa memorijom";
    }
    mknjiga.insert(std::make_pair(evbroj,pok));
}

Biblioteka::~Biblioteka()
{
    for(auto it=mkorisnik.begin();it!=mkorisnik.end();it++)
        delete it->second;
    
    for(auto it=mknjiga.begin();it!=mknjiga.end();it++)
        delete it->second;
}

Biblioteka::Biblioteka(const Biblioteka &b)
{
    try
    {
        for(auto it=b.mkorisnik.begin();it!=b.mkorisnik.end();it++)
        {
            Korisnik* pok=new Korisnik(*(it->second));
            mkorisnik.insert(std::make_pair(it->first,pok));
        }
        
        for(auto it=b.mknjiga.begin();it!=b.mknjiga.end();it++)
        {
            Knjiga* pok=new Knjiga(*(it->second));
            mknjiga.insert(std::make_pair(it->first,pok));
        }
    }
    catch(...)
    {
        for(auto it=mkorisnik.begin();it!=mkorisnik.end();it++)
        {
            delete it->second;
        }
        for(auto it=mknjiga.begin();it!=mknjiga.end();it++)
        {
            delete it->second;
        }
        std::cout<<"Problemi sa memorijom";
    }
};

Biblioteka::Biblioteka(Biblioteka &&b)
{
    mknjiga=std::move(b.mknjiga);
    mkorisnik=std::move(b.mkorisnik);
};

Biblioteka &Biblioteka::operator=(const Biblioteka &b)
{
    mknjiga.clear();
    mkorisnik.clear();
    try
    {
        for(auto it=b.mkorisnik.begin();it!=b.mkorisnik.end();it++)
        {
            Korisnik* pok=new Korisnik(*(it->second));
            mkorisnik.insert(std::make_pair(it->first,pok));
        }
        
        for(auto it=b.mknjiga.begin();it!=b.mknjiga.end();it++)
        {
            Knjiga* pok=new Knjiga(*(it->second));
            mknjiga.insert(std::make_pair(it->first,pok));
        }
    }
    catch(...)
    {
        for(auto it=b.mkorisnik.begin();it!=b.mkorisnik.end();it++)
            delete it->second;
        for(auto it=b.mknjiga.begin();it!=b.mknjiga.end();it++)
            delete it->second;
    }
    return *this;
};

Biblioteka &Biblioteka::operator =(Biblioteka &&b)
{
    std::swap(mkorisnik,b.mkorisnik);
    std::swap(mknjiga,b.mknjiga);
    return *this;
}

int main()
{
    Biblioteka b;
    for(;;)
    {
        try
        {
            std::cout<<"Odaberite opciju:\n1 za kraj\n2 za registriranje novog korisnika\n3 za registriranje nove knjige\n4 za pronalazak korisnika\n5 za pronalazak knjige\n6 za izlistavanje korisnika\n7 za izlistavanje knjiga\n8 za zaduzivanje knjige\n9 za razduzivanje knjige\n10 za izlistavanje zaduzenja korisnika\n";
            int odabir(0);
            std::cin>>odabir;
            if(odabir==1) return 0;
            else if(odabir==2)
            {
                std::cout<<"Unesite clanski broj korisnika: ";
                int br; std::cin>>br;
                std::cin.ignore(10000,'\n');
                std::cout<<"Unesite ime korisnika: ";
                std::string ime; std::getline(std::cin,ime);
                std::cout<<"Unesite prezime korisnika: ";
                std::string prezime; std::getline(std::cin,prezime);
                std::cout<<"Unesite adresu korisnika: ";
                std::string adresa; std::getline(std::cin,adresa);
                std::cout<<"Unesite broj telefona korisnika: ";
                std::string brtel; std::getline(std::cin,brtel);
                b.RegistrirajNovogKorisnika(br,ime,prezime,adresa,brtel);
                std::cout<<"Korisnik uspjesno registrovan!";
            }
            else if(odabir==3)
            {
                std::cout<<"Unesite evidencijski broj knjige: ";
                int br; std::cin>>br;
                std::cin.ignore(10000,'\n');
                std::cout<<"Unesite naslov knjige: ";
                std::string ime; std::getline(std::cin,ime);
                std::cout<<"Unesite ime i prezime pisca knjige: ";
                std::string prezime; std::getline(std::cin,prezime);
                std::cout<<"Unesite zanr knjige: ";
                std::string zanr; std::getline(std::cin,zanr);
                std::cout<<"Unesite godinu izdavanja knjige: ";
                int god; std::cin>>god;
                b.RegistrirajNovuKnjigu(br,ime,prezime,zanr,god);
                std::cout<<"Knjiga uspjesno registrovana!";
            }
            else if(odabir==4)
            {
                std::cout<<"Unesite clanski broj korisnika: ";
                int br; std::cin>>br;
                auto it(b.NadjiKorisnika(br));
                std::cout<<"Ime i prezime: "<<it.ime<<" "<<it.prezime<<std::endl
                <<"Adresa: "<<it.adresa<<std::endl
                <<"Broj telefona: "<<it.telefon;
            }
            else if(odabir==5)
            {
                std::cout<<"Unesite evidencijski broj knjige: ";
                int br; std::cin>>br;
                auto it(b.NadjiKnjigu(br));
                std::cout<<"Naslov: "<<it.DajNaslov()<<std::endl
                <<"Pisac: "<<it.DajAutora()<<std::endl
                <<"Zanr: "<<it.DajZanr()<<std::endl
                <<"Godina izdavanja: "<<it.DajGodinuIzdavanja();
                if((it.DaLiJeZaduzena())==true)
                std::cout<<std::endl<<"Zaduzena kod korisnika: "<<(it.DajKodKogaJe())->ime<<" "<<(it.DajKodKogaJe())->prezime;
            }
            else if(odabir==6)
            {
                b.IzlistajKorisnike();
            }
            else if(odabir==7)
            {
                b.IzlistajKnjige();
            }
            else if(odabir==8)
            {
                std::cout<<"Unesite evidencijski broj knjige: ";
                int br; std::cin>>br;
                std::cout<<"Unesite clanski broj korisnika: ";
                int br2; std::cin>>br2;
                b.ZaduziKnjigu(br,br2);
            }
            else if(odabir==9)
            {
                std::cout<<"Unesite evidencijski broj knjige: ";
                int br; std::cin>>br;
                b.RazduziKnjigu(br);
            }
            else if(odabir==10)
            {
                std::cout<<"Unesite clanski broj korisnika: ";
                int br; std::cin>>br;
                b.PrikaziZaduzenja(br);
            }
        }
        catch(std::logic_error e)
        {
            std::cout<<e.what()<<std::endl;
        }
        std::cout<<std::endl;
    }
    return 0;
}

