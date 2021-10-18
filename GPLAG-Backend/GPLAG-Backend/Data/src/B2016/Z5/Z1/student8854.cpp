/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

struct Korisnik{
    std::string ime,prezime,adresa,telefon;
};

class Knjiga{
    std::string naslov,autor,zanr;
    int godina_izdavanja;
    Korisnik* vlasnik=nullptr;
    public:
    Knjiga(std::string naslov,std::string autor,std::string zanr,int godina_izdavanja) : naslov(naslov),autor(autor),zanr(zanr),godina_izdavanja(godina_izdavanja)
    {
        
    }
    std::string DajNaslov() const {return naslov;}
    std::string DajAutora() const {return autor;}
    std::string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdavanja;}
    Korisnik* DajKodKogaJe() const {return vlasnik;}
    void ZaduziKnjigu(Korisnik &vlasni){vlasnik=&vlasni;}
    void RazduziKnjigu(){vlasnik=nullptr;}
    bool DaLiJeZaduzena(){return vlasnik;}
    
};

class Biblioteka{
    std::map<int,Korisnik*> vlasnici;
    std::map<int,Knjiga*> knjige;
    public:
    
    Biblioteka(){}
    
    ~Biblioteka()
    {
        for(std::pair<int,Korisnik*> i:vlasnici)
        delete i.second;
        for(std::pair<int,Knjiga*> j:knjige)
        delete j.second;
    }
    Biblioteka(const Biblioteka &a)
    {
        
        vlasnici=a.vlasnici;
        knjige=a.knjige;
        
    }
    
    
    
    
    
    
    
    void RegistrirajNovogKorisnika(int clanskibroj,std::string ime, std::string prezime,std::string adresa,std::string telefon)
    {
        if(vlasnici.count(clanskibroj))
        throw std::logic_error("Korisnik vec postoji");
        else
        {
            try
            {
                vlasnici[clanskibroj]=new Korisnik{ime,prezime,adresa,telefon};
            }
            catch(std::bad_alloc e)
            {
                std::cout<<"Problemi s memorijom!";
            }
        }
    }
    void RegistrirajNovuKnjigu(int brojknjige,std::string naslov,std::string ime,std::string zanr,int godina)
    {
        if(knjige.count(brojknjige))
        throw std::logic_error("Knjiga vec postoji");
        else
        {
            try
            {
                knjige[brojknjige]=new Knjiga(naslov,ime,zanr,godina);
            }
            catch(std::bad_alloc e)
            {
                std::cout<<"Problemi s memorijom!";
            }
        }
    }
    Korisnik &NadjiKorisnika (int broj)
    {
        if(!vlasnici.count(broj))
        throw std::logic_error("Korisnik nije nadjen");
        else
        return *vlasnici[broj];
    }
    Knjiga &NadjiKnjigu (int broj)
    {
        if(!knjige.count(broj))
        throw std::logic_error("Knjiga nije nadjena");
        else
        return *knjige[broj];
    }
    void IzlistajKorisnike () 
    {
        for(std::pair<int,Korisnik*> i:vlasnici)
        {
            std::cout<<"Clanski broj: "<<i.first<<std::endl;
            std::cout<<"Ime i prezime: "<<(*i.second).ime<<" "<<(*i.second).prezime<<std::endl;
            std::cout<<"Adresa: "<<(*i.second).adresa<<std::endl;
            std::cout<<"Broj telefona: "<<(*i.second).telefon<<std::endl<<std::endl;
        }
    }
    void IzlistajKnjige () 
    {
        for(std::pair<int,Knjiga*> i:knjige)
        {
            std::cout<<"Evidencijski broj: "<<i.first<<std::endl;
            std::cout<<"Naslov: "<<(*i.second).DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<(*i.second).DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<(*i.second).DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<(*i.second).DajGodinuIzdavanja()<<std::endl;
            if(((*i.second).DajKodKogaJe()))
            std::cout<<"Zaduzena kod korisnika: "<<(*((*i.second).DajKodKogaJe())).ime<<" "<<(*((*i.second).DajKodKogaJe())).prezime<<std::endl<<std::endl;
        }
    }    
    void ZaduziKnjigu(int evidencijski,int clanski)
    {
        if(!knjige.count(evidencijski))
        throw std::logic_error("Knjiga nije nadjena");
        if(!vlasnici.count(clanski))
        throw std::logic_error("Korisnik nije nadjen");
        if((*knjige[evidencijski]).DajKodKogaJe())
        throw std::logic_error("Knjiga vec zaduzena");
        (*(knjige[evidencijski])).ZaduziKnjigu(*vlasnici[clanski]);
    }
    void RazduziKnjigu(int evidencijski)
    {
        if(!knjige.count(evidencijski))
        throw std::logic_error("Knjiga nije nadjena");
        if(!((*knjige[evidencijski]).DajKodKogaJe()))
        throw std::logic_error("Knjiga nije zaduzena");
        (*(knjige[evidencijski])).RazduziKnjigu();
    }
    void PrikaziZaduzenja (int clanski)
    {
        if(!vlasnici.count(clanski))
        throw std::logic_error("Korisnik nije nadjen");
        {
        bool Zaduzio(false);
        for(std::pair<int,Knjiga*> i:knjige)
        {
            if((*i.second).DajKodKogaJe()==vlasnici[clanski])
            {
                Zaduzio=true;
                break;
            }
        }
        if(!Zaduzio)
        std::cout<<"Nema zaduzenja za tog korisnika!";
        }
        
        for(std::pair<int,Knjiga*> i:knjige)
        {
            if((*i.second).DajKodKogaJe()==vlasnici[clanski])
            {
                std::cout<<"Evidencijski broj: "<<i.first<<std::endl;
                std::cout<<"Naslov: "<<(*i.second).DajNaslov()<<std::endl;
                std::cout<<"Pisac: "<<(*i.second).DajAutora()<<std::endl;
                std::cout<<"Zanr: "<<(*i.second).DajZanr()<<std::endl;
                std::cout<<"Godina izdavanja: "<<(*i.second).DajGodinuIzdavanja()<<std::endl<<std::endl;
            }
        }
        
    }
    
    
    
  
};









int main ()
{
	
	Knjiga a("a","d","d",3);
	a.DaLiJeZaduzena();
	Korisnik b{"a","s","s","s"};
	a.ZaduziKnjigu(b);
	return 0;
}