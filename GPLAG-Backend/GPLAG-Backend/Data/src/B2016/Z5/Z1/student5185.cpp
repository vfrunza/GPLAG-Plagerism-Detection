/*  {/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
} */
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga{
        std::string naslovKnjige, imePisca, zanr;
        int godinaIzdavanja;
        Korisnik* zaduzeno;
    public: //Konstruktor
    Knjiga(std::string naslovKnjige, std::string imePisca, std::string zanr, int godinaIzdavanja) : naslovKnjige(naslovKnjige), imePisca(imePisca), zanr(zanr), godinaIzdavanja(godinaIzdavanja), zaduzeno(nullptr) {}
    
    //Pristupne metode
    std::string DajNaslov()const{
        return naslovKnjige;
    }
    std::string DajAutora()const{
        return imePisca;
    }
    std::string DajZanr()const{
        return zanr;
    }
    int DajGodinuIzdavanja() const{
        return godinaIzdavanja;
    }
    Korisnik* DajKodKogaJe() const{
        return zaduzeno;
    }
    
    //Dodatne metode
    void ZaduziKnjigu(Korisnik &k){
       
        zaduzeno = &k;
    }
    void RazduziKnjigu(){
        zaduzeno = nullptr;
    }
    bool DaLiJeZaduzena(){
        if (zaduzeno == nullptr) return false;
        return true;
    }
    
};

class Biblioteka{
        std::map<int, Korisnik*> korisnici;
        std::map<int, Knjiga*> knjige;
        void Pomocna(int evBr, Knjiga* knjiga) const{
            std::cout << "Evidencijski broj: " << evBr << std::endl
                << "Naslov: " << knjiga->DajNaslov() << std::endl
                << "Pisac: "<< knjiga->DajAutora() << std::endl
                << "Zanr: " << knjiga->DajZanr() << std::endl
                << "Godina izdavanja: " << knjiga->DajGodinuIzdavanja() << std::endl;
        }
    public:   
        Biblioteka(){}
        Biblioteka(const Biblioteka &b){ 
            try{ //U slucaju nekog izuzetka
                for (auto i : b.korisnici){
                    Korisnik* k (new Korisnik(*i.second));
                    korisnici.insert(std::make_pair(i.first, k));
                } 
            }
            catch (...){
                for (auto i : korisnici){
                    delete i.second; i.second = nullptr;
                } 
                throw;
            }
            try{
                for (auto i : b.knjige) {
                    Knjiga* k(new Knjiga (*i.second));
                    knjige.insert(std::make_pair(i.first, k));
                }
            }catch (...){
                for (auto i : knjige){
                    delete i.second; i.second = nullptr;
                } 
                throw;
            }
            
            
        }//Trebalo bi da radi, sigurno pravi duboke kopije
        Biblioteka(Biblioteka &&b){
            //Prvo obrisati sve pokazivace
            for (auto i : knjige) {delete i.second; i.second = nullptr;}
            for (auto i : korisnici) {delete i.second; i.second = nullptr;}
            
            //Ocistiti mape
            korisnici.clear();
            knjige.clear();
            
            //Kopirati i obrisati pokazivace
            for (auto i : b.korisnici) {
                korisnici.insert(std::make_pair(i.first, i.second));
                
            }
            for (auto i : b.knjige) {
                knjige.insert(std::make_pair(i.first, i.second));
                
            }
            b.korisnici.clear();
            b.knjige.clear();
            
        }
        Biblioteka &operator =(const Biblioteka &b){
            try{ //U slucaju nekog izuzetka
                for (auto i : b.korisnici){
                    Korisnik* k (new Korisnik(*i.second));
                    korisnici.insert(std::make_pair(i.first, k));
                } 
            }
            catch (...){
                for (auto i : korisnici){
                    delete i.second; i.second = nullptr;
                } 
                throw;
            }
            try{
                for (auto i : b.knjige) {
                    Knjiga* k(new Knjiga (*i.second));
                    knjige.insert(std::make_pair(i.first, k));
                }
            }catch (...){
                for (auto i : knjige){
                    delete i.second; i.second = nullptr;
                } 
                throw;
            }
            
            return *this;
        } //Trebalo bi da radi, sigurno pravi duboke kopije
        Biblioteka &operator =(Biblioteka &&b){ 
            //Prvo obrisati sve pokazivace
            for (auto i : knjige) {delete i.second; i.second = nullptr;}
            for (auto i : korisnici) {delete i.second; i.second = nullptr;}
            
            //Ocistiti mape
            korisnici.clear();
            knjige.clear();
            
            //Kopirati i obrisati pokazivace
            for (auto i : b.korisnici) {
                korisnici.insert(std::make_pair(i.first, i.second));
                
            }
            for (auto i : b.knjige) {
                knjige.insert(std::make_pair(i.first, i.second));
                
            }
            b.korisnici.clear();
            b.knjige.clear();
            
            return *this;
        }
        ~Biblioteka(){
            for (auto i : knjige) {delete i.second; i.second = nullptr;}
            for (auto i : korisnici) {delete i.second; i.second = nullptr;}
            
        }
        
