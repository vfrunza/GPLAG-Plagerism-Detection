#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <map>
#include <memory>

using std::cin;
using std::cout;

struct Korisnik{
    std::string ime,prezime,adresa,telefon;
};

class Knjiga{
  std::string naslov,ime_pisca,zanr;
  int god;
  Korisnik* zaduzio;
  public:
  Knjiga(std::string naslov1,std::string ime_pisca1,std::string zanr1,int godina):naslov(naslov1),ime_pisca(ime_pisca1),zanr(zanr1),god(godina),zaduzio(nullptr){}
  std::string DajNaslov() const{return naslov;}
  std::string DajAutora() const{return ime_pisca;}
  std::string DajZanr() const{return zanr;}
  int DajGodinuIzdavanja() const{return god;}
  Korisnik* DajKodKogaJe() const{return zaduzio;}
  void ZaduziKnjigu(Korisnik &k){zaduzio=&k;}
  void RazduziKnjigu(){zaduzio=nullptr;}
  bool DaLiJeZaduzena(){if(!zaduzio) return false;return true;}
};

class Biblioteka{
    std::map<int,Korisnik*> korisnici;
    std::map<int,std::shared_ptr<Knjiga>> knjige;
    public:
    Biblioteka(){};
    Biblioteka(const Biblioteka &b){
        for(auto it=b.korisnici.begin();it!=b.korisnici.end();it++){
            auto novi=new Korisnik;
            (*novi).ime=(*(it->second)).ime;
            (*novi).prezime=(*(it->second)).prezime;
            (*novi).adresa=(*(it->second)).adresa;
            (*novi).telefon=(*(it->second)).telefon;
            korisnici.insert(std::make_pair(it->first,novi));
        }
        for(auto it=b.knjige.begin();it!=b.knjige.end();it++){
            auto nova=std::make_shared<Knjiga>((*(it->second)).DajNaslov(),(*(it->second)).DajAutora(),(*(it->second)).DajZanr(),(*(it->second)).DajGodinuIzdavanja());
            auto p=(*nova).DajKodKogaJe();
            p=(*(it->second)).DajKodKogaJe();
            knjige.insert(std::make_pair(it->first,nova));
        }
    }
    ~Biblioteka(){
        for(auto it=korisnici.begin();it!=korisnici.end();it++){
            delete it->second;
        }
    }
    Biblioteka &operator =(const Biblioteka &b){
        for(auto it=korisnici.begin();it!=korisnici.end();it++){
            delete it->second;
        }
        for(auto it=b.korisnici.begin();it!=b.korisnici.end();it++){
            Korisnik *novi=new Korisnik;
            (*novi).ime=(*(it->second)).ime;
            (*novi).prezime=(*(it->second)).prezime;
            (*novi).adresa=(*(it->second)).adresa;
            (*novi).telefon=(*(it->second)).telefon;
            korisnici.insert(std::make_pair(it->first,novi));
        }
        for(auto it=b.knjige.begin();it!=b.knjige.end();it++){
            auto nova=std::make_shared<Knjiga>((*(it->second)).DajNaslov(),(*(it->second)).DajAutora(),(*(it->second)).DajZanr(),(*(it->second)).DajGodinuIzdavanja());
            auto p=(*nova).DajKodKogaJe();
            p=(*(it->second)).DajKodKogaJe();
            knjige.insert(std::make_pair(it->first,nova));
        }
        return *this;
    }
    Biblioteka(Biblioteka &&b){
        for(auto it=b.korisnici.begin();it!=b.korisnici.end();it++){
            korisnici.insert(std::make_pair(it->first,it->second));
            it->second=nullptr;
        }
        for(auto it=b.knjige.begin();it!=b.knjige.end();it++){
            knjige.insert(std::make_pair(it->first,it->second));
            it->second=nullptr;
        }
    }
    Biblioteka &operator =(Biblioteka &&b){
        for(auto it=korisnici.begin();it!=korisnici.end();it++){
            delete it->second;
        }
        for(auto it=b.korisnici.begin();it!=b.korisnici.end();it++){
            korisnici.insert(std::make_pair(it->first,it->second));
            it->second=nullptr;
        }
        for(auto it=b.knjige.begin();it!=b.knjige.end();it++){
            knjige.insert(std::make_pair(it->first,it->second));
            it->second=nullptr;
        }
        return *this;
    }
    void RegistrirajNovogKorisnika(int clanskibr,std::string im,std::string prez,std::string adr,std::string brtel){
        Korisnik *novi=new Korisnik;
        (*novi).ime=im;
        (*novi).prezime=prez;
        (*novi).adresa=adr;
        (*novi).telefon=brtel;
        if(!korisnici.count(clanskibr))
        korisnici.insert(std::make_pair(clanskibr,novi));
        else throw std::logic_error("Korisnik vec postoji");
    }
    void RegistrirajNovuKnjigu(int brknjige,std::string naslov1,std::string autor,std::string zanr1,int godina){
        auto nova=std::make_shared<Knjiga>(naslov1,autor,zanr1,godina);
        if(!knjige.count(brknjige))
        knjige.insert(std::make_pair(brknjige,nova));
        else throw std::logic_error("Knjiga vec postoji");
    }
    Korisnik &NadjiKorisnika(int clanskibr){
        if(korisnici.count(clanskibr))
        return *(korisnici[clanskibr]);
        else throw std::logic_error("Korisnik nije nadjen");
    }
    Knjiga &NadjiKnjigu(int brknjige){
        if(knjige.count(brknjige))
        return *(knjige[brknjige]);
        else throw std::logic_error("Knjiga nije nadjena");
    }
    void IzlistajKorisnike() const{
        for(auto it=korisnici.begin();it!=korisnici.end();it++){
            cout<<"Clanski broj: "<<it->first<<std::endl;
            cout<<"Ime i prezime: "<<(*(it->second)).ime<<" "<<(*(it->second)).prezime<<std::endl;
            cout<<"Adresa: "<<(*(it->second)).adresa<<std::endl;
            cout<<"Broj telefona: "<<(*(it->second)).telefon<<std::endl;
            cout<<std::endl;
        }
    }
    void IzlistajKnjige() const{
        for(auto it=knjige.begin();it!=knjige.end();it++){
            cout<<"Evidencijski broj: "<<it->first<<std::endl;
            cout<<"Naslov: "<<(*(it->second)).DajNaslov()<<std::endl;
            cout<<"Pisac: "<<(*(it->second)).DajAutora()<<std::endl;
            cout<<"Zanr: "<<(*(it->second)).DajZanr()<<std::endl;
            cout<<"Godina izdavanja: "<<(*(it->second)).DajGodinuIzdavanja()<<std::endl;
            if((*(it->second)).DajKodKogaJe())
            cout<<"Zaduzena kod korisnika: "<<(*((*(it->second)).DajKodKogaJe())).ime<<" "<<(*((*(it->second)).DajKodKogaJe())).prezime<<std::endl;
            cout<<std::endl;
        }
    }
    void ZaduziKnjigu(int brknjige,int clanskibr){
        if(!knjige.count(brknjige)) throw std::logic_error("Knjiga nije nadjena");
        if(!korisnici.count(clanskibr)) throw std::logic_error("Korisnik nije nadjen");
        if((*(knjige[brknjige])).DajKodKogaJe()) throw std::logic_error("Knjiga vec zaduzena");
        (*(knjige[brknjige])).ZaduziKnjigu(*(korisnici[clanskibr]));
    }
    void RazduziKnjigu(int brknjige){
        if(!knjige.count(brknjige)) throw std::logic_error("Knjiga nije nadjena");
        if(!((*(knjige[brknjige])).DajKodKogaJe())) throw std::logic_error("Knjiga nije zaduzena");
        auto p=(*(knjige[brknjige])).DajKodKogaJe();
        p=nullptr;
    }
    void PrikaziZaduzenja(int clanskibr){
        int brojac(0);
        if(!korisnici.count(clanskibr)) throw std::logic_error("Korisnik nije nadjen");
        for(auto it=knjige.begin();it!=knjige.end();it++){
            if((*(it->second)).DajKodKogaJe()==nullptr)
            continue;
            if((*((*(it->second)).DajKodKogaJe())).ime==(*korisnici[clanskibr]).ime && (*((*(it->second)).DajKodKogaJe())).prezime==(*korisnici[clanskibr]).prezime && (*((*(it->second)).DajKodKogaJe())).adresa==(*korisnici[clanskibr]).adresa && (*((*(it->second)).DajKodKogaJe())).telefon==(*korisnici[clanskibr]).telefon){
                cout<<"Evidencijski broj: "<<it->first<<std::endl;
                cout<<"Naslov: "<<(*(it->second)).DajNaslov()<<std::endl;
                cout<<"Pisac: "<<(*(it->second)).DajAutora()<<std::endl;
                cout<<"Zanr: "<<(*(it->second)).DajZanr()<<std::endl;
                cout<<"Godina izdavanja: "<<(*(it->second)).DajGodinuIzdavanja()<<std::endl;
                cout<<std::endl;
                brojac++;
            }
        }
        if(brojac==0) cout<<"Nema zaduzenja za tog korisnika!";
    }
};

