#include <string>
#include <map>
#include <iostream>

struct Korisnik {
    std::string ime,prezime,adresa,telefon;
};

class Knjiga
{
    std::string naslov,autor,zanr;
    int godina_izdavanja;
    Korisnik * zaduzenje = nullptr;
public:
    Knjiga(std::string naslov,std::string autor,std::string zanr, int godina_izdavanja,Korisnik* p=nullptr):naslov(naslov),autor(autor),zanr(zanr),godina_izdavanja(godina_izdavanja),zaduzenje(p) {}
    ~Knjiga() {}
    std::string DajNaslov()const {
        return naslov;
    }
    std::string DajAutora()const{
        return autor;
    }
    std::string DajZanr()const {
        return zanr;
    }
    int DajGodinuIzdavanja()const{
        return godina_izdavanja;
    }
    Korisnik* DajKodKogaJe ()const {
        return zaduzenje;
    }
    void ZaduziKnjigu(Korisnik& korisnik) {
        zaduzenje=&korisnik;
    }
    void RazduziKnjigu() {
        zaduzenje=nullptr;
    }
    bool DaLiJeZaduzena()const {
        if(!zaduzenje) return false;
        return true;
    }

};

class Biblioteka
{
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
public:
    Biblioteka() {}
    Biblioteka(std::map<int, Korisnik*>k1, std::map<int, Knjiga*> k2):korisnici(k1),knjige(k2) {}
    ~Biblioteka() {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++) delete it->second;
        for(auto it=knjige.begin(); it!=knjige.end(); it++) delete it->second;
    }
    Biblioteka(Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    Biblioteka &operator=(const Biblioteka &b);
    Biblioteka &operator=(Biblioteka &&b);
    void RegistrirajNovogKorisnika(int broj, std::string imee, std::string prezimee, std::string adresaa, std::string broj_telefonaa);
    void RegistrirajNovuKnjigu(int broj,std::string nasloov, std::string ime_pisca, std::string zanrr , int godinaizdavanja);
    Korisnik &NadjiKorisnika(int broj);
    Knjiga &NadjiKnjigu(int broj);
    void IzlistajKorisnike();
    void IzlistajKnjige();
    void ZaduziKnjigu(int broj_knjige, int broj_korisnika);
    void PrikaziZaduzenja(int broj_korisnika);
};


Biblioteka::Biblioteka(Biblioteka &b)
{
    try {
        for (auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++)
            korisnici[it->first]=new Korisnik(*(it->second));
    } catch(std::bad_alloc) {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
            delete it->second;
            korisnici.erase(it->first);
            throw;
        }
    }
    try {
        for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++)
            knjige[it->first]=new Knjiga(*(it->second));
    } catch(std::bad_alloc) {
        for(auto it=knjige.begin(); it!=knjige.end(); it++) {
            delete it->second;
            korisnici.erase(it->first);
            throw;
        }
    }
}
Biblioteka:: Biblioteka(Biblioteka && b)
{
    std::swap(korisnici,b.korisnici);
    std::swap(knjige, b.knjige);
}


Biblioteka& Biblioteka ::operator=(const Biblioteka &b)
{
    std::map<int, Korisnik*>novi_korisnici;
    std::map<int, Knjiga*> nove_knjige;
    for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++)
        novi_korisnici[it->first]=new Korisnik(*(it->second));

    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        delete it->second;
        korisnici.erase(it->first);
    }
    for(auto it=novi_korisnici.begin(); it!=novi_korisnici.end(); it++)
        korisnici[it->first]=it->second;
    return *this;

}

Biblioteka& Biblioteka ::operator =(Biblioteka &&b)
{
    std::swap(korisnici, b.korisnici);
    std::swap(knjige,b.knjige);
    for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++) b.korisnici[it->first]=nullptr;
    for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++) b.knjige[it->first]=nullptr;
    return *this;
}

void Biblioteka:: RegistrirajNovogKorisnika(int broj, std::string imee, std::string prezimee,std::string adresaa, std::string broj_telefonaa)
{
    if(korisnici.count(broj)) throw std::logic_error("Korisnik vec postoji");
    else {
        Korisnik* novi=new Korisnik;
        novi->ime=imee;
        novi->prezime=prezimee;
        novi->adresa=adresaa;
        novi->telefon=broj_telefonaa;
        korisnici.insert(std::make_pair(broj,novi));

    }
}

void Biblioteka:: RegistrirajNovuKnjigu(int broj, std::string nasloov, std::string ime_pisca, std::string zanrr, int godinaizdavanja)
{
    if(knjige.count(broj)) throw std::logic_error("Knjiga vec postoji");
    else {
        Knjiga * nova=new Knjiga(nasloov,ime_pisca,zanrr,godinaizdavanja);
        knjige.insert(std::make_pair(broj,nova));
    }
}

Korisnik & Biblioteka::NadjiKorisnika(int broj)
{
    if(!korisnici.count(broj)) throw std::logic_error("Korisnik nije nadjen");
    return *(korisnici[broj]);

}

Knjiga & Biblioteka::NadjiKnjigu(int broj)
{
    if(!knjige.count(broj)) throw std::logic_error("Knjiga nije nadjena");
    return *(knjige[broj]);
}

