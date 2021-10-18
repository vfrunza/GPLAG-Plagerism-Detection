#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <memory>

struct Korisnik {
    //Napomena: Sve je javno !
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};

class Knjiga {
    
    std::string naslov, pisac, zanr;
    int godina_izdavanja;
    Korisnik *zaduzena_kod;
    
    public:
    
    Knjiga(std::string naslov, std::string pisac, std::string zanr, int godina)
            : naslov(naslov), pisac(pisac), zanr(zanr), godina_izdavanja(godina) {
                zaduzena_kod=nullptr;
            }
            
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return pisac; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik *DajKodKogaJe() const { return zaduzena_kod; }
    bool DaLiJeZaduzena() const { if(zaduzena_kod==nullptr) return false; return true; }
    
    void ZaduziKnjigu(Korisnik &k) { zaduzena_kod=&k; }
    void RazduziKnjigu() { zaduzena_kod=nullptr; }
    
};

class Biblioteka {
    
    std::map<int,std::shared_ptr<Korisnik>> korisnici;
    std::map<int,std::shared_ptr<Knjiga>> knjige;
    
    public:
    
    Biblioteka() {};
    
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    Biblioteka &operator=(Biblioteka b);
    
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string pisac, std::string zanr, int godina);
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void PrikaziZaduzenja(int clanski_broj) const;
    Korisnik &NadjiKorisnika(int clanski_broj) const;
    Knjiga &NadjiKnjigu(int evidencijski_broj) const;
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int evidencijski_broj);
    
};

Biblioteka::Biblioteka(const Biblioteka &b) {
        for(auto it=(b.korisnici).begin(); it!=(b.korisnici).end(); it++ ) {
            korisnici.insert(std::make_pair(it->first, std::make_shared<Korisnik>(*(it->second)))); 
        }
        for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++)
            knjige.insert(std::make_pair(it->first, std::make_shared<Knjiga>(*(it->second))));
    }
Biblioteka::Biblioteka(Biblioteka &&b) {
    korisnici=b.korisnici;
    knjige=b.knjige;
}
Biblioteka& Biblioteka::operator=(Biblioteka b) {
    std::swap(b.korisnici, korisnici);
    std::swap(b.knjige, knjige);
    return *this;
}


