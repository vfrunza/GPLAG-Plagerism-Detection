#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <vector>
#include <cstring>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdanja;
    Korisnik* zaduzenik;
    public:
    Knjiga(std::string title, std::string name,std::string genre, int godina) {
        naslov=title; ime_pisca=name; zanr=genre; godina_izdanja=godina; 
        zaduzenik=nullptr;
    }
    std::string DajNaslov() const {return naslov;}
    std::string DajAutora() const {return ime_pisca;}
    std::string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdanja;}
    Korisnik* DajKodKogaJe() const {return zaduzenik;}
    void ZaduziKnjigu(Korisnik &neko) {
        zaduzenik=&neko;
    }
    void RazduziKnjigu()  {
        zaduzenik=nullptr;
    }
    bool DaLiJeZaduzena() const {
        return zaduzenik!=nullptr;
    }
};
class Biblioteka{
    std::map<int, Knjiga*> knjige;
    std::map<int, Korisnik*> korisnici;
    public:
    Biblioteka() {}
    Biblioteka(std::map<int, Knjiga*> mapa1, std::map <int, Korisnik*> mapa2){
        knjige=mapa1;
        korisnici=mapa2;
    }
    Biblioteka(std::map<int, Korisnik*> mapa1, std::map<int, Knjiga*> mapa2) {
        korisnici=mapa1;
        knjige=mapa2;
    } 
    Biblioteka (const Biblioteka &b) {
        *this=b;
    }
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime,
    std::string adresa, std::string br_tel) {
        for(auto i=korisnici.begin(); i!=korisnici.end(); i++) {
            if(clanski_broj==i->first) throw std::logic_error("Korisnik vec postoji");
        }
        korisnici.insert(std::make_pair(clanski_broj, new Korisnik {ime, prezime, adresa, br_tel}));
    }
    void RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdanja){
        for(auto i=knjige.begin(); i!=knjige.end(); i++) if(evidencijski_broj==i->first) throw std::logic_error("Knjiga vec postoji");
        knjige.insert(std::make_pair(evidencijski_broj, new Knjiga(naslov, ime_pisca, zanr, godina_izdanja)));
    }
     Korisnik &NadjiKorisnika(int clanski_broj) const {
        for(auto i=korisnici.begin(); i!=korisnici.end(); i++) if(clanski_broj==i->first) return *(i->second);
        throw std::logic_error("Korisnik nije nadjen");
    }
    Knjiga &NadjiKnjigu(int evidencijski_broj) const {
        for(auto i=knjige.begin(); i!=knjige.end(); i++){
            if(evidencijski_broj==i->first) return *(i->second);
        }throw std::logic_error("Knjiga nije nadjena");
    }
    ~Biblioteka(){
        for(auto i=knjige.begin(); i!=knjige.end(); i++) delete i->second;
        for(auto i=korisnici.begin(); i!=korisnici.end(); i++) delete i->second;
    }
    void IzlistajKorisnike() const {
        for(auto i=korisnici.begin(); i!=korisnici.end(); i++) {
            std::cout<<"Clanski broj: "<<i->first<<std::endl;;
            std::cout<<"Ime i prezime: "<<(i->second)->ime<<" "<<(i->second)->prezime<<std::endl;
            std::cout<<"Adresa: "<<(i->second)->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<(i->second)->telefon<<std::endl;
            std::cout<<std::endl;
        }
    }
    void IzlistajKnjige() const {
        for(auto i=knjige.begin(); i!=knjige.end(); i++) {
            std::cout<<"Evidencijski broj: "<<i->first<<std::endl;
            std::cout<<"Naslov: "<<(i->second)->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<(i->second)->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<(i->second)->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<(i->second)->DajGodinuIzdavanja()<<std::endl;
            if((i->second)->DajKodKogaJe()!=nullptr) std::cout<<"Zaduzena kod korisnika: "<<((i->second)->DajKodKogaJe())->ime<<" "<<((i->second)->DajKodKogaJe())->prezime<<std::endl;
            std::cout<<std::endl;
        }
    }
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj) {
        bool ima_li_knjige=false, ima_li_korisnika=false;
        for(auto i=knjige.begin(); i!=knjige.end(); i++) {
            if(i->first==evidencijski_broj) {ima_li_knjige=true;
            break;} 
        }
        if(!ima_li_knjige) throw std::logic_error("Knjiga nije nadjena");
        for(auto i=korisnici.begin(); i!=korisnici.end(); i++) {
            if(i->first==clanski_broj) {
                ima_li_korisnika=true;
                break;
            }
        } if(!ima_li_korisnika) throw std::logic_error("Korisnik nije nadjen");
        if(knjige[evidencijski_broj]->DajKodKogaJe()!=nullptr) throw std::logic_error("Knjiga vec zaduzena");
        knjige[evidencijski_broj]->ZaduziKnjigu(*(korisnici[clanski_broj]));
    }
    void RazduziKnjigu(int evidencijski_broj) {
        bool ima_li_knjige=false;
        for(auto i=knjige.begin(); i!=knjige.end(); i++) {
            if(evidencijski_broj==i->first) {ima_li_knjige=true;
            break;}
        } if(!ima_li_knjige) throw std::logic_error("Knjiga nije nadjena");
        if((knjige[evidencijski_broj])->DajKodKogaJe()==nullptr) throw std::logic_error("Knjiga nije zaduzena");
        knjige[evidencijski_broj]->RazduziKnjigu();
    }
    
    void PrikaziZaduzenja(int clanski_broj) {
        bool ima_li_korisnika=false;
        for(auto i=korisnici.begin(); i!=korisnici.end(); i++) {
            if(i->first==clanski_broj) {ima_li_korisnika=true;
                break;
            }
        } if(!ima_li_korisnika) throw std::logic_error("Korisnik nije nadjen");
        std::vector<int> indeksi(0);
        auto ko_je_taj_korisnik=korisnici[clanski_broj];
        for(auto i=knjige.begin(); i!=knjige.end(); i++) {
            if(ko_je_taj_korisnik == (i->second)->DajKodKogaJe())  {
                indeksi.push_back(i->first);
            }
        } if(indeksi.size()==0) throw std::logic_error("Nema zaduzenja za tog korisnika!");
       for(auto i=knjige.begin(); i!=knjige.end(); i++) {
           for(int j=0; j<indeksi.size(); j++) {
               if(i->first==indeksi[j]){
                   std::cout<<"Evidencijski broj: "<<indeksi[j]<<std::endl;
                   std::cout<<"Naslov: "<<(i->second)->DajNaslov()<<std::endl;
                   std::cout<<"Pisac: "<<(i->second)->DajAutora()<<std::endl;
                   std::cout<<"Zanr: "<<(i->second)->DajZanr()<<std::endl;
                   std::cout<<"Godina izdavanja: "<<(i->second)->DajGodinuIzdavanja()<<std::endl;
                   std::cout<<std::endl;}
           }
       }
    }
};

