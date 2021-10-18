/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
class Student {
    int index;
    std::string god_studija;
    std::string ime_prezime;
    std::string adresa;
    std::string br_tel;
    int BrojCifara (int n) {
        int br(0), cifra(0);
        while(n!=0) {
            cifra=n%10;
            n=n/10;
            br++;
        }
        return br;
    }
    public:
    Student(int index, std::string god_studija,std::string ime_prezime, std::string adresa, std::string br_tel) {
        if(BrojCifara(index)!=5 ) throw std::domain_error("Neispravni parametri");//fali ovdje
        Student::index=index;
        Student::god_studija=god_studija;
        Student::ime_prezime=ime_prezime;
        Student::adresa=adresa;
        Student::br_tel=br_tel;
    }
    int DajIndeks() const { return index; }
    std::string DajGodinuStudija() const { return god_studija; }
    std::string DajImePrezime() const { return ime_prezime; }
    std::string DajAdresu() const { return adresa; }
    std::string DajTelefon() const { return br_tel; }
    void Ispisi() {
        std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl<<"Godina studija: "<<DajGodinuStudija()<<std::endl<<"Ime i prezime: "<<DajImePrezime()<<std::endl<<"Adresa: "<<DajAdresu()<<std::endl<<"Telefon: "<<DajTelefon();
    }
};
class Laptop{
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student* kod_koga_je;
    public:
    Laptop(int ev_broj, std::string naziv, std::string karakteristike) {
        if(ev_broj<0) throw std::domain_error("Neispravni parametri");
        Laptop::ev_broj=ev_broj;
        Laptop::naziv=naziv;
        Laptop::karakteristike=karakteristike;
        Laptop::kod_koga_je=nullptr;
    }
    int DajEvidencijskiBroj() const { return ev_broj;}
    std::string DajNaziv() const { return naziv; }
    std::string DajKarakteristike() const { return karakteristike; }
    void Zaduzi (Student &s) {//izuzetak
        kod_koga_je=&s;
    }
    void Razduzi() {
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen () {
        if(kod_koga_je!=nullptr) return true;
        return false;
    }
    Student* &DajKodKogaJe() {
        if(kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen");
        return kod_koga_je;
    }
    Student* DajPokKodKogaJe() {
        return kod_koga_je;
    }
    void Ispisi() {
        std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<std::endl<<"Naziv: "<<DajNaziv()<<std::endl<<"Karakteristike: "<<DajKarakteristike();
    }
};
class Administracija {
    std::map<int,Student*>mapa_studenata;
    std::map<int,Laptop*>mapa_laptopa;
    public:
    Administracija () {}
    ~Administracija() {
        for(auto i(mapa_laptopa.begin()); i!=mapa_laptopa.end(); i++) {
            delete i->second;
        }
        mapa_laptopa.clear();
        for(auto i(mapa_studenata.begin()); i!=mapa_studenata.end(); i++) {
            delete i->second;
        }
        mapa_studenata.clear();
    }
    void RegistrirajNovogStudenta(int index, std::string god_studija, std::string ime_prezime, std::string adresa, std::string br_tel) {
        for(auto i(mapa_studenata.begin()); i!=mapa_studenata.end(); i++) {
            if(index==i->first) throw std::domain_error("Student s tim indeksom vec postoji");
        }
        Student *novi_student=new Student( index,god_studija, ime_prezime, adresa, br_tel);
       mapa_studenata[index]=novi_student;
    }
    void RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike) {
        for(auto i(mapa_laptopa.begin()); i!=mapa_laptopa.end(); i++) {
            if(ev_broj==i->first) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
        }
        Laptop *novi_laptop=new Laptop(ev_broj,naziv,karakteristike);
        mapa_laptopa[ev_broj]=novi_laptop;
    }
    Student &NadjiStudenta(int index) {
        int k(0);
        for(auto i(mapa_studenata.begin()); i!=mapa_studenata.end(); i++) {
            if(index==i->first) k++;
        }
        if(k==0) throw std::domain_error("Student nije nadjen");
        return *mapa_studenata[index];
    }
    Laptop &NadjiLaptop(int ev_broj) {
        int k(0);
        for(auto i(mapa_laptopa.begin()); i!=mapa_laptopa.end(); i++) {
            if(ev_broj==i->first) k++;
        }
        if(k==0) throw std::domain_error("Laptop nije nadjen");
        return *mapa_laptopa[ev_broj];
    }
    void IzlistajStudente() const {
        for(auto it(mapa_studenata.begin()); it!=mapa_studenata.end(); it++) {
            std::cout<<"Broj indeksa: "<<it->first<<std::endl;
            std::cout<<"Godina studija: "<<it->second->DajGodinuStudija()<<std::endl;
            std::cout<<"Ime i prezime: "<<it->second->DajImePrezime()<<std::endl;
            std::cout<<"Adresa: "<<it->second->DajAdresu()<<std::endl;
            std::cout<<"Broj telefona: "<<it->second->DajTelefon()<<std::endl;
        }
    }
    void IzlistajLaptope() const {
        for(auto it(mapa_laptopa.begin()); it!=mapa_laptopa.end(); it++) {
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naziv: "<<it->second->DajNaziv()<<std::endl;
            std::cout<<"Karakteristike: "<<it->second->DajKarakteristike()<<std::endl;
            if(it->second->DaLiJeZaduzen()) std::cout<<"Zaduzio(la): "<<it->second->DajKodKogaJe()->DajImePrezime()<<" ("<<it->second->DajKodKogaJe()->DajIndeks()<<")"<<std::endl;
        }
    }
    void ZaduziLaptop(int index, int ev_broj) {//fali kad je vec zaduzen laptop i kad je student vec neki zaduzio
        int k(0);
        for(auto i(mapa_studenata.begin()); i!=mapa_studenata.end(); i++) {
            if(index==i->first) k++;
        }
        if(k==0) throw std::domain_error("Student nije nadjen");
        int p(0);
        for(auto i(mapa_laptopa.begin()); i!=mapa_laptopa.end(); i++) {
            if(ev_broj==i->first) p++;
        }
        if(p==0) throw std::domain_error("Laptop nije nadjen");
        mapa_laptopa[ev_broj]->Zaduzi(*mapa_studenata[index]);
    }
    int NadjiSlobodanLaptop() {
        for(auto i(mapa_laptopa.begin()); i!=mapa_laptopa.end(); i++) {
            if(!(i->second->DaLiJeZaduzen())) return i->first;
            else throw std::domain_error("Nema slobodnih laptopa");
        }
    }
    void RazduziLaptop(int ev_broj) {
        int k(0);
        for(auto i(mapa_laptopa.begin()); i!=mapa_laptopa.end(); i++) {
            if(ev_broj==i->first) k++;
        }
        if(k==0) throw std::domain_error("Laptop nije nadjen");
        for(auto i(mapa_laptopa.begin()); i!=mapa_laptopa.end(); i++) {
            if(!(i->second->DaLiJeZaduzen())) throw std::domain_error("Laptop nije zaduzen");
        }
        mapa_laptopa[ev_broj]->Razduzi();
    }
    void PrikaziZaduzenja() {//fali ako niko nije zaduzio
        for(auto i(mapa_laptopa.begin()); i!=mapa_laptopa.end(); i++) {
            std::cout<<"Student "<<i->second->DajKodKogaJe()->DajImePrezime()<<" ("<<i->second->DajKodKogaJe()->DajIndeks()<<") zaduzio/la je laptop broj "<<i->first<<std::endl;
        }
    }
    
};
int main ()
{
    Administracija etf;
    std::map<int,Student*>mapa_studenata;
    std::map<int,Laptop*>mapa_laptopa;
    int izbor;
    std::cout<<"Pritisnite 1 za unos  ili 0 za kraj: "<<std::endl;
    std::cin>>izbor;
    do {
        int brojic(0);
         int ev_broj;
         std::string naziv;
         std::string karakteristike;
         std::cout<<"Koliko zelite unijeti laptopa: ";
         std::cin>>brojic;
         for(int i=0; i<brojic;i++) {
            std::cout<<"Unesite evidencijski broj laptopa: "<<std::endl;;
            std::cin>>ev_broj;
            std::cout<<"Unesite naziv laptopa: "<<std::endl;
            std::getline(std::cin,naziv);
            std::cout<<"Unesite karakteristike laptopa: "<<std::endl;
            std::getline(std::cin,karakteristike);
            etf.RegistrirajNoviLaptop(ev_broj,naziv,karakteristike);
         }
        
        int brojic2;
        std::cout<<"Koliko zelite unijeti studenta: ";
        std::cin>>brojic2;
        for(int i=0; i<brojic2; i++) {
            int index;
            std::string god_studija,ime_prezime,adresa,br_tel;
            std::cout<<"Unesite index: "<<std::endl;
            std::cin>>index;
            std::cout<<"Unesite godinu studija: "<<std::endl;
            std::cin.clear();
            std::getline(std::cin,god_studija);
            std::cout<<"Unesite ime i prezime: "<<std::endl;
            std::cin.clear();
            std::getline(std::cin,ime_prezime);
            std::cout<<"Unesite adresu: "<<std::endl;
            std::cin.clear();
            std::getline(std::cin,adresa);
            std::cout<<"Unesite broj telefona: "<<std::endl;
            std::cin.clear();
            std::getline(std::cin,br_tel);
            etf.RegistrirajNovogStudenta(index,god_studija,ime_prezime,adresa,br_tel);
        }
            int index1;
            std::cout<<"Unesite index studenta kojeg zelite pronaci: ";
            std::cin>>index1;
            std::cout<<etf.NadjiStudenta(index1).DajImePrezime();
            etf.IzlistajLaptope();
            etf.IzlistajStudente();
        }while (izbor!=0);
        std::cout<<"Dovidjenja!";
   
    
	return 0;
}
