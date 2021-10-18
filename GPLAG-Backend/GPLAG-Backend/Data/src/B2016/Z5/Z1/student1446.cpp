#include <iostream>
#include <stdexcept>
#include <string>
#include <new>
#include <vector>
#include <memory>
#include <algorithm>
class Student{
    int br_indexa;
    int god_studija;
    char ime_i_prezime[50];
    char adresa [50];
    char br_telefona [15];
    public:
    Student (int br, int god, const char ime[50], const char adr[50], const char telefon[15]);
    int DajIndeks () const {return br_indexa;}
    int DajGodinuStudija () const {return god_studija;}
    std::string DajImePrezime () const;
    std::string DajAdresu () const;
    std::string DajTelefon () const;
    void Ispisi ();
};
Student::Student(int br, int god, const char ime[50], const char adr[50], const char telefon[15]){
    if(br>99999 || br<10000 || god<1 || god>8 )throw std::domain_error ("Neispravni parametri");
    int a(0),c(0),b(0);
    for(int i=0; i<10; i++){
        if(telefon[i]=='/')a++;
        if(telefon[i]=='-')b++;
        if(telefon[i]>='0' && telefon[i]<='9')c++;
    }
    if(a!=1 || b!=1 || c<3){
            throw std::domain_error ("Neispravni parametri");
        } 
    br_indexa=br;
    god_studija=god;
    int i=0;
    while(ime[i]!='\0'){
        ime_i_prezime[i]=ime[i];
        i++;
    }
    ime_i_prezime[i]='\0';
    i=0;
    while(adr[i]!='\0'){
        Student::adresa[i]=adr[i];
        i++;
    }
    adresa[i]='\0';
    i=0;
    while(telefon[i]!='\0'){
        br_telefona[i]=telefon[i];
        i++;
    }
    br_telefona[i]='\0';
}
    std::string Student::DajImePrezime () const{
    std::string a;
        int i=0;
        while(ime_i_prezime[i]!='\0'){
            a.push_back(ime_i_prezime[i]);
            i++;
        }
    return a;
}
    std::string Student::DajAdresu () const{
    std::string a;
    int i=0;
        while(adresa[i]!='\0'){
            a.push_back(adresa[i]);
            i++;
        }
    return a;
}
    std::string Student::DajTelefon () const{
    std::string a;
    int i=0;
        while(br_telefona[i]!='\0'){
            a.push_back(br_telefona[i]);
            i++;
        }
    return a;
}
    void Student::Ispisi (){
    std::cout<<"Broj indeksa: " << this->DajIndeks() << std::endl;
    if(this->DajGodinuStudija()<=3) std::cout << "Godina studija: " << this->DajGodinuStudija() <<"/I" << std::endl;
    if(this->DajGodinuStudija()<=5 && this->DajGodinuStudija()>3) std::cout << "Godina studija: " << this->DajGodinuStudija()-3 <<"/II" << std::endl;
    if(this->DajGodinuStudija()>5) std::cout << "Godina studija: " << this->DajGodinuStudija()-5 <<"/III" << std::endl;
    std::cout<<"Ime i prezime: " << this->DajImePrezime() <<std::endl;
    std::cout<<"Adresa: " << this->DajAdresu() <<std::endl;
    std::cout<<"Telefon: " << this->DajTelefon() <<std::endl;
}
class Laptop{
    int evid_br;
    char ime_laptopa [20];
    char karakteristike [50];
    bool zaduzen=false;
    Student* pok_kod_kog_je=nullptr;
    public:
    Laptop (int br, const char ime[20], const char kar[50]);
    int DajEvidencijskiBroj ()const {return evid_br;}
    std::string DajNaziv ()const;
    std::string DajKarakteristike() const;
    void Zaduzi(Student &student);
    void Razduzi ();
    bool DaLiJeZaduzen ()const;
    Student &KodKogaJe();
    void Ispisi() const;
};
    Laptop ::Laptop (int br, const char ime[20], const char kar[50]){
        if(br<0)throw std::domain_error ("Neispravni parametri");
        evid_br=br;
        int i=0;
        while(ime[i]!='\0'){
            ime_laptopa[i]=ime[i];
            i++;
        }
        ime_laptopa[i]='\0';
        i=0;
        while(kar[i]!='\0'){
            karakteristike[i]=kar[i];
            i++;
        }
        karakteristike[i]='\0';
    }
    std::string Laptop::DajNaziv()const{
        std::string a;
        int i=0;
        while(this->ime_laptopa[i]!='\0'){
            a.push_back(ime_laptopa[i]);
            i++;
        }
        return a;
    }
    std::string Laptop::DajKarakteristike() const{
        std::string a;
        int i=0;
        while(this->karakteristike[i]!='\0'){
            a.push_back(karakteristike[i]);
            i++;
        }
        return a;
    }
    void Laptop::Zaduzi(Student &student){
        if(zaduzen==true)throw std::domain_error ("Laptop vec zaduzen");
        zaduzen=true;
        pok_kod_kog_je=&student;
    }
    void Laptop::Razduzi (){
        if(zaduzen){
            zaduzen=false;
            pok_kod_kog_je=nullptr;
        }
    }
    bool Laptop::DaLiJeZaduzen() const{
        if(zaduzen)return true;
        return false;
    }
    Student &Laptop::KodKogaJe(){
        if(zaduzen==false)throw std::domain_error ("Laptop nije zaduzen");
        return *pok_kod_kog_je;
    }
    void Laptop::Ispisi() const{
        std::cout << "Evidencijski broj: "<< this->DajEvidencijskiBroj() << std::endl;
        std::cout << "Naziv: "<< this->DajNaziv() << std::endl;
        std::cout << "Karakteristike: "<< this->DajKarakteristike() << std::endl;
    }
