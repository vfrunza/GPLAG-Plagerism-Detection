/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>

struct Korisnik {
    string ime, prezime, adresa, telefon;
};

class Knjiga
{
    string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *zaduzena;

public:
    Knjiga(string nasloov, string ime_piscaa, string zaanr, int godina_izdavanjaa) {
        naslov=nasloov;
        ime_pisca=ime_piscaa;
        zanr=zaanr;
        godina_izdavanja=godina_izdavanjaa;
        zaduzena=nullptr;
    }
    string DajNaslov() {
        return naslov;
    }
    string DajAutora(){
        return ime_pisca;
    }
    string DajZanr{
        return zanr;
    }
    int DajGodinuIzdavanja(){
        return godina_izdavanja;  
    }
    Korisnik *DajKodKogaJe(){
        return zaduzena;
    }
    void ZaduziKnjigu(Korisnik &korisnik){
        zaduzena=korisnik;
    }
    void RazduziKnjigu(){
        zaduzena=nullptr;
    }
    bool DaLiJeZaduzena(){
        if(zaduzena==nullptr) return false;
        return true;
    }

};

class Biblioteka{
    std::map<int clanski_broj, Korisnik *pokazivac>mapa_korisnika;
    std::map<int evidencijski_broj, Knjiga *pokazivac>mapa_knjiga;
    
    public:
    Biblioteka(){
        
    }
};

int main ()
{
    return 0;
}