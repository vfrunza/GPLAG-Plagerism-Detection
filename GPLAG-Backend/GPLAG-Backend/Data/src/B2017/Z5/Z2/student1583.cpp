/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <map>


using std::cout;
using std::cin;
using std::endl;


class Student
{

    int broj_indeksa;
    std::string godina_studija, ime_i_prezime, adresa, broj_telefona;



    void IzbaciSuvisneRazmake(std::string &s) {

        for(int i=0; i<s.length(); i++)
            if( i!=0 && i!=s.length()-1 && s.at(i)==' ' && (s.at(i+1)==' ' || s.at(i-1)==' ') ) {
                s.erase(s.begin()+i);
                i--;
            }
        if(s.at(0)==' ') s.erase(s.begin());
        if(s.at(s.length()-1)==' ') s.erase(s.end()-1);

    }

    bool IspravanIndeks(int indeks) {
        return (indeks/10000>=1 || indeks/10000<=9);
    }

    bool IspravnaGodinaStudija(std::string godina_studija) {

        if(godina_studija=="") return false;
        const std::string godine_studija[11] {"1","2","3","1/B","2/B","3/B","1/M","2/M","1/D","2/D","3/D"};
        return std::find(&godine_studija[0],&godine_studija[11],godina_studija)!=&godine_studija[11];
    }

    bool IspravanBrojTelefona(const std::string &br_telefona) {

        if(br_telefona=="") return false;

        auto it(br_telefona.begin());
        if(!(*it>='0' && *it<='9')) return false; // na pocetku mora biti cifra

        while(it!=br_telefona.end()) {
            if(!(*it>='0' && *it<='9')) {
                if(*it!='/' && *it!='-') return false; // 123/456-789
                else {
                    it++;
                    if(it==br_telefona.end()) return false;
                    it--;
                }
            }
            it++;
        }

        return true;
    }

public:

    Student (int br_indeksa, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::string br_telefona) {

        if( !(IspravanIndeks(br_indeksa) && IspravnaGodinaStudija(godina_studija) && IspravanBrojTelefona(br_telefona))) throw std::domain_error("Neispravni paramteri");
        IzbaciSuvisneRazmake(ime_i_prezime);
        IzbaciSuvisneRazmake(adresa);

        broj_indeksa=br_indeksa;
        Student::godina_studija=godina_studija;
        Student::ime_i_prezime=ime_i_prezime;
        Student::adresa=adresa;
        broj_telefona=br_telefona;
    }


    int DajIndeks() const {
        return broj_indeksa;
    }
    std::string DajGodinuStudija() const {
        if(godina_studija=="1") return "1/B";
        if(godina_studija=="2") return "2/B";
        if(godina_studija=="3") return "3/B";
        return godina_studija;
    }
    std::string DajImePrezime() const {
        return ime_i_prezime;
    }
    std::string DajAdresu() const {
        return adresa;
    }
    std::string DajTelefon() const {
        return broj_telefona;
    }

    void Ispisi() const {
        cout<<"Broj indeksa: "<<DajIndeks()<<endl<<"Godina studija: "<<DajGodinuStudija()<<endl<<"Ime i prezime: "<<DajImePrezime()<<endl<<"Adresa: "<<DajAdresu()<<endl<<"Telefon: "<<DajTelefon()<<endl;
    }
} ;

class Laptop
{

    int ev_broj;
    std::string naziv,karakteristike;
    Student *kod_koga_je=nullptr;
    
    public:
    
    Laptop(int evidencijski_broj, std::string naziv_laptopa, std::string karakteristike_laptopa){
        
        if(evidencijski_broj<0) throw std::domain_error ("Neispravni parametri");
        
        ev_broj=evidencijski_broj;
        naziv=naziv_laptopa;
        karakteristike=karakteristike_laptopa;
    }

    /* 
    kao i metode “Zaduzi”, “Razduzi”, “DaLiJeZaduzen”, “DajKodKogaJe”, “DajPokKodKogaJe” i “Ispisi”. 
    Metoda “Zaduzi” vrši zaduživanje laptopa, a parametar joj je referenca na studenta koji zadužuje laptop. 
    Metoda treba da baci izuzetak tipa “domain_error” uz prateći tekst “Laptop vec zaduzen” ukoliko je laptop već zadužen. 
    Metoda “Razduzi” nema parametara, a vrši razduživanje laptopa*/
    
    int DajEvidencijskiBroj() const { return ev_broj; }
    std::string DajNaziv() const { return naziv; }
    std::string DajKarakteristike() const { return karakteristike; }
    
