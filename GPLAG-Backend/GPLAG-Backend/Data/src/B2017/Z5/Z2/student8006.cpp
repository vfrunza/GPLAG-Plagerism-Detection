#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <memory>

class Student {
    int indeks;
    std::string g_studija, i_p, adresa, br_tel;
    void PostaviIndeks(int indeks) {
        if (indeks < 10000 || indeks > 99999) 
            throw std::domain_error("Neispravni parametri");
        this->indeks = indeks;
    }
    void PostaviGodinu(const std::string &god) {
        const std::string godine[11] {"1", "2", "3", "1/B", "2/B", "3/B", "1/M",
            "2/M", "1/D", "2/D", "3/D"};
        int i(0);
        for (; i < 11; i++) if (god == godine[i]) break;
        if (i == 11) throw std::domain_error("Neispravni parametri");
        g_studija = god;
    }
    void PostaviIme(const std::string &ime) {
        for (int i = 0; i < ime.size(); i++) {
            if (ime[i] == ' ' && i_p.size() == 0) continue;
            else if (i_p.size() != 0 && i_p[i_p.size()-1] == ' ' && ime[i] == ' ') continue;
            else {
                int j(i);
                for (; j < ime.size(); j++) if (ime[j] != ' ') break;
                if (j != ime.size()) i_p.push_back(ime[i]);
            }
        }
        if (i_p.size() == 0) throw std::domain_error("Neispravni parametri");
    }
    void PostaviAdresu(const std::string &adr) {
        for (int i = 0; i < adr.size(); i++) {
            if (adr[i] == ' ' && adresa.size() == 0) continue;
            else if (adresa.size() != 0 && adresa[adresa.size()-1] == ' ' && adr[i] == ' ') continue;
            else {
                int j(i);
                for (; j < adr.size(); j++) if (adr[j] != ' ') break;
                if (j != adr.size()) adresa.push_back(adr[i]);
            }
        }
        if (adresa.size() == 0) throw std::domain_error("Neispravni parametri");
    }
    void PostaviTelefon(const std::string &tel) {
        if (tel.size() == 0) throw;
        auto trenutni(tel.begin()), kraj(tel.end());
        while (trenutni != kraj && *trenutni != '/') 
            if (*trenutni < '0' || *trenutni++ > '9') 
                throw std::domain_error("Neispravni parametri");
        if (trenutni == tel.begin()) throw;
        while (++trenutni != kraj && *trenutni != '-')
            if (*trenutni < '0' || *trenutni > '9') 
                throw std::domain_error("Neispravni parametri");
        if (*(trenutni - 1) == '/' || trenutni == kraj) throw;
        while (++trenutni != kraj)
            if (*trenutni < '0' || *trenutni > '9') 
                throw std::domain_error("Neispravni parametri");
        br_tel = tel;
    }
public:
    Student(int indeks, const std::string &g_studija, const std::string &i_p,
        const std::string &adresa, const std::string &tel) {
            PostaviIndeks(indeks); PostaviGodinu(g_studija);
            PostaviIme(i_p); PostaviAdresu(adresa);
            PostaviTelefon(tel);
    }
    int DajIndeks() const { return indeks; }
    std::string DajGodinuStudija() const {
        if (g_studija == "1" || g_studija == "2" || g_studija == "3")
            return g_studija + "/B";
        return g_studija;
    }
    std::string DajImePrezime() const { return i_p; }
    std::string DajAdresu() const { return adresa; }
    std::string DajTelefon() const { return br_tel; }
    void Ispisi() const {
        std::cout << "Broj indeksa: " << DajIndeks() << std::endl
        << "Godina studija: " << DajGodinuStudija() << std::endl
        << "Ime i prezime: " << DajImePrezime() << std::endl
        << "Adresa: " << DajAdresu() << std::endl
        << "Telefon: " << DajTelefon() << std::endl;
    }
};

class Laptop {
    int ev_broj;
    std::string naziv, karakteristike;
    Student *kod_koga_je;
public:
    Laptop(int broj, const std::string &naziv, const std::string &kar) :
        ev_broj(broj), naziv(naziv), karakteristike(kar), kod_koga_je(nullptr) {
            if (ev_broj < 0) throw std::domain_error("Neispravni parametri");    
    }
    int DajEvidencijskiBroj() const { return ev_broj; }
    std::string DajNaziv() const { return naziv; }
    std::string DajKarakteristike() const { return karakteristike; }
    Laptop &Zaduzi(Student &s) {
        if (kod_koga_je) throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je = &s; return *this;
    }
    Laptop &Razduzi() { kod_koga_je = nullptr; return *this; }
    bool DaLiJeZaduzen() const { return kod_koga_je != nullptr; }
    Student &DajKodKogaJe() const {
        if (!kod_koga_je) throw std::domain_error("Laptop nije zaduzen");
        return *kod_koga_je; 
    }
    Student *DajPokKodKogaJe() const {
        if (!kod_koga_je) throw std::domain_error("Laptop nije zaduzen");
        return kod_koga_je;
    }
    void Ispisi() const {
        std::cout << "Evidencijski broj: " << DajEvidencijskiBroj() << std::endl
        << "Naziv: " << DajNaziv() << std::endl
        << "Karakteristike: " << DajKarakteristike() << std::endl;
    }
};

