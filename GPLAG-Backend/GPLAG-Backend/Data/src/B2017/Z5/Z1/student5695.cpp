#include <iostream>
#include <map>
#include <stdexcept>
#include <new>
#include <string>

using namespace std;

string GodinaStudijaKarakteri[10]={"1","2","3","1/B","2/B","3/B","1/M","2/M","1/D","2/D","3/D"};

bool duzinaPet(int a) {
    int rez(0);
    while(a>0) {
        a/=10;
        rez++;
    }
    return (rez==5);
}

bool GodinaStudijaOK(string a) {
    for(int i=0;i<11;i++) {
        if(a==GodinaStudijaKarakteri[i]) return true;
    }
    return false;
}

void OcistiRazmake(string &a) {
    for(int i=0;i<a.length();i++) {
        if((i==0 && a[i]==' ') || (i!=0 && a[i-1]==' ' && a[i]==' ') || (i==a.length()-1 && a[i]==' ')) {
            a.erase(a.begin()+i);
            i--;
        }
    }
}

bool DaLiJeBrojTelefona(string a) {
    int i(0), b(-1);
    bool backslash(false), dash(false);
    while(i<a.length() && isdigit(a[i])) {
        i++;
        if(!backslash && a[i]=='/') {
            b=i;
            i++;
            backslash=true;
        }
        else if(backslash && !dash && i-b>1 && a[i]=='-') {
            i++;
            dash=true;
        }
    }
    return (a.length()==i && backslash && dash && isdigit(a[a.length()-1]));
}

class Student {
    int brojIndexa;
    string godinaStudija;
    string imeIPrezime;
    string adresa;
    string brojTelefona;
    public:
    Student(int brojIndexa, string godinaStudija,string imeIPrezime, string adresa, string brojTelefona){
        if(!( duzinaPet(brojIndexa) && godinaStudijaOK(godinaStudija) && dalJeBrTelefona(brojTelefona)))
            throw domain_error("Neispravni parametri");
        this->brojIndexa = brojIndexa;
        this->godinaStudija = godinaStudija;
        if(godinaStudija.length() == 1) {
            this->godinaStudija.push_back('/');
            this->godinaStudija.push_back('B');
            }
        this->imeIPrezime = imeIPrezime;
        this->adresa = adresa;
        this->brojTelefona = brojTelefona;
    }
    int DajIndex() {
        return brojIndexa;
    }
    string DajGodinuStudija() {
        return godinaStudija;
    }
    string DajImePrezime() {
        return imeIPrezime;
    }
    string DajAdresu() {
        return adresa;
    }
    string DajTelefon() {
        return brojTelefona
    }
    void Ispisi() {
        cout << "Broj indeksa: " << brojIndexa << endl <<
        "Godina studija: " + godinaStudija << endl <<
        "Ime i prezime: " + imeIPrezime << endl <<
        "Adresa: " + adresa << endl <<
        "Telefon: " + brojTelefona;
    }
};

bool evBrojIspravan(int a) {
    return a>=0;
}

class Laptop {
    int ev_broj;
    string naziv;
    string karakteristike;
    Student* kod_koga_je;
    public:
    Laptop(int ev_broj, string naziv, string karakteristike){
        if(!evBrojIspravan(ev_broj))
            throw domain_error("Neispravni parametri");
        this->ev_broj = ev_broj;
        this->naziv = naziv;
        this->karakteristike = karakteristike;
        kod_koga_je = nullptr;
    }
    int DajEvidencijskiBroj() {
        return ev_broj;
    }
    string DajNaziv() {
        return naziv;
    }
    string DajKarakteristike() {
        return karakteristike;
    }
    void Zaduzi(Student &s) {
        if(kod_koga_je!=nullptr) throw domain_error("Laptop vec zaduzen");
        kod_koga_je=&s;
    }
    void Razduzi(Student &s) {
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen() {
        if(kod_koga_je==nullptr) return false;
        return true;
    }
    Student &DajKodKogaJe(){
        if(kod_koga_je == nullptr) throw domain_error("Laptop nije zaduzen");
        return *kod_koga_je;
    }
    Student* DajPokKodKogaJe(){
        return kod_koga_je;
    }
    void Ispisi() {
        cout << "Evidencijski broj: " << ev_broj << endl <<
        "Naziv: " +naziv << endl <<
        "Karakteristike: " + karakteristike;
    }
};

class Administracija() {
    map<int, Student*> studenti;
    map<int, Laptop*> laptopi;
    public:
    Administracija() {}
    ~Administracija() {
        for(auto it = studenti.begin(); it != studenti.end(); it++){
            delete it->second;
            it->second = nullptr;
        }
        for(auto it = laptopi.begin(); it != laptopi.end(); it++){
            delete it->second;
            (it->second)->Razduzi();
            it->second = nullptr;
        }
    }
    
};

int main() {
    
	return 0;
}
