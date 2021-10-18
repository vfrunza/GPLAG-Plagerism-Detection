#include<iostream>
#include<string>
#include<stdexcept>
#include<map>
using namespace std;

struct Korisnik{
    string ime,prezime,adresa,telefon;
};

class Knjiga{
    string naslov;
    string pisac;
    string zanr;
    int godina_izdavanja;
    Korisnik *zaduzenje;
    public:
    Knjiga(string n,string p,string z, int g):
    zaduzenje(nullptr){ 
        naslov=n; pisac=p; zanr=z; godina_izdavanja=g; }
    void Postavi(string n, string p, string z, int g_i){ 
        naslov=n;
        pisac=p;
        zanr=z;
        godina_izdavanja=g_i;
        zaduzenje=nullptr;
    }
    string DajNaslov()const{ return naslov; }
    string DajAutora()const{ return pisac; }
    string DajZanr()const{ return zanr; }
    int DajGodinuIzdavanja() const{ return godina_izdavanja; }
    Korisnik *DajKodKogaJe() { return zaduzenje; } 
    void ZaduziKnjigu(Korisnik &k){ 
        zaduzenje=&k; }
    void RazduziKnjigu(){ zaduzenje=nullptr; }
    bool DaLiJeZaduzena(){ if(zaduzenje==nullptr) return false; return true; } 
 };

class Biblioteka{
    map<int,Korisnik*>korisnici; //kljuc: clanski broj korisnika
    map<int,Knjiga*>knjige; //kljuc: evidencijski broj knjige
    public:
    Biblioteka(){} //konstruktor bez parametara
    Biblioteka(const Biblioteka &b); //kopirajuci konstruktor
    //Biblioteka &operator=(const Biblioteka &b); //kopirajuci operator dodjele
    //Biblioteka(Biblioteka &&b); //pomjerajuci konstruktor
    //Biblioteka &operator =(Biblioteka &&b); //pomjerajuci operator dodjele
    ~Biblioteka(); //destruktor
    void RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime, string adresa, string telefon);
    void RegistrirajNovuKnjigu(int broj_knjige, string naslov, string pisac, string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int evidencijski_broj);
    void IzlistajKorisnike()const;
    void IzlistajKnjige()const;
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int clanski_broj);
    
};

//kopirajuci konstruktor
Biblioteka::Biblioteka(const Biblioteka &b){
    for(auto it=b.korisnici.begin();it!=b.korisnici.end();it++) korisnici[it->first]=new Korisnik{it->second->ime,it->second->prezime,it->second->adresa,it->second->telefon};
    for(auto it=b.knjige.begin();it!=b.knjige.end();it++) knjige[it->first]=new Knjiga{it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja()};
} 

//destruktor
Biblioteka::~Biblioteka(){
    for(auto it=korisnici.begin();it!=korisnici.end();it++) delete it->second; 
    for(auto it=knjige.begin();it!=knjige.end();it++) delete it->second;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime, string adresa, string telefon){
    for(auto it=korisnici.begin();it!=korisnici.end();it++){ if(it->first==clanski_broj) throw logic_error("Korisnik vec postoji"); }
    Korisnik *novi(new Korisnik); 
    novi->ime=ime; novi->prezime=prezime; novi->adresa=adresa; novi->telefon=telefon;
    korisnici.insert(make_pair(clanski_broj,novi));
}

void Biblioteka::RegistrirajNovuKnjigu(int broj_knjige, string naslov, string ime_pisca, string zanr, int godina_izdavanja){
    for(auto it=knjige.begin();it!=knjige.end();it++) if(it->first==broj_knjige) throw logic_error("Knjiga vec postoji");
    Knjiga *nova=new Knjiga(naslov,ime_pisca,zanr,godina_izdavanja);
    knjige.insert(make_pair(broj_knjige,nova));
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj){
    for(auto it=korisnici.begin();it!=korisnici.end();it++){ if(it->first==clanski_broj) return *(it->second); }
    throw logic_error("Korisnik nije nadjen"); 
}




Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj){
    for(auto it=knjige.begin();it!=knjige.end();it++){ if(it->first==evidencijski_broj) return *(it->second); } 
    throw logic_error("Knjiga nije nadjena"); 
}