int main ()
{
    Biblioteka bibl;
    for(;;){
        int n;
        cout<<"Odaberite jednu od opcija: "<<std::endl;
        cout<<"0 - za kraj"<<std::endl;
        cout<<"1 - za unos novog korisnika"<<std::endl;
        cout<<"2 - za unos nove knjige"<<std::endl;
        cout<<"3 - za zaduzenje knjige"<<std::endl;
        cout<<"4 - za razduzenje knjige"<<std::endl;
        cin>>n;
        if(n==0) break;
        if(n==1){
            cout<<"Unesite sljedece podatke za korisnika: "<<std::endl;
            cout<<"Clanski broj: ";
            int clanskibr;
            cin>>clanskibr;
            cout<<"Ime: ";
            std::string ime;
            cin.ignore(1000,'\n');
            std::getline(cin,ime);
            cout<<"Prezime: ";
            std::string prezime;
            std::getline(cin,prezime);
            cout<<"Adresa: ";
            std::string adresa;
            std::getline(cin,adresa);
            cout<<"Telefon: ";
            std::string telefon;
            std::getline(cin,telefon);
            bibl.RegistrirajNovogKorisnika(clanskibr,ime,prezime,adresa,telefon);
            bibl.IzlistajKorisnike();
        }
        if(n==2){
            cout<<"Unesite sljedece informacije o knjizi: "<<std::endl;
            cout<<"Evidencijski broj: ";
            int brknjige;
            cin>>brknjige;
            cin.ignore(1000,'\n');
            cout<<"Naslov: ";
            std::string naslov;
            std::getline(cin,naslov);
            cout<<"Autor: ";
            std::string autor;
            std::getline(cin,autor);
            cout<<"Zanr: ";
            std::string zanr;
            std::getline(cin,zanr);
            cout<<"Godina izdavanja: ";
            int godina;
            cin>>godina;
            cin.ignore(1000,'\n');
            bibl.RegistrirajNovuKnjigu(brknjige,naslov,autor,zanr,godina);
            bibl.IzlistajKnjige();
        }
        if(n==3){
            cout<<"Unesite evidencijski broj knjige i clanski broj korisnika: ";
            int brknjige,clanskibr;
            cin>>brknjige>>clanskibr;
            cin.ignore(1000,'\n');
            bibl.ZaduziKnjigu(brknjige,clanskibr);
            bibl.PrikaziZaduzenja(clanskibr);
        }
        if(n==4){
            cout<<"Unesite evidencijski broj knjige: ";
            int brknjige;
            cin>>brknjige;
            cin.ignore(1000,'\n');
            bibl.RazduziKnjigu(brknjige);
        }
    }
	return 0;
}