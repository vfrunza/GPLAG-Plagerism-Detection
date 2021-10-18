/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <stdexcept>
#include <memory>

using namespace std;

struct Korisnik
{
    string ime, prezime, adresa, telefon;
};

class Knjiga
{
    string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* zaduzena;
    
    public:
        Knjiga(string naslov, string ime, string zanr, int godina) : naslov(naslov), ime_pisca(ime), zanr(zanr), godina_izdavanja(godina), zaduzena(nullptr) {}
        string DajNaslov() const { return naslov; }
        string DajAutora() const { return ime_pisca; }
        string DajZanr() const { return zanr; }
        int DajGodinuIzdavanja() const { return godina_izdavanja; }
        Korisnik* DajKodKogaJe() const { return zaduzena; }
        void ZaduziKnjigu(Korisnik &k) { zaduzena=&k; }
        void RazduziKnjigu() { zaduzena=nullptr; }
        bool DaLiJeZaduzena() const { if(zaduzena!=nullptr) return true; return false; }
};

class Biblioteka
{
    map <int, shared_ptr<Korisnik>> mapa_korisnika;
    map <int, shared_ptr<Knjiga>> mapa_knjiga;
    
    public:
        Biblioteka() {}
        ~Biblioteka(){}
        Biblioteka(const Biblioteka &biblioteka);
        Biblioteka(Biblioteka &&biblioteka);
        Biblioteka &operator =(const Biblioteka &biblioteka);
        Biblioteka &operator =(Biblioteka &&biblioteka);
        void RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime, string adresa, string telefon);
        void RegistrirajNovuKnjigu(int ev_broj, string naslov, string ime, string zanr, int godina);
        Korisnik &NadjiKorisnika(int clanski_broj) const;
        Knjiga &NadjiKnjigu(int ev_broj) const;
        void IzlistajKorisnike() const;
        void IzlistajKnjige() const;
        void ZaduziKnjigu(int ev_broj, int clanski_broj);
        void RazduziKnjigu(int ev_broj);
        void PrikaziZaduzenja(int clanski_broj) const;
};

Biblioteka::Biblioteka(const Biblioteka &biblioteka)
{
    try 
	{
		for(auto it=biblioteka.mapa_knjiga.begin(); it!=biblioteka.mapa_knjiga.end(); it++)
        	mapa_knjiga[it->first]=make_shared<Knjiga>(*it->second);
        
		for(auto it=biblioteka.mapa_korisnika.begin(); it!=biblioteka.mapa_korisnika.end(); it++)
        	mapa_korisnika[it->first]=make_shared<Korisnik>(*it->second);
	}
	catch(...) 
	{
		throw;
	}
}

Biblioteka &Biblioteka::operator =(const Biblioteka &biblioteka)
{
	for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
    {
    	it->second=nullptr;
	}
    
	for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
	{
    	it->second=nullptr;
	}
	
	for(auto it=biblioteka.mapa_knjiga.begin(); it!=biblioteka.mapa_knjiga.end(); it++)
    	mapa_knjiga[it->first]=make_shared<Knjiga>(*it->second);
    
	for(auto it=biblioteka.mapa_korisnika.begin(); it!=biblioteka.mapa_korisnika.end(); it++)
		mapa_korisnika[it->first]=make_shared<Korisnik>(*it->second);
		
	return *this;
}

Biblioteka &Biblioteka::operator =(Biblioteka &&biblioteka) 
{
    swap(mapa_knjiga, biblioteka.mapa_knjiga);
    swap(mapa_korisnika, biblioteka.mapa_korisnika);
    return *this;
}

Biblioteka::Biblioteka(Biblioteka &&biblioteka)
{   
	for(auto it=biblioteka.mapa_knjiga.begin(); it!=biblioteka.mapa_knjiga.end(); it++)
    {
    	mapa_knjiga[it->first]=it->second;
    	it->second=nullptr;
    }
        
	for(auto it=biblioteka.mapa_korisnika.begin(); it!=biblioteka.mapa_korisnika.end(); it++)
    {
    	mapa_korisnika[it->first]=it->second;
    	it->second=nullptr;
    }
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime, string adresa, string telefon)
{
	auto it(mapa_korisnika.find(clanski_broj));
    if(it!=mapa_korisnika.end()) throw logic_error("Korisnik vec postoji");
	
	Korisnik k;
	k.ime=ime; k.prezime=prezime; k.adresa=adresa; k.telefon=telefon;
	mapa_korisnika[clanski_broj]=make_shared<Korisnik>(k);
}

