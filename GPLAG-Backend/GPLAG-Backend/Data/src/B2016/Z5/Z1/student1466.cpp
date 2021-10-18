#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

struct Korisnik {
    
std::string ime;
std::string prezime;
std::string adresa;
std::string telefon;
    
    
};


class Knjiga {
    
    std::string naslov;
    std::string ime;
    std::string zanr;
    int god;
    Korisnik *uzeo=nullptr;
    
    public:
    
    Knjiga (std::string a,std::string b,std::string c,int d) {
        
        naslov = a;
        ime = b;
        zanr = c;
        god = d;
        uzeo = nullptr;
        
    }
    
    std::string DajNaslov () const { return naslov; }
    
    std::string DajAutora () const { return ime; }
    
    std::string DajZanr () const { return zanr; } 
    
    int DajGodinuIzdavanja () const { return god; }
    
    Korisnik* DajKodKogaJe () const { return uzeo; }
    
    
    
     void ZaduziKnjigu(Korisnik &sitni) {
        
        uzeo = &sitni;

    }
    
    Korisnik* RazduziKnjigu () {
        
        uzeo = nullptr;
        return uzeo;
        
    }
    
    bool DaLiJeZaduzena () {  if (uzeo == nullptr) return false;
    else return true; }

    
};

class Biblioteka {
    
   std::map<int, Korisnik*> kor;
   std::map<int, Knjiga*> knjiga;
    
    public:
    
    Biblioteka () = default;

Biblioteka &operator =(const Biblioteka &l)
{
	kor = std::move (l.kor);
	knjiga = std::move (l.knjiga);
	return *this;
}


void RegistrirajNovogKorisnika(int br, std::string ime, std::string prezime, std::string adresa, std::string broj) {

auto a = new Korisnik{ime,prezime,adresa,broj};

if(kor.count(br)>0) throw std::logic_error("Korisnik vec postoji");
else kor[br] = a;

 }
 
 void RegistrirajNovuKnjigu (int broj, std::string naslov, std::string ime, std::string zanr, int godina) {


auto a = new Knjiga{naslov,ime,zanr,godina};

if(knjiga.count(broj)>0) throw std::logic_error("Knjiga vec postoji");
else knjiga[broj] = a;

 }
 
 ~Biblioteka() {
      
      for (auto it = knjiga.begin(); it != knjiga.end(); it++) {

delete (it -> second );

}

      for (auto it = kor.begin(); it != kor.end(); it++) {

delete (it -> second );

}

 } 
 Korisnik &NadjiKorisnika (int br) {
     
    if(kor.count(br)>0) return *kor[br];
else throw std::logic_error("Korisnik nije nadjen");
 }
 
  Knjiga &NadjiKnjigu (int br) {
     
    if(knjiga.count(br)>0) return *knjiga[br];
else throw std::logic_error("Knjiga nije nadjena");
 }
 
  void IzlistajKorisnike () {
   
       for (auto it = kor.begin(); it != kor.end(); it++) {

std::cout<<"Clanski broj: "<<it->first; 
std::cout<<std::endl;   

std::cout<<"Ime i prezime: "<<(*(it->second)).ime<<" "<<(*(it->second)).prezime;
std::cout<<std::endl;   

std::cout<<"Adresa: "<<(*(it->second)).adresa;
std::cout<<std::endl;   

std::cout<<"Broj telefona: "<<(*(it->second)).telefon; 
std::cout<<std::endl;   
std::cout<<std::endl;
      } 
  }
  
