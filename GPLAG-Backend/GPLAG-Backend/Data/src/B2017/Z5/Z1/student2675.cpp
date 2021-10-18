/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>   
#include <stdexcept>
#include <map>
#include <algorithm>

class Student
{
    int br_indeksa;
    std::string godina_studija, ime_prezime, adresa, telefon;
    static std::string ZanemariRazmake(std::string);
    static bool IspravanBroj(std::string);
    static bool IspravnaGodina(std::string);
    static bool IspravanIndeks(int);
    void PostaviGodinu(std::string);
public:
    Student(int br_indeksa, std::string godina_studija, std::string ime_prezime,
            std::string adresa, std::string telefon);
    int DajIndeks() const {
        return br_indeksa;
    }
    std::string DajGodinuStudija() const {
        return godina_studija;
    }
    std::string DajImePrezime() const {
        return ime_prezime;
    }
    std::string DajAdresu() const {
        return adresa;
    }
    std::string DajTelefon() const {
        return telefon;
    }
    void Ispisi() const {
        std::cout << "Broj indeksa: " << DajIndeks() << std::endl;
        std::cout << "Godina studija: " << DajGodinuStudija() << std::endl;
        std::cout << "Ime i prezime: "<< DajImePrezime() << std::endl;
        std::cout << "Adresa: " << DajAdresu() << std::endl;
        std::cout << "Telefon: " << DajTelefon() << std::endl;
    }
};

class Laptop
{
    int ev_broj;
    std::string naziv, karakteristike;
    Student* kod_koga_je = nullptr;
public:
    Laptop(int ev_broj, std::string naziv, std::string karakteristike);
    int DajEvidencijskiBroj() const {
        return ev_broj;
    }
    std::string DajNaziv() const {
        return naziv;
    }
    std::string DajKarakteristike() const {
        return karakteristike;
    }
    void Zaduzi(Student &student);
    void Razduzi();
    bool DaLiJeZaduzen() const {
        return kod_koga_je != nullptr;
    }
    Student& DajKodKogaJe() const {
        if(!kod_koga_je) throw std::domain_error ("Laptop nije zaduzen");
        return *kod_koga_je;
    }
    Student* DajPokKodKogaJe() const {
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
    std::map<int, Student*> studenti;
    std::map<int, Laptop*> laptopi;
public:
    Administracija() {}
    Administracija(const Administracija &a);
    Administracija(Administracija &&a);
    Administracija& operator = (const Administracija &a);
    Administracija& operator = (Administracija &&a);
    ~Administracija();
    void RegistrirajNovogStudenta(int br_indeksa, std::string godina_studija, std::string ime_prezime,
                                  std::string adresa, std::string telefon);
    void RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike);
    Student& NadjiStudenta(int br_indeksa);
    Student NadjiStudenta(int br_indeksa) const;
    Laptop& NadjiLaptop(int ev_broj);
    Laptop NadjiLaptop(int ev_broj) const;
    void IzlistajStudente() const;
    void IzlistajLaptope() const;
    void ZaduziLaptop(int br_indeksa, int ev_broj);
    int NadjiSlobodniLaptop();
    void RazduziLaptop(int ev_broj);
    void PrikaziZaduzenja();

};

int main ()
{
     Administracija etf ;

    etf.RegistrirajNoviLaptop(123, "Dell", "CPU 3.0 GHz, 4 GB RAM");
    etf.RegistrirajNoviLaptop(331, "ASUS", "CPU 3.5 GHz, 2 GB RAM");
    etf.RegistrirajNoviLaptop(122, "Dell 2", "CPU 3.2 GHz, 6 GB RAM");
    etf.RegistrirajNovogStudenta(14212, "1", "Benjamin", "Francuska revolucija 23", "12/34-56");
    etf.RegistrirajNovogStudenta(17528, "2","Ivan", "Trg vjecnih studenata 12", "048/597-585");
    
    etf.ZaduziLaptop(14212, 123);
    //etf.ZaduziLaptop(17528, 331);
    
    etf.PrikaziZaduzenja();
    return 0;
}

//Implementacija interfejsa klase Student
Student::Student(int br_indeksa, std::string godina_studija, std::string ime_prezime,
                 std::string adresa, std::string telefon)
{
    if(!Student::IspravanIndeks(br_indeksa))
        throw std::domain_error ("Neispravni parametri");
    Student::br_indeksa = br_indeksa;

    if(!Student::IspravnaGodina(godina_studija)) 
        throw std::domain_error ("Neispravni parametri");

    PostaviGodinu(godina_studija);
    Student::ime_prezime = Student::ZanemariRazmake(ime_prezime);
    Student::adresa = Student::ZanemariRazmake(adresa);

    if(!Student::IspravanBroj(telefon))
        throw std::domain_error ("Neispravni parametri");
    Student::telefon = telefon;

}

