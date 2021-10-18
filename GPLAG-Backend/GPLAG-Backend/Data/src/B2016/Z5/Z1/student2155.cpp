#include <iostream>
#include <string>
#include <map>
#include <algorithm>
struct Korisnik{
std::string ime,prezime,adresa,telefon;
};
class Knjiga{
    std::string naslov,ime_pisca,zanr;
    Korisnik *korisnik;
    int godina_izdavanja;
    public:
    Knjiga(std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja):
    naslov(naslov),ime_pisca(ime_pisca),zanr(zanr),godina_izdavanja(godina_izdavanja),
    korisnik(nullptr){}
    std::string DajNaslov() const{return naslov;}
    std::string DajAutora() const{return ime_pisca;}
    std::string DajZanr() const{return zanr;}
    int DajGodinuIzdavanja() const{return godina_izdavanja;}
    Korisnik* DajKodKogaJe() const{return korisnik;}
    void ZaduziKnjigu(Korisnik &k){Knjiga::korisnik=&k;}
    void RazduziKnjigu(){korisnik=nullptr;}
    bool DaLiJeZaduzena(){return korisnik;}
};
class Biblioteka{
    std::map<int,Korisnik*> korisnici;
    std::map<int,Knjiga*> knjige;
  public:
  Biblioteka(){}
  Biblioteka(const Biblioteka &k);
  Biblioteka &operator =(const Biblioteka &k);
  ~Biblioteka(){
      for(auto x:korisnici)delete x.second;
      for(auto x:knjige)delete x.second;
  }
  Biblioteka(Biblioteka &&k):korisnici(std::move(k.korisnici)),
  knjige(std::move(k.knjige)){}
  Biblioteka &operator =(Biblioteka &&k){
      for(auto x:korisnici)delete x.second;
      for(auto x:knjige)delete x.second;
     korisnici=std::move(k.korisnici);
     knjige=std::move(k.knjige);
     return *this;
  }
  void RegistrirajNovogKorisnika(int clanski_broj,std::string ime,
  std::string prezime,std::string adresa,std::string telefon);
  void RegistrirajNovuKnjigu(int evidencijski_broj,std::string naslov,
  std::string ime_pisca,std::string zanr,int godina_izdavanja);
  Korisnik &NadjiKorisnika(int clanski_broj);
  Knjiga &NadjiKnjigu(int evidencijski_broj);
  void IzlistajKorisnike() const;
  void IzlistajKnjige() const;
  void ZaduziKnjigu(int evidencijski_broj,int clanski_broj);
  void RazduziKnjigu(int evidencijski_broj);
  void PrikaziZaduzenja(int clanski_broj) const;
};
  Biblioteka::Biblioteka(const Biblioteka &k){
     try{
       for(auto x:k.korisnici){
         korisnici[x.first]=new Korisnik;
         korisnici[x.first]->ime=x.second->ime;
         korisnici[x.first]->prezime=x.second->prezime;
         korisnici[x.first]->adresa=x.second->adresa;
         korisnici[x.first]->telefon=x.second->telefon;
       }
       for(auto x:k.knjige){
         knjige[x.first]=new Knjiga(*x.second);
       }
     }catch(...){
       for(auto x: korisnici)delete x.second;
       for(auto x: knjige)delete x.second;
       throw;
     }
   }
   Biblioteka &Biblioteka::operator =(const Biblioteka &k){
    std::map<int,Korisnik*> tmp1;
    std::map<int,Knjiga*> tmp2;
     try{
       for(auto x:k.korisnici){
          tmp1[x.first]=new Korisnik;
          tmp1[x.first]->ime=x.second->ime;
          tmp1[x.first]->prezime=x.second->prezime;
          tmp1[x.first]->adresa=x.second->adresa;
          tmp1[x.first]->telefon=x.second->telefon;
       }
       for(auto x:k.knjige){
         tmp2[x.first]=new Knjiga(*x.second);
       }
        korisnici=std::move(tmp1);
        knjige=std::move(tmp2);
     }catch(...){
       for(auto x:tmp1)delete x.second;
       for(auto x:tmp2)delete x.second;
     }
     return *this;
   }
