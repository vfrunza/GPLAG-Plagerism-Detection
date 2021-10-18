/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <algorithm>

class Student {
    int BrojIndeksa;
    std::string GodinaStudiranja;
    std::string ImeIPrezime;
    std::string Adresa;
    std::string BrojTelefona;
    public:
    Student(int indeks, std::string godina, std::string imeiprezime, std::string adresa, std::string broj) {
            if(indeks<10000 || indeks>99999 || godina.size()>3 || godina.size()==0 || (godina.at(0)!='1' && godina.at(0)!='2' && godina.at(0)!='3') ||
                                    (godina.size()>1 && godina.at(1)!='\0' && godina.at(1)!='/') || 
                                    (godina.size()>2 && godina.at(1)=='/' && godina.at(2)!='B' && godina.at(2)!='M' && godina.at(2)!='D')) throw std::domain_error("Neispravni parametri");
            if(godina=="1" || godina=="2" || godina=="3") godina+="/B";
            int brojkosih{0}, brojcrtica{0};
            for(int i=0; i<broj.size(); i++) {
                if(brojkosih > 1 || brojcrtica > 1 || ((broj[i] < '0' || broj[i] > '9') && broj[i] != '/' && broj[i] != '-') || (broj[i]=='-' && brojkosih==0)) {throw std::domain_error("Neispravni parametri");}
                if(broj[i] == '/') brojkosih++;
                if(broj[i] == '-') brojcrtica++;
            }
            if(brojcrtica==0 || brojkosih==0) throw std::domain_error("Neispravni parametri");
            SklonijRazmake(imeiprezime);
            SklonijRazmake(adresa);
            BrojIndeksa=indeks;
            GodinaStudiranja=godina;
            ImeIPrezime=imeiprezime;
            Adresa=adresa;
            BrojTelefona=broj;
    }
    void SklonijRazmake(std::string &str) { for(int i=0; i<str.size(); i++) if(str[i]==' ' && (i==0 || i==str.size()-1 || str[i-1]==' ')) { str.erase(str.begin()+i); i--; } }
    int DajIndeks() const { return BrojIndeksa; }
    std::string DajGodinuStudija() const { if(GodinaStudiranja.size()==1) return GodinaStudiranja+"/B"; return GodinaStudiranja; }
    std::string DajImePrezime() const { return ImeIPrezime; }
    std::string DajAdresu() const { return Adresa; }
    std::string DajTelefon() const { return BrojTelefona; }
    void Ispisi() const {
        std::cout << "Broj indeksa: " << BrojIndeksa << std::endl << "Godina studija: " << GodinaStudiranja << std::endl << "Ime i prezime: " << ImeIPrezime << std::endl << "Adresa: " <<
                                                                                  Adresa << std::endl << "Telefon: " << BrojTelefona << std::endl;
    }
};

class Laptop {
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student *kod_koga_je{nullptr};
    public:
    Laptop(int evidencijski, std::string nazif, std::string karak) { if(evidencijski<0) throw std::domain_error("Neispravni parametri"); ev_broj=evidencijski; naziv=nazif; karakteristike=karak; kod_koga_je=nullptr; }
    int DajEvidencijskiBroj() const { return ev_broj; }
    std::string DajNaziv() const { return naziv; }
    std::string DajKarakteristike() const { return karakteristike; }
    void Zaduzi(Student &zaduzuje) { if(kod_koga_je != nullptr) throw std::domain_error("Laptop vec zauzet"); kod_koga_je=&zaduzuje; }
    void Razduzi() { kod_koga_je=nullptr; }
    bool DaLiJeZaduzen() const { if(kod_koga_je != nullptr) return true; return false; }
    Student &DajKodKogaJe() const { if(kod_koga_je == nullptr) throw std::domain_error("Laptop nije zaduzen"); return *kod_koga_je; }
    Student* DajPokKodKogaJe() const { return kod_koga_je; }
    void Ispisi() const { std::cout << "Evidencijski broj: " << ev_broj << std::endl << "Naziv: " << naziv << std::endl << "Karakteristike: " << karakteristike << std::endl; }
};

