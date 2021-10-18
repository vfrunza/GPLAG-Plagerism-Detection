/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise


#include <iostream>
#include <map>
#include <string>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};
class Knjiga{
    std::string naslov, ime_pisca, zanr;
    int god_izdavanja;
    Korisnik *pok_na_kor=nullptr;
public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int god_izdavanja): naslov(naslov),
        ime_pisca(ime_pisca), zanr(zanr) , god_izdavanja(god_izdavanja) {pok_na_kor=nullptr;}
    std::string DajNaslov() const{return naslov;}
    std::string DajAutora() const{return ime_pisca;}
    std::string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return god_izdavanja;}
    Korisnik* DajKodKogaJe() const {return pok_na_kor;}
    void ZaduziKnjigu(Korisnik &a) {pok_na_kor=&a;}
    void RazduziKnjigu() {pok_na_kor=nullptr;}
    bool DaLiJeZaduzena () {if(!(pok_na_kor==nullptr)) return true; return false;}
};
class Biblioteka{
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
public:
    Biblioteka(){};
    ~Biblioteka();
    Biblioteka &operator=(const Biblioteka &b);
    Biblioteka &operator=(Biblioteka &&b);
    void RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu(int ev_broj, std::string naslov, std::string ime_pisca, std::string zanr, int god_izdavanja);
    Korisnik& NadjiKorisnika(int cl_broj);
    Knjiga& NadjiKnjigu(int ev_broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int ev_broj, int cl_broj);
    void RazduziKnjigu(int ev_broj);
    void PrikaziZaduzenja(int cl_broj) const;
};
Biblioteka::~Biblioteka(){
    for(auto it1(korisnici.begin()); it1!=korisnici.end(); it1++){
        delete (it1->second);
    }
    for(auto it2(knjige.begin());it2!=knjige.end();it2++){
        delete (it2->second);
    }
}
void Biblioteka::RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
    auto it(korisnici.find(cl_broj));
    if(it==korisnici.end()) {}
    else throw std::logic_error("Korisnik vec postoji");
    
    Korisnik tmp;
    tmp.ime=ime;
    tmp.prezime=prezime;
    tmp.adresa=adresa;
    tmp.telefon=telefon;
    
    Korisnik *pok_na_kor=nullptr;
    try{
        pok_na_kor=new Korisnik(tmp);
        korisnici[cl_broj]=pok_na_kor;
    }catch(std::bad_alloc){
        throw;
        for(auto it(korisnici.begin()); it!=korisnici.end(); it++){
            delete it->second;
        }
    }
}
void Biblioteka::RegistrirajNovuKnjigu(int ev_broj, std::string naslov, std::string ime_pisca, std::string zanr, int god_izdavanja){
    auto it(knjige.find(ev_broj));
    if(it==knjige.end()) {}
    else throw std::logic_error("Knjiga vec postoji");
    
    Knjiga tmp(naslov,ime_pisca,zanr, god_izdavanja);
    Knjiga *pok_na_knjigu(nullptr);
    try{
        pok_na_knjigu=new Knjiga(tmp);
        knjige[ev_broj]=pok_na_knjigu;
    }catch(std::bad_alloc){
        throw;
        for(auto it(knjige.begin()); it!=knjige.end(); it++){
            delete it->second;
        }
    }
}
Korisnik& Biblioteka::NadjiKorisnika(int cl_broj){
        if(cl_broj<=0) throw std::domain_error("Neispravan clanski broj");
        auto it(korisnici.find(cl_broj));
        if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    return *it->second;
}
Knjiga& Biblioteka::NadjiKnjigu(int ev_broj){
        if(ev_broj<=0) throw std::domain_error("Neispravan evidencijski broj");
        auto it(knjige.find(ev_broj));
        if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    return *it->second;    
}
void Biblioteka::IzlistajKorisnike() const{
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
        std::cout<<"Clanski broj: "<<it->first<<std::endl;
        std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
        std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const{
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        Knjiga pom=*it->second;
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<pom.DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<pom.DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<pom.DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<pom.DajGodinuIzdavanja()<<std::endl;
        if(pom.DaLiJeZaduzena()==true) {
            Korisnik* kor(pom.DajKodKogaJe());
            std::cout<<"Zaduzena kod korisnika: ";
            std::cout<<kor->ime;
            std::cout<<" ";
            std::cout<<kor->prezime<<std::endl;
        }
    }    
};
void Biblioteka::ZaduziKnjigu(int ev_broj, int cl_broj){
    if(ev_broj<=0 || cl_broj<=0) throw std::logic_error("Neispravni podaci");
    auto it(knjige.find(ev_broj));
    if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    
    auto it2(korisnici.find(cl_broj));
    if(it2==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    
    if(it->second->DaLiJeZaduzena()==true) throw std::logic_error("Knjiga je vec zaduzena");

    it->second->ZaduziKnjigu(*it2->second);
}
void Biblioteka::RazduziKnjigu(int ev_broj){
    auto it(knjige.find(ev_broj));
    if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    if(it->second->DaLiJeZaduzena()==false) throw std::logic_error("Knjiga nije zaduzena");
    it->second->RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int cl_broj) const {
    try{
        auto it(korisnici.find(cl_broj));
        if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        Korisnik* a;
        for(auto it2(knjige.begin()); it2!=knjige.end();it2++){
            if(it2->second->DaLiJeZaduzena()==true) {a=it2->second->DajKodKogaJe();
                if(it->second->ime==a->ime){
                    Knjiga pom=*it2->second;
                    std::cout<<"Evidencijski broj: "<<it2->first<<std::endl;
                    std::cout<<"Naslov: "<<pom.DajNaslov()<<std::endl;
                    std::cout<<"Pisac: "<<pom.DajAutora()<<std::endl;
                    std::cout<<"Zanr: "<<pom.DajZanr()<<std::endl;
                    std::cout<<"Godina izdavanja: "<<pom.DajGodinuIzdavanja()<<std::endl;
                }
            std::cout<<std::endl;
        }
}
    }catch(...){
        throw;
    }
}

int main (){
    std::cout<<"    Dobrodosli!"<<std::endl;
    
    do{
        Biblioteka biblioteka;
        std::cout<<"\nOpcije su: "<<std::endl;
        std::cout<<"[1]--------->Registriraj Novog Korisnika";
        std::cout<<"\n[2]--------->Registriraj Novu Knjigu";
        std::cout<<"\n[3]--------->Nadji Korisnika";
        std::cout<<"\n[4]--------->Nadji Knjigu";
        std::cout<<"\n[5]--------->Izlistaj Korisnike";
        std::cout<<"\n[6]--------->Izlistaj Knjige";
        std::cout<<"\n[7]--------->Zaduzi Knjigu";
        std::cout<<"\n[8]--------->RazduziKnjigu";
        std::cout<<"\n\"Kraj\"--------->Kraj"<<std::endl;
        
        std::cout<<"Izaberite neku opciju, unosom broja zeljene opcije: ";
        int n;
        std::cin>>n;
        
        while(n<0 && n>8)   {std::cout<<"\nNiste unijeli validan broj. Molimo pokusajte ponovo!";}
    /**/    if(!std::cin) {std::cout<<"\nDovidjenja!"; return 0;}
    
        switch(n){
            case(1):{
                bool neispravno(false);
                do{
                    std::cout<<"\n->Za ragistraciju novog korisnika unesite njegov clanski broj, ime, prezime, adresu, i broj telefona: ";
                    
                    std::cout<<"\nUnesite clanski broj i ime u istom redu: ";
                    int cl_broj;
                    std::cin>>cl_broj;
                    
                    //std::cout<<"Unesite ime: ";
                    std::string ime;
                    std::getline(std::cin, ime); 
                    
                    std::cout<<"Unesite prezime: ";
                    std::string prezime;
                    std::getline(std::cin, prezime); 
                    
                    std::cout<<"Unesite adresu: ";
                    std::string adresa;
                    std::getline(std::cin, adresa); 
                    
                    std::cout<<"Unesite broj telefona: ";
                    std::string broj_telefona;
                    std::getline(std::cin, broj_telefona);
    
                    try{
                        biblioteka.RegistrirajNovogKorisnika(cl_broj, ime, prezime, adresa,broj_telefona);
                        break;
                    }catch(std::logic_error izu){
                        std::cout<<izu.what()<<" Molimo pokusajte ponovo";
                        neispravno=true;
                    }
                }while(neispravno==true);
                break;
            }
            case(2):{
                bool neispravno(false);
                do{
                    std::cout<<"\n->Za ragistraciju nove knjige unesite njen evidencijski broj, naslov, ime pisca, zanr, i godinu izdavanja: ";
                    
                    std::cout<<"\nUnesite evidencijski broj i naslov knjige u istom redu: ";
                    int ev_broj;
                    std::cin>>ev_broj;
                    
                    //std::cout<<"Unesite naslov: ";
                    std::string naslov;
                    std::getline(std::cin, naslov); 
                    
                    std::cout<<"Unesite ime pisca: ";
                    std::string ime_pisca;
                    std::getline(std::cin, ime_pisca); 
                    
                    std::cout<<"Unesite zanr: ";
                    std::string zanr;
                    std::getline(std::cin, zanr); 
                    
                    std::cout<<"Unesite godinu izdavanja: ";
                    int god_izdavanja;
                    std::cin>>god_izdavanja;
    
                    try{
                        biblioteka.RegistrirajNovuKnjigu(ev_broj, naslov, ime_pisca, zanr,god_izdavanja);
                    }catch(std::logic_error izu){
                        std::cout<<izu.what()<<" Molimo pokusajte ponovo";
                        neispravno=true;
                    }
                }while(neispravno==true);                
                
            }
            case(3):{
                
            }
            case(4):{
                
            }
            case(5):{
                std::cout<<"\nKorisnici su: ";
                biblioteka.IzlistajKorisnike();
            }
            case(6):{
                std::cout<<"\nKnjige su: ";
                biblioteka.IzlistajKnjige();
            }
            case(7):{
                
            }
            case(8):{
                
            }        
        }
    }while(1);

	return 0;
}