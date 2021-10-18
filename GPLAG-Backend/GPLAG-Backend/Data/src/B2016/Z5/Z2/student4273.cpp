/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <utility>
#include <memory>

using std::cin; using std::cout; using std::endl;

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *info_o_zaduzenju; //Pok na korisnika koji je zaduzio knjigu
    public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), info_o_zaduzenju(nullptr) {}
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik* DajKodKogaJe() const { return info_o_zaduzenju; }
    void ZaduziKnjigu(Korisnik &ref_na_korisnika);
    void RazduziKnjigu() { info_o_zaduzenju=nullptr; } //Da li ce trebati dealokacija
    bool DaLiJeZaduzena() { 
        if (!info_o_zaduzenju) return false; //Ako je nullptr
        return true;
    }
};

void Knjiga::ZaduziKnjigu(Korisnik &ref_na_korisnika) {
    info_o_zaduzenju=&ref_na_korisnika; //?
}


class Biblioteka {
    std::map<int, std::shared_ptr<Korisnik>> mapa_korisnika;
    std::map<int, std::shared_ptr<Knjiga>> mapa_knjiga;
    public:
    Biblioteka () : mapa_korisnika(), mapa_knjiga() {}
    Biblioteka (const Biblioteka &b); //Kopirajuci konstruktor
    Biblioteka (Biblioteka &&b); //Pomjerajuci konstruktor
    Biblioteka &operator=(Biblioteka b);
    Biblioteka &operator=(Biblioteka &&b);
    
    //Kopirajuci konstruktor i konstruktor dodjele -duboke kopije
    ~Biblioteka();
    void RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu(int ev_br, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int cl_broj) const; //inspektor?
    Knjiga &NadjiKnjigu(int ev_broj) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int ev_broj, int cl_broj);
    void RazduziKnjigu(int ev_broj);
    void PrikaziZaduzenja(int cl_broj) const;
};

//Konstruktori

Biblioteka::~Biblioteka() {
    auto it(mapa_korisnika.begin());
    for (; it!=mapa_korisnika.end(); it++) {
        it->second=nullptr;
    }
    mapa_korisnika.clear();
    auto it2(mapa_knjiga.begin());
    for ( ; it2!=mapa_knjiga.end(); it2++) {
        auto p(it2->second->DajKodKogaJe());
        p=nullptr;
        it2->second=nullptr;
    }
    mapa_knjiga.clear();
}

Biblioteka::Biblioteka (const Biblioteka &b) {
    //Kopirajmo prvu mapu
    auto it(b.mapa_korisnika.begin());
    for (; it!=b.mapa_korisnika.end(); it++) {
        Korisnik k;
        k.ime=(it->second)->ime;
        k.prezime=(it->second)->prezime;
        k.adresa=(it->second)->adresa;
        k.telefon=(it->second)->telefon;
        std::shared_ptr<Korisnik> kopija(std::make_shared<Korisnik>(k));
        mapa_korisnika.insert(std::make_pair(it->first, kopija));
    }
    //Kopirajmo drugu mapu
    auto it2(b.mapa_knjiga.begin());
    for ( ; it2!=b.mapa_knjiga.end(); it2++) {
        std::shared_ptr<Knjiga> kopija(std::make_shared<Knjiga>(it2->second->DajNaslov(), it2->second->DajAutora(), it2->second->DajZanr(), it2->second->DajGodinuIzdavanja()));
        mapa_knjiga.insert(std::make_pair(it2->first, kopija));
    }
}

Biblioteka::Biblioteka (Biblioteka &&b) {
    auto it(b.mapa_korisnika.begin());
    for (; it!=b.mapa_korisnika.end(); it++) { 
        mapa_korisnika.insert(std::make_pair(it->first, it->second));
        it->second=nullptr;
    }
    auto it2(b.mapa_knjiga.begin());
    for ( ; it2!=b.mapa_knjiga.end(); it2++) { 
        mapa_knjiga.insert(std::make_pair(it2->first, it2->second));
        it->second=nullptr;
    }
}

