/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

class Student
{
    int broj_indeksa;
    std::string godina_studija, ime_i_prezime, adresa_studenta, broj_telefona;

    bool TestCifri(int broj_indeksa);
    bool TestGodineStudija(std::string godina_studija);
    void IzbaciRazmake(std::string &ime_i_prezime);
    bool TestTelefona(std::string broj_telefona);
    bool DaLiJeCifra(char c);

public:
    Student (int broj_indeksa, std::string godina_studija, std::string ime_i_prezime,
             std::string adresa_studenta, std::string broj_telefona);

    int DajIndeks() const {
        return broj_indeksa;
    }
    std::string DajGodinuStudija () const;
    std::string DajImePrezime() const {
        return ime_i_prezime;
    }
    std::string DajAdresu() const {
        return adresa_studenta;
    }
    std::string DajTelefon() const {
        return broj_telefona;
    }
    void Ispisi() const;
};
class Laptop
{
    int ev_broj;
    std::string naziv, karakteristike;
    Student* kod_koga_je;
public:
    Laptop (int ev_broj, std::string naziv, std::string karakteristike);

    int DajEvidencijskiBroj () const {
        return ev_broj;
    }
    std::string DajNaziv() const {
        return naziv;
    }
    std::string DajKarakteristike() const {
        return karakteristike;
    }
    void Zaduzi(Student& student);
    void Razduzi() {
        if(kod_koga_je) kod_koga_je = nullptr;
    }
    bool DaLiJeZaduzen() {
        return kod_koga_je;
    }
    Student &DajKodKogaJe() const;
    Student *&DajPokKodKogaJe() {
        return kod_koga_je;
    }
    void Ispisi() const;
};
class Administracija
{
    std::map <int, Student*> mapa_studenta;
    std::map<int, Laptop*> mapa_laptopa;

public:
    Administracija() = default;
    ~Administracija();
    Administracija(const Administracija &admin);
    Administracija(Administracija &&admin);
    Administracija &operator= (const Administracija &admin);
    Administracija &operator= (Administracija &&admin);

    void RegistrirajNovogStudenta (int broj_indeksa, std::string godina_studija, std::string ime_i_prezime,
                                   std::string adresa_studenta, std::string broj_telefona);
    void RegistrirajNoviLaptop (int ev_broj, std::string naziv, std::string karakteristike);

    Student &NadjiStudenta(int broj_indeksa);
    Student NadjiStudenta(int broj_indeksa) const;
    Laptop &NadjiLaptop(int broj_indeksa);
    Laptop NadjiLaptop(int broj_indeksa) const;

    void IzlistajStudente() const;
    void IzlistajLaptope() const;

    void ZaduziLaptop(int broj_indeksa, int ev_broj);
    int NadjiSlobodniLaptop() const;
    void RazduziLaptop(int ev_broj);
    void PrikaziZaduzenja() const;


};
bool Student::TestCifri(int broj_indeksa)
{
    std::string test(std::to_string(broj_indeksa));
    if(test.at(0) == '-') return  false;
    return test.length() == 5;
}

bool Student::TestGodineStudija(std::string godina_studija)
{
    std::vector<std::string> imena_mjeseci {"1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D", "3/D", "B"};
    return std::find(imena_mjeseci.begin(), imena_mjeseci.end(), godina_studija) != imena_mjeseci.end();
}

