/B2017/2018: ===TITLE===
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <string>
#include <map>
#include <utility>

class Student {
	int brojindeksa;
	std::string godina_studija, imeiprezime, adresa, brojtel;
	static bool DaLiJePetocifren(int broj);
	static bool DaLiJeIspravnaGodinaStudija(std::string godina_studija);
	static void ObrisiSveRazmake(std::string &adresa);
	static bool DaLiJeIspravanBrojTelefona(std::string broj_telefona);
public:
	Student(int broj_indeksa, std::string godst, std::string ime, std::string adress, std::string broj);
	int DajIndeks() const { return brojindeksa; }
	std::string DajGodinuStudija() const { return godina_studija; }
	std::string DajImePrezime() const { return imeiprezime; }
	std::string DajAdresu() const { return adresa; }
	std::string DajTelefon() const { return brojtel; }
	void Ispisi() const;
};
class Laptop {
	int ev_broj;
	std::string naziv;
	std::string karakteristike;
	Student* kod_koga_je;
public:
	Laptop(int broj, std::string nazivlaptopa, std::string characteristics);
	int DajEvidencijskiBroj() const{ return ev_broj; }
	std::string DajNaziv() const { return naziv; }
	std::string DajKarakteristike() const{ return karakteristike; }
	void Zaduzi(Student &student) { kod_koga_je = &student; }
	void Razduzi() { kod_koga_je = nullptr; }
	bool DaLiJeZaduzen() const { return kod_koga_je != nullptr; }
	Student& DajKodKogaJe() const { if (kod_koga_je == nullptr) throw std::domain_error("Laptop nije zaduzen"); return *kod_koga_je; }
	Student* DajPokKodKogaJe() const { return kod_koga_je; }
	void Ispisi() const;
};
class Administracija {
	std::map<int, Student*> studenti;
	std::map<int, Laptop*> laptopi;
	bool DaLiPostojiStudent(int indeks) const { return bool(studenti.count(indeks)); }
	bool DaLiPostojiLaptop(int evbroj) const { return bool(laptopi.count(evbroj)); }
	bool DaLiJeZaduzen(int evbroj);
	bool DaLiJeVecZaduzio(int indeks) const;
public:
	Administracija() {}
	Administracija(const Administracija &a);
	Administracija(Administracija &&a);
	Administracija& operator =(const Administracija &a);
	Administracija& operator =(Administracija &&);
	~Administracija();
	void RegistrirajNovogStudenta(int broj_indeksa, std::string godst, std::string ime, std::string adress, std::string broj);
	void RegistrirajNoviLaptop(int broj, std::string nazivlaptopa, std::string characteristics);
	Student& NadjiStudenta(int indeks);
	Student NadjiStudenta(int indeks) const;
	Laptop& NadjiLaptop(int evbroj);
	Laptop NadjiLaptop(int evbroj) const;
	void IzlistajStudente() const;
	void IzlistajLaptope() const;
	void ZaduziLaptop(int indeks, int evbroj);
	int NadjiSlobodniLaptop() const;
	void RazduziLaptop(int evbroj);
	void PrikaziZaduzenja() const;
};
int main()
{
	Administracija a;
	std::cout << "Dobrodosli na ETF" << std::endl;
	for (;;) {
		std::cout << "Unesite jednu od opcija: " << std::endl << "1 - Registriraj novi laptop" << std::endl << "2 - Registriraj novog studenta" << std::endl << "3 - Izlistaj laptope" << std::endl << "4 - Izlistaj studente" << std::endl << "5 - Nadji prvi slobodni laptop" << std::endl << "6 - Nadji laptop" << std::endl << "7 - Zaduzi laptop" << std::endl << "8 - Razduzi laptop" << std::endl << "9 - Prikazi sva zaduzenja" << std::endl << "10 - Kraj programa" << std::endl;
		int opcija;
		std::cin >> opcija;
		switch (opcija) {
		case 1: { std::cout << "Unesite evidencijski broj: ";
			int evbroj;
			std::cin >> evbroj;
			std::cout << "Unesite naziv i karakteristike laptopa: ";
			std::string naziv, karakteristike;
			std::cin.ignore(5, '\n');
			std::getline(std::cin, naziv); std::getline(std::cin, karakteristike);
			try {
				a.RegistrirajNoviLaptop(evbroj, naziv, karakteristike);
			}
			catch (std::domain_error e) {
				std::cout << e.what() << std::endl;
			}
			catch (...) {
				return 0;
			}
		} break;
		case 2: { std::cout << "Unesite indeks: ";
			int indeks;
			std::cin >> indeks;
			std::cout << "Unesite godinu studija, ime, adresu i broj telefona: ";
			std::string godstud, ime, adresa, brojtel;
			std::cin.ignore(5, '\n');
			std::getline(std::cin, godstud); std::getline(std::cin, ime); std::getline(std::cin, adresa); std::getline(std::cin, brojtel);
			try {
				a.RegistrirajNovogStudenta(indeks, godstud, ime, adresa, brojtel);
			}
			catch (std::domain_error e) {
				std::cout << e.what() << std::endl;
			}
			catch (...) {
				return 0;
			}
			break;
		}
		case 3: { a.IzlistajLaptope(); } break;
		case 4: { a.IzlistajStudente(); } break;
		case 5: { try {
			int evbroj = a.NadjiSlobodniLaptop(); std::cout << "Prvi slobodni laptop je laptop sa evidencijskim brojem " << evbroj;
		}
				catch (std::domain_error e) {
					std::cout << e.what() << std::endl;
				}
		}
				break;
		case 6: { std::cout << "Unesite evidencijski broj laptopa: ";
			int broj;
			std::cin >> broj;
			try {
				a.NadjiLaptop(broj).Ispisi();
			}
			catch (std::domain_error e) {
				std::cout << e.what() << std::endl;
			}
		}
				break;
		case 7: { std::cout << "Unesite evidencijski broj laptopa kojeg zelite zaduziti: ";
			int evbroj, indeks;
			std::cin >> evbroj;
			std::cout << "Unesite broj indeksa studenta koji zaduzuje laptop: ";
			std::cin >> indeks;
			try {
				a.ZaduziLaptop(indeks, evbroj);
				std::cout << "Laptop uspjesno zaduzen" << std::endl;
			}
			catch (std::domain_error e) {
				std::cout << e.what() << std::endl;
			}
		}
				break;
		case 8: { std::cout << "Unesite evidencijski broj laptopa kojeg zelite razduziti: ";
			int evbroj;
			std::cin >> evbroj;
			try {
				a.RazduziLaptop(evbroj);
				std::cout << "Laptop uspjesno razduzen" << std::endl;
			}
			catch (std::domain_error e) {
				std::cout << e.what() << std::endl;
			}
		} break;
		case 9: { a.PrikaziZaduzenja(); } break;
		default: { return 0; }
		}
	}
	return 0;
}

