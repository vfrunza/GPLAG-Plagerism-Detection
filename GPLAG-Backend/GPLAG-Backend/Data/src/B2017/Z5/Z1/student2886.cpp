#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <utility>
#include <algorithm>
#include <iterator>
#include <vector>


class Student {
	int index;//mora biti petocifren
	std::string godina_studija;
    std::string ime_prezime;
	std::string adresa;
	std::string telefon;
	public:
	Student (int index, std::string godina_studija, std::string ime_prezime, std::string adresa, std::string telefon) {
		if (index<10000 || index>99999) throw std::domain_error ("Neispravni parametri");
		else Student::index=index;
		Student::godina_studija=godina_studija;
		Student::ime_prezime=ime_prezime;
		Student::adresa=adresa;
		Student::telefon=telefon;		//preskočila sve provjere
	}
	int DajIndex () const { return index; }
	std::string DajGodinuStudija () const { return godina_studija; }
	std::string DajImePrezime () const { return ime_prezime; }
	std::string DajAdresu () const { return adresa; }
	std::string DajTelefon () const { return telefon; }
	
	void Ispisi () const {
		std::cout<< "Broj indexa: " << index << std::endl <<
					"Godina studija: " << godina_studija << std::endl <<
					"Ime i prezime: " << ime_prezime << std::endl <<
					"Adresa: " << adresa << std::endl <<
					"Telefon: " << telefon << std::endl;
	}
};

