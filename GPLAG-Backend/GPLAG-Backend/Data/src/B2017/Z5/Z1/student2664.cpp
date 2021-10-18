/B2017/2018: Zadaća 5, Zadatak 1
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <string>
#include <utility> //pair ?? i move ??
#include <map>
using std::domain_error;
using std::getline;
using std::string;
using std::find;
using std::cout;
using std::endl;
using std::pair;
using std::move;
using std::cin;
using std::map;

class Student {
    int indeks;
    string godina_studija, ime_i_prezime, adresa, br_tel;
    static int BrojCifara(int x); 
    static bool OdgovarajucaGodinaStudija(const string &s);
    static string SrediIme(const string &s);
    static bool IspravanFormatBroja(const string &b);
    static bool JeLiCifra(char c) {
        if(c <= '9' && c >= '0') return true;
        return false;
    }
  public:
    Student(int indeks, string godina_s, string ime_i_prezime, string adresa, string br_tel);
    int DajIndeks() const { return indeks; }
    string DajGodinuStudija() const;
    string DajImePrezime() const { return ime_i_prezime; }
    string DajAdresu() const { return adresa; }
    string DajTelefon() const { return br_tel; }
    void Ispisi() const {
        cout << "Broj indeksa: " << DajIndeks() << endl;
        cout << "Godina studija: " << DajGodinuStudija() << endl;
        cout << "Ime i prezime: " << DajImePrezime() << endl;
        cout << "Adresa: " << DajAdresu() << endl;
        cout << "Telefon: " << DajTelefon() << endl;
    }
};
Student::Student(int indeks, string godina_s, string ime_i_prezime, string adresa, string br_tel) {
    if(BrojCifara(indeks) != 5 || !OdgovarajucaGodinaStudija(godina_s) || !IspravanFormatBroja(br_tel)) 
        throw domain_error("Neispravni parametri");
    Student::indeks = indeks;
    godina_studija = godina_s;
    Student::ime_i_prezime = SrediIme(ime_i_prezime); 
    Student::adresa = SrediIme(adresa);
    Student::br_tel = br_tel;
}
int Student::BrojCifara(int x) {
    if(x == 0) return 1;
    int br(0);
    do{
        if(x != 0) br++, x /= 10;
        else break;
    }while(1);
    return br;
}
bool Student::OdgovarajucaGodinaStudija(const string &s) {
    string niz[11]{"1","2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D", "3/D"};
    if(find(niz, niz+11, s) != niz+11) return true;
    return false;
}
string Student::SrediIme(const string &s) {
    bool razmak(true);
    int broj_rijeci(0);
    string ime;
    auto it(s.begin());
    while(it != s.end()) {
        if(*it == ' ') razmak = true;
        else if(razmak == true){
            razmak = false;
            broj_rijeci++;
            if(broj_rijeci > 1) ime.push_back(' ');
            while(it != s.end() && *it != ' '){
                ime.push_back(*it);
                it++;
            }
            if(it == s.end()) break;
            it--;
        }
        it++;
    }
    return ime;
}
bool Student::IspravanFormatBroja(const string &b) {
    auto it(b.begin());
    if(it != b.end() && !JeLiCifra(*it)) return false;
    while(it != b.end() && JeLiCifra(*it)) it++;
    if(it == b.end() || *it != '/') return false;
    it++;
    while(it != b.end() && JeLiCifra(*it)) it++;
    if(it == b.end() || *it != '-') return false;
    it++;
    if(!JeLiCifra(*it)) return false;
    while(it != b.end() && JeLiCifra(*it)) it++;
    if(it == b.end()) return true;
    return false;
}
string Student::DajGodinuStudija() const {
    if(godina_studija == "1" || godina_studija == "2" || godina_studija == "3"){
        string pom(godina_studija);
        pom += "/B";
        return pom;
    }
    return godina_studija; 
} 

