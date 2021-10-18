/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>

using namespace std;

struct Korisnik {
    string ime, prezime, adresa, telefon;
};

class Knjiga {
    string Naslov, ImePisca, Zanr;
    int GodinaIzdavanja;
    Korisnik *pok;
    
    public:
    Knjiga(string n_k, string i_p, string z_k, int g_i):Naslov(n_k),ImePisca(i_p),Zanr(z_k),GodinaIzdavanja(g_i),pok(nullptr){}

    string DajNaslov()const{ return Naslov; };
    string DajAutora()const{ return ImePisca; };
    string DajZanr()const{ return Zanr; };
    int DajGodinuIzdavanja()const{ return GodinaIzdavanja; };
    Korisnik* DajKodKogaJe()const{ return pok; };
    void ZaduziKnjigu(Korisnik &k) { pok=&k; };
    void RazduziKnjigu() { pok=nullptr; };
    bool DaLiJeZaduzena() { if(pok!=nullptr) return true; else return false; };
};

class Biblioteka {
    map<int,Korisnik*> korisnici;
    map<int,Knjiga*> knjige;
      
    public:
    Biblioteka(){}
    Biblioteka( const Biblioteka &b){
        for(auto it=b.korisnici.begin();it!=b.korisnici.end();it++)
            korisnici[it->first]=new Korisnik(*it->second);
        for(auto it=b.knjige.begin();it!=b.knjige.end();it++)
            knjige[it->first]=new Knjiga(*it->second);
    }
    Biblioteka( Biblioteka && b){
        korisnici=b.korisnici;
        knjige=b.knjige;
        b.knjige.clear();
        b.korisnici.clear();
    }
      
    Biblioteka &operator =(const Biblioteka &b){
        if(this==&b) return *this;
        for (auto it=korisnici.begin();it!=korisnici.end();it++)
             delete it->second;
        for (auto it=knjige.begin();it!=knjige.end();it++)
             delete it->second;
        knjige.clear();
        korisnici.clear();
        for(auto it=b.korisnici.begin();it!=b.korisnici.end();it++)
            korisnici[it->first]=new Korisnik(*it->second);
        for(auto it=b.knjige.begin();it!=b.knjige.end();it++)
            knjige[it->first]=new Knjiga(*it->second);
        return *this;   
    }
      
    Biblioteka &operator =(Biblioteka &&b){
        if(this==&b) return *this;
        for(auto it=korisnici.begin();it!=korisnici.end();it++)
            it->second=nullptr;
        for(auto it=knjige.begin();it!=knjige.end();it++)
            it->second=nullptr;
        knjige.clear();
        korisnici.clear();
        korisnici=b.korisnici;
        knjige=b.knjige;
        b.knjige.clear();
        b.korisnici.clear();
        
        return *this;  
    }
    
    ~Biblioteka() { 
        for (auto it=korisnici.begin();it!=korisnici.end();it++)
            delete it->second;
        for (auto it=knjige.begin();it!=knjige.end();it++)
            delete it->second;
        knjige.clear();
        korisnici.clear();
    }
    void RegistrirajNovogKorisnika( int clanski_broj, string ime, string prezime, string adresa, string br_telefona){
          korisnici[clanski_broj]=new Korisnik();
          korisnici[clanski_broj]->ime=ime,
          korisnici[clanski_broj]->prezime=prezime;
          korisnici[clanski_broj]->adresa=adresa;
          korisnici[clanski_broj]->telefon=br_telefona;
    }
    void RegistrirajNovuKnjigu(int ev_broj, string naslov, string ime_pisca, string z, int god_izdanja){
          knjige[ev_broj]=new Knjiga(naslov,ime_pisca,z,god_izdanja);
    }
    Korisnik& NadjiKorisnika(int clanski_broj) {
          return *korisnici[clanski_broj];
    }
    Knjiga& NadjiKnjigu(int ev_broj){
          return *knjige[ev_broj];
    }
      
    void IzlistajKorisnike(){
        vector<int> v;
        for (auto it=korisnici.begin();it!=korisnici.end();it++)
              v.push_back(it->first);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++) {
            cout<<"Clanski broj: "<<v[i]<<endl;
            cout<<"Ime i prezime: "<<korisnici[v[i]]->ime<<" "<<korisnici[v[i]]->prezime<<endl;
            cout<<"Adresa: "<<korisnici[v[i]]->adresa<<endl;
            cout<<"Broj telefona: "<<korisnici[v[i]]->telefon<<endl<<endl;
         }
    }
    void IzlistajKnjige(){
        vector<int> v;
        for (auto it=knjige.begin();it!=knjige.end();it++)
              v.push_back(it->first);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<"Clanski broj: "<<v[i];
            cout<<"Ime i prezime: "<<korisnici[v[i]]->ime<<" "<<korisnici[v[i]]->prezime<<endl;
            cout<<"Adresa: "<<korisnici[v[i]]->adresa<<endl;
            cout<<"Broj telefona: "<<korisnici[v[i]]->telefon;
         }
    }
    void ZaduziKnjigu(int ev_broj, int clanski_broj){
          knjige[ev_broj]->ZaduziKnjigu(*korisnici[clanski_broj]);
    }
    void RazduziKnjigu(int ev_broj){
          knjige[ev_broj]->RazduziKnjigu();
    }
    void PrikaziZaduzenja(int clanski_broj);
};

                                                 
int main(){
    Korisnik korisnik1{"Meho", "Mik", "Dobojska 15", "033/123-456"};
    Knjiga knjiga1("Tvrdjava", "Mesa Selimovic", "Roman", 1965);
    if(knjiga1.DajKodKogaJe() == nullptr) cout<<"Nije zaduzena\n";
    cout<<knjiga1.DaLiJeZaduzena()<<endl;
    knjiga1.ZaduziKnjigu(korisnik1);
    cout<<"Knjigu je zaduzio "<<knjiga1.DajKodKogaJe()->ime<<endl;
    
    cout<<knjiga1.DaLiJeZaduzena()<<endl;
    
    Biblioteka b;
    b.RegistrirajNovogKorisnika(1234, "Zvjecdan", "Petrovic","Zmaja od Bosne 30", "032/434-455");
    b.RegistrirajNovogKorisnika(1235, "Zvjezdan", "Zvjezdanovic","BB", "032/434-457");
    
    b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
    b.RegistrirajNovuKnjigu(232, "Ruza", "Nura Hubijar", "Roman", 1965);
    b.IzlistajKorisnike();
    return 0;
}
