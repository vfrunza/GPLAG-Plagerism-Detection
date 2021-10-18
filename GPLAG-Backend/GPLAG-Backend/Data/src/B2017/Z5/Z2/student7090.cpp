/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <map>
#include <memory>



class Student{
    //atributi
    int broj_indeksa;
    std::string godina_studija;
    std::string ime;
    std::string adresa;
    std::string broj_telefona;
    //privatne metode
    std::string TransformirajString(std::string s);
    int BrojRijeci(std::string s);
    
    public:
    explicit Student(int br_indeksa,std::string g_studija,std::string ime_prezime,std::string adr,std::string br_telefona);
    int DajIndeks() const { return broj_indeksa; }
    std::string DajGodinuStudija() const { return godina_studija; }
    std::string DajImePrezime() const { return ime; }
    std::string DajAdresu() const { return adresa; }
    std::string DajTelefon() const { return broj_telefona; }
    void Ispisi() const;
};

void Student::Ispisi() const {
    std::cout << "Broj indeksa: " << DajIndeks() << std::endl;
    std::cout << "Godina studija: " << DajGodinuStudija() << std::endl;
    std::cout << "Ime i prezime: " << DajImePrezime() << std::endl;
    std::cout << "Adresa: " << DajAdresu() << std::endl;
    std::cout << "Telefon: " << DajTelefon() << std::endl;
}

int Student::BrojRijeci(std::string s){
    auto it(s.begin());
    bool razmak(true);
    bool rijec;
    rijec=false;
    int broj_rijeci;
    if(!rijec) broj_rijeci=0;
    while(it!=s.end()){
        if(*it!=' ' && razmak){
            rijec=true;
            razmak=false;
            broj_rijeci++;
        }
        else if(*it==' '){
            razmak=true;
            rijec=false;
        }
        it++;
    }
    return broj_rijeci;
}

std::string Student::TransformirajString(std::string s){
    std::string pomocni;
    int br_rijeci(BrojRijeci(s));
    auto it(s.begin());
    bool razmak(true),rijec(false);
    int broj_rijeci(0);
    while(it!=s.end()){
        if(*it!=' '){
            if(razmak){
                razmak=false;
                broj_rijeci++;
            }
            rijec=true;
            pomocni.push_back(*it);
        }
        
        else if(*it==' ' && rijec){
            razmak=true;
            rijec=false;
            if(broj_rijeci<br_rijeci){
                pomocni.push_back(*it);
            }
        }
        it++;
    }
    return pomocni;
}

Student::Student(int br_indeksa,std::string g_studija,std::string ime_prezime,std::string adr,std::string br_telefona){
    if(int(log10(br_indeksa))+1!=5) throw std::domain_error("Neispravni parametri");
    const char* studij[]{"1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D","3/D"};
    if(std::count(std::begin(studij),std::end(studij),g_studija)!=1) throw std::domain_error("Neispravni parametri");
    std::string pomocni(TransformirajString(ime_prezime));
    if(std::count(br_telefona.begin(),br_telefona.end(),'/')!=1 || std::count(br_telefona.begin(),br_telefona.end(),'-')!=1
    || std::count_if(br_telefona.begin(),br_telefona.end(),[](char znak){return (znak>='0' && znak<='9');})<3)
    // uslov za broj telefona treba promijeniti zbog ovoga npr. 11/1-
    { throw std::domain_error("Neispravni parametri");}
    broj_indeksa=br_indeksa; ime=pomocni; adresa=adr; broj_telefona=br_telefona;
    if(g_studija==studij[0]) godina_studija=studij[3];
    else if(g_studija==studij[1]) godina_studija=studij[4];
    else if(g_studija==studij[2]) godina_studija=studij[5];
    else godina_studija=g_studija;
}

