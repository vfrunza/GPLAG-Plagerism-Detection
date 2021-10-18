/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>

struct Korisnik
{
    std::string ime, prezime, adresa, telefon;
    //Korisnik(std::string ime, std::string prezime, std::string adresa, std::string br): ime(ime), prezime(prezime), adresa(adresa), telefon(br){}
};

class Knjiga
{
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *korisnik;
public:
    Knjiga(std::string naslov, std::string autor, std::string zanr, int godina): naslov(naslov), ime_pisca(autor), zanr(zanr),godina_izdavanja(godina),korisnik(nullptr){}
    ~Knjiga() {delete korisnik;}
    std::string DajNaslov() const { return naslov;}
    std::string DajAutora() const { return ime_pisca;}
    std::string DajZanr() const { return zanr;}
    int DajGodinuIzdavanja() const { return godina_izdavanja;}
    Korisnik *DajKodKogaJe() const { return korisnik;}
    void ZaduziKnjigu(Korisnik &k)
    {
        korisnik= new Korisnik{k.ime, k.prezime, k.adresa, k.telefon};
    }
    void RazduziKnjigu() { delete korisnik; korisnik=nullptr;}
    bool DaLiJeZaduzena() 
    { 
        if(korisnik!=nullptr) return true;
        return false;
    }
};

class Biblioteka
{
    std::map<int, Korisnik*> korisnik;
    std::map<int, Knjiga*> knjiga;
public:
    friend class Knjiga;
    Biblioteka(){};
    Biblioteka(const Biblioteka &b)
    {
        Korisnik *p;
        Knjiga *q;
        for(auto it=b.knjiga.begin();it!=b.knjiga.end();it++)
        {
           q=new Knjiga(it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja());
          knjiga[it->first]=q;
        }
         
        for(auto j=b.korisnik.begin();j!=b.korisnik.end();j++)
        {
                p= new Korisnik{j->second->ime, j->second->prezime,j->second->adresa,j->second->telefon};
               
               korisnik[j->first]=p;
        }
    }
    Biblioteka operator =(const Biblioteka &b)
    {
       for(auto it=b.knjiga.begin();it!=b.knjiga.end();it++)
           knjiga[it->first]=new Knjiga(it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja());
        for(auto j=b.korisnik.begin();j!=b.korisnik.end();j++)
                korisnik[j->first] = new Korisnik{j->second->ime, j->second->prezime,j->second->adresa,j->second->telefon};
                return *this;
    }
          Biblioteka(const Biblioteka &&b)
	{
		for (auto i = knjiga.begin(); i != knjiga.end();i++)
		for (auto it = b.knjiga.begin();it != b.knjiga.end();it++)
		{
			knjiga[i->first] = it->second;
		}
		for (auto j = korisnik.begin(); j != korisnik.end();j++)
		for (auto k= b.korisnik.begin();k != b.korisnik.end();k++)
		{
			korisnik[j->first] = k->second;
		}
	}
    
    ~Biblioteka()
    {
        for(auto it=korisnik.begin();it!=korisnik.end();it++)
            delete it->second;
        for(auto it=knjiga.begin();it!=knjiga.end();it++)
            delete it->second;
    }
    void RegistrirajNovogKorisnika(int clanski, std::string ime, std::string prezime, std::string adresa, std::string br)
    {
        Korisnik *p=new Korisnik{ime, prezime, adresa, br}; //dodati u try
        auto it(korisnik.find(clanski));
        if(it!=korisnik.end()) throw std::logic_error("Korisnik vec postoji");
        
            korisnik[clanski]=p;
    }
    void RegistrirajNovuKnjigu(int evidencija, std::string naslov, std::string autor, std::string zanr, int god)
    {
        Knjiga *p= new Knjiga(naslov, autor, zanr, god);
        auto it(knjiga.find(evidencija));
        if(it!=knjiga.end()) throw std::logic_error("Knjiga vec postoji");
        
            knjiga[evidencija]=p;
    }
    
    Korisnik &NadjiKorisnika(int clanski)
    {
        auto it(korisnik.find(clanski));
        if(it==korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
        
            return *(it->second);
    }
    Knjiga &NadjiKnjigu(int evidencija)
    {
        auto it(knjiga.find(evidencija));
        if(it==knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
        return *(it->second);
    }
    void IzlistajKorisnike() const 
    {
        for(auto it=korisnik.begin(); it!=korisnik.end();it++)
        {
            std::cout << "Clanski broj: "<<it->first << std::endl;
            std::cout << "Ime i prezime: "<<it->second->ime <<" "<<it->second->prezime<< std::endl;
            std::cout << "Adresa: "<<it->second->adresa << std::endl;
            std::cout << "Broj telefona: "<<it->second->telefon << std::endl;
            std::cout  << std::endl;
        }
        
    }
    void IzlistajKnjige() const
    {
        for(auto  it=knjiga.begin(); it!=knjiga.end();it++)
        {
            std::cout << "Evidencijski broj: "<<it->first << std::endl;
            std::cout << "Naslov: "<<it->second->DajNaslov() << std::endl;
            std::cout << "Pisac: " <<it->second->DajAutora()<< std::endl;
            std::cout << "Zanr: " <<it->second->DajZanr()<< std::endl;
            std::cout << "Godina izdavanja: "<<it->second->DajGodinuIzdavanja() << std::endl;
            if(it->second->DaLiJeZaduzena()==1)
                std::cout << "Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime <<" "<< it->second->DajKodKogaJe()->prezime<<std::endl;
            std::cout << std::endl;
        }
        
    }
    void ZaduziKnjigu(int evidencija, int clanski)
    {
        auto i(NadjiKnjigu(evidencija));
        auto j(NadjiKorisnika(clanski));
        auto it(knjiga.find(evidencija));
        if(it->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
        else
            it->second->ZaduziKnjigu(j);

    }
    void RazduziKnjigu(int evidencija)
    {
        auto i(NadjiKnjigu(evidencija));
        auto it(knjiga.find(evidencija));
        if(!it->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
        else
            it->second->RazduziKnjigu();
    }
    void PrikaziZaduzenja(int clanski) const;
};



void Biblioteka::PrikaziZaduzenja(int clanski) const
{
    auto a(korisnik.find(clanski));
    if(a==korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
    else
    {
        for(auto it=korisnik.begin();it!=korisnik.end();it++)
        {
            for(auto i=knjiga.begin(); i!=knjiga.end();i++)
            {
                if(i->second->DaLiJeZaduzena())
                {
                    if((it->second->ime== i->second->DajKodKogaJe()->ime) && (it->second->prezime== i->second->DajKodKogaJe()->prezime))
                    {
                        std::cout << "Evidencijski broj: "<<i->first << std::endl;
                        std::cout << "Naslov: "<<i->second->DajNaslov() << std::endl;
                        std::cout << "Pisac: " <<i->second->DajAutora()<< std::endl;
                        std::cout << "Zanr: " <<i->second->DajZanr()<< std::endl;
                         std::cout << "Godina izdavanja: "<<i->second->DajGodinuIzdavanja() << std::endl;
                    }
                }
                else
                {
                    throw std::logic_error("Nema zaduzenja za tog korisnika!");
                }
            }
        }
    }
}



int main ()
{
  Biblioteka b;
	b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic","Zmaja od Bosne 30", "032/444-555");
	b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
	b.IzlistajKnjige();
	Biblioteka bib8;
    bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
    bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
    bib8.IzlistajKnjige();
    b=bib8;
    b.IzlistajKnjige();

	return 0;
}
