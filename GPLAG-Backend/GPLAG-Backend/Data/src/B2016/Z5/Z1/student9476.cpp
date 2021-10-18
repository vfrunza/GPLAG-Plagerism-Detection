/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <new>

using std::string;
struct Korisnik {
    string ime, prezime, adresa, telefon;
    
};
class Knjiga{
    friend class Biblioteka;
    string naslov, ime_pisca, zanr;
    int god_izdavanja;
    Korisnik* zaduzena;
public:
    Knjiga(string title, string author, string genre, int published) :naslov(title), ime_pisca(author), zanr(genre), god_izdavanja(published), zaduzena(nullptr) {};
    string DajNaslov() const { return naslov;}
    string DajAutora() const {return ime_pisca;}
    string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return god_izdavanja;}
    Korisnik* DajKodKogaJe() const {return zaduzena;}
    void ZaduziKnjigu( Korisnik &k){ zaduzena=&k;}
    void RazduziKnjigu() {zaduzena=nullptr;}
    bool DaLiJeZaduzena()
        {
            if(zaduzena!=nullptr) return true;
            return false;
        }
};
    class Biblioteka{
        std::map<int, Korisnik*> korisnici;
        std::map<int, Knjiga*> knjige;
    public:
    Biblioteka(){};
    Biblioteka(Biblioteka &b)
    {  
        for(auto x: b.korisnici) korisnici.insert(std::make_pair(x.first, new Korisnik(*x.second)));
        for(auto y: b.knjige) knjige.insert(std::make_pair(y.first, new Knjiga(*y.second)));
    }
    Biblioteka(Biblioteka &&b)
    {
        for(auto x: b.korisnici) korisnici.insert(std::make_pair(x.first, x.second));
        for(auto y: b.knjige) knjige.insert(std::make_pair(y.first, y.second));
    }
    
   ~Biblioteka() 
   {
       for(auto x: korisnici) delete x.second;
       for(auto y: knjige) delete y.second;
   }
       
      void RegistrirajNovogKorisnika(int ID, string ime_k, string prezime_k, string add, string tel)
       {
           for(auto x: korisnici)
           {
               if(x.first==ID) throw std::logic_error ("Korisnik vec postoji");
           }
           
           Korisnik*k=new Korisnik;
          (*k).ime=ime_k; (*k).prezime=prezime_k; (*k).adresa=add; (*k).telefon=tel;
           
          korisnici.insert(std::make_pair(ID, k ));
           
       }
      void RegistrirajNovuKnjigu(int ID, string title, string author, string genre, int published)
        {
            for(auto x: knjige)
            {
                if(x.first==ID) throw std::logic_error("Knjiga vec postoji");
            }
            Knjiga k(title, author, genre, published);
            knjige.insert(std::make_pair(ID,new Knjiga(k)));
            
        }
        Knjiga &NadjiKnjigu(int ID)
        {   
            for(auto x: knjige)
            {   
                
                if(x.first==ID) return *x.second;
            }
            throw std::logic_error("Knjiga nije nadjena");
        }
        Korisnik &NadjiKorisnika(int ID)
        {
            for(auto x: korisnici)
            {
                if(x.first==ID) return *x.second;
            }
            throw(std::logic_error("Korisnik nije nadjen"));
        }
      void IzlistajKorisnike() const
      {
          for(auto x: korisnici)
          {
              std::cout<<"Clanski broj: " <<x.first<<std::endl;
              std::cout<<"Ime i prezime: "<<x.second->ime<<" "<<x.second->prezime<<std::endl;
              std::cout<<"Adresa: "<<x.second->adresa<<std::endl;
              std::cout<<"Broj telefona: "<<x.second->telefon<<std::endl;
          }
      }
      void IzlistajKnjige() const
      {
          for(auto x: knjige)
          {
              std::cout<<"Evidencijski broj: "<<x.first<<std::endl;
              std::cout<<"Naslov: "<<x.second->DajNaslov()<<std::endl;
              std::cout<<"Pisac: "<<x.second->DajAutora()<<std::endl;
              std::cout<<"Zanr: "<<x.second->DajZanr()<<std::endl;
              std::cout<<"Godina izdavanja: "<<x.second->DajGodinuIzdavanja()<<std::endl;
              if(x.second->DajKodKogaJe()!=nullptr)
              {
                  std::cout<<"Zaduzena kod korisnika: "<<(x.second->DajKodKogaJe())->ime<<" "<<(x.second->DajKodKogaJe())->prezime<<std::endl;
              }
              std::cout<<std::endl;
          }
      }
       
       void ZaduziKnjigu(int book_ID, int user_ID)
       {
           if(!knjige.count(book_ID)) throw std::logic_error("Knjiga nije nadjena");
           if(!korisnici.count(user_ID)) throw std::logic_error("Korisnik nije nadjen");
           for(auto x: knjige)
           {
               if(x.first==book_ID)
               {
                   if(x.second->zaduzena!=nullptr) throw std::logic_error("Knjiga vec zaduzena");
                    else
                    {
                        for(auto y:korisnici)
                        {
                            if(y.first==user_ID)
                            {
                               x.second->zaduzena=y.second;
                            }
                        }
                    }
                   break;
               }
           }
            
           
       }
       
       
      void RazduziKnjigu(int book_ID)
       {
           if(!knjige.count(book_ID)) throw std::logic_error("Knjiga nije nadjena");
           for(auto x: knjige)
           {
               if(x.first==book_ID)
               {
                   if(x.second->zaduzena!=nullptr)
                    
                        for(auto y:korisnici)
                        {
                            if(y.second==x.second->zaduzena)
                            {
                               x.second->zaduzena=nullptr;
                            }
                        }
                    
                   break;
               }
           }
            
       }
    /*   void PrikaziZaduzenja(int user_ID)
       {
          for(auto x:knjige)
          {
            for(auto y:korisnici)
            {
               if(y==user_ID)
               {
                   if(x.second->zaduzena==y)
                   
               }
            }
          }
       }
       
       */
      
       
    };

int main ()
{
	return 0;
}