/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
class Student
{
    int broj_indeksa;
    std::string godina_studija, ime_i_prezime, adresa, br_tel;
    static bool provjeri_indeks(int br) {
        if(br<=9999 || br>99999) return false;
        return true;
    }
    static bool provjeri_godinu(std::string s) {

    }
    std::string PrepraviIme(std::string s);
    std::string PrepraviAdresu(std::string s);
    static bool provjeri_telefon(std::string s);
public:
    Student(int br_ind, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::br_tel) {
        if (provjeri_indeks(br_ind)==false)throw std::domain_error("Neispravni parametri");
        if (provjeri_godinu(godina_studija)==false)throw std::domain_error("Neispravni parametri");
        if (provjeri_telefon(br_tel)==false)throw std::domain_error("Neispravni parametri");
        broj_indeksa=br_ind;
        Studend::godina_studija=godina_studija;
        Student::ime_i_prezime=PrepraviIme(ime_i_prezime);
        Student::adresa=PrepraviAdresu(adresa);
        Student::br_tel=br_tel;
    }
    int DajIndeks() const {
        return broj_indeksa;
    }
    std::string DajGodinuStudija() const {
        return godina_studija;
    }
    std::string DajImePrezime() const {
        return ime_i_prezime;
    }
    std::string DajAdresu() const {
        return adresa;
    }
    std::string DajTelefon() const {
        return br_tel;
    }
    void Ispisi();

};

class Laptop
{
    int ev_broj;
    std::string naziv, karakteristike;
    Student *kod_koga_je;
public:
    Laptop(int ev_broj, std::string naziv, std::string karakteristike) : kod_koga_je(nullptr) {
        if (ev_broj<0) throw std::domain_error("Neispravni parametri");
        Student::ev_broj=ev_broj;
        Student::naziv=naziv;
        Student::karakteristike=karakteristike;
    }
    int DajEvidencijskiBroj() const { return ev_broj; }
    std::string DajNaziv() const { return naziv; }
    std::string DajKarakteristike() const { return karakteristike; }
    bool DaLiJeZaduzen(){return (kod_koga_je!=nullptr);}
    void Zaduzi(Student &student){
        if (DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je=&student;
    }
    void Razduzi(){ kod_koga_je=nullptr; }
    Student *DajPokKodKogaJe(){
        return kod_koga_je;
    }
    Student &DajKodKogaJe(){
        if (!DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen");
        return *kod_koga_je; 
    }
    void Ispisi();
};

class Administracija{
    std::map<int, Student*>studenti;
    std::map<int, Laptop*>laptopi;
public:
Administracija() = default;
~ Administracija(){
    for (auto it=studenti.begin(); it!= studenti.end(); it++) {
        delete it->second;
    }
   for (auto it=laptopi.begin(); it!= laptopi.end(); it++) {
        delete it->second;
    }
}
Administracija(const Administracija &a){
    for (auto it=a.studenti.begin(); it!= a.studenti.end(); it++) {
        studenti[it->first]=new Student (*[it->second]);
    }
    for (auto it=a.laptopi.begin(); it!= a.laptopi.end(); it++) {
        laptopi[it->first]=new Laptop (*[it->second]);
    }
}
Administracija &operator =(const Administracija &a){
    if (&a==this) return *this;
    for (auto it=studenti.begin(); it!= studenti.end(); it++) {
        delete it->second;
    }
   for (auto it=laptopi.begin(); it!= laptopi.end(); it++) {
        delete it->second;
    }
    for (auto it=a.studenti.begin(); it!= a.studenti.end(); it++) {
        studenti[it->first]=new Student (*[it->second]);
    }
    for (auto it=a.laptopi.begin(); it!= a.laptopi.end(); it++) {
        laptopi[it->first]=new Laptop (*[it->second]);
    }
    return *this;
}
Administracija(const Administracija &&a){
    studenti=a.studenti;
    laptopi=a.laptopi;
    for (auto it=a.studenti.begin(); it!= a.studenti.end(); it++) {
        it->second=nullptr;
    }
    for (auto it=a.laptopi.begin(); it!= a.laptopi.end(); it++) {
        it->second=nullptr;
    }
}
Administracija &operator =(const Administracija &&a){
    if (&a==this) return *this;
    for (auto it=studenti.begin(); it!= studenti.end(); it++) {
        delete it->second;
    }
   for (auto it=laptopi.begin(); it!= laptopi.end(); it++) {
        delete it->second;
    }
    studenti=a.studenti;
    laptopi=a.laptopi;
    for (auto it=a.studenti.begin(); it!= a.studenti.end(); it++) {
        it->second=nullptr;
    }
    for (auto it=a.laptopi.begin(); it!= a.laptopi.end(); it++) {
        it->second=nullptr;
    }
    return *this;
}
void RegistrirajNovogStudenta(int br_ind, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::br_tel){
    for (auto it=a.studenti.begin(); it!= a.studenti.end(); it++) {
        if (it->first==br_ind) throw std::domain_error("Student s tim indeksom vec postoji");
    }
    studenti[br_ind]=new Student(br_ind, godina_studija,ime_i_prezime, adresa, br_tel);
}
void RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike){
    for (auto it=a.laptopi.begin(); it!= a.laptopi.end(); it++) {
        if (it->first==ev_broj) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    }
    laptopi[ev_broj]=new Laptop(ev_broj, naziv, karakteristike);
}
Student &NadjiStudenta(int br_ind){
    if (studenti.find(br_ind))==studenti.end()) throw std::domain_error("Student nije nadjen");
    return *studenti[br_ind];
}
Student &NadjiLaptop(int ev_broj){
    if (laptopi.find(ev_broj))==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    return *laptopi[ev_broj];
}
void IzlistajStudente(){
    for (auto it=studenti.begin(); it!= studenti.end(); it++) {
        it->Ispisi();
        std::cout<<std::endl;
    }
}
void IzlistajLaptope(){
    for (auto it=laptopi.begin(); it!= laptopi.end(); it++) {
        it->Ispisi();
        std::cout<<std::endl;
    }
}
ZaduziLaptop(int broj_indeksa, int ev_broj){
    if (studenti.find(br_ind))==studenti.end()) throw std::domain_error("Student nije nadjen");
    if (laptopi.find(ev_broj))==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    if(laptopi[ev_broj]->second->DaLiJeZaduzen()) throw std::domain_error("Laptop je zaduzen");
    for (auto it=a.laptopi.begin(); it!= a.laptopi.end(); it++) {
        if (it->second->DajPokKodKogaJe()==studenti[broj_indeksa]->second) throw std::domain_error("Student je vec zaduzio laptop");
    }
}
int NadjiSlobodniLaptop(){
    for (auto it=laptopi.begin(); it!= laptopi.end(); it++) {
        if(!DaLiJeZaduzen())
    }
    return ;
}


};

int main ()
{
    return 0;
}
