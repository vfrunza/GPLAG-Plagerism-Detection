/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

class Student
{
    int index;
    std::string god_studija;
    std::string ime_prezime;
    std::string adresa;
    std::string br_tel;
    public:
    Student (int index, std::string god_studija, std::string ime_prezime, std::string adresa, std::string br_tel) : index(index), god_studija(god_studija), ime_prezime(ime_prezime), adresa(adresa), br_tel(br_tel)
    {
        if (index < 10000 || index > 99999) throw std::domain_error ("Neispravni parametri");
        //if (god_studija != '1/B' || god_studija != '2/B' || god_studija != '3/B' || god_studija != '1/M' || god_studija != '2/M' || god_studija != '3/M' || god_studija != '1/D' || god_studija != '2/D' || god_studija != '3/D') throw std::domain_error ("Neispravni parametri");
        //if ( !(ime_prezime >= 'A' && ime_prezime <= 'Z') || !(ime_prezime >= 'a' && ime_prezime <= 'z')) throw std::domain_error ("Neispravni parametri");
        //if (br_tel < '0' || br_tel > '9' || br_tel != '-' || br_tel != '/') throw std::domain_error ("Neispravni parametri");
    }
    int DajIndeks() const {return index;}
    std::string DajGodinuStudija() const {return god_studija;}
    std::string DajImePrezime() const {return ime_prezime;}
    std::string DajAdesu() const {return adresa;}
    std::string DajTelefon() const {return br_tel;}
    void Ispisi() const
    {
        std::cout << "Broj indeksa: " << index << std::endl;
        std::cout << "Godina studija: " << DajGodinuStudija() << std::endl;
        std::cout << "Ime i prezime: " << DajImePrezime() << std::endl;
        std::cout << "Adresa: " << DajAdesu() << std::endl;
        std::cout << "Telefon: " << DajTelefon() << std::endl;
    }
    
};
class Laptop
{
    int ev_broj; 
    std::string naziv;
    std::string karakteristike; 
    Student *kod_koga_je;
    public:
    Laptop (int ev_broj, std::string naziv, std::string karakteristike) : ev_broj(ev_broj), naziv(naziv), karakteristike(karakteristike)
    {
        kod_koga_je = nullptr;
        if (ev_broj < 0) throw std::domain_error ("Neispravni parametri");
    }
    int DajEvidncijskiBroj() const {return ev_broj;}
    std::string DajNaziv() const {return naziv;}
    std::string DajKarakteristike() const {return karakteristike;}
    std::string Zaduzi (Student &s)
    {
        if(kod_koga_je != nullptr) throw std::domain_error ("Laptop vec zaduzen");
        //return s.ime_prezime;
    }
    std::string Razduzi ()
    {
        if(kod_koga_je != nullptr) delete[] kod_koga_je;
    }
    bool DaLiJeZaduzen()
    {
        if (kod_koga_je != nullptr) return true;
        else return false;
    }
    Student &DajKodKogaJe()
    {
        if (DaLiJeZaduzen() == false) throw std::domain_error ("Laptop nije zaduzen");
        else return *kod_koga_je;
    }
    Student *DajPokKodKogaJe()
    {
        if (DaLiJeZaduzen() == false) {kod_koga_je = nullptr; return kod_koga_je;}
        else return kod_koga_je;
    }
    void Ispisi()
    {
        std::cout << "Evidencijski broj: " << ev_broj << std::endl;
        std::cout << "Naziv: " << DajNaziv() << std::endl;
        std::cout << "Karakteristike: " << DajKarakteristike() << std::endl;
    }
};
class Administracija
{
    std::map<int, Student *> studenti; //kljucno polje index
    std::map<int, Laptop *> laptopi; //kljucno polje ev_br
    public:
    Student RegistrirajNovogStudenta(int index, std::string god_studija, std::string ime_prezime, std::string adresa, std::string br_tel)
    {
        
    }
};

int main ()
{
	return 0;
}