void Student::IzbaciRazmake(std::string &ime_i_prezime)
{
    std::string pomocni {};
    for(int i = 0; i < ime_i_prezime.length(); i++) {

        if(ime_i_prezime[i] == ' ') continue;
        std::string temp {};

        while(ime_i_prezime[i] != ' ' && i < ime_i_prezime.length()) {
            temp.push_back(ime_i_prezime[i]);
            i++;
        }
        pomocni += temp;
        if(i != ime_i_prezime.length()) pomocni +=' ';
    }
    auto it (pomocni.end());
    it--;
    if(*it == ' ')
        pomocni.resize(pomocni.size() - 1);
    ime_i_prezime = pomocni;
}
bool Student::DaLiJeCifra(char c)
{
    return (c >= '0' && c <= '9');
}
bool Student::TestTelefona(std::string broj_telefona)
{
    int broj1(0), broj2(0);
    for(int i = 0; i < broj_telefona.length(); i++) {
        if(!DaLiJeCifra(broj_telefona[i]) && broj_telefona[i] != '/' && broj_telefona[i] != '-') return false;
        if(broj_telefona[i] == '/') broj1 = i;
        if(broj_telefona[i] == '-') broj2 = i;
    }
    if(broj1 == 0 || broj2 == 0 || broj1 > broj2) return false;
    return true;
}
Student::Student(int broj_indeksa, std::string godina_studija, std::string ime_i_prezime,
                 std::string adresa_studenta, std::string broj_telefona)
{
    if(!(TestCifri(broj_indeksa) || TestGodineStudija(godina_studija) || TestTelefona(broj_telefona)))
        throw std::domain_error("Neispravni parametri");
    IzbaciRazmake(ime_i_prezime);

    Student::broj_indeksa = broj_indeksa;
    Student::godina_studija = godina_studija;
    Student::ime_i_prezime = ime_i_prezime;
    Student::adresa_studenta = adresa_studenta;
    Student::broj_telefona = broj_telefona;

}

std::string Student::DajGodinuStudija () const
{
    std::string temp(godina_studija);
    if(godina_studija == "1" || godina_studija == "2" || godina_studija == "3") temp += "/B";
    return temp;
}
void Student::Ispisi() const
{
    std::cout << "Broj indeksa: "<< DajIndeks() << std::endl;
    std::cout << "Godina studija: " << DajGodinuStudija() << std::endl;
    std::cout << "Ime i prezime: " << DajImePrezime() << std::endl;
    std::cout << "Adresa: " << DajAdresu() << std::endl;
    std::cout << "Telefon: " << DajTelefon() << std::endl;
}

