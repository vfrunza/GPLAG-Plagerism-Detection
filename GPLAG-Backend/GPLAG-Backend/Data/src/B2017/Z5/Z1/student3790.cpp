/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include<map>
#include<new>
class Student
{
    int broj_indeksa;
    std::string godina_studija;
    std::string ime_prezime;
    std::string adresa_studenta;
    std::string broj_telefona;
public:
    Student(int broj_indeksa1,std::string godina_studija1, std::string ime_prezime1,std::string adresa_studenta1,std::string broj_telefona1) {
        for(int i=0; i<ime_prezime1.size(); i++) {
            if(ime_prezime1[i]==' ') {
                ime_prezime1.erase(ime_prezime1.begin()+i);
                i--;
            } else break;
        }
        for(int i=ime_prezime1.size()-1; i>=0; i--) {
            if(ime_prezime1[i]==' ') ime_prezime1.erase(ime_prezime1.begin()+i);
            else break;
        }
        for(int i=0; i<ime_prezime1.size()-1; i++) {
            if(ime_prezime1[i]==' ' && ime_prezime1[i+1]==' ') {
                ime_prezime1.erase(ime_prezime1.begin()+i);
                i--;
            }
        }
        broj_indeksa=broj_indeksa1;
        std::string b="/B";
        if(godina_studija1.size()==1) godina_studija1+=b;
        godina_studija=godina_studija1;
        ime_prezime=ime_prezime1;
        adresa_studenta=adresa_studenta1;
        broj_telefona=broj_telefona1;
    }
    int DajIndeks()const {
        return broj_indeksa;
    }
    std::string DajGodinuStudija()const {
        return godina_studija;
    }
    std::string DajImePrezime()const {
        return ime_prezime;
    }
    std::string DajAdresu()const {
        return adresa_studenta;
    }
    std::string DajTelefon()const {
        return broj_telefona;
    }
    
