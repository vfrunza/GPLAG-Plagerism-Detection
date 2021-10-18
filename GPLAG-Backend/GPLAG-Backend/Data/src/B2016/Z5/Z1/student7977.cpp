/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stdexcept>

struct Korisnik {
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
    
    Korisnik(std::string ime, std::string prezime, std::string adresa, std::string telefon) : ime(ime), prezime(prezime), adresa(adresa), telefon(telefon){}
    
    std::string DajIme()const { return ime; }
    std::string DajPrezime()const { return prezime; }
    std::string DajAdresu()const { return adresa; }
    std::string DajTelefon()const { return telefon; }
    bool operator ==(const Korisnik &k);
};

bool Korisnik::operator ==(const Korisnik &k){
    if(k.DajIme() != ime) return false;
    if(k.DajPrezime() != prezime) return false;
    if(k.DajAdresu() != adresa) return false;
    if(k.DajTelefon() != telefon) return false;
    return true;
}

class Knjiga {
    std::string naslov;
    std::string ime_pisca;
    std::string zanr;
    int godina_izdavanja;
    Korisnik* zaduzeni;
public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int god_izdavanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(god_izdavanja), zaduzeni(nullptr){}
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik *DajKodKogaJe() const { return zaduzeni; }
    void ZaduziKnjigu(Korisnik &k){ zaduzeni = &k; }
    void RazduziKnjigu(){ zaduzeni = nullptr; }
    bool DaLiJeZaduzena() { if(zaduzeni){ return true; } return false; }
    
};

class Biblioteka {
    std::map<int, Korisnik *> korisnici;
    std::map<int, Knjiga *> knjige;
public:
    Biblioteka(){}
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    ~Biblioteka();
    Biblioteka &operator =(const Biblioteka &b);
    Biblioteka &operator =(Biblioteka &&b);
    void RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona);
    void RegistrirajNovuKnjigu(int broj_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina);
    Korisnik &NadjiKorisnika(int cl_broj);
    Knjiga &NadjiKnjigu(int broj_knjige);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int broj_knjige, int cl_broj);
    void RazduziKnjigu(int broj_knjige);
    void PrikaziZaduzenja(int cl_broj) const;
};

Biblioteka::Biblioteka(const Biblioteka &b){
    for(auto it = (b.korisnici).begin(); it != (b.korisnici).end(); it++){
        korisnici.insert( std::make_pair( it->first, new Korisnik(*(it->second)) ) );
    }
    for(auto it = (b.knjige).begin(); it != (b.knjige).end(); it++){
        knjige.insert( std::make_pair( it->first, new Knjiga(*(it->second)) ) );
    }
}

Biblioteka::Biblioteka(Biblioteka &&b){
    for(auto it = (b.korisnici).begin(); it != (b.korisnici).end(); it++){
        korisnici.insert( std::make_pair( it->first, it->second) );
        it->second = nullptr;
    }
    for(auto it = (b.knjige).begin(); it != (b.knjige).end(); it++){
        knjige.insert( std::make_pair( it->first, it->second ) );
        it->second = nullptr;
    }
}

Biblioteka::~Biblioteka(){
    for(auto it = korisnici.begin(); it != korisnici.end(); it++){
        delete it->second;
    }
    for(auto it = knjige.begin(); it != knjige.end(); it++){
        delete it->second;
    }
}

Biblioteka &Biblioteka::operator =(Biblioteka &&b){
    if(this != &b){
        for(auto it = korisnici.begin(); it != korisnici.end(); it++){
            delete it->second;
        }
        for(auto it = knjige.begin(); it != knjige.end(); it++){
            delete it->second;
        }
        
        for(auto it = (b.korisnici).begin(); it != (b.korisnici).end(); it++){
            korisnici.insert( std::make_pair( it->first, it->second) );
            it->second = nullptr;
        }
        for(auto it = (b.knjige).begin(); it != (b.knjige).end(); it++){
            knjige.insert( std::make_pair( it->first, it->second ) );
            it->second = nullptr;
        }
    }
    return *this;
}

