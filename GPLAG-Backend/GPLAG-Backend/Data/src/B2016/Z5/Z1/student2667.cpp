/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>

struct Korisnik{
  std::string ime;
  std::string prezime;
  std::string adresa;
  std::string telefon;
  
};

class Knjiga {
   std::string naslov_knjige;
   std::string ime_autora_knjige;
   std::string zanr_knjige;
   int godina_izdavanja_knjige;
   Korisnik *kod_koga_je_zaduzena;
  public:
   Knjiga(std::string n, std::string i, std::string z, int g){
        kod_koga_je_zaduzena = nullptr;
        naslov_knjige = n;
        ime_autora_knjige = i;
        zanr_knjige = z;
        godina_izdavanja_knjige = g;
    }
    std::string DajNaslov(){
        std::string s = naslov_knjige;
        return s;
    }
    std::string DajAutora(){
        std::string s = ime_autora_knjige;
        return s;
    }
    std::string DajZanr(){
        std::string s = zanr_knjige;
        return s;
    }
    int DajGodinuIzdavanja(){
        int godina = godina_izdavanja_knjige;
        return godina;
    }
    Korisnik *DajKodKogaJe(){
        return kod_koga_je_zaduzena;
        
    }
    void RazduziKnjigu(){
        kod_koga_je_zaduzena = nullptr;
    }
    void ZaduziKnjigu(Korisnik &k){
        kod_koga_je_zaduzena= &k;
    }
    bool DaLiJeZaduzena(){
        if(kod_koga_je_zaduzena != nullptr)
        return true;
        return false;
    }
};

class Biblioteka{
   std::map<int, Korisnik*> mapa_korisnika;
   std::map<int, Knjiga*> mapa_knjiga;
  public:
   Biblioteka(){
       
   }
   
   Biblioteka(const Biblioteka &biblioteka){
       for(auto it = biblioteka.mapa_knjiga.begin(); it != biblioteka.mapa_knjiga.end(); it++){
           Knjiga *nova = new Knjiga((it->second)->DajNaslov(), (it->second)->DajAutora() , (it->second)->DajZanr(), (it->second)->DajGodinuIzdavanja());
       
           if((it->second)->DaLiJeZaduzena() == true){
               nova->ZaduziKnjigu(*(it->second)->DajKodKogaJe());
           }
           mapa_knjiga.insert(std::make_pair(it->first, nova));
       }
       
       for(auto it = biblioteka.mapa_korisnika.begin(); it != biblioteka.mapa_korisnika.end(); it++){
           Korisnik *novi = new Korisnik();
           novi->ime = (it->second)->ime;
           novi->prezime = (it->second)->prezime;
           novi->adresa = (it->second)->adresa;
           novi->telefon = (it->second)->telefon;
           mapa_korisnika.insert(std::make_pair(it->first, novi));
       }
       
   }
   
   ~Biblioteka(){
       for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++){
           delete it->second;
           it->second = nullptr;
       }
       
       for(auto it = mapa_korisnika.begin(); it != mapa_korisnika.end(); it++){
           delete it->second;
           it->second = nullptr;
       }
       
