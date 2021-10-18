#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <memory>
#include <stdexcept>
#include <algorithm>

struct Korisnik
{
    std::string ime,prezime,adresa,telefon;
};

class Knjiga
{
    std::string naslov,autor,genre;
    int god_izd;
    Korisnik * zaduzio;
    public:
    
    Knjiga (std::string naslov, std::string autor, std::string genre, int god):
    naslov(naslov),autor(autor),genre(genre),god_izd(god),zaduzio(nullptr)
    {
        
    }
    
    std::string DajNaslov () const { return naslov; }
    std::string DajAutora () const { return autor;  }
    std::string DajZanr   () const { return genre;  }
    int DajGodinuIzdavanja() const { return god_izd;}
    
    Korisnik * DajKodKogaJe () const { return zaduzio; }
    
    void ZaduziKnjigu (Korisnik & korisinik)
    {
        zaduzio=&(korisinik);
    }
    
    void RazduziKnjigu ()
    {
        zaduzio=nullptr;
    }
    
    bool DaLiJeZaduzena () const
    {
        if (zaduzio==0)
        {
            return 0;
        }
        return 1;
    }
};

class Biblioteka
{
    std::map<int,Korisnik*> mapa_korisnika;
    std::map<int,Knjiga*>   mapa_knjiga;
    
    public:
    
    Biblioteka ()
    {
      
    }

    Biblioteka(const Biblioteka & blb)
    {
        for (auto it=blb.mapa_korisnika.begin();it!=blb.mapa_korisnika.end();it++)
        {
            mapa_korisnika.insert (std::make_pair (it->first,new Korisnik));
            mapa_korisnika[it->first]=it->second;
        }
        for (auto it=blb.mapa_knjiga.begin();it!=blb.mapa_knjiga.end();it++)
        {
            mapa_knjiga.insert (std::make_pair (it->first, new Knjiga("naslov","autor","zanr",0)));
            mapa_knjiga[it->first]=it->second;
        }
    } 
    
    
    Biblioteka (const Biblioteka && blb )
    {
        for (auto it=blb.mapa_korisnika.begin();it!=blb.mapa_korisnika.end();it++)
        {
            mapa_korisnika.insert (std::make_pair (it->first,it->second));
        }
        for (auto it=blb.mapa_knjiga.begin();it!=blb.mapa_knjiga.end();it++)
        {
            mapa_knjiga.insert (std::make_pair (it->first, it->second));
        }
    }
    
    
    
    //operator dodjele
    //kopirajuci operator dodjele
    
    
    void RegistrirajNovogKorisnika (int cl_br, std::string i, std::string p, std::string adr, std::string br)
    {
        if (  mapa_korisnika.count(cl_br)    )
        {
            throw std::logic_error ("Korisnik vec postoji");
        }
        Korisnik * kor (new Korisnik);
        kor->ime=i;
        kor->prezime=p;
        kor->adresa=adr;
        kor->telefon=br;
        mapa_korisnika.insert(std::make_pair(cl_br,kor));
    }
    
    
    void RegistrirajNovuKnjigu (int br_knj, std::string n, std::string a, std::string g, int gi)
    {
        if (mapa_knjiga.count(br_knj))
        {
            throw std::logic_error ("Knjiga vec postoji");
        }
        Knjiga * book (new Knjiga (n,a,g,gi));
        mapa_knjiga.insert (std::make_pair(br_knj,book));
    }
    
    Korisnik & NadjiKorisnika (int cl_br)
    {
        auto it (mapa_korisnika.find (cl_br));
        if (it==mapa_korisnika.end())
        {
            throw std::logic_error ("Korisnik nije nadjen");
        }
        return *(it->second);
    }
    
    Knjiga & NadjiKnjigu (int br)
    {
        auto it (mapa_knjiga.find(br));
        if (it == mapa_knjiga.end())
        {
            throw std::logic_error ("Knjiga nije nadjena");
        }
        return *(it->second);
    }
    
    
    void IzlistajKorisnike () const
    {
        for (auto it=mapa_korisnika.begin();it!=mapa_korisnika.end();it++)
        {
            std::cout << "\n\nClanski broj: "<<it->first;
            std::cout << "\nIme i prezime: "<<it->second->ime<<" "<<it->second->prezime;
            std::cout << "\nAdresa: "<<it->second->adresa;
            std::cout << "\nBroj telefona: "<< it->second->telefon;
        }
    }
    
    void IzlistajKnjige () const
    {
        for (auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++)
        {
            std::cout << "\n\nEvidencijski broj: "<<it->first;
            std::cout << "\nNaslov: "<<it->second->DajNaslov();
            std::cout << "\nPisac: "<<it->second->DajAutora();
            std::cout << "\nZanr: "<<it->second->DajZanr();
            std::cout << "\nGodina izdavanja: "<<it->second->DajGodinuIzdavanja();
            
            
            if (it->second->DaLiJeZaduzena())
            {
                Korisnik * kor (it->second->DajKodKogaJe());
                std::cout << "\nZaduzena kod korisinika: "<<kor->ime;
            }
        }
    }
    
    void ZaduziKnjigu (int br_knj, int cl_br)
    {
        if (!mapa_knjiga.count(br_knj))
        {
            throw std::logic_error ("Knjiga nije nadjena");
        }
        
        auto it (mapa_knjiga.find(br_knj));
        if (it!=mapa_knjiga.end() && it->second->DaLiJeZaduzena())
        {
            throw std::logic_error ("Knjiga vec zaduzena");
        }
        
        if (!mapa_korisnika.count (cl_br))
        {
            throw std::logic_error ("Korisnik nije nadjen");
        }
        
        auto it1 (mapa_korisnika.find(cl_br));

        Korisnik kor;
        kor.ime=it1->second->ime;
        kor.prezime=it1->second->prezime;
        kor.adresa=it1->second->adresa;
        kor.telefon=it1->second->telefon;
        
        it->second->Knjiga::ZaduziKnjigu(kor);
    }
    
    ~Biblioteka()
    {
        for (auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++)
        {
            delete (it->second);
        }
        for (auto it=mapa_korisnika.begin();it!=mapa_korisnika.end();it++)
        {
            delete (it->second);
        }
    }
    
    
};

int main ()
{
    return 0;
}