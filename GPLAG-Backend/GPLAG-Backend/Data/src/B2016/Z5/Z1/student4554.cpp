#include <iostream>
#include <stdexcept>
#include <string>
#include <map>

using namespace std;

struct Korisnik {
    string ime, prezime, adresa, telefon; 
};

class Knjiga {
    string naslov_knjige, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *zaduzenik;
public:
    Knjiga(string naslov_knjige,string ime_pisca,string zanr, int godina_izdavanja) :
        naslov_knjige(naslov_knjige), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), zaduzenik(nullptr) {}
    string DajNaslov() const { return naslov_knjige; }
    string DajAutora() const { return ime_pisca; }
    string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik* DajKodKogaJe() const { return zaduzenik; }
    void ZaduziKnjigu(Korisnik &korisnik) { zaduzenik = &korisnik; }
    void RazduziKnjigu() { zaduzenik = nullptr; } 
    bool DaLiJeZaduzena() const { return zaduzenik; }
    
};

class Biblioteka {
    map<int, Korisnik* > mapa_korisnika;
    map<int, Knjiga* > mapa_knjiga;
public:
    ~Biblioteka();
    Biblioteka() = default;
    Biblioteka(const Biblioteka &bib);
    Biblioteka(Biblioteka &&bib);
    Biblioteka &operator =(const Biblioteka &bib);
    Biblioteka &operator =(Biblioteka &&bib);
    void RegistrirajNovogKorisnika(int cl_broj, string ime, string prezime, string adresa, string telefon);
    void RegistrirajNovuKnjigu(int ev_broj, string naslov, string ime_pisca, string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika (int cl_broj) const;
    Knjiga &NadjiKnjigu (int ev_broj) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int ev_broj, int cl_broj);
    void RazduziKnjigu(int ev_broj);
    void PrikaziZaduzenja(int cl_broj) const;
};

Biblioteka::~Biblioteka() {
    for(auto it = mapa_korisnika.begin(); it != mapa_korisnika.end(); it++) {
        delete it->second;           
    }
    for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
        delete it->second;           
    }
}

Biblioteka::Biblioteka(const Biblioteka &bib) {
    try {
        for(auto it = bib.mapa_korisnika.begin(); it != bib.mapa_korisnika.end(); it++) 
            RegistrirajNovogKorisnika(it->first, it->second->ime, it->second->prezime, it->second->adresa, it->second->telefon);
        
        for(auto it = bib.mapa_knjiga.begin(); it != bib.mapa_knjiga.end(); it++)
            RegistrirajNovuKnjigu(it->first, it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja());
    }
    catch (std::bad_alloc) {
        throw;
    }
}

Biblioteka::Biblioteka(Biblioteka &&bib) {
    try {
        for(auto it = bib.mapa_korisnika.begin(); it != bib.mapa_korisnika.end(); it++) {
            mapa_korisnika.insert(std::make_pair(it->first, it->second));
            it->second = nullptr;
        }    
        
        for(auto it = bib.mapa_knjiga.begin(); it != bib.mapa_knjiga.end(); it++){
            mapa_knjiga.insert(std::make_pair(it->first, it->second));
            it->second = nullptr;
        }
    }
    catch (std::bad_alloc) {
        throw;
    }
}

Biblioteka &Biblioteka::operator =(const Biblioteka &bib) {
    
    Biblioteka pom;
    
    try {
        for(auto it = bib.mapa_korisnika.begin(); it != bib.mapa_korisnika.end(); it++) 
            pom.RegistrirajNovogKorisnika(it->first, it->second->ime, it->second->prezime, it->second->adresa, it->second->telefon);
        
        for(auto it = bib.mapa_knjiga.begin(); it != bib.mapa_knjiga.end(); it++)
            pom.RegistrirajNovuKnjigu(it->first, it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja());
        
        for(auto it = mapa_korisnika.begin(); it != mapa_korisnika.end(); it++) 
            delete it->second;
            
        for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) 
            delete it->second;
            
        for(auto it = pom.mapa_korisnika.begin(); it != pom.mapa_korisnika.end(); it++) 
            RegistrirajNovogKorisnika(it->first, it->second->ime, it->second->prezime, it->second->adresa, it->second->telefon);
        
        for(auto it = pom.mapa_knjiga.begin(); it != pom.mapa_knjiga.end(); it++)
            RegistrirajNovuKnjigu(it->first, it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja());
    }
    catch (std::bad_alloc) {
        throw;
    }
    return *this;
}

