/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map> 
#include <stdexcept>
#include <utility> 

struct Korisnik {
    std::string ime,prezime, adresa, telefon; 
}; 

class Knjiga {
    std::string naslov, ime_pisca, zanr; 
    int godina_izdavanja; 
    Korisnik *onaj_koji_je_zaduzio_knjigu; 
    
    public: 
    
    Knjiga (std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) {
        Knjiga::naslov=naslov; Knjiga::ime_pisca=ime_pisca; Knjiga::zanr=zanr; Knjiga::godina_izdavanja=godina_izdavanja; 
        onaj_koji_je_zaduzio_knjigu=nullptr; 
    }
    
    std::string DajNaslov() const  { return naslov; } 
    std::string DajAutora() const { return ime_pisca; } 
    std::string DajZanr() const { return zanr; } 
    int DajGodinuIzdavanja() const { return godina_izdavanja; } 
    Korisnik *DajKodKogaJe() const { return onaj_koji_je_zaduzio_knjigu; }
    
    void ZaduziKnjigu (Korisnik &onaj_koji_zaduzuje) {
        onaj_koji_je_zaduzio_knjigu=&onaj_koji_zaduzuje; 
    }
    
    void RazduziKnjigu () {
        onaj_koji_je_zaduzio_knjigu=0; 
    }

    bool DaLiJeZaduzena() {
        if (onaj_koji_je_zaduzio_knjigu==nullptr) return false; 
        else return true; 
    }
    
}; 

class Biblioteka {
    
    std::map<int, Korisnik*> korisnici; 
    std::map<int, Knjiga*> knjige; 
    
    public: 
    
    Biblioteka()=default; 
    Biblioteka &operator =(Biblioteka b) {
        std::swap(b.korisnici, korisnici); 
        std::swap(b.knjige, knjige); 
        return *this;
    }
    ~Biblioteka() {
        for (auto it=korisnici.begin(); it!=korisnici.end(); it++) 
        delete it->second; 
        
        for (auto it1=knjige.begin(); it1!=knjige.end(); it1++)
        delete it1->second; 
    }
    void RegistrirajNovogKorisnika(int clanski, std::string ime, std::string prezime, std::string adresa, std::string telefon); 
    void RegistrirajNovuKnjigu(int evidencijski, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja); 
    Korisnik &NadjiKorisnika (int clanski); 
    Knjiga &NadjiKnjigu (int evidencijski); 
    void IzlistajKorisnike() const; 
    void IzlistajKnjige() const; 
    void ZaduziKnjigu(int evidencijski, int clanski); 
    void RazduziKnjigu(int evidencijski); 
    void PrikaziZaduzenja(int clanski); 
}; 

void Biblioteka::PrikaziZaduzenja(int clanski) {
    bool ne_postoji=true; 
    for (auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        if (clanski==it->first) {
            ne_postoji=false; 
            break;
        }
    }
    if (ne_postoji==true) throw std::logic_error ("Korisnik nije nadjen"); 
    
    for (auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        for (auto it1=knjige.begin(); it1!=knjige.end(); it1++) {
            bool nema_zaduzenja=true; 
            if (it1->second->DajKodKogaJe()==it->second) {
                nema_zaduzenja=false; 
                std::cout << "Evidencijski broj: " << it1->first << std::endl; 
                std::cout << "Naslov: " << it1->second->DajNaslov() << std::endl; 
                std::cout << "Pisac: " << it1->second->DajAutora() << std::endl; 
                std::cout << "Zanr: " << it1->second->DajZanr() << std::endl; 
                std::cout << "Godina izdavanja: " << it1->second->DajGodinuIzdavanja() << std::endl; 
                
            }
            if (nema_zaduzenja==true) std::cout << "Nema zaduzenja za tog korisnika!"; 
        }
    }
}

