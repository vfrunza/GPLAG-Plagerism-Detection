/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <memory>

struct Korisnik {
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};
class Knjiga
{
private:
    std::string naslov;
    std::string pisac;
    std::string zanr;
    int godina_izdavanja;
    std::shared_ptr<Korisnik> p;
public:
    Knjiga(std::string naslov1, std::string pisac1,std::string zanr1, int godina) {
        naslov=naslov1;
        pisac=pisac1;
        zanr=zanr1;
        godina_izdavanja=godina;
       
    }
    Knjiga() {};
    ~Knjiga() {};
    std::string DajNaslov() const {
        return naslov;
    }
    std::string DajAutora() const {
        return pisac;
    }
    std::string DajZanr() const {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return godina_izdavanja;
    }
    void ZaduziKnjigu(Korisnik &user) {
        *p=user;
    }
    void *RazduziKnjigu()  {
        p=nullptr;
    }
    std::shared_ptr<Korisnik> DajKodKogaJe() {
        return p;
    }
    bool DaLiJeZaduzena() {
        if(p==nullptr) {
            return false;
        } else return true;
    }
};

class Biblioteka
{
    std::map<int, Korisnik*> user;
    std::map<int, Knjiga*> book;
public:
    void RegistrirajNovogKorisnika (int broj, std::string ime1, std::string prezime1, std::string adresa1, std::string telefon1);
    void RegistrirajNovuKnjigu (int ev_broj, std::string naslov1, std::string ime_pisca1, std::string zanr1, int godina_izdavanja1);
    Korisnik &NadjiKorisnika(int clanskibroj);
    Knjiga &NadjiKnjigu(int evbroj);
    void IzlistajKorisnike();
    void IzlistajKnjige();
    void ZaduziKnjigu(int evbroj,int clbroj);
    void RazduziKnjigu(int evbroj);
    void PrikaziZaduzenja(int clbroj);
    ~Biblioteka() {
        auto it=book.begin();
        auto it2=user.begin();
        while(it!=book.end()) {
            delete it->second;
            it->second=nullptr;
            it++;
        }
        while(it2!=user.end()) {
            delete it2->second;
            it2->second=nullptr;
            it2++;
        }
    }
};
void Biblioteka::RegistrirajNovogKorisnika (int broj, std::string ime1, std::string prezime1, std::string adresa1, std::string telefon1)
{
    for(auto it = user.begin(); it != user.end(); it++)
        if(it->first==broj) throw std::logic_error ("Korisnik vec postoji");
    try {
        Korisnik *a= new Korisnik;
        (*a).ime=ime1;
        (*a).prezime=prezime1;
        (*a).adresa=adresa1;
        (*a).telefon=telefon1;
        user.insert(std::make_pair(broj,a));
    } catch(...) {
        std::cout<<"Greska";
    }
}
void Biblioteka::RegistrirajNovuKnjigu (int ev_broj, std::string naslov1, std::string ime_pisca1, std::string zanr1, int godina_izdavanja1)
{
    for(auto it = book.begin(); it != book.end(); it++)
        if((*it).first==ev_broj) throw std::logic_error ("Knjiga vec postoji");
    Knjiga *buch=new Knjiga(naslov1,ime_pisca1,zanr1,godina_izdavanja1);
    book.insert(std::make_pair(ev_broj,buch));
}
static Korisnik a;
Korisnik &Biblioteka::NadjiKorisnika(int clanskibroj)
{
    for(auto it = user.begin(); it != user.end(); it++)
        if((*it).first==clanskibroj)  {
            try {

                a.ime=(*it).second->ime;
                a.prezime=(*it).second->prezime;
                a.adresa=(*it).second->adresa;
                a.telefon=(*it).second->telefon;
                return a;
            } catch(...) {
                std::cout<<"Greska";
            }
        } else
            throw std::logic_error ("Korisnik nije nadjen");
}
static Knjiga b;
Knjiga &Biblioteka::NadjiKnjigu(int evbroj)
{
    for(auto it = book.begin(); it != book.end(); it++)
        if((*it).first==evbroj) {
            b=Knjiga((*it).second->DajNaslov(),(*it).second->DajAutora(),(*it).second->DajZanr(),(*it).second->DajGodinuIzdavanja());
            return b;
        } else
            throw std::logic_error ("Knjiga nije nadjena");
}
void Biblioteka::ZaduziKnjigu(int evbroj,int clbroj)
{
    auto it=book.begin();
    bool zaduzena=false;
    while(it!=book.end()) {
        if(evbroj==(*it).first && (*it).second->DaLiJeZaduzena())
            throw std::logic_error("Knjiga zaduzena");
        if(evbroj==(*it).first) {
            zaduzena=true;
            break;
        }
        it++;
    }
    if(zaduzena==false)
        throw std::logic_error("Knjiga nije nadjena");

    auto it1=user.begin();
    zaduzena=false;
    while(it1!=user.end()) {
        if(clbroj==(*it1).first) {
            zaduzena=true;
            break;
        }
        it1++;
    }
    if(zaduzena==false)
        throw std::logic_error("Korisnik nije nadjen");
    (*it).second->ZaduziKnjigu(*((*it1).second));
}
/*for(auto it=book.begin(); it!=book.end(); it++) {
    if((*it).first==evbroj){
        for(auto it=user.begin(); it!=user.end(); it++) {
    if((*it).first==clbroj) {
       auto q=Knjiga::DajKodKogaJe();
       Knjiga::ZaduziKnjigu(q);
        std::cout<<"Zaduzena kod korisnika: "<<(*it).second->ime<<" "<<(*it).second->prezime;
    } else
        throw std::logic_error("Korisnik nije nadjen");
}
    }
    else
        throw std::logic_error("Knjiga nije nadjena");
}*/

