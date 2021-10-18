/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

using std::string;
using std::cout;
using std::cin;
using std::endl;

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};
class Knjiga
{
    std::string naslov, ime_pisca, zanr;
    int god_izd;
    Korisnik* p;
public:
    Knjiga (string naslov, string ime_pisca, string zanr, int god_izd): naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), god_izd(god_izd), p(nullptr) {};
    string DajNaslov() {
        return naslov;
    };
    string DajAutora() {
        return ime_pisca;
    };
    string DajZanr() {
        return zanr;
    };
    int DajGodinuIzdavanja () {
        return god_izd;
    };
    Korisnik* DajKodKogaJe () {
        return p;
    };
    void ZaduziKnjigu (Korisnik& k) {
        p=&k;
    };
    void RazduziKnjigu () {
        p=nullptr;
    };
    bool DaLiJeZaduzena () {
        return !(p==nullptr);
    }
};
class Biblioteka
{
    std::map<int, Knjiga*> knjige;
    std::map<int, Korisnik*> korisnici;
public:
    Biblioteka(){};
    Biblioteka (const Biblioteka& b);
    Biblioteka& operator = (const Biblioteka &b);
    Biblioteka(Biblioteka&& b): knjige(b.knjige), korisnici(b.korisnici) {};
    Biblioteka& operator = (Biblioteka &&b);
    ~Biblioteka() {
        for(auto it=knjige.begin(); it!=knjige.end(); it++) {
            delete knjige[it->first];
        }
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
            delete korisnici[it->first];
        }
    }
    void RegistrirajNovogKorisnika(int cl_br, string ime, string prezime, string adresa, string br_tel);
    void RegistrirajNovuKnjigu(int ev_broj, string naslov, string ime_pisca, string zanr, int godina);
    Korisnik& NadjiKorisnika(int cl_br);
    Knjiga& NadjiKnjigu(int ev_broj);
    void IzlistajKnjige() const;
    void IzlistajKorisnike() const;
    void ZaduziKnjigu(int ev_broj, int cl_br);
    void RazduziKnjigu(int ev_broj);
    void PrikaziZaduzenja(int cl_br);
};

