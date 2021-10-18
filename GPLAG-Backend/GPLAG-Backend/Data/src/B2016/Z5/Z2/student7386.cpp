/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <stdexcept>
#include <memory>

struct Korisnik
{
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};

class Knjiga
{
    private:
    std::string naslov;
    std::string autor;
    std::string zanr;
    int godinaizd;
    std::shared_ptr<Korisnik> pkorisnik;
    public:
    Knjiga(std::string knaslov, std::string kautor, std::string kzanr, int kgodinaizd)
    {
        naslov = knaslov;
        autor = kautor;
        zanr = kzanr;
        godinaizd = kgodinaizd;
        pkorisnik = nullptr;
    }
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return autor; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godinaizd; }
    std::shared_ptr<Korisnik> DajKodKogaJe() const { return pkorisnik; }
    void ZaduziKnjigu(Korisnik &k)
    {
        pkorisnik = std::make_shared<Korisnik>(k);
    }
    void RazduziKnjigu() { pkorisnik = nullptr; }
    bool DaLiJeZaduzena() const { return pkorisnik!=nullptr; }
};

class Biblioteka
{
    private:
    std::map<int, std::shared_ptr<Korisnik>> korisnici;
    std::map<int, std::shared_ptr<Knjiga>> knjige;
    public:
    Biblioteka()
    {
        korisnici = std::map<int, std::shared_ptr<Korisnik>>{};
        knjige = std::map<int,std::shared_ptr<Knjiga>>{};
    }
    Biblioteka(const Biblioteka &b)
    {
        
    }
    void RegistrirajNovogKorisnika(int clanski_br, std::string imek, std::string prezimek, std::string adresak, std::string telk);
    void RegistrirajNovuKnjigu(int,std::string,std::string,std::string,int);
    Korisnik &NadjiKorisnika(int) const;
    Knjiga &NadjiKnjigu(int) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int, int);
    void RazduziKnjigu(int);
    void PrikaziZaduzenja(int clanski_br) const;
    Biblioteka &operator = (Biblioteka &&b);
};


Biblioteka &Biblioteka::operator = (Biblioteka  &&b)
{
    *this = std::move(b);
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_br, std::string imek, std::string prezimek, std::string adresak, std::string telk)
{
    if(korisnici.count(clanski_br) > 0) throw std::logic_error("Korisnik vec postoji");
   std::shared_ptr<Korisnik> novikorisnik = std::make_shared<Korisnik>();
        novikorisnik->ime = imek;
        novikorisnik->prezime = prezimek;
        novikorisnik->adresa = adresak;
        novikorisnik->telefon = telk;
        korisnici.insert(std::make_pair(clanski_br,novikorisnik));
  
}

void Biblioteka::RegistrirajNovuKnjigu(int e_br, std::string naslovk, std::string pisack, std::string zanrk, int godinak)
{
    if(knjige.count(e_br) > 0) throw std::logic_error("Knjiga vec postoji");
    std::shared_ptr<Knjiga> novaknjiga = std::make_shared<Knjiga>(naslovk,pisack,zanrk,godinak);
  
 knjige.insert(std::make_pair(e_br,novaknjiga));
   
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_br) const
{
    if(korisnici.count(clanski_br) > 0)
    {
        auto it = korisnici.find(clanski_br);
        return *(it->second);
    }
    else
    {
        throw std::logic_error("Korisnik nije nadjen");
    }
}

Knjiga &Biblioteka::NadjiKnjigu(int e_br) const
{
    if(knjige.count(e_br) > 0)
    {
        auto it = knjige.find(e_br);
        return *(it->second);
    }
    else
    {
        throw std::logic_error("Knjiga nije nadjena");
    }
}

void Biblioteka::IzlistajKorisnike() const
{
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
    {
        std::cout << "Clanski broj: " << it->first << std::endl;
        std::cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl;
        std::cout << "Adresa: " << it->second->adresa << std::endl;
        std::cout << "Broj telefona: " << it->second->telefon << std::endl << std::endl;
    }
}

