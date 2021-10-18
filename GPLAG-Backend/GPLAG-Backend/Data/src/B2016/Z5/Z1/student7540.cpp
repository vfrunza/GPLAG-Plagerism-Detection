/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;

struct Korisnik {
    string ime;
    string prezime;
    string adresa;
    string telefon;
};

class Knjiga {
    string naslov;
    string ime_pisca;
    string zanr;
    int godina_izdavanja;
    Korisnik* zaduzenje;
    public:
    Knjiga(string naslov_knjige, string piscevo_ime, string koji_je_zanr, int god_izd): naslov(naslov_knjige), ime_pisca(piscevo_ime),
    zanr(koji_je_zanr), godina_izdavanja(god_izd) , zaduzenje(nullptr) {}
    
    string DajNaslov() const{
        return naslov;
    }
      string DajAutora() const{
        return ime_pisca;
    }
      string DajZanr() const{
        return zanr;
    }
    int DajGodinuIzdavanja() const{
        return godina_izdavanja;
    }
    Korisnik* DajKodKogaJe() const{
        return zaduzenje;
    }
    void ZaduziKnjigu(const Korisnik &lik) {
        if(DaLiJeZaduzena()) throw domain_error("Vec je zaduzena");
        Korisnik* pok(lik);
        zaduzenje=pok;
    }
    void RazduziKnjigu() {
        if(zaduzenje)
        zaduzenje=nullptr;
    }
    bool DaLiJeZaduzena() const{
        if(zaduzenje) return true;
        return false;
    }
    
    
};

class Biblioteka{
    map<int,Korisnik*> korisnik_mapa;
    map<int,Knjiga*> knjiga_mapa;
    public:
    Biblioteka(){};
    void RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime, string adresa, string broj_telefona){
        Korisnik* pok(new Korisnik);
          if(korisnik_mapa.find(clanski_broj)) throw logic_error("Korisnik vec postoji");
        *pok.ime=ime;
        *pok.prezime=prezime;
        *pok.adresa=adresa;
        *pok.telefon=broj_telefona;
        korisnik_mapa.insert(make_pair(clanski_broj,*pok));
    }
    void RegistrirajNovuKnjigu(int br, string naslov, string ime, string zanr, int god ){
        Knjiga* pok(new Knjiga);
        if (knjiga_mapa.find(br)) throw logic_error("Knjiga vec postoji");
        *pok.naslov=naslov;
        *pok.ime_pisca=ime;
        *pok.zanr=zanr;
        *pok.godina_izdavanja=god;
        knjiga_mapa.insert(make_pair(br,*pok));
    } 
    Biblioteka(const Biblioteka &b){
        
    }
    Korisnik &NadjiKorisnika(int cl_broj){
       
        if(!korisnik_mapa.find(cl_broj)) throw logic_error("Korisnik nije nadjen");
         Korisnik &referenca;
         referenca=korisnik_mapa.find(cl_broj);
         return referenca;
    }
     Knjiga &NadjiKnjigu(int cl_broj){
       
        if(!knjiga_mapa.find(cl_broj)) throw logic_error("Knjiga nije nadjena");
         Knjiga &referenca;
         referenca=knjiga_mapa.find(cl_broj);
         return referenca;
    }
    void IzlistajKorisnike() const{
        for (auto it=korisnik_mapa.begin(); it!=korisnik_mapa.end(); it++){
            cout<< "Clanski broj: "<< it->first<< endl;
            cout<< "Ime i prezime: "<<*(it->second).ime << " "<< *(it->second).prezime <<endl;
            cout<< "Adresa: "<< *(it->second).adresa << endl;
            cout<< "Broj telefona: "<<*(it->second).telefon<< endl;
        }
    }
    void IzlistajKnjige() const{
        for (auto it=knjiga_mapa.begin(); it!=knjiga_mapa.end(); it++){
            cout<< "Evidencijski broj: "<< it->first<< endl;
            cout<< "Naslov: "<<*(it->second).naslov << " "<< *(it->second).prezime <<endl;
            cout<< "Pisac: "<< *(it->second).ime_pisca << endl;
            cout<< "Zanr: "<<*(it->second).zanr<< endl;
            cout<< "Godina izdavanja: "<<*(it->second).godina_izdavanja<<endl;
            if(((it->second).zaduzenje))
            cout<< "Zaduzena kod korisnika: "<<*(it->second).zaduzenje->ime << *(it->second).zaduzenje->prezime<< endl;
        }
    }
    void ZaduziKnjigu(int ev_broj, int cl_broj) {
          if(!knjiga_mapa.find(ev_broj)) throw logic_error("Knjiga nije nadjena");
          if(!korisnik_mapa.find(cl_broj)) throw logic_error("Korisnik nije nadjen");
           for (auto it=knjiga_mapa.begin(); it!=knjiga_mapa.end(); it++){
               if (ev_broj==it->first) if (it->second.zaduzenje) throw logic_error("Knjiga vec zaduzena");
                                        else{
                                           for (auto it1=korisnik_mapa.begin(); it1!=korisnik_mapa.end(); it1++){
                                               if(cl_broj==it1->first) *(it->second).zaduzenje=it1->second;
                                           }  
                                        } 
           }
    }
    void RazduziKnjigu(int ev_broj){
         if(!korisnik_mapa.find(cl_broj)) throw logic_error("Korisnik nije nadjen");
           for (auto it=knjiga_mapa.begin(); it!=knjiga_mapa.end(); it++){
               if (ev_broj==it->first) { if (!it->second.zaduzenje) throw logic_error("Knjiga nije zaduzena");
               else it->second.zaduzenje=nullptr; }
    }
    void PrikaziZaduzenja(int cl_broj){
          if(!korisnik_mapa.find(cl_broj)) throw logic_error("Korisnik nije nadjen");
             for (auto it=knjiga_mapa.begin(); it!=knjiga_mapa.end(); it++){
                 if (cl_broj==*(it->second).zaduzenje)
             }
    }
};


int main ()
{
	return 0;
}