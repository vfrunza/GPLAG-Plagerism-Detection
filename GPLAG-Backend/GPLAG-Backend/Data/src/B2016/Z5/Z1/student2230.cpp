/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

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
    Korisnik *pok=nullptr;
    bool zaduzena=false;
    friend class Biblioteka;
public:
    Knjiga(std::string naslov,std::string ime_pisca, std::string zanr, int godina_izdavanja): naslov(naslov), ime_pisca(ime_pisca),zanr(zanr),godina_izdavanja(godina_izdavanja){};
    std::string DajNaslov()  const{ return naslov;}
    std::string DajAutora()  const{ return ime_pisca;}
    std::string DajZanr()    const{ return zanr;}
    int DajGodinuIzdavanja() const{ return godina_izdavanja;}
    Korisnik *DajKodKogaJe() const{ return pok;}
    void ZaduziKnjigu (Korisnik &korisnik) {pok=&korisnik; zaduzena=true;}
    void RazduziKnjigu(){pok=nullptr; zaduzena=false;};
    bool DaLiJeZaduzena(){ return zaduzena;}
   
};

class Biblioteka{
    std::map<int,Korisnik*> mapa_korisnika;
    std::map<int,Knjiga*> mapa_knjiga;
public:
    Biblioteka(){};
    ~Biblioteka(){ for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end();++it){delete it->second;}
                for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end();++it) delete it->second;}
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    Biblioteka &operator=(const Biblioteka &b);
    Biblioteka &operator=(Biblioteka &&b);
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int evidencijski_broj); 
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int clanski_broj);
    
};
void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
    for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end();++it){
        if(it->first==clanski_broj){
            throw std::logic_error("Korisnik vec postoji");
        }
    }
    Korisnik *pok=new Korisnik;
    pok->ime=ime;
    pok->prezime=prezime;
    pok->adresa=adresa;
    pok->telefon=telefon;
    mapa_korisnika.insert(std::make_pair(clanski_broj,pok));
    //delete pok;
}
void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj,std::string naslov,std::string ime_pisca, std::string zanr, int godina_izdavanja){
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end();++it){
        if(it->first==evidencijski_broj){
            throw std::logic_error("Knjiga vec postoji");
        }
    }
    Knjiga *pok=new Knjiga(naslov,ime_pisca,zanr,godina_izdavanja);
    mapa_knjiga.insert(std::make_pair(evidencijski_broj,pok));
    //pok=nullptr;
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj){
    bool pomoc(false);
    for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end();++it){
        if(it->first==clanski_broj){
            pomoc=true;
            break;
        }
    }
    if(pomoc==false) throw std::logic_error("Korisnik nije nadjen");
    return *mapa_korisnika[clanski_broj];
}
Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj){
    bool pomoc(false);
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end();++it){
        if(it->first==evidencijski_broj){
            pomoc=true;
            break;
        }
    }
    if(pomoc==false) throw std::logic_error("Knjiga nije nadjena");
    return *mapa_knjiga[evidencijski_broj];
}
void Biblioteka::IzlistajKorisnike() const{
    for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end();++it){
        std::cout<<"Clanski broj: "<<it->first<<std::endl;
        std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
        std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const{
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); ++it){
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
        if(it->second->DaLiJeZaduzena()==true){
            std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<std::endl;
        }
    }
}
void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj){
    bool pomoc(false);
    bool pomoc1(false);
    for(auto it=mapa_korisnika.begin();it!=mapa_korisnika.end();++it){
        if(it->first == clanski_broj){
            pomoc=true;
            break;
        }
    }
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end();++it){
        if(it->first==evidencijski_broj){
            pomoc1=true;
            break;
        }
    }
    if(pomoc1==false) throw std::logic_error("Knjiga nije nadjena");
    if(pomoc==false) throw std::logic_error("Korisnik nije nadjen");
    if(mapa_knjiga[evidencijski_broj]->DaLiJeZaduzena()==true) throw std::logic_error("Knjiga vec zaduzena");
    mapa_knjiga[evidencijski_broj]->ZaduziKnjigu(*mapa_korisnika[clanski_broj]);
}
void Biblioteka::RazduziKnjigu(int evidencijski_broj){
    if(mapa_knjiga[evidencijski_broj]->DaLiJeZaduzena()==false) throw std::logic_error("Knjiga nije zaduzena");
    bool pomoc(false);
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end();++it){
        if(it->first==evidencijski_broj){
            pomoc=true;
            break;
        }
    }
    if(pomoc==false) throw std::logic_error("Knjiga nije nadjena");
    mapa_knjiga[evidencijski_broj]->RazduziKnjigu();
}

