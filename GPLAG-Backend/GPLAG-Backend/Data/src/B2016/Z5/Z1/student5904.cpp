/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <new>
#include <stdexcept>

struct Korisnik{
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};
class Knjiga{
    std::string naslov;
    std::string ime_pisca;
    std::string zanr;
    int godina_izdavanja;
    Korisnik *pok;
    public:
    Knjiga(std::string naslov,std::string ime,std::string zanr,int godina): naslov(naslov),ime_pisca(ime),zanr(zanr),godina_izdavanja(godina){
        pok=nullptr;
    }
    std::string DajNaslov()const{
        return naslov;
    }
    std::string DajAutora()const{
        return ime_pisca;
    }
    std::string DajZanr()const{
        return zanr;
    }
    int DajGodinuIzdavanja()const{
        return godina_izdavanja;
    }
    Korisnik* DajKodKogaJe()const{
        return pok;
    }
    /////Daj kod koga je fali
    void ZaduziKnjigu(Korisnik &korisnik){
        pok=&korisnik;
    }
    void RazduziKnjigu(){
        pok=nullptr;
    }
    bool DaLiJeZaduzena()const{
        if( pok!=nullptr) return true;
        else return false;
    }
};
class Biblioteka{
  
    std::map<int, Korisnik *> korisnici;//prebaciti na glupe pok
    std::map<int, Knjiga*> knjige;
    public:
    Biblioteka(){};
    Biblioteka(const Biblioteka &bib);
    Biblioteka &operator=(const Biblioteka &x)=delete;
    void RegistrirajNovogKorisnika(int cl_br,std::string ime,std::string prezime,std::string adresa,std::string broj_tel){
        for(auto &x:korisnici)
            if(x.first==cl_br) throw std::logic_error("Korisnik vec postoji");
        try
        {
            Korisnik *kor=nullptr;
            kor=new Korisnik;
            kor->ime=ime;
            kor->prezime=prezime;
            kor->adresa=adresa;
            kor->telefon=broj_tel;
            korisnici.insert(std::make_pair(cl_br,kor));
        }
        catch(std::bad_alloc)
        {
            throw;
        }
    }
    void RegistrirajNovuKnjigu(int ev_br,std::string naziv, std::string ime_pisca,std::string zanr,int godina){
        for(auto &x:knjige){
            if(x.first==ev_br) throw std::logic_error("Knjiga vec postoji");
    
        }
        try
        {
            Knjiga *k=nullptr;
            k=new Knjiga(naziv,ime_pisca,zanr,godina);
            knjige.insert(std::make_pair(ev_br,k));
        }
        catch(std::bad_alloc)
        {
            throw;
        }
    }
    Korisnik &NadjiKorisnika(int br){
        for(auto &x: korisnici)
            if(x.first==br) return *x.second;//promijeniti
        throw std::logic_error("Korisnik nije nadjen");
        
    }
   Knjiga &NadjiKnjigu(int br){
        for(auto &x: knjige)
             if(x.first==br) return *(x.second);
        throw std::logic_error("Knjiga nije nadjena");
    }
   void IzlistajKorisnike()const{
      for(auto&x:korisnici)
      {
          std::cout<<"Clanski broj: "<<x.first<<"\n";
          std::cout<<"Ime i prezime: "<<x.second->ime<<" "<<x.second->prezime<<"\n";
          std::cout<<"Adresa: "<<x.second->adresa<<"\n";
          std::cout<<"Broj telefona: "<<x.second->telefon<<"\n\n";
          
      }
   }
   void IzlistajKnjige() const{
       for(auto &x:knjige)
       {
           std::cout<<"Evidencijski broj: "<<x.first<<"\n";
           std::cout<<"Naslov: "<<x.second->DajNaslov()<<"\n";
           std::cout<<"Pisac: "<<x.second->DajAutora()<<"\n";
           std::cout<<"Zanr: "<<x.second->DajZanr()<<"\n";
           std::cout<<"Godina izdavanja: "<<x.second->DajGodinuIzdavanja()<<"\n";
           if(x.second->DaLiJeZaduzena())
           {
               std::cout<<"Zaduzena kod korisnika: "<<x.second->DajKodKogaJe()->ime<<" "<<x.second->DajKodKogaJe()->prezime<<"\n";
           }
           std::cout<<"\n";
       }
   }
   void RazduziKnjigu(int broj){
       Knjiga *k=nullptr;
        for (auto &x:knjige)
        {
            if(x.first==broj)
            {
                k=x.second;
            }
        }
        if(k==nullptr) throw std::logic_error("Knjiga nije nadjena");
        if(!k->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
        k->RazduziKnjigu();
    }
    void ZaduziKnjigu(int knjiga,int korisnik)
    {
        Knjiga *k=nullptr;
        Korisnik *kor=nullptr;
        for(auto &x:knjige)
        {
            if (knjiga==x.first)
            {
               k=x.second;
            }
        }
        if (k==nullptr) throw std::logic_error("Knjiga nije nadjena");
        for(auto &x:korisnici)
        {
            if(korisnik==x.first)
            {
                kor=x.second;
            }
        }
        if(kor==nullptr) throw std::logic_error("Korisnik nije nadjen");
        if (k->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
        k->ZaduziKnjigu(*kor);
    }
     ~Biblioteka()
     {
         for(auto &x:korisnici)
         {
             delete x.second;
         }
         for(auto &x:knjige)
         {
             delete x.second;
         }
     }
};
int main ()
{
	return 0;
}