/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <new>
#include <algorithm>
#include <stdexcept>
#include <iterator>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;  
};

class Knjiga {
    std::string naslov, pisac, zanr;
    int godina_izdavanja;
    Korisnik* zaduzenik{nullptr};
public:
    Knjiga(std::string naslov, std::string pisac, std::string zanr, int god) : naslov(naslov), pisac(pisac), zanr(zanr), godina_izdavanja(god) {}
    std::string DajNaslov() const {return naslov;}
    std::string DajAutora() const {return pisac;}
    std::string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdavanja;}
    Korisnik* DajKodKogaJe() const {return zaduzenik;}
    void ZaduziKnjigu(Korisnik& citac);
    void RazduziKnjigu();
    bool DaLiJeZaduzena();
};

void Knjiga::ZaduziKnjigu(Korisnik& citac) {
    zaduzenik = &citac;
}
void Knjiga::RazduziKnjigu() {
    zaduzenik = nullptr;
}
bool Knjiga::DaLiJeZaduzena() {
    return zaduzenik;
}

class Biblioteka {
    std::map<int, Korisnik*> m_korisnika;
    std::map<int, Knjiga*> m_knjiga;
public:
    ~Biblioteka();
    Biblioteka& operator = (const Biblioteka &b);
    Biblioteka& operator = (Biblioteka &&b);
    void RegistrirajNovogKorisnika(int cl_br, std::string ime, std::string prezime, std::string adresa, std::string brtel);
    void RegistrirajNovuKnjigu(int ev_br, std::string naslov, std::string autor, std::string zanr, int god_izdavanja);
    Korisnik& NadjiKorisnika(int clanski_br) const;
    Knjiga& NadjiKnjigu(int evidencijski_br) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int ev_broj, int cl_broj);
    void RazduziKnjigu(int ev_broj);
    void PrikaziZaduzenja(int cl_broj) const;
};
Biblioteka::~Biblioteka() {
    for(auto it = m_korisnika.begin(); it != m_korisnika.end(); it++)
        delete it->second;
    for(auto it = m_knjiga.begin(); it != m_knjiga.end(); it++)
        delete it->second;
}
Biblioteka& Biblioteka::operator = (const Biblioteka &b) {
    if(&b != this){
    std::map<int, Korisnik*> tmp_korisnika;
    std::map<int, Knjiga*> tmp_knjiga;
    try{
        for(auto it = b.m_korisnika.begin(); it != b.m_korisnika.end(); it++)
            tmp_korisnika[it->first] = new Korisnik (*it->second);
        for(auto it = b.m_knjiga.begin(); it != b.m_knjiga.end(); it++)
            tmp_knjiga[it->first] = new Knjiga (*it->second);
    }
    catch(std::bad_alloc) {
        for(auto it = tmp_korisnika.begin(); it != tmp_korisnika.end(); it++)
            delete it->second;
        for(auto it = tmp_knjiga.begin(); it != tmp_knjiga.end(); it++)
        throw;
    }
    for(auto it = m_korisnika.begin(); it != m_korisnika.end(); it++)
        delete it->second;
    for(auto it = m_knjiga.begin(); it != m_knjiga.end(); it++)
        delete it->second;
    m_korisnika = tmp_korisnika;
    m_knjiga = tmp_knjiga;
    for(auto it = b.m_knjiga.begin(); it != b.m_knjiga.end(); it++) {
        for(auto it2 = b.m_korisnika.begin(); it2 != b.m_korisnika.end(); it2++)
            if(it->second->DajKodKogaJe() == it2->second) {
                auto it3(m_korisnika.begin());
                std::advance(it3, std::distance(b.m_korisnika.begin(), it2));
                m_knjiga[it->first]->ZaduziKnjigu(*it3->second);
            }
    }
    }
    return *this;
}

