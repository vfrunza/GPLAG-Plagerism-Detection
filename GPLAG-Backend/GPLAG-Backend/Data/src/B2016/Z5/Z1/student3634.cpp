/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
using std::string;

struct Korisnik{
    string ime, prezime, adresa, telefon;
};

class Knjiga{
    string knjiga, pisac, zanr;
    int g_izdavanja;
    Korisnik *zaduzenik;
  public:
    Knjiga (string knjiga, string pisac, string zanr(zanr), int g_izdavanja) :
    //Korisnik *zaduzeni
    knjiga (knjiga), pisac (pisac),zanr (zanr)
    {
    }
};







int main (){
        
	return 0;
}