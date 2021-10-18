#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <memory>

using std::vector;
using std::string;
using std::map;
using std::shared_ptr;
using std::make_shared;

class Student{
    int index;
    string godina, ime;
    string adresa, br_tel;
    
    bool CheckIndex(int idx){
        if(idx < 0) return false;
        
        short digits = 1;
        idx /= 10;
        
        while(idx){
            digits++;
            idx /= 10;
        }
        
        return digits == 5;
    }
    bool ProcessYear(string godina){
        string valid[11]{
            "1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D", "3/D"
        };
        
        for(int i = 0; i < 11; i++)
            if(godina == valid[i]){
                Student::godina = (i < 3)? valid[i+3] : valid[i];
                return true;
            }
        
        return false;
    }
    void ClearWhitespace(string &godina){
        string::iterator i1, i2;
        i1 = godina.begin();
        i2 = godina.begin();
        
        while(i1 != godina.end()){
            i2 = i1;
            while(i2 != godina.end() && *i2 == ' ') {
                i2++;
            }
            
            if(std::distance(i1, i2) >= 1){
                int dec = (i1 == godina.begin() && *i1 == ' ')? 0 : 1;
                godina.erase(i1, i2 - dec );
            }
            
            i1++;
        }
        if(godina.size() > 1 && godina.at(godina.size()-1) == ' ')
            godina.erase(godina.size()-1);
    }
    bool isDigit(char c){ return c >= '0' && c <= '9'; }
    bool ProcessTelephone(string tel){
        string::iterator it = tel.begin();
        bool firstCheck = true;
        
        while(it != tel.end()){
            
            if(!isDigit(*it)){
                if(firstCheck && *it != '/') return false;
                else if (!firstCheck && *it != '-') return false;
                else if(firstCheck) firstCheck = false;
            }
            
            it++;
        }
        
        return true;
    }
public:
    Student(int index, string godina, string ime, string adresa, string broj_telefona)
        : index(index), godina(godina), ime(ime), adresa(adresa), br_tel(broj_telefona)
    {
        if(!CheckIndex(index) || !ProcessYear(godina) || !ProcessTelephone(broj_telefona))
            throw std::domain_error("Neispravni parametri");
        ClearWhitespace(Student::ime);
        ClearWhitespace(Student::adresa);
    }
    
    int DajIndeks() const{ return index; }
    string DajGodinuStudija()const { return godina; }
    string DajImePrezime() const{ return ime; }
    string DajAdresu() const{ return adresa; }
    string DajTelefon() const{ return br_tel; }
    
    void Ispisi() const {
        std::cout << "Broj indeksa: " << index << std::endl;
        std::cout << "Godina studija: " << godina << std::endl;
        std::cout << "Ime i prezime: " << ime << std::endl;
        std::cout << "Adresa: " << adresa << std::endl;
        std::cout << "Telefon: " << br_tel << std::endl;
    }
};

class Laptop{
    int ev_broj;
    string naziv;
    string karakteristike;
    Student* kod_koga_je = nullptr; //Po default nije niciji
    
public:
    Laptop(int ev_broj, string naziv, string specs) : ev_broj(ev_broj), naziv(naziv), karakteristike(specs) {
        if(ev_broj < 0)
            throw std::domain_error("Neispravni parametri");
    }
    
    int DajEvidencijskiBroj() const { return ev_broj; }
    string DajNaziv() const { return naziv; }
    string DajKarakteristike() const { return karakteristike; }
    
    //Sta ako se posalje isti student, baca li se izuzetak?
    void Zaduzi(Student &student) {
        if(DaLiJeZaduzen())
            throw std::domain_error("Laptop vec zaduzen");
        
        kod_koga_je = &student;
    }
    void Razduzi() {
        kod_koga_je = nullptr;
    }
    bool DaLiJeZaduzen() const {
        return kod_koga_je != nullptr;
    }
    Student& DajKodKogaJe() const {
        if(!DaLiJeZaduzen())
            throw std::domain_error("Laptop nije zaduzen");
        
        return *kod_koga_je;
    }
    Student* DajPokKodKogaJe() const {
        return kod_koga_je;
    }
    void Ispisi() const {
        std::cout << "Evidencijski broj: " << ev_broj << std::endl;
        std::cout << "Naziv: " << naziv << std::endl;
        std::cout << "Karakteristike: " << karakteristike << std::endl;
    }
};