       mapa_knjiga.erase(mapa_knjiga.begin(), mapa_knjiga.end());
       mapa_korisnika.erase(mapa_korisnika.begin(), mapa_korisnika.end());
       
   }
   
   Biblioteka &operator =(const Biblioteka &biblioteka){
       if(this == &biblioteka)
       return *this;
       
       for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++){
           delete it->second;
           it->second = nullptr;
       }
       
       for(auto it = mapa_korisnika.begin(); it != mapa_korisnika.end(); it++){
           delete it->second;
           it->second = nullptr;
       }
       
       mapa_knjiga.erase(mapa_knjiga.begin(), mapa_knjiga.end());
       mapa_korisnika.erase(mapa_korisnika.begin(), mapa_korisnika.end());
       
       
              for(auto it = biblioteka.mapa_knjiga.begin(); it != biblioteka.mapa_knjiga.end(); it++){
           Knjiga *nova = new Knjiga((it->second)->DajNaslov(), (it->second)->DajAutora() , (it->second)->DajZanr(), (it->second)->DajGodinuIzdavanja());
       
           if((it->second)->DaLiJeZaduzena() == true){
               nova->ZaduziKnjigu(*(it->second)->DajKodKogaJe());
           }
           mapa_knjiga.insert(std::make_pair(it->first, nova));
       }
       
       for(auto it = biblioteka.mapa_korisnika.begin(); it != biblioteka.mapa_korisnika.end(); it++){
           Korisnik *novi = new Korisnik();
           novi->ime = (it->second)->ime;
           novi->prezime = (it->second)->prezime;
           novi->adresa = (it->second)->adresa;
           novi->telefon = (it->second)->telefon;
           mapa_korisnika.insert(std::make_pair(it->first, novi));
       }
       
       return *this;
   }
   
   void RegistrirajNovogKorisnika(int b, std::string i, std::string p, std::string a, std::string t){
       if(ImaLiKorisnika(b) == true) throw std::logic_error("Korisnik vec postoji");
       
       Korisnik *novi = new Korisnik();
       novi->ime = i; novi->prezime = p; novi->adresa = a; novi->telefon = t;
       mapa_korisnika.insert(std::make_pair(b,novi));
        novi = nullptr;
   }
   
   void RegistrirajNovuKnjigu(int b, std::string n, std::string a, std::string z, int g){
       if(ImaLiKnjige(b) == true) throw std::logic_error("Knjiga vec postoji");
       
       Knjiga *nova = new Knjiga(n,a,z,g);
       mapa_knjiga.insert(std::make_pair(b,nova));
       nova = nullptr;
   }
   
   void ZaduziKnjigu(int br_knj, int br_kor){
       if(ImaLiKnjige(br_knj) == false) throw std::logic_error("Knjiga nije nadjena");
       if(ImaLiKorisnika(br_kor) == false) throw std::logic_error("Korisnik nije nadjen");
       if(mapa_knjiga[br_knj]->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
       mapa_knjiga[br_knj]->ZaduziKnjigu(*mapa_korisnika[br_kor]);
   }
   
   Korisnik &NadjiKorisnika(int b){
       if(ImaLiKorisnika(b) == false) throw std::logic_error("Korisnik nije nadjen");
       return *mapa_korisnika[b];
   }
   
   
   Knjiga &NadjiKnjigu(int b){
       if(ImaLiKnjige(b) == false) throw std::logic_error("Knjiga nije nadjena");
       return *mapa_knjiga[b];
   }
   
   void IzlistajKorisnike(){
       
       auto it = mapa_korisnika.begin();
       while(it != mapa_korisnika.end()){
           IspisiZaKorisnika(*it);
           std::cout << std::endl;
           it++;
       }
       
   }
   
   void IzlistajKnjige(){
       auto it = mapa_knjiga.begin();
       while(it != mapa_knjiga.end()){
           IspisiZaKnjigu(*it);
           std::cout << std::endl;
           it++;
       }
   }
   
   void PrikaziZaduzenja(int b){
       if(ImaLiKorisnika(b) == false) throw std::logic_error("Korisnik nije nadjen");
       
       bool postoji = false;
       
       for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++){
           if(it->second->DaLiJeZaduzena()){
               
               if(it->second->DajKodKogaJe() == mapa_korisnika[b]){
                   postoji = true;
                   std::cout << "Evidencijski broj: " << it->first << std::endl;
       std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
       std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
       std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
       std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
                   std::cout << std::endl;
               }
           }
       }
   }
  private:
   void IspisiZaKnjigu(std::pair<int, Knjiga*> par){
       std::cout << "Evidencijski broj: " << par.first << std::endl;
       std::cout << "Naslov: " << par.second->DajNaslov() << std::endl;
       std::cout << "Pisac: " << par.second->DajAutora() << std::endl;
       std::cout << "Zanr: " << par.second->DajZanr() << std::endl;
       std::cout << "Godina izdavanja: " << par.second->DajGodinuIzdavanja() << std::endl;
        if(par.second->DaLiJeZaduzena()) std::cout << "Zaduzena kod korisnika: " << (par.second->DajKodKogaJe())->ime << " " << (par.second->DajKodKogaJe())->prezime <<std::endl;
       
   }
   
   void IspisiZaKorisnika(std::pair<int, Korisnik*> par){
       std::cout << "Clanski broj: "<<par.first << std::endl;
       std::cout << "Ime i prezime: " << par.second->ime << " " <<par.second->prezime << std::endl;
       std::cout << "Adresa: " << par.second->adresa << std::endl;
       std::cout << "Broj telefona: " << par.second->telefon << std::endl;
   }
   bool ImaLiKnjige(int b){
       auto it = mapa_knjiga.begin();
       while(it!= mapa_knjiga.end()){
           if(it->first == b) return true;
           it++;
       }
       return false;
   }
   bool ImaLiKorisnika(int b){
       auto it = mapa_korisnika.begin();
       while(it != mapa_korisnika.end()){
           if(it->first == b) return true;
           it++;
       }
       return false;
   }
};
int main ()
{
    
    Biblioteka bib8;
bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
bib8.ZaduziKnjigu(2, 1);
bib8.PrikaziZaduzenja(1);
    
	return 0;
}