Biblioteka &Biblioteka::operator =(Biblioteka &&bib) {
    try {
        for(auto it = bib.mapa_korisnika.begin(); it != bib.mapa_korisnika.end(); it++) {
            mapa_korisnika.insert(std::make_pair(it->first, it->second));
            it->second = nullptr;
        }    
        
        for(auto it = bib.mapa_knjiga.begin(); it != bib.mapa_knjiga.end(); it++){
            mapa_knjiga.insert(std::make_pair(it->first, it->second));
            it->second = nullptr;
        }
    }
    catch (std::bad_alloc) {
        throw;
    }
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int cl_broj, string ime,
    string prezime, string adresa, string telefon) {
        
    if(mapa_korisnika.count(cl_broj))
        throw std::logic_error("Korisnik vec postoji");
    
    
    Korisnik *pok_na_korisnika;
    
    try {
        pok_na_korisnika = new Korisnik;
    }
    catch (std::bad_alloc) {
        throw;
    }
                                                  
    pok_na_korisnika->ime = ime;
    pok_na_korisnika->prezime = prezime;
    pok_na_korisnika->adresa = adresa;
    pok_na_korisnika->telefon = telefon;
    
    mapa_korisnika.insert(std::make_pair(cl_broj, pok_na_korisnika));    
}

void Biblioteka::RegistrirajNovuKnjigu(int ev_broj, string naslov_knjige, 
    string ime_pisca, string zanr, int godina_izdavanja) {
    
    if(mapa_knjiga.count(ev_broj))
        throw std::logic_error("Knjiga vec postoji");
        
    Knjiga *pok_na_knjigu;   
    
    try {
        pok_na_knjigu = new Knjiga(naslov_knjige, ime_pisca, zanr, godina_izdavanja);
    }
    catch (std::bad_alloc) {
        throw;
    }
    
    mapa_knjiga.insert(make_pair(ev_broj, pok_na_knjigu));
}

Korisnik &Biblioteka::NadjiKorisnika (int cl_broj) const {
    
    auto it = mapa_korisnika.find(cl_broj);
    
    if(it == mapa_korisnika.end())
        throw std::logic_error("Korisnik nije nadjen");
        
    return *it->second;    
}

Knjiga &Biblioteka::NadjiKnjigu (int ev_broj) const {
    
    auto it = mapa_knjiga.find(ev_broj);
    
    if (it == mapa_knjiga.end())
        throw logic_error("Knjiga nije nadjena");
        
    return *it->second;    
}

void Biblioteka::IzlistajKorisnike() const {
    
    for (auto it = mapa_korisnika.begin(); it != mapa_korisnika.end(); it++) {
        cout << "Clanski broj: " << it->first << endl 
            << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << endl
            << "Adresa: " << it->second->adresa << endl 
            << "Broj telefona: " << it->second->telefon << endl << endl;
    }
}

void Biblioteka::IzlistajKnjige() const {
    
    for (auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
        cout << "Evidencijski broj: " << it->first << endl
            << "Naslov: " << it->second->DajNaslov() << endl
            << "Pisac: " << it->second->DajAutora() << endl
            << "Zanr: " << it->second->DajZanr() << endl
            << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << endl;
            
        if(it->second->DaLiJeZaduzena())
            cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime
                << " " << it->second->DajKodKogaJe()->prezime << endl;
        
        cout << endl;        
    }
}

void Biblioteka::ZaduziKnjigu(int ev_broj, int cl_broj) {
    NadjiKnjigu(ev_broj);               
    NadjiKorisnika(cl_broj);
    
    if(NadjiKnjigu(ev_broj).DaLiJeZaduzena())
        throw logic_error("Knjiga je vec zaduzena");
        
    NadjiKnjigu(ev_broj).ZaduziKnjigu(NadjiKorisnika(cl_broj));        
}

void Biblioteka::RazduziKnjigu(int ev_broj) {
    if(!NadjiKnjigu(ev_broj).DaLiJeZaduzena())
        throw logic_error("Knjiga nije zaduzena");
        
    NadjiKnjigu(ev_broj).RazduziKnjigu();    
}

