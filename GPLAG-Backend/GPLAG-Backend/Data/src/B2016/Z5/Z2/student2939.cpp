/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga{
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* info;
    public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja): naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), info(nullptr){}
    std::string DajNaslov() const {return naslov;}
    std::string DajAutora() const {return ime_pisca;}
    std::string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdavanja;}
    Korisnik* DajKodKogaJe() const {return info;}
    void ZaduziKnjigu(Korisnik &lik) {info=&lik;}
    void RazduziKnjigu() {info=nullptr;}
    bool DaLiJeZaduzena() {if(!info) return false; return true;}
};

Korisnik KopirajKorisnika(const Korisnik &k){
    auto pok(std::make_shared<Korisnik>());
    pok->ime=k.ime;
    pok->prezime=k.prezime;
    pok->adresa=k.adresa;
    pok->telefon=k.telefon;
    return *pok;
}

Knjiga KopirajKnjigu(const Knjiga &k){
    auto pok(std::make_shared<Knjiga>(k.DajNaslov(), k.DajAutora(), k.DajZanr(), k.DajGodinuIzdavanja()));
    return *pok;
}

std::shared_ptr<Korisnik> Kopirajkorisnik(std::shared_ptr<Korisnik> k1){
    auto k(std::make_shared<Korisnik);
    k->ime=k1->ime;
    k->prezime=k1->prezime;
    k->adresa=k1->adresa;
    k->telefon=k1->telefon;
}