class Administracija{
    std::vector<std::shared_ptr<Student>>studenti;
    std::vector<std::shared_ptr<Laptop>>laptopi;
    public:
    Administracija(){};
    Administracija(Administracija &a)=delete;
    Administracija(Administracija &&a);
    Administracija operator =(Administracija a)=delete;
    void RegistrirajNovogStudenta(int br, int god, const char ime[50], const char adr[50], const char telefon[15]);
    void RegistrirajNoviLaptop(int br, const char ime[20], const char kar[50]);
    Student &NadjiStudenta(int br)const;
    Student NadjiStudenta(int br);
    Laptop &NadjiLaptop(int br)const;
    Laptop NadjiLaptop(int br);
    void IzlistajStudente ();
    void IzlistajLaptope();
    void ZaduziLaptop(int bri, int evbr);
    int NadjiSlobodanLaptop ();
    void RazduziLaptop(int br);
    void PrikaziZaduzenja()const;
};   
    Administracija::Administracija(Administracija &&a){
        studenti=a.studenti;
        laptopi=a.laptopi;
    }
    void Administracija::RegistrirajNovogStudenta(int br, int god, const char ime[50], const char adr[50], const char telefon[15]){
        for(int i=0;i<studenti.size();i++){
            if((*studenti[i]).DajIndeks()==br)throw std::domain_error ("Student s tim indeksom vec postoji");
        }
        std::shared_ptr<Student> p(std::make_shared<Student>(br,god,ime,adr,telefon));
        studenti.push_back(p);
    }
    void Administracija::RegistrirajNoviLaptop(int br, const char ime[20], const char kar[50]){
        for(int i=0; i<laptopi.size();i++){
            if((*laptopi[i]).DajEvidencijskiBroj()==br)throw std::domain_error ("Laptop s tim evidencijskim brojem vec postoji");
        }
        std::shared_ptr<Laptop> p(new Laptop(br,ime,kar));
        laptopi.push_back(p);
    }
    Student &Administracija::NadjiStudenta(int br)const{
        for(int i=0; i<studenti.size();i++){
            if((*studenti[i]).DajIndeks()==br)
                return *studenti[i];
        }
        throw std::domain_error ("Student nije nadjen");
    }
    Student Administracija::NadjiStudenta(int br){
        for(int i=0; i<studenti.size();i++){
            if((*studenti[i]).DajIndeks()==br)
                return *studenti[i];
        }
        throw std::domain_error ("Student nije nadjen");
    }
    Laptop &Administracija::NadjiLaptop(int br)const{
        for(int i=0;i<laptopi.size();i++){
            if((*laptopi[i]).DajEvidencijskiBroj()==br)
                return *laptopi[i];
        }
        throw std::domain_error ("Laptop nije nadjen");
    }
    Laptop Administracija::NadjiLaptop(int br){
        for(int i=0;i<laptopi.size();i++){
            if((*laptopi[i]).DajEvidencijskiBroj()==br)
                return *laptopi[i];
        }
        throw std::domain_error ("Laptop nije nadjen");
    }
    void Administracija::IzlistajStudente (){
        for(int i=0;i<studenti.size();i++){
            (*studenti[i]).Ispisi();
            std::cout << std::endl;
        }
    }
    void Administracija::IzlistajLaptope(){
        for(int i=0;i<laptopi.size();i++){
            (*laptopi[i]).Ispisi();
            if((*laptopi[i]).DaLiJeZaduzen())
                std::cout << "Zaduzio(la): "<< (*laptopi[i]).KodKogaJe().DajImePrezime()<<" ("<< (*laptopi[i]).KodKogaJe().DajIndeks()<<")" << std::endl;
            std::cout << std::endl;    
        }
    }
    void Administracija::ZaduziLaptop(int bri, int evbr){
        int i,j;
        for(i=0; i<studenti.size(); i++){
            if((*studenti[i]).DajIndeks()==bri)break;
        }
        if(i==studenti.size())throw std::domain_error ("Student nije nadjen");
        for(j=0; j<laptopi.size();j++){
            if((*laptopi[i]).DajEvidencijskiBroj()==evbr)break;
        }
        if(j==laptopi.size())throw std::domain_error ("Laptop nije nadjen");
        if((*laptopi[j]).DaLiJeZaduzen())throw std::domain_error ("Laptop vec zaduzen");
        for(int k=0; k<laptopi.size();k++){
            if((*laptopi[k]).DaLiJeZaduzen()){
                if((*laptopi[k]).KodKogaJe().DajIndeks()==bri)throw std::domain_error ("Student je vec zaduzio laptop");
            }    
        }
        (*laptopi[j]).Zaduzi(*studenti[i]);
    }
    int Administracija::NadjiSlobodanLaptop (){
        int i;
        for( i=0;i<laptopi.size();i++){
            if((*laptopi[i]).DaLiJeZaduzen()==false)
                return (*laptopi[i]).DajEvidencijskiBroj();
        }
        if(i==laptopi.size())throw std::domain_error ("Nema slobodnih laptopa");
        return 102030;
    }
    void Administracija::RazduziLaptop(int br){
        int i;
        for( i=0; i<laptopi.size();i++){
            if((*laptopi[i]).DajEvidencijskiBroj()==br){
                if((*laptopi[i]).DaLiJeZaduzen()){
                    (*laptopi[i]).Razduzi();
                    break;
                }
                throw std::domain_error ("Laptop nije zaduzen");
            }
        }
        if(i==laptopi.size())throw std::domain_error ("Laptop nije nadjen");
    }
    void Administracija::PrikaziZaduzenja()const{
        int i;
        for(i=0;i<laptopi.size();i++){
            if((*laptopi[i]).DaLiJeZaduzen())
            std::cout << "Student "<<(*laptopi[i]).KodKogaJe().DajImePrezime()<<" ("<<(*laptopi[i]).KodKogaJe().DajIndeks()<<") zaduzi/la laptop broj "<<(*laptopi[i]).DajEvidencijskiBroj() << std::endl;
        }
        if(i==laptopi.size())throw std::domain_error ("Nema zaduzenja");
    }
