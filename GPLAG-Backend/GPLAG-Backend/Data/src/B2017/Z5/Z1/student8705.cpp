#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <map>
using std::string;
void Izuzetak() { throw std::domain_error("Neispravni parametri"); }

class Student
{
    int indeks;
    string ime, telefon, godina, adresa;
    void ProvjeriGodinu(const string&); 
    void Normaliziraj(string&); 
    void ProvjeriTel(const string&); 
public:
    Student(int i, const string &g, string im, string adr, const string &tel); 
    int DajIndeks() const { return indeks; }
    string DajGodinuStudija() const { return godina; }
    string DajImePrezime() const { return ime; }
    string DajAdresu() const { return adresa; }
    string DajTelefon() const { return telefon; }
    void Ispisi() const; 
};
void Student::ProvjeriGodinu(const string &s)
{
    static const char *dozv[]{ "1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D", "3/D" };
    if (std::find(dozv, dozv + 11, s) == dozv + 11) Izuzetak();
}
void Student::Normaliziraj(string &s)
{
    std::string t;
    int i(0);
    for (; i < s.size() && s[i] == ' '; ++i);
    for (; i < s.size(); ++i)
    {
        t += s[i];
        if (s[i] == ' ')
            for (; i+1 < s.size() && s[i+1] == ' '; ++i);
    }
    if (t[t.size()-1] == ' ')
    {
        i = t.size();
        while (i > 0 && t[--i] == ' ');
        t.resize(i+1);
    }
    s = std::move(t);
}
void Student::ProvjeriTel(const string &s)
{
    int i(0);
    for (; i < s.size() && s[i] != '/'; ++i)
        if (!isdigit(s[i])) goto izuzetak;
    if (s[i] != '/' || ++i == s.size()) goto izuzetak;
    for (; i < s.size() && s[i] != '-'; ++i)
        if (!isdigit(s[i])) Izuzetak();
    if (s[i] != '-' || ++i == s.size()) goto izuzetak;
    for (; i < s.size(); ++i)
        if (!isdigit(s[i])) goto izuzetak;
    return;
    izuzetak: Izuzetak();
}

Student::Student(int i, const string &g, string im, string adr, const string &tel)
{
    if (i < 10000 || i > 99999) Izuzetak();
    ProvjeriGodinu(g); ProvjeriTel(tel); Normaliziraj(ime = std::move(im)); Normaliziraj(adresa = std::move(adr));
    indeks = i; godina = g + (g.size() == 1 ? "/B" : ""); telefon = tel;
}
void Student::Ispisi() const
{
    std::cout << "Broj indeksa: " << indeks << "\nGodina studija: " << godina
    << "\nIme i prezime: " << ime << "\nAdresa: " << adresa << "\nTelefon: " << telefon;
}

class Laptop
{
    int ev_broj;
    string naziv, karakteristike;
    Student *kod_koga_je{};
public:
    Laptop(int br, const string &n, const string &k); 
    int DajEvidencijskiBroj() const { return ev_broj; };
    string DajNaziv() const { return naziv; }
    string DajKarakteristike() const { return karakteristike; }
    void Zaduzi(Student &s) { if (kod_koga_je) throw std::domain_error("Laptop vec zaduzen"); kod_koga_je = &s; }
    void Razduzi() { kod_koga_je = {}; }
    bool DaLiJeZaduzen() const { return kod_koga_je; };
    Student &DajKodKogaJe() const { if (!kod_koga_je) throw std::domain_error("Laptop nije zaduzen"); return *kod_koga_je; }
    Student *DajPokKodKogaJe() const { return kod_koga_je; }
    void Ispisi() const;
};

Laptop::Laptop(int br, const string &n, const string &k) { if (br < 0) Izuzetak(); ev_broj = br; naziv = n; karakteristike = k; }

void Laptop::Ispisi() const
{
    std::cout << "Evidencijski broj: " << ev_broj << "\nNaziv: " << naziv << "\nKarakteristike: " << karakteristike;
}