    void Zaduzi(Student &student){ kod_koga_je=&student; }
    void Razduzi() { if(kod_koga_je!=nullptr) kod_koga_je=nullptr; }
    bool DaLiJeZaduzen() const { return kod_koga_je!=nullptr; }
    Student &DajKodKogaJe() const { if (kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen"); return *kod_koga_je; }
    Student *DajPokKodKogaJe() const { return kod_koga_je; }
    
    void Ispisi() const { cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<endl<<"Naziv: "<<DajNaziv()<<endl<<"Karakteristike: "<<DajKarakteristike()<<endl; }
    
};


/*Klasa “Administracija” objedinjuje u sebi podatke o svim  studentima, kao i o svim raspoloživim laptopima.
Radi brže pretrage, podaci se čuvaju u dvije mape, mapa studenata i mapa laptopa, i one su jedini atributi ove klase. 
Svaki student i svaki laptop imaju jedinstveni identifikacioni broj (broj indeksa odnosno evidencijski broj laptopa), 
i oni su ključna polja ove dvije mape. Ostatak podataka o studentima odnosno laptopima nalazi se u dinamički alocianim
objektima tipa “Student” odnosno “Laptop”, tako da su pridružene vrijednosti u mapi knjiga odnosno mapi korisnika (obični)
pokazivači na dinamički alocirane objekte koje sadrže podatke o odgovarajućem studentu odnosno laptopu. Objekti tipa “Administracija”
moraju se moći kreirati ne navodeći nikakve dopunske informacije, a također se mogu bezbjedno kopirati i međusobno dodjeljivati, 
koristeći strategiju dubokog kopiranja, pri čemu su predviđene optimizirane verzije u slučaju kada se kopiraju privremeni objekti.
Također, primjerci ove klase treba da se brinu o oslobađanju svih resursa koje su zauzeli tokom njihovog života.
*/




class Administracija{
    
    std::map<int,Student*> mapa_studenata;
    std::map<int,Laptop*> mapa_laptopa;
    
    
    public:
    
    ~Administracija(){
        for(auto it=mapa_studenata.begin();it!=mapa_studenata.end();it++) delete std::get<1>(*it);
        for(auto it=mapa_laptopa.begin();it!=mapa_laptopa.end();it++) delete std::get<1>(*it);
    }
    
    Student &NadjiStudenta (int br_indeksa){ auto it(mapa_studenata.find(br_indeksa)); if(it!=mapa_studenata.end()) throw std::domain_error ("Student nije nadjen"); return *(mapa_studenata[br_indeksa]); }
    Student NadjiStudenta (int br_indeksa) const { auto it(mapa_studenata.begin()); for(it=mapa_studenata.begin();it!=mapa_studenata.end();it++) if(std::get<0>(*it)==br_indeksa) return *std::get<1>(*it); throw std::domain_error ("Student nije nadjen"); }
    
    Laptop &NadjiLaptop (int ev_broj){ auto it(mapa_laptopa.find(ev_broj)); if(it!=mapa_laptopa.end()) throw std::domain_error ("Laptop nije nadjen"); return *(mapa_laptopa[ev_broj]); }
    Laptop NadjiLaptop (int ev_broj) const { auto it(mapa_laptopa.begin()); for(it=mapa_laptopa.begin();it!=mapa_laptopa.end();it++) if(std::get<0>(*it)==ev_broj) return *std::get<1>(*it); throw std::domain_error ("Laptop nije nadjen"); }
    
    void RegistrirajNovogStudenta(int br_indeksa, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::string br_telefona ){
        
        for(auto it=mapa_studenata.begin();it!=mapa_studenata.end();it++)
            if(std::get<0>(*it)==br_indeksa) throw std::domain_error ("Student s tim indeksom vec postoji");
        
        mapa_studenata[br_indeksa]=new Student(br_indeksa,godina_studija,ime_i_prezime,adresa,br_telefona);
        
        
    }
    
    
    void RegistrirajNoviLaptop(int evidencijski_broj, std::string naziv_laptopa, std::string karakteristike_laptopa){
        
        for(auto it=mapa_laptopa.begin();it!=mapa_laptopa.end();it++)
            if(std::get<0>(*it)==evidencijski_broj) throw std::domain_error ("Laptop s tim evidencijskim brojem vec postoji");
        
        mapa_laptopa[evidencijski_broj]=new Laptop(evidencijski_broj,naziv_laptopa,karakteristike_laptopa);
    }
    
     void IzlistajStudente() const{
         
         for(auto it=mapa_studenata.begin();it!=mapa_studenata.end();it++){
         std::get<1>(*it)->Ispisi();
         cout<<endl;
         }
     }
     
     void IzlistajLaptope() const{
     
     
         for(auto it=mapa_laptopa.begin();it!=mapa_laptopa.end();it++){
         std::get<1>(*it)->Ispisi();
         if(std::get<1>(*it)->DaLiJeZaduzen()) cout<<"Zaduzio(la): "<<std::get<1>(*it)->DajKodKogaJe().DajImePrezime()<<" ("<<std::get<1>(*it)->DajKodKogaJe().DajIndeks()<<")"<<endl;
         cout<<endl;
         }
     
     }/*Metoda “IzlistajStudente” ispisuje podatke o svim registriranim studentima, jedan za drugim, sa po jednim praznim redom između svaka dva studenta, 
     dok metoda “IzlistajLaptope” tu istu stvar radi za laptope. Pri tome, ukoliko je laptop zadužen, iza standardnih podataka koji se ispisuju za laptop 
     treba odmah ispod u novom redu ispisati i tekst “Zaduzio(la): ” iza čega slijedi ime i prezime studenta, te njegov broj indeksa u zagradi (recimo “Huso Husic Car (35124)”). */
    
    
};


int main ()
{


    return 0;
}