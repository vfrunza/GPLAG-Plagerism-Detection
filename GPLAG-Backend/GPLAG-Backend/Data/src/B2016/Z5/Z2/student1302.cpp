/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <map>
#include <stdexcept>
#include <string> 
#include <memory>
struct Korisnik {
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
    Korisnik(std::string im, std::string prez, std::string adr, std::string tele){
        ime = im;
        prezime = prez;
        adresa = adr;
        telefon = tele;
    }
    Korisnik (Korisnik &k){
        this->ime = k.ime;
        this->prezime = k.prezime;
        this->adresa = k.adresa;
        this->telefon = k.telefon;
    }
    /*friend const bool &operator == (const Korisnik &k1, const Korisnik &k2){
        if(k1.ime==k2.ime && k1.prezime==k2.prezime && k1.adresa==k2.adresa && k1.telefon == k2.telefon)
            return true;
        return false;
    }*/
};
void IspisiKorisnika (Korisnik &k){
    std::cout<<"Ime i prezime: "<<k.ime<<" "<<k.prezime<<std::endl;
    std::cout<<"Adresa: "<<k.adresa<<std::endl<<"Broj telefona: "<<k.telefon<<std::endl;
}
class Knjiga {
    private: 
        std::string Naslov, Ime_pisca, Zanr;
        int Godina_izdavanja;
        Korisnik *p = nullptr;
    public:
        Knjiga(std::string naslov, std::string  autor, std::string zanr, int godina) :Naslov(naslov), Ime_pisca(autor), Zanr(zanr){
            Naslov = naslov;
            Ime_pisca = autor;
            Zanr = zanr;
            Godina_izdavanja = godina;
            p = nullptr;
        }
        Knjiga &operator =(Knjiga &k){
            if(&k== this) return *this;
            Naslov = k.DajNaslov();
            Ime_pisca = k.DajAutora();
            Zanr = k.DajZanr();
            Godina_izdavanja = k.DajGodinuIzdavanja();
            Korisnik *k1 = new Korisnik(*(k.DajKodKogaJe()));
            p = k1;
            return *this;
        }
        std::string DajNaslov(){ return Naslov;}
        std::string DajAutora(){ return Ime_pisca;}
        std::string DajZanr() { return Zanr;}
        int DajGodinuIzdavanja(){ return Godina_izdavanja;}
        Korisnik *DajKodKogaJe(){ return p;}
        void ZaduziKnjigu(Korisnik &k){ p=&k;}
        void RazduziKnjigu() { p = nullptr;}
        bool DaLiJeZaduzena(){
            if(p==nullptr)  return false;
            else return true;
        }
};
void IspisiKnjigu(Knjiga &k){
    std::cout<<"Naslov: "<<k.DajNaslov()<<std::endl;
    std::cout<<"Pisac: "<<k.DajAutora()<<std::endl;
    std::cout<<"Zanr: "<<k.DajZanr()<<std::endl;
    std::cout<<"Godina izdavanja: "<<k.DajGodinuIzdavanja()<<std::endl;
}
class Biblioteka {
    private:
        std::map<int, std::shared_ptr<Korisnik>> korisnici;
        std::map<int, std::shared_ptr<Knjiga>> knjige;
    public:
    
        ~Biblioteka() {
        auto it1 = korisnici.begin();
        while(it1!=korisnici.end()) {
            it1->second=nullptr; 
            it1++;
        }
        auto it2 = knjige.begin();
        while(it2!=knjige.end()) {
            it2->second=nullptr;
            it2++;
        }
        }
        
