/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <vector>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;  
};

class Knjiga{
    std::string naslov_knjige;
    std::string ime_pisca;
    std::string zanr;
    int godina_izdavanja;
    Korisnik* zaduzio;
public:
    Knjiga(std::string naslov_knjige, std::string ime_pisca, std::string zanr, int godina_izdavanja):naslov_knjige(naslov_knjige), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), zaduzio(nullptr){}
    std::string DajNaslov() const{return naslov_knjige;}
    std::string DajAutora() const{return ime_pisca;}
    std::string DajZanr() const{return zanr;}
    int DajGodinuIzdavanja() const{return godina_izdavanja;}
    Korisnik* DajKodKogaJe(){return zaduzio;}
    bool DaLiJeZaduzena() const{return zaduzio!=nullptr;}
    void ZaduziKnjigu(Korisnik &korisnik){
        zaduzio=&korisnik;
    }
    void RazduziKnjigu(){zaduzio=nullptr;}
};

class Biblioteka{
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
public:
    Biblioteka(){}
    ~Biblioteka(){
        for(auto i=korisnici.begin();i!=korisnici.end();i++){
            delete i->second;
        }
        korisnici.clear();
        for(auto i=knjige.begin();i!=knjige.end();i++){
            delete i->second;
        }
        knjige.clear();
    }
    Biblioteka(const Biblioteka &b){
        try{
            for(auto &i:b.korisnici){
                korisnici[i.first]=new Korisnik;
                korisnici[i.first]->ime=i.second->ime;
                korisnici[i.first]->prezime=i.second->prezime;
                korisnici[i.first]->adresa=i.second->adresa;
                korisnici[i.first]->telefon=i.second->telefon;
            }
            for(auto &i:b.knjige){
                knjige[i.first]=new Knjiga(i.second->DajNaslov(), i.second->DajAutora(), i.second->DajZanr(), i.second->DajGodinuIzdavanja());
            }
        }
        catch(...){
            for(auto &i:korisnici){
                delete i.second;
            }
            korisnici.clear();
            for(auto &i:knjige){
                delete i.second;
            }
            knjige.clear();
            throw;
        }
    }
    Biblioteka(Biblioteka &b){
        std::swap(korisnici, b.korisnici);
        std::swap(knjige, b.knjige);
    }
    Biblioteka& operator =(const Biblioteka &b){
        Biblioteka temp;
        try{
            for(auto &i:b.korisnici){
                temp.korisnici[i.first]=new Korisnik;
                temp.korisnici[i.first]->ime=i.second->ime;
                temp.korisnici[i.first]->prezime=i.second->prezime;
                temp.korisnici[i.first]->adresa=i.second->adresa;
                temp.korisnici[i.first]->telefon=i.second->telefon;
            }
            for(auto &i:b.knjige){
                temp.knjige[i.first]=new Knjiga(i.second->DajNaslov(), i.second->DajAutora(), i.second->DajZanr(), i.second->DajGodinuIzdavanja());
            }
            korisnici=temp.korisnici;
            knjige=temp.knjige;
            return *this;
        }
        catch(...){
            for(auto &i:temp.korisnici){
                delete i.second;
            }
            temp.korisnici.clear();
            for(auto &i:temp.knjige){
                delete i.second;
            }
            temp.knjige.clear();
            throw;
        }
    }
    Biblioteka& operator =(Biblioteka &b){
        std::swap(knjige, b.knjige);
        std::swap(korisnici, b.korisnici);
        return *this;
    }
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona){
        if(korisnici.find(clanski_broj)!=korisnici.end())throw std::logic_error("Korisnik vec postoji");
        korisnici[clanski_broj]=new Korisnik;
        korisnici[clanski_broj]->ime=ime;
        korisnici[clanski_broj]->prezime=prezime;
        korisnici[clanski_broj]->adresa=adresa;
        korisnici[clanski_broj]->telefon=broj_telefona;
    }
    void RegistrirajNovuKnjigu(int broj_knjige, std::string naslov, std::string ime, std::string zanr, int godina){
        if(knjige.find(broj_knjige)!=knjige.end())throw std::logic_error("Knjiga vec postoji");
        knjige[broj_knjige]=new Knjiga(naslov, ime, zanr, godina);
    }
    Korisnik& NadjiKorisnika(int clanski_broj) const{
        if(korisnici.find(clanski_broj)==korisnici.end())throw std::logic_error("Korisnik nije nadjen");
        return *korisnici.at(clanski_broj);
    }
    Knjiga& NadjiKnjigu(int broj_knjige) const{
        if(knjige.find(broj_knjige)==knjige.end())throw std::logic_error("Knjiga nije nadjena");
        return *knjige.at(broj_knjige);
    }
    void IzlistajKorisnike() const{
        for(auto &i:korisnici){
            std::cout<<"Clanski broj: "<<i.first<<"\n";
            std::cout<<"Ime i prezime: "<<i.second->ime<<" "<<i.second->prezime<<"\n";
            std::cout<<"Adresa: "<<i.second->adresa<<"\n";
            std::cout<<"Broj telefona: "<<i.second->telefon<<"\n\n";
        }
    }
    void IzlistajKnjige() const{
        for(auto &i:knjige){
            std::cout<<"Evidencijski broj: "<<i.first<<"\n";
            std::cout<<"Naslov: "<<i.second->DajNaslov()<<"\n";
            std::cout<<"Pisac: "<<i.second->DajAutora()<<"\n";
            std::cout<<"Zanr: "<<i.second->DajZanr()<<"\n";
            std::cout<<"Godina izdavanja: "<<i.second->DajGodinuIzdavanja()<<"\n";
            if(i.second->DaLiJeZaduzena()){
                std::cout<<"Zaduzena kod korisnika: "<<i.second->DajKodKogaJe()->ime<<" "<<i.second->DajKodKogaJe()->prezime<<"\n";
            }
            std::cout<<"\n";
        }
    }
    void ZaduziKnjigu(int broj_knjige, int clanski_broj){
        if(knjige.find(broj_knjige)==knjige.end())throw std::logic_error("Knjiga nije nadjena");
        if(korisnici.find(clanski_broj)==korisnici.end())throw std::logic_error("Korisnik nije nadjen");
        if(knjige[broj_knjige]->DaLiJeZaduzena())throw std::logic_error("Knjiga vec zaduzena");
        knjige[broj_knjige]->ZaduziKnjigu(*korisnici[clanski_broj]);
    }
    void RazduziKnjigu(int broj_knjige){
        if(knjige.find(broj_knjige)==knjige.end())throw std::logic_error("Knjiga nije nadjena");
        if(!knjige[broj_knjige]->DaLiJeZaduzena())throw std::logic_error("Knjiga nije zaduzena");
        delete knjige[broj_knjige];
        knjige.erase(broj_knjige);
    }
    void PrikaziZaduzenja(int clanski_broj) const{
        if(korisnici.find(clanski_broj)==korisnici.end())throw std::logic_error("Korisnik nije nadjen");
        std::vector<std::pair<int, Knjiga>>v;
        for(auto &i:knjige){
            if(i.second->DajKodKogaJe()==korisnici.at(clanski_broj))v.push_back({i.first,*i.second});
        }
        if(v.size()==0)std::cout<<"Nema zaduzenja za tog korisnika!";
        for(auto i:v){
            std::cout<<"Evidencijski broj: "<<i.first<<"\n";
            std::cout<<"Naslov: "<<i.second.DajNaslov()<<"\n";
            std::cout<<"Pisac: "<<i.second.DajAutora()<<"\n";
            std::cout<<"Zanr: "<<i.second.DajZanr()<<"\n";
            std::cout<<"Godina izdavanja: "<<i.second.DajGodinuIzdavanja()<<"\n\n";
        }
    }
};

int main ()
{
    Biblioteka bib8;
    bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
    bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
    bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
    const Biblioteka b=bib8;
    b.NadjiKorisnika(1).ime="5";
    b.IzlistajKorisnike();
	return 0;
}