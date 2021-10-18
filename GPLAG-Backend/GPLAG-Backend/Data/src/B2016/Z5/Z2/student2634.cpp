#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <map>
#include <iterator>

using namespace std;

struct Korisnik{
    string ime; 
    string prezime; 
    string adresa; 
     string telefon;
};

class Knjiga{
    string naslov; string ime_pisca; string zanr; 
    int god_izdavanja; 
    Korisnik *zaduzenje;
    public:
    Knjiga(string naslov1, string ime, string zanr2, int godina):
    naslov(naslov1), ime_pisca(ime), zanr(zanr2), god_izdavanja(godina), zaduzenje(nullptr) {}
    string DajNaslov() const{return naslov;}
    string DajAutora() const {return ime_pisca;}
    string DajZanr() const{return zanr;}
    int DajGodinuIzdavanja() const{return god_izdavanja;}
    Korisnik* DajKodKogaJe() const{return zaduzenje;}
    void ZaduziKnjigu(Korisnik &n) {zaduzenje=&n;}
    void RazduziKnjigu() {zaduzenje=nullptr;}
    bool DaLiJeZaduzena() const{if(zaduzenje==nullptr)return false; return true;}
    void Ispisi() const;
};

void Knjiga::Ispisi() const{
    cout<<"Naslov: "<<naslov<<"\n";
    cout<<"Pisac: "<<ime_pisca<<"\n";
    cout<<"Zanr: "<<zanr<<"\n";
    cout<<"Godina izdavanja: "<<god_izdavanja<<"\n";
}

class Biblioteka{
    map<int, shared_ptr<Korisnik>> clanovi;
    map<int, shared_ptr<Knjiga>> knjige;
    public:
    Biblioteka()=default;
    Biblioteka(const Biblioteka &b)=delete;
    Biblioteka &operator=(const Biblioteka &b)=delete;
    Biblioteka(Biblioteka &&b);
    Biblioteka operator = (Biblioteka &&b);
    void RegistrirajNovogKorisnika(int broj, string ime, string prezime, string adresa, string telefon);
    void RegistrirajNovuKnjigu(int broj, string naslov1, string ime, string zanr2, int godina);
    Korisnik &NadjiKorisnika(int broj_clana) const;
    Knjiga &NadjiKnjigu(int broj_knjige) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int broj_knjige, int broj_clana);
    void RazduziKnjigu(int broj);
    void PrikaziZaduzenja(int broj) const;
};
Biblioteka::Biblioteka(Biblioteka &&b){
    move(b.clanovi.begin(),b.clanovi.end(),inserter(clanovi, clanovi.begin()));
    move(b.knjige.begin(), b.knjige.end(), inserter(knjige, knjige.begin()));
     }

//Biblioteka &Biblioteka::operator=(Biblioteka &&b){}
       
void Biblioteka::RegistrirajNovogKorisnika(int broj, string ime, string prezime, string adresa, string telefon) {
    if(!clanovi.count(broj)){
    shared_ptr<Korisnik>p=shared_ptr<Korisnik>(new Korisnik{ime,prezime,adresa,telefon});
    clanovi.insert(make_pair(broj,p));
    }
    else throw logic_error("Korisnik vec postoji");
}

void Biblioteka::RegistrirajNovuKnjigu(int broj, string naslov1, string ime, string zanr2, int godina) {
    if(!knjige.count(broj)){
    shared_ptr<Knjiga> p=shared_ptr<Knjiga>(new Knjiga{naslov1,ime,zanr2,godina});
    knjige.insert(make_pair(broj,p));}
    throw logic_error("Knjiga vec postoji");
    
}

Korisnik& Biblioteka::NadjiKorisnika(int broj_clana)const{
    for(auto x:clanovi)
    if(x.first==broj_clana) return *(x.second);
    throw logic_error("Clan nije nadjen");
}

Knjiga& Biblioteka:: NadjiKnjigu(int broj_knjige)const{
    for(auto x:knjige)
    if(x.first==broj_knjige) return *(x.second);
    throw logic_error("Knjiga nije nadjena");
}

void Biblioteka::IzlistajKorisnike() const {
    for(auto x:clanovi){
       cout<<"Clanski broj: "<<x.first<<endl;
       cout<<"Ime i prezime: "<<x.second->ime<<" "; 
       cout<<x.second->prezime<<endl;
       cout<<"Adresa: "<<x.second->adresa<<endl;
       cout<<"Broj telefona: "<<x.second->telefon<<endl<<endl;
        }
}

void Biblioteka::IzlistajKnjige() const{
    for(auto x:knjige) {x.second->Ispisi();cout<<"\n";
        if(x.second->DaLiJeZaduzena())
        cout<<"Zaduzena kod clana: "<<(x.second->DajKodKogaJe())->ime<<" "<<(x.second->DajKodKogaJe())->prezime;
        cout<<"\n"<<"\n";
    }
}

void Biblioteka::ZaduziKnjigu(int broj_knjige, int broj_clana) {
    int brojac1=0, brojac2=0;
    for(auto x:knjige) {
        if(x.first==broj_knjige) {
            brojac1++;
            if(x.second->DaLiJeZaduzena()) throw logic_error("Knjiga vec zaduzena");
            for(auto y:clanovi)
            if(y.first==broj_clana)
            {x.second->ZaduziKnjigu(*y.second);brojac2++;}
        }
    }
    if(brojac1==0) throw logic_error("Knjiga nije nadjena");
    if(brojac2==0) throw logic_error("Clan nije nadjen");
}

