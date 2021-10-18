/B2017/2018: Zadaća 5, Zadatak 2

// koristio sam kod iz prvog zadatka
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <iomanip>
#include <memory>

class Student
{
    friend class Administracija;
    int br_indeksa;
    std::string godina, ime_prezime, adresa, telefon;

    std::string UnistiRazmake (std::string str);  // Brise suvisne razmake
    std::string ProvjeriGodinu (std::string god); // provjerava da godina bude kao u tekstu zadatka
    std::string ProvjeriTelefon (std::string tel); // Provjerava broj telefona
public:

    Student (int br_indeksa, std::string godina, std::string ime_prezime, std::string adresa, std::string telefon) {
        if (br_indeksa<10000 ||br_indeksa>99999) throw std::domain_error ("Neispravni parametri");
        Student::br_indeksa=br_indeksa;
        Student::ime_prezime=UnistiRazmake(ime_prezime);
        Student::adresa=UnistiRazmake(adresa);
        Student::godina=ProvjeriGodinu(godina);
        Student::telefon=ProvjeriTelefon(telefon);
    }

    int DajIndeks () const {
        return br_indeksa;
    }

    std::string DajGodinuStudija () const {
        if (godina=="1" || godina=="2" || godina=="3") return godina+"/B";
        return godina;
    }

    std::string DajImePrezime () const {
        return ime_prezime;
    }

    std::string DajAdresu () const {
        return adresa;
    }

    std::string DajTelefon () const {
        return telefon;
    }

    void Ispisi () const {
        std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl<<"Godina studija: "<<DajGodinuStudija()<<std::endl<<"Ime i prezime: "<<DajImePrezime()
                 <<std::endl<<"Adresa: "<<DajAdresu()<<std::endl<<"Telefon: "<<DajTelefon()<<std::endl;
    }

};

std::string Student::UnistiRazmake (std::string s)
{
    int i(0);
    std::string vrati;
    while (i<s.length()) {
        if (s.at(0)==' ' && i==0) while (i<s.length() && s.at(i)==' ') i++; // za razmake na pocetku rijeci
        if (i==s.length()) return s;

        if (s.at(i)==' ') {
            vrati.push_back(s.at(i));
            while (i<s.length() && s.at(i)==' ') i++;
        } else {
            vrati.push_back(s.at(i));
            i++;
        }
    }
    if (vrati.at(vrati.size()-1)==' ') vrati.resize(vrati.size()-1); // ukoliko je zadnji znak bio razmak
    return vrati;
}

std::string Student::ProvjeriGodinu (std::string s)
{
    if (s=="1" || s=="2" || s=="3" || s=="1/B" || s=="2/B" || s=="3/B" || s=="1/M" || s=="2/M" || s=="1/D" || s=="2/D" || s=="3/D") return s;
    throw std::domain_error ("Neispravni parametri");
}

std::string Student::ProvjeriTelefon (std::string s)
{
    int i(0);
    if (i<s.length() && s.at(0)>='0' && s.at(0)<='9') {
        while (i<s.length() && s.at(i)>='0' && s.at(i)<='9') i++;
        if (i<s.length() && s.at(i)=='/') {
            i++;
            if (i<s.length() && s.at(i)>='0' && s.at(i)<='9') {
                while (i<s.length () && s.at(i)>='0' && s.at(i)<='9') i++;
                if (i<s.length() && s.at(i)=='-') {
                    i++;
                    if (i<s.length() && s.at(i)>='0' && s.at(i)<='9')
                        while (i<s.length() && s.at(i)>='0' && s.at(i)<='9') i++;
                    else i--;
                } else i--;
            } else i--;
        } else i--;
    } else i--;
    if (i==s.length()) return s;
    throw std::domain_error ("Neispravni parametri");

}

class Laptop {
  friend class Administracija;
  int ev_broj;
  std::string naziv,karakteristike;
  Student *kod_koga_je; // da li je ovo mjesto 
    public:

    Laptop (int ev_broj, std::string naziv, std::string karakteristike, Student *kod_koga_je=nullptr) : naziv(naziv), karakteristike(karakteristike), kod_koga_je(kod_koga_je) {
        if (ev_broj<0) throw std::domain_error ("Neispravni parametri");
        Laptop::ev_broj=ev_broj;
    }

    int DajEvidencijskiBroj () const {
        return ev_broj;
    }

    std::string DajNaziv () const {
        return naziv;
    }

    std::string DajKarakteristike () const {
        return karakteristike;
    }

    void Zaduzi (Student &student){
        if (kod_koga_je) throw std::domain_error("Laptop vec zaduzen"); 
        kod_koga_je=&student;
    }

    void Razduzi () {
        kod_koga_je=nullptr;
    }

