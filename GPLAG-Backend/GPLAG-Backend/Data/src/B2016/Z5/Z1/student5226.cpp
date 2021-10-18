/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

struct Korisnik {
  std::string ime,prezime,adresa, telefon;  
};

class Knjiga {
  std::string naslov, ime_pisca,zanr;
  int godina_izdavanja;
  Korisnik *kod_koga_je;
  
  public:
  Knjiga(std:: string s1,std::string s2,std::string s3, int god){
      naslov=s1;
      ime_pisca=s2;
      zanr=s3;
      godina_izdavanja=god;
      kod_koga_je=nullptr;
  }
  
  std::string DajNaslov() const { return naslov; }
  std::string DajAutora() const { return ime_pisca;}
  std::string DajZanr() const {return zanr; }
  int DajGodinuIzdavanja() const { return godina_izdavanja; }
  Korisnik *DajKodKogaJe() const { return kod_koga_je; }
  
  void ZaduziKnjigu(Korisnik &korisnik){
      kod_koga_je=&korisnik;
  }
  void RazduziKnjigu() {
      kod_koga_je=nullptr;
  }
  bool DaLiJeZaduzena(){
      if(kod_koga_je==nullptr) return false;
      else return true;
  }
};


class Biblioteka {
    std::map<int,Korisnik*> korisnicka_mapa;
    std::map<int,Knjiga*> mapa_knjiga;
    
    public:
    
    void RegistrirajNovogKorisnika(int clanski_broj, std::string s1,std::string s2,std::string s3, std::string s4){
        Korisnik *pok;
        if(!korisnicka_mapa.count(clanski_broj)){
            try{
           pok=new Korisnik();
            pok->ime=s1;
            pok->prezime=s2;
            pok->adresa=s3;
            pok->telefon=s4;
            Korisnik *korisnik;
            korisnik=pok;
            korisnicka_mapa.insert(std::make_pair(clanski_broj,korisnik)); 
               
            }
            catch(...){
                delete pok;
                throw;
            }
        }
        else {
            throw std::logic_error("Korisnik vec postoji");
        }
       delete pok;
        
    }
    void RegistrirajNovuKnjigu(int clanski_broj, std::string s1,std::string s2,std::string s3,int godina){
        Knjiga *pok1;
        if(!mapa_knjiga.count(clanski_broj)){
            try{
            pok1=new Knjiga(s1,s2,s3,godina);
            Knjiga *knjiga;
            knjiga=pok1;
            mapa_knjiga.insert(std::make_pair(clanski_broj,knjiga));
            
            
          }
            catch(...) {
                delete pok1;
                throw; }
     }
        else {
            throw std::logic_error("Knjiga vec postoji");
        }
       delete pok1;
    }
    
    Korisnik NadjiKorisnika(int clanski_broj)
    {
        Korisnik korisnik;
        for(auto it=korisnicka_mapa.begin(); it!=korisnicka_mapa.end(); it++)
            if(!korisnicka_mapa.count(clanski_broj)) throw std::logic_error("Korisnik nije nadjen");
         
          for(auto it=korisnicka_mapa.begin();it!=korisnicka_mapa.end();it++)
          {if(korisnicka_mapa.count(clanski_broj))
          korisnik=*(it->second);
          
        }
        return korisnik;
    }
    
    Knjiga NadjiKnjigu(int clanski_broj){
        Knjiga knjiga(" "," "," ",0);
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end();it++)
            if(!mapa_knjiga.count(clanski_broj)) throw std::logic_error("Knjiga nije nadjena");
        for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++){
            if(mapa_knjiga.count(clanski_broj))
            knjiga=*(it->second);
        }    
        return knjiga;
    }
    