// IMPLEMENTACIJA 
	//Student::private
bool Student::DaLiJePetocifren(int broj) {
	return broj >= 10000 && broj <= 99999;
}
bool Student::DaLiJeIspravnaGodinaStudija(std::string godina_studija) {
	static const std::vector<std::string> godine{ "1","2","3","1/B","2/B","3/B","1/M","2/M","1/D","2/D","3/D" };
	return std::find(godine.begin(), godine.end(), godina_studija) != godine.end();
}
void Student::ObrisiSveRazmake(std::string &adresa) {
	std::string s;
	auto it = adresa.begin();
	bool loga2(false);
	std::remove_copy_if(adresa.begin(), adresa.end(), std::back_inserter(s),[&loga2, &it, &adresa](char c) { bool loga = !(c != ' ' || (it != adresa.begin() && it != adresa.end() - 1 && c == ' ' && *(it + 1) != ' ' && loga2)); if (c != ' ') loga2 = true; it++; return loga; });
	adresa = s;
}
bool Student::DaLiJeIspravanBrojTelefona(std::string broj_telefona) {
	bool daLiJeBilaCifra(false), daLiJeBilaKosa(false), daLiJeBilaCrta(false);
	for (char znak : broj_telefona) {
		if (znak >= '0' && znak <= '9') daLiJeBilaCifra = true;
		else if (znak == '/' && daLiJeBilaCifra && !daLiJeBilaCrta && !daLiJeBilaKosa) { daLiJeBilaKosa = true; daLiJeBilaCifra = false; }
		else if (znak == '-' && daLiJeBilaCifra && daLiJeBilaKosa && !daLiJeBilaCrta) { daLiJeBilaCrta = true; daLiJeBilaCifra = false; }
		else return false;
	}
	if (!daLiJeBilaKosa || !daLiJeBilaCrta) return false;
	return true;
}
	//Student::public
