/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <map>
#include <utility>
#include <memory>
struct Korisnik {
    std::string ime, prezime, adresa, telefon;  
};
class Knjiga {
        std::string Naslov, ImePisca, Zanr;
        int GodinaIzdavanja;
         Korisnik *zaduzenje;
    public:
        Knjiga(std::string Naslov, std::string ImePisca, std::string Zanr, int GodinaIzdavanja): zaduzenje(nullptr) {
            Knjiga::Naslov=Naslov; Knjiga::ImePisca=ImePisca; Knjiga::Zanr=Zanr; Knjiga::GodinaIzdavanja=GodinaIzdavanja;
        }
        std::string DajNaslov() const { return Naslov; }
        std::string DajAutora() const { return ImePisca; }
        std::string DajZanr() const { return Zanr; }
        int DajGodinuIzdavanja() const { return GodinaIzdavanja; }
        Korisnik *DajKodKogaJe() const { return zaduzenje; }
        void ZaduziKnjigu(Korisnik &korisnik) { zaduzenje=&korisnik; }
        void RazduziKnjigu() { zaduzenje=nullptr; }
        bool DaLiJeZaduzena()const{ if(zaduzenje==nullptr) return false; return true; }
};
class Biblioteka {
        std::map<int, std::shared_ptr<Korisnik>> MapaKorisnika;
        std::map<int, std::shared_ptr<Knjiga>> MapaKnjiga;
    public:
        Biblioteka()=default;
        Biblioteka(const Biblioteka &b);
        Biblioteka(Biblioteka &&b);
        Biblioteka &operator=(const Biblioteka &b);
        Biblioteka &operator=(Biblioteka &&b);
        void RegistrirajNovogKorisnika(int clanskibroj, std::string ime, std::string prezime, std::string adresa, std::string telefon);
        void RegistrirajNovuKnjigu(int brojknjige, std::string Naslov, std::string ImePisca, std::string Zanr, int GodinaIzdavanja);
        Korisnik &NadjiKorisnika(int clanskibroj);
        Knjiga &NadjiKnjigu(int brojknjige);
        void IzlistajKorisnike()const;
        void IzlistajKnjige()const;
        void ZaduziKnjigu(int brojknjige, int clanskibroj);
        void RazduziKnjigu(int brojknjige);
        void PrikaziZaduzenja(int clanskibroj);
};
Biblioteka::Biblioteka(const Biblioteka &b) {
    for(auto it(b.MapaKorisnika.begin()); it!=b.MapaKorisnika.end(); it++) {
        MapaKorisnika.insert(std::make_pair(it->first, it->second));
    }
    for(auto it(b.MapaKnjiga.begin()); it!=b.MapaKnjiga.end(); it++) {
        MapaKnjiga.insert(std::make_pair(it->first, it->second));
    }
}
Biblioteka::Biblioteka(Biblioteka &&b) { // ili sa : vidjet cemo
    MapaKnjiga=b.MapaKnjiga,
    MapaKorisnika=b.MapaKorisnika;
    b.MapaKnjiga.clear();
    b.MapaKorisnika.clear();
}
Biblioteka &Biblioteka::operator =(const Biblioteka &b) {
    MapaKorisnika.clear();
    MapaKnjiga.clear();
    for(auto it(b.MapaKorisnika.begin()); it!=b.MapaKorisnika.end(); it++) {
        MapaKorisnika.insert(std::make_pair(it->first, it->second));
    }
    for(auto it(b.MapaKnjiga.begin()); it!=b.MapaKnjiga.end(); it++) {
         MapaKnjiga.insert(std::make_pair(it->first, it->second));
    }
    return *this;
}
Biblioteka &Biblioteka::operator =(Biblioteka &&b) {
    std::swap(MapaKnjiga, b.MapaKnjiga); std::swap(MapaKorisnika, b.MapaKorisnika);
    return *this;
}
void Biblioteka::RegistrirajNovogKorisnika(int clanskibroj, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
    auto it(MapaKorisnika.find(clanskibroj));
    if(it==MapaKorisnika.end()) {
        auto novi(std::make_shared<Korisnik>());
        novi->ime=ime;
        novi->prezime=prezime;
        novi->adresa=adresa;
        novi->telefon=telefon;
        MapaKorisnika.insert(std::make_pair(clanskibroj, novi));
    }
    else throw std::logic_error("Korisnik vec postoji");
}
void Biblioteka::RegistrirajNovuKnjigu(int brojknjige, std::string Naslov, std::string ImePisca, std::string Zanr, int GodinaIzdavanja) {
    auto it(MapaKnjiga.find(brojknjige));
    if(it==MapaKnjiga.end()) {
        std::shared_ptr<Knjiga>nova=std::make_shared<Knjiga>(Naslov, ImePisca, Zanr, GodinaIzdavanja);
        MapaKnjiga.insert(std::make_pair(brojknjige, nova));
    }
    else throw std::logic_error("Knjiga vec postoji");
}
Korisnik &Biblioteka::NadjiKorisnika(int clanskibroj) {
    auto it(MapaKorisnika.find(clanskibroj));
    if(it==MapaKorisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    return *(MapaKorisnika[clanskibroj]);
}
Knjiga &Biblioteka::NadjiKnjigu(int brojknjige) {
    auto it(MapaKnjiga.find(brojknjige));
    if(it==MapaKnjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    return *(MapaKnjiga[brojknjige]);
}
void Biblioteka::IzlistajKorisnike() const {
    for(auto it(MapaKorisnika.begin()); it!=MapaKorisnika.end(); it++) {
        std::cout << "Clanski broj: " << it->first << std::endl;
        std::cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl;
        std::cout << "Adresa: " << it->second->adresa << std::endl;
        std::cout << "Broj telefona: " << it->second->telefon << std::endl << std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const {
    int broj(0);
    for(auto it(MapaKnjiga.begin()); it!=MapaKnjiga.end(); it++) {
        std::cout << "Evidencijski broj: " << it->first << std::endl;
        std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
        std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
        if(it->second->DaLiJeZaduzena()) {
            std::cout << "Zaduzena kod korisnika: " <<
            it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime << std::endl << std::endl;
            broj=1;
        }
        if(broj==0) std::cout << std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int brojknjige, int clanskibroj) {
    auto it(MapaKnjiga.find(brojknjige));
    if(it==MapaKnjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    auto at(MapaKorisnika.find(clanskibroj));
    if(at==MapaKorisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    if(it->second->DaLiJeZaduzena()==true) throw std::logic_error("Knjiga vec zaduzena");
    it->second->ZaduziKnjigu(*MapaKorisnika[clanskibroj]);
}
void Biblioteka::RazduziKnjigu(int brojknjige) {
    auto it(MapaKnjiga.find(brojknjige));
    if(it==MapaKnjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    if(it->second->DaLiJeZaduzena()==false) throw std::logic_error("Knjiga nije zaduzena");
    it->second->RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clanskibroj) {
    auto it(MapaKorisnika.find(clanskibroj));
    if(it==MapaKorisnika.end()) throw std::domain_error("Korisnik nije nadjen");
    std::vector<Knjiga> knjige;
    std::vector<int> brojknjiga;
    Korisnik duzbenik=NadjiKorisnika(clanskibroj);
    for(auto at(MapaKnjiga.begin()); at!=MapaKnjiga.end(); at++) {
        if(duzbenik.ime==at->second->DajKodKogaJe()->ime && duzbenik.prezime==at->second->DajKodKogaJe()->prezime && duzbenik.adresa==at->second->DajKodKogaJe()->adresa && duzbenik.telefon==at->second->DajKodKogaJe()->telefon) {
            knjige.push_back(*(at->second));
            brojknjiga.push_back(at->first);
        }
    }
    if(knjige.size()==0) std::cout << "Nema zaduzenja za tog korisnika" << std::endl;
    else {
        for(int i(0); i<knjige.size(); i++) {
            std::cout << "Evidencijski broj: " << brojknjiga[i] << std::endl;
            std::cout << "Naslov: " << knjige[i].DajNaslov() << std::endl;
            std::cout << "Pisac: " << knjige[i].DajAutora() << std::endl;
            std::cout << "Zanr: " << knjige[i].DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << knjige[i].DajGodinuIzdavanja() << std::endl << std::endl;
        }
    }
}
int main (){
    Biblioteka bajbuk;
    for(;;) {
        std::cout << "Odaberite opciju: " << std::endl;
        std::cout << " 1 - Registriraj novog korisnika" << std::endl << " 2 - Registriraj novu knjigu" << std::endl << " 0 - Kraj registracija" << std::endl;
        int opcija;
        std::cin >> opcija;
        if(!std::cin && opcija!=1 && opcija!=2 && opcija!=0) std::cout << "Ponovo pokreni program! Pazi sta unosis";
        if(opcija==1) {
            std::cout << "Unesite podatke za korisnika: " << std::endl;
            std::string ime, prezime, adresa, telefon;
            int clanskibroj;
            std::cout << "Unesite clanski broj: ";
            std::cin >> clanskibroj;
            std::cin.ignore(100000, '\n');
            std::cout << "Unesite ime: ";
            std::getline(std::cin, ime);
            std::cout << "Unesite prezime: ";
            std::getline(std::cin, prezime);
            std::cout << "Unesite adresu: ";
            std::getline(std::cin, adresa);
            std::cout << "Unesite broj telefona: ";
            std::getline(std::cin, telefon);
            bajbuk.RegistrirajNovogKorisnika(clanskibroj, ime, prezime, adresa, telefon);
        }
        if(opcija==2) {
            std::cout << "Unesite podatke za knjigu: " << std::endl;
            int brojknjige, GodinaIzdavanja;
            std::string Naslov, ImePisca, Zanr;
            std::cin.ignore(10000, '\n');
            std::cout << "Unesite broj knjige: ";
            std::cin.ignore(10000, '\n');
            std::cin >> brojknjige;
            std::cout << "Unesite naslov: ";
            std::getline(std::cin, Naslov);
            std::cout << "Unesite autora: ";
            std::getline(std::cin, ImePisca);
            std::cout << "Unesite zanr: ";
            std::getline(std::cin, Zanr);
            std::cout << "Unesite godinu izdavanja: ";
            std::cin >> GodinaIzdavanja;
            bajbuk.RegistrirajNovuKnjigu(brojknjige, Naslov, ImePisca, Zanr, GodinaIzdavanja);
        }
        if(opcija==0) break;
    }
    for(;;) {
        int opcija;
        std::cout << "Unesite opciju: " << std::endl;
        std::cout << " 1 - Nadji korisnika" << std::endl << " 2 - Nadji knjigu" << std::endl << " 3 - Izlistaj korisnike" << std::endl
         << " 4 - Izlistaj knjige" << std::endl << " 5 - Zaduzi knjigu" << std::endl << " 6 - Razduzi knjigu" << std::endl << " 7 - Prikazi zaduzenja" << std::endl << " 0 - kraj" << std::endl;
        std::cin >> opcija;
        if(!std::cin && opcija!=1 && opcija!=2 && opcija!=3 && opcija!=4 && opcija!=5 && opcija!=6 && opcija!=7 && opcija!=0) std::cout << "Ponovo!" << std::endl;
        if(opcija==1) {
            int clanskibroj;
            std::cout << "Unesite clanski broj: ";
            std::cin >> clanskibroj;
            auto Korisnik=bajbuk.NadjiKorisnika(clanskibroj);
            std::cout << "Korisnik: " << Korisnik.ime << " " << Korisnik.prezime << " " << Korisnik.adresa << " " << Korisnik.telefon << std::endl;
        }
        if(opcija==2) {
            int brojknjige;
            std::cout << "Unesite broj knjige: ";
            std::cin >> brojknjige;
            auto Knjiga=bajbuk.NadjiKnjigu(brojknjige);
            std::cout << "Knjiga: " << Knjiga.DajNaslov() << " " << Knjiga.DajAutora() << " " << Knjiga.DajZanr() << " " << Knjiga.DajGodinuIzdavanja() << std::endl;
        }
        if(opcija==3) bajbuk.IzlistajKorisnike();
        if(opcija==4) bajbuk.IzlistajKnjige();
        if(opcija==5) {
            std::cout << "Unesite broj knjige i clanski broj korisnika: ";
            int brojknjige, clanskibroj;
            std::cin >> brojknjige >> clanskibroj;
            bajbuk.ZaduziKnjigu(brojknjige, clanskibroj);
        }
        if(opcija==6) {
            std::cout << "Unesite broj knjige: ";
            int brojknjige;
            std::cin >> brojknjige;
            bajbuk.RazduziKnjigu(brojknjige);
        }
        if(opcija==7) {
            std::cout << "Unesite clanski broj korisnika: ";
            int clanskibroj;
            std::cin >> clanskibroj;
            bajbuk.PrikaziZaduzenja(clanskibroj);
        }
        if(opcija==0) return 0;
    }
	return 0; 
}