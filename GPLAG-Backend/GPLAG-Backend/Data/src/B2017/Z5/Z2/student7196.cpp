/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <utility>
#include <memory>
#include <vector>

class Student {
    int broj_indexa;
    std::string godina_studija;
    std::string ime_i_prezime;
    std::string adresa;
    std::string br_telefona;
    static bool Peterocifren(int broj) {
        return int(std::log10(broj))+1==5;
    }
public:
    Student(int broj_indexa, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::string br_telefona);
    int DajIndeks() const {
        return broj_indexa;
    }
    std::string DajGodinuStudija() const {
        if (godina_studija=="1") return "1/B";
        if (godina_studija=="2") return "2/B";
        if (godina_studija=="3") return "3/B";
        return godina_studija;
    }
    std::string DajImePrezime() const {
        return ime_i_prezime;
    }
    std::string DajAdresu() const {
        return adresa;
    }
    std::string DajTelefon() const {
        return br_telefona;
    }
    void Ispisi() const {
        std::cout << "Broj indeksa: " << DajIndeks() << std::endl;
        std::cout << "Godina studija: " << DajGodinuStudija() << std::endl;
        std::cout << "Ime i prezime: " << DajImePrezime() << std::endl;
        std::cout << "Adresa: " << DajAdresu() << std::endl;
        std::cout << "Telefon: " << DajTelefon();
        std::cout << std::endl;
    }
};

Student::Student(int broj_indexa, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::string br_telefona) {
    if (broj_indexa<=0) throw std::domain_error("Neispravni parametri");
    if (!Peterocifren(broj_indexa)) throw std::domain_error("Neispravni parametri");
    Student::broj_indexa=broj_indexa;
    std::vector<std::string> vektor_dozvoljenih{"1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D", "3/D"};
    if (std::find(vektor_dozvoljenih.begin(), vektor_dozvoljenih.end(), godina_studija)==vektor_dozvoljenih.end())
        throw std::domain_error("Neispravni parametri");
    Student::godina_studija=godina_studija;
    while (ime_i_prezime.length()>0 && ime_i_prezime.at(0)==' ') {
        ime_i_prezime.erase(ime_i_prezime.begin());
    }
    while (ime_i_prezime.length()>0 && ime_i_prezime.at(ime_i_prezime.length()-1)==' ') {
        ime_i_prezime.erase(ime_i_prezime.begin()+ime_i_prezime.length()-1);
    }
    for (int i=0; i<ime_i_prezime.length()-1; i++) {
        if (ime_i_prezime.substr(i, 2)=="  ") {
            ime_i_prezime.erase(ime_i_prezime.begin()+i);
            i-=2;
        }
        i++;
    }
    Student::ime_i_prezime=ime_i_prezime;
    while (adresa.length()>0 && adresa.at(0)==' ') {
        adresa.erase(adresa.begin());
    }
    while (adresa.length()>0 && adresa.at(adresa.length()-1)==' ') {
        adresa.erase(adresa.begin()+adresa.length()-1);
    }
    for (int i=0; i<adresa.length()-1; i++) {
        if (adresa.substr(i, 2)=="  ") {
            adresa.erase(adresa.begin()+i);
            i-=2;
        }
        i++;
    }
    Student::adresa=adresa;
    bool uredu(true);
    for (int i=0; i<br_telefona.length(); i++) {
        if (br_telefona.at(i)>='A' && br_telefona.at(i)<='Z') {
            uredu=false;
            break;
        }
        if (br_telefona.at(i)>='a' && br_telefona.at(i)<='z') {
            uredu=false;
            break;
        }
    }
    if (!uredu) throw std::domain_error("Neispravni parametri");
    bool pronadjena_kosa(false);
    int indeks_kose(0);
    for (int i=0; i<br_telefona.length(); i++) {
        if (br_telefona.at(i)=='/') {
            pronadjena_kosa=true;
            indeks_kose=i;
            break;
        }
    }
    if (!pronadjena_kosa) throw std::domain_error("Neispravni parametri");
    bool pronadjena_ravna(false);
    int indeks_ravne(0);
    for (int i=0; i<br_telefona.length(); i++) {
        if (br_telefona.at(i)=='-') {
            pronadjena_ravna=true;
            indeks_ravne=i;
            break;
        }
    }
    if (!pronadjena_ravna) throw std::domain_error("Neispravni parametri");
    uredu=true;
    for (int i=indeks_kose+1; i<br_telefona.length(); i++) {
        if (br_telefona.at(i)=='/') {
            uredu=false;
            break;
        }
    }
    if (!uredu) throw std::domain_error("Neispravni parametri");
    uredu=true;
    for (int i=indeks_ravne+1; i<br_telefona.length(); i++) {
        if (br_telefona.at(i)=='-') {
            uredu=false;
            break;
        }
    }
    if (!uredu) throw std::domain_error("Neispravni parametri");
    Student::br_telefona=br_telefona;
}