class Administracija{
    map<int, shared_ptr<Student>> studenti;
    map<int, shared_ptr<Laptop>> laptopi;
    
    void CheckIfStudentGotLaptop(Student *s){
        map<int, shared_ptr<Laptop>>::iterator lit;
        for(lit = laptopi.begin(); lit != laptopi.end(); lit++){
            if(lit->second->DajPokKodKogaJe() == s)
                throw std::domain_error("Student je vec zaduzio laptop");
        }
    }
public:
    Administracija() {}
    ~Administracija() {}
    
    //Copy const
    Administracija(const Administracija &a) : studenti(a.studenti), laptopi(a.laptopi) {
        map<int, shared_ptr<Student>>::iterator sit;
        for(sit = studenti.begin(); sit != studenti.end(); sit++){
            sit->second = make_shared<Student>(*(sit->second));
        }
        map<int, shared_ptr<Laptop>>::iterator lit;
        for(lit = laptopi.begin(); lit != laptopi.end(); lit++){
            lit->second = make_shared<Laptop>(*(lit->second));
        }
    }
    //Move const
    Administracija(Administracija &&a) : studenti(std::move(a.studenti)), laptopi(std::move(a.laptopi)) {
        a.studenti.clear();
        a.laptopi.clear();
    }
    //Copy assign
    Administracija& operator =(const Administracija &a) {
        if(&a == this) return *this;
        
        studenti = a.studenti;
        laptopi = a.laptopi;
        
        map<int, shared_ptr<Student>>::iterator sit;
        for(sit = studenti.begin(); sit != studenti.end(); sit++){
            sit->second = make_shared<Student>(*(sit->second));
        }
        map<int, shared_ptr<Laptop>>::iterator lit;
        for(lit = laptopi.begin(); lit != laptopi.end(); lit++){
            lit->second = make_shared<Laptop>(*(lit->second));
        }
        
        return *this;
    }
    //Move assign
    Administracija& operator =(Administracija &&a) {
        if(&a == this) return *this;
        
        studenti = std::move(a.studenti);
        laptopi = std::move(a.laptopi);
        
        a.studenti.clear();
        a.laptopi.clear();
        
        return *this;
    }
    
    void RegistrirajNovogStudenta(int index, string godina, string ime, string adresa, string broj_telefona) {
        if(studenti.count(index) > 0)
            throw std::domain_error("Student s tim indeksom vec postoji");
            
        studenti[index] = make_shared<Student>(index, godina, ime, adresa, broj_telefona);
    }
    void RegistrirajNoviLaptop(int ev_broj, string naziv, string specs) {
        if(laptopi.count(ev_broj) > 0)
            throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
            
        laptopi[ev_broj] = make_shared<Laptop>(ev_broj, naziv, specs);
    }
    
    Student& NadjiStudenta(int index) {
        map<int, shared_ptr<Student>>::iterator sit = studenti.find(index);
        
        if(sit == studenti.end())
            throw std::domain_error("Student nije nadjen");
        
        return *(sit->second);
    }
    Student NadjiStudenta(int index) const {
        map<int, shared_ptr<Student>>::const_iterator sit = studenti.find(index);
        
        if(sit == studenti.end())
            throw std::domain_error("Student nije nadjen");
        
        return *(sit->second);
    }
    Laptop& NadjiLaptop(int ev_broj) {
        map<int, shared_ptr<Laptop>>::iterator lit = laptopi.find(ev_broj);
        
        if(lit == laptopi.end())
            throw std::domain_error("Laptop nije nadjen");
        
        return *(lit->second);
    }
    Laptop NadjiLaptop(int ev_broj) const {
        map<int, shared_ptr<Laptop>>::const_iterator lit = laptopi.find(ev_broj);
        
        if(lit == laptopi.end())
            throw std::domain_error("Laptop nije nadjen");
        
        return *(lit->second);
    }
    
    void IzlistajStudente() const {
        map<int, shared_ptr<Student>>::const_iterator sit;
        for(sit = studenti.begin(); sit != studenti.end(); sit++){
            sit->second->Ispisi();
            std::cout << std::endl;
        }
    }
    void IzlistajLaptope() const {
        map<int, shared_ptr<Laptop>>::const_iterator lit;
        for(lit = laptopi.begin(); lit != laptopi.end(); lit++){
            lit->second->Ispisi();
            if(lit->second->DaLiJeZaduzen()){
                std::cout << "Zaduzio(la): " << lit->second->DajPokKodKogaJe()->DajImePrezime() 
                      << " (" << lit->second->DajPokKodKogaJe()->DajIndeks() << ")" << std::endl;
            }
            std::cout << std::endl;
        }
    }
    