Student::Student(int broj_indeksa, std::string godst, std::string ime, std::string adress, std::string broj) {
	if (!DaLiJePetocifren(broj_indeksa) || !DaLiJeIspravnaGodinaStudija(godst) || !DaLiJeIspravanBrojTelefona(broj)) throw std::domain_error("Neispravni parametri");
	ObrisiSveRazmake(adress); ObrisiSveRazmake(ime);
	brojindeksa = broj_indeksa; godina_studija = godst; imeiprezime = ime; adresa = adress; brojtel = broj;
	if (godina_studija == "1" || godina_studija == "2" || godina_studija == "3") godina_studija+="/B";
}
void Student::Ispisi() const {
	std::cout << "Broj indeksa: " << DajIndeks() << std::endl << "Godina studija: " << DajGodinuStudija();
	if (godina_studija == "1" || godina_studija == "2" || godina_studija == "3") std::cout << "/B";
	std::cout << std::endl << "Ime i prezime: " << DajImePrezime() << std::endl << "Adresa: " << adresa << std::endl << "Telefon: " << brojtel << std::endl;
}

	//Laptop::public
Laptop::Laptop(int broj, std::string nazivlaptopa, std::string characteristics) : kod_koga_je(nullptr) {
	if (broj < 0) throw std::domain_error("Neispravni parametri");
	ev_broj = broj; naziv = nazivlaptopa; karakteristike = characteristics;
}
void Laptop::Ispisi() const {
	std::cout << "Evidencijski broj: " << ev_broj << std::endl << "Naziv: " << naziv << std::endl << "Karakteristike: " << karakteristike << std::endl;
}

	//Administracija::private
bool Administracija::DaLiJeVecZaduzio(int indeks) const {
	for (auto par : laptopi) {
		auto pok = par.second->DajPokKodKogaJe();
		if (pok == nullptr) continue;
		if (pok->DajIndeks() == indeks)
			return true;
	}
	return false;
}
bool Administracija::DaLiJeZaduzen(int evbroj) {
	return laptopi[evbroj]->DaLiJeZaduzen();
}
	//Administracija::public