void Biblioteka::RegistrirajNovuKnjigu(int ev_broj, string naslov, string ime, string zanr, int godina)
{
	auto it(mapa_knjiga.find(ev_broj));
    if(it!=mapa_knjiga.end()) throw logic_error("Knjiga vec postoji");
	
	Knjiga k(naslov, ime, zanr, godina);
	mapa_knjiga[ev_broj]=make_shared<Knjiga>(k);
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) const
{
    auto it(mapa_korisnika.find(clanski_broj));
	if(it==mapa_korisnika.end()) throw logic_error("Korisnik nije nadjen");
	
	return *it->second;
}

Knjiga &Biblioteka::NadjiKnjigu(int ev_broj) const
{
	auto it(mapa_knjiga.find(ev_broj));
	if(it==mapa_knjiga.end()) throw logic_error("Knjiga nije nadjena");
	
	return *it->second;
}

void Biblioteka::IzlistajKorisnike() const
{
	for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
    {
    	cout << "Clanski broj: " << it->first << endl;
    	cout << "Ime i prezime: " << (it->second)->ime << " " << (it->second)->prezime << endl;
    	cout << "Adresa: " << (it->second)->adresa << endl;
    	cout << "Broj telefona: " << (it->second)->telefon << endl << endl;
    }
    return;
}

void Biblioteka::IzlistajKnjige() const
{
	for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
    {
    	cout << "Evidencijski broj: " << it->first << endl;
    	cout << "Naslov: " << (it->second)->DajNaslov() << endl;
    	cout << "Pisac: " << (it->second)->DajAutora() << endl;
    	cout << "Zanr: " << (it->second)->DajZanr() << endl;
    	cout << "Godina izdavanja: " << (it->second)->DajGodinuIzdavanja() << endl;
    	if((it->second)->DaLiJeZaduzena()) cout << "Zaduzena kod korisnika: " << ((it->second)->DajKodKogaJe())->ime  << " " << ((it->second)->DajKodKogaJe())->prezime << endl;
    	cout << endl;
    }
    return;
}

void Biblioteka::ZaduziKnjigu(int ev_broj, int clanski_broj)
{
	auto it1(mapa_knjiga.find(ev_broj));
	auto it2(mapa_korisnika.find(clanski_broj));
	if(it1==mapa_knjiga.end()) throw logic_error("Knjiga nije nadjena");
	if(it2==mapa_korisnika.end()) throw logic_error("Korisnik nije nadjen");
	if((it1->second)->DaLiJeZaduzena()) throw logic_error("Knjiga vec zaduzena");
	
	(it1->second)->Knjiga::ZaduziKnjigu(*(it2->second));
}

void Biblioteka::RazduziKnjigu(int ev_broj)
{
	auto it1(mapa_knjiga.find(ev_broj));
	if(it1==mapa_knjiga.end()) throw logic_error("Knjiga nije nadjena");
	if(!((it1->second)->DaLiJeZaduzena())) throw logic_error("Knjiga nije bila zaduzena");
	
	(it1->second)->Knjiga::RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) const
{
	auto it1(mapa_korisnika.find(clanski_broj));
	if(it1==mapa_korisnika.end()) throw logic_error("Korisnik nije nadjen");
	
	bool zaduzen(false);
	for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
	{
		if((it->second)->DaLiJeZaduzena() && (((it->second)->DajKodKogaJe())->ime==(it1->second)->ime) && (((it->second)->DajKodKogaJe())->prezime==(it1->second)->prezime) && (((it->second)->DajKodKogaJe())->adresa==(it1->second)->adresa) && (((it->second)->DajKodKogaJe())->telefon==(it1->second)->telefon))
		{
			zaduzen=true;
			cout << "Evidencijski broj: " << it->first << endl;
			cout << "Naslov: " << (it->second)->DajNaslov() << endl;
			cout << "Pisac: " << (it->second)->DajAutora() << endl;
			cout << "Zanr: " << (it->second)->DajZanr() << endl;
			cout << "Godina izdavanja: " << (it->second)->DajGodinuIzdavanja() << endl;
			cout << endl;
		}
	}
	if(!zaduzen) cout << "Nema zaduzenja za tog korisnika!" << endl;
	return;
}

