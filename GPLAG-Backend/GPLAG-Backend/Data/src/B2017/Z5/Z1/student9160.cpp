/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

class Student {
    
    int index;
    std::string godina_studiranja;
    std::string ime_i_prezime;
    std::string adresa;
    std::string broj_telefona;
    void TestGodine(std::string s);
    void UkloniViskaRazmake(std::string &s);
    void TestBroja(std::string s);
    public:
    
    Student(int i,std::string gs, std::string ime, std::string ad, std::string broj);
    int DajIndeks() const { return index; }
    std::string DajGodinuStudija() const { return godina_studiranja; }
    std::string DajAdresu() const { return adresa; }
    std::string DajTelefon() const { return broj_telefona; }
    std::string DajImePrezime() const { return ime_i_prezime; }
    void Ispisi() const;
    
    friend bool operator ==(const Student &s1, const Student &s2){
        return s1.index == s2.index && s1.godina_studiranja == s2.godina_studiranja
                && s1.ime_i_prezime == s2.ime_i_prezime && s1.adresa == s2.adresa &&
                s1.broj_telefona == s2.broj_telefona;
    }
    
};

void Student::TestGodine(std::string s){
    const std::string niz[]{"1","2","3","1/B","2/B","3/B","1/M","2/M","1/D","2/D","3/D"};
    bool ima(false);
    for(int i(0);i<11;i++)
        if(s == niz[i]) { 
            ima = true; break;
        }
    if(!ima)throw std::domain_error("Neispravni parametri");   
}
void Student::UkloniViskaRazmake(std::string &s){
    std::string pom;
    int i(0);
    while(i<s.length()){
        
        //ako ima na pocetku razmaka preskoci ih
        while(s[i]==' ' && i<s.length())i++;
        
        //upisi sve sto nije razmak
        while(s[i]!=' ' && i<s.length()){pom.push_back(s[i]);i++;}
        
        pom.push_back(' ');
        i++;
    }
    s = pom;
    if(s[s.length()-1] == ' ')s = s.substr(0,s.length()-1);
}
void Student::TestBroja(std::string s){
    if(s.length() == 0)throw std::domain_error("Neispravni parametri");
    int i(0);
    while(2){
        while (s[i]>='0' && s[i]<='9' && i<s.length())i++;
        if(s[i] != '/')throw std::domain_error("Neispravni parametri");
        i++;
        while (s[i]>='0' && s[i]<='9' && i<s.length())i++;
        if(s[i]!= '-')throw std::domain_error("Neispravni parametri");
        break;
    }
}
Student::Student(int i,std::string gs, std::string ime, std::string ad, std::string broj){
        if(i>99999 || i<10000)throw std::domain_error("Neispravni parametri");
        index = i;
        TestGodine(gs);
        if(gs == "1" || gs == "2" || gs == "3")
            godina_studiranja = gs + "/B";
        else godina_studiranja = gs;
        
        UkloniViskaRazmake(ime);
        UkloniViskaRazmake(ad);
        
        ime_i_prezime = ime;
        adresa = ad;
        
        TestBroja(broj);
        broj_telefona = broj;
}
void Student::Ispisi() const {
    std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl;
    std::cout<<"Godina studija: "<<DajGodinuStudija()<<std::endl;
    std::cout<<"Ime i prezime: "<<DajImePrezime()<<std::endl;
    std::cout<<"Adresa: "<<DajAdresu()<<std::endl;
    std::cout<<"Telefon: "<<DajTelefon()<<std::endl;
}



class Laptop {
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student *kod_koga_je;
    
    public: 
    
    Laptop(int n, std::string ime, std::string kar);
    int DajEvidencijskiBroj() const { return ev_broj; }
    std::string DajNaziv() const { return naziv; }
    std::string DajKarakteristike() const { return karakteristike; }
    
    void Zaduzi(Student &s){
        if(kod_koga_je != nullptr) throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je = &s;
    }
    void Razduzi(){ kod_koga_je = nullptr; }
    bool DaLiJeZaduzen() const { return kod_koga_je != nullptr; }
    Student &DajKodKogaJe() const {
        if(kod_koga_je == nullptr)
            throw std::domain_error("Laptop nije zaduzen");
        return *kod_koga_je;
    }
    Student *DajPokKodKogaJe(){ return kod_koga_je; }
    void Ispisi() const;
    
};

Laptop::Laptop(int n, std::string ime, std::string kar):naziv(ime),karakteristike(kar),kod_koga_je(nullptr){
    if(n < 0) throw std::domain_error("Neispravni parametri");
    ev_broj = n;
}

