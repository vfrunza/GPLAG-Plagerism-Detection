#include "Student.h"
#include "Laptop.h"

#include "Administracija.h"

Administracija::Administracija(Student* s, Laptop* l) {
    student = new Student(s->DajIndeks(), s->DajGodinuStudija(), s->DajImePrezime(), s->DajAdresu(), s->DajTelefon());
    laptop = new Laptop(l->DajEvidencijskiBroj(), l->DajNaziv(), l->DajKarakteristike());
    
}

Administracija::Administracija(const Administracija& o) {
    student = new Student(o.student->DajIndeks(), o.student->DajGodinuStudija(), o.student->DajImePrezime(), o.student->DajAdresu(), o.student->DajTelefon());
    laptop = new Laptop(o.laptop->DajEvidencijskiBroj(), o.laptop->DajNaziv(), o.laptop->DajKarakteristike());
    *student = *o.student;
    *laptop = *o.laptop;
    
} 

void Administracija::RegistrirajNovogStudenta(int indeks, std::string godinaStudija, std::string imePrezime, std::string adresa, std::string telefon) {
    Student *s = new Student(indeks, godinaStudija, imePrezime, adresa, telefon);
    if (mapaStudenata.find(indeks) == mapaStudenata.end())
        mapaStudenata.insert(std::pair<int, Student*> (s->DajIndeks(),s));
    else throw std::domain_error("Student s tim indeksom vec postoji");
}

Student& Administracija::NadjiStudenta(int brojIndeksa) {
    if (mapaStudenata.find(brojIndeksa) == mapaStudenata.end())
        return *this->student;
    else throw std::domain_error("Student nije nadjen");
}

Student Administracija::NadjiStudenta(const Administracija& o) {
    if (mapaStudenata.find(student->DajIndeks()) == mapaStudenata.end())
        return *student;
    else throw std::domain_error("Student nije nadjen");
}

Laptop& Administracija::NadjiLaptop(int ev_broj) {
    if (mapaLaptopa.find(ev_broj) == mapaLaptopa.end())
        return *this->laptop;
    else throw std::domain_error("Laptop nije nadjen");
}

Laptop Administracija::NadjiLaptop(const Laptop& o) {
    if (mapaLaptopa.find(laptop->DajEvidencijskiBroj()) == mapaLaptopa.end())
        return *laptop;
    else throw std::domain_error("Laptop nije nadjen");
}

void Administracija::IzlistajStudente() {
    int brojac = 1;
    
    for (auto &s:mapaStudenata) {
        std::cout << "Broj indeksa: " << s.first << std::endl;
        std::cout << "Godina studija: " << s.second->DajGodinuStudija() << std::endl;
        std::cout << "Ime i prezime: " << s.second->DajImePrezime() << std::endl;
        std::cout << "Adresa: " << s.second->DajAdresu() << std::endl;
        std::cout << "Telefon: " << s.second->DajTelefon() << std::endl;
        
        if (brojac %2 == 0) std::cout << std::endl;
        
    }
}

void Administracija::IzlistajLaptope() {
    for (auto &l: mapaLaptopa) {
        std::cout << "Evidencijski broj: " << l.first << std::endl;
        std::cout << "Naziv: " << l.second->DajNaziv() << std::endl;
        std::cout << "Karakteristike: " << l.second->DajKarakteristike() << std::endl;
        
        if(l.second->DaLiJeZaduzen()) {
            std::string zaduzio = l.second->DajPokKodKogaJe() -> DajImePrezime();
        
            std::cout << "Zaduzio(la): " << zaduzio << "(" << l.second->DajPokKodKogaJe()->DajIndeks() << ")";
            
        }
    }
}

void Administracija::ZaduziLaptop(int indeks, int evBroj) {
    *student = NadjiStudenta(indeks);
    *laptop = NadjiLaptop(evBroj);
    
    if(!laptop->DaLiJeZaduzen()) laptop->Zaduzi(*student);
    else throw std::domain_error("Student je vec zaduzio laptop");
}

int Administracija::NadjiSlobodanLaptop() {
    
    for(const auto &l: mapaLaptopa) {
        if (!l.second->DaLiJeZaduzen()) 
            return l.first;
    }
    
    throw std::domain_error("Nema slobodnih laptopa");
}

#include <iostream>
#include <stdexcept>
#include "Student.h"
#include <map>
#include "Laptop.h"

#ifndef ADMINISTRACIJA_H
#define ADMINISTRACIJA_H