int main() {
    Administracija administracija;
    bool lj(false);
    while(lj==false){
        std::cout << "Odaberite koju opciju zelite: " <<std::endl;
        std::cout <<"1:Registracija novog studenta";
        std::cout <<"   2:Registracija novog laptopa";
        std::cout <<"   3:Pronalazak studenta ";
        std::cout <<"   4:Pronalazak laptopa "  << std::endl;
        std::cout <<"5:Izlistavanje studenata";
        std::cout <<"   6:Izlistavanje laptopa";
        std::cout <<"   7:Zaduzivanje laptopa";
        std::cout <<"   8:Pronalazak prvog slobodnog laptopa"  << std::endl;
        std::cout <<"9:Razduzivanje laptopa";
        std::cout <<"   10:Prikazivanje zaduzenja";
        std::cout <<"   0 ili 11 za kraj programa"  << std::endl;
        int x;
        std::cin >> x;
        switch(x%11){
            case 1:
                try{
                    std::cout << "Unesite broj indeksa: " << std::endl;
                    int a;
                    std::cin >> a;
                    std::cout << "Unesite godinu studija" << std::endl;
                    int s;
                    std::cin >> s;
                    std::cout << "Unesite ime i prezime studenta: " << std::endl;
                    char ime[50];
                    std::cin.ignore(1000,'\n');
                    std::cin.getline(ime,50);
                    std::cout << "Unesite adresa studenta: " << std::endl;
                    char adr[50];
                    std::cin.getline(adr,50);
                    std::cout << "Unesite broj telefona studenta: " << std::endl;
                    char tel[15];
                    std::cin.getline(tel,15);
                    administracija.RegistrirajNovogStudenta(a,s,ime,adr,tel);
                    std::cout << "Uspjesno ste registrovali novog studenta" << std::endl;
                }
                catch(std:: domain_error greska){
                    std::cout << greska.what() << std::endl;
                }
            break;
            case 2:
                try{
                    std::cout << "Unesite Evidencijski broj laptopa: " << std::endl;
                    int q;
                    std::cin >> q;
                    std::cout << "Unesite ime laptopa: " << std::endl;
                    char imee[20];
                    std::cin.ignore(1000,'\n');
                    std::cin.getline(imee,20);
                    std::cout << "Unesite karakteristike laptopa: " << std::endl;
                    char kar[50];
                    std::cin.getline(kar,50);
                    administracija.RegistrirajNoviLaptop(q,imee,kar);
                    std::cout << "Uspjesno ste registrovali novi laptop" << std::endl;
                }
                catch(std:: domain_error greska){
                    std::cout << greska.what() << std::endl;
                }
            break;
            case 3:
                std::cout << "Unesite broj indeksa studenta kojeg zelite pronaci: " << std::endl;
                int w;
                std::cin >> w;
                
                try{
                    std::cout << administracija.NadjiStudenta(w).DajImePrezime() << std::endl;
                }
                catch(std:: domain_error greska){
                    std::cout << greska.what() << std::endl;
                }
            break;
            case 4:
                try{
                    std::cout << "Unesite evidencijski broj laptopa kojeg zelite pronaci: " << std::endl;
                    int r;
                    std::cin >> r;
                    std::cout << administracija.NadjiLaptop(r).DajNaziv() << std::endl;
                }
                catch(std:: domain_error greska){
                    std::cout << greska.what() << std::endl;
                }
            break;
            case 5:
                try{
                    administracija.IzlistajStudente();
                }
                catch(std:: domain_error greska){
                    std::cout << greska.what() << std::endl;
                }
            break;
            case 6:
                try{
                    administracija.IzlistajLaptope();
                }
                catch(std:: domain_error greska){
                    std::cout << greska.what() << std::endl;
                }
            break;
            case 7:
                try{
                    std::cout << "Unesite broj indeksa: " << std::endl;
                    int z;
                    std::cin >> z;
                    std::cout << "Unesite evidencijski broj laptopa: " << std::endl;
                    int o;
                    std::cin >> o;
                    administracija.ZaduziLaptop(z,o);
                }
                catch(std:: domain_error greska){
                    std::cout << greska.what() << std::endl;
                }
            break;
            case 8:
                try{
                    std::cout << "Prvi slobodni laptop ima evidencijski broj:  "<<administracija.NadjiSlobodanLaptop() << std::endl;
                }
                catch(std:: domain_error greska){
                    std::cout << greska.what() << std::endl;
                }
            break;
            case 9:
                try{
                    std::cout << "Unesite evidencijski broj laptopa kojeg zelite razduziti: " << std::endl;
                    int p;
                    std::cin >> p;
                    administracija.RazduziLaptop(p);
                }
                catch(std:: domain_error greska){
                    std::cout << greska.what() << std::endl;
                }
            break;
            case 10:
                try{
                    administracija.PrikaziZaduzenja();
                }
                catch(std:: domain_error greska){
                    std::cout << greska.what() << std::endl;
                }
            break;
            default: 
                lj=true;
                break;
        }
    }
    return 0;
}

