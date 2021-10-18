/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

using namespace std;

class Student {
    int brIndeksa;
    string godinaStudija, imePrezime, Adresa, brTelefona;
    bool ValidirajIndeks(int broj_indeksa) {
    bool validan = true;
    int brojac = 0;
    while(broj_indeksa > 0) {
        broj_indeksa /= 10;
        brojac++;
    }
    if(brojac != 5) validan = false;
    return validan;
}
    bool ValidirajBroj(string broj_telefona) {
    bool validanBroj = true;
    int brojac1 = 0, brojac2 = 0, brojac3 = 0;
    
    if(broj_telefona.size() == 0) validanBroj = false;
    
    for(int i = 0; i < broj_telefona.length(); i++) 
    {
        if((int)broj_telefona[i] >= 49 && (int)broj_telefona[i] <= 57) // 49 >= 49 (T) && 49 <= 57 (T)
        {
            brojac1++;
        } else if(broj_telefona[i]  == '/') {
            if(brojac1 == 0)
                validanBroj = false;
            brojac1 = 0;
            brojac2++;
        } else if(broj_telefona[i] == '-') {
            if(brojac2 > 1 || brojac1 == 0)
                validanBroj = false;
            brojac1 = 0;
            brojac3++;
        }
        
        
        if(brojac3 > 1) validanBroj = false;
    }
    if(brojac1 == 0 || brojac3 == 0) validanBroj = false;
    return validanBroj;
}
    string IgnorisiRazmake(string s) {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ' && s[i + 1] == ' ') {
                s.erase(i, 1);
                i--;
            }
        }
        if(s[0] == ' ')
            s.erase(0, 1);
        if(s[s.length() - 1] == ' ')
            s.erase(s.length() - 1, 1);
    
        return s;
    }
    bool ValidirajGodinu(string g) {
    bool validnaGodina = false;
    
    if(g == "1" || g == "2" || g == "3" || g == "1/B" || g == "2/B" || g == "3/B" || g == "1/M" || g == "2/M" || g == "1/D" || g == "2/D" || g == "3/D")
        validnaGodina = true;
    
    return validnaGodina;
    }
    string VratiPunuGodinu(string g) {
        if(g == "1" || g == "2" || g == "3")
            g += "/B";
        return g;
    }
public:
    Student(int broj_indeksa, string godina_studija, string ime_prezime, string adresa, string broj_telefona) {
        if(ValidirajIndeks(broj_indeksa) == false || ValidirajGodinu(godina_studija) == false || ValidirajBroj(broj_telefona) == false)
            throw domain_error("Neispravni parametri");
        
        brIndeksa = broj_indeksa;
        godinaStudija = VratiPunuGodinu(godina_studija);
        imePrezime = IgnorisiRazmake(ime_prezime);
        Adresa = IgnorisiRazmake(adresa);
        brTelefona = broj_telefona;
    }
    int DajIndeks() const { return brIndeksa; }
    string DajGodinuStudija() const { return godinaStudija; }
    string DajImePrezime() const { return imePrezime; }
    string DajAdresu() const { return Adresa; }
    string DajTelefon() const { return brTelefona; }
    void Ispisi() const {
        cout << "Broj indeksa: " << brIndeksa << "\nGodina studija: " << godinaStudija << "\nIme i prezime: " << imePrezime << "\nAdresa: " << Adresa << "\nTelefon: " << brTelefona;
    }
};

class Laptop {
    int ev_broj;
    string naziv, karakteristike;
    Student *kod_koga_je;
public:
    Laptop(int eb, string n, string k) {
        if(eb < 0) throw domain_error("Neispravni parametri");
        
        ev_broj = eb;
        naziv = n;
        karakteristike = k;
        kod_koga_je = nullptr;
    }
    int DajEvidencijskiBroj() const { return ev_broj; }
    string DajNaziv() const { return naziv; }
    string DajKarakteristike() const { return karakteristike; }
    void Zaduzi(Student &student) { 
        if(DaLiJeZaduzen()) throw domain_error("Laptop vec zaduzen");
        kod_koga_je = &student; }
    void Razduzi() { kod_koga_je = nullptr; }
    bool DaLiJeZaduzen() { return kod_koga_je; }
    Student &DajKodKogaJe() { 
        if(DaLiJeZaduzen()) return *kod_koga_je;
        else throw domain_error("Laptop nije zaduzen");
    }
    Student *DajPokKodKogaJe() { return kod_koga_je; }
    void Ispisi() const {
        cout << "Evidencijski broj: " << ev_broj << "\nNaziv: " << naziv << "\nKarakteristike: " << karakteristike;
    }
};