class Laptop {
    int ev_broj;
    string naziv, karakteristike;
    Student *kod_koga_je;
  public:
    Laptop(int ev_broj, string naziv, string karakteristike) : 
        naziv(naziv), karakteristike(karakteristike), kod_koga_je(nullptr) {
            if(ev_broj < 0) throw domain_error("Neispravni parametri"); 
            Laptop::ev_broj = ev_broj;
        }
    int DajEvidencijskiBroj() const { return ev_broj; }
    string DajNaziv() const { return naziv; }
    string DajKarakteristike() const { return karakteristike; }
    void Zaduzi(Student &s) {
        if(kod_koga_je != nullptr) throw domain_error("Laptop vec zaduzen");
        kod_koga_je = &s; // ** ??
    }
    void Razduzi() { kod_koga_je = nullptr; }
    bool DaLiJeZaduzen() const { return static_cast<bool>(kod_koga_je); }
    Student &DajKodKogaJe() const { // const??
        if(kod_koga_je == nullptr) throw domain_error("Laptop nije zaduzen");
        return *kod_koga_je; // **
    }
    Student* DajPokKodKogaJe() const { // const??
        return kod_koga_je;
    }
    void Ispisi() const {
        cout << "Evidencijski broj: " << DajEvidencijskiBroj() << endl;
        cout << "Naziv: " << DajNaziv() << endl;
        cout << "Karakteristike: " << DajKarakteristike() << endl;
    }
};

class Administracija {
    map<int, Student*> studenti;
    map<int, Laptop*> laptopi;
  public:
    explicit Administracija() {} // **explicit
    
    ~Administracija();
    Administracija(const Administracija &a);
    Administracija(Administracija &&a) : studenti (move(a.studenti)), laptopi (move(a.laptopi)) {
        // na nullptr ?? **
    } // nije li to podrazumijevano svakako ??
    Administracija &operator =(const Administracija &a);
    Administracija &operator =(Administracija &&a);
   
    void RegistrirajNovogStudenta(int indeks, string godina_s, string ime_i_prezime, string adresa, string br_tel);
    void RegistrirajNoviLaptop(int ev_broj, string naziv, string karakteristike);
    Student &NadjiStudenta(int indeks) {
        if(studenti.find(indeks) == studenti.end()) throw domain_error("Student nije nadjen");
        return *studenti[indeks];
    }
    Student NadjiStudenta(int indeks) const {
        auto it(studenti.find(indeks));
        if(it == studenti.end()) throw domain_error("Student nije nadjen");
        return *(it->second); 
        //return *studenti[indeks]; nece **
    }
    Laptop &NadjiLaptop(int ev_broj) {
        if(laptopi.find(ev_broj) == laptopi.end()) throw domain_error("Laptop nije nadjen");
        return *laptopi[ev_broj];
    }
    Laptop NadjiLaptop(int ev_broj) const {
        auto it(laptopi.find(ev_broj));
        if(it == laptopi.end()) throw domain_error("Laptop nije nadjen");
        return *(it->second);
    }
    void IzlistajStudente() const;
    void IzlistajLaptope() const;
    void ZaduziLaptop(int indeks, int ev_broj);
    int NadjiSlobodniLaptop() const;
    void RazduziLaptop(int ev_broj);
    void PrikaziZaduzenja() const;
};
Administracija::~Administracija(){
        for(auto par : studenti) delete par.second;
        for(auto par : laptopi) delete par.second;
    }
Administracija::Administracija(const Administracija &a){
        for(const pair<const int, Student*> &par : a.studenti){
            try{
                studenti.insert({par.first, new Student(*(par.second))});
            }
            catch(...){
                for(pair<const int, Student*> &par : studenti) delete par.second;
                throw; // **
            }
        } 
        for(const pair<const int, Laptop*> &par : a.laptopi){ 
            try{
                laptopi.insert({par.first, new Laptop(*(par.second))});
            }
            catch(...){
                for(pair<const int, Laptop*> &par : laptopi) delete par.second;
                for(pair<const int, Student*> &par : studenti) delete par.second;
                throw; // **
            }
        }
    }
Administracija &Administracija::operator =(const Administracija &a) {
    map<int, Student*> pom_studenti;
    for(const pair<const int, Student*> &par : a.studenti){
        try{
            pom_studenti.insert({par.first, new Student(*(par.second))});
        }
        catch(...){
            for(pair<const int, Student*> &par : pom_studenti) delete par.second;
            throw; // **
        }
    }
    map<int, Laptop*> pom_laptopi;
    for(const pair<const int, Laptop*> &par : a.laptopi){
        try{
            pom_laptopi.insert({par.first, new Laptop(*(par.second))});
        }
        catch(...){
            for(pair<const int, Laptop*> &par : pom_laptopi) delete par.second;
            for(pair<const int, Student*> &par : pom_studenti) delete par.second;
            throw; // **
        }
    }
    studenti = move(pom_studenti);
    laptopi = move(pom_laptopi);
    return *this;
}
Administracija &Administracija::operator =(Administracija &&a){
        studenti = move(a.studenti);
        laptopi = move(a.laptopi);
        return *this;
    }
