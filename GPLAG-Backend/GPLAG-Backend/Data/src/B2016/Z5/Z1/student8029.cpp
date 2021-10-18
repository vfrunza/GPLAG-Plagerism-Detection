/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <stdexcept>
struct Korisnik{
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
    
    
};
class Knjiga {
std::string naslov;
std::string ime_pisca;
std::string zanr;
int godina_izdavanja;
Korisnik* zaduzen=nullptr;
friend class Biblioteka;
friend void IzlistajKnjigu( Knjiga k) ;
public:
Knjiga(std::string naslov_ulaz,std::string ime,std::string zanr_ulaz,int godina)
{
    naslov=naslov_ulaz;ime_pisca=ime;zanr=zanr_ulaz;godina_izdavanja=godina;
}
std::string DajNaslov() const
{
    return naslov;
}
std::string DajAutora() const{
    return ime_pisca;
}
std::string DajZanr() const{
    return zanr;
}
int DajGodinuIzdavanja() const
{
    return godina_izdavanja;
}
Korisnik* DajKodKogaJe() const{
    return zaduzen;
}

Knjiga ZaduziKnjigu( Korisnik &k) 
{
    zaduzen=&k;
    return *this;
}

Knjiga RazduziKnjigu(){
    zaduzen=nullptr;
    return *this;
}
bool DaLiJeZaduzena() const
{
    if(zaduzen==nullptr)
    return false;
    return true;
}
};