void Laptop::Ispisi() const {
    std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<std::endl;
    std::cout<<"Naziv: "<<DajNaziv()<<std::endl;
    std::cout<<"Karakteristike: "<<DajKarakteristike()<<std::endl;
}


class Administracija {
    
    std::map<int,Student*> studenti;
    std::map<int,Laptop*> laptopi;
    
    public:
    
    Administracija(){}//done
    Administracija(const Administracija &admin);//done
    Administracija(Administracija &&admin);//done
    Administracija &operator = (const Administracija &admin);//done
    Administracija &operator = (Administracija &&admin);//done
    ~Administracija();//done
    
    void RegistrirajNovogStudenta(int i,std::string gs, std::string ime, std::string ad, std::string broj);//done
    void RegistrirajNoviLaptop(int n, std::string ime, std::string kar);//done
    Student &NadjiStudenta(int i);//done
    Student NadjiStudenta(int i) const;//done
    Laptop &NadjiLaptop(int i);//done
    Laptop NadjiLaptop(int i) const;//done
    void IzlistajStudente() const;//done
    void IzlistajLaptope() const;//done
    
    void ZaduziLaptop(int i, int ev_b);//done
    int NadjiSlobodniLaptop() const;//done
    void RazduziLaptop(int ev_b);//done
    void PrikaziZaduzenja() const;//done
};
// kopirajuci i pomjerajuci konstruktori
Administracija::Administracija(const Administracija &admin){
    for(auto it(admin.studenti.begin()); it != admin.studenti.end(); it++)
        studenti.insert({it->first, new Student (*(it->second))});
    for(auto it(admin.laptopi.begin()); it != admin.laptopi.end(); it++)
        laptopi.insert({it->first, new Laptop (*(it->second))});
}
Administracija::Administracija(Administracija &&admin){
    std::swap(admin.studenti,studenti);
    std::swap(admin.laptopi,laptopi);
}
// kopirajuci i pomjerajuci operatori dodjele
Administracija &Administracija::operator = (const Administracija &admin){
    // radi sve sta radi destruktor
    for(auto it(studenti.begin()); it != studenti.end(); it++){
        delete it->second; 
        it = studenti.erase(it);
    }
    for(auto it(laptopi.begin()); it != laptopi.end(); it++){
        delete it->second; 
        it = laptopi.erase(it);
    }
    // radi sve sta radi kopirajuci konstruktor
    for(auto it(admin.studenti.begin()); it != admin.studenti.end(); it++)
        studenti.insert({it->first, new Student (*(it->second))});
    for(auto it(admin.laptopi.begin()); it != admin.laptopi.end(); it++)
        laptopi.insert({it->first, new Laptop (*(it->second))});
    return *this;    
}
Administracija &Administracija::operator =(Administracija &&admin){
    std::swap(admin.studenti, studenti);
    std::swap(admin.laptopi,laptopi);
    return *this;
}
// destruktor
Administracija::~Administracija(){
    for(auto it(studenti.begin()); it != studenti.end(); it++){
        delete it->second; 
        it = studenti.erase(it);
    }
    for(auto it(laptopi.begin()); it != laptopi.end(); it++){
        delete it->second; 
        it = laptopi.erase(it);
    }
}

void Administracija::RegistrirajNovogStudenta(int i,std::string gs, std::string ime, std::string ad, std::string broj){
    auto it(studenti.find(i));
    if(it!=studenti.end())throw std::domain_error("Student s tim indeksom vec postoji");
    studenti.insert({i,new Student(i,gs,ime,ad,broj)});
}

void Administracija::RegistrirajNoviLaptop(int n, std::string ime, std::string kar){
    auto it(laptopi.find(n));
    if(it != laptopi.end()) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    laptopi.insert({n,new Laptop(n,ime,kar)});
}

Student &Administracija::NadjiStudenta(int i){
    auto it(studenti.find(i));
    if(it == studenti.end()) throw std::domain_error("Student nije nadjen");
    return *(it->second);
}
Student Administracija::NadjiStudenta(int i) const {
    auto it(studenti.find(i));
    if(it == studenti.end()) throw std::domain_error("Student nije nadjen");
    return *(it->second);
}

