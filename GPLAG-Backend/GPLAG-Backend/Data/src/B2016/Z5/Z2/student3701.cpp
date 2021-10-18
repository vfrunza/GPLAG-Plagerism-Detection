/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <stdexcept>
#include <memory>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naziv, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* zaduzio_knjigu;
    public:
    Knjiga(std::string naziv_knjige, std::string ime, std::string zanr_knjige, int izdata) {
        naziv=naziv_knjige;  ime_pisca=ime;  zanr=zanr_knjige;  godina_izdavanja=izdata;
        zaduzio_knjigu=nullptr;
    }
    std::string DajNaslov() const { return naziv; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik* DajKodKogaJe() { return zaduzio_knjigu; }
    void ZaduziKnjigu(Korisnik &zeli_zaduziti) { Knjiga::zaduzio_knjigu=&zeli_zaduziti; }
    void RazduziKnjigu() { zaduzio_knjigu=nullptr; }
    bool DaLiJeZaduzena() { if (zaduzio_knjigu==nullptr) return false; return true; }
};

class Biblioteka {
    std::map<int, std::shared_ptr<Korisnik>> mapa_korisnika;
    std::map<int, std::shared_ptr<Knjiga>> mapa_knjiga;
    public:
    Biblioteka() =default;
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    Biblioteka &operator =(const Biblioteka &b);
    Biblioteka &operator =(Biblioteka &&b);
    ~Biblioteka();
    void RegistrirajNovogKorisnika (int clanski_broj_korisnika, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona);
    void RegistrirajNovuKnjigu(int evidencijski_broj_knjige, std::string naziv, std::string ime, std::string zanr, int godina);
    Korisnik& NadjiKorisnika(int clanski_broj) const;
    Knjiga& NadjiKnjigu(int evidencijski_broj) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int clanski_broj) const;
};
//KOPIRAJUCI KONSTRUKTOR
Biblioteka::Biblioteka(const Biblioteka &b) {
    for (auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++) {
        std::shared_ptr<Knjiga> novi(std::make_shared<Knjiga>(it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja()));
        novi->Knjiga::ZaduziKnjigu(*(it->second->DajKodKogaJe()));
        mapa_knjiga.insert(std::make_pair(it->first,novi));
     //   it->second=nullptr;
    }
   for (auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++) {
        std::shared_ptr<Korisnik> novi(new Korisnik);
        novi->ime=it->second->ime;
        novi->prezime=it->second->prezime;
        novi->adresa=it->second->adresa;
        novi->telefon=it->second->telefon;
        mapa_korisnika.insert(std::make_pair(it->first,novi));
    //    it->second=nullptr;
    }
}
//POMIJERAJUCI KONSTRUKTOR
Biblioteka::Biblioteka(Biblioteka && b) {
    for (auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++) {
        mapa_knjiga.insert(std::make_pair(it->first, it->second));
        it->second=nullptr;
    }
    for (auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++) {
        mapa_korisnika.insert(std::make_pair(it->first, it->second));
        it->second=nullptr;
    }
}
//OPERATOR DODJELE
Biblioteka &Biblioteka::operator = (const Biblioteka &b) {
    for (auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++) {
        std::shared_ptr<Korisnik> novi(new Korisnik);
        novi->ime=it->second->ime;
        novi->prezime=it->second->prezime;
        novi->adresa=it->second->adresa;
        novi->telefon=it->second->telefon;
        mapa_korisnika.insert(std::make_pair(it->first,novi));
    //    (it->second)=nullptr;
    }
    for (auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++) {
        std::shared_ptr<Knjiga> novi= std::make_shared<Knjiga>(it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja());
        novi->Knjiga::ZaduziKnjigu(*((it->second)->DajKodKogaJe()));
        mapa_knjiga.insert(std::make_pair(it->first,novi));
       // it->second=nullptr;
    }
    return *this;
}
//POMIJERAJUCI OPERATOR DODJELE
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
//DESTRUKTOR
Biblioteka::~Biblioteka() {
    for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) {
        it->second=nullptr;
    }
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
        it->second=nullptr;
}
//REGISTRIRAJ KORISNIKA
void Biblioteka::RegistrirajNovogKorisnika (int clanski_broj_korisnika, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona) {
    for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
        if (it->first==clanski_broj_korisnika) throw std::logic_error("Korisnik vec postoji");
    std::shared_ptr<Korisnik>novi(new Korisnik);
    novi->ime=ime;
    novi->prezime=prezime;
    novi->adresa=adresa;
    novi->telefon=broj_telefona;
    mapa_korisnika.insert(std::make_pair(clanski_broj_korisnika,novi));
}

void Biblioteka::RegistrirajNovuKnjigu (int evidencijski_broj_knjige, std::string naziv, std::string ime, std::string zanr, int godina) {
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) 
        if (it->first==evidencijski_broj_knjige) throw std::logic_error("Knjiga vec postoji");
    std::shared_ptr<Knjiga> nova=std::make_shared<Knjiga>(naziv,ime,zanr,godina);
    mapa_knjiga.insert(std::make_pair(evidencijski_broj_knjige,nova));
}

Korisnik& Biblioteka::NadjiKorisnika (int clanski_broj) const{
    for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
        if (clanski_broj==it->first) 
            return *(it->second);
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
        if ((it->second)->DaLiJeZaduzena()) 
            std::cout<<"Zaduzena kod korisnika: "<<(it->second)->DajKodKogaJe()->Korisnik::ime<<" "<<(it->second)->DajKodKogaJe()->Korisnik::prezime<<std::endl;
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
    int a=0;
    auto k=NadjiKorisnika(clanski_broj);
    for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
        if (it->second->DajKodKogaJe()==&k) {
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl<<"Naslov: "<<(it->second)->DajNaslov()<<std::endl<<"Pisac: "<<(it->second)->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<(it->second)->DajZanr()<<std::endl<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl;
            a=1;
        }
    if (a==0) std::cout<<"Nema zaduzenja za tog korisnika!";
}

int main ()
{
    Biblioteka bib8;
bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
bib8.ZaduziKnjigu(2, 1);
bib8.IzlistajKnjige();
    
  /*  
    Korisnik k2 { "Niko", "Nikic", "Zmaja od Bosne bb", "123 456"};
Knjiga knj2("Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
knj2.ZaduziKnjigu(k2);
if(!knj2.DaLiJeZaduzena()) std::cout << "Knjiga je slobodna";
else std::cout << "Knjiga je zaduzena";
knj2.RazduziKnjigu();
if(!knj2.DaLiJeZaduzena()) std::cout << "\nKnjiga je slobodna";
else std::cout << "\nKnjiga je zaduzena";*/
	return 0;
}