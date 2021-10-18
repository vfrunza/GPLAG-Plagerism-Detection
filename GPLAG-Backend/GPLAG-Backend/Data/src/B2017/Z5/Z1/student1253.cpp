/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <map>


class Student
{
    int indeks;
    std::string godina;
    std::string imeprezime, adresa, telefon;

    static void UkloniRazmake(std::string &s) {
        std::string temp(s);
        bool razmak(true), pocetak(true);
        int poc(0), kraj(s.size());
        for(int i=0; i<s.size(); i++) {
            if(s[i] != ' ' && razmak && pocetak) {
                pocetak = false;
                razmak = false;
                poc = i;
            }
            if(s[i] == ' ' && !razmak) {
                razmak = true;
                kraj = i;
            }
            if(s[i] != ' ') {
                razmak = false;
                kraj = s.size();
            }
        }
        s = temp.substr(poc, kraj-poc);

        temp = s;
        razmak = false;
        poc = 0;
        kraj = 0;
        for(int i=0; i<temp.size(); i++) {
            if(temp[i] == ' ') {
                poc = i;
                while(i<temp.size() && temp[i]==' ') i++;
                kraj = i;
                s = temp.substr(0, poc) + " " + temp.substr(kraj, temp.size()-kraj);
                i--;
            }
        }

    }
public:
    Student(int indeks, std::string godina, std::string imeprezime, std::string adresa, std::string telefon) {
        std::string temp;
        temp = std::to_string(indeks);
        if(temp.size() != 5) throw std::domain_error("Neispravni parametri\n");


        if(godina.size() == 1 || godina.size() == 3) {
            if(godina[0] != '1' && godina[0] != '2' && godina[0] != '3') throw std::domain_error("Neispravni parametri\n");
            if(godina.size() == 3) {
                if(godina[1] != '/') throw std::domain_error("Neispravni parametri\n");
                if(godina[2] != 'B' && godina[2] != 'M' && godina[2] != 'D') throw std::domain_error("Neispravni parametri\n");
                if(godina[0] == 3 && godina[2] == 'M') throw std::domain_error("Neispravni parametri\n");
            }
        } else {
            throw std::domain_error("Neispravni parametri\n");
        }
        UkloniRazmake(imeprezime);
        UkloniRazmake(adresa);

        bool prvi(true);
        for(int i=0; i<telefon.size(); i++) {
            if( !(telefon[i] >= '0' && telefon[i] <= '9') ) {
                if(prvi) {
                    if(telefon[i] != '/') throw std::domain_error("Neispravni parametri\n");
                    prvi = false;
                } else {
                    if(telefon[i] != '-') throw std::domain_error("Neispravni parametri\n");
                }
            }
        }
        this->indeks = indeks;
        this->godina = godina;
        this->imeprezime = imeprezime;
        this->telefon = telefon;
        this->adresa = adresa;
    }

    int DajIndeks() const {
        return indeks;
    }
    std::string DajGodinuStudija() const {
        std::string temp(godina);
        if(temp.size()==1) {
            temp += "/B";
        }
        return temp;
    }
    std::string DajImePrezime() const {

        return imeprezime;
    }
    std::string DajAdresu() const {
        return adresa;
    }
    std::string DajTelefon() const {
        return telefon;
    }
    void Ispisi() const {
        std::cout << "Broj indeksa: " << indeks << "\n";
        std::cout << "Godina studija: " << this->DajGodinuStudija() << "\n";
        std::cout << "Ime i prezime: " << imeprezime << "\n";
        std::cout << "Adresa: " << this->DajAdresu() << "\n";
        std::cout << "Telefon: " << this->DajTelefon() << std::endl;
    }

};

class Laptop
{
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student *kod_koga_je;
public:
    Laptop(int ev_broj, std::string naziv, std::string karakteristike) : kod_koga_je(nullptr) {
        if(ev_broj<0) throw std::domain_error("Neispravni parametri\n");
        this->ev_broj = ev_broj;
        this->naziv = naziv;
        this->karakteristike = karakteristike;
    }
    int DajEvidencijskiBroj() const {
        return ev_broj;
    }
    std::string DajNaziv() const {
        return naziv;
    }
    std::string DajKarakteristike() const {
        return karakteristike;
    }
    void Zaduzi(Student &s) {
        if(kod_koga_je != nullptr) throw std::domain_error("Laptop vec zaduzen\n");
        kod_koga_je = &s;
    }
    void Razduzi() {
        if(kod_koga_je != nullptr) {
            delete kod_koga_je; //treba li
            kod_koga_je = nullptr;
        }
    }
    bool DaLiJeZaduzen() const {
        if(kod_koga_je) return true;
        return false;
    }
    Student &DajKodKogaJe() {
        if(kod_koga_je == nullptr) throw std::domain_error("Laptop nije zaduzen\n");
        return *kod_koga_je;
    }
    Student *DajPokKodKogaJe() {
        return kod_koga_je;
    }
    void Ispisi() const {
        std::cout<<"Evidencijski broj: "<<ev_broj<<"\n";
        std::cout<<"Naziv: "<<naziv<<"\n";
        std::cout<<"Karakteristike: "<<karakteristike<<std::endl;
    }

};