void Biblioteka:: IzlistajKorisnike()
{
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        auto korisniik=korisnici[it->first];
        std::cout<<"Clanski broj: "<<it->first<<std::endl;
        std::cout<<"Ime i prezime: "<<korisniik->ime<<" "<<korisniik->prezime<<std::endl;
        std::cout<<"Adresa: "<<korisniik->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<korisniik->telefon<<std::endl<<std::endl;
    }
}

void Biblioteka::IzlistajKnjige()
{
    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
        auto book=knjige[it->first];
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<book->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<book->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<book->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<book->DajGodinuIzdavanja()<<std::endl<<std::endl;
        if (book->DaLiJeZaduzena()) {
            std::cout<<"Zaduzena kod korisnika: "<<book->DajKodKogaJe()->ime<<" "<<book->DajKodKogaJe()->prezime<<std::endl;

        }
    }
}

void Biblioteka::ZaduziKnjigu(int broj_knjige, int broj_korisnika)
{
    if(!knjige.count(broj_knjige)) throw std::logic_error("Knjiga nije nadjena");
    if(knjige[broj_knjige]->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    if(!korisnici.count(broj_korisnika)) throw std::logic_error("Korisnik nije nadjen");
    knjige[broj_knjige]->ZaduziKnjigu(*(korisnici[broj_korisnika]));
}

void Biblioteka:: PrikaziZaduzenja(int broj_korisnika)
{
    int brojac=0;
    if(!korisnici.count(broj_korisnika)) throw std::logic_error("Korisnik nije nadjen");
    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
        auto book=knjige[it->first];
        if (book->DajKodKogaJe()==korisnici[broj_korisnika]) {
            brojac++;
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<book->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<book->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<book->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<book->DajGodinuIzdavanja()<<std::endl<<std::endl;

        }
    }
    if(brojac==0) std::cout<<"Nema zaduzenja za tog korisnika"<<std::endl;


}







int main ()
{
    int in=0;
    Biblioteka bib;
    do {
        std::cout<<"Unesite zeljeni broj opcije: "<<std::endl;
        std::cout<<"1 - Registracija novog korisnika"<<std::endl;
        std::cout<<"2 - Registracija nove knjige"<<std::endl;
        std::cout<<"3 - Pretraga korisnika"<<std::endl;
        std::cout<<"4 - Pretraga knjiga"<<std::endl;
        std::cout<<"5 - Izlistavanje korisnika"<<std::endl;
        std::cout<<"6 - Izlistavanje knjiga"<<std::endl;
        std::cout<<"7 - Zaduzivanje knjige"<<std::endl;
        std::cout<<"8 - Prikaz zaduzenja"<<std::endl;
        std::cout<<"0 - IZLAZ"<<std::endl;
        std::cin>>in;
        if(in==1){
            int broj;
            std::string ime, prezime,adresa , brojtelefona;
            std::cout<<"Unesite broj korisnika: "<<std::endl;
            std::cin>>broj;
            std::cout<<"Unesite ime korisnika: "<<std::endl;
            std::cin>>ime;
            std::cout<<"Unesite prezime: "<<std::endl;
            std::cin>>prezime;
            std::cout<<"Unesite adresu: "<<std::endl;
            std::cin>>adresa;
            std::cout<<"Unesite broj telefona"<<std::endl;
            std::cin>>brojtelefona;
            bib.RegistrirajNovogKorisnika(broj,ime,prezime,adresa,brojtelefona);
        }
        else if(in==2){
            std::string naslov, ime_pisca, zanr;
            int godina_izdavanja,broj;
            std::cout<<"Unesite broj knjige: "<<std::endl;
            std::cin>>broj;
            std::cout<<"Unesite naslov knjige: "<<std::endl;
            std::cin>>naslov;
            std::cout<<"Unesite ime pisca: "<<std::endl;
            std::cin>>ime_pisca;
            std::cout<<"Unesite zanr: "<<std::endl;
            std::cin>>zanr;
            std::cout<<"Unesite godinu izdavanja knjige: "<<std::endl;
            std::cin>>godina_izdavanja;
            bib.RegistrirajNovuKnjigu(broj,naslov,ime_pisca,zanr,godina_izdavanja);
        }
        else if(in==3){
            int broj_korisnika;
            std::cout<<"Unesite broj korisnika: "<<std::endl;
            std::cin>>broj_korisnika;
           bib.NadjiKorisnika(broj_korisnika);
        }
        
        else if(in==4){
            int broj_knjige;
            std::cout<<"Unesite broj knjige: "<<std::endl;
            std::cin>>broj_knjige;
            bib.NadjiKnjigu(broj_knjige);
        }
        
        else if(in==5) bib.IzlistajKorisnike();
        
        else if(in==6) bib.IzlistajKnjige();
        
        else if(in==7){
            int broj_knjige, broj_korisnika;
            std::cout<<"Unesite broj knjige: "<<std::endl;
            std::cin>>broj_knjige;
            std::cout<<"Unesite broj korisnika: "<<std::endl;
            std::cin>>broj_korisnika;
            bib.ZaduziKnjigu(broj_knjige, broj_korisnika);
        }
        
        else if(in==8){
            int broj;
            std::cout<<"Unesite broj korisnika: "<<std::endl;
            std::cin>>broj;
            bib.PrikaziZaduzenja(broj);
        }
        
         }while(in!=0);
        
    return 0;

}