/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <utility>
#include <memory>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    std::shared_ptr<Korisnik> zaduzenje; //Korisnik *zaduzenje;
public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) : 
        naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), zaduzenje(nullptr) {}
    std::string DajNaslov() const {return naslov;}
    std::string DajAutora() const {return ime_pisca;}
    std::string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdavanja;}
    std::shared_ptr<Korisnik> DajKodKogaJe() const {return zaduzenje;}         //Korisnik *DajKodKogaJe()
    void ZaduziKnjigu(Korisnik &korisnik) {zaduzenje=std::make_shared<Korisnik>(korisnik);}      //zaduzenje=&korisnik;
    void RazduziKnjigu() {zaduzenje=nullptr;}
    bool DaLiJeZaduzena() {return bool(zaduzenje);}
};

class Biblioteka {
    std::map<int,std::shared_ptr<Korisnik>> korisnici;
    std::map<int,std::shared_ptr<Knjiga>> knjige;
public:
    Biblioteka() = default;
    Biblioteka(const Biblioteka &objekat);
    Biblioteka(Biblioteka &&objekat);
    Biblioteka &operator =(const Biblioteka &objekat);
    Biblioteka &operator =(Biblioteka &&objekat);
    ~Biblioteka();
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona);
    void RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int evidencijski_broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int clanski_broj) const;
};

Biblioteka::Biblioteka(const Biblioteka &objekat) {
    try {
        for(auto &x : objekat.korisnici)
            korisnici.insert(std::make_pair(x.first, std::make_shared<Korisnik>(*x.second)));    //new Korisnik(*x.second)
        for(auto &x : objekat.knjige)
            knjige.insert(std::make_pair(x.first, std::make_shared<Knjiga>(*x.second)));    //new Knjiga(*x.second)
    }
    catch(...) {
        for(auto &x : korisnici) x.second=nullptr; //delete x.second;
        for(auto &x : knjige) x.second=nullptr; //delete x.second;
        throw;
    }
}

Biblioteka::Biblioteka(Biblioteka &&objekat) : korisnici(objekat.korisnici), knjige(objekat.knjige) {
        for(auto &x : objekat.korisnici) x.second=nullptr;
        for(auto &x : objekat.knjige) x.second=nullptr;
}

Biblioteka &Biblioteka::operator =(const Biblioteka &objekat) {
    for(auto &x : korisnici) x.second=nullptr;
    for(auto &x : knjige) x.second=nullptr;
    std::map<int,std::shared_ptr<Korisnik>> temp1;
    std::map<int,std::shared_ptr<Knjiga>> temp2;
    try {
        for(auto &x : objekat.korisnici)
            temp1.insert(std::make_pair(x.first, std::make_shared<Korisnik>(*x.second))); //temp1.insert(std::make_pair(x.first, new Korisnik(*x.second)));
        for(auto &x : objekat.knjige)
            temp2.insert(std::make_pair(x.first, std::make_shared<Knjiga>(*x.second))); //temp2.insert(std::make_pair(x.first, new Knjiga(*x.second)));
    }
    catch(...) {
        for(auto &x : korisnici) x.second=nullptr; //delete x.second;
        for(auto &x : knjige) x.second=nullptr; //delete x.second;
        throw;
    }
    std::swap(korisnici, temp1);
    std::swap(knjige, temp2);
    return *this;
}

Biblioteka &Biblioteka::operator =(Biblioteka &&objekat) {
    std::swap(korisnici, objekat.korisnici);
    std::swap(knjige, objekat.knjige);
    return *this;
}