class Administracija {
    
    private:
        Student* student;
        Laptop* laptop;
        std::map <int, Student*> mapaStudenata;
        std::map <int, Laptop*> mapaLaptopa;
        
    public:
        Administracija(Student* s, Laptop* l);
        Administracija(const Administracija& obj);
        void RegistrirajNovogStudenta(int indeks, std::string godinaStudija, std::string imePrezime, std::string adresa, std::string telefon);
        Student& NadjiStudenta(int);
        Student NadjiStudenta(const Administracija&);
        Laptop& NadjiLaptop(int);
        Laptop NadjiLaptop(const Laptop&);
        void IzlistajStudente();
        void ZaduziLaptop(int,int);
        int NadjiSlobodanLaptop();
        //~Administracija();
};
#endif

#include "Laptop.h"

Laptop::Laptop(int ev_broj, std::string naziv, std::string karakteristike) {
    
    if (ev_broj < 0) throw std::domain_error("Neispravni parametri");
    this->ev_broj = ev_broj;
    this->naziv = naziv;
    this->karakteristike = karakteristike;
    this->kod_koga_je = nullptr;
}

int Laptop::DajEvidencijskiBroj() {
    return ev_broj;
}

std::string Laptop::DajNaziv() {
    return naziv;
}

std::string Laptop::DajKarakteristike() {
    return karakteristike;
}

void Laptop::Zaduzi(Student &student) {
    if (kod_koga_je == nullptr) throw std::domain_error("Laptop vec zaduzen");
    *kod_koga_je = student;
}

void Laptop::Razduzi() {
    kod_koga_je = nullptr;
}

bool Laptop::DaLiJeZaduzen() {
    return kod_koga_je == nullptr;
}

Student& Laptop::DajKodKogaJe() {
    if (kod_koga_je == nullptr) throw std::domain_error("Laptop nije zaduzen");
    return *kod_koga_je;
}

Student* Laptop::DajPokKodKogaJe() {
    return kod_koga_je;
}

void Laptop::Ispisi() {
    std::cout << "Evidencijski broj: " DajEvidencijskiBroj() << std::endl;
    std::cout << "Naziv: " << DajNaziv() << std::endl;
    std::cout << "Karakteristike: " << DajKarakteristike() << std::endl;
}


#include "Administracija.h"

Administracija::Administracija(Student* s, Laptop* l) {
    student = new Student(s->DajIndeks(), s->DajGodinuStudija(), s->DajImePrezime(), s->DajAdresu(), s->DajTelefon());
    laptop = new Laptop(l->DajEvidencijskiBroj(), l->DajNaziv(), l->DajKarakteristike());
    
}

Administracija::Administracija(const Administracija& o) {
    student = new Student(o.student->DajIndeks(), o.student->DajGodinuStudija(), o.student->DajImePrezime(), o.student->DajAdresu(), o.student->DajTelefon());
    laptop = new Laptop(o.laptop->DajEvidencijskiBroj(), o.laptop->DajNaziv(), o.laptop->DajKarakteristike());
    *student = *o.student;
    *laptop = *o.laptop;
    
} 

void Administracija::RegistrirajNovogStudenta(int indeks, std::string godinaStudija, std::string imePrezime, std::string adresa, std::string telefon) {
    Student *s = new Student(indeks, godinaStudija, imePrezime, adresa, telefon);
    if (mapaStudenata.find(indeks) == mapaStudenata.end())
        mapaStudenata.insert(std::pair<int, Student*> (s->DajIndeks(),s));
    else throw std::domain_error("Student s tim indeksom vec postoji");
}

Student& Administracija::NadjiStudenta(int brojIndeksa) {
    if (mapaStudenata.find(brojIndeksa) == mapaStudenata.end())
        return *this->student;
    else throw std::domain_error("Student nije nadjen");
}

Student Administracija::NadjiStudenta(const Administracija& o) {
    if (mapaStudenata.find(student->DajIndeks()) == mapaStudenata.end())
        return *student;
    else throw std::domain_error("Student nije nadjen");
}

Laptop& Administracija::NadjiLaptop(int ev_broj) {
    if (mapaLaptopa.find(ev_broj) == mapaLaptopa.end())
        return *this->laptop;
    else throw std::domain_error("Laptop nije nadjen");
}

Laptop Administracija::NadjiLaptop(const Laptop& o) {
    if (mapaLaptopa.find(laptop->DajEvidencijskiBroj()) == mapaLaptopa.end())
        return *laptop;
    else throw std::domain_error("Laptop nije nadjen");
}

