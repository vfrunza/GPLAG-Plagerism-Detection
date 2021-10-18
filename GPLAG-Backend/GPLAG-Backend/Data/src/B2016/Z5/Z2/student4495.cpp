#include <stdexcept>
#include <iostream>
#include <string>
#include <map>
#include <memory>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};
class Knjiga{
    std::string naslov, ime, zarn;
    int god;
    std::shared_ptr<Korisnik> pok;
    public:
    Knjiga(std::string na, std::string im, std::string zn, int g){
        naslov=na;
        ime=im;
        zarn=zn;
        god=g;
        pok=nullptr;
    }
    std::string DajNaslov() const{
        return naslov;
    }
    std::string DajZanr() const{
        return zarn;
    }
    std::string DajAutora() const{
        return ime;
    }
    int DajGodinuIzdavanja() const{
        return god;
    }
    std::shared_ptr<Korisnik> DajKodKogaJe(){
        return pok;
    }
    bool DaLiJeZaduzena(){
        if(pok==nullptr) return false;
        return true;
    }
    void ZaduziKnjigu(Korisnik &k){
        pok=std::make_shared<Korisnik>(k);
    }
    void RazduziKnjigu(){
        pok=nullptr;
    }
};

class Biblioteka{
    std::map<int,std::shared_ptr<Korisnik>> map1;
    std::map<int,std::shared_ptr<Knjiga>> map2;
    public:
    Biblioteka(){}
    Biblioteka &operator=(const Biblioteka &b)=default;
    Biblioteka &operator =(Biblioteka &&b)=default;
    void RegistrirajNovogKorisnika(int br,std::string imex, std::string prezimex, std::string adresax, std::string telefonx){
        auto it = map1.find(br);
        if(it!=map1.end()) throw std::logic_error("Korisnik vec postoji");
        auto p=std::make_shared<Korisnik>();
        p->ime=imex;
        p->prezime=prezimex;
        p->adresa=adresax;
        p->telefon=telefonx;
        map1.insert(std::pair<int,std::shared_ptr<Korisnik>>(br,p));
    }
    void RegistrirajNovuKnjigu(int br,std::string na, std::string im, std::string zn, int g){
        auto it = map2.find(br);
        if(it!=map2.end()) throw std::logic_error("Knjiga vec postoji");
        auto p=std::make_shared<Knjiga>(na,im,zn,g);
        map2.insert(std::pair<int,std::shared_ptr<Knjiga>>(br,p));
    }
    Korisnik &NadjiKorisnika(int x) const{
        auto it = map1.find(x);
        if(it==map1.end()) throw std::logic_error("Korisnik nije nadjen");
        return *(it->second);
    }
    Knjiga &NadjiKnjigu(int x) const{
        auto it = map2.find(x);
        if(it==map2.end()) throw std::logic_error("Knjga nije nadjen");
        return *(it->second);
    }
    void IzlistajKorisnike() const {
        for(auto it(map1.begin()); it!=map1.end(); it++){
            std::cout << "Clanski broj: " << it->first<< std::endl;
            std::cout << "Ime i prezime: " << it->second->ime << " "<<it->second->prezime<< std::endl;
            std::cout << "Adresa: " << it->second->adresa <<std::endl;
            std::cout << "Broj telefona: " << it->second->telefon <<std::endl<< std::endl;
        }    
    }
    void IzlistajKnjige() const {
        for(auto it(map2.begin()); it!=map2.end(); it++){
            std::cout << "Evidencijski broj: " << it->first<< std::endl;
            std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
            std::cout << "Pisac: " << it->second->DajAutora() <<std::endl;
            std::cout << "Zanr: " << it->second->DajZanr() <<std::endl;
            std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() <<std::endl;
            if(it->second->DajKodKogaJe()!=nullptr)
                std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<< std::endl;
            std::cout  << std::endl;    
        }    
    }
    void ZaduziKnjigu(int x, int y){
        if(x<0 || y<0) throw std::logic_error("Knjiga nije nadjena");
        NadjiKnjigu(x);
        NadjiKorisnika(y);
        if(NadjiKnjigu(x).DaLiJeZaduzena())
           throw std::logic_error("Knjiga vec zaduzena");
       NadjiKnjigu(x).ZaduziKnjigu(NadjiKorisnika(y));    
        
    }
    void RazduziKnjigu(int x){
        if(!NadjiKnjigu(x).DaLiJeZaduzena())
            throw std::logic_error("Knjiga nije zaduzena");
        NadjiKnjigu(x).RazduziKnjigu();
    }
    void PrikaziZaduzenja(int x){
        auto it1 = map1.find(x);
        if(it1==map1.end()) throw std::logic_error("Korisnik nije nadjen");
        bool nasao=false;
        for(auto it(map2.begin()); it!=map2.end(); it++){
            if(it->second->DajKodKogaJe()==it1->second){
                nasao=true;
                std::cout << "Evidencijski broj: " << it->first<< std::endl;
                std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
                std::cout << "Pisac: " << it->second->DajAutora() <<std::endl;
                std::cout << "Zanr: " << it->second->DajZanr() <<std::endl;
                std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() <<std::endl;
                std::cout  << std::endl;    
            }
        }
        if(!nasao)
            std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
    }
};


int main ()
{
    Biblioteka b;
    int n;
    int b1(0),b2(0);
    while(true){
        std::cout << "Odaberite komandu:\nZa dodavanje novog korisnika - 1\nZa dodavanje nove knjige - 2\nZa izlistavanje svih knjige - 3\nZa izlistavanje svih korisnika - 4" << std::endl;
        std::cout << "Za prikaz zaduzenja odredjenog korisnika - 5\nZa razduzenje knjige - 6" << std::endl;
        std::cout << "Kraj - 0" << std::endl;
        std::cin >> n;
        if(n==0) break;
        if(n==1){
            std::cin.ignore(1000, '\n');
            std:: string ime, prezime,adresa, telefon;
            std::cout << "Unesite ime:  ";
            std::getline(std::cin, ime);
            std::cout <<"Unesite prezime: ";
            std::getline(std::cin, prezime);
            std::cout << "Adresa: " ;
            std::getline(std::cin, adresa);
            std::cout << "Broj telefona: " ;
            std::getline(std::cin, telefon);
            b.RegistrirajNovogKorisnika(b1, ime,prezime, adresa, telefon);
            b1++;
        }
        if(n==2){
            std::cin.ignore(1000, '\n');
            std:: string ime,zanr, naslov; int g;
            std::cout << "Unesite ime autora:  ";
            std::getline(std::cin, ime);
            std::cout <<"Unesite naslov: ";
            std::getline(std::cin, naslov);
            std::cout << "Zanr: " ;
            std::getline(std::cin, zanr);
            std::cout << "Godina: " ;
            std::cin >> g;
            b.RegistrirajNovuKnjigu(b2,naslov,ime,zanr,g);
            b2++;
        }
        if(n==3){
            b.IzlistajKnjige();
        }
        if(n==4){
            b.IzlistajKorisnike();
        }
        if(n==5){
            int x;
            std::cout << "Unesite clanski broj korisnika za kojeg zelite znati zaduzenja: " << std::endl;
            std::cin >> x;
            b.PrikaziZaduzenja(x);
        }
        if(n==6){
            int x,y;
            std::cout << "Unesite br. knjige i cl.br. korisnika koji zaduzuje knjigu: " << std::endl;
            std::cin >> x>>y;
            b.ZaduziKnjigu(x,y);
        }
        
    }
	return 0;
}