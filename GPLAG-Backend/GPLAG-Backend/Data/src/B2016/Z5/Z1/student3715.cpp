/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
    Korisnik(std::string Ime, std::string Prezime, std::string Adresa, std::string Tel)
    {
        ime = Ime;
        prezime = Prezime;
        adresa = Adresa;
        telefon = Tel;
    }
    Korisnik(Korisnik &neki)
    {
        ime = neki.ime;
        prezime = neki.prezime;
        adresa = neki.adresa;
        telefon = neki.telefon;
    }
    
};

class Knjiga
{
    std::string naslov_knjige, ime_pisca, zanr;
    int god_izdavanja;
    Korisnik *duznik {nullptr};
public:
    Knjiga(std::string a, std::string b, std::string c, int god) {
        naslov_knjige = a;
        ime_pisca = b;
        zanr = c;
        god_izdavanja = god;
    }
    std::string DajNaslov() const {
        return naslov_knjige;
    }
    std::string DajAutora() const {
        return ime_pisca;
    }
    std::string DajZanr() const {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return god_izdavanja;
    }
    Korisnik* DajKodKogaJe() const {
        return duznik;
    }
    void ZaduziKnjigu(Korisnik &covjek) {//PARAMETAR REFERENCA A ONA POKAZUJE NA ONOGA KOJI ZADUZUJE KNJIGU
        duznik = &covjek;                //DA LI STAVITI DA POKAZIVAC DUZNIK POKAZUJE NA DEREFERENCIRANOG COVJEKA???
    }
    void RazduziKnjigu() {
        duznik = nullptr;
    }
    bool DaLiJeZaduzena() {
        if(duznik == nullptr)
            return false;
        return true;
    }
};

class Biblioteka
{
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
public:
    Biblioteka() {
     //   korisnici.insert(std::make_pair(0,new Korisnik*));
    };
    Biblioteka(const Biblioteka &bejb);
    Biblioteka &operator = (const Biblioteka &bibl);
    //TILDA JE ALTGR + 1
    ~Biblioteka() {//TREBA IZBRISATI SVE DINAMIČKI ALOCIRANE KORISNIKE I KNJIGE U MAPAMA
        for(auto i = korisnici.begin(); i != korisnici.end(); ++i)
            delete i->second;
        for(auto i = knjige.begin(); i != knjige.end(); ++i)
            delete i->second;
    }
    void RegistrirajNovogKorisnika(int cl_br, std::string ime, std::string prezime, std::string adresa, int telefon);
    void RegistrirajNovuKnjigu(int br_knjige, std::string naslov, std::string ime_autora, std::string zanrr, int godina_iz);
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int broj_knjige);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int broj_knjige, int broj_korisnika);
    void RazduziKnjigu(int broj_knjige);
    void PrikaziZaduzenja(int broj_korisnika) const;
    
};

int main ()
{
    
    return 0;
}

void Biblioteka::RegistrirajNovogKorisnika(int cl_br, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
    if(korisnici.find(cl_br) == korisnici.end())
    {
       auto *pok = new Korisnik(ime, prezime, adresa, telefon);
       korisnici.insert(std::pair<int, Korisnik*>(cl_br, pok));
    } 
    else
    {
        throw std::logic_error("Korisnik vec postoji");
    }
       
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) {
    if(!korisnici.count(clanski_broj))
       throw std::logic_error("Korisnik nije nadjen");
    
    auto it(korisnici.find(clanski_broj));
    return *it->second;

}
void Biblioteka::IzlistajKorisnike() const{
    for(auto it = korisnici.begin(); it != korisnici.end(); it++)
    {
        std::cout << "Clanski broj: " << it->first
                  << "\nIme i prezime: " << (it->second).Knjiga::ime << " " << (it->second).Knjiga::prezime
                  << "\nAdresa: " << (it->second).Knjiga.adresa
                  << "\nBroj telefona: " << (it->second).Knjiga.telefon
                  <<std::endl;
    }
}
void IzlistajKnjige() {
    for(auto it = knjige.begin(); it != knjige.end(); it++) 
    {
        std::cout << "Evidencijski broj: " << it->first
                  << "\nNaslov: " << (it->second).Korisnik.DajNaslov()
                  << "\nPisac: " << (it->second).Korisnik.DajAutora()
                  <<"\nZanr: " << (it->second).Korisnik.DajZanr()
                  << "\nGodina izdavanja: " << (it->second).Korisnik.DajGodinuIzdavanja();
        if((it->second).Korisnik.DaLiJeZaduzena())
        {
           auto pok((it->second).Korisnik.DajKodKogaJe());
           std::cout << "\nZaduzena kod korisnika: "
                     << pok.ime << " " << pok.prezime;
        }            
        std::cout << std::endl;
    }
}

void RegistrirajNovuKnjigu(int ev_br, std::string naslov, std::string ime_autora, std::string zanrr, int godina) {
    if(knjige.find(ev_br) == knjige.end())
    {
        Knjiga *pok = new Knjiga(naslov, ime_autora, zanrr, godina);
        knjige.insert(std::pair<int, Knjiga*>(ev_br, pok));
    }
    else
    {
        throw std::logic_error("Knjiga vec postoji");
    }
}
Knjiga &NadjiKnjigu(int broj_knjige) {
    if(!knjige.count(broj_knjige))
       throw std::logic_error("Korisnik nije nadjen");
    return *knjige.find(broj_knjige)->second;   
}
void ZaduziKnjigu(int broj_knjige, int broj_korisnika) {
    if(!knjige.count(broj_knjige))
       throw std::logic_error("Knjiga nije nadjena");
    if(!korisnici.count(broj_korisnika))
       throw std::logic_error("Korisnik nije nadjen");
    if(((*(knjige.find(broj_knjige))).second)->DaLiJeZaduzena() == true) 
       throw std::logic_error("Knjiga vec zaduzena");
    
    ((*(knjige.find(broj_knjige))).second)->ZaduziKnjigu(*(korisnici.find(broj_korisnika)->second));   
}

void RazduziKnjigu(int broj_knjige)
{
    auto i = knjige.find(broj_knjige);
    if(!knjige.count(broj_knjige))
       throw std::logic_error("Knjiga nije nadjena");
    
    if(((*i).second)->DaLiJeZaduzena() == false)
      throw std::logic_error("Knjiga nije zaduzena");
    ((*i).second)->Knjiga.RazduziKnjigu();  
       
       
}







