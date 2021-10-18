#include <memory>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>

class Student {
    int broj_indexa;
    std::string godina_studija, ime_i_prezime, adresa, broj_telefona;
    public:
    Student(int broj_indexa, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::string broj_telefona) {
        std::vector<std::string> v={"1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "3/M", "1/D", "2/D", "3/D"};
        if (Petocifren(std::to_string(broj_indexa))==0) throw std::domain_error("Neispravni parametri");
        int znak=0;
        for (int i=0; i<v.size(); i++) {
            if (godina_studija==v.at(i)) {
                znak=0;
                break;
            }
        }
        if (znak==0) throw std::domain_error("Neispravni parametri");
        std::string temp;
        for (int i=0; i<ime_i_prezime.size(); i++) {
            if (ime_i_prezime.at(i)!=' ') temp.push_back(ime_i_prezime.at(i));
        }
        for (int i=0; i<temp.size(); i++) {
            if (i==temp.size()-1) break;
            if (temp.at(i)<='z' and temp.at(i)>='a' and temp.at(i+1)<='Z' and temp.at(i+1)>='A') temp.insert(temp.begin()+1, ' ');
        }
        znak=0;
        for (int i=0; i<broj_telefona.size(); i++) {
            if (broj_telefona.at(i)!='/' or broj_telefona.at(i)!='-' or !(broj_telefona.at(i)>='0' and broj_telefona.at(i)<='9')) throw std::domain_error("Neispravni parametri");
        }
        int brojac=0;
        for (int i=0; i<broj_telefona.size(); i++) {
            if (broj_telefona.at(i)=='/') brojac++;
        }
        if (brojac!=1) throw std::domain_error("Neispravni parametri");
        brojac=0;
        for (int i=0; i<broj_telefona.size(); i++) {
            if (broj_telefona.at(i)=='-') brojac++;
        }
        if (brojac!=1) throw std::domain_error("Neispravni parametri");
        int index_ravne, index_kose;
        if (index_ravne<index_kose or index_ravne-1==index_kose or index_ravne==broj_telefona.size()-1 or index_kose==0) throw std::domain_error("Neispravni parametri");
        ime_i_prezime=temp;
        Student::broj_indexa=broj_indexa;
        Student::godina_studija=godina_studija;
        Student::ime_i_prezime=ime_i_prezime;
        Student::adresa=adresa;
        Student::broj_telefona=broj_telefona;
    }
    int DajIndeks() const {
        return Student::broj_indexa;
    }
    std::string DajGodinuStudija() const {
        std::vector<std::string> v={"1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "3/M", "1/D", "2/D", "3/D"};
        if (Student::godina_studija==v.at(0)) return v.at(0+3);
        if (Student::godina_studija==v.at(1)) return v.at(1+3);
        if (Student::godina_studija==v.at(2)) return v.at(2+3);
        return Student::godina_studija;
    }
    std::string DajImePrezime() const {
        return Student::ime_i_prezime;
    }
    std::string DajAdresu() const {
        return Student::adresa;
    }
    std::string DajTelefon() const {
        return Student::broj_telefona;
    }
    void Ispisi() {
        std::cout << "Broj indeksa: " << DajIndeks() << std::endl;
        std::cout << "Godina studija: " << DajGodinuStudija() << std::endl;
        std::cout << "Ime i prezime: " << DajImePrezime() << std::endl;
        std::cout << "Adresa: " << DajAdresu() << std::endl;
        std::cout << "Telefon: " << DajTelefon() << std::endl;
    }
    bool Petocifren (std::string index) {
        if (index.length()==5) return true;
        return false;
    }
};

class Laptop {
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student* kod_koga_je;
    public:
    Laptop (int ev_broj, std::string naziv, std::string karakteristike) {
        if (ev_broj<0) throw std::domain_error("Neispravni parametri");
        Laptop::ev_broj=ev_broj;
        Laptop::naziv=naziv;
        Laptop::karakteristike=karakteristike;
    }
    int DajEvidencijskiBroj() const {
        return Laptop::ev_broj;
    }
    std::string DajNaziv () const {
        return Laptop::naziv;
    }
    std::string DajKarakteristike() const {
        return Laptop::karakteristike;
    }
    void Zaduzi(Student &student) {
        if (Laptop::kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
        *Laptop::kod_koga_je=student;
    }
    void Razduzi() {
        if (Laptop::kod_koga_je!=nullptr) Laptop::kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen() {
        if (Laptop::kod_koga_je!=nullptr) return true;
    }
    Student &DajKodKogaJe() {
        if (Laptop::kod_koga_je!=nullptr) throw std::domain_error("Laptop nije zaduzen");
        return *(Laptop::kod_koga_je);
    }
    Student *DajPokKodKogaJe() {
        return Laptop::kod_koga_je;
    }
    void Ispisi() {
        std::cout << "Evidencijski broj: " << DajEvidencijskiBroj() << std::endl;
        std::cout << "Naziv: " << DajNaziv() << std::endl;
        std::cout << "Karakteristike: " << DajKarakteristike() << std::endl;
    }
};

class Administracija {
    std::map<int, Student*> studenti;
    std::map<int, Laptop*> toplap;
    public:
    Administracija(std::map<int, Student*> studenti, std::map<int, Laptop*> toplap) {
        Administracija::studenti=studenti;
        Administracija::toplap=toplap;
    }
    void RegistrirajNovogStudenta(int broj_indexa, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::string broj_telefona) {
        auto it=studenti.begin();
        for (it=studenti.begin(); it!=studenti.end(); it++) {
            if (it->first==broj_indexa) throw std::domain_error("Student s tim indeksom vec postoji");
        }
        studenti.insert({broj_indexa, new Student(broj_indexa, godina_studija, ime_i_prezime, adresa, broj_telefona)});
    }
    void RegistrirajNoviLaptop (int ev_broj, std::string naziv, std::string karakteristike) {
        auto it=toplap.begin();
        for (it=toplap.begin(); it!=toplap.end(); it++) {
            if (it->first==ev_broj) throw std::domain_error("Laptop s tim evidencijskim brojem nije nadjen");
        }
        toplap.insert({ev_broj, new Laptop(ev_broj, naziv, karakteristike)});
    }
    Student &NadjiStudenta(int broj_indexa) {
        auto it=studenti.begin();
        for (it=studenti.begin(); it!=studenti.end(); it++) {
            if (it->first==broj_indexa) return *(it->second);
        }
        throw std::domain_error("Student nije nadjen");
    }
    Student NadjiStudenta(int broj_indexa) const {
        auto it=studenti.begin();
        for (it=studenti.begin(); it!=studenti.end(); it++) {
            if (it->first==broj_indexa) return *(it->second);
        }
        throw std::domain_error("Student nije nadjen");
    }
    Laptop &NadjiLaptop(int ev_broj) {
        auto it=toplap.begin();
        for (it=toplap.begin(); it!=toplap.end(); it++) {
            if (it->first==ev_broj) return *(it->second);
        }
        throw std::domain_error("Laptop nije nadjen");
    }
    Laptop NadjiLaptop(int ev_broj) const {
        auto it=toplap.begin();
        for (it=toplap.begin(); it!=toplap.end(); it++) {
            if (it->first==ev_broj) return *(it->second);
        }
        throw std::domain_error("Laptop nije nadjen");
    }
    void IzlistajStudente() {
        auto it=studenti.begin();
        for (it=studenti.begin(); it!=studenti.end(); it++) {
            it->second->Ispisi();
            std::cout << std::endl;
        }
    }
    void IzlistajLaptope() {
        auto it=toplap.begin();
        for (it=toplap.begin(); it!=toplap.end(); it++) {
            it->second->Ispisi();
            std::cout << std::endl;
            std::cout << "Zaduzio(la): ";
        }
    }
    void ZaduziLaptop (int broj_indexa, int ev_broj) {
        auto s=NadjiStudenta(broj_indexa);
        auto l=NadjiLaptop(ev_broj);
        if (l.DajPokKodKogaJe()!=nullptr) throw std::domain_error("Laptop vec zaduzen");
        auto it2=toplap.begin();
        for (it2=toplap.begin(); it2!=toplap.end(); it2++) {
            if (Jednaki(it2->second->DajKodKogaJe(), s)==true) throw std::domain_error("Student je vec zaduzio laptop"); 
        }
        l.Zaduzi(s);
    }
    int NadjiSlobodniLaptop () {
        auto it=toplap.begin();
        for (it=toplap.begin(); it!=toplap.end(); it++) {
            if (it->second->DajPokKodKogaJe()==nullptr) return it->first;
        }
        throw std::domain_error("Nema slobodnih laptopa");
    }
    void RazduziLaptop(int ev_broj) {
        auto it=toplap.begin();
        for (it=toplap.begin(); it!=toplap.end(); it++) {
            if (it->first==ev_broj and it->second->DajPokKodKogaJe()==nullptr) throw std::domain_error("Laptop nije zaduzen");
            else if (it->first==ev_broj) it->second->Razduzi();
        }
        int znak=0;
        for (it==toplap.begin(); it!=toplap.end(); it++) {
            if (it->first==ev_broj) znak=1;
        }
        if (znak==0) throw std::domain_error("Laptop nije nadjen");
    }
    void PrikaziZaduzenja() {
        for (auto it=studenti.begin(); it!=studenti.end(); it++) {
            
        }
    }
    bool Jednaki(Student &s1, Student &s2) {
        if (s1.DajImePrezime()==s2.DajImePrezime() and s1.DajAdresu()==s2.DajAdresu() and s1.DajIndeks()==s2.DajIndeks() and s1.DajTelefon()==s2.DajTelefon() and s1.DajGodinuStudija()==s2.DajGodinuStudija()) return true;
        return false;
    }
};

int main ()
{
    int k;
    std::cin >> k;
	return 0;
}