Biblioteka &Biblioteka::operator =(const Biblioteka &b){
    if(this != &b){
        for(auto it = korisnici.begin(); it != korisnici.end(); it++){
            delete it->second;
        }
        for(auto it = knjige.begin(); it != knjige.end(); it++){
            delete it->second;
        }
        
        for(auto it = (b.korisnici).begin(); it != (b.korisnici).end(); it++){
            korisnici.insert(std::make_pair(it->first, new Korisnik((it->second)->DajIme(), (it->second)->DajPrezime(), (it->second)->DajAdresu(), (it->second)->DajTelefon() )));
        }
        for(auto it = (b.knjige).begin(); it != (b.knjige).end(); it++){
            knjige.insert(std::make_pair(it->first, new Knjiga((it->second)->DajNaslov(), (it->second)->DajAutora(), (it->second)->DajZanr(), (it->second)->DajGodinuIzdavanja() )));
            if( (*(it->second)).DaLiJeZaduzena() ){
                Korisnik* k((*(it->second)).DajKodKogaJe());
                for(auto it1 = (b.korisnici).begin(); it1 != (b.korisnici).end(); it1++){
                    if( *k == *(it1->second) ){ 
                        ZaduziKnjigu(it->first, it1->first);
                        break;
                    }
                }
            }
        }
    }
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona){
    auto it( korisnici.find(cl_broj) );
    if(it != korisnici.end()) throw std::logic_error("Korisnik vec postoji");
    korisnici.insert(std::make_pair(cl_broj, new Korisnik(ime, prezime, adresa, broj_telefona)));
}

void Biblioteka::RegistrirajNovuKnjigu(int broj_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina){
    auto it( knjige.find(broj_knjige) );
    if(it != knjige.end()) throw std::logic_error("Knjiga vec postoji");
    knjige.insert(std::make_pair(broj_knjige, new Knjiga(naslov, ime_pisca, zanr, godina)));
}

