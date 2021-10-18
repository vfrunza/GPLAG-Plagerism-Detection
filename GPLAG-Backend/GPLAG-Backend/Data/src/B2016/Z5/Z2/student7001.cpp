/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <utility>
#include <memory>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* korisnik;
public:
    Knjiga (std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja, Korisnik* korisnik=nullptr) : 
        naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), korisnik(korisnik) {}
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik* DajKodKogaJe() const { return korisnik; }
    void ZaduziKnjigu(Korisnik &k) { korisnik=&k; }
    void RazduziKnjigu() { korisnik=nullptr; }
    bool DaLiJeZaduzena() { if (DajKodKogaJe()==nullptr) return false; return true; }
};

class Biblioteka {
    std::map<int,std::shared_ptr<Korisnik>> mapa_korisnika;
    std::map<int,std::shared_ptr<Knjiga>> mapa_knjiga;
public:
    explicit Biblioteka()=default;
    ~Biblioteka();
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    Biblioteka &operator =(const Biblioteka &b);
    Biblioteka &operator =(Biblioteka &&b);
    void RegistrirajNovogKorisnika(int clanski_broj,std::string ime,std::string prezime,std::string adresa,std::string telefon);
    void RegistrirajNovuKnjigu(int evidencijski_broj,std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja);
    Korisnik &NadjiKorisnika(int clanski_broj) const;
    Knjiga &NadjiKnjigu(int evidencijski_broj) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidencijski_broj,int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int clanski_broj) const;
};

Biblioteka::~Biblioteka() {
    for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
        it->second=nullptr;
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
        it->second=nullptr;
}

Biblioteka::Biblioteka(const Biblioteka &b) {
    try {
        for (auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++) {
            Korisnik temp{it->second->ime,it->second->prezime,it->second->adresa,it->second->telefon};
            std::shared_ptr<Korisnik> pok=std::make_shared<Korisnik>(temp);
            mapa_korisnika.insert(std::make_pair(it->first,pok));
        }
        try {
            for (auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++) {
                std::shared_ptr<Knjiga> pok=std::make_shared<Knjiga>(it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja(),it->second->DajKodKogaJe());
                mapa_knjiga.insert(std::make_pair(it->first,pok));
            }
        }
        catch(...) {
            for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
                it->second=nullptr;
            for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
                it->second=nullptr;
            throw;
        }
    }
    catch(...) {
        for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
            it->second=nullptr;
        throw;
    }
}

Biblioteka::Biblioteka(Biblioteka &&b) {
    mapa_korisnika=std::move(b.mapa_korisnika);
    mapa_knjiga=std::move(b.mapa_knjiga);
}

Biblioteka &Biblioteka::operator =(const Biblioteka &b) {
    Biblioteka temp;
    try {
        for (auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++) {
            Korisnik temp1{it->second->ime,it->second->prezime,it->second->adresa,it->second->telefon};
            std::shared_ptr<Korisnik> pok=std::make_shared<Korisnik>(temp1);
            temp.mapa_korisnika.insert(std::make_pair(it->first,pok));
        }
        try {
            for (auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++) {
                std::shared_ptr<Knjiga> pok=std::make_shared<Knjiga>(it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja(),it->second->DajKodKogaJe());
                temp.mapa_knjiga.insert(std::make_pair(it->first,pok));
            }
        }
        catch(...) {
            for (auto it=temp.mapa_knjiga.begin(); it!=temp.mapa_knjiga.end(); it++)
                it->second=nullptr;
            for (auto it=temp.mapa_korisnika.begin(); it!=temp.mapa_korisnika.end(); it++)
                it->second=nullptr;
            throw;
        }
    }
    catch(...) {
        for (auto it=temp.mapa_korisnika.begin(); it!=temp.mapa_korisnika.end(); it++)
            it->second=nullptr;
        throw;
    }
    for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
        it->second=nullptr;
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
        it->second=nullptr;
    mapa_korisnika=std::move(temp.mapa_korisnika);
    mapa_knjiga=std::move(temp.mapa_knjiga);
    return *this;
}

