/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>
#include <utility>
using namespace std; 
struct Korisnik{
  string ime, prezime, adresa, telefon;   
};
class Knjiga{
    string naslov, ime_pisca, zanr; 
    int godina_izdavanja; 
    Korisnik* zaduzenje;  
public:
    Knjiga(string naslov, string ime_pisca, string zanr, int godina_izdavanja){
        Knjiga::naslov=naslov; 
        Knjiga::ime_pisca=ime_pisca; 
        Knjiga::zanr=zanr; 
        Knjiga::godina_izdavanja=godina_izdavanja; 
        zaduzenje=nullptr; 
    }
    string DajNaslov() const {
        return naslov; 
    }
    string DajAutora() const {
        return ime_pisca; 
    }
    string DajZanr() const {
        return zanr; 
    }
    int DajGodinuIzdavanja() const {
        return godina_izdavanja; 
    }
    Korisnik* DajKodKogaJe() const {
        return zaduzenje; 
    }
    void ZaduziKnjigu(Korisnik &korisnik){
        zaduzenje=&korisnik; 
    }
    void RazduziKnjigu(){
        zaduzenje=nullptr; 
    }
    bool DaLiJeZaduzena() const {
        if(zaduzenje==nullptr) return false; 
        return true; 
    }
    
};
class Biblioteka{
	map<int, shared_ptr<Korisnik>> korisnici; 
	map<int, shared_ptr<Knjiga>> knjige; 
public:
    Biblioteka(){}
	Biblioteka(const Biblioteka &bib)=default; 
	Biblioteka(Biblioteka &&bib) : korisnici(bib.korisnici), knjige(bib.knjige) {
		for(auto i=bib.korisnici.begin(); i!=bib.korisnici.end(); i++){
			i->second=nullptr; 
		}
		for(auto i=bib.knjige.begin(); i!=bib.knjige.end(); i++){
			i->second=nullptr; 
		}
	}  
	void RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime, string adresa, string broj_telefona){
		if(korisnici.count(clanski_broj)) throw logic_error ("Korisnik vec postoji"); 
		Korisnik* novi=new Korisnik; 
		novi->ime=ime; 
		novi->prezime=prezime; 
		novi->adresa=adresa; 
		novi->telefon=broj_telefona; 
		shared_ptr<Korisnik> nov(novi); 
		korisnici.insert(make_pair(clanski_broj, nov)); 
	}
	void RegistrirajNovuKnjigu(int evidencijski_broj, string naslov, string pisac, string zanr, int godina){
		if(knjige.count(evidencijski_broj)) throw logic_error ("Knjiga vec postoji"); 
	    auto nova=make_shared<Knjiga>(Knjiga(naslov, pisac, zanr, godina)); 
		knjige.insert(make_pair(evidencijski_broj, nova)); 
	}
	~Biblioteka(){}
	Korisnik& NadjiKorisnika(int clanski_broj) const {
		if(!korisnici.count(clanski_broj)) throw logic_error ("Korisnik nije nadjen"); 
		return *(korisnici.find(clanski_broj))->second; 
	}
	Knjiga& NadjiKnjigu(int evidencijski_broj) const {
		if(!knjige.count(evidencijski_broj)) throw logic_error ("Knjiga nije nadjena"); 
		return *(knjige.find(evidencijski_broj))->second; 
	}
	void ZaduziKnjigu(int evidencijski_broj, int clanski_broj){
		if(!knjige.count(evidencijski_broj)) throw logic_error ("Knjiga nije nadjena");
		if(!korisnici.count(clanski_broj)) throw logic_error ("Korisnik nije nadjen"); 
		auto knjiga=knjige.find(evidencijski_broj);
		auto korisnik=korisnici.find(clanski_broj); 
		knjiga->second->ZaduziKnjigu(*(korisnik->second)); 
	}
	void RazduziKnjigu(int evidencijski_broj){
		if(!knjige.count(evidencijski_broj)) throw logic_error ("Knjiga nije nadjena");
		auto knjiga=knjige.find(evidencijski_broj); 
		if(knjiga->second->DaLiJeZaduzena()==false) throw logic_error("Knjiga nije zaduzena"); 
		knjiga->second->RazduziKnjigu(); 
	}
	void IzlistajKorisnike() const {
		for(auto i=korisnici.begin(); i!=korisnici.end(); i++){
			cout << "Clanski broj: " << i->first << endl; 
			cout << "Ime i prezime: " << (i->second)->ime << " " << (i->second)->prezime << endl; 
			cout << "Adresa: " << (i->second)->adresa << endl; 
			cout << "Broj telefona: " << (i->second)->telefon << endl; 
		}
	}
	void IzlistajKnjige()const {
		for(auto i=knjige.begin(); i!=knjige.end(); i++){
			cout << "Evidencijski broj: " << i->first << endl; 
			cout << "Naslov: " << (i->second)->DajNaslov() << endl; 
			cout << "Pisac: " << (i->second)->DajAutora() << endl; 
			cout << "Zanr: " << (i->second)->DajZanr() << endl; 
			cout << "Godina izdavanja: " << (i->second)->DajGodinuIzdavanja() << endl; 
			if(i->second->DajKodKogaJe()!=nullptr){
				cout << "Zaduzena kod korisnika: " << i->second->DajKodKogaJe()->ime << " " << i->second->DajKodKogaJe()->prezime; 
			}
		}
	}
	void PrikaziZaduzenja(int clanski_broj)const {
		if(!korisnici.count(clanski_broj)) throw logic_error ("Korisnik nije nadjen"); 
		int brojac=0; 
		auto p=(korisnici.find(clanski_broj))->second; 
		auto f(p.get()); 
		for(auto i=knjige.begin(); i!=knjige.end(); i++){
			if(i->second->DajKodKogaJe()==f){
				brojac++; 
				cout << "Evidencijski broj: " << i->first << endl; 
				cout << "Naslov: " << (i->second)->DajNaslov() << endl; 
				cout << "Pisac: " << (i->second)->DajAutora() << endl; 
				cout << "Zanr: " << (i->second)->DajZanr() << endl; 
				cout << "Godina izdavanja: " << (i->second)->DajGodinuIzdavanja() << endl; 
			}
		}
		if(brojac==0) cout << "Nema zaduzenja za tog korisnika!" << endl; 
	}
	
}; 
int main ()
{
	return 0;
}