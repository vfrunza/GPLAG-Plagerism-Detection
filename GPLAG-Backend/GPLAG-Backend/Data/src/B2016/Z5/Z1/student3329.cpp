#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga{
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* zaduzena;
public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr),
        godina_izdavanja(godina_izdavanja), zaduzena(nullptr){}
    std::string DajNaslov()const{return naslov;}
    std::string DajAutora()const{return ime_pisca;}
    std::string DajZanr()const{return zanr;}
    int DajGodinuIzdavanja()const{return godina_izdavanja;}
    Korisnik* DajKodKogaJe()const{return zaduzena;}
    void ZaduziKnjigu(Korisnik &kor){zaduzena=&kor;}
    void RazduziKnjigu(){zaduzena=nullptr;}
    bool DaLiJeZaduzena()const{return zaduzena;}
};

class Biblioteka{
    std::map<int, Korisnik*> mkorisnika;
    std::map<int, Knjiga*> mknjiga;
public:
    Biblioteka(){}
    Biblioteka(Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    Biblioteka &operator=(Biblioteka &b);
    Biblioteka &operator=(Biblioteka &&b);
    ~Biblioteka();
    void RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu(int ev_broj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int cl_broj);
    Knjiga &NadjiKnjigu(int ev_broj);
    void IzlistajKorisnike();
    void IzlistajKnjige();
    void ZaduziKnjigu(int ev_broj, int cl_broj);
    void RazduziKnjigu(int ev_broj);
    void PrikaziZaduzenja(int cl_broj);
};

Biblioteka::Biblioteka(Biblioteka &b){
    for(auto it=b.mkorisnika.begin(); it!=b.mkorisnika.end(); it++){
        mkorisnika[it->first]=new Korisnik;
        *mkorisnika[it->first]=*b.mkorisnika[it->first];
    }
    for(auto it=b.mknjiga.begin(); it!=b.mknjiga.end(); it++){
        auto knjiga(b.mknjiga[it->first]);
        mknjiga[it->first]=new Knjiga(knjiga->DajNaslov(), knjiga->DajAutora(), knjiga->DajZanr(), knjiga->DajGodinuIzdavanja());
        //znam da je plitko
    }
}
Biblioteka::Biblioteka(Biblioteka &&b) : mkorisnika(b.mkorisnika), mknjiga(b.mknjiga){
    for(auto it=b.mkorisnika.begin(); it!=b.mkorisnika.end(); it++) b.mkorisnika[it->first]=nullptr;
    for(auto it=b.mknjiga.begin(); it!=b.mknjiga.end(); it++) b.mknjiga[it->first]=nullptr;
}
Biblioteka &Biblioteka::operator=(Biblioteka &b){
    for(auto it=b.mkorisnika.begin(); it!=b.mkorisnika.end(); it++){
        mkorisnika[it->first]=new Korisnik;
        *mkorisnika[it->first]=*b.mkorisnika[it->first];
    }
    for(auto it=b.mknjiga.begin(); it!=b.mknjiga.end(); it++){
        auto knjiga(b.mknjiga[it->first]);
        mknjiga[it->first]=new Knjiga(knjiga->DajNaslov(), knjiga->DajAutora(), knjiga->DajZanr(), knjiga->DajGodinuIzdavanja());
        //znam da je plitko
    } return *this;
}
Biblioteka &Biblioteka::operator=(Biblioteka &&b){
    mkorisnika=b.mkorisnika; mknjiga=b.mknjiga;
    for(auto it=b.mkorisnika.begin(); it!=b.mkorisnika.end(); it++) b.mkorisnika[it->first]=nullptr;
    for(auto it=b.mknjiga.begin(); it!=b.mknjiga.end(); it++) b.mknjiga[it->first]=nullptr; return *this;
}
Biblioteka::~Biblioteka(){
    for(auto it=this->mkorisnika.begin(); it!=this->mkorisnika.end(); it++)
        delete this->mkorisnika[it->first];
    for(auto it=this->mknjiga.begin(); it!=this->mknjiga.end(); it++)
        delete this->mknjiga[it->first];
}
void Biblioteka::RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
    if(mkorisnika.count(cl_broj)) throw std::logic_error("Korisnik vec postoji");
    mkorisnika[cl_broj]=new Korisnik;
    mkorisnika[cl_broj]->ime=ime; mkorisnika[cl_broj]->prezime=prezime; mkorisnika[cl_broj]->adresa=adresa; mkorisnika[cl_broj]->telefon=telefon;
}
void Biblioteka::RegistrirajNovuKnjigu(int ev_broj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja){
    if(mknjiga.count(ev_broj)) throw std::logic_error("Knjiga vec postoji");
    mknjiga[ev_broj]=new Knjiga(naslov, ime_pisca, zanr, godina_izdavanja);
}
Korisnik& Biblioteka::NadjiKorisnika(int cl_broj){
    if(!mkorisnika.count(cl_broj)) throw std::logic_error("Korisnik nije nadjen");
    return *mkorisnika[cl_broj];
}
Knjiga& Biblioteka::NadjiKnjigu(int ev_broj){
    if(!mknjiga.count(ev_broj)) throw std::logic_error("Knjiga nije nadjena");
    return *mknjiga[ev_broj];
}
void Biblioteka::IzlistajKorisnike(){
    for(auto it=mkorisnika.begin(); it!=mkorisnika.end(); it++){
        std::cout<<"Clanski broj: "<<it->first<<std::endl;
        std::cout<<"Ime i prezime: "<<mkorisnika[it->first]->ime<<" "<<mkorisnika[it->first]->prezime<<std::endl;
        std::cout<<"Adresa: "<<mkorisnika[it->first]->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<mkorisnika[it->first]->telefon<<std::endl;
        std::cout<<std::endl;
    }
}
void Biblioteka::IzlistajKnjige(){
    for(auto it=mknjiga.begin(); it!=mknjiga.end(); it++){
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<mknjiga[it->first]->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<mknjiga[it->first]->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<mknjiga[it->first]->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<mknjiga[it->first]->DajGodinuIzdavanja()<<std::endl;
        if(mknjiga[it->first]->DaLiJeZaduzena()){
            std::cout<<"Zaduzena kod korisnika: "<<mknjiga[it->first]->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime;
        /*    for(auto it2=mkorisnika.begin(); it2!=mkorisnika.end(); it2++){
                if(mknjiga[it->first]->DajKodKogaJe()==mkorisnika[it2->first])
                    std::cout<<"Zaduzena kod korisnika: "<<it2->first;
            }
        */
        }
        std::cout<<std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int ev_broj, int cl_broj){
    if(!mknjiga.count(ev_broj)) throw std::logic_error("Knjiga nije nadjena");
    if(!mkorisnika.count(cl_broj)) throw std::logic_error("Korisnik nije nadjen");
    if(mknjiga[ev_broj]->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    mknjiga[ev_broj]->ZaduziKnjigu(*mkorisnika[cl_broj]);
}
void Biblioteka::RazduziKnjigu(int ev_broj){
    if(!mknjiga.count(ev_broj)) throw std::logic_error("Knjiga nije nadjena");
    if(!mknjiga[ev_broj]->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
    mknjiga[ev_broj]->RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int cl_broj){
    if(!mkorisnika.count(cl_broj)) throw std::domain_error("Korisnik nije nadjen"); bool zaduzio(false);
    for(auto it=mknjiga.begin(); it!=mknjiga.end(); it++){
        if(mkorisnika[cl_broj]==mknjiga[it->first]->DajKodKogaJe()){
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<mknjiga[it->first]->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<mknjiga[it->first]->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<mknjiga[it->first]->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<mknjiga[it->first]->DajGodinuIzdavanja()<<std::endl<<std::endl;
            zaduzio=true;
        }
    }
    if(!zaduzio) std::cout<<"Nema zaduzenja za tog korisnika!";
}

int main (){
    std::cout<<"*Biblioteka - Rubik's Cube*"<<std::endl<<std::endl;
    Biblioteka rubiks;
    int input;
    std::cout<<"1 ->-> Registriraj Novog Korisnika"<<std::endl
        <<"2 ->-> Registriraj Novu Knjigu"<<std::endl
        <<"3 ->-> Izlistaj Korisnike"<<std::endl
        <<"4 ->-> Izlistaj Knjige"<<std::endl
        <<"5 ->-> Zaduzi Knjigu"<<std::endl
        <<"6 ->-> Razduzi Knjigu"<<std::endl
        <<"7 ->-> Prikazi Zaduzenja"<<std::endl
        <<"0 ->-> Kraj"<<std::endl;
    do{
        std::cout<<"___Komanda___: "; std::cin>>input;
        int cl_broj, ev_broj, godina_izdavanja; 
        std::string ime, prezime, adresa, telefon, naslov, ime_pisca, zanr;
        switch(input){
            case 1:
                std::cout<<"Clanski broj: "; std::cin>>cl_broj; std::cin.ignore(1000, '\n');
                std::cout<<"Ime: "; std::cin>>ime;
                std::cout<<"Prezime: "; std::cin>>prezime;
                std::cout<<"Adresa: "; std::cin>>adresa;
                std::cout<<"Telefon: "; std::cin>>telefon;
                rubiks.RegistrirajNovogKorisnika(cl_broj, ime, prezime, adresa, telefon); break;
            case 2:
                std::cout<<"Evidencijski broj: "; std::cin>>ev_broj; std::cin.ignore(1000, '\n');
                std::cout<<"Naslov: "; std::cin>>naslov;
                std::cout<<"Ime Pisca: "; std::cin>>ime_pisca;
                std::cout<<"Zanr: "; std::cin>>zanr;
                std::cout<<"Godina Izdavanja: "; std::cin>>godina_izdavanja; std::cin.ignore(1000, '\n');
                rubiks.RegistrirajNovuKnjigu(ev_broj, naslov, ime_pisca, zanr, godina_izdavanja); break;
            case 3:
                rubiks.IzlistajKorisnike(); break;
            case 4:
                rubiks.IzlistajKnjige(); break;
            case 5:
                std::cout<<"Evidencijski broj: "; std::cin>>ev_broj; std::cin.ignore(1000, '\n');
                std::cout<<"Clanski broj: "; std::cin>>cl_broj;
                rubiks.ZaduziKnjigu(ev_broj, cl_broj); break;
            case 6:
                std::cout<<"Evidencijski broj: "; std::cin>>ev_broj; std::cin.ignore(1000, '\n');
                rubiks.RazduziKnjigu(ev_broj); break;
            case 7:
                std::cout<<"Clanski broj: "; std::cin>>cl_broj; std::cin.ignore(1000, '\n');
                rubiks.PrikaziZaduzenja(cl_broj); break;
        }
    }while(input!=0);
    Biblioteka a; a=rubiks;
    a.IzlistajKnjige();
    std::cout<<std::endl<<"OVO JE NULLPOINTER? 0=jeste: "<<a.NadjiKnjigu(2212).DajKodKogaJe();
	return 0;
}