        void RegistrirajNovogKorisnika (int clanskiBroj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
            for (auto i : korisnici) if (clanskiBroj == i.first) throw std::logic_error ("Korisnik vec postoji");
            //Ako nije bacio izuzetak znaci da nema tog cl broja
            Korisnik* k1(new Korisnik); //stvori pok
            k1->ime = ime; k1->prezime = prezime; k1->adresa = adresa; k1->telefon=telefon; //popuni info
            korisnici.insert(std::make_pair(clanskiBroj, k1)); // ubaci u mapu
        }
        
        void RegistrirajNovuKnjigu(int evidencijskiBroj, std::string naslovKnjige, std::string imePisca, std::string zanr, int godinaIzdavanja){
            for (auto i : knjige) if (evidencijskiBroj == i.first) throw std::logic_error ("Knjiga vec postoji");
            
            knjige.insert(std::make_pair(evidencijskiBroj, new Knjiga (naslovKnjige, imePisca, zanr, godinaIzdavanja)));
        } //
        
        Korisnik &NadjiKorisnika (int clanskiBroj) const{
            for (auto i : korisnici) if (clanskiBroj == i.first) return *(i.second);
            throw std::logic_error ("Korisnik nije nadjen");
        } //
        
        Knjiga &NadjiKnjigu (int evidencijskiBroj) const{
            for (auto i : knjige) if (evidencijskiBroj == i.first) return *(i.second);
            throw std::logic_error ("Knjiga nije nadjena");
        } //
        
        void IzlistajKorisnike() const{
            for (auto i : korisnici) {
                std::cout << "Clanski broj: " << i.first << std::endl
                << "Ime i prezime: " << i.second->ime << " " << i.second->prezime << std::endl
                << "Adresa: " << i.second->adresa << std::endl
                << "Broj telefona: " << i.second->telefon << std::endl << std::endl;
            }
        }
        
        void IzlistajKnjige() const{
            for (auto i : knjige) {
                Pomocna(i.first, i.second);
           
                if (i.second->DaLiJeZaduzena()){
                    
                std::cout << "Zaduzena kod korisnika: " << i.second->DajKodKogaJe()->ime << " " << i.second->DajKodKogaJe()->prezime << std::endl;}
                std::cout << std::endl;
            }
        } //
        
        void ZaduziKnjigu(int evidencijskiBroj, int clanskiBroj){
            
            
            if (NadjiKnjigu(evidencijskiBroj).DaLiJeZaduzena()) throw std::logic_error ("Knjiga vec zaduzena");
                
            NadjiKnjigu(evidencijskiBroj).Knjiga::ZaduziKnjigu(NadjiKorisnika(clanskiBroj));
        } //
        
        void RazduziKnjigu(int evidencijskiBroj){

            if (!(NadjiKnjigu(evidencijskiBroj).DaLiJeZaduzena())) throw std::logic_error ("Knjiga nije zaduzena");
            
            NadjiKnjigu(evidencijskiBroj).Knjiga::RazduziKnjigu();
        } //
        
