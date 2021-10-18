/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <utility>
#include <memory>

struct Korisnik{
    std::string ime,prezime,adresa,telefon;
};

class Knjiga{
    std::string naslov,pisac,zanr;
    int godina;
    Korisnik *kodkogaje;
    public:
    Knjiga(std::string naslov1,std::string pisac1,std::string zanr1,int godina1){
        naslov=naslov1; pisac=pisac1; zanr=zanr1; godina=godina1;
        kodkogaje=nullptr;
    }
    std::string DajNaslov() {return naslov;}
    std::string DajAutora() {return pisac;}
    std::string DajZanr() {return zanr;}
    int DajGodinuIzdavanja() {return godina;}
    Korisnik *DajKodKogaJe() {return kodkogaje;}
    void ZaduziKnjigu(Korisnik &osoba){
        kodkogaje=&osoba;
    }
    void RazduziKnjigu(){
        kodkogaje=nullptr;
    }
    bool DaLiJeZaduzena(){
        if(kodkogaje!=nullptr) return true;
        return false;
    }
};

class Biblioteka{
    std::map<int,std::shared_ptr<Korisnik>> mapakorisnika;
    std::map<int,std::shared_ptr<Knjiga>> mapaknjiga;
    public:
    void RegistrirajNovogKorisnika(int broj, std::string ime1, std::string prezime1, std::string adresa1, std::string telefon1){
        for(auto it=mapakorisnika.begin();it!=mapakorisnika.end();it++){
            if(broj==it->first) throw std::logic_error("Korisnik vec postoji");
        }
        try{
            std::shared_ptr<Korisnik> novi(new Korisnik);
            novi->ime=ime1; novi->prezime=prezime1; novi->adresa=adresa1; novi->telefon=telefon1;
            mapakorisnika.insert(std::make_pair(broj,novi));
        }
        catch(...){
            throw;
        }
    }
    void RegistrirajNovuKnjigu(int broj, std::string naslov1, std::string pisac1, std::string zanr1, int godina1){
        for(auto it=mapaknjiga.begin(); it!=mapaknjiga.end();it++){
            if(broj==it->first) throw std::logic_error("Knjiga vec postoji");
        }
        try{
            std::shared_ptr<Knjiga> nova(new Knjiga{naslov1,pisac1,zanr1,godina1});
            mapaknjiga.insert(std::make_pair(broj,nova));
        }
        catch(...){
            throw;
        }
    }
    Korisnik &NadjiKorisnika(int broj){
        for(auto it=mapakorisnika.begin();it!=mapakorisnika.end();it++){
            if(broj==it->first) {
                return *(it->second);
            }
            else if(it==--(mapakorisnika.end())) throw std::logic_error("Korisnik nije nadjen");
        }
    }
    
    Knjiga &NadjiKnjigu(int broj){
        for(auto it=mapaknjiga.begin();it!=mapaknjiga.end();it++){
            if(broj==it->first) return *(it->second);
            else if(it==--(mapaknjiga.end())) throw std::logic_error("Knjiga nije nadjena");
        }
        
    }
    
    void IzlistajKorisnike() const{
        for(auto it=mapakorisnika.begin();it!=mapakorisnika.end();it++){
            std::cout<<"Clanski broj: "<<it->first<<std::endl;
            std::cout<<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<std::endl;
            std::cout<<"Adresa: "<<(it->second)->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<(it->second)->telefon<<std::endl;
            std::cout<<std::endl;
        }
    }
    
    void IzlistajKnjige() const{
        for(auto it=mapaknjiga.begin();it!=mapaknjiga.end();it++){
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<(it->second)->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<(it->second)->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<(it->second)->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl;
            if((it->second)->DaLiJeZaduzena()){
                auto tmp=((it->second)->DajKodKogaJe());
                std::cout<<"Zaduzena kod korisnika: "<<tmp->ime<<" "<<tmp->prezime;
            }  
            std::cout<<std::endl;
        }
    }
    
