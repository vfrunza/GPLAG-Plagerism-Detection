/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <new>
#include <stdexcept>
#include <map>
#include <algorithm>

std::string izbaci_razmake(std::string ime)
{
    while(ime[0]==' ') {
        ime.erase(ime.begin()+0);
    }
    while(ime[ime.size()-1]==' ') {
        ime.erase(ime.begin()+ime.size()-1);
    }
    for(int i(1); i<ime.size()-1; i++) {
        if(ime[i]==' ' && ime[i-1]==' ') {
            ime.erase(ime.begin()+i);
            i--;
        }
    }
    return ime;
}
class Student
{
    int broj_indeksa;
    std::string ime_prezime, adresa, broj_telefona,godina_studija;

public:

    Student (int indeks,std::string godina, std::string ime, std::string adr, std::string telefon) {
        bool T(true);
        if(indeks/10000<1 || indeks/10000>9) T=false;
        if(godina!="1" && godina!="2" && godina!="3" && godina!="1/B" && godina!="2/B" && godina!="3/B" && godina!="1/M" && godina!="2/M" && godina!="1/D" && godina!="2/D" && godina!="3/D") T=false;
        if(telefon.size()==0) T=false;
        int i(0);
        if(T) {
            while(telefon[i]!='/' && i!=telefon.size()-1) {
                if(telefon[i]<'0' || telefon[i]>'9') T=false;
                i++;
            }
            if(i==telefon.size()-1) T=false;
        }
        if(T) {
            i++;
            if(i==telefon.size()-1) T=false;
            while(telefon[i]!='-' && i!=telefon.size()-1) {
                if(telefon[i]<'0' || telefon[i]>'9') T=false;
                i++;
            }
            if(i==telefon.size()-1) T=false;
        }
        if(T) {
            i++;
            if(telefon[i]<'0' || telefon[i]>'9') T=false;
            while(i!=telefon.size()-1) {
                if(telefon[i]<'0' || telefon[i]>'9') T=false;
                i++;
            }
        }
        if(T) {
            broj_indeksa=indeks;
            godina_studija=godina;
            ime_prezime=izbaci_razmake(ime);
            adresa=izbaci_razmake(adr);
            broj_telefona=telefon;
        } else throw std::domain_error("Neispravni parametri");
    }
     int DajIndeks() const {
        return broj_indeksa;
    }
     std::string DajImePrezime() const {
        return ime_prezime;
    }
     std::string DajAdresu() const {
        return adresa;
    }
    std::string DajTelefon() const {
        return broj_telefona;
    }
    std::string DajGodinuStudija() {
        std::string god(godina_studija);
        if(god.size()==1) {
            god.push_back('/');
            god.push_back('B');
        }
        return god;
    }
    void Ispisi() {
        std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl;
        std::cout<<"Godina studija: "<<DajGodinuStudija()<<std::endl;
        std::cout<<"Ime i prezime: "<<DajImePrezime()<<std::endl;
        std::cout<<"Adresa: "<<DajAdresu()<<std::endl;
        std::cout<<"Telefon: "<<DajTelefon()<<std::endl;
    }
};