void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj,std::string ime,
  std::string prezime,std::string adresa,std::string telefon){
      if(korisnici.find(clanski_broj) != korisnici.end())
        throw std::logic_error("Korisnik vec postoji");
    korisnici[clanski_broj] = new Korisnik;
    korisnici[clanski_broj]->ime=ime;korisnici[clanski_broj]->prezime=prezime;
    korisnici[clanski_broj]->adresa=adresa;korisnici[clanski_broj]->telefon=telefon;
  }
 void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj,std::string naslov,
 std::string ime_pisca,std::string zanr,int godina_izdavanja){
      if(knjige.find(evidencijski_broj) != knjige.end())
        throw std::logic_error("Knjiga vec postoji");
        knjige[evidencijski_broj]=new Knjiga(naslov,ime_pisca,zanr,godina_izdavanja);
  }
  Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj){
      auto it(korisnici.find(clanski_broj));
      if(it != korisnici.end())
        return *korisnici[clanski_broj];
      else throw std::logic_error("Korisnik nije nadjen");  
  }
  Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj){
      auto it(knjige.find(evidencijski_broj));
      if(it != knjige.end())
        return *knjige[evidencijski_broj];
      else throw std::logic_error("Knjiga nije nadjena");  
  }
  void Biblioteka::IzlistajKorisnike() const{
      for(auto it(korisnici.begin());it != korisnici.end();it++){
          if(it != korisnici.begin())std::cout << "\n";
          std::cout << "Clanski broj: " << it->first << "\n";
          std::cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << "\n";
          std::cout << "Adresa: " << it->second->adresa << "\n";
          std::cout << "Broj telefona: " << it->second->telefon << "\n";
      }
  }
  void Biblioteka::IzlistajKnjige() const{
      for(auto it(knjige.begin());it != knjige.end();it++){
          if(it != knjige.begin())std::cout << "\n";
          std::cout << "Evidencijski broj: " << it->first << "\n";
          std::cout << "Naslov: " << it->second->DajNaslov() << "\n";
          std::cout << "Pisac: " << it->second->DajAutora() << "\n";
          std::cout << "Zanr: " << it->second->DajZanr() << "\n";
          std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << "\n";
          if(it->second->DaLiJeZaduzena()){
              std::cout << "Zaduzena kod korisnika: " << 
              it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime;
              
          }
      }
  }
  void Biblioteka::ZaduziKnjigu(int evidencijski_broj,int clanski_broj){
      auto k(knjige.find(evidencijski_broj));
      auto kor(korisnici.find(clanski_broj));
      if(k==knjige.end()){
          throw std::logic_error("Knjiga nije nadjena");
      }else if(k->second->DajKodKogaJe()){
          throw std::logic_error("Knjiga vec zaduzena");
      }else if(kor==korisnici.end()){
          throw std::logic_error("Korisnik nije nadjen");
      }
      k->second->ZaduziKnjigu(*kor->second);
  }
 void Biblioteka::RazduziKnjigu(int evidencijski_broj){
     auto k(knjige.find(evidencijski_broj));
     if(k == knjige.end())
        throw std::logic_error("Knjiga nije nadjena");
    else if(!k->second->DaLiJeZaduzena()){
        throw std::logic_error("Knjiga nije zaduzena");
    }
    k->second->RazduziKnjigu();
 }
 void Biblioteka::PrikaziZaduzenja(int clanski_broj) const{
     auto it(korisnici.find(clanski_broj));
     if(it == korisnici.end())
        throw std::logic_error("Korisnik nije nadjen");
    bool nema_zaduzenja(true);
    for(auto it1(knjige.begin());it1 != knjige.end();it1++){
        if(it1->second->DajKodKogaJe() == it->second){
          if(!nema_zaduzenja)std::cout << "\n";
          nema_zaduzenja=false;
          std::cout << "Evidencijski broj: " << it1->first << "\n";
          std::cout << "Naslov: " << it1->second->DajNaslov() << "\n";
          std::cout << "Pisac: " << it1->second->DajAutora() << "\n";
          std::cout << "Zanr: " << it1->second->DajZanr() << "\n";
          std::cout << "Godina izdavanja: " << it1->second->DajGodinuIzdavanja() << "\n";
        }
    }
    if(nema_zaduzenja)
        std::cout << "Nema zaduzenja za tog korisnika!";
 }
int main ()
{
    Knjiga a("a","a","b",1);
	return 0;
}