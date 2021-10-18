/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <memory>                           //  ZADATAK KOPIRAN SA PRETHODNOG
#include <algorithm>                        //  I PREPRAVLJEN
using std::shared_ptr;
using std::map;
using std::string;
using std::cout;
using std::cin;
using std::find;

void IzbaciRazmake(string &s){
    if(s.length()==1 && s[0]==' ') s="";
    if(s.length()<=1) return;
    int i(0);
    while(s[i]==' ') s.erase(s.begin());
    for(i=1;i<s.length();i++) if(s[i]==' ' && s[i-1]==' ') s.erase(s.begin()+i--);
    if(s[s.length()-1]==' ') s.erase(s.end()-1);
}

class Student{
    int br_indexa;
    string god_studija,ime_i_prezime,adresa,br_tel;
    public:
    Student(int br_indexa,string god_studija,string ime_i_prezime,string adresa,string br_tel);
    int DajIndeks() const{ return br_indexa; }
    string DajGodinuStudija() const{ return god_studija; }
    string DajImePrezime() const{ return ime_i_prezime; }
    string DajAdresu() const{ return adresa; }
    string DajTelefon() const{ return br_tel; }
    void Ispisi() const;
    
};
Student::Student(int br_indexa,string god_studija,string ime_i_prezime,string adresa,string br_tel){
    int i(0);
    if(br_indexa<10000 || br_indexa>=100000) throw std::domain_error("Neispravni parametri");
    string niz[]{"1","2","3","1/B","2/B","3/B","1/M","2/M","1/D","2/D","3/D"};
    for(i=0;i<11;i++) if(niz[i]==god_studija) break;
    if(niz[i]!=god_studija) throw std::domain_error("Neispravni parametri");
    if(i==0 || i==1 || i==2) i+=3; god_studija=niz[i];
    IzbaciRazmake(ime_i_prezime);
    IzbaciRazmake(adresa);
    if(br_tel.length()<5) throw std::domain_error("Neispravni parametri");
    bool I1(true),I2(false),I3(false);
    for(int j(0);j<br_tel.length();j++){
        if(I1){
            if(br_tel[j]>='0' && br_tel[j]<='9' && br_tel.length()-j>4);
            else if(j>0 && br_tel[j]=='/' && br_tel.length()-j>3){
                I1=false; I2=true;
            }
            else throw std::domain_error("Neispravni parametri");
        }
        else if(I2){
            if(br_tel[j]>='0' && br_tel[j]<='9' && br_tel.length()-j>2);
            else if(br_tel[j]=='-' && br_tel[j-1]>='0' && br_tel[j-1]<='9' && br_tel.length()-j>1){
                I2=false; I3=true;
            }
            else throw std::domain_error("Neispravni parametri");
        }
        else if(I3){
            if(br_tel[j]>='0' && br_tel[j]<='9');
            else throw std::domain_error("Neispravni parametri");
        }
    }
    Student::br_indexa=br_indexa; Student::god_studija=god_studija;
    Student::ime_i_prezime=ime_i_prezime; Student::adresa=adresa;
    Student::br_tel=br_tel;
}
void Student::Ispisi() const{
    cout<<"Broj indeksa: "<<br_indexa<<std::endl;
    cout<<"Godina studija: "<<god_studija<<std::endl;
    cout<<"Ime i prezime: "<<ime_i_prezime<<std::endl;
    cout<<"Adresa: "<<adresa<<std::endl;
    cout<<"Telefon: "<<br_tel<<std::endl;
}

