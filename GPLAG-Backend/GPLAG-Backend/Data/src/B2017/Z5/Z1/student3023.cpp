/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>
#include <cmath>
#include <iomanip>

int velicina(int br) {
    int brojac=0;
    while(br!=0){
        br/=10;
        brojac++;
    }
    return brojac;
}

std::string prepravka(std::string s) {
    std::string temp;
    int j=0;
    for(int i=0; i<s.length(); i++) {
        while(s.at(i)==' ') i++;
        while(s.at(i)!=' ') temp.at(j)=s.at(i); j++; i++;
        if(s.at(i+1)!=s.length()) {
            j++;
            temp.at(j)=' ';
        }
    }
    return temp;
}

bool testiranje(std::string s) {
    if(s.empty()) return false;
    int i=0;
    switch(s.at(i)) {
        case 1:
            i++;
            switch(s.at(i)) {
                case '\0': return true;
                case '/':
                    i++;
                    switch(s.at(i)) {
                        case 'B':
                            i++;
                            if(s.at(i)!='\0') return false;
                            else return true;
                        case 'M':
                            i++;
                            if(s.at(i)!='\0') return false;
                            else return true;
                        case 'D':
                            i++;
                            if(s.at(i)!='\0') return false;
                            else return true;
                        default:
                            return false;
                    }
                default: return false;    
            }
        case 2:
            i++;
            switch(s.at(i)) {
                case '\0': return true;
                case '/':
                    i++;
                    switch(s.at(i)) {
                        case 'B':
                            i++;
                            if(s.at(i)!='\0') return false;
                            else return true;
                        case 'M':
                            i++;
                            if(s.at(i)!='\0') return false;
                            else return true;
                        case 'D':
                            i++;
                            if(s.at(i)!='\0') return false;
                            else return true;
                        case default:
                            return false;
                    }
                default: return false;    
            }
        case 3:
            i++;
            switch(s.at(i)) {
                case '\0': return true;
                case '/':
                    i++;
                    switch(s.at(i)) {
                        case 'B':
                            i++;
                            if(s.at(i)!='\0') return false;
                            else return true;
                        case 'M':
                            i++;
                            if(s.at(i)!='\0') return false;
                            else return true;
                        case 'D':
                            i++;
                            if(s.at(i)!='\0') return false;
                            else return true;
                        default:
                            return false;
                    }
                default: return false;    
            }
        default: return false;    
    }
    return false;
}

bool telefon(std::string broj) {
    int i=0;
    int brojac=0;
back:    
    while(broj.at(i)>='0' && broj.at(i)<='9' && broj.at(i)!='\0') i++;
    brojac++;
    if(brojac==1) {
        switch(broj.at(i)){
            case '/':
                i++;
                goto back;
            default: return false;    
        }
    } else {
        if(brojac==2) {
            switch(broj.at(i)) {
                case '-':
                    i++;
                    goto back;
                default: return false;    
            }
        }
    }
    return true;
}

class Student {
int index_pr;
std::string godina_studija_pr, ime_i_prezime_pr, adresa_pr, broj_telefona_pr;
public:
Student(int broj_indeksa, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::string broj_telefona) {
    if(velicina(broj_indeksa)!=5) throw std::domain_error("Neispravni parametri - indeks");
    if(testiranje(godina_studija)==false) throw std::domain_error("Neispravni parametri - godina");
    if(telefon(broj_telefona)==false) throw std::domain_error("Neispravni parametri - telefon");
    this->broj_telefona_pr=broj_telefona;
    this->index_pr=broj_indeksa;
    this->ime_i_prezime_pr=prepravka(ime_i_prezime);
    this->adresa_pr=prepravka(adresa);
    this->godina_studija_pr=godina_studija;
    if(godina_studija.length()==1) this->godina_studija_pr+="/B";
}
int DajIndeks() const {return index_pr;}
std::string DajGodinuStudija() const {return godina_studija_pr;}
std::string DajImePrezime() const {return ime_i_prezime_pr;}
std::string DajAdresu() const {return adresa_pr;}
std::string DajTelefon() const {return broj_telefona_pr;}
void Ispisi() const {
    std::cout << "Broj indeksa: " << index_pr << std::endl;
    std::cout << "Godina studija: " << godina_studija_pr << std::endl;
    std::cout << "Ime i prezime: " << ime_i_prezime_pr << std::endl;
    std::cout << "Adresa: " << adresa_pr << std::endl;
    std::cout << "Telefon: " << broj_telefona_pr << std::endl;
}
};

class Laptop {
int ev_broj;
std::string naziv;
std::string karakteristike;
Student* kod_koga_je;
public:
Laptop(int ev_broj, std::string naziv, std::string karakteristike) : kod_koga_je(nullptr) {
    if(ev_broj<=0) throw std::domain_error("Neispravni parametri");
    this->naziv=prepravka(naziv);
    this->karakteristike=karakteristike;
}
int DajEvidencijskiBroj() const {return ev_broj;}
std::string DajNaziv() const {return naziv;}
std::string DajKarakteristike() const {return karakteristike;}
void Zaduzi(Student &student) {}
void Razduzi() {
    if(kod_koga_je==nullptr) return;
}
bool DaLiJeZaduzen() {
    if(kod_koga_je==nullptr) return false;
    else return true;
}
void DajKodKogaJe() {
    if(kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen");
}
void DajPokKodKogaJe() {
    if(kod_koga_je==nullptr) return;
}
void Ispisi() {
    std::cout << "Evidencijski broj: " << ev_broj << std::endl;
    std::cout << "Naziv: " << naziv << std::endl;
    std::cout << "Karakteristike: " << karakteristike << std::endl;
}
};

class Administracija {
public:
};

int main () {
    std::vector<std::shared_ptr<Student>>student;
    try {
        student[0]=std::make_shared<Student>(17555, "1", "Huso Husic", "Grbavica", "033/645-445");
    }catch(std::domain_error jedan) {
        std::cout << jedan.what() << std::endl;
    }
    for(int i = 0; i < student.size(); i++) student[i]->Ispisi();
	return 0;
}
