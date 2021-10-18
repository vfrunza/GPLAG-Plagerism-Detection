/B16/17 (Zadaća 5, Zadatak 1)

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

using std::string;
using std::map;
using std::cout;
using std::cin;

struct Korisnik{
    string ime, prezime, adresa, telefon;
};

class Knjiga{
    string naslov, pisac, zanr;
    int godina;
    Korisnik* zaduzio = nullptr;
    
public:
    // Konstruktor
    Knjiga(){}
    Knjiga(string n, string p, string z, int god){
        naslov=n;
        pisac=p;
        zanr=z;
        godina=god;
        zaduzio=nullptr;
    }
    
    // Getteri
    string DajNaslov() const { return naslov; }
    string DajAutora() const { return pisac; }
    string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina; }
    Korisnik* DajKodKogaJe() const { return zaduzio; }
    
    // Metode
    void ZaduziKnjigu(Korisnik &k){ zaduzio=&k; }
    void RazduziKnjigu(){ zaduzio=nullptr; }
    bool DaLiJeZaduzena() const { if(zaduzio) return true; return false; }
    
    friend class Biblioteka;
};

class Biblioteka{
    map<int, Korisnik*> korisnici;
    map<int, Knjiga*> knjige;
    
public:
    // Konstruktor
    Biblioteka(){}
    Biblioteka(map<int, Korisnik*> kor, map<int, Knjiga*> knji){ korisnici=kor; knjige=knji; }
    
    // Kopirajuci konstruktor
    Biblioteka(Biblioteka &b){ korisnici=b.korisnici; knjige=b.knjige; }
    
    // Destruktor
    ~Biblioteka(){
        for(auto it(korisnici.begin()); it!=korisnici.end(); it++) delete it->second;
        for(auto it(knjige.begin()); it!=knjige.end(); it++) delete it->second;
    }
    
