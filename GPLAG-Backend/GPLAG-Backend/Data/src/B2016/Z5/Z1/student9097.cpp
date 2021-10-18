/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>
struct Korisnik{
    std::string ime,prezime,adresa,telefon;
};
class Knjiga{
    std::string Naslov,Autor,Zanr;
    int GodinaIzdavanja;
    Korisnik* KodKogaJe;
    public:
        Knjiga(std::string Naslov,std::string ImePisca,std::string Zanr, int GodinaIzdavanja): Naslov(Naslov),Autor(ImePisca),Zanr(Zanr),GodinaIzdavanja(GodinaIzdavanja),KodKogaJe(nullptr) {}
        std::string DajNaslov() const{return Naslov;}
        std::string DajAutora() const{return Autor;}
        std::string DajZanr() const{return Zanr;}
        int DajGodinuIzdavanja() const{return GodinaIzdavanja;}
        Korisnik* DajKodKogaJe() const{return KodKogaJe;}
        void ZaduziKnjigu(Korisnik &korisnik){KodKogaJe=&korisnik;}
        void RazduziKnjigu(){KodKogaJe=nullptr;}
        bool DaLiJeZaduzena() const{if(!KodKogaJe)return false; return true;}
};
class Biblioteka{
    std::map<int,Korisnik*> Korisnici;
    std::map<int,Knjiga*> Knjige;
    public:
        Biblioteka(){}
        ~Biblioteka(){
            for(auto it=Korisnici.begin();it!=Korisnici.end();it++){delete it->second; it->second=nullptr;}
            for(auto it=Knjige.begin();it!=Knjige.end();it++){delete it->second;it->second=nullptr;}
        }
        Biblioteka(const Biblioteka &b){
            for(auto &x: b.Korisnici){
                auto pok(new Korisnik);
                *pok=*(x.second);
                Korisnici[x.first]=pok;
            }
            for(auto &x: b.Knjige){
                auto pok(new Knjiga(x.second->DajNaslov(),x.second->DajAutora(),x.second->DajZanr(),x.second->DajGodinuIzdavanja()));
                Knjige[x.first]=pok;
                if(x.second->DaLiJeZaduzena()){
                    for(auto &y :b.Korisnici) if(y.second==x.second->DajKodKogaJe()) this->ZaduziKnjigu(x.first,y.first);
                }
            }
        }
        Biblioteka &operator=(const Biblioteka &b){
            if(&b!=this){
                for(auto &x: Korisnici){delete x.second; x.second=nullptr;}
                for(auto &x: Knjige){delete x.second; x.second=nullptr;}
                Knjige.erase(Knjige.begin(),Knjige.end());
                Korisnici.erase(Korisnici.begin(),Korisnici.end());
                Korisnici=b.Korisnici;
                Knjige=b.Knjige;
                for(auto &x: Korisnici){
                    auto pok(new Korisnik);
                    *pok=*(x.second);
                    x.second=pok;
                }
                for(auto &x: Knjige){
                    auto pok(new Knjiga(x.second->DajNaslov(),x.second->DajAutora(),x.second->DajZanr(),x.second->DajGodinuIzdavanja()));
                    if(x.second->DaLiJeZaduzena()){
                        for(auto &y: b.Korisnici) if(y.second==x.second->DajKodKogaJe()) pok->ZaduziKnjigu(*(Korisnici[y.first]));
                    }
                    x.second=pok;
                }
            }
            return *this;
        }
        Biblioteka(Biblioteka &&b){
            Korisnici=b.Korisnici;
            Knjige=b.Knjige;
            for(auto &x: b.Korisnici){x.second=nullptr;}
            for(auto &x: b.Knjige){x.second=nullptr;}
        }
        Biblioteka &operator=(Biblioteka &&b){
            if(&b!=this){
                for(auto &x: Korisnici){delete x.second; x.second=nullptr;}
                for(auto &x: Knjige){delete x.second;x.second=nullptr;}
                Knjige.erase(Knjige.begin(),Knjige.end());
                Korisnici.erase(Korisnici.begin(),Korisnici.end());
                Korisnici=b.Korisnici;
                Knjige=b.Knjige;
                for(auto &x: b.Korisnici){x.second=nullptr;}
                for(auto &x: b.Knjige){x.second=nullptr;}
            }
            return *this;
        }
        void RegistrirajNovogKorisnika(int ClanskiBrojKorisnika,std::string Ime,std::string Prezime, std::string Adresa,std::string BrojTelefona){
            auto it(Korisnici.find(ClanskiBrojKorisnika));
            if(it!=Korisnici.end()) throw std::logic_error("Korisnik vec postoji");
            try{
                auto pok(new Korisnik);
                pok->ime=Ime;
                pok->prezime=Prezime;
                pok->adresa=Adresa;
                pok->telefon=BrojTelefona;
                Korisnici[ClanskiBrojKorisnika]=pok;
            }catch(std::bad_alloc){
                std::cout<<"Greska pri alokaciji";
            }
        }
        void RegistrirajNovuKnjigu(int EvidencijskiBrojKnjige,std::string Naslov,std::string Autor,std::string Zanr,int GodinaIzdavanja){
            auto it(Knjige.find(EvidencijskiBrojKnjige));
            if(it!=Knjige.end()) throw std::logic_error("Knjiga vec postoji");
            try{
                auto pok(new Knjiga(Naslov,Autor,Zanr,GodinaIzdavanja));
                Knjige[EvidencijskiBrojKnjige]=pok;
            }catch(std::bad_alloc){
                std::cout<<"Greska pri alokaciji";
            }
        }
        Korisnik &NadjiKorisnika(int ClanskiBrojKorisnika) const{
            auto it(Korisnici.find(ClanskiBrojKorisnika));
            if(it==Korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
            return *(it->second);
        }
        Knjiga &NadjiKnjigu(int EvidencijskiBrojKnjige) const{
            auto it(Knjige.find(EvidencijskiBrojKnjige));
            if(it==Knjige.end()) throw std::logic_error("Knjiga nije nadjena");
            return *(it->second);
        }
        void IzlistajKorisnike() const{
            for(auto &x:Korisnici)
                std::cout<<"\nClanski broj: "<<x.first<<"\nIme i prezime: "<<x.second->ime<<" "<<x.second->prezime<<"\nAdresa: "<<x.second->adresa<<"\nBroj telefona: "<<x.second->telefon;
        }
        void IzlistajKnjige() const{
            for(auto &x:Knjige){
                std::cout<<"\nEvidencijski broj: "<<x.first<<"\nNaslov: "<<x.second->DajNaslov()<<"\nPisac: "<<x.second->DajAutora()<<"\nZanr: "<<x.second->DajZanr()<<"\nGodina izdavanja: "<<x.second->DajGodinuIzdavanja();
                if((x.second->DaLiJeZaduzena())) std::cout<<"\nZaduzena kod korisnika: "<<x.second->DajKodKogaJe()->ime<<" "<<x.second->DajKodKogaJe()->prezime;
                std::cout<<"\n";
            }
        }
        void ZaduziKnjigu(int EvidencijskiBrojKnjige, int ClanskiBrojKorisnika){
            auto Korisnik(Korisnici.find(ClanskiBrojKorisnika));
            auto Knjiga(Knjige.find(EvidencijskiBrojKnjige));
            if( Knjiga == Knjige.end()) throw std::logic_error("Knjiga nije nadjena");
            if( Korisnik== Korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
            if( Knjiga->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
            Knjiga->second->ZaduziKnjigu(*(Korisnik->second));
        }
        void RazduziKnjigu(int EvidencijskiBrojKnjige){
            auto Knjiga(Knjige.find(EvidencijskiBrojKnjige));
            if(Knjiga==Knjige.end()) throw std::logic_error("Knjiga nije nadjena");
            if(!(Knjiga->second->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
            Knjiga->second->RazduziKnjigu();
        }
        void PrikaziZaduzenja(int ClanskiBrojKorisnika) const{
            auto Korisnik(Korisnici.find(ClanskiBrojKorisnika));
            if(Korisnik==Korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
            bool ZaduzioIsta(false);
            for(auto &x:Knjige){
                if(x.second->DajKodKogaJe()==Korisnik->second){
                    if(!ZaduzioIsta) ZaduzioIsta=true;
                    std::cout<<"\nEvidencijski broj: "<<x.first<<"\nNaslov: "<<x.second->DajNaslov()<<"\nPisac: "<<x.second->DajAutora()<<"\nZanr: "<<x.second->DajZanr()<<"\nGodina izdavanja: "<<x.second->DajGodinuIzdavanja()<<"\n";
                }
            }
            if(!ZaduzioIsta) std::cout<<"Nema zaduzenja za tog korisnika!";
        }
};
int main (){
//AT9 (c9): testira IzlistajKnjige sa zaduzenim knjigama
Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
"Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
"Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
"Studenata etfovaca 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
b.ZaduziKnjigu(231, 1234);
b.ZaduziKnjigu(136, 1234);
b.PrikaziZaduzenja(1234);
	return 0;
}