/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

class Student {
    int indeks;
    std::string godina_studija, ime, adresa, broj_telefona;
    bool TestirajIndeks(int x);
    bool TestirajGodinu(std::string &s);
    std::string StringBezRazmaka(std::string);
    bool TestirajTelefon(std::string s);
    std::string Prilagodi(std::string s);
    Student(){};
    public:
    Student(int in, std::string god, std::string i, std::string ad, std::string tel) :
    indeks(in), ime(i), adresa(ad), broj_telefona(tel), godina_studija(god) {
        if(godina_studija=="1") godina_studija="1/B"; 
        else if(godina_studija=="2") godina_studija="2/B";
        //if(!TestirajIndeks(indeks) || !TestirajGodinu(godina_studija)) throw std::domain_error("Neispravni parametri");ime
       //auto pom=StringBezRazmaka(ime);
       //std::cout << pom << std::endl;
    }
    int DajIndeks() { return indeks; }
    std::string DajGodinuStudija() { return godina_studija; }
    std::string DajImePrezime() { return ime; }
    std::string DajAdresu() { return adresa; }
    std::string DajTelefon() { return broj_telefona; }
    void Ispisi();
    friend class Administracija;
    friend class Laptop;
};

std::string Student::Prilagodi(std::string s) {
    std::string povratni;
    if(s=="1") return("1/B");
    else if(s=="2") return("2/B");
   // return povratni;
} 

bool Student::TestirajIndeks(int x) {
        int broj(0);
        while(x>0) {
            x/=10;
            broj++;
        }
        if(broj!=5) return false;
        return true;
}

bool Student::TestirajGodinu(std::string &s) {
    if(s.length()!=1 || s.length()!=3) return false;
    if(s.length()==1) {
        if(s=="1") s="1/B"; 
        else if(s=="2") s="2/B";
        else if(s=="3") s="3/B";
        else return false;
    }
    else if(s.length()==3) {
        if(s[0]!='1' || s[0]!='2' || s[0]!='3') return false; 
        else if(s[1]!='/') return false; 
        else if(s[2]!='B' || s[2]!='M' || s[2]!='D') return false; 
    }
    return true;
}

std::string Student::StringBezRazmaka(std::string s) {
    std::string povratni;
    int brojac(0);
    for(int i=0; i<s.length(); i++) {
        while(s[i]==' ' && i<s.length()) i++;
        //broj_rijeci++;
        while (s[i]!=' ') {
             povratni[brojac++]=s[i++];
        }
        if(i!=s.length()-1) povratni[brojac++]=' ';
    }
    return povratni;
}

bool JeLiBroj(char c) {
    return(c>='0' && c<='9');
}

bool Student::TestirajTelefon(std::string s) {
   // bool ispravno=true;
    int broj_rijeci(0);
    for(int i=0; i<s.length(); i++) {
        if(!JeLiBroj(s[0])) return false;
        while(JeLiBroj(s[i])) i++;
        broj_rijeci++;
        i++;
        if(s[i]!='/' && broj_rijeci==1) return false;
        i++;
        while (JeLiBroj(s[i])) i++;
        i++;
        broj_rijeci++;
        if(s[i]!='-' && broj_rijeci==2) return false;
    }
    return true;
}

void Student::Ispisi() {
    std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl;
    std::cout<<"Godina studija: "<<DajGodinuStudija()<<std::endl;
    std::cout<<"Ime i prezime: "<<DajImePrezime()<<std::endl;
    std::cout << "Adresa: "<<DajAdresu()<<std::endl;
    std::cout <<"Telefon: "<<DajTelefon()<< std::endl;
}