Laptop::Laptop (int ev_broj, std::string naziv, std::string karakteristike): kod_koga_je(nullptr)
{
    if(ev_broj < 0) throw std::domain_error("Neispravni parametri");
    Laptop::ev_broj = ev_broj;
    Laptop::naziv = naziv;
    Laptop::karakteristike = karakteristike;
}
void Laptop::Zaduzi(Student& student)
{
    if(kod_koga_je) throw std::domain_error("Laptop vec zaduzen");
    kod_koga_je = &student;
}
Student &Laptop::DajKodKogaJe() const
{
    if(!kod_koga_je) throw std::domain_error("Laptop nije zaduzen");
    return *kod_koga_je;
}
void Laptop::Ispisi() const
{
    std::cout << "Evidencijski broj: " << ev_broj << std::endl;
    std::cout << "Naziv: " << naziv << std::endl;
    std::cout << "Karakteristike: " << karakteristike << std::endl;
}
Administracija::~Administracija()
{
    for(auto it = mapa_studenta.begin(); it != mapa_studenta.end(); it++)
        delete it->second;

    for(auto it = mapa_laptopa.begin(); it != mapa_laptopa.end(); it++)
        delete it->second;
}
Administracija::Administracija(const Administracija &admin)
{
    try {
        for(auto it = admin.mapa_studenta.begin(); it != admin.mapa_studenta.end(); it++)
            mapa_studenta[it->first] = new Student (it->second->DajIndeks(), it->second->DajGodinuStudija(), it->second->DajImePrezime(),
                                                    it->second->DajAdresu(), it->second->DajTelefon());
    } catch(...) {
        for(auto it = mapa_studenta.begin(); it != mapa_studenta.end(); it++)
            delete it->second;
        mapa_studenta.clear();
    }
    try {
        for(auto it = admin.mapa_laptopa.begin(); it != admin.mapa_laptopa.end(); it++)
            mapa_laptopa[it->first] = new Laptop (it->second->DajEvidencijskiBroj(), it->second->DajNaziv(), it->second->DajKarakteristike());
    } catch(...) {
        for(auto it = mapa_laptopa.begin(); it != mapa_laptopa.end(); it++)
            delete it->second;
        mapa_laptopa.clear();
    }
}
Administracija::Administracija(Administracija &&admin)
{
    std::swap(admin.mapa_laptopa, mapa_laptopa);
    std::swap(mapa_studenta, admin.mapa_studenta);
}
Administracija &Administracija::operator= (const Administracija &admin)
{
    for(auto it = mapa_laptopa.begin(); it != mapa_laptopa.end(); it++)
        delete it->second;
    mapa_laptopa.clear();

    for(auto it = mapa_studenta.begin(); it != mapa_studenta.end(); it++)
        delete it-> second;
    mapa_studenta.clear();

    for(auto it = admin.mapa_laptopa.begin(); it != admin.mapa_laptopa.end(); it++)
        mapa_laptopa[it->first] = new Laptop(it->second->DajEvidencijskiBroj(), it->second->DajNaziv(), it->second->DajKarakteristike());

    for(auto it = admin.mapa_studenta.begin(); it != admin.mapa_studenta.end(); it++)
        mapa_studenta[it->first] = new Student(it->second->DajIndeks(), it->second->DajGodinuStudija(), it->second->DajImePrezime(),
                                               it->second->DajAdresu(), it->second->DajTelefon());

    return *this;
}
Administracija &Administracija::operator= (Administracija &&admin)
{
    for(auto it = mapa_laptopa.begin(); it != mapa_laptopa.end(); it++)
        delete it->second;
    mapa_laptopa.clear();

    for(auto it = mapa_studenta.begin(); it != mapa_studenta.end(); it++)
        delete it-> second;
    mapa_studenta.clear();

    std::swap(admin.mapa_studenta, mapa_studenta);
    std::swap(admin.mapa_laptopa, mapa_laptopa);
    return *this;
}
void Administracija::RegistrirajNovogStudenta(int broj_indeksa, std::string godina_studija, std::string ime_i_prezime,
        std::string adresa_studenta, std::string broj_telefona)
{
    if(mapa_studenta.count(broj_indeksa != 0)) throw std::domain_error("Student s tim indeksom vec postoji");

    mapa_studenta[broj_indeksa] = new Student(broj_indeksa, godina_studija, ime_i_prezime, adresa_studenta, broj_telefona);
}

void Administracija::RegistrirajNoviLaptop (int ev_broj, std::string naziv, std::string karakteristike)
{
    if(mapa_laptopa.count(ev_broj) != 0) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    mapa_laptopa[ev_broj] = new Laptop(ev_broj, naziv, karakteristike);
}
Student &Administracija::NadjiStudenta(int broj_indeksa)
{
    if(!mapa_studenta.count(broj_indeksa)) throw std::domain_error ("Student nije nadjen");
    return *mapa_studenta[broj_indeksa];
}
Student Administracija::NadjiStudenta(int broj_indeksa) const
{
    if(!mapa_studenta.count(broj_indeksa)) throw std::domain_error ("Student nije nadjen");
    auto it = mapa_studenta.find(broj_indeksa);
    Student novi(it->second->DajIndeks(), it->second->DajGodinuStudija(), it->second->DajImePrezime(), it->second->DajAdresu(),
                 it->second->DajTelefon());
    return novi;
}
Laptop &Administracija::NadjiLaptop(int ev_broj)
{
    if(!mapa_laptopa.count(ev_broj)) throw std::domain_error ("Laptop nije nadjen");
    return *mapa_laptopa[ev_broj];

}
Laptop Administracija::NadjiLaptop(int ev_broj) const
{
    if(!mapa_laptopa.count(ev_broj)) throw std::domain_error ("Laptop nije nadjen");
    auto it = mapa_laptopa.find(ev_broj);
    Laptop novi(it->second->DajEvidencijskiBroj(), it->second->DajNaziv(), it->second->DajKarakteristike());
    return novi;
}
void Administracija::IzlistajStudente() const
{
    for(auto it = mapa_studenta.begin(); it != mapa_studenta.end(); it++) {
        it->second->Ispisi();
        std::cout << std::endl;
    }
}
void Administracija::IzlistajLaptope() const
{
    for(auto it = mapa_laptopa.begin(); it != mapa_laptopa.end(); it++) {
        it->second->Ispisi();
        if(it->second->DaLiJeZaduzen())
            std::cout << "Zaduzio(la): " << it->second->DajKodKogaJe().DajImePrezime() << " (" << it->second->DajKodKogaJe().DajIndeks() << ")";
        std::cout << std::endl;
    }
}

