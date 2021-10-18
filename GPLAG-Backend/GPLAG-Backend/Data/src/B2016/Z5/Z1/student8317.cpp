/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include<string>
#include<stdexcept>
#include<map>
using namespace std;


struct Korisnik {
    string ime,prezime,adresa,telefon;

};

class Knjiga
{
    string naslov;
    string ime_pisca;
    string zanr;
    int godina;
    Korisnik* zaduzenja;
public:
    Knjiga(string naslov,string ime_pisca,string zanr,int godina): naslov(naslov),ime_pisca(ime_pisca),zanr(zanr),godina(godina) {
        zaduzenja=nullptr;
    }
    string DajNaslov() {
        return naslov;
    }
    string DajAutora() {
        return ime_pisca;
    }
    string DajZanr() {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return godina;
    }
    Korisnik *DajKodKogaJe () {
        return zaduzenja;
    }
    void ZaduziKnjigu(Korisnik &v) {
        zaduzenja=&v;
    }
    void RazduziKnjigu() {
        zaduzenja=nullptr;
    }
    bool DaLiJeZaduzena() const {
        return zaduzenja!=nullptr;
    }
    //void Ispisi() const;
};

class Biblioteka
{
    map<int,Korisnik*> mapa_korisnika;
    map<int,Knjiga*>mapa_knjiga;
    Biblioteka &operator=(const Biblioteka &b);
    Biblioteka (const Biblioteka &b);

public:
    Biblioteka() {};
    ~Biblioteka() {
        for (auto it = mapa_korisnika.begin(); it != mapa_korisnika.end(); ++it)
            delete it->second;
        for (auto it2 = mapa_knjiga.begin(); it2 != mapa_knjiga.end(); ++it2)
            delete it2->second;
    };
    void RegistrirajNovogKorisnika(int clanskibr,string ime,string prezime,string adresa,string telefon );
    void RegistrirajNovuKnjigu(int ev_br_knjige,string naslov,string ime_pisca,string zanr,int godina);
    Korisnik &NadjiKorisnika(int clanskibr) {
        if(!mapa_korisnika.count(clanskibr)) throw logic_error("Korisnik nije nadjen");
        else
            return *mapa_korisnika[clanskibr];
    }
    Knjiga &NadjiKnjigu(int ev_br_knjige) {
        if(!mapa_knjiga.count(ev_br_knjige)) throw logic_error("Knjiga nije nadjena");
        else
            return *mapa_knjiga[ev_br_knjige];
    }
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int ev_br_knjige,int clanskibr);
    void RazduziKnjigu(int ev_br_knjige);
    void PrikaziZaduzenja(int clanskibr);
};

void Biblioteka::RegistrirajNovogKorisnika(int clanskibr,string ime,string prezime,string adresa,string telefon )
{
    auto korisnik=new Korisnik;
    *korisnik= {ime,prezime,adresa,telefon};
    if(mapa_korisnika.count(clanskibr)==0)
        mapa_korisnika[clanskibr]=korisnik;
    else throw logic_error("Korisnik vec postoji");


}

void Biblioteka::RegistrirajNovuKnjigu(int ev_br_knjige,string naslov,string ime_pisca,string zanr,int godina)
{
    auto knjiga=new Knjiga(naslov,ime_pisca,zanr,godina);
    if(mapa_knjiga.count(ev_br_knjige)==0)
        mapa_knjiga[ev_br_knjige]=knjiga;
    else throw logic_error ("Knjiga vec postoji");
}
void Biblioteka::IzlistajKorisnike() const
{
    for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) {
        cout<<"Clanski broj: "<<(*it).first<<endl;
        cout<<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<endl;
        cout<<"Adresa: "<<(it->second)->adresa<<endl;
        cout<<"Broj telefona: "<<(it->second)->telefon<<endl;
        cout<<endl;
    }
}
void Biblioteka::IzlistajKnjige() const
{
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) {
        cout<<"Evidencijski broj: "<<(*it).first<<endl;
        cout<<"Naslov: "<<(it->second)->DajNaslov()<<endl;
        cout<<"Pisac: "<<(it->second)->DajAutora()<<endl;
        cout<<"Zanr: "<<(it->second)->DajZanr()<<endl;
        cout<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<endl;

        if(it->second->DaLiJeZaduzena())
            cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;

        cout<<endl;
    }

}
void Biblioteka::ZaduziKnjigu(int ev_br_knjige,int clanskibr)
{
    auto k=mapa_knjiga[ev_br_knjige];
    auto c=mapa_korisnika[clanskibr];
    if(k==nullptr) throw logic_error("Knjiga nije nadjena");
    if(c==nullptr) throw logic_error("Korisnik nije nadjen");
    if(k->DaLiJeZaduzena()) throw logic_error ("Knjiga vec zaduzena");
    k->ZaduziKnjigu(*c);

}
void Biblioteka::RazduziKnjigu(int ev_br_knjige)
{
    auto k=mapa_knjiga[ev_br_knjige];
    if(k==nullptr) throw logic_error("Knjiga nije nadjena");
    if(!k->DaLiJeZaduzena()) throw logic_error ("Knjiga nije zaduzena");
    k->RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clanskibr)
{
    auto c=mapa_korisnika[clanskibr];
    int br=0;
    if( c==nullptr) throw logic_error("Korisnik nije nadjen");
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) {

        if(it->second->DajKodKogaJe()==c) {
            br++;
            cout<<"Evidencijski broj: "<<(*it).first<<endl;
            cout<<"Naslov: "<<(it->second)->DajNaslov()<<endl;
            cout<<"Pisac: "<<(it->second)->DajAutora()<<endl;
            cout<<"Zanr: "<<(it->second)->DajZanr()<<endl;
            cout<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<endl;
        }
    }
    if(br==0) cout<<"Nema zaduzenja za tog korisnika!";

}