    bool DaLiJeZaduzen () const {
        if (!kod_koga_je) return false;
        return true;
    }

    Student& DajKodKogaJe () const {
        if (!kod_koga_je) throw std::domain_error ("Laptop nije zaduzen");
        return *kod_koga_je;
    }

    Student* DajPokKodKogaJe () const {
        return kod_koga_je;
    }

    void Ispisi() const {
        std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<std::endl<<"Naziv: "<<DajNaziv()<<std::endl<<
        "Karakteristike: "<<DajKarakteristike()<<std::endl;
    }

};

typedef std::map<int, std::shared_ptr<Student>> MapaPametnihStudenata;
typedef std::map<int, std::shared_ptr<Laptop>> MapaPametnihLaptopa;
// bio sam zaboravio da pisem metode izvan tijela klase
class Administracija {
    MapaPametnihLaptopa laptopi;
    MapaPametnihStudenata studenti;
    public:
    Administracija () { }  // konstruktor
    
    //kopirajuci konstruktor
    Administracija (const Administracija &admin){
        if (this==&admin) return; // destruktivna samododjela
         MapaPametnihLaptopa::const_iterator it_lap (admin.laptopi.begin());
         while (it_lap!=admin.laptopi.end()){
             laptopi.insert({it_lap->first,std::make_shared<Laptop> (*(it_lap->second))});
             it_lap++;
         }
         MapaPametnihStudenata::const_iterator it_stud (admin.studenti.begin());
         while (it_stud!=admin.studenti.end()){
          
             studenti.insert({it_stud->first, std::make_shared <Student>(*(it_stud->second))});
             it_stud++;
         }
    }
    
    // kopirajuci operator dodjele
    
    Administracija &operator = (const Administracija &admin){
         if (this!=&admin) return *this; // destruktivna samododjela
         MapaPametnihLaptopa::const_iterator it_lap (admin.laptopi.begin());
         while (it_lap!=admin.laptopi.end()){
             laptopi.insert({it_lap->first,std::make_shared <Laptop> (*(it_lap->second))});
             it_lap++;
         }
         MapaPametnihStudenata::const_iterator it_stud (admin.studenti.begin());
         while (it_stud!=admin.studenti.end()){
          
             studenti.insert({it_stud->first, std::make_shared<Student> (*(it_stud->second))});
             it_stud++;
         }
         return *this;
    }
    
    // pomjerajuci operator dodjele
    
    Administracija &operator =(Administracija &&admin){
        std::swap(laptopi, admin.laptopi);
        std::swap(studenti, admin.studenti);
        return *this;
    }
    
    // pomjerajuci konstruktor
    
    Administracija (Administracija &&admin) : laptopi(admin.laptopi), studenti(admin.studenti) {
       MapaPametnihLaptopa::iterator it_lap (admin.laptopi.begin());
       while (it_lap!=admin.laptopi.end()){
        it_lap->second=nullptr;
        it_lap++;
       }
       MapaPametnihStudenata::iterator it_stud (admin.studenti.begin());
       while (it_stud!=admin.studenti.end()){
        it_stud->second=nullptr;
        it_stud++;
       }
    }

    void RegistrirajNovogStudenta (int br_indeksa, std::string godina, std::string ime_prezime, std::string adresa, std::string telefon) {
        Student student(br_indeksa,godina,ime_prezime,adresa,telefon);
        MapaPametnihStudenata::iterator it(studenti.begin());
        while (it!=studenti.end()){
            if (it->first==student.DajIndeks()) throw std::domain_error ("Student s tim indeksom vec postoji");
            it++;
        }
        studenti.insert({student.DajIndeks(), std::make_shared<Student>(student)});  // registracija novog studenta
    }

    void RegistrirajNoviLaptop (int ev_broj, std::string naziv, std::string karakteristike, Student *student=nullptr){ // da li treba i cetvrti parametar
        Laptop laptop (ev_broj, naziv, karakteristike, student);
        MapaPametnihLaptopa::iterator it(laptopi.begin());
        while (it!=laptopi.end()) {
            if (it->first==laptop.DajEvidencijskiBroj()) throw std::domain_error ("Laptop s tim evidencijskim brojem vec postoji");
            it++;
        }
        laptopi.insert({ev_broj, std::make_shared<Laptop> (laptop)});
    }

    Student& NadjiStudenta (int br_indeksa){
        MapaPametnihStudenata::iterator it(studenti.begin());
        while (it!=studenti.end()) {
            if (it->first==br_indeksa) return *(it->second);
            it++;
        }
        throw std::domain_error ("Student nije nadjen");
    }
    