class Laptop {
    int ev_broj;
    std::string naziv, karakteristike;
    Student* kod_koga_je;
    Laptop(){
        kod_koga_je=nullptr; 
    }
    public:
    Laptop(int broj, std::string ime, std::string karakteristike) : ev_broj(broj), naziv(ime), karakteristike(karakteristike), kod_koga_je(nullptr) {
        if(ev_broj<=0) throw std::domain_error("Neispravni parametri");
    }
    int DajEvidencijskiBroj() { return ev_broj; }
    std::string DajNaziv() { return naziv; }
    std::string DajKarakteristike() { return karakteristike; }
    void Zaduzi(Student &s) { 
        if(kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je=&s; 
    }
    void Razduzi() {
        if(!kod_koga_je) return;
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen() { return kod_koga_je!=nullptr; }
    Student &DajKodKogaJe() { 
        if(!kod_koga_je) throw std::domain_error("Laptop nije zaduzen");
        return *kod_koga_je;
        }
    Student *DajPokKodKogaJe() {
        return kod_koga_je;
    }
   void Ispisi() {
       std::cout << "Evidencijski broj: " <<DajEvidencijskiBroj()<< std::endl;
       std::cout << "Naziv: " <<DajNaziv()<< std::endl;
       std::cout << "Karakteristike: "<<DajKarakteristike() << std::endl;
   }
   friend class Administracija;
};

class Administracija {
    std::map<int, Student*> studenti;
    std::map<int, Laptop*> laptopi;
    public:
    Administracija(){};
    Administracija(const Administracija &a);
    Administracija(Administracija &&a);
    Administracija& operator=(const Administracija &a);
    Administracija& operator=(Administracija &&a);
    ~Administracija();
    void RegistrirajNovogStudenta(int in, std::string god, std::string i, std::string ad, std::string tel);
    void RegistrirajNoviLaptop(int broj, std::string ime, std::string karakteristike);
    Student &NadjiStudenta(int indeks);
    Laptop &NadjiLaptop(int broj);
    void IzlistajStudente();
    void IzlistajLaptope();
    void ZaduziLaptop(int indeks, int broj);
    int NadjiSlobodniLaptop();
    void RazduziLaptop(int broj);
    void PrikaziZaduzenja();
};

Administracija::Administracija(const Administracija &a) {
    for(auto it=a.studenti.begin(); it!=a.studenti.end(); it++) {
        studenti[it->first]=new Student(*it->second); 
    }
    for(auto it=a.laptopi.begin(); it!=a.laptopi.end(); it++ ) {
        laptopi[it->first]=new Laptop(*it->second);
    }
}

Administracija::Administracija(Administracija &&a) {
    for(auto it=a.studenti.begin(); it!=a.studenti.end(); it++) {
        studenti[it->first]=it->second;
        it->second=nullptr;
    }
    for(auto it=a.laptopi.begin(); it!=a.laptopi.end(); it++) {
        laptopi[it->first]=it->second;
        it->second=nullptr;
    }
}

Administracija& Administracija::operator=(const Administracija &a) {
    if(&a!=this) {
        
    }
    return *this;
}

Administracija& Administracija::operator=(Administracija &&a) {
    std::swap(studenti, a.studenti);
    std::swap(laptopi, a.laptopi);
    return *this;
}

Administracija::~Administracija() {
    for(auto it=studenti.begin(); it!=studenti.end(); it++) {
        if(it->second) delete it->second;
    }
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
        if(it->second) delete it->second;
    }
}

void Administracija::RegistrirajNovogStudenta(int in, std::string god, std::string i, std::string ad, std::string tel) {
    if(studenti.count(in)) throw std::domain_error("Student sa tim indeksom vec postoji");
    studenti[in]=new Student;
    studenti[in]->ime=i;
    studenti[in]->adresa=ad;
    studenti[in]->broj_telefona=tel;
}
void Administracija::RegistrirajNoviLaptop(int broj, std::string ime, std::string karakteristike) {
    if(laptopi.count(broj)) throw std::domain_error("Laptop sa tim evidencijskim brojem vec postoji");
    laptopi[broj]=new Laptop;
    laptopi[broj]->naziv=ime;
    laptopi[broj]->karakteristike=karakteristike;
}

Student &Administracija::NadjiStudenta(int indeks) {
    if(!studenti.count(indeks)) throw std::domain_error("Student nije nadjen");
    return *studenti[indeks];
}
Laptop &Administracija::NadjiLaptop(int broj) {
    if(laptopi.find(broj)==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    return *laptopi[broj];
}
void Administracija::IzlistajStudente() {
    for(auto it=studenti.begin(); it!=studenti.end(); it++) {
    std::cout<<"\nBroj indeksa: "<<it->first<<std::endl;
    std::cout<<"Godina studija: "<<it->second->DajGodinuStudija()<<std::endl;
    std::cout<<"Ime i prezime: "<<it->second->DajImePrezime()<<std::endl;
    std::cout << "Adresa: "<<it->second->DajAdresu()<<std::endl;
    std::cout <<"Telefon: "<<it->second->DajTelefon()<< std::endl;
    }
}
void Administracija::IzlistajLaptope() {
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
        std::cout << "\nEvidencijski broj: " <<it->first<< std::endl;
        std::cout << "Naziv: " <<it->second->DajNaziv()<< std::endl;
        std::cout << "Karakteristike: "<<it->second->DajKarakteristike() << std::endl;
        if(it->second->DaLiJeZaduzen()) {
            std::cout<<"Zaduzio(la): "<<it->second->DajPokKodKogaJe()->ime<<" ("<<it->second->DajPokKodKogaJe()->indeks<<")";
        }
    }
}
void Administracija::ZaduziLaptop(int indeks, int broj) {
    NadjiStudenta(indeks);
    NadjiLaptop(broj);
    if(NadjiLaptop(broj).DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
      /*  if(it->second->DaLiJeZaduzen()) {
            if (it->second->DajKodKogaJe().DajIndeks()==indeks) throw std::domain_error)"Student je vec zaduzio laptop";
        }*/
    }
    NadjiLaptop(broj).Zaduzi(NadjiStudenta(indeks));
}

int Administracija::NadjiSlobodniLaptop() {
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
        if(!it->second->DaLiJeZaduzen()) return it->second->DajEvidencijskiBroj();
    }
     throw std::domain_error("Nema slobodnih laptopa");
}

void Administracija::RazduziLaptop(int broj) {
    NadjiLaptop(broj);
    if(!NadjiLaptop(broj).DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen");
    NadjiLaptop(broj).kod_koga_je=nullptr;
}

void Administracija::PrikaziZaduzenja() {
    bool pronadjeno(false);
    
}

int main ()
{
    try {
    Student s1(17833, "1", "Nadira", "Aleja lipa 44", "062/1-2" );
    s1.Ispisi();
    }
    catch(std::exception &ex) {
        std::cout<<ex.what();
    }
	return 0;
}
