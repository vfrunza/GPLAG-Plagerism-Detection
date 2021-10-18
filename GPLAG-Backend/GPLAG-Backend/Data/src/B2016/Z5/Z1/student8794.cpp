/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>

struct Korisnik {
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};

class Knjiga
{
    std::string naslov;
    std::string ime_pisca;
    std::string zanr;
    int godina_izdavanja;
    Korisnik* kod_koga_je;
public :
    Knjiga (std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja),kod_koga_je(nullptr) {}

    std::string DajNaslov () const {
        return naslov;
    }
    std::string DajAutora () const {
        return ime_pisca;
    }
    std::string DajZanr () const {
        return zanr;
    }
    int DajGodinuIzdavanja () const {
        return godina_izdavanja;
    }
    Korisnik* DajKodKogaJe () const {
        return kod_koga_je;
    }
    void ZaduziKnjigu (Korisnik &k) {
        kod_koga_je = &k;
    }
    void RazduziKnjigu ()  {
        kod_koga_je = nullptr;
    }
    bool DaLiJeZaduzena () const {
        return kod_koga_je;
    }
};

class Biblioteka
{
    std::map<int,Knjiga*> knjige;
    std::map<int,Korisnik*> korisnici;
    static void Ispis_knjige(const Knjiga &k,int broj_k,bool test=true) {
        std::cout << "Evidencijski broj: " << broj_k <<std::endl;
        std::cout << "Naslov: " << k.DajNaslov() <<std::endl;
        std::cout << "Pisac: " << k.DajAutora() <<std::endl;
        std::cout << "Zanr: " << k.DajZanr() <<std::endl;
        std::cout << "Godina izdavanja: " << k.DajGodinuIzdavanja() <<std::endl;    
        if (test and k.DaLiJeZaduzena()) {
            std::cout << "Zaduzena kod korisnika: " << k.DajKodKogaJe()->ime << " " << k.DajKodKogaJe()->prezime << std::endl;
        }
    }
    static void Ispis_korisnika(const Korisnik &k,int broj_k) {
        std::cout << "Clanski broj: " << broj_k <<std::endl;
        std::cout << "Ime i prezime: " << k.ime << " "  << k.prezime <<std::endl;
        std::cout << "Adresa: " << k.adresa <<std::endl;
        std::cout << "Broj telefona: " << k.telefon <<std::endl;
        
    }
public :
    ~Biblioteka() {
        for (auto &i : korisnici) {
            delete i.second;
        }
        for (auto &i : knjige) {
            delete i.second;
        }
    }
    Biblioteka() = default;
    Biblioteka (const Biblioteka &b);
    Biblioteka operator = (Biblioteka b) {
        std::swap(knjige,b.knjige);
        std::swap(korisnici,b.korisnici);
        return *this;
    }
    Biblioteka &operator = (Biblioteka &&b) = default;
    void RegistrirajNovogKorisnika (int clanski_broj, std::string ime,std::string prezime, std::string adresa,std::string telefon) {
        if(korisnici.count(clanski_broj)) throw std::logic_error ("Korisnik vec postoji");
        korisnici.insert(std::make_pair(clanski_broj,new Korisnik{ime,prezime,adresa,telefon}));
    }
    void RegistrirajNovuKnjigu (int clanski_broj, std::string naslov,std::string ime_pisca, std::string zanr,int godina_izdavanja) {
        if(knjige.count(clanski_broj)) throw std::logic_error ("Knjiga vec postoji");
        knjige.insert(std::make_pair(clanski_broj,new Knjiga(naslov,ime_pisca,zanr,godina_izdavanja)));
    }
    Korisnik &NadjiKorisnika(int clanski_broj) {
        if(korisnici.count(clanski_broj) == 0) throw std::logic_error ("Korisnik nije nadjen");
        return *(korisnici.find(clanski_broj))->second;
    }
    Knjiga &NadjiKnjigu(int clanski_broj) {
        if(knjige.count(clanski_broj) == 0) throw std::logic_error ("Knjiga nije nadjena");
        return *(knjige.find(clanski_broj))->second;
    }
    void IzlistajKnjige() {
        for (auto &i : knjige) {
            Ispis_knjige(*i.second,i.first); std::cout  << std::endl;
        }
    }
    void IzlistajKorisnike() {
        for (auto &i : korisnici) {
            Ispis_korisnika(*i.second,i.first); std::cout  << std::endl;
        }
    }
    void ZaduziKnjigu (int broj_knjige, int broj_korisnika) {
        
        for (auto &j : korisnici) {
            if(j.first == broj_korisnika) {
                for (auto &i : knjige) {
                    if (i.first == broj_knjige) {
                        if (i.second->DaLiJeZaduzena()) throw std::logic_error ("Knjiga vec zaduzena");
                        i.second->ZaduziKnjigu(*j.second);
                        return;
                    }
                } // Trazimo knjigu
                throw std::logic_error ("Knjiga nije nadjena");
            } 
        } 
        throw std::logic_error ("Korisnik nije nadjen");
    }
    void RazduziKnjigu(int broj_knjige) {
        for (auto &i : knjige) {
            if(i.first == broj_knjige) {
                if (!i.second->DaLiJeZaduzena()) throw std::logic_error ("Knjiga nije zaduzena");
                i.second->RazduziKnjigu();
                return;
            }
        }
        throw std::logic_error ("Knjiga nije nadjena");
    }
    void PrikaziZaduzenja (int broj_korisnika) {
        bool flag(false);
        auto t(korisnici.find(broj_korisnika));
        if(korisnici.find(broj_korisnika) == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        for (auto &i : knjige) {
            if(i.second->DajKodKogaJe() and i.second->DajKodKogaJe() == t->second) {
                if(!flag) flag = true;
                Ispis_knjige(*i.second,i.first,false); std::cout << std::endl;
            }
        }
        if (!flag) std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
    }

};
Biblioteka::Biblioteka (const Biblioteka &b)
{
    for (auto &i : b.knjige) {
        knjige.insert(std::make_pair(i.first,nullptr));
    }
    for (auto &i : b.korisnici) {
        korisnici.insert(std::make_pair(i.first,nullptr));
    }
    try  {
        auto j(b.knjige.begin());
        auto k(b.korisnici.begin());
        for (auto i = knjige.begin(); i != knjige.end(); i++) {
            i->second = new Knjiga (*(j->second));
            j++;
        }
        for (auto i = korisnici.begin(); i != korisnici.end(); i++) {
            i->second = new Korisnik(*(k->second));
            k++;
        }
    } catch (...) {
        for (auto i : knjige) {
            delete i.second;
        }
         for (auto i : korisnici) {
            delete i.second;
        }
    }
}

int main ()
{
    
    return 0;
}