Biblioteka::Biblioteka(const Biblioteka &b){
    for(auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end();it++){
        Korisnik *k=new Korisnik;
        k->ime=it->second->ime;
        k->prezime=it->second->prezime;
        k->adresa=it->second->adresa;
        k->telefon=it->second->telefon;
        mapa_korisnika[it->first]=k;
    }
    for(auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end();it++){
        mapa_knjiga[it->first]=new Knjiga(it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja());
    }  
}
Biblioteka::Biblioteka(Biblioteka &&b){
    for(auto it=b.mapa_korisnika.begin();it != b.mapa_korisnika.end();++it){
        mapa_korisnika[it->first]=it->second;
        it->second=nullptr;
    }
    for(auto it=b.mapa_knjiga.begin(); it != b.mapa_knjiga.end(); ++it){
        mapa_knjiga[it->first]=it->second;
        it->second=nullptr;
    }
}
Biblioteka &Biblioteka::operator=(const Biblioteka &b){
    if(&b != this){
        for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end();++it){
            delete it->second;
            it->second=nullptr;
            mapa_korisnika.erase(it);
        }
        for(auto it=b.mapa_korisnika.begin(); it != mapa_korisnika.end();++it){
            Korisnik *k=new Korisnik;
            k->ime=it->second->ime;
            k->prezime=it->second->prezime;
            k->adresa=it->second->prezime;
            k->telefon=it->second->prezime;
            mapa_korisnika.insert(std::make_pair(it->first,k));
        }
        for(auto it=mapa_knjiga.begin(); it != mapa_knjiga.end();++it){
            delete it->second;
            it->second=nullptr;
            mapa_knjiga.erase(it);
        }
        for(auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end();++it){
            Knjiga *p(new Knjiga(it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja()));
            mapa_knjiga.insert(std::make_pair(it->first,p));
        }
        return *this;
    }
    return *this;
}
Biblioteka &Biblioteka::operator=(Biblioteka &&b){
    if(&b != this){
        for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end();++it){
            delete it->second;
            it->second=nullptr;
            mapa_korisnika.erase(it);
        }
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end();++it){
            delete it->second;
            it->second=nullptr;
            mapa_knjiga.erase(it);
        }
        for(auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end();++it){
            mapa_korisnika.insert(std::make_pair(it->first,it->second));
            it->second=nullptr;
        }
        for(auto it=b.mapa_knjiga.begin();it!=mapa_knjiga.end();++it){
            mapa_knjiga.insert(std::make_pair(it->first,it->second));
            it->second=nullptr;
        }
        return *this;
    }
    return *this;
}
void Biblioteka::PrikaziZaduzenja(int clanski_broj){
   
auto i = mapa_korisnika.find(clanski_broj);
if(i == mapa_korisnika.end())
    throw std::domain_error("Korisnik nije nadjen");
    bool ima = false;
    for(auto j : mapa_knjiga){
        if(j.second -> DajKodKogaJe() != nullptr && i->second->ime == j.second->DajKodKogaJe()->ime && i->second->prezime == j.second->DajKodKogaJe()->prezime && i->second->adresa == j.second->DajKodKogaJe()->adresa && i->second->telefon == j.second->DajKodKogaJe()->telefon){
            ima = true;
            std::cout<<"Evidencijski broj: "<<j.first<<std::endl;
            std::cout<<"Naslov "<<j.second->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<j.second->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<j.second->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<j.second->DajGodinuIzdavanja()<<std::endl<<std::endl;
        }}
        if(ima == false){
            std::cout<<"Nema zaduzenja za tog korisnika!";
        }
    }

