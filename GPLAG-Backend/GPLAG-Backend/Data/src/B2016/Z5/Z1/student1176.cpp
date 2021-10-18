#include <iostream> 
#include <string>  

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};
class Knjiga{
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;  
    Korisnik *korisnik;
    public:  
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr),
    godina_izdavanja(godina_izdavanja) {}
    std::string DajNaslov() const{ 
        return naslov;
    } 
    std::string DajAutora() const{
        return ime_pisca;
    } 
    std::string DajZanr() const{
        return zanr;
    } 
    int DajGodinuIzdavanja() const{
        return godina_izdavanja;
    } 
    ZaduziKnjigu
    RazduziKnjigu 
    bool DaLiJeZaduzena
}; 
class Biblioteka{
    std::map<Korisnik, int> korisnici;
    std::map<Knjiga, int> knjige;
    public: 
    RegistrirajNovogKorisnika
    RegistrirajNovuKnjigu 
    NadjiKorisnika
    NadjiKnjigu
    IzlistajKorisnike
    IzlistajKnjige
    ZaduziKnjigu
}
int main ()
{
	return 0;
}