class Administracija
{
    std::map<int, Laptop*> laptopi;
    std::map<int, Student*> studenti;
    void Unisti();
public:
    Administracija() = default; 
    Administracija(const Administracija&);
    Administracija(Administracija &&a) { std::swap(laptopi, a.laptopi); std::swap(studenti, a.studenti); } 
    ~Administracija() { Unisti(); } 
    Administracija &operator =(Administracija a) { std::swap(laptopi, a.laptopi); std::swap(studenti, a.studenti); return *this; } 
    void RegistrirajNovogStudenta(int i, const string &g, const string &im, const string &adr, const string &tel); 
    void RegistrirajNoviLaptop(int br, const string &n, const string &k); 
    Student &NadjiStudenta(int ind); 
    Student NadjiStudenta(int ind) const; 
    Laptop &NadjiLaptop(int br); 
    Laptop NadjiLaptop(int br) const; 
    void IzlistajStudente() const;
    void IzlistajLaptope() const;
    void ZaduziLaptop(int ind, int br);
    int NadjiSlobodniLaptop() const;
    void RazduziLaptop(int br);
    void PrikaziZaduzenja() const;
};
void Administracija::Unisti()
{
    for (auto &x : laptopi) delete x.second;
    for (auto &x : studenti) delete x.second;
}

