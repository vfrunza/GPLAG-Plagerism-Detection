#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <stdexcept>
#include <stdio.h>
#include <map>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::pair;

class Student {
	int br_ind;
	std::string god_studija, ime_prezime, adresa, br_tel;
	void NormalizirajImeIliAdresu(std::string &s);
	bool IspravnostGodineStudija(const std::string &godina_studija);
	bool IspravnostBrojaTelefona(const std::string &broj_telefona);
	bool IspravnostBrojaIndeksa(const int &bi) { return (bi >= 10000 && bi <= 99999); }
	bool Broj(const char &znak) { return znak >= '0' && znak <= '9'; }
public:
	Student(int br_ind, std::string god_studija, std::string ime_prezime, std::string adresa, std::string br_tel);
	int DajIndeks() const { return br_ind; }
	std::string DajGodinuStudija() const { return god_studija; }
	std::string DajImePrezime() const { return ime_prezime; }
	std::string DajAdresu() const { return adresa; }
	std::string DajTelefon() const { return br_tel; }
	void Ispisi() const;
	friend class Laptop;
	friend class Administracija;
};
//KLASA "STUDENT"
void Student::NormalizirajImeIliAdresu(std::string &s) {
	auto Pocetak(std::find_if(s.begin(), s.end(), [](const char &znak) { return znak != ' '; }));
	auto Kraj(s.end());
	Kraj--;
	while (Kraj != Pocetak) {
		if (*Kraj != ' ')
			break;
		Kraj--;
	}
	Kraj++;
	std::string Pomocni;
	std::copy(Pocetak, Kraj, back_inserter(Pomocni));
	auto novi_kraj(std::unique(Pomocni.begin(), Pomocni.end(), [](char l, char d) { return (l == d) && (l == ' '); }));
	Pomocni.erase(novi_kraj, Pomocni.end());
	s = Pomocni;
}
bool Student::IspravnostGodineStudija(const std::string &s) {
	static const std::vector<std::string> ValidneGS{ "1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D", "3/D" };
	if (std::count(ValidneGS.begin(), ValidneGS.end(), s)) return true; return false;
}
bool Student::IspravnostBrojaTelefona(const std::string &broj_telefona) {
	if (!Broj(broj_telefona[0])) return false;
	auto klizeci(broj_telefona.begin());
	while (klizeci != broj_telefona.end()) {
		while (Broj(*klizeci) && klizeci!=broj_telefona.end()) klizeci++;
		if (*klizeci != '/') return false;
		klizeci++;
		if (!Broj(*klizeci)) return false;
		while (Broj(*klizeci) && klizeci != broj_telefona.end()) klizeci++;
		if (*klizeci != '-') return false;
		klizeci++;
		if (!Broj(*klizeci)) return false;
		while (klizeci != broj_telefona.end()) {
			if (!Broj(*klizeci)) return false;
			klizeci++;
		}
	}
	return true;
}
void Student::Ispisi() const {
	cout << "Broj indeksa: " << DajIndeks() << endl;
	cout << "Godina studija: " << DajGodinuStudija();
	if (DajGodinuStudija() == "1" || DajGodinuStudija() == "2" || DajGodinuStudija() == "3") cout << "/B" << endl;
	else cout << endl; 
	cout << "Ime i prezime: " << DajImePrezime() << endl;
	cout << "Adresa: " << DajAdresu() << endl; 
	cout << "Telefon: " << DajTelefon() << endl; 
}
Student::Student(int br_ind, std::string god_studija, std::string ime_prezime, std::string adresa, std::string br_tel) {
	if (!IspravnostBrojaIndeksa(br_ind)) throw std::domain_error("Neispravni parametri");  
	if (!IspravnostGodineStudija(god_studija)) throw std::domain_error("Neispravni parametri");
	if (!IspravnostBrojaTelefona(br_tel)) throw std::domain_error("Neispravni parametri");
	NormalizirajImeIliAdresu(adresa);
	NormalizirajImeIliAdresu(ime_prezime);
	Student::br_ind = br_ind; Student::ime_prezime = ime_prezime; Student::adresa = adresa; Student::br_tel = br_tel;
	if(god_studija=="1" || god_studija=="2" || god_studija=="3") Student::god_studija = god_studija+"/B";
	else Student::god_studija = god_studija;
}