class Laptop{
    int ev_broj;
    string naziv;
    string karakteristike;
    Student *kod_koga_je;
    public:
    Laptop(int ev_broj,string naziv,string karakteristike,Student *kod_koga_je);
    int DajEvidencijskiBroj() const{ return ev_broj; }
    string DajNaziv() const{ return naziv; }
    string DajKarakteristike() const{ return karakteristike; }
    void Zaduzi(Student &s);
    void Razduzi();
    bool DaLiJeZaduzen() const;
    Student &DajKodKogaJe();
    Student *DajPokKodKogaJe();
    void Ispisi() const;
};
Laptop::Laptop(int ev_broj,string naziv,string karakteristike,Student *kod_koga_je=nullptr){
    if(ev_broj<0) throw std::domain_error("Neispravni parametri");
    Laptop::ev_broj=ev_broj; Laptop::naziv=naziv;
    Laptop::karakteristike=karakteristike; Laptop::kod_koga_je=kod_koga_je;
}
void Laptop::Zaduzi(Student &s){
    if(kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
    kod_koga_je=&s;
}
void Laptop::Razduzi(){ kod_koga_je=nullptr; }
bool Laptop::DaLiJeZaduzen() const{ return kod_koga_je; }
Student &Laptop::DajKodKogaJe(){
    if(kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen");
    return *kod_koga_je;
}
Student *Laptop::DajPokKodKogaJe(){ return kod_koga_je; }
void Laptop::Ispisi() const{
    cout<<"Evidencijski broj: "<<ev_broj<<std::endl;
    cout<<"Naziv: "<<naziv<<std::endl;
    cout<<"Karakteristike: "<<karakteristike<<std::endl;
}

class Administracija{
    map<int,shared_ptr<Student>> studenti;
    map<int,shared_ptr<Laptop>> laptopi;
    public:
    Administracija(){}
    Administracija(const Administracija &a);
    Administracija &operator=(const Administracija &a);
    Administracija(Administracija &&a);
    Administracija &operator=(Administracija &&a);
    void RegistrirajNovogStudenta(int br_indexa,string god_studija,string ime_i_prezime,string adresa,string br_tel);
    void RegistrirajNoviLaptop(int ev_broj,string naziv,string karakteristike,Student *kod_koga_je);
    Student &NadjiStudenta(int br_indexa);
    Student NadjiStudenta(int br_indexa) const;
    Laptop &NadjiLaptop(int ev_broj);
    Laptop NadjiLaptop(int ev_broj) const;
    void IzlistajStudente() const;
    void IzlistajLaptope() const;
    void ZaduziLaptop(int br_indexa,int ev_broj);
    int NadjiSlobodniLaptop() const;
    void RazduziLaptop(int ev_broj);
    void PrikaziZaduzenja() const;
};
Administracija::Administracija(const Administracija &a){
    for(auto it(a.studenti.begin());it!=a.studenti.end();it++) studenti[it->first]=std::make_shared<Student>(*(it->second));
    for(auto it(a.laptopi.begin());it!=a.laptopi.end();it++) laptopi[it->first]=std::make_shared<Laptop>(*(it->second));
}
Administracija &Administracija::operator=(const Administracija &a){
    for(auto it(a.studenti.begin());it!=a.studenti.end();it++) studenti[it->first]=std::make_shared<Student>(*(it->second));
    for(auto it(a.laptopi.begin());it!=a.laptopi.end();it++) laptopi[it->first]=std::make_shared<Laptop>(*(it->second));
    return *this;
}
Administracija::Administracija(Administracija &&a){
    studenti=a.studenti;
    laptopi=a.laptopi;
}
Administracija &Administracija::operator=(Administracija &&a){
    studenti=a.studenti;
    laptopi=a.laptopi;
    return *this;
}
void Administracija::RegistrirajNovogStudenta(int br_indexa,string god_studija,string ime_i_prezime,string adresa,string br_tel){
    auto it(studenti.find(br_indexa));
    if(it!=studenti.end()) throw std::domain_error("Student s tim indeksom vec postoji");
    studenti[br_indexa]=std::make_shared<Student>(br_indexa, god_studija, ime_i_prezime, adresa, br_tel);
}
void Administracija::RegistrirajNoviLaptop(int ev_broj,string naziv,string karakteristike,Student *kod_koga_je=nullptr){
    auto it(laptopi.find(ev_broj));
    if(it!=laptopi.end()) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    laptopi[ev_broj]=std::make_shared<Laptop>(ev_broj, naziv, karakteristike, kod_koga_je);
}
Student &Administracija::NadjiStudenta(int br_indexa){
    auto it(studenti.find(br_indexa));
    if(it==studenti.end()) throw std::domain_error("Student nije nadjen");
    return *(it->second);
}
Student Administracija::NadjiStudenta(int br_indexa) const{
    auto it(studenti.find(br_indexa));
    if(it==studenti.end()) throw std::domain_error("Student nije nadjen");
    return *(it->second);
}
Laptop &Administracija::NadjiLaptop(int ev_broj){
    auto it(laptopi.find(ev_broj));
    if(it==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    return *(it->second);
}
Laptop Administracija::NadjiLaptop(int ev_broj) const{
    auto it(laptopi.find(ev_broj));
    if(it==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    return *(it->second);
}
void Administracija::IzlistajStudente() const{
    int i(0);
    for(auto it(studenti.begin());it!=studenti.end();it++){
        it->second->Ispisi();
        if(i%2!=0 && i!=0) cout<<std::endl;
        i++;
    }
}
void Administracija::IzlistajLaptope() const{
    int i(0);
    for(auto it(laptopi.begin());it!=laptopi.end();it++){
        it->second->Ispisi();
        if(it->second->DaLiJeZaduzen()){
            auto pok(it->second->DajPokKodKogaJe());
            cout<<"Zaduzio(la): "<<pok->DajImePrezime()<<"("<<pok->DajIndeks()<<")"<<std::endl;
        }
        if(i%2!=0 && i!=0) cout<<std::endl;
        i++;
    }
}
void Administracija::ZaduziLaptop(int br_indexa,int ev_broj){
    auto it1(studenti.find(br_indexa));
    if(it1==studenti.end()) throw std::domain_error("Student nije nadjen");
    auto it2(laptopi.find(ev_broj));
    if(it2==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    if(it2->second->DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
    for(auto it3(laptopi.begin());it3!=laptopi.end();it3++){
        auto pok(it3->second->DajPokKodKogaJe());
        if(pok->DajIndeks()==br_indexa) throw std::domain_error("Student je vec zaduzio laptop");
    }
    it2->second->Zaduzi(*(it1->second));
}
int Administracija::NadjiSlobodniLaptop() const{
    for(auto it(laptopi.begin());it!=laptopi.end();it++){
        if(!(it->second->DaLiJeZaduzen())) return it->second->DajEvidencijskiBroj();
    }
    throw std::domain_error("Nema slobodnih laptopa");
}
void Administracija::RazduziLaptop(int ev_broj){
    auto it(laptopi.find(ev_broj));
    if(it==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    if(!(it->second->DaLiJeZaduzen())) throw std::domain_error("Laptop nije zaduzen");
    it->second->Razduzi();
}
void Administracija::PrikaziZaduzenja() const{
    bool zaduzen(true);
    for(auto it(laptopi.begin());it!=laptopi.end();it++){
        if(it->second->DaLiJeZaduzen()){
            zaduzen=false;
            auto pok(it->second->DajPokKodKogaJe());
            cout<<"Student "<<pok->DajImePrezime()<<" ("<<pok->DajIndeks()<<") zaduzio/la laptop broj "<<it->first<<std::endl;
        }
    }
    if(zaduzen) cout<<"Nema zaduzenja"<<std::endl;
}

void IzvrsiNaredbu(int n,Administracija &a){
    if(n==0){
        int br_indexa(0);
        string god_studija,ime_i_prezime,adresa,br_tel;
        cout<<"Unesite redom: broj indeksa, godina studija, ime i prezime, adresu, br. telefona: \n";
        cin>>br_indexa; cin.clear(); cin.ignore(1000,'\n');
        getline(cin,god_studija); cin.clear();
        getline(cin,ime_i_prezime); cin.clear();
        getline(cin,adresa); cin.clear();
        getline(cin,br_tel); cin.clear();
        a.RegistrirajNovogStudenta(br_indexa,god_studija,ime_i_prezime,adresa,br_tel);
    }
    else if(n==1){
        int ev_broj(0),index(0);
        string naziv, karakteristike;
        Student *kod_koga_je(nullptr);
        cout<<"Unesite redom: evidencijski broj, naziv, karakteristike i br. indexa kod koga je lapto ili 0 ako nije ni kod koga: \n";
        cin>>ev_broj; cin.clear(); cin.ignore(1000,'\n');
        getline(cin,naziv); cin.clear();
        getline(cin,karakteristike); cin.clear();
        cin>>index; cin.clear(); cin.ignore(1000,'\n');
        if(index!=0){
            *kod_koga_je=a.NadjiStudenta(index);
            a.RegistrirajNoviLaptop(ev_broj,naziv,karakteristike,kod_koga_je);
        }
        else a.RegistrirajNoviLaptop(ev_broj,naziv,karakteristike);
    }
    else if(n==2){
        cout<<"Unesite index: ";
        int index(0);
        cin>>index; cin.clear(); cin.ignore(1000,'\n');
        a.NadjiStudenta(index).Ispisi();
    }
    else if(n==3){
        cout<<"Unesite evidencijski broj laptopa: ";
        int ev_broj(0);
        cin>>ev_broj; cin.clear(); cin.ignore(1000,'\n');
        a.NadjiLaptop(ev_broj).Ispisi();
    }
    else if(n==4){
        a.IzlistajStudente();
    }
    else if(n==5){
        a.IzlistajLaptope();
    }
    else if(n==6){
        int br_indexa(0),ev_broj(0);
        cout<<"Unesite redom: br. indexa i evidencijski broj: ";
        cin>>br_indexa>>ev_broj; cin.clear(); cin.ignore(1000,'\n');
        a.ZaduziLaptop(br_indexa,ev_broj);
        cout<<"Laptop zaduzen\n";
    }
    else if(n==7){
        int ev_broj(a.NadjiSlobodniLaptop());
        a.NadjiLaptop(ev_broj).Ispisi();
    }
    else if(n==8){
        int ev_broj(0);
        cout<<"Unesite evidencijski broj: ";
        cin>>ev_broj; cin.clear(); cin.ignore(1000,'\n');
        a.RazduziLaptop(ev_broj);
        cout<<"Laptop razduzen\n";
    }
    else if(n==9){
        a.PrikaziZaduzenja();
    }
}

int main ()
{   
    Administracija a;
    for(;;){
        int n(0);
        try{
            cout<<"Izaberite jednu od opcija: "<<std::endl;
            cout<<"0-Registriraj novog studenta    ";
            cout<<"1-Registriraj novi laptop"<<std::endl;
            cout<<"2-Nadji studenta                ";
            cout<<"3-Nadji laptop"<<std::endl;
            cout<<"4-Izlistaj studente             ";
            cout<<"5-Izlistaj laptope"<<std::endl;
            cout<<"6-Zaduzi laptop                 ";
            cout<<"7-Nadji slobodni laptop"<<std::endl;
            cout<<"8-Razduzi laptop                ";
            cout<<"9-Prikazi zaduzenja"<<std::endl;
            cout<<"10-Zavrsi sa radom"<<std::endl;
            cin>>n;
            if(n==10) break;
            if(!cin || n<0 || n>10){
                cout<<"Greska, unesite ponovo!\n"<<std::endl;
                cin.clear();
                cin.ignore(1000,'\n');
            }
            else{ IzvrsiNaredbu(n,a); cout<<std::endl; }
        }
        catch(std::domain_error izuzetak){
            cout<<"Izuzetak: "<<izuzetak.what()<<std::endl<<std::endl;
        }
    }
    cout<<"kraj";
	return 0;
}
