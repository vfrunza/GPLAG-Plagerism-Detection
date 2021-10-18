/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <new>
#include <algorithm>
#include <stdexcept>

using std::string;
using std::map;

struct Korisnik{
   string ime;
   string prezime;
   string adresa;
   string telefon;
};

class Knjiga{
    string naslov;
    string ime_pisca;
    string zanr;
    int godina_izdanja;
    Korisnik *kor_knjige;
   
    
    public:
   // Korisnik *kor_knjige;
    Knjiga(string nasl,string ime,string znr,int god): naslov(nasl),ime_pisca(ime),zanr(znr),godina_izdanja(god),kor_knjige(nullptr){}
    string DajNaslov()const {return naslov;}
    string DajAutora()const {return ime_pisca;}
    string DajZanr()const {return zanr;}
    int DajGodinuIzdavanja()const {return godina_izdanja;}
    Korisnik *DajKodKogaJe()const {return kor_knjige;}
    
    void ZaduziKnjigu(Korisnik &k){kor_knjige=&k;}   //da li treba alocirat novi pok pa postavi na njeg ?
    void RazduziKnjigu(){kor_knjige=nullptr;}
    bool DaLiJeZaduzena()const { if(kor_knjige)return true; else return false; }
    
};

class Biblioteka{
    map<int,std::shared_ptr<Korisnik>> korisnici;
    map<int,std::shared_ptr<Knjiga>> knjige;
    /*
    void DealocirajKorisnike(){
        for(auto it=korisnici.begin();it != korisnici.end();it++)delete it->second;
    }
    
    void DealocirajKnjige(){
        for(auto it=knjige.begin();it != knjige.end();it++)delete it->second;
    }
    */
    static void IspisiKorisnika(const Korisnik &k,int clanski_broj){
        std::cout<<"Clanski broj: "<<clanski_broj<<std::endl;
        std::cout<<"Ime i prezime: "<<k.ime<<" "<<k.prezime<<std::endl;
        std::cout<<"Adresa: "<<k.adresa<<std::endl;
        std::cout<<"Broj telefona: "<<k.telefon<<std::endl;
        
    }
    
    static void IspisiKnjigu(const Knjiga &k,int evid_broj,bool dodatno=true){
        std::cout<<"Evidencijski broj: "<<evid_broj<<std::endl;
        std::cout<<"Naslov: "<<k.DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<k.DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<k.DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<k.DajGodinuIzdavanja()<<std::endl;
        if(k.DaLiJeZaduzena() && dodatno){
            Korisnik *p(k.DajKodKogaJe());
            std::cout<<"Zaduzena kod korisnika: "<<p->ime<<" "<<p->prezime<<std::endl;   
        }
    }
    
    public:
    Biblioteka()=default;
    ~Biblioteka() =default;
    //kopirajuci i pomjerajuci konstruktor
    Biblioteka (const Biblioteka &b);
    Biblioteka (Biblioteka &&b);
    
    //kopirajuci i pomjerajuci operator dodjele
    Biblioteka &operator= (const Biblioteka &b);
    Biblioteka &operator= (Biblioteka &&b){
        std::swap(korisnici,b.korisnici);
        std::swap(knjige,b.knjige);
        return *this;
    }
    
    void RegistrirajNovogKorisnika(int clanski_broj,string ime,string prezime,string adresa,string telefon);
    void RegistrirajNovuKnjigu(int evid_broj,string naslov,string ime_pisca,string zanr,int godina_izdanja);
    Korisnik &NadjiKorisnika(int clanski_broj)const ;
    Knjiga &NadjiKnjigu(int evid_broj)const ;
    
    void IzlistajKorisnike()const {
        for(auto it=korisnici.begin();it != korisnici.end();it++){
            IspisiKorisnika(*(it->second),it->first);
            std::cout<<std::endl;
        }
    }
    
    void IzlistajKnjige()const {
        
        for(auto it=knjige.begin();it != knjige.end();it++){
            IspisiKnjigu(*(it->second),it->first);
            std::cout<<std::endl;
        }
    }
    
    //IZMJENE VRSENE OVDJE
    /*
    void ZaduziKnjigu(int evid_broj,int clanski_broj){
        auto it(knjige.find(evid_broj));
        if(it == knjige.end())throw std::logic_error("Knjiga nije nadjena");
        auto it2(korisnici.find(clanski_broj));
        if(it2 == korisnici.end())throw std::logic_error("Korisnik nije nadjen");
    
        
        if(k.DaLiJeZaduzena()){
            throw std::logic_error("Knjiga vec zaduzena");
        }else{
            Korisnik p=NadjiKorisnika(clanski_broj);
            k.ZaduziKnjigu(p);
        }
        
        
    }*/
    
     void ZaduziKnjigu(int broj_knjige,int broj_korisnika){
         if( !knjige.count(broj_knjige)) throw std::logic_error("Knjiga nije nadjena");
         if( !korisnici.count(broj_korisnika)) throw std::logic_error("Korisnik nije nadjen");
         auto it_knjiga(knjige.find(broj_knjige));
         auto it_korisnik(korisnici.find(broj_korisnika));
         if(it_knjiga->second->DaLiJeZaduzena())throw std::logic_error("Knjiga vec zaduzena");
         it_knjiga->second->ZaduziKnjigu(*(it_korisnik->second));
     }
    
    
    
    void RazduziKnjigu(int evid_broj) {
        auto it(knjige.find(evid_broj));
        if(it == knjige.end())throw std::logic_error("Knjiga nije nadjena");
        Knjiga k=NadjiKnjigu(evid_broj);                                         //da li brisat ??
        if(k.DaLiJeZaduzena()==false){
            throw std::logic_error("Knjiga nije zaduzena");
        }else{
            k.RazduziKnjigu();
        }
    }
    
