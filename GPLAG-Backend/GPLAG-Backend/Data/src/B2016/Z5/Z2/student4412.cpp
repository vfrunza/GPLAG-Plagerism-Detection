/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <utility>  
#include <stdexcept>
#include <algorithm>
#include <map>


struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga{
  std::string naslov, ime_pisca, zanr;
  int god_izdanja;
  Korisnik *pok=nullptr;
public:
   Knjiga (const std::string &Naslov, const std::string &Ime_pisca, const std::string &Zanr, const int &God_izdanja){
        naslov=Naslov;
        ime_pisca=Ime_pisca;
        zanr=Zanr;
        god_izdanja=God_izdanja;
   }
   std::string DajNaslov() const;
   std::string DajAutora() const;
   std::string DajZanr() const;
   int DajGodinuIzdavanja() const;
   Korisnik* DajKodKogaJe() const;
   void ZaduziKnjigu(Korisnik &x);
   void RazduziKnjigu();
   bool DaLiJeZaduzena();
   
};


std::string Knjiga::DajNaslov()const{
    return naslov;
}

std::string Knjiga::DajAutora() const{
    return ime_pisca;
}

std::string Knjiga::DajZanr() const{
    return zanr;
}

int Knjiga::DajGodinuIzdavanja() const{
    return god_izdanja;
}

Korisnik* Knjiga::DajKodKogaJe() const{
    return pok;
}

void Knjiga::ZaduziKnjigu(Korisnik &x){
    pok=&x;
}

void Knjiga::RazduziKnjigu(){
    pok=nullptr;
}

bool Knjiga::DaLiJeZaduzena(){
    if(pok==nullptr) return false;
    else return true;
} 


int main()
{
	return 0;
}