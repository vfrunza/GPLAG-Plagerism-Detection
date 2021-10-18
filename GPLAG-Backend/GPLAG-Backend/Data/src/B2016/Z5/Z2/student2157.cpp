/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <string>
#include <iostream>
#include <map>
#include <exception>
#include <algorithm>
#include <new>
#include <memory>
struct Korisnik{
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
    void Ispisi()const;
};
void Korisnik::Ispisi()const{
        std::cout<<"Ime i prezime: "<<ime<<" "<<prezime<<"\n";
        std::cout<<"Adresa: "<<adresa<<"\n";
        std::cout<<"Broj telefona: "<<telefon<<"\n";
    }
class Knjiga{
    std::string naslov_knjige;
    std::string ime_pisca;
    std::string zanr;
    int godina_izdavanja;
    Korisnik *zaduzena;
    public:
    Knjiga(std::string naslov,std::string pisac,std::string zanr,int godina);
    std::string DajNaslov()const{return naslov_knjige;}
    std::string DajAutora()const{return ime_pisca;}
    std::string DajZanr()const{return zanr;}
    int DajGodinuIzdavanja()const{return godina_izdavanja;}
    Korisnik *DajKodKogaJe()const{return zaduzena;}
    void ZaduziKnjigu(Korisnik &k){if(zaduzena!=nullptr)throw std::logic_error("Knjiga vec zaduzena");
        else {zaduzena=&k;}}
    void RazduziKnjigu(){if(zaduzena==nullptr)throw std::logic_error("Knjiga nije zaduzena");
        else{zaduzena=nullptr;}}
    bool DaLiJeZaduzena(){if(zaduzena==nullptr)return false; return true;}
    void Ispisi()const;
};
void Knjiga::Ispisi()const{
        std::cout<<"Naslov: "<<naslov_knjige<<"\n";
        std::cout<<"Pisac: "<<ime_pisca<<"\n";
        std::cout<<"Zanr: "<<zanr<<"\n";
        std::cout<<"Godina izdavanja: "<<godina_izdavanja<<"\n";
        if(zaduzena!=nullptr){
            std::cout<<"Zaduzena kod korisnika: "<<zaduzena->ime<<" "<<
            zaduzena->prezime<<"\n";
        }
        
 }
Knjiga::Knjiga(std::string naslov,std::string pisac,std::string zanrr,int godina){
    naslov_knjige=naslov;
    ime_pisca=pisac;
    zanr=zanrr;
    godina_izdavanja=godina;
    zaduzena=nullptr;
}
class Biblioteka{
    std::map<int,std::shared_ptr<Korisnik>> korisnik;
    std::map<int,std::shared_ptr<Knjiga>> knjiga;
    public:
    Biblioteka(){};
    void RegistrirajNovogKorisnika( int clbr,std::string ime,std::string prezime
    ,std::string adresa, std::string br_tel);
    void RegistrirajNovuKnjigu(const int evbr,std::string naslov,std::string ime,
    std::string zanr,int godina);
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&bibl);
    Biblioteka &operator=(const Biblioteka &b);
    Biblioteka &operator=(Biblioteka &&b);
    Korisnik &NadjiKorisnika(int clbr);
    Knjiga &NadjiKnjigu(int evbr);
    void IzlistajKorisnike()const;
    void IzlistajKnjige()const;
    void ZaduziKnjigu(int evbr,int clbr);
    void RazduziKnjigu(int evbr);
    void PrikaziZaduzenja(int clbr);
    friend bool UporediKorisnika(Korisnik k1,Korisnik k2);
};
Biblioteka::Biblioteka(const Biblioteka &bibl){
    for(auto b =bibl.korisnik.begin(); b != bibl.korisnik.end(); b++){
        auto p=std::shared_ptr<Korisnik>(new Korisnik);
        p->ime=b->second->ime;p->prezime=b->second->prezime;p->adresa=b->second->adresa;
        p->telefon=b->second->telefon;
        korisnik.insert(std::make_pair(b->first,p));
    }
    for(auto b =bibl.knjiga.begin(); b != bibl.knjiga.end(); b++){
        auto p=std::shared_ptr<Knjiga>(new Knjiga(b->second->DajNaslov(),b->second->DajAutora()
        ,b->second->DajZanr(),b->second->DajGodinuIzdavanja()));
        knjiga.insert(std::make_pair(b->first,p));
    }
}
Biblioteka::Biblioteka(Biblioteka &&bibl){
    std::swap(korisnik,bibl.korisnik);
    std::swap(knjiga,bibl.knjiga);
}
Biblioteka &Biblioteka::operator=(const Biblioteka &bibl){
    delete this;
    for(auto b =bibl.korisnik.begin(); b != bibl.korisnik.end(); b++){
        auto p=std::shared_ptr<Korisnik>(new Korisnik);
        p->ime=b->second->ime;p->prezime=b->second->prezime;p->adresa=b->second->adresa;
        p->telefon=b->second->telefon;
        korisnik.insert(std::make_pair(b->first,p));
    }
    for(auto b =bibl.knjiga.begin(); b != bibl.knjiga.end(); b++){
    auto p=std::shared_ptr<Knjiga>(new Knjiga(b->second->DajNaslov(),b->second->DajAutora()
        ,b->second->DajZanr(),b->second->DajGodinuIzdavanja()));
        knjiga.insert(std::make_pair(b->first,p));
    }
    return *this;
}
Biblioteka &Biblioteka::operator =(Biblioteka &&bibl){
    delete this;
        for(auto b =bibl.korisnik.begin(); b != bibl.korisnik.end(); b++){
        auto p=std::shared_ptr<Korisnik> (new Korisnik);
        p->ime=b->second->ime;p->prezime=b->second->prezime;p->adresa=b->second->adresa;
        p->telefon=b->second->telefon;
        korisnik.insert(std::make_pair(b->first,p));
    }
    for(auto b =bibl.knjiga.begin(); b != bibl.knjiga.end(); b++){
        auto p=std::shared_ptr<Knjiga>(new Knjiga(b->second->DajNaslov(),b->second->DajAutora()
        ,b->second->DajZanr(),b->second->DajGodinuIzdavanja()));
        knjiga.insert(std::make_pair(b->first,p));
    }
    return *this;
}
void Biblioteka::RegistrirajNovogKorisnika(int clbr,std::string ime
,std::string prezime,std::string adresa,std::string br_tel){
    bool sluc=false;
    std::for_each(korisnik.begin(),korisnik.end(),[clbr,&sluc](std::pair<int,std::shared_ptr<Korisnik>> k){
        if(k.first==clbr)sluc=true;
    });
    if(sluc==true)throw std::logic_error("Korisnik vec postoji");
    auto pok=std::shared_ptr<Korisnik>(new Korisnik);
    pok->ime=ime;pok->prezime=prezime;pok->adresa=adresa;pok->telefon=br_tel;
    korisnik.insert(std::make_pair(clbr,pok));
}
void Biblioteka::RegistrirajNovuKnjigu(const int evbr,std::string naslov,std::string ime,
    std::string zanr,int godina){
        bool sluc=false;
            std::for_each(knjiga.begin(),knjiga.end(),[evbr,&sluc](std::pair<int,std::shared_ptr<Knjiga>> k){
        if(k.first==evbr)sluc=true;
        });
        if(sluc==true)throw std::logic_error("Knjiga vec postoji");
        auto pok=std::shared_ptr<Knjiga>(new Knjiga(naslov,ime,zanr,godina));
        knjiga.insert(std::make_pair(evbr,pok));
    }
