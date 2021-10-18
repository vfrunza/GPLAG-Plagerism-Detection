/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Korisnik{
    string ime,prezime,adresa,telefon;
};
class Knjiga{
    string naslov,ime_pisca,zanr;
    int g;
    Korisnik *zaduzio = nullptr;
    public:
    Knjiga (string naslov, string ime_pisca, string zanr, int g): naslov(naslov),ime_pisca(ime_pisca),zanr(zanr),g(g){}
    string DajNaslov()const{return naslov;}
    string DajAutora()const{return ime_pisca;}
    string DajZanr()const{return zanr;}
    int DajGodinuIzdavanja() const {return g;}
    Korisnik *DajKodKogaJe()const{return zaduzio;}
    bool DaLiJeZaduzena() const {return (zaduzio!=nullptr);}
    void ZaduziKnjigu(Korisnik &z){ zaduzio=&z;}
    void RazduziKnjigu(){zaduzio=nullptr;}
};
class Biblioteka{
    std::map<int,Knjiga*> knjige;
    std::map<int,Korisnik*> korisnici;
    template<typename T>
    void Obrisi(T a){
        for(auto i=a.begin();i!=a.end();i++){
            delete i->second;
            i->second = nullptr;
        }
        a.clear();
    }
    void IspisiJednuKnjigu(int id,Knjiga &i, bool ispisiKorisnika=true) const {
        cout<<"Evidencijski broj: "<<id<<'\n'
                <<"Naslov: "<<i.DajNaslov()<<'\n'
                <<"Pisac: "<<i.DajAutora()<<'\n'
                <<"Zanr: "<<i.DajZanr()<<'\n'
                <<"Godina izdavanja: "<< i.DajGodinuIzdavanja()<<'\n';
            if(i.DaLiJeZaduzena() && ispisiKorisnika)
            cout<<"Zaduzena kod korisnika: "<<i.DajKodKogaJe()->ime<<" "<<i.DajKodKogaJe()->prezime<<'\n';
            cout<<endl;
    }
    void dubokaKopija(const Biblioteka &b){
        Obrisi(knjige);
        Obrisi(korisnici);
        for(auto it = b.knjige.begin(); it!=b.knjige.end();it++){
            bool kopirana = false;
            for(auto et = b.korisnici.begin(); et!=b.korisnici.end();et++){
                if(it->second->DajKodKogaJe()==et->second){
                    Korisnik *tmp = new Korisnik(*et->second);
                    korisnici[et->first] = tmp;
                    knjige[it->first] = new Knjiga(*it->second);
                    knjige[it->first]->RazduziKnjigu();
                    knjige[it->first]->ZaduziKnjigu(*tmp);
                    kopirana = true; break;
                }
            }
            if(!kopirana){
                knjige[it->first] = new Knjiga(*it->second);
            }
        }
        for(auto et = b.korisnici.begin();et!=b.korisnici.end();et++){
            if(korisnici.find(et->first)==korisnici.end()){
                korisnici[et->first] = new Korisnik(*et->second);
            }
        }
    }
    public:
    Biblioteka(){}
    ~Biblioteka(){
        Obrisi(knjige);Obrisi(korisnici);
    }
    Biblioteka(const Biblioteka &b){
        dubokaKopija(b);
    }
    Biblioteka(Biblioteka &&b){
        std::swap(korisnici,b.korisnici);
        std::swap(knjige,b.knjige);
    }
    Biblioteka &operator =(Biblioteka &&b){
        Obrisi(korisnici);
        Obrisi(knjige);
        std::swap(korisnici,b.korisnici);
        std::swap(knjige,b.knjige);
        return *this;
    }
    Biblioteka &operator =(const Biblioteka &b){dubokaKopija(b);return *this;}
    void RegistrirajNovogKorisnika(int clBroj,string ime, string prezime,string adr,string tel){
        if(korisnici.find(clBroj)!=korisnici.end())
            throw std::logic_error("Korisnik vec postoji");
        Korisnik tmp ={ime,prezime,adr,tel};
        korisnici[clBroj] = new Korisnik(tmp);
    }
    void RegistrirajNovuKnjigu(int id, string naziv,string ime,string zanr,int g){
        if(knjige.find(id)!=knjige.end())
            throw std::logic_error("Knjiga vec postoji");
        knjige[id] = new Knjiga(naziv,ime,zanr,g);
    }
    Korisnik &NadjiKorisnika(int clBroj){
        if(korisnici.find(clBroj)==korisnici.end())
            throw std::logic_error("Korisnik nije nadjen");
        return *korisnici[clBroj];
    }
    Knjiga &NadjiKnjigu(int id){
        if(knjige.find(id)==knjige.end())
            throw std::logic_error("Knjiga nije nadjena");
        return *knjige[id];
    }
    void IzlistajKorisnike()const{
        for(auto i = korisnici.begin();i!=korisnici.end();i++){
            cout<<"Clanski broj: " <<i->first<<'\n'
                <<"Ime i prezime: "<<i->second->ime<<" "<<i->second->prezime<<'\n'
                <<"Adresa: "<<i->second->adresa<<'\n'
                <<"Broj telefona: "<<i->second->telefon<<'\n';
        }
    }
    void IzlistajKnjige()const{
        for(auto i=knjige.begin();i!=knjige.end();i++){
            IspisiJednuKnjigu(i->first,*i->second);
        }
    }
    void ZaduziKnjigu(int id, int clBroj){
        bool a = false;
        string greske[]{"Knjiga nije nadjena","Korisnik nije nadjen","Knjiga vec zaduzena"};
        if(knjige.find(id)==knjige.end())a=true,id=0;
        else if(korisnici.find(clBroj)==korisnici.end())a=true,id=1;
        else if(knjige[id]->DaLiJeZaduzena())a=true,id=2;
        if(a)throw std::logic_error(greske[id]);
        knjige[id]->ZaduziKnjigu(*korisnici[clBroj]);
    }
    void RazduziKnjigu(int id){
        if(knjige.find(id)==knjige.end())throw std::logic_error("Knjiga nije nadjena");
        else if(!knjige[id]->DaLiJeZaduzena())throw std::logic_error("Knjiga nije zaduzena");
        knjige[id]->RazduziKnjigu();
    }
    void PrikaziZaduzenja(int clBroj) const {
        if(korisnici.find(clBroj)==korisnici.end())
            throw std::logic_error("Korisnik nije nadjen");
        bool ispis=false;
        auto it = korisnici.find(clBroj);
        for(auto i = knjige.begin();i!=knjige.end();i++)
            if( it->second==i->second->DajKodKogaJe()){
                IspisiJednuKnjigu(i->first,*i->second,false);
                ispis=true;
            }
        if(!ispis)cout<<"Nema zaduzenja za tog korisnika!\n";
    }
};

