/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>

using std::string;
using std::map;

class Student {
    int broj_indeksa;
    string godina_studija;
    string ime;
    string adresa;
    string broj_telefona;
    
    void PostaviIndeks(int);
    void PostaviTelefon(string);
    void PostaviGodinuStudija(string);
    void PostaviIme(string);
    void PostaviAdresu(string);
    string UkloniRazmake(string);
public:
    Student(int, string, string, string, string);
    int DajIndeks() const { return broj_indeksa; }
    string DajGodinuStudija() const { return godina_studija; }
    string DajImePrezime() const { return ime; }
    string DajAdresu() const { return adresa; }
    string DajTelefon() const { return broj_telefona; }
    void Ispisi() const;
};

void Student::PostaviIndeks(int broj_indeksa) {
    int indeks = broj_indeksa;
    int broj_cifara = 0;
    while(indeks) {
        broj_cifara++;
        indeks /= 10;
    }
    if(broj_cifara != 5)
        throw std::domain_error("Neispravni parametri");
    this -> broj_indeksa = broj_indeksa;
}

void Student::PostaviTelefon(string telefon) {
    int i = 0;
    bool validan = true;
    while(telefon[i] >= '0' && telefon[i] <= '9' && i < telefon.length())
        i++;
    if(telefon[i] != '/' || i == 0)
        validan = false;
    else
        i++;
    while(telefon[i] >= '0' && telefon[i] <= '9' && i < telefon.length())
        i++;
    if(telefon[i] != '-' || telefon[i - 1] == '/')
        validan = false;
    else
        i++;
    while(telefon[i] >= '0' && telefon[i] <= '9' && i < telefon.length())
        i++;
    if(i == telefon.length() && validan)
        broj_telefona = telefon;
    else
        throw std::domain_error("Neispravni parametri");
}

void Student::PostaviGodinuStudija(string godina) {
    string validna_godina = "";
    if(godina.length() == 1 && (godina[0] == '1' || godina[0] == '2' || godina[0] == '3')) {
        validna_godina.push_back(godina[0]);
        validna_godina += "/B";
    }
    else if(godina.length() == 3) {
        if((godina[0] == '1' || godina[0] == '2' || godina[0] == '3') && godina[1] == '/') {
            if(godina[2] == 'B' || godina[2] == 'D' || (godina[2] == 'M' && godina[0] != '3')) {
                validna_godina = godina;
            }
        }
    }
    if(validna_godina != "")
        this -> godina_studija = validna_godina;
    else
        throw std::domain_error("Neispravni parametri");
}

string Student::UkloniRazmake(string s) {
    string bez_razmaka = "";
    bool razmak = true;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != ' ') {
            bez_razmaka.push_back(s[i]);
            razmak = false;
        }
        else if(!razmak) {
            razmak = true;
            bez_razmaka.push_back(' ');
        }
    }
    bez_razmaka = (razmak == false) ? bez_razmaka : bez_razmaka.substr(0, bez_razmaka.length() - 1);
    return bez_razmaka;
}

void Student::PostaviIme(string ime) {
    this -> ime = UkloniRazmake(ime);
}

void Student::PostaviAdresu(string adresa) {
    this -> adresa = UkloniRazmake(adresa);
}

Student::Student(int broj_indeksa, string godina_studija, string ime, string adresa, string broj_telefona) {
    PostaviIndeks(broj_indeksa);
    PostaviGodinuStudija(godina_studija);
    PostaviIme(ime);
    PostaviAdresu(adresa);
    PostaviTelefon(broj_telefona);
}

void Student::Ispisi() const {
    std::cout << "Broj indeksa: " << broj_indeksa << "\n";
    std::cout << "Godina studija: " << godina_studija << "\n";
    std::cout << "Ime i prezime: " << ime << "\n";
    std::cout << "Adresa: " << adresa << "\n";
    std::cout << "Telefon: " << broj_telefona << "\n";
}

class Laptop {
    int ev_broj;
    string naziv;
    string karakteristike;
    Student* kod_koga_je;
public:
    Laptop(int, string, string);
    int DajEvidencijskiBroj() const { return ev_broj; }
    string DajNaziv() const { return naziv; }
    string DajKarakteristike() const { return karakteristike; }
    void Zaduzi(Student&);
    void Razduzi() { kod_koga_je = nullptr; }
    bool DaLiJeZaduzen() { return kod_koga_je != nullptr; }
    Student& KodKogaJe();
    void Ispisi() const;
};

Laptop::Laptop(int ev_broj, string naziv, string karakteristike) {
    if(ev_broj < 0)
        throw std::domain_error("Neispravni parametri");
    this -> ev_broj = ev_broj;
    this -> naziv = naziv;
    this -> karakteristike = karakteristike;
    this -> kod_koga_je = nullptr;
}