Korisnik &Biblioteka::NadjiKorisnika(int cl_broj){
    auto it( korisnici.find(cl_broj) );
    if(it == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    Korisnik &k(*(it->second));
    return k;
}

Knjiga &Biblioteka::NadjiKnjigu(int broj_knjige){
    auto it( knjige.find(broj_knjige) );
    if(it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    Knjiga &k(*(it->second));
    return k;    
}

void Biblioteka::IzlistajKorisnike() const{
    for(auto it = korisnici.begin(); it != korisnici.end(); it++){
        std::cout << "Clanski broj: " << it->first << std::endl;
        std::cout << "Ime i prezime: " << (it->second)->DajIme() << " " << (it->second)->DajPrezime() << std::endl;
        std::cout << "Adresa: " << (it->second)->DajAdresu() << std::endl;
        std::cout << "Broj telefona: " << (it->second)->DajTelefon() << std::endl;
        std::cout << std::endl;
    }
}

void Biblioteka::IzlistajKnjige() const{
    for(auto it = knjige.begin(); it != knjige.end(); it++){
        std::cout << "Evidencijski broj: " << it->first << std::endl;
        std::cout << "Naslov: " << (it->second)->DajNaslov() << std::endl;
        std::cout << "Pisac: " << (it->second)->DajAutora() << std::endl;
        std::cout << "Zanr: " << (it->second)->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << (it->second)->DajGodinuIzdavanja() << std::endl;
        if( (it->second)->DaLiJeZaduzena() ) std::cout << "Zaduzena kod korisnika: " << ( (it->second)->DajKodKogaJe() )->DajIme() << " " << ( (it->second)->DajKodKogaJe() )->DajPrezime() << std::endl;
        std::cout << std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int broj_knjige, int cl_broj){
    auto it( knjige.find(broj_knjige) );
    if(it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    
    auto it1( korisnici.find(cl_broj) );
    if(it1 == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    
    if( (it->second)->DaLiJeZaduzena() ) throw std::logic_error("Knjiga vec zauzeta");

    (*(it->second)).ZaduziKnjigu( NadjiKorisnika(cl_broj) );
}

void Biblioteka::RazduziKnjigu(int broj_knjige){
    auto it( knjige.find(broj_knjige) );
    if(it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    
    if( !((it->second)->DaLiJeZaduzena()) ) throw std::logic_error("Knjiga nije zauzeta");
    
    (*(it->second)).RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int cl_broj) const{
    auto it( korisnici.find(cl_broj) );
    if(it == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    
    Korisnik korisnik(*(it->second));
    auto it2( knjige.begin() );
    while( it2 != knjige.end() ){
        if( (it2->second)->DaLiJeZaduzena() ){
            if( *((it2->second)->DajKodKogaJe()) == korisnik ){
                break;
            }
        }
        it2++;
    }
    
    if( it2 ==knjige.end() ) throw std::logic_error("Nema zaduzenja za tog korisnika");
    
    for(auto it1 = knjige.begin(); it1 != knjige.end(); it1++){
        if( (it1->second)->DaLiJeZaduzena() ){
            if( *((it1->second)->DajKodKogaJe()) == korisnik ){
                std::cout << "Evidencijski broj: " << it1->first << std::endl;
                std::cout << "Naslov: " << (it1->second)->DajNaslov() << std::endl;
                std::cout << "Pisac: " << (it1->second)->DajAutora() << std::endl;
                std::cout << "Zanr: " << (it1->second)->DajZanr() << std::endl;
                std::cout << "Godina izdavanja: " << (it1->second)->DajGodinuIzdavanja() << std::endl;
            }
        }
    }
}

int main ()
{
    Biblioteka b;
    while (true) {
        std::cout << "Odaberite opciju: " << std::endl;
        std::cout << " 0 - za kraj" << std::endl;
        std::cout << " 1 - za registraciju korisnika" << std::endl;
        std::cout << " 2 - za registraciju knjige" << std::endl;
        std::cout << " 3 - za popis korisnika" << std::endl;
        std::cout << " 4 - za popis knjiga" << std::endl;
        std::cout << " 5 - za zaduzivanje knjige" << std::endl;
        std::cout << " 6 - za razduzivanje knjige" << std::endl;
        std::cout << " 7 - za prikaz zaduzenja" << std::endl;
        int n;
        std::cin >> n;
        if(n == 0){
            break;
        }else if(n == 1){
            int cl_broj;
            std::cout << "Unesite clanski broj korisnika: " << std::endl;
            std::cin >> cl_broj;
            std::cin.ignore(1000, '\n');
            std::string ime;
            std::cout << "Unesite ime korisnika: " << std::endl;
            std::getline(std::cin, ime);
            std::string prezime;
            std::cout << "Unesite prezime korisnika: " << std::endl;
            std::getline(std::cin, prezime);
            std::string adresa;
            std::cout << "Unesite adresu korisnika: " << std::endl;
            std::getline(std::cin, adresa);
            std::string telefon;
            std::cout << "Unesite broj telefona korisnika: " << std::endl;
            std::getline(std::cin, telefon);
            try{
                b.RegistrirajNovogKorisnika(cl_broj, ime, prezime, adresa, telefon);
                std::cout << "Korisnik registrovan." << std::endl;
                std::cout << std::endl;
            }catch(std::logic_error izuzetak){
                std::cout << izuzetak.what() << std::endl;
                std::cout << std::endl;
            }
        }else if(n == 2){
            int broj_knjige, godina_izdavanja;
            std::cout << "Unesite evidencijski broj knjige: " << std::endl;
            std::cin >> broj_knjige;
            std::cin.ignore(1000,'\n');
            std::string naslov;
            std::cout << "Unesite naslov knjige: " << std::endl;
            std::getline(std::cin, naslov);
            std::string ime_pisca;
            std::cout << "Unesite ime pisca knjige: " << std::endl;
            std::getline(std::cin, ime_pisca);
            std::string zanr;
            std::cout << "Unesite zanr knjige: " << std::endl;
            std::getline(std::cin, zanr);
            std::cout << "Unesite godina izdavanja knjige: " << std::endl;
            std::cin >> godina_izdavanja;
            try{
                b.RegistrirajNovuKnjigu(broj_knjige, naslov, ime_pisca, zanr, godina_izdavanja);
                std::cout << "Knjiga registrovana." << std::endl;
                std::cout << std::endl;
            }catch(std::logic_error izuzetak){
                std::cout << izuzetak.what() << std::endl;
                std::cout << std::endl;
            }
        }else if(n==3){
            b.IzlistajKorisnike();
        }else if(n==4){
            b.IzlistajKnjige();
        }else if(n==5){
            int cl_broj, broj_knjige;
            std::cout << "Unesite clanski broj korisnika koji zaduzuje knigu: ";
            std::cin >> cl_broj;
            std::cout << "Unesite evidencijski broj knjige koju zaduzuje korisnik: ";
            std::cin >> broj_knjige;
            try{
                b.ZaduziKnjigu(broj_knjige, cl_broj);
                std::cout << "Knjiga zaduzena." << std::endl;
                std::cout << std::endl;
            }catch(std::logic_error izuzetak){
                std::cout << izuzetak.what() << std::endl;
                std::cout << std::endl;
            }
        }else if(n==6){
            int broj_knjige;
            std::cout << "Unesite evidencijski broj knjige koju razduzujete: ";
            std::cin >> broj_knjige;
            try{
                b.RazduziKnjigu(broj_knjige);
                std::cout << "Knjiga razduzena." << std::endl;
                std::cout << std::endl;
            }catch(std::logic_error izuzetak){
                std::cout << izuzetak.what() << std::endl;
                std::cout << std::endl;
            }
        }else if(n==7){
            int cl_broj;
            std::cout << "Unesite clanski broj korisnika: ";
            std::cin >> cl_broj;
            try{
                std::cout << std::endl;
                b.PrikaziZaduzenja(cl_broj);
                std::cout << std::endl;
            }catch(std::logic_error izuzetak){
                std::cout << izuzetak.what() << std::endl;
                std::cout << std::endl;
            }
        }
    }
    
	return 0;
}