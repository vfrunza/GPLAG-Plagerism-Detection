/// updating, solved locally (during c9 crash problems)
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <memory>

/** Implementation of Student class **/
class Student {
private:
    static std::set<std::string> const godine;
    int broj_indeksa;
    std::string ime_prezime, godina_studija, adresa, broj_telefona;
    
    void static TrimString(std::string& str);
    bool static notDigits(const std::string& str);
    bool static ValidatePhone(std::string& str);
public:
    Student(int br_indeksa, std::string study_year, std::string name, std::string address, std::string telephone);
    int DajIndeks() const { return broj_indeksa; }
    std::string DajGodinuStudija() const { return godina_studija + (godina_studija.length() == 1 ? "/B" : ""); }
    std::string DajImePrezime() const { return ime_prezime; }
	std::string DajAdresu() const { return adresa; }
	std::string DajTelefon() const { return broj_telefona; }
	void Ispisi() const;
};
// Implementation of Student class interface
std::set<std::string> const Student::godine = { "1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D", "3/D" };
void Student::TrimString(std::string& str) {
    auto new_end = std::unique(str.begin(), str.end(), [](char l, char r) { return (l == r) && (r == ' '); });
    str.erase(new_end, str.end());
    if(!str.empty() && str[0] == ' ') str.erase(0, 1);
    if(!str.empty() && str[str.size() - 1] == ' ') str.erase(str.size() - 1);
}
bool Student::notDigits(const std::string& str) {
    return str.length() == 0 || std::any_of(str.begin(), str.end(), [](char c) { return !::isdigit(c); });
}
bool Student::ValidatePhone(std::string& str) {
    int slash(0), line(0);
    bool check(false);
    std::all_of(str.begin(), str.end(), [&slash, &line, &check](char c) {
        if(c == '-') ++line;
        else if(c == '/') ++slash;
        return check = !(line > 1 || slash > 1 || line > slash);
    });
    if(!check || line == 0 || slash == 0) return false;
    size_t posSlash(str.find('/')), posLine(str.find('-'));
    return !(notDigits(str.substr(0, posSlash)) ||
            notDigits(str.substr(posSlash + 1, posLine - posSlash - 1)) ||
            notDigits(str.substr(posLine + 1, str.size() - 1)));
}
Student::Student(int br_indeksa, std::string study_year, std::string name, std::string address, std::string telephone) {
    std::string newphone;
    TrimString(name); TrimString(address);
    std::copy_if(telephone.begin(), telephone.end(), std::back_inserter(newphone), [](char c) { return c != ' '; });
    
    if(br_indeksa < 10000 || br_indeksa > 99999 || name.empty() || address.empty() || !ValidatePhone(newphone) || godine.find(study_year) == godine.end())
        throw std::domain_error("Neispravni parametri");
        
    Student::broj_indeksa = br_indeksa; Student::ime_prezime = name;
    Student::broj_telefona = newphone; // provjeriti da li ovaj se dodaj ili onaj ugly string
    Student::adresa = address;
    Student::godina_studija = study_year;
}
void Student::Ispisi() const {
    std::cout << "Broj indeksa: " << this->DajIndeks() << std::endl;
    std::cout << "Godina studija: " << this->DajGodinuStudija() << std::endl;
    std::cout << "Ime i prezime: " << this->DajImePrezime() << std::endl;
    std::cout << "Adresa: " << this->DajAdresu() << std::endl;
    std::cout << "Telefon: " << this->DajTelefon() << std::endl;
}
/** Implementation of Laptop class **/
class Laptop {
private:
    int ev_broj;
    std::string naziv, karakteristike;
    Student* kod_koga_je;
public:
    Laptop(int ev_broj, const std::string& naziv, const std::string& karakteristike);
    
    int DajEvidencijskiBroj() const { return ev_broj; }
    std::string DajNaziv() const { return naziv; }
    std::string DajKarakteristike() const { return karakteristike; }
    
