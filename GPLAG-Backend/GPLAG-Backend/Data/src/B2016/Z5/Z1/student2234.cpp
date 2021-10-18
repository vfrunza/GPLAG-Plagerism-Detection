/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>
struct Korisnik{
  std::string ime,prezime,adresa,telefon;  
};
class Knjiga{
  std::string naslov,pisac,zanr;
  int godina_izdavanja;
  Korisnik* kod_koga_je;
  public:
  Knjiga(std::string a,std::string b,std::string c,int g):naslov(a),pisac(b),zanr(c),godina_izdavanja(g),kod_koga_je(nullptr){
  }
  std::string DajNaslov()const{return naslov;}
  std::string DajAutora()const{return pisac;}
  std::string DajZanr()const{return zanr;}
  int DajGodinuIzdavanja()const{return godina_izdavanja;}
  Korisnik*DajKodKogaJe()const{return kod_koga_je;}
  bool DaLiJeZaduzena(){
      if(kod_koga_je==nullptr)return false;
      return true;
  }
  void ZaduziKnjigu( Korisnik& covjek){
      kod_koga_je=&covjek;
  }
  void RazduziKnjigu(){
      kod_koga_je=nullptr;
  }
};
class Biblioteka{
  std::map<int,Korisnik>korisnici;
  std::map<int,Knjiga>udzbenici;
};
int main ()
{
  Knjiga k("abc", "efg","ghi",1999);
  std::cout << k.DajNaslov() << std::endl << k.DajAutora() << std::endl << k.DajZanr() << std::endl << k.DajGodinuIzdavanja() << std::endl;
  Korisnik b;
  b.ime="a"; b.prezime="b"; b.adresa="c"; b.telefon="d";
  k.ZaduziKnjigu(b);
	return 0;
}