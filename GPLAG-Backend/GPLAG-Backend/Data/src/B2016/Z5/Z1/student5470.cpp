#include <string>
#include <map>
#include <new>
#include <stdexcept>
#include <iostream>
//zadatak je bio greskom napisan u t12/z6
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
    std::string DajNaslov() const{return nas;}
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
    std::map<int,Knjiga*> knjige;
    std::map<int,Korisnik*> kor;
public:
    Biblioteka()
    {
    }
    Biblioteka(const Biblioteka &b)
    {
        try
        {
            for(auto it=b.knjige.begin();it!=b.knjige.end();it++) 
            {
                knjige[it->first] = new Knjiga(it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja());
                knjige[it->first]->ZaduziKnjigu(*(it->second->DajKodKogaJe()));
            }
            for(auto it=b.kor.begin();it!=b.kor.end();it++) 
            {
                kor[it->first] = new Korisnik(*(it->second));
            }
        }
        catch(std::bad_alloc x)
        {
            for(auto it=knjige.begin();it!=knjige.end();it++) 
            {
                delete it->second;
            }
            for(auto it=kor.begin();it!=kor.end();it++) 
            {
                delete it->second;
            }
            throw x;
        }
    }
    Biblioteka(Biblioteka &&b)
    {
        try
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
        catch(std::bad_alloc x)
        {
            for(auto it=knjige.begin();it!=knjige.end();it++) 
            {
                delete it->second;
            }
            for(auto it=kor.begin();it!=kor.end();it++) 
            {
                delete it->second;
            }
            throw x;
        }
    }
    Biblioteka &operator= (const Biblioteka &b)
    {
        for(auto it=knjige.begin();it!=knjige.end();it++) delete it->second;
        for(auto it=kor.begin();it!=kor.end();it++) delete it->second;
        kor.clear();
        knjige.clear();
        try
        {
            for(auto it=b.knjige.begin();it!=b.knjige.end();it++) 
            {
                knjige[it->first] = new Knjiga(it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja());
                knjige[it->first]->ZaduziKnjigu(*(it->second->DajKodKogaJe()));
            }
            for(auto it=b.kor.begin();it!=b.kor.end();it++) 
            {
                kor[it->first] = new Korisnik(*(it->second));
            }
            return *this;
        }
        catch(std::bad_alloc x)
        {
            for(auto it=knjige.begin();it!=knjige.end();it++) 
            {
                delete it->second;
            }
            for(auto it=kor.begin();it!=kor.end();it++) 
            {
                delete it->second;
            }
            throw x;
        }
    }
    Biblioteka &operator =(Biblioteka &&b)
    {
        try
        {
            for(auto it=knjige.begin();it!=knjige.end();it++) delete it->second;
            for(auto it=kor.begin();it!=kor.end();it++) delete it->second;
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
        catch(std::bad_alloc x)
        {
            for(auto it=knjige.begin();it!=knjige.end();it++) 
            {
                delete it->second;
            }
            for(auto it=kor.begin();it!=kor.end();it++) 
            {
                delete it->second;
            }
            throw x;
        }
    }
    ~Biblioteka()
    {
        for(auto it=knjige.begin();it!=knjige.end();it++) delete it->second;
        for(auto it=kor.begin();it!=kor.end();it++) delete it->second;
    }
    void RegistrirajNovogKorisnika(int id,std::string i,std::string p,std::string a,std::string bt)
    {
        if(kor.count(id)) throw std::logic_error("Korisnik vec postoji");
        try
        {
            kor[id]=new Korisnik;
            kor[id]->ime=i;
            kor[id]->prezime=p;
            kor[id]->adresa=a;
            kor[id]->telefon=bt;
        }
        catch(std::bad_alloc x)
        {
            kor.erase(id);
            throw x;
        }
    }
    void RegistrirajNovuKnjigu(int id,std::string n,std::string p,std::string z,int g)
    {
        if(knjige.count(id)) throw std::logic_error("Knjiga vec postoji");
        try
        {
            knjige[id]=new Knjiga(n,p,z,g);
        }
        catch(std::bad_alloc x)
        {
            knjige.erase(id);
            throw x;
        }
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
            if(it->second->DajKodKogaJe()==kor[id])
            isp=false,std::cout << "Evidencijski broj: " << it->first << "\nNaslov: " << it->second->DajNaslov()  << "\nPisac: " << it->second->DajAutora() << "\nZanr: " << it->second->DajZanr() << "\nGodina izdavanja: " << it->second->DajGodinuIzdavanja() <<"\n";
        }
        if(isp) std::cout << "Nema zaduzenja za tog korisnika!";
    }
};
int main()
{
    Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
"Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
"Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
"Studenata etfovaca 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
Biblioteka b2(b);                                           
b2.PrikaziZaduzenja(4312);
    return 0;
}