int main ()
{
	Biblioteka bib;
	
	while(1)
	{
		int opcija;
		cout << "Izaberite ociju:" << endl << "0 - kraj" << endl << "1 - registriraj novog korisnika" << endl << "2 - registriraj novu knjigu" << endl << "3 - zaduzi knjigu" << endl << "4 - razduzi knjigu" << endl << "5 - izlistaj podatke" << endl;
		cin >> opcija;
		if(!cin) cin.clear();
		cin.ignore(10000, '\n');
		if(opcija<0 || opcija>5) cout << "Neispravna opcija. Molimo unesite ponovo." << endl;
		else if(opcija==0) break;
		else if(opcija==1)
		{
			ponovo1:
			try
			{
				int broj;
				string ime, prezime, adresa, br_telefona;
				cout << "Unesite clanski broj: ";
				cin >> broj;
				if(!cin) cin.clear();
				cin.ignore(10000, '\n');
				
				cout << "Unesite ime korisnika: ";
				getline(cin, ime);
				cout << "Unesite prezime korisnika: ";
				getline(cin, prezime);
				cout << "Unesite adresu korisnika: ";
				getline(cin, adresa);
				cout << "Unesite broj telefona korisnika: ";
				getline(cin, br_telefona);
				
				bib.RegistrirajNovogKorisnika(broj, ime, prezime, adresa, br_telefona);
				cout << "Korisnik uspjesno registrovan!" << endl;
			}
			catch(logic_error izuzetak)
			{
				cout << izuzetak.what() << ". Molimo unesite ponovo." << endl;
				if(!cin) cin.clear();
				cin.ignore(10000, '\n');
				goto ponovo1;
			}
		}
		else if(opcija==2)
		{
			ponovo2:
			try
			{
				int ev_broj, godina;
				string naslov, ime, zanr;
				cout << "Unesite evidencijski broj: ";
				cin >> ev_broj;
				if(!cin) cin.clear();
				cin.ignore(10000, '\n');
				
				cout << "Unesite naslov knjige: ";
				getline(cin, naslov);
				cout << "Unesite ime pisca: ";
				getline(cin, ime);
				cout << "Unesite zanr: ";
				getline(cin, zanr);
				cout << "Unesite godinu izdavanja: ";
				cin >> godina;
				
				bib.RegistrirajNovuKnjigu(ev_broj, naslov, ime, zanr, godina);
				cout << "Knjiga uspjesno registrovana!" << endl;
			}
			catch(logic_error izuzetak)
			{
				cout << izuzetak.what() << ". Molimo unesite ponovo." << endl;
				if(!cin) cin.clear();
				cin.ignore(10000, '\n');
				goto ponovo2;
			}
		}
		else if(opcija==3)
		{
			try
			{
				int ev_broj, clan_broj;
				cout << "Unesite evidencijski broj knjige koju zelite zaduziti: ";
				cin >> ev_broj;
				cout << "Unesite clanski broj korisnika: ";
				cin >> clan_broj;
				
				bib.ZaduziKnjigu(ev_broj, clan_broj);
				cout << "Knjiga uspjesno zaduzena!" << endl;
			}
			catch(logic_error izuzetak)
			{
				cout << izuzetak.what() << endl;
			}
		}
		else if(opcija==4)
		{
			try
			{
				int ev_broj;
				cout << "Unesite evidencijski broj knjige koju zelite razduziti: ";
				cin >> ev_broj;
				
				bib.RazduziKnjigu(ev_broj);
				cout << "Knjiga uspjesno razduzena!" << endl;
			}
			catch(logic_error izuzetak)
			{
				cout << izuzetak.what() << endl;
			}
		}
		else if(opcija==5)
		{
			while(1)
			{
				ponovo3:
				int opcija5;
				cout << "Izaberite opciju:" << endl << "0 - nazad" << endl << "1 - ispisi korisnike" << endl << "2 - ispisi knjige" << endl << "3 - ispisi zaduzenja" << endl;
				cin >> opcija5;
				if(opcija5<0 || opcija5>3)
				{
					cout << "Neispravna opcija. Molimo unesite ponovo." << endl;
					goto ponovo3;
				}
				else if(opcija5==0) break;
				else if(opcija5==1) bib.IzlistajKorisnike();
				else if(opcija5==2) bib.IzlistajKnjige();
				else if(opcija5==3)
				{
					try
					{
						int clan_broj;
						cout << "Unesite clanski broj korisnika cija zaduzenja zelite vidjeti: ";
						cin >> clan_broj;
						cout << "Zaduzenja korisnika sa tim clanskim brojem su:" << endl;
						bib.PrikaziZaduzenja(clan_broj);
					}
					catch(logic_error izuzetak)
					{
						cout << izuzetak.what() << endl;
					}
				}
			}
		}
	}
	
	return 0;
}