void Biblioteka::IzlistajKorisnike()
{
    for(auto it = user.begin(); it != user.end(); it++) {
        std::cout<<"Clanski broj: "<< (*it).first<<std::endl;
        std::cout<<"Ime i prezime: "<<(*it).second->ime<<" ";
        std::cout<<(*it).second->prezime<<std::endl;
        std::cout<<"Adresa: "<<(*it).second->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<(*it).second->telefon<<std::endl;
        std::cout<<std::endl;
    }
}
void Biblioteka::IzlistajKnjige()
{
    for(auto it = book.begin(); it != book.end(); it++) {
        std::cout<<"Evidencijski broj: "<< (*it).first<<std::endl;
        std::cout<<"Naslov: "<<(*it).second->DajNaslov()<<" "<<std::endl;
        std::cout<<"Pisac: "<<(*it).second->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<(*it).second->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<(*it).second->DajGodinuIzdavanja()<<std::endl;
        Biblioteka::PrikaziZaduzenja((*it).first);
        std::cout<<std::endl;
    }
}
void Biblioteka::PrikaziZaduzenja(int clbroj)
{
    auto it1=user.begin();
    while(it1!=user.end()) {
        if(clbroj==(*it1).first) {
            std::cout<<"Knjiga je zaduzena od korisnika "<<(*it1).second->ime<<" "<<(*it1).second->prezime;
        }
        it1++;
    }
}
void Biblioteka::RazduziKnjigu(int evbroj)
{
    bool zaduzena=false;
    auto it=book.begin();

    while(it!=book.end()) {
        if(evbroj==(*it).first && (*it).second->DaLiJeZaduzena()==false)
            throw std::logic_error("Knjiga zaduzena");
        if(evbroj==(*it).first) {
            zaduzena=true;
            break;
        }
        it++;
    }
    if(zaduzena==false)
        throw std::logic_error("Knjiga nije nadjena");
}

int main ()
{
    Biblioteka bib8;
    bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
    bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
    bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
    bib8.ZaduziKnjigu(2, 1);
    bib8.IzlistajKnjige();
    return 0;
}