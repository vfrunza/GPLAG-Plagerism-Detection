/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>

struct Korisnik{
    string ime;
    string prezime;
    string adresa;
    string telefon;
};

class Knjiga{
    string naslov, pisac, zanr;
    int godina_izdavanja;
    auto zaduzena=*Korisnik; //potrebno staviti nullptr
public:
    Knjiga (const string Naslov, const string Pisac, const Zanr, const int Godina_izdavanja){
        naslov=Naslov; pisac=Pisac; zanr=Zanr; godina_izdavanja=Godina_izdavanja;
    }
    string DajNaslo (){return naslov;}
    string DajAutora (){return pisac;}
    string DajZanr (){return zanr;}
    int DajGodinuIzdavanja(){return godina_izdavanja;}
    string DajKodKogaJe(){return zaduzena;}
    
    
};



int main ()
{
	return 0;
}