Biblioteka &Biblioteka::operator=(Biblioteka b) {
    mapa_korisnika.swap(b.mapa_korisnika); mapa_knjiga.swap(b.mapa_knjiga);
    return *this;
}
Biblioteka &Biblioteka::operator=(Biblioteka &&b) {
    mapa_korisnika.swap(b.mapa_korisnika); mapa_knjiga.swap(b.mapa_knjiga);
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
    Korisnik novi;
    novi.ime=ime; novi.prezime=prezime; novi.adresa=adresa; novi.telefon=telefon;
    auto pok_na_novog(std::make_shared<Korisnik>(novi));
    //Provjerimo da li ima vec korisnik sa ovim cl_br
    auto it(mapa_korisnika.begin());
    for (; it!=mapa_korisnika.end(); it++) {
        if (it->first==cl_broj) break;
    }
    if (it!=mapa_korisnika.end()) throw std::logic_error("Korisnik vec postoji");
    mapa_korisnika.insert(std::make_pair(cl_broj, pok_na_novog));
}
  
void Biblioteka::RegistrirajNovuKnjigu(int ev_br, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) {
    auto pok_na_novu(std::make_shared<Knjiga>(naslov, ime_pisca, zanr, godina_izdavanja));
    //Provjerimo da li postoji vec knjiga sa ovim ev_br
    auto it(mapa_knjiga.begin());
    for ( ; it!=mapa_knjiga.end(); it++) {
        if (it->first==ev_br) break;
    }
    if (it!=mapa_knjiga.end()) throw std::logic_error("Knjiga vec postoji");
    mapa_knjiga.insert(std::make_pair(ev_br, pok_na_novu));
}


