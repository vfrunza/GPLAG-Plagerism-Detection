#include <iostream>
#include <cmath>
#include <memory>
#include <string>
#include <cstring>
#include <stdexcept>
#include <memory>
#include <map>
#include <algorithm>
#include <exception>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::shared_ptr;
using std::make_shared;
class Student
{

    int index;
    string god,imepr,adresa,broj;
    static const char * godine[11];
    static bool IspravanIndeks(int bri) {
        return (bri>0 && bri>=10000 && bri<=99999);
    }
    static bool IspravnaGodina(const string &g) {
        for(int i=0; i<11; i++)
            if(g==godine[i]) return true;
        return false;
    }
    static bool Broj(char c) {
        return (c>='0' && c<='9');
    }
    static bool IspravanBroj(const string &s) {
        string temp {};
        string::const_iterator sIt(s.begin());
        while(sIt!=s.end() && Broj(*sIt)) sIt++;
        if(*sIt!='/') return false;
        sIt++;
        while(sIt!=s.end() && Broj(*sIt)) sIt++;
        if(*sIt!='-') return false;
        sIt++;
        while(sIt!=s.end()) {
            if(!Broj(*sIt)) return false;
            sIt++;
        }
        return true;
    }
    void Podesi(string &s) {
        string temp {};
        string::const_iterator sIt(s.begin());
        while(sIt!=s.end()) {
            if(*sIt!=' ') {
                while(sIt!=s.end() && *sIt!=' ') {
                    temp+=*sIt;
                    sIt++;
                }
                temp+=' ';
                sIt--;
            }
            sIt++;
        }
        temp.erase(temp.end()-1);
        s=temp;
    }

public:
    Student(int bri,string god,string ip,string adresa,string broj) {
        if(!IspravanIndeks(bri) || !IspravnaGodina(god) || !IspravanBroj(broj))
            throw std::domain_error("Neispravni parametri");
        Student::god=god;
        index=bri;
        imepr=ip;
        Podesi(imepr);
        Student::adresa=adresa;
        Podesi(Student::adresa);
        Student::broj=broj;
    }

    int DajIndeks() const {
        return index;
    }

    string DajImePrezime() const {
        return imepr;
    }

    string DajGodinuStudija() const {
        int i {};
        for(i=0; i<11; i++)
            if(god==godine[i]) break;
        if(i<=2) i+=3;
        return godine[i];
    }

    string DajTelefon() const {
        return broj;
    }

    string DajAdresu() const {
        return adresa;
    }

    void Ispisi() const {
        cout << "Broj indeksa: " << DajIndeks() << endl << "Godina studija: " << DajGodinuStudija() << endl
             << "Ime i prezime: " << DajImePrezime() << endl << "Adresa: " << DajAdresu() << endl << "Telefon: " << DajTelefon() << endl;
    }
};

const char *  Student::godine[11]= {"1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D", "3/D"};

class Laptop
{
    int ev_broj;
    string naziv, karakteristike;
    Student* kod_koga_je;
public:
    Laptop(int evb,string n, string k) : kod_koga_je(nullptr) {
        if(evb<0) throw std::domain_error("Neispravni parametri");
        ev_broj=evb;
        naziv=n;
        karakteristike=k;
    }

    int DajEvidencijskiBroj() const {
        return ev_broj;
    }

    string DajNaziv() const {
        return naziv;
    }

    string DajKarakteristike() const {
        return karakteristike;
    }

    void Zaduzi(Student &s) {
        if(kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je=&s;
    }

    void Razduzi() {
        kod_koga_je=nullptr;
    }

    bool DaLiJeZaduzen() const {
        return kod_koga_je!=nullptr;
    }

    Student & DajKodKogaJe() const {
        if(!kod_koga_je) throw std::domain_error("Laptop nije zaduzen");
        return *kod_koga_je;
    }

    Student * DajPokKodKogaJe() const {
        return kod_koga_je;
    }

    void Ispisi() {
        cout << "Evidencijski broj: " << ev_broj << endl << "Naziv: " << naziv << endl << "Karakteristike: " << karakteristike << endl;
    }
};

class Administracija
{
    map<int,shared_ptr<Student>> studenti;
    map<int,shared_ptr<Laptop>> laptopi;

public:
    Administracija() {}
    Administracija(const Administracija &a) {
        auto si=a.studenti.begin();
        auto li=a.laptopi.begin();
        while(si!=a.studenti.end()) {
            studenti.insert(std::make_pair(si->first,make_shared<Student>(*(si->second))));
            si++;
        }
        while(li!=a.laptopi.end()) {
            laptopi.insert(std::make_pair(li->first,make_shared<Laptop>(*(li->second))));
            li++;
        }
    }

    Administracija &operator=(const Administracija &a) {
        studenti.clear();
        laptopi.clear();
        auto si=a.studenti.begin();
        auto li=a.laptopi.begin();
        
         while(si!=a.studenti.end()) {
            studenti.insert(std::make_pair(si->first,make_shared<Student>(*(si->second))));
            si++;
        }
        while(li!=a.laptopi.end()) {
            laptopi.insert(std::make_pair(li->first,make_shared<Laptop>(*(li->second))));
            li++;
        }
        return *this;
    }

    Administracija(Administracija &&a) {
        std::swap(studenti,a.studenti);
        std::swap(laptopi,a.laptopi);
    }

    Administracija &operator=(Administracija &&a) {
        std::swap(studenti,a.studenti);
        std::swap(laptopi,a.laptopi);
        return *this;
    }

