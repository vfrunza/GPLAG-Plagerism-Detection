/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <new>
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
  map<int,Korisnik*> mapa_korisnika;
  map<int,Knjiga*> mapa_knjiga;
  public:
~Biblioteka();
Biblioteka(){}
Biblioteka(const Biblioteka &biblioteka);
Biblioteka(Biblioteka &&biblioteka);
Biblioteka &operator =(const Biblioteka &biblioteka);
Biblioteka &operator =(Biblioteka &&biblioteka);
void RegistrirajNovogKorisnika(int clanski,string ime,string prezime,string adresa,string telefon);
void RegistrirajNovuKnjigu(int evidencijski_broj,string naslov,string ime_pisca,string zanr,int godina_izdavanja);
Korisnik &NadjiKorisnika(int clanski) const;
Knjiga &NadjiKnjigu(int evidencijski_broj) const;
void IzlistajKorisnike() const;
void IzlistajKnjige() const;
void ZaduziKnjigu(int evidencijski_broj,int clanski);
void RazduziKnjigu(int evidencijski_broj);
void PrikaziZaduzenja(int clanski) const;
};
void Biblioteka::RegistrirajNovogKorisnika(int clanski,string ime,string prezime,string adresa,string telefon)
{
    for(auto it=mapa_korisnika.begin();it!=mapa_korisnika.end();it++)
    {
        if(it->first==clanski)
        throw std::logic_error("Korisnik vec postoji");
    }
     Korisnik *novi_korisnik=new Korisnik{ime,prezime,adresa,telefon};
     mapa_korisnika.insert(std::make_pair(clanski,novi_korisnik));
}
void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj,string naslov,string ime_pisca,string zanr,int godina_izdavanja)
{
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++)
    {
        if(it->first==evidencijski_broj)
        throw std::logic_error("Knjiga vec postoji");
    }
    Knjiga *nova_knjiga=new Knjiga(naslov,ime_pisca,zanr,godina_izdavanja);
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
Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj) const
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
    Korisnik *pom;
    for(auto it2=mapa_korisnika.begin();it2!=mapa_korisnika.end();it2++)
    {
        if(it2->first==clanski)
        pom=it2->second;
    }
    int brojac(0);
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++)
    {
        if((*(it->second)).Knjiga::DaLiJeZaduzena())
        {
            if((*(it->second)).Knjiga::DajKodKogaJe()==pom)
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
Biblioteka::~Biblioteka()
{
    for(auto it1=mapa_korisnika.begin();it1!=mapa_korisnika.end();it1++)
    {
        delete (it1->second);
    }
    for(auto it2=mapa_knjiga.begin();it2!=mapa_knjiga.end();it2++)
    {
        delete (it2->second);
    }
}
Biblioteka::Biblioteka(const Biblioteka &prodaje)
{
 map<int,Korisnik*> mapa_1;
  map<int,Knjiga*> mapa_2;
  mapa_korisnika=mapa_1;
  mapa_knjiga=mapa_2;
    for(auto it1=prodaje.mapa_korisnika.begin();it1!=prodaje.mapa_korisnika.end();it1++)
    {
        Korisnik *novi_korisnik(new Korisnik{(*(it1->second)).ime,(*(it1->second)).prezime,(*(it1->second)).adresa,(*(it1->second)).telefon});
        mapa_korisnika.insert(std::make_pair(it1->first,novi_korisnik));
    }
    for(auto it2=prodaje.mapa_knjiga.begin();it2!=prodaje.mapa_knjiga.end();it2++)
    {
        Knjiga *nova_knjiga(new Knjiga((*(it2->second)).Knjiga::DajNaslov(),(*(it2->second)).Knjiga::DajAutora(),(*(it2->second)).Knjiga::DajZanr(),(*(it2->second)).Knjiga::DajGodinuIzdavanja()));
        nova_knjiga->Knjiga::ZaduziKnjigu(*((*(it2->second)).Knjiga::DajKodKogaJe()));
        mapa_knjiga.insert(std::make_pair(it2->first,nova_knjiga));
    }
}
Biblioteka::Biblioteka(Biblioteka &&prodaje)
{
  map<int,Korisnik*> mapa_1;
  map<int,Knjiga*> mapa_2;
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
            delete it1->second;
        }
        for(auto it2=mapa_knjiga.begin();it2!=mapa_knjiga.end();it2++)
        {
            delete it2->second;
        }
        map<int,Korisnik*> mapa_1;
        map<int,Knjiga*> mapa_2;
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
    Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic", "Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic", "Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic", "Studenata etfovaca 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
b.PrikaziZaduzenja(1234);
	return 0;
	
}