void Administracija::IzlistajStudente() {
    int brojac = 1;
    
    for (auto &s:mapaStudenata) {
        std::cout << "Broj indeksa: " << s.first << std::endl;
        std::cout << "Godina studija: " << s.second->DajGodinuStudija() << std::endl;
        std::cout << "Ime i prezime: " << s.second->DajImePrezime() << std::endl;
        std::cout << "Adresa: " << s.second->DajAdresu() << std::endl;
        std::cout << "Telefon: " << s.second->DajTelefon() << std::endl;
        
        if (brojac %2 == 0) std::cout << std::endl;
        
    }
}

void Administracija::IzlistajLaptope() {
    for (auto &l: mapaLaptopa) {
        std::cout << "Evidencijski broj: " << l.first << std::endl;
        std::cout << "Naziv: " << l.second->DajNaziv() << std::endl;
        std::cout << "Karakteristike: " << l.second->DajKarakteristike() << std::endl;
        
        if(l.second->DaLiJeZaduzen()) {
            std::string zaduzio = l.second->DajPokKodKogaJe() -> DajImePrezime();
        
            std::cout << "Zaduzio(la): " << zaduzio << "(" << l.second->DajPokKodKogaJe()->DajIndeks() << ")";
            
        }
    }
}

void Administracija::ZaduziLaptop(int indeks, int evBroj) {
    *student = NadjiStudenta(indeks);
    *laptop = NadjiLaptop(evBroj);
    
    if(!laptop->DaLiJeZaduzen()) laptop->Zaduzi(*student);
    else throw std::domain_error("Student je vec zaduzio laptop");
}

int Administracija::NadjiSlobodanLaptop() {
    
    for(const auto &l: mapaLaptopa) {
        if (!l.second->DaLiJeZaduzen()) 
            return l.first;
    }
    
    throw std::domain_error("Nema slobodnih laptopa");
}

#include <iostream>
#include <stdexcept>
#include "Student.h"
#include <map>
#include "Laptop.h"

#ifndef ADMINISTRACIJA_H
#define ADMINISTRACIJA_H

class Administracija {
    
    private:
        Student* student;
        Laptop* laptop;
        std::map <int, Student*> mapaStudenata;
        std::map <int, Laptop*> mapaLaptopa;
        
    public:
        Administracija(Student* s, Laptop* l);
        Administracija(const Administracija& obj);
        void RegistrirajNovogStudenta(int indeks, std::string godinaStudija, std::string imePrezime, std::string adresa, std::string telefon);
        Student& NadjiStudenta(int);
        Student NadjiStudenta(const Administracija&);
        Laptop& NadjiLaptop(int);
        Laptop NadjiLaptop(const Laptop&);
        void IzlistajStudente();
        void ZaduziLaptop(int,int);
        int NadjiSlobodanLaptop();
        //~Administracija();
};
#endif

#include "Laptop.h"

Laptop::Laptop(int ev_broj, std::string naziv, std::string karakteristike) {
    
    if (ev_broj < 0) throw std::domain_error("Neispravni parametri");
    this->ev_broj = ev_broj;
    this->naziv = naziv;
    this->karakteristike = karakteristike;
    this->kod_koga_je = nullptr;
}

int Laptop::DajEvidencijskiBroj() {
    return ev_broj;
}

std::string Laptop::DajNaziv() {
    return naziv;
}

std::string Laptop::DajKarakteristike() {
    return karakteristike;
}

void Laptop::Zaduzi(Student &student) {
    if (kod_koga_je == nullptr) throw std::domain_error("Laptop vec zaduzen");
    *kod_koga_je = student;
}

void Laptop::Razduzi() {
    kod_koga_je = nullptr;
}

bool Laptop::DaLiJeZaduzen() {
    return kod_koga_je == nullptr;
}

Student& Laptop::DajKodKogaJe() {
    if (kod_koga_je == nullptr) throw std::domain_error("Laptop nije zaduzen");
    return *kod_koga_je;
}

Student* Laptop::DajPokKodKogaJe() {
    return kod_koga_je;
}

void Laptop::Ispisi() {
    std::cout << "Evidencijski broj: " DajEvidencijskiBroj() << std::endl;
    std::cout << "Naziv: " << DajNaziv() << std::endl;
    std::cout << "Karakteristike: " << DajKarakteristike() << std::endl;
}


#include "Student.h"