std::string Student::ZanemariRazmake(std::string s)
{
    std::string rezultat("");
    for(auto it = s.begin(); it != s.end(); it++) {
        if(*it == ' ') continue;
        while (*it != ' ' && it != s.end()) {
            rezultat += *it;
            it++;
        }
        if(it != --s.end()) rezultat+= " ";
        if(it == s.end()) break;
    }
    int pos(rezultat.size());
    for(auto it = rezultat.end(); it != rezultat.begin(); it--){
        pos--;
        if(*it != ' ') {
            rezultat = rezultat.substr(0, pos);
            break;
        }
    }
    return rezultat;
}
bool Student::IspravanBroj(std::string telefon)
{
    auto it(telefon.begin());
    int crta(0), crtica(0);
    while (it != telefon.end()) {
        if(*it == '/') crta++;
        if(crtica > 0 && crta == 0) return false;
        if(*it == '-') crtica++;
        if(!((*it >= '0' && *it <='9') || *it == '-' || *it == '/')) return false;
        it++;
    }
    if(!(crta==1 && crtica==1)) return false;
    return true;
}
bool Student::IspravnaGodina(std::string godina_studija)
{
    if(godina_studija.size() == 1 && *(godina_studija.begin())>'0' &&
            *(godina_studija.begin())<'4') return true;
    if(godina_studija.size() == 3 && godina_studija[0] > '0' && godina_studija[0] < '4' &&
            godina_studija[1] == '/' && (godina_studija[2] == 'B' ||
                                         godina_studija[2] == 'M' || godina_studija[2] == 'D')) return true;
    return false;
}
bool Student::IspravanIndeks(int br_indeksa)
{
    int br_cifara(0);
    while (br_indeksa != 0) {
        br_indeksa /=10;
        br_cifara++;
    }
    return br_cifara == 5;
}
void Student::PostaviGodinu(std::string godina_studija)
{
    if(godina_studija.size() == 1 && *(godina_studija.begin())>'0' &&
            *(godina_studija.begin())<'4')
        Student::godina_studija = godina_studija + "/B";
    else Student::godina_studija = godina_studija;
}

//Implementacija interfejsa klase Laptop
Laptop::Laptop(int ev_broj, std::string naziv, std::string karakteristike)
{
    if(ev_broj <= 0 ) throw std::domain_error ("Neispravni parametri");
    Laptop:: ev_broj = ev_broj;
    Laptop::naziv = naziv;
    Laptop::karakteristike = karakteristike;
}
void Laptop::Zaduzi(Student &student)
{
    if(kod_koga_je != nullptr) throw std::domain_error ("Laptop vec zaduzen");
    kod_koga_je = &student;
}
void Laptop::Razduzi()
{
    kod_koga_je = nullptr;
}

