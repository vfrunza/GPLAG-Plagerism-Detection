/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>
using namespace std;

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
    public:
    Korisnik(string ime, string prezime, string adresa, string telefon){
        Korisnik::ime=ime;
        Korisnik::prezime=prezime;
        Korisnik::adresa=adresa;
        Korisnik::telefon=telefon;
    }
};
class Knjiga
{
    std::string naslov, pisac, zanr;
    int godIzdavanja;
    //bool zaduzena;
    Korisnik* zaduzena;
public:
    Knjiga(std::string naslov, std::string pisac, std::string zanr,int godIzdavanja ) {
        Knjiga::naslov = naslov;
        Knjiga::pisac = pisac;
        Knjiga::zanr = zanr;
        zaduzena = nullptr;
        Knjiga::godIzdavanja = godIzdavanja;

    }
    std::string DajNaslov()const {
        return naslov;
    }
    std::string DajAutora()const {
        return pisac;
    }
    std::string DajZanr()const {
        return zanr;
    }
    int DajGodinuIzdavanja()const {
        return godIzdavanja;
    }
    Korisnik* DajKodKogaJe()const {
        return zaduzena;
    }
    void ZaduziKnjigu(Korisnik& korisnik) {
        zaduzena = &korisnik;
    }
    void RazduziKnjigu() {
        zaduzena = nullptr;
    }
    bool DaLiJeZaduzena() {
        return zaduzena;
    }
};
class Biblioteka
{
    std::map<int,shared_ptr<Korisnik> > korisnici;
    std::map<int,shared_ptr<Knjiga>> knjige;

public:

    Biblioteka() {}

    /*~Biblioteka() {

        for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
            delete it->second;
        }
        korisnici.clear();

        for(auto it=knjige.begin(); it!=knjige.end(); it++) {
            delete it->second;
        }
        knjige.clear();
    }*/

    Biblioteka(const Biblioteka&b) {
        for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++) {
            korisnici.insert(make_pair(it->first,make_shared<Korisnik>(*(it->second))));
        }

        for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++) {
            knjige.insert(make_pair(it->first,make_shared<Knjiga>(*(it->second))));
        }

    }


    Biblioteka(Biblioteka&&b) {
        korisnici= b.korisnici;
        knjige=b.knjige;
        b.korisnici.clear();
        b.knjige.clear();

    }


    Biblioteka& operator=(const Biblioteka&b) {
        if(this!=&b) {

          /* for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
                delete it->second;
            }*/
            korisnici.clear();

          /* for(auto it=knjige.begin(); it!=knjige.end(); it++) {
                delete it->second;
            }*/
            knjige.clear();



            for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++) {
                korisnici.insert(make_pair(it->first,make_shared<Korisnik>(*(it->second))));
            }

            for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++) {
                knjige.insert(make_pair(it->first,make_shared<Knjiga>(*(it->second))));
            }
        }
        return *this;
    }




    Biblioteka& operator=(Biblioteka&&b) {

        if(this!=&b) {
           /* for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
                delete it->second;
            }*/
            korisnici.clear();

           /* for(auto it=knjige.begin(); it!=knjige.end(); it++) {
                delete it->second;
            }*/
            knjige.clear();
            korisnici= b.korisnici;
            knjige=b.knjige;
            b.korisnici.clear();
            b.knjige.clear();
        }

        return *this;
    }

    void RegistrirajNovogKorisnika(int clanskiBroj, string ime, string prezime, string adresa,string telefon) {

        if(korisnici.find(clanskiBroj) != korisnici.end()) throw logic_error("Korisnik vec postoji");
        shared_ptr<Korisnik> korisnik = make_shared<Korisnik>(ime,prezime,adresa, telefon);
        korisnici.insert(std::make_pair(clanskiBroj,korisnik));


    }

    void RegistrirajNovuKnjigu(int evidencijskiBroj, string naslov, string pisac, string zanr, int godIzdavanja) {
        if(knjige.find(evidencijskiBroj) != knjige.end()) throw logic_error("Knjiga vec postoji");
        shared_ptr<Knjiga> knjiga = make_shared<Knjiga>(naslov, pisac, zanr, godIzdavanja);
        knjige.insert(std::make_pair(evidencijskiBroj,knjiga));
    }

    Korisnik& NadjiKorisnika(int clanskiBroj)const {
        auto it = korisnici.find(clanskiBroj);
        if(it==korisnici.end()) throw logic_error("Korisnik nije nadjen");
        return *(it->second);
    }
    Knjiga& NadjiKnjigu(int evidencijskiBroj)const {
        auto it = knjige.find(evidencijskiBroj);
        if(it==knjige.end()) throw logic_error("Knjigak nije nadjen");
        return *(it->second);
    }



    void IzlistajKorisnike()const {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
            cout<<"Clanski broj: "<<it->first<<endl;
            cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl;
            cout<<"Adresa: "<<it->second->adresa<<endl;
            cout<<"Broj telefona: "<<it->second->telefon<<endl;
            cout<<endl;
        }
    }
    void IzlistajKnjige()const {
        for(auto it=knjige.begin(); it!=knjige.end(); it++) {
            cout<<"Evidencijski broj: "<<it->first<<endl;
            cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
            cout<<"Pisac: "<<it->second->DajAutora()<<endl;
            cout<<"Zanr: "<<it->second->DajZanr()<<endl;
            cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
            if(it->second->DaLiJeZaduzena()){
                cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;
            }
            cout<<endl;
        }
    }
    
    void ZaduziKnjigu(int evidencijskiBroj, int clanskiBroj){
        auto itKnjiga = knjige.find(evidencijskiBroj);
        if(itKnjiga==knjige.end())throw logic_error("Knjiga nije nadjena");
        auto itKorisnik = korisnici.find(clanskiBroj);
        if(itKorisnik==korisnici.end()) throw logic_error("Korisnik nije nadjen");
        if(itKnjiga->second->DaLiJeZaduzena()) throw logic_error("Knjiga vec zaduzena");
        itKnjiga->second->ZaduziKnjigu(*(itKorisnik->second));
    }
    
    
    void RazduziKnjigu(int evidencijskiBroj){
        auto itKnjiga = knjige.find(evidencijskiBroj);
        if(itKnjiga==knjige.end())throw logic_error("Knjiga nije nadjena");
     
        if(!itKnjiga->second->DaLiJeZaduzena())throw logic_error("Knjiga nije zaduzena");
        
        itKnjiga->second->RazduziKnjigu();
    }
    
        void PrikaziZaduzenja(int clanskiBroj){
        int provjera=0;
        auto itKorisnik = korisnici.find(clanskiBroj);
        if(itKorisnik==korisnici.end()) throw logic_error ("Korisnik nije nadjen");
        for(auto itKnjige=knjige.begin(); itKnjige!=knjige.end(); itKnjige++){
          auto pok = itKnjige->second->DajKodKogaJe();
            if(pok==&*(itKorisnik->second))  {
            provjera++;
            cout<<"Evidencijski broj: "<<itKnjige->first<<endl;
            cout<<"Naslov: "<<itKnjige->second->DajNaslov()<<endl;
            cout<<"Pisac: "<<itKnjige->second->DajAutora()<<endl;
            cout<<"Zanr: "<<itKnjige->second->DajZanr()<<endl;
            cout<<"Godina izdavanja: "<<itKnjige->second->DajGodinuIzdavanja()<<endl;
            cout<<endl;
            }
        }
        if(provjera==0) std::cout<<"Nema zaduzenja za tog korisnika!";
    }
    

};
int main ()
{



    return 0;
}