bool Student::jeLiValidanStudij(std::string godinaStudija) {
    const std::vector<std::string> &godineStudija{"1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D", "3/D"};
    return std::find(godineStudija.begin(), godineStudija.end(), godinaStudija) != godineStudija.end();
}

std::string Student::ukloniRazmake(std::string imePrezime) {
    std::string pocetak = ukloniPocetak(imePrezime);
    std::string novoImePrezime = ukloniKraj(pocetak);
    
    std::string rijec;
    std::string rezultat = "";
    int broj_razmaka = 0;
    
    for(int i=0; i<novoImePrezime.length(); i++) {
        rijec = izdvojiRijec(novoImePrezime, i);
        i=i+rijec.length();
        broj_razmaka = prebrojiRazmake(novoImePrezime,i);
        i = i + broj_razmaka;
        rezultat = rezultat + " " + rijec;
    }
    
    return rezultat.substr(1);
}

std::string Student::ukloniPocetak(std::string unos) {
    int i=0;
    
    if(unos[0] == ' ') {
        while (unos[i] == ' ') {
            i++;
        }
    }
    return unos.substr(i);
    
}

std::string Student::ukloniKraj(std::string unos) {
    int i=0;
    int kraj = unos.length();
    
    if(unos[kraj] == ' ') {
        while (unos[kraj] == ' ') {
            kraj--;
        }
    }
    return unos.substr(0,kraj);
}

std::string Student::izdvojiRijec(std::string unos, int i) {
    std::string rezultat = "";
    
    while (i<unos.length() && unos[i] != ' ') {
        rezultat = rezultat + unos[i];
        i++;
    }
    
    return rezultat;
}

int Student::prebrojiRazmake(std::string recenica, int i) {
    int brojac = 0;
    
    while(recenica[i] == ' ') {
        brojac++;
        i++;
    }
    
    if (brojac >= 1)
        return brojac - 1;
    
    return brojac;
    
}

bool Student::jeLiValidanTelefon(std::string telefon) {
    int i=0;
    
    while (isdigit(telefon[i])) 
        i++;
        
    if (telefon[i] != '/') return false;
    i++;
    
    while (isdigit(telefon[i])) 
        i++;
        
    if (telefon[i] != '-') return false;
    i++;
    
    while (isdigit(telefon[i])) 
       i++;
       
    if(!isdigit(telefon[i-1])) return false;
    return true;
        
}
    
    

Student::Student(int indeks, std::string godinaStudija, std::string imePrezime, std::string adresa, std::string telefon) {
        
    if(std::to_string(indeks).length() < 5 || !jeLiValidanStudij(godinaStudija) || !jeLiValidanTelefon(telefon))
        throw std::domain_error("Neispravni parametri");
        
    this->imePrezime = ukloniRazmake(imePrezime);
    this->indeks = indeks;
    this->adresa = adresa;
    this->telefon = telefon;
    this->godinaStudija = godinaStudija;
    
}

std::string Student::DajImePrezime() {
    return imePrezime;
}

int Student::DajIndeks() {
    return indeks;
}

std::string Student::DajAdresu() {
    return adresa;
}

std::string Student::DajTelefon() {
    return telefon;
}

std::string Student::DajGodinuStudija() {
    if (godinaStudija == "1") return "1/B";
    else if (godinaStudija == "2") return "2/B";
    else if (godinaStudija == "3") return "3/B";
    else return godinaStudija;
}

void Student::Ispisi() {
    std::cout << "Broj indeksa: " << Student::DajIndeks() << std::endl;
    std::cout << "Godina studija: " << Student::DajGodinuStudija() << std::endl;
    std::cout << "Ime i prezime: " << Student::DajImePrezime() << std::endl;
    std::cout << "Adresa: " << Student::DajAdresu() << std::endl;
    std::cout << "Telefon: " << Student::DajTelefon() << std::endl;
}


#include "Student.h"

bool Student::jeLiValidanStudij(std::string godinaStudija) {
    const std::vector<std::string> &godineStudija{"1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D", "3/D"};
    return std::find(godineStudija.begin(), godineStudija.end(), godinaStudija) != godineStudija.end();
}

std::string Student::ukloniRazmake(std::string imePrezime) {
    std::string pocetak = ukloniPocetak(imePrezime);
    std::string novoImePrezime = ukloniKraj(pocetak);
    
    std::string rijec;
    std::string rezultat = "";
    int broj_razmaka = 0;
    
    for(int i=0; i<novoImePrezime.length(); i++) {
        rijec = izdvojiRijec(novoImePrezime, i);
        i=i+rijec.length();
        broj_razmaka = prebrojiRazmake(novoImePrezime,i);
        i = i + broj_razmaka;
        rezultat = rezultat + " " + rijec;
    }
    
    return rezultat.substr(1);
}