    // Metode
    void RegistrirajNovogKorisnika(int clanskiBroj, string ime, string prezime, string adresa, string telefon){
        try{
        if(korisnici.find(clanskiBroj)!=korisnici.end()) throw std::logic_error("Korisnik vec postoji");
        Korisnik* k = new Korisnik;
        k->ime=ime;
        k->prezime=prezime;
        k->adresa=adresa;
        k->telefon=telefon;
        korisnici[clanskiBroj] = k;
        } catch(std::logic_error e){ cout << e.what(); }
    }
    void RegistrirajNovuKnjigu(int evBroj, string naslov, string pisac, string zanr, int godina){
        try{
        if(knjige.find(evBroj)!=knjige.end()) throw std::logic_error("Knjiga vec postoji");
        Knjiga* k = new Knjiga;
        k->naslov=naslov;
        k->pisac=pisac;
        k->zanr=zanr;
        k->godina=godina;
        knjige[evBroj] = k;
        } catch(std::logic_error e){ cout << e.what(); }
    }
    Korisnik &NadjiKorisnika(int clanskiBroj) const {
        if(korisnici.find(clanskiBroj)==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        return *(korisnici.find(clanskiBroj)->second);
    }
    Knjiga &NadjiKnjigu(int evBroj) const {
        if(knjige.find(evBroj)==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        return *(knjige.find(evBroj)->second);
    }
    void IzlistajKorisnike() const {
        for(auto it(korisnici.begin()); it!=korisnici.end(); it++){
            cout << "Clanski broj: " << it->first << std::endl;
            cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl;
            cout << "Adresa: " << it->second->adresa << std::endl;
            cout << "Broj telefona: " << it->second->telefon << std::endl;
        }
    }
    void IzlistajKnjige() const {
        for(auto it(knjige.begin()); it!=knjige.end(); it++){
            cout << "Evidencijski broj: " << it->first << std::endl;
            cout << "Naslov: " << it->second->naslov << std::endl;
            cout << "Pisac: " << it->second->pisac << std::endl;
            cout << "Zanr: " << it->second->zanr << std::endl;
            cout << "Godina izdavanja: " << it->second->godina << std::endl;
            // Dodatni ispis ako je knjiga zaduzena
            if(it->second->zaduzio){
                cout << "Zaduzena kod korisnika: " << it->second->zaduzio->ime << " " << it->second->zaduzio->prezime << std::endl;
            }
        }
    }
    void ZaduziKnjigu(int evBroj, int clanskiBroj){
        try{
        // Moguci problemi
        if(knjige.find(evBroj)==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        if(korisnici.find(clanskiBroj)==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        if(knjige[evBroj]->zaduzio) throw std::logic_error("Knjiga vec zaduzena");
        
        knjige[evBroj]->zaduzio = korisnici[clanskiBroj];
        } catch(std::logic_error e){ cout << e.what(); }
    }
    void RazaduziKnjigu(int evBroj){
        try{
        // Moguci problemi
        if(knjige.find(evBroj)==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        if(!(knjige[evBroj]->zaduzio)) throw std::logic_error("Knjiga nije zaduzena");
        
        knjige[evBroj]->zaduzio = nullptr;
        } catch(std::logic_error e){ cout << e.what(); }
    }
    void PrikaziZaduzenja(int clanskiBroj){
        try{
        Korisnik* korisnik = korisnici[clanskiBroj];
        if(korisnici.find(clanskiBroj)==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        int br(0);
        for(auto it(knjige.begin()); it!=knjige.end(); it++){
            if(it->second->zaduzio == korisnik){
                cout << "Evidencijski broj: " << it->first << std::endl;
                cout << "Naslov: " << it->second->naslov << std::endl;
                cout << "Pisac: " << it->second->pisac << std::endl;
                cout << "Zanr: " << it->second->zanr << std::endl;
                cout << "Godina izdavanja: " << it->second->godina << std::endl;
                br++;
            }
        }
        if(br==0) throw std::logic_error("Nema zaduzenja za tog korisnika!");
        } catch(std::logic_error e){ cout << e.what(); }
    }
};

int main (){
    Biblioteka bibble;
    
    for(;;){
        cout << "Unesite redni broj komande koju zelite:" << std::endl;
        cout << "(0)    " << "Izlaz iz programa" << std::endl;
        cout << "(1)    " << "Registracija Korisnika" << std::endl;
        cout << "(2)    " << "Registracija Knjige" << std::endl;
        cout << "(3)    " << "Pronadji Korisnika" << std::endl;
        cout << "(4)    " << "Pronadji Knjigu" << std::endl;
        cout << "(5)    " << "Ispisi Korisnike" << std::endl;
        cout << "(6)    " << "Ispisi Knjige" << std::endl;
        cout << "(7)    " << "Zaduzi Knjigu" << std::endl;
        cout << "(8)    " << "Vrati Knjigu" << std::endl;
        cout << "(9)    " << "Prikazi Zaduzene Knjige Korisnika" << std::endl;
        
        int komanda;
        std::cin >> komanda;
        
        bool van(false);
        switch(komanda){
            case 0:{
                van=true;
                break;
            }
            case 1:{
                try{
                string ime, prezime, adresa, telefon;
                cin.ignore(10000, '\n');
                cout << "Ime: ";
                getline(cin, ime);
                cout << "Prezime: ";
                getline(cin, prezime);
                cout << "Adresa: ";
                getline(cin, adresa);
                cout << "Kontakt Telefon: ";
                getline(cin, telefon);
                
                int clanskiBroj;
                cout << "Clanski Broj: ";
                cin >> clanskiBroj;
                
                bibble.RegistrirajNovogKorisnika(clanskiBroj, ime, prezime, adresa, telefon);
                cout << std::endl;
                break;
                } catch(std::logic_error greska){
                    cout << greska.what();
                    break;
                }
            }
            case 2:{
                try{
                string naslov, pisac, zanr;
                cin.ignore(10000, '\n');
                cout << "Naslov: ";
                getline(cin, naslov);
                cout << "Autor: ";
                getline(cin, pisac);
                cout << "Zanr: ";
                getline(cin, zanr);
                
                int godina, evBroj;
                cout << "Godina Izdavanja: ";
                cin >> godina;
                cout << "Evidencijski Broj: ";
                cin >> evBroj;
                
                bibble.RegistrirajNovuKnjigu(evBroj, naslov, pisac, zanr, godina);
                cout << std::endl;
                break;
                } catch(std::logic_error greska){
                    cout << greska.what();
                    break;
                }
            }
            case 3:{
                try{
                cout << "Unesite Clanski Broj: ";
                int clanskiBroj;
                cin >> clanskiBroj;
                
                Korisnik kor(bibble.NadjiKorisnika(clanskiBroj));
                
                cout << kor.ime << " " << kor.prezime << std::endl;
                cout << kor.adresa << std::endl << kor.telefon << std::endl;
                break;
                } catch(std::logic_error greska){
                    cout << greska.what();
                    break;
                }
            }
            case 4:{
                try{
                cout << "Unesite Evidencijski Broj: ";
                int evBroj;
                cin >> evBroj;
                
                Knjiga knjiga(bibble.NadjiKnjigu(evBroj));
                
                cout << knjiga.DajAutora() <<  " - " << knjiga.DajNaslov() << ", napisana " << knjiga.DajGodinuIzdavanja();
                cout << ". / " << knjiga.DajZanr() << std::endl;
                break;
                } catch(std::logic_error greska){
                    cout << greska.what();
                    break;
                }
            }
            case 5:{
                try{
                bibble.IzlistajKorisnike();
                cout << std::endl;
                break;
                } catch(std::logic_error greska){
                    cout << greska.what();
                    break;
                }
            }
            case 6:{
                try{
                bibble.IzlistajKnjige();
                cout << std::endl;
                break;
                } catch(std::logic_error greska){
                    cout << greska.what();
                    break;
                }
            }
            case 7:{
                try{
                cout << "Unesite Evidencijski Broj Knjige: ";
                int evBroj;
                cin >> evBroj;
                
                cout << "Unesite Clanski Broj Korisnika: ";
                int clanskiBroj;
                cin >> clanskiBroj;
                
                bibble.ZaduziKnjigu(evBroj, clanskiBroj);
                cout << std::endl;
                break;
                } catch(std::logic_error greska){
                    cout << greska.what();
                    break;
                }
            }
            case 8:{
                try{
                cout << "Unesite Evidencijski Broj Knjige: ";
                int evBroj;
                cin >> evBroj;
                
                bibble.RazaduziKnjigu(evBroj);
                cout << std::endl;
                break;
                } catch(std::logic_error greska){
                    cout << greska.what();
                    break;
                }
            }
            case 9:{
                try{
                cout << "Unesite Clanski Broj Korisnika: ";
                int clanskiBroj;
                cin >> clanskiBroj;
                
                bibble.PrikaziZaduzenja(clanskiBroj);
                cout << std::endl;
                break;
                } catch(std::logic_error greska){
                    cout << greska.what();
                    break;
                }
            }
            default:{
                cout << "Pogresan unos komande, pokusajte ponovo.";
                cout << std::endl;
                break;
            }
        }
        
        if(van) break;
    }
	return 0;
}