Biblioteka::Biblioteka (const Biblioteka& b)
{
    for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++) {
        knjige[it->first]=new Knjiga(*(it->second));
    }
    for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++) {
        korisnici[it->first]=new Korisnik(*(it->second));
    }
}
Biblioteka& Biblioteka::operator = (const Biblioteka &b)
{
    for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++) {
        knjige[it->first]=new Knjiga(*(it->second));
    }
    for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++) {
        korisnici[it->first]=new Korisnik(*(it->second));
    }
    return *this;
}
Biblioteka& Biblioteka::operator = (Biblioteka &&b)
{
    knjige=b.knjige;
    korisnici=b.korisnici;
    return *this;
}
void Biblioteka::RegistrirajNovogKorisnika(int cl_br, string ime, string prezime, string adresa, string br_tel)
{

    if(korisnici.count(cl_br)) throw std::logic_error ("Korisnik vec postoji");
    Korisnik k;
    k.ime=ime;
    k.prezime=prezime;
    k.adresa=adresa;
    k.telefon=br_tel;
    korisnici[cl_br]=new Korisnik(k);
}
void Biblioteka::RegistrirajNovuKnjigu(int ev_broj, string naslov, string ime_pisca, string zanr, int godina)
{
    if(knjige.count(ev_broj)) throw std::logic_error ("Knjiga vec postoji");
    knjige[ev_broj]=new Knjiga(naslov, ime_pisca, zanr, godina);
}
Korisnik& Biblioteka::NadjiKorisnika(int cl_br) 
{
    if(!korisnici.count(cl_br)) throw std::logic_error ("Korisnik nije nadjen");
    return *korisnici[cl_br];
}
Knjiga& Biblioteka::NadjiKnjigu(int ev_broj)
{
    if(!knjige.count(ev_broj)) throw std::logic_error ("Knjiga nije nadjena");
    return *knjige[ev_broj];
}
void Biblioteka::IzlistajKorisnike() const
{
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        std::cout << "Clanski broj: "<< it->first << std::endl;
        cout<< "Ime i prezime: " << (it->second)->ime << " " << (it->second)->prezime << endl;
        cout << "Adresa: " << (it->second)->adresa << endl;
        cout << "Broj telefona: " << (it->second)->telefon << endl << endl;
    }
}
void Biblioteka::IzlistajKnjige() const
{
    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
        std::cout << "Evidencijski broj: "<< it->first << std::endl;
        cout<< "Naslov: " << (it->second)->DajNaslov()<< endl;
        cout << "Pisac: " << (it->second)->DajAutora() << endl;
        cout << "Zanr: " << (it->second)->DajZanr() << endl;
        cout << "Godina izdavanja: " << (it->second)->DajGodinuIzdavanja() << endl;
        if((it->second)->DaLiJeZaduzena()) {
            cout << "Zaduzena kod korisnika: " << ((it->second)->DajKodKogaJe())->ime <<" "<<((it->second)->DajKodKogaJe())->prezime<< endl;
        }
        cout << endl;
    }
}
void Biblioteka::ZaduziKnjigu(int ev_broj, int cl_br)
{
    if(!knjige.count(ev_broj)) throw std::logic_error ("Knjiga nije nadjena");
    if(!korisnici.count(cl_br)) throw std::logic_error ("Korisnik nije nadjen");
    if(knjige[ev_broj]->DaLiJeZaduzena()) throw std::logic_error ("Knjiga vec zaduzena");
    knjige[ev_broj]->ZaduziKnjigu(*korisnici[cl_br]);
}
void Biblioteka::RazduziKnjigu(int ev_broj)
{
    if(!knjige.count(ev_broj)) throw std::logic_error ("Knjiga nije nadjena");
    if(!knjige[ev_broj]->DaLiJeZaduzena()) throw std::logic_error ("Knjiga nije zaduzena");
    knjige[ev_broj]->RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int cl_br)
{
    if(!korisnici.count(cl_br)) throw std::logic_error ("Korisnik nije nadjen");
    Korisnik k1(*korisnici[cl_br]);
    bool nadjen(false);
    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
        Korisnik k(*((it->second)->DajKodKogaJe()));
        Korisnik k1(*korisnici[cl_br]);
        if(k.ime==k1.ime and k.prezime==k1.prezime and k.adresa==k1.adresa and k.telefon==k1.telefon) {
            nadjen=true;
            std::cout << "Evidencijski broj: "<< it->first << std::endl;
            cout<< "Naslov: " << (it->second)->DajNaslov()<< endl;
            cout << "Pisac: " << (it->second)->DajAutora() << endl;
            cout << "Godina izdavanja: " << (it->second)->DajGodinuIzdavanja() << endl<< endl;
        }
    }
    if(!nadjen) cout << "Nema zaduzenja za tog korisnika!"<< endl;
}
int main ()
{
    Knjiga k("ja","azra","horor",1998);/*
try {    
    Biblioteka bib6(1,"Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
}
catch(std::logic_error Izuzetak){
    std::cout<<Izuzetak.what()<<std::endl;
}    */
try{
    Biblioteka bib6;
    bib6.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
    bib6.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
    std::cout << bib6.NadjiKorisnika(1).ime<<std::endl;
    
    Biblioteka bib8;
    bib8.RegistrirajNovogKorisnika(1, "Pero", "Periša", "Zmaja od Bosne bb", "123 444");
    bib8.RegistrirajNovogKorisnika(2, "Mirko", "Miki", "Čekaluša", "123 987");
    bib8.RegistrirajNovuKnjigu(1, "Pustolovine", "Mato Lovrak", "Roman2", 1941);
    bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
    bib8.RegistrirajNovuKnjigu(3, "A planine su odjekivale", "Khaled Hosseini", "Roman", 2012);
    bib8.RegistrirajNovuKnjigu(4, "Hiljadu čudesnih sunaca", "Khaled Hosseini", "Roman", 2007);
    bib8.ZaduziKnjigu(2, 1);
    bib8.ZaduziKnjigu(4, 2);
    bib8.IzlistajKnjige();
    std::cout<<"Nakon dodjele biblioteka: "<<std::endl;
    bib8=bib6;
    bib8.IzlistajKnjige();
    Biblioteka bib7(bib6);
    std::cout<<"Nova biblioteka: "<<std::endl;
    bib7.IzlistajKnjige();
    bib7.PrikaziZaduzenja(2);
} catch(std::logic_error Izuzetak){
    std::cout<<Izuzetak.what()<<std::endl;
}    
    return 0;
}