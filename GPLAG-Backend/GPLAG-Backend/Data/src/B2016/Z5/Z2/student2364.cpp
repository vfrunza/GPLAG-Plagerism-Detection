#include <iostream>
#include <string>
#include <map>
#include <initializer_list>
#include <stdexcept>
#include <memory>

struct Korisnik {
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};

class Knjiga {
    std::string naslov;
    std::string autor;
    std::string zanr;
    int godina_izdavanja;
    Korisnik *kod_koga_je;
public:
    Knjiga(std::string naslov, std::string autor, std::string zanr, int godina_izdavanja);
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return autor; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik *DajKodKogaJe() const { return kod_koga_je; }
    void ZaduziKnjigu(Korisnik &k){ kod_koga_je = &k; }
    void RazduziKnjigu(){ kod_koga_je = nullptr; }
    bool DaLiJeZaduzena(){ if(kod_koga_je)return true; else return false; }
};

Knjiga::Knjiga(std::string naslov, std::string autor, std::string zanr, int godina_izdavanja) : naslov(naslov),
    autor(autor), zanr(zanr), godina_izdavanja(godina_izdavanja), kod_koga_je(nullptr) {}

class Biblioteka {
    std::map<int ,std::shared_ptr<Korisnik>> korisnici;
    std::map<int, std::shared_ptr<Knjiga>> knjige;
public:
    Biblioteka(){}
    ~Biblioteka(){}
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu(int ev_broj, std::string naslov, std::string autor, std::string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int clanski_broj) const ;
    Knjiga &NadjiKnjigu(int ev_broj)const ;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int ev_broj, int clanski_broj);
    void RazduziKnjigu(int ev_broj);
    void PrikaziZaduzenja(int clanski_broj)const;
};

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string Ime, std::string Prezime, std::string Adresa, std::string Telefon){
    std::shared_ptr<Korisnik> p(std::make_shared<Korisnik>());
    auto it(korisnici.find(clanski_broj));
    if(it != korisnici.end()) throw std::logic_error("Korisnik vec postoji");
    else{
        p->ime = Ime;
        p->prezime = Prezime;
        p->adresa = Adresa;
        p->telefon = Telefon;
        korisnici[clanski_broj] = p;
    }
}
void Biblioteka::RegistrirajNovuKnjigu(int ev_broj, std::string naslov, std::string autor, std::string zanr, int godina_izdavanja){
    std::shared_ptr<Knjiga> p(std::make_shared<Knjiga>(naslov, autor, zanr, godina_izdavanja));
    auto it(knjige.find(ev_broj));
    if(it != knjige.end()) throw std::logic_error("Knjiga vec postoji"); 
    else knjige[ev_broj] = p; 
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) const {
    auto it(korisnici.find(clanski_broj));
    if(it == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    else return *it->second;
}
Knjiga &Biblioteka::NadjiKnjigu(int ev_broj) const {
    auto it(knjige.find(ev_broj));
    if(it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    else return *it->second;
}
void Biblioteka::IzlistajKorisnike() const{
    for(auto i(korisnici.begin()); i != korisnici.end(); i++){
        std::cout << "Clanski broj: " << i->first << std::endl;
        std::cout << "Ime i prezime: " << i->second->ime << " " << i->second->prezime << std::endl;
        std::cout << "Adresa: " << i->second->adresa << std::endl;
        std::cout << "Broj telefona: " << i->second->telefon << std::endl;
        std::cout << std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const{
    for(auto i(knjige.begin()); i != knjige.end(); i++){
        std::cout << "Evidencijski broj: " << i->first << std::endl;
        std::cout << "Naslov: " << i->second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << i->second->DajAutora() << std::endl;
        std::cout << "Zanr: " << i->second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << i->second->DajGodinuIzdavanja() << std::endl;
        if((i->second->DajKodKogaJe()) != nullptr)
            std::cout << "Zaduzena kod korisnika: " << i->second->DajKodKogaJe()->ime << " " << i->second->DajKodKogaJe()->prezime << std::endl;
        std::cout << std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int ev_broj, int clanski_broj){
    auto knjiga(NadjiKnjigu(ev_broj));
    auto korisnik(NadjiKorisnika(clanski_broj));
    if(NadjiKnjigu(ev_broj).DaLiJeZaduzena()) throw std::logic_error("Knjiga je zaduzena");
    else
    NadjiKnjigu(ev_broj).ZaduziKnjigu(NadjiKorisnika(clanski_broj));
}
void Biblioteka::RazduziKnjigu(int ev_broj){
    auto knjiga(NadjiKnjigu(ev_broj));
    if(!(NadjiKnjigu(ev_broj).DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
    else NadjiKnjigu(ev_broj).RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clanski_broj) const{
    if(korisnici.find(clanski_broj) == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    int brojac{};
    for(auto i(knjige.begin()); i != knjige.end(); i++)
        if(i->second->DajKodKogaJe() == korisnici.find(clanski_broj)->second.get()){
            ++brojac;
            std::cout << "Evidencijski broj: " << i->first << std::endl;
            std::cout << "Naslov: " << i->second->DajNaslov()<< std::endl;
            std::cout << "Pisac: " << i->second->DajAutora() << std::endl;
            std::cout << "Zanr: " << i->second->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << i->second->DajGodinuIzdavanja() << std::endl;
        }
    if(brojac == 0) std::cout << "Nema zaduzenja za tog korisnika!";
    }
int main(){
    Biblioteka bib8;
    try{
    std::cout << "Dobro dosli u nasu biblioteku!\n";
    for(;;){
        std::cout << "\nUnesite broj (1 - 8) da bi odabrali neku od opcija koju vam nudi biblioteka:\n";
        std::cout << "1 - registracija novog korisnika.\n";
        std::cout << "2 - registracija nove knjige.\n";
        std::cout << "3 - prikaz korisnika biblioteke.\n";
        std::cout << "4 - prikaz svih knjiga.\n";
        std::cout << "5 - zaduzi knjigu.\n";
        std::cout << "6 - razduzi knjigu.\n";
        std::cout << "7 - prikaz zaduzenja korisnika.\n";
        std::cout << "8 - za izlaz.\n";
        int broj;
        std::cin >> broj;
        while(broj < 1 || broj > 8){ std::cout << "Pogresna opcija, molimo unesite ponovo! "; std::cin >> broj; }
        
        if(broj == 1){
            std::cout << "Registracija novog korisnika!\n";
            std::cout << "Unesite clanski broj koji bi zeljeli imati: ";
            int clanski_broj; std::cin >> clanski_broj;
            std::cout << "Unesite ime: ";
            std::cin.ignore(1000, '\n');
            std::string ime; std::getline(std::cin, ime);
            std::cout << "Unesite prezime: ";
            std::string prezime; std::getline(std::cin, prezime);
            std::cout << "Unesite adresu korisnika: ";
            std::string adresa; std::getline(std::cin, adresa);
            std::cout << "Unesite telefonski broj: ";
            std::string telefon; std::getline(std::cin, telefon);
            try{
                bib8.RegistrirajNovogKorisnika(clanski_broj, ime, prezime, adresa, telefon);
                std::cout << "Uspjesna registracija!\n";
            }catch(std::logic_error iz){
                std::cout << iz.what() << std::endl;
            }
        }
        else if(broj == 2){
            std::cout << "Registracija nove knjige!\n";
            std::cout << "Unesite evidencijski broj knjige: ";
            int ev_broj; std::cin >> ev_broj;
            std::cout << "Unesite naslov knjige: ";
            std::cin.ignore(1000, '\n');
            std::string naslov; std::getline(std::cin, naslov);
            std::cout << "Unesite autora knjige: ";
            std::string autor; std::getline(std::cin, autor);
            std::cout << "Unesite zanr: ";
            std::string zanr; std::getline(std::cin, zanr);
            std::cout << "Unesite godina izdavanja: ";
            int godina_izdavanja; std::cin >> godina_izdavanja; std::cin.ignore(1000, '\n');
            try{
                bib8.RegistrirajNovuKnjigu(ev_broj, naslov, autor, zanr, godina_izdavanja);
                std::cout << "Uspjesna registracija!\n";
            }catch(std::logic_error iz){
                std::cout << iz.what() << std::endl;
            }
        }
        else if(broj == 3){
            std::cout << "Spisak korisnika biblioteke:\n\n";
            bib8.IzlistajKorisnike();
        }
        else if(broj == 4){
            std::cout << "Spisak svih knjiga biblioteke:\n\n";
            bib8.IzlistajKnjige();
        }
        else if(broj == 5){
            std::cout << "Unesite evidencijski broj knjige koju zelite zaduziti, te clanski broj korisnika: ";
            int ev_broj, clanski_broj;
            std::cin >> ev_broj >> clanski_broj;
            try{
            bib8.ZaduziKnjigu(ev_broj, clanski_broj);
            std::cout << "Uspjesno ste zaduzili knjigu!\n";
            }catch(std::logic_error iz){
                std::cout << iz.what() << std::endl;
            }
        }
        else if(broj == 6){
                std::cout << "Unesite evidencijski broj knjige koju zelite razduziti: ";
                int ev_broj; std::cin >> ev_broj;
                try{
                    bib8.RazduziKnjigu(ev_broj);
                    std::cout << "Uspjesno ste razduzili knjigu!\n";
                }catch(std::logic_error iz){
                    std::cout << iz.what() << std::endl;
                }
        }
        else if(broj == 7){
            std::cout << "Unesite clanski broj korisnika za kojeg zelite da se prikazu zaduzenja: ";
            int clanski_broj; std::cin >> clanski_broj;
            try{
                bib8.PrikaziZaduzenja(clanski_broj);
            }catch(std::logic_error iz){
                std::cout << iz.what() << std::endl;
            }
        }
        else if(broj == 8){
            std::cout << "\n\nHvala vam sto ste nas posjetili, dovidjenja :)";
            break;
        }
    
    }
    }catch(std::logic_error iz){
        std::cout << iz.what();
    }
    return 0;
}