int main ()
{
    
    Biblioteka biblioteka;
    std::cout<<"Unesite opciju: "<<std::endl;
    int opcija(0);
    for(;;){
    std::cout<<" 0 - za kraj"<<std::endl<<" 1 - unesi novog korisnika"<<std::endl<<" 2 - unesi novu knjigu"<<std::endl<<" 3 - nadji korisnika"<<std::endl;
    std::cout<<" 4 - nadji knjigu"<<std::endl<<" 5 - izlistaj korisnike"<<std::endl<<" 6 - izlistaj knjige"<<std::endl<<" 7 - zaduzi knjigu"<<std::endl;
    std::cout<<" 8 - razduzi knjigu"<<std::endl<<" 9 - prikazi zaduzenja"<<std::endl;
    std::cin>>opcija;
    if(opcija==0) return 0;
    else if(opcija==1){
        int clanski_broj;
        std::string ime,prezime,adresa,telefon;
        try{
        std::cout<<"Unesite clanski broj: ";
        std::cin>>clanski_broj;
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout<<"Unesite ime korisnika: ";
        std::getline(std::cin,ime);
        std::cout<<"Unesite prezime korisnika: ";
        std::getline(std::cin,prezime);
        std::cout<<"Unesite adresu korisnika: ";
        std::getline(std::cin,adresa);
        std::cout<<"Unesite telefon korisnika: ";
        std::getline(std::cin,telefon);
        biblioteka.RegistrirajNovogKorisnika(clanski_broj,ime,prezime,adresa,telefon);
        std::cout<<"Korisnik uspjesno dodan!"<<std::endl;}
        catch(std::logic_error e){
            std::cout<<"Izuzetak: "<<e.what()<<std::endl;
        }
    }
    else if(opcija==5){
        biblioteka.IzlistajKorisnike();
    }
    else if(opcija==6){
        biblioteka.IzlistajKnjige();
    }
    else if(opcija==2){
        
        int evidencijski_broj,godina_izdavanja;
        std::string naslov,ime_pisca,zanr;
        try{
        std::cout<<"Unesite evidencijski broj: ";
        std::cin>>evidencijski_broj;
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout<<"Unesite naslov knjige: ";
        std::getline(std::cin,naslov);
        std::cout<<"Unesite ime autora knjige: ";
        std::getline(std::cin,ime_pisca);
        std::cout<<"Unesite zanr knjige: ";
        std::getline(std::cin,zanr);
        std::cout<<"Unesite godinu izdavanja: ";
        std::cin>>godina_izdavanja;
        biblioteka.RegistrirajNovuKnjigu(evidencijski_broj,naslov,ime_pisca,zanr,godina_izdavanja);
        std::cout<<"Knjiga uspjesno dodana!"<<std::endl;}
        catch(std::logic_error e){
            std::cout<<"Izuzetak: "<<e.what()<<std::endl;
        }
    }
    else if(opcija==3){
        int clanski(0);
        std::cout<<"Unesite clanski broj korisnika: ";
        std::cin>>clanski;
        try{
            Korisnik korisnik=biblioteka.NadjiKorisnika(clanski);
            std::cout<<"Korisnik sa clanskim brojem "<<clanski<<" je: "<<std::endl;
            std::cout<<"Ime: "<<korisnik.ime<<std::endl;
            std::cout<<"Prezime: "<<korisnik.prezime<<std::endl;
            std::cout<<"Adresa: "<<korisnik.adresa<<std::endl;
            std::cout<<"Telefon: "<<korisnik.telefon<<std::endl;
        }
        catch(std::logic_error e){
            std::cout<<"Izuzetak: "<<e.what()<<std::endl;
        }
    }
    else if(opcija==4){
        int evidencijski(0);
        std::cout<<"Unesite evidencijski broj knjige: ";
        std::cin>>evidencijski;
        try{
            Knjiga knjiga=biblioteka.NadjiKnjigu(evidencijski);
            std::cout<<"Knjiga sa evidencijskim brojem "<<evidencijski<<" je: "<<std::endl;
            std::cout<<"Naslov: "<<knjiga.DajNaslov()<<std::endl;
            std::cout<<"Ime autora: "<<knjiga.DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<knjiga.DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<knjiga.DajGodinuIzdavanja()<<std::endl;
        }
        catch(std::logic_error e){
            std::cout<<"Izuzetak: "<<e.what()<<std::endl;
        }
    }
    else if(opcija==7){
        int evidencijski_broj(0);
        int clanski_broj(0);
        try{
        std::cout<<"Unesite evidencijski broj: ";
        std::cin>>evidencijski_broj;
        std::cout<<"Unesite clanski broj: ";
        std::cin>>clanski_broj;
        biblioteka.ZaduziKnjigu(evidencijski_broj,clanski_broj);
        std::cout<<"Knjiga uspjesno zaduzena!"<<std::endl;    
        }
        catch(std::logic_error e){
            std::cout<<"Izuzetak: "<<e.what()<<std::endl;
        }
    }
    else if(opcija==8){
        int evidencijski_broj;
        std::cout<<"Unesite evidencijski broj: ";
        std::cin>>evidencijski_broj;
        try{
            biblioteka.RazduziKnjigu(evidencijski_broj);
            std::cout<<"Knjiga uspjesno razduzena!"<<std::endl;
        }
        catch(std::logic_error e){
            std::cout<<"Izuzetak: "<<e.what()<<std::endl;
        }
    }
    else if(opcija==9){
        int clanski_broj;
        std::cout<<"Unesite clanski broj: ";
        std::cin>>clanski_broj;
        try{
            biblioteka.PrikaziZaduzenja(clanski_broj);
        }
        catch(std::logic_error e){
            std::cout<<"Izuzetak: "<<e.what()<<std::endl;
        }
    }
    else if(opcija==10){
        Biblioteka g;
        g.Biblioteka::operator=(biblioteka);
        g.IzlistajKorisnike();
    }
    }
	return 0;
}