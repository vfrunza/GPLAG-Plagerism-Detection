#include <iostream>
#include <string>
#include <stdexcept>

class Student
{
    int Broj_indexa;
    std::string Godina_studija, Ime_i_Prezime, Adresa, Broj_telefona;
    std::string IzbaciSuvisneRazmake(std::string s) {
        int br_razmaka(0);
        for(int i = 0; i < s.length(); i++) {
            int br_razmaka(0);
            if(s.at(i) == ' ') {
                while(s.at(i) == ' ') {
                    br_razmaka++;
                    if(br_razmaka > 1) {
                        s.erase(s.begin() + i);
                        i--;
                    }
                    i++;
                }
            }
        }
        return s;
    }
public:
    Student(int broj_indexa, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::string broj_telefona) {

        if(broj_indexa < 0 || broj_indexa > 99999) throw std::domain_error("Neispravni parametri");
        Broj_indexa = broj_indexa;

        const char *godine[12] {"1","2","3","1/B","2/B","3/B","1/M","2/M","3/M","1/D","2/D","3/D"};

        bool postoji(false);
        int i(0);
        while(1) {
            if(godina_studija == godine[i]) {
                postoji = true;
                break;
            }
            i++;
        }
        if(postoji == false) throw std::domain_error("Neispravni parametri");
        Godina_studija = godina_studija;

        Ime_i_Prezime = IzbaciSuvisneRazmake(ime_i_prezime);
        Adresa = IzbaciSuvisneRazmake(adresa);

        int brojacznaka1(0);
        int brojacznaka2(0);
        int brojacznaka3(0);
        int index1(0);
        int index2(0);
        for(int i = 0; i < broj_telefona.length(); i++) {
            if(broj_telefona.at(i) == '/') {
                index1 = i;
                brojacznaka1++;
            }
        }
        for(int i = 0; i < broj_telefona.length(); i++) {
            if(broj_telefona.at(i) == '-') {
                index2 = i;
                brojacznaka2++;
            }
        }
        for(int i = 0; i < broj_telefona.length(); i++) {
            if(broj_telefona.at(i) != '/' && broj_telefona.at(i) != '-' && (broj_telefona.at(i) < '0' || broj_telefona.at(i) > '9')) brojacznaka3++;
        }
        if(brojacznaka1 > 1 || brojacznaka1 == 0 || brojacznaka2 > 1 || brojacznaka2 == 0 || brojacznaka3 > 0 || index2 < index1)
            throw std::domain_error("Neispravni parametri");

        Broj_telefona = broj_telefona;
    }

    int DajIndeks() const {
        return Broj_indexa;
    }

    std::string DajGodinuStudija() const {
        if(Godina_studija == "1") {
            std::string pomocna_godina = "1/B";
            return pomocna_godina;
        } else if(Godina_studija == "2") {
            std::string pomocna_godina = "2/B";
            return pomocna_godina;
        } else if(Godina_studija == "3") {
            std::string pomocna_godina = "3/B";
            return pomocna_godina;
        }
        return Godina_studija;
    }
    std::string DajImePrezime() const {
        return Ime_i_Prezime;
    }
    std::string DajAdresu() const {
        return Adresa;
    }
    std::string DajTelefon() const {
        return Broj_telefona;
    }
    void Ispisi() const {
        std::cout << "Broj indeksa: " << DajIndeks() << std::endl;
        std::cout << "Godina studija: " << DajGodinuStudija() << std::endl;
        std::cout << "Adresa: " << DajAdresu() << std::endl;
        std::cout << "Telefon: " << DajTelefon() << std::endl;
    }

    friend bool operator == (const Student &s1, const Student &s2) {
        return s1.Broj_indexa == s2.Broj_indexa && s1.Godina_studija == s2.Godina_studija && s1.Ime_i_Prezime == s2.Ime_i_Prezime &&
               s1.Adresa == s2.Adresa && s1.Broj_telefona == s2.Broj_telefona;
    }
    Student &operator = (const Student &s1) {
        Ime_i_Prezime = s1.Ime_i_Prezime;
        Godina_studija = s1.Godina_studija;
        Broj_indexa = s1.Broj_indexa;
        Broj_telefona = s1.Broj_telefona;
        Adresa = s1.Adresa;
        return *this;
    }
};
class Laptop
{
    int ev_broj;
    std::string naziv, karakteristike;
    Student *kod_koga_je;
public:
    Laptop(int evidencijski_broj, std::string naziv_laptopa, std::string karakteristike_laptopa) {
        if(evidencijski_broj < 0) throw std::domain_error("Neispravni parametri");
        ev_broj = evidencijski_broj;
        naziv = naziv_laptopa;
        kod_koga_je = nullptr;
    }
    int DajEvidencijskiBroj() const {
        return ev_broj;
    }
    std::string DajNaziv() const {
        return naziv;
    }
    std::string DajKarakteristike() const {
        return karakteristike;
    }

    void Zaduzi(Student &student_koji_zaduzuje_laptop) {
        if(student_koji_zaduzuje_laptop == *kod_koga_je) throw std::domain_error("Laptop vec zaduzen");
        else *kod_koga_je = student_koji_zaduzuje_laptop;
    }

    void Razduzi() {
        if(kod_koga_je == nullptr) return;
        kod_koga_je = nullptr;
    }

    bool DaLiJeZaduzen() {
        if(kod_koga_je == nullptr) return false;
        return true;
    }
    Student &DajKodKogaJe() {
        if(kod_koga_je == nullptr) throw std::domain_error("Laptop nije zaduzen");
        return *kod_koga_je;
    }
    Student *DajPokKodKogaJe() {
        return kod_koga_je;
    }
    void Ispisi() const {
        std::cout << "Evidencijski broj: " << DajEvidencijskiBroj() << std::endl;
        std::cout << "Naziv: " << DajNaziv() << std::endl;
        std::cout << "Karakteristike: " << DajKarakteristike() << std::endl;
    }
};
class Administracija
{
    std::map<int br_indexa, Student *student> studenti;
    std::map<int evid_broj, Laptop *laptop> laptopi;
public:
    
    Administracija(const Administracija &original);
    Administracija(Administracija &&original);
};
int main ()
{
    return 0;
}
