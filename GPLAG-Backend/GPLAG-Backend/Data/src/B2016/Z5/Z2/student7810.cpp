/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::make_shared;
using std::shared_ptr;

struct Korisnik{
    string ime,prezime,adresa,telefon;  
};
class Knjiga{
    string naslov,ime_pisca,zanr;
    int godina_izdavanja;
    Korisnik* zaduzenje;
    public:
    Knjiga(string nas, string pisac, string zanrknjige, int godina) : naslov(nas), ime_pisca(pisac), zanr(zanrknjige), godina_izdavanja(godina), zaduzenje(nullptr) {}
    string DajNaslov ()const{return naslov;}
    string DajAutora ()const{return ime_pisca;}
    string DajZanr ()const{return zanr;}
    int DajGodinuIzdavanja() const{return godina_izdavanja;}
    Korisnik* DajKodKogaJe()const{return zaduzenje;}
    void ZaduziKnjigu(Korisnik &korisnik) {zaduzenje=&korisnik;}
    void RazduziKnjigu (){zaduzenje=nullptr;}
    bool DaLiJeZaduzena (){if (!zaduzenje) return false; else return true;}
};
class Biblioteka{
    map<int, shared_ptr<Korisnik>> korisnici;
    map<int, shared_ptr<Knjiga>> knjige;
    public:
    Biblioteka(){};
    Biblioteka (const Biblioteka& bibloiteka){
        for(auto it : bibloiteka.knjige){
            this->RegistrirajNovuKnjigu(it.first,(it.second)->DajNaslov(),(it.second)->DajAutora(),(it.second)->DajZanr(),(it.second)->DajGodinuIzdavanja());
        }
        for(auto it : bibloiteka.korisnici){
            this->RegistrirajNovogKorisnika(it.first,(it.second)->ime,(it.second)->prezime,(it.second)->adresa,(it.second)->telefon);
        }
        for(auto it : bibloiteka.korisnici){
            for(auto it1 : bibloiteka.knjige){
                auto novikorisnik((it1.second)->DajKodKogaJe());
                if (novikorisnik==(it.second).get()){
                    this->ZaduziKnjigu(it1.first,it.first);
                }
            }
        }
    }
    Biblioteka(Biblioteka&& bibloiteka){
        korisnici=bibloiteka.korisnici;
        knjige=bibloiteka.knjige;
        for(auto it(korisnici.begin());it!=korisnici.end();it++) it->second=nullptr;
        for(auto it(knjige.begin());it!=knjige.end();it++) it->second=nullptr;

    }
    Biblioteka& operator =(const Biblioteka& bibloiteka){
        if(&bibloiteka!=this){
            for(auto it : bibloiteka.knjige) it.second=nullptr;
            for(auto it : bibloiteka.korisnici) it.second=nullptr;
            korisnici.erase(korisnici.begin(), korisnici.end());
            knjige.erase(knjige.begin(), knjige.end());
            for(auto it : bibloiteka.knjige){
                this->RegistrirajNovuKnjigu(it.first,(it.second)->DajNaslov(),(it.second)->DajAutora(),(it.second)->DajZanr(),(it.second)->DajGodinuIzdavanja());
            }
            for(auto it : bibloiteka.korisnici){
                this->RegistrirajNovogKorisnika(it.first,(it.second)->ime,(it.second)->prezime,(it.second)->adresa,(it.second)->telefon);
            }
        }
        for(auto it : bibloiteka.korisnici){
            for(auto it1 : bibloiteka.knjige){
                auto novikorisnik((it1.second)->DajKodKogaJe());
                if (novikorisnik==(it.second).get()){
                    this->ZaduziKnjigu(it1.first,it.first);
                }
            }
        }
        return *this;
    }
    Biblioteka& operator =(Biblioteka&& bibloiteka){
        if(&bibloiteka!=this){
            for(auto it : bibloiteka.knjige)  it.second=nullptr;
            for(auto it : bibloiteka.korisnici) it.second=nullptr;
            korisnici.erase(korisnici.begin(), korisnici.end());
            knjige.erase(knjige.begin(), knjige.end());
            for(auto it : bibloiteka.knjige){
                this->RegistrirajNovuKnjigu(it.first,(it.second)->DajNaslov(),(it.second)->DajAutora(),(it.second)->DajZanr(),(it.second)->DajGodinuIzdavanja());
            }
            for(auto it : bibloiteka.korisnici){
                this->RegistrirajNovogKorisnika(it.first,(it.second)->ime,(it.second)->prezime,(it.second)->adresa,(it.second)->telefon);
            }
        }
        korisnici=bibloiteka.korisnici;
        knjige=bibloiteka.knjige;
        for(auto it(korisnici.begin());it!=korisnici.end();it++) it->second=nullptr;
        for(auto it(knjige.begin());it!=knjige.end();it++) it->second=nullptr;
        return *this;
    }
    /*~Biblioteka(){ for(auto it(korisnici.begin());it!=korisnici.end();it++) delete it->second;
        for(auto it(knjige.begin());it!=knjige.end();it++) delete it->second;
    }*/
    void RegistrirajNovogKorisnika(int clanski, string i, string p, string adr, string broj){
        for(auto it(korisnici.begin());it!=korisnici.end();it++){
            if(it->first==clanski) throw std::logic_error ("Korisnik vec postoji");
        }
        auto pok(make_shared< Korisnik>()); pok->ime=i;pok->prezime=p;pok->adresa=adr;pok->telefon=broj;
        korisnici.insert(std::make_pair(clanski, pok));
    }
    void RegistrirajNovuKnjigu(int evbr, string nas, string pisac, string zanrknjige, int godina){
        for(auto it(knjige.begin());it!=knjige.end();it++){
            if(it->first==evbr) throw std::logic_error ("Knjiga vec postoji");
        }
        knjige.insert(std::make_pair(evbr,make_shared <Knjiga>(nas,pisac,zanrknjige,godina)));
    }
    Korisnik& NadjiKorisnika(int clanski){
        for(auto it(korisnici.begin());it!=korisnici.end();it++){
            if(it->first==clanski) return *(it->second);
        }
        throw std::logic_error ("Korisnik nije nadjen");
    }
    Knjiga& NadjiKnjigu(int evbr){
        for(auto it(knjige.begin());it!=knjige.end();it++){
            if(it->first==evbr) return *(it->second);
        }
        throw std::logic_error ("Knjiga nije nadjena");
    }
    void IzlistajKorisnike(){
        for(auto it(korisnici.begin());it!=korisnici.end();it++){
            cout<<"Clanski broj: "<<it->first<<endl<<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<endl<<"Adresa: "<<(it->second)->adresa<<endl<<"Broj telefona: "<<(it->second)->telefon<<endl;
        }
    }
    void IzlistajKnjige(){
        for(auto it(knjige.begin());it!=knjige.end();it++){
            cout<<"Evidencijski broj: "<<it->first<<endl<<"Naslov: "<<(it->second)->DajNaslov()<<endl<<"Pisac: "<<(it->second)->DajAutora()<<endl<<"Zanr: "<<(it->second)->DajZanr()<<endl<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<endl;
            if((it->second)->DaLiJeZaduzena()){
                cout<<"Zaduzena kod korisnika: "<<(((it->second)->DajKodKogaJe())->ime)<<" "<<(((it->second)->DajKodKogaJe())->prezime)<<endl;
            }
        }
    }
    void ZaduziKnjigu(int evbr, int clanski){
        bool ima(false);
        auto pokkor(korisnici.begin());
        for(auto it(korisnici.begin());it!=korisnici.end();it++){
            if(it->first==clanski) {ima=true;pokkor=it;break;}
        }
        if(!ima) throw std::logic_error ("Korisnik nije nadjen");
        ima=false;
        auto pokknjig(knjige.begin());
        for(auto it(knjige.begin());it!=knjige.end();it++){
            if(it->first==evbr) {ima=true;pokknjig=it;break;}
        }
        if(!ima) throw std::logic_error ("Knjiga nije nadjena");
        else if(ima){
            if((pokknjig->second)->DaLiJeZaduzena()) throw std::logic_error ("Knjiga vec zaduzena");
            else{
                (pokknjig->second)->ZaduziKnjigu(*(pokkor->second));
            }
        }
        
    }
    void RazduziKnjigu(int evbr){
        bool ima(false);
        auto pokknjig(knjige.begin());
        for(auto it(knjige.begin());it!=knjige.end();it++){
            if(it->first==evbr) {ima=true;pokknjig=it;break;}
        }
        if(!ima) throw std::logic_error ("Knjiga nije nadjena");
        else if(!(pokknjig->second)->DaLiJeZaduzena()) throw std::logic_error ("Knjiga nije zaduzena");
        else{
            (pokknjig->second)->RazduziKnjigu();
        }
    }
    void PrikaziZaduzenja(int clanski){
        bool ima(false);
        auto pokkor(korisnici.begin());
        for(auto it(korisnici.begin());it!=korisnici.end();it++){
            if(it->first==clanski) {ima=true;pokkor=it;break;}
        }
        if(!ima) throw std::logic_error ("Korisnik nije nadjen");
        else{
            for(auto it(knjige.begin());it!=knjige.end();it++){
            if(((it->second)->DajKodKogaJe())==(pokkor->second).get())
            {cout<<"Evidencijski broj: "<<it->first<<endl<<"Naslov: "<<(it->second)->DajNaslov()<<endl<<"Pisac: "<<(it->second)->DajAutora()<<endl<<"Zanr: "<<(it->second)->DajZanr()<<endl<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<endl;}
        }
        }
    }
};
int main ()
{
    Biblioteka bib5;
    bib5.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
    bib5.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
    std::cout << bib5.NadjiKnjigu(2).DajNaslov();
	return 0;
}