class Laptop {
	int ev_broj;
	std::string naziv, karakteristike;
	Student *kod_koga_je;
public:
	Laptop(int ev_broj, std::string naziv, std::string karakteristike);
	int DajEvidencijskiBroj() const { return ev_broj; }
	std::string DajNaziv() const { return naziv; }
	std::string DajKarakteristike() const { return karakteristike; }
	void Zaduzi(Student &stud) { if (kod_koga_je != nullptr) throw std::domain_error("Laptop vec zaduzen"); *kod_koga_je = stud; }
	void Razduzi() { kod_koga_je = nullptr; }
	bool DaLiJeZaduzen() { if (kod_koga_je == nullptr) return false; return true; }
	Student& DajKodKogaJe() { if (kod_koga_je == nullptr) throw std::domain_error("Laptop nije zaduzen"); return *kod_koga_je; }
	Student* DajPokKodKogaJe() { return kod_koga_je; }
	void Ispisi() const;
};
//KLASA "LAPTOP"
Laptop::Laptop(int ev_broj, std::string naziv, std::string karakteristike) {
	if (ev_broj<0) throw std::domain_error("Neispravni parametri");
	Laptop::ev_broj = ev_broj; Laptop::naziv = naziv; Laptop::karakteristike = karakteristike; kod_koga_je = nullptr;
}
void Laptop::Ispisi() const {
	cout << "Evidencijski broj: " << DajEvidencijskiBroj() << endl << "Naziv: " << DajNaziv() << endl << "Karakteristike: " << DajKarakteristike() << endl;
}

class Administracija {
	std::map<int, std::shared_ptr<Student>> Studenti;
	std::map<int, std::shared_ptr<Laptop>> Laptopi;

public:
	Administracija () {}
	Administracija (const Administracija &a);
	Administracija (Administracija &&a);
	Administracija &operator =(const Administracija &a);
	Administracija &operator =(Administracija &&a);
	void RegistrirajNovogStudenta (int br_ind, std::string god_studija, std::string ime_prezime, std::string adresa, std::string br_tel);
	void RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike);
	Student& NadjiStudenta (int brind);
	Laptop& NadjiLaptop(int evbr);
	Student NadjiStudenta(int brind) const;
	Laptop NadjiLaptop(int evbr) const;
	void IzlistajStudente () const;
	void IzlistajLaptope () const;
	void ZaduziLaptop(int brind, int evbr);
	int NadjiSlobodniLaptop();
	void RazduziLaptop(int evbroj);
	void PrikaziZaduzenja() const;
	~Administracija() { for (auto stud : Studenti) stud.second=nullptr; for (auto lapas : Laptopi) lapas.second=nullptr; }
};
//KLASA "ADMINISTRACIJA"