void Administracija::RegistrirajNovogStudenta(int indeks, string godina_s, string ime_i_prezime, string adresa, string br_tel) {
    if(studenti.find(indeks) != studenti.end()) throw domain_error("Student s tim indeksom vec postoji");
    try{
        studenti[indeks] = new Student(indeks, godina_s, ime_i_prezime, adresa, br_tel);
    }
    catch(...){
        cout << "Belaj"; throw; // ??
    }
}
void Administracija::RegistrirajNoviLaptop(int ev_broj, string naziv, string karakteristike) {
    if(laptopi.find(ev_broj) != laptopi.end()) throw domain_error("Laptop s tim evidencijskim brojem vec postoji");
    try{
        laptopi[ev_broj] = new Laptop(ev_broj, naziv, karakteristike);
    }
    catch(...){
        cout << "Belaj2"; throw; // ??
    }
}
void Administracija::IzlistajStudente() const {
    for(pair<const int, Student*> par : studenti) par.second->Ispisi();
}
void Administracija::IzlistajLaptope() const {
    for(pair<const int, Laptop*> par : laptopi) {
        (par.second)->Ispisi();
        if(par.second->DaLiJeZaduzen()){
            cout << "Zaduzio(la): ";
            Student* pok(par.second->DajPokKodKogaJe());
            cout << pok->DajImePrezime() << " (" << pok->DajIndeks() << ")" << endl;
        }
    }
}
void Administracija::ZaduziLaptop(int indeks, int ev_broj) {
    auto it_student(studenti.find(indeks));
    if(it_student == studenti.end()) throw domain_error("Student nije nadjen");
    auto it_lapi(laptopi.find(ev_broj));
    if(it_lapi == laptopi.end()) throw domain_error("Laptop nije nadjen");
    if(it_lapi->second->DaLiJeZaduzen()) throw domain_error("Laptop vec zaduzen");
    for(auto par : laptopi)
        if (par.second->DajPokKodKogaJe() != nullptr && par.second->DajPokKodKogaJe()->DajIndeks() == indeks) throw domain_error("Student je vec zaduzio laptop");
    
    it_lapi->second->Zaduzi(*(it_student->second));
}
int Administracija::NadjiSlobodniLaptop() const {
    for(auto par_lapi : laptopi){
        if( par_lapi.second->DaLiJeZaduzen() == false) return par_lapi.second->DajEvidencijskiBroj();
    }
    throw domain_error("Nema slobodnih laptopa");
    return -1;
}
void Administracija::RazduziLaptop(int ev_broj) {
    auto it(laptopi.find(ev_broj));
    if(it == laptopi.end()) throw domain_error("Laptop nije nadjen");
    if(it->second->DaLiJeZaduzen() == false) throw domain_error("Laptop nije zaduzen");
    it->second->Razduzi();
}
void Administracija::PrikaziZaduzenja() const {
    int br(0);
    for(auto it = laptopi.begin(); it != laptopi.end(); it++){
        auto par(*it);
        auto pok(par.second->DajPokKodKogaJe());
        if(pok == nullptr) continue;
        cout << "Student " << pok->DajImePrezime() << " (" << pok->DajIndeks() << ") zaduzio/la laptop broj " << par.second->DajEvidencijskiBroj() << endl;
        br++; // **
    }
    if(br == 0) cout << "Nema zaduzenja";
}

