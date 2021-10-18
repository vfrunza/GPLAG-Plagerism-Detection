/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <memory>
struct  Korisnik
{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga
{
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    std::shared_ptr<Korisnik> pok;
public:  
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) : naslov(naslov), ime_pisca (ime_pisca), zanr (zanr), godina_izdavanja (godina_izdavanja), pok(nullptr) {};
    std::string DajNaslov() const { return naslov;}
    std::string DajAutora() const { return ime_pisca;}
    std::string DajZanr() const { return zanr;}
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    auto DajKodKogaJe() const {return pok;}
    void ZaduziKnjigu(Korisnik &neko) { pok = &neko;}
    void RazduziKnjigu () 
    {
        if(pok == nullptr) throw std::logic_error("Knjiga nije zaduzena");
        pok = nullptr;
        
    }
    bool DaLiJeZaduzena () { if(pok!=nullptr) return true;
        else return false;
    }
 
    
 };
 
 class Biblioteka
 {
    std::map<int , std::shared_ptr<Korisnik>> korisnici;
    std::map<int , std::shared_ptr<Knjiga>> knjige;
    auto NadjiKorisnikaPokazivac(int clanskibroj);

public:
    Biblioteka(){};
    Biblioteka (const Biblioteka &b);
    Biblioteka(Biblioteka &&b) 
    {         
        korisnici = b.korisnici;
        knjige = b.knjige;
    }

    Biblioteka &operator = (const Biblioteka b);
    Biblioteka &operator = (Biblioteka &&b);
    void RegistrirajNovogKorisnika (int clanskibroj, std::string ime, std::string prezime, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu (int evidencijskibroj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int clanskibroj);
    Knjiga &NadjiKnjigu(int evidencijskibroj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int clanskibroj, int evidencijskibroj);
    void RazduziKnjigu(int evidencijskibroj);
    void PrikaziZaduzenja(int clanskibroj);
    ~Biblioteka ();
 };


Biblioteka &Biblioteka::operator = ( Biblioteka b)
{

    std::swap(korisnici, b.korisnici);
    std::swap(knjige, b.knjige);
    return *this;
}
Biblioteka::Biblioteka (const Biblioteka &b)
{
    knjige = b.knjige;
    korisnici = b.korisnici;
    
}
Biblioteka &Biblioteka::operator =(Biblioteka &&b)
{
    if(&b!=this)
    {
        korisnici = b.korisnici;
        for(auto it = korisnici.begin();it!=korisnici.end();it++) it->second = nullptr;
        knjige = b.knjige;
        for(auto it = knjige.begin();it!=knjige.end();it++) it->second = nullptr;
    }
    return *this;
}
Biblioteka::~Biblioteka()
{
    for(auto it = korisnici.begin();it!=korisnici.end();it++)
        delete it->second;
    for(auto it = knjige.begin();it!=knjige.end();it++)
        delete it->second;

 }
void Biblioteka::RegistrirajNovogKorisnika(int clanskibroj, std::string ime, std::string prezime, std::string adresa, std::string telefon)
    {
        if(!korisnici.count(clanskibroj))
        {
            Korisnik *user(new Korisnik);
            user->ime = ime;
            user->prezime = prezime;
            user->adresa = adresa;
            user->telefon = telefon;
            korisnici.insert(std::make_pair(clanskibroj, user));  
        }
        else
        {
            throw std::logic_error("Korisnik vec postoji");
        }
    }
void Biblioteka::RegistrirajNovuKnjigu (int evidencijskibroj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja)
{
    if(!knjige.count(evidencijskibroj)) 
    {
        Knjiga *book(new Knjiga(naslov, ime_pisca, zanr, godina_izdavanja));
        knjige.insert(std::make_pair(evidencijskibroj, book));
    }
    else throw std::logic_error("Knjiga vec postoji");
    
}
Korisnik& Biblioteka::NadjiKorisnika(int clanskibroj) 
{
    if(!korisnici.count(clanskibroj)) throw std::logic_error("Korisnik nije nadjen");
    else
        {
            auto it(korisnici.find(clanskibroj));
            Korisnik *p = it->second;
            Korisnik &b(*p);
            p=nullptr;
            return b;
        }
}


Korisnik* Biblioteka::NadjiKorisnikaPokazivac(int clanskibroj)
{
    if(!korisnici.count(clanskibroj)) throw std::logic_error("Korisnik nije nadjen");
    else
        {
            auto it(korisnici.find(clanskibroj));
            return it->second;
        }
}


Knjiga& Biblioteka::NadjiKnjigu(int evidencijskibroj) 
{
    if(!knjige.count(evidencijskibroj)) throw std::logic_error("Knjiga nije nadjena");
    else
        {
            auto it(knjige.find(evidencijskibroj));
            Knjiga *p = it->second;
            Knjiga &b(*p);
            p = nullptr;
            return b;
        }
}

void Biblioteka::IzlistajKorisnike() const
{

    for(auto it = korisnici.begin();it!=korisnici.end();it++)
    {
        std::cout<<"Clanski broj: "<<it->first<<std::endl;
        std::cout<<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<std::endl;
        std::cout<<"Adresa: "<<(it->second)->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<(it->second)->telefon<<std::endl;
        std::cout<<std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const//DORADI
{
    for(auto it = knjige.begin();it!=knjige.end();it++)
    {
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<(it->second)->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<(it->second)->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<(it->second)->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl;
        if((it->second)->DaLiJeZaduzena() == true) 
        {
            std::cout<<"Zaduzena kod korisnika: "<<(it->second)->DajKodKogaJe()->ime<<" "<<(it->second)->DajKodKogaJe()->prezime<<std::endl;
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
void Biblioteka::ZaduziKnjigu(int evidencijskibroj, int clanskibroj)//PROBLEM
    {
        Knjiga& book(NadjiKnjigu(evidencijskibroj));
        Korisnik& user(NadjiKorisnika(clanskibroj));
        if(book.DaLiJeZaduzena() == true) throw std::logic_error("Knjiga vec zaduzena");
        book.ZaduziKnjigu(user);
        
    }
void Biblioteka::RazduziKnjigu(int evidencijskibroj)
{
    Knjiga &book (NadjiKnjigu(evidencijskibroj));
    book.RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clanskibroj)
{
    int br(0);
    for(auto it = knjige.begin();it!=knjige.end();it++)
    {
        if(NadjiKorisnikaPokazivac(clanskibroj) == (it->second)->DajKodKogaJe())
        {
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<(it->second)->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<(it->second)->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<(it->second)->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl;
            br++;
        }
        std::cout<<std::endl;

    }
    if(br==0)
    {
        std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
    }
    
    std::cout<<std::endl;
}
int main ()
{
    for(;;)
    {
        Biblioteka b;
        int broj;

        std::cout<<"Exit: 0 \n";
        std::cout<<"Registruj novog korisnika: 1 \n";
        std::cout<<"Registruj novu knjigu: 2 \n";
        std::cout<<"Prikazi zaduzenja: 3 \n";
        std::cout<<"Zaduzi knjigu: 4 \n";
        std::cout<<"Razduzi knjigu: 5 \n";
        std::cout<<"Izlistaj korisnike: 6 \n";
        std::cout<<"Izlistaj knjige: 7 \n";
        
        std::cin>>broj;
        if(broj == 0) break;
        if(broj == 1)
        {
            std::string s1, s2, s3, s4;
            int clanskibroj;
            std::cout<<"Clanski broj: ";
            std::cin>>clanskibroj;
            std::cout<<"Ime: ";
            std::cin>>s1;
            std::cout<<"Prezime: ";
            std::cin>>s2;
            std::cout<<"Adresa: ";
            std::cin>>s3;
            std::cout<<"Telefon: ";
            std::cin>>s4;
            b.RegistrirajNovogKorisnika(clanskibroj, s1, s2, s3,s4);
        }
        if(broj == 2)
        {
            std::string s1, s2, s3;
            int evidencijskibroj;
            int godina_izdavanja;
            std::cout<<"Evidencijski broj: ";
            std::cin>>evidencijskibroj;
            std::cout<<"Naslov: ";
            std::cin>>s1;
            std::cout<<"Ime pisca: ";
            std::cin>>s2;
            std::cout<<"Zanr: ";
            std::cin>>s3;
            std::cout<<"Godina izdavanja: ";
            std::cin>>godina_izdavanja;
            b.RegistrirajNovuKnjigu(evidencijskibroj, s1, s2, s3,godina_izdavanja);
        }
        if(broj == 3)
        {
            int clanskibroj;
            std::cout<<"Clanski broj: ";
            std::cin>>clanskibroj;
            b.PrikaziZaduzenja(clanskibroj);
        }
        if(broj == 4) 
        {
            int clanskibroj;
            std::cout<<"Clanski broj: ";
            std::cin>>clanskibroj;
            int evidencijskibroj;
            std::cout<<"Evidencijski broj: ";
            std::cin>>evidencijskibroj;
            b.ZaduziKnjigu(clanskibroj, evidencijskibroj);
        }
        if(broj == 5)
        {
            int evidencijskibroj;
            std::cout<<"Evidencijski broj: ";
            std::cin>>evidencijskibroj;
            b.RazduziKnjigu(evidencijskibroj);
            if(broj == 6) b.IzlistajKorisnike();
            if(broj == 7) b.IzlistajKnjige();
        }
    }
    return 0;
}