    void ZaduziLaptop(int index, int ev_broj) {
        Student* s = &NadjiStudenta(index);
        Laptop* l = &NadjiLaptop(ev_broj);
        
        CheckIfStudentGotLaptop(s);
        l->Zaduzi(*s);
    }
    
    int NadjiSlobodniLaptop() const {
        map<int, shared_ptr<Laptop>>::const_iterator lit = std::find_if(laptopi.begin(), laptopi.end(), [](const std::pair<int, shared_ptr<Laptop>> a){
            return (a.second)->DajPokKodKogaJe() == nullptr;
        });
        
        if(lit == laptopi.end())
            throw std::domain_error("Nema slobodnih laptopa");
        
        return lit->first;
    }
    void RazduziLaptop(int ev_broj) {
        Laptop* l = &NadjiLaptop(ev_broj);
        
        if(!(l->DaLiJeZaduzen()))
            throw std::domain_error("Laptop nije zaduzen");
        
        l->Razduzi();
    }
    
    void PrikaziZaduzenja() const {
        map<int, shared_ptr<Laptop>>::const_iterator lit;
        bool nemaZaduzenja = true;
        
        for(lit = laptopi.begin(); lit != laptopi.end(); lit++){
            if(lit->second->DaLiJeZaduzen()){
                nemaZaduzenja = false;
                std::cout << "Student " << lit->second->DajPokKodKogaJe()->DajImePrezime() <<
                        " (" << lit->second->DajPokKodKogaJe()->DajIndeks() << ")" <<
                        " zaduzio/la laptop broj " << lit->first << std::endl;
            }
        }
        
        if(nemaZaduzenja)
            std::cout << "Nema zaduzenja" << std::endl;
    }
};

void UserInterface(Administracija &admin){
    while(true){
        std::cout << 
            "1 - Registriraj novog studenta" << std::endl <<
            "2 - Registriraj novi laptop" << std::endl <<
            "3 - Izlistaj studente" << std::endl <<
            "4 - Izlistaj laptope" << std::endl <<
            "5 - Nadji slobodni laptop" << std::endl <<
            "6 - Zaduzi laptop" << std::endl <<
            "7 - Razduzi laptop" << std::endl <<
            "8 - Prikazi zaduzenja" << std::endl <<
            "9 - Kraj" << std::endl;
        try{
            int opt;
            std::cin >> opt;
            
            if(opt < 0 || opt > 9)
                throw std::domain_error("Pogresna komanda!");
            
            int index, ev_broj;
            string godina, ime, adresa, tel, naziv, opis;
            
            if(opt == 1){
                std::cout << "Unesite podatke o studentu: ";
                std::cin >> index >> godina >> ime >> adresa >> tel;
                admin.RegistrirajNovogStudenta(index, godina, ime, adresa, tel);
            }else if(opt == 2){
                std::cout << "Unesite podatke o laptopu: ";
                std::cin >> ev_broj >> naziv >> opis;
                admin.RegistrirajNoviLaptop(ev_broj, naziv, opis);
            }else if(opt == 3){
                admin.IzlistajStudente();
            }else if(opt == 4){
                admin.IzlistajLaptope();
            }else if(opt == 5){
                std::cout << "Evidencijski broj slobodnog laptopa: " << admin.NadjiSlobodniLaptop() << std::endl;
            }else if(opt == 6){
                std::cout << "Indeks studenta i evidencijski broj laptopa: ";
                std::cin >> index >> ev_broj;
                admin.ZaduziLaptop(index, ev_broj);
            }else if(opt == 7){
                std::cout << "Evidencijski broj laptopa: ";
                std::cin >> ev_broj;
                admin.RazduziLaptop(ev_broj);
            }else if(opt == 8){
                admin.PrikaziZaduzenja();
            }else if(opt == 9){
                break;
            }
        }catch(std::exception &err){
            std::cout << err.what() << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    
    Administracija admin;
    UserInterface(admin);
    
    return 0;
}