class Administracija
{
    std::map<int, Student* > s;
    std::map<int, Laptop* > l;
    static void Dealokacija(Administracija *a) {
        for(auto it = a->s.begin(); it!=a->s.end(); it++) {
            delete it->second;
            it->second = nullptr;
        }
        for(auto it = a->l.begin(); it!=a->l.end(); it++) {
            delete it->second;
            it->second = nullptr;
        }
    }
public:
    Administracija() = default;
    ~Administracija() {
        Dealokacija(this);
    }
    Administracija(const Administracija &a) {
        for(auto it = a.s.begin(); it!=a.s.end(); it++) {
            s.insert({it->first, nullptr });
        }
        for(auto it = a.l.begin(); it!=a.l.end(); it++) {
            l.insert({it->first, nullptr });
        }

        auto i(a.s.begin());
        try {
            for(auto it = s.begin(); it!=s.end() && i != a.s.end(); it++) {
                it->second = new Student(*(i->second));
                i++;
            }
        } catch(...) {
            Dealokacija(this);
            throw;
        }
        auto j(a.l.begin());
        try {
            for(auto it = l.begin(); it!=l.end() && j != a.l.end(); it++) {
                it->second = new Laptop(*(j->second));
                j++;
            }
        } catch(...) {
            Dealokacija(this);
            throw;
        }
    }

    Administracija(Administracija &&a) : s(a.s), l(a.l) {
        for(auto it = a.s.begin(); it!=a.s.end(); it++) {
            s.insert({it->first, nullptr });
        }
        for(auto it = a.l.begin(); it!=a.l.end(); it++) {
            l.insert({it->first, nullptr });
        }
        auto i(a.s.begin());
        for(auto it = s.begin(); it!=s.end() && i != a.s.end(); it++) {
            it->second = i->second;
            i++;
        }
        auto j(a.l.begin());
        for(auto it = l.begin(); it!=l.end() && j != a.l.end(); it++) {
            it->second =j->second;
            j++;
        }
        for(auto it = a.s.begin(); it!=a.s.end(); it++) {
            it->second = nullptr;
        }
        for(auto it = a.l.begin(); it!=a.l.end(); it++) {
            it->second = nullptr;
        }

    }
    Administracija &operator =(const Administracija &a) {
        Dealokacija(this);
        *this = a;
        for(auto it = s.begin(); it!=s.end(); it++) {
            it->second = nullptr;
        }
        for(auto it = l.begin(); it!=l.end(); it++) {
            it->second = nullptr;
        }
        auto i(a.s.begin());
        try {
            for(auto it = s.begin(); it!=s.end() && i != a.s.end(); it++) {
                it->second = new Student(*(i->second));
                i++;
            }
        } catch(...) {
            Dealokacija(this);
            throw;
        }
        auto j(a.l.begin());
        try {
            for(auto it = l.begin(); it!=l.end() && j != a.l.end(); it++) {
                it->second = new Laptop(*(j->second));
                j++;
            }
        } catch(...) {
            Dealokacija(this);
            throw;
        }
        return *this;
    }
    Administracija &operator =(Administracija &&a) {
        std::swap(s, a.s);
        std::swap(l, a.l);
        return *this;
    }

    void RegistrirajNovogStudenta(int indeks, std::string godina, std::string imeprezime, std::string adresa, std::string telefon)  {
        for(auto it = s.begin(); it!=s.end(); it++) {
            if(it->second->DajIndeks() == indeks) throw std::domain_error("Student s tim indeksom vec postoji\n");
        }
        Student *novi(new Student(indeks, godina, imeprezime, adresa, telefon));
        s.insert({indeks, novi});
    }

