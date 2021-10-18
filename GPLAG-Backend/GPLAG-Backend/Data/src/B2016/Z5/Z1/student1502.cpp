#include <iostream>
#include <string>
#include <stdexcept>
#include <map>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;


struct Korisnik {
    string ime,prezime,adresa,telefon;
};

class Knjiga
{
    string naslov,ime_p,zanr;
    int godinaiz;
    Korisnik* zaduzenik=nullptr;
public:
    Knjiga(string naslov, string ime_p, string zanr, int godinaiz): naslov(naslov), ime_p(ime_p), zanr(zanr), godinaiz(godinaiz) {};
    string DajNaslov() const {
        return naslov;
    }
    string DajAutora() const {
        return ime_p;
    }
    string DajZanr() const {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return godinaiz;
    }
    Korisnik* DajKodKogaJe() const {
        return zaduzenik;
    }
    void ZaduziKnjigu(Korisnik& korisnik) {
        zaduzenik=&korisnik;
    }
    void RazduziKnjigu() {
        zaduzenik=nullptr;
    }
    bool DaLiJeZaduzena() {
        if(!zaduzenik) return false;
        return true;
    }
};

class Biblioteka
{
    map<int,Korisnik*> korisnici;
    map<int,Knjiga*> knjige;
public:
    Biblioteka()=default;
    Biblioteka(const Biblioteka& bib);
    Biblioteka(Biblioteka&& bib);
    ~Biblioteka();
    Biblioteka& operator = (const Biblioteka& bib);
    Biblioteka& operator =(Biblioteka&& bib);
    void RegistrirajNovogKorisnika(int,string,string,string,string);
    void RegistrirajNovuKnjigu(int ev_br, string naslov, string ime_p, string zanr, int godinaiz);
    Korisnik& NadjiKorisnika(int);
    Knjiga& NadjiKnjigu(int);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int ev_br, int cb);
    void RazduziKnjigu(int);
    void PrikaziZaduzenja(int) const ;
};

void Biblioteka::ZaduziKnjigu(int ev_br, int cb)
{
    if(!knjige.count(ev_br)) throw std::logic_error("Knjiga nije nadjena");
    if(!korisnici.count(cb)) throw std::logic_error("Korisnik nije nadjen");
    if(knjige[ev_br]->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    knjige[ev_br]->ZaduziKnjigu(*korisnici[cb]);
}

void Biblioteka::RazduziKnjigu(int ev_br)
{
    if(!knjige.count(ev_br)) throw std::logic_error("Knjiga nije nadjena");
    if(!knjige[ev_br]->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
    knjige[ev_br]->RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int cb) const
{
    if(!korisnici.count(cb)) throw std::logic_error("Korisnik nije nadjen");
    bool ima(false);
    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
        if(it->second->DajKodKogaJe()==korisnici.at(cb)) {
            ima=true;
            cout<<"Evidencijski broj: "<<it->first<<endl;
            cout<<"Pisac: "<<it->second->DajAutora()<<" "<<endl;
            cout<<"Zanr: "<<it->second->DajZanr()<<endl;
            cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        }
    }
    if(!ima) cout<<"Nema zaduzenja kod korisnika"<<endl;
    cout<<endl;
}

void Biblioteka::IzlistajKorisnike() const
{
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        cout<<"Clanski broj: "<<it->first<<endl;
        cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl;
        cout<<"Adresa: "<<it->second->adresa<<endl;
        cout<<"Broj telefona: "<<it->second->telefon<<endl;
        cout<<endl;
    }
}


void Biblioteka::IzlistajKnjige() const
{
    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
        cout<<"Evidencijski broj: "<<it->first<<endl;
        cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
        cout<<"Pisac: "<<it->second->DajAutora()<<" "<<endl;
        cout<<"Zanr: "<<it->second->DajZanr()<<endl;
        cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        if(it->second->DaLiJeZaduzena()) {
            cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;
        }
        cout<<endl;
    }
}

Korisnik& Biblioteka::NadjiKorisnika(int cb)
{
    if(!korisnici.count(cb)) throw std::logic_error("Korisnik nije nadjen");
    return *korisnici[cb];
}

Knjiga& Biblioteka::NadjiKnjigu(int ev_br)
{
    if(!knjige.count(ev_br)) throw std::logic_error("Knjiga nije nadjena");
    return *knjige[ev_br];
}

void Biblioteka::RegistrirajNovogKorisnika(int cb,string ime, string prezime, string adresa, string telefon)
{
    if (korisnici.count(cb)) throw std::logic_error("Korisnik vec postoji");
    korisnici[cb]=new Korisnik {ime,prezime,adresa,telefon};
}