Biblioteka::~Biblioteka() {
    for(auto &x : korisnici) x.second=nullptr; //delete x.second;
    for(auto &x : knjige) x.second=nullptr; //delete x.second;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime,
    std::string adresa, std::string broj_telefona) {
    auto it(korisnici.find(clanski_broj));
    if(it!=korisnici.end()) throw std::logic_error("Korisnik vec postoji");
    Korisnik temp{ime, prezime, adresa, broj_telefona};
    korisnici.insert(std::make_pair(clanski_broj, std::make_shared<Korisnik>(temp)));     //new Korisnik(temp)
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string ime_pisca,
    std::string zanr, int godina_izdavanja) {
    auto it(knjige.find(evidencijski_broj));
    if(it!=knjige.end()) throw std::logic_error("Knjiga vec postoji");
    Knjiga temp(naslov, ime_pisca, zanr, godina_izdavanja);
    knjige.insert(std::make_pair(evidencijski_broj, std::make_shared<Knjiga>(temp)));        //new Knjiga(temp)
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) {
    auto it(korisnici.find(clanski_broj));
    if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    return *it->second;
}

Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj) {
    auto it(knjige.find(evidencijski_broj));
    if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    return *it->second;
}

void Biblioteka::IzlistajKorisnike() const {
    for(const std::pair<int, std::shared_ptr<Korisnik>> &x : korisnici) {
        std::cout << "Clanski broj: " << x.first << std::endl;
        std::cout << "Ime i prezime: " << x.second->ime << " " << x.second->prezime << std::endl;
        std::cout << "Adresa: " << x.second->adresa << std::endl;
        std::cout << "Broj telefona: " << x.second->telefon << std::endl;
        std::cout << std::endl;
    }
}

