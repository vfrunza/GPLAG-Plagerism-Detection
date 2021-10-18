/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <stdexcept>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naziv, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* zaduzio_knjigu;
    public:
    Knjiga(std::string naziv_knjige, std::string ime, std::string zanr_knjige, int izdata) { 
        naziv=naziv_knjige; 
        ime_pisca=ime; 
        zanr=zanr_knjige; 
        godina_izdavanja=izdata; 
        zaduzio_knjigu=nullptr; 
    }
    std::string DajNaslov() const { return naziv; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik* DajKodKogaJe() { return zaduzio_knjigu; }
    void ZaduziKnjigu(Korisnik &zeli_zaduziti) { zaduzio_knjigu=&zeli_zaduziti; }
    void RazduziKnjigu() { this->zaduzio_knjigu=nullptr; }
    bool DaLiJeZaduzena() { if(zaduzio_knjigu==nullptr) return false; return true; }
};

class Biblioteka {
    std::map<int,Korisnik*> mapa_korisnika;
    std::map<int,Knjiga*> mapa_knjiga;
    public:
    Biblioteka() =default;
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    Biblioteka &operator = (const Biblioteka &b);
    Biblioteka &operator = (Biblioteka &&b);
    ~Biblioteka();
    void RegistrirajNovogKorisnika(int clanski_broj_korisnika, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona);
    void RegistrirajNovuKnjigu(int evidencijski_broj_knjige, std::string naziv, std::string ime, std::string zanr, int godina);
    Korisnik& NadjiKorisnika(int clanski_broj) const;
    Knjiga& NadjiKnjigu(int evidencijski_broj) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int clanski_broj) const;
};

Biblioteka::Biblioteka(const Biblioteka &b) {
    try {
        for (auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++) {
            Knjiga* novi= new Knjiga(it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja());
            novi->Knjiga::ZaduziKnjigu(*(it->second->DajKodKogaJe()));
            mapa_knjiga.insert(std::make_pair(it->first,novi));
        }
    }
    catch (...) {
        for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
            delete it->second;
    }
    try {
        for (auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++) {
            Korisnik* novi= new Korisnik;
            novi->ime=it->second->ime;
            novi->prezime=it->second->prezime;
            novi->adresa=it->second->adresa;
            novi->telefon=it->second->telefon;
            mapa_korisnika.insert(std::make_pair(it->first,novi));
        }
    }
    catch (...) {
        for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
            delete it->second;
    }
}

Biblioteka::Biblioteka(Biblioteka &&b) {
    for (auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++) {
        mapa_knjiga.insert(std::make_pair(it->first,it->second));
        it->second=nullptr;
    }
    for (auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++) {
        mapa_korisnika.insert(std::make_pair(it->first,it->second));
        it->second=nullptr;
    }
}

Biblioteka &Biblioteka::operator = (const Biblioteka &b) {
    if (&b!=this){
    try {
        for (auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++) {
            Korisnik* novi= new Korisnik;
            novi->ime=it->second->ime;
            novi->prezime=it->second->prezime;
            novi->adresa=it->second->adresa;
            novi->telefon=it->second->telefon;
            mapa_korisnika.insert(std::make_pair(it->first,novi));
        }
    }
    catch (...) {
        for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
            delete it->second;
    }
    try {
        for (auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++) {
            Knjiga* novi= new Knjiga(it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja());
            novi->Knjiga::ZaduziKnjigu(*(it->second->DajKodKogaJe()));
            mapa_knjiga.insert(std::make_pair(it->first,novi));
        }
    }
    catch (...) {
        for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
            delete it->second;
    }
    }
    return *this;
}

Biblioteka &Biblioteka::operator =(Biblioteka &&b) {
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) {
        mapa_knjiga.insert(std::make_pair(it->first, it->second));
        it->second=nullptr;
    }
    for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) {
        mapa_korisnika.insert(std::make_pair(it->first, it->second));
        it->second=nullptr;
    }
    return *this;
}

Biblioteka::~Biblioteka() {
    for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) {
        delete it->second;
    }
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
        delete it->second;
}

void Biblioteka::RegistrirajNovogKorisnika (int clanski_broj_korisnika, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona) {
    for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
        if (it->first==clanski_broj_korisnika) throw std::logic_error("Korisnik vec postoji");
    Korisnik* novi=new Korisnik;
    novi->ime=ime;
    novi->prezime=prezime;
    novi->adresa=adresa;
    novi->telefon=broj_telefona;
    mapa_korisnika.insert(std::make_pair(clanski_broj_korisnika,novi));
}