Biblioteka &Biblioteka::operator =(Biblioteka &&b) {
    for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) 
        it->second=nullptr;
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) 
        it->second=nullptr;
    mapa_korisnika=std::move(b.mapa_korisnika);
    mapa_knjiga=std::move(b.mapa_knjiga);
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj,std::string ime,std::string prezime,std::string adresa,std::string telefon) {
    auto it(mapa_korisnika.find(clanski_broj));
    if (mapa_korisnika.begin()!=mapa_korisnika.end() && it!=mapa_korisnika.end()) 
        throw std::logic_error("Korisnik vec postoji");
    try {
        Korisnik tmp{ime,prezime,adresa,telefon};
        std::shared_ptr<Korisnik> pok=std::make_shared<Korisnik>(tmp);
        mapa_korisnika.insert(std::make_pair(clanski_broj,pok));
    }
    catch(...) {
        throw;
    }
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj,std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja) {
    auto it(mapa_knjiga.find(evidencijski_broj));
    if (mapa_knjiga.begin()!=mapa_knjiga.end() && it!=mapa_knjiga.end())
        throw std::logic_error("Knjiga vec postoji");
    try {
        std::shared_ptr<Knjiga> pok=std::make_shared<Knjiga>(naslov,ime_pisca,zanr,godina_izdavanja);
        mapa_knjiga.insert(std::make_pair(evidencijski_broj,pok));
    }
    catch(...) {
        throw;
    }
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) const {
    auto it(mapa_korisnika.find(clanski_broj));
    if (it==mapa_korisnika.end())
        throw std::logic_error("Korisnik nije nadjen");
    return *it->second;
}

Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj) const {
    auto it(mapa_knjiga.find(evidencijski_broj));
    if (it==mapa_knjiga.end())
        throw std::logic_error("Knjiga nije nadjena");
    return *it->second;
}

void Biblioteka::IzlistajKorisnike() const {
    for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) {
        if (it->second!=nullptr) {
            std::cout << "Clanski broj: " << it->first << std::endl
            << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl
            << "Adresa: " << it->second->adresa << std::endl
            << "Broj telefona: " << it->second->telefon << std::endl << std::endl;
        }
    }
}

void Biblioteka::IzlistajKnjige() const {
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) {
        if (it->second!=nullptr) {
            std::cout << "Evidencijski broj: " << it->first << std::endl
            << "Naslov: " << it->second->DajNaslov() << std::endl
            << "Pisac: " << it->second->DajAutora() << std::endl
            << "Zanr: " << it->second->DajZanr() << std::endl
            << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
            if (it->second->DaLiJeZaduzena()) 
                std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime << std::endl << std::endl;
            else std::cout << std::endl;
        }
    }
}

void Biblioteka::ZaduziKnjigu(int evidencijski_broj,int clanski_broj) {
    auto it1(mapa_korisnika.find(clanski_broj));
    auto it2(mapa_knjiga.find(evidencijski_broj));
    if (it2==mapa_knjiga.end()) 
        throw std::logic_error("Knjiga nije nadjena");
    else if (it1==mapa_korisnika.end()) 
        throw std::logic_error("Korisnik nije nadjen");
    if (it2->second->DaLiJeZaduzena()) 
        throw std::logic_error("Knjiga vec zaduzena");
    it2->second->ZaduziKnjigu(*it1->second);
}

void Biblioteka::RazduziKnjigu(int evidencijski_broj) {
    auto it(mapa_knjiga.find(evidencijski_broj));
    if (it==mapa_knjiga.end())
        throw std::logic_error("Knjiga nije nadjena");
    else if (!it->second->DaLiJeZaduzena())
        throw std::logic_error("Knjiga nije zaduzena");
    it->second->RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) const {
    auto it1(mapa_korisnika.find(clanski_broj));
    if (it1==mapa_korisnika.end())
        throw std::logic_error("Korisnik nije nadjen");
    int brojac_pronadjenih_korisnika=0;
    for (auto it2=mapa_knjiga.begin(); it2!=mapa_knjiga.end(); it2++) {
        if (it2->second->DaLiJeZaduzena() && it2->second->DajKodKogaJe()==it1->second.get()) {
            brojac_pronadjenih_korisnika++;
            std::cout << "Evidencijski broj: " << it2->first << std::endl
            << "Naslov: " << it2->second->DajNaslov() << std::endl
            << "Pisac: " << it2->second->DajAutora() << std::endl
            << "Zanr: " << it2->second->DajZanr() << std::endl
            << "Godina izdavanja: " << it2->second->DajGodinuIzdavanja() << std::endl << std::endl;
        }
    }
    if (!brojac_pronadjenih_korisnika) std::cout << "Nema zaduzenja za tog korisnika!";
}