    void IzlistajKnjige () {
   
       for (auto it = knjiga.begin(); it != knjiga.end(); it++) {
        
std::cout<<"Evidencijski broj: "<<it->first;
std::cout<<std::endl;   

std::cout<<"Naslov: "<<(*(it->second)).DajNaslov();
std::cout<<std::endl;   

std::cout<<"Pisac: "<<(*(it->second)).DajAutora();
std::cout<<std::endl;   

std::cout<<"Zanr: "<<(*(it->second)).DajZanr();
std::cout<<std::endl;   

std::cout<<"Godina izdavanja: "<<(*(it->second)).DajGodinuIzdavanja();
std::cout<<std::endl;   
if( (it->second)->DaLiJeZaduzena() == 1) std::cout<<"Zaduzena kod korisnika: "<<(*(*(it->second)).DajKodKogaJe()).ime<<" "<<(*(*(it->second)).DajKodKogaJe()).prezime<<std::endl;
std::cout<<std::endl;   

       }
  }

void ZaduziKnjigu (int broj, int clanski) {
 
     if(!knjiga.count(broj)) throw std::logic_error("Knjiga nije nadjena");
    if(!kor.count(clanski)) throw std::logic_error("Korisnik nije nadjen");
    if ( knjiga[broj] -> DaLiJeZaduzena() == 1 ) throw std::logic_error("Knjiga vec zaduzena");
   
     knjiga[broj] -> ZaduziKnjigu (*kor[clanski]);
 
 
} 


void RazduziKnjigu (int broj) {
 
     if(!knjiga.count(broj)) throw std::logic_error("Knjiga nije nadjena");
    if ( knjiga[broj] -> DaLiJeZaduzena() == 0 ) throw std::logic_error("Knjiga nije zaduzena");
   
     knjiga[broj] -> RazduziKnjigu();
 
 
} 


void PrikaziZaduzenja (int broj) {
 
    if(!kor.count(broj)) throw std::logic_error("Korisnik nije nadjen");
int brojac(0);
       for (auto it = knjiga.begin(); it != knjiga.end(); it++) {

     if ( (*(it->second)).DajKodKogaJe() == kor[broj])  {
      
      std::cout<<"Evidencijski broj: "<<it->first;
std::cout<<std::endl;   

std::cout<<"Naslov: "<<(*(it->second)).DajNaslov();
std::cout<<std::endl;   

std::cout<<"Pisac: "<<(*(it->second)).DajAutora();
std::cout<<std::endl;   

std::cout<<"Zanr: "<<(*(it->second)).DajZanr();
std::cout<<std::endl;   

std::cout<<"Godina izdavanja: "<<(*(it->second)).DajGodinuIzdavanja()<<std::endl;
 std::cout<<std::endl;
      brojac++;
     }


}
if (brojac == 0) std::cout<<"Nema zaduzenja za tog korisnika!";
 
} 



 };



int main ()
{
  
 std::cout<<"Pritisnite zeljenu opciju, 1 za novog korisnika, 2 za novu knjigu, 3 za prikaz, 0 za kraj: "<<std::endl;
  
  int b;
  std::cin>>b;
  Biblioteka bibl;
 while ( b != 0 ) 
 
 { if (b == 1) {
   
   std::cout<<"Podaci korisnika: ";
    int br;
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
    std::cin>>br;
    std::cin>>ime;
    std::cin>>prezime;
    std::cin>>adresa;
    std::cin>>telefon;
    
    bibl.RegistrirajNovogKorisnika(br,ime,prezime,adresa,telefon);

  }
  
  
if (b == 2) {
 
 std::cout<<"Podaci o knjizi: ";
    int br;
    std::string ime;
    std::string autor;
    std::string zanr;
    int god;
    std::cin>>br;
    std::cin>>ime;
    std::cin>>autor;
    std::cin>>zanr;
    std::cin>>god;
    
 bibl.RegistrirajNovuKnjigu(br,ime,autor,zanr,god);
 
}
  
if (b == 3) {
 
 bibl.IzlistajKnjige();
 bibl.IzlistajKorisnike();
 std::cout<<"Zaduzenja korisnika: ";
 int br;
 std::cin>>br;
 bibl.PrikaziZaduzenja(br);
 
}

std::cout<<"Opcija: ";
int b;
std::cin>>b;
}

	return 0;
}