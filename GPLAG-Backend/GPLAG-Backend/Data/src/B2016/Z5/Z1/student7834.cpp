/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <string>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
struct Korisnik{
    string ime,prezime,adresa,telefon;
};
class Knjiga{
    string naslov,ime_pisca,zanr;
    int godina_izdavanja;
    Korisnik *zaduzenje;
    public:
    Knjiga(string naslov,string ime_pisca,string zanr,int godina_izdavanja)
    {
        Knjiga::naslov=naslov,Knjiga::ime_pisca=ime_pisca,Knjiga::zanr=zanr,Knjiga::godina_izdavanja=godina_izdavanja,zaduzenje=nullptr;
    }
    string DajNaslov()const{return naslov;}
    string DajAutora()const{return ime_pisca;}
    string DajZanr()const{return zanr;}
    int DajGodinuIzdavanja()const{return godina_izdavanja;}
    Korisnik* DajKodKogaJe()const{return zaduzenje;}
    void ZaduziKnjigu(Korisnik &k){zaduzenje=&k;}
    void RazduziKnjigu(){zaduzenje=nullptr;}
    bool DaLiJeZaduzena()const{return !(zaduzenje==nullptr);}
};
class Biblioteka{
    map<int,Korisnik*> korisnici;
    map<int,Knjiga*> knjige;
    static void ProvjeraKorisnika(map<int,Korisnik*> k,int n){
        for(auto it=k.begin();it!=k.end();it++)if(it->first==n)throw logic_error("Korisnik vec postoji");
    }
    static void ProvjeraKnjiga(map<int,Knjiga*> k,int n){
        for(auto it=k.begin();it!=k.end();it++)if(it->first==n)throw logic_error("Knjiga vec postoji");
    }
    public:
   Biblioteka(){
        korisnici.insert(make_pair(0,nullptr));
        knjige.insert(make_pair(0,nullptr));
   }
    Biblioteka(const Biblioteka &b) {
        Biblioteka::korisnici=b.korisnici;
        Biblioteka::knjige=b.knjige;
    }
    Biblioteka &operator =(const Biblioteka &b){
        korisnici=b.korisnici;
        knjige=b.knjige;
        return *this;
    }
     ~Biblioteka(){
        for(auto x:korisnici)delete x.second;
        for(auto x:knjige)delete x.second;
    }
    void RegistrirajNovogKorisnika(int clanski_broj,string ime,string prezime,string adresa,string broj_telefona){
        Korisnik *k(new Korisnik{ime,prezime,adresa,broj_telefona});
        ProvjeraKorisnika(korisnici,clanski_broj);
        korisnici.insert(make_pair(clanski_broj,k));
    }
    void RegistrirajNovuKnjigu(int evidencijski_broj,string naslov,string ime_pisca,string zanr,int godina_izdavanja){
        Knjiga *k(new Knjiga{naslov,ime_pisca,zanr,godina_izdavanja});
        ProvjeraKnjiga(knjige,evidencijski_broj);
        knjige.insert(make_pair(evidencijski_broj,k));
    }
    Korisnik& NadjiKorisnika(int clanski_broj){
        if(!korisnici.count(clanski_broj))throw logic_error("Korisnik nije nadjen");
        return *korisnici[clanski_broj];
    }
    Knjiga& NadjiKnjigu(int evidencijski_broj){
        if(!knjige.count(evidencijski_broj))throw logic_error("Knjiga nije nadjena");
        return *knjige[evidencijski_broj];
    }
    void IzlistajKorisnike(){
        for(auto it=korisnici.begin();it!=korisnici.end();it++){
            if(it->first!=0){
            cout<<"Clanski broj: "<<it->first<<endl;
            cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl;;
            cout<<"Adresa: "<<it->second->adresa<<endl;
            cout<<"Broj telefona: "<<it->second->telefon<<endl;
        
        }
        cout<<endl;
        }
    }
    void IzlistajKnjige(){
        for(auto it=knjige.begin();it!=knjige.end();it++){
            if(it->first!=0){
            cout<<"Evidencijski broj: "<<it->first<<endl;
            cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
            cout<<"Pisac: "<<it->second->DajAutora()<<endl;
            cout<<"Zanr: "<<it->second->DajZanr()<<endl;
            cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
            if(it->second->DaLiJeZaduzena())cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;
    }
    cout<<endl;
        }
        
    }
    void ZaduziKnjigu(int evidencijski_broj,int clanski_broj){
        if(!evidencijski_broj || !knjige.count(evidencijski_broj))throw logic_error("Knjiga nije nadjena");
        else if(knjige[evidencijski_broj]->DaLiJeZaduzena())throw logic_error("Knjiga vec zaduzena");
        else if(!clanski_broj || !korisnici.count(clanski_broj))throw logic_error("Korisnik nije nadjen");
        NadjiKnjigu(evidencijski_broj).ZaduziKnjigu(NadjiKorisnika(clanski_broj));
    }
    void RazduziKnjigu(int evidencijski_broj){
        if(!evidencijski_broj || !knjige.count(evidencijski_broj))throw logic_error("Knjiga nije nadjena");
        else if(!knjige[evidencijski_broj]->DaLiJeZaduzena())throw logic_error("Knjiga nije zaduzena");
        NadjiKnjigu(evidencijski_broj).RazduziKnjigu();
    }
    void PrikaziZaduzenja(int clanski_broj){
        int br(0);
        if(!clanski_broj || !korisnici.count(clanski_broj))throw domain_error("Korisnik nije nadjen");
        for(auto it=knjige.begin();it!=knjige.end();it++){
            if(it->second->DajKodKogaJe()->ime==NadjiKorisnika(clanski_broj).ime && it->second->DajKodKogaJe()->prezime==NadjiKorisnika(clanski_broj).prezime && it->second->DajKodKogaJe()->adresa==NadjiKorisnika(clanski_broj).adresa && it->second->DajKodKogaJe()->telefon==NadjiKorisnika(clanski_broj).telefon){
                cout<<"Evidencijski broj: "<<it->first<<endl;
                cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
                cout<<"Pisac: "<<it->second->DajAutora()<<endl;
                cout<<"Zanr: "<<it->second->DajZanr()<<endl;
                cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
            }
        }
        if(br==0)throw domain_error("Nema zaduzenja za tog korisnika");
    }
};
int main ()
{
    Biblioteka Vogosca;
    Biblioteka Dobrinja(Vogosca);
    cout<<"Registracija novog korisnika: 1 "<<endl;
    cout<<"Registracija nove knjige: 2"<<endl;
    cout<<"Nadji korisnika: 3"<<endl;
    cout<<"Nadji knjigu: 4"<<endl;
    cout<<"Izlistaj korisnike: 5"<<endl;
    cout<<"Izlistaj knjige: 6"<<endl;
    cout<<"Zaduzi knjigu: 7"<<endl;
    cout<<"Razduzi knjigu: 8"<<endl;
    cout<<"Prikazi zaduzenja korisnika: 9"<<endl;
    cout<<"Prekini sa radom: 10"<<endl;
    int Komanda(0);
    while(Komanda!=10){
    if(Komanda==1){
        int clanski_broj;
        string ime,prezime,adresa,br_telefona;
        cout<<"Unesi clanski broj korisnika: "<<endl;
        cin>>clanski_broj;
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Unesi ime korisnika: "<<endl;
        getline(cin,ime);
        cout<<"Unesi prezime korisnika: "<<endl;
        getline(cin,prezime);
        cout<<"Unesi adresu korisnika: "<<endl;
        getline(cin,adresa);
        cout<<"Unesi broj telefona korisnika: "<<endl;
        getline(cin,br_telefona);
        Dobrinja.RegistrirajNovogKorisnika(clanski_broj,ime,prezime,adresa,br_telefona);
    }
    if(Komanda==2){
        int evidencijski_broj,godina_izdavanja;
        string naslov,ime_pisca,zanr;
        cout<<"Unesi evidencijski broj knjige: "<<endl;
        cin>>evidencijski_broj;
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Unesi naslov knjige "<<endl;
        getline(cin,naslov);
        cout<<"Unesi ime pisca: "<<endl;
        getline(cin,ime_pisca);
        cout<<"Unesi zanr knjige: "<<endl;
        getline(cin,zanr);
        cout<<"Unesi godinu izdavanja: "<<endl;
        cin>>godina_izdavanja;
        Dobrinja.RegistrirajNovuKnjigu(evidencijski_broj,naslov,ime_pisca,zanr,godina_izdavanja);
    }
    if(Komanda==3){
        int clanski_broj;
        cout<<"Clanski broj korisnika: "<<endl;
        cin>>clanski_broj;
        try{
        Dobrinja.NadjiKorisnika(clanski_broj);
        }
        catch(logic_error izuzetak){
            cout<<izuzetak.what()<<endl;
        }
    }
    if(Komanda==4){
        int evidencijski_broj;
        cout<<"Evidencijski broj knjige: "<<endl;
        cin>>evidencijski_broj;
        try{
        Dobrinja.NadjiKnjigu(evidencijski_broj);
        }
        catch(logic_error izuzetak){
            cout<<izuzetak.what()<<endl;
        }
    }
    if(Komanda==5){
        Dobrinja.IzlistajKorisnike();
    }
    if(Komanda==6){
        Dobrinja.IzlistajKnjige();
    }
    if(Komanda==7){
        int evidencijski_broj,clanski_broj;
        cout<<"Unesi evidencijski broj knjige: "<<endl;
        cin>>evidencijski_broj;
        cout<<"Unesi clanski broj korisnika: "<<endl;
        cin>>clanski_broj;
        try{
        Dobrinja.ZaduziKnjigu(evidencijski_broj,clanski_broj);
        }
        catch(logic_error izuzetak){
            cout<<izuzetak.what()<<endl;
        }
    }
    if(Komanda==8){
        int evidencijski_broj;
        cout<<"Unesi evidencijski broj knjige: "<<endl;
        cin>>evidencijski_broj;
        try{
        Dobrinja.RazduziKnjigu(evidencijski_broj);
        }
        catch(logic_error izuzetak){
            cout<<izuzetak.what()<<endl;
        }
    }
    if(Komanda==9){
        int clanski_broj;
        cout<<"Unesi clanski broj korisnika: "<<endl;
        cin>>clanski_broj;
        try{
        Dobrinja.PrikaziZaduzenja(clanski_broj);
        }
        catch(domain_error izuzetak){
            cout<<izuzetak.what()<<endl;
        }
    }
    while(true)
    {
        cout<<"Unesi komandu: ";
        cin>>Komanda;
        cin.clear();
        cin.ignore(1000,'\n');
        if(!cin || Komanda<1 || Komanda>10){
            cout<<"Neispravna komanda!"<<endl;
            cout<<"Unesi ponovo: ";
            
        }
        else break;
    }
    }
return 0;
}