void Biblioteka::IzlistajKorisnike()const{
     for(auto it=korisnici.begin();it!=korisnici.end();it++){
         cout<<"Clanski broj: "<<it->first<<endl;
         cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl;
         cout<<"Adresa: "<<it->second->adresa<<endl;
         cout<<"Broj telefona: "<<it->second->telefon<<endl;
         cout<<endl;
     }
}

void Biblioteka::IzlistajKnjige()const{
    for(auto it=knjige.begin();it!=knjige.end();it++){
        cout<<"Evidencijski broj: "<<it->first<<endl;
        cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
        cout<<"Pisac: "<<it->second->DajAutora()<<endl;
        cout<<"Zanr: "<<it->second->DajZanr()<<endl;
        cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        if(it->second->DaLiJeZaduzena()==true)
            cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;
    }
    cout<<endl;
}

void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj){
     auto it3=knjige.begin();
     for(;it3!=knjige.end();it3++){
     if(it3->second->DaLiJeZaduzena()==true && it3->first==evidencijski_broj) throw logic_error("Knjiga vec zaduzena"); }
    { auto it2=knjige.begin();
     while(it2!=knjige.end()){ if(it2->first==evidencijski_broj) break; else it2++; } 
     if(it2==knjige.end()) {throw logic_error("Knjiga nije nadjena"); }
 }   
 int emo=0;
 { auto it2=korisnici.begin();
     while(it2!=korisnici.end()){ if(it2->first==clanski_broj){ emo=1; break; } else it2++; } 
     if(emo==0) {throw logic_error("Korisnik nije nadjen"); }
 } 
 //vrsi registraciju da je navedena knjiga zaduzena kod navedenog korisnika
 for(auto it1=knjige.begin();it1!=knjige.end();it1++){
     if(it1->first==evidencijski_broj) {
          for(auto it=korisnici.begin();it!=korisnici.end();it++) { if(it->first==clanski_broj) it1->second->Knjiga::ZaduziKnjigu(*(it->second)); break; } }
}
}

void Biblioteka::RazduziKnjigu(int evidencijski_broj){
    { auto it2=knjige.begin();
     while(it2!=knjige.end()){ if(it2->first==evidencijski_broj) break; else it2++; } 
     if(it2==knjige.end()) {throw logic_error("Knjiga nije nadjena"); }
    }
    auto it=knjige.begin();
    for(;it!=knjige.end();it++) 
         if(it->second->DaLiJeZaduzena()==false){ throw logic_error("Knjiga nije zaduzena"); }
        //registrira da knjiga nije vise zaduzena
        for(auto it=knjige.begin();it!=knjige.end();it++){ if(it->first==evidencijski_broj) it->second->RazduziKnjigu(); break;}
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj){
    int emo=0;
    auto it2=korisnici.begin();
    while(it2!=korisnici.end()){ if(it2->first==clanski_broj){ emo=1; break; }else it2++; } 
    if(emo==0) throw logic_error("Korisnik nije nadjen");
    for(auto it=knjige.begin();it!=knjige.end();it++){
        cout<<"Evidencijski broj "<<it->first<<endl;
        cout<<"Naslov "<<it->second->DajNaslov()<<endl;
        cout<<"Pisac "<<it->second->DajAutora()<<endl;
        cout<<"Zanr "<<it->second->DajZanr()<<endl;
        cout<<"Godina izdavanja "<<it->second->DajGodinuIzdavanja()<<endl;
        cout<<endl;
    }
    /*for(auto it=knjige.begin();it!=knjige.end();it++){
    if(it->second->DaLiJeZaduzena()==false) {cout<<"Nema zaduzenja za tog korisnika!"; break;} } */
}

int main(){
    
return 0;

}