class Administracija { // treba uraditi destruktor, konstruktor kopije(oba), operator dodjele(oba)
    map<int, Student*> studenti;
    map<int, Laptop*> laptopi;
public:
    Administracija() {}
    ~Administracija()
    {
        for(auto s: studenti) delete s.second;
        for(auto l: laptopi) delete l.second;
    }
    Administracija(const Administracija &a) : studenti(a.studenti), laptopi(a.laptopi)
    {
        auto it = a.studenti.begin();
        for(auto s: studenti)
        {
            s.second = new Student(it->second->DajIndeks(), it->second->DajGodinuStudija(), it->second->DajImePrezime(), it->second->DajAdresu(), it->second->DajTelefon());
            it++;
        }
        auto it1 = a.laptopi.begin();
        for(auto l: laptopi)
        {
            l.second = new Laptop(it1->second->DajEvidencijskiBroj(), it1->second->DajNaziv(), it1->second->DajKarakteristike());
            it1++;
        }
    }
    Administracija(Administracija &&a) : studenti(a.studenti), laptopi(a.laptopi)
    {
        for(auto s: a.studenti) s.second = nullptr;
        for(auto l: a.laptopi) l.second = nullptr;
    }
    Administracija &operator =(const Administracija &a);
    Administracija &operator =(Administracija &&a);
    void RegistrirajNovogStudenta(int broj_indeksa, string godina_studija, string ime_prezime, string adresa, string broj_telefona);
    void RegistrirajNoviLaptop(int eb, string n, string k);
    Student &NadjiStudenta(int broj_indeksa);
    Student NadjiStudenta(int broj_indeksa) const;
    Laptop &NadjiLaptop(int ev_broj);
    Laptop NadjiLaptop(int ev_broj) const;
    void IzlistajStudente() const;
    void IzlistajLaptope() const;
    void ZaduziLaptop(int broj_indeksa, int ev_broj);
    int NadjiSlobodniLaptop();
    void RazduziLaptop(int ev_broj);
    void PrikaziZaduzenja() const;
};

Administracija &Administracija::operator =(const Administracija &a)
{
    if(&a != this)
    {
        for(auto s: studenti) delete s.second;
        for(auto l: laptopi) delete l.second;
        
        auto it = a.studenti.begin();
        for(auto s: studenti)
        {
            s.second = new Student(it->second->DajIndeks(), it->second->DajGodinuStudija(), it->second->DajImePrezime(), it->second->DajAdresu(), it->second->DajTelefon());
            it++;
        }
        auto it1 = a.laptopi.begin();
        for(auto l: laptopi)
        {
            l.second = new Laptop(it1->second->DajEvidencijskiBroj(), it1->second->DajNaziv(), it1->second->DajKarakteristike());
            it1++;
        }
    }
    
    return *this;
}

Administracija &Administracija::operator =(Administracija &&a)
{
    if(&a != this)
    {
        for(auto s: studenti) delete s.second;
        for(auto l: laptopi) delete l.second;
        studenti = a.studenti;
        laptopi = a.laptopi;
        for(auto s: a.studenti) s.second = nullptr;
        for(auto l: a.laptopi) l.second = nullptr;
    }
    
    return *this;
}

void Administracija::RegistrirajNovogStudenta(int broj_indeksa, string godina_studija, string ime_prezime, string adresa, string broj_telefona)
{
    auto it = studenti.find(broj_indeksa);
    if(it != studenti.end())
        throw domain_error("Student s tim indeksom vec postoji");
    
    Student* student = new Student(broj_indeksa, godina_studija, ime_prezime, adresa, broj_telefona);
    studenti.insert(pair<int, Student*>(broj_indeksa, student));
}

void Administracija::RegistrirajNoviLaptop(int eb, string n, string k)
{
    auto it = laptopi.find(eb);
    if(it != laptopi.end())
        throw domain_error("Laptop s tim evidencijskim brojem vec postoji");
    
    Laptop* laptop = new Laptop(eb, n, k);
    laptopi.insert(pair<int, Laptop*>(eb, laptop));
}

