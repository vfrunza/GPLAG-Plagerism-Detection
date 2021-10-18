#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>
using std::cin;
using std::ws;
struct Korisnik{
    std::string ime,prezime,adresa,telefon;
};
class Knjiga{
  std::string naslov,ime_pisca,zanr;
  int godina_izdavanja;
  Korisnik* zaduzenje;
  public:
  Knjiga(std::string n,std::string i,std::string z,int g):naslov(n),ime_pisca(i),zanr(z),godina_izdavanja(g),zaduzenje(nullptr){};
  std::string DajNaslov()const{return naslov;}
  std::string DajAutora()const{return ime_pisca;}
  std::string DajZanr()const {return zanr;}
  int DajGodinuIzdavanja()const{return godina_izdavanja;}
  Korisnik* DajKodKogaJe()const{return zaduzenje;}
  void ZaduziKnjigu(Korisnik &a){zaduzenje=&a;}
  void RazduziKnjigu(){zaduzenje=nullptr;}
  bool DaLiJeZaduzena()const{return zaduzenje!=nullptr; }
};
class Biblioteka{
    std::map<int,Korisnik*> korisnici;
    std::map<int,Knjiga*> knjige;
    public:
    Biblioteka();
    Biblioteka(const Biblioteka &a);
    Biblioteka(Biblioteka &&a);
    Biblioteka& operator=(const Biblioteka &a);
    Biblioteka& operator=(Biblioteka&&a);
    ~Biblioteka();
    void RegistrirajNovogKorisnika(int cl_br,std::string i,std::string p,std::string adress, std::string br_tel);
    void RegistrirajNovuKnjigu(int evid_br,std::string n,std::string ime_p,std::string z,int god_izd);
    Korisnik& NadjiKorisnika(int cl_br){
      if(korisnici.find(cl_br)==korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
      return *korisnici[cl_br];  
  }
    Knjiga& NadjiKnjigu(int evid_br){
        if(knjige.find(evid_br)==knjige.end()) throw std::logic_error ("Knjiga nije nadjena");
        return *knjige[evid_br];
    }
    void IzlistajKorisnike();
    void IzlistajKnjige();
    void ZaduziKnjigu(int evid_br,int cl_br);
    void RazduziKnjigu(int evid_br){if (NadjiKnjigu(evid_br).DaLiJeZaduzena()) NadjiKnjigu(evid_br).RazduziKnjigu();
        else throw std::logic_error ("Knjiga nije zaduzena");
    }
    void PrikaziZaduzenja(int cl_br);
};
Biblioteka::Biblioteka(){}
Biblioteka::Biblioteka(const Biblioteka &a){
    
    for(auto it1(a.korisnici.begin()); it1!=a.korisnici.end(); it1++){
        korisnici[it1->first]=new Korisnik (*it1->second);
    }
    for(auto it(a.knjige.begin()); it!=a.knjige.end(); it++){
        knjige[it->first]=new Knjiga (*it->second);
    }
}
Biblioteka::Biblioteka(Biblioteka &&a){
    for(auto it1(a.korisnici.begin()); it1!=a.korisnici.end(); it1++){
        korisnici[it1->first]=it1->second;
        it1->second=nullptr;
    }
    for(auto it(a.knjige.begin()); it!=a.knjige.end(); it++){
        knjige[it->first]=it->second;
        it->second=nullptr;
    }
}
Biblioteka& Biblioteka::operator=(const Biblioteka &a){
    if(&a==this) throw std::logic_error ("Destruktivna samododjela!");
    for(auto it(knjige.begin()); it!=knjige.end(); it++){
        knjige.erase(it->first);
    }
    knjige.clear();
    {
    auto it2(korisnici.begin());
    for(auto it1(a.korisnici.begin()); it1!=a.korisnici.end(); it1++){
        for(; it2!=korisnici.end(); ){
            korisnici[it1->first]=new Korisnik (*it1->second);
            it2++;
            break;
    }
    }
    }
    auto it2(knjige.begin());
    for(auto it1(a.knjige.begin()); it1!=a.knjige.end(); it1++){
        for(; it2!=knjige.end(); it2++){
            it2->second=new Knjiga (*it1->second);
            it2++;
            break;
    }
    }
    return *this;
}
Biblioteka& Biblioteka::operator=(Biblioteka &&a){
    std::swap(korisnici,a.korisnici);
    std::swap(knjige,a.knjige);
    return *this;
}
Biblioteka::~Biblioteka(){
    for(auto it(knjige.begin()); it!=knjige.end(); it++){
        if(it->second!=nullptr)
            delete it->second;
    }
    for(auto it(korisnici.begin()); it!=korisnici.end(); it++){
        if(it->second!=nullptr)
            delete it->second;
    }
}
void Biblioteka::RegistrirajNovogKorisnika(int cl_br,std::string i,std::string p,std::string adress, std::string br_tel){
    if(korisnici.find(cl_br)!=korisnici.end()) throw std::logic_error ("Korisnik vec postoji");
    korisnici[cl_br]=new Korisnik;
    korisnici[cl_br]->ime=i;
    korisnici[cl_br]->prezime=p;
    korisnici[cl_br]->adresa=adress;
    korisnici[cl_br]->telefon=br_tel;
  //  std::cout<<"k";
}
void Biblioteka::RegistrirajNovuKnjigu(int evid_br,std::string n,std::string ime_p,std::string z,int god_izd){
    if(knjige.find(evid_br)!=knjige.end()) throw std::logic_error ("Knjiga vec postoji");
    knjige[evid_br]=new Knjiga (n,ime_p,z,god_izd);
}
void Biblioteka::IzlistajKorisnike(){
    for(auto it(korisnici.begin()); it!=korisnici.end(); it++){
        std::cout<<"Clanski broj: "<<it->first<<std::endl;
        std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
        std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl<<std::endl;
    }
}
void Biblioteka::IzlistajKnjige(){
    for(auto it(knjige.begin()); it!=knjige.end(); it++){
         std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
         std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
         std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
         std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
         std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
         if(it->second->DaLiJeZaduzena()){
             std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime;
         }
         std::cout<<std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int evid_br,int cl_br){
    NadjiKnjigu(evid_br);
    NadjiKorisnika(cl_br);
    if(NadjiKnjigu(evid_br).DaLiJeZaduzena()) throw std::logic_error ("Knjiga vec zaduzena");
    NadjiKnjigu(evid_br).ZaduziKnjigu(NadjiKorisnika(cl_br));
}
void Biblioteka::PrikaziZaduzenja(int cl_br){
    bool pom(true);
    Korisnik a=NadjiKorisnika(cl_br);
//std::cout<<"kffk";
    for(auto it(knjige.begin()); it!=knjige.end(); it++){
if((it->second->DajKodKogaJe()->ime==a.ime) &&(it->second->DajKodKogaJe()->prezime==a.prezime) && (it->second->DajKodKogaJe()->adresa==a.adresa) && (it->second->DajKodKogaJe()->telefon==a.telefon)){
            pom=false;
         std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
         std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
         std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
         std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
         std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl<<std::endl;
        }
    }
    if(pom) std::cout<<"Nema zaduzenja za tog korisnika";
}
int main ()
{
   for(;;){
        std::cout<<"Izaberite zeljenu opciju :"<<std::endl<<"1 za unos korisnika, 2 za unos knjige, 3 za ispis biblioteke, 4 za zaduzivanje knjige, 5 za razduzivanje, 6 izlistaj knjige zaduzene od jednog korisnika, 0 za izlaz: ";
        int opcija;
        std::cin>>opcija;
        Biblioteka aleksandrijska;
        switch(opcija){
            case 1:{
                    std::cout<<"Unesite clasnki broj, ime, prezime, adresu i broj telefona: ";
                    std::string i,p,a,br_tel;
                    int clanski;
                    cin>>clanski>>ws>>i>>ws>>p>>ws>>a>>ws>>br_tel;
                    aleksandrijska.RegistrirajNovogKorisnika(clanski,i,p,a,br_tel);
                break;
            }
            case 2:{
                std::cout<<"Unesite evidencijski broj, naslov, ime autora, žanr i godinu izdavanja: ";
                std::string n,i,z;
                int ev,god;
                cin>>ev>>ws>>n>>ws>>i>>ws>>z>>ws>>god;
                aleksandrijska.RegistrirajNovuKnjigu(ev,n,i,z,god);
                break;
            }
            case 3:{
                aleksandrijska.IzlistajKnjige();
                aleksandrijska.IzlistajKorisnike();
                break;
            }
            case 4:{
                std::cout<<"Unesite evidencijski broj i claski broj: ";
                int ev,cl;
                cin>>ws>>ev>>ws>>cl;
                aleksandrijska.ZaduziKnjigu(ev,cl);
                break;
            }
            case 5:{
                std::cout<<"Unesite evidencijski broj: ";
                int ev;
                cin>>ev;
                aleksandrijska.RazduziKnjigu(ev);
                break;
            }
            case 6:{
                std::cout<<"Unesite clasnki broj: ";
                int cl;
                cin>>cl;
                aleksandrijska.PrikaziZaduzenja(cl);
                break;
            }
            default: goto izlaz;
        }
    }  
izlaz:       
	return 0;
}