Administracija::Administracija(const Administracija &a) {
	for (auto its(a.Studenti.begin()); its != a.Studenti.end(); its++) 
		Studenti.emplace(its->first, its->second);
	for (auto itl(a.Laptopi.begin()); itl != a.Laptopi.end(); itl++)
		Laptopi.emplace(itl->first, itl->second);
}
Administracija::Administracija(Administracija &&a) {
	Administracija::Studenti = std::move(a.Studenti);
	Administracija::Laptopi = std::move(a.Laptopi);
	a.Studenti.clear(); a.Laptopi.clear();
}
void Administracija::RegistrirajNovogStudenta(int br_ind, std::string god_studija, std::string ime_prezime, std::string adresa, std::string br_tel) {
	auto Pretraga = Studenti.find(br_ind);
	if (Pretraga != Studenti.end()) throw std::domain_error("Student s tim indeksom vec postoji");
	Studenti.emplace(br_ind, std::make_shared<Student>(br_ind, god_studija, ime_prezime, adresa, br_tel));
}
void Administracija::RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike) {
	auto Pretraga = Laptopi.find(ev_broj);
	if (Pretraga != Laptopi.end()) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
	Laptopi.emplace(ev_broj, std::make_shared<Laptop>(ev_broj, naziv, karakteristike));
}
Student & Administracija::NadjiStudenta(int brind) {
	auto lokacija = Studenti.find(brind);
	if (lokacija == Studenti.end()) throw std::domain_error("Student nije nadjen");
	return *lokacija->second;
}
Student  Administracija::NadjiStudenta(int brind) const {
	auto lokacija = Studenti.find(brind);
	if (lokacija == Studenti.end()) throw std::domain_error("Student nije nadjen");
	return *lokacija->second;
}
Laptop & Administracija::NadjiLaptop(int evbr) {
	auto lokacija = Laptopi.find(evbr);
	if (lokacija == Laptopi.end()) throw std::domain_error("Laptop nije nadjen");
	return *lokacija->second;
}
Laptop  Administracija::NadjiLaptop(int evbr) const {
	auto lokacija = Laptopi.find(evbr);
	if (lokacija == Laptopi.end()) throw std::domain_error("Laptop nije nadjen");
	return *lokacija->second;
}
void Administracija::IzlistajStudente() const {
	for (auto Stud : Studenti) {
		Stud.second->Ispisi(); cout << endl;
	}
}
void Administracija::IzlistajLaptope() const {
	for (auto Lap : Laptopi) {
		Lap.second->Ispisi();
		if (Lap.second->DaLiJeZaduzen())
			cout << "Zaduzio(la): " << Lap.second->DajPokKodKogaJe()->DajImePrezime() << " (" << Lap.second->DajPokKodKogaJe()->DajIndeks() << ")" << endl;
		else
			cout << endl;
	}
}
void Administracija::ZaduziLaptop(int brind, int evbr) {
	auto RegStud(Studenti.find(brind));
	if (RegStud == Studenti.end()) throw std::domain_error("Student nije nadjen");
	auto RegLap(Laptopi.find(evbr));
	if(RegLap == Laptopi.end()) throw std::domain_error("Laptop nije nadjen");
	if (RegLap->second->DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
	for (auto laptop : Laptopi) {
		if(laptop.second->DaLiJeZaduzen())
			if(laptop.second->DajPokKodKogaJe()->DajIndeks()==brind) throw std::domain_error("Student je vec zaduzio laptop");
	}
	RegLap->second->Zaduzi(*RegStud->second);
}
int Administracija::NadjiSlobodniLaptop() {
	auto SlobodanLaptop(std::find_if(Laptopi.begin(), Laptopi.end(), [](const std::pair<int, const std::shared_ptr<Laptop>> &Lap) { return !(Lap.second->DaLiJeZaduzen());}));
	if (SlobodanLaptop == Laptopi.end()) throw std::domain_error("Nema slobodnih laptopa");
	return SlobodanLaptop->second->DajEvidencijskiBroj();
}
void Administracija::RazduziLaptop(int evbroj) {
	auto ZaRazduzit(Laptopi.find(evbroj));
	if (ZaRazduzit == Laptopi.end()) throw std::domain_error("Laptop nije nadjen");
	if (!ZaRazduzit->second->DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen");
	ZaRazduzit->second->Razduzi();
}
void Administracija::PrikaziZaduzenja() const {
	int brojac(0);
	std::for_each(Laptopi.begin(), Laptopi.end(), [&brojac](const std::pair<int, std::shared_ptr<Laptop>> Zaduzeni) {
		if (Zaduzeni.second->DaLiJeZaduzen()) {
			cout << "Student " << Zaduzeni.second->DajPokKodKogaJe()->DajImePrezime() << " (" << Zaduzeni.second->DajPokKodKogaJe()->DajIndeks() << ") zaduzio/la laptop broj " << Zaduzeni.second->DajEvidencijskiBroj() << endl;
			brojac++;
		}
	});
	if (!brojac) cout << "Nema zaduzenja" << endl;
}
Administracija &Administracija::operator =(const Administracija &a) {
	for (auto Stud : Studenti)
		Stud.second=nullptr;
	Studenti.clear();
	for (auto Lap : Laptopi)
		Lap.second=nullptr;
	Laptopi.clear();
	for (auto Studd : a.Studenti)
		Studenti.emplace(Studd.first, std::make_shared<Student>(*Studd.second));
	for (auto Lapp : a.Laptopi)
		Laptopi.emplace(Lapp.first, std::make_shared<Laptop>(*Lapp.second));
	return *this;
}
Administracija &Administracija::operator =(Administracija &&a) {
	std::swap(Studenti, a.Studenti);
	std::swap(Laptopi, a.Laptopi);
	return *this;
}


int main () {
    return 0;                  
}