void Biblioteka::RazduziKnjigu(int evidencijski) {
    
    bool ne_postoji=true; 
    for (auto it=knjige.begin(); it!=knjige.end(); it++) {
        if (it->second->DajKodKogaJe()==nullptr) throw std::logic_error ("Knjiga nije zaduzena");
        
        if (evidencijski==it->first) {
            ne_postoji=false; 
            break; 
        }
    }
    if (ne_postoji==true) throw std::logic_error ("Knjiga nije nadjena"); 
    
    else {
    for (auto it=knjige.begin(); it!=knjige.end(); it++) 
        if (evidencijski==it->first) it->second=nullptr;
    }
}

void Biblioteka::ZaduziKnjigu(int evidencijski, int clanski) {
    bool ne_postoji=true; 
    bool ne_postoji_korisnik=true; 
    
    for (auto it=knjige.begin(); it!=knjige.end(); it++) {
        if (evidencijski==it->first) {
            ne_postoji=false; 
            break; 
        }
    }
    if (ne_postoji==true) throw std::logic_error ("Knjiga nije nadjena");
    
    for (auto it1=korisnici.begin(); it1!=korisnici.end(); it1++) {
        if (clanski==it1->first) {
            ne_postoji_korisnik=false; 
            break; 
        }
    }
    if (ne_postoji_korisnik==true) throw std::logic_error ("Korisnik nije nadjen"); 
    
    bool zaduzena=true;
    for (auto it=knjige.begin(); it!=knjige.end(); it++) {
        if (it->second->DajKodKogaJe()==nullptr) {
            zaduzena=false; 
            break; 
        } 
    }
    if (zaduzena==true) throw std::logic_error ("Knjiga vec zaduzena"); 
    
     for (auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        if (clanski==it->first) {
            for (auto it1=knjige.begin(); it1!=knjige.end(); it1++) {
                if (evidencijski==it1->first)
                it->second=it1->second->DajKodKogaJe(); 
            }
        }
    }
}

void Biblioteka::IzlistajKnjige() const {
    for (auto it=knjige.begin(); it!=knjige.end(); it++) {
        
        std::cout << std::endl << "Evidencijski broj: " << it->first << std::endl; 
        std::cout << "Naslov: " << it->second->DajNaslov() << std::endl; 
        std::cout << "Pisac: " << it->second->DajAutora() << std::endl; 
        std::cout << "Zanr: " << it->second->DajZanr() << std::endl; 
        std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl; 
        
        if (it->second->DaLiJeZaduzena()==true) {
            std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime; 
        }
    }
}

void Biblioteka::IzlistajKorisnike() const {
    for (auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        
        std::cout << std::endl << "Clanski broj: " << it->first << std::endl; 
        std::cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl; 
        std::cout << "Adresa: " << it->second->adresa << std::endl; 
        std::cout << "Broj telefona: " << it->second->telefon << std::endl; 
    }
}

Knjiga &Biblioteka::NadjiKnjigu (int evidencijski) {
    
    auto it=knjige.find(evidencijski); 
    if (it==knjige.end()) throw std::logic_error ("Knjiga nije nadjena"); 
    else return *(it->second); 
}

Korisnik &Biblioteka::NadjiKorisnika (int clanski) {
    
    auto it=korisnici.find(clanski); 
    if (it==korisnici.end()) throw std::logic_error ("Korisnik nije nadjen"); 
    else return *(it->second);  
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) {
    bool postoji=false; 
    for (auto it=knjige.begin(); it!=knjige.end(); it++) {
     if (evidencijski==it->first) {
         postoji=true; 
         break; 
    }
    }
    if (postoji==true) throw std::logic_error ("Knjiga vec postoji"); 
    else {
         Knjiga *knjiga(new Knjiga(naslov, ime_pisca, zanr, godina_izdavanja)); 
         knjige.insert(std::make_pair(evidencijski, knjiga)); 
    }
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski, std::string ime, std::string prezime, std::string adresa, std::string telefon) { 
    bool postoji=false; 
    for (auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        if (clanski==it->first) {
            postoji=true; 
            break; 
       }
    }  
     
     if (postoji==true)  throw std::logic_error ("Korisnik vec postoji"); 
        else {
            Korisnik *korisnik=new Korisnik; 
            korisnik->ime=ime; korisnik->prezime=prezime; korisnik->adresa=adresa; korisnik->telefon=telefon; 
            korisnici.insert(std::make_pair(clanski, korisnik)); 
        }
}