void IzlistajKorisnike() const {
    for(auto it=korisnicka_mapa.begin();it!=korisnicka_mapa.end(); it++){
        std::cout<<"Clanski broj: "<<it->first;
        
        std::cout<<"\nIme i prezime: "<<it->second->ime<<" "<<it->second->prezime;
        std::cout<<"\nAdresa: "<<it->second->adresa;
        std::cout<<"\nBroj telefona: "<<it->second->telefon;
        std::cout<<std::endl;
        std::cout<<std::endl;
    }
}    
void IzlistajKnjige() const {
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++){
        std::cout<<"Evidencijski broj: "<<it->first;
        std::cout<<"\nNaslov: "<<it->second->DajNaslov();
        std::cout<<"\nPisac: "<<it->second->DajAutora();
        std::cout<<"\nZanr: "<<it->second->DajZanr();
        std::cout<<"\nGodina izdavanja: "<<it->second->DajGodinuIzdavanja();
        if(it->second->DajKodKogaJe()!=nullptr) std::cout<<"Zaduzena kod korisnika: ";//ovdje dodati ime korisnika!!!!
        std::cout<<std::endl;
        std::cout<<std::endl;
    }
}

void ZaduziKnjigu(int broj_knjige,int broj_korisnika){
    int brojac(0),brojac2(0);
    for(auto it=korisnicka_mapa.begin();it!=korisnicka_mapa.end();it++){
        if(it->first==broj_korisnika){
            for(auto it1=mapa_knjiga.begin();it1!=mapa_knjiga.end();it1++){
                if(it1->first==broj_knjige)
                {
                    if(it1->second->DaLiJeZaduzena()==true) throw std::logic_error("Knjiga vec zaduzena");
                    else 
                    it1->second->ZaduziKnjigu(*(it->second));
                    break;
                }
                brojac++;
            }
            brojac2++;
            break;
        }
    }
    if(brojac2==korisnicka_mapa.size()) throw std::logic_error("Korisnik nije nadjen");
    if(brojac==mapa_knjiga.size()) throw std::logic_error("Knjiga nije nadjena");
}

void RazduziKnjigu(int broj_knjige){
    int brojac(0);
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++){
        if(it->first==broj_knjige) {
            if(it->second->DaLiJeZaduzena()==true) throw std::logic_error("Knjiga nije zaduzena");
            else  it->second->RazduziKnjigu();
            brojac++;
            break;
        }
    }
    if(brojac==mapa_knjiga.size()) throw std::logic_error("Knjiga nije nadjena");
}

void PrikaziZaduzenja(int broj_korisnika){
    for(auto it=korisnicka_mapa.begin();it!=korisnicka_mapa.end();it++){
        if(it->first==broj_korisnika){
            for(auto it1=mapa_knjiga.begin();it1!=mapa_knjiga.end();it1++){
                if(it1->second->DajKodKogaJe()==it->second){
                    std::cout<<"Naslov: "<<it1->second->DajNaslov();
                    std::cout<<"\nPisac: "<<it1->second->DajAutora();
                    std::cout<<"\nZanr: "<<it1->second->DajZanr();
                    std::cout<<"\nGodina izdavanja: "<<it1->second->DajGodinuIzdavanja();
                    std::cout<<std::endl;
                }
            }
        }
    }
}
 
};

int main ()
{
    
    Biblioteka b1;
    b1.RegistrirajNovogKorisnika(1,"Amina","Husic","Zmaja od Bosne bb", "062018738");
    b1.IzlistajKorisnike();
    std::cout<<b1.NadjiKorisnika(1).ime<<std::endl;
    Knjiga knj1{"Vlak u snijegu","Mato Lovrak","Roman",1931};
    Korisnik k1 {"Amina","Husic","Zmaja od bosne bb","123-456"};
    knj1.ZaduziKnjigu(k1);
    if(knj1.DaLiJeZaduzena()) std::cout<<"Knjiga je zauzeta\n";
    else std::cout<<"Knjiga je slobodna\n";
    knj1.RazduziKnjigu();
    if(knj1.DaLiJeZaduzena()) std::cout<<"Knjiga je zauzeta\n";
    else std::cout<<"Knjiga je slobodna";
   
	return 0;
}