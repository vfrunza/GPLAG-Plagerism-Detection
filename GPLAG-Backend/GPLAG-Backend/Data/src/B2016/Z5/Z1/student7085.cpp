/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>

using std::string;

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
    Korisnik(string ime, string prezime, string adresa, string telefon){
        Korisnik::ime=ime;
        Korisnik::prezime=prezime;
        Korisnik::adresa=adresa;
        Korisnik::telefon=telefon;
    }
};

class Knjiga{
    string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* zaduzio;
    public:
    Knjiga(string naslov, string ime_pisca, string zanr,int godina_izdavanja, Korisnik* zaduzio=nullptr){
        this->naslov=naslov; this->ime_pisca=ime_pisca; this->zanr=zanr; this->godina_izdavanja=godina_izdavanja;
        this->zaduzio=nullptr;//this->zaduzio=&zaduzio;
    }
    std::string DajNaslov()const{ return naslov;}
    std::string DajAutora()const{ return ime_pisca;}
    std::string DajZanr()const{ return zanr;}
    int DajGodinuIzdavanja()const{ return godina_izdavanja;}
    Korisnik* DajKodKogaJe()const{ return zaduzio;}
    void ZaduziKnjigu( Korisnik &A){
        zaduzio=&A;
    }
    void RazduziKnjigu(){ zaduzio=nullptr;}
    bool DaLiJeZaduzena()const{ 
        if(zaduzio!=nullptr) return true;
        else return false;
    }
};

class Biblioteka{
    private:
    void Obrisi(std::map<int,Korisnik*> m1, std::map<int,Knjiga*>m2){
        for(auto &x: m1) delete x.second;
        for(auto &x: m2) delete x.second;
    }
    template<typename tip>
    void Dodaj(std::map<int, tip*> m){
        for(auto x: m) m.insert(std::make_pair(x.first, new tip(*x.second)));
    }
    std::map<int,Korisnik*> mapa1;
    std::map<int, Knjiga*> mapa2;
    public:
    Biblioteka()=default;
    Biblioteka(Biblioteka &bibl){
        //for(auto x: bibl.mapa1) mapa1.insert(std::make_pair(x.first, new Korisnik(*x.second)));
        Dodaj(mapa1);
        //for(auto x:bibl.mapa2) mapa2.insert(std::make_pair(x.first, new Knjiga(*x.second)));
        Dodaj(mapa2);
    }
    
    Biblioteka(Biblioteka &&bibl){
        //for(auto x:bibl.mapa2) mapa2.insert(std::make_pair(x.first, x.second));
        Dodaj(mapa2);
        //for(auto x:bibl.mapa1) mapa1.insert(std::make_pair(x.first, x.second));
        Dodaj(mapa1);
    }
    
    Biblioteka &operator= (Biblioteka &bibl){
        if(&bibl!=this){
            for(auto &x: mapa2) delete x.second;
            for(auto &x:mapa1) delete x.second;
            //for(auto x:bibl.mapa1)mapa1.insert(std::make_pair(x.first, new Korisnik(*x.second)));
            //for(auto x:bibl.mapa2) mapa2.insert(std::make_pair(x.first, new Knjiga(*x.second)));
            Dodaj(mapa1);
            Dodaj(mapa2);
        }
        return *this;
    }
    Biblioteka &operator= (Biblioteka &&bibl){
        if(&bibl !=this){
            for(auto &x:mapa2) delete x.second;
            for(auto &x:mapa1) delete x.second;
            //for(auto x: bibl.mapa1) mapa1.insert(std::make_pair(x.first, x.second));
            //for(auto x: bibl.mapa2) mapa2.insert(std::make_pair(x.first, x.second));
            Dodaj(mapa1);
            Dodaj(mapa2);
            
        }
        return *this;
    }
    ~Biblioteka(){
        Obrisi(mapa1, mapa2);
    }
    
    void RegistrirajNovogKorisnika(int br, std::string i, std::string p, std::string a, std::string t){
        bool ima=false;
        for(auto x:mapa1) 
        if(x.first==br) ima=true;
        if(ima==true) throw std::logic_error("Korisnik vec postoji");
        mapa1.insert(std::make_pair(br, new Korisnik (i,p,a,t)));
    }
    
