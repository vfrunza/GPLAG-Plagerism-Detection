#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <memory>
#include <new>

using namespace std;

struct Korisnik{
    string ime;
    string prezime;
    string adresa;
    string telefon;
    
};

class Knjiga{
    private:
        string naslov;
        string ime_pisca;
        string zanr;
        int godina_izdavanja;
        Korisnik *zaduzio;
    
    public:
        Knjiga(string _naslov, string _ime, string _zanr, int _godina_izdavanja){
            naslov = _naslov;
            ime_pisca = _ime;
            zanr = _zanr; 
            godina_izdavanja = _godina_izdavanja;
            zaduzio = nullptr;
        }
        
        string DajNaslov() const {
            return naslov;
        }
        
        string DajAutora() const{
            return ime_pisca;
        }
        
        string DajZanr() const{
            return zanr;
        }
        
        int DajGodinuIzdavanja() const{
            return godina_izdavanja;
        }
        
        Korisnik* DajKodKogaJe() const{
            return zaduzio;
        }
        
        void ZaduziKnjigu(Korisnik* _zaduzio){
            zaduzio = _zaduzio;
        }
        
        void ZaduziKnjigu(Korisnik _zaduzio){
            zaduzio = &_zaduzio;
        }
        
        void RazduziKnjigu(){
            zaduzio = nullptr;
        }
        
        bool DaLiJeZaduzena(){
            if(zaduzio == nullptr) return false;
            else return true;
        }
        
        
};

class Biblioteka{
    private:
        map<int, shared_ptr<Korisnik>> mapa_korisnika;
        map<int, shared_ptr<Knjiga>> mapa_knjiga;
    public:
        Biblioteka():mapa_korisnika(),mapa_knjiga(){}
        
        Biblioteka(Biblioteka &b){
            
            for(auto val : b.mapa_korisnika){
                shared_ptr<Korisnik> novi_korisnik(new Korisnik{val.second -> ime, val.second -> prezime, val.second -> adresa, val.second -> telefon});
                int clanski_kopija = val.first;
                
                mapa_korisnika.insert(pair<int, shared_ptr<Korisnik>>(clanski_kopija, novi_korisnik));
            }
            
           for(auto val : b.mapa_knjiga){
               shared_ptr<Knjiga> nova_knjiga(new Knjiga(val.second -> DajNaslov(), val.second -> DajAutora(), val.second -> DajZanr(), val.second -> DajGodinuIzdavanja()));
               int evidencijski_kopija = val.first;
               
               mapa_knjiga.insert(pair<int, shared_ptr<Knjiga>>(evidencijski_kopija, nova_knjiga));
           }
        }
        
        Biblioteka operator=(const Biblioteka &b){
            if( this == &b){
                for(auto val : b.mapa_korisnika){
                    shared_ptr<Korisnik> novi_korisnik(new Korisnik{val.second -> ime, val.second -> prezime, val.second -> adresa, val.second -> telefon});
                    int clanski_kopija = val.first;
                    
                    mapa_korisnika.insert(pair<int, shared_ptr<Korisnik>>(clanski_kopija, novi_korisnik));
                }
                for(auto val : b.mapa_knjiga){
                    shared_ptr<Knjiga> nova_knjiga(new Knjiga(val.second -> DajNaslov(), val.second -> DajAutora(), val.second -> DajZanr(), val.second -> DajGodinuIzdavanja()));
                    int evidencijski_kopija = val.first;
                    
                    mapa_knjiga.insert(pair<int, shared_ptr<Knjiga>>(evidencijski_kopija, nova_knjiga));
                }
            }
            return*this;
        }
        
        
        
        void RegistrirajNovogKorisnika(int clanskiBroj, string _ime, string _prezime, string _adresa, string _telefon){
            
                for(auto val : mapa_korisnika){
                    if( val.first == clanskiBroj && val.second -> ime == _ime && val.second -> prezime == _prezime && 
                        val.second -> adresa == _adresa && val.second -> telefon == _telefon) throw logic_error("Korisnik vec postoji.");
                    }
                    
                    shared_ptr<Korisnik> n_korisnik(new Korisnik{_ime, _prezime, _adresa, _telefon});
                    mapa_korisnika.insert(pair<int, shared_ptr<Korisnik>> (clanskiBroj, n_korisnik));
            
                
           
        }
        
