/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cstring>
#include <map>
#include <utility>
#include<iomanip>
#include <algorithm>
#include <stdexcept>
using namespace std;
struct Korisnik{
    string ime, prezime, adresa,telefon;
};
class Knjiga{
    string naslov_knjige,ime_pisca,zanr;
    int godina_izdavanja;
    Korisnik *zaduzenje;
    public:
    Knjiga(string n_k, string i_p, string z, int g_i): zaduzenje(nullptr) { //konstruktor sa 4 parametra
        naslov_knjige=n_k;
        ime_pisca=i_p;
        zanr=z;
        godina_izdavanja=g_i;
}
    void Postavi(string n_k, string i_p, string z, int g_i){ 
        naslov_knjige=n_k;
        ime_pisca=i_p;
        zanr=z;
        godina_izdavanja=g_i;
        zaduzenje=nullptr;
    }
    string DajNaslov() const{ return naslov_knjige;}
    string DajAutora() const{ return ime_pisca;}
    string DajZanr() const { return zanr;}
    int DajGodinuIzdavanja() const { return godina_izdavanja;}
    Korisnik *DajKodKogaJe() const { return zaduzenje;}
    void ZaduziKnjigu (Korisnik &k) { zaduzenje=&k;} // postavlja pokazivac zaduzenje na korisnika koji poslan kao parametar
    void RazduziKnjigu() { zaduzenje=nullptr;} // postavlja pokazivac na nullptr jer je korisnik razduzio knjigu
    bool DaLiJeZaduzena(){ if(zaduzenje==nullptr) return false; else return true;} //vraca 0 ako nije zaduzena, 1 ako je zaduzena
};
class Biblioteka{
    map<int, Korisnik*> korisnik; //atributi mape, gdje je kljuc identifikacioni broj, a pridruzena vrijednost dinamicki alocirani objekat
    map<int, Knjiga*> knjiga; 
    public:
    Biblioteka(); //Objekti tipa “Biblioteka” moraju se moći kreirati ne navodeći nikakve dopunske informacije
    Biblioteka(const Biblioteka &b); // kopirajuci konstruktor
    Biblioteka &operator=(const Biblioteka &b); // operator dodjele
    ~Biblioteka(); //destruktor
    void RegistrirajNovogKorisnika(int clanskibr, string ime, string prezime, string adresa, string telefon);
    void RegistrirajNovuKnjigu(int evidencijskibr, string naslov_knjige, string ime_pisca, string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int clanskibr);
    Knjiga &NadjiKnjigu(int evidencijskibr);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const; 
    void ZaduziKnjigu(int evidencijskibr, int clanskibr);
    void RazduziKnjigu(int evidencijskibr);
    void PrikaziZaduzenja(int clanskibr);
};
Biblioteka::Biblioteka(){ //konstruktor bez parametra
    Korisnik* k=new Korisnik;
    (*k).ime="\0";
    (*k).prezime="\0";
    (*k).adresa="\0";
    (*k).telefon="\0";
    Knjiga* k1=new Knjiga("\0","\0","\0",0);
    delete k;
    delete k1;
}
Biblioteka::Biblioteka(const Biblioteka &b){ //kopirajuci konstruktor
    try{
    for(auto it=b.korisnik.begin(); it!=b.korisnik.end(); it++){
        Korisnik* k=new Korisnik;
        (*k).ime=it->second->ime;
        (*k).prezime=it->second->prezime;
        (*k).adresa=it->second->adresa;
        (*k).telefon=it->second->telefon;
        pair<int,Korisnik*>p(it->first, k);
        korisnik.insert(p);
    }
    for(auto it=b.knjiga.begin(); it!=b.knjiga.end(); it++){
        Knjiga* k=new Knjiga(it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja());
        pair<int,Knjiga*>p(it->first, k);
        knjiga.insert(p);
    }
    }
    catch(...){
    for(auto it=b.korisnik.begin(); it!=b.korisnik.end(); it++) delete it->second; 
    for(auto it=b.knjiga.begin(); it!=b.knjiga.end(); it++) delete it->second;
    throw;
    }
}
Biblioteka &Biblioteka::operator=(const Biblioteka &b){ // operator dodjele
if(korisnik.size()<b.korisnik.size()){
   try{
    Korisnik* k=new Korisnik;
    for(auto i=korisnik.size(); i<b.korisnik.size(); i++){
        auto it1=b.korisnik.begin();
        (*k).ime=it1->second->ime;
        (*k).prezime=it1->second->prezime;
        (*k).adresa=it1->second->adresa;
        (*k).telefon=it1->second->telefon;
        pair<int,Korisnik*>p(it1->first, k);
        auto it=korisnik.end();
        korisnik.insert(it,p);
        it1++;
        it++;
    }
    delete k;
   }
   catch(...){
    for(auto it=korisnik.begin(); it!=korisnik.end(); it++) delete it->second;  
    throw;
   }
}
else {
   for(auto it=korisnik.begin(); it!=korisnik.end(); it++) delete it->second; 
}
if(korisnik.size()<b.korisnik.size()){
    try{
    for(auto i=knjiga.size(); i<b.knjiga.size(); i++){
        auto it1=b.knjiga.begin();
        Knjiga* k=new Knjiga(it1->second->DajNaslov(),it1->second->DajAutora(),it1->second->DajZanr(),it1->second->DajGodinuIzdavanja());
        pair<int,Knjiga*>p(it1->first, k);
        auto it=knjiga.end();
        knjiga.insert(it,p);
        it1++;
        it++;
    }
    }
    catch(...){
    for(auto it=knjiga.begin(); it!=knjiga.end(); it++) delete it->second;
    throw;
}
}
else {
   for(auto it=korisnik.begin(); it!=korisnik.end(); it++) delete it->second; 
}
    return *this;
}
Biblioteka::~Biblioteka(){
    for(auto it=korisnik.begin(); it!=korisnik.end(); it++) delete it->second; 
    for(auto it=knjiga.begin(); it!=knjiga.end(); it++) delete it->second;
}
void Biblioteka::RegistrirajNovogKorisnika(int clanskibr, string ime, string prezime, string adresa, string telefon){
    for(auto it=korisnik.begin(); it!=korisnik.end(); it++){
            if(it->first==clanskibr) throw logic_error ("Korisnik vec postoji");
        }
    try{
        Korisnik* k=new Korisnik;
        (*k).ime=ime;
        (*k).prezime=prezime;
        (*k).adresa=adresa;
        (*k).telefon=telefon;
        pair<int,Korisnik*>p(clanskibr, k);
        korisnik.insert(p);
    }
    catch(...){ throw;}
}
void Biblioteka::RegistrirajNovuKnjigu(int evidencijskibr, string naslov_knjige, string ime_pisca, string zanr, int godina_izdavanja){
    for(auto it=knjiga.begin(); it!=knjiga.end(); it++){
            if(it->first==evidencijskibr) throw logic_error ("Knjiga vec postoji");}
      try{
        Knjiga* k;
        k=new Knjiga(naslov_knjige, ime_pisca, zanr, godina_izdavanja);
        pair<int,Knjiga*>p(evidencijskibr, k);
        knjiga.insert(p);
    }
    catch(...){ throw;}
}
Korisnik k;
Korisnik &Biblioteka::NadjiKorisnika(int clanskibr){
    for(auto it=korisnik.begin(); it!=korisnik.end(); it++) if(it->first==clanskibr) {
    k.ime=it->second->ime;
    k.prezime=it->second->prezime;
    k.adresa=it->second->adresa;
    k.telefon=it->second->telefon;
    return k;
    }
    throw logic_error("Korisnik nije nadjen");
}
Knjiga k1("\0","\0","\0",0);
 Knjiga &Biblioteka::NadjiKnjigu(int evidencijskibr){
    for(auto it=knjiga.begin(); it!=knjiga.end(); it++) if(it->first==evidencijskibr){ 
     k1.Postavi(it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja());
    return k1;
 }
 throw logic_error("Knjiga nije nadjena");
 }
 void Biblioteka::IzlistajKorisnike()const {
     for(auto it=korisnik.begin(); it!=korisnik.end(); it++){
         cout<<"Clanski broj: "<<it->first<<endl;
         cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl;
         cout<<"Adresa: "<<it->second->adresa<<endl;
         cout<<"Broj telefona: "<<it->second->telefon<<endl;
         cout<<endl;
     }
 }
 void Biblioteka::IzlistajKnjige() const{
    for(auto it=knjiga.begin(); it!=knjiga.end(); it++){
        cout<<"Evidencijski broj: "<<it->first<<endl;
        cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
        cout<<"Pisac: "<<it->second->DajAutora()<<endl;
        cout<<"Zanr: "<<it->second->DajZanr()<<endl;
        cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        if(it->second->DaLiJeZaduzena()==1){
            Korisnik *k=it->second->DajKodKogaJe();
         cout<<"Zaduzena kod korisnika: "<<k->ime<<" "<<k->prezime<<endl;}
        cout<<endl;
 }
 }