void Laptop::Zaduzi(Student& student) {
    if(DaLiJeZaduzen())
        throw std::domain_error("Laptop vec zaduzen");
    kod_koga_je = &student;
}

Student& Laptop::KodKogaJe() {
    if(!DaLiJeZaduzen())
        throw std::domain_error("Laptop nije zaduzen");
    return *kod_koga_je;
}

void Laptop::Ispisi() const {
    std::cout << "Evidencijski broj: " << ev_broj << std::endl;
    std::cout << "Naziv: " << naziv << std::endl;
    std::cout << "Karakteristike: " << karakteristike << std::endl;
}

class Administracija {
    map<int, std::shared_ptr<Student>> studenti;
    map<int, std::shared_ptr<Laptop>> laptopi;
public:
    Administracija() {}
    void RegistrirajNovogStudenta(int, string, string, string, string);
    void RegistrirajNoviLaptop(int, string, string);
    Student& NadjiStudenta(int);
    Student NadjiStudenta(int) const;
    Laptop& NadjiLaptop(int);
    Laptop NadjiLaptop(int) const;
    void IzlistajStudente() const;
    void IzlistajLaptope() const;
    void ZaduziLaptop(int, int);
    int NadjiSlobodniLaptop() const;
    void RazduziLaptop(int);
    void PrikaziZaduzenja() const;
};

void Administracija::RegistrirajNovogStudenta(int broj_indeksa, string godina_studija, string ime, string adresa, string broj_telefona) {
    auto it = studenti.find(broj_indeksa);
    if(it == studenti.end())
        studenti[broj_indeksa] = std::make_shared<Student>(broj_indeksa, godina_studija, ime, adresa, broj_telefona);
    else
        throw std::domain_error("Student s tim indeksom vec postoji");
}

void Administracija::RegistrirajNoviLaptop(int ev_broj, string naziv, string karakteristike) {
    auto it = laptopi.find(ev_broj);
    if(it == laptopi.end())
        laptopi[ev_broj] = std::make_shared<Laptop>(ev_broj, naziv, karakteristike);
    else
        throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
}

Student& Administracija::NadjiStudenta(int indeks) {
    auto it = studenti.find(indeks);
    if(it == studenti.end())
        throw std::domain_error("Student nije nadjen");
    return *it -> second;
}

Student Administracija::NadjiStudenta(int indeks) const {
    auto it = studenti.find(indeks);
    if(it == studenti.end())
        throw std::domain_error("Student nije nadjen");
    return *it -> second;
}

Laptop& Administracija::NadjiLaptop(int ev_broj) {
    auto it = laptopi.find(ev_broj);
    if(it == laptopi.end())
        throw std::domain_error("Laptop nije nadjen");
    return *it -> second;
}

Laptop Administracija::NadjiLaptop(int ev_broj) const {
    auto it = laptopi.find(ev_broj);
    if(it == laptopi.end())
        throw std::domain_error("Laptop nije nadjen");
    return *it -> second;
}

void Administracija::IzlistajStudente() const {
    for(auto it = studenti.begin(); it != studenti.end(); it++) {
        it -> second -> Ispisi();
        std::cout << std::endl;
    }
}

void Administracija::IzlistajLaptope() const {
    for(auto it = laptopi.begin(); it != laptopi.end(); it++) {
        std::shared_ptr<Laptop> laptop = it -> second;
        laptop -> Ispisi();
        if(laptop -> DaLiJeZaduzen()) {
            Student vlasnik = laptop -> KodKogaJe();
            std::cout << "Zaduzio(la): " << vlasnik.DajImePrezime() << " (" << vlasnik.DajIndeks() << ")";
        }
        std::cout << std::endl;    
    }
}

void Administracija::ZaduziLaptop(int indeks, int ev_broj) {
    auto student = studenti.find(indeks);
    if(student == studenti.end())
        throw std::domain_error("Student nije nadjen");

    auto laptop = laptopi.find(ev_broj);
    if(laptop == laptopi.end())
        throw std::domain_error("Laptop nije nadjen");
    
    if(laptop -> second -> DaLiJeZaduzen())
        throw std::domain_error("Laptop vec zaduzen");
        
    auto iter(std::find_if(laptopi.begin(), laptopi.end(), [indeks](const std::pair<int, std::shared_ptr<Laptop>>& it) {
        if((it.second) -> DaLiJeZaduzen() && ((it.second) -> KodKogaJe()).DajIndeks() == indeks) return true; return false; } ));
    if(iter == laptopi.end())
        laptop -> second -> Zaduzi(*student -> second);
    else
        throw std::domain_error("Student je vec zaduzio laptop");
}