    Student NadjiStudenta (int br_indeksa) const {
        MapaPametnihStudenata::const_iterator it(studenti.begin()); // hehehehhehe const iterator
        while (it!=studenti.end()){
            if (it->first==br_indeksa) return *(it->second);
            it++;
        }
        throw std::domain_error ("Student nije nadjen");
    }

    Laptop& NadjiLaptop (int ev_broj) {
        MapaPametnihLaptopa::iterator it(laptopi.begin());
        while (it!=laptopi.end()){
            if(it->first==ev_broj) return *(it->second);
            it++;
        }
        throw std::domain_error ("Laptop nije nadjen");
    }
    
    Laptop NadjiLaptop (int ev_broj) const {
        MapaPametnihLaptopa::const_iterator it(laptopi.begin());
        while (it!=laptopi.end()){
            if(it->first==ev_broj) return *(it->second);
            it++;
        }
        throw std::domain_error ("Laptop nije nadjen");
    }

    void IzlistajStudente () const { 
        MapaPametnihStudenata::const_iterator it(studenti.begin());
        while (it!=studenti.end()){
            it->second->Ispisi();
            std::cout<<std::endl;
            it++;
        }
    }

    void IzlistajLaptope () const {
        MapaPametnihLaptopa::const_iterator it(laptopi.begin());
        while (it!=laptopi.end()){
            it->second->Ispisi();
            std::cout<<std::endl;
            if (it->second->DaLiJeZaduzen()) std::cout<<"Zaduzio(la): "<<it->second->DajKodKogaJe().DajImePrezime()
            <<" ("<<it->second->DajKodKogaJe().DajIndeks()<<")"<<std::endl;
            it++;
        }
    }

    void ZaduziLaptop (int br_indeksa, int ev_broj){
        Student student(NadjiStudenta(br_indeksa)); // samo da provjerim da li je vec zaduzeno
        Laptop laptop(NadjiLaptop(ev_broj));
        MapaPametnihLaptopa::iterator it(laptopi.begin());
        if (laptop.DaLiJeZaduzen()) throw std::domain_error ("Laptop vec zaduzen");
        while (it!=laptopi.end()){
            if (it->second->DaLiJeZaduzen())
            if (it->second->DajKodKogaJe().DajIndeks()==student.DajIndeks()) throw std::domain_error ("Student vec zaduzio laptop");
            it++;
        } // provjerava da li dati student vec zaduzuje laptop
        NadjiLaptop(ev_broj).Zaduzi(NadjiStudenta(br_indeksa));
    }

    int NadjiSlobodniLaptop () const {
        MapaPametnihLaptopa::const_iterator it(laptopi.begin());
        while (it!=laptopi.end()){
            if (!it->second->DaLiJeZaduzen()) return it->first;
            it++;
        }
        throw std::domain_error ("Nema slobodnih laptopa");
    }

    void RazduziLaptop (int ev_broj) {
        MapaPametnihLaptopa::iterator it(laptopi.begin());
        while (it!=laptopi.end()){
            if (it->first==ev_broj) {
                if (!it->second->DaLiJeZaduzen()) throw std::domain_error ("Laptop nije zaduzen");
                it->second->Razduzi();
                return;
            }
            it++;
        }
        throw std::domain_error ("Laptop nije nadjen");
    }

    void PrikaziZaduzenja () const {
        MapaPametnihLaptopa::const_iterator it(laptopi.begin());
        bool nijedan(true);
        while (it!=laptopi.end()){
            if (it->second->DaLiJeZaduzen()) {
            std::cout<<"Student "<<it->second->DajKodKogaJe().DajImePrezime()<<
            " ("<<it->second->DajKodKogaJe().DajIndeks()<<") "<<"zaduzio/la laptop broj "<<it->first<<std::endl;
            nijedan=false;
            }
            it++;
        }
        if (nijedan) std::cout<<"Nema zaduzenja";
    }
};

