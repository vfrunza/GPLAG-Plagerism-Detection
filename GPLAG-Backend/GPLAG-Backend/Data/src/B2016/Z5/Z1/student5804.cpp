#include <iostream>
#include <map>
struct Korisnik {
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
    };
class Knjiga{
   std::string naslov_knjige;
   std::string ime_pisca;
   std::string zanr;
   int godina;
   Korisnik *zaduzenje=nullptr;
   public:
   Knjiga (std::string naslov, std::string ime, std::string tip, int g): naslov_knjige(naslov),ime_pisca(ime),zanr(tip),godina(g),zaduzenje(nullptr){
  }
  std::string DajNaslov () const {return naslov_knjige;}
  
  std::string DajAutora  ()  const {return ime_pisca;}
  std::string DajZanr    ()    const {return zanr;}
  int DajGodinuIzdavanja () const {return godina;}
  Korisnik *DajKodKogaJe () const {return zaduzenje;}
  void RazduziKnjigu() {
      zaduzenje=nullptr;}
  void ZaduziKnjigu (Korisnik &k) {
      zaduzenje=&k;
  }
  bool DaLiJeZaduzena(){
      if (zaduzenje==nullptr) return false;
      else return true;}
  };
class Biblioteka{
   std::map<int ,Korisnik * > m1;
   std::map<int , Knjiga *> m2;
    
    
};
int main ()
{
	return 0;
}