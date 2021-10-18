/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <stdexcept>
#include <utility>
struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};
class Knjiga{
    std::string ime_knjige, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *kod_kog_je=nullptr;
    public:
    Knjiga(std::string ime_k, std::string ime_p, std::string vrsta, int godina){
        ime_knjige=ime_k; ime_pisca=ime_p; zanr=vrsta; godina_izdavanja=godina;
    }
    std::string DajNaslov() const{ return ime_knjige;}
    std::string DajAutora() const{ return ime_pisca;}
    std::string DajZanr() const{ return zanr;}
    int DajGodinuIzdavanja() const{ return godina_izdavanja;}
    Korisnik* DajKodKogaJe() const{ return kod_kog_je;}
    void ZaduziKnjigu(Korisnik &clan){ kod_kog_je = &clan;}
    void RazduziKnjigu(){ kod_kog_je=nullptr;}
    bool DaLiJeZaduzena(){ return kod_kog_je!=nullptr;}
    void Ispisi() const{
      //  std::cout<<"Evidencijski broj: "<<knjige->first<<std::endl<<"Naslov: "<<DajNaslov()<<std::endl<<"Pisac: "<<DajAutora()<<std::endl<<"Zanr: "<<DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<DajGodinuIzdavanja()<<std::endl;
    }
};
class Biblioteka{
    std::map<int, std::shared_ptr<Korisnik>>korisnici;
    std::map<int, std::shared_ptr<Knjiga>>knjige;
    public:
    Biblioteka(){}
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string br_telefona);
    void RegistrirajNovuKnjigu(int br_knjige, std::string naslov, std::string ime_pisca, std::string zanr, std::string br_telefona);
    Korisnik &NadjiKorisnika(int broj);
    Knjiga &NadjiKnjigu(int broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    
};
/*void Biblioteka::RegistrirajNovogKorisnika(int clanski_br, std::string ime, std::string prezime, std::string adresa, std::string br_telefona){
    auto it=korisnici.find(clanski_br);
    if(it!=korisnici.end()) throw std::logic_error ("Korisnik vec postoji");
        Korisnik k{ime,prezime,adresa,br_telefona};
        korisnici[clanski_br]= (std::make_pair(clanski_br, new Korisnik(k)));
}
void Biblioteka::RegistrirajNovuKnjigu(int br_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina){
    auto it1=knjige.find(br_knjige);
    if(it1==knjige.end()) throw std::logic_error ("Knjiga vec postoji");
    knjige.insert(std::make_pair(br_knjige, new Knjiga(naslov,ime_pisca,zanr,godina)));
    }
    */
int main ()
{
	return 0;
}