        void RegistrirajNovuKnjigu(int evidencijskiBroj, string _naslov, string _ime_pisca, string _zanr, int _godina_izdavanja){
            
                for(auto val : mapa_knjiga){
                    if(val.first == evidencijskiBroj && val.second -> DajNaslov() == _naslov && val.second -> DajAutora() == _ime_pisca &&
                    val.second -> DajZanr() == _zanr && val.second -> DajGodinuIzdavanja() == _godina_izdavanja) throw logic_error("Knjiga vec postoji");
                }
                
                shared_ptr<Knjiga> n_knjiga(new Knjiga(_naslov, _ime_pisca, _zanr, _godina_izdavanja));
                mapa_knjiga.insert(pair<int, shared_ptr<Knjiga>> (evidencijskiBroj, n_knjiga));
                
           
        }
        
        Korisnik& NadjiKorisnika(const int _clanskiBroj) const{
            
                if(mapa_korisnika.count( _clanskiBroj ) > 0) return *(mapa_korisnika.find(_clanskiBroj) -> second);
                else throw logic_error("Korisnik nije nadjen");
                
            
        }
        
        Knjiga& NadjiKnjigu(const int _evidencijskiBroj) const{
                
                if(mapa_knjiga.count(_evidencijskiBroj) > 0){
                    return *(mapa_knjiga.find(_evidencijskiBroj) -> second);
                }
                else throw logic_error("Knjiga nije nadjena");
            
        }
        
        void IzlistajKorisnike() const{
            for(auto val : mapa_korisnika){
                cout << "Clanski broj: " << val.first<<endl;
                cout << "Ime i prezime: " << val.second -> ime << " " << val.second -> prezime << endl; 
                cout << "Adresa: " << val.second -> adresa << endl;
                cout << "Broj telefona: " << val.second -> telefon << endl;
            }
        }
        
        void IzlistajKnjige() const{
            for(auto val : mapa_knjiga){
                cout << "Evidencijski broj: " << val.first<<endl;
                cout << "Naslov: " << val.second -> DajNaslov()<<endl;
                cout << "Pisac: " << val.second -> DajAutora() << endl;
                cout << "Zanr: " << val.second -> DajZanr() << endl;
                cout << "Godina izdavanja: " << val.second -> DajGodinuIzdavanja() <<endl;
                
                if(val.second -> DaLiJeZaduzena()) cout << "Zaduzena kod korisnika: " << val.second -> DajKodKogaJe() -> ime  << " " << val.second -> DajKodKogaJe() -> prezime << endl;
            }
        }
        
        void ZaduziKnjigu(int evid, int clans){
            if(mapa_knjiga.count(evid) == 0) throw logic_error("Knjiga nije nadjena");
            else if(mapa_knjiga.find(evid) -> second -> DaLiJeZaduzena()) throw logic_error("Knjiga vec zaduzena");
            else mapa_knjiga.find(evid) -> second -> Knjiga::ZaduziKnjigu(&*(mapa_korisnika[clans]));
        }
        
        void RazduziKnjigu(int evid){
            if(mapa_knjiga.count(evid) == 0) throw logic_error("Knjiga nije nadjena");
            else if(!(mapa_knjiga.find(evid) -> second -> DaLiJeZaduzena())) throw logic_error("Knjiga nije zaduzena");
            else NadjiKnjigu(evid).RazduziKnjigu();
        }
        
        void PrikaziZaduzenja(int clans) const{
            shared_ptr<Korisnik> korisnik_temp = mapa_korisnika.find(clans) -> second;
            if(mapa_korisnika.count(clans) == 0) throw logic_error("Korisnik nije nadjen");
            else {
                int counter = 0;
                for(auto val : mapa_knjiga){
                    if(val.second -> DajKodKogaJe() == &*korisnik_temp) {
                        cout << "Evidencijski broj: " << val.first << endl;
                        cout << "Naslov: " << val.second -> DajNaslov() << endl;
                        cout << "Pisac: " << val.second -> DajAutora() << endl;
                        cout << "Zanr: " << val.second -> DajZanr() << endl;
                        cout << "Godina izdavanja: " << val.second -> DajGodinuIzdavanja() << endl;
                        counter++;
                    }
                }
                if(counter == 0) throw logic_error("Nema zaduzenja za tog korisnika!");
            }
        }
        
};