void Administracija::ZaduziLaptop(int broj_indeksa, int ev_broj)
{
    if(!mapa_studenta.count(broj_indeksa)) throw std::domain_error ("Student nije nadjen");
    if(!mapa_laptopa.count(ev_broj)) throw std::domain_error("Laptop nije nadjen");
    if(mapa_laptopa[ev_broj]->DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");

    for(auto it = mapa_laptopa.begin(); it != mapa_laptopa.end(); it++)
        if(it->second->DajPokKodKogaJe() && it->second->DajPokKodKogaJe()->DajIndeks() == broj_indeksa && it->second->DaLiJeZaduzen())
            throw std::domain_error("Student je vec zaduzio laptop");


    for(auto it = mapa_studenta.begin(); it != mapa_studenta.end(); it++)
        if (it->second->DajIndeks() == broj_indeksa) {
            mapa_laptopa[ev_broj]->DajPokKodKogaJe() = (it->second);
            break;
        }

}
int Administracija::NadjiSlobodniLaptop() const
{
    int brojac(0);

    Laptop* pok = nullptr;
    for(auto it = mapa_laptopa.begin(); it != mapa_laptopa.end(); it++) {
        if(!(it->second->DajPokKodKogaJe())) {
            pok = it->second;
            break;
        }
        brojac++;
    }
    if(brojac == mapa_laptopa.size()) throw std::domain_error("Nema slobodnih laptopa");

    return pok->DajEvidencijskiBroj();

}
void Administracija::RazduziLaptop(int ev_broj)
{
    if(!mapa_laptopa.count(ev_broj)) throw std::domain_error("Laptop nije nadjen");
    if(!mapa_laptopa[ev_broj]->DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen");
    mapa_laptopa[ev_broj]->Razduzi();
}
void Administracija::PrikaziZaduzenja() const
{
    int brojac_ispisa(0);
    for(auto it = mapa_laptopa.begin(); it != mapa_laptopa.end(); it++)
        if(it->second->DajPokKodKogaJe()) {
            std::cout << "Student " << it->second->DajKodKogaJe().DajImePrezime() << " ("<< it->second->DajKodKogaJe().DajIndeks()
            <<") zaduzio/la laptop broj "
                      << it->second->DajEvidencijskiBroj() << std::endl;
            brojac_ispisa++;
        }
    if(brojac_ispisa == 0) std::cout << "Nema zaduzenja" << std::endl;
}


int main ()
{
    Administracija etf ;

    etf.RegistrirajNoviLaptop(123, "Dell", "CPU 3.0 GHz, 4 GB RAM");
    etf.RegistrirajNoviLaptop(331, "ASUS", "CPU 3.5 GHz, 2 GB RAM");
    etf.RegistrirajNoviLaptop(122, "Dell 2", "CPU 3.2 GHz, 6 GB RAM");
    etf.RegistrirajNovogStudenta(14212, "1", "Benjamin", "Francuska revolucija 23", "12/34-56");
    etf.RegistrirajNovogStudenta(17528, "2","Ivan", "Trg vjecnih studenata 12", "048/597-585");

    etf.ZaduziLaptop(14212, 123);
    etf.ZaduziLaptop(17528, 331);

    etf.PrikaziZaduzenja();
}
