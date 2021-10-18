/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>
#include <utility>
#include <memory>

struct Korisnik{
    std::string ime, prezime,adresa, telefon;
};

class Knjiga{
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *zaduzena = nullptr;
public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina){
        this->naslov = naslov;
        this->ime_pisca = ime_pisca;
        this->zanr = zanr;
        this->godina_izdavanja = godina;
        
    }
    std::string DajNaslov(){
        return naslov;
    }
    std::string DajAutora(){
        return ime_pisca;
    }
    std::string DajZanr(){
        return zanr;
    }
    int DajGodinuIzdavanja(){
        return godina_izdavanja;
    }
    Korisnik *DajKodKogaJe(){
        return zaduzena;
    }
    void ZaduziKnjigu(Korisnik &k){
        //mozda ipak da napravim novog ili?
        zaduzena = &k;
        
    }
    void RazduziKnjigu(){
        
        zaduzena = nullptr;
    }
    bool DaLiJeZaduzena(){
        
        if(zaduzena == nullptr) return false;
        return true;
    }
};

class Biblioteka{
    std::map<int, std::shared_ptr<Knjiga>> knjige;
    std::map<int, std::shared_ptr<Korisnik>> korisnici;
    
    void IspisiKorisnika(const Korisnik &k){
        std::cout << "Ime i prezime: " << k.ime << " " << k.prezime << std::endl;
        std::cout << "Adresa: " << k.adresa << std::endl;
        std::cout << "Broj telefona: " << k.telefon << std::endl;
    }
    