std::string Student::ukloniPocetak(std::string unos) {
    int i=0;
    
    if(unos[0] == ' ') {
        while (unos[i] == ' ') {
            i++;
        }
    }
    return unos.substr(i);
    
}

std::string Student::ukloniKraj(std::string unos) {
    int i=0;
    int kraj = unos.length();
    
    if(unos[kraj] == ' ') {
        while (unos[kraj] == ' ') {
            kraj--;
        }
    }
    return unos.substr(0,kraj);
}

std::string Student::izdvojiRijec(std::string unos, int i) {
    std::string rezultat = "";
    
    while (i<unos.length() && unos[i] != ' ') {
        rezultat = rezultat + unos[i];
        i++;
    }
    
    return rezultat;
}

int Student::prebrojiRazmake(std::string recenica, int i) {
    int brojac = 0;
    
    while(recenica[i] == ' ') {
        brojac++;
        i++;
    }
    
    if (brojac >= 1)
        return brojac - 1;
    
    return brojac;
    
}

bool Student::jeLiValidanTelefon(std::string telefon) {
    int i=0;
    
    while (isdigit(telefon[i])) 
        i++;
        
    if (telefon[i] != '/') return false;
    i++;
    
    while (isdigit(telefon[i])) 
        i++;
        
    if (telefon[i] != '-') return false;
    i++;
    
    while (isdigit(telefon[i])) 
       i++;
       
    if(!isdigit(telefon[i-1])) return false;
    return true;
        
}
    
    

Student::Student(int indeks, std::string godinaStudija, std::string imePrezime, std::string adresa, std::string telefon) {
        
    if(std::to_string(indeks).length() < 5 || !jeLiValidanStudij(godinaStudija) || !jeLiValidanTelefon(telefon))
        throw std::domain_error("Neispravni parametri");
        
    this->imePrezime = ukloniRazmake(imePrezime);
    this->indeks = indeks;
    this->adresa = adresa;
    this->telefon = telefon;
    this->godinaStudija = godinaStudija;
    
}

std::string Student::DajImePrezime() {
    return imePrezime;
}

int Student::DajIndeks() {
    return indeks;
}

std::string Student::DajAdresu() {
    return adresa;
}

std::string Student::DajTelefon() {
    return telefon;
}

std::string Student::DajGodinuStudija() {
    if (godinaStudija == "1") return "1/B";
    else if (godinaStudija == "2") return "2/B";
    else if (godinaStudija == "3") return "3/B";
    else return godinaStudija;
}

void Student::Ispisi() {
    std::cout << "Broj indeksa: " << Student::DajIndeks() << std::endl;
    std::cout << "Godina studija: " << Student::DajGodinuStudija() << std::endl;
    std::cout << "Ime i prezime: " << Student::DajImePrezime() << std::endl;
    std::cout << "Adresa: " << Student::DajAdresu() << std::endl;
    std::cout << "Telefon: " << Student::DajTelefon() << std::endl;
}


#ifndef STUDENT_H
#define STUDENT_H

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <locale>
#include <iostream>
#include <string>

class Student {
    
    private:
        int indeks;
        std::string godinaStudija;
        std::string imePrezime;
        std::string adresa;
        std::string telefon;
        
        bool jeLiValidanStudij(std::string godinaStudija);
        std::string ukloniRazmake(std::string);
        std::string ukloniPocetak(std::string unos);
        std::string ukloniKraj(std::string unos);
        std::string izdvojiRijec(std::string, int);
        int prebrojiRazmake(std::string, int);
        bool jeLiValidanTelefon(std::string);
        
    public:
        Student(int indeks, std::string godinaStudija, std::string imePrezime, std::string adresa, std::string telefon );
        std::string DajImePrezime();
        int DajIndeks();
        std::string DajAdresu();
        std::string DajTelefon();
        std::string DajGodinuStudija();
        void Ispisi();
};





int main() {
    try {
        Student s(12345, "1/B", "  meho   mehic  meh", "adresa", "1/1-1");
        std::cout << "Ime prezime: " s.DajImePrezime() << std::endl;
    }
    
    catch (std::domain_error e) {
        
    }
    return 0;
}