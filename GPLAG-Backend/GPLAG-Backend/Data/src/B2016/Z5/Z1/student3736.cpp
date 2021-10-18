/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <stdexcept>
#include <iterator>

using namespace std;


struct Korisnik
{
    string ime;
    string prezime;
    string adresa;
    string telefon;
};

class Knjiga
{
    string naslov;
    string imePisca;
    string zanr;
    int godinaIzdavanja;
    Korisnik* zaduzivac = nullptr;
    
  public:
    Knjiga(string _naslov, string _imePisca, string _zanr, int _godIzd) : naslov(_naslov), imePisca(_imePisca), zanr(_zanr), godinaIzdavanja(_godIzd) {}
    
    string DajNaslov() const { return naslov; }
    string DajAutora() const { return imePisca; }
    string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godinaIzdavanja; }
    Korisnik* DajKodKogaJe() const { return zaduzivac; }
    
    void ZaduziKnjigu(Korisnik &kojiZaduzuje) { zaduzivac = &kojiZaduzuje; }
    void RazduziKnjigu()   {  zaduzivac = nullptr; }
    bool DaLiJeZaduzena() const { return zaduzivac!=nullptr;  }
};

class Biblioteka
{
    map<int, Korisnik*>  korisnici;  
    map<int, Knjiga*>    knjige;
    
  public:
    Biblioteka() { }
    
    void RegistrirajNovogKorisnika(int clanskiBroj, string ime, string prezime, string adresa, string telefon)
    {
        auto nadjiKorisnika = korisnici.find(clanskiBroj);
        if(nadjiKorisnika!=korisnici.end())
        {
            throw logic_error("Korisnik vec postoji");
        }
        korisnici[clanskiBroj] = new Korisnik{ime, prezime, adresa, telefon};
    }
    
    void RegistrirajNovuKnjigu(int brojKnjige, string naslov, string imePisca, string zanr, int godIzd)
    {
        auto nadjiKnjigu = knjige.find(brojKnjige);
        if(nadjiKnjigu!=knjige.end())
        {
            throw logic_error("Knjiga vec postoji");
        }
        knjige[brojKnjige] = new Knjiga(naslov, imePisca, zanr, godIzd);
    }
    
    Korisnik &NadjiKorisnika(int clanskiBroj)
    {
        auto nadjiKorisnika = korisnici.find(clanskiBroj);
        if(nadjiKorisnika==korisnici.end())
        {
            throw logic_error("Korisnik nije nadjen");
        }
        return *korisnici[clanskiBroj];
    }
    
    Knjiga &NadjiKnjigu(int evidencijskiBroj)
    {
        auto nadjiKnjigu = knjige.find(evidencijskiBroj);
        if(nadjiKnjigu==knjige.end())
        {
            throw logic_error("Knjiga nije nadjena");
        }
        return *knjige[evidencijskiBroj];
    }
    
    void IzlistajKorisnike() const
    {
        for(auto p : korisnici)
        {
            cout<<"Clanski broj: "<<p.first<<endl;
            cout<<"Ime i prezime: "<<p.second->ime<<" "<<p.second->prezime<<endl;
            cout<<"Adresa: "<<p.second->adresa<<endl;
            cout<<"Broj telefona: "<<p.second->telefon<<endl;
            cout<<endl;
        }
    }
    
    void IzlistajKnjige() const
    {
        for(auto p : knjige)
        {
            cout<<"Evidencijski broj: "<<p.first<<endl;
            cout<<"Naslov: "<<p.second->DajNaslov()<<endl;
            cout<<"Pisac: "<<p.second->DajAutora()<<endl;
            cout<<"Zanr: "<<p.second->DajZanr()<<endl;
            cout<<"Godina izdavanja: "<<p.second->DajGodinuIzdavanja()<<endl;
            if(p.second->DaLiJeZaduzena())
            {
                Korisnik* kor = p.second->DajKodKogaJe();
                cout<<"Zaduzena kod korisnika: "<<kor->ime<<" "<<kor->prezime<<endl;
            }
            cout<<endl;
        }
    }
    
    void ZaduziKnjigu(int evidBrojKnjige, int clanskiBrojKorisnik)
    {
        if(knjige.find(evidBrojKnjige)==knjige.end())
        {
            throw logic_error("Knjiga nije nadjena");
        }
        if(korisnici.find(clanskiBrojKorisnik)==korisnici.end())
        {
            throw logic_error("Korisnik nije nadjen");
        }
        if(knjige[evidBrojKnjige]->DaLiJeZaduzena())
        {
            throw logic_error("Knjiga je vec zaduzena");
        }
        
        knjige[evidBrojKnjige]->ZaduziKnjigu(*(korisnici[clanskiBrojKorisnik]));
    }
    
    void RazduziKnjigu(int evidBrojKnjige)
    {
        if(knjige.find(evidBrojKnjige)==knjige.end())
        {
            throw logic_error("Knjiga nije nadjena");
        }
        if(!knjige[evidBrojKnjige]->DaLiJeZaduzena())
        {
            throw logic_error("Knjiga nije zaduzena");
        }
        
        knjige[evidBrojKnjige]->RazduziKnjigu();
    }
    
    void PrikaziZaduzivanja(int clanskiBrojKorisnik) const
    {
        if(korisnici.find(clanskiBrojKorisnik)==korisnici.end())
        {
            throw domain_error("Korisnik nije nadjen");
        }
        
        int brojac{0};
        
        for(auto knj : knjige)
        {
            if(knj.second->DajKodKogaJe()==korisnici.at(clanskiBrojKorisnik))
            {
                cout<<"Evidencijski broj: "<<knj.first<<endl;
                cout<<"Naslov: "<<knj.second->DajNaslov()<<endl;
                cout<<"Pisac: "<<knj.second->DajAutora()<<endl;
                cout<<"Zanr: "<<knj.second->DajZanr()<<endl;
                cout<<"Godina izdavanja: "<<knj.second->DajGodinuIzdavanja()<<endl;
                cout<<endl;
                brojac++;
            }
        }
        
        if(brojac==0)
        {
            cout<<"Nema zaduzenja za tog korisnika"<<endl;
        }
    }
    ~Biblioteka ()
    {
        for(auto it=korisnici.begin(); it != korisnici.end(); it++)
            delete it->second;
        for(auto it=knjige.begin(); it != knjige.end(); it++ )
            delete it->second;
    }
    
};



int main ()
{
	return 0;
}