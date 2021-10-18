/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <memory>
#include <new>
#include <stdexcept>
using namespace std;

struct Korisnik {
    string ime, prezime, adresa, telefon;  
};

class Knjiga {
        string naslov, ime_pisca, zanr;
        int godina_izdavanja;
        Korisnik *zaduzenje;
    public:
        Knjiga(string naslov, string ime_pisca, string zanr, int godina_izdavanja) :
            naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), zaduzenje(nullptr) {}
        string DajNaslov() const {
            return naslov;
        }
        string DajAutora() const {
            return ime_pisca;
        }
        string DajZanr() const {
            return zanr;
        }
        int DajGodinuIzdavanja() const {
            return godina_izdavanja;
        }
        Korisnik *DajKodKogaJe() const {
            return zaduzenje;
        }
        void ZaduziKnjigu(Korisnik &zaduzivac) {
            zaduzenje=&zaduzivac;
        }
        void RazduziKnjigu() {
            zaduzenje=nullptr;
        }
        bool DaLiJeZaduzena() {
            if(zaduzenje==nullptr) return false;
            return true;
        }
};

class Biblioteka {
        map<int,Korisnik*> korisnici;
        map<int,Knjiga*> knjige;
    public:
        Biblioteka() {}
        ~Biblioteka() {
            for(auto &x : korisnici) {
                delete x.second;
            }
            for(auto &x : knjige) {
                delete x.second;
            }
        }
        void RegistrirajNovogKorisnika(int clanski_br, string ime, string prezime, string adresa, string telefon) {
            for(auto &x : korisnici) {
                if(x.first==clanski_br) throw logic_error("Korisnik vec postoji");
            }
            Korisnik temp;
            temp.ime=ime; temp.prezime=prezime; temp.adresa=adresa; temp.telefon=telefon;
            korisnici.insert(make_pair(clanski_br,new Korisnik(temp)));
        }
        void RegistrirajNovuKnjigu(int evidencijski_br, string naslov, string ime_pisca, string zanr, int godina_izdavanja) {
            for(auto &x : knjige) {
                if(x.first==evidencijski_br) throw logic_error("Knjiga vec postoji");
            }
            Knjiga temp(naslov,ime_pisca,zanr,godina_izdavanja);
            knjige.insert(make_pair(evidencijski_br,new Knjiga(temp)));
        }
        Korisnik &NadjiKorisnika(int clanski_br) const {
            for(auto &x : korisnici) {
                if(x.first==clanski_br) return *x.second;
            }
            throw logic_error("Korisnik nije nadjen");
        }
        Knjiga &NadjiKnjigu(int evidencijski_br) const {
            for(auto &x : knjige) {
                if(x.first==evidencijski_br) return *x.second;
            }
            throw logic_error("Knjiga nije nadjen");
        }
        void IzlistajKorisnike() const {
            for(auto &x : korisnici) {
                cout << "\nClanski broj: " << x.first << endl;
                cout << "Ime i prezime: " << x.second->ime << " " << x.second->prezime << endl;
                cout << "Adresa: " << x.second->adresa << endl;
                cout << "Broj telefona: " << x.second->telefon << "\n";
            }
        }
        void IzlistajKnjige() const {
            for(auto &x : knjige) {
                cout << "\nEvidencijski broj: " << x.first << endl;
                cout << "Naslov: " << x.second->DajNaslov() << endl;
                cout << "Pisac: " << x.second->DajAutora() << endl;
                cout << "Zanr: " << x.second->DajZanr() << endl;
                cout << "Godina izdavanja: " << x.second->DajGodinuIzdavanja();
                if(x.second->DajKodKogaJe()==nullptr) cout << endl;
                else {
                    cout << "\nZaduzena kod korisnika: " << x.second->DajKodKogaJe()->ime << " " << x.second->DajKodKogaJe()->prezime << endl;
                }
            }
        }
        void ZaduziKnjigu(int evidencijski_br, int clanski_br) {
            bool nadjena_knjiga(false);
            for(auto &x : knjige) {
                if(x.first==evidencijski_br) {
                    nadjena_knjiga=true;
                    if(x.second->Knjiga::DaLiJeZaduzena()==true) throw logic_error("Knjiga vec zaduzena");
                    bool nadjen_korisnik(false);
                    for(auto &y : korisnici) {
                        if(y.first==clanski_br) {
                            nadjen_korisnik=true;
                            x.second->Knjiga::ZaduziKnjigu(*y.second);
                        }
                    }
                    if(nadjen_korisnik==false) throw logic_error("Korisnik nije nadjen");
                }
            }
            if(nadjena_knjiga==false) throw logic_error("Knjiga nije nadjena");
        }
        void RazduziKnjigu(int evidencijski_br) {
            bool nadjena_knjiga(false);
            for(auto &x : knjige) {
                if(x.first==evidencijski_br) {
                    nadjena_knjiga=true;
                    if(x.second->Knjiga::DaLiJeZaduzena()==true) x.second->Knjiga::RazduziKnjigu();
                    else throw logic_error("Knjiga nije zaduzena");
                }
            }
            if(nadjena_knjiga==false) throw logic_error("Knjiga nije nadjena");
        }
        void PrikaziZaduzenja(int clanski_br) {
            Korisnik *nas_covjek(nullptr);
            for(auto &x : korisnici) {
                if(x.first==clanski_br) {
                    nas_covjek=x.second;
                    break;
                }
            }
            if(nas_covjek==nullptr) throw logic_error("Korisnik nije nadjen");
            int jel_zaduzeno(0);
            for(auto &x : knjige) {
                if(x.second->Knjiga::DajKodKogaJe()==nas_covjek) {
                    jel_zaduzeno=1;
                    cout << "\nEvidencijski broj: " << x.first << endl;
                    cout << "Naslov: " << x.second->DajNaslov() << endl;
                    cout << "Pisac: " << x.second->DajAutora() << endl;
                    cout << "Zanr: " << x.second->DajZanr() << endl;
                    cout << "Godina izdavanja: " << x.second->DajGodinuIzdavanja() << endl;
                }
            }
            if(jel_zaduzeno==0) cout << "Nema zaduzenja za tog korisnika!\n";
        }
};