class Administracija {
    std::map<int, Student*> Studenti;
    std::map<int, Laptop*> Laptopi;
    public:
    Administracija() { }
    Administracija(const Administracija &a) {
        auto it(a.Studenti.begin());
        while(it != a.Studenti.end()) {
            Studenti.insert({it->first, new Student(*((*it).second))});
            it++;
        }
        auto itlap(a.Laptopi.begin());
        while(itlap != a.Laptopi.end()) {
            Laptopi.insert({itlap->first, new Laptop(*((*itlap).second))});
            itlap++;
        }
    }
    Administracija(Administracija &&a) {
        Studenti=a.Studenti;
        auto it(a.Studenti.begin());
        while(it != a.Studenti.end()) {
            (it->second)=nullptr;
            it++;
        }
        Laptopi=a.Laptopi;
        auto itlap(a.Laptopi.begin());
        while(itlap != a.Laptopi.end()) {
            (itlap->second)=nullptr;
            itlap++;
        }
    }
    ~Administracija() {
        auto it(Studenti.begin());
        while(it != Studenti.end()) {
            delete (it->second);
            it++;
        }
        auto itlap(Laptopi.begin());
        while(itlap != Laptopi.end()) {
            delete (itlap->second);
            itlap++;
        }
    }
    void RegistrirajNovogStudenta(int indeks, std::string godina, std::string imeiprezime, std::string adresa, std::string broj) {
        if(Studenti.find(indeks) != Studenti.end()) throw std::domain_error("Student s tim indeksom vec postoji");
        Studenti.insert({indeks, new Student({indeks, godina, imeiprezime, adresa, broj})});
    }
    void RegistrirajNoviLaptop(int evidencijski, std::string nazif, std::string karak) {
        if(Laptopi.find(evidencijski) != Laptopi.end()) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
        Laptopi.insert({evidencijski, new Laptop({evidencijski, nazif, karak})});
    }
    Student &NadjiStudenta(int indeks) const {
        auto taj(Studenti.find(indeks));
        if(taj == Studenti.end()) throw std::domain_error("Student nije nadjen");
        return *((*taj).second);
    }
    Student NadjiStudenta(const int indeks) {
        auto taj(Studenti.find(indeks));
        if(taj == Studenti.end()) throw std::domain_error("Student nije nadjen");
        return *((*taj).second);
    } 
    Laptop &NadjiLaptop(int ev_broj) const {
        auto taj(Laptopi.find(ev_broj));
        if(taj == Laptopi.end()) throw std::domain_error("Laptop nije nadjen");
        return *((*taj).second);
    }
    void IzlistajStudente() const {
        auto it(Studenti.begin());
        while(it != Studenti.end()) {
            (*((*it).second)).Ispisi();
            std::cout << std::endl;
            it++;
        }
    }
    void IzlistajLaptope() const {
        auto it(Laptopi.begin());
        while(it != Laptopi.end()) {
            (*((*it).second)).Ispisi();
            std::cout << std::endl;
            if((*((*it).second)).DaLiJeZaduzen()) std::cout << "Zaduzio(la): " << ((*((*it).second)).DajKodKogaJe()).DajImePrezime() << " (" << ((*((*it).second)).DajKodKogaJe()).DajIndeks() << ")" << std::endl;
            it++;
        }
    }
    void ZaduziLaptop(int indeks, int ev_broj) {
        auto tajSt(Studenti.find(indeks));
        if(tajSt==Studenti.end()) throw std::domain_error("Student nije nadjen");
        for(auto it(Laptopi.begin()); it != Laptopi.end(); it++) { if((*((*it).second)).DajPokKodKogaJe() == ((*tajSt).second)) throw std::domain_error("Student je vec zaduzio laptop"); }
        auto taj(Laptopi.find(ev_broj));
        if(taj==Laptopi.end()) throw std::domain_error("Laptop nije nadjen");
        if((*((*taj).second)).DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
        (*((*taj).second)).Zaduzi((*((*tajSt).second)));
    }
    int NadjislobodniLaptop() const {
        for(auto it(Laptopi.begin()); it != Laptopi.end(); it++) {
            if(!(*((*it).second)).DaLiJeZaduzen()) return (*((*it).second)).DajEvidencijskiBroj();
        }
        throw std::domain_error("Nema slobodnih laptopa");
    }
    void RazduziLaptop(int ev_broj) {
        auto taj(Laptopi.find(ev_broj));
        if(taj == Laptopi.end()) throw std::domain_error("Laptop nije nadjen");
        if(!(*((*taj).second)).DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen");
        (*((*taj).second)).Razduzi();
    }
    void PrikaziZaduzenja() {
        int brojac{0};
        for(auto it(Laptopi.begin()); it!=Laptopi.end(); it++) {
            Laptop lap(*((*it).second));
            if(lap.DaLiJeZaduzen()) {
                brojac++;
                std::cout << "Student " << (lap.DajKodKogaJe()).DajImePrezime() << " (" << (lap.DajKodKogaJe()).DajIndeks() << ") zaduzio/la laptop broj " << lap.DajEvidencijskiBroj() << std::endl;
            }
        }
        if(brojac==0) std::cout << "Nema zaduzenja" << std::endl;
    }
};

int main () {
    try{
    Administracija AD;
    int brojstudenata{0};
    for(;;) {
        int znak;
        std::cout << "Unesi 1 za unos studenta, 2 za ostatak programa ili 0 za prekid: ";
        std::cin >> znak;
        if(znak!=1 && znak!=2) return 0;
        else if(znak == 2) break;
        brojstudenata++;
        std::cout << "Unesi " << brojstudenata << ". studenta:" << std::endl;
        std::cout << "Broj indeksa: ";
        int indeks;
        std::cin >> indeks;
        std::cin.ignore(10000, '\n');
        std::cout << "Godina studenta - 1, 2, 3 ili 1/B, 2/B, 3/B za prvu, drugu, trecu godinu bachelor studija, 1/M, 2/M za prvu, drugu godinu master studija, 1/D, 2/D, 3/D za prvu, drugu, trecu godinu doktorskog studija: " << std::endl;
        std::string godina;
        std::getline(std::cin, godina);
        std::cout << "Ime i prezime: ";
        std::string imeiprezime;
        std::getline(std::cin, imeiprezime);
        std::cout << "Adresa: ";
        std::string adresa;
        std::getline(std::cin, adresa);
        std::cout << "Broj telefona u obliku cifre/cifre-cifre: ";
        std::string broj;
        std::getline(std::cin, broj);
        AD.RegistrirajNovogStudenta(indeks, godina, imeiprezime, adresa, broj);
    }
    int brlaptopa{0};
    for(;;) {
        int znak;
        std::cout << "Unesi 1 za unos laptopa, 2 za ostatak programa ili 0 za prekid:  ";
        std::cin >> znak;
        if(znak!=1 && znak!=2) return 0;
        else if(znak == 2) break;
        brlaptopa++;
        std::cout << "Unesi " << brlaptopa << ". laptop:" << std::endl;
        std::cout << "Evidencijski broj: ";
        int evidencijski;
        std::cin >> evidencijski;
        std::cin.ignore(10000, '\n');
        std::cout << "Naziv: ";
        std::string nazif;
        std::getline(std::cin, nazif);
        std::cout << "Karakteristike: ";
        std::string karak;
        std::getline(std::cin, karak);
        AD.RegistrirajNoviLaptop(evidencijski, nazif, karak);
    }
    for(;;) {
        std::cout << "Za izlistavanje studenata unesite 1, za nastavak programa 2 i za kraj 0: ";
        int znak;
        std::cin >> znak;
        if(znak==2)break;
        else if( znak != 1) return 0;
        AD.IzlistajStudente();
    }
    for(;;) {
        std::cout << "Za izlistavanje laptopa unesite 1, za nastavak programa 2 i za kraj 0: ";
        int znak;
        std::cin >> znak;
        if(znak==2)break;
        else if( znak != 1) return 0;
        AD.IzlistajLaptope();
    }
    for(;;) {
        std::cout << "Za zaduzivanje laptopa unesite 1, za nastavak programa 2 i za kraj 0: ";
        int znak;
        std::cin >> znak;
        if(znak==2) break;
        else if(znak != 1) return 0;
        std::cout << "Unesi indeks studenta koji zaduzuje: ";
        int ind;
        std::cin >> ind;
        std::cout << "Unesi evidencijski broj laptopa: ";
        int evi;
        std::cin >> evi;
        AD.ZaduziLaptop(ind, evi);
    }
    for(;;) {
        std::cout << "Unesi 1 za ispis zaduzenja ili drugo za kraj: ";
        int znak;
        std::cin >> znak;
        if(znak != 1) return 0;
        AD.PrikaziZaduzenja();
    }
    }
    catch(std::domain_error izuzetak) {
        std::cout << izuzetak.what();
    }
	return 0;
}
