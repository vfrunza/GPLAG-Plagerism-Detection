/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <memory>

struct Korisnik
{
    std::string ime, prezime, adresa, telefon;
    Korisnik(std::string ime, std::string prezime, std::string adresa, std::string br): ime(ime), prezime(prezime), adresa(adresa), telefon(br){}
};

class Knjiga
{
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    //Korisnik *korisnik;
    std::shared_ptr<Korisnik> korisnik;
public:
    Knjiga(std::string naslov, std::string autor, std::string zanr, int godina): naslov(naslov), ime_pisca(autor), zanr(zanr),godina_izdavanja(godina),korisnik(nullptr){}
    ~Knjiga() =default;//{delete korisnik;}
    std::string DajNaslov() const { return naslov;}
    std::string DajAutora() const { return ime_pisca;}
    std::string DajZanr() const { return zanr;}
    int DajGodinuIzdavanja() const { return godina_izdavanja;}
    std::shared_ptr<Korisnik> DajKodKogaJe() const { return korisnik;}
    void ZaduziKnjigu(Korisnik &k)
    {
         korisnik = std::make_shared<Korisnik>(k.ime, k.prezime, k.adresa, k.telefon);
    }
    void RazduziKnjigu() { korisnik=nullptr;}
    bool DaLiJeZaduzena() 
    { 
        if(korisnik!=nullptr) return true;
        return false;
    }
};

class Biblioteka
{
    std::map<int, std::shared_ptr<Korisnik>> korisnik;
    std::map<int, std::shared_ptr<Knjiga>> knjiga;
public:
    friend class Knjiga;
    //kopirajuci, pomjerajuci
    ~Biblioteka()=default;
   /* {
        for(auto it=korisnik.begin();it!=korisnik.end();it++)
            delete it->second;
        for(auto it=knjiga.begin();it!=knjiga.end();it++)
            delete it->second;
    }*/
    void RegistrirajNovogKorisnika(int clanski, std::string ime, std::string prezime, std::string adresa, std::string br)
    {
        auto p= std::make_shared <Korisnik>(ime, prezime, adresa, br); //dodati u try
        auto it(korisnik.find(clanski));
        if(it!=korisnik.end()) throw std::logic_error("Korisnik vec postoji");
        else
            korisnik[clanski]=p;
    }
    void RegistrirajNovuKnjigu(int evidencija, std::string naslov, std::string autor, std::string zanr, int god)
    {
        auto p= std::make_shared<Knjiga>(naslov, autor, zanr, god);
        auto it(knjiga.find(evidencija));
        if(it!=knjiga.end()) throw std::logic_error("Knjiga vec postoji");
        else
            knjiga[evidencija]=p;
    }
    
    Korisnik &NadjiKorisnika(int clanski)
    {
        auto it(korisnik.find(clanski));
        if(it==korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
        else
            return *(it->second);
    }
    Knjiga &NadjiKnjigu(int evidencija)
    {
        auto it(knjiga.find(evidencija));
        if(it==knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
        else
            return *(it->second);
    }
    void IzlistajKorisnike() const 
    {
        for(auto it=korisnik.begin(); it!=korisnik.end();it++)
        {
            std::cout << "Clanski broj: "<<it->first << std::endl;
            std::cout << "Ime i prezime: "<<it->second->ime <<" "<<it->second->prezime<< std::endl;
            std::cout << "Adresa: "<<it->second->adresa << std::endl;
            std::cout << "Broj telefona: "<<it->second->telefon << std::endl;
            std::cout  << std::endl;
        }
        
    }
    void IzlistajKnjige() const
    {
        for(auto  it=knjiga.begin(); it!=knjiga.end();it++)
        {
            std::cout << "Evidencijski broj: "<<it->first << std::endl;
            std::cout << "Naslov: "<<it->second->DajNaslov() << std::endl;
            std::cout << "Pisac: " <<it->second->DajAutora()<< std::endl;
            std::cout << "Zanr: " <<it->second->DajZanr()<< std::endl;
            std::cout << "Godina izdavanja: "<<it->second->DajGodinuIzdavanja() << std::endl;
            if(it->second->DaLiJeZaduzena()==1)
                std::cout << "Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime <<" "<< it->second->DajKodKogaJe()->prezime<<std::endl;
            std::cout << std::endl;
        }
        
    }
    void ZaduziKnjigu(int evidencija, int clanski)
    {
        auto i(NadjiKnjigu(evidencija));
        auto j(NadjiKorisnika(clanski));
        auto it(knjiga.find(evidencija));
        if(it->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
        else
            it->second->ZaduziKnjigu(j);

    }
    void RazduziKnjigu(int evidencija)
    {
        auto i(NadjiKnjigu(evidencija));
        auto it(knjiga.find(evidencija));
        if(!it->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
        else
            it->second->RazduziKnjigu();
    }
    void PrikaziZaduzenja(int clanski) const;
};

void Biblioteka::PrikaziZaduzenja(int clanski) const
{
    auto a(korisnik.find(clanski));
    if(a==korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
    else
    {
        for(auto it=korisnik.begin();it!=korisnik.end();it++)
        {
            for(auto i=knjiga.begin(); i!=knjiga.end();i++)
            {
                if(i->second->DaLiJeZaduzena())
                {
                    if((it->second->ime== i->second->DajKodKogaJe()->ime) && (it->second->prezime== i->second->DajKodKogaJe()->prezime))
                    {
                        std::cout << "Evidencijski broj: "<<i->first << std::endl;
                        std::cout << "Naslov: "<<i->second->DajNaslov() << std::endl;
                        std::cout << "Pisac: " <<i->second->DajAutora()<< std::endl;
                        std::cout << "Zanr: " <<i->second->DajZanr()<< std::endl;
                         std::cout << "Godina izdavanja: "<<i->second->DajGodinuIzdavanja() << std::endl;
                    }
                }
            }
        }
    }
}

int main()
{
    std::cout << "Radi" << std::endl;
}