void Biblioteka::PrikaziZaduzenja(int cl_broj) const {
    Korisnik k(NadjiKorisnika(cl_broj));
    
    for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
        if (it->second->DajKodKogaJe()->ime == k.ime && it->second->DajKodKogaJe()->prezime == k.prezime 
            && it->second->DajKodKogaJe()->adresa == k.adresa && it->second->DajKodKogaJe()->telefon == k.telefon) {
                
            cout << "Evidencijski broj: " << it->first << endl
            << "Naslov: " << it->second->DajNaslov() << endl
            << "Pisac: " << it->second->DajAutora() << endl
            << "Zanr: " << it->second->DajZanr() << endl
            << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << endl;
            cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime
                << " " << it->second->DajKodKogaJe()->prezime << endl;
        }
    }
}

int main ()
{
    Biblioteka bib;
    cout << endl << endl;
    cout << "WILLKOMMEN!" << endl;
    cout << "Vasa biblioteka se sove bib :D " << endl << endl;
    
    int opcija;
    
    for(;;) {
        try {
            
            cout << endl 
                << "Izaberite opciju: " << endl
                << "1: RegistrirajNovogKorisnika" << endl
                << "2: RegistrirajNovuKnjigu" << endl
                << "3: ZaduziKnjigu" << endl
                << "4: RazduziKnjigu" << endl
                << "5: PrikaziZaduzenja" << endl
                << "6: IzlistajKorisnike" << endl
                << "7: IzlistajKnjige" << endl
                << "0: IZLAZ!" << endl << endl;
            
            cin >> opcija;
            
            switch(opcija) {
                case 0:
                    return 0;
                case 1: {
                    int cl_broj;
                    string ime, prezime, adresa, telefon;
                    
                    cout << "Unesite clanski broj: " << endl;
                    cin >> cl_broj;
                    
                    cin.ignore(100,'\n');
                    
                    cout << "Unesite ime korisnika: " << endl;
                    std::getline(std::cin, ime);
                    
                    cout << "Unesite prezime korisnika: " << endl;
                    std::getline(std::cin, prezime);
                    
                    cout << "Unesite adresu: " << endl;
                    std::getline(std::cin, adresa);
                    
                    cout << "Unesite telefon: " << endl;
                    std::getline(std::cin, telefon);
                    
                    bib.RegistrirajNovogKorisnika(cl_broj, ime, prezime, adresa, telefon);
                    
                    break;
                }
                case 2: {
                    int ev_broj, godina_izdavanja;
                    string naslov, ime_pisca, zanr;
                    
                    cout << "Unesite evidencijski broj: " << endl;
                    cin >> ev_broj;
                    cin.ignore(100, '\n');
                    
                    cout << "Unesite naslov knjige: " << endl;
                    std::getline(std::cin, naslov);
                    
                    cout << "Unesite ime pisca: " << endl;
                    std::getline(std::cin, ime_pisca);
                    
                    cout << "Unesite zanr: " << endl;
                    std::getline(std::cin, zanr);
                    
                    cout << "Unesite godina izdavanja" << endl;
                    cin >> godina_izdavanja;
                    cin.ignore(100,'\n');
                    
                    bib.RegistrirajNovuKnjigu(ev_broj, naslov, ime_pisca, zanr, godina_izdavanja);
                
                    break;
                }
                case 3: {
                    int ev_broj, cl_broj;
                    
                    cout << "Unesite evidencijski broj knjige: " << endl;
                    cin >> ev_broj;
                    cout << "Unesite clanski broj korisnika: " << endl;
                    cin >> cl_broj;
                    cin.ignore(100,'\n');
                    
                    bib.ZaduziKnjigu(ev_broj, cl_broj);
                    
                    break;
                }
                case 4: {
                    int ev_broj;
                    
                    cout << "Unesite evidencijski broj knjige: " << endl;
                    cin >> ev_broj;
                    cin.ignore(100,'\n');
                    
                    bib.RazduziKnjigu(ev_broj);
                    
                    break;
                }
                case 5: {
                    int cl_broj;
                    
                    cout << "Unesite clanski broj korisnika: " << endl;
                    cin >> cl_broj;
                    cin.ignore(100,'\n');
                    
                    bib.PrikaziZaduzenja(cl_broj);
                    
                    break;
                }
                case 6: {
                    bib.IzlistajKorisnike();
                    break;
                }
                case 7: {
                    bib.IzlistajKnjige();
                    break;
                }
                
            }
        } catch (...) {}    
    }
        
    return 0;
}
