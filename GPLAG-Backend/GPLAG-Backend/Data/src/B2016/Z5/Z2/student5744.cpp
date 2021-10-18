/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <string>
#include <map>
#include <new>
#include <stdexcept>
#include <iostream>
#include <memory>
struct Korisnik
{
    std::string ime,prezime,adresa,telefon;
};
class Knjiga
{
    Korisnik *k;
    std::string pis,nas,zan;
    int god;
public:
    Knjiga(std::string n,std::string p,std::string z,int g)
    {
        k=nullptr;
        nas=n;
        pis=p;
        zan=z;
        god=g;
    }
    std::string DajNaslov()const{return nas;}
    std::string DajAutora()const{return pis;} 
    std::string DajZanr()const{return zan;} 
    int DajGodinuIzdavanja()const{return god;} 
    Korisnik *DajKodKogaJe(){return k;}
    void ZaduziKnjigu(Korisnik &kor)
    {
        k=&kor;
    }
    void RazduziKnjigu()
    {
        k=nullptr;
    }
    bool DaLiJeZaduzena()const
    {
        return bool(k);
    }
};
class Biblioteka
{
    std::map<int,std::shared_ptr<Knjiga>> knjige;
    std::map<int,std::shared_ptr<Korisnik>> kor;
public:
    Biblioteka()
    {
    }
    Biblioteka(const Biblioteka &b)
    {
        for(auto it=b.knjige.begin();it!=b.knjige.end();it++) 
        {
            knjige[it->first]= std::make_shared<Knjiga>(it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja()) ;
            knjige[it->first]->ZaduziKnjigu(*(it->second->DajKodKogaJe()));
        }
        for(auto it=b.kor.begin();it!=b.kor.end();it++) 
        {
            kor[it->first] =std::make_shared<Korisnik>(*(it->second));
        }
    }
    Biblioteka(Biblioteka &&b)
    {
        for(auto it=b.knjige.begin();it!=b.knjige.end();it++) 
        {
            knjige[it->first] = it->second;
            b.knjige[it->first] = nullptr;
        }
        for(auto it=b.kor.begin();it!=b.kor.end();it++) 
        {
            kor[it->first] = it->second;
            b.kor[it->first] = nullptr;
        }
    }
    Biblioteka &operator= (const Biblioteka &b)
    {
        kor.clear();
        knjige.clear();
       for(auto it=b.knjige.begin();it!=b.knjige.end();it++) 
        {
            knjige[it->first]= std::make_shared<Knjiga>(it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja()) ;
            knjige[it->first]->ZaduziKnjigu(*(it->second->DajKodKogaJe()));
        }
        for(auto it=b.kor.begin();it!=b.kor.end();it++) 
        {
            kor[it->first] =std::make_shared<Korisnik>(*(it->second));
        }
        return *this;
    }
    Biblioteka &operator =(Biblioteka &&b)
    {
        kor.clear();
        knjige.clear();
        for(auto it=b.knjige.begin();it!=b.knjige.end();it++) 
        {
            knjige[it->first] = it->second;
            b.knjige[it->first] = nullptr;
        }
        for(auto it=b.kor.begin();it!=b.kor.end();it++) 
        {
            kor[it->first] = it->second;
            b.kor[it->first] = nullptr;
        }
        return *this;
    }
    void RegistrirajNovogKorisnika(int id,std::string i,std::string p,std::string a,std::string bt)
    {
        if(kor.count(id)) throw std::logic_error("Korisnik vec postoji");
        kor[id]=std::make_shared<Korisnik>();
        kor[id]->ime=i;
        kor[id]->prezime=p;
        kor[id]->adresa=a;
        kor[id]->telefon=bt;
    }
    void RegistrirajNovuKnjigu(int id,std::string n,std::string p,std::string z,int g)
    {
        if(knjige.count(id)) throw std::logic_error("Knjiga vec postoji");
        knjige[id]=std::make_shared<Knjiga>(n,p,z,g);
    }
    Korisnik &NadjiKorisnika(int id)
    {
        if(!kor.count(id)) throw std::logic_error("Korisnik nije nadjen");
        else return *kor[id];
    }
    Knjiga &NadjiKnjigu(int id)
    {
        if(!knjige.count(id)) throw std::logic_error("Knjiga nije nadjena");
        else return *knjige[id];
    }
    void IzlistajKorisnike() const 
    {
        for(auto it=kor.begin();it!=kor.end();it++)
        {
            std::cout << "Clanski broj: " << it->first << "\nIme i prezime: " << it->second->ime << " " << it->second->prezime << "\nAdresa: " << it->second->adresa << "\nBroj telefona: " << it->second->telefon <<"\n";
        }
    }
    void IzlistajKnjige() const
    {
        for(auto it=knjige.begin();it!=knjige.end();it++)
        {
            std::cout << "Evidencijski broj: " << it->first << "\nNaslov: " << it->second->DajNaslov()  << "\nPisac: " << it->second->DajAutora() << "\nZanr: " << it->second->DajZanr() << "\nGodina izdavanja: " << it->second->DajGodinuIzdavanja() <<"\n";
            if(it->second->DaLiJeZaduzena()) std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime << " " <<it->second->DajKodKogaJe()->prezime << "\n";
        }
    }
    void ZaduziKnjigu(int ev,int id)
    {
        if(!knjige.count(ev)) throw std::logic_error("Knjiga nije nadjena");
        if(!kor.count(id)) throw std::logic_error("Korisnik nije nadjen");
        if(knjige[ev]->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
        knjige[ev]->ZaduziKnjigu(*kor[id]);
    }
    void RazduziKnjigu(int ev)
    {
        if(!knjige.count(ev)) throw std::logic_error("Knjiga nije nadjena");
        if(!knjige[ev]->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
        knjige[ev]->RazduziKnjigu();
    }
    void PrikaziZaduzenja(int id)
    {
        bool isp=true;
        if(!kor.count(id)) throw std::logic_error("Korisnik nije nadjen");
        for(auto it=knjige.begin();it!=knjige.end();it++)
        {
            if((it->second->DajKodKogaJe())==kor[id].get())
            isp=false,std::cout << "Evidencijski broj: " << it->first << "\nNaslov: " << it->second->DajNaslov()  << "\nPisac: " << it->second->DajAutora() << "\nZanr: " << it->second->DajZanr() << "\nGodina izdavanja: " << it->second->DajGodinuIzdavanja() <<"\n";
        }
        if(isp) std::cout << "Nema zaduzenja za tog korisnika!";
    }
};
int main ()
{
	return 0;
}