class Biblioteka{
    std::map<int, std::shared_ptr<Korisnik>> mapa_korisnik;
    std::map<int, std::shared_ptr<Knjiga>> mapa_knjiga;
    bool DaLiJeIstiKorisnik(Korisnik* p1, Knjiga* p2){
        if(p1->ime==p2->DajKodKogaJe()->ime && p1->prezime==p2->DajKodKogaJe()->prezime && p1->adresa==p2->DajKodKogaJe()->adresa && p1->telefon==p2->DajKodKogaJe()->telefon)
            return true;
        return false;
    }
    public:
    Biblioteka(){}
    Biblioteka(Biblioteka &&b){
        std::swap(mapa_korisnik, b.mapa_korisnik);
        std::swap(mapa_knjiga, b.mapa_knjiga);
    /*    for(auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++)
        {
            (*it).second->RazduziKnjigu();
            (*it).second=nullptr;
        }
        for(auto it=b.mapa_korisnik.begin(); it!=b.mapa_korisnik.end(); it++)
            (*it).second=nullptr;*/
    }
    Biblioteka &operator= (const Biblioteka &b){
        for(auto it=mapa_korisnik.begin(); it!=mapa_korisnik.end(); it++)
             (*it).second=nullptr;
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
             (*it).second=nullptr;
        }
        for(auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++){
            auto k=std::make_shared<Knjiga>(KopirajKnjigu(*((*it).second)));
            mapa_knjiga.insert(std::make_pair((*it).first, k));
        }
        for(auto it=b.mapa_korisnik.begin(); it!=mapa_korisnik.end(); it++){
            auto k=std::make_shared<Korisnik> (KopirajKorisnika(*((*it).second)));
            mapa_korisnik.insert(std::make_pair((*it).first, k));
        }
        return *this;
    }
    Biblioteka(const Biblioteka &b){
        for(auto it=b.mapa_korisnik.begin(); it!=b.mapa_korisnik.end(); it++){
            auto k(std::make_shared<Korisnik>(KopirajKorisnika(*(*it).second)));
            mapa_korisnik.insert(std::make_pair((*it).first, k));
        }
        for(auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++){
            auto k=std::make_shared<Knjiga>(KopirajKnjigu(*((*it).second)));
            mapa_knjiga.insert(std::make_pair((*it).first, k));
        }
    }
    Biblioteka &operator=(Biblioteka &&b){
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
             (*it).second=nullptr;
        }
        for(auto it=mapa_korisnik.begin(); it!=mapa_korisnik.end(); it++){
             (*it).second=nullptr;
        }
        std::swap(mapa_knjiga, b.mapa_knjiga);
        std::swap(mapa_korisnik, b.mapa_korisnik);
       /* for(auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++){
            (*it).second->RazduziKnjigu();
            (*it).second=nullptr;
        }
        for(auto it=b.mapa_korisnik.begin(); it!=b.mapa_korisnik.end(); it++)
            (*it).second=nullptr;*/
        return *this;
    }
   /* ~Biblioteka(){
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
            //delete (*it).second->DajKodKogaJe();
            delete (*it).second;
        }
        for(auto it=mapa_korisnik.begin(); it!=mapa_korisnik.end(); it++)
            delete (*it).second;
    }*/
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
        if(mapa_korisnik.count(clanski_broj)) throw std::logic_error("Korisnik vec postoji");
        auto k(std::make_shared<Korisnik>());
        k->ime=ime;
        k->prezime=prezime;
        k->adresa=adresa;
        k->telefon=telefon;
        mapa_korisnik.insert(std::make_pair(clanski_broj, k));
    }
    void RegistrirajNovuKnjigu(int ev_br, std::string naslov, std::string autor, std::string zanr, int godina){
        if(mapa_knjiga.count(ev_br)) throw std::logic_error("Knjiga vec postoji");
        auto k(std::make_shared<Knjiga>(naslov, autor, zanr, godina));
        mapa_knjiga.insert(std::make_pair(ev_br, k));
    }
    Korisnik &NadjiKorisnika(int clanski_broj){
        if(!mapa_korisnik.count(clanski_broj)) throw std::logic_error("Korisnik nije nadjen");
        return *(mapa_korisnik.find(clanski_broj)->second);
    }
    Knjiga &NadjiKnjigu(int broj){
        if(!mapa_knjiga.count(broj)) throw std::logic_error("Knjiga nije nadjena");
        return *(mapa_knjiga.find(broj)->second);
    }
    void IzlistajKorisnike() const{
        for(auto it=mapa_korisnik.begin(); it!=mapa_korisnik.end(); it++){
            std::cout<<"Clanski broj: "<<(*it).first<<std::endl;
            std::cout<<"Ime i prezime: "<<(*it).second->ime<<" "<<(*it).second->prezime<<std::endl;
            std::cout<<"Adresa: "<<(*it).second->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<(*it).second->telefon<<std::endl<<std::endl;
        }
    }
    void IzlistajKnjige() const{
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
            std::cout<<"Evidencijski broj: "<<(*it).first<<std::endl;
            std::cout<<"Naslov: "<<(*it).second->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<(*it).second->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<(*it).second->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<(*it).second->DajGodinuIzdavanja()<<std::endl;
            if((*it).second->DaLiJeZaduzena()) {
                std::cout<<"Zaduzena kod korisnika: "<<(*it).second->DajKodKogaJe()->ime;
                std::cout<<" "<<(*it).second->DajKodKogaJe()->prezime<<std::endl;
            }
            std::cout<<std::endl;
        }
    }
    void ZaduziKnjigu(int br_knjige, int clanski){
        if(!mapa_knjiga.count(br_knjige)) throw std::logic_error("Knjiga nije nadjena");
        if(!mapa_korisnik.count(clanski)) throw std::logic_error("Korisnik nije nadjen");
        if(mapa_knjiga.find(br_knjige)->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
        mapa_knjiga.find(br_knjige)->second->ZaduziKnjigu(*(mapa_korisnik.find(clanski)->second));
    }
    void RazduziKnjigu(int br_knjige){
        if(!mapa_knjiga.count(br_knjige)) throw std::logic_error("Knjiga nije nadjena");
        if(!mapa_knjiga.find(br_knjige)->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
        mapa_knjiga.find(br_knjige)->second->RazduziKnjigu();
    }
    void PrikaziZaduzenja(int clanski_br) const{
        if(!mapa_korisnik.count(clanski_br)) throw std::logic_error("Korisnik nije nadjen");
        bool istina(false);
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
            if((*it).second->DajKodKogaJe()==mapa_korisnik.find(clanski_br)->second.get()){
                istina=true;
                std::cout<<"Evidencijski broj: "<<(*it).first<<std::endl;
                std::cout<<"Naslov: "<<(*it).second->DajNaslov()<<std::endl;
                std::cout<<"Pisac: "<<(*it).second->DajAutora()<<std::endl;
                std::cout<<"Zanr: "<<(*it).second->DajZanr()<<std::endl;
                std::cout<<"Godina izdavanja: "<<(*it).second->DajGodinuIzdavanja()<<std::endl;
            
                std::cout<<std::endl;
            }
        }
        if(!istina) throw std::logic_error("Nema zaduzenja za tog korisnika!");
    }
};/*
int main ()
{
    std::cout<<"Dobro dosli u biblioteku!\n";
    for(;;){
        std::cout<<"Za registraciju korisnika, birajte 1 ~\nZa registraciju knjige, birajte 2 ~\n";
        std::cout<<"Za pronalazak korisnika, birajte 3 ~\nZa pronalazak knjige, birajte 4 ~"<<std::endl;
        std::cout<<"Za prikaz svih korisnika, birajte 5 ~\nZa prikaz svih knjiga, birajte 6 ~"<<std::endl;
        std::cout<<"Za zaduzivanje knjige, birajte 7 ~\nZa razduzivanje knjige, birajte 8 ~"<<std::endl;
        std::cout<<"Za prikaz razduzivanja, birajte 9 ~\nZa kraj, birajte 0 ~"<<std::endl;
        int n;
        std::cin>>n;
        Biblioteka b;
        
            if(n==0)  return 0;
            else if(n==1){ std::cout<<"Unesite clanski broj, ime, prezime, adresu i telefon korisnika, sve u posebnom redu.\n";
                std::string ime, prezime, adresa, telefon;
                int clanski;
                std::cin>>clanski;
                std::cin.ignore(1000,'\n');
                std::getline(std::cin, ime);
                std::getline(std::cin, prezime);
                std::getline(std::cin, adresa);
                std::getline(std::cin, telefon);
                b.RegistrirajNovogKorisnika(clanski, ime, prezime, adresa, telefon);
            }
            else if(n==2){ std::cout<<"Unesite broj knjige, naslov, autora, zanr i godinu izdavanja, sve u zasebnom redu.\n";
                    std::string naslov, autor, zanr;
                    int br_knj, god;
                    std::cin>>br_knj;
                    std::cin.ignore(1000, '\n');
                    std::getline(std::cin, naslov);
                    std::getline(std::cin, autor);
                    std::getline(std::cin, zanr);
                    std::cin>>god;
                    b.RegistrirajNovuKnjigu(br_knj, naslov, autor, zanr, god);
            }
            else if(n==3){
                    std::cout<<"Unesite clanski broj korisnika kojeg zelite naci.\n";
                    int broj;
                    std::cin>>broj;
                    try{
                    Korisnik lik(b.NadjiKorisnika(broj));
                    std::cout<<"Trazili ste korisnika: "<<lik.ime<<" "<<lik.prezime<<", adresa: "<<lik.adresa<<", broj telefona: "<<lik.telefon<<std::endl;}
                    catch(std::logic_error i){
                        std::cout<<i.what()<<std::endl;
                    }
            }
            else if(n==4){ 
                    std::cout<<"Unesite broj knjige koju trazite.\n";
                    int broj1;
                    std::cin>>broj1;
                    try{
                        b.NadjiKnjigu(broj1);
                        std::cout<<"Trazili ste knjigu: "<<b.NadjiKnjigu(broj1).DajNaslov()<<", autora "<<b.NadjiKnjigu(broj1).DajAutora()<<", zanra: "<<b.NadjiKnjigu(broj1).DajZanr()<<", izdatu "<<b.NadjiKnjigu(broj1).DajGodinuIzdavanja()<<std::endl;
                    }catch(std::logic_error i){std::cout<<i.what()<<std::endl;}
            }
            else if(n==5)
                    b.IzlistajKorisnike();

            else if(n==6)
                    b.IzlistajKnjige();
                    
            else if(n==7){
                    std::cout<<"Unesite clanski broj korisnika, i broj knjige koju zaduzuje: ";
                    int br1, br2;
                    std::cin>>br1>>br2;
                    b.ZaduziKnjigu(br1, br2);
            }
            else if(n==8){ std::cout<<"Unesite broj knjige koju zelite razduziti: ";
                    int broj2;
                    std::cin>>broj2;
                    b.RazduziKnjigu(broj2);
            }
            else if(n==9){ std::cout<<"Unesite clanski broj korisnika cije zaduzenje zelite prikazati: ";
                int broj3;
                std::cin>>broj3;
                b.PrikaziZaduzenja(broj3);
            }
            else std::cout<<"Pogresan unos opcije, birajte ponovo."<<std::endl;
        std::cout<<std::endl;
        
    }
	return 0;
}*/