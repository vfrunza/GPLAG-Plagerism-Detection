/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <memory>

class Student
{
    int br_indeksa;
    std::string god_studija, ime_prezime, adresa, br_tel;
public:
    Student(int br_indeksa, std::string god_studija, std::string ime_prezime,
            std::string adresa, std::string br_tel);
    int DajIndeks() const { return br_indeksa; }
    std::string DajGodinuStudija() const { return god_studija; }
    std::string DajImePrezime() const { return ime_prezime; }
    std::string DajAdresu() const { return adresa; }
    std::string DajTelefon() const { return br_tel; }
    void Ispisi() const {
        std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl
                 <<"Godina studija: "<<DajGodinuStudija()<<std::endl
                 <<"Ime i prezime: "<<DajImePrezime()<<std::endl
                 <<"Adresa: "<<DajAdresu()<<std::endl
                 <<"Telefon: "<<DajTelefon()<<std::endl;
    }
};

Student::Student(int br_indeksa, std::string god_studija, std::string ime_prezime,
                 std::string adresa, std::string br_tel) : adresa(adresa)
{
    int br_cif(0), tmp(br_indeksa);
    while(tmp!=0) {
        tmp/=10;
        br_cif++;
    }
    if(br_cif!=5) throw std::domain_error ("Neispravni parametri");
    else Student::br_indeksa=br_indeksa;

    if(god_studija=="1") Student::god_studija ="1/B";
    else if(god_studija=="2") Student::god_studija ="2/B";
    else if(god_studija=="3") Student::god_studija ="3/B";
    else {
        if(god_studija!="1/B" && god_studija!="2/B" && god_studija!="3/B"
                && god_studija!="1/M" && god_studija!="2/M" &&
                god_studija!="1/D" && god_studija!="2/D" && god_studija!="3/D")
            throw std::domain_error ("Neispravni parametri");
        Student::god_studija=god_studija;
    }
    int i=0;
    int vel=ime_prezime.length();
    while(i<vel) {
        while(ime_prezime[i]==' ') i++;
        while(ime_prezime[i]!=' ' && i<vel) {
            Student::ime_prezime.push_back(ime_prezime[i]);
            i++;
        }
        Student::ime_prezime.push_back(' ');
        i++;
    }
    int j=Student::ime_prezime.length()-1;
    while(Student::ime_prezime[j]==' ') {
        Student::ime_prezime.resize(j);
        j--;
    }
    
    bool ispravno_1=false, ispravno_2=false;
    for(int i=0; i<br_tel.length(); i++) {
        if(br_tel[i]=='/') ispravno_1=true;
        if(br_tel[i]=='-') ispravno_2=true;
    }
    if(!ispravno_1) throw std::domain_error ("Neispravni parametri");
    else if(!ispravno_2) throw std::domain_error ("Neispravni parametri");
    else Student::br_tel=br_tel;
}

class Laptop
{
    int ev_broj;
    std::string naziv, karakteristike;
    Student *kod_koga_je;
public:
    Laptop(int ev_broj, std::string naziv, std::string karakteristike) :
        naziv(naziv), karakteristike(karakteristike), kod_koga_je(nullptr)
    {
        if(ev_broj<0) throw std::domain_error ("Neispravni parametri");
        Laptop::ev_broj=ev_broj;
    }
    int DajEvidencijskiBroj() const { return ev_broj; }
    std::string DajNaziv() const { return naziv; }
    std::string DajKarakteristike() const { return karakteristike; }
    void Zaduzi(Student &s) {
        if(kod_koga_je!=nullptr) throw std::domain_error ("Laptop vec zaduzen");
        kod_koga_je=&s;
    }
    void Razduzi() { if(kod_koga_je!=nullptr) kod_koga_je=nullptr; }
    bool DaLiJeZaduzen() const { return kod_koga_je!=nullptr; }
    Student &DajKodKogaJe() {
        if(!DaLiJeZaduzen()) throw std::domain_error ("Laptop nije zaduzen");
        return *kod_koga_je;
    }
    Student *DajPokKodKogaJe() const { return kod_koga_je; }
    void Ispisi() const {
        std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<std::endl
                 <<"Naziv: "<<DajNaziv()<<std::endl
                 <<"Karakteristike: "<<DajKarakteristike()<<std::endl;
    }
};

class Administracija
{
    std::map<int, std::shared_ptr<Student> > studenti;
    std::map<int, std::shared_ptr<Laptop> > laptopi;
public:
    void RegistrirajNovogStudenta(int br_indeksa, std::string god_studija, std::string ime_prezime,
                 std::string adresa, std::string br_tel) 
    {
        for(auto it=studenti.begin(); it!=studenti.end(); it++) {
            if(br_indeksa==it->first) 
                throw std::domain_error ("Student s tim indeksom vec postoji");
        }
        studenti.insert( {br_indeksa, std::make_shared <Student> (br_indeksa, god_studija, 
                          ime_prezime, adresa, br_tel) } );
    }
    void RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike) 
    {
        for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
            if(ev_broj==it->first) 
                throw std::domain_error ("Laptop s tim evidencijskim brojem vec postoji");
        }
        laptopi.insert( {ev_broj, std::make_shared <Laptop> (ev_broj, naziv, karakteristike) } );
    }
    
    Student &NadjiStudenta(int br_indeksa) const {
        for(auto it=studenti.begin(); it!=studenti.end(); it++) {
            if(br_indeksa==it->first)
                return (Student &)*it;
            if(it==studenti.end()) throw std::domain_error ("Student nije nadjen");
        }
    }
    Laptop &NadjiLaptop(int ev_broj) const {
        for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
            if(ev_broj==it->first)
                return (Laptop &) (it->second)->Laptop::DajKodKogaJe();
            if(it==laptopi.end()) throw std::domain_error ("Laptop nije nadjen");
        }
    }
    void IzlistajStudente() const {
        for(auto it=studenti.begin(); it!=studenti.end(); it++) {
            (it->second)->Student::Ispisi();
            std::cout<<std::endl;
        }
    }
    void IzlistajLaptope() const {
        for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
            it->second->Laptop::Ispisi();
            std::cout<<std::endl;
        }
    }
    int NadjiSlobodniLaptop() const {
        for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
            if( !(it->second->DaLiJeZaduzen()) )
                return it->second->DajEvidencijskiBroj();
            if(it==laptopi.end())
                throw std::domain_error ("Nema slobodnih laptopa");
        }
    }
    

};

int main ()
{
    Student s(12345,"1","  a  q   sg   dc            f    ","1", "1/1-1");
    s.Ispisi();
    Administracija a;
    a.RegistrirajNovogStudenta(12345,"1","2","3","4/2-1");
    a.RegistrirajNovogStudenta(12395,"1","2","3","4/2-1");
    a.IzlistajStudente();
    return 0;
}