    void ZaduziKnjigu(int evbr, int clbr){
       bool postojiknjiga(false),postojikorisnik(false);
       for(auto it=mapaknjiga.begin();it!=mapaknjiga.end();it++){                   //provjere ...
            if(it->first==evbr) {
                postojiknjiga=true;
                if((it->second)->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");   //ako postoji, provjeri je li zaduzena..
                break;                                
            }
        }
        if(!(postojiknjiga)) throw std::logic_error("Knjiga ne postoji");   //ako knjiga nije pronadjena kroz cijelu petlju, bool ce ostati false i baca se izuzetak...
        for(auto it=mapakorisnika.begin(); it!=mapakorisnika.end(); it++){
            if(it->first==clbr) {
                postojikorisnik=true;
                break;
            }                               //ako pronadje, znaci da postoji i odmah prekida petlju
        }
        if(!(postojikorisnik)) throw std::logic_error("Korisnik ne postoji");   //analogno kao i za knjigu
        //zaduzivanje
        for(auto it=mapaknjiga.begin();it!=mapaknjiga.end();it++){
            for(auto it1=mapakorisnika.begin();it1!=mapakorisnika.end();it1++){
                if(it->first==evbr && it1->first==clbr) {             //kad nadje da su isti, postavi pokazivac i izlazi iz petlji
                  (it->second)->Knjiga::ZaduziKnjigu(*(it1->second));
                  break;
                }
            }
        }
    }
    
    void RazduziKnjigu(int evbr){
        for(auto it=mapaknjiga.begin(); it!=mapaknjiga.end();it++){
            if(it->first==evbr){                                     //ako pronadjemo knjigu u mapi, provjerimo je li zaduzena - ako nije baca se izuzetak, ako jest, postavljamo na nullptr i prekidamo petlju
                if(!((it->second)->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
                (it->second)->Knjiga::RazduziKnjigu();
                break;
            }
        }
    }
    void PrikaziZaduzenja(int clbr) const{
        bool postoji(false),imazaduzenja(false);
        for(auto it=mapakorisnika.begin();it!=mapakorisnika.end();it++){
            for(auto it1=mapaknjiga.begin();it1!=mapaknjiga.end();it++){
                if((it->first)==clbr){
                    postoji=true;
                    auto temp=(it1->second)->DajKodKogaJe();
                    if((it->second).get()==temp) {
                        imazaduzenja=true;
                        std::cout<<"Evidencijski broj: "<<it1->first<<std::endl;
                        std::cout<<"Naslov: "<<(it1->second)->DajNaslov()<<std::endl;
                        std::cout<<"Pisac: "<<(it1->second)->DajAutora()<<std::endl;
                        std::cout<<"Zanr: "<<(it1->second)->DajZanr()<<std::endl;
                        std::cout<<"Godina izdavanja: "<<(it1->second)->DajGodinuIzdavanja()<<std::endl;
                    }
                }
            }
        }
        if(!(imazaduzenja)) std::cout<<"Nema zaduzenja za tog korisnika!";
        if(!(postoji)) throw std::logic_error("Korisnik nije nadjen");
    }
};

int main(){
    std::cout<<"Izaberite opciju: 1 za registrovanje novog korisnika, 2 za registrovanje nove knjige, \n3 za nalazenje korisnika, 4 za nalazenje knjige, \n5 za zaduzivanje knjige, 6 za razduzivanje knjige, \n7 za izlistavanje zaduzenja, 8 za izlistavanje korisnika, \n9 za izlistavanje knjiga, 0 za kraj:";
   int opcija(1);
   Biblioteka bib;
   int broj;
   while(opcija!=0){
       std::cout<<"\nOpcija: ";
       std::cin>>opcija;
       if(opcija==1){
           std::cout<<"Unesite podatke o korisniku kojeg zelite registrovati: ";
           std::string ime,prezime,adresa,telefon;
           std::cin>>broj;
           std::cin.ignore(1000,'\n');
           std::getline(std::cin, ime);
           std::getline(std::cin,prezime);
           std::getline(std::cin,adresa);
           std::getline(std::cin,telefon);
           try{
               bib.RegistrirajNovogKorisnika(broj,ime,prezime,adresa,telefon);
           }
           catch(std::logic_error izuzetak){
               std::cout<<izuzetak.what();
           }
       }
       else if(opcija==2){
           std::cout<<"Unesite podatke o knjizi koju zelite registrovati: ";
           std::string naslov,pisac,zanr;
           int godina;
           std::cin>>broj;
           std::cin.ignore(1000,'\n');
           std::getline(std::cin, naslov);
           std::getline(std::cin,pisac);
           std::getline(std::cin,zanr);
           std::cin>>godina;
           try{
               bib.RegistrirajNovuKnjigu(broj,naslov,pisac,zanr,godina);
           }
           catch(std::logic_error izuzetak){
               std::cout<<izuzetak.what();
           }
       }
       else if(opcija==3){
           std::cout<<"Unesite clanski broj korisnika kojeg zelite naci: ";
           std::cin>>broj;
           try{
               Korisnik k=bib.NadjiKorisnika(broj);
               std::cout<<k.ime<<" "<<k.prezime<<" "<<k.adresa<<" "<<k.telefon<<std::endl;
           }
           catch(std::logic_error izuzetak){
               std::cout<<izuzetak.what();
           }
       }
       else if(opcija==4){
           std::cout<<"Unesite evidencijski broj knjige koju zelite naci: ";
           std::cin>>broj;
           try{
               Knjiga k=bib.NadjiKnjigu(broj);
               std::cout<<k.DajNaslov()<<" "<<k.DajAutora()<<" "<<k.DajZanr()<<" "<<k.DajGodinuIzdavanja()<<std::endl;
           }
           catch(std::logic_error izuzetak){
               std::cout<<izuzetak.what();
           }
       }
       else if(opcija==5){
           std::cout<<"Unesite evidencijski broj knjige koju zelite zaduziti, i clanski broj korisnika kod kojeg je zelite zaduziti: ";
           int ebr, cbr;
           std::cin>>ebr>>cbr;
           try{
               bib.ZaduziKnjigu(ebr,cbr);
           }
           catch(std::logic_error izuzetak){
               std::cout<<izuzetak.what();
           }
       }
       else if(opcija==6){
           std::cout<<"Unesite evidencijski broj knjige koju zelite razduziti: ";
           std::cin>>broj;
           try{
               bib.RazduziKnjigu(broj);
           }
           catch(std::logic_error izuzetak){
               std::cout<<izuzetak.what();
           }
       }
       else if(opcija==7){
            std::cout<<"Unesite clanski broj korisnika cija zaduzenja zelite prikazati: ";
            std::cin>>broj;
            try{
                bib.PrikaziZaduzenja(broj);
            }
            catch(std::logic_error izuzetak){
                std::cout<<izuzetak.what();
            }
       }
       else if(opcija==8){
           bib.IzlistajKorisnike();
       }
       else if(opcija==9){
           bib.IzlistajKnjige();
       }
       else break;
       
   }
	return 0;
}