//Implementacija interfejsa klase Administracija
Administracija::Administracija(const Administracija &a)
{
    for(auto it = a.studenti.begin(); it != a.studenti.end(); it++) {
        studenti[it->first] = new Student(*(it->second));
        //studenti.insert(std::pair<int, Student*>(it->first, new Student(*(it->second))));
    }
    for(auto it = a.laptopi.begin(); it != a.laptopi.end(); it++) {
        laptopi[it->first] = new Laptop(*(it->second));
        laptopi.insert(std::pair<int, Laptop*>(it->first, new Laptop(*(it->second))));
    }
}
Administracija::Administracija(Administracija &&a)
{
    studenti = a.studenti;
    laptopi = a.laptopi;
    for(auto it = a.studenti.begin(); it != a.studenti.end(); it++)
        it->second = nullptr;
    for(auto it = a.laptopi.begin(); it != a.laptopi.end(); it++)
        it->second = nullptr;
}
Administracija& Administracija::operator = (const Administracija &a)
{
    if(this == &a) return *this;
    for(auto it = studenti.begin(); it != studenti.end(); it++) {
        delete it->second;
        it->second = nullptr;
    }
    studenti.clear();
    for(auto it = laptopi.begin(); it != laptopi.end(); it++) {
        delete it->second;
        it->second = nullptr;
    }
    laptopi.clear();
    for(auto it = a.studenti.begin(); it != a.studenti.end(); it++) {
        studenti[it->first] = new Student(*(it->second));
        //studenti.insert(std::pair<int, Student*>(it->first, new Student(*(it->second))));
    }
    for(auto it = a.laptopi.begin(); it != a.laptopi.end(); it++) {
        laptopi[it->first] = new Laptop(*(it->second));
        laptopi.insert(std::pair<int, Laptop*>(it->first, new Laptop(*(it->second))));
    }
    return *this;
}
Administracija& Administracija::operator = (Administracija &&a)
{
    for(auto it = studenti.begin(); it != studenti.end(); it++) {
        delete it->second;
        it->second = nullptr;
    }
    studenti.clear();
    for(auto it = laptopi.begin(); it != laptopi.end(); it++) {
        delete it->second;
        it->second = nullptr;
    }
    laptopi.clear();
    studenti = a.studenti;
    laptopi = a.laptopi;
    for(auto it = a.studenti.begin(); it != a.studenti.end(); it++)
        it->second = nullptr;
    for(auto it = a.laptopi.begin(); it != a.laptopi.end(); it++)
        it->second = nullptr;
    return *this;
}
Administracija::~Administracija()
{
    for(auto it = studenti.begin(); it != studenti.end(); it++) {
        delete it->second;
        it->second = nullptr;
    }
    for(auto it = laptopi.begin(); it != laptopi.end(); it++) {
        delete it->second;
        it->second = nullptr;
    }
}
void Administracija::RegistrirajNovogStudenta(int br_indeksa, std::string godina_studija, std::string ime_prezime,
        std::string adresa, std::string telefon)
{
    if(studenti.find(br_indeksa) != studenti.end())
        throw std::domain_error ("Student s tim indeksom vec postoji");
    studenti[br_indeksa] = new Student(br_indeksa, godina_studija, ime_prezime,
                                       adresa, telefon);
}
void Administracija::RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike)
{
    if(laptopi.find(ev_broj) != laptopi.end())
        throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    laptopi[ev_broj] = new Laptop(ev_broj, naziv, karakteristike);
}
Student& Administracija::NadjiStudenta(int br_indeksa)
{
    auto it(studenti.find(br_indeksa));
    if(it == studenti.end())
        throw std::domain_error ("Student nije nadjen");
    return *(it->second);
}
Student Administracija::NadjiStudenta(int br_indeksa) const
{
    auto it(studenti.find(br_indeksa));
    if(it == studenti.end())
        throw std::domain_error ("Student nije nadjen");
    return *(it->second);
}
Laptop& Administracija::NadjiLaptop(int ev_broj)
{
    auto it(laptopi.find(ev_broj));
    if(it == laptopi.end())
        throw std::domain_error ("Laptop nije nadjen");
    return *(it->second);
}
Laptop Administracija::NadjiLaptop(int ev_broj) const
{
    auto it(laptopi.find(ev_broj));
    if(it == laptopi.end())
        throw std::domain_error ("Laptop nije nadjen");
    return *(it->second);
}
void Administracija::IzlistajStudente() const
{
    for(auto it = studenti.begin(); it != studenti.end(); it++) {
        (it->second)->Ispisi();
        std::cout << std::endl;
    }
}
void Administracija::IzlistajLaptope() const
{
    for(auto it = laptopi.begin(); it != laptopi.end(); it++) {
        (it->second)->Ispisi();
        if((it->second)->DaLiJeZaduzen())
            std::cout << "Zaduzio(la): " << (it->second)->DajKodKogaJe().DajImePrezime() <<
                      " (" << (it->second)->DajKodKogaJe().DajIndeks() << ")"<< std::endl;
        std::cout << std::endl;
    }
}
void Administracija::ZaduziLaptop(int br_indeksa, int ev_broj)
{
    if(studenti.find(br_indeksa) == studenti.end())
        throw std::domain_error ("Student nije nadjen");
    if(laptopi.find(ev_broj) == laptopi.end())
        throw std::domain_error ("Laptop nije nadjen");
    if(laptopi[ev_broj]->DaLiJeZaduzen())
        throw std::domain_error ("Laptop vec zaduzen");
    bool jenull(false);
    auto it = std::find_if(laptopi.begin(), laptopi.end(), [br_indeksa, &jenull](std::pair<int, Laptop*> x) {
        if(!x.second->DajPokKodKogaJe()) jenull = true;
        return !x.second->DajPokKodKogaJe() || x.second->DajKodKogaJe().DajIndeks() == br_indeksa;
    });
    if(it != laptopi.end() && !jenull)
        throw std::domain_error("Student je vec zaduzio laptop");
    laptopi[ev_broj]->Zaduzi(*studenti[br_indeksa]);
}
int Administracija::NadjiSlobodniLaptop()
{
    auto it = std::find_if(laptopi.begin(), laptopi.end(), [](std::pair<int, Laptop*> x) {
        return x.second->DaLiJeZaduzen();
    });
    if(it == laptopi.end())
        throw std::domain_error("Nema slobodnih laptopa");
    return it->second->DajEvidencijskiBroj();
}
void Administracija::RazduziLaptop(int ev_broj)
{
    if(laptopi.find(ev_broj) == laptopi.end())
        throw std::domain_error ("Laptop nije nadjen");
    if(!laptopi[ev_broj]->DaLiJeZaduzen())
        throw std::domain_error ("Laptop nije zaduzen");
    laptopi[ev_broj]->Razduzi();
}
void Administracija::PrikaziZaduzenja()
{   bool ima_zaduzenja(false);
    for_each(laptopi.begin(), laptopi.end(), [this, &ima_zaduzenja](std::pair<int, Laptop*> x){
        if(x.second->DaLiJeZaduzen()){
            ima_zaduzenja = true;
            std::cout << "Student " << x.second->DajKodKogaJe().DajImePrezime() <<
                      " (" << x.second->DajKodKogaJe().DajIndeks() << ") zaduzio/la laptop broj ";
                std::cout << x.second->DajEvidencijskiBroj() << std::endl;
        }
    });
    if(!ima_zaduzenja) std::cout << "Nema zaduzenja" << std::endl;
} 
