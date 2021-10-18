/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
using std::string;
using std::cout;
using std::endl;
struct Korisnik{
    string ime,prezime,adresa,telefon;   
};
class Knjiga{
    string naslov,pisac,zanr;
    int god_izdavanja;
    Korisnik *pokazivac_na_korisnika;
    public:
    Knjiga(string n,string a,string z,int god):naslov(n),pisac(a),zanr(z),god_izdavanja(god){pokazivac_na_korisnika=nullptr;}
    //testiran konstruktor
    string DajNaslov() const { return naslov; }//testirano
    string DajAutora() const { return pisac; }//testirano
    string DajZanr() const { return zanr; }//testirno
    int DajGodinuIzdavanja()const { return god_izdavanja; }//testirano
    Korisnik *DajKodKogaJe()const {return pokazivac_na_korisnika; }//testirano
    void ZaduziKnjigu(Korisnik &kor){
        pokazivac_na_korisnika=&kor;
    };
    void RazduziKnjigu(){pokazivac_na_korisnika=nullptr;}
    bool DaLiJeZaduzena(){ if(!pokazivac_na_korisnika)return false; return true;}//testirana
};
class Biblioteka{
    std::map<int,Korisnik*> korisnici;
    std::map<int,Knjiga*> knjige;
    public:
    void RegistrirajNovogKorisnika(int cl_broj,string kime,string kprezime,string kadresa,string ktelefon){
        for(auto it(korisnici.begin());it!=korisnici.end();it++)
            if(it->first==cl_broj)throw std::logic_error("Korisnik vec postoji");
        Korisnik *k=new Korisnik;
        korisnici[cl_broj]=k;
        k->ime=kime;
        k->prezime=kprezime;
        k->adresa=kadresa;
        k->telefon=ktelefon;
    }
    void RegistrirajNovuKnjigu(int ev_broj,string name,string aut,string genre,int god){
        for(auto it(knjige.begin());it!=knjige.end();it++)
            if(it->first==ev_broj)throw std::logic_error("Knjiga vec postoji");
        Knjiga *k=new Knjiga(name,aut,genre,god);
        knjige[ev_broj]=k;
    }
    Korisnik &NadjiKorisnika(int cl_broj){
        auto it = korisnici.find(cl_broj);
        if(it!=korisnici.end())return *(it->second);   
        throw std::logic_error("Korisnik nije pronadjen");
    }
    Knjiga &NadjiKnjigu(int n){
        auto it(knjige.find(n));
        if(it!=knjige.end())return *(it->second);
        throw std::logic_error("Knjiga nije pronadjena");
    }
    void ZaduziKnjigu(int ev,int cl){
        auto it_knjiga(knjige.find(ev));
        auto it_kor(korisnici.find(cl));
        if(it_knjiga==knjige.end())throw std::logic_error("Knjiga nije nadjena");
        if(it_kor==korisnici.end())throw std::logic_error("Korisnik nije nadjen");
        if(it_knjiga->second->DaLiJeZaduzena())throw std::logic_error("Knjiga vec zaduzena");
        it_knjiga->second->Knjiga::ZaduziKnjigu(*(it_kor->second));
    }
    void IzlistajKorisnike()const{
        for(auto x(korisnici.begin());x!=korisnici.end();x++)
        {
            cout<<"Clanski broj: "<<x->first<<endl;
            cout<<"Ime i prezime: "<<(x->second)->ime<<" "<<(x->second)->prezime<<endl;
            cout<<"Adresa: "<<(x->second)->adresa<<endl;
            cout<<"Broj telefona: "<<(x->second)->telefon<<endl;
            cout<<endl;
        }
    }
    void IzlistajKnjige()const{
        for(auto x(knjige.begin());x!=knjige.end();x++)
        {
            cout<<"Evidencijski broj: "<<x->first<<endl;
            cout<<"Naslov: "<<x->second->DajNaslov()<<endl;
            cout<<"Pisac: "<<x->second->DajAutora()<<endl;
            cout<<"Zanr: "<<x->second->DajZanr()<<endl;
            cout<<"Godina izdavanja: "<<x->second->DajGodinuIzdavanja()<<endl;
            if(x->second->DaLiJeZaduzena())
            cout<<"Zaduzena kod korisnika: "<<x->second->DajKodKogaJe()->ime<<" "<<x->second->DajKodKogaJe()->prezime;
            cout<<endl;
        }
    }
    ~Biblioteka(){
        for(auto it(korisnici.begin());it!=korisnici.end();it++)
         delete it->second;
        for(auto it(knjige.begin());it!=knjige.end();it++)
         delete it->second; 
    }
   /* void PrikaziZaduzenja(int n){
        for(auto it(knjige.begin());it!=knjige.end();it++)
        {
            cout<<"Evidencijski broj: "<<it->first<<endl;
            cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
            cout<<"Pisac: "<<it->second->DajAutora()<<endl;
            cout<<"Zanr: "<<it->second->DajZanr()<<endl;
            cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        }
    }*/
    //treba dodati kopiranje tj kopirajuci konstruktor i operaotr= koji orave duboke kopije
   /* friend Biblioteka &operator =(Biblioteka &a,Biblioteka &b)
    {
        for(auto it(a.korisnici.begin());it!=b.korisnici.end();it++)
         delete it->second;
        for(auto it(a.knjige.begin());it!=a.knjige.end();it++)
            delete it->second;
            
    }*/
};
int main ()
{
	return 0;
}