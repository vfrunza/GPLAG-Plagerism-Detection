/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <stdexcept>

class Student {
    int br_indeksa;
    std::string g_studija, ime_prezime, adresa, br_telefona;
    bool TestG_Studija(std::string g_studija) {
        if(!(g_studija == '1' || g_studija == '2' || g_studija == '3' || g_studija == '1/B' || g_studija == '2/B' || g_studija == '3/B' || g_studija == '1/M' || g_studija == '2/M' || g_studija == '1/D' || g_studija == '2/D' || g_studija == '3/D')) throw std::domain_error("Neispravni parametri");
    }
    std::string &BezRazmaka (const std::string &ime) {
       std::string pomocni;
       for(int i(0); i < ime.length(); i++) {
            while(s.at(i) == ' ') i++;
            if(s.at(i) != ' ') 
                    while(s.at(i) != ' ') pomocni += s.at(i);
                if(s.at(i) != s.length()-1) {
                   pomocni += ' ';
                   while (s.at(i) == ' ') i++;
                   if(s.at(i) != ' ')
                       while(s.at(i) != ' ') pomocni += s.at(i);
            }
        }
        return pomocni;
    }
    bool TestBr_Telefona (std::string br_telefona) {
        bool a = false, b = false;
        for(int i(0); i < br_telefona.length(); i++) {
            if(br_telefona.at(i) == '/') a = true;
            if(a == true && br_telefona.at(i) == '-') b = true;
        }if(a == false || b == false) throw std::domain_error("Neispravni parametri");
        return true;
    }
    public:
        Student(int br_indeksa, std::string g_studija, std::string ime_prezime, std::string adresa, std::string br_telefona) : adresa(adresa) {
            if(br_indeksa < 10000 || br_indeksa > 99999) throw std::domain_error("Neispravni parametri");
            Student::br_indeksa(br_indeksa);
            TestG_Studija(g_studija);     Student::g_studija(g_studija);
            Student::ime_prezime(BezRazmaka(ime_prezime));
            TestBr_Telefona(br_telefona);   Student::br_telefona(br_telefona);
        }
        int DajIndeks() const { return br_indeksa; }
        std::string DajGodinuStudija() const;
        std::string DajImePrezime () const { return ime_prezime; }
        std::string DajAdresu () const { return adresa; }
        std::string DajTelefon () const { return br_telefona; }
        void Ispisi () const;
}; 

int Student::DajGodinuStudija() const {
    if(g_studija == '1') { std::string g{'1/B'}; return g; }
    else if(g_studija == '2') { std::string g{'2/B'}; return g; }
    else if(g_studija == '3') { std::string g{'3/B'}; return g; }
    return g_studija;
}

void Student::Ispisi() const {
    std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl<<"Godina studija: "<<DajGodinuStudija()<<std::endl<<"Ime i prezime: "<<DajImePrezime()<<std::endl<<"Adresa: "<<DajAdresu()<<std::endl<<"Telefon: "<<DajTelefon()<<std::endl;
}

class Laptop {
    int ev_broj;
    std::string naziv, karakteristike;
    Student *kod_koga_je;
    public:
        Laptop(int ev_broj, std::string naziv, std::napomena) : naziv(naziv), karakteristike(napomena), kod_koga_je(nullptr) {
            if(ev_broj < 0) throw std::domain_error("Neispravni parametri");
        }
        int DajEvidencijskiBroj() const { return ev_broj; }
        std::string DajNaziv() const { return naziv; }
        std::string DajKarakteristike() const { return karakteristike; }
        void Zaduzi (Student &student);
        void Razduzi ();
        bool DaLiJeZaduzen();
        Student &DajKodKogaJe();
        Student *DajPokKodKogaJe();
        void Ispisi() const;
};

void Laptop::Zaduzi(Student &student) {
    if(student )
}

void Laptop::Ispisi() const {
    std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<std::endl<<"Naziv: "<<DajNaziv()<<std::endl<<"Karakteristike: "<<DajKarakteristike()<<std::endl;    
}

int main ()
{
	return 0;
}