Biblioteka& Biblioteka::operator =(Biblioteka &&b) {
    std::swap(m_korisnika, b.m_korisnika);
    std::swap(m_knjiga, b.m_knjiga);
    return *this;
}
void Biblioteka::RegistrirajNovogKorisnika(int cl_br, std::string ime, std::string prezime, std::string adresa, std::string brtel) {
   if(m_korisnika.count(cl_br)) throw std::logic_error("Korisnik vec postoji");
    try{
        m_korisnika[cl_br] = new Korisnik{ime, prezime, adresa, brtel};
    }
    catch(std::bad_alloc) {
        throw;
    }
}
void Biblioteka::RegistrirajNovuKnjigu(int ev_br, std::string naslov, std::string autor, std::string zanr, int god_izdavanja) {
    if(m_knjiga.count(ev_br)) throw std::logic_error("Knjiga vec postoji");
    try{
        m_knjiga[ev_br] = new Knjiga(naslov, autor, zanr, god_izdavanja);
    }
    catch(std::bad_alloc) {
        throw;
    }
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski_br) const {
    auto it(m_korisnika.find(clanski_br));
    if(it == m_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    return *(it->second);
}
Knjiga &Biblioteka::NadjiKnjigu(int ev_br) const {
    auto it(m_knjiga.find(ev_br));
    if(it == m_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    return *(it->second);
}
void Biblioteka::IzlistajKorisnike() const {
    for(auto it = m_korisnika.begin(); it != m_korisnika.end(); it++) {
        std::cout << "Clanski broj: " << it->first;
        std::cout << "\nIme i prezime: " << it->second->ime << " " << it->second->prezime;
        std::cout << "\nAdresa: " << it->second->adresa;
        std::cout << "\nBroj telefona: " << it->second->telefon << std::endl << std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const {
    for(auto it = m_knjiga.begin(); it != m_knjiga.end(); it++) {
        std::cout << "Evidencijski broj: " << it->first;
        std::cout << "\nNaslov: " << it->second->DajNaslov();
        std::cout << "\nPisac: " << it->second->DajAutora();
        std::cout << "\nZanr: " << it->second->DajZanr();
        std::cout << "\nGodina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
        if(it->second->DaLiJeZaduzena()) std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime << std::endl;
        std::cout << std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int ev_br, int cl_br) {
    if(!m_knjiga.count(ev_br)) throw std::logic_error("Knjiga nije nadjena");
    if(!m_korisnika.count(cl_br)) throw std::logic_error("Korisnik nije nadjen");
    if(m_knjiga[ev_br]->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    m_knjiga[ev_br]->ZaduziKnjigu(*m_korisnika[cl_br]);
}
void Biblioteka::RazduziKnjigu(int ev_br) {
    if(!m_knjiga.count(ev_br)) throw std::logic_error("Knjiga nije nadjena");
    if(!m_knjiga[ev_br]->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
    delete m_knjiga[ev_br];
    m_knjiga[ev_br]->RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int cl_br) const {
    auto i(m_korisnika.find(cl_br));
    if(i == m_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    bool nadjen(false);
    for(auto it = m_knjiga.begin(); it != m_knjiga.end(); it++) {
        if(it->second->DajKodKogaJe() == &NadjiKorisnika(cl_br)) {
            std::cout << "Evidencijski broj: " << it->first;
            std::cout << "\nNaslov: " << it->second->DajNaslov();
            std::cout << "\nPisac: " << it->second->DajAutora();
            std::cout << "\nZanr: " << it->second->DajZanr();
            std::cout << "\nGodina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl << std::endl;
            nadjen = true;
        }
    }
    if(!nadjen) std::cout << "Nema zaduzenja za tog korisnika!";
}

int main ()
{
    try{
    Biblioteka b;
    b.RegistrirajNovogKorisnika(100, "abc", "abc", "abc", "abc");
    b.RegistrirajNovogKorisnika(20, "efg", "ef", "ef", "ef");
    b.RegistrirajNovuKnjigu(5, "abc", "abc", "abc", 123);
    b.RegistrirajNovuKnjigu(6, "abc", "abc", "abc", 567);
    b.RegistrirajNovuKnjigu(1, "a", "a", "a", 13);
    b.ZaduziKnjigu(5, 100);
    b.ZaduziKnjigu(6, 100);
    b.ZaduziKnjigu(1, 20);
    Biblioteka c;
    c = b;
    c.PrikaziZaduzenja(100);
    }
    catch(std::logic_error) {
    }
    catch(std::bad_alloc){
    }
    
   
	return 0;
}