    void PrikaziZaduzenja(int clanski_broj)const {
        auto it2(korisnici.find(clanski_broj));
        if(it2 == korisnici.end())throw std::domain_error("Korisnik nije nadjen");
        Korisnik kr=*(it2->second);//da li brisat ??
        int brojac=0;
        for(auto it=knjige.begin();it != knjige.end();it++){
                if(&(*it->second->DajKodKogaJe())== &kr){
                    IspisiKnjigu(*(it->second),it->first,false);
                    brojac++;
                }
        }
        if(brojac==0)std::cout<<"Nema zaduzenja za tog korisnika!"<<std::endl;
    }
    
};

//copy konstruktor
Biblioteka::Biblioteka(const Biblioteka &b){
    bool uspjela_alokacija(true);
    
    try{
        for(auto it=b.korisnici.begin();it != b.korisnici.end();it++){
            korisnici.insert(std::make_pair(it->first, std::make_shared<Korisnik>(Korisnik(*(it->second) ))));
        }
    }catch(...){
       // DealocirajKorisnike();
        uspjela_alokacija=false;
    }
    
    if(uspjela_alokacija){
        
        try{
            for(auto it=b.knjige.begin();it != b.knjige.end();it++){
                knjige.insert(std::make_pair(it->first, std::make_shared<Knjiga>(Knjiga(*(it->second) ))));
            }
        }catch(...){
           // DealocirajKorisnike();
            //DealocirajKnjige();
        }
    }
}

//pomjerajuci konstruktor
Biblioteka::Biblioteka(Biblioteka &&b){
    for(auto it=b.korisnici.begin();it != b.korisnici.end();it++){
            korisnici.insert(std::make_pair(it->first, it->second));
            it->second = nullptr;
    }
    
    for(auto it=b.knjige.begin();it != b.knjige.end();it++){
                knjige.insert(std::make_pair(it->first, it->second));
                it->second = nullptr;
    }
}

//kopirajuci operator dodjele
Biblioteka &Biblioteka::operator= (const Biblioteka &b){
    //broj knjiga i broj korisnika ne mora bit isti zato radimo 2 slucaja
        
        //odlucit cemo se za varijantu da nas nije briga jel vec ima dovoljno alocirane memorije tj vrsit cemo potpuno alokaciju !
        int uspjela_alokacija(true);
        map<int,std::shared_ptr<Korisnik>> nova_mapa;
        try{
            for(auto it=b.korisnici.begin();it != b.korisnici.end();it++){
               // nova_mapa.insert(std::make_pair(it->first, std::make_shared<Korisnik>(Korisnik(*(it->second) )) ) );
               //nova_mapa.insert(std::make_pair( it->first, std::make_shared<Korisnik>(Korisnik(*(it->second))) )    );
             // nova_mapa.insert(it->first, std::make_shared<Korisnik> (*(it->second)));
                nova_mapa.insert(std::make_pair(it->first, std::make_shared<Korisnik> (*(it->second)) ));
            }
        }catch(...){
          //  for(auto it=nova_mapa.begin();it != nova_mapa.end();it++)delete it->second;
            uspjela_alokacija=false;
        }
        
        //ako je prosla prva alokacija
        if(uspjela_alokacija){
            map<int,std::shared_ptr<Knjiga>> nove_knjige;
            try{
                for(auto it=b.knjige.begin();it != b.knjige.end();it++){
                    nove_knjige.insert(std::make_pair(it->first, std::make_shared<Knjiga> ( Knjiga(*(it->second) ))) );
                }
            }catch(...){
               // for(auto it=nove_knjige.begin();it != nove_knjige.end();it++)delete it->second;
                //for(auto it=nova_mapa.begin();it != nova_mapa.end();it++)delete it->second;
                uspjela_alokacija=false;
            }
            
            //ako je sve proslo kako treba zavrsavamo alokacije
            if(uspjela_alokacija){
               // this->DealocirajKorisnike();
                //this->DealocirajKnjige();
                //krademo resurese od novamapa i noveknjige
                std::swap(korisnici,nova_mapa);
                std::swap(knjige,nove_knjige);
               
            }
        }
        
         return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj,string ime,string prezime,string adresa,string telefon){
    auto it(korisnici.find(clanski_broj));
    if(it != korisnici.end())throw std::logic_error("Korisnik vec postoji");
    korisnici.insert(std::make_pair(clanski_broj,std::make_shared<Korisnik>(Korisnik{ime,prezime,adresa,telefon}))  ); //ne moze Korisnik() jer nema konstuktora u strukturi
}

void Biblioteka::RegistrirajNovuKnjigu(int evid_broj,string naslov,string ime_pisca,string zanr,int godina_izdanja){
    auto it(knjige.find(evid_broj));
    if(it != knjige.end())throw std::logic_error("Knjiga vec postoji");
    knjige.insert(std::make_pair(evid_broj,std::make_shared<Knjiga>(Knjiga(naslov,ime_pisca,zanr,godina_izdanja)))); 
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj)const {
    auto it(korisnici.find(clanski_broj));
    if(it == korisnici.end())throw std::logic_error("Korisnik nije nadjen");
    return *it->second;
}

Knjiga &Biblioteka::NadjiKnjigu(int evid_broj)const {
    auto it(knjige.find(evid_broj));
    if(it == knjige.end())throw std::logic_error("Knjiga nije nadjena");
    return *it->second;
}


int main(){
    Biblioteka bib8;
bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
bib8.ZaduziKnjigu(2, 1);
bib8.IzlistajKnjige();
    return 0;
}