class Biblioteka{
    std::map<int,Korisnik*> korisnik;
    std::map<int,Knjiga*> knjiga;
    public:
    Biblioteka(){};
    Biblioteka(const Biblioteka &l);
    Biblioteka(Biblioteka &&l);
    Biblioteka &operator =(const Biblioteka &l);
    Biblioteka &operator =(Biblioteka &&l);
    ~Biblioteka()
    {
        for(auto it=korisnik.begin();it!=korisnik.end();it++)
        {
            delete it->second;
        }
        for(auto it=knjiga.begin();it!=knjiga.end();it++)
        delete it->second;
    }
    Biblioteka RegistrirajNovogKorisnika(int broj,std::string ime,std::string prezime,std::string adresa,std::string broj_moba);
    Biblioteka RegistrirajNovuKnjigu(int evidencija,std::string naslov,std::string ime,std::string zanr,int godina);
    Korisnik &NadjiKorisnika(int broj) const;
    Knjiga &NadjiKnjigu(int broj) const;
     Biblioteka IzlistajKorisnike() const;
    Biblioteka IzlistajKnjige() const;
    Biblioteka ZaduziKnjigu(int broj_knjige,int broj_korisnika);
    Biblioteka RazduziKnjigu(int broj_knjige);
    Biblioteka PrikaziZaduzenja(int broj_korisnika);
};
 Biblioteka::Biblioteka(const Biblioteka &l)
{
    
    for(auto it=l.korisnik.begin();it!=l.korisnik.end();it++)
    {
        
        auto temp(new  Korisnik(*it->second));
        int br=it->first;
        korisnik.insert(std::make_pair(br,temp));
        
    }
    for(auto it=l.knjiga.begin();it!=l.knjiga.end();it++)
    {
        auto temp(new Knjiga(*it->second));
        int br=it->first;
        knjiga.insert(std::make_pair(br,temp));
    }
}
 Biblioteka::Biblioteka(Biblioteka &&l)
{
    korisnik=l.korisnik;
    knjiga=l.knjiga;
    for(auto it=l.korisnik.begin();it!=l.korisnik.end();it++)
    {
        it->second=nullptr;
    }
    for(auto it=l.knjiga.begin();it!=knjiga.end();it++)
    {
        it->second=nullptr;
    }


}
Biblioteka &Biblioteka::operator=(const Biblioteka &l)
{
    for(auto it=l.korisnik.begin();it!=l.korisnik.end();it++)
    {
        this->korisnik.insert(std::make_pair(it->first,new Korisnik(*it->second)));
    }
    for(auto it=l.knjiga.begin();it!=l.knjiga.end();it++)
    {
        this->knjiga.insert(std::make_pair(it->first,new Knjiga(*it->second)));
    }
    return *this;
}
Biblioteka &Biblioteka::operator =(Biblioteka &&l)
{
 *this=l;
  for(auto it=l.korisnik.begin();it!=l.korisnik.end();it++)
  it->second=nullptr;
  for(auto it=l.knjiga.begin();it!=l.knjiga.end();it++)
  it->second=nullptr;
    return *this;
    
    
}
Biblioteka Biblioteka::RegistrirajNovogKorisnika(int broj,std::string ime,std::string prezime,std::string adresa,std::string broj_moba)
{
    auto it(korisnik.find(broj));
    if(it!=korisnik.end())
    throw std::logic_error("Korisnik vec postoji");
     Korisnik k;
    k.ime=ime;
    k.prezime=prezime;
    k.adresa=adresa;
    k.telefon=broj_moba;
    Korisnik* temp=new Korisnik(k);
    korisnik.insert(std::make_pair(broj,temp));
    return *this;
  
}
Biblioteka Biblioteka:: RegistrirajNovuKnjigu(int evidencija,std::string naslov,std::string ime,std::string zanr,int godina)
{
    auto it(knjiga.find(evidencija));
    if(it!=knjiga.end())
    throw std::logic_error("Knjiga vec postoji");
    Knjiga* temp=new Knjiga(naslov,ime,zanr,godina);
    knjiga.insert(std::make_pair(evidencija,temp));
    return *this;
}
Korisnik& Biblioteka::NadjiKorisnika(int broj) const
{
    auto it(korisnik.find(broj));
    if(it==korisnik.end())
    throw std::logic_error("Korisnik nije nadjen");
    return *it->second;
    
}
Knjiga& Biblioteka::NadjiKnjigu(int broj) const
{
    auto it(knjiga.find(broj));
    if(it==knjiga.end())
    throw std::logic_error("Knjiga nije nadjena");
    return *it->second;

}
 Biblioteka Biblioteka::IzlistajKorisnike() const
{
    for(auto it=korisnik.begin();it!=korisnik.end();it++)
    {
        std::cout<<"Clanski broj: "<<it->first<<"\n";
        std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<"\n";
        std::cout<<"Adresa: "<<it->second->adresa<<"\n";
        std::cout<<"Broj telefona: "<<it->second->telefon<<"\n";
        std::cout<<"\n";
    }
        return *this;
    
}
void IzlistajKnjigu( Knjiga k) 
{
    std::cout<<"Naslov: "<<k.naslov<<"\n";
    std::cout<<"Pisac: "<<k.ime_pisca<<"\n";
    std::cout<<"Zanr: "<<k.zanr<<"\n";
    std::cout<<"Godina izdavanja: "<<k.godina_izdavanja<<"\n";
    
    
}
Biblioteka Biblioteka::IzlistajKnjige() const
{
    for(auto it=knjiga.begin();it!=knjiga.end();it++)
    {
        std::cout<<"Evidencijski broj: "<<it->first<<"\n";
        IzlistajKnjigu(*it->second);
        if(it->second->zaduzen!=nullptr)
        {
            std::cout<<"Zaduzena kod korisnika: "<<it->second->zaduzen->ime<<" "<<it->second->zaduzen->prezime<<"\n";
        }
        std::cout<<"\n";
    }
    return *this;
}
Biblioteka Biblioteka::ZaduziKnjigu(int broj_knjige,int broj_korisnika)
{
    auto it(knjiga.find(broj_knjige));
    if(it==knjiga.end())
    throw std::logic_error("Knjiga nije nadjena");
    if(it->second->zaduzen!=nullptr)
    throw std::logic_error("Knjiga vec zaduzena");
    auto it2(korisnik.find(broj_korisnika));
    if(it2==korisnik.end())
    throw std::logic_error("Korisnik nije nadjen");
    it->second->zaduzen=it2->second;
    return *this;
    
}
Biblioteka Biblioteka::RazduziKnjigu(int broj_knjige)
{
    auto it(knjiga.find(broj_knjige));
    if(it==knjiga.end())
    throw std::logic_error("Knjiga nije nadjena");
    if(it->second->zaduzen==nullptr)
    throw std::logic_error("Knjiga nije zaduzena");
    it->second->zaduzen=nullptr;
    return *this;
 
}
Biblioteka Biblioteka::PrikaziZaduzenja(int broj_korisnika)
{
    int brojac(0);
    auto it(korisnik.find(broj_korisnika));
    if(it==korisnik.end())
    throw std::domain_error("Korisnik nije nadjen");
    for(auto it2=knjiga.begin();it2!=knjiga.end();it2++)
    {
        if(it2->second->zaduzen==it->second)
        {
            brojac++;
        std::cout<<"Adresa: "<<it->second->adresa<<"\n";
        std::cout<<"Broj telefona: "<<it->second->telefon<<"\n";
        std::cout<<"\n";
            
        }
        
    }
    if(brojac==0)
    {
        std::cout<<"Nema zaduzenja za tog korisnika!";
    }
    
    return *this;
    
}
int main ()
{ 
	return 0;
}