void Biblioteka::IzlistajKnjige() const {
    for(const std::pair<int, std::shared_ptr<Knjiga>> &x : knjige) {
        std::cout << "Evidencijski broj: " << x.first << std::endl;
        std::cout << "Naslov: " << x.second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << x.second->DajAutora() << std::endl;
        std::cout << "Zanr: " << x.second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << x.second->DajGodinuIzdavanja() << std::endl;
        if(x.second->DaLiJeZaduzena()) std::cout << "Zaduzena kod korisnika: " << x.second->DajKodKogaJe()->ime << " "
                                          << x.second->DajKodKogaJe()->prezime << std::endl;
        std::cout << std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj) {
    auto it(knjige.find(evidencijski_broj));
    if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    auto it2(korisnici.find(clanski_broj));
    if(it2==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    if(it->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    it->second->ZaduziKnjigu(*it2->second);
}

void Biblioteka::RazduziKnjigu(int evidencijski_broj) {
    auto it(knjige.find(evidencijski_broj));
    if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    if(!(it->second->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
    it->second->RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) const {
    auto it(korisnici.find(clanski_broj));
    if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    Korisnik t1{it->second->ime, it->second->prezime, it->second->adresa, it->second->telefon};
    bool a(false);
    for(const std::pair<int, std::shared_ptr<Knjiga>> &x : knjige) {
        if(x.second->DajKodKogaJe()!=nullptr) {
        auto t2(*x.second->DajKodKogaJe());
        if(t1.ime==t2.ime and t1.prezime==t2.prezime and t1.adresa==t2.adresa and t1.telefon==t2.telefon) {
            a=true;
            std::cout << "Evidencijski broj: " << x.first << std::endl;
            std::cout << "Naslov: " << x.second->DajNaslov() << std::endl;
            std::cout << "Pisac: " << x.second->DajAutora() << std::endl;
            std::cout << "Zanr: " << x.second->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << x.second->DajGodinuIzdavanja() << std::endl;
            std::cout << std::endl;
        }
        }
    }
    if(!a) throw std::logic_error("Nema zaduzenja za tog korisnika");
}

int main ()
{
    Biblioteka teka;
    std::cout << "Dobrodosli!\n";
    while(1) {
        std::cout << "\nIzaberite opciju: " << std::endl << " 0 - kraj" << std::endl
                  << " 1 - Registracija novog korisnika" << std::endl << " 2 - Registracija nove knjige" << std::endl
                  << " 3 - Modifikacija postojecih podataka" << std::endl << " 4 - Izvjestaji" << std::endl;
        int t1; std::cin >> t1;
        if(t1==0) {
            break;
        } else if(t1==1) {
            std::string ime, prezime, adresa, telefon;
            int clanski_broj;
            std::cin.ignore(1000, '\n');
            std::cout << "Unesite ime korisnika: ";
            std::getline(std::cin, ime);
            //std::cin.ignore(1000, '\n');
            std::cout << "Unesite prezime korisnika: ";
            std::getline(std::cin, prezime);
            //std::cin.ignore(1000, '\n');
            std::cout << "Unesite adresu korisnika: ";
            std::getline(std::cin, adresa);
            //std::cin.ignore(1000, '\n');
            std::cout << "Unesite telefon korisnika: ";
            std::getline(std::cin, telefon);
            //std::cin.ignore(1000, '\n');
            std::cout << "Unesite clanski broj korisnika: ";
            std::cin >> clanski_broj;
            try {
                teka.RegistrirajNovogKorisnika(clanski_broj, ime, prezime, adresa, telefon);
                std::cout << "Uspjesno registrovan korisnik!" << std::endl;
            }
            catch(std::logic_error a) {
                std::cout << "Izuzetak: " << a.what() << std::endl;
            }
        } else if(t1==2) {
            std::string naslov, ime_pisca, zanr;
            int evidencijski_broj, godina_izdavanja;
            std::cin.ignore(1000, '\n');
            std::cout << "Unesite naslov knjige: ";
            std::getline(std::cin, naslov);
            //std::cin.ignore(1000, '\n');
            std::cout << "Unesite ime pisca knjige: ";
            std::getline(std::cin, ime_pisca);
            //std::cin.ignore(1000, '\n');
            std::cout << "Unesite zanr knjige: ";
            std::getline(std::cin, zanr);
            //std::cin.ignore(1000, '\n');
            std::cout << "Unesite godinu izdavanja knjige: ";
            std::cin >> godina_izdavanja;
            //std::cin.ignore(1000, '\n');
            std::cout << "Unesite evidencijski broj knjige: ";
            std::cin >> evidencijski_broj;
            try {
                teka.RegistrirajNovuKnjigu(evidencijski_broj, naslov, ime_pisca, zanr, godina_izdavanja);
            }
            catch(std::logic_error a) {
                std::cout << "Izuzetak: " << a.what() << std::endl;
            }
        } else if(t1==3) {
            std::cout << "\nOdaberite opciju: " << std::endl << " 0 - nazad" << std::endl << " 1 - korisnik"
                      << std::endl << " 2 - knjiga" << std::endl;
            int t2; std::cin >> t2;
            if(t2==0) {
                continue;
            } else if(t2==1) {
                std::cout << "Unesite clanski broj korisnika: ";
                int clanski_broj;
                std::cin >> clanski_broj;
                try {
                    Korisnik trenutni(teka.NadjiKorisnika(clanski_broj));
                    std::cout << "Zaduzenja korisnika: " << std::endl;
                    teka.PrikaziZaduzenja(clanski_broj);
                }
                catch(std::logic_error a) {
                    std::cout << "Izuzetak: " << a.what() << std::endl;
                }
            } else if(t2==2) {
                std::cout << "Unesite evidencijski broj knjige: ";
                int evidencijski_broj;
                std::cin >> evidencijski_broj;
                std::cout << "Zelite li razduziti knjigu? (0 - NE, 1 - DA): ";
                int t3; std::cin >> t3;
                if(t3==1) {
                    try {
                        teka.RazduziKnjigu(evidencijski_broj);
                        std::cout << "Knjiga uspjesno razduzena!" << std::endl;
                    }
                    catch(std::logic_error a) {
                        std::cout << "Izuzetak: " << a.what() << std::endl;
                    }
                }
            }
        } else if(t1==4) {
            try {
            std::cout << "Lista trenutnih korisnika:" << std::endl;
            teka.IzlistajKorisnike();
            }
            catch(std::logic_error a) {
                std::cout << "Izuzetak: " << a.what() << std::endl;
            }
            try {
            std::cout << "Lista knjiga koje posjeduje ova biblioteka:" << std::endl;
            teka.IzlistajKnjige();
            }
            catch(std::logic_error a) {
                std::cout << "Izuzetak: " << a.what() << std::endl;
            }
        }
    }
    
    std::cout << "\n\nDovidjenja!";
	return 0;
}