int Administracija::NadjiSlobodniLaptop() const {
    auto iter(std::find_if(laptopi.begin(), laptopi.end(), [](const std::pair<int, std::shared_ptr<Laptop>>& it) {
        if(!(it.second) -> DaLiJeZaduzen()) return true; return false; } ));
    if(iter == laptopi.end())
        throw std::domain_error("Nema slobodnih laptopa");
    return iter -> second -> DajEvidencijskiBroj();
}

void Administracija::RazduziLaptop(int ev_broj) {
    auto it = laptopi.find(ev_broj);
    if(it == laptopi.end())
        throw std::domain_error("Laptop nije nadjen");
    if(it -> second -> DaLiJeZaduzen())
        it -> second -> Razduzi();
    else
        throw std::domain_error("Laptop nije zaduzen");
}

void Administracija::PrikaziZaduzenja() const {
    bool ima_zaduzenih = false;
    for(auto it = laptopi.begin(); it != laptopi.end(); it++) {
        std::shared_ptr<Laptop> laptop = it -> second;
        if(laptop -> DaLiJeZaduzen()) {
            Student vlasnik = laptop -> KodKogaJe();
            std::cout << "Student "<< vlasnik.DajImePrezime() << " (" << vlasnik.DajIndeks() << ") ";
            std::cout << "zaduzio/la laptop broj " << laptop -> DajEvidencijskiBroj() << "\n";
            ima_zaduzenih = true;
        }
        std::cout << std::endl;    
    }
    if(!ima_zaduzenih)
        std::cout << "Nema zaduzenja";
}

using std::cout;
using std::cin;
using std::getline;

int main () {
    Administracija administracija;
    cout << "1. Registracija studenta\n2. Registracija laptopa\n";
    cout << "3. Trazenje studenta\n4. Trazenje laptopa\n5. Ispis studenta\n";
    cout << "6. Ispis laptopa\n7. Zaduzenje laptopa\n8. Trazenje slobodnog laptopa\n";
    cout << "9. Razduzenje laptopa\n10. Prikaz zaduzenja\n0. ***IZLAZ***\n";
    
    try {
        while(1) {
            cout << "\nOdaberite opciju: ";
            int n;
            cin >> n;
            if(n == 1) {
                cin.ignore(9999, '\n');
                string ime, adresa, telefon, godina;
                int indeks;
                cout << "Unesite ime i prezime: ";
                getline(cin, ime);
                cout << "Unesite adresu: ";
                getline(cin, adresa);
                cout << "Unesite broj telefona: ";
                getline(cin, telefon);
                cout << "Unesite godinu studija: ";
                getline(cin, godina);
                cout << "Unesite broj indeksa: ";
                cin >> indeks;
                administracija.RegistrirajNovogStudenta(indeks, godina, ime, adresa, telefon);
            }
            else if(n == 2) {
                string naziv, karakteristike;
                int ev_broj;
                cin.ignore(9999, '\n');
                cout << "Unesite naziv: ";
                getline(cin, naziv);
                cout << "Unesite karakteristike: ";
                getline(cin, karakteristike);
                cout << "Unesite evidencijski broj: ";
                cin >> ev_broj;
                administracija.RegistrirajNoviLaptop(ev_broj, naziv, karakteristike);
            }
            else if(n == 3) {
                int indeks;
                cout << "Unesite indeks trazenog studenta: ";
                cin >> indeks;
                cout << "Student sa unesenim brojem indeksa:\n";
                administracija.NadjiStudenta(indeks).Ispisi();
            }
            else if(n == 4) {
                int ev_broj;
                cout << "Unesite evidencijski broj trazenog laptopa: ";
                cin >> ev_broj;
                cout << "Laptop sa unesenim evidencijskim brojem\n";
                administracija.NadjiLaptop(ev_broj).Ispisi();
            }
            else if(n == 5) {
                administracija.IzlistajStudente();
            }
            else if(n == 6) {
                administracija.IzlistajLaptope();
            }
            else if(n == 7) {
                int ev_broj, indeks;
                cout << "Unesite indeks studenta koji zaduzuje laptop: ";
                cin >> indeks;
                cout << "Unesite evidencijski broj laptopa: ";
                cin >> ev_broj;
                administracija.ZaduziLaptop(indeks, ev_broj);
            }
            else if(n == 8) {
                cout << "Prvi slobodan laptop je sa evidencijskim brojem: ";
                cout << administracija.NadjiSlobodniLaptop() << "\n";
            }
            else if(n == 9) {
                int ev_broj;
                cout << "Unesite evidencijski broj laptopa za razduzenje: ";
                cin >> ev_broj;
                administracija.RazduziLaptop(ev_broj);
            }
            else if(n == 10) {
                administracija.PrikaziZaduzenja();
            }
            else break;
        }
    }
    catch(std::domain_error greska) {
        std::cout << greska.what();
    }
	return 0;
}
