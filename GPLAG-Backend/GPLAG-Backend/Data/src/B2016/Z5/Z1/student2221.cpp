/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>

struct Korisnik 
{
    private:
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
    
    public:
};

class Knjiga
{
    std::string naslov_knjige;
    std::string ime_pisca;
    std::string zanr_knjige;
    int godina_izdavanja;
    Korisnik *pok_na_korisnika;

     public:
    
    Knjiga (std::string naslov, std::string ime, std::string zanr, int godina)
    {
        pok_na_korisnika = nullptr;
        this -> naslov_knjige = naslov;
        this -> ime_pisca = ime;
        this -> zanr_knjige = zanr; 
        this -> godina_izdavanja = godina;
    }
    
    std::string DajNaslov() const { return naslov_knjige;}
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr_knjige; }
    int DajGodinuIzdavanja() const { return godina_izdavanja;}
    
    Knjiga ZaduziKnjigu (const Knjiga &k)
    {
        return new Knjiga
    }
    
    
};

class Biblioteka
{
    std::map<int,int> mapa_korisnika;
    std::map<int,int> mapa_knjiga;
};


int main ()
{
	return 0;
}