class Laptop {
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student* kod_koga_je;
public:
    Laptop(int ev_broj, std::string naziv, std::string karakteristike) : 
    ev_broj(ev_broj), naziv(naziv), karakteristike(karakteristike), kod_koga_je(nullptr) {
        if (ev_broj<0) throw std::domain_error("Neispravni parametri");
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
        if (kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je=&s;
    }
    void Razduzi() {
        if (kod_koga_je==nullptr) return;
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen() const {
        if (kod_koga_je==nullptr) return false;
        return true;
    }
    Student &DajKodKogaJe() const {
        if (kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen");
        return (*kod_koga_je);
    }
    Student* DajPokKodKogaJe() const {
        return kod_koga_je;
    }
    void Ispisi() const {
        std::cout << "Evidencijski broj: " << DajEvidencijskiBroj() << std::endl;
        std::cout << "Naziv: " << DajNaziv() << std::endl;
        std::cout << "Karakteristike: " << DajKarakteristike();
        std::cout << std::endl;
    }
};


class Administracija {
    std::map<int, std::shared_ptr<Student>> mapa_studenata;
    std::map<int, std::shared_ptr<Laptop>> mapa_laptopa;
public:
    Administracija()=default;
    Administracija(const Administracija &a);
    Administracija(Administracija &&a);
    Administracija &operator =(const Administracija &a);
    Administracija &operator =(Administracija &&a);
    ~Administracija();
    void RegistrirajNovogStudenta(int broj_indexa, std::string godina_studija, 
    std::string ime_i_prezime, std::string adresa, std::string br_telefona);
    void RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike);
    Student &NadjiStudenta(int broj_indexa);
    Student NadjiStudenta(int broj_indexa) const;
    Laptop &NadjiLaptop(int ev_broj);
    Laptop NadjiLaptop(int ev_broj) const;
    void IzlistajStudente() const;
    void IzlistajLaptope() const;
    void ZaduziLaptop(int broj_indexa, int ev_broj);
    int NadjiSlobodniLaptop() const;
    void RazduziLaptop(int ev_broj);
    void PrikaziZaduzenja() const;
};

Administracija::Administracija(const Administracija &a) {
    std::map<int, std::shared_ptr<Laptop>> mapa_laptopa1;
    for (auto iter=a.mapa_laptopa.begin(); iter!=a.mapa_laptopa.end(); iter++) {
        try {
            std::shared_ptr<Laptop> pok_na_laptop(std::make_shared<Laptop>(*(iter->second)));
            mapa_laptopa1.insert({iter->first, pok_na_laptop});
        }
        catch(...) {
            while (!mapa_laptopa1.empty())
                mapa_laptopa1.erase(mapa_laptopa1.begin());
            throw;
        }
    }
    std::map<int, std::shared_ptr<Student>> mapa_studenata1;
    for (auto iter=a.mapa_studenata.begin(); iter!=a.mapa_studenata.end(); iter++) {
        try {
            std::shared_ptr<Student> pok_na_studenta(std::make_shared<Student>(*(iter->second)));
            mapa_studenata1.insert({iter->first, pok_na_studenta});
        }
        catch(...) {
            while (!mapa_studenata1.empty())
                mapa_studenata1.erase(mapa_studenata1.begin());
            throw;
        }
    }
    while (!mapa_laptopa.empty())
        mapa_laptopa.erase(mapa_laptopa.begin());
    while (!mapa_studenata.empty())
        mapa_studenata.erase(mapa_studenata.begin());
    mapa_laptopa=mapa_laptopa1;
    mapa_studenata=mapa_studenata1;
}

Administracija::Administracija(Administracija &&a) {
    mapa_laptopa=a.mapa_laptopa;
    mapa_studenata=a.mapa_studenata;
    while (!a.mapa_laptopa.empty())
        a.mapa_laptopa.erase(a.mapa_laptopa.begin());
    while (!a.mapa_studenata.empty())
        a.mapa_studenata.erase(a.mapa_studenata.begin());
}

Administracija &Administracija::operator =(const Administracija &a) {
    if (&a==this) return *this;
    std::map<int, std::shared_ptr<Laptop>> mapa_laptopa1;
    for (auto iter=a.mapa_laptopa.begin(); iter!=a.mapa_laptopa.end(); iter++) {
        try {
            std::shared_ptr<Laptop> pok_na_laptop(std::make_shared<Laptop>(*(iter->second)));
            mapa_laptopa1.insert({iter->first, pok_na_laptop});
        }
        catch(...) {
            while (!mapa_laptopa1.empty())
                mapa_laptopa1.erase(mapa_laptopa1.begin());
            throw;
        }
    }
    std::map<int, std::shared_ptr<Student>> mapa_studenata1;
    for (auto iter=a.mapa_studenata.begin(); iter!=a.mapa_studenata.end(); iter++) {
        try {
            std::shared_ptr<Student> pok_na_studenta(std::make_shared<Student>(*(iter->second)));
            mapa_studenata1.insert({iter->first, pok_na_studenta});
        }
        catch(...) {
            while (!mapa_studenata1.empty())
                mapa_studenata1.erase(mapa_studenata1.begin());
            throw;
        }
    }
    while (!mapa_laptopa.empty())
        mapa_laptopa.erase(mapa_laptopa.begin());
    while (!mapa_studenata.empty())
        mapa_studenata.erase(mapa_studenata.begin());
    mapa_laptopa=mapa_laptopa1;
    mapa_studenata=mapa_studenata1;
    return *this;
}

Administracija &Administracija::operator =(Administracija &&a) {
    if (&a==this) return *this;
    while (!mapa_laptopa.empty())
        mapa_laptopa.erase(mapa_laptopa.begin());
    while (!mapa_studenata.empty())
        mapa_studenata.erase(mapa_studenata.begin());
    mapa_laptopa=a.mapa_laptopa;
    mapa_studenata=a.mapa_studenata;
    while (!a.mapa_laptopa.empty())
        a.mapa_laptopa.erase(a.mapa_laptopa.begin());
    while (!a.mapa_studenata.empty())
        a.mapa_studenata.erase(a.mapa_studenata.begin());
    return *this;
}

Administracija::~Administracija() {
    for (auto iter=mapa_laptopa.begin(); iter!=mapa_laptopa.end(); iter++) {
        (iter->second)->Razduzi();
    }
    while (!mapa_laptopa.empty())
        mapa_laptopa.erase(mapa_laptopa.begin());
    while (!mapa_studenata.empty())
        mapa_studenata.erase(mapa_studenata.begin());
}

void Administracija::RegistrirajNovogStudenta(int broj_indexa, std::string godina_studija, 
std::string ime_i_prezime, std::string adresa, std::string br_telefona) {
    if (mapa_studenata.find(broj_indexa)!=mapa_studenata.end())
        throw std::domain_error("Student s tim indeksom vec postoji");
    mapa_studenata[broj_indexa]=std::make_shared<Student>(broj_indexa, godina_studija, ime_i_prezime, adresa, br_telefona);
}

void Administracija::RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike) {
    if (mapa_laptopa.find(ev_broj)!=mapa_laptopa.end())
        throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    mapa_laptopa[ev_broj]=std::make_shared<Laptop>(ev_broj, naziv, karakteristike);
}

Student &Administracija::NadjiStudenta(int broj_indexa) {
    if (mapa_studenata.find(broj_indexa)==mapa_studenata.end())
        throw std::domain_error("Student nije nadjen");
    return (*mapa_studenata[broj_indexa]);
}

Student Administracija::NadjiStudenta(int broj_indexa) const {
    auto iter(mapa_studenata.find(broj_indexa));
    if (iter==mapa_studenata.end())
        throw std::domain_error("Student nije nadjen");
    return Student(*(iter->second));
}

Laptop &Administracija::NadjiLaptop(int ev_broj) {
    if (mapa_laptopa.find(ev_broj)==mapa_laptopa.end())
        throw std::domain_error("Laptop nije nadjen");
    return (*mapa_laptopa[ev_broj]);
}

Laptop Administracija::NadjiLaptop(int ev_broj) const {
    auto iter(mapa_laptopa.find(ev_broj));
    if (iter==mapa_laptopa.end())
        throw std::domain_error("Laptop nije nadjen");
    return Laptop(*(iter->second));
}

void Administracija::IzlistajStudente() const {
    for (auto iter=mapa_studenata.begin(); iter!=mapa_studenata.end(); iter++) {
        (iter->second)->Ispisi();
        auto it=iter;
        it++;
        if (it!=mapa_studenata.end()) std::cout << std::endl;
    }
}

void Administracija::IzlistajLaptope() const {
    for (auto iter=mapa_laptopa.begin(); iter!=mapa_laptopa.end(); iter++) {
        (iter->second)->Ispisi();
        if ((iter->second)->DaLiJeZaduzen()) {
            std::cout << "Zaduzio(la): " << ((iter->second)->DajPokKodKogaJe())->DajImePrezime();
            std::cout << " (" << ((iter->second)->DajPokKodKogaJe())->DajIndeks();
            std::cout << ")";
            std::cout << std::endl;
        }
        auto it=iter;
        it++;
        if (it!=mapa_laptopa.end()) std::cout << std::endl;
    }
}

void Administracija::ZaduziLaptop(int broj_indexa, int ev_broj) {
    auto nadji_studenta(mapa_studenata.find(broj_indexa));
    if (nadji_studenta==mapa_studenata.end())
        throw std::domain_error("Student nije nadjen");
    auto nadji_laptop(mapa_laptopa.find(ev_broj));
    if (nadji_laptop==mapa_laptopa.end())
        throw std::domain_error("Laptop nije nadjen");
    if ((nadji_laptop->second)->DaLiJeZaduzen())
        throw std::domain_error("Laptop vec zaduzen");
    for (auto iter=mapa_laptopa.begin(); iter!=mapa_laptopa.end(); iter++) {
        if ((iter->second)->DaLiJeZaduzen()) {
            if ((((iter->second)->DajPokKodKogaJe())->DajIndeks())==broj_indexa)
                throw std::domain_error("Student je vec zaduzio laptop");
        }
    }
    (nadji_laptop->second)->Zaduzi(*(nadji_studenta->second));
}

int Administracija::NadjiSlobodniLaptop() const {
    auto iter=std::find_if(mapa_laptopa.begin(), mapa_laptopa.end(), [](std::pair<int, std::shared_ptr<Laptop>> par) {
        return ((par.second)->DajPokKodKogaJe())==nullptr;
    });
    if (iter==mapa_laptopa.end()) {
        throw std::domain_error("Nema slobodnih laptopa");
    }
    return (iter->second)->DajEvidencijskiBroj();
}

void Administracija::RazduziLaptop(int ev_broj) {
    auto nadji_laptop(mapa_laptopa.find(ev_broj));
    if (nadji_laptop==mapa_laptopa.end())
        throw std::domain_error("Laptop nije nadjen");
    if ((nadji_laptop->second)->DajPokKodKogaJe()==nullptr)
        throw std::domain_error("Laptop nije zaduzen");
    (nadji_laptop->second)->Razduzi();
}

void Administracija::PrikaziZaduzenja() const {
    auto iter=std::find_if(mapa_laptopa.begin(), mapa_laptopa.end(), [](std::pair<int, std::shared_ptr<Laptop>> par) {
        return ((par.second)->DajPokKodKogaJe())!=nullptr;
    });
    if (iter==mapa_laptopa.end()) {
        throw std::domain_error("Nema zaduzenja");
    }
    for (auto iterat=mapa_laptopa.begin(); iterat!=mapa_laptopa.end(); iterat++) {
        if (((iterat->second)->DajPokKodKogaJe())!=nullptr) {
            std::cout << "Student ";
            std::cout << ((iterat->second)->DajPokKodKogaJe())->DajImePrezime();
            std::cout << " (";
            std::cout << ((iterat->second)->DajPokKodKogaJe())->DajIndeks();
            std::cout << ") zaduzio/la laptop broj ";
            std::cout << (iterat->second)->DajEvidencijskiBroj();
            std::cout << std::endl;
        }
    }
}

int main ()
{
	return 0;
}