Korisnik &Biblioteka::NadjiKorisnika(int cl_broj) const {
    auto it(mapa_korisnika.begin());
    for (; it!=mapa_korisnika.end(); it++) {
        if (it->first==cl_broj) break;
    }
    if (it==mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    return *(it->second); //??
}


Knjiga &Biblioteka::NadjiKnjigu(int ev_broj) const {
    auto it(mapa_knjiga.begin());
    for (; it!=mapa_knjiga.end(); it++) {
        if (it->first==ev_broj) break;
    }
    if (it==mapa_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    return *(it->second); //?
}

void Biblioteka::IzlistajKorisnike() const {
    auto it(mapa_korisnika.begin());
    for (; it!=mapa_korisnika.end(); it++) {
        cout << "Clanski broj: " << it->first << endl;
        cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << endl;
        cout << "Adresa: " << it->second->adresa << endl;
        cout << "Broj telefona: " << it->second->telefon << endl << endl;
    }
}

void Biblioteka::IzlistajKnjige() const {
    auto it(mapa_knjiga.begin());
    for (; it!=mapa_knjiga.end(); it++) {
        cout << "Evidencijski broj: " << it->first << endl;
        cout << "Naslov: " << it->second->DajNaslov() << endl;
        cout << "Pisac: " << it->second->DajAutora() << endl;
        cout << "Zanr: " << it->second->DajZanr() << endl;
        cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << endl;
        if (!(it->second->DaLiJeZaduzena())) { cout << endl; continue; }
        cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime << endl;
        cout << endl;
    }
}

void Biblioteka::ZaduziKnjigu(int ev_broj, int cl_broj) {
    auto it(mapa_knjiga.begin());
    for (; it!=mapa_knjiga.end(); it++) {
        if (it->first==ev_broj) {
            if (it->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
            auto it2(mapa_korisnika.begin());
            for (; it2!=mapa_korisnika.end(); it2++) {
                if (it2->first==cl_broj) {
                    //it na knjigu it2 na kokrisnika
                    it->second->ZaduziKnjigu(*(it2->second));
                    break;
                }
            }
            if (it2==mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
            break;
        }
    }
    if (it==mapa_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    
}

void Biblioteka::RazduziKnjigu(int ev_broj) {
    auto it(mapa_knjiga.begin());
    for (; it!=mapa_knjiga.end(); it++) {
        if (it->first==ev_broj) {
            if (it->second->DaLiJeZaduzena()==false) throw std::logic_error ("Knjiga nije zaduzena");
            it->second->RazduziKnjigu();
            break;
        }
    }
    if (it==mapa_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
}
void Biblioteka::PrikaziZaduzenja(int cl_broj) const {
    auto it2(mapa_korisnika.begin());
    for (; it2!=mapa_korisnika.end(); it2++) {
        if (it2->first==cl_broj) {
            auto it(mapa_knjiga.begin());
            for (; it!=mapa_knjiga.end(); it++) { 
                if (it->second->DajKodKogaJe()->ime==it2->second->ime)
                cout << "Evidencijski broj: " << it->first << endl;
                cout << "Naslov: " << it->second->DajNaslov() << endl;
                cout << "Pisac: " << it->second->DajAutora() << endl;
                cout << "Zanr: " << it->second->DajZanr() << endl;
                cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << endl;  
            }
            if (it==mapa_knjiga.end()) cout << "Nema zaduzenja za tog korisnika!" << endl;
        }
    }
    if (it2==mapa_korisnika.end()) throw std::logic_error ("Korisnik nije nadjen");
}

int main () {
    Biblioteka b;
    int opcija(0);
    while(true) {
        cout << "Odaberite opciju: " << endl;
        cout << " 0 - kraj" << endl << " 1 - Registriraj novog korisnika" << endl << " 2 - Registriraj novu knjigu" << endl 
        <<" 3 - Izlistaj korisnike" << endl << " 4 - Izlistaj knjige" << endl << " 5 - Zaduzi knjigu" << endl 
        << " 6 - Razduzi knjigu" << endl << " 7 - PrikaziZaduzenja" << endl; 
        cin >> opcija;
        if (opcija==0) return 0;
        if (opcija==1) {
            try {
                int cl_br(0);
                cout << "Unesite podatke o novom korisniku.\nClanski broj: ";
                cin >> cl_br;
                std::string ime, prezime, adresa, telefon;
                cout << "Ime: ";
                cin.ignore(1000, '\n');
                std::getline(cin, ime);
                cout << "Prezime: ";
                std::getline(cin, prezime);
                cout << "Adresa: ";
                std::getline(cin, adresa);
                cout << "Telefon: ";
                std::getline(cin, telefon);
                //b.RegistrirajNovogKorisnika(cl_br, ime, prezime, adresa, telefon);
            }
            catch (std::logic_error i) {
                cout << i.what() << endl;
                continue;
            }
        }
        if (opcija==2) {
            try {
                int ev_br(0), godina(0);
                cout << "Unesite podatke o novoj knjizi.\nEvidencijski broj: ";
                cin >> ev_br;
                std::string naslov, ime_pisca, zanr;
                cout << "Naslov: ";
                cin.ignore(1000, '\n');
                std::getline(cin, naslov);
                cout << "Ime pisca: ";
                std::getline(cin, ime_pisca);
                cout << "Zanr: ";
                std::getline(cin, zanr);
                cout << "Godina: ";
                cin >> godina;
                b.RegistrirajNovuKnjigu(ev_br, naslov, ime_pisca, zanr, godina);
            }
            catch (std::logic_error i) {
                cout << i.what() << endl;
            }
        }
        if (opcija==3) {
            cout << "Korisnici biblioteke: " << endl;
            b.IzlistajKorisnike();
        }
        if (opcija==4) {
            cout << "Knjige u biblioteci: " << endl;
            b.IzlistajKnjige();
        }
        if (opcija==5) {
            try {
                cout << "Unesite evidencijski broj knjige i clanski broj korisnika: " << endl;
                int broj(0), cl_broj(0);
                cin >> broj >> cl_broj;
                b.ZaduziKnjigu(broj, cl_broj);
            }
            catch (std::logic_error i) {
                cout << i.what() << endl;
            }
        }
        if (opcija==6) {
            try {
                int broj(0);
                cout << "Unesite evidencijski broj knjige koju zelite razduziti: ";
                cin >> broj;
                b.RazduziKnjigu(broj);
            }
            catch (std::logic_error i) {
                cout << i.what() << endl;
            }
        }
        if (opcija==7) {
            try {
                int broj(0);
            cout << "Unesite clanski broj korisnika: ";
            cin >> broj;
            cout << "Zaduzenja: " << endl;
            b.PrikaziZaduzenja(broj);
            }
            catch (std::logic_error i) {
                cout << i.what() << endl;
            } 
        }
    }
	return 0;
}