    void Ispisi()const {
        std::cout<<"Broj indeksa: "<<broj_indeksa<<std::endl;
        std::cout<<"Godina studija: ";
        for(auto x:godina_studija) {
            std::cout<<x;
        }
        if(godina_studija.size()==1) std::cout<<"/B";
        std::cout<<std::endl;
        std::cout<<"Ime i prezime: ";
        for(auto x:ime_prezime) {
            std::cout<<x;
        }
        std::cout<<std::endl;
        std::cout<<"Adresa: ";
        for(auto x:adresa_studenta) {
            std::cout<<x;
        }
        std::cout<<std::endl;
        std::cout<<"Telefon: ";
        for(auto x:broj_telefona) {
            std::cout<<x;
        }
        std::cout<<std::endl;
    }
    void IspisiPodatke()const {
        std::cout<<"Broj indeksa: "<<broj_indeksa<<std::endl;
        std::cout<<"Godina studija: ";
        for(auto x:godina_studija) {
            std::cout<<x;
        }
        if(godina_studija.size()==1) std::cout<<"/B";
        std::cout<<std::endl;
        std::cout<<"Ime i prezime: ";
        for(auto x:ime_prezime) {
            std::cout<<x;
        }
        std::cout<<std::endl;
        std::cout<<"Adresa: ";
        for(auto x:adresa_studenta) {
            std::cout<<x;
        }
        std::cout<<std::endl;
        std::cout<<"Telefon: ";
        for(auto x:broj_telefona) {
            std::cout<<x;
        }
        std::cout<<std::endl;
    }

};
class Laptop
{
    int  ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student* kod_koga_je;
public:
    Laptop(int  ev_broj1, std::string naziv1, std::string karakteristike1) {
        if(ev_broj1<0) throw std::domain_error("Neispravni parametri");
        ev_broj=ev_broj1;
        naziv=naziv1;
        karakteristike=karakteristike1;
        kod_koga_je=nullptr;
    }
    int DajEvidencijskiBroj()const {
        return ev_broj;
    }
    std::string DajNaziv()const {
        return naziv;
    }
    std::string DajKarakteristike()const {
        return karakteristike;
    }
    //OVDJE MOZDA TREBA PRIMAT CONST STUDENDT &S
    void  Zaduzi(Student &s) {
        if(kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je=&s;
    }
    void Razduzi() {
        if(kod_koga_je!=nullptr) {
            kod_koga_je=nullptr;
        }
    }
    bool DaLiJeZaduzen() {
        return (kod_koga_je!=nullptr);
    }
    Student& DajKodKogaJe() {
        if(kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen");
        return *kod_koga_je;
    }
    Student* DajPokKodKogaJe() {
        return kod_koga_je;
    }
    void Ispisi() {
        std::cout << "Evidencijski broj: " <<ev_broj<< std::endl;
        std::cout << "Naziv: "<<naziv << std::endl;
        std::cout <<"Karakteristike: "<< karakteristike << std::endl;
    }
};
class Administracija
{
    std::map<int,Student*> mapa_studenata;
    std::map<int ,Laptop*> mapa_laptopa;
public:
    Administracija(){}
    Administracija(const Administracija& a){
        
        for(auto x:a.mapa_laptopa){ mapa_laptopa[x.first]=new Laptop(*(x.second));}
        for(auto x:a.mapa_studenata){mapa_studenata[x.first]=new Student(*(x.second));}
    }
    Administracija (Administracija&& a){
        
        for(auto x:a.mapa_laptopa){ mapa_laptopa[x.first]=x.second; a.mapa_laptopa[x.first]=nullptr;}
        for(auto x:a.mapa_studenata){mapa_studenata[x.first]=x.second; a.mapa_studenata[x.first]=nullptr;}
        
    }
    ~Administracija(){
        for(auto x:mapa_laptopa){delete x.second;}
        for(auto x:mapa_studenata){delete x.second;}
    }
    void operator=(const Administracija& a){
        for(auto x:mapa_laptopa){delete x.second;}
        for(auto x:mapa_studenata){delete x.second;}
        for(auto x:a.mapa_laptopa){ mapa_laptopa[x.first]=new Laptop(*(x.second));}
        for(auto x:a.mapa_studenata){mapa_studenata[x.first]=new Student(*(x.second));}
    }
    void operator=(Administracija&& a){
        for(auto x:mapa_laptopa){delete x.second;}
        for(auto x:mapa_studenata){delete x.second;}
        for(auto x:a.mapa_laptopa){ mapa_laptopa[x.first]=x.second; a.mapa_laptopa[x.first]=nullptr;}
        for(auto x:a.mapa_studenata){mapa_studenata[x.first]=x.second; a.mapa_studenata[x.first]=nullptr;}
        
    }
    void RegistrirajNovogStudenta(int broj_indeksa1,std::string godina_studija1, std::string ime_prezime1,std::string adresa_studenta1,std::string broj_telefona1);
    void  RegistrirajNoviLaptop(int  ev_broj1, std::string naziv1, std::string karakteristike1);
    Student& NadjiStudenta(int broj_indeksa1);
    Student NadjiStudenta(int broj_indeksa1)const;
    Laptop& NadjiLaptop(int ev_broj1);
    Laptop NadjiLaptop(int ev_broj1)const;
    void IzlistajStudente()const;
    void IzlistajLaptope()const;
    void ZaduziLaptop(int broj_indeksa1,int ev_broj1);
    int NadjiSlobodniLaptop()const;
    void RazduziLaptop(int ev_broj1);
    void PrikaziZaduzenja();
};
//KRAJ KLASE
void Administracija::RegistrirajNovogStudenta(int broj_indeksa1,std::string godina_studija1, std::string ime_prezime1,std::string adresa_studenta1,std::string broj_telefona1)
{
    if( mapa_studenata.find(broj_indeksa1)==mapa_studenata.end()) //ako ne postoji student vec
        mapa_studenata[broj_indeksa1]=new Student(broj_indeksa1,godina_studija1,ime_prezime1,adresa_studenta1,broj_telefona1);
    else throw std::domain_error("Student s tim indeksom vec postoji");
}
void Administracija:: RegistrirajNoviLaptop(int  ev_broj1, std::string naziv1, std::string karakteristike1)
{
    if(mapa_laptopa.find(ev_broj1)==mapa_laptopa.end())
        mapa_laptopa[ev_broj1]=new Laptop(ev_broj1,naziv1,karakteristike1);
    else throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
}
Student& Administracija:: NadjiStudenta(int broj_indeksa1)
{
    if( mapa_studenata.find(broj_indeksa1)==mapa_studenata.end()) throw std::domain_error("Student nije nadjen");
    Student& s=*mapa_studenata[broj_indeksa1];
    return s;
}
Student Administracija:: NadjiStudenta(int broj_indeksa1)const
{
    if( mapa_studenata.find(broj_indeksa1)==mapa_studenata.end()) throw std::domain_error("Student nije nadjen");
    auto it=mapa_studenata.find(broj_indeksa1);
    auto p=(*it).second;
    Student s=*p;
    return s;
}
Laptop& Administracija:: NadjiLaptop(int ev_broj1)
{
    if( mapa_laptopa.find(ev_broj1)==mapa_laptopa.end()) throw std::domain_error("Laptop nije nadjen");
    Laptop& l=*mapa_laptopa[ev_broj1];
    return l;
}
Laptop Administracija:: NadjiLaptop(int ev_broj1)const
{
    if( mapa_laptopa.find(ev_broj1)==mapa_laptopa.end()) throw std::domain_error("Laptop nije nadjen");
    auto it=mapa_laptopa.find(ev_broj1);
    auto p=(*it).second;
    Laptop l=*p;
    return l;
}
void Administracija:: IzlistajStudente()const
{
    for(auto x:mapa_studenata) {
        x.second->IspisiPodatke();
    }
}
void Administracija:: IzlistajLaptope()const
{
    for(auto x:mapa_laptopa) {
        x.second->Ispisi();
        if(x.second->DaLiJeZaduzen()==1) {
            std::cout<<"Zaduzio(la): "<< x.second->DajKodKogaJe().DajImePrezime()<<" ("<<x.second->DajKodKogaJe().DajIndeks()<<")"<<std::endl;
        }
        std::cout<<std::endl;
    }
}
void Administracija:: ZaduziLaptop(int broj_indeksa1,int ev_broj1)
{
    if( mapa_studenata.find(broj_indeksa1)==mapa_studenata.end()) throw std::domain_error("Student nije nadjen");
    if( mapa_laptopa.find(ev_broj1)==mapa_laptopa.end()) throw std::domain_error("Laptop nije nadjen");
    if(mapa_laptopa[ev_broj1]->DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
    mapa_laptopa[ev_broj1]->Zaduzi(*mapa_studenata[broj_indeksa1]);
}
int Administracija::NadjiSlobodniLaptop()const
{
    for(auto x:mapa_laptopa) {
        if(x.second->DaLiJeZaduzen()==0) return x.second->DajEvidencijskiBroj();
    }
    throw std::domain_error("Nema slobodnih laptopa");
}
void Administracija::RazduziLaptop(int ev_broj1)
{
    if( mapa_laptopa.find(ev_broj1)==mapa_laptopa.end()) throw std::domain_error("Laptop nije nadjen");
    if(mapa_laptopa[ev_broj1]->DaLiJeZaduzen()==0) throw std::domain_error("Laptop nije zaduzen");
    mapa_laptopa[ev_broj1]->Razduzi();
}
void Administracija::PrikaziZaduzenja()
{
    int i=0;
    for(auto x:mapa_laptopa) {

        if(x.second->DaLiJeZaduzen()==1) {
            std::cout<<"Student "<< x.second->DajKodKogaJe().DajImePrezime()<<" ("<<x.second->DajKodKogaJe().DajIndeks()<<") zaduzio/la laptop broj "<<x.second->DajEvidencijskiBroj()<<std::endl;

            i++;
        }

    }

    if(i==0) std::cout<<"Nema zaduzenja";
}

int main ()
{
    //AT3 - (javni) Test klase Student - metoda Ispisi
    Student s1(12345, "1/D", "Neko Nekic", "Bascarsija 1", "1/1-1");
    Student s2(12346, "1", "    Neko  Nekic    ", "Bascarsija 2", "1/1-1");
    s1.Ispisi();
    std::cout << std::endl;
    s2.Ispisi();
    return 0;
}