int main () {
    std::cout << "Dobrodosli u virtualnu biblioteku!" << std::endl << std::endl;
    int opcija;
    Biblioteka b;
    do {
        std::cout << std::endl << "Izaberite opciju: " << std::endl
        << " 0 - kraj" << std::endl
        << " 1 - Registriraj novog korisnika" << std::endl
        << " 2 - Registriraj novu knjigu" << std::endl
        << " 3 - Izlistaj korisnike" << std::endl
        << " 4 - Izlistaj knjige" << std::endl
        << " 5 - Zaduzi knjigu" << std::endl 
        << " 6 - Razduzi knjigu" << std::endl
        << " 7 - Prikazi zaduzenja" << std::endl;
        std::cin >> opcija;
        if (opcija==0) break;
        else if (opcija==1) {
            bool da_li_je_unos_ispravan=false;
            do {
                da_li_je_unos_ispravan=false;
                int clanski_broj;
                std::string ime, prezime, adresa, telefon;
                std::cout << "Unesite clanski broj: ";
                std::cin >>  clanski_broj;
                std::cin.ignore(10000,'\n');
                std::cout << "Unesite ime: ";
                std::getline(std::cin,ime);
                std::cout << "Unesite prezime: ";
                std::getline(std::cin,prezime);
                std::cout << "Unesite adresu: ";
                std::getline(std::cin,adresa);
                std::cout << "Unesite telefon: ";
                std::getline(std::cin,telefon);
                try {
                    b.RegistrirajNovogKorisnika(clanski_broj,ime,prezime,adresa,telefon);
                    std::cout << "Korisnik je uspjesno registrovan!" << std::endl;
                    da_li_je_unos_ispravan=true;
                }
                catch(std::logic_error izuzetak) {
                    std::cout << izuzetak.what() << ". Molimo ponovite unos!" << std::endl << std::endl;
                }
            } while(!da_li_je_unos_ispravan);
        }
        else if (opcija==2) {
            bool da_li_je_unos_ispravan=false;
            do {
                da_li_je_unos_ispravan=false;
                int evidencijski_broj, godina_izdavanja;
                std::string naslov, ime_pisca, zanr;
                std::cout << "Unesite evidencijski broj: ";
                std::cin >> evidencijski_broj;
                std::cin.ignore(10000,'\n');
                std::cout << "Unesite naslov: ";
                std::getline(std::cin,naslov);
                std::cout << "Unesite ime pisca: ";
                std::getline(std::cin,ime_pisca);
                std::cout << "Unesite zanr: ";
                std::getline(std::cin,zanr);
                std::cout << "Unesite godinu izdavanja: ";
                std::cin >> godina_izdavanja;
                std::cin.ignore(10000,'\n');
                try {
                    b.RegistrirajNovuKnjigu(evidencijski_broj,naslov,ime_pisca,zanr,godina_izdavanja);
                    std::cout << "Knjiga je uspjesno registrovana!" << std::endl;
                    da_li_je_unos_ispravan=true;
                }
                catch(std::logic_error izuzetak) {
                    std::cout << izuzetak.what() << ". Molimo ponovite unos!" << std::endl << std::endl;
                }
            } while(!da_li_je_unos_ispravan);
        }
        else if (opcija==3) {
            std::cout << "=====Registrovani korisnici=====" << std::endl;
            b.IzlistajKorisnike();
        }
        else if (opcija==4) {
            std::cout << "=====Registrovane knjige=====" << std::endl;
            b.IzlistajKnjige();
        }
        else if (opcija==5) {
            bool da_li_je_unos_ispravan=false;
            do {
                da_li_je_unos_ispravan=false;
                int evidencijski_broj, clanski_broj;
                std::cout << "Unesite evidencijski broj: ";
                std::cin >> evidencijski_broj;
                std::cin.ignore(10000,'\n');
                std::cout << "Unesite clanski broj: ";
                std::cin >> clanski_broj;
                std::cin.ignore(10000,'\n');
                try {
                    b.ZaduziKnjigu(evidencijski_broj,clanski_broj);
                    std::cout << "Knjiga sa evidencijskim brojem " << evidencijski_broj << " je uspjesno zaduzena od strane korisnika "
                    << "sa clanskim brojem " << clanski_broj << "!" << std::endl;
                    da_li_je_unos_ispravan=true;
                }
                catch(std::logic_error izuzetak) {
                    std::cout << izuzetak.what() << ". Molimo ponovite unos!" << std::endl << std::endl;
                }
            } while (!da_li_je_unos_ispravan);
        }
        else if (opcija==6) {
            bool da_li_je_unos_ispravan=false;
            do {
                da_li_je_unos_ispravan=false;
                int evidencijski_broj;
                std::cout << "Unesite evidencijski broj: ";
                std::cin >> evidencijski_broj;
                std::cin.ignore(10000,'\n');
                try {
                    b.RazduziKnjigu(evidencijski_broj);
                    std::cout << "Knjiga sa evidencijskim brojem " << evidencijski_broj << " je uspjesno razduzena!" << std::endl;
                    da_li_je_unos_ispravan=true;
                }
                catch(std::logic_error izuzetak) {
                    std::cout << izuzetak.what() << ". Molimo ponovite unos!" << std::endl << std::endl;
                }
            } while(!da_li_je_unos_ispravan);
        }
        else if (opcija==7) {
            bool da_li_je_unos_ispravan=false;
            do {
                int clanski_broj;
                std::cout << "Unesite clanski broj: ";
                std::cin >> clanski_broj;
                std::cin.ignore(10000,'\n');
                try {
                    b.PrikaziZaduzenja(clanski_broj);
                    da_li_je_unos_ispravan=true;
                }
                catch(std::logic_error izuzetak) {
                    std::cout << izuzetak.what() << ". Molimo ponovite unos!" << std::endl << std::endl;
                }
            } while(!da_li_je_unos_ispravan);
        }
    } while (opcija!=0);
	return 0;
}