class Laptop {
	int ev_broj;
	std::string naziv;
	std::string karakteristike;
	Student* kod_koga_je;
	public:
		Laptop (int ev_broj, std::string naziv, std::string karakteristike) : naziv(naziv), karakteristike(karakteristike) {
			if (ev_broj<0) throw std::domain_error("Neispravni parametri");
			else Laptop::ev_broj=ev_broj;
		}
		int DajEvidencijskiBroj () const { return ev_broj; }
		std::string DajNaziv () const { return naziv; }
		std::string DajKarakteristike () const { return karakteristike; }
		void Zaduzi (Student &student){ kod_koga_je=&student;}
		void Razduzi () { kod_koga_je=nullptr; }
		bool DaLiJeZaduzen () const { if (kod_koga_je==nullptr) return 0; else return 1;}
		Student& DajKodKogaJe () const { if (!DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen"); else return *kod_koga_je; }
		Student* DajPokKodKogaJe () const { return kod_koga_je; }
		void Ispisi () const {
			std::cout << "Evidencijski broj: " << ev_broj << std::endl 
					  << "Naziv: " << naziv << std::endl 
					  << "Karakteristike: " << karakteristike << std::endl;
		}
};

class Administracija {
	std::map<int, Student*> studenti;
	std::map<int, Laptop*> laptopi;
	
	bool DaLiPostojiStudent (int broj) const {
	    return bool(studenti.count(broj));
	}
	bool DaLiPostojiLaptop (int broj) const {
	    return bool(laptopi.count(broj));
	}
	bool DaLiJeZaduzio (int broj){
	    for (auto x : laptopi){
	        if(x.second->DajPokKodKogaJe()!=nullptr){
	        if (broj==x.second->DajKodKogaJe().DajIndex()) return true;
	        }
	    }
	    return false;
	}
	public:
	Administracija () {}
	Administracija (const Administracija &a);
	Administracija (Administracija &&a);
	Administracija& operator = (const Administracija &a);
	Administracija& operator = (Administracija &&a);
	~Administracija();
	
	void RegistrirajNovogStudenta (int index, std::string godina_studija, std::string ime_prezime, std::string adresa, std::string telefon);
	void RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike);
	Student& NadjiStudenta(int index);
	Student NadjiStudenta (int index) const;
	Laptop& NadjiLaptop (int ev_broj);
	Laptop NadjiLaptop (int ev_broj) const;
	void IzlistajStudente() const;
	void IzlistajLaptope() const;
	void ZaduziLaptop(int index, int ev_broj);
	int NadjiSlobodniLaptop () const;
	void RazduziLaptop (int ev_broj);
	void PrikaziZaduzenja () const;
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


Administracija::Administracija(const Administracija &a){
    try{
        for (auto x : a.studenti){
            studenti.insert(std::make_pair(x.first, new Student(*x.second)));
        }
        for( auto x : a.laptopi){
            laptopi.insert(std::make_pair(x.first, new Laptop(*x.second)));
        }
    } catch (...){
        for (auto x : a.studenti)
            delete x.second;
        for (auto x : a.laptopi)
            delete x.second;
        throw;
    }
}
Administracija::Administracija(Administracija &&a){
    studenti=std::move(a.studenti);
    laptopi=std::move(a.laptopi);
    a.studenti.clear();
    a.laptopi.clear();
}
Administracija& Administracija::operator = (const Administracija &a){
    if (&a!=this){
        for (auto x : studenti)
            delete x.second;
        for (auto x : laptopi)
            delete x.second;
        studenti.clear();
        laptopi.clear();
        for (auto x : a.studenti){
            studenti.insert(std::make_pair(x.first, new Student(*x.second)));
        }
        for( auto x : a.laptopi){
            laptopi.insert(std::make_pair(x.first, new Laptop(*x.second)));
        }
    }
    return *this;
}

Administracija& Administracija::operator = (Administracija &&a){
    std::swap(studenti, a.studenti);
    std::swap(laptopi, a.laptopi);
    return *this;
}

Administracija::~Administracija(){
    for (auto x : studenti)
            delete x.second;
        for (auto x : laptopi)
            delete x.second;
}

void Administracija::RegistrirajNovogStudenta(int index,
    std::string godina_studija, std::string ime_prezime, 
    std::string adresa, std::string telefon){
        if (DaLiPostojiStudent(index)) throw "error";
        else studenti.insert(std::make_pair(index, new Student(index,
                godina_studija,ime_prezime,adresa,telefon)));
    }
void Administracija::RegistrirajNoviLaptop(int ev_broj, 
                    std::string naziv, std::string karakteristike){
    if (DaLiPostojiLaptop(ev_broj)) throw "error";
    else laptopi.insert(std::make_pair(ev_broj, new Laptop(ev_broj,
                                        naziv,karakteristike)));
}
Student& Administracija::NadjiStudenta(int index){
    if (!DaLiPostojiStudent(index)) throw "error";
    return *studenti.find(index)->second;
}
Student Administracija::NadjiStudenta (int index) const {
    if (!DaLiPostojiStudent(index)) throw "error";
    return *studenti.find(index)->second;
}
Laptop& Administracija::NadjiLaptop (int ev_broj){
    if (!DaLiPostojiLaptop(ev_broj)) throw "error";
    return *laptopi.find(ev_broj)->second;
}
Laptop Administracija::NadjiLaptop (int ev_broj) const{
	if (!DaLiPostojiLaptop(ev_broj)) throw "error";
    return *laptopi.find(ev_broj)->second;
}
void Administracija::IzlistajStudente() const{
    for (auto x : studenti){
        x.second->Ispisi(); 
        std::cout << std::endl;
    }
}
void Administracija::IzlistajLaptope() const{
    for (auto x : laptopi){
        x.second->Ispisi();
        if (x.second->DaLiJeZaduzen()) std::cout << "Zaduzio(la): " << 
            x.second->DajKodKogaJe().DajImePrezime() << "(" << 
            x.second->DajKodKogaJe().DajIndex() << ")" << std::endl;
        std::cout << std::endl;
    }
}
void Administracija::ZaduziLaptop(int index, int ev_broj){
    if (!DaLiPostojiStudent(index)) throw "nema studenta";
    if (DaLiJeZaduzio(index)) throw "jest zaduzio";
    if (!DaLiPostojiLaptop(ev_broj)) throw "ne postoji laptop";
    if (laptopi[ev_broj]->DaLiJeZaduzen()) throw "zaduzen je";
        laptopi[ev_broj]->Zaduzi(*studenti[index]);
}
int Administracija::NadjiSlobodniLaptop () const{
    for (auto x : laptopi){
        if (!x.second->DaLiJeZaduzen()) return x.second->DajEvidencijskiBroj();
    }
    throw "Svi laptopi zauzeti!";
}
void Administracija::RazduziLaptop (int ev_broj){
    if (!DaLiPostojiLaptop(ev_broj)) throw "Laptop ne postoji";
    if (!laptopi[ev_broj]->DaLiJeZaduzen()) throw "Laptop nije zaduzen";
    laptopi[ev_broj]->Razduzi();
}
void Administracija::PrikaziZaduzenja () const{
    bool istina(false);
	    for (auto x : laptopi){
	        if (x.second->DaLiJeZaduzen()){
	       istina=true;
	        std::cout << "Student " << x.second->DajKodKogaJe().DajImePrezime() <<
	                    " (" << x.second->DajKodKogaJe().DajIndex() << 
	                    ") zaduzio/la laptop broj " << x.first << std::endl;
	        }
	    }
	    if (istina==false) std::cout << "Nema zaduzenja" << std::endl;
}