void Pocisti(){
    cin.clear();
    cin.ignore(10000, '\n');
}
int main () {
    Administracija a;
    int opcija;
    do{
       cout << "Odaberite jednu od sljedecih opcija" << endl << "0 - Kraj programa" << endl;
       cout << "1 - Registracija studenta" << endl << "2 - Registracija laptopa" << endl;
       cout << "3 - Izlistaj studente" << endl << "4 - Izlistaj laptope" << endl;
       cout << "5 - Nadji studenta" << endl << "6 - Nadji laptop" << endl;
       cout << "7 - Zaduzi laptop" << endl << "8 - Razduzi laptop" << endl;
       cout << "9 - Nadji slobodni laptop" << endl << "10 - Prikazi zaduzenja" << endl;
       cin >> opcija;
       if(opcija == 0) break;
       if(opcija == 1) {
           cout << "Registracija studenta:\n";
           int indeks;
           string godina_s, ime_i_prezime, adresa, br_tel;
           cout << "Unesi indeks: ";
           cin >> indeks;
           Pocisti();
           cout << "Unesi godinu studija: ";
           getline(cin, godina_s);
           cout << "Unesi ime i prezime: ";
           getline(cin, ime_i_prezime);
           cout << "Unesi adresu: ";
           getline(cin, adresa);
           cout << "Unesi broj telefona: ";
           getline(cin, br_tel);
           a.RegistrirajNovogStudenta(indeks, godina_s, ime_i_prezime, adresa, br_tel);
       }
       else if(opcija == 2) {
           cout << "Registracija laptopa:\n";
           int ev_broj;
           string naziv, karakteristike;
           cout << "Unesi evidencijski broj: ";
           cin >> ev_broj;
           Pocisti();
           cout << "Unesi naziv: ";
           getline(cin, naziv);
           cout << "Unesi karakteristike: ";
           getline(cin, karakteristike);
           a.RegistrirajNoviLaptop(ev_broj, naziv, karakteristike);
       }
       else if(opcija == 3) a.IzlistajStudente();
       else if(opcija == 4) a.IzlistajLaptope();
       else if(opcija == 5){
           cout << "Unesi indeks: ";
           int indeks;
           cin >> indeks;
           try{
                a.NadjiStudenta(indeks).Ispisi();
           }
           catch(domain_error er){
               cout << er.what() << endl;
           }
       }
       else if(opcija == 6){
           int ev_broj;
           cout << "Unesi evidencijski broj: ";
           cin >> ev_broj;
           try{
                a.NadjiLaptop(ev_broj).Ispisi();
           }
           catch(domain_error er){
               cout << er.what() << endl;
           }
       }
       else if(opcija == 7){
           cout << "Unesi indeks i evidencijski broj: ";
           int indeks, ev_broj;
           cin >> indeks >> ev_broj;
           a.ZaduziLaptop(indeks, ev_broj);
       }
       else if(opcija == 8){
           cout << "Unesi evidencijski broj: ";
           int ev_broj;
           cin >> ev_broj;
           a.RazduziLaptop(ev_broj);
       }
       else if(opcija == 9){
           try{
             cout << "Slobodan je laptop sa evidencijskim brojem " << a.NadjiSlobodniLaptop();
           }
           catch(domain_error er){
               cout << er.what() << endl;
           }
       }
       else if(opcija == 10) a.PrikaziZaduzenja();
       cout << endl << endl;
       a.IzlistajLaptope(); 
       cout << endl;
       a.IzlistajStudente();
       cout << endl;
    }while(1);
   
   
   return 0;
}

int _main() {
    //AT42 - (skriveni) Test klase Administracija - pomjerajuci operator dodjele

    Administracija etf;

    etf.RegistrirajNoviLaptop(123, "Dell", "CPU 3.0 GHz, 4 GB RAM");
    etf.RegistrirajNoviLaptop(331, "ASUS", "CPU 3.5 GHz, 2 GB RAM");
    etf.RegistrirajNoviLaptop(122, "Dell 2", "CPU 3.2 GHz, 6 GB RAM");


    etf.RegistrirajNovogStudenta(14212, "1","Benjamin", "Francuska revolucija 23", "12/34-56");
    etf.RegistrirajNovogStudenta(17528, "2","Ivan", "Trg vjecnih studenata 12", "048/597-585");
    etf.RegistrirajNovogStudenta(17525, "3", "Ante" ,"Trg vjecnih studenata 11", "062/582-757");

    etf.ZaduziLaptop(14212, 122);
    etf.ZaduziLaptop(17525,331);

    Administracija etf_2016;

    etf_2016.RegistrirajNovogStudenta(17531, "3","Bill","Albanska", "063/451-758");
    etf_2016.RegistrirajNovogStudenta(17648, "2","Johny","Francuska revolucija 54", "024/685-658");


    etf_2016.RegistrirajNoviLaptop(432,"Toshiba", "CPU 3.2 GHz, 8 GB RAM");
    etf_2016.RegistrirajNoviLaptop(132,"Lenovo", "CPU 2.0 GHz, 4 GB RAM");

    etf_2016.ZaduziLaptop(17648,432);
    etf_2016.ZaduziLaptop(17531,132);

    etf = std::move(etf_2016);

    etf.IzlistajStudente();
    std::cout<<std::endl;
    etf.IzlistajLaptope();
    return 0;
}