int main ()
{
    Biblioteka B;
    std::string unos;
    while(unos!=".") {
        std::cout<<"Odaberite: 1 za unos novog korisnika, 2 za registraciju knjige, 3 za pronalazak korisnika po sifri,\n";
        std::cout<<"4 za pronalazak knjige po evidencijskom broju, 5 za prikaz korisnika, 6 za prikaz knjiga, 7 za zaduzivanje knjige,\n";
        std::cout<<"8 za razduzivanje knjige, 9 za prikaz zaduzenja korisnika, \".\" za kraj: ";
        std::cin>>unos;
        if(unos=="1") {
            int broj;
            std::string ime, prezime, adresa, brtel;
            std::cout<<"Unesite podatke o korisniku (clanski broj, ime, prezime, adresu i telefon: ";
            std::cin>>broj>>ime>>prezime>>adresa>>brtel;
            B.RegistrirajNovogKorisnika(broj, ime, prezime, adresa, brtel);
        }
        if(unos=="2") {
            int evid_br, god_izdanja;
            std::string naslov, autor, zanr;
            std::cout<<"Unesite podatke o knjizi redom: evidencijski broj, naslov, ime i prezime autora, zanr, godinu izdanja: ";
            std::cin>>evid_br;
            std::getline(std::cin,naslov);
            std::getline(std::cin, autor);
            std::getline(std::cin, zanr);
            std::cin>>god_izdanja;
            B.RegistrirajNovuKnjigu(evid_br, naslov, autor, zanr, god_izdanja);
        }
        if(unos=="3") {
            std::cout<<"Unesite clanski broj: ";
            int br;
            std::cin>>br;
            try{
            auto k=B.NadjiKorisnika(br);
                std::cout<<"Korisnik se zove: "<<k.ime<<" "<<k.prezime;
            }
            catch(std::logic_error e) {std::cout<<e.what();}
            }
            if(unos=="4"){
                std::cout<<"Unesite evidencijski broj knjige: ";
                int br;
                std::cin>>br;
                try{
                    std::cout<<"Rado se o knjizi: "<<  B.NadjiKnjigu(br).DajNaslov()<<std::endl;
                } catch(std::logic_error e) {
                    std::cout<<e.what();
                }
            } 
            if(unos=="5") {B.IzlistajKorisnike();}
            if(unos=="6") B.IzlistajKnjige();
            if(unos=="7") {
                int br1, br2;
                std::cout<<"Unesite redom evidencijski broj knjige i clanski broj korisnika: ";
                std::cin>>br1>>br2;
                try{
                    B.ZaduziKnjigu(br1, br2);
                }catch(std::logic_error e) {std::cout<<e.what();}
            }
            if(unos=="8") {
                int br1;
                std::cout<<"Unesite redom evidencijski broj knjige: ";
                std::cin>>br1;
                try{
                 B.RazduziKnjigu(br1);   
                }catch(std::logic_error e) {
                    std::cout<<e.what();
                }
            }
            if(unos=="9") {
                int br;
                std::cout<<"Unesite clanski broj korisnika: ";
                std::cin>>br;
                try{
                B.PrikaziZaduzenja(br);} catch(std::logic_error e) {std::cout<<e.what();}
            }
            }
        
	return 0;
}


