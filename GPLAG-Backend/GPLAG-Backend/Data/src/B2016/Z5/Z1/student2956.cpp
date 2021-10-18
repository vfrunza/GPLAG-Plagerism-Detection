/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>

using namespace std;

struct Korisnik{
    string ime;
    string prezime;
    string adresa;
    string telefon;
}

class Knjiga{
    string naslov;
    string ime_pisca;
    string zanr;
    int godina;
    Korisnik *zaduzenje;
    public:
    Knjiga(string naslov,string ime_pisca,string zanr,int godina,Korisnik *zaduzenje):naslov(naslov),ime_pisca(ime_pisca),zanr(zanr),godina(godina),zaduzenje(nullptr){}
    string DajNaslov()const{return naslov;}
    string DajAutora()const{return ime_pisca;}
    string DajZanr()const{return zanr;}
    int DajGodinuIzdavanja()const{return godina;}
    Korisnik DajKodKogaJe()const{return *zaduzenje;}
    
    void ZaduziKnjigu(Korisnik &k){
        zaduzenje=new Korisnik
    }
};

class Biblioteka{
    
};