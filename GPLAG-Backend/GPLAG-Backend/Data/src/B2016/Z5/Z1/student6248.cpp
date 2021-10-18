/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <stdexcept>

struct Korisnik
{
    std::string ime,prezime,adresa,telefon;
};

class Knjiga
{
    std::string naslov,ime,zanr;
    int godina_izd;
    Korisnik *p=nullptr;
    public:
    Knjiga(std::string nas, std::string ime_p,std::string z,int godina)
    {
        naslov=nas; ime=ime_p; zanr=z; godina_izd=godina; p=nullptr;
    }
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return ime; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izd; }
    Korisnik *DajKodKogaJe() const { return p; }
    void ZaduziKnjigu(Korisnik &k)
    {
        p=&k;
    }
    void RazduziKnjigu()
    {
        p=nullptr;
    }
    bool DaLiJeZaduzena()
    {
        if(p==nullptr) return false;
        else return true;
    }
};

class Biblioteka
{
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
    public:
    Biblioteka() {}
    Biblioteka(const Biblioteka &b)
    {
        auto it(b.korisnici.begin());
        while(it!=b.korisnici.end())
        {
            int broj(it->first);
            Korisnik *pom(nullptr);
            try
            {
            pom=new Korisnik;
            pom->ime=it->second->ime;
            pom->prezime=it->second->prezime;
            pom->adresa=it->second->adresa;
            pom->telefon=it->second->telefon;
            korisnici.insert(std::make_pair(broj,pom));
            delete pom;
            }
            catch(...)
            {
                delete pom;
            }
            it++;
        }
        auto it2(b.knjige.begin());
        while(it2!=b.knjige.end())
        {
            int broj(it2->first);
            Knjiga *pom(nullptr);
            pom=new Knjiga(it2->second->DajNaslov(),it2->second->DajAutora(),it2->second->DajZanr(),it2->second->DajGodinuIzdavanja());
            knjige.insert(std::make_pair(broj,pom));
            delete pom;
            it2++;
        }
    }
    Biblioteka(Biblioteka &&b)
    {
        auto it(b.korisnici.begin());
        while(it!=b.korisnici.end())
        {
            int broj(it->first);
            Korisnik *pomocni(nullptr);
            pomocni=it->second;
            korisnici.insert(std::make_pair(broj,pomocni));
            it->second=nullptr;
            it++;
        }
        auto it2(b.knjige.begin());
        while(it2!=b.knjige.end())
        {
            int broj(it2->first);
            Knjiga *pomocni(nullptr);
            pomocni=it2->second;
            knjige.insert(std::make_pair(broj,pomocni));
            it2->second=nullptr;
            it2++;
        }
    }
    Biblioteka &operator =(const Biblioteka &b)
    {
        
        return *this;
    }
    Biblioteka &operator =(Biblioteka &&b)
    {
        return *this;
    }
    ~Biblioteka()
    {
        auto it(korisnici.begin());
        while(it!=korisnici.end())
        {
            delete it->second;
            it++;
        }
        auto it2(knjige.begin());
        while(it2!=knjige.end())
        {
            delete it2->second;
            it2++;
        }
    }
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon)
    {
        auto it(korisnici.begin());
        while(it!=korisnici.end())
        {
            if(clanski_broj==it->first) throw std::logic_error("Korisnik vec postoji");
            it++;
        }
        Korisnik *novi(nullptr);
        novi=new Korisnik;
        novi->ime=ime;
        novi->prezime=prezime;
        novi->adresa=adresa;
        novi->telefon=telefon;
        korisnici.insert(std::make_pair(clanski_broj,novi));
        delete novi;
    }
    void RegistrirajNovuKnjigu(int broj_knjige, std::string naslov, std::string pisac, std::string zanr, int godina)
    {
        auto it(knjige.begin());
        while(it!=knjige.end())
        {
            if(broj_knjige==it->first) throw std::logic_error("Knjiga vec postoji");
            it++;
        }
        Knjiga *nova(nullptr);
        nova=new Knjiga(naslov,pisac,zanr,godina);
        knjige.insert(std::make_pair(broj_knjige,nova));
        delete nova;
    }
    Korisnik &NadjiKorisnika(int clanski_broj)
    {
        bool ima(false);
        auto it(korisnici.begin());
        while(it!=korisnici.end())
        {
            if(clanski_broj==it->first) { ima=true; break; }
            else ima=false;
            it++;
        }
        if(ima==false) throw std::logic_error("Korisnik nije nadjen");
        return *it->second;
    }
    Knjiga &NadjiKnjigu(int broj_knjige)
    {
        bool ima(false);
        auto it(knjige.begin());
        while(it!=knjige.end())
        {
            if(broj_knjige==it->first) { ima=true; break; }
            else ima=false;
            it++;
        }
        if(ima==false) throw std::logic_error("Knjiga nije nadjena");
        return *it->second;
    }
    void IzlistajKorisnike() const 
    {
        auto it(korisnici.begin());
        while(it!=korisnici.end())
        {
            std::cout << "Clanski broj: " << it->first << std::endl;
            std::cout << "Ime i prezime: " << it->second->ime << it->second->prezime << std::endl;
            std::cout << "Adresa: " << it->second->adresa << std::endl << "Telefon: " << it->second->telefon << std::endl;
            it++;
        }
    }
    void IzlistajKnjige() const
    {
        auto it(knjige.begin());
        while(it!=knjige.end())
        {
            std::cout << "Evidencijski broj: " << it->first << std::endl;
            std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
            std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
            std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
            std::cout << "Godina: " << it->second->DajGodinuIzdavanja() << std::endl;
            it++;
        }
    }
};

int main ()
{
    Biblioteka b;
    b.RegistrirajNovogKorisnika(1,"Niko","Nikic","Zmaja od Bosne bb","123 456");
    b.RegistrirajNovuKnjigu(2,"Vlak u snijegu","Mato Lovrak","Roman",1931);
    std::cout << "Ime korisnika: " << b.NadjiKorisnika(1).ime << std::endl;
    std::cout << "Godina izdavanja: " << b.NadjiKnjigu(2).DajGodinuIzdavanja() << std::endl;
    b.IzlistajKorisnike();
    b.IzlistajKnjige();
	return 0;
}