void Biblioteka::RegistrirajNovuKnjigu (int evidencijski_broj_knjige, std::string naziv, std::string ime, std::string zanr, int godina) {
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) 
        if (it->first==evidencijski_broj_knjige) throw std::logic_error("Knjiga vec postoji");
    Knjiga* nova=new Knjiga(naziv,ime,zanr,godina);
    mapa_knjiga.insert(std::make_pair(evidencijski_broj_knjige,nova));
}

Korisnik& Biblioteka::NadjiKorisnika (int clanski_broj) const{
    for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
        if (clanski_broj==it->first) {
            return *(it->second);
        }
    throw std::logic_error("Korisnik nije nadjen");
}

Knjiga& Biblioteka::NadjiKnjigu (int evidencijski_broj) const{
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
        if (evidencijski_broj==it->first) {
            return *(it->second);
        }
    throw std::logic_error("Knjiga nije nadjena");
}

void Biblioteka::IzlistajKorisnike() const{
    for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) {
        std::cout<<"Clanski broj: "<<it->first<<std::endl<<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<std::endl<<"Adresa: "<<(it->second)->adresa<<std::endl<<"Broj telefona: "<<(it->second)->telefon<<std::endl;
        std::cout<<std::endl;
    }
}

void Biblioteka::IzlistajKnjige() const{
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) {
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl<<"Naslov: "<<(it->second)->DajNaslov()<<std::endl<<"Pisac: "<<(it->second)->DajAutora()<<std::endl<<"Zanr: "<<(it->second)->DajZanr()<<std::endl<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl;
        if (it->second->DaLiJeZaduzena()) 
            std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->Korisnik::ime<<" "<<(it->second)->DajKodKogaJe()->Korisnik::prezime<<std::endl;
        std::cout<<std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj) {
    int a=0,da=0;
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) {
        if (it->first==evidencijski_broj) {
            if (it->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
            a=1;
        }
    }
    if(a==0) throw std::logic_error("Knjiga nije nadjena");
    for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
        if (clanski_broj==it->first)
            da=1;
    if (da==0) throw std::logic_error("Korisnik nije nadjen");
//std::cout<<"doslo je ipak ";
    NadjiKnjigu(evidencijski_broj).Knjiga::ZaduziKnjigu(NadjiKorisnika(clanski_broj));
    
}

void Biblioteka::RazduziKnjigu(int evidencijski_broj) {
    int a=0;
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
        if(it->first==evidencijski_broj) { a=1; break; }
    if (a==0) throw std::logic_error("Knjiga nije nadjena");
    if(NadjiKnjigu(evidencijski_broj).DaLiJeZaduzena()==false) throw std::logic_error("Knjiga nije zaduzena");
    NadjiKnjigu(evidencijski_broj).Knjiga::RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) const {
    try { auto nk=NadjiKorisnika(clanski_broj); }
    catch (std::logic_error a) { throw std::logic_error("Korisnik nije nadjen"); } 
    auto k=NadjiKorisnika(clanski_broj);
    int a=0;
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) {
        if (it->second->DajKodKogaJe()==&k) {
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl<<"Naslov: "<<(it->second)->DajNaslov()<<std::endl<<"Pisac: "<<(it->second)->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<(it->second)->DajZanr()<<std::endl<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl;
            a=1;
        }
    }
    if (a==0) std::cout<<"Nema zaduzenja za tog korisnika!";
}

int main ()
{
    /*
Knjiga knj1("Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
std::cout << knj1.DajNaslov() << " " << knj1.DajAutora() << " " << knj1.DajZanr() << " " << knj1.DajGodinuIzdavanja();
if(!knj1.DaLiJeZaduzena()) std::cout << "\nKnjiga je slobodna";
else std::cout << "\nKnjiga je zaduzena";


Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
"Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
"Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
"Studenata etfovaca 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
b.PrikaziZaduzenja(1234);
*/

Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
"Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
"Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
"Studenata etfovaca 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
b.ZaduziKnjigu(231, 1234);
b.ZaduziKnjigu(136, 1234);
b.PrikaziZaduzenja(1234);

	return 0;
}