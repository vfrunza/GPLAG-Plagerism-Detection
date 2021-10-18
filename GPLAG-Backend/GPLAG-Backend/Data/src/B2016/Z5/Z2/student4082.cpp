/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>
struct Korisnik{
    std::string ime, prezime, adresa, telefon;
    };
    
class Knjiga{
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    std::shared_ptr<Korisnik> korisnici;
    static int broj_zaduzenih;
    static int broj_razduzenih;
public:
    Knjiga(std::string s1, std::string s2, std::string s3, int x){
        naslov=s1;
        ime_pisca=s2;
        zanr=s3;
        godina_izdavanja=x;
        korisnici=nullptr;
    }
    std::string DajNaslov() const{
        return naslov;
    }
    std::string DajAutora() const{
        return ime_pisca;
    }
    std::string DajZanr() const{
        return zanr;
    }
    int DajGodinuIzdavanja() const{
        return godina_izdavanja;
    }
    std::shared_ptr<Korisnik> DajKodKogaJe() const{
        return korisnici;
    }
    void ZaduziKnjigu(Korisnik &korisnici){
        // OVDJE
        auto pok=std::make_shared<Korisnik>();
        *pok = {korisnici.ime,korisnici.prezime,korisnici.adresa, korisnici.telefon};
        /*korisnici=std::make_shared<Korisnik>();
        korisnici = pok;*/
        
    }
    void RazduziKnjigu(){
        //broj_razduzenih ++;
        korisnici=nullptr;
    }
    bool DaLiJeZaduzena(){
        //bool a(false);
        //if(broj_zaduzenih==1) a=true;
        //return a;
        if(korisnici) return true;
        return false;
    }
    
};