class Laptop
{
    int ev_broj;
    std::string naziv, karakteristike;
    Student *kod_koga_je;

public:
    Laptop (int br, std::string ime, std::string osobine) {
        if(br<0) throw std::domain_error("Neispravni parametri");
        else {
            ev_broj=br;
            naziv=ime;
            karakteristike=osobine;
            kod_koga_je=nullptr;
        }
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
    void Zaduzi(Student &s) {
        if(kod_koga_je==nullptr)
            kod_koga_je=&s;
    }
    void Razduzi()  {
        if(kod_koga_je!=nullptr)
            kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen() const {
        return (kod_koga_je!=nullptr);
    }
    Student &DajKodKogaJe () const {
        if(kod_koga_je!=nullptr) return *kod_koga_je;
        else throw std::domain_error("Laptop nije zaduzen");
    }
    Student *DajPokKodKogaJe() {
        return kod_koga_je;
    }
    void Ispisi()  {
        std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<std::endl;
        std::cout<<"Naziv: "<<DajNaziv()<<std::endl;
        std::cout<<"Karakteristike: "<<DajKarakteristike()<<std::endl;
    }
};

class Administracija
{
    std::map<int,Student *> studenti;
    std::map<int,Laptop *> laptopi;
public:
    Administracija() {
        studenti.insert({0,nullptr});
        laptopi.insert({0,nullptr});
    }
    Administracija(const Administracija &a) {
        for(auto it=a.studenti.begin(); it!=a.studenti.end(); it++) {
            Student *pok(new Student(it->second->DajIndeks(),it->second->DajGodinuStudija(),it->second->DajImePrezime(),it->second->DajAdresu(),it->second->DajAdresu()));
            studenti.insert({it->first,pok});
        }
        for(auto it=a.laptopi.begin(); it!=a.laptopi.end(); it++) {
            Laptop *pok(new Laptop(it->second->DajEvidencijskiBroj(), it->second->DajNaziv(), it->second->DajKarakteristike()));
            laptopi.insert({it->first,pok});
        }
    }
    Administracija(Administracija &&a) {
        for(auto it=a.studenti.begin(); it!=a.studenti.end(); it++)
            studenti.insert({it->first, it->second});
        for(auto it=a.laptopi.begin(); it!=a.laptopi.end(); it++)
            laptopi.insert({it->first, it->second});
    }
    ~Administracija() {
        for(auto it=studenti.begin(); it!=studenti.end(); it++)
            delete it->second;
        for(auto its=laptopi.begin(); its!=laptopi.end(); its++)
            delete its->second;
    }

    void RegistrirajNovogStudenta(int indeks,std::string godina, std::string ime, std::string adr, std::string telefon) {
        int brojac(0);
        for(auto it = studenti.begin(); it != studenti.end(); it++)
            if(indeks==it->first) brojac++;
        if(brojac>0) throw std::domain_error("Student s tim indeksom vec postoji");
        else {
            Student *neki_student(new Student(indeks,godina,ime,adr,telefon));
            studenti.insert({indeks,neki_student});
        }
    }

    void RegistrirajNoviLaptop (int br, std::string ime, std::string osobine) {
        int brojac(0);
        for(auto it= laptopi.begin(); it!= laptopi.end(); it++)
            if(br==it->first) brojac++;
        if(brojac>0) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
        else {
            Laptop *neki_laptop=new Laptop(br,ime,osobine);
            laptopi.insert({br,neki_laptop});
        }
    }
    Student &NadjiStudenta(int indeks) {
        auto it(studenti.find(indeks));
        if(it == studenti.end()) throw std::domain_error("Student nije nadjen");
        else return *(it->second);
    }
    Laptop &NadjiLaptop(int br) {
        auto it(laptopi.find(br));
        if(it == laptopi.end()) throw std::domain_error("Laptop nije nadjen");
        else return *(it->second);
    }
    void IzlistajStudente() {
        for( auto it=studenti.begin(); it!=studenti.end(); it++)
            std::cout<<it->second->DajIndeks()<<" "<<it->second->DajImePrezime()<<" "<<it->second->DajAdresu()<<" "<<it->second->DajTelefon()<<std::endl<<std::endl;
    }
    void IzlistajLaptope() {
        for( auto it=laptopi.begin(); it!=laptopi.end(); it++) {
            std::cout<<(it->second)->DajEvidencijskiBroj()<<" "<<(it->second)->DajNaziv()<<" "<<(it->second)->DajKarakteristike()<<std::endl;
            if(it->second->DaLiJeZaduzen()) std::cout<<"Zaduzio(la): "<<it->second->DajKodKogaJe().DajImePrezime()<<"("<<it->second->DajKodKogaJe().DajIndeks()<<")"<<std::endl;
            else std::cout<<std::endl;
        }
    }
    void ZaduziLaptop(int br, int ev) {
        bool T(false);
        for(auto it = studenti.begin(); it != studenti.end(); it++)
            if(it->first==br) {
                T=true;
                break;
            }
        if(!T) throw std::domain_error("Student nije nadjen");
        else {
            T=false;
            for(auto it=laptopi.begin(); it!= laptopi.end(); it++)
                if(it->first==ev) {
                    T=true;
                    break;
                }
            if(!T) throw std::domain_error("Laptop nije nadjen");
            else {
                for(auto it=laptopi.begin(); it!= laptopi.end() ; it++)
                    if(it->first==ev) if(it->second->DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");

                for(auto it=laptopi.begin(); it!= laptopi.end() ; it++)
                    for(auto its=studenti.begin(); its!=studenti.end() ; its++)
                        if(it->first==ev && its->first == br) {
                            it->second->Zaduzi(*(its->second));
                        }
            }
        }
    }
    int NajdiSlobodniLaptop() {
        for(auto it=laptopi.begin(); it!= laptopi.end() ; it++)
            if(it->second->DaLiJeZaduzen()) return it->first;
        throw std::domain_error("Nema slobodnih laptopa");
    }
    void RazduziLaptop(int ev) {
        int br(0);
        for(auto it=laptopi.begin(); it!= laptopi.end() ; it++)
            if(it->first==ev) {
                br++;
                if(!(it->second->DaLiJeZaduzen())) throw std::domain_error("Laptop nije zaduzen");
                else it->second->Razduzi();
            }
        if(br==0) throw std::domain_error("Laptop nije nadjen");
    }
    void PrikaziZaduzenja() {
        int brojac(0);
        for(auto it=laptopi.begin(); it!=laptopi.end(); it++)
            if(it->second->DaLiJeZaduzen()) {
                brojac++;
                std::cout<<"Student "<<it->second->DajKodKogaJe().DajImePrezime()<<" ("<<it->second->DajKodKogaJe().DajIndeks()<<")"<<" zaduzio/la laptop broj "<<it->second->DajEvidencijskiBroj()<<std::endl;
            }
        if(brojac>0)  std::cout<<"Nema zaduzenja"<<std::endl;
    }
};
int main ()
{
//AT24 - (javni) Test klase Administracija - IzlistajStudente

    Administracija etf ;

    etf.RegistrirajNoviLaptop(123, "Dell", "CPU 3.0 GHz, 4 GB RAM");
    etf.RegistrirajNoviLaptop(331, "ASUS", "CPU 3.5 GHz, 2 GB RAM");
    etf.RegistrirajNoviLaptop(122, "Dell 2", "CPU 3.2 GHz, 6 GB RAM");
    etf.RegistrirajNovogStudenta(14212, "1", "Benjamin", "Francuska revolucija 23", "12/34-56");
    etf.RegistrirajNovogStudenta(17528, "2","Ivan", "Trg vjecnih studenata 12", "048/597-585");

    etf.MojaFunkcija();
    return 0;
}
