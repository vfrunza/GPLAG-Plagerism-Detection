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
            if(jel_zaduzeno==0) cout << "Nema zaduzenja za tog korisnika!";
        }
};

int main ()
{
    try {
        Biblioteka bib8, bib(bib8);
        bib.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
        bib.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
        bib.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
        bib.ZaduziKnjigu(2, 1);
        bib.ZaduziKnjigu(1, 1);
        bib.PrikaziZaduzenja(1);
    }
    catch (logic_error err) {
        cout<< endl << err.what();
    }
	return 0;
}