/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <map>
#include <stdexcept>
#include <memory>
using namespace std;

struct Korisnik
{
    string ime, prezime, adresa, telefon;
};

class Knjiga
{
    string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *korisnik=nullptr;
    bool zaduzen=false;
     
    public:
    
    Knjiga(string name, string ime, string vrsta, int datum)
    {
        naslov=name; ime_pisca=ime; zanr=vrsta; godina_izdavanja=datum;
        korisnik=nullptr;
        zaduzen=false;
    }
    
    string DajNaslov() const {return naslov;}
    string DajAutora() const {return ime_pisca;}
    string DajZanr() const  {return zanr;}
    int DajGodinuIzdavanja() {return godina_izdavanja;}
    Korisnik* DajKodKogaJe() {return korisnik;}
    
    void ZaduziKnjigu(Korisnik &k) {korisnik=&k; zaduzen=true;}
    void RazduziKnjigu() {korisnik=nullptr; zaduzen=false;}
    bool DaLiJeZaduzena() {return zaduzen;}
    
};

class Biblioteka
{
    map<int, shared_ptr<Korisnik> > korisnici;
    map<int, shared_ptr<Knjiga> > knjige;
    
    public:
    
    Biblioteka() {};
    
    ~Biblioteka()
    {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
            it->second=nullptr;
        
         for(auto it=knjige.begin(); it!=knjige.end(); it++)
            it->second=nullptr;
    }
    
    Biblioteka(const Biblioteka &v)
       {
           for(auto it=v.korisnici.begin();it!=v.korisnici.end();it++)
           korisnici[it->first]= make_shared<Korisnik>(Korisnik{it->second->ime, it->second->prezime,it->second->adresa,it->second->telefon});
           
           for(auto it=knjige.begin(); it!=knjige.end(); it++)
           {
              knjige[it->first]= make_shared<Knjiga>(Knjiga{it->second->DajNaslov(), it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja()});
           }
       }
       
    Biblioteka(const Biblioteka &&v)
       {
         for(auto it=v.korisnici.begin();it!=v.korisnici.end();it++)
           korisnici[it->first]=nullptr;
           
          for(auto it=knjige.begin(); it!=knjige.end(); it++)
           
              knjige[it->first]=nullptr;
           
       }
    Biblioteka operator=(const Biblioteka &&v)
    {
        if(&v==this)return *this;
     for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
            it->second=nullptr;
        
         for(auto it=knjige.begin(); it!=knjige.end(); it++)
            it->second=nullptr;
            
      for(auto it=v.korisnici.begin();it!=v.korisnici.end();it++)
           korisnici[it->first]=nullptr;
           
          for(auto it=knjige.begin(); it!=knjige.end(); it++)
           
              knjige[it->first]=nullptr;
           return *this;   
    }
       
    Biblioteka operator=(const Biblioteka &v)
    {
        if(this==&v)return *this;
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
            it->second=nullptr;
        
         for(auto it=knjige.begin(); it!=knjige.end(); it++)
            it->second=nullptr;
            
            for(auto it=v.korisnici.begin();it!=v.korisnici.end();it++)
           korisnici[it->first]=make_shared<Korisnik>(Korisnik{it->second->ime, it->second->prezime,it->second->adresa,it->second->telefon});
           
           for(auto it=knjige.begin(); it!=knjige.end(); it++)
           {
              knjige[it->first]=make_shared<Knjiga>(Knjiga{it->second->DajNaslov(), it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja()});
           }
           
           return *this;
    }
    
