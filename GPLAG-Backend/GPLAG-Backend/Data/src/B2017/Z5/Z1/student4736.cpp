/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <stdexcept>

using namespace std;

class Student
{
    int broj_indeksa;
    string godina_studija;
    string ime_prezime;
    string adresa;
    string telefon;

    static bool ispravna_godina_studija(string godina_studija) {
        if(godina_studija=="1"||godina_studija=="2"||godina_studija=="3") {
            return true;
        } else if(godina_studija.size()==3&&
                  (godina_studija[0]=='1'||godina_studija[0]=='2'||godina_studija[0]=='3')&&
                  (godina_studija[1]=='/')&&
                  (godina_studija[2]=='B'||godina_studija[2]=='M'||godina_studija[2]=='D')
                 ) {
            return true;
        } else {
            return false;
        }
    }

    static string formatiraj_string(string ime_prezime) {
        int i=0;
        string formatirano_ime_prezime="";

        while(ime_prezime[i]==' ' && i<ime_prezime.size()) {
            i++;
        }
        int kraj = ime_prezime.size()-1;
        while(ime_prezime[kraj]==' '&&kraj>=0) {
            kraj--;
        }
        while(i<=kraj) {
            if(ime_prezime[i]!=' ') formatirano_ime_prezime += ime_prezime[i];
            else {
                if(i>0 && ime_prezime[i-1]!=' ') formatirano_ime_prezime+=' ';
            }
            i++;
        }

        return formatirano_ime_prezime;
    }

    static bool  ispravan_telefon(string telefon) {
        bool cifre1=false, cifre2=false, cifre3=false;
        int i=0;
        while(i<telefon.size()&&telefon[i]>='0'&&telefon[i]<='9') {
            cifre1=true;
            i++;
        }
        if(i==telefon.size()||!cifre1 || telefon[i++]!='/') return false;

        while(i<telefon.size()&&telefon[i]>='0'&&telefon[i]<='9') {
            cifre2=true;
            i++;
        }
        if(i==telefon.size()||!cifre2 || telefon[i++]!='-') return false;
        while(i<telefon.size()&&telefon[i]>='0'&&telefon[i]<='9') {
            cifre3=true;
            i++;
        }
        if(!cifre3 || i<=telefon.size()-1) return false;

        return true;
    }

public:
    Student(int broj_indeksa, string godina_studija,string ime_prezime, string adresa, string telefon) {
        if(broj_indeksa<10000 && broj_indeksa>99999) throw domain_error("Neispravni parametri");
        if(!ispravna_godina_studija(godina_studija)) throw domain_error("Neispravni parametri");
        if(!ispravan_telefon(telefon))throw domain_error("Neispravni parametri");
        this->ime_prezime  = formatiraj_string(ime_prezime);
        this->adresa  = formatiraj_string(adresa);
        this->broj_indeksa = broj_indeksa;
        this->godina_studija = godina_studija;
        this->telefon = telefon;
    }

    int DajIndeks()const {
        return broj_indeksa;
    }

    string DajGodinuStudija()const {
        if(godina_studija=="1") return "1/B";
        if(godina_studija=="2") return "2/B";
        if(godina_studija=="3") return "3/B";
        return godina_studija;
    }

    string DajImePrezime()const {
        return ime_prezime;
    }

    string DajAdresu()const {
        return adresa;
    }

    string DajTelefon()const {
        return telefon;
    }


    void Ispisi()const {
        cout<<"Broj indeksa: "<<DajIndeks()<<endl;
        cout<<"Godina studija: "<<DajGodinuStudija()<<endl;
        cout<<"Ime i prezime: "<<DajImePrezime()<<endl;
        cout<<"Adresa: "<<DajAdresu()<<endl;
        cout<<"Telefon: "<<DajTelefon()<<endl;

    }

};


class Laptop
{
    int ev_broj;
    string naziv, karakteristike;
    Student* kod_koga_je;

public:
    Laptop(int ev_broj, string naziv, string karakteristike) {
        if(ev_broj<0)throw domain_error("Neispravni parametri");

        this->ev_broj = ev_broj;
        this->naziv = naziv;
        this->karakteristike = karakteristike;
        this->kod_koga_je = nullptr;
    }

    int DajEvidencijskiBroj()const {
        return ev_broj;
    }

    string DajNaziv()const {
        return naziv;
    }

    string DajKarakteristike()const {
        return karakteristike;
    }

    void Zaduzi(Student& s) {
        if(DaLiJeZaduzen()) throw domain_error("Laptop vec zaduzen");
        kod_koga_je = &s;
    }

    void Razduzi() {
        kod_koga_je = nullptr;
    }

    bool DaLiJeZaduzen()const {
        return kod_koga_je !=nullptr;
    }

    Student& DajKodKogaJe()const {
        if(!DaLiJeZaduzen()) throw domain_error("Laptop nije zaduzen");

        return *kod_koga_je;
    }

    Student* DajPokKodKogaJe()const {
        return kod_koga_je;
    }

    void Ispisi()const {
        cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<endl;
        cout<<"Naziv: "<<DajNaziv()<<endl;
        cout<<"Karakteristike: "<<DajKarakteristike()<<endl;
    }
};



class Administracija
{
    map<int,Student*> studenti;
    map<int,Laptop*> laptopi;

public:
    Administracija() {}

    ~Administracija() {
        for (auto it= a.studenti.begin(); it!=a.studenti.end(); it++) {
            delete it->second;
        }

        for (auto it= a.laptopi.begin(); it!=a.laptopi.end(); it++) {
            delete it->second;
        }
        studenti.clear();
        laptopi.clear();
    }
    Administracija(const Administracija&a) {

        for(auto it = a.studenti.begin(); it!=a.studenti.end(); it++) {
            studenti[it->first] = new Student( *it->second);
        }

        for(auto it = a.laptopi.begin(); it!=a.laptopi.end(); it++) {
            laptopi[it->first] = new Laptop( *it->second);
        }


    }

    Administracija& operator=(const Administracija&a) {
        if(this==&a) return *this; //Samododjela
        
        //Destruktor
        for (auto it= a.studenti.begin(); it!=a.studenti.end(); it++) {
            delete it->second;
        }

        for (auto it= a.laptopi.begin(); it!=a.laptopi.end(); it++) {
            delete it->second;
        }
        studenti.clear();
        laptopi.clear();

        //Konstruktor kopije
        for(auto it = a.studenti.begin(); it!=a.studenti.end(); it++) {
            studenti[it->first] = new Student( *it->second);
        }

        for(auto it = a.laptopi.begin(); it!=a.laptopi.end(); it++) {
            laptopi[it->first] = new Laptop( *it->second);
        }
        
        //vracanje *this
        return *this;
    }


    Administracija(Administracija&&a){
        studenti = a.studenti;
        laptopi = a.laptopi;
        a.studenti.clear();
        a.laptopi.clear();
    }
    
    //Kasnije pomjerajuci operator dodjele


}

int main ()
{
    Student s1(35124,"3/B"," Huso Husic Car"," Trg zrtava reforme obrazovanja 25","069/434-072");
    s1.Ispisi();

    Laptop l1(724," ASUS X554L","Intel CPU 2.4 GHz, 8 GB RAM");
    l1.Ispisi();
    return 0;
}