        void PrikaziZaduzenja (int clanskiBroj) const{
            int brojac(0); 
            Korisnik k1 (NadjiKorisnika(clanskiBroj)); // To je taj clan
            for (auto i : knjige) {
                Korisnik *pokNaKorisnika(i.second->DajKodKogaJe());
                if (pokNaKorisnika == nullptr) continue;
                Korisnik k2 (*pokNaKorisnika); // Trazimo knige koje ima
                
                if (k1.ime == k2.ime && k1.prezime == k2.prezime && k1.adresa == k2.adresa && k1.telefon == k2.telefon) {
                    Pomocna(i.first, i.second);
                    brojac++;
                }
            }
            if (brojac==0) throw std::logic_error("Nema zaduzenja za tog korisnika!");
            
        } 
};


int main (){
    
    Biblioteka b; 
    for (;;){
        std::cout << "Dobrodosli. Vasa biblioteka je trenutno prazna. Da li zelite raditi sa knjigama(1), clanovima(2) ili izaci (0)? ";
        int n=0; std::cin >> n;
        if (n == 0) break;
        else if (n == 1)
            for(;;){
                std::cout << "Da li zelite dodati registrovati nove knjige (1), izlistati knjige(2), zaduziti(3) ili razduziti knjigu(4) [0 za kraj] ? ";
                int m; std::cin >> m;
                if (m == 0) break;
                else if (m == 1){
                    int evidencijskiBroj,  godinaIzdavanja; std::string naslovKnjige, imePisca, zanr; 
                    std::cout << "Unesite evidencijski broj: "; std::cin >> evidencijskiBroj; std::cin.ignore(10000, '\n');
                    std::cout << "Unesite naslov knjige: "; std::getline(std::cin, naslovKnjige);
                    std::cout << "Unesite ime autora knjige: "; std::getline(std::cin, imePisca);
                    std::cout << "Unesite zanr knjige: "; std::getline(std::cin, zanr);
                    std::cout << "Unesite godinu izdavanja: "; std::cin >> godinaIzdavanja; std::cin.ignore(10000, '\n');
                    b.RegistrirajNovuKnjigu(evidencijskiBroj, naslovKnjige, imePisca, zanr, godinaIzdavanja);
                }
                else if (m==2){
                    b.IzlistajKnjige();
                }
                else if (m==3){
                    int evidencijskiBroj, clanskiBroj;
                    std::cout << "Unesite evidencijski broj: "; std::cin >> evidencijskiBroj; std::cin.ignore(10000, '\n');
                    std::cout << "Unesite clanski broj: "; std::cin >> clanskiBroj; std::cin.ignore(10000, '\n');
                    b.ZaduziKnjigu(evidencijskiBroj, clanskiBroj);
                }
                else if (m==4){
                    int evidencijskiBroj;
                    std::cout << "Unesite evidencijski broj: "; std::cin >> evidencijskiBroj; std::cin.ignore(10000, '\n');
                    
                    b.RazduziKnjigu(evidencijskiBroj);
                }
            }
        
        else if (n == 2)
            for(;;){
                std::cout << "Da li zelite dodati registrovati nove clanove (1), izlistati clanove(2), prikazati zaduzenja (3) [0 za kraj] ? ";
                int m; std::cin >> m;
                if (m == 0) break;
                else if (m == 1){
                    int clanskiBroj; std::string ime, prezime, adresa, telefon; 
                    std::cout << "Unesite clanski broj: "; std::cin >> clanskiBroj; std::cin.ignore(10000, '\n');
                    std::cout << "Unesite ime clana: "; std::getline(std::cin, ime);
                    std::cout << "Unesite prezime clana: "; std::getline(std::cin, prezime);
                    std::cout << "Unesite adresu clana: "; std::getline(std::cin, adresa);
                    std::cout << "Unesite telefon clana:  "; std::getline(std::cin, telefon);
                    b.RegistrirajNovogKorisnika(clanskiBroj, ime, prezime, adresa, telefon);
                }
                else if (m==2){
                    b.IzlistajKorisnike();
                }
                else if (m==3){
                    int clanskiBroj;
                    std::cout << "Unesite clanski broj: "; std::cin >> clanskiBroj; std::cin.ignore(10000, '\n');
                    b.PrikaziZaduzenja(clanskiBroj);
                }
                
            }
        
        else{
            std::cout << "greska, ponovite unos" << std::endl;
            std::cin.clear(); std::cin.ignore(10000, '\n');
        }
    }
    
    
	return 0;
}