/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
struct Korisnik{
    std::string ime;std::string prezime;std::string adresa;std::string telefon;
};
class Knjiga{
    std::string naslov;std::string ime_pisca;std::string zanr;int god_izdavanja;
    Korisnik &kod_koga_je;
    public:
    Knjiga(std::string ime_pisca1,std::string zanr1,int god_izdavanja1,std::string naslov1){
        ime_pisca=ime_pisca1;zanr=zanr1;god_izdavanja=god_izdavanja1;naslov=naslov1;
    }
};
int main ()
{
	return 0;
}