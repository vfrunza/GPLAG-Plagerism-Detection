/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <utility>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* korisnik;
    public:
        Knjiga(std::string naslov1, std::string ime_pisca1, std::string zanr1, int godina_izdavanja1){
            naslov=naslov1;
            ime_pisca=ime_pisca1;
            zanr=zanr1;
            godina_izdavanja=godina_izdavanja1;
            korisnik=nullptr;
        }
        std::string DajNaslov() const {
            return naslov;
        }
        std::string DajAutora() const {
            return ime_pisca;
        }
        std::string DajZanr() const {
            return zanr;
        }
        int DajGodinuIzdavanja() const {
            return godina_izdavanja;
        }
        void ZaduziKnjigu(Korisnik &korisnik1){
            korisnik=&korisnik1;
        }
        void RazduziKnjigu(){
            korisnik=nullptr;
        }
        bool DaLiJeZaduzena() const {
            if(korisnik != nullptr) return 1;
            return 0;
        }
        Korisnik* DajKodKogaJe() const {
            return korisnik;
        }
};

class Biblioteka {
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
    public:
        Biblioteka() = default;
        
        Biblioteka(const Biblioteka &biblioteka){
            korisnici = biblioteka.korisnici;
            knjige = biblioteka.knjige;
            for(auto it = korisnici.begin(); it!=korisnici.end(); it++){
                Korisnik* k = new Korisnik;
                *k = *(it->second);
                it->second = k;
            }
            for(auto it = knjige.begin(); it!=knjige.end(); it++){
                it->second = new Knjiga(*(it->second));
            }
        }
        
        Biblioteka(Biblioteka &&biblioteka){
            korisnici = std::move(biblioteka.korisnici);
            knjige = std::move(biblioteka.knjige);
        }
        
        Biblioteka &operator = (const Biblioteka &biblioteka){
            for(auto it = korisnici.begin(); it != korisnici.end(); it++){
                delete it->second;
                it->second = nullptr;
            }
            for(auto it = knjige.begin(); it != knjige.end(); it++){
                delete it->second;
                it->second = nullptr;
            }
            korisnici = biblioteka.korisnici;
            knjige = biblioteka.knjige;
            for(auto it = korisnici.begin(); it!=korisnici.end(); it++){
                auto *k = new Korisnik;
                *k = *it->second;
                it->second = k;
            }
            for(auto it = knjige.begin(); it!=knjige.end(); it++){
                it->second = new Knjiga(*(it->second));
            }
            return *this;
        }
        
        Biblioteka &operator = (Biblioteka &&biblioteka){
            for(auto it = korisnici.begin(); it != korisnici.end(); it++){
                delete it->second;
                it->second = nullptr;
            }
            for(auto it = knjige.begin(); it != knjige.end(); it++){
                delete it->second;
                it->second = nullptr;
            }
            korisnici = std::move(biblioteka.korisnici);
            knjige = std::move(biblioteka.knjige);
            return *this;
        }
        
        ~Biblioteka(){
            for(auto it = korisnici.begin(); it != korisnici.end(); it++){
                delete it->second;
                it->second = nullptr;
            }
            for(auto it = knjige.begin(); it != knjige.end(); it++){
                delete it->second;
                it->second = nullptr;
            }
        }
        
        void RegistrirajNovogKorisnika(int clanski, std::string ime, std::string prezime, std::string adresa, std::string telefon){
            Korisnik* k(new Korisnik{ime, prezime, adresa, telefon});
            if(korisnici.count(clanski)) {
                delete k;
                throw std::logic_error ("Korisnik vec postoji");
            }
            korisnici[clanski] = k;
        }
        
        void RegistrirajNovuKnjigu(int broj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja){
            Knjiga* k(new Knjiga(naslov, ime_pisca, zanr, godina_izdavanja));
            if(knjige.count(broj)) {
                delete k;
                throw std::logic_error ("Knjiga vec postoji");
            }
            knjige[broj] = k;
        }
        
        Korisnik &NadjiKorisnika(int clanski) {
            if(!korisnici.count(clanski)) throw std::logic_error ("Korisnik nije nadjen");
            return *(korisnici[clanski]);
        }
        
        Knjiga &NadjiKnjigu(int broj) {
            if(!knjige.count(broj)) throw std::logic_error ("Knjiga nije nadjena");
            return *(knjige[broj]);
        }
        
        void IzlistajKorisnike() const{
            for(auto x : korisnici){
                std::cout << "Clanski broj: "<<x.first << std::endl;
                std::cout << "Ime i prezime: " << x.second->ime << " "<< x.second->prezime << std::endl;
                std::cout << "Adresa: " << x.second->adresa << std::endl;
                std::cout << "Broj telefona: " << x.second->telefon << std::endl;
                std::cout << std::endl;
            }
        }
        
        void IzlistajKnjige() const{
            for(auto x : knjige){
                std::cout << "Evidencijski broj: " << x.first << std::endl;
                std::cout << "Naslov: " << x.second->DajNaslov() << std::endl;
                std::cout << "Pisac: " << x.second->DajAutora() << std::endl;
                std::cout << "Zanr: " << x.second->DajZanr() << std::endl;
                std::cout << "Godina izdavanja: " << x.second->DajGodinuIzdavanja() << std::endl;
                if(x.second->DaLiJeZaduzena()) std::cout << "Zaduzena kod korisnika: " << x.second->DajKodKogaJe()->ime << " " << x.second->DajKodKogaJe()->prezime << std::endl;
                std::cout << std::endl;
            }
        }
        
        void ZaduziKnjigu(int broj, int clanski){
            if(!knjige.count(broj)) throw std::logic_error ("Knjiga nije nadjena");
            if(!korisnici.count(clanski)) throw std::logic_error ("Korisnik nije nadjen");
            if(knjige[broj]->DaLiJeZaduzena()) throw std::logic_error ("Knjiga vec zaduzena");
            knjige[broj]->ZaduziKnjigu(*(korisnici[clanski]));
        }

        void RazduziKnjigu(int broj){
            if(!knjige.count(broj)) throw std::logic_error ("Knjiga nije nadjena");
            if(!knjige[broj]->DaLiJeZaduzena()) throw std::logic_error ("Knjiga nije zaduzena");
            knjige[broj]->RazduziKnjigu();
        }        
        
        void PrikaziZaduzenja(int clanski) {
            if(!korisnici.count(clanski)) throw std::logic_error ("Korisnik nije nadjen");
            bool zaduzena(false);
            for(auto x : knjige){
                if(x.second->DajKodKogaJe() == korisnici[clanski]) {
                    std::cout << "Evidencijski broj: " << x.first << std::endl;
                    std::cout << "Naslov: " << x.second->DajNaslov() << std::endl;
                    std::cout << "Pisac: " << x.second->DajAutora() << std::endl;
                    std::cout << "Zanr: " << x.second->DajZanr() << std::endl;
                    std::cout << "Godina izdavanja: " << x.second->DajGodinuIzdavanja() << std::endl;
                    std::cout << std::endl;
                    zaduzena = true;
                }
            }
            if(!zaduzena) std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
        }
        
};




int main ()
{
	return 0;
}