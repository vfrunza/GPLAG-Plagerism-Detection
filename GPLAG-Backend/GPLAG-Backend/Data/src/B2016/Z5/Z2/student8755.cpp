/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <stdexcept>
#include <new>
#include <iterator>
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
    std::string naslov;
    std::string pisac;
    std::string zanr;
    int godina;
    Korisnik *zaduzenje=nullptr;
    
        public:
    Knjiga(std::string naslov_knjige, std::string ime_pisca, std::string zanr_knjige, int g)
        : naslov(naslov_knjige), pisac(ime_pisca), zanr(zanr_knjige), godina(g) {}
    
    std::string DajNaslov() const{return naslov;}
    std::string DajAutora() const{return pisac;}
    std::string DajZanr() const{return zanr;}
    int DajGodinuIzdavanja() const{return godina;}
    
    void ZaduziKnjigu(Korisnik &osoba){zaduzenje=&osoba;}
    void RazduziKnjigu(){zaduzenje=nullptr;}
    bool DaLiJeZaduzena()const{return zaduzenje;}
    Korisnik* DajKodKogaJe() const{return zaduzenje;}
};
class Biblioteka
{
    std::map<int, std::shared_ptr<Korisnik>> m_korisnik;
    std::map<int, std::shared_ptr<Knjiga>> m_knjiga;
        public:
    Biblioteka():m_korisnik(), m_knjiga(){}
    Biblioteka(Biblioteka &bible);
    Biblioteka(Biblioteka &&bible);
    Biblioteka operator=(Biblioteka bible);
    void RegistrirajNovogKorisnika(int cb, std::string ime, std::string prezime, std::string adresa, std::string tel);
    void RegistrirajNovuKnjigu(int eb, std::string naslov, std::string pisac, std::string zanr, int g);
    Korisnik& NadjiKorisnika (const int &cb) const{if(m_korisnik.count(cb)) return *(m_korisnik.find(cb)->second); else throw std::logic_error("Korisnik nije nadjen");}
    Knjiga& NadjiKnjigu(const int &eb) const{if(m_knjiga.count(eb)) return *(m_knjiga.find(eb)->second); else throw std::logic_error("Knjiga nije nadjena");};
    void IzlistajKorisnike();
    void IzlistajKnjige();
    void ZaduziKnjigu(const int &eb, const int &cb);
    void RazduziKnjigu(const int &eb);
    void PrikaziZaduzenja(const int &cb);
    
};
Biblioteka::Biblioteka(Biblioteka &bible)
{
    for(auto it=bible.m_korisnik.begin(); it!=bible.m_korisnik.end(); it++)
        m_korisnik.insert(std::make_pair(it->first, std::shared_ptr<Korisnik>(new Korisnik{it->second->ime, it->second->prezime, it->second->adresa, it->second->telefon})));
    for(auto it=bible.m_knjiga.begin(); it!=bible.m_knjiga.end(); it++)
        m_knjiga.insert(std::make_pair(it->first, std::shared_ptr<Knjiga>(new Knjiga{it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja()})));
}
Biblioteka::Biblioteka(Biblioteka &&bible)
{
    for(auto it=bible.m_korisnik.begin(); it!=bible.m_korisnik.end(); it++)
    {
        m_korisnik.insert(std::make_pair(it->first, it->second));
        it->second=nullptr;
    }
    for(auto it=bible.m_knjiga.begin(); it!=bible.m_knjiga.end(); it++)
    {
        m_knjiga.insert(std::make_pair(it->first, it->second));
        it->second=nullptr;
    }
}
Biblioteka Biblioteka::operator =(Biblioteka bible)
{
    if(this!=&bible)
    {
        std::swap(m_knjiga, bible.m_knjiga); std::swap(m_korisnik, bible.m_korisnik);
    }
    return *this;
}
void Biblioteka::RegistrirajNovogKorisnika(int cb, std::string ime, std::string prezime, std::string adresa, std::string tel)
{
    if((m_korisnik.count(cb))) throw std::logic_error("Korisnik vec postoji");
    std::shared_ptr<Korisnik> user(new Korisnik{ime, prezime, adresa, tel});
    m_korisnik.insert(std::make_pair(cb, user));
}
void Biblioteka::RegistrirajNovuKnjigu(int eb, std::string naslov, std::string pisac, std::string zanr, int g)
{
    if((m_knjiga.count(eb)))     throw std::logic_error("Knjiga vec postoji");
    std::shared_ptr<Knjiga> book(new Knjiga(naslov, pisac, zanr,g));
    m_knjiga.insert(std::make_pair(eb, book));
}
void Biblioteka::IzlistajKorisnike()
{
    
    for(auto it=m_korisnik.begin(); it!=m_korisnik.end(); it++)
    {
        std::cout<<"Clanski broj: "<<it->first<<std::endl;
        std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
        std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
        std::cout<<std::endl;
    }
}
void Biblioteka::IzlistajKnjige()
{
    for(auto it=m_knjiga.begin(); it!=m_knjiga.end(); it++)
    {
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
        if(it->second->DaLiJeZaduzena()) std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime;
        std::cout<<std::endl;
        std::cout<<std::endl;
    }
}
void Biblioteka::PrikaziZaduzenja(const int &cb)
{
    bool NijePronadjen(true);   
    for(auto it=m_knjiga.begin(); it!=m_knjiga.end(); it++)
    {
        if(it->second->DaLiJeZaduzena() && &*(m_korisnik[cb])==(it->second->DajKodKogaJe()))
        {
            NijePronadjen=false;   
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
        }
        
    }
    if(NijePronadjen)   std::cout<<"Nema zaduzenja za tog korisnika";
}
void Biblioteka::ZaduziKnjigu(const int &eb, const int &cb)
{
    if(!m_knjiga.count(eb)) throw std::logic_error("Knjiga nije nadjena");
    else if(!m_korisnik.count(cb)) throw std::logic_error("Korisnik nije nadjen");
    else if(m_knjiga.find(eb)->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    else m_knjiga.find(eb)->second->ZaduziKnjigu(*(m_korisnik[cb]));
}
void Biblioteka::RazduziKnjigu(const int &eb)
{
    if(!m_knjiga.count(eb)) throw std::logic_error("Knjiga nije nadjena");
    else if(!m_knjiga.find(eb)->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
    else m_knjiga.find(eb)->second->RazduziKnjigu();
}
int main ()
{
}