int main ()
{
    Biblioteka mojaBib;
    int komanda = -1;
    while(komanda != 0){
        cout << "Izaberite komandu: "<< endl;
        cout << "1 - Kreiranje nove knjige " << endl;
        cout << "2 - Kreiranje novog korisnika "<< endl;
        cout << "3 - Zaduzivanje knjige "<< endl;
        cout << "4 - Razduzivanje knjige "<< endl;
        cout << "5 - Izlistavanje knjiga " << endl;
        cout << "6 - Izlistavanje korisnika "<< endl;
        cout << "0 - Izlazak iz programa "<< endl;
        
        cin >> komanda;
        cin.clear();
        switch(komanda){
            case 1:
            {
                cout << "Unesite podatke o knjizi: "<< endl;
                cout << "Unesite naslov knjige: ";
                string naslov_knjige;
                cin >> naslov_knjige;
                cin.clear();
                cout << endl;
                cout << "Unesite autora knjige: " << endl;
                string autor;
                cin >> autor;
                cin.clear();
                cout << endl;
                cout << "Unesite zanr knjige: " << endl;
                string zanr_knjige;
                cin >> zanr_knjige;
                cin.clear();
                cout << endl;
                cout << "Unesite godinu izdavanja knjige: " << endl;
                int godina_izdavanja_knjige;
                cin >> godina_izdavanja_knjige;
                cin.clear();
                cout << endl;
                cout << "Unesite evidencijski broj knjige: ";
                int ev_br;
                cin >> ev_br;
                cin.clear();
                cout << endl;
                mojaBib.RegistrirajNovuKnjigu(ev_br,naslov_knjige, autor, zanr_knjige, godina_izdavanja_knjige);
                cout << "Knjiga uspjesno kreirana." << endl;
                break;
            }
            case 2:
            {
                cout << "Unesite podatke korisnika: "<< endl;
                cout << "Unesite ime korisnika: ";
                string ime_korisnika;
                cin >> ime_korisnika;
                cin.clear();
                cout << endl;
                cout << "Unesite prezime korisnika: ";
                string prezime_korisnika;
                cin >> prezime_korisnika;
                cin.clear();
                cout << endl;
                cout << "Unesite adresu korisnika: ";
                string adresa_korisnika;
                cin >> adresa_korisnika;
                cin.clear();
                cout << endl;
                cout << "Unesite telefon korisnika: ";
                string telefon_korisnika;
                cin >> telefon_korisnika;
                cin.clear();
                cout << endl;
                cout << "Unesite clanski broj korisnika: ";
                int cl_br;
                cin >> cl_br;
                cin.clear();
                cout << endl;
                mojaBib.RegistrirajNovogKorisnika(cl_br, ime_korisnika, prezime_korisnika, adresa_korisnika, telefon_korisnika);
                cout << "Korisnik uspjesno kreiran." << endl;
                break;
            }
            case 3:
            {
                cout << "Unesite evidencijski broj knjige koju zelite zaduziti: ";
                int ev_br1;
                cin >> ev_br1;
                cin.clear();
                cout << endl;
                cout << "Unesite clanski broj korisnika koji zaduzuje knjigu: ";
                int cl_br1;
                cin >> cl_br1;
                cin.clear();
                cout << endl;
                mojaBib.ZaduziKnjigu(ev_br1,cl_br1);
                cout << "Knjiga uspjesno zaduzena" << endl;
                break;
            }
            case 4:
            {
                cout << "Unesite evidencijski broj knjige koju zelite razduziti: ";
                int ev_br2;
                cin >> ev_br2;
                cin.clear();
                mojaBib.RazduziKnjigu(ev_br2);
                break;
            }
            case 5:
            {
                mojaBib.IzlistajKnjige();
                break;
            }
            case 6:
            {
                mojaBib.IzlistajKorisnike();
                break;
            }
        }
    }

    
	return 0;
}