Student &Administracija::NadjiStudenta(int broj_indeksa) 
{
    auto it = studenti.find(broj_indeksa);
    if(it != studenti.end()) return *it->second;
    else throw domain_error("Student nije nadjen");
}

Student Administracija::NadjiStudenta(int broj_indeksa) const
{
    auto it = studenti.find(broj_indeksa);
    if(it != studenti.end()) return *it->second;
    else throw domain_error("Student nije nadjen");
}

Laptop &Administracija::NadjiLaptop(int ev_broj)
{
    auto it = laptopi.find(ev_broj);
    if(it != laptopi.end()) return *it->second;
    else throw domain_error("Laptop nije nadjen");
}

Laptop Administracija::NadjiLaptop(int ev_broj) const
{
    auto it = laptopi.find(ev_broj);
    if(it != laptopi.end()) return *it->second;
    else throw domain_error("Laptop nije nadjen");
}

void Administracija::IzlistajStudente() const
{
    auto it = studenti.begin();
    while(it != studenti.end())
    {
        it->second->Ispisi();
        cout << endl << endl;
        it++;
    }
}

void Administracija::IzlistajLaptope() const
{
    auto it = laptopi.begin();
    while(it != laptopi.end())
    {
        it->second->Ispisi();
        if(it->second->DaLiJeZaduzen())
            cout << "\nZaduzio(la): " << it->second->DajKodKogaJe().DajImePrezime() << " (" << it->second->DajKodKogaJe().DajIndeks() << ")";
        cout << endl << endl;
        it++;
    }
}

void Administracija::ZaduziLaptop(int broj_indeksa, int ev_broj)
{
    auto itS = studenti.find(broj_indeksa);
    auto itL = laptopi.find(ev_broj);
    
    if(itS == studenti.end()) 
        throw domain_error("Student nije nadjen");
        
    if(itL == laptopi.end())
        throw domain_error("Laptop nije nadjen");
    else
    {
        if(itL->second->DaLiJeZaduzen())
            throw domain_error("Laptop vec zaduzen");
    }
    
    auto it = laptopi.begin();
    while(it != laptopi.end())
    {
        if(it->second->DaLiJeZaduzen())
        {
            if(it->second->DajKodKogaJe().DajIndeks() == broj_indeksa)
                throw domain_error("Student je vec zaduzio laptop");
        }
        it++;
    }
    
    itL->second->Zaduzi(NadjiStudenta(broj_indeksa));
}

int Administracija::NadjiSlobodniLaptop()
{
    auto it = laptopi.begin();
    while(it != laptopi.end())
    {
        if(!(it->second->DaLiJeZaduzen()))
            return it->second->DajEvidencijskiBroj();
        it++;
    }
    throw domain_error("Nema slobodnih laptopa");
}

void Administracija::RazduziLaptop(int ev_broj)
{
    auto it = laptopi.find(ev_broj);
    if(it == laptopi.end())
        throw domain_error("Laptop nije nadjen");
    else
    {
        if(!(it->second->DaLiJeZaduzen()))
            throw domain_error("Laptop nije zaduzen");
    }
    
    it->second->Razduzi();
}

void Administracija::PrikaziZaduzenja() const
{
    bool zaduzenja = false;
    
    auto it = laptopi.begin();
    while(it != laptopi.end())
    {
        if(it->second->DaLiJeZaduzen())
        {
            zaduzenja = true;
            cout << "Student " << it->second->DajKodKogaJe().DajImePrezime() << " (" << it->second->DajKodKogaJe().DajIndeks() << ") zaduzio/la laptop broj " << it->second->DajEvidencijskiBroj() << endl;
        }
        it++;
    }
    if(!zaduzenja) cout << "Nema zaduzenja";
}