Korisnik k2;
void Biblioteka::ZaduziKnjigu(int evidencijskibr, int clanskibr){
int jeste=0;
for(auto it1=korisnik.begin(); it1!=korisnik.end(); it1++){
    jeste=0;
    if(clanskibr==it1->first) {
        k2.ime=it1->second->ime;
        k2.prezime=it1->second->prezime;
        k2.adresa=it1->second->adresa;
        k2.telefon=it1->second->telefon;
        jeste=1; break;
    }
}
if(jeste==0) throw logic_error("Korisnik nije nadjen");
jeste=0;
for(auto it=knjiga.begin(); it!=knjiga.end(); it++){
        if(evidencijskibr==it->first){
            jeste=1;
            if(it->second->DaLiJeZaduzena()==1) throw logic_error("Knjiga vec zaduzena");
            it->second->ZaduziKnjigu(k2); break;}
}
if(jeste==0) throw logic_error("Knjiga nije nadjena");
}
void Biblioteka::RazduziKnjigu(int evidencijskibr){
    int jeste=0;
    for(auto it=knjiga.begin(); it!=knjiga.end(); it++){
        jeste=0;
        if(it->first==evidencijskibr){
            jeste=1;
            if(it->second->DaLiJeZaduzena()==0) throw logic_error("Knjiga nije zaduzena");
            it->second->RazduziKnjigu(); break;}
    }
     if(jeste==0) throw logic_error("Knjiga nije nadjena");
}
void Biblioteka::PrikaziZaduzenja(int clanskibr){
    int jeste=0;
    Korisnik k;
    for(auto it=korisnik.begin(); it!=korisnik.end(); it++){
    jeste=0;
    if(it->first==clanskibr){
        jeste=1;
        k.ime=it->second->ime;
        k.prezime=it->second->prezime;
        k.adresa=it->second->adresa;
        k.telefon=it->second->telefon;
        break;
    }
    }
    if(jeste==0) throw logic_error("Korisnik nije nadjen");
    jeste=0;
    for(auto it=knjiga.begin(); it!=knjiga.end(); it++){
        if(it->second->DaLiJeZaduzena()){
          Korisnik *k1=it->second->DajKodKogaJe(); 
          if(k1->ime==k.ime && k1->prezime==k.prezime) { jeste=1; 
      cout<<"Evidencijski broj: "<<it->first<<endl;
        cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
        cout<<"Pisac: "<<it->second->DajAutora()<<endl;
        cout<<"Zanr: "<<it->second->DajZanr()<<endl;
        cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        cout<<endl;
          }
        }
    }
    if(jeste==0) cout<<"Nema zaduzenja za tog korisnika!"<<endl;
}

int main ()
{
Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
"Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
"Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
"Studenata etfovaca 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
Biblioteka b2(b);                                           
b2.PrikaziZaduzenja(4312);
	return 0;
}