void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
    if(!korisnici.count(clanski_broj)) {
        Korisnik k{ime,prezime,adresa,telefon};
        korisnici.insert(std::make_pair(clanski_broj, std::make_shared<Korisnik>(k)));
    }
    else throw std::logic_error ("Korisnik vec postoji");
}
void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string pisac, std::string zanr, int godina) {
    if(!knjige.count(evidencijski_broj)) {
        Knjiga k(naslov,pisac,zanr, godina);
        knjige.insert(std::make_pair(evidencijski_broj, std::make_shared<Knjiga>(k)));
    }
    else throw std::logic_error ("Knjiga vec postoji");
}
void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj) {
    try {
        if(NadjiKnjigu(evidencijski_broj).DaLiJeZaduzena()) throw std::logic_error ("Knjiga vec zaduzena");
        NadjiKnjigu(evidencijski_broj).ZaduziKnjigu(NadjiKorisnika(clanski_broj));
    }
    catch(...) {
        throw;
    }
}
void Biblioteka::RazduziKnjigu(int evidencijski_broj) {
    try {
        if(!NadjiKnjigu(evidencijski_broj).DaLiJeZaduzena()) throw std::logic_error ("Knjiga nije zaduzena");
        NadjiKnjigu(evidencijski_broj).RazduziKnjigu();
    }
    catch(...) { throw; }
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) const {
    try {
        bool nadjen(false);
        
        for(auto it(knjige.begin()); it!=knjige.end(); it++) {
            if((it->second->DajKodKogaJe())==&(NadjiKorisnika(clanski_broj))) {
                nadjen=true;
               std::cout<<"Evidencijski broj: "<<it->first<<std::endl
                 <<"Naslov: "<<it->second->DajNaslov()<<std::endl
                 <<"Pisac: "<<it->second->DajAutora()<<std::endl
                 <<"Zanr: "<<it->second->DajZanr()<<std::endl
                 <<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl; 
            }
        }
        if(!nadjen) std::cout<<"Nema zaduzenja za tog korisnika!";
    }
    catch(...) {
        throw std::logic_error ("Korisnik nije nadjen");
    }
}
void Biblioteka::IzlistajKorisnike() const {
    for(auto it(korisnici.begin()); it!=korisnici.end(); it++) {
        std::cout<<"Clanski broj: "<<it->first<<std::endl
                 <<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl
                 <<"Adresa: "<<it->second->adresa<<std::endl
                 <<"Broj telefona: "<<it->second->telefon<<std::endl;
                 
        std::cout<<std::endl;
    }
    
}
void Biblioteka::IzlistajKnjige() const {
    for(auto it(knjige.begin()); it!=knjige.end(); it++) {
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl
                 <<"Naslov: "<<it->second->DajNaslov()<<std::endl
                 <<"Pisac: "<<it->second->DajAutora()<<std::endl
                 <<"Zanr: "<<it->second->DajZanr()<<std::endl
                 <<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
        if(it->second->DaLiJeZaduzena())
            std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<std::endl;
    std::cout<<std::endl;
    }
}
Korisnik& Biblioteka::NadjiKorisnika(int clanski_broj) const {
    auto it(korisnici.find(clanski_broj));
    if(it==korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
    return *(it->second);
}
Knjiga& Biblioteka::NadjiKnjigu(int evidencijski_broj) const {
    auto it(knjige.find(evidencijski_broj));
    if(it==knjige.end()) throw std::logic_error ("Knjiga nije nadjena");
    return *(it->second);
}
Korisnik& Biblioteka::NadjiKorisnika(int clanski_broj) {
    auto it(korisnici.find(clanski_broj));
    if(it==korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
    return *(it->second);
}
Knjiga& Biblioteka::NadjiKnjigu(int evidencijski_broj) {
    auto it(knjige.find(evidencijski_broj));
    if(it==knjige.end()) throw std::logic_error ("Knjiga nije nadjena");
    return *(it->second);
}

void Meni1(Biblioteka &b) {
    int opcija;
    for(;;) {
        std::cout<<"Odaberite opciju:\n"
                 <<" 0 - nazad\n"
                 <<" 1 - dodaj novog korisnika\n"
                 <<" 2 - pronadji korisnika\n"
                 <<" 3 - izlistaj korisnike\n"
                 <<" 4 - izlistaj zaduzenja korisnika\n";
        std::cin>>opcija;
        if(opcija==0) return;
        if(opcija==1) {
            for(;;) {
                std::string ime, prezime, adresa, telefon; int n; bool unos(false);
                std::cout<<"\nUnesite clanski broj: "; std::cin>>n;
                std::cout<<"Unesite ime: "; std::cin.ignore(10000, '\n'); std::getline(std::cin, ime);
                std::cout<<"Unesite prezime: "; ; std::getline(std::cin, prezime);
                std::cout<<"Unesite adresu: ";  std::getline(std::cin, adresa);
                std::cout<<"Unesite telefon: ";  std::getline(std::cin, telefon);
                try {
                b.RegistrirajNovogKorisnika(n,ime, prezime, adresa, telefon);
                unos=true;
                }
                catch(std::logic_error g) {
                    std::cout<<g.what()<<" Unesite ponovo\n";
                    unos=false;
                }
                if(unos) {
                    std::cout<<"Novi korisnik je uspjesno dodan!\n";
                    break;
                }
            }
        }
        if(opcija==2) {
            int n; 
            std::cout<<"Unesite clanski broj: "; std::cin>>n;
            try {
                Korisnik k(b.NadjiKorisnika(n));
                std::cout<<"Ime: "<<k.ime<<std::endl
                         <<"Prezime: "<<k.prezime<<std::endl
                         <<"Adresa: "<<k.adresa<<std::endl
                         <<"Telefon: "<<k.telefon<<std::endl;
            }
            catch(std::logic_error g) { std::cout<<g.what()<<std::endl; }
        }
        if(opcija==3) {
            b.IzlistajKorisnike();
        }
        if(opcija==4) {
            std::cout<<"Unesite clanski broj korisnika: ";
            int n; std::cin>>n;
            b.PrikaziZaduzenja(n);
        }
    }
}

void Meni2(Biblioteka &b) {
    int opcija;
    for(;;) {
    std::cout<<"Odaberite opciju:\n"
             <<" 0 - nazad\n"
             <<" 1 - dodaj novu knjigu\n"
             <<" 2 - pronadji knjigu\n"
             <<" 3 - izlistaj knjige\n"
             <<" 4 - pronadji kod koga je knjiga\n"
             <<" 5 - zaduzi knjigu\n"
             <<" 6 - razduzi knjigu\n";
    std::cin>>opcija;
    if(opcija==0) return;
    if(opcija==1) {
       for(;;) {
            std::string naslov, pisac, zanr; int godina, n; bool unos(false);
            std::cout<<"\nUnesite evidencijski broj: "; std::cin>>n;
            std::cout<<"Unesite naslov: "; std::cin.ignore(10000, '\n'); std::getline(std::cin, naslov);
            std::cout<<"Unesite pisca: ";  std::getline(std::cin, pisac);
            std::cout<<"Unesite zanr: ";  std::getline(std::cin, zanr);
            std::cout<<"Unesite godinu izdavanja: "; std::cin>>godina;
            try {
                b.RegistrirajNovuKnjigu(n, naslov, pisac, zanr, godina);
                unos=true;
            }
            catch(std::logic_error g) {
                std::cout<<g.what()<<" Unesite ponovo\n";
                unos=false;
            }
            if(unos) {
                std::cout<<"Nova knjiga je uspjesno dodana!\n";
                break;
            }
        } 
    }
    if(opcija==2) {
        int n; 
        std::cout<<"Unesite evidencijski broj: "; std::cin>>n;
        try {
            Knjiga k(b.NadjiKnjigu(n));
            std::cout<<"Naslov: "<<k.DajNaslov()<<std::endl
                     <<"Pisac: "<<k.DajAutora()<<std::endl
                     <<"Zanr: "<<k.DajZanr()<<std::endl
                     <<"Godina izdavanja: "<<k.DajGodinuIzdavanja()<<std::endl;
        }
        catch(std::logic_error g) { std::cout<<g.what()<<std::endl; }
    }
    if(opcija==3) b.IzlistajKnjige();
    if(opcija==4) {
        std::cout<<"Unesite evidencijski broj: ";
        int n; std::cin>>n;
        try {
            Knjiga k(b.NadjiKnjigu(n));
            if(!k.DaLiJeZaduzena()) throw std::logic_error ("Knjiga nije zaduzena");
            std::cout<<"\nKnjiga se nalazi kod: "<<k.DajKodKogaJe()->ime<<" "<<k.DajKodKogaJe()->prezime<<std::endl;
        }
        catch(std::logic_error g) {
            std::cout<<g.what()<<std::endl;
        }
    }
    if(opcija==5) {
        std::cout<<"Unesite evidencijski broj knjige: ";
        int n; std::cin>>n;
        std::cout<<"Unesite clanski broj korisnika: ";
        int m; std::cin>>m;
        try{
            b.ZaduziKnjigu(n,m);
        }
        catch(std::logic_error g) { std::cout<<g.what()<<std::endl; }
    }
    if(opcija==6) {
        std::cout<<"Unesite evidencijski broj knjige: ";
        int n; std::cin>>n;
        try{
            b.RazduziKnjigu(n);
        }
        catch(std::logic_error g) { std::cout<<g.what()<<std::endl; }
    }
}
}

int main () {

Biblioteka b;

std::cout<<"DOBRODOSLI!\n\n";

for(;;) {
    int opcija;
    std::cout<<"Odaberite opciju:\n"
             <<" 0 - kraj\n"
             <<" 1 - upravljanje korisnicima\n"
             <<" 2 - upravljanje knjigama\n";
    std::cin>>opcija;
    if(opcija==0) break;
    if(opcija==1) Meni1(b);
    if(opcija==2) Meni2(b);
}

std::cout<<"\nDOVIDJENJA!";
	return 0;
}