int main ()
{
    Administracija admin;
    for(;;)
    {
        cout << "Izaberite opciju:\n";
        cout << "1 - Registriraj novog studenta\n";
        cout << "2 - Registriraj novi laptop\n";
        cout << "3 - Nadji studenta\n";
        cout << "4 - Nadji laptop\n";
        cout << "5 - Izlistaj studente\n";
        cout << "6 - Izlistaj laptope\n";
        cout << "7 - Zaduzi laptop\n";
        cout << "8 - Razduzi laptop\n";
        cout << "9 - Prikazi zaduzenja\n";
        cout << "0 - Kraj\n\n";
        cout << "Vas izbor je: ";
        int opcija;
        cin >> opcija;
        while(opcija < 0 || opcija > 9) {
            cout << "Pogresna opcija!\nVas izbor je: ";
            cin >> opcija;
        }
        if(opcija == 1) {
            string imeprezime, adresa, telefon, godina;
            int indeks_broj;
            cout << "\nUnesite broj indeksa: ";
            cin >> indeks_broj;
            cin.get();
			cout << "Unesite godinu studija: ";
			getline(cin, godina);
            cout << "Unesite ime i prezime: ";
            getline(cin, imeprezime);
            cout << "Unesite adresu: ";
            getline(cin, adresa);
            cout << "Unesite telefon: ";
            getline(cin, telefon);
            try {
                admin.RegistrirajNovogStudenta(indeks_broj, godina, imeprezime, adresa, telefon);
            }
            catch(domain_error izuzetak) {
                cout << endl << izuzetak.what() << endl << endl;
            }
        }
        else if(opcija == 2) {
			int ev_broj;
            string naziv, karakteristike;
            cout << "\nUnesite evidencijski broj: ";
            cin >> ev_broj;
            cin.get();
            cout << "Unesite naziv: ";
            getline(cin, naziv);
            cout << "Unesite karakteristike: ";
            getline(cin, karakteristike);
            try {
                admin.RegistrirajNoviLaptop(ev_broj, naziv, karakteristike);
            }
            catch(domain_error izuzetak) {
                cout << endl << izuzetak.what() << endl << endl;
            }
        }
        else if(opcija == 3) {
            int indeks_broj;
            cout << "\nUnsite broj indeksa studenta kojeg zelite pronaci: ";
            cin >> indeks_broj;
            try {
                Student s(admin.NadjiStudenta(indeks_broj));
                cout << "\nPronasli ste studenta sa podacima:\n";
				s.Ispisi();
            }
            catch(domain_error izuzetak) {
                cout << endl << izuzetak.what() << endl << endl;
            }
        }
        else if(opcija == 4) {
            int evidencijski_broj;
            cout << "\nUnsite evidencijski broj laptopa kojeg zelite pronaci: ";
            cin >> evidencijski_broj;
            try {
                Laptop p(admin.NadjiLaptop(evidencijski_broj));
                cout << "\nPronasli ste knjigu sa podacima:\n";
                p.Ispisi();
            }
            catch(domain_error izuzetak) {
                cout << endl << izuzetak.what() << endl << endl;
            }
        }
        else if(opcija == 5) {
            cout << "\nRegistrovani studenti su: " << endl << endl;
            admin.IzlistajStudente();
        }
        else if(opcija == 6) {
            cout << "\nLaptopi koji se nalaze u administraciji su: " << endl << endl;
            admin.IzlistajLaptope();
        }
        else if(opcija == 7) {
            int indeks_broj, evidencijski_broj;
            cout << "\nUnesite evidencijski broj laptopa kojeg zelite zaduziti: ";
            cin >> evidencijski_broj;
            cout << "Unesite broj indeksa studenta kojem zaduzujete laptop: ";
            cin >> indeks_broj;
            try {
                admin.ZaduziLaptop(indeks_broj, evidencijski_broj);
            }
            catch(domain_error izuzetak) {
                cout << endl << izuzetak.what() << endl << endl;
            }
        }
        else if(opcija == 8) {
            int evidencijski_broj;
            cout << "\nUnesite evidencijski broj laptopa kojeg zelite razduziti: ";
            cin >> evidencijski_broj;
            try {
                admin.RazduziLaptop(evidencijski_broj);
            }
            catch(domain_error izuzetak) {
                cout << endl << izuzetak.what() << endl << endl;
            }
        }
        else if(opcija == 9) {
            try {
                admin.PrikaziZaduzenja();
                cout << endl << endl;
            }
            catch(domain_error izuzetak) {
                cout << endl << izuzetak.what() << endl << endl;
            }
        }
        else break;
    }
    
	return 0;
}