class Laptop{
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    std::shared_ptr<Student> kod_koga_je;
    public:
    explicit Laptop(int evid_br,std::string ime,std::string specifikacije);
    int DajEvidencijskiBroj() const { return ev_broj; }
    std::string DajNaziv() const { return naziv; }
    std::string DajKarakteristike() const { return karakteristike; }
    void Zaduzi(Student &student);
    void Razduzi() { kod_koga_je=nullptr; }
    bool DaLiJeZaduzen() const { if(!kod_koga_je) return false; return true; }
    Student &DajKodKogaJe() { if(!DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen"); return *kod_koga_je; }
    std::shared_ptr<Student> DajPokKodKogaJe()const{ return kod_koga_je; }
    void Ispisi()const;
};

void Laptop::Ispisi()const{
    std::cout << "Evidencijski broj: " << DajEvidencijskiBroj() << std::endl;
    std::cout << "Naziv: " << DajNaziv() << std::endl;
    std::cout << "Karakteristike: " <<DajKarakteristike() << std::endl;
}



void Laptop::Zaduzi(Student &student){
    if(DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
    kod_koga_je=std::make_shared<Student>(student);
}

Laptop::Laptop(int evidencijski_br,std::string ime,std::string specifikacije){
    if(evidencijski_br<0) throw std::domain_error("Neispravni parametri");
    ev_broj=evidencijski_br; naziv=ime; karakteristike=specifikacije;
    kod_koga_je=nullptr;
    
    
}

class Administracija{
    std::map<int,std::shared_ptr<Student>> mapa_studenata;
    std::map<int,std::shared_ptr<Laptop>> mapa_laptopa;
    
    public:
    ~Administracija() = default;
    Administracija() = default;
    Administracija(const Administracija &a);
    Administracija(Administracija &&a);
    void RegistrirajNovogStudenta(int br_indeksa,std::string g_studija,std::string ime_prezime,std::string adr,std::string br_telefona);
    void RegistrirajNoviLaptop(int evid_br,std::string ime,std::string specifikacije);
    Student NadjiStudenta(int indeks) const;
    Student &NadjiStudenta(int indeks);
    Laptop NadjiLaptop(int evid_br) const;
    Laptop &NadjiLaptop(int evid_br);
    void IzlistajStudente() const;
    void IzlistajLaptope() const;
    void ZaduziLaptop(int indeks_studenta,int ev_broj);
    int NadjiSlobodniLaptop() const;
    void RazduziLaptop(int evidencijski_broj_laptopa);
    void PrikaziZaduzenja() const;
    Administracija& operator=(const Administracija &a);
    Administracija& operator=(Administracija &&a);
};

Administracija& Administracija::operator =(Administracija &&a){
    this->mapa_studenata.clear();
    this->mapa_laptopa.clear();
    auto it1(a.mapa_studenata.begin());
    while(it1!=a.mapa_studenata.end()){
        auto pomocni(it1->second);
        this->RegistrirajNovogStudenta(pomocni->DajIndeks(),pomocni->DajGodinuStudija(),pomocni->DajImePrezime(),pomocni->DajAdresu(),pomocni->DajTelefon());
        it1++;
    }
    auto it2(a.mapa_laptopa.begin());
    while(it2!=a.mapa_laptopa.end()){
        auto pomocni(it2->second);
        this->RegistrirajNoviLaptop(pomocni->DajEvidencijskiBroj(),pomocni->DajNaziv(),pomocni->DajKarakteristike());
        if(pomocni->DaLiJeZaduzen()){
            auto s(pomocni->DajKodKogaJe());
            this->ZaduziLaptop(s.DajIndeks(),pomocni->DajEvidencijskiBroj());
        }
        it2++;
    }
    return *this;
}

Administracija::Administracija(Administracija &&a){
    auto it1(a.mapa_studenata.begin());
    while(it1!=a.mapa_studenata.end()){
        auto pomocni(it1->second);
        this->RegistrirajNovogStudenta(pomocni->DajIndeks(),pomocni->DajGodinuStudija(),pomocni->DajImePrezime(),pomocni->DajAdresu(),pomocni->DajTelefon());
        it1++;
    }
    auto it2(a.mapa_laptopa.begin());
    while(it2!=a.mapa_laptopa.end()){
        auto pomocni(it2->second);
        this->RegistrirajNoviLaptop(pomocni->DajEvidencijskiBroj(),pomocni->DajNaziv(),pomocni->DajKarakteristike());
        if(pomocni->DaLiJeZaduzen()){
            auto s(pomocni->DajKodKogaJe());
            this->ZaduziLaptop(s.DajIndeks(),pomocni->DajEvidencijskiBroj());
        }
        it2++;
    }
}

Administracija& Administracija::operator=(const Administracija &a){
    this->mapa_studenata.clear();
    this->mapa_laptopa.clear();
    auto it1(a.mapa_studenata.begin());
    while(it1!=a.mapa_studenata.end()){
        auto pomocni(it1->second);
        this->RegistrirajNovogStudenta(pomocni->DajIndeks(),pomocni->DajGodinuStudija(),pomocni->DajImePrezime(),pomocni->DajAdresu(),pomocni->DajTelefon());
        it1++;
    }
    auto it2(a.mapa_laptopa.begin());
    while(it2!=a.mapa_laptopa.end()){
        auto pomocni(it2->second);
        this->RegistrirajNoviLaptop(pomocni->DajEvidencijskiBroj(),pomocni->DajNaziv(),pomocni->DajKarakteristike());
        if(pomocni->DaLiJeZaduzen()){
            auto s(pomocni->DajKodKogaJe());
            this->ZaduziLaptop(s.DajIndeks(),pomocni->DajEvidencijskiBroj());
        }
        it2++;
    }
    return *this;
}

Administracija::Administracija(const Administracija &a){
    auto it1(a.mapa_studenata.begin());
    while(it1!=a.mapa_studenata.end()){
        auto pomocni(it1->second);
        this->RegistrirajNovogStudenta(pomocni->DajIndeks(),pomocni->DajGodinuStudija(),pomocni->DajImePrezime(),pomocni->DajAdresu(),pomocni->DajTelefon());
        it1++;
    }
    auto it2(a.mapa_laptopa.begin());
    while(it2!=a.mapa_laptopa.end()){
        auto pomocni(it2->second);
        this->RegistrirajNoviLaptop(pomocni->DajEvidencijskiBroj(),pomocni->DajNaziv(),pomocni->DajKarakteristike());
        if(pomocni->DaLiJeZaduzen()){
            auto s(pomocni->DajKodKogaJe());
            this->ZaduziLaptop(s.DajIndeks(),pomocni->DajEvidencijskiBroj());
        }
        it2++;
    }
}



void Administracija::PrikaziZaduzenja() const{
    bool imal_zaduzenja(false);
    auto it(mapa_laptopa.begin());
    while(it!=mapa_laptopa.end()){
        auto pomocni(it->second);
        if(pomocni->DaLiJeZaduzen()){
            imal_zaduzenja=true;
            std::cout << "Student " << (pomocni->DajKodKogaJe()).DajImePrezime();
            std::cout << " (" << (pomocni->DajKodKogaJe()).DajIndeks() << ")";
            std::cout << " zaduzio/la laptop broj " << pomocni->DajEvidencijskiBroj() << std::endl;
        }
        it++;
    }
    if(!imal_zaduzenja) std::cout << "Nema zaduzenja" << std::endl;
}

void Administracija::RazduziLaptop(int evid_br){
    Laptop &l(this->NadjiLaptop(evid_br));
    if(!(l.DaLiJeZaduzen())) throw std::domain_error("Laptop nije zaduzen");
    l.Razduzi();
}

int Administracija::NadjiSlobodniLaptop() const {
    auto it(mapa_laptopa.begin());
    while(it!=mapa_laptopa.end()){
        auto pomocni(it->second);
        if(!(pomocni->DaLiJeZaduzen())) return it->first;
        it++;
    }
    throw std::domain_error("Nema slobodnih laptopa");
}

void Administracija::ZaduziLaptop(int indeks_studenta,int evid_br){
    Student &s(this->NadjiStudenta(indeks_studenta));
    Laptop &l(this->NadjiLaptop(evid_br));
    if(l.DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
    auto it(mapa_laptopa.begin());
    while(it!=mapa_laptopa.end()){
        auto pomocni(it->second);
        if(pomocni->DaLiJeZaduzen()) if((pomocni->DajKodKogaJe()).DajImePrezime()==s.DajImePrezime()) throw std::domain_error("Student je vec zaduzio laptop");
        
        it++;
    }
    l.Zaduzi(s);
}


void Administracija::IzlistajLaptope()const{
    auto it(mapa_laptopa.begin());
    while(it!=mapa_laptopa.end()){
        auto pomocni(it->second);
        pomocni->Ispisi();
        if(pomocni->DaLiJeZaduzen()){
            std::cout << "Zaduzio(la): " << (pomocni->DajKodKogaJe()).DajImePrezime();
            std::cout << " (" << (pomocni->DajKodKogaJe()).DajIndeks() << ")" << std::endl;
        }
        std::cout << std::endl;
        it++;
    }
}

void Administracija::IzlistajStudente()const{
    auto it(mapa_studenata.begin());
    while(it!=mapa_studenata.end()){
        auto pomocni(it->second);
        pomocni->Ispisi();
        std::cout << std::endl;
        it++;
    }
}


Laptop Administracija::NadjiLaptop(int evid_br) const {
    if(!mapa_laptopa.count(evid_br)) throw std::domain_error("Laptop nije nadjen");
    auto it(mapa_laptopa.find(evid_br));
    Laptop l(*it->second);
    return l;
}

Laptop& Administracija::NadjiLaptop(int evid_br){
    if(!mapa_laptopa.count(evid_br)) throw std::domain_error("Laptop nije nadjen");
    auto it(mapa_laptopa.find(evid_br));
    return *(it->second);
}

Student Administracija::NadjiStudenta(int indeks) const {
    if(!mapa_studenata.count(indeks)) throw std::domain_error("Student nije nadjen");
    auto it(mapa_studenata.find(indeks));
    Student s(*(it->second));
    return s;
}

Student& Administracija::NadjiStudenta(int indeks){
    if(!mapa_studenata.count(indeks)) throw std::domain_error("Student nije nadjen");
    auto it(mapa_studenata.find(indeks));
    return *(it->second);
}

void Administracija::RegistrirajNoviLaptop(int evid_br,std::string ime,std::string specifikacije){
    if(mapa_laptopa.count(evid_br)) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    mapa_laptopa.insert({evid_br,std::make_shared<Laptop>(Laptop(evid_br,ime,specifikacije))});
}

void Administracija::RegistrirajNovogStudenta(int br_indeksa,std::string g_studija,std::string ime_prezime,std::string adr,std::string br_telefona){
    if(mapa_studenata.count(br_indeksa)) throw std::domain_error ("Student s tim indeksom vec postoji");
    mapa_studenata.insert({br_indeksa,std::make_shared<Student>(Student(br_indeksa,g_studija,ime_prezime,adr,br_telefona))});
}

Administracija BezveznaFunkcija(Administracija &a){
    return a;
}

int main ()
{
    
    Administracija A;
    for(;;) {
        try{
        std::cout << std::endl;
        std::cout << "Odaberi opciju:" << std::endl;
        std::cout << "1 - Registriraj Novog Studenta" << std::endl;
        std::cout << "2 - Registriraj Novi Laptop" << std::endl;
        std::cout << "3 - Izlistaj Studente" << std::endl;
        std::cout << "4 - Izlistaj Laptope" << std::endl;
        std::cout << "5 - Zaduzi Laptop" << std::endl;
        std::cout << "6 - Razduzi Laptop" << std::endl;
        std::cout << "7 - Prikazi Zaduzenja" << std::endl;
        std::cout << "8 - Nadji Slobodni Laptop" << std::endl;
        std::cout << "9 - Izlaz" << std::endl;
        int opcija(0);
        std::cin >> opcija;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << std::endl;
        switch(opcija){
            case 1:{
                
                std::cout << "Ime i prezime studenta: ";
                std::string s;
                std::getline(std::cin,s);
                std::cout << "Indeks: ";
                int indeks(0); std::cin >> indeks;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cout << "Godina studija: ";
                std::string godina;
                std::getline(std::cin,godina);
                std::cout << "Adresa stanovanja: ";
                std::string adresa;
                std::getline(std::cin,adresa);
                std::cout << "Broj telefona: ";
                std::string telefon;
                std::getline(std::cin,telefon);
                A.RegistrirajNovogStudenta(indeks,godina,s,adresa,telefon);
                break;
            }
            case 2:{
                std::cout << "Naziv laptopa: ";
                std::string naziv;
                std::getline(std::cin,naziv);
                std::cout << "Evidencijski broj: ";
                int broj(-1); std::cin >> broj;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cout << "Karakteristike: ";
                std::string opis;
                std::getline(std::cin,opis);
                A.RegistrirajNoviLaptop(broj,naziv,opis);
                break;
            }
            case 3:{
                A.IzlistajStudente();
                break;
            }
            case 4:{
                A.IzlistajLaptope();
                break;
            }
            case 5:{
                std::cout << "Unesite broj indeksa studenta koji zaduzuje laptop: ";
                int indeks(0); std::cin >> indeks;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cout << "Unesite evidencijski broj laptopa koji se zaduzuje: ";
                int evid_br(-1); std::cin >> evid_br;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                A.ZaduziLaptop(indeks,evid_br);
                std::cout << std::endl;
                break;
            }
            case 6:{
                std::cout << "Unesite evidencijski broj laptopa koji se razduzuje: ";
                int evid_br(-1); std::cin >> evid_br;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                A.RazduziLaptop(evid_br);
                std::cout << std::endl;
                break;
            }
            case 7:{
                A.PrikaziZaduzenja();
                break;
            }
            case 8:{
                std::cout << "Slobodan laptop ima evidencijski broj " << A.NadjiSlobodniLaptop() << "." << std::endl;
                break;
            }
            case 9:{
                return 0;
            }
            default:{
                std::cout << "Pogresna komanda. Pokusajte ponovo." << std::endl;
            }
        }
        
    }
    catch(std::domain_error iz){
        std::cout << iz.what();
        }
    }
    
	return 0;
}