Korisnik &Biblioteka::NadjiKorisnika(const int clbr){
    auto p=korisnik.find(clbr);
    if(p==korisnik.end() && clbr!=(*korisnik.end()).first){
        throw std::logic_error ("Korisnik nije nadjen");
    }
    return *((*p).second);
}
Knjiga &Biblioteka::NadjiKnjigu(const int evbr){
    auto p=knjiga.find(evbr);
    if(p==knjiga.end() && evbr!=p->first){
        throw std::logic_error ("Knjiga nije nadjena");
    }
    return *(*p).second;
}
void Biblioteka::IzlistajKorisnike()const{
    for(auto const &i:korisnik){
        std::cout<<"Clanski broj: "<<i.first<<"\n";
        i.second->Ispisi();std::cout<<"\n";}
}
void Biblioteka::IzlistajKnjige()const{
    for(auto const &i:knjiga){
    std::cout<<"Evidencijski broj: "<<i.first<<"\n";
    i.second->Ispisi();std::cout<<"\n";}
}
void Biblioteka::ZaduziKnjigu(int evbr,int clbr){
    try{
        NadjiKnjigu(evbr).ZaduziKnjigu(NadjiKorisnika(clbr));
    }
    catch(std::logic_error x){throw x;}
}
void Biblioteka::RazduziKnjigu(int evbr){
    try{
        NadjiKnjigu(evbr).RazduziKnjigu();
    }
    catch(std::logic_error x){throw x;}
}
bool UporediKorisnika(Korisnik k1,Korisnik k2){
    if(k1.ime==k2.ime && k1.prezime==k2.prezime
    && k1.adresa==k2.adresa && k1.telefon==k2.telefon)return true;
    return false;
}
void Biblioteka::PrikaziZaduzenja(int clbr){
    bool sluc=false;
    try{
    auto p=NadjiKorisnika(clbr);
    std::for_each(knjiga.begin(),knjiga.end(),[clbr,&sluc,p](std::pair<int,std::shared_ptr<Knjiga>> k){
        if(k.second->DajKodKogaJe()==nullptr);
        else if(UporediKorisnika(p,*k.second->DajKodKogaJe())==true){
            sluc=true;
            std::cout<<"Clanski broj: "<<k.first<<"\n";
            k.second->Ispisi();std::cout<<"\n";}
    });}
    catch(std::logic_error x){throw std::domain_error ("Korisnik nije nadjen");}
    if(sluc==false)std::cout<<"Nema zaduzenja za tog korisnika!\n"; 
}
int main ()
{
    Biblioteka Cazin;
    for(;;){
        std::cout<<"Izaberite opciju: \n";
        std::cout<<" 0 - Kraj\n";
        std::cout<<" 1 - Uredjivanje knjiga\n";
        std::cout<<" 2 - Uredjivanje korisnika\n";
        int glavni;
        std::cin>>glavni;
        if(glavni==1){
            for(;;){
             std::cout<<"Izaberite opciju: \n";
             std::cout<<" 0 - Nazad\n";
             std::cout<<" 1 - Dodavanje nove knjige\n";
             std::cout<<" 2 - Zaduzi knjigu\n";
             std::cout<<" 3 - Razduzi knjigu\n";
             std::cout<<" 4 - Izlistaj knjige\n";
             std::cout<<" 5 - Kraj\n";
             int int_knjig;
             std::cin>>int_knjig;
             if(int_knjig==1){
                 for(;;){
                     int evbr,god;
                     std::cout<<"Unesi evidencijski broj knjige: ";
                     std::cin>>evbr;
                     std::cin.ignore(1000,'\n');
                     std::cout<<"Unesite naslov knjige: ";
                     std::string naziv,ime,zanr;
                     std::getline(std::cin,ime,'\n');
                     std::cout<<"Unesite ime pisca: ";
                     std::getline(std::cin,ime,'\n');
                     std::cout<<"Unesite zanr: ";
                     std::getline(std::cin,ime,'\n');
                     std::cout<<"Unesi godinu izdavanja: ";
                     std::cin>>god;
                     try{
                         Cazin.RegistrirajNovuKnjigu(evbr,naziv,ime,zanr,god);
                     }
                     catch(std::logic_error x){
                         std::cout<<"Izuzetak: "<<x.what();
                         continue;
                     }
                     break;
                 }
             }
             if(int_knjig==2){
                 for(;;){
                int evbr,clbr;
                std::cout<<"Unesite evidencijski broj knjige: ";
                std::cin>>evbr;
                std::cout<<"Unesite clanski broj korisnika: ";
                std::cin>>clbr;
                try{Cazin.ZaduziKnjigu(evbr,clbr);}
                catch(std::logic_error x){
                         std::cout<<"Izuzetak: "<<x.what();
                         continue;
                     }
                break;}
             }
             if(int_knjig==3){
                 for(;;){
                 int evbr;
                 std::cout<<"Unesite evidencijski broj knjige: ";
                 std::cin>>evbr;
                try{Cazin.RazduziKnjigu(evbr);}
                catch(std::logic_error x){
                         std::cout<<"Izuzetak: "<<x.what();
                         continue;
                     }
                break;
             }
             if(int_knjig==4){
                 Cazin.IzlistajKnjige();
             }
             if(int_knjig==0)break;
             if(int_knjig==5)return 0;
            }
        }
            }
        if(glavni==2){
            for(;;){
                std::cout<<"Izaberite opciju: \n";
                std::cout<<" 0 - Nazad\n";
                std::cout<<" 1 - Dodavanje novog korisnika\n";
                std::cout<<" 2 - Izlistaj korisnike\n";
                std::cout<<" 3 - Izlistaj zaduzenja korisnika\n";
                std::cout<<" 4 - Kraj\n";
                int int_kor;
                std::cin>>int_kor;
                if(int_kor==1){
                    for(;;){
                        int clbr;
                        std::string ime,prezime,adresa,telefon;
                        std::cout<<"Unesi clanski broj korisnika: ";
                        std::cin>>clbr;
                        std::cout<<"Unesi ime korisnika: ";
                        std::cin.ignore(1000,'\n');
                        std::getline(std::cin,ime,'\n');
                        std::cout<<"Unesi prezime korisnika: ";
                        std::getline(std::cin,prezime,'\n');
                        std::cout<<"Unesi adresu korisnika: ";
                        std::getline(std::cin,adresa,'\n');
                        std::cout<<"Unesi broj telefona: ";
                        std::getline(std::cin,telefon,'\n');
                        try{
                            Cazin.RegistrirajNovogKorisnika(clbr,ime,prezime,adresa,telefon);
                        }
                        catch(std::logic_error x){
                            std::cout<<"Izuzetak: "<<x.what();
                            continue;
                        }break;
                    }
                }
                if(int_kor==2){
                    Cazin.IzlistajKorisnike();
                }
                if(int_kor==3){
                    for(;;){std::cout<<"Unesi clanski broj korisnika: ";
                    int clbr;
                    std::cin>>clbr;
                    try{
                        Cazin.PrikaziZaduzenja(clbr);
                    }
                    catch(std::domain_error x){
                        std::cout<<"Izuzetak: "<<x.what();continue;
                    }break;
                    }
                }
                if(int_kor==0)break;
                if(int_kor==4)return 0;
            }
        }
        if(glavni==0)break;
    }
	return 0;
}