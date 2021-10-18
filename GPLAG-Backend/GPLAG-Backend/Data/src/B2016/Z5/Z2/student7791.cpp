/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <utility>
#include <stdexcept>
using std::map;
using std::string;
using std::cin;
using std::cout;

struct Korisnik
{
    string ime;
    string prezime;
    string adresa;
    string telefon;
};
class Knjiga
{
    private:
    string naslov;
    string ime_pisca;
    string zanr;
    int godina_izdavanja;
    Korisnik *p;
    public:
    Knjiga(string nasl,string ime_p,string zanrr,int godina) :naslov(nasl),ime_pisca(ime_p),zanr(zanrr),godina_izdavanja(godina) {p=nullptr;}
    string DajNaslov() const {return naslov;}
    string DajAutora() const {return ime_pisca;}
    string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdavanja;}
    Korisnik* DajKodKogaJe() const{return p;}
    void ZaduziKnjigu(Korisnik &r){p=&r;}
    void RazduziKnjigu(){p=nullptr;};
    bool DaLiJeZaduzena(){if(p!=nullptr) return true; return false;}
};
class Biblioteka
{
  private:
  map<int,std::shared_ptr<Korisnik>> mapa_korisnika;
  map<int,std::shared_ptr<Knjiga>> mapa_knjiga;
  public:
~Biblioteka()=default;
Biblioteka(){}
Biblioteka(const Biblioteka &biblioteka);
Biblioteka(Biblioteka &&biblioteka);
Biblioteka &operator =(const Biblioteka &biblioteka);
Biblioteka &operator =(Biblioteka &&biblioteka);
void RegistrirajNovogKorisnika(int clanski,string ime,string prezime,string adresa,string telefon);
void RegistrirajNovuKnjigu(int evidencijski_broj,string naslov,string ime_pisca,string zanr,int godina_izdavanja);
Korisnik &NadjiKorisnika (int clanski) const;
Knjiga &NadjiKnjigu (int evidencijski_broj) const;
void IzlistajKorisnike() const;
void IzlistajKnjige() const;
void ZaduziKnjigu(int evidencijski_broj,int clanski);
void RazduziKnjigu(int evidencijski_broj);
void PrikaziZaduzenja (int clanski) const;
};
void Biblioteka::RegistrirajNovogKorisnika(int clanski,string ime,string prezime,string adresa,string telefon)
{
    for(auto it=mapa_korisnika.begin();it!=mapa_korisnika.end();it++)
    {
        if(it->first==clanski)
        throw std::logic_error("Korisnik vec postoji");
    }
    Korisnik novi{ime,prezime,adresa,telefon};
     std::shared_ptr<Korisnik> novi_korisnik=std::make_shared<Korisnik>(novi);
     mapa_korisnika.insert(std::make_pair(clanski,novi_korisnik));
}
void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj,string naslov,string ime_pisca,string zanr,int godina_izdavanja)
{
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++)
    {
        if(it->first==evidencijski_broj)
        throw std::logic_error("Knjiga vec postoji");
    }
    std::shared_ptr<Knjiga> nova_knjiga=std::make_shared<Knjiga>(naslov,ime_pisca,zanr,godina_izdavanja);
    mapa_knjiga.insert(std::make_pair(evidencijski_broj,nova_knjiga));
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski) const
{
    for(auto it=mapa_korisnika.begin();it!=mapa_korisnika.end();it++)
    {
        if(it->first==clanski)
        {
            return *(it->second);
        }
    }
    throw std::logic_error("Korisnik nije nadjen");
}
Knjiga &Biblioteka::NadjiKnjigu (int evidencijski_broj) const
{
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++)
    {
        if(it->first==evidencijski_broj)
        {
        return *(it->second);
        }
    }
    throw std::logic_error("Knjiga nije nadjena");
}
void Biblioteka::IzlistajKorisnike() const
{
    for(auto it=mapa_korisnika.begin();it!=mapa_korisnika.end();it++)
    {
        cout<<"Clanski broj: "<<it->first<<std::endl;
        cout<<"Ime i prezime: "<<(*(it->second)).ime<<" "<<(*(it->second)).prezime<<std::endl;
        cout<<"Adresa: "<<(*(it->second)).adresa<<std::endl;
        cout<<"Broj telefona: "<<(*(it->second)).telefon<<std::endl;
        cout<<std::endl; //je li treba?
    }
}
void Biblioteka::IzlistajKnjige() const
{
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++)
    {
        cout<<"Evidencijski broj: "<<it->first<<std::endl;
        cout<<"Naslov: "<<(*(it->second)).Knjiga::DajNaslov()<<std::endl;
        cout<<"Pisac: "<<(*(it->second)).Knjiga::DajAutora()<<std::endl;
        cout<<"Zanr: "<<(*(it->second)).Knjiga::DajZanr()<<std::endl;
        cout<<"Godina izdavanja: "<<(*(it->second)).Knjiga::DajGodinuIzdavanja()<<std::endl;
        if((*(it->second)).Knjiga::DaLiJeZaduzena())
        cout<<"Zaduzena kod korisnika: "<<(*(it->second)).Knjiga::DajKodKogaJe()->ime<<" "<<(*(it->second)).Knjiga::DajKodKogaJe()->prezime<<std::endl;
        cout<<std::endl; //je li treba
    }
}
void Biblioteka::ZaduziKnjigu(int evidencijski_broj,int clanski)
{
    Knjiga knjiga=Biblioteka::NadjiKnjigu(evidencijski_broj);
    Korisnik korisnik=Biblioteka::NadjiKorisnika(clanski);
    if(knjiga.Knjiga::DaLiJeZaduzena())
    throw std::logic_error("Knjiga vec zaduzena");
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++)
    {
        if(it->first==evidencijski_broj)
        {
                (*(it->second)).Knjiga::ZaduziKnjigu(Biblioteka::NadjiKorisnika(clanski));
        }
    }
}
void Biblioteka::RazduziKnjigu(int evidencijski_broj)
{
    Knjiga knjiga=Biblioteka::NadjiKnjigu(evidencijski_broj);
    if(!knjiga.Knjiga::DaLiJeZaduzena())
    throw std::logic_error("Knjiga nije zaduzena");
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++)
    {
        if(it->first==evidencijski_broj)
        {
            (*(it->second)).Knjiga::RazduziKnjigu();
        }
    }
}
void Biblioteka::PrikaziZaduzenja(int clanski) const
{
    Korisnik korisnik=Biblioteka::NadjiKorisnika(clanski);
    Korisnik pom;
    int brojac(0);
    for(auto it2=mapa_korisnika.begin();it2!=mapa_korisnika.end();it2++)
    {
        if(it2->first==clanski)
        pom=*it2->second;
    }
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++)
    {
        if((*(it->second)).Knjiga::DaLiJeZaduzena())
        {
            if((*((*(it->second)).Knjiga::DajKodKogaJe())).ime==pom.ime && (*((*(it->second)).Knjiga::DajKodKogaJe())).prezime==pom.prezime && (*((*(it->second)).Knjiga::DajKodKogaJe())).adresa==pom.adresa && (*((*(it->second)).Knjiga::DajKodKogaJe())).telefon==pom.telefon)
            {
        cout<<"Evidencijski broj: "<<it->first<<std::endl;
        cout<<"Naslov: "<<(*(it->second)).Knjiga::DajNaslov()<<std::endl;
        cout<<"Pisac: "<<(*(it->second)).Knjiga::DajAutora()<<std::endl;
        cout<<"Zanr: "<<(*(it->second)).Knjiga::DajZanr()<<std::endl;
        cout<<"Godina izdavanja: "<<(*(it->second)).Knjiga::DajGodinuIzdavanja()<<std::endl;
        cout<<std::endl; //je li treba
        brojac++;
            }
        }
    }
    if(brojac==0)
    cout<<"Nema zaduzenja za tog korisnika!";
}
Biblioteka::Biblioteka(const Biblioteka &prodaje)
{
 map<int,std::shared_ptr<Korisnik>> mapa_1;
  map<int,std::shared_ptr<Knjiga>> mapa_2;
  mapa_korisnika=mapa_1;
  mapa_knjiga=mapa_2;
    for(auto it1=prodaje.mapa_korisnika.begin();it1!=prodaje.mapa_korisnika.end();it1++)
    {
        Korisnik novi{(*(it1->second)).ime,(*(it1->second)).prezime,(*(it1->second)).adresa,(*(it1->second)).telefon};
        std::shared_ptr<Korisnik> novi_korisnik=std::make_shared<Korisnik>(novi);
        mapa_korisnika.insert(std::make_pair(it1->first,novi_korisnik));
    }
    for(auto it2=prodaje.mapa_knjiga.begin();it2!=prodaje.mapa_knjiga.end();it2++)
    {
        std::shared_ptr<Knjiga> nova_knjiga(std::make_shared<Knjiga>((*(it2->second)).Knjiga::DajNaslov(),(*(it2->second)).Knjiga::DajAutora(),(*(it2->second)).Knjiga::DajZanr(),(*(it2->second)).Knjiga::DajGodinuIzdavanja()));
        nova_knjiga->Knjiga::ZaduziKnjigu(*((*(it2->second)).Knjiga::DajKodKogaJe()));
        mapa_knjiga.insert(std::make_pair(it2->first,nova_knjiga));
    }
}
Biblioteka::Biblioteka(Biblioteka &&prodaje)
{
  map<int,std::shared_ptr<Korisnik>> mapa_1;
  map<int,std::shared_ptr<Knjiga>> mapa_2;
   mapa_korisnika=mapa_1;
  mapa_knjiga=mapa_2;
     for(auto it1=prodaje.mapa_korisnika.begin();it1!=prodaje.mapa_korisnika.end();it1++)
     {
         mapa_korisnika.insert(std::make_pair(it1->first,it1->second));
         (it1->second)=nullptr;
     }
     for(auto it2=prodaje.mapa_knjiga.begin();it2!=prodaje.mapa_knjiga.end();it2++)
     {
         mapa_knjiga.insert(std::make_pair(it2->first,it2->second));
         (it2->second)=nullptr;
     }
   //  prodaje.mapa_korisnika=mapa_1;
   //  prodaje.mapa_knjiga=mapa_2;
}
Biblioteka &Biblioteka::operator =(const Biblioteka &biblioteka)
{
    if(&biblioteka!=this)
    {
        for(auto it1=mapa_korisnika.begin();it1!=mapa_korisnika.end();it1++)
        {
            it1->second=nullptr;
        }
        for(auto it2=mapa_knjiga.begin();it2!=mapa_knjiga.end();it2++)
        {
            it2->second=nullptr;
        }
        map<int,std::shared_ptr<Korisnik>> mapa_1;
        map<int,std::shared_ptr<Knjiga>> mapa_2;
        mapa_korisnika=mapa_1;
        mapa_knjiga=mapa_2;
        for(auto it1=biblioteka.mapa_korisnika.begin();it1!=biblioteka.mapa_korisnika.end();it1++)
        {
            mapa_korisnika.insert(std::make_pair(it1->first,it1->second));
        }
        for(auto it2=biblioteka.mapa_knjiga.begin();it2!=biblioteka.mapa_knjiga.end();it2++)
        {
            mapa_knjiga.insert(std::make_pair(it2->first,it2->second));
        }
    }
    return *this;
}
Biblioteka &Biblioteka::operator =(Biblioteka &&biblioteka)
{
    if(&biblioteka!=this)
    {
        std::swap(mapa_korisnika,biblioteka.mapa_korisnika);
        std::swap(mapa_knjiga,biblioteka.mapa_knjiga);
    }
    return *this;
}
int main ()
{
	return 0;
	
}