Administracija::Administracija(const Administracija &a) {
	try {
		for (auto par : a.studenti) {
			studenti.emplace(par.first, new Student(*par.second));
		}
		for (auto par : a.laptopi) {
			laptopi.emplace(par.first, new Laptop(*par.second));
		}
	}
	catch (...) {
		for (auto par : studenti) 
			delete par.second;
		for (auto par : laptopi) 
			delete par.second;
		studenti.clear(); laptopi.clear();
		throw;
	}
}
Administracija::Administracija(Administracija &&a) : studenti(std::move(a.studenti)), laptopi(std::move(a.laptopi)) {
	a.studenti.clear(); a.laptopi.clear();
}
Administracija& Administracija::operator =(const Administracija &a) {
	if (&a != this) {
		auto mapastudenata = studenti;
		auto mapalaptopa = laptopi;
		try {
			for (auto par : a.studenti)
				if (!studenti.count(par.first))
					studenti.emplace(par.first, new Student(*par.second));
			for (auto par : a.laptopi)
				if (!laptopi.count(par.first))
					laptopi.emplace(par.first, new Laptop(*par.second));
		}
		catch (...) {
			for (auto it = studenti.begin(); it != studenti.end(); it++) {
				if (!mapastudenata.count(it->first)) {
					delete it->second; it = studenti.erase(it);
				}
			}
			for (auto it = laptopi.begin(); it != laptopi.end(); it++) {
				if (!mapalaptopa.count(it->first)) {
					delete it->second; it = laptopi.erase(it);
				}
			}
			throw;
		}
		for (auto it = studenti.begin(); it != studenti.end(); it++) {
			if (!a.studenti.count(it->first)) {
				delete it->second; it = studenti.erase(it);
			}
		}
		for (auto it = laptopi.begin(); it != laptopi.end(); it++) {
			if (!a.laptopi.count(it->first)) {
				delete it->second; it = laptopi.erase(it);
			}
		}
	}	
	return *this;
}
Administracija& Administracija::operator =(Administracija &&a) {
	std::swap(laptopi, a.laptopi); std::swap(studenti, a.studenti);
	return *this;
}
Administracija::~Administracija() {
	for (auto par : studenti)
		delete par.second;
	for (auto par : laptopi)
		delete par.second;
}
void Administracija::RegistrirajNovogStudenta(int broj_indeksa, std::string godst, std::string ime, std::string adress, std::string broj) {
	if (DaLiPostojiStudent(broj_indeksa)) throw std::domain_error("Student s tim indeksom vec postoji");
	studenti.emplace(broj_indeksa, new Student(broj_indeksa, godst, ime, adress, broj));
}
void Administracija::RegistrirajNoviLaptop(int broj, std::string nazivlaptopa, std::string characteristics) {
	if (DaLiPostojiLaptop(broj)) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
	laptopi.emplace(broj, new Laptop(broj, nazivlaptopa, characteristics));
}
Student& Administracija::NadjiStudenta(int indeks) {
	auto it = studenti.find(indeks);
	if (it == studenti.end()) throw std::domain_error("Student nije nadjen");
	return *it->second;
}
Student Administracija::NadjiStudenta(int indeks) const {
	auto it = studenti.find(indeks);
	if (it == studenti.end()) throw std::domain_error("Student nije nadjen");
	return *it->second;
}
Laptop& Administracija::NadjiLaptop(int evbroj) {
	auto it = laptopi.find(evbroj);
	if (it == laptopi.end()) throw std::domain_error("Laptop nije nadjen");
	return *it->second;
}
Laptop Administracija::NadjiLaptop(int evbroj) const {
	auto it = laptopi.find(evbroj);
	if (it == laptopi.end()) throw std::domain_error("Laptop nije nadjen");
	return *it->second;
}
void Administracija::IzlistajStudente() const {
	std::for_each(studenti.begin(), studenti.end(), [](std::pair<int, Student*> par) { par.second->Ispisi(); std::cout << std::endl; });
}
void Administracija::IzlistajLaptope() const {
	std::for_each(laptopi.begin(), laptopi.end(), [](std::pair<int, Laptop*> par) { 
		par.second->Ispisi(); 
		if (par.second->DaLiJeZaduzen())
			std::cout << "Zaduzio(la): " << par.second->DajPokKodKogaJe()->DajImePrezime() << " (" << par.second->DajPokKodKogaJe()->DajIndeks() << ")"<<std::endl;
		std::cout << std::endl; });
}
void Administracija::ZaduziLaptop(int indeks, int evbroj) {
	if (!DaLiPostojiStudent(indeks)) throw std::domain_error("Student nije nadjen");
	if (!DaLiPostojiLaptop(evbroj)) throw std::domain_error("Laptop nije nadjen");
	if (DaLiJeZaduzen(evbroj)) throw std::domain_error("Laptop vec zaduzen");
	if (DaLiJeVecZaduzio(indeks)) throw std::domain_error("Student je vec zaduzio laptop");
	laptopi[evbroj]->Zaduzi(*studenti[indeks]);
}
int Administracija::NadjiSlobodniLaptop() const {	
	int broj;
	bool nasao(false);	
	std::for_each(laptopi.begin(), laptopi.end(), [&broj,&nasao](std::pair<int, Laptop*> par) {
		if (!(par.second->DaLiJeZaduzen())) { nasao=true; broj=par.first; }
	});
	if (!nasao) throw std::domain_error("Nema slobodnih laptopa");
	return broj;
}
void Administracija::RazduziLaptop(int evbroj) {
	if (!DaLiPostojiLaptop(evbroj)) throw std::domain_error("Laptop nije nadjen");
	if (!DaLiJeZaduzen(evbroj)) throw std::domain_error("Laptop nije zaduzen");
	laptopi[evbroj]->Razduzi();
}
void Administracija::PrikaziZaduzenja() const {
	bool postojiLiZaduzen(false);
	std::for_each(laptopi.begin(), laptopi.end(), [&postojiLiZaduzen](std::pair<int, Laptop*> par) {
		if (par.second->DaLiJeZaduzen()) {
			std::cout << "Student " << par.second->DajKodKogaJe().DajImePrezime() << " (" << par.second->DajKodKogaJe().DajIndeks() << ") zaduzio/la laptop broj " << par.first << std::endl;
			postojiLiZaduzen = true;
		}
	});
	if (!postojiLiZaduzen) std::cout << "Nema zaduzenja" << std::endl;
}