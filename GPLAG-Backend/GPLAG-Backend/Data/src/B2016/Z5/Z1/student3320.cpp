/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>
#include <iomanip>
#include <map>

struct Korisnik {
int Clanski_Broj;
std::string Ime[20];
std::string Prezime[20];
std::string Telefon[20];
std::string Adresa[100];
};

class Knjiga {
int id;
std::string Naslov;
std::string Autor;
std::string Zanr;
int Godina;
bool Zaduzen;
Korisnik *Zaduzenje;
public:
Knjiga(int broj, std::string Naslov1, std::string Autor1, std::string Zanr1, int Godina1) {
    if(Godina1<1 || Godina>2017) std::domain_error("Neispravna godina");
    id=broj;
    Naslov=Naslov1;
    Autor=Autor1;
    Zanr=Zanr1;
    Godina=Godina1;
    Zaduzen=false;
}
std::string DajNaslov() const { return Naslov; }
std::string DajAutora() const { return Autor; }
std::string DajZanr() const { return Zanr; }
int DajGodinuIzdavanja() const { return Godina; }
Korisnik &DajKodKogaJe() const { return *Zaduzenje; }
void ZaduziKnjigu(Korisnik &korisnik) { Zaduzenje=this->korisnik.Clanski_Broj; Zaduzen=true; }
void RazduziKnjigu() { Zaduzenje=nullptr; Zaduzen=false; }
bool DaLiJeZaduzena() const { return Zaduzen; }
};


class Biblioteka {
std::map<int, Korisnik>korisnik;
std::map<int, Knjiga>knjiga;
public:
Biblioteka(Biblioteka &&temp) : korisnik(temp.korisnik), knjiga(temp.knjiga) {};
void RegistrirajNovogKorisnika(int, std::string, std::string, std::string, std::string);
void RegistrirajNovuKnjigu(int, std::string, std::string, std::string, int);
};


void Biblioteka::RegistrirajNovogKorisnika(int broj1, std::string Ime1, std::string Prezime1, std::string Telefon1, std::string Adresa1) {
    auto iter=korisnik.find(broj1);
    Korisnik kor;
    if(iter == korisnik.end()) throw std::logic_error("Korisnik vec postoji");
    else korisnik.insert(std::make_pair(broj1, kor));
}

void Biblioteka::RegistrirajNovuKnjigu(int broj1, std::string Naslov1, std::string Autor1, std::string Zanr1, int Godina1) {
    if(Godina1<1 || Godina1>2017) throw std::domain_error("Neispravna godina");
    auto iter=knjiga.find(broj1);
    if(iter == knjiga.end()) throw std::logic_error("Knjiga vec postoji");
    else knjiga.insert(std::make_pair(broj1, Knjiga(broj1, Naslov1, Autor1, Zanr1, Godina1)));
}

int main () {
    
	return 0;
}