    void RegistrirajNovuKnjigu(int br, std::string ime, std::string pisac, std::string zanr, int godina){
        bool ima=false;
        for(auto &x:mapa2)
        if(x.first==br) ima=true;
        if(ima==true) throw std::logic_error("Knjiga vec postoji");
        
        mapa2.insert(std::make_pair(br, new Knjiga(ime, pisac, zanr, godina)));
    }
    Korisnik &NadjiKorisnika (int br){
        for(auto x:mapa1)
        if(x.first==br) return *x.second;
         throw std::logic_error("Korisnik nije nadjen");
    }
    Knjiga &NadjiKnjigu (int br){
        for(auto x:mapa2)
        if(x.first== br) return *x.second;
        throw std::logic_error("Knjiga nije nadjena");
    }
    
    void ZaduziKnjigu( int knj, int kor){
        bool ima=false;
        for(auto x: mapa2)
        if(x.first==knj){
            ima=true;
            if(x.second->DajKodKogaJe()!=nullptr)
            throw std::logic_error("Knjiga vec zaduzena");
        }
        if(ima==false) throw std::logic_error("Knjiga nije nadjena");
        ima=false;
        for(auto x:mapa1)
        if(x.first==kor) ima=true;
        if(ima==false) throw std::logic_error("Korisnik nije nadjen");
        mapa2[knj]->ZaduziKnjigu(*mapa1[kor]);
    }
    void RazduziKnjigu(int br){
        bool ima=false;
        for(auto x: mapa2)
        if(x.first== br){
            ima=true;
            if(x.second->DajKodKogaJe()==nullptr)
            throw std::logic_error("Knjiga nije zaduzena");
        }
        if(ima==false) throw std::logic_error("Knjiga nije nadjena");
        mapa2[br]->RazduziKnjigu();
        
    }
    
    void IzlistajKorisnike()const{
        for(auto x: mapa1)
        {
            std::cout<<"Clanski broj: "<<x.first<<std::endl;
            std::cout<<"Ime i prezime: "<<x.second->ime<<" "<<x.second->prezime<<std::endl;
            std::cout<<"Adresa: "<<x.second->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<x.second->telefon<< std::endl;
            std::cout<<std::endl;
            
        }
    }
    void IzlistajKnjige(){
        for(auto x:mapa2){
        std::cout<<"Evidencijski broj: "<<x.first<<std::endl;
        std::cout<<"Naslov: "<<x.second->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<x.second->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<x.second->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<x.second->DajGodinuIzdavanja()<<std::endl;
        if(x.second->DajKodKogaJe()!=nullptr)
        std::cout<<"Zaduzena kod korisnika: "<<x.second->DajKodKogaJe()->ime<<" "<<x.second->DajKodKogaJe()->prezime<<std::endl;
        std::cout<<std::endl;
        }
    }
    
    void PrikaziZaduzenja(int br){
        bool ima=false;
        for(auto x: mapa1)
        if(x.first == br) ima=true;
        if(ima==false) throw std::logic_error("Korisnik nije nadjen");
        for(auto x: mapa2){
            //if(*mapa1[br]==*x.second->DajKodKogaJe()){
                std::cout<<"Evidencijski broj: "<<x.first<<std::endl;
                std::cout<<"Naslov: "<<x.second->DajNaslov()<<std::endl;
                std::cout<<"Pisac: "<<x.second->DajAutora()<<std::endl;
                std::cout<<"Zanr: "<<x.second->DajZanr()<<std::endl;
                std::cout<<"Godina izdavanja: "<<x.second->DajGodinuIzdavanja()<<std::endl;
            }
       // }
    }
    
};

int main ()
{
    /*Korisnik a("Marko", "Markovic", "BB", "29385");
    Korisnik b("Maarko", "Markovic", "BB", "29385");
    Knjiga k("jej", "Mark Tven", "klasika", 1923);
    k.ZaduziKnjigu(b);
    std::cout<<k.DaLiJeZaduzena();*/
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
const Biblioteka b2(b);                                           
b2.IzlistajKorisnike();	return 0;
}