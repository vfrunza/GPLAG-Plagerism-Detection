#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>

struct Korisnik{
    std::string ime,prezime,adresa,telefon;
};
class Knjiga{
    std::string naslov,pisac,zanr;
    int godina;
    Korisnik *korisnik = nullptr;
    public:
    Knjiga(std::string nasl, std::string pis, std::string zan, int god): naslov(nasl),pisac(pis),zanr(zan),godina(god){}
    std::string DajNaslov() const { return naslov;}
    std::string DajAutora() const {return pisac;}
    std::string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina;}
    Korisnik *&DajKodKogaJe() {return korisnik;}
    void ZaduziKnjigu(Korisnik &kor){
        korisnik = &kor;
    }
    void RazduziKnjigu(){
        korisnik = nullptr;
    }
    bool DaLiJeZaduzena(){
        if(!korisnik) return false;
        return true;
    }
};
class Biblioteka{
    std::map<int,std::shared_ptr<Korisnik>> korisnik;
    std::map<int,std::shared_ptr<Knjiga>> knjiga;
    public:
    Biblioteka(){};
    Biblioteka(Biblioteka &bibl);
    Biblioteka(Biblioteka &&bibl);
    Biblioteka &operator =(Biblioteka &bibl);
    Biblioteka &operator =(Biblioteka &&bibl);
    ~Biblioteka(){}
    void RegistrirajNovogKorisnika(int clanskibr, std::string ime, std::string prezime, std::string adresa, std::string broj);
    void RegistrirajNovuKnjigu(int evidencija, std::string naslov, std::string pisac ,std::string zanr, int godina);
    Korisnik &NadjiKorisnika(int clanskibr);
    Knjiga &NadjiKnjigu(int evidencija);
    void IzlistajKnjige() const;
    void IzlistajKorisnike() const;
    void ZaduziKnjigu(int evidencija, int clanskibr);
    void RazduziKnjigu(int evidencija);
    void PrikaziZaduzenja(int clanskibr);
};
int main ()
{ 
    std::cout<<"Dobrodosli!"<<std::endl<<std::endl<<"Odaberite opciju: "<<std::endl;
    while(true){
    std::cout<<"1)Registrirajte novog korisnika"<<std::endl<<"2)Novu knjigu"<<std::endl<<"3)Izlistaj Korisnike"<<std::endl<<"4)Izlistaj Knjige"<<std::endl<<"5)Zaduzi knjigu"<<std::endl<<"6)Prikazi Zaduzenja"<<std::endl<<"7)Nadji nekoga"<<std::endl<<"8)Razduzi Knjigu: "<<std::endl<<"0)Kraj programa"<<std::endl;
    int n,a;
    std::string ime,prezime,telefon,adresa;
    Biblioteka biblioteka;
    std::cin>>n;
    try{
    switch(n){
        case 0: return 0;
        case 1:
        std::cout<<"Unesite clanski broj, ime, prezime, adresu i broj telefona"<<std::endl;
        std::cin>>n;
        std::cin.ignore(10000,'\n');
        std::cin>>ime>>prezime>>adresa>>telefon;
        biblioteka.RegistrirajNovogKorisnika(n,ime,prezime,adresa,telefon);
        break;
        case 2:
        std::cout<<"Unesite evidencijski broj,naslov, ime autora, zanr i kada je izdata"<<std::endl;
        std::cin>>n;
        std::cin.ignore(10000,'\n');
        std::cin>>ime>>prezime>>adresa>>a;
        biblioteka.RegistrirajNovuKnjigu(n,ime,prezime,adresa,a);
        break;
        case 3:
        biblioteka.IzlistajKorisnike();
        break;
        case 4:
        biblioteka.IzlistajKnjige();
        break;
        case 5:
        std::cout<<"Unesite evidencjski broj knjige i clanski broj korisnika"<<std::endl;
        std::cin>>n>>a;
        biblioteka.ZaduziKnjigu(n,a);
        break;
        case 6:
        std::cout<<"Unesite broj osobe za koja zelit evidjeti zaduzenja"<<std::endl;
        std::cin>>n;
        biblioteka.PrikaziZaduzenja(n);
        break;
        case 7:
        std::cout<<"Za trazenje knjige unesite 1, za trazenje osobe unesite 2"<<std::endl;
        std::cin>>n;
        if(n == 1){
            std::cout<<"Unesite evidencijski broj"<<std::endl;
            std::cin>>a;
            Knjiga b = biblioteka.NadjiKnjigu(a);
            std::cout<<b.DajNaslov()<<std::endl<<b.DajAutora()<<std::endl<<b.DajGodinuIzdavanja()<<std::endl<<b.DajZanr()<<std::endl;
        }
        if(n == 2){
            std::cout<<"Unesite clanski broj"<<std::endl;
            std::cin>>a;
            Korisnik b = biblioteka.NadjiKorisnika(a);
            std::cout<<b.ime<<" "<<b.prezime<<" "<<std::endl<<b.adresa<<std::endl<<b.telefon;
        }
        break;
        case 8:
            std::cout<<"Unesite evidencijski broj knjige koju razduzujete"<<std::endl;
            std::cin>>a;
            biblioteka.RazduziKnjigu(a);
            break;
        
    }
    }catch(...){
        std::cout<<"Pogresan unos"<<std::endl;
    }
    }
	return 0;
}
Biblioteka::Biblioteka(Biblioteka &bibl){
    for(auto it(bibl.korisnik.begin()); it!= bibl.korisnik.end(); it++){
        korisnik[it->first] =std::make_shared<Korisnik>(*(it->second));
    }
    for(auto it(bibl.knjiga.begin()); it!= bibl.knjiga.end(); it++){
        knjiga[it->first] =std::make_shared<Knjiga>(*(it->second));
    }
}
Biblioteka::Biblioteka(Biblioteka &&bibl){
    std::swap(korisnik,bibl.korisnik);
    std::swap(knjiga,bibl.knjiga);
}
Biblioteka &Biblioteka::operator =(Biblioteka &bibl){
    for(auto it(bibl.korisnik.begin()); it!= bibl.korisnik.end(); it++){
        korisnik[it->first] =std::make_shared<Korisnik>(*(it->second));
    }
    for(auto it(bibl.knjiga.begin()); it!= bibl.knjiga.end(); it++){
        knjiga[it->first] = std::make_shared<Knjiga>(*(it->second));
    }
    return *this;
}
Biblioteka &Biblioteka::operator =(Biblioteka &&bibl){
    std::swap(korisnik,bibl.korisnik);
    std::swap(knjiga,bibl.knjiga);
    return *this;
}
void Biblioteka::RegistrirajNovogKorisnika(int clanskibr, std::string ime, std::string prezime, std::string adresa, std::string telefon){
    auto it(korisnik.find(clanskibr));
    if(it != korisnik.end())
        throw std::logic_error("Korisnik vec postoji");
    korisnik[clanskibr] = std::make_shared<Korisnik>();
    korisnik[clanskibr]->ime = ime,korisnik[clanskibr]->prezime = prezime,korisnik[clanskibr]->adresa = adresa, korisnik[clanskibr]->telefon = telefon;
}
void Biblioteka::RegistrirajNovuKnjigu(int evidencija, std::string naslov, std::string pisac, std::string zanr, int godina){
    auto it(knjiga.find(evidencija));
    if(it != knjiga.end())
        throw std::logic_error("Knjiga vec postoji");
    knjiga[evidencija] = std::make_shared<Knjiga>(naslov,pisac,zanr,godina);
}
Korisnik &Biblioteka::NadjiKorisnika(int clanskibr){
    auto it(korisnik.find(clanskibr));
    if(it == korisnik.end())
        throw std::logic_error("Korisnik nije nadjen");
    return *(korisnik[clanskibr]);
}
Knjiga &Biblioteka::NadjiKnjigu(int evidencija){
    auto it(knjiga.find(evidencija));
    if(it == knjiga.end())
        throw std::logic_error("Knjiga nije nadjena");
    return *(knjiga[evidencija]);
}
void Biblioteka::IzlistajKnjige() const{
    for(auto it(knjiga.begin()); it != knjiga.end(); it++){
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl<<"Naslov: "<<it->second->DajNaslov()<<" "<<std::endl
    <<"Pisac: "<<it->second->DajAutora()<<std::endl<<"Zanr: "<<it->second->DajZanr()<<std::endl<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
    if(it->second->DajKodKogaJe())
        std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<std::endl;
    std::cout<<std::endl;
    }
}
void Biblioteka::IzlistajKorisnike() const{
    for(auto it(korisnik.begin()); it != korisnik.end(); it++){
        std::cout<<"Clanski broj: "<<it->first<<std::endl<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl
        <<"Adresa: "<<it->second->adresa<<std::endl<<"Broj telefona: "<<it->second->telefon<<std::endl<<std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int evidencija, int clanskibr){
    auto it(knjiga.find(evidencija));
    if(it == knjiga.end())
        throw std::logic_error("Knjiga nije nadjena");
    if(it ->second-> DajKodKogaJe() != nullptr)
        throw std::logic_error("Knjiga vec zaduzena");
    auto it2(korisnik.find(clanskibr));
    if(it2 == korisnik.end())
        throw std::logic_error("Korisnik nije nadjen");
    knjiga[evidencija]->DajKodKogaJe() = korisnik[clanskibr].get();
}
void Biblioteka::RazduziKnjigu(int evidencija){
    auto it(knjiga.find(evidencija));
    if(it == knjiga.end())
        throw std::logic_error("Knjiga nije nadjena");
    if(it ->second-> DajKodKogaJe() == nullptr)
        throw std::logic_error("Knjiga nije zaduzena");
    knjiga[evidencija]->DajKodKogaJe() = nullptr;
}
void Biblioteka::PrikaziZaduzenja(int clanskibr){
    auto it(korisnik.find(clanskibr));
    if(it == korisnik.end())
        throw std::logic_error("Korisnik nije nadjen");
    for(auto it(knjiga.begin()); it != knjiga.end(); it++){
        if(it->second->DajKodKogaJe() == korisnik[clanskibr].get())
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl<<"Naslov: "<<it->second->DajNaslov()<<" "<<std::endl
    <<"Pisac: "<<it->second->DajAutora()<<std::endl<<"Zanr: "<<it->second->DajZanr()<<std::endl<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
    return;
    }
    throw std::logic_error("Nema zaduzenja za tog korisnika!");
}