/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>
using namespace std; 
struct Korisnik{
  string ime, prezime, adresa, telefon;   
};
class Knjiga{
    string naslov, ime_pisca, zanr; 
    int godina_izdavanja; 
    Korisnik *zaduzenje; 
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
	map<int, Korisnik*> korisnici; 
	map<int, Knjiga*> knjige; 
public:
	Biblioteka(){}
	// kopirajuci konstrktor
	Biblioteka(const Biblioteka &bib){
		
		//copy(bib.korisnici.begin(), bib.korisnici.end(), korisnici.begin()); 
		//copy(bib.knjige.begin(), bib.knjige.end(), knjige.begin()); 
	}
	// pomjerajuci konstrukor
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
		auto novi=new Korisnik; 
		novi->ime=ime; 
		novi->prezime=prezime; 
		novi->adresa=adresa; 
		novi->telefon=broj_telefona; 
		korisnici.insert(make_pair(clanski_broj, novi)); 
	}
	void RegistrirajNovuKnjigu(int evidencijski_broj, string naslov, string pisac, string zanr, int godina){
		if(knjige.count(evidencijski_broj)) throw logic_error ("Knjiga vec postoji"); 
		auto nova=new Knjiga(naslov, pisac, zanr, godina); 
		knjige.insert(make_pair(evidencijski_broj, nova)); 
	}
	~Biblioteka(){
		for(auto i=korisnici.begin(); i!=korisnici.end(); i++) delete i->second;  
		for(auto i=knjige.begin(); i!=knjige.end(); i++) delete i->second;
	}
	Korisnik& NadjiKorisnika(int clanski_broj) const{
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
		knjiga->second->Knjiga::ZaduziKnjigu(*(korisnik->second)); 
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
	void IzlistajKnjige() const {
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
	void PrikaziZaduzenja(int clanski_broj) const {
		if(!korisnici.count(clanski_broj)) throw logic_error ("Korisnik nije nadjen"); 
		int brojac=0; 
		for(auto i=knjige.begin(); i!=knjige.end(); i++){
			if(i->second->DajKodKogaJe()==(korisnici.find(clanski_broj)->second)){
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
Biblioteka bib8;
bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib8.RegistrirajNovogKorisnika(2, "emina", "catic", "brace bezdrob bb", "364 379");
bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
bib8.ZaduziKnjigu(2, 2);
try{
 
bib8.PrikaziZaduzenja(1); cout << endl; 
 bib8.PrikaziZaduzenja(2);  cout << endl; 
bib8.PrikaziZaduzenja(3); cout << endl; 
}
catch(logic_error poruka){
	cout << poruka.what() << endl; 
}


	return 0;
}