    void Zaduzi(Student& student);
    void Zaduzi(std::shared_ptr<Student> student);
    void Razduzi();
    bool DaLiJeZaduzen() const;
    Student& DajKodKogaJe() const;
    Student* DajPokKodKogaJe() const { return this->kod_koga_je; }
    void Ispisi() const;
};
// Implementation of Laptop class interface
Laptop::Laptop(int ev_broj, const std::string& naziv, const std::string& karakteristike) : 
    ev_broj(ev_broj), naziv(naziv), karakteristike(karakteristike), kod_koga_je(nullptr) {
    
    if(ev_broj < 0 || naziv.empty() || karakteristike.empty()) /// PROVJERITI C2 DA LI SU OVO VALIDNI PARAMETRI
        throw std::domain_error("Neispravni parametri");
}
void Laptop::Zaduzi(Student& student) {
    if(this->DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
    kod_koga_je = &student;
}
void Laptop::Zaduzi(std::shared_ptr<Student> student) {
    if(this->DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
    kod_koga_je = student.get();
}
void Laptop::Razduzi() {
    if(this->DaLiJeZaduzen()) this->kod_koga_je = nullptr;
}
bool Laptop::DaLiJeZaduzen() const {
    return kod_koga_je != nullptr;
}
Student& Laptop::DajKodKogaJe() const {
    if(!this->DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen");
    return *this->DajPokKodKogaJe();
}
void Laptop::Ispisi() const {
    std::cout << "Evidencijski broj: " << this->DajEvidencijskiBroj() << std::endl;
    std::cout << "Naziv: " << this->DajNaziv() << std::endl;
    std::cout << "Karakteristike: " << this->DajKarakteristike() << std::endl;
}
/** Implementation of Administracija class **/
class Administracija {
private:
    std::map<int, std::shared_ptr<Student>> mapa_studenata;
    std::map<int, std::shared_ptr<Laptop>> mapa_laptopa;
    
    bool StudentPostoji(int broj_indeksa) const;
    bool LaptopPostoji(int ev_broj) const;
    void PrekopirajUMene(const Administracija& adm);
    void ObrisiPodatkeIzMapi();
public:
    Administracija();
    ~Administracija();
    
    Administracija(const Administracija& adm);
    Administracija(Administracija&& adm);
    Administracija& operator=(const Administracija& adm);
    Administracija& operator=(Administracija&& adm);
    
    void RegistrirajNovogStudenta(int br_indeksa, const std::string& study_year, const std::string& name,
									const std::string& address, const std::string& telephone);
	void RegistrirajNoviLaptop(int ev_broj, const std::string& naziv, const std::string& karakteristike);

    Student& NadjiStudenta(int br_indeksa);
    Student NadjiStudenta(int br_indeksa) const;
    Laptop& NadjiLaptop(int ev_broj);
    Laptop NadjiLaptop(int ev_broj) const;
    
    void IzlistajStudente() const;
    void IzlistajLaptope() const;
    void ZaduziLaptop(int broj_indeksa, int ev_broj);
    int NadjiSlobodniLaptop() const;
    void RazduziLaptop(int ev_broj);
    void PrikaziZaduzenja() const;
};
// Implementation of Administracija class interface
bool Administracija::StudentPostoji(int broj_indeksa) const { return mapa_studenata.find(broj_indeksa) != mapa_studenata.end(); }
bool Administracija::LaptopPostoji(int ev_broj) const { return mapa_laptopa.find(ev_broj) != mapa_laptopa.end(); }
void Administracija::PrekopirajUMene(const Administracija& adm) {
    for(auto laptop(adm.mapa_laptopa.begin()); laptop != adm.mapa_laptopa.end(); ++laptop)
        mapa_laptopa[laptop->first] = std::make_shared<Laptop>(*laptop->second);
    for(auto student(adm.mapa_studenata.begin()); student != adm.mapa_studenata.end(); ++student)
        mapa_studenata[student->first] = std::make_shared<Student>(*student->second);
}
void Administracija::ObrisiPodatkeIzMapi() {
    mapa_laptopa.clear(); mapa_studenata.clear();
}
Administracija::Administracija() : mapa_studenata(), mapa_laptopa() {}
Administracija::~Administracija() {
    this->ObrisiPodatkeIzMapi();
}
Administracija::Administracija(const Administracija& adm) {
    this->PrekopirajUMene(adm);
}
Administracija::Administracija(Administracija&& adm) : mapa_studenata(), mapa_laptopa() {
    std::swap(mapa_laptopa, adm.mapa_laptopa);
    std::swap(mapa_studenata, adm.mapa_studenata);
    adm.mapa_laptopa.clear(); adm.mapa_studenata.clear();
}
Administracija& Administracija::operator=(const Administracija& adm) {
    this->ObrisiPodatkeIzMapi();
    this->PrekopirajUMene(adm);
    return *this;
}
/// TESTIRATI RVALUE DODJELU SA NECIM STO VEC IMA U SEBI PODATKE
Administracija& Administracija::operator=(Administracija&& adm) {
    std::swap(mapa_laptopa, adm.mapa_laptopa);
    std::swap(mapa_studenata, adm.mapa_studenata);    
    adm.ObrisiPodatkeIzMapi();
    return *this;
}

void Administracija::RegistrirajNovogStudenta(int br_indeksa, const std::string& study_year, const std::string& name, 
												const std::string& address, const std::string& telephone) {
    if(StudentPostoji(br_indeksa))
        throw std::domain_error("Student s tim indeksom vec postoji");
    mapa_studenata[br_indeksa] = std::make_shared<Student>(br_indeksa, study_year, name, address, telephone);
}
void Administracija::RegistrirajNoviLaptop(int ev_broj, const std::string& naziv, const std::string& karakteristike) {
    if(LaptopPostoji(ev_broj))
        throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    mapa_laptopa[ev_broj] = std::make_shared<Laptop>(ev_broj, naziv, karakteristike);
}

Student& Administracija::NadjiStudenta(int br_indeksa) {
    if(!StudentPostoji(br_indeksa))
        throw std::domain_error("Student nije nadjen");
    return *mapa_studenata.at(br_indeksa);
}
Student Administracija::NadjiStudenta(int br_indeksa) const {
    if(!StudentPostoji(br_indeksa))
        throw std::domain_error("Student nije nadjen");
    return *mapa_studenata.at(br_indeksa);
}
Laptop& Administracija::NadjiLaptop(int ev_broj) {
    if(!LaptopPostoji(ev_broj))
        throw std::domain_error("Laptop nije nadjen");
    return *mapa_laptopa.at(ev_broj);
}
Laptop Administracija::NadjiLaptop(int ev_broj) const {
    if(!LaptopPostoji(ev_broj))
        throw std::domain_error("Laptop nije nadjen");
    return *mapa_laptopa.at(ev_broj);
}

void Administracija::IzlistajStudente() const {
    for(auto student(mapa_studenata.begin()); student != mapa_studenata.end(); ++student) {
        if(student->second != nullptr) {
            student->second->Ispisi();
            std::cout << std::endl;
        }
    }
}
void Administracija::IzlistajLaptope() const {
    for(auto laptop(mapa_laptopa.begin()); laptop != mapa_laptopa.end(); ++laptop /*,--_size*/) {
	    if(laptop->second != nullptr) {
    	    laptop->second->Ispisi();
    	    if(laptop->second->DaLiJeZaduzen())
    	        std::cout << "Zaduzio(la): " << laptop->second->DajPokKodKogaJe()->DajImePrezime() <<
    	                    " (" << laptop->second->DajPokKodKogaJe()->DajIndeks() << ")" << std::endl;
	            std::cout << std::endl;
	    }
    }
}
void Administracija::ZaduziLaptop(int broj_indeksa, int ev_broj) {
    if (!StudentPostoji(broj_indeksa))
		throw std::domain_error("Student nije nadjen");
    if (!LaptopPostoji(ev_broj))
		throw std::domain_error("Laptop nije nadjen");
	if (mapa_laptopa.at(ev_broj) != nullptr && mapa_laptopa.at(ev_broj)->DaLiJeZaduzen())
	    throw std::domain_error("Laptop vec zaduzen");
	    
    for(auto it(mapa_laptopa.begin()); it != mapa_laptopa.end(); ++it) 
        if(it->second != nullptr && it->second->DajPokKodKogaJe() == mapa_studenata[broj_indeksa].get())
            throw std::domain_error("Student je vec zaduzio laptop");

    mapa_laptopa[ev_broj]->Zaduzi(*mapa_studenata[broj_indeksa]);    
}
int Administracija::NadjiSlobodniLaptop() const {
    auto it = std::find_if(mapa_laptopa.begin(), mapa_laptopa.end(), [](const std::pair<int,  std::shared_ptr<Laptop>>& laptop) { return !laptop.second->DaLiJeZaduzen(); });
    if (it == mapa_laptopa.end())
        throw std::domain_error("Nema slobodnih laptopa");
    return it->first;
}
void Administracija::RazduziLaptop(int ev_broj) {
	if (!LaptopPostoji(ev_broj))
		throw std::domain_error("Laptop nije nadjen");
	if (!mapa_laptopa[ev_broj]->DaLiJeZaduzen())
		throw std::domain_error("Laptop nije zaduzen");
	
	mapa_laptopa[ev_broj]->Razduzi();
}
void Administracija::PrikaziZaduzenja() const {
    bool postoje_zaduzenja(false);
    for (auto laptop(mapa_laptopa.begin()); laptop != mapa_laptopa.end(); ++laptop) {
	    if (laptop->second != nullptr && laptop->second->DaLiJeZaduzen()) {
	        std::cout << "Student " << laptop->second->DajPokKodKogaJe()->DajImePrezime() << " (" << laptop->second->DajPokKodKogaJe()->DajIndeks() <<
                ") zaduzio/la laptop broj " << laptop->second->DajEvidencijskiBroj() << std::endl;
	        postoje_zaduzenja = true;
	    }
    }
    if(!postoje_zaduzenja)
        std::cout << "Nema zaduzenja" << std::endl;
}


/// MENU IMPLEMENTATION, would be better if class was made
void PrikaziMeni(Administracija& administracija);
template <class T>
T UnesiBroj(std::string welcomeMessage = "", std::string errorMessage = "") {
    std::cout << welcomeMessage;
    T input;
    for(;;) {
        std::cin >> input;
        if (!std::cin) {
            std::cin.clear(); std::cin.ignore(10000, '\n');
            std::cout << errorMessage << std::endl;
        }
        else break;
    }
    return input;
}
void RegistrirajLaptop(Administracija& administracija) {
    std::string naziv, karakteristike;
    int ev_broj(UnesiBroj<int>("Unesite evidencijski broj laptopa (0 za nazad): ", "Greska, unesite ponovo!"));
    if(ev_broj == 0) PrikaziMeni(administracija);
    
    std::cin.ignore(10000, '\n');
    std::cout << "Unesite naziv laptopa: "; std::getline(std::cin, naziv);
    std::cout << "Unesite karakteristike laptopa: "; std::getline(std::cin, karakteristike);
    try {
        administracija.RegistrirajNoviLaptop(ev_broj, naziv, karakteristike);
        std::cout << "Laptop " << administracija.NadjiLaptop(ev_broj).DajNaziv() << " (" << ev_broj << ") uspjesno registrovan.\n";
    }
    catch (std::exception& e) {
        std::cout << "Greska: " << e.what() << std::endl;
    }
    PrikaziMeni(administracija);
}
void RegistrirajStudenta(Administracija& administracija) {
    std::string godina, ime, adresa, broj;
    int indeks(UnesiBroj<int>("Unesite broj indeksa studenta (0 za nazad): ", "Greska, unesite ponovo!"));
    if(indeks == 0) PrikaziMeni(administracija);

    std::cin.ignore(10000, '\n');
    std::cout << "Unesite godinu studija studenta: "; std::getline(std::cin, godina);
    std::cout << "Unesite ime i prezime studenta: "; std::getline(std::cin, ime);
	std::cout << "Unesite adresu studenta: "; std::getline(std::cin, adresa);
	std::cout << "Unesite broj telefona studenta (prihvatljivo: 000/000-000): "; std::getline(std::cin, broj);
	try {
        administracija.RegistrirajNovogStudenta(indeks, godina, ime, adresa, broj);
        std::cout << "Student " << administracija.NadjiStudenta(indeks).DajImePrezime() << " (" << indeks << ") uspjesno registrovan.\n";
    }
    catch (std::exception& e) {
        std::cout << "Greska: " << e.what() << std::endl;
    }
    PrikaziMeni(administracija);
}
void IspisiStudenta(Administracija& administracija) {
    int indeks(UnesiBroj<int>("Unesite broj indeksa studenta (0 za nazad): ", "Greska, unesite ponovo!"));
    if(indeks == 0) PrikaziMeni(administracija);
    try {
        administracija.NadjiStudenta(indeks).Ispisi();
    }
    catch (std::exception& e) {
        std::cout << "Greska: " << e.what() << std::endl;
		IspisiStudenta(administracija);
    }
	PrikaziMeni(administracija);
}
void IspisiLaptop(Administracija& administracija) {
    int ev_broj(UnesiBroj<int>("Unesite evidencijski broj laptopa (0 za nazad): ", "Greska, unesite ponovo!"));
    if(ev_broj == 0) PrikaziMeni(administracija);
    try {
        administracija.NadjiLaptop(ev_broj).Ispisi();
    }
    catch (std::exception& e) {
        std::cout << "Greska: " << e.what() << std::endl;
		IspisiLaptop(administracija);
    }
	PrikaziMeni(administracija);
}
void PronadjiSlobodanLaptop(Administracija& administracija) {
    try {
        int id(administracija.NadjiSlobodniLaptop());
        std::cout << "Evidencijski broj prvog slobodnog laptopa je: " << id << std::endl;
    }
    catch (std::exception& e) {
		std::cout << "Info: " << e.what() << std::endl;
    }
	PrikaziMeni(administracija);
}
void ZaduziLaptop(Administracija& administracija) {
    int indeks(UnesiBroj<int>("Unesite broj indeksa studenta koji ce zaduziti laptop (0 za nazad): ", "Greska, unesite ponovo!"));
	if(indeks == 0) PrikaziMeni(administracija);
	int ev_broj(UnesiBroj<int>("Unesite evidencijski broj laptopa koji zaduzuje student: ", "Greska, unesite ponovo!"));
    try {
        administracija.ZaduziLaptop(indeks, ev_broj);
        std::cout << "Laptop " << administracija.NadjiLaptop(ev_broj).DajNaziv() << " (" << ev_broj << ") uspjesno zaduzen od studenta " << 
            administracija.NadjiStudenta(indeks).DajImePrezime() << " (" << indeks << ").\n";
    }
    catch (std::exception& e) {
		std::cout << "Greska: " << e.what() << std::endl;
    }
	PrikaziMeni(administracija);
}
void RazduziLaptop(Administracija& administracija) {
    int ev_broj(UnesiBroj<int>("Unesite evidencijski broj laptopa koji zelite razduziti (0 za nazad): ", "Greska, unesite ponovo!"));
	if(ev_broj == 0) PrikaziMeni(administracija);
    try {
		administracija.NadjiLaptop(ev_broj);
		std::string student = administracija.NadjiLaptop(ev_broj).DajPokKodKogaJe()->DajImePrezime();
		std::string naziv = administracija.NadjiLaptop(ev_broj).DajNaziv();
		int index = administracija.NadjiLaptop(ev_broj).DajKodKogaJe().DajIndeks();
		administracija.RazduziLaptop(ev_broj);
		std::cout << "Laptop " << naziv << "(" << ev_broj << ") uspjesno razduzen od studenta " << student << " (" << index << ").\n";
    }
    catch (std::exception& e) {
		std::cout << "Greska: " << e.what() << std::endl;
    }
	PrikaziMeni(administracija);
}

void PrikaziMeni(Administracija& administracija) {
    std::cout << std::endl << std::string(30, '*') << std::endl << "\tMoguce opcije" << std::endl << std::string(30, '*') << std::endl
        << "(1) Registriraj laptop\n"
        << "(2) Registriraj studenta\n"
        << "(3) Ispisi studenta\n"
        << "(4) Ispisi laptop\n"
        << "(5) Pronadji slobodan laptop\n"
        << "(6) Zaduzi laptop\n"
        << "(7) Razduzi laptop\n"
        << "(8) Ispisi sve studente\n"
        << "(9) Ispisi sve laptope\n"
        << "(10) Ispisi zaduzenja\n"
        << "(  0  ) Zavrsi evidenciju\n" << std::string(30, '*') << std::endl << std::endl;
    int option(UnesiBroj<int>("Unesite opciju: ", "Greska, unesite ponovo!"));
	for (; option < 0 || option > 10; )
	    option = UnesiBroj<int>("Nepostojeca opcija, unesite ponovo: ", "Greska, unesite ponovo!");
	    
    switch (option) {
        case 1: RegistrirajLaptop(administracija); break;
        case 2: RegistrirajStudenta(administracija); break;
        case 3: IspisiStudenta(administracija); break;
        case 4: IspisiLaptop(administracija); break;
        case 5: PronadjiSlobodanLaptop(administracija); break;
        case 6: ZaduziLaptop(administracija); break;
        case 7: RazduziLaptop(administracija); break;
        case 8: administracija.IzlistajStudente(), PrikaziMeni(administracija); break;
        case 9: administracija.IzlistajLaptope(), PrikaziMeni(administracija); break;
        case 10: administracija.PrikaziZaduzenja(), PrikaziMeni(administracija); break;
        default: break;
    }
}


int main () {
    Administracija admin;
    std::cout << "Dobrodosli na Rent-a-Laptop servis Elektrotehnickog fakulteta u Sarajevu.\nPrijavljeni ste kao Administrator.";
    PrikaziMeni(admin);
    std::cout << "Hvala Vam sto ste koristili nas servis.\n";
	return 0;
}