void Biblioteka::RazduziKnjigu(int broj) {
    int brojac1=0;
    for(auto x:knjige) {
        if(x.first==broj) {
            brojac1++;
            if(!(x.second->DaLiJeZaduzena())) throw logic_error("Knjiga nije zaduzena");
            x.second->RazduziKnjigu();
        }
    }
    if(brojac1==0) throw logic_error("Knjiga nije nadjena");
}

void Biblioteka::PrikaziZaduzenja(int broj) const{
    
    for(auto x:clanovi) {
         if(x.first==broj){
            shared_ptr<Korisnik>cl=x.second;
            for(auto y:knjige){
                if(y.second->DajKodKogaJe()==cl.get()){
                   cout<<"Clanski broj: "<<x.first<<endl;
                    cout<<"Ime i prezime: "<<x.second->ime<<" "<<x.second->prezime<<endl;
                    cout<<"Adresa: "<<x.second->adresa<<endl;
                    cout<<"Broj telefona: "<<x.second->telefon;
                    for(auto z:knjige) {
                       z.second->Ispisi();
                       if(z.second->DaLiJeZaduzena()){
                          cout<<"Zaduzena kod clana: "<<(z.second->DajKodKogaJe())->ime<<" "<<(z.second->DajKodKogaJe())->prezime;
                          cout<<"\n"<<"\n";
                       }
                  }
             
              }
           }
     }
 }
}

/*if(!brojac) throw domain_error("Clan nije nadjen");
    brojac=0;
    for(auto y:knjige)
    if(((y.second->DajKodKogaJe())->first)==broj) {
        brojac++;
        y.second->Ispisi();
        cout<<"\n"<<"\n";
    }
    if(brojac==0) throw domain_error("Nema zaduzenja za tog clana!");
}*/

int main() {
  /*  Biblioteka b;
    try{
        for(;;) {
            cout<<"\n1-Registracija novog clana"<<"\n"<<"2-Registracija nove knjige"<<"\n"<<
            "3-Pronadji clana"<<"\n"<<"4-Pronadji knjigu"<<"\n"<<"5-Izlistaj clanove"<<"\n"<<
            "6-Izlistaj knjige"<<"\n"<<"7-Zaduzi knjigu"<<"\n"<<"8-Razduzi knjigu"<<"\n"<<
            "9-Prikazi zaduzenja"<<"\n"<<"10-Izadji iz biblioteke"<<"\n";
            int x; 
            cin>>x;
            if(x==1) {
                string ime,prezime,adresa,telefon;
                int broj;
                cout<<"Clanski broj: ";
                cin>>broj;
                cout<<"\nIme i prezime clana: ";
                cin>>ime>>prezime;
                cout<<"\nAdresa: ";
                cin>>adresa;
                cout<<"\nBroj telefona: ";
                cin>>telefon;
                b.RegistrirajNovogClana(broj,ime,prezime,adresa,telefon);
                cout<<"Uspjesno ste registrovali novog clana."<<"\n";
            }
            if(x==2) {
                string ime,zanr,naslov;
                int broj,godina;
                cout<<"Unesite evidencijski broj:";
                cin>>broj;
                cout<<"\nUnesite naslov knjige: ";
                cin>>naslov;
                cout<<"\nUnesite ime pisca: ";
                cin>>ime;
                cout<<"\nUnesite zanr knjige: ";
                cin>>zanr;
                cout<<"\nUnesite godinu izdavanja: ";
                cin>>godina;
                b.RegistrirajNovuKnjigu(broj,naslov,ime,zanr,godina);
                cout<<"Uspjesno ste registrovali novu knjigu."<<"\n";
            }
            if(x==3){
                int x;
                cout<<"Unesite evidencijski broj clana ";
                cin>>x;
                cout<<"\n";
                Clan c=b.NadjiClana(2);
                cout<<"Clan kojeg ste trazili je "<<c.DajIme()<<c.DajPrezime();
            }
            if(x==4) {
                int x;
                cout<<"Unesite evidencijski broj knjige: ";
                cin>>x;
                cout<<"\n";
                Knjiga c=b.NadjiKnjigu(2);
                cout<<"Knjiga koju ste trazili je "<<c.DajNaslov();
            }
            if(x==5) {b.IzlistajClanove();}
            if(x==6) {b.IzlistajKnjige();}
            if(x==7) {
                int broj,broj2;
                cout<<"Unesite broj knjige i broj clana: ";
                cin>>broj>>broj2;
                b.ZaduziKnjigu(broj,broj2);
            }
            if(x==8) {
                int broj;
                cout<<"Unesite broj clana: ";
                cin>>broj;
                b.RazduziKnjigu(broj);
            }
            if(x==9){
                int broj;
                cout<<"Unesite broj clana: ";
                cin>>broj;
                b.PrikaziZaduzenja(broj);
            }
            if(x==10) {break;}
        }
        return 0;
    }
    catch(domain_error greska) {
        cout<<greska.what();
    }
    catch(bad_alloc) {
        cout<<"Nema dovoljno memorije";
    }*/
}