Administracija::Administracija(const Administracija &a)
{
    if (&a == this) return;
    try
    {
        for (auto &x : a.laptopi)
            laptopi[x.first] = new Laptop(*x.second);
        for (auto &x : a.studenti)
            studenti[x.first] = new Student(*x.second);
    }
    catch (...) { Unisti(); }
}
void Administracija::RegistrirajNovogStudenta(int i, const string &g, const string &im, const string &adr, const string &tel)
{
    if (studenti.find(i) != studenti.end()) throw std::domain_error("Student s tim indeksom vec postoji");
    studenti[i] = new Student(i, g, im, adr, tel);
}
void Administracija::RegistrirajNoviLaptop(int br, const string &n, const string &k)
{
    if (laptopi.find(br) != laptopi.end()) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    laptopi[br] = new Laptop(br, n, k);
}
Student &Administracija::NadjiStudenta(int ind)
{
    auto it(studenti.find(ind));
    if (it == studenti.end()) throw std::domain_error("Student nije nadjen");
    return *it->second;
}
Student Administracija::NadjiStudenta(int ind) const
{
    auto it(studenti.find(ind));
    if (it == studenti.end()) throw std::domain_error("Student nije nadjen");
    return *it->second;
}
Laptop &Administracija::NadjiLaptop(int br)
{
    auto it(laptopi.find(br));
    if (it == laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    return *it->second;
}
Laptop Administracija::NadjiLaptop(int br) const
{
    auto it(laptopi.find(br));
    if (it == laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    return *it->second;
}
void Administracija::IzlistajStudente() const
{
    for (auto i(studenti.begin()); i != studenti.end(); ++i)
    {
        if (i != studenti.begin()) std::cout << "\n\n";
        i->second->Ispisi();
    }
}
void Administracija::IzlistajLaptope() const
{
    for (auto i(laptopi.begin()); i != laptopi.end(); ++i) 
    {
        if (i != laptopi.begin()) std::cout << "\n\n";
        i->second->Ispisi();
        if (!i->second->DaLiJeZaduzen()) continue;
        Student &s(i->second->DajKodKogaJe());
        std::cout << "\nZaduzio(la): " << s.DajImePrezime() << " (" << s.DajIndeks() << ')';
    }
}
void Administracija::ZaduziLaptop(int ind, int br)
{
    Student &st(NadjiStudenta(ind));
    Laptop &lap(NadjiLaptop(br));
    if (lap.DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
    if (std::find_if(laptopi.begin(), laptopi.end(), [&](const std::pair<int, Laptop*> &p) {
        return p.second->DajPokKodKogaJe() == &st;
    }) != laptopi.end()) throw std::domain_error("Student je vec zaduzio laptop");
    lap.Zaduzi(st);
}
int Administracija::NadjiSlobodniLaptop() const
{
    auto it(std::find_if(laptopi.begin(), laptopi.end(), [](const std::pair<int, Laptop*> &p) {
        return !p.second->DaLiJeZaduzen();
    }));
    if (it == laptopi.end()) throw std::domain_error("Nema slobodnih laptopa");
    return it->first;
}
void Administracija::RazduziLaptop(int br)
{
    Laptop &lap(NadjiLaptop(br));
    if (!lap.DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen");
    lap.Razduzi();
}
void Administracija::PrikaziZaduzenja() const
{
    if (std::find_if(laptopi.begin(), laptopi.end(), [](const std::pair<int, Laptop*> &p) {
        return p.second->DaLiJeZaduzen();
    }) == laptopi.end()) { std::cout << "Nema zaduzenja"; return; }
    bool f(false);
    for (auto &l : laptopi)
    {
        if (!l.second->DaLiJeZaduzen()) continue;
        if (f) std::cout << '\n';
        else f = true;
        Student &s(l.second->DajKodKogaJe());
        std::cout << "Student " << s.DajImePrezime() << " (" << s.DajIndeks() << ") zaduzio/la laptop broj " << l.second->DajEvidencijskiBroj();
    }
}
int main()
{
    Administracija admin;
    for (;;) try
    {
        std::cout << "\nOdaberite opciju:\n"
        "1 - Registracija studenta\n"
        "2 - Registracija laptopa\n"
        "3 - Ispis studenta po broju indeksa\n"
        "4 - Ispis laptopa pod evidencijskim brojem\n"
        "5 - Ispis svih studenata\n"
        "6 - Ispis svih laptopa\n"
        "7 - Zaduzenje laptopa\n"
        "8 - Razduzenje laptopa\n"
        "9 - Ispis prvog slobodnog laptopa\n"
        "10 - Ispis svih zaduzenja\n"
        "0 - Kraj programa\n";
        int n, m;
        string s, t, u, v;
        std::cin >> n;
        switch (n)
        {
            case 0: return 0;
            case 1:
                std::cout << "Broj indeksa: "; std::cin >> n; Student(n, "1", "", "", "1/1-1");
                std::cin.ignore(10000, '\n');
                std::cout << "Godina: "; std::getline(std::cin, s); Student(12345, s, "", "", "1/1-1");
                std::cout << "Ime: "; std::getline(std::cin, t); Student(12345, "1", t, "", "1/1-1");
                std::cout << "Adresa: "; std::getline(std::cin, u); Student(12345, "1", "", u, "1/1-1");
                std::cout << "Telefon: "; std::getline(std::cin, v);
                admin.RegistrirajNovogStudenta(n, s, t, u, v);
                std::cout << "Student uspjesno registriran.\n";
                break;
            case 2:
                std::cout << "Evidencijski broj: "; std::cin >> n; Laptop(n, "", "");
                std::cin.ignore(10000, '\n');
                std::cout << "Naziv: "; std::getline(std::cin, s);
                std::cout << "Karakteristike: "; std::getline(std::cin, t);
                admin.RegistrirajNoviLaptop(n, s, t);
                std::cout << "Laptop uspjesno registriran.\n";
                break;
            case 3:
                std::cout << "Broj indeksa:\n"; std::cin >> n;
                admin.NadjiStudenta(n).Ispisi(); std::cout << '\n';
                break;
            case 4:
                std::cout << "Evidencijski broj:\n"; std::cin >> n;
                admin.NadjiLaptop(n).Ispisi(); std::cout << '\n';
                break;
            case 5:
                admin.IzlistajStudente(); std::cout << '\n';
                break;
            case 6:
                admin.IzlistajLaptope(); std::cout << '\n';
                break;
            case 7:
                std::cout << "Broj indeksa studenta: "; std::cin >> n;
                std::cout << "Evidencijski broj laptopa: "; std::cin >> m;
                admin.ZaduziLaptop(n, m);
                std::cout << "Laptop uspjesno zaduzen.\n";
                break;
            case 8:
                std::cout << "Evidencijski broj laptopa: "; std::cin >> m;
                admin.RazduziLaptop(m);
                std::cout << "Laptop uspjesno razduzen.\n";
                break;
            case 9:
                std::cout << "Prvi slobodan laptop ima evidencijski broj " << admin.NadjiSlobodniLaptop() << ".\n";
                break;
            default:
                std::cout << '\n'; admin.PrikaziZaduzenja(); std::cout << '\n';
        }
    } catch (const std::exception &e) { std::cout << "Izuzetak: " << e.what() << '\n'; }
	return 0;
}