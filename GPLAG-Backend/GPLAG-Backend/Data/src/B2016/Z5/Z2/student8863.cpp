#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

using std::cin;
using std::cout;

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};
class Knjiga{
    std::string naslov, pisac, zanr;
    int godina_izdavanja;
    Korisnik *zaduzenik;
public:
    Knjiga(std::string naslov, std::string pisac, std::string zanr, int godina) : naslov(naslov), pisac(pisac), zanr(zanr), godina_izdavanja(godina), zaduzenik(nullptr) {}
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return pisac; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik* DajKodKogaJe() const { return zaduzenik; }
    void ZaduziKnjigu(Korisnik &k) { zaduzenik = &k; }
    void RazduziKnjigu() { zaduzenik = nullptr; }
    bool DaLiJeZaduzena() { return zaduzenik; }
};
class Biblioteka{
    std::map<int, Korisnik*> korisnik;
    std::map<int, Knjiga*> knjiga;
public:
    Biblioteka() {}
    ~Biblioteka() { for(auto it = korisnik.begin(); it != korisnik.end(); it++) delete it -> second; 
        for(auto it = knjiga.begin(); it != knjiga.end(); it++) delete it -> second; }
    Biblioteka(const Biblioteka &biblio);
    Biblioteka(Biblioteka &&biblio);
    Biblioteka &operator = (const Biblioteka &biblio);
    Biblioteka &operator = (Biblioteka &&biblio);
    void RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string br_telefona);
    void RegistrirajNovuKnjigu(int br_knjige, std::string naslov_knjige, std::string ime_pisca, std::string zanr_knjige, int god_izdavanja);
    Korisnik &NadjiKorisnika(int cl_broj);
    Knjiga &NadjiKnjigu(int br_knjige);
    void IzlistajKorisnike();
    void IzlistajKnjige();
    void ZaduziKnjigu(int br_knjige, int cl_broj);
    void RazduziKnjigu(int br_knjige);
    void PrikaziZaduzenja(int cl_broj);
};
Biblioteka::Biblioteka(const Biblioteka &biblio){
    try{
        for(auto it = biblio.korisnik.begin(); it != biblio.korisnik.end(); it++) korisnik.insert(std::pair<int, Korisnik*>(it -> first, new Korisnik(*(it -> second))));
    } catch(...){
        for(auto it = korisnik.begin(); it != korisnik.end(); it++) delete it -> second; throw;
    }
    try{
        for(auto it = biblio.knjiga.begin(); it != biblio.knjiga.end(); it++) knjiga.insert(std::pair<int, Knjiga*>(it -> first, new Knjiga(*(it -> second))));
    } catch(...){
        for(auto it = knjiga.begin(); it != knjiga.end(); it++) delete it -> second; throw;
    }        
} // kopirajuci 1
Biblioteka::Biblioteka(Biblioteka &&biblio){
    for(auto it = biblio.korisnik.begin(); it != biblio.korisnik.end(); it++) {
        korisnik.insert(std::pair<int, Korisnik*>(it -> first, it -> second));
        it -> second = nullptr;
    }
    for(auto it = biblio.knjiga.begin(); it != biblio.knjiga.end(); it++) {
        knjiga.insert(std::pair<int, Knjiga*>(it -> first, it -> second));
        it -> second = nullptr;
    }
} // kopirajuci 2
Biblioteka &Biblioteka::operator = (const Biblioteka &biblio){
    std::map<int, Korisnik*> novi_korisnik;
    std::map<int, Knjiga*> nova_knjiga;
    try{
        for(auto it = biblio.korisnik.begin(); it != biblio.korisnik.end(); it++) novi_korisnik.insert(std::pair<int, Korisnik*>(it -> first, new Korisnik(*(it -> second))));
        for(auto it = biblio.knjiga.begin(); it != biblio.knjiga.end(); it++) nova_knjiga.insert(std::pair<int, Knjiga*>(it -> first, new Knjiga(*(it -> second))));   
    } catch(...){
        for(auto it = novi_korisnik.begin(); it != novi_korisnik.end(); it++) delete it -> second;
        for(auto it = nova_knjiga.begin(); it != nova_knjiga.end(); it++) delete it -> second;
        throw;
    }
    for(auto it = korisnik.begin(); it != korisnik.end(); it++){ delete it -> second; korisnik.erase(it); }
    for(auto it = knjiga.begin(); it != knjiga.end(); it++){ delete it -> second; knjiga.erase(it); }
    for(auto it = novi_korisnik.begin(); it != novi_korisnik.end(); it++) korisnik.insert(std::pair<int, Korisnik*>(it -> first, it -> second));
    for(auto it = nova_knjiga.begin(); it != nova_knjiga.end(); it++) knjiga.insert(std::pair<int, Knjiga*>(it -> first, it -> second));
    return *this;
} // opreator dodjele 1
Biblioteka &Biblioteka::operator = (Biblioteka &&biblio){
    std::swap(korisnik, biblio.korisnik);
    std::swap(knjiga, biblio.knjiga);
    return *this;
} // operator dodjele 2
void Biblioteka::RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string br_telefona){
    if(korisnik.find(cl_broj) != korisnik.end()) throw std::logic_error("Korisnik vec postoji");
    Korisnik pomocni; pomocni.ime = ime; pomocni.prezime = prezime; pomocni.adresa = adresa; pomocni.telefon = br_telefona;
    korisnik.insert(std::pair<int, Korisnik*>(cl_broj, new Korisnik(pomocni)));
} // registracija korisnika
void Biblioteka::RegistrirajNovuKnjigu(int br_knjige, std::string naslov, std::string pisac, std::string zanr, int godina){
    if(knjiga.find(br_knjige) != knjiga.end()) throw std::logic_error("Knjiga vec postoji");
    knjiga.insert(std::pair<int, Knjiga*>(br_knjige, new Knjiga(naslov, pisac, zanr, godina)));
} // registracija knjige
Korisnik &Biblioteka::NadjiKorisnika(int cl_broj){
    auto it(korisnik.find(cl_broj));
    if(it == korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
    return *(it -> second);
} // pretraga korisnika
Knjiga &Biblioteka::NadjiKnjigu(int br_knjige){
    auto it(knjiga.find(br_knjige));
    if(it == knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    return *(it -> second);
} // pretraga knjiga
void Biblioteka::IzlistajKorisnike(){
    for(auto it = korisnik.begin(); it != korisnik.end(); it++)
        cout << "Clanski broj: " << it -> first << std::endl << "Ime i prezime: " << it -> second -> ime << " " << it -> second -> prezime << std::endl 
        << "Adresa: " << it -> second -> adresa << std::endl << "Broj telefona: " << it -> second -> telefon << std::endl << std::endl;
} // ispis korisnika
void Biblioteka::IzlistajKnjige(){
    for(auto it = knjiga.begin(); it != knjiga.end(); it++){
        cout << "Evidencijski broj: " << it -> first << std::endl << "Naslov: " << it -> second -> DajNaslov() << std::endl << "Pisac: " << it -> second -> DajAutora() << std::endl
        << "Zanr: " << it -> second -> DajZanr() << std::endl << "Godina izdavanja: " << it -> second -> DajGodinuIzdavanja() << std::endl;
        if(it -> second -> DaLiJeZaduzena()) cout << "Zaduzena kod korisnika: " << it -> second -> DajKodKogaJe() -> ime << " " << it -> second -> DajKodKogaJe() -> prezime << std::endl;
        cout << std::endl;
    }
} // ispis knjiga
void Biblioteka::ZaduziKnjigu(int br_knjige, int cl_broj){
    auto it1(knjiga.find(br_knjige));
    auto it2(korisnik.find(cl_broj));
    if(it1 == knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    if(it2 == korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
    if(it1 -> second -> DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    it1 -> second -> ZaduziKnjigu(*(it2 -> second));
} // zaduzivanje knjige
void Biblioteka::RazduziKnjigu(int br_knjige){
    auto it(knjiga.find(br_knjige));
    if(it == knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    if(!(it -> second -> DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
    it -> second -> RazduziKnjigu();
} // razduzivanje knjige
void Biblioteka::PrikaziZaduzenja(int cl_broj){
    auto user(korisnik.find(cl_broj));
    if(user == korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
    bool zaduzena;
    for(auto book = knjiga.begin(); book != knjiga.end(); book++){
        if((book -> second -> DajKodKogaJe()) == &(*(user -> second))) cout << "Evidencijski broj: " << book -> first << std::endl 
        << "Naslov: " << book -> second -> DajNaslov() << std::endl << "Pisac: " << book -> second -> DajAutora() << std::endl
        << "Zanr: " << book -> second -> DajZanr() << std::endl << "Godina izdavanja: " << book -> second -> DajGodinuIzdavanja() << std::endl << std::endl;
        zaduzena = true;
    }
    if(!zaduzena) throw std::logic_error("Nema zaduzenja za tog korisnika");
}
int main ()
{
	return 0;
}