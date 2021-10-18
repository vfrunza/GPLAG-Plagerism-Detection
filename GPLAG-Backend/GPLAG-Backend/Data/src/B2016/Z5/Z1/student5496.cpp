/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <cstring>
#include <map>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};
class Knjiga{
    std::string naslov_knjige, ime_pisca, zanr;
    int god_izdavanja;
    Korisnik *kod_kog_je=nullptr;
    public:
    Knjiga(std::string naslov, std::string ime, std::string vrsta, int godina){
        naslov_knjige=naslov; ime_pisca=ime; zanr=vrsta; god_izdavanja=godina;
    }
    std::string DajNaslov() const{ return naslov_knjige;}
    std::string DajAutora() const{ return ime_pisca;}
    std::string DajZanr() const{ return zanr;}
    int DajGodinuIzdavanja() const{ return god_izdavanja;}
    Korisnik *DajKodKogaJe() const{ return kod_kog_je;}
    void ZaduziKnjigu(Korisnik &clan) { kod_kog_je = &clan;}
    void RazduziKnjigu() { kod_kog_je=nullptr;}
    bool DaLiJeZaduzena() { return kod_kog_je!=nullptr;}
    void Ispis()  const{
        std::cout<<"Naslov: "<<DajNaslov()<<std::endl<<"Pisac: "<<DajAutora()<<std::endl<<"Zanr: "<<DajZanr()<<std::endl<<"Godina izdavanja: "<<DajGodinuIzdavanja()<<std::endl;
    }
};
class Biblioteka{
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
    public:
    Biblioteka(){}
    ~Biblioteka();
    void RegistrirajNovogKorisnika(int clanski_br, std::string ime, std::string prezime, std::string adresa, std::string br_telefona);
    void RegistrirajNovuKnjigu(int br_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina);
    Korisnik &NadjiKorisnika(int broj);
    Knjiga &NadjiKnjigu(int broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu (int broj_knjige, int clanski_br);
    void RazduziKnjigu (int broj_knjige);
    void PrikaziZaduzenja (int clanski_br);
};
void Biblioteka::RegistrirajNovogKorisnika(int clanski_br, std::string ime, std::string prezime, std::string adresa, std::string br_telefona){
        auto it=korisnici.find(clanski_br);
        if(it!=korisnici.end()) throw std::logic_error ("Korisnik vec postoji");
        try{
            Korisnik k{ime,prezime,adresa,br_telefona};
            korisnici.insert(std::make_pair(clanski_br, new Korisnik (k)));
        } catch(...){ throw;
        }
    }
void Biblioteka::RegistrirajNovuKnjigu(int br_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina){
        Knjiga k(naslov,ime_pisca,zanr,godina);
        auto it1=knjige.find(br_knjige);
        if(it1!=knjige.end()) throw std::logic_error ("Knjiga vec postoji");
        try{
          knjige.insert(std::make_pair(br_knjige, new Knjiga(naslov, ime_pisca,zanr,godina)));
        }catch(...){ throw;}
    }
Korisnik &Biblioteka::NadjiKorisnika(int broj){
        auto it2(korisnici.find(broj));
        if(it2==korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
        return *korisnici[broj];
    }
Knjiga &Biblioteka::NadjiKnjigu(int broj){
    auto it2(knjige.find(broj));
    if(it2!=knjige.end()) return *knjige[broj];
    throw std::logic_error ("Knjiga nije nadjena");
}
void Biblioteka::IzlistajKorisnike() const{
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
    std::cout<<"Clanski broj: "<<it->first<<std::endl;
    std::cout<<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<std::endl;
    std::cout<<"Adresa: "<<(it->second)->adresa<<std::endl;
    std::cout<<"Broj telefona: "<<(it->second)->telefon<<std::endl;
    std::cout<<std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const{
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
    std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
    std::cout<<"Naslov: "<<(it->second)->Knjiga::DajNaslov()<<std::endl;
    std::cout<<"Pisac: "<<(it->second)->Knjiga::DajAutora()<<std::endl;
    std::cout<<"Zanr: "<<(it->second)->Knjiga::DajZanr()<<std::endl;
    std::cout<<"Godina izdavanja: "<<(it->second)->Knjiga::DajGodinuIzdavanja()<<std::endl;
    }    
}
Biblioteka::~Biblioteka(){
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
        delete it->second;
    }
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        delete it->second;
    }
}
   // Biblioteka(const Biblioteka &b)=delete;
    //Biblioteka &operator=(const Biblioteka &b)=delete;
    //void RegistrirajNovogKorisnika
    
int main ()
{
	return 0;
}