/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <stdexcept>
#include <map>
#include <memory>

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
    int godina_izdavanja;
    std::shared_ptr<Korisnik> zaduzena;
    
    public: 
    
        Knjiga(std::string _naslov, std::string _ime_pisca, std::string _zanr, int _godina_izdavanja) : 
            naslov(_naslov),ime_pisca(_ime_pisca), zanr(_zanr),godina_izdavanja(_godina_izdavanja), zaduzena(nullptr){}

        std::string DajNaslov () const {return naslov;}
        std::string DajAutora () const {return ime_pisca;}
        std::string DajZanr () const {return zanr;}
        int DajGodinuIzdavanja () const {return godina_izdavanja;}
        std::shared_ptr<Korisnik> DajKodKogaJe () const {return zaduzena;}
        
        void ZaduziKnjigu (Korisnik &k){
            zaduzena = std::make_shared<Korisnik>(k);
        }
        void RazduziKnjigu () {
            zaduzena=nullptr;
        }
        bool DaLiJeZaduzena () {
            if (zaduzena!=nullptr) return true;
            return false;
        }
};

class Biblioteka{
    std::map<int, std::shared_ptr<Korisnik> > mapa_korisnika;
    std::map<int, std::shared_ptr<Knjiga> > mapa_knjiga;
    //mapa_knjiga.first je evidencijski broj knjige
    //mapa_korisnika.first je clanski broj korisnika
    //mapa_knjiga.second je Knjiga** mapa_knjiga
    //mapa_korisnika.second je Korisnik** mapa_korisnika
    
  public:
        Biblioteka () {};
        ~Biblioteka(){
            mapa_knjiga.clear();
            mapa_korisnika.clear();
        }
        
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, 
                                       std::string adresa, std::string broj_telefona){
        for(auto i(mapa_korisnika.begin()); i!=mapa_korisnika.end();i++){
            if(clanski_broj==i->first) throw std::logic_error("Korisnik vec postoji");
        }    
        std::shared_ptr<Korisnik> novi_korisnik = std::make_shared<Korisnik>();
        novi_korisnik->ime = ime;
        novi_korisnik->prezime = prezime;
        novi_korisnik->adresa = adresa;
        novi_korisnik->telefon = broj_telefona;
        mapa_korisnika[clanski_broj] = novi_korisnik;
    }
    
    void RegistrirajNovuKnjigu(int evidencijski_broj_knjige, std::string naslov, std::string ime_pisca, 
                                       std::string zanr, int godina_izdavanja){
        for(auto i(mapa_knjiga.begin()); i!=mapa_knjiga.end();i++){
            if(evidencijski_broj_knjige==i->first) throw std::logic_error("Knjiga vec postoji");
        }    
        std::shared_ptr<Knjiga> nova_knjiga = std::make_shared<Knjiga>(Knjiga(naslov, ime_pisca, zanr, godina_izdavanja));
        mapa_knjiga[evidencijski_broj_knjige] = nova_knjiga;                                   
    }
    
    Korisnik& NadjiKorisnika(int clanski_broj){
        int k(0);
        for(auto i(mapa_korisnika.begin()); i!=mapa_korisnika.end();i++){
            if(clanski_broj==i->first) k++;
            if(k==0) throw std::logic_error("Korisnik nije nadjen");
        } 
        return *mapa_korisnika[clanski_broj].get();
    }
        
    Knjiga& NadjiKnjigu(int evidencijski_broj_knjige){
        int k(0);
        for(auto i(mapa_knjiga.begin()); i!=mapa_knjiga.end();i++){
            if(evidencijski_broj_knjige==i->first) k++;
            if(k==0) throw std::logic_error("Knjiga nije nadjena");
        }    
        return *mapa_knjiga[evidencijski_broj_knjige].get();
    }
    
    void IzlistajKorisnike() const {
        for(auto it(mapa_korisnika.begin()); it!=mapa_korisnika.end(); it++){
        std::cout<<"Clanski broj: "<<it->first<<std::endl;
        std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
        std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
        }
    }
    
    void IzlistajKnjige() const {
    for(auto it(mapa_knjiga.begin()); it!=mapa_knjiga.end(); it++){
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<it->second->DajNaslov()<<"\n";
        std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
        
        if(it->second->DaLiJeZaduzena()) std::cout<<"Zaduzena kod korisnika: "
            <<it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime << std::endl << std::endl;
            
        }
    }
    
    void ZaduziKnjigu(int evidencijski_broj_knjige,int clanski_broj){
        int k(0);
        for(auto i(mapa_knjiga.begin()); i!=mapa_knjiga.end();i++){
            if(evidencijski_broj_knjige==i->first) k++;
        }
        if(k==0) throw std::logic_error("Knjiga nije nadjena");
        mapa_knjiga[evidencijski_broj_knjige]->ZaduziKnjigu(*mapa_korisnika[clanski_broj]);
        
    }
    void RazduziKnjigu(int evidencijski_broj_knjige){
        int k(0);
        for(auto i(mapa_knjiga.begin()); i!=mapa_knjiga.end();i++){
            if(evidencijski_broj_knjige==i->first) k++;
            if(k==0) throw std::logic_error("Knjiga nije nadjena");
        }   
        for(auto i(mapa_knjiga.begin()); i!=mapa_knjiga.end();i++){
            if(!i->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
        }   
    }
    
    void PrikaziZaduzenja(int clanski_broj){
        /*for(auto i(mapa_korisnika.begin()); i!=mapa_korisnika.end();i++){
            if(clanski_broj==i->first) 
                throw std::logic_error("Nema zaduzenja za tog korisnika!");
        } */
        bool test(false);
        for(auto it(mapa_knjiga.begin()); it!=mapa_knjiga.end(); it++){
            if (it->second->DajKodKogaJe() == mapa_korisnika[clanski_broj]) {
                test=true;
                break;
            }
        }
        if (!test)
            throw std::logic_error("Nema zaduzenja za tog korisnika!");
        
        for(auto it(mapa_knjiga.begin()); it!=mapa_knjiga.end(); it++){
            if (it->second->DajKodKogaJe() == mapa_korisnika[clanski_broj]) {
                std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
                std::cout<<"Naslov: "<<it->second->DajNaslov()<<"\n";
                std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
                std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
                std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl<<std::endl;
            }
        }
    }
};

