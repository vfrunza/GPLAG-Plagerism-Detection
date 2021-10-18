/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <stdexcept>
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Korisnik {
    string ime, prezime, adresa, telefon;
};

class Knjiga {
    string Naslov, ImePisca, Zanr;
    int GodinaIzdavanja;
    Korisnik *pok=nullptr;
    public:
    
    Knjiga(string naslov_knjige, string ime_pisca, string zanr_knjige, int god_izdanja): Naslov(naslov_knjige), ImePisca(ime_pisca), Zanr(zanr_knjige), GodinaIzdavanja(god_izdanja) {};
    string DajNaslov() const { return Naslov; };
    string DajAutora() const { return ImePisca; };
    string DajZanr() const { return Zanr; };
    int DajGodinuIzdavanja() const { return GodinaIzdavanja; };
    Korisnik* DajKodKogaJe() const { return pok; };
    void ZaduziKnjigu(Korisnik &k) { pok=&k; };
    void RazduziKnjigu() { pok=nullptr; };
    bool DaLiJeZaduzena() { if(pok!=nullptr) return true; else return false; };
};

class Biblioteka {
      map< int, Korisnik* > MapaKorisnika;
      map< int, Knjiga*   > MapaKnjiga;
      public:
      Biblioteka() {} ;
      Biblioteka( const Biblioteka &bib);
      Biblioteka( Biblioteka && bib);
      Biblioteka &operator =(const Biblioteka &bib);
      Biblioteka &operator =(Biblioteka &&bib);
      ~Biblioteka() { 
          auto it=MapaKnjiga.begin(); auto it2=MapaKorisnika.begin();
          while(it!=MapaKnjiga.end()) { delete it->second; it->second=nullptr; it++; }
          while(it2!=MapaKorisnika.end()) { delete it2->second; it2->second=nullptr; it2++; }
      }
      void RegistrirajNovogKorisnika( int clanski_broj, string ime, string prezime, string adresa, string br_telefona);
      void RegistrirajNovuKnjigu(int ev_broj, string naslov, string ime_pisca, string z, int god_izdanja);
      Korisnik& NadjiKorisnika(int clanski_broj) const;
      Knjiga& NadjiKnjigu(int ev_broj) const ;
      void IzlistajKorisnike() const;
      void IzlistajKnjige() const;
      void ZaduziKnjigu(int ev_broj, int clanski_broj);
      void RazduziKnjigu(int ev_broj);
      void PrikaziZaduzenja(int clanski_broj);
};

Biblioteka::Biblioteka( const Biblioteka &bib) {
    auto it=bib.MapaKorisnika.begin();
    while(it!=bib.MapaKorisnika.end()) {
        MapaKorisnika.insert(make_pair(it->first, new Korisnik(*(it->second))));
        it++;
    }
    auto it2=bib.MapaKnjiga.begin();
    while(it2!=bib.MapaKnjiga.end()) {
        MapaKnjiga.insert(make_pair(it2->first, new Knjiga(*(it2->second))));
        it2++;
    }
}

Biblioteka::Biblioteka( Biblioteka && bib){
    auto it=bib.MapaKorisnika.begin();
    while(it!=bib.MapaKorisnika.end()) {
        MapaKorisnika.insert(make_pair(it->first, it->second));
        it->second=nullptr;
        it++;
    }
    auto it2=bib.MapaKnjiga.begin();
    while(it2!=bib.MapaKnjiga.end()) {
        MapaKnjiga.insert(make_pair(it2->first, it2->second));
        it2->second=nullptr;
        it2++;
    }
}

Biblioteka &Biblioteka::operator =(const Biblioteka &bib) {
    if(this==&bib) return *this;
    auto it=MapaKorisnika.begin();
    while(it!=MapaKorisnika.end()) { delete it->second; MapaKorisnika.erase(it);  it++; }
    auto it2=MapaKnjiga.begin();
    while(it2!=MapaKnjiga.end()) { delete it2->second; MapaKnjiga.erase(it2); it2++; }
   
    auto it3=bib.MapaKorisnika.begin();
    while(it3!=bib.MapaKorisnika.end()) { MapaKorisnika.insert(make_pair(it3->first,new Korisnik(*(it3->second)))); it3++; }
    auto it4=bib.MapaKnjiga.begin();
    while(it4!=bib.MapaKnjiga.end()) { MapaKnjiga.insert(make_pair(it4->first, new Knjiga(*(it4->second)))); it4++; }
    
    return *this;
}