//Biblioteka::Biblioteka(const Biblioteka &b):


int main ()
{
    Biblioteka b;
    int clanski,evidencijski,godizdavanja,unos;
    string zanr,pisac,ime,prezime,adresa,broj,nazivknjige;
    while(1) {
        cout<<"REGISTRACIJA KORISNIKA -1"<<endl;
        cout<<"REGISTRACIJA KNJIGE -2"<<endl;
        cout<<"ZADUZIVANJE KNJIGE -3"<<endl;
        cout<<"RAZDUZIVANJE KNJIGE -4"<<endl;
        cout<<"PRIKAZ ZADUZENJA -5"<<endl;
        cout<<"IZLISTAJ SVE KORISNIKE -6"<<endl;
        cout<<"IZLISTAJ SVE KNJIGE -7"<<endl;
        cout<<"PRETRAGA KORISNIKA -8"<<endl;
        cout<<"PRETRAGA KNJIGA -9"<<endl;
        cout<<"EXIT -0"<<endl;
        cin>>unos;
        cin.clear();
        cin.ignore(1000,'\n');
        switch (unos) {
        case 1:
            cout<<"Unesite ime korisnika: ";
            getline(cin,ime);
            cout<<"Unesite prezime korisnika: ";
            getline(cin,prezime);
            cout<<"Unesite adresu korisnika: ";
            getline(cin,adresa);
            cout<<"Unesite telefonski broj: ";
            getline(cin,broj);
            cin.clear();
            cin.ignore(1000,'\n');
            b.RegistrirajNovogKorisnika(clanski,ime,prezime,adresa,broj);
            break;

        case 2:
            cout<<"Unesite naziv knjige: ";
            getline(cin,nazivknjige);
            cout<<"Unesite autora knjige: ";
            getline(cin,pisac);
            cout<<"Unesite zanr: ";
            getline(cin,zanr);
            cout<<"Unesite evidencijski broj knjige: ";
            cin>>evidencijski;
            cout<<"Unesite godinu izdavanja: ";
            cin>>godizdavanja;
            cin.clear();
            cin.ignore(1000,'\n');
            b.RegistrirajNovuKnjigu(evidencijski,nazivknjige,pisac,zanr,godizdavanja);
            break;

        case 3:
            cout<<"Unesite clanski broj korisnika: ";
            cin>>clanski;
            cout<<"Unesi evidencijski broj: ";
            cin>>evidencijski;
            cin.clear();
            cin.ignore(1000,'\n');
            b.ZaduziKnjigu(clanski,evidencijski);
            break;

        case 4:
            cout<<"Unesite evidencijski broj: ";
            cin>>evidencijski;
            cin.clear();
            cin.ignore(1000,'\n');
            b.RazduziKnjigu(evidencijski);
            break;

        case 5:
            cout<<"Unesite clanski broj: ";
            cin>>clanski;
            cin.clear();
            cin.ignore(1000,'\n');
            b.PrikaziZaduzenja(clanski);
            break;
            
            case 6:
            b.IzlistajKorisnike();
            break;

        case 7:
            b.IzlistajKnjige();
            break;

        case 8:
          cout<<"Unesite clanski broj: ";
            cin>>clanski;
            cin.clear();
            cin.ignore(1000,'\n');
            b.NadjiKorisnika(clanski);
            
            case 9:
             cout<<"Unesite evidencijski broj: ";
            cin>>evidencijski;
            cin.clear();
            cin.ignore(1000,'\n');
            b.NadjiKnjigu(evidencijski);
            break;
            
            case 0:
            cout<<"Dovidjenja.Dodjite nam opet!";
            exit(1);
        }
    } 
    return 0;
}
