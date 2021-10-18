/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga{
    std::string naslov_knjige, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* kod_koga_je;
public:
    Knjiga(std::string naslov_knjige, std::string ime_pisca, std::string zanr, int godina_izdavanja){
        Knjiga::naslov_knjige = naslov_knjige; Knjiga::ime_pisca = ime_pisca;
        Knjiga::zanr = zanr; Knjiga::godina_izdavanja = godina_izdavanja;                               // konstruktor sa 4 parametra
        kod_koga_je = nullptr;
    }
    ~Knjiga(){ delete kod_koga_je; kod_koga_je = nullptr; }
    
    std::string DajNaslov() const{ return naslov_knjige; }
    std::string DajAutora() const{ return ime_pisca; }
    std::string DajZanr() const{ return zanr; }
    int DajGodinuIzdavanja() const{ return godina_izdavanja; }
    Korisnik* DajKodKogaJe() const{ return kod_koga_je; }
    
    void ZaduziKnjigu(Korisnik &k){ kod_koga_je = new Korisnik(k); }
    void RazduziKnjigu(){ delete kod_koga_je; kod_koga_je = nullptr; }
    bool DaLiJeZaduzena() const{ return kod_koga_je != nullptr; }
    
};

class Biblioteka{
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;                              // u obje mape -> first oznacava identifikacioni broj knjige/korisnika
public:
    Biblioteka()=default;
    Biblioteka(const Biblioteka &b){
        for(auto it = b.korisnici.begin(); it != b.korisnici.end(); it++){
            korisnici.insert(std::make_pair(it -> first, new Korisnik(*(it -> second))));
        }                                                                                           // konstruktor bez parametara i kopirajuci konstruktor
        for(auto it = b.knjige.begin(); it != b.knjige.end(); it++){
            knjige.insert(std::make_pair(it -> first, new Knjiga(*(it -> second))));
        }
    }
    ~Biblioteka(){
        for(auto it = korisnici.begin(); it != korisnici.end(); it++) delete it -> second;
        for(auto it = knjige.begin(); it != knjige.end(); it++) delete it -> second;
    }
    Biblioteka &operator =(const Biblioteka &b);            // kopirajuci operator dodjele
    
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona);
    void RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov_knjige, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int clanski_broj) const;
    Knjiga &NadjiKnjigu(int evidencijski_broj) const;
    void ZaduziKnjigu(int ev_broj, int cl_broj);
    void RazduziKnjigu(int ev_broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void PrikaziZaduzenja(int cl_broj) const;
};

Biblioteka &Biblioteka::operator =(const Biblioteka &b){
    std::map<int, Korisnik*> p_korisnici;
    std::map<int, Knjiga*> p_knjige;
    
    for(auto it = b.korisnici.begin(); it != b.korisnici.end(); it++){
        p_korisnici.insert(std::make_pair(it -> first, new Korisnik(*(it -> second))));
    }                                                                                           
    for(auto it = b.knjige.begin(); it != b.knjige.end(); it++){
        p_knjige.insert(std::make_pair(it -> first, new Knjiga(*(it -> second))));
    }
    
    for(auto it = korisnici.begin(); it != korisnici.end(); it++) delete it -> second;          // prvo dealociraj stare
    for(auto it = knjige.begin(); it != knjige.end(); it++) delete it -> second;   
    korisnici = p_korisnici; knjige = p_knjige;
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona){
    auto it(korisnici.find(clanski_broj));
    if(it != korisnici.end()) throw std::logic_error ("Korisnik vec postoji");
    auto pok(new Korisnik{ime, prezime, adresa, broj_telefona});
    korisnici.insert(std::make_pair(clanski_broj, pok));
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov_knjige, std::string ime_pisca, std::string zanr, int godina_izdavanja){
    auto it(knjige.find(evidencijski_broj));
    if(it != knjige.end()) throw std::logic_error ("Knjiga vec postoji");
    auto pok(new Knjiga(naslov_knjige, ime_pisca, zanr, godina_izdavanja));
    knjige.insert(std::make_pair(evidencijski_broj, pok));
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) const{
    auto it(korisnici.find(clanski_broj));
    if(it == korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
    return *(it -> second);
}

Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj) const{
    auto it(knjige.find(evidencijski_broj));
    if(it == knjige.end()) throw std::logic_error ("Knjiga vec postoji");
    return *(it -> second);
}

