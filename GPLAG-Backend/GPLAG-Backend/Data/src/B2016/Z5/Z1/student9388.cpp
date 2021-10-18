/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <new>
#include <map>
#include <iterator>
#include <utility>
#include <stdexcept>
#include <algorithm>
struct Korisnik{
   std::string ime;
   std::string prezime;
   std::string adresa;
   std::string telefon;
};
class Knjiga{
    std::string naslov_knjige, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *zaduzena;
    public:
     Knjiga(std::string naslov_knjige, std::string ime_pisca, std::string zanr, int godina_izdavanja) : naslov_knjige(naslov_knjige), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), zaduzena(nullptr){}
     std::string DajNaslov() const { return naslov_knjige;}
     std::string DajAutora() const { return ime_pisca;}
     std::string DajZanr() const { return zanr;}
     int DajGodinuIzdavanja() const { return godina_izdavanja;}
     Korisnik *DajKodKogaJe() const { return zaduzena;}
     void ZaduziKnjigu(Korisnik &korisnik){ zaduzena=&korisnik;}
     void RazduziKnjigu(){ zaduzena=nullptr;}
     bool DaLiJeZaduzena() const{ return zaduzena;}
    // Korisnik *DajKodKogaJe() const{ return zaduzena;}
};
class Biblioteka{
    std::map<int, Korisnik*> mapa_korisnika;
    std::map<int, Knjiga*> mapa_knjiga;
    public:
     Biblioteka(){}
     Biblioteka(const Biblioteka &b);
     ~Biblioteka(){
         for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
          delete it->second;
     }
     void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa,std::string telefon);
     Korisnik &NadjiKorisnika(int clanski_broj) const;
};
void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
 Korisnik *korisnik{nullptr};
 for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
  if(clanski_broj==it->first) throw std::logic_error("Korsinik vec postoji");
  korisnik=new Korisnik;
 korisnik->ime=ime;
 korisnik->prezime=prezime;
 korisnik->adresa=adresa;
 korisnik->telefon=telefon;
 mapa_korisnika.insert(std::make_pair(clanski_broj,korisnik));
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) const{
    auto it(mapa_korisnika.find(clanski_broj));
    if(it==mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    return it->second;
}
int main (){
   Korisnik korisnik{"Senija", "Biogradlija", "Bulevar Eze Arnautovica 2", "032/223-845"};    
   Knjiga knjiga("Lesi se vraca kuci", "Eric Knight", "Roman", 1940);
   std::cout <<knjiga.DajNaslov()<<" "<<knjiga.DajAutora()<<" "<<knjiga.DajZanr()<<" "<<knjiga.DajGodinuIzdavanja()<<" ";
   Biblioteka b;
   b.RegistrirajNovogKorisnika(12345,"Senija","Biogradlija","Bulevar Eze Arnautovica 2","032/223-845");
	return 0;
}