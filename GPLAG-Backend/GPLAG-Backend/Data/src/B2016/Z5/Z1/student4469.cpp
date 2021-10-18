/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <memory>
#include <map>

struct Korisnik {

std::string ime,prezime,adresa,telefon;

};

class Knjiga { 

std::string naslov, ime_pisca,zanr;
int godizd;
Korisnik* p;
public:
Knjiga(std::string Naslov, std::string Ime_pisca,std::string Zanr, int Godizd, bool zaduzen) {
    naslov=Naslov;
    ime_pisca=Ime_pisca;
    zanr=Zanr;
    godizd=Godizd;
    p=nullptr;
    
}

std::string DajNaslov() const { return naslov;}
std::string DajAutora() const {return ime_pisca;}
std::string DajZanr() const {return zanr;}
int DajGodinuIzdavanja () const {return godizd;}
Korisnik DajKodKogaJe () const {return *p;}

void ZaduziKnjigu (Korisnik &user) {
    
    p=&user;
    
    
}
void RazduziKnjigu ();
bool DaliJeZaduzena();

};


class Biblioteka {
    
  
  std::map<int,Korisnik*> mapakorisnika;
  std::map<int,Knjiga*> mapaknjiga;
 Biblioteka() {
     
 } 
    
    void RegistrirajNovogKorisnika(int clanskibroj, std::string ime, std::string prezime, std::string adresa, std::string brojtel) {
        
       struct Korisnik* p=new struct Korisnik;
        
        (*p).ime=ime;(*p).prezime=prezime;(*p).adresa=adresa;(*p).telefon=brojtel;
        
        
        auto it(mapakorisnika.find(clanskibroj));
        if(it==mapakorisnika.end()) {
        mapakorisnika.insert(std::make_pair(clanskibroj,p));
        }
        
        else {
            throw std::logic_error ("Korisnik vec postoji");
        }
        
        
    }
    
    void RegistrirajNovuKnjigu(int evidbroj, std::string naslov, std::string imepisca, std::string zanr, int godina) {
        
        
       class Knjiga*p=new class Knjiga(naslov,imepisca,zanr,godina,false);
        
    
        
        auto it(mapaknjiga.find(evidbroj));
        if(it==mapaknjiga.end())
        mapaknjiga.insert(std::make_pair(evidbroj,p));
        
        else {
            throw std::logic_error("Knjiga vec postoji");
        }
        
        
    }
    
    
    Korisnik NadjiKorisnika (int clanskibroj) {
        
        auto it(mapakorisnika.find(clanskibroj));
        if (it==mapakorisnika.end())
        throw std::logic_error("Korisnik nije nadjen");
        
        
        return ( 
            *((*it).second));
        
    }
    
    
    
    
    Knjiga NadjiKnjigu (int evidbroj) {
        
        auto it(mapaknjiga.find(evidbroj));
        if(it==mapaknjiga.end())
        throw std::logic_error ("Knjiga nije nadjena");
    
    return  ( *((*it).second) );
    

    }
    
    
    void IzlistajKorisnike() {
    
    
    for(auto it=mapakorisnika.begin();it!=mapakorisnika.end();it++) {
        
       std::cout<<"Clanski broj: "<<it->first<<std::endl;
       std::cout<<"Ime i prezime: "<<(*(it->second)).ime<<" "<<(*(it->second)).prezime<<std::endl;
       std::cout<<"Adresa: "<< (*(it->second)).adresa<<std::endl;
        std::cout<<"Broj telefona: "<< (*(it->second)).telefon<<std::endl<<std::endl;
        
    }
    
    }
    
    void IzlistajKnjige() {
    
    
    
    for(auto it=mapaknjiga.begin();it!=mapaknjiga.end();it++) {
    
    std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
    std::cout<<"Naslov: "<< (*(it->second)).DajNaslov()<<std::endl;
    std::cout<<"Pisac: "<< (*(it->second)).DajAutora()<<std::endl;
    std::cout<<"Zanr: "<< (*(it->second)).DajZanr()<<std::endl;
    std::cout<<"Godina izdavanja: "<< (*(it->second)).DajGodinuIzdavanja()<<std::endl<<std::endl;
    if((*(it->second)).DajKodKogaJe()!=0) {
        
        Korisnik *pok=(it->second).DajKodKogaJe();
        
        for(auto it2=mapakorisnika.begin();it2!=mapakorisnika.end();it2++){
        
        if( (*(it2->second)).ime==(*pok).ime &&  (*(it2->second)).prezime==(*pok).prezime  && (*(it2->second)).adresa==(*pok).adresa &&  (*(it2->second)).telefon==(*pok).telefon ){
            
            std::cout<<"Zaduzena kod korisnika: "<<it2->first<<std::endl<<std::endl;
            
            break;
        }
    
        }
        
       
}


    }
    
    
    }
    
    
    
    void ZaduziKnjigu(int evidbroj, int clanskibroj) {
        
        
       auto it(mapakorisnika.find(clanskibroj));
        
        auto it2(mapaknjiga.find(evidbroj));
       
        
        
        
    }
    
    
    
    
    
    
    
    
    
    
};







int main ()
{
	return 0;
}