void Biblioteka::IzlistajKorisnike() const{
    for(auto it = korisnici.begin(); it != korisnici.end(); it++){
        std::cout << "Clanski broj: " << it -> first << std::endl <<
        "Ime i prezime: " << (it -> second) -> ime << " " << (it -> second) -> prezime << std::endl <<
        "Adresa: " << (it -> second) -> adresa << std::endl << "Broj telefona: " <<
        (it -> second) -> telefon << std::endl << std::endl;
    }
}

void Biblioteka::PrikaziZaduzenja(int cl_broj) const{
    auto it(korisnici.find(cl_broj));
    if(it == korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
    bool nasao_bar_jednu(false);
    
    for(auto knjige_it = knjige.begin(); knjige_it != knjige.end(); knjige_it++){
        auto lik((knjige_it -> second) -> DajKodKogaJe());
        if(lik != nullptr and lik -> ime == (it -> second) -> ime){
            nasao_bar_jednu = true;
            std::cout << "Evidencijski broj: " << knjige_it -> first << std::endl <<
            "Naslov: " << (knjige_it -> second) -> DajNaslov() <<  std::endl <<
            "Pisac: " << (knjige_it -> second) -> DajAutora() << std::endl << "Zanr: " <<
            (knjige_it -> second) -> DajZanr() << std::endl << "Godina izdavanja: " << 
            (knjige_it -> second) -> DajGodinuIzdavanja() << std::endl << std::endl; 
        }
    }
    if(!nasao_bar_jednu) std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
    
}

void Biblioteka::ZaduziKnjigu(int ev_broj, int cl_broj){
    auto knjige_it(knjige.find(ev_broj));
    if(knjige_it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    auto korisnici_it(korisnici.find(cl_broj));
    if(korisnici_it == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    if((knjige_it -> second) -> DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zauzeta");
    
    (knjige_it -> second) -> ZaduziKnjigu(*(korisnici_it -> second));
}

void Biblioteka::RazduziKnjigu(int ev_broj){
    auto knjige_it(knjige.find(ev_broj));
    if(knjige_it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    if(!(knjige_it -> second) -> DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
    
    (knjige_it -> second) -> RazduziKnjigu();
}

void Biblioteka::IzlistajKnjige() const{
    for(auto it = knjige.begin(); it != knjige.end(); it++){
        std::cout << "Evidencijski broj: " << it -> first << std::endl <<
        "Naslov: " << (it -> second) -> DajNaslov() << std::endl <<
        "Pisac: " << (it -> second) -> DajAutora() << std::endl <<
        "Zanr: " << (it -> second) -> DajZanr() << std::endl <<
        "Godina izdavanja: " << (it -> second) -> DajGodinuIzdavanja() << std::endl;
        auto p_it((it -> second) -> DajKodKogaJe());
        if(p_it != nullptr){
            std::cout << "Zaduzena kod korisnika: " << p_it -> ime << " " << p_it -> prezime << std::endl << std::endl;
        }
        else std::cout << std::endl;
    }
}

int main ()
{
    Biblioteka b;
    
    std::cout << "Dobrodosli!" << std::endl;
    int generator_clanskih(1), generator_evidencijskih(1);
    
    for(;;){
        std::cout << std::endl << "Odaberite opciju: " << std::endl << "1) Azuriranje korisnika " << std::endl << "2) Azuriranje knjiga" << std::endl << "3) Izlaz" << std::endl;
        int opcija(0); 
        std::cin >> opcija;
        if(opcija == 1){
            std::cout << std::endl << "Izabrali ste opciju 'Azuriranje korisnika'" << std::endl;
            std::cout << "Odaberite opciju za rad sa korisnicima: " << std::endl << "1) Unos novog korisnika" << std::endl << "2) Spisak svih korisnika" << std::endl << "3) Sva zaduzenja odredjenog korisnika" << std::endl;
            int korisnicka_opcija(0);
            std::cin >> korisnicka_opcija;
            if(korisnicka_opcija == 1){
                std::cin.ignore(1000,'\n');
                std::string ime, prezime, adresa, broj_telefona;
                std::cout << std::endl << "Unesite podatke: " << std::endl;
                std::cout << "Ime: "; std::getline(std::cin, ime);
                std::cout << "Prezime: "; std::getline(std::cin, prezime);
                std::cout << "Adresa: "; std::getline(std::cin, adresa);
                std::cout << "Broj telefona: "; std::getline(std::cin, broj_telefona); 
                try{
                    b.RegistrirajNovogKorisnika(generator_clanskih, ime, prezime, adresa, broj_telefona);
                    generator_clanskih++;
                }
                catch(std::logic_error l){
                    std::cout << l.what() << std::endl;
                }
            }
            if(korisnicka_opcija == 2){
                std::cout << std::endl;
                b.IzlistajKorisnike();
            }
            if(korisnicka_opcija == 3){
                std::cout << std::endl << "Unesite clanski broj korisnika: ";
                int cb(0); 
                std::cin >> cb;
                try{
                    b.PrikaziZaduzenja(cb);
                }
                catch(std::logic_error l){
                    std::cout << l.what() << std::endl;
                }
            }
        }
        if(opcija == 2){
            std::cout << std::endl << "Odabrali ste opciju: 'Azuriranje knjiga' " << std::endl;
            std::cout << "Odaberite opciju za rad sa knjigama:" << std::endl << "1) Registriranje nove knjige" << std::endl
            << "2) Spisak svih knjiga" << std::endl << "3) Zaduzivanje knjige" << std::endl << "4) Razduzivanje knjige" << std::endl;
            
            int korisnicka_opcija(0);
            std::cin >> korisnicka_opcija;
            if(korisnicka_opcija == 1){
                std::cin.ignore(1000,'\n');
                int godina_izdavanja(0);
                std::string naslov_knjige, ime_pisca, zanr;
                std::cout << std::endl << "Unesite podatke za novu knjigu: " << std::endl;
                std::cout << "Naslov knjige: "; std::getline(std::cin, naslov_knjige);
                std::cout << "Ime pisca: "; std::getline(std::cin, ime_pisca);
                std::cout << "Zanr: "; std::getline(std::cin, zanr);
                std::cout << "Godina izdavanja: "; std::cin >> godina_izdavanja;
                std::cin.ignore(1000, '\n');
                try{
                    b.RegistrirajNovuKnjigu(generator_evidencijskih, naslov_knjige, ime_pisca, zanr, godina_izdavanja);
                    generator_evidencijskih++;
                }
                catch(std::logic_error l){
                    std::cout << l.what() << std::endl;
                }
            }
            if(korisnicka_opcija == 2){
                std::cout << std::endl;
                b.IzlistajKnjige();
            }
            if(korisnicka_opcija == 3){
                int cb(0), eb(0);
                std::cout << "Unesite evidencijski broj: ";
                std::cin >> eb;
                std::cout << "Unesite clanski broj: ";
                std::cin >> cb;
                try{
                    b.ZaduziKnjigu(eb, cb);
                }
                catch(std::logic_error l){
                    std::cout << l.what() << std::endl;
                }
            }
            if(korisnicka_opcija == 4){
                int eb(0);
                std::cout << "Unesite evidencijski broj: ";
                std::cin >> eb;
                try{
                    b.RazduziKnjigu(eb);
                }
                catch(std::logic_error l){
                    std::cout << l.what() << std::endl;
                }
            }
        }
        if(opcija == 3){
            std::cout << std::endl << "Dovidjenja!" << std::endl;
            break;
        }
    }
	return 0;
}