    void IspisiKnjigu(Knjiga &k){
        std::cout << "Naslov: " << k.DajNaslov() << std::endl;
        std::cout << "Pisac: " << k.DajAutora() << std::endl;
        std::cout << "Zanr: " << k.DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << k.DajGodinuIzdavanja() << std::endl;
        
        
    }
public:
    Biblioteka (){
    }
    Biblioteka(Biblioteka &b){
        
        for(auto x : b.knjige){
            int broj = x.first;
            std::shared_ptr<Knjiga> knjiga = std::make_shared<Knjiga>((x.second)->DajNaslov(), (x.second)->DajAutora(), (x.second)->DajZanr(), (x.second)->DajGodinuIzdavanja());
            if((x.second)->DaLiJeZaduzena()){
                Korisnik korisnik =*(x.second)->DajKodKogaJe();
                knjiga->ZaduziKnjigu(korisnik);
                knjiga = nullptr;
            }
            knjige.insert(std::make_pair(broj,knjiga));
        }
        
        for(auto x : b.korisnici){
            int broj = x.first;
            std::shared_ptr<Korisnik>novi_korisnik = std::make_shared<Korisnik>();
            novi_korisnik->ime = (x.second)->ime;
            novi_korisnik->prezime = (x.second)->prezime;
            novi_korisnik->adresa = (x.second)->adresa;
            novi_korisnik->telefon = (x.second)->telefon;
            korisnici.insert(std::make_pair(broj,novi_korisnik));
            novi_korisnik = nullptr;
        }
        
    }
    Biblioteka &operator =(Biblioteka &b){
        if(&b == this) return *this;
        for(auto x : knjige){
            //delete x.second;
            x.second = nullptr;
            
        }
        knjige.erase(knjige.begin(),knjige.end());
        for(auto x : korisnici){
            //delete x.second;
            x.second = nullptr;
            
        }
       for(auto x : b.knjige){
            int broj = x.first;
            std::shared_ptr<Knjiga> knjiga = std::make_shared<Knjiga>((x.second)->DajNaslov(), (x.second)->DajAutora(), (x.second)->DajZanr(), (x.second)->DajGodinuIzdavanja());
            if((x.second)->DaLiJeZaduzena()){
                Korisnik korisnik =*(x.second)->DajKodKogaJe();
                knjiga->ZaduziKnjigu(korisnik);
                knjiga = nullptr;
            }
            knjige.insert(std::make_pair(broj,knjiga));
        }
        
        for(auto x : b.korisnici){
            int broj = x.first;
            std::shared_ptr<Korisnik>novi_korisnik = std::make_shared<Korisnik>();
            novi_korisnik->ime = (x.second)->ime;
            novi_korisnik->prezime = (x.second)->prezime;
            novi_korisnik->adresa = (x.second)->adresa;
            novi_korisnik->telefon = (x.second)->telefon;
            korisnici.insert(std::make_pair(broj,novi_korisnik));
            novi_korisnik = nullptr;
        }
        return *this;
        
    }
    ~Biblioteka(){
        for(auto x : knjige){
            //delete x.second;
            x.second = nullptr;
            
        }
        knjige.erase(knjige.begin(),knjige.end());
        for(auto x : korisnici){
            //delete x.second;
            x.second = nullptr;
            
        }
        korisnici.erase(korisnici.begin(),korisnici.end());
    }
    //dodati za privremene objekte -.-'
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
        for(auto x : korisnici){
            if(x.first == clanski_broj) throw std::logic_error("Korisnik vec postoji");
            
        }
        std::shared_ptr<Korisnik> novi_korisnik = std::make_shared<Korisnik>();
        novi_korisnik->ime = ime;
        novi_korisnik->prezime = prezime;
        novi_korisnik->adresa = adresa;
        novi_korisnik->telefon = telefon;
        korisnici[clanski_broj] = novi_korisnik;
        novi_korisnik = nullptr;
    }
    void RegistrirajNovuKnjigu(int ev_broj_knjige, std::string naziv, std::string autor, std::string zanr, int godina){
        for(auto x : knjige){
            if(x.first == ev_broj_knjige) throw std::logic_error("Knjiga vec postoji");
            
        }
        std::shared_ptr<Knjiga>knjiga = std::make_shared<Knjiga>(naziv, autor,zanr , godina);
        //knjige[ev_broj_knjige] = knjiga;
        knjige.insert(std::make_pair(ev_broj_knjige,knjiga));
        knjiga = nullptr;
    }
    
    Korisnik &NadjiKorisnika(int clanski_broj){
       
        for(auto x : korisnici){
           if(x.first == clanski_broj){
               return *(korisnici[clanski_broj]);
           } 
        }
        throw std::logic_error("Korisnik nije nadjen");
        
        
    }
    Knjiga &NadjiKnjigu(int ev_broj_knjige){
        for(auto x : knjige){
           if(x.first == ev_broj_knjige){
               return *(knjige[ev_broj_knjige]);
           } 
        }
        throw std::logic_error("Knjiga nije nadjena");
    }
    
    void ZaduziKnjigu(int ev_broj_knjige, int clanski_broj){
        bool nasao = false;
        for(auto x : knjige) 
            if(x.first == ev_broj_knjige){
                nasao = true;
                break;
            }
        if(nasao == false) throw std::logic_error("Knjiga nije nadjena");
        nasao = false;
        for(auto x : korisnici)
            if(x.first == clanski_broj) {
                nasao = true;
                break;
            }
        if(nasao == false) throw std::logic_error("Korisnik nije nadjen");
        
        if(knjige[ev_broj_knjige]->DaLiJeZaduzena() == true) throw std::logic_error("Knjiga vec zaduzena");
        
        knjige[ev_broj_knjige]->ZaduziKnjigu(*(korisnici[clanski_broj]));
    }
    
    void IzlistajKorisnike(){
        for(auto x : korisnici){
            std::cout <<"Clanski broj: " << x.first << std::endl;
            IspisiKorisnika(*(x.second));
            std::cout << std::endl;
            
        }
    }
    void IzlistajKnjige(){
        for(auto x : knjige){
            std::cout <<"Evidencijski broj: " << x.first <<std::endl;
            IspisiKnjigu(*(x.second));
            if(x.second->DaLiJeZaduzena()){
                Korisnik k = *(x.second)->DajKodKogaJe();
                for(auto y : korisnici) {
                    if((y.second)->ime == k.ime && (y.second)->prezime == k.prezime && (y.second)->adresa == k.adresa && (y.second)->telefon == k.telefon) std::cout <<"Zaduzena kod korisnika: " << k.ime << " " << k.prezime <<std::endl;
                }
            }
            std::cout << std::endl;
            
        }
    }
    void PrikaziZaduzenja(int clanski_broj){
        bool nasao = false;
        for(auto x : korisnici){
            if(x.first == clanski_broj) {
                nasao = true;
                break;
            }
        }
        if(nasao == false ) throw std::logic_error("Korisnik nije nadjen");
        Korisnik k = *(korisnici[clanski_broj]);
        bool ima = false;;
        for(auto x : knjige){
            //std::cout << x.first;
            //IspisiKnjigu(*(x.second));
            if(x.second->DaLiJeZaduzena()){
                Korisnik y= *(x.second)->DajKodKogaJe();
                if(y.ime == k.ime && y.prezime == k.prezime && y.adresa == k.adresa && y.telefon == k.telefon) {
                    ima = true;
                    std::cout << "Evidencijski broj: "<<x.first <<std::endl;
                    IspisiKnjigu(*(x.second));
                   // std::cout <<"Zaduzena kod korisnika: " << k.ime << " " << k.prezime <<std::endl;
                    std::cout << std::endl;
                }
            }
            
            
        }
        if(ima == false) std::cout << "Nema zaduzenja za tog korisnika"<< std::endl;
    }
    void RazduziKnjigu(int ev_broj_knjige){
        bool nasao = false;
        for(auto x : knjige){
            if(x.first == ev_broj_knjige){
                if((x.second)->DaLiJeZaduzena() == true){
                    (x.second)->RazduziKnjigu();
                    nasao = true;
                    break;
                }
                else 
                    throw std::logic_error("Knjiga nije zaduzena");
            }
        }
        if(nasao == false) throw std::logic_error("Knjiga nije nadjena");
    }
};
int main ()
{
   /* Korisnik *k = new Korisnik();
    Biblioteka *b = new Biblioteka();
    Biblioteka c(*b);
    
    k->ime="a";
    k->prezime ="b";
    k->adresa = "c";
    k->telefon = "d";
    Knjiga *knjiga = new Knjiga("k","l","m",1);
    knjiga->ZaduziKnjigu(*k);
    std::cout << knjiga->DaLiJeZaduzena();
    knjiga->RazduziKnjigu();
    std::cout << knjiga->DaLiJeZaduzena();
    delete knjiga;
    delete k;
    delete b;*/
   /* Korisnik kor{"Meho", "Mehic", "Dobojska 15", "033/123-456"};
Knjiga knj("Tvrdjava", "Mesa Selimovic", "Roman", 1965);
if(knj.DajKodKogaJe() == nullptr) std::cout << "Nije zaduzena\n";
std::cout << knj.DaLiJeZaduzena() << std::endl;
knj.ZaduziKnjigu(kor);
std::cout << "Knjigu je zaduzio " << knj.DajKodKogaJe()->ime << std::endl;
std::cout << knj.DaLiJeZaduzena() << std::endl;
*/
Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
"Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
"Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
"Studenata etfovaca 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
b.PrikaziZaduzenja(1234);
	return 0;
}