int main ()
{
    Biblioteka b; 
    
    for (;;) {
        int n; 
        std::cout << std::endl << "Izaberite opciju: ";
        std::cout << std::endl << "1-za izlaz" << std::endl << "2-za registraciju korisnika" << std::endl << "3-za registraciju knjige" <<
        std::endl << "4-za nalazenje korisnika" << std::endl << "5-za nalazenje knjige" << std::endl << "6-za ispis korisnika" << std::endl
        << "7-za ispis knjiga" << std::endl << "8-za zaduzivanje knjige" << std::endl << "9-za razduzivanje knjige" << std::endl 
        << "10-za prikaz zaduzenja" << std::endl; 
        
        std::cin >> n; 
        
        if (n==1) break; 
        
        try {
        
        if (n==2) {
            std::cout << "Unesite clanski broj: " << std::endl; 
            int clanski; 
            std::cin >> clanski; 
            
            std::cin.clear(); 
            std::cin.ignore(1000, '\n'); 
            
            std::string ime, prezime, adresa, telefon; 
            std::cout << "Unesite ime, prezime, adresu i broj telefona: " << std::endl; 
            std::getline(std::cin, ime); std::getline(std::cin, prezime); 
            std::getline(std::cin, adresa); std::getline(std::cin, telefon); 
            
            b.RegistrirajNovogKorisnika(clanski, ime, prezime, adresa, telefon);
        }
        
        if (n==3) {
            std::cout << "Unesite evidencijski broj: " << std::endl; 
            int ev; 
            std::cin >> ev; 
            
            std::cin.clear(); 
            std::cin.ignore(1000,'\n');
            
            std::string naslov, ime_pisca, zanr; 
            std::cout << "Unesite naslov, ime pisca i zanr: " << std::endl;  
            std::getline(std::cin, naslov); 
            std::getline(std::cin, ime_pisca); 
            std::getline(std::cin, zanr); 
            
            int godina_izdavanja; 
            std::cout << "Unesite godinu izdavanja: " << std::endl; 
            std::cin >> godina_izdavanja; 
            
            b.RegistrirajNovuKnjigu(ev, naslov, ime_pisca, zanr, godina_izdavanja); 
        }
        
        if (n==4) {
            int clanski; 
            std::cout << "Unesite clanski broj korisnika: " << std::endl; 
            std::cin >> clanski; 
            
            b.NadjiKorisnika(clanski); 
        }
        
        if (n==5) {
            int evidencijski; 
            std::cout << "Unesite evidencijski broj knjige: " << std::endl; 
            std::cin >> evidencijski; 
            
            b.NadjiKnjigu(evidencijski); 
        }
        
        if (n==6) {
            b.IzlistajKorisnike(); 
        }
        
        if (n==7) {
            b.IzlistajKnjige(); 
        }
        
        if (n==8) {
            int ev, cl; 
            std::cout << "Unesite evidencijski broj knjige te clanski broj korisnika: " << std::endl; 
            std::cin >> ev >> cl; 
            
            b.ZaduziKnjigu(ev,cl); 
        }
        
        if (n==9) {
            int ev; 
            std::cout << "Unesite evidencijski broj knjige: " << std::endl; 
            std::cin >> ev; 
            
            b.RazduziKnjigu(ev); 
        }
        
        if (n==10) {
            int cl; 
            std::cout << "Unesite clanski broj korisnika: " << std::endl; 
            std::cin >> cl; 
            
            b.PrikaziZaduzenja(cl); 
        }
    }
        catch (std::logic_error e) {
            std::cout << e.what() << std::endl; 
        }
    }
    
	return 0;
}