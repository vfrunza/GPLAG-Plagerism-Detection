#include <iostream> 
#include <string>
#include <map>
#include <new>
#include <stdexcept>
#include <memory>

//prekopiran Z1 i vršene tražene izmjene

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *zaduzio; //nullptr = nije zadužena
public:
    Knjiga (std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), 
            godina_izdavanja(godina_izdavanja), zaduzio(nullptr) {};
    std::string DajNaslov() const {return naslov;}
    std::string DajAutora() const {return ime_pisca;}
    std::string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdavanja;}
    //Korisnik DajKodKogaJe() const {return *zaduzio;}
    Korisnik* DajKodKogaJe() const {return zaduzio;}
    void ZaduziKnjigu (Korisnik &korisnik) {zaduzio = &korisnik;}
    void RazduziKnjigu() {zaduzio = nullptr;}
    bool DaLiJeZaduzena() {if (!zaduzio) return false; return true;}
};

class Biblioteka {
    std::map<int, std::shared_ptr<Korisnik>> users;
    std::map<int, std::shared_ptr<Knjiga>> books;
public:
    //Upravljački elementi
    Biblioteka() {};
    Biblioteka (const Biblioteka &biblioteka) {
        std::map<int, std::shared_ptr<Korisnik>> kopija_users;
        auto it_korisnik((biblioteka.users).begin());
        while (it_korisnik != (biblioteka.users).end()) {
            kopija_users.insert(std::make_pair(it_korisnik->first, std::make_shared<Korisnik>(Korisnik(*(it_korisnik->second)))));
            it_korisnik++;
        }
        std::map<int, std::shared_ptr<Knjiga>> kopija_books;
        auto it_knjiga((biblioteka.books).begin());
        while (it_knjiga != (biblioteka.books).end()) {
            kopija_books.insert(std::make_pair(it_knjiga->first, std::make_shared<Knjiga>(Knjiga(*(it_knjiga->second)))));
            it_knjiga++;
        }
        
        auto it1(users.begin()); 
        while (it1 != users.end()) {
            it1->second = nullptr;
            it1++;
        }
        auto it2(books.begin()); 
        while (it2 != books.end()) {
            it2->second = nullptr;
            it2++;
        }
        
        users.empty(); users = kopija_users;
        books.empty(); books = kopija_books;
    }
    Biblioteka (Biblioteka &&biblioteka) {
        auto it1(users.begin());
        while (it1 != users.end()) {
            it1->second = nullptr;
            it1++;
        }
        auto it2(books.begin());
        while (it2 != books.end()) {
            it2->second = nullptr;
            it2++;
        }
        users = biblioteka.users;
        books = biblioteka.books;
    }
    Biblioteka &operator =(const Biblioteka &biblioteka) {
        if (&biblioteka != this) {
            std::map<int, std::shared_ptr<Korisnik>> kopija_users;
            auto it_korisnik((biblioteka.users).begin());
            while (it_korisnik != (biblioteka.users).end()) {
                kopija_users.insert(std::make_pair(it_korisnik->first, std::make_shared<Korisnik>(Korisnik(*(it_korisnik->second)))));
                it_korisnik++;
            }
            std::map<int, std::shared_ptr<Knjiga>> kopija_books;
            auto it_knjiga((biblioteka.books).begin());
            while (it_knjiga != (biblioteka.books).end()) {
                kopija_books.insert(std::make_pair(it_knjiga->first, std::make_shared<Knjiga>(Knjiga(*(it_knjiga->second)))));
                it_knjiga++;
            }
            auto it1(users.begin());
            while (it1 != users.end()) {
                it1->second = nullptr;
                it1++;
            }
            auto it2(books.begin());
            while (it2 != books.end()) {
                it2->second = nullptr;
                it2++;
            }
            users.empty(); users = kopija_users;
            books.empty(); books = kopija_books;
        }
        return *this;
    }
    Biblioteka &operator =(Biblioteka &&biblioteka) {
        if (&biblioteka != this) {
            auto it1(users.begin());
            while (it1 != users.end()) {
                it1->second = nullptr;
                it1++;
            }
            auto it2(books.begin());
            while (it2 != books.end()) {
                it2->second = nullptr;
                it2++;
            }
            users = biblioteka.users;
            books = biblioteka.books;
        }
        return *this;
    }
    
