/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
//Zadatak greskom pisan u folderu Tutorijal 12, Zadatak 3.

struct Korisnik {
	std::string ime;
	std::string prezime;
	std::string adresa;
	std::string telefon;
};
class Knjiga {
	std::string naslov;
	std::string ime_pisca;
	std::string zanr;
	int g_izdavanja;
	Korisnik *zaduzenik;
public:
	Knjiga(std::string hdln, std::string wrtr, std::string gnre, int ypub) : naslov(hdln), ime_pisca(wrtr), zanr(gnre), g_izdavanja(ypub) {zaduzenik=nullptr;}
	std::string DajNaslov() const { return naslov; }
	std::string DajAutora() const { return ime_pisca; }
	std::string DajZanr() const { return zanr; }
	int DajGodinuIzdavanja() const { return g_izdavanja; }
	Korisnik *DajKodKogaJe() const { return zaduzenik; }
	void ZaduziKnjigu(Korisnik &korisnik) { zaduzenik = &korisnik; }
	void RazduziKnjigu() { zaduzenik = nullptr; }
	bool DaLiJeZaduzena() { if(zaduzenik) return true; return false; }
};

class Biblioteka {
	std::map<int, Korisnik*> korisnici;
	std::map<int, Knjiga*> knjige;
public:
	Biblioteka();
	Biblioteka(const Biblioteka &b);
	Biblioteka(Biblioteka &&b);
	Biblioteka &operator=(const Biblioteka &b);
	Biblioteka &operator=(Biblioteka &&b);
	void RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon);
	void RegistrirajNovuKnjigu(int ev_broj, std::string naslov, std::string ime, std::string zanr, int ypub);
	Korisnik &NadjiKorisnika(int cl_broj);
	Knjiga &NadjiKnjigu(int ev_broj);
	void IzlistajKorisnike() const;
	void IzlistajKnjige() const;
	void ZaduziKnjigu(int ev_broj, int cl_broj);
	void RazduziKnjigu(int ev_broj);
	void PrikaziZaduzenja(int cl_broj) const;
	~Biblioteka();
};

Biblioteka::Biblioteka() {}
Biblioteka::Biblioteka(const Biblioteka &b) : korisnici(b.korisnici), knjige(b.knjige) {
	auto it2 = b.korisnici.begin();
	for(auto it1=korisnici.begin(); it1!=korisnici.end(); it1++){
		it1->second = new Korisnik(*(it2->second));
		it2++;
	}
}
Biblioteka::Biblioteka(Biblioteka &&b) : korisnici(b.korisnici), knjige(b.knjige){
	for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++){
		it->second = nullptr;
	}
	for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++){
		it->second = nullptr;
	}
}
Biblioteka &Biblioteka::operator=(const Biblioteka &b){
	auto it2 = b.korisnici.begin();
	for(auto it1=korisnici.begin(); it1!=korisnici.end(); it1++){
		it1->second = new Korisnik(*(it2->second));
		it2++;
	}
	return *this;
}
Biblioteka &Biblioteka::operator=(Biblioteka &&b){
	for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++){
		it->second = nullptr;
	}
	for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++){
		it->second = nullptr;
	}
	return *this;
}
Biblioteka::~Biblioteka(){
	for(auto it=korisnici.begin(); it!=korisnici.end(); it++){ delete it->second; }
	for(auto it=knjige.begin(); it!=knjige.end(); it++){ delete it->second; }
}

void Biblioteka::RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
	if(korisnici.count(cl_broj)>0) throw std::logic_error("Korisnik vec postoji");
	Korisnik *temp = new Korisnik;
	temp->ime = ime; temp->prezime = prezime; temp->adresa = adresa; temp->telefon = telefon;
	korisnici[cl_broj] = temp;
}
void Biblioteka::RegistrirajNovuKnjigu(int ev_broj, std::string naslov, std::string ime, std::string zanr, int ypub){
	if(knjige.count(ev_broj)>0) throw std::logic_error("Korisnik vec postoji");
	Knjiga *temp = new Knjiga(naslov, ime, zanr, ypub);
	knjige[ev_broj] = temp;
}
Korisnik &Biblioteka::NadjiKorisnika(int cl_broj){
	auto it = korisnici.find(cl_broj);
	if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
	return *it->second;
}
Knjiga &Biblioteka::NadjiKnjigu(int ev_broj){
	auto it = knjige.find(ev_broj);
	if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
	return *it->second;
}

void Biblioteka::IzlistajKorisnike() const {
	for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
		std::cout << "Clanski broj: "<< it->first << std::endl;
		std::cout << "Ime i prezime: "<< it->second->ime << " " << it->second->prezime << std::endl;
		std::cout << "Adresa: "<< it->second->adresa << std::endl;
		std::cout << "Broj telefona: "<< it->second->telefon << std::endl;
		std::cout << std::endl;
	}
}
void Biblioteka::IzlistajKnjige() const {
	for(auto it=knjige.begin(); it!=knjige.end(); it++){
		std::cout << "Evidencijski broj: " << it->first << std::endl;
		std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
		std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
		std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
		std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
		if(it->second->DaLiJeZaduzena()) std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime << std::endl;
		std::cout << std::endl;
	}
}

void Biblioteka::ZaduziKnjigu(int ev_broj, int cl_broj){
	if(knjige.count(ev_broj) == 0) throw std::logic_error("Knjiga nije nadjena");
	if(korisnici.count(cl_broj) == 0) throw std::logic_error("Korisnik nije nadjen");
	if(knjige[ev_broj]->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
	knjige[ev_broj]->ZaduziKnjigu(*korisnici[cl_broj]);
}
void Biblioteka::RazduziKnjigu(int ev_broj){
	if(knjige.count(ev_broj)==0) throw std::logic_error("Knjiga nije nadjena");
	if(!knjige[ev_broj]->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
	knjige[ev_broj]->RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int cl_broj) const{
	if(korisnici.count(cl_broj)==0) throw std::logic_error("Korisnik nije nadjen");
	for(auto it=knjige.begin(); it!=knjige.end(); it++){
		if(it->second->DajKodKogaJe()->ime == korisnici.find(cl_broj)->second->ime){
			std::cout << "Evidencijski broj: " << it->first << std::endl;
			std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
			std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
			std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
			std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
			std::cout << std::endl;
		}
	}
}

int main ()
{
	Biblioteka bib5;
	bib5.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
	bib5.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
	
	Biblioteka bib6(bib5);
	std::cout << bib6.NadjiKnjigu(2).DajNaslov();
	return 0;
}