class Administracija {
    std::map<int, std::shared_ptr<Student>> studenti;
    std::map<int, std::shared_ptr<Laptop>> laptopi;
public:
    Administracija() = default;
    Administracija(const Administracija &a) {
        for (auto s = a.studenti.begin(); s != a.studenti.end(); s++)
            studenti[s->first] = std::make_shared<Student>(*s->second);
        for (auto l = a.laptopi.begin(); l != a.laptopi.end(); l++)
            laptopi[l->first] = std::make_shared<Laptop>(*l->second);
    }
    Administracija(Administracija &&a) : studenti(a.studenti), laptopi(a.laptopi) {
        a.studenti.clear(); a.laptopi.clear();
    }
    Administracija &operator = (const Administracija &a) {
        std::map<int, std::shared_ptr<Student>> s;
        std::map<int, std::shared_ptr<Laptop>> l;
        for (auto it = a.studenti.begin(); it != a.studenti.end(); it++) 
            s[it->first] = std::make_shared<Student>(*it->second);
        for (auto it = a.laptopi.begin(); it != a.laptopi.end(); it++)
            l[it->first] = std::make_shared<Laptop>(*it->second);
        studenti = s; laptopi = l;
        return *this;
    }
    Administracija &operator = (Administracija &&a) {
        std::swap(studenti, a.studenti);
        std::swap(laptopi, a.laptopi);
        return *this;
    }
    Administracija &RegistrirajNovogStudenta(int indeks, const std::string &god, 
        const std::string &i_p, const std::string &adr, const std::string &tel) {
            if (studenti.find(indeks) != studenti.end())
                throw std::domain_error("Student s tim indeksom vec postoji");
            studenti[indeks] = std::make_shared<Student>(indeks, god, i_p, adr, tel);
            return *this;
        }
    Administracija &RegistrirajNoviLaptop(int broj, const std::string &naziv, 
        const std::string &kar) {
            if (laptopi.find(broj) != laptopi.end())
                throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
            laptopi[broj] = std::make_shared<Laptop>(broj, naziv, kar);
            return *this;
        }
    Student &NadjiStudenta(int indeks) {
        if (studenti.find(indeks) == studenti.end())
            throw std::domain_error("Student nije nadjen");
        return *studenti[indeks];
    }
    Student NadjiStudenta(int indeks) const {
        if (studenti.find(indeks) == studenti.end())
            throw std::domain_error("Student nije nadjen");
        return *studenti.find(indeks)->second;
    }
    Laptop &NadjiLaptop(int ev_broj) {
        if (laptopi.find(ev_broj) == laptopi.end())
            throw std::domain_error("Laptop nije nadjen");
        return *laptopi[ev_broj];
    }
    Laptop NadjiLaptop(int ev_broj) const {
        if (laptopi.find(ev_broj) == laptopi.end())
            throw std::domain_error("Laptop nije nadjen");
        return *laptopi.find(ev_broj)->second;
    }
    void IzlistajStudente() const {
        for (auto s : studenti) { 
            s.second->Ispisi(); std::cout << std::endl;
        }
    }
    void IzlistajLaptope() const {
        for (auto l : laptopi) {
            l.second->Ispisi();
            if (l.second->DaLiJeZaduzen()) 
                std::cout << "Zaduzio(la): " << l.second->DajPokKodKogaJe()->DajImePrezime()
                << " (" << l.second->DajPokKodKogaJe()->DajIndeks() << ")" << std::endl;
            std::cout << std::endl;
        }
    }
    Administracija &ZaduziLaptop(int indeks, int ev_broj) {
        Student &s(NadjiStudenta(indeks));
        Laptop &l(NadjiLaptop(ev_broj));
        l.Zaduzi(s);
        for (auto l1 : laptopi) {
            if (l1.first != ev_broj && l1.second->DaLiJeZaduzen() && l1.second->DajPokKodKogaJe()->DajIndeks() == indeks) {
                l.Razduzi(); 
                throw std::domain_error("Student je vec zaduzio laptop");
            }
        }
        return *this;
    }
    int NadjiSlobodniLaptop() const {
        auto l(laptopi.begin());
        for (; l != laptopi.end(); l++) 
            if (!(l->second->DaLiJeZaduzen())) break;
        if (l == laptopi.end()) 
            throw std::domain_error("Nema slobodnih laptopa");
        return l->second->DajEvidencijskiBroj();
    }
    Administracija &Razduzi(int ev_broj) {
        Laptop &l(NadjiLaptop(ev_broj));
        if (!l.DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen");
        l.Razduzi();
        return *this;
    }
    void PrikaziZaduzenja() const {
        bool ima_zaduzenih(false);
        for (auto l : laptopi) {
            if (l.second->DaLiJeZaduzen()) {
                auto s(l.second->DajPokKodKogaJe());
                std::cout << "Student " << s->DajImePrezime() << " ("
                << s->DajIndeks() << ") zaduzio/la laptop broj " << l.first << std::endl;
                ima_zaduzenih = true;
            }
        }
        if (!ima_zaduzenih) std::cout << "Nema zaduzenja" << std::endl;
    }
};


int main ()
{
    Administracija a;
    a.RegistrirajNovogStudenta(17969, "1", "  Dino            Kopic", " Vitkovac 16   ", "062/813-845");
    a.RegistrirajNovogStudenta(11111, "2", "Emir Emirovic", "Prva", "1/1-1");
    a.RegistrirajNovogStudenta(22222, "3", "Samir Samirovic", "Druga", "2/2-2");
    a.IzlistajStudente();
    a.RegistrirajNoviLaptop(5, "HP EliteBook 2560p", "i5");
    a.IzlistajLaptope();
    a.ZaduziLaptop(17969, 5);
    Administracija b;
    b = a;
    b.RegistrirajNoviLaptop(6, "D", "P");
    b.ZaduziLaptop(22222, b.NadjiSlobodniLaptop());
    a.PrikaziZaduzenja(); b.PrikaziZaduzenja();

    
	return 0;
}
