#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
#include <string>
struct Korisnik {
    std::string ime, prezime, adresa,telefon;
};
class Knjiga
{
    std::string naslov;
    std::string ime_pisca;
    std::string zanr;
    int godina_izdavanja;
    Korisnik *pok=nullptr;
public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja):naslov(naslov),ime_pisca(ime_pisca),zanr(zanr),
        godina_izdavanja(godina_izdavanja) {
        pok=nullptr;
    }
    std::string DajNaslov() const {
        return naslov;
    };
    std::string DajZanr() const {
        return zanr;
    };
    std::string DajAutora() const {
        return ime_pisca;
    };
    int DajGodinuIzdavanja() const {
        return godina_izdavanja;
    };
    Korisnik* DajKodKogaJe() const {
        return pok;
    };
    void ZaduziKnjigu(Korisnik &k) {
        pok=&k;
    }
    void RazduziKnjigu() {
        pok=nullptr;
    }
    bool DaLiJeZaduzena() {
        if(pok==nullptr) return false;
        return true;
    }
};

class Biblioteka
{
    std::map<int,Korisnik*> mapa_korisnika;
    std::map<int,Knjiga*> mapa_knjiga;
public:
    ~Biblioteka() {
        for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
            if(it->second!=nullptr) {
                delete  it->second;
            }
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) {
            if(it->second!=nullptr) {
                delete it->second;
            }
        }
    }
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
        Korisnik *k= new Korisnik {ime,prezime,adresa,telefon};
        for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)  {
            if(it->first==clanski_broj) throw std::logic_error ("Korisnik vec postoji");
        }
        mapa_korisnika.insert(std::make_pair(clanski_broj,k));
    }
    void RegistrirajNovuKnjigu(int broj_knjige, std::string naslov, std::string ime_pisca,std::string zanr, int godina_izdavanja) {
        Knjiga *k=new Knjiga (naslov,ime_pisca,zanr,godina_izdavanja);
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)  {
            if(it->first==broj_knjige) throw std::logic_error ("Knjiga vec postoji");
        }
        mapa_knjiga.insert(std::make_pair(broj_knjige,k));
    }
    Korisnik& NadjiKorisnika(int clanski_broj) {
        for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) {
            if(clanski_broj==it->first) return *it->second;
        }
        throw std::logic_error ("Korisnik nije najen.");

    }
    Knjiga& NadjiKnjigu(int broj) {
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) {
            if(broj==it->first) return *(it->second);
        }
        throw std::logic_error ("Knjiga nije nadjena.");

    }
    void IzlistajKorisnike () {
        for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) {
            std::cout<<"Clanski broj: "<<it->first<<std::endl;
            std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
            std::cout<<"Adresa: "<<(it->second)->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
            std::cout<<std::endl;
        }
    }
    void IzlistajKnjige () {
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) {
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
            if(it->second->DaLiJeZaduzena()) std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<std::endl;
            std::cout<<std::endl;
        }
    }
    void ZaduziKnjigu(int broj_knjige, int broj_korisnika) {
        bool ima=false;
        auto it1=mapa_knjiga.begin();
        for( it1=mapa_knjiga.begin(); it1!=mapa_knjiga.end(); it1++) {

            if(it1->first==broj_knjige)  {
                ima=true;
                break;
            }

        }
        if(ima==false) throw std::logic_error ("Knjiga nije nadjena");
        bool ima1=false;
        auto it=mapa_korisnika.begin();
        for( it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) {

            if(it->first==broj_korisnika) {
                ima1=true;
                break;
            }

        }
        if(ima1==false) throw std::logic_error ("Korisnik nije nadjen");
        if(it1->second->DaLiJeZaduzena()==false) it1->second->ZaduziKnjigu(*(it->second));
        else throw std::logic_error("Knjiga je vec zaduzena");
        }
        void RazduziKnjigu(int broj_knjige) {
            bool ima=false;
        auto it1=mapa_knjiga.begin();
        for( it1=mapa_knjiga.begin(); it1!=mapa_knjiga.end(); it1++) {

            if(it1->first==broj_knjige)  {
                ima=true;
                break;
            }

        }
        if(ima==false) throw std::logic_error ("Knjiga nije nadjena");
        if(it1->second->DaLiJeZaduzena()==false) throw std::logic_error("Knjiga nije zaduzena");
         it1->second->RazduziKnjigu();
        }
        
};



int main ()
{
    Biblioteka bib5;
    bib5.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
    bib5.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
    std::cout << bib5.NadjiKnjigu(2).DajNaslov();

    return 0;
}