class Biblioteka{
    std::map<int, std::shared_ptr<Korisnik>> korisnici;
    std::map<int, std::shared_ptr<Knjiga>> knjige;
    public:
    Biblioteka(){}
    Biblioteka(const Biblioteka &b){}
    Biblioteka(Biblioteka &&b){}
    Biblioteka& operator =(const Biblioteka &b){}
    Biblioteka& operator =(Biblioteka &&b){}
 
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona){
          for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
            if(it->first==clanski_broj) throw std::logic_error("Korisnik vec postoji");
        }
        
        auto pok=std::make_shared<Korisnik>();
        pok->ime=ime;
        pok->prezime=prezime;
        pok->adresa=adresa;
        pok->telefon=broj_telefona;
        korisnici.insert(std::pair<int,std::shared_ptr<Korisnik>> (clanski_broj,pok));
    }
    void RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja){
        for(auto it=knjige.begin(); it!=knjige.end(); it++){
            if(it->first==evidencijski_broj) throw std::logic_error("Knjiga vec postoji");
        }
       auto pok=std::make_shared<Knjiga>(naslov,ime_pisca,zanr,godina_izdavanja);
       knjige.insert(std::pair<int,std::shared_ptr<Knjiga>> (evidencijski_broj,pok));
    }
    Korisnik  &NadjiKorisnika(int clanski_broj){
        bool a(false);
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
            if(it->first==clanski_broj){
                a=true;
                break;
            }
        }
        if(!a) throw std::logic_error("Korisnik nije nadjen");
             for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
            if(it->first==clanski_broj){
               return *(it->second);
            }
        }
        
    }
    Knjiga &NadjiKnjigu(int evidencijski_broj){
        bool a(false);
        for(auto it=knjige.begin(); it!=knjige.end(); it++){
            if(it->first==evidencijski_broj){
                a=true;
                break;
            }
        }
        if(!a) throw std::logic_error("Knjiga nije nadjena");
             for(auto it=knjige.begin(); it!=knjige.end(); it++){
            if(it->first==evidencijski_broj){
               return *(it->second);
            }
        }
        
        
    }
    void IzlistajKorisnike() const{
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
            std::cout<<"Clanski broj: "<<it->first<<std::endl<<"Ime i prezime: "<<(*(it->second)).ime<<" "<<(*(it->second)).prezime<<std::endl<<"Adresa: "<<(*(it->second)).adresa<<std::endl<<"Broj telefona: "<<(*(it->second)).telefon<<std::endl<<std::endl;
        }
    }
    void IzlistajKnjige() const{
         for(auto it=knjige.begin(); it!=knjige.end(); it++){
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl<<"Naslov: "<<(*(it->second)).DajNaslov()<<std::endl<<"Pisac: "<<(*(it->second)).DajAutora()<<std::endl<<"Zanr: "<<(*(it->second)).DajZanr()<<std::endl<<"Godina izdavanja: "<<(*(it->second)).DajGodinuIzdavanja()<<std::endl;
            if((*(it->second)).DaLiJeZaduzena()){
                std::cout<<"Zaduzena kod korisnika: "<<((*(it->second)).DajKodKogaJe())->ime<<" "<<((*(it->second)).DajKodKogaJe())->prezime<<std::endl<<std::endl;
            }
            else std::cout<<std::endl;
        }
        
    }
   void ZaduziKnjigu(int evidencijski_broj, int clanski_broj){
       bool a(false);
        for(auto it=knjige.begin(); it!=knjige.end(); it++){
            if(it->first==evidencijski_broj){
                a=true;
                break;
            }
        }
        if(!a) throw std::logic_error("Knjiga nije nadjena");
   a=false;
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
            if(it->first==clanski_broj){
                a=true;
                break;
            }
        }
        if(!a) throw std::logic_error("Korisnik nije nadjen");
        
        for(auto it=knjige.begin(); it!=knjige.end(); it++){
            if(it->first==evidencijski_broj){
                if((*(it->second)).DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
                for(auto it1=korisnici.begin(); it1!=korisnici.end(); it1++){
                    if(it1->first==clanski_broj){
                        //  OVDJE
                        (*(it->second)).ZaduziKnjigu(*(it1->second));
                    }
                }
            }
            
        }
       
   }
   void RazduziKnjigu(int evidencijski_broj){
        bool a(false);
        for(auto it=knjige.begin(); it!=knjige.end(); it++){
            if(it->first==evidencijski_broj){
                a=true;
                break;
            }
        }
        if(!a) throw std::logic_error("Knjiga nije nadjena");
           for(auto it=knjige.begin(); it!=knjige.end(); it++){
            if(it->first==evidencijski_broj){
               if((*(it->second)).DaLiJeZaduzena()){
                   (*(it->second)).RazduziKnjigu();
                   
               }
               else throw std::logic_error("Knjiga nije zaduzena");
            }
        }
        
       
   }
   void PrikaziZaduzenja(int clanski_broj) const{
       bool postoji(false);
       for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
           if(it->first==clanski_broj){
               postoji=true;
               bool zaduzenja(false);
               for(auto it1=knjige.begin(); it1!=knjige.end(); it1++){
                   if((*(it1->second)).DaLiJeZaduzena()){
                       zaduzenja=true;
                       if(((*(it1->second)).DajKodKogaJe())->ime==(*(it->second)).ime && ((*(it1->second)).DajKodKogaJe())->prezime==(*(it->second)).prezime && ((*(it1->second)).DajKodKogaJe())->adresa==(*(it->second)).adresa && ((*(it1->second)).DajKodKogaJe())->telefon==(*(it->second)).telefon){
                           std::cout<<"Evidencijski broj: "<<it1->first<<std::endl<<"Naslov: "<<(*(it1->second)).DajNaslov()<<std::endl<<"Pisac: "<<(*(it1->second)).DajAutora()<<std::endl<<"Zanr: "<<(*(it1->second)).DajZanr()<<std::endl<<"Godina izdavanja: "<<(*(it1->second)).DajGodinuIzdavanja()<<std::endl<<std::endl;
                           
                       }
                   }
               }
               if(!zaduzenja) std::cout<<"Nema zaduzenja za tog korisnika!";
           }
       }
       if(!postoji) throw std::logic_error("Korisnik nije nadjen");
       
   }
    
    
};
int main ()
{

	return 0;
}
int Knjiga::broj_zaduzenih=0;
int Knjiga::broj_razduzenih=0;