    void RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime, string adresa, string telefon)
    {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
            if(it->first==clanski_broj)
                throw logic_error("Korisnik vec postoji");
        korisnici[clanski_broj]=make_shared<Korisnik>(Korisnik{ime, prezime, adresa, telefon});
    }
    
    void RegistrirajNovuKnjigu(int evid_broj, string naziv, string pisac, string zanr, int date)
    {
        for(auto it=knjige.begin(); it!=knjige.end(); it++)
            if(it->first==evid_broj)
                throw logic_error("Knjiga vec postoji");
        knjige[evid_broj]=make_shared<Knjiga>(naziv, pisac, zanr, date);
    }
    
    Korisnik &NadjiKorisnika(int broj)
    {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
            if(it->first==broj)
                return *it->second;
        throw logic_error("Korisnik nije nadjen");
    }
    
    Knjiga &NadjiKnjigu(int broj)
    {
        for(auto it=knjige.begin(); it!=knjige.end(); it++)
            if(it->first==broj)
                return *it->second;
        throw logic_error("Knjiga nije nadjena");
    }
    
    void IzlistajKorisnike()
    {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
        {
            cout<<"Clanski broj: "<<it->first<<endl<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl;
            cout<<"Adresa: "<<it->second->adresa<<endl<<"Broj telefona: "<<it->second->telefon<<endl<<endl;
        }
    }
    
    void IzlistajKnjige()
    {
        for(auto it=knjige.begin(); it!=knjige.end(); it++)
        {
            cout<<"Evidencijski broj: "<<it->first<<endl<<"Naslov: "<<it->second->DajNaslov()<<endl<<"Pisac: "<<it->second->DajAutora()<<endl;
            cout<<"Zanr: "<<it->second->DajZanr()<<endl<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
            if(it->second->DaLiJeZaduzena())
                cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;
            cout<<endl;
        }
    }
    
    void ZaduziKnjigu(int evid_br, int cl_br)
    {
        bool moze1=false, moze2=false;
        for(auto it=knjige.begin(); it!=knjige.end(); it++)
        {
            if(it->first==evid_br)
                moze1=true;
            if(it->first==evid_br && it->second->DaLiJeZaduzena())
                throw logic_error("Knjiga vec zaduzena");
        }
        if(!moze1) throw logic_error("Knjiga nije nadjena");
    
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
            if(it->first==cl_br)
                moze2=true;
        if(!moze2) throw logic_error("Korisnik nije nadjen");
        
        
        for(auto it=knjige.begin(); it!=knjige.end(); it++)
        {
            if(it->first==evid_br)
                for(auto it1=korisnici.begin(); it1!=korisnici.end(); it1++)
                    if(it1->first==cl_br)
                    {
                        it->second->ZaduziKnjigu(*it1->second);
                    }
        
        }
    }
    
    void RazduziKnjigu(int evid_br)
    {
        bool moze1=false;
        for(auto it=knjige.begin(); it!=knjige.end(); it++)
         {
             if(it->first==evid_br)
                moze1=true;
            if(it->first==evid_br && it->second->DaLiJeZaduzena()==0)
                throw logic_error("Knjiga nije zaduzena");
         }
        if(!moze1) throw logic_error("Knjiga nije nadjena");
        
        for(auto it=knjige.begin(); it!=knjige.end(); it++)
            if(it->first==evid_br)
                it->second->Knjiga::RazduziKnjigu();
    }
    
    void PrikaziZaduzenja(int cl_br)
    {
        int ima=-1;
        for(auto it1=korisnici.begin(); it1!=korisnici.end(); it1++)
            if(it1->first==cl_br)
            {
                ima=0;
                for(auto it=knjige.begin(); it!=knjige.end(); it++)
                    if(it->second->DaLiJeZaduzena())
                       if(it->second->DajKodKogaJe()->ime==it1->second->ime && it->second->DajKodKogaJe()->prezime==it1->second->prezime && it->second->DajKodKogaJe()->adresa==it1->second->adresa && it->second->DajKodKogaJe()->telefon==it1->second->telefon)
                            {
                                cout<<"Evidencijski broj: "<<it->first<<endl<<"Naslov: "<<it->second->DajNaslov()<<endl<<"Pisac: "<<it->second->DajAutora()<<endl;
                                cout<<"Zanr: "<<it->second->DajZanr()<<endl<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
                                cout<<endl;
                                ima=1;
                            }
            }
        if(ima==0) cout<<"Nema zaduzenja za tog korisnika!";
        if(ima==-1) throw logic_error("Korisnik nije nadjen");
        
    }
};




int main ()
{
Korisnik k2 { "Niko", "Nikic", "Zmaja od Bosne bb", "123 456"};
Knjiga knj2("Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
knj2.ZaduziKnjigu(k2);
if(!knj2.DaLiJeZaduzena()) std::cout << "Knjiga je slobodna";
else std::cout << "Knjiga je zaduzena";
knj2.RazduziKnjigu();
if(!knj2.DaLiJeZaduzena()) std::cout << "\nKnjiga je slobodna";
else std::cout << "\nKnjiga je zaduzena";
    
    /*
    Knjiga knj1("IM2", "Huse Fatkic", "Horor", 1979);
    cout<<endl<<endl<<knj1.DajAutora();
    cout<<endl;
    Biblioteka da;
    da.RegistrirajNovogKorisnika(17392, "Suljo", "Hero", "Prozor", "2347890");
    cout<<endl<<da.NadjiKorisnika(17392).ime;
    cout<<endl<<endl;
    da.IzlistajKorisnike();
    cout<<endl<<endl;
    da.RegistrirajNovuKnjigu(1211, "Starac i more", "Hemingvej", "Avanturisticki", 1967);
    da.ZaduziKnjigu(1211, 17392);
    da.IzlistajKnjige();
    da.RazduziKnjigu(1211);
    Biblioteka d;
    d=da;
    da.PrikaziZaduzenja(17392);
    cout<<endl<<endl;
    d.IzlistajKorisnike();*/
	return 0;
}