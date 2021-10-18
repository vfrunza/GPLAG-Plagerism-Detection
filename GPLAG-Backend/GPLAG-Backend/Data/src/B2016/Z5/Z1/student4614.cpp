/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <stdexcept>
#include <new>
#include <iterator>

    using std::cout;
    using std::endl;
    using std::cin;
    
    struct Korisnik{
        std::string ime;
        std::string prezime;
        std::string adresa;
        std::string telefon;
    };
        
    class Knjiga{
        std::string naslov;
        std::string ime_pisca;
        std::string zanr;
        int god_izdavanja;
        Korisnik *zaduzenje;
    public: 
        Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int god_izdavanja) :
           naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), god_izdavanja(god_izdavanja), zaduzenje(nullptr) {}
        std::string DajNaslov()const{
            return naslov;
        }
        std::string DajAutora()const{
            return ime_pisca;
        }
        std::string DajZanr()const{
            return zanr;
        }
        int DajGodinuIzdavanja()const{
            return god_izdavanja;
        }
        Korisnik *DajKodKogaJe()const{
            return zaduzenje;
        }
        void ZaduziKnjigu(Korisnik &zaduzioc){
            zaduzenje = &zaduzioc;
        }
        void RazduziKnjigu(){
            zaduzenje = nullptr;
        }
        bool DaLiJeZaduzena()const{
            if(!zaduzenje) return false;
            return true;
        }
        void Ispisi()const{
            cout<< "Naslov: " << naslov << endl;
            cout<< "Pisac: " << ime_pisca << endl;
            cout<< "Zanr: " << zanr << endl;
            cout<< "Godina izdavanja: " << god_izdavanja << endl;
        }
    };
    
    class Biblioteka{
        std::map<int, Korisnik*>korisnik;
        std::map<int, Knjiga*>knjige;
    public:
        Biblioteka(){}
        Biblioteka(const Biblioteka &b){
        for(auto it = b.korisnik.begin(); it != b.korisnik.end(); it++)
            korisnik[it->first] = new Korisnik(*it->second);
        for(auto it = b.knjige.begin(); it != b.knjige.end(); it++)
            knjige[it->first] = new Knjiga(*it->second);
        }
        Biblioteka(Biblioteka &&b){
            korisnik = b.korisnik;
            knjige = b.knjige;
            b.korisnik.clear();
            b.knjige.clear();
        }
        Biblioteka &operator =(Biblioteka b){
            std::swap(korisnik,b.korisnik);
            std::swap(knjige,b.knjige);
            return *this;
        }
       /* Biblioteka &operator =(const Biblioteka &b){
            if(korisnik.size() < b.korisnik.size()){
                for(auto it = b.korisnik.begin(); it != b.korisnik.end(); it++)
                    korisnik[it->first] = new Korisnik(*it->second);
                for(auto it = korisnik.begin(); it != korisnik.end(); it++)
                    delete it->second;
                korisnik = b.korisnik;
            }
            return *this;
        }
        */
        ~Biblioteka(){
            for(auto it = korisnik.begin(); it != korisnik.end(); it++)
                delete it->second;
            for(auto it = knjige.begin(); it != knjige.end(); it++)
                delete it->second;
        }
        void RegistrirajNovogKorisnika(int clanski_broj,std::string ime, std::string prezime, std::string adresa, std::string telefon){
            for(auto it = korisnik.begin(); it != korisnik.end(); it++){
                if(it->first == clanski_broj)
                    throw std::logic_error("Korisnik vec postoji");
            }
            Korisnik* pomocni = new Korisnik{ime,prezime,adresa,telefon};
            korisnik.insert(std::make_pair(clanski_broj,pomocni));
        }
        void RegistrirajNovuKnjigu(int evid_broj, std::string naslov, std::string ime_pisca, std::string zanr, int god_izdavanja){
            for(auto it = knjige.begin(); it != knjige.end(); it++){
                if(it->first == evid_broj)
                    throw std::logic_error("Knjiga vec postoji");
            }
            Knjiga *pomocni = new Knjiga(naslov,ime_pisca,zanr,god_izdavanja);
            knjige.insert(std::make_pair(evid_broj,pomocni));
        }
        Korisnik &NadjiKorisnika(int clanski_broj){
            auto it(korisnik.find(clanski_broj));
            if(it == korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
            return *(it->second);
            }
        Knjiga &NadjiKnjigu(int knjiga_id){
            auto it(knjige.find(knjiga_id));
            if(it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
            return *(it->second);
        }
        void IzlistajKorisnike(){
            for(auto it = korisnik.begin(); it != korisnik.end(); it++){
                cout << "Clanski broj: " << it->first << endl;
                cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << endl;
                cout << "Adresa: " << it->second->adresa << endl;
                cout << "Broj telefona: " << it->second->telefon << endl;
            }
        }
        void IzlistajKnjige(){
                for(auto it = knjige.begin(); it != knjige.end(); it++){
                    cout<< "Evidencijski broj: " << it->first << endl;
                    it->second->Ispisi();
                    if(it->second->DaLiJeZaduzena()){
                        cout << "Zaduzena kod korisnika: ";
                        auto k = it->second->DajKodKogaJe();
                        cout << k->ime << " " << k->prezime;
                    }
                    cout << endl;
                }
        }
        void ZaduziKnjigu(int evid_broj, int clanski_broj){
            auto it1(knjige.find(evid_broj));
            if(it1 == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
            auto it(korisnik.find(clanski_broj));
            if(it == korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
            if(NadjiKnjigu(evid_broj).DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
            NadjiKnjigu(evid_broj).ZaduziKnjigu(NadjiKorisnika(clanski_broj));
        }
        
        void RazduziKnjigu(int evid_broj){
            auto it1(knjige.find(evid_broj));
            if(it1 == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
            if(!NadjiKnjigu(evid_broj).DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
            NadjiKnjigu(evid_broj).RazduziKnjigu();
        }
        void PrikaziZaduzenja(int clanski_broj){
            try {
                NadjiKorisnika(clanski_broj);
                bool provjera(false);
                for(auto it = knjige.begin(); it != knjige.end(); it++){
                    if(it->second->DaLiJeZaduzena()){
                        provjera = true;
                        auto gdje = it->second->DajKodKogaJe();
                        if(it->first == clanski_broj)
                            cout << gdje->ime << " " << gdje->prezime;
                    }
                }
                if(!provjera) cout << "Nema zaduzenja za tog korisnika!";
            }
            catch (std::logic_error e) {
                throw;
            }
            
        }
        
    };
    
int main(){
    Biblioteka gradska;
    cout << "*****************Dobro dosli u gradsku bibloteku*****************\n\n\n";
    while (true) {
        cout << "\nIzbornik:\n\n\n1. Dodaj korisnika\n2. Dodaj knjigu\n3. Nadji korisnika\n4. Nadji knjigu\n5. Izlistaj Korisnike\n6. Izlistaj Knjige\n7. Zaduzi Knjigu\n8. Razduzi Knjigu\n9. Prikaz Zaduzenja\n10. IZLAZ\n\n\nVas izbor: ";
        int n;
        cin >> n;
        if(n <= 0 || n > 10) cout << "Broj koji ste unijeli ne nalazi se u izborniku, molimo pokusajte ponovo!";
        else if(n == 1){
            cin.ignore(10, '\n');
            int clanski_broj;
            std::string ime;
            std::string prezime;
            std::string adresa;
            std::string telefon;
            cout << "Unesite ime novog korisnika: ";
            std::getline(cin,ime);
            cout << "Unesite prezime novog korisnika: ";
            std::getline(cin,prezime);
            cout << "Unesite adresu novog korisnika: ";
            std::getline(cin,adresa);
            cout << "Unesite telefon novog korisnika: ";
            std::getline(cin,telefon);
            cout << "Unesite clanski broj novog korisnika: ";
            cin >> clanski_broj;
            try {
                gradska.RegistrirajNovogKorisnika(clanski_broj,ime,prezime,adresa,telefon);
            }
            catch (std::logic_error e) {
                cout << e.what() << endl;
            }
        }
        else if(n == 2){
            cin.ignore(10, '\n');
            std::string naslov, pisac, zanr;
            int evid_broj,god_izdavanja;
            cout << "Unesite naslov nove knjige: ";
            std::getline(cin,naslov);
            cout << "Unesite pisca nove knjige: ";
            std::getline(cin,pisac);
            cout << "Unesite zanr nove kjige: ";
            std::getline(cin,zanr);
            cout << "Unesite godinu izdavanja nove knjige: ";
            cin >> god_izdavanja;
            cout << "Unesite evidencijski broj nove knjige: ";
            cin >> evid_broj;
            try {
                gradska.RegistrirajNovuKnjigu(evid_broj,naslov,pisac,zanr,god_izdavanja);
            }
            catch (std::logic_error e) {
                cout << e.what() << endl;
            }
        }
        else if(n == 3){
            cin.ignore(10, '\n');
            cout << "Unesite clanski broj korisnika: ";
            int clanski_broj;
            cin >> clanski_broj;
            try {
                Korisnik nadjen = gradska.NadjiKorisnika(clanski_broj);
                cout << "Korisnik sa clanskim brojem " << clanski_broj << " je: "<<nadjen.ime << " " << nadjen.prezime;
            }
            catch (std::logic_error e) {
                cout << e.what() << endl;
            }
        }
        else if(n == 4){
            cin.ignore(10, '\n');
            cout << "Unesite evidencijski broj knjige: ";
            int evid_broj;
            cin >> evid_broj;
            try {
                Knjiga nadjen = gradska.NadjiKnjigu(evid_broj);
                cout << "Knjiga sa evidencijskim brojem " << evid_broj << " je: ";
                nadjen.Ispisi();
            }
            catch (std::logic_error e) {
                cout << e.what() << endl;
            }
        }
        else if(n == 5){
            cout << "**********Korisnici:*************\n\n";
            gradska.IzlistajKorisnike();
        }
        else if(n == 6){
            cout<< "***********Knjige***********\n\n";
            gradska.IzlistajKnjige();
        }
        else if(n == 7){
            cout << "Unesite evidencijski broj knjige koja se zaduzuje: ";
            int evid_broj;
            cin >> evid_broj;
            cout << "Unesite clanski broj korisnika koji zaduzuje knjigu: ";
            int clanski_broj;
            cin >> clanski_broj;
            try {
                gradska.ZaduziKnjigu(evid_broj,clanski_broj);
            }
            catch (std::logic_error e) {
                cout << e.what() << endl;
            }
        }
        else if(n == 8){
            cout << "Unesite evidencijski broj knjige koja se razduzuje: ";
            int evid_broj;
            cin >> evid_broj;
            try {
                gradska.RazduziKnjigu(evid_broj);
            }
            catch (std::logic_error e) {
                cout << e.what() << endl;
            }
        }
        else if(n == 9){
            cout << "Unesite clanski broj korisnika za kojeg provjeravate zaduzenje: ";
            int clanski_broj;
            cin >> clanski_broj;
            try {
                gradska.PrikaziZaduzenja(clanski_broj);
            }
            catch (std::logic_error e) {
                cout << e.what() << endl;
            }
        }
        else if(n == 10) break;
    }
    return 0;
}