bool DodajKorisnika(Biblioteka &b){
    int c;
    string ime,prezime,adr,tel;
    cout<<"Unesite clanski broj korisnika: ";
    cin>>c;
    cout<<"Unesite ime: ";
    cin>>ime;
    cout<<"Unesite prezime: ";
    cin>>prezime;
    cout<<"Unesite adresu: ";
    cin.ignore(1);
    std::getline(cin,adr);
    cout<<"Unesite telefon: ";
    cin>>tel;
    try{
        b.RegistrirajNovogKorisnika(c,ime,prezime,adr,tel);
        cout<<"Uspjesno dodan novi korisnik.\n";
        return true;
    }catch(std::logic_error e){
        cout<<"Izuzetak: "<<e.what()<<endl;
        return false;
    }
}
bool DodajKnjigu(Biblioteka &b){
    int id,g;
    cout<<"Unesite evidencijski broj knjige: ";
    cin>>id;
    cout<<"Unesite naziv knjige: ";
    string naziv,ime,zanr;
    cin>>naziv;
    cout<<"Unesite ime pisca: ";
    cin.ignore(1);
    std::getline(cin,ime);
    cout<<"Unesite zanr knjige: ";
    cin>>zanr;
    cout<<"Unesite godinu izdavanja: ";
    cin>>g;
    try{
        b.RegistrirajNovuKnjigu(id,naziv,ime,zanr,g);
        return true;
    }catch(std::logic_error e){
        cout<<"Izuzetak: "<<e.what()<<endl;
        return false;
    }
}

int main ()
{
    Biblioteka b;
    cout<<"Dobrodosli: \n\n";
    while (true) {
        cout<<"Odaberite opciju: \n 0 - kraj\n 1 - Uredjivanje korisnika\n 2 - Uredjivanje knjiga\n";
        int n;
        cin>>n;
        if(n==1)
            while (n!=0) {
            cout<<"Odaberite opciju:\n 0 - nazad\n 1 - Dodaj novog korisnika\n 2 - Prikazi zaduzenja korisnika \n 3 - Izlistaj korisnike\n";
            cin>>n;
            if(!n){n=-1;break;}
            else if(n==1){
                bool dobar=DodajKorisnika(b);
                while (!dobar) {
                    cout<<"\n Molimo ponovite unos! \n";
                    dobar = DodajKorisnika(b);
                }
            }
            else if(n==2){
                int clBroj;
                cout<<"Unesite clanski broj korisnika: \n";
                cin>>clBroj;
                try{
                    b.PrikaziZaduzenja(clBroj);
                }catch(std::logic_error e){
                    cout<<"Izuzetak: "<<e.what()<<endl;
                }
            }
            else if(n==3){
                b.IzlistajKorisnike();
            }
        }
        else if(n==2)
            while (n!=0) {
                cout<<"Odaberite opciju \n 0 - nazad\n 1 - Dodaj novu knjigu\n 2 - Izlistaj sve knjige\n";
                cin>>n;
                if(!n){n=-1;break;}
                else if(n==1){
                    bool dobar = DodajKnjigu(b);
                    while (!dobar)cout<<"\nMolimo ponovite unos!\n",dobar = DodajKnjigu(b);
                }
                else if(n==2)b.IzlistajKnjige();
            }
        if(!n)break;
    }
    cout<<"Dovidjenja!\n";
	return 0;
}