int main ()
{
    cout << "Dobrodosli!\n";
    Biblioteka bibl;
    while(1) {
        int n;
        ponovo:
        cout << "Unesite: \n";
        cout << "- 0 za kraj\n";
        cout << "- 1 za registraciju novog korisnika\n";
        cout << "- 2 za registraciju nove knjige\n";
        cout << "- 3 za trazenje korisnika\n";
        cout << "- 4 za trazenje knjige\n";
        cout << "- 5 za prikaz svih korisnika\n";
        cout << "- 6 za prikaz svih knjiga\n";
        cout << "- 7 za zaduzivanje knjige\n";
        cout << "- 8 za razduzivanje knjige\n";
        cout << "- 9 za prikaz svih zaduzenja korisnika\n";
        cin >> n;
        if(n==0) return 0;
        else if(n==1) {
            ponovo1:
            cout << "Unesite podatke o korisniku: \n";
            int clanski_br;
            cout << "Clanski broj (0 za vracanje na pocetak): ";
            cin >> clanski_br;
            if(clanski_br==0) goto ponovo;
            string ime;
            cout << "Ime: ";
            cin >> ime;
            string prezime;
            cout << "Prezime: ";
            cin >> prezime;
            string adresa;
            cout << "Adresa: ";
            cin >> adresa;
            string telefon;
            cout << "telefon: ";
            cin >> telefon;
            try {
                bibl.RegistrirajNovogKorisnika(clanski_br, ime, prezime, adresa, telefon);
                cout << "Korisnik uspjesno registriran! \n";
            }
            catch(logic_error err) {
                cout << err.what() << ". Ponovite unos!\n";
                goto ponovo1;
            }
        }
        else if(n==2) {
            ponovo2:
            cout << "Unesite podatke o korisniku: \n";
            int evidencijski_br;
            cout << "Evidencijski broj (0 za vracanje na pocetak): ";
            cin >> evidencijski_br;
            if(evidencijski_br==0) goto ponovo;
            string naslov;
            cout << "Naslov: ";
            cin >> naslov;
            string ime_pisca;
            cout << "Ime pisca: ";
            cin >> ime_pisca;
            string zanr;
            cout << "Zanr: ";
            cin >> zanr;
            int godina_izdavanja;
            cout << "Godina izdavanja: ";
            cin >> godina_izdavanja;
            try {
                bibl.RegistrirajNovuKnjigu(evidencijski_br, naslov, ime_pisca, zanr, godina_izdavanja);
                cout << "Knjiga uspjesno registrirana! \n";
            }
            catch(logic_error err) {
                cout << err.what() << ". Ponovite unos!\n";
                goto ponovo2;
            }
        }
        else if(n==3) {
            ponovo3:
            cout << "Unesite clanski broj korisnika (0 za vracanje na pocetak): ";
            int clanski_br;
            cin >> clanski_br;
            if(clanski_br==0) goto ponovo;
            try {
                Korisnik nadjen=bibl.NadjiKorisnika(clanski_br);
                cout << "Podaci o korisniku: \n";
                cout << "Ime: " << nadjen.ime << endl;
                cout << "Prezime: " << nadjen.prezime << endl;
                cout << "Adresa: " << nadjen.adresa << endl;
                cout << "Telefon: " << nadjen.telefon << endl;
                cout << "Zaduzenja korisnika: \n";
                bibl.PrikaziZaduzenja(clanski_br);
            }
            catch(logic_error err) {
                cout << err.what() << ". Ponovite unos!\n";
                goto ponovo3;
            }
        }
        else if(n==4) {
            ponovo4:
            cout << "Unesite evidencijski broj knjige (0 za vracanje na pocetak): ";
            int evidencijski_br;
            cin >> evidencijski_br;
            if(evidencijski_br==0) goto ponovo;
            try {
                Knjiga nadjena=bibl.NadjiKnjigu(evidencijski_br);
                cout << "Podaci o knjizi: \n";
                cout << "Naslov: " << nadjena.DajNaslov() << endl;
                cout << "Autor: " << nadjena.DajAutora() << endl;
                cout << "Zanr: " << nadjena.DajZanr() << endl;
                cout << "Godina_izdavanja: " << nadjena.DajGodinuIzdavanja() << endl;
                if(nadjena.DajKodKogaJe()==nullptr) cout << endl;
                else {
                    cout << "Zaduzena kod korisnika: " << nadjena.DajKodKogaJe()->ime << " " << nadjena.DajKodKogaJe()->prezime << endl;
                }
            }
            catch(logic_error err) {
                cout << err.what() << ". Ponovite unos!\n";
                goto ponovo4;
            }
        }
        else if(n==5) {
            bibl.IzlistajKorisnike();
        }
        else if(n==6) {
            bibl.IzlistajKnjige();
        }
        else if(n==7) {
            ponovo7:
            int clanski_br;
            cout << "Clanski broj korisnika (0 za vracanje na pocetak): ";
            cin >> clanski_br;
            if(clanski_br==0) goto ponovo;
            int evidencijski_br;
            cout << "Evidencijski broj knjige (0 za vracanje na pocetak): ";
            cin >> evidencijski_br;
            if(evidencijski_br==0) goto ponovo;
            try {
                bibl.ZaduziKnjigu(evidencijski_br, clanski_br);
                cout << "Knjiga uspjesno zaduzena!\n ";
            }
            catch(logic_error err) {
                cout << err.what() << ". Ponovite unos!\n";
                goto ponovo7;
            }
        }
        else if(n==8) {
            ponovo8:
            int evidencijski_br;
            cout << "Evidencijski broj knjige (0 za vracanje na pocetak): ";
            cin >> evidencijski_br;
            if(evidencijski_br==0) goto ponovo;
            try {
                bibl.RazduziKnjigu(evidencijski_br);
                cout << "Knjiga uspjesno razduzena!\n ";
            }
            catch(logic_error err) {
                cout << err.what() << ". Ponovite unos!\n";
                goto ponovo8;
            }
        }
        else if(n==9) {
            ponovo9:
            int clanski_br;
            cout << "Clanski broj korisnika (0 za vracanje na pocetak): ";
            cin >> clanski_br;
            try {
                bibl.PrikaziZaduzenja(clanski_br);
            }
            catch(logic_error err) {
                cout << err.what() << ". Ponovite unos!\n";
                goto ponovo9;
            }
        }
    }
	return 0;
}