Biblioteka &Biblioteka::operator =(Biblioteka &&bib) {
    if(this==&bib) return *this;
    auto it=MapaKorisnika.begin();
    while(it!=MapaKorisnika.end()) { delete it->second; MapaKorisnika.erase(it); it++; }
    auto it2=MapaKnjiga.begin();
    while(it2!=MapaKnjiga.end()) { delete it2->second; MapaKnjiga.erase(it2); it2++; }
    
    auto it3=bib.MapaKorisnika.begin();
    while(it3!=bib.MapaKorisnika.end()) { MapaKorisnika.insert(make_pair(it3->first, it3->second)); it3->second=nullptr; it3++; }
    auto it4=bib.MapaKnjiga.begin();
    while(it4!=bib.MapaKnjiga.end()) { MapaKnjiga.insert(make_pair(it4->first, it4->second)); it4->second=nullptr; it4++; }
    
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika( int clanski_broj, string ime, string prezime, string adresa, string br_telefona) {
    auto it=MapaKorisnika.begin();
    while(it!=MapaKorisnika.end()) { if(it->first==clanski_broj) throw logic_error ("Korisnik vec postoji"); it++; }
    Korisnik k;
    k.ime=ime; k.prezime=prezime; k.adresa=adresa; k.telefon=br_telefona;
    MapaKorisnika.insert(make_pair(clanski_broj, new Korisnik(k)));
}

void Biblioteka::RegistrirajNovuKnjigu(int ev_broj, string naslov, string ime_pisca, string z, int god_izdanja){
    auto it=MapaKnjiga.begin();
    while(it!=MapaKnjiga.end()) { if(it->first==ev_broj) throw logic_error ("Knjiga vec postoji"); it++; }
    
    Knjiga k(naslov, ime_pisca, z, god_izdanja);
    MapaKnjiga.insert(make_pair(ev_broj, new Knjiga(k)));
}

Korisnik& Biblioteka::NadjiKorisnika(int clanski_broj) const {
    auto it=MapaKorisnika.begin();
    while(it!=MapaKorisnika.end()) { if(it->first==clanski_broj) return *(it->second); it++; }
    throw logic_error ("Korisnik nije nadjen");
}

Knjiga& Biblioteka::NadjiKnjigu(int ev_broj) const {
    auto it=MapaKnjiga.begin();
    while(it!=MapaKnjiga.end()) { if(it->first==ev_broj) return *(it->second); it++; }
    throw logic_error ("Knjiga nije nadjena");
}

void Biblioteka::IzlistajKorisnike() const {
    auto it=MapaKorisnika.begin();
    while(it!=MapaKorisnika.end()) {
        cout<<"Clanski broj: "<<it->first<<endl;
        cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl;
        cout<<"Adresa: "<<it->second->adresa<<endl;
        cout<<"Broj telefona: "<<it->second->telefon<<endl<<endl;
        it++;
    }
}

void Biblioteka::IzlistajKnjige() const {
    auto it=MapaKnjiga.begin();
    while(it!=MapaKnjiga.end()) {
        cout<<"Evidencijski broj: "<<it->first<<endl;
        cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
        cout<<"Pisac: "<< it->second->DajAutora()<<endl;
        cout<<"Zanr: "<<it->second->DajZanr()<<endl;
        cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        if(it->second->DaLiJeZaduzena()==true) cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;
        cout<<endl;
        it++;
    }
}

void Biblioteka::ZaduziKnjigu(int ev_broj, int clanski_broj) {
    auto it=MapaKnjiga.begin();
    bool ima=false;
    while(it!=MapaKnjiga.end()) {
        if(ev_broj==it->first && it->second->DaLiJeZaduzena()) throw logic_error ("Knjiga vec zaduzena");
        if(ev_broj==it->first) { ima=true; break; }
        it++;
    }
    if(!ima) throw logic_error ("Knjiga nije nadjena");
    auto it2=MapaKorisnika.begin();
    ima=false;
    while(it2!=MapaKorisnika.end()) {
        if(clanski_broj==it2->first) { ima=true; break; }
        it2++;
    } 
    if(!ima) throw logic_error ("Korisnik nije nadjen");
    
    it->second->ZaduziKnjigu(*(it2->second));
    
}

void Biblioteka::RazduziKnjigu(int ev_broj) {
    auto it=MapaKnjiga.begin();
    bool ima=false;
    while(it!=MapaKnjiga.end()) {
        if(ev_broj==it->first && it->second->DaLiJeZaduzena()==false) throw logic_error ("Knjiga nije zaduzena");
        else if(ev_broj==it->first) { ima=true; break; }
        it++;
    }
    if(!ima) throw logic_error ("Knjiga nije nadjena");
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) {
    bool ima=false;
    auto it2=MapaKorisnika.begin();
    while(it2!=MapaKorisnika.end()) {
        if(clanski_broj==it2->first) { ima=true; break; }
    }
    if(!ima) throw logic_error ("Korisnik nije nadjen");
    
    bool zaduzena=false;
    auto it=MapaKnjiga.begin();
    while(it!=MapaKnjiga.end()) {
        if(it->second->DajKodKogaJe()==it2->second) {
            zaduzena=true;
            cout<<"Evidencijski broj: "<<it->first<<endl;
            cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
            cout<<"Pisac: "<< it->second->DajAutora()<<endl;
            cout<<"Zanr: "<<it->second->DajZanr()<<endl;
            cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl<<endl;
            
        }
        it++;
    }
    if(!zaduzena) cout<<"Nema zaduzenja za tog korisnika!";
    
}

int main ()
{
    /*Biblioteka b;
    for(;;) {
        cout<<"Izaberite opciju: "<<endl;
        cout<<"0 - Kraj"<<endl<<"1 - Registriraj novu knjigu"<<endl<<"2 - Registriraj novog korisnika"<<endl<<"3 - Izlistaj knjige"<<endl<<"4 - Izlistaj korisnike"<<endl;
        cout<<"5 - Zaduzi knjigu"<<endl<<"6 - Razduzi knjigu"<<endl<<"7 - Prikazi zaduzenja"<<endl;
        int n=0; cin>>n;
        if(n==0) break;
        else if(n==1) {
            cin.ignore(10000, '\n');
            cout<<"Unesite naslov knjige: ";
            string naslov;
            getline(cin,naslov);
            cout<<"Unesite Ime i Prezime pisca: ";
            string imepisca; 
            getline(cin,imepisca);
            cout<<"Unesite zanr knjige: ";
            string zanr;
            getline(cin,zanr);
            cout<<"Unesite godinu izdavanja: ";
            int god; cin>>god;
            cout<<"Unesite evidencijski broj: ";
            int ev; cin>>ev;
            try {
                b.RegistrirajNovuKnjigu(ev,naslov,imepisca,zanr,god);
            }catch(logic_error e)  { cout<<e.what()<<endl; }
                
        }
        else if(n==2) {
            cin.ignore(10000, '\n');
            cout<<"Unesite ime korisnika: ";
            string ime; getline(cin,ime);
            cout<<"Unesite prezime korisnika: ";
            string prezime; getline(cin,prezime);
            cout<<"Unesite adresu korisnika: "; 
            string adresa; getline(cin,adresa);
            cout<<"Unesite telefonski broj korisnika: ";
            string broj; getline(cin,broj);
            cout<<"Unesite clanski broj korisnika: ";
            int n; cin>>n;
            try {
                b.RegistrirajNovogKorisnika(n,ime,prezime,adresa,broj);
            }catch(logic_error e)  { cout<<e.what()<<endl; }
        }
        else if(n==3) {
            b.IzlistajKnjige();
        }
        else if(n==4) {
            b.IzlistajKorisnike();
        }
        else if(n==5) {
            cout<<"Unesite evidencijski broj knjige koju zelite zaduziti: ";
            int broj; cin>>broj;
            cout<<"Unesite clanski broj korisnika koji zaduzuje knjigu: ";
            int broj1; cin>>broj1;
            try {
                b.ZaduziKnjigu(broj, broj1);
            }catch (logic_error e) { cout<<e.what()<<endl; }
        }
        else if(n==6) {
            cout<<"Unesite evidencijski broj knjige koju zelite razduziti: ";
            int broj; cin>>broj;
            try {
                b.RazduziKnjigu(broj);
            }catch(logic_error e) { cout<<e.what()<<endl;}
        }
        else if(n==7) {
            cout<<"Unesite clanski broj korisnika cija zaduzenja zelite vidjeti: ";
            int broj; cin>>broj;
            try {
                b.PrikaziZaduzenja(broj);
            }catch(logic_error e) { cout<<e.what()<<endl; }
        }
    }*/
    
    Korisnik kor{"Meho", "Mehic", "Dobojska 15", "033/123-456"};
Knjiga knj("Tvrdjava", "Mesa Selimovic", "Roman", 1965);
const Knjiga knj2(knj); 
std::cout << knj2.DajNaslov() << " " << knj2.DajAutora() << " "
    << knj2.DajZanr() << " " << knj2.DajGodinuIzdavanja() << std::endl;
  std::cout << knj2.DaLiJeZaduzena() << std::endl;
    
	return 0;
}