        Biblioteka &operator = (const Biblioteka &b1) {
            if(&b1==this)    
                return *this;
            auto it1 = b1.korisnici.begin();
            if(korisnici.size() != 0)
            korisnici.erase(korisnici.begin(), korisnici.end());
            if(knjige.size() !=0)
            knjige.erase(knjige.begin(),knjige.end());
            //auto it2 = korisnici.begin();
            while(it1!=b1.korisnici.end()){
                int sifra = it1->first;
                Korisnik p(it1->second->ime,it1->second->prezime,it1->second->adresa, it1->second->telefon);
                std::shared_ptr<Korisnik> k = std::make_shared<Korisnik>(p);
                korisnici.insert(std::make_pair(sifra, k));
                it1++;
            }
            auto it3 = b1.knjige.begin();
            while(it3 != b1.knjige.end()) {
                auto it4 = korisnici.begin();
                int sifra = it3->first;
                auto k = std::make_shared<Knjiga>(it3->second->DajNaslov(),it3->second->DajAutora(),it3->second->DajZanr(),it3->second->DajGodinuIzdavanja());
                while(it4!=korisnici.end()){
                    if(k->DaLiJeZaduzena() == true)
                    if((it4->second)->ime == k->DajKodKogaJe()->ime && (it4->second)->prezime ==k->DajKodKogaJe()->prezime  && (it4->second)->adresa == k->DajKodKogaJe()->adresa && (it4->second)->telefon == k->DajKodKogaJe()->telefon) 
                    k->ZaduziKnjigu(*(it4->second));
                    it4++;
                }
                knjige.insert(std::make_pair(sifra,k));
                it3++;
            }
            return *this;
        }
        void RegistrirajNovogKorisnika (int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
            Korisnik p(ime,prezime,adresa,telefon);
            if (korisnici.find(clanski_broj) == korisnici.end()){
                std::shared_ptr<Korisnik> k = std::make_shared<Korisnik>(p);
                k->ime=ime;
                k->prezime=prezime; 
                k->adresa=adresa; 
                k->telefon=telefon;
                korisnici.insert(std::make_pair(clanski_broj,k));
                //korisnici.insert(std::pair<int, Korisnik*>(clanski_broj,k));
            }
            else{
                throw std::logic_error("Korisnik vec postoji");
            }
        }
        void RegistrirajNovuKnjigu (int evidencijski_broj, std::string naslov, std::string ime_pisca, std::string zanr, int godina){
            if(knjige.find(evidencijski_broj) == knjige.end()){
                auto k = std::make_shared<Knjiga>(naslov, ime_pisca, zanr, godina);
                knjige.insert(std::make_pair(evidencijski_broj,k));
            }
            else{
                throw std::logic_error("Knjiga vec postoji");
            }
        }
        Korisnik &NadjiKorisnika (int clanski_broj){
            auto it = korisnici.begin();
            it = korisnici.find(clanski_broj);
            if(it==korisnici.end())
                throw std::logic_error("Korisnik nije nadjen");
            else return *korisnici.find(clanski_broj)->second;
        }
        Knjiga &NadjiKnjigu (int evidencijski_broj){
            auto it = knjige.begin();
            it = knjige.find(evidencijski_broj);
            if(it == knjige.end()) throw std::logic_error("Korisnik nije nadjen");
            else return *knjige.find(evidencijski_broj)->second;
        }
        void IzlistajKorisnike(){
            auto it = korisnici.begin();
            while(it!=korisnici.end()){
                std::cout<<"Clanski broj: "<<it->first<<std::endl;
                IspisiKorisnika(*it->second);
                it++;
                std::cout<<std::endl<<std::endl;
            }
        }
        void IzlistajKnjige () const{
            auto it = knjige.begin();
            while (it!=knjige.end()){
                std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
                IspisiKnjigu(*it->second);
                if(((*it).second)->DaLiJeZaduzena() == true){
                    std::cout<<"Zaduzena kod korisnika: "<<((*it).second)->DajKodKogaJe()->ime<<" "<<((*it).second)->DajKodKogaJe()->prezime<<std::endl;
                }
                it++;
                std::cout<<std::endl<<std::endl;
            }
        }
        void ZaduziKnjigu(int evidencijski_broj, int clanski_broj){
            auto it1 = knjige.find(evidencijski_broj);
            auto it2 = korisnici.find(clanski_broj);
            if(it1==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
            else if(it2==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
            else if(((*it1).second)->DaLiJeZaduzena()==true) throw std::logic_error("Knjiga vec zaduzena");
            else 
                ((*it1).second)->ZaduziKnjigu(*(it2->second));
        }
        void RazduziKnjigu(int evidencijski_broj){
            auto it1 = knjige.find(evidencijski_broj);
            if(it1==knjige.end()) throw std::logic_error ("Knjiga nije nadjena");
            else if (((*it1).second)->DaLiJeZaduzena()==false) throw std::logic_error("Knjiga nije zaduzena");
            else ((*it1).second)->RazduziKnjigu();
        }
      void PrikaziZaduzenja(int clanski_broj) const {
            auto i = korisnici.find(clanski_broj);
    if(i == korisnici.end())
        throw std::domain_error("Korisnik nije nadjen");
    
    bool ima = false;
    for(auto j : knjige)
    {
        if(j.second->DajKodKogaJe() != nullptr && i->second->ime == j.second->DajKodKogaJe()->ime && i->second->prezime == j.second->DajKodKogaJe()->prezime
            && i->second->adresa == j.second->DajKodKogaJe()->adresa && i->second->telefon == j.second->DajKodKogaJe()->telefon);
        {
            ima = true;
            std::cout << "Evidencijski broj: " << j.first << std::endl;
            std::cout << "Naslov: " << j.second->DajNaslov() << std::endl;
            std::cout << "Pisac: " << j.second->DajAutora() << std::endl;
            std::cout << "Zanr: " << j.second->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << j.second->DajGodinuIzdavanja() << std::endl << std::endl;
        }
    }
    if(ima == false)
        std::cout << "Nema zaduzenja za tog korisnika!";
}
};
int main ()
{
   Biblioteka b = Biblioteka();
   b.RegistrirajNovogKorisnika(5, "Ilma", "Spahic", "Malta 1", "061741743");
  b.RegistrirajNovogKorisnika(4,"Ilm", "Spahi", "Malta", "061741743");
   b.RegistrirajNovuKnjigu(3,"Proces", "Kafka", "Roman", 1999);
   b.ZaduziKnjigu(3,5);
  b.PrikaziZaduzenja(5);
  b.RazduziKnjigu(3);
  //b.ZaduziKnjigu(3,5);
  b.PrikaziZaduzenja(4);
  //b1.PrikaziZaduzenja(5);
   return 0;
}