    //Metode
    void RegistrirajNovogKorisnika (int clanski_broj_korisnika, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona) {
        auto it(users.find(clanski_broj_korisnika));
        if (it != users.end()) throw std::logic_error("Korisnik vec postoji");
        auto novi(std::make_shared<Korisnik>(Korisnik{ime, prezime, adresa, broj_telefona}));
        users.insert(std::make_pair(clanski_broj_korisnika, novi));
    }
    void RegistrirajNovuKnjigu (int evidencijski_broj_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) {
        auto it(books.find(evidencijski_broj_knjige));
        if (it != books.end()) throw std::logic_error("Knjiga vec postoji");
        auto nova(std::make_shared<Knjiga>(Knjiga(naslov, ime_pisca, zanr, godina_izdavanja)));
        books.insert(std::make_pair(evidencijski_broj_knjige, nova));
    }
    Korisnik& NadjiKorisnika (int clanski_broj_korisnika) const {
        auto it(users.find(clanski_broj_korisnika));
        if (it == users.end()) throw std::logic_error("Korisnik nije nadjen");
        return *(it->second);
    }
    Knjiga& NadjiKnjigu (int evidencijski_broj_knjige) const {
        auto it(books.find(evidencijski_broj_knjige));
        if (it == books.end()) throw std::logic_error("Knjiga nije nadjena");
        return *(it->second);
    }
    void IzlistajKorisnike() const {
        auto korisnik(users.begin());
        while (korisnik != users.end()) {
            std::cout << "Clanski broj: " << korisnik->first << std::endl;
            std::cout << "Ime i prezime: " << (*(korisnik->second)).ime << " " << (*(korisnik->second)).prezime << std::endl;
            std::cout << "Adresa: " << (*(korisnik->second)).adresa << std::endl;
            std::cout << "Broj telefona: " << (*(korisnik->second)).telefon << std::endl;
            std::cout << std::endl;
            korisnik++;
        }
    }
    void IzlistajKnjige() const {
        auto knjiga(books.begin());
        while (knjiga != books.end()) {
            std::cout << "Evidencijski broj: " << knjiga->first << std::endl;
            std::cout << "Naslov: " << (knjiga->second)->DajNaslov() << std::endl;
            std::cout << "Pisac: " << (knjiga->second)->DajAutora() << std::endl;
            std::cout << "Zanr: " << (knjiga->second)->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << (knjiga->second)->DajGodinuIzdavanja() << std::endl;
            if ((knjiga->second)->DaLiJeZaduzena()) 
                std::cout << "Zaduzena kod korisnika: " << (*((knjiga->second)->DajKodKogaJe())).ime << " " << (*((knjiga->second)->DajKodKogaJe())).prezime << std::endl;
            std::cout << std::endl;
            knjiga++;
        }
    }
    void ZaduziKnjigu (int evidencijski_broj_knjige, int clanski_broj_korisnika) { //const?
        auto it_knjiga(books.find(evidencijski_broj_knjige));
        if (it_knjiga == books.end()) throw std::logic_error("Knjiga nije nadjena");
        auto it_korisnik(users.find(clanski_broj_korisnika));
        if (it_korisnik == users.end()) throw std::logic_error("Korisnik nije nadjen");
        if ((it_knjiga->second)->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
        (it_knjiga->second)->ZaduziKnjigu(*(it_korisnik->second));
    }
    void RazduziKnjigu (int evidencijski_broj_knjige) { //const?
        auto it(books.find(evidencijski_broj_knjige));
        if (it == books.end()) throw std::logic_error("Knjiga nije nadjena");
        if (!(it->second)->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
        (it->second)->RazduziKnjigu();
    }
    void PrikaziZaduzenja (int clanski_broj_korisnika) const {
        auto it(users.find(clanski_broj_korisnika));
        if (it == users.end()) throw std::logic_error("Korisnik nije nadjen");
        Korisnik renter = *(it->second);
        auto it_knjiga(books.begin());
        int count(0);
        while (it_knjiga != books.end()) {
            if ((*(it_knjiga->second)).DaLiJeZaduzena()) {
                if ((*(*(it_knjiga->second)).DajKodKogaJe()).ime     == renter.ime       && 
                    (*(*(it_knjiga->second)).DajKodKogaJe()).prezime == renter.prezime   && 
                    (*(*(it_knjiga->second)).DajKodKogaJe()).adresa  == renter.adresa    && 
                    (*(*(it_knjiga->second)).DajKodKogaJe()).telefon == renter.telefon) {
                    std::cout << "Evidencijski broj: " << it_knjiga->first << std::endl;
                    std::cout << "Naslov: " << (it_knjiga->second)->DajNaslov() << std::endl;
                    std::cout << "Pisac: " << (it_knjiga->second)->DajAutora() << std::endl;
                    std::cout << "Zanr: " << (it_knjiga->second)->DajZanr() << std::endl;
                    std::cout << "Godina izdavanja: " << (it_knjiga->second)->DajGodinuIzdavanja() << std::endl;
                    std::cout << std::endl;
                    count++;
                }
            }
            it_knjiga++;
        }
        if (count == 0) std::cout << "Nema zaduzenja za tog korisnika!";
    }
};

int main () {
    Biblioteka b1;
    b1.RegistrirajNovogKorisnika(1234, "Denin", "Mehanovic", "Gradacacka 5", "0603004770");
    b1.RegistrirajNovogKorisnika(2345, "Sejma", "Kudic", "Gradacacka 4", "062428114");
    b1.RegistrirajNovuKnjigu(0001, "Knjiga1", "Autor1", "Zanr1", 2000);
    b1.ZaduziKnjigu(0001, 2345);
    Biblioteka b2;
    b2.RegistrirajNovogKorisnika(3456, "Elma", "Dzaferovic", "Gradacacka 4", "062428114");
    b2.RegistrirajNovuKnjigu(0002, "Knjiga2", "Autor2", "Zanr2", 2000);
    std::cout << "PRIJE================================== " << std::endl;
    b2.IzlistajKorisnike();
    b2.IzlistajKnjige();
    b2 = b1;
    std::cout << "POSLIJE=================================\n" << "b1: " << std::endl;
    b1.IzlistajKnjige();
    b1.IzlistajKorisnike();
    std::cout << std::endl << "b2: " << std::endl;
    b2.IzlistajKnjige();
    b2.IzlistajKorisnike();
    std::cout << "WHATEVS==================================\n";
    b2.PrikaziZaduzenja(1234);
	return 0;
}