Laptop &Administracija::NadjiLaptop(int i){
    auto it(laptopi.find(i));
    if(it == laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    return *(it->second);
}

Laptop Administracija::NadjiLaptop(int i) const {
    auto it(laptopi.find(i));
    if(it == laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    return *(it->second);
}

void Administracija::IzlistajStudente() const {
    for(auto x : studenti){
        x.second->Ispisi();
        std::cout<<std::endl;
    }
}

void Administracija::IzlistajLaptope() const {
    for(auto x : laptopi){
        x.second->Ispisi();
        if(x.second->DaLiJeZaduzen()){
            Student s = *(x.second->DajPokKodKogaJe());
            std::cout<<"Zaduzio(la): "<<s.DajImePrezime()<<"("<<s.DajIndeks()<<")";
        }
        std::cout<<std::endl;
    }
}


void Administracija::ZaduziLaptop(int i, int ev_b){
    auto its(studenti.find(i));
    auto itl(laptopi.find(ev_b));
    if(its == studenti.end()) throw std::domain_error("Student nije nadjen");
    if(itl == laptopi.end())  throw std::domain_error("Laptop nije nadjen");
    if(itl->second->DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
    for(auto it(laptopi.begin()); it != laptopi.end(); it++){
        if(*(it->second->DajPokKodKogaJe()) == *(its->second))
            throw std::domain_error("Student je vec zaduzio laptop");
    }
    itl->second->Zaduzi(*(its->second));
}


int Administracija::NadjiSlobodniLaptop() const{
    for(auto it(laptopi.begin()); it!=laptopi.end(); it++){
        if(it->second->DajPokKodKogaJe() == nullptr)return it->first;
    }
    throw std::domain_error("Nema slobodnih laptopa");
}

void Administracija::RazduziLaptop(int ev_b){
    auto it(laptopi.find(ev_b));
    if(it == laptopi.end()) std::domain_error("Laptop nije nadjen");
    
    if(it->second->DajPokKodKogaJe() == nullptr)
        throw std::domain_error("Laptop nije zaduzen");
    
    delete it->second->DajPokKodKogaJe();
    it->second->Razduzi();
}


void Administracija::PrikaziZaduzenja() const {
    int brojac(0);
    for(auto x : laptopi){
        if(x.second->DaLiJeZaduzen()){
            brojac++;
            Student s = *(x.second->DajPokKodKogaJe());
            std::cout<<"Student "<<s.DajImePrezime()<<"("<<s.DajIndeks()<<")"<<
            "zaduzio/la laptop broj "<<x.first;
        }
    }
    if(brojac == 0) std::cout<<"Nema zaduzenja";
}
/*
int main ()
{   
    Administracija adm;
    while(1){
        std::cout<<"Odaberite opciju: "<<std::endl;
        std::cout<<"1) Registruj studenta"<<std::endl;
        std::cout<<"2) Registruj laptop"<< std::endl;
        std::cout<<"3) Nadji studenta"<<std::endl;
        std::cout<<"4) Nadji laptop"<<std::endl;
        std::cout<<"5) Ispisi studente"<<std::endl;
        std::cout<<"6) Ispisi laptope"<<std::endl;
        std::cout<<"7) Zaduzi laptop"<<std::endl;
        std::cout<<"8) Razduzi laptop"<<std::endl;
        std::cout<<"9) Nadji slobodni laptop"<<std::endl;
        std::cout<<"10) Ispisi zaduzenje"<<std::endl;
        std::cout<<"11) Kraj"<<std::endl;
        int opcija;
        std::cin>>opcija;
        if(opcija == 1){
            
        }else if(opcija == 2){
            
        }else if(opcija == 3){
            
        }else if(opcija == 4){
            
        }else if(opcija == 5){
            
        }else if(opcija == 6){
            
        }else if(opcija == 7){
            
        }else if(opcija == 8){
            
        }else if(opcija == 9){
            
        }else if(opcija == 10){
            
        }else if(opcija == 11){
            std::cout<<"Dovidjenja!";
            return 0;
        }
    }
	return 0;
}*/
int main(){
    
    Administracija etf ;

    etf.RegistrirajNoviLaptop(123, "Dell", "CPU 3.0 GHz, 4 GB RAM");
    etf.RegistrirajNoviLaptop(331, "ASUS", "CPU 3.5 GHz, 2 GB RAM");
    etf.RegistrirajNoviLaptop(122, "Dell 2", "CPU 3.2 GHz, 6 GB RAM");
    etf.RegistrirajNovogStudenta(14212, "1", "Benjamin", "Francuska revolucija 23", "12/34-56");
    etf.RegistrirajNovogStudenta(17528, "2","Ivan", "Trg vjecnih studenata 12", "048/597-585");
    
    etf.ZaduziLaptop(14212, 123);
    etf.ZaduziLaptop(17528, 331);
    
    etf.PrikaziZaduzenja();
    return 0;
}