void Biblioteka::RegistrirajNovuKnjigu(int ev_br, string naslov, string ime_p, string zanr, int godinaiz)
{
    if(knjige.count(ev_br)) throw std::logic_error("Knjiga vec postoji");
    knjige[ev_br] = new Knjiga(naslov,ime_p,zanr,godinaiz);
}

Biblioteka::~Biblioteka()
{
    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
        delete it->second;
    }
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        delete it->second;
    }
}

Biblioteka::Biblioteka(const Biblioteka& bib)
{
    for(auto it = bib.korisnici.begin(); it!= bib.korisnici.end(); it++) {
        korisnici[it->first] = new Korisnik();
        *korisnici[it->first] = *it->second;
    }
    for(auto it = bib.knjige.begin(); it!= bib.knjige.end(); it++) {
        knjige[it->first] = new Knjiga(*it->second);
    }

}
Biblioteka::Biblioteka(Biblioteka&& bib)
{
    std::swap(korisnici,bib.korisnici);
    std::swap(knjige,bib.knjige);
}
Biblioteka& Biblioteka::operator = (const Biblioteka& bib)
{
    *this=Biblioteka(bib);
    return *this;
}
Biblioteka& Biblioteka::operator =(Biblioteka&& bib)
{
    *this=Biblioteka(std::move(bib));
    return *this;
}

int main ()
{
    Biblioteka bib;
    int opcija;
    while(true) {
        try {
            cout<<"Unesite opciju:\n";
            cout<<" 1. Registriraj novog korisnika\n 2. Registriraj novu knjigu\n 3. Izlistaj sve korisnike\n 4. Izlistaj sve knjige"<<endl;
            cout<<" 5. Zaduzi knjigu\n 6. Razduzi knjigu\n 7. Prikazi zaduzenja\n 0: kraj\n";
            cin>>opcija;
            switch(opcija){
                case 0: throw std::runtime_error("kraj");
                case 1: {
                    int cb;
                    string ime,prezime,adresa, telefon;
                    cout<<"Unesite clanski broj: ";
                    cin>>cb;
                    cin.ignore(10000,'\n');
                    cout<<"Unesite ime: ";
                    getline(cin,ime);
                    cout<<"Unesite prezime: ";
                    getline(cin,prezime);
                    cout<<"Unesite adresu: ";
                    getline(cin,adresa);
                    cout<<"Unesite telefon: ";
                    getline(cin,telefon);
                    bib.RegistrirajNovogKorisnika(cb,ime,prezime,adresa,telefon);
                    cout<<"Korisnik uspjesno registririran"<<endl;
                    break;
                }
                case 2:{
                    int ev_br,godina_iz;
                    string naslov,autor,zanr;
                    cout<<"Unesite evidencijski broj knjige: ";
                    cin>>ev_br;
                    cin.ignore(10000,'\n');
                    cout<<"Unesite naslov: ";
                    getline(cin,naslov);
                    cout<<"Unesite autora: ";
                    getline(cin,autor);
                    cout<<"Unesite zanr: ";
                    getline(cin,zanr);
                    cout<<"Unesite godinu izdavanja: ";
                    cin>>godina_iz;
                    bib.RegistrirajNovuKnjigu(ev_br,naslov,autor,zanr,godina_iz);
                    cout<<"Knjiga uspjesno registrovana"<<endl;
                    break;                    
                }
                case 3:{
                    cout<<"Korisnici date biblioteke su: "<<endl;
                    bib.IzlistajKorisnike();
                    cout<<endl;
                    break;
                }
                case 4:{
                    cout<<"Knjige date biblioteke: "<<endl;
                    bib.IzlistajKnjige();
                    cout<<endl;
                    break;
                }
                case 5:{
                    cout<<"Unesite clanski broj zaduznika: ";
                    int cb,ev_br;
                    cin>>cb;
                    cout<<"Unesite evidencijski broj knjige: ";
                    cin>>ev_br;
                    bib.ZaduziKnjigu(ev_br,cb);
                    cout<<"Knjiga uspjesno zaduzena! "<<endl;
                    break;
                }
                case 6:{
                    cout<<"Unesite evidencijski broj knjige: ";
                    int ev_br;
                    cin>>ev_br;
                    bib.RazduziKnjigu(ev_br);
                    break;
                }
                case 7:{
                    cout<<"Unesite clanski broj korisnika: ";
                    int cb;
                    cin>>cb;
                    cout<<"Zaduzenja datog korisnika su sljedeca: "<<endl;
                    bib.PrikaziZaduzenja(cb);
                    cout<<endl;
                    break;
                }
            }

        } 
        catch(std::runtime_error e){
            break;
        }
        catch(std::logic_error e) {
            cout<<e.what()<<endl;
        }
   
    }
   
    cout<<"Dovidjenja! "<<endl;
    return 0;
}