int main ()
{
        /*
        Student student (18248, "3", "    Dinno     Koluh   ", "  Semira Fraste 15  ", "142/545-6425");
         Laptop laptop (724, "HP core i3", "Intel CPU", &student);
        Administracija admin;
        admin.RegistrirajNovogStudenta(18248, "2", " Dinno     Koluh ", "  Semira Fraste 15  ", "037/042-049");
        admin.RegistrirajNovogStudenta(18184, "3/D", "Lorenc", "Titova 45", "012/154-784");
        admin.RegistrirajNoviLaptop(724, "HP core i3", "Intel CPU");
        admin.RegistrirajNoviLaptop(541, "LINUX aaa", "Nije los", &student);
        admin.ZaduziLaptop(18184,724);
        admin.RazduziLaptop(541);
       // admin.RazduziLaptop(724);
        // admin.ZaduziLaptop(18184,7247);
        Administracija admin2;
        admin2=admin;
        
        
        admin.IzlistajLaptope();
        admin.IzlistajStudente();
        admin.IzlistajLaptope();
        //std::cout<<admin.NadjiSlobodanLaptop();
       // admin.PrikaziZaduzenja();*/
       
        std::cout<<"~  Dobro dosli na ETF-Laptoteku  ~\n";
        Administracija admin;
        while (1){
            try{
            std::cout<<"\nImate slijedece opcije: "<<std::endl<<"~ 1 ~ Registracija novog studenta"<<std::endl<<
            "~ 2 ~ Registracija novog laptopa"<<std::endl<<"~ 3 ~ Nadji studenta"<<std::endl<<"~ 4 ~ Nadji laptop"<<
            std::endl<<"~ 5 ~ Zaduzi laptop"<<std::endl<<"~ 6 ~ Nadji slobodan laptop"<<std::endl<<
            "~ 7 ~ Razduzi laptop"<<std::endl<<"~ 8 ~ Izlistaj studente"<<std::endl<<"~ 9 ~ Izlistaj laptope"<<std::endl
            <<"~ 10 ~ Prikazi zaduzenja"<<std::endl<<"~ 0 ~ Kraj programa"<<std::endl<<"Unesite opciju: "<<std::endl;
            int n;
            std::cin>>n;
            if (n==0) {
                std::cout<<"~ ~ ~ Hvala Vam sto ste koristili usluge ETF-Laptoteke ~ ~ ~";
                break;
            }
            else if (n==1){
                std::cout<<"Unesite broj indeksa studenta: "<<std::endl;
                int b;
                std::cin>>b;
                std::cin.ignore(10000, '\n');
                std::string ime_prezime, adresa, telefon, godina;
                std::cout<<"Unesite godinu studija studenta: "<<std::endl;
                std::getline (std::cin, godina);
                std::cout<<"Unesite ime i prezime studenta: "<<std::endl;
                std::getline (std::cin, ime_prezime);
                std::cout<<"Unesite adresu studenta: "<<std::endl;
                std::getline (std::cin, adresa);
                std::cout<<"Unesite telefon studenta: "<<std::endl;
                std::getline (std::cin, telefon);
                admin.RegistrirajNovogStudenta(b, godina, ime_prezime, adresa, telefon);
                
            }
            else if (n==2){
                std::cout<<"Unesite evidencijski broj laptopa: "<<std::endl;
                int x;
                std::cin>>x;
                std::cin.ignore(10000, '\n');
                std::cout<<"Unesite ime laptopa: "<<std::endl;
                std::string naziv, karakteristike;
                std::getline (std::cin, naziv);
                std::cout<<"Unesite karakteristike laptopa: "<<std::endl;
                std::getline (std::cin, karakteristike);
                admin.RegistrirajNoviLaptop(x,naziv, karakteristike);
            }
            else if (n==3) {
                std::cout<<"Unesite broj indeksa od studenta kojeg trazite: "<<std::endl;
                int x;
                std::cin>>x;
                std::cout<<"Student kojeg trazite je: "<<std::endl;
                admin.NadjiStudenta(x).Ispisi();
            }
            else if (n==4) {
                std::cout<<"Unesite evidencijski broj laptopa kojeg trazite: "<<std::endl;
                int x;
                std::cin>>x;
                std::cout<<"Trazeni laptop je: "<<std::endl;
                admin.NadjiLaptop(x).Ispisi();
            }
            else if (n==7) {
                std::cout<<"Unesite evidencijski broj laptopa kojeg zelite raduziti: "<<std::endl;
                int x;
                std::cin>>x;
                admin.RazduziLaptop(x);
                std::cout<<"Uspjesno razduzen laptop "<<admin.NadjiLaptop(x).DajNaziv()<<" sa ev. brojem "<<x<<std::endl;
            }
            else if (n==6) {
                int x (admin.NadjiSlobodniLaptop());
                std::cout<<"Nadjen je slobodan laptop sa ev. brojem "<<x<<std::endl;
            }
            else if (n==5) {
                std::cout<<"Unesite indeks studenta i ev. broj laptopa koje zelite zduziti: "<<std::endl;
                int x,y;
                std::cin>>x>>y;
                admin.ZaduziLaptop(x,y);
                std::cout<<"Laptop uspjesno zaduzen"<<std::endl;
            }
            else if (n==8) {
                admin.IzlistajStudente();
            }
            else if (n==9) {
                admin.IzlistajLaptope();
            }
            else if (n==10) {
                admin.PrikaziZaduzenja();
            }
            else std::cout<<"->->-> Nije Vam ovo kafana, nego fakultet!"<<std::endl;
            }catch (std::domain_error i){
                std::cout<<i.what()<<std::endl;
            }
        }
    return 0;
}
