#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <utility>
#include <new>
#include <memory>
#include <algorithm>
struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov_knjige, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *korisnik;
    public : 
    Knjiga(std::string naslov, std::string ime, std::string zanr_knjige, int godina) {
        naslov_knjige = naslov;
        ime_pisca = ime;
        zanr = zanr_knjige;
        godina_izdavanja = godina;
        korisnik = nullptr;
    }
    std::string DajNaslov() const { return naslov_knjige; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik* DajKodKogaJe() const { return korisnik; }
    void ZaduziKnjigu(Korisnik &korisnik1) {
        korisnik = &korisnik1;
    }
    void RazduziKnjigu() {
        korisnik = nullptr;
    }
    bool DaLiJeZaduzena() const {
        if(korisnik == nullptr) return false;
        else return true;
    }
};

class Biblioteka {
    std::map<int, Korisnik*> mapa_korisnika;
    std::map<int, Knjiga*> mapa_knjiga;
    public: 
    Biblioteka() {}
    Biblioteka (const Biblioteka &b) {
            
            for(auto it((b.mapa_korisnika).begin()); it != (b.mapa_korisnika).end(); it++) {
                std::pair<int, Korisnik*> korisnici;
                korisnici.first = it->first;
                korisnici.second = new Korisnik(*(it->second));
                mapa_korisnika.insert(korisnici);
            }
            for(auto it((b.mapa_knjiga).begin()); it != (b.mapa_knjiga.end()); it++) {
                mapa_knjiga.insert(std::make_pair(it->first, new Knjiga(*(it->second))));
            }
        }
    Biblioteka &operator = (const Biblioteka &b) {
            for(auto it = mapa_korisnika.begin(); it != mapa_korisnika.end() ; it++) {
                it->second = nullptr;
            }
                for(auto it((b.mapa_korisnika).begin()); it != ((b.mapa_korisnika).end()); it++) {
                std::pair<int, Korisnik*> korisnici;
                korisnici.first = (*it).first;
                korisnici.second = new Korisnik(*(it->second));
                mapa_korisnika.insert(korisnici);
            }
            for(auto it(mapa_knjiga.begin()); it != mapa_knjiga.end(); it++) {
                it->second = nullptr;
            }
            for(auto it(b.mapa_knjiga.begin()); it != (b.mapa_knjiga.end()); it++) {
                std::pair<int, Knjiga*> knjige;
                knjige.first = (*it).first;
                knjige.second = new Knjiga(*(it->second));
                mapa_knjiga.insert(knjige);
            }
            return *this;
        }
    Biblioteka(Biblioteka &&b) {
        swap(mapa_korisnika, b.mapa_korisnika);
        swap(mapa_knjiga, b.mapa_knjiga);
    }
    Biblioteka operator =(Biblioteka &&b) {
        swap(mapa_korisnika, b.mapa_korisnika);
        swap(mapa_knjiga, b.mapa_knjiga);
        return *this;
    }
    ~Biblioteka() {
        for(auto it(mapa_korisnika.begin()); it != mapa_korisnika.end(); it++) {
            delete it->second;
            (*it).second = nullptr;
        }
            for(auto it(mapa_knjiga.begin()); it != mapa_knjiga.end(); it++) {
                delete it->second;
                (*it).second = nullptr;
            }
    }
    void RegistrirajNovogKorisnika (int clanski_broj_korisnika, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
        auto it = mapa_korisnika.find(clanski_broj_korisnika);
        if(it != mapa_korisnika.end()) throw std::logic_error ("Korisnik vec postoji");
        Korisnik novi {ime, prezime, adresa, telefon};
        mapa_korisnika.insert(std::make_pair(clanski_broj_korisnika, new Korisnik (novi)));
    }
    void RegistrirajNovuKnjigu(int evidencijski_broj_knjige, std::string naslov, std::string ime, std::string zanr, int godina) {
        auto it = mapa_knjiga.find(evidencijski_broj_knjige);
        if(it != mapa_knjiga.end()) throw std::logic_error ("Knjiga vec postoji");
        Knjiga nova{naslov, ime, zanr, godina};
        mapa_knjiga.insert(std::make_pair(evidencijski_broj_knjige, new Knjiga(nova)));
    }
    Korisnik NadjiKorisnika (int clanski_broj_korisnika) {
        auto it = mapa_korisnika.find(clanski_broj_korisnika);
        if(it == mapa_korisnika.end()) throw std::logic_error ("Korisnik nije nadjen");
        return *(it->second);
    }
    Knjiga NadjiKnjigu(int evidencijski_broj_knjige) {
        auto it = mapa_knjiga.find(evidencijski_broj_knjige);
        if(it == mapa_knjiga.end()) throw std::logic_error ("Knjiga nije nadjena");
        return *(it->second);
    }
    void IzlistajKorisnike() const {
        for(auto it(mapa_korisnika.begin()); it != mapa_korisnika.end(); it++) {
            std::cout << "Clanski broj: " << it->first << std::endl;
            std::cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl;
            std::cout << "Adresa: " << it->second->adresa << std::endl;
            std::cout << "Broj telefona: " << it->second->telefon << std::endl;
            std::cout << std::endl;
        }
    }
    void IzlistajKnjige() const {
        for(auto it(mapa_knjiga.begin()); it != mapa_knjiga.end(); it++) {
            std::cout << "Evidencijski broj: " << it->first << std::endl;
            std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
            std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
            std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
           if((*(it -> second)).DaLiJeZaduzena()) {
               Korisnik *vlasnik = (*(it->second)).DajKodKogaJe();
               std::cout << "Zaduzena kod korisnika: "  << (*vlasnik).ime << " " << (*vlasnik).prezime << std::endl;
                }
            std::cout << std::endl;
        }
    }
    void ZaduziKnjigu(int evidencijski_broj_knjige, int clanski_broj_korisnika) {
        auto it = mapa_knjiga.find(evidencijski_broj_knjige);
        if(it == mapa_knjiga.end()) {
            throw std::logic_error ("Knjiga nije nadjena");
        }
        auto iterator = mapa_korisnika.find(clanski_broj_korisnika);
        if(iterator == mapa_korisnika.end()) {
            throw std::logic_error ("Korisnik nije nadjen");
        }
        if((*it).second -> DaLiJeZaduzena()) throw std::logic_error ("Knjiga vec zaduzena");
        (*it).second -> ZaduziKnjigu(*mapa_korisnika[clanski_broj_korisnika]);
    }
    void RazduziKnjigu(int evidencijski_broj_knjige) {
        auto iterator = mapa_knjiga.find(evidencijski_broj_knjige);
        if(iterator == mapa_knjiga.end()) 
        throw std::logic_error("Knjiga nije nadjena");
        if(((*(iterator->second)).DaLiJeZaduzena()) == false) 
        throw std::logic_error("Knjiga nije zaduzena");
        (*(iterator -> second)).RazduziKnjigu();
    }
    void PrikaziZaduzenja(int clanski_broj_korisnika) const {
        auto it1 = mapa_korisnika.find(clanski_broj_korisnika);
        if(it1 == mapa_korisnika.end()) 
        throw std::logic_error("Korisnik nije nadjen");
        bool knjiga(false);
        for(auto it(mapa_knjiga.begin()); it != mapa_knjiga.end(); it++) {
            if((*(it -> second)).DajKodKogaJe() == (it1 -> second)) {
                
                std::cout << "Evidencijski broj: "<< (*it).first << std::endl;
                std::cout << "Naslov: "<< (*(it->second)).DajNaslov() << std::endl;
                std::cout << "Pisac: " << (*(it->second)).DajAutora() << std::endl;
                std::cout << "Zanr: " << (*(it->second)).DajZanr() << std::endl;
                std::cout << "Godina izdavanja: " << (*(it -> second)).DajGodinuIzdavanja() << std::endl;
                std::cout << std::endl;
                knjiga = true;
            }
        }
        if(knjiga == false) std::cout << "Nema zaduzenja za tog korisnika!";
    }
};
int main () {
    try {
    Biblioteka b;
    while(1) {
        std::cout << "Odaberite opciju: "<< std::endl;
        std::cout << "1 - Unesi novog korisnika: " << std::endl;
        std::cout << "2 - Unesi novu knjigu: " << std::endl;
        std::cout << "3 - Nadji korisnika: " << std::endl;
        std::cout << "4 - Nadji knjigu: " << std::endl;
        std::cout << "5 - Zaduzi knjigu: " << std::endl;
        std::cout << "6 - Razduzi knjigu: " << std::endl;
        std::cout << "7 - Izlistaj zaduzenja: " << std::endl;
        std::cout << "Unesite broj 8 za kraj!" << std::endl;
        int br;
        std::cin >> br;
        if(br == 1) {
            int clanski_broj_korisnika;
            std::string ime, prezime, adresa, telefon;
            std::cout << "Unesite clanski broj korisnika: ";
            std::cin >> clanski_broj_korisnika; 
            std::cout << "Unesite ime korisnika: ";
            std::getline(std::cin, ime); 
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Unesite prezime korisnika: "; 
            std::cin >> prezime;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Unesite adresu: "; 
            std::getline(std::cin, adresa); 
            std::cout << "Unesite broj telefona korisnika: "; 
            std::cin >> telefon;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            b.RegistrirajNovogKorisnika(clanski_broj_korisnika, ime, prezime, adresa, telefon);
            continue;
        }
        else if(br == 2) {
            int evidencijski_broj_knjige, godina_izdavanja;
            std::string naslov_knjige, ime_pisca, zanr;
            std::cout << "Unesite evidencijski broj knjige: "; 
            std::cin >> evidencijski_broj_knjige;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Unesite naslov knjige: "; 
            std::getline(std::cin, naslov_knjige);
            std::cout << "Unesite ime pisca: "; 
            std::getline(std::cin, ime_pisca);
            std::cout << "Unesite zanr knjige: ";
            std::getline(std::cin, zanr); 
            std::cout << "Unesite godinu izdavanja knjige: "; std::cin >> godina_izdavanja; 
            b.RegistrirajNovuKnjigu(evidencijski_broj_knjige, naslov_knjige, ime_pisca, zanr, godina_izdavanja);
            continue;
        }
        else if(br == 3) {
            int clanski_broj_korisnika;
            std::cout << "Unesite clanski broj korisnika: "; 
            std::cin >> clanski_broj_korisnika;
            std::cout << std::endl;
            b.NadjiKorisnika(clanski_broj_korisnika);
            b.PrikaziZaduzenja(clanski_broj_korisnika);
            continue;
        }
        else if(br == 4) {
            int evidencijski_broj_knjige;
            std::cout << "Unesite evidencijski broj knjige: ";
            std::cin >> evidencijski_broj_knjige;
            std::cout << std::endl;
            b.NadjiKnjigu(evidencijski_broj_knjige);
            
            continue;
        }
        else if(br == 5) {
            int evidencijski_broj_knjige, clanski_broj_korisnika;
            std::cout << "Unesite evidencijski broj knjige koju zelite zaduziti: "; std::cin >> evidencijski_broj_knjige;
            std::cout << "Unesite clanski broj korisnika koji zaduzuje knjigu: "; std::cin >> clanski_broj_korisnika; std::cout << std::endl;
            b.ZaduziKnjigu(evidencijski_broj_knjige, clanski_broj_korisnika);
            continue;
        }
        else if(br == 6) {
            int evidencijski_broj_knjige;
            std::cout << "Unesite evidencijski broj knjige da biste je razduzili: "; std::cin >> evidencijski_broj_knjige; std::cout << std::endl;
            b.RazduziKnjigu(evidencijski_broj_knjige);
            continue;
        }
        if(br == 7) {
            std::cout << "Knjige: " << std::endl;
            b.IzlistajKnjige();
            std::cout << "Korisnici: " << std::endl;
            b.IzlistajKorisnike();
            continue;
        }
        if(br == 8) {
            std::cout << "Dovidjenja!";
            break;
        }
        else {
            std::cout << "Unijeli ste pogresan broj, pokusajte ponovo!" << std::endl;
            continue;
        }
    }
    }catch(std::logic_error e) {
        std::cout << e.what();
    } 
    return 0;
}