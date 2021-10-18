/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>
struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};
class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int god_izd;
    Korisnik* korisnik;
public:
    Knjiga(std::string nasl, std::string ime, std::string z, int god) : korisnik(nullptr) {
        naslov = nasl; ime_pisca = ime; zanr = z; god_izd = god;
    }
    std::string DajNaslov() const {
        return naslov;
    }
    std::string DajAutora() const {
        return ime_pisca;
    }
    std::string DajZanr() const {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return god_izd;
    }
    Korisnik* DajKodKogaJe() {
        return korisnik;
    }
    void ZaduziKnjigu(Korisnik &k) {
       korisnik = &k;
    }
    void RazduziKnjigu() {
        korisnik = nullptr;
    }
    bool DaLiJeZaduzena() {
        return bool(korisnik);
    }
};
class Biblioteka
{
    std::map<int, std::shared_ptr<Korisnik>> user;
    std::map<int, std::shared_ptr<Knjiga>> book;
public:
    Biblioteka() {}
    Biblioteka &operator = (Biblioteka b);
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
   // ~Biblioteka();
    void RegistrirajNovogKorisnika(int clanski_br, std::string ime, std::string prezime, std::string adresa, std::string br);
    void RegistrirajNovuKnjigu(int evid_br, std::string naslov, std::string ime_pisca, std::string zanr, int godina);
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int ev_br);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int ev_br, int clan_br);
    void RazduziKnjigu(int ev_br);
    void PrikaziZaduzenja(int clanski_br);
    
};
void Biblioteka::PrikaziZaduzenja(int clanski_br) {
    bool ima(false), zaduzena(false);
    for(auto it = user.begin(); it != user.end(); it++)
        if(it->first == clanski_br)
            ima = true;
    if(!ima) throw std::logic_error("Korisnik nije nadjen");
    for(auto it = book.begin(); it != book.end(); it++)
        if(it->second->DajKodKogaJe() == user[clanski_br].get()) {
            zaduzena = true;
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl<<std::endl;
        }
    if(!zaduzena) std::cout<<"Nema zaduzenja za tog korisnika!";
}
void Biblioteka::RazduziKnjigu(int ev_br) {
    bool ima(false), zaduzena(false);
    for(auto it = book.begin(); it != book.end(); it++)
        if(it->first == ev_br)
        {
            ima = true;
            if(it->second->DaLiJeZaduzena()) zaduzena = true;
        }
    if(!ima) throw std::logic_error("Knjiga nije nadjena");
    if(!zaduzena) throw std::logic_error("Knjiga nije zaduzena");
    book[ev_br]->RazduziKnjigu();
}
void Biblioteka::ZaduziKnjigu(int ev_br, int clan_br) {
    bool ima(false), zaduzena(false);
    for(auto it = book.begin(); it != book.end(); it++)
        if(it->first == ev_br) 
        {
            ima = true;
            if(it->second->DaLiJeZaduzena()) zaduzena = true;
        }
    if(!ima) throw std::logic_error("Knjiga nije nadjena");
    ima = false;
    for(auto it = user.begin(); it != user.end(); it++) 
        if(it->first == clan_br) ima = true;
    if(!ima) throw std::logic_error("Korisnik nije nadjen");
    if(zaduzena) throw std::logic_error("Knjiga vec zaduzena");
    book[ev_br]->ZaduziKnjigu(*(user[clan_br]));
}
void Biblioteka::IzlistajKnjige() const {
    for(auto it = book.begin(); it != book.end(); it++)
    {
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
        if(it->second->DaLiJeZaduzena()) std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime;
        std::cout<<std::endl;
    }
}
void Biblioteka::IzlistajKorisnike() const {
    for(auto it = user.begin(); it != user.end(); it++) 
    {
            std::cout<<"Clanski broj: "<<it->first<<std::endl;
            std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
            std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl<<std::endl;
    }
}
Knjiga &Biblioteka::NadjiKnjigu(int ev_br) {
    for(auto it = book.begin(); it != book.end(); it++)
        if(it->first == ev_br) return *(it->second);
    throw std::logic_error("Knjiga nije nadjena");
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski_br) {
    for(auto it = user.begin(); it != user.end(); it++)
        if(it->first == clanski_br) return *(it->second);
    throw std::logic_error("Korisnik nije nadjen");
}
void Biblioteka::RegistrirajNovogKorisnika(int clanski_br, std::string ime, std::string prezime, std::string adresa, std::string br) {
    for(auto it = user.begin(); it != user.end(); it++)
        if(it->first == clanski_br) throw std::logic_error("Korisnik vec postoji");
    user[clanski_br] = std::make_shared<Korisnik>();
    user[clanski_br]->ime = ime; user[clanski_br]->prezime = prezime; user[clanski_br]->adresa = adresa; user[clanski_br]->telefon = br;
}
void Biblioteka::RegistrirajNovuKnjigu(int evid_br, std::string naslov, std::string ime_pisca, std::string zanr, int godina) {
    for(auto it = book.begin(); it != book.end(); it++)
        if(it->first == evid_br) throw std::logic_error("Knjiga vec postoji");
    book[evid_br] = std::make_shared<Knjiga>(naslov, ime_pisca, zanr, godina);
}
/*
Biblioteka::~Biblioteka() {
    for(auto it = user.begin(); it != user.end(); it++)
        delete it->second;
    user.clear();
    for(auto it = book.begin(); it != book.end(); it++)
        delete it->second;
    book.clear();
} */
Biblioteka::Biblioteka (const Biblioteka &b) {
    for(auto it = b.user.begin(); it != b.user.end(); it++)
        user[it->first] = std::make_shared<Korisnik>(*(it->second));
    for(auto it = b.book.begin(); it != b.book.end(); it++)
        book[it->first] = std::make_shared<Knjiga>(*(it->second));
} 
Biblioteka::Biblioteka(Biblioteka &&b) {
    user = std::move(b.user);
    book = std::move(b.book);
}
Biblioteka &Biblioteka::operator=(Biblioteka b) {
    user = std::move(b.user);
    book = std::move(b.book);

    return *this;
} /*
Biblioteka &Biblioteka::operator=(Biblioteka &&b) {
    std::map<int, Korisnik*> tmp1;
    std::map<int, Knjiga*> tmp2;
    for(auto it = user.begin(); it != user.end(); it++)
        delete it->second;
    user.clear();
    for(auto it = book.begin(); it != book.end(); it++)
        delete it->second;
    book.clear();
    for(auto it = b.user.begin(); it != b.user.end(); it++) {
        tmp1[it->first] = it->second;
        delete it->second;
    }
    b.user.clear();
    for(auto it = b.book.begin(); it != b.book.end(); it++) {
        tmp2[it->first] = it->second;
        delete it->second;
    }
    b.book.clear();
    return *this;
} */
/*
Biblioteka &Biblioteka::operator=(Biblioteka &&b) {
    std::map<int, std::shared_ptr<Korisnik>> tmp1;
    std::map<int, std::shared_ptr<Knjiga>> tmp2;
    tmp1 = std::move(b.user);
    tmp2 = std::move(b.book);
    user = tmp1;
    book = tmp2;
    return *this;
} */
void Ispisi() {
    std::cout<<"Dobrodosli!"<<std::endl;
    std::cout<<"- Da zaduzite knjigu unesite 1."<<std::endl;
    std::cout<<"- Da razduzite knjigu unesite 2."<<std::endl;
    std::cout<<"- Za prikaz zaduzenja unesite 3."<<std::endl;
    std::cout<<"- Za izlistavanje knjiga unesite 4."<<std::endl;
    std::cout<<"- Za izlistavanje korisnika unesite 5."<<std::endl;
    std::cout<<"- Da izadjete iz programa unesite ."<<std::endl;
}

int main ()
{
    Biblioteka b;
    for(;;) {
        Ispisi();
        int a;
        std::cin>>a;
        if(!std::cin) break;
        try {
            switch (a) {
                case 1: {
                    std::cout<<"Unesite evidencijski i clanski broj: "<<std::endl;
                    int ev, cl;
                    std::cin>>ev>>cl;
                    b.ZaduziKnjigu(ev, cl);
                    break;
                }
                case 2: {
                    std::cout<<"Unesite evidencijski broj knjige: "<<std::endl;
                    int ev;
                    std::cin>>ev;
                    b.RazduziKnjigu(ev);
                    break;
                }
                case 3: {
                    std::cout<<"Za prikaz zaduzenja unesite clanski broj korisnika: "<<std::endl;
                    int cl;
                    std::cin>>cl;
                    b.PrikaziZaduzenja(cl);
                    break;
                }
                case 4: {
                    b.IzlistajKnjige();
                    break;
                }
                case 5: {
                    b.IzlistajKorisnike();
                    break;
                }
                
            }
        } catch(std::logic_error &i) {
            std::cout<<i.what()<<std::endl;
        }
    }
    return 0;
}