void Biblioteka::IzlistajKnjige() const
{
    for(auto it=knjige.begin(); it!=knjige.end(); it++)
    {
        std::cout << "Evidencijski broj: " << it->first << std::endl;
        std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
        std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
        if(it->second->DaLiJeZaduzena())
        {
            std::cout << "Zaduzena kod korisnika: ";
            std::cout << it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int e_br, int clanski_br)
{
    if(knjige.count(e_br) == 0) throw std::logic_error("Knjiga nije nadjena");
    if(korisnici.count(clanski_br) == 0) throw std::logic_error("Korisnik nije nadjen");
    auto it = knjige.find(e_br);
    if(it->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    auto zaduzenik = korisnici.find(clanski_br)->second;
    it->second->ZaduziKnjigu(*zaduzenik);
}

void Biblioteka::RazduziKnjigu(int e_br)
{
    if(knjige.count(e_br) == 0) throw std::logic_error("Knjiga nije nadjena");
    auto it = knjige.find(e_br);
    if(it->second->DaLiJeZaduzena() == false) throw std::logic_error("Knjiga nije zaduzena");
    it->second->RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int clanski_br) const
{
    if(korisnici.count(clanski_br) == 0) throw std::logic_error("Korisnik nije nadjen");
    int br = 0;
    for(auto it=knjige.begin(); it!=knjige.end(); it++)
    {
        if(it->second->DajKodKogaJe() == korisnici.find(clanski_br)->second)
        {
            br++;
            std::cout << "Evidencijski broj: " << it->first << std::endl;
            std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
            std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
            std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
        }
        std::cout << std::endl;
    }
    if(br==0) throw std::logic_error("Nema zaduzenja za tog korisnika!");
}

int main ()
{
    Biblioteka svjetlost;
    std::cout << "1-Unesite korisnika, 2-Unesite knjigu, 3-Unesi zaduzenje, 4-Unesi razduzenje" << std::endl;
    std::cout << "5-Izlistaj korisnike, 6-Izlistaj knjige ili neki drugi broj za kraj\n";
    int k=1;
    while(k!=0)
    {
        std::cout << "Unesite opciju: ";
        int n;
        std::cin >> n;
        switch(n)
        {
            case 1:
            {
                std::cout << "Unesite clanski broj, ime, prezime, adresu i br telefona redom(svaki podatak u zaseban red): ";
                int clanski;
                std::string imee;
                std::string prezimee;
                std::string adresaa;
                std::string brtell;
                std::cin >> clanski;
                std::cin.ignore(1000,'\n');
                std::getline(std::cin, imee);
        
                std::getline(std::cin, prezimee);
                
                std::getline(std::cin, adresaa);
               
                std::getline(std::cin,brtell);
               
                svjetlost.RegistrirajNovogKorisnika(clanski,imee,prezimee,adresaa,brtell);
            break;
            }
            case 5:
            {
                svjetlost.IzlistajKorisnike();
                break;
            }
            case 2:
            {
                std::cout << "Unesite evidencijski broj, naslov, pisca, zanr, godinu redom(svaki podatak u novi red): ";
                int evid;
                std::string naslovv;
                std::string pisacc;
                std::string zanrr;
                int godina;
                std::cin >> evid;
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, naslovv);
                std::getline(std::cin, pisacc);
                std::getline(std::cin, zanrr);
                std::cin >> godina;
                svjetlost.RegistrirajNovuKnjigu(evid,naslovv,pisacc,zanrr,godina);
                break;
            }
            case 6:
            {
                svjetlost.IzlistajKnjige();
                break;
            }
            case 3:
            {
                std::cout << "Unesite clanski broj korisnika i evidencijski broj knjige: ";
                int a,b;
                std::cin >> a >> b;
                svjetlost.ZaduziKnjigu(a,b);
                break;
            }
            case 4:
            {
                std::cout << "Unesite evidencijski broj knjige: ";
                int a;
                std::cin >> a;
                svjetlost.RazduziKnjigu(a);
                break;
            }
            default:
            {
                k=0;
                break;
            }
        }
    }
	return 0;
}