int main ()
{
    Biblioteka BibliotekaSarajeva;
    int n(0);
    std::map<int, Korisnik*> mapa_korisnika;
    std::map<int, Knjiga*> mapa_knjiga;
    std::cout<<"\nDobrodosli na stranicu Biblioteka grada Sarajeva! Ja sam Amila i bit cu vas vodic :)\n\n\n";
    std::cout<<"Unesite broj knjiga koje želite unijeti: ";
    std::cout<<"(ukoliko želite preskočiti ovaj dio, unesite 0)\n";
    std::cin>>n;
    std::string naziv,autor,zanr;
    int godina_izdavanja(0),brojcic(0);
    for(int i(0); i<n; i++){
    std::cout<<"\nEvidencijski broj knjige: ";
    std::cin>>brojcic;
    std::cout<<"\nUnesite naziv knjige: ";
    std::cin.clear();
    std::getline(std::cin, naziv);
    std::cout<<"\nUnesite autora: ";
    std::cin.clear();
    std::getline(std::cin, autor);
    std::cout<<"\nUnesite zanr: ";
    std::cin.clear();
    std::getline(std::cin, zanr);
    std::cin.clear();
    std::cout<<"\nUnesite godinu izdavanja: ";
    std::cin>>godina_izdavanja;
    BibliotekaSarajeva.RegistrirajNovuKnjigu(brojcic,naziv, autor, zanr, godina_izdavanja);
    }
    
    int m(0);
    std::cout<<"\nŽelite registrirati novog korisnika? Ili više njih? ";
    std::cout<<"Prvo unesite broj korisnika koje želite registrirati, a zatim i njihove podatke !";
    std::cout<<"(ukoliko želite preskočiti ovaj dio, unesite 0)\n";
    std::cin >> m;
    
    int broj(0);
    std::string ime,prezime,adresa,broj_telefona;
    
    for(int i(0); i<m; i++){
        std::cout<<"\nEvidencijski broj: ";
        std::cin>>broj;
        std::cout<<"\nIme korisnika: ";
        std::getline(std::cin,ime);
        std::cout<<"\nPrezime korisnika: ";
        std::getline(std::cin,prezime);
        std::cout<<"\nAdresa: ";
        std::getline(std::cin,adresa);
        std::cout<<"\nBroj Telefona: ";
        std::getline(std::cin, broj_telefona);
        
        BibliotekaSarajeva.RegistrirajNovogKorisnika(broj,ime,prezime,adresa,broj_telefona);
    }
    
    int evidencijski;
    std::cout<<"Unesite evidencijski broj osobe koju želite pronaći: ";
    std::cin>>evidencijski;
    std::cout<<BibliotekaSarajeva.NadjiKorisnika(evidencijski).ime;

    std::cout<<"\nŽelite li provjeriti da li je neka knjiga zadužena? Unesite evidencijski broj knjige!\n";
    std::cin>>evidencijski;
    std::cout<<BibliotekaSarajeva.NadjiKnjigu(evidencijski).DaLiJeZaduzena();
    

    BibliotekaSarajeva.IzlistajKnjige();
    BibliotekaSarajeva.IzlistajKorisnike();

    
	return 0;
}