/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
    
};

class Knjiga{
    std::string naslov, pisac, zanr;
    int godina;
    Korisnik* zaduzenje;
    
    public:
        Knjiga(std::string Naslov, std::string Pisac, std::string Zanr, int Godina){
            naslov=Naslov;
            pisac=Pisac;
            zanr=Zanr;
            godina=Godina;
            zaduzenje=nullptr;
        }
        std::string DajNaslov() const{ return naslov; }
        std::string DajAutora() const{ return pisac; }
        std::string DajZanr() const{ return zanr; }
        int DajGodinuIzdavanja() const{ return godina; }
        Korisnik* DajKodKogaJe() const{ return zaduzenje; }
        
        void ZaduziKnjigu(Korisnik &hoceDaZaduzi){
            zaduzenje=&hoceDaZaduzi;
        }
        void RazduziKnjigu(){
            zaduzenje=nullptr;
        }
        bool DaLiJeZaduzena(){
            if(zaduzenje==nullptr) return false;
            return true;
        }
};

class Biblioteka{
    std::map<int, Korisnik*> mapaKorisnika;
    std::map<int, Knjiga*> mapaKnjiga;
    
    public:
        Biblioteka(){}
        //kopirajuci kontruktor
        Biblioteka(const Biblioteka &b){
            for(auto it=b.mapaKorisnika.begin();it!=b.mapaKorisnika.end();it++){
              mapaKorisnika[it->first]=new Korisnik(*(it->second));
            }
        }
        //pomjerajuci konstruktor
        Biblioteka(Biblioteka &&b){
            mapaKorisnika=b.mapaKorisnika;
            mapaKnjiga=b.mapaKnjiga;
        }
        //kopirajuci operator dodjele
        Biblioteka &operator =(const Biblioteka &b){
            if(this==&b) return *this;
            for(auto it=mapaKorisnika.begin();it!=mapaKorisnika.end();it++){
                delete it->second;
                mapaKorisnika.erase(it);
            }
            for(auto it=b.mapaKorisnika.begin();it!=b.mapaKorisnika.end();it++){
              mapaKorisnika[it->first]=new Korisnik(*(it->second));
            }
            return *this;
        }
        //pomjerajuci operator dodjele
        Biblioteka &operator =(Biblioteka &&b){
            std::swap(mapaKorisnika, b.mapaKorisnika);
            std::swap(mapaKnjiga, b.mapaKnjiga);
            return *this;
        }
        ~Biblioteka(){
            for(auto it=mapaKorisnika.begin();it!=mapaKorisnika.end();it++){
                delete it->second;
            }
            for(auto it=mapaKnjiga.begin();it!=mapaKnjiga.end();it++){
                delete it->second;
            }
        }
        void RegistrirajNovogKorisnika(int clanskiBroj, std::string Ime, std::string Prezime, std::string Adresa, std::string brojTelefona){
            for(auto it=mapaKorisnika.begin();it!=mapaKorisnika.end();it++){
                if(it->first==clanskiBroj) throw std::logic_error("Korisnik vec postoji");
            }
            Korisnik *k=new Korisnik{Ime, Prezime, Adresa, brojTelefona};
            mapaKorisnika[clanskiBroj]=k;
            
            
        }
        void RegistrirajNovuKnjigu(int evidencijskiBroj, std::string Naslov, std::string imePisca, std::string Zanr, int godinaIzdavanja){
            for(auto it=mapaKnjiga.begin();it!=mapaKnjiga.end();it++){
                if(it->first==evidencijskiBroj) throw std::logic_error("Knjiga vec postoji");
            }
            Knjiga *k=new Knjiga(Naslov, imePisca, Zanr, godinaIzdavanja);
            mapaKnjiga[evidencijskiBroj]=k;
            
        }
        Korisnik &NadjiKorisnika(int clanskiBroj){
            for(auto it=mapaKorisnika.begin();it!=mapaKorisnika.end();it++){
                if(it->first==clanskiBroj){
                    return *(it->second);
                }
            }
            throw std::logic_error("Korisnik nije nadjen");
        }
        Knjiga &NadjiKnjigu(int evidencijskiBroj){
            for(auto it=mapaKnjiga.begin();it!=mapaKnjiga.end();it++){
                if(it->first==evidencijskiBroj){
                    return *(it->second);
                }
            }
            throw std::logic_error("Knjiga nije nadjena");
        }
        void IzlistajKorisnike(){
            for(auto it=mapaKorisnika.begin();it!=mapaKorisnika.end();it++){
                std::cout<<"Clanski broj: "<<it->first<<std::endl;
                std::cout<<"Ime i prezime: "<<(*(it->second)).ime<<" "<<(*(it->second)).prezime<<std::endl;
                std::cout<<"Adresa: "<<(*(it->second)).adresa<<std::endl;
                std::cout<<"Broj telefona: "<<(*(it->second)).telefon;
                std::cout<<std::endl;
            }
        }
        void IzlistajKnjige(){
            for(auto it=mapaKnjiga.begin();it!=mapaKnjiga.end();it++){
                std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
                std::cout<<"Naslov: "<<(*(it->second)).DajNaslov()<<std::endl;
                std::cout<<"Pisac: "<<(*(it->second)).DajAutora()<<std::endl;
                std::cout<<"Zanr: "<<(*(it->second)).DajZanr()<<std::endl;
                std::cout<<"Godina izdavanja: "<<(*(it->second)).DajGodinuIzdavanja()<<std::endl;
                if(it->second->DaLiJeZaduzena())
                    std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime;
                std::cout<<std::endl;
            }
        }
        
        void ZaduziKnjigu(int evidencijskiBroj, int clanskiBroj){
          
          auto p=mapaKnjiga.find(evidencijskiBroj);
          auto t=mapaKorisnika.find(clanskiBroj);
          if(p==mapaKnjiga.end()) throw std::logic_error("Knjiga nije nadjena");
          if(t==mapaKorisnika.end()) throw std::logic_error("Korisnik nije nadjen");
          if(p->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena"); 
          p->second->ZaduziKnjigu(*(t->second));
          
          
        }
        void RazduziKnjigu(int evidencijskiBroj){
            auto p=mapaKnjiga.find(evidencijskiBroj);
            if(p==mapaKnjiga.end()) throw std::logic_error("Knjiga nije nadjena");
            if(p->second->DaLiJeZaduzena()==false) throw std::logic_error("Knjiga nije zaduzena");
            (*(p->second)).RazduziKnjigu();
        }
        void PrikaziZaduzenja(int clanskiBroj){
            auto t=mapaKorisnika.find(clanskiBroj);
            if(t->second==nullptr) throw std::logic_error("Korisnik nije nadjen");
            int br(0);
            for(auto it=mapaKnjiga.begin();it!=mapaKnjiga.end();it++){
                if((*(it->second)).DajKodKogaJe()==t->second){br++; IzlistajKnjige();}
            }
            if(br==0) std::cout<<"Nema zaduzenja za tog korisnika!"<<std::endl;
        }
        
};


int main ()
{
    
    
	return 0;
}