    void RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike)  {
        for(auto it = l.begin(); it!=l.end(); it++) {
            if(it->second->DajEvidencijskiBroj() == ev_broj) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji\n");
        }
        Laptop *novi(new Laptop(ev_broj, naziv, karakteristike));
        l.insert({ev_broj, novi});
    }

    Student &NadjiStudenta(int indeks) {
        for(auto it = s.begin(); it!=s.end(); it++) {
            if(it->second->DajIndeks() == indeks) {
                return *(it->second);
            }
        }
        throw std::domain_error("Student nije nadjen\n");
    }
    Student NadjiStudenta(int indeks) const {
        for(auto it = s.begin(); it!=s.end(); it++) {
            if(it->second->DajIndeks() == indeks) {
                return *(it->second);
            }
        }
        throw std::domain_error("Student nije nadjen\n");
    }

    Laptop &NadjiLaptop(int ev_broj) {
        for(auto it = l.begin(); it!=l.end(); it++) {
            if(it->second->DajEvidencijskiBroj() == ev_broj) {
                return *(it->second);
            }
        }
        throw std::domain_error("Laptop nije nadjen\n");
    }
    Laptop NadjiLaptop(int ev_broj) const {
        for(auto it = l.begin(); it!=l.end(); it++) {
            if(it->second->DajEvidencijskiBroj() == ev_broj) {
                return *(it->second);
            }
        }
        throw std::domain_error("Laptop nije nadjen\n");
    }

    void IzlistajStudente() const {
        for(auto it = s.begin(); it!=s.end(); it++) {
            it->second->Ispisi();
            std::cout<<std::endl;
        }
    }
    void IzlistajLaptope() const {
        for(auto it = l.begin(); it!=l.end(); it++) {
            it->second->Ispisi();
            if(it->second->DaLiJeZaduzen()) {
                Student temp(it->second->DajKodKogaJe());
                std::cout<<"Zaduzio(la): "<<temp.DajImePrezime()<<" ("<<temp.DajIndeks()<<")\n";
            }
            std::cout<<std::endl;
        }
    }

    void ZaduziLaptop(int indeks, int ev_broj) {
        bool ima_student(false);
        for(auto it = s.begin(); it!=s.end(); it++) {
            if(it->second->DajIndeks() == indeks) {
                ima_student = true;
                bool ima_laptop(false);
                for(auto it2 = l.begin(); it2!=l.end(); it2++) {
                    if(it2->second->DajEvidencijskiBroj() == ev_broj) {
                        ima_laptop = true;
                        for(auto it3 = l.begin(); it3!=l.end(); it3++) {
                            if(it3->second->DajPokKodKogaJe()) {
                                if(it3->second->DajPokKodKogaJe()->DajIndeks() == indeks) {
                                    throw std::domain_error("Student je vec zaduzio laptop\n");
                                }
                            }
                        }

                        it2->second->Zaduzi(*(it->second));
                    }
                }
                if(!ima_laptop) throw std::domain_error("Laptop nije nadjen\n");
            }
        }
        if(!ima_student) {
            throw std::domain_error("Student nije nadjen\n");
        }
    }

    int NadjiSlobodniLaptop() const {
        for(auto it = l.begin(); it!=l.end(); it++) {
            if( !(it->second->DaLiJeZaduzen()) ) {
                return it->second->DajEvidencijskiBroj();
            }
        }
        throw std::domain_error("Nema slobodnih laptopa\n");
    }

    void RazduziLaptop(int ev_broj) {
        for(auto it = l.begin(); it!=l.end(); it++) {
            if(it->second->DajEvidencijskiBroj() == ev_broj) {
                if( !(it->second->DaLiJeZaduzen()) ) {
                    throw std::domain_error("Laptop nije zaduzen\n");
                }
                it->second->Razduzi();
            }
        }

        throw std::domain_error("Laptop nije nadjen\n");
    }
    void PrikaziZaduzenja() const {
        bool test(false);
        for(auto it = l.begin(); it!=l.end(); it++) {
            if(it->second->DaLiJeZaduzen()) {
                test = true;
                Student temp(it->second->DajKodKogaJe());
                std::cout<<"Student "<<temp.DajImePrezime()<<" ("<<temp.DajIndeks()<<") zaduzio/la laptop broj "<<it->second->DajEvidencijskiBroj()<<"\n";
            }
            std::cout<<std::endl;
        }
        if(!test) {
            std::cout<<"Nema zaduzenja\n";
        }
    }

};


int main ()
{
    try {
        Administracija etf;

        etf.RegistrirajNoviLaptop(123, "Dell", "CPU 3.0 GHz, 4 GB RAM");
        etf.RegistrirajNoviLaptop(331, "ASUS", "CPU 3.5 GHz, 2 GB RAM");
        etf.RegistrirajNoviLaptop(122, "Dell 2", "CPU 3.2 GHz, 6 GB RAM");


        etf.RegistrirajNovogStudenta(14212, "1","Benjamin", "Francuska revolucija 23", "12/34-56");
        etf.RegistrirajNovogStudenta(17528, "2","Ivan", "Trg vjecnih studenata 12", "048/597-585");
        etf.RegistrirajNovogStudenta(17525, "3", "Ante" ,"Trg vjecnih studenata 11", "062/582-757");

        etf.ZaduziLaptop(14212, 122);
        etf.ZaduziLaptop(17525,331);
        etf.IzlistajLaptope();
    } catch(std::domain_error izu) {
        std::cout<<izu.what();
    }
    return 0;
}
