/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
class Student{
    int br_indeksa;
    std::string god_studija,ime_prezime,adresa,br_telefona;
    public:
    Student(int br_indeksa, std::string god_studija, std::string ime_prezime,std::string adresa,std::string br_telefona);
    int DajIndeks()const{ return br_indeksa;}
    std::string DajGodinuStudija()const{ return god_studija;}
    std::string DajImePrezime() const{return ime_prezime;}
    std::string DajAdresu() const{ return adresa;}
    std::string DajTelefon() const { return br_telefona;}
    void Ispisi() const;
};
Student::Student(int br_indeksa, std::string god_studija, std::string ime_prezime, std::string adresa, std::string br_telefona){
    Student::br_indeksa=br_indeksa;
    Student::god_studija=god_studija;
    Student::ime_prezime=ime_prezime;
    Student::adresa=adresa;
    Student::br_telefona=br_telefona;
}
void Student::Ispisi() const{
    std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl;
    std::cout<<"Godina studija: "<<DajGodinuStudija()<<std::endl;
    std::cout<<"Ime i prezime: "<<DajImePrezime()<<std::endl;
    std::cout<<"Adresa: "<<DajAdresu()<<std::endl;
    std::cout<<"Telefon: "<<DajTelefon()<<std::endl;
}
class Laptop{
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student* kod_koga_je;  
    public:
    Laptop(int ev_broj, std::string naziv, std::string karakteristike);
    int DajEvidencijskiBroj() const{ return ev_broj;}
    std::string DajNaziv() const {return naziv;}
    std::string DajKarakteristike() const {return karakteristike;}
    void Zaduzi(Student &s){
        if(kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je=&s;
    }
    void Razduzi(){kod_koga_je=nullptr;}
    bool DaLiJeZaduzen()const {return kod_koga_je!=nullptr;}
    Student* DajKodKogaJe() const{
        if(kod_koga_je==nullptr)throw std::domain_error("Laptop nije zaduzen");
        return kod_koga_je;
    }
    Student* DajPokKodKogaJe()const {return kod_koga_je;}
    void Ispisi() const;
    
};
Laptop::Laptop(int ev_broj, std::string naziv, std::string karakteristike):kod_koga_je(nullptr){
    if(ev_broj<0) throw std::domain_error("Neispravni parametri");
    Laptop::ev_broj=ev_broj;
    Laptop::naziv=naziv;
    Laptop::karakteristike=karakteristike;
}
void Laptop::Ispisi() const {
    std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<std::endl;
    std::cout<<"Naziv: "<<DajNaziv()<<std::endl;
    std::cout<<"Karakteristike: "<<DajKarakteristike()<<std::endl;
}
class Administracija{
    std::map<int, Student*> studenti;
    std::map<int, Laptop*> laptopi;
    public:
    Administracija(){}
    ~Administracija();
    void RegistrirajNovogStudenta(int br_indeksa, std::string god_studija, std::string ime_prezime, std::string adresa, std::string br_telefona);
    void RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike);
    Student &NadjiStudenta(int br_indeksa);
    Laptop &NadjiLaptop(int ev_broj);
    void IzlistajStudente() const;
    void IzlistajLaptope() const;
    void ZaduziLaptop(int br_indeksa, int ev_broj);
    int NadjiSlobodanLaptop();
    void RazduziLaptop(int ev_broj);
    void PrikaziZaduzenja();
};
Administracija:: ~Administracija(){
    for(auto it1=studenti.begin(); it1!=studenti.end(); it1++) delete it1->second;
    for(auto it2=laptopi.begin(); it2!=laptopi.end(); it2++) delete it2->second;
}
void Administracija::RegistrirajNovogStudenta(int br_indeksa, std::string god_studija, std::string ime_prezime, std::string adresa, std::string br_telefona){
    auto it(studenti.find(br_indeksa));
    if(it!=studenti.end()) throw std::domain_error("Student s tim indeksom vec postoji");
    try{
    Student *s = new Student(br_indeksa, god_studija, ime_prezime, adresa, br_telefona);
    studenti.insert({s->DajIndeks(), s});
    }catch(...){
        throw;
    }
}
void Administracija::RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike){
    auto it(laptopi.find(ev_broj));
    if(it!=laptopi.end()) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    try{
    Laptop *l = new Laptop(ev_broj, naziv, karakteristike);
    laptopi.insert({l->DajEvidencijskiBroj(), l});
    }catch(...){
        throw;
    }
}
Student &Administracija::NadjiStudenta(int br_indeksa){
    auto it(studenti.find(br_indeksa));
    if(it==studenti.end()) throw std::domain_error("Student nije nadjen");
    return *it->second;
}
Laptop &Administracija::NadjiLaptop(int ev_broj){
    auto it(laptopi.find(ev_broj));
    if(it==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    return *it->second;
}
void Administracija::IzlistajStudente() const{
    for(auto it=studenti.begin(); it!=studenti.end(); it++){
    std::cout<<"Broj indeksa: "<<it->first<<std::endl;
    std::cout<<"Godina studija: "<<(it->second)->DajGodinuStudija()<<std::endl;
    std::cout<<"Ime i prezime: "<<(it->second)->DajImePrezime()<<std::endl;
    std::cout<<"Adresa: "<<(it->second)->DajAdresu()<<std::endl;
    std::cout<<"Telefon: "<<(it->second)->DajTelefon()<<std::endl;
    std::cout<<std::endl;
    }
}
void Administracija::IzlistajLaptope() const{
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++){
    std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
    std::cout<<"Naziv: "<<(it->second)->DajNaziv()<<std::endl;
    std::cout<<"Karakteristike: "<<(it->second)->DajKarakteristike()<<std::endl;
    if((it->second)->DaLiJeZaduzen()){
        std::cout<<"Zaduzio(la): "<<(it->second)->DajKodKogaJe()<<" ("<<((it->second)->DajPokKodKogaJe())->DajIndeks()<<")";
    }
    std::cout<<std::endl;
    }
}
void Administracija::ZaduziLaptop(int br_indeksa, int ev_broj){
    auto it1=studenti.find(br_indeksa);
    if(it1==studenti.end()) throw std::domain_error("Student nije nadjen");
    auto it2=laptopi.find(ev_broj);
    if(it2==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    if((it2->second)->DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
    if((it2->second)->DajKodKogaJe()!=nullptr) throw std::domain_error("Student je vec zaduzio laptop");
    //
}
int Administracija::NadjiSlobodanLaptop(){
    auto it(laptopi.begin());
    for(it=laptopi.begin(); it!=laptopi.end(); it++){
        if((it->second)->DajKodKogaJe()==nullptr) return (it->second)->DajEvidencijskiBroj();
    }
    if(it==laptopi.end()) throw std::domain_error("Nema slobodnih laptopa");
}
void Administracija::RazduziLaptop(int ev_broj){
    
}
void Administracija::PrikaziZaduzenja(){
    int brojac(0);
    auto it2(laptopi.begin());
    for(it2=laptopi.begin(); it2!=laptopi.end(); it2++){
        if((it2->second)->DaLiJeZaduzen()){
            std::cout<<"Student "<<((it2->second)->DajPokKodKogaJe())->DajImePrezime()<<"("<<((it2->second)->DajPokKodKogaJe())->DajIndeks()<<") zaduzio/la laptop broj "<<it2->first<<std::endl;
        }
    }
    if(it2==laptopi.end()) std::cout<<"Nema zaduzenja";
}
int main ()
{
	return 0;
}