    void RegistrirajNovogStudenta(int bri,string god,string ip,string adresa,string broj) {
        if(studenti.find(bri)!=studenti.end()) throw std::domain_error("Student s tim indeksom vec postoji");
        studenti.insert(std::make_pair(bri,make_shared<Student>(bri,god,ip,adresa,broj)));
    }

    void RegistrirajNoviLaptop(int evb,string n, string k) {
        if(laptopi.find(evb)!=laptopi.end()) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
        laptopi.insert(std::make_pair(evb,make_shared<Laptop>(evb,n,k)));
    }

    Student &NadjiStudenta(int bri) {
        std::map<int,shared_ptr<Student>>::iterator i;
        if((i=studenti.find(bri))==studenti.end()) throw std::domain_error("Student nije nadjen");
        return *(i->second);
    }

    Student NadjiStudenta(int bri) const {
        std::map<int,shared_ptr<Student>>::const_iterator i;
        if((i=studenti.find(bri))==studenti.end()) throw std::domain_error("Student nije nadjen");
        return *(i->second);
    }

    Laptop &NadjiLaptop(int evb) {
        std::map<int,shared_ptr<Laptop>>::iterator i;
        if((i=laptopi.find(evb))==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
        return *(i->second);
    }

    Laptop NadjiLaptop(int evb) const {
        std::map<int,shared_ptr<Laptop>>::const_iterator i;
        if((i=laptopi.find(evb))==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
        return *(i->second);
    }

    void IzlistajStudente() const {
        std::for_each(studenti.begin(),studenti.end(),[](const std::pair<int,shared_ptr<Student>> &p)->void { p.second->Ispisi();});
    }

    void IzlistajLaptope() const {
        std::for_each(laptopi.begin(),laptopi.end(),[](const std::pair<int,shared_ptr<Laptop>> &p)->void {
            p.second->Ispisi(); if(p.second->DajPokKodKogaJe()!=nullptr)
                cout << "Zaduzio(la): " << p.second->DajPokKodKogaJe()->DajImePrezime() << " (" << p.second->DajPokKodKogaJe()->DajIndeks()  << ")" <<endl;
                cout << endl;
        });
    }

    void ZaduziLaptop(int bri, int evb) {
        try {
            Student &s=NadjiStudenta(bri);
            Laptop &l=NadjiLaptop(evb);
            if(l.DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
            auto i =laptopi.begin();
            while(i!=laptopi.end()) {
                if(i->second->DajPokKodKogaJe()!=nullptr)
                if(bri==i->second->DajPokKodKogaJe()->DajIndeks()) throw std::domain_error("Student vec zaduzio laptop");
                i++;
            }
            l.Zaduzi(s);
        } catch(...) {
            throw;
        }
    }

    int NadjiSlobodniLaptop() const {
        auto i =laptopi.begin();
        while(i!=laptopi.end()) {
            if(!i->second->DaLiJeZaduzen()) return i->first;
            i++;
        }
        throw std::domain_error("Nema slobodnih laptopa");
    }

    void RazduziLaptop(int evb) {
        Laptop &l=NadjiLaptop(evb);
        if(l.DajPokKodKogaJe()==nullptr) throw std::domain_error("Laptop nije zaduzen");
        l.Razduzi();
    }

    void PrikaziZaduzenja() const {
        auto i=laptopi.begin();
        int brojac {};
        while(i!=laptopi.end()) {
            if(i->second->DajPokKodKogaJe()!=nullptr) {
                cout << "Student " << i->second->DajPokKodKogaJe()->DajImePrezime() << " (" <<
                     i->second->DajPokKodKogaJe()->DajIndeks() << ") " << "zaduzio/la laptop broj " << i->first << endl;
                brojac++;
            }
            i++;
        }
        if(brojac==0) cout << "Nema zaduzenja";
    }

    ~Administracija() {}

};


int main ()
{
    
    Administracija etf;

    etf.RegistrirajNoviLaptop(123, "Dell", "CPU 3.0 GHz, 4 GB RAM");
    etf.RegistrirajNoviLaptop(331, "ASUS", "CPU 3.5 GHz, 2 GB RAM");
    etf.RegistrirajNoviLaptop(122, "Dell 2", "CPU 3.2 GHz, 6 GB RAM");


    etf.RegistrirajNovogStudenta(14212, "1","Benjamin", "Francuska revolucija 23", "12/34-56");
    etf.RegistrirajNovogStudenta(17528, "2","Ivan", "Trg vjecnih studenata 12", "048/597-585");
    etf.RegistrirajNovogStudenta(17525, "3", "Ante" ,"Trg vjecnih studenata 11", "062/582-757");

    etf.ZaduziLaptop(14212, 122);
    etf.ZaduziLaptop(17525,331);
    etf.IzlistajLaptope();
    
    
    /*Administracija a;
    a.RegistrirajNovogStudenta(18088,"2", "         Zoe     Taliyah","         Kolodvorska      13","060/318-9774");
    a.RegistrirajNovogStudenta(18221,"3/D","Hehe Hehic","Hehovska 23","000/000-321");
    a.RegistrirajNoviLaptop(1337,"Alienware","Gaming Laptop, 16GB, I7 4770K 3.5GHz Quad-Core, GTX980");
    a.RegistrirajNoviLaptop(1338,"Beze","Beze skroz");
    a.ZaduziLaptop(18088,1337);
    a.PrikaziZaduzenja();
    a.RazduziLaptop(1337);
    a.PrikaziZaduzenja();
    a.NadjiStudenta(18221).Ispisi();*/
    return 0;
}
