/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <memory>
struct Korisnik{
  std::string ime,prezime,adresa,telefon;  
};
class Knjiga{
    std::string naslov,ime_pisca,zanr;
    int god_izdavanja;
    Korisnik* zaduzenje=nullptr;
    public:
    Knjiga(std::string n,std::string i_p,std::string z,int g){
        naslov=n;
        ime_pisca=i_p;
        zanr=z;
        god_izdavanja=g;
    }
    std::string DajNaslov()const{
        return naslov;
    }
    std::string DajAutora()const{
        return ime_pisca;
    }
    std::string DajZanr()const{
        return zanr;
    }
    int DajGodinuIzdavanja()const{
        return god_izdavanja;
    }
    Korisnik* DajKodKogaJe()const{
        return zaduzenje;
    }
    void ZaduziKnjigu(Korisnik &k){
        //std::cout<<k.prezime;
        zaduzenje=&k;
    }
    void RazduziKnjigu(){
        zaduzenje=0;
    }
    bool DaLiJeZaduzena()const{
        return zaduzenje!=nullptr;
    }
};
class Biblioteka{
    std::map<int,std::shared_ptr<Korisnik>>korisnici;
    std::map<int,std::shared_ptr<Knjiga>>knjige;
    public:
    Biblioteka(){}
//~Biblioteka();
Biblioteka(const Biblioteka &b);
Biblioteka &operator =(const Biblioteka &b);
void RegistrirajNovogKorisnika(int clanski_broj,std::string ime,std::string prezime,std::string adresa,std::string broj_telefona);
void RegistrirajNovuKnjigu(int ev_broj,std::string nas,std::string im_pr,std::string zan,int god);
Korisnik &NadjiKorisnika(int clanski_broj);
Knjiga &NadjiKnjigu(int ev_broj);
void IzlistajKorisnike()const;
void IzlistajKnjige()const;
void ZaduziKnjigu(int ev_broj,int clanski_broj);
void RazduziKnjigu(int ev_broj);
void PrikaziZaduzenja(int clanski_broj);

};
/*Biblioteka::~Biblioteka(){
    for(auto  it=korisnici.begin();it!=korisnici.end();it++){
        delete it->second;
    }
    for(auto it=knjige.begin();it!=knjige.end();it++){
        delete it->second;
    }
}*/
Biblioteka::Biblioteka(const Biblioteka &b){
    //korisnici=b.korisnici;
    //knjige=b.knjige;
    for(auto it=b.korisnici.begin();it!=b.korisnici.end();it++){
        std::shared_ptr<Korisnik>k(new Korisnik);
        k->ime=it->second->ime;
        k->prezime=it->second->prezime;
        k->adresa=it->second->adresa;
        k->telefon=it->second->telefon;
        Biblioteka::korisnici.insert(std::make_pair(it->first,k));
    }
    for(auto it=b.knjige.begin();it!=knjige.end();it++){
        std::shared_ptr<Knjiga >k(std::make_shared<Knjiga>(it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja()));
        k->Knjiga::ZaduziKnjigu(*(it->second->DajKodKogaJe()));
        Biblioteka::knjige.insert(std::make_pair(it->first,k));
    }
}
Biblioteka &Biblioteka::operator =(const Biblioteka &b){
    if(&b==this) return *this;
    for(auto it=korisnici.begin();it!=korisnici.end();it++){
         it->second=nullptr;
        korisnici.erase(it);
    }
    for(auto it=b.korisnici.begin();it!=b.korisnici.end();it++){
        std::shared_ptr<Korisnik >k(new Korisnik);
        k->ime=it->second->ime;
        k->prezime=it->second->prezime;
        k->adresa=it->second->adresa;
        k->telefon=it->second->telefon;
        Biblioteka::korisnici.insert(std::make_pair(it->first,k));
        //it->second=nullptr;
    }
    for(auto it=knjige.begin();it!=knjige.end();it++){
         it->second=nullptr;
        knjige.erase(it);
    }
    for(auto it=b.knjige.begin();it!=b.knjige.end();it++){
        std::shared_ptr<Knjiga >k(std::make_shared<Knjiga>(it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja()));
        k->Knjiga::ZaduziKnjigu(*(it->second->DajKodKogaJe()));
        Biblioteka::knjige.insert(std::make_pair(it->first,k));
        //delete it->second;
    }
    return *this;
}
void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj,std::string ime,std::string prezime,std::string adresa,std::string broj_telefona){
    for(auto it=korisnici.begin();it!=korisnici.end();it++){
        if(clanski_broj==it->first)throw std::logic_error("Korisnik vec postoji");
    }
    std::shared_ptr<Korisnik >k(new Korisnik);
        k->ime=ime;
        k->prezime=prezime;
        k->adresa=adresa;
        k->telefon=broj_telefona;
        Biblioteka::korisnici.insert(std::make_pair(clanski_broj,k));
}
void Biblioteka::RegistrirajNovuKnjigu(int ev_broj,std::string nas,std::string im_pr,std::string zan,int god){
    for(auto it=knjige.begin();it!=knjige.end();it++){
        if(ev_broj==it->first)throw std::logic_error("Knjiga vec postoji");
    }
    std::shared_ptr<Knjiga >k(std::make_shared<Knjiga>(nas,im_pr,zan,god));
        Biblioteka::knjige.insert(std::make_pair(ev_broj,k));
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj){
    for(auto it=korisnici.begin();it!=korisnici.end();it++){
        if(clanski_broj==it->first)return *(it->second);
    }
    throw std::logic_error("Korisnik nije nadjen");
}
Knjiga &Biblioteka::NadjiKnjigu(int ev_broj){
    for(auto it=knjige.begin();it!=knjige.end();it++){
        if(ev_broj==it->first)return *(it->second);
    }
    throw std::logic_error("Knjiga nije nadjena");
}
void Biblioteka::IzlistajKorisnike()const{
    for(auto it=korisnici.begin();it!=korisnici.end();it++){
        std::cout<<"Clanski broj: "<<it->first<<std::endl;
        std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
        std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
        std::cout<<std::endl;
    }
}
void Biblioteka::IzlistajKnjige()const{
    for(auto it=knjige.begin();it!=knjige.end();it++){
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
        if(it->second->DaLiJeZaduzena()){
            std::cout<<"Zaduzena kod korisnika: "
            <<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime;
        }
        std::cout<<std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int ev_broj,int clanski_broj){
    try{
        Knjiga k=NadjiKnjigu(ev_broj);
        //std::cout<<k.DajAutora()<<std::endl;
        try{
        Korisnik r=NadjiKorisnika(clanski_broj);
        //std::cout<<r.ime<<std::endl;
        if(k.DaLiJeZaduzena())throw std::logic_error("Knjiga vec zaduzena");
        else{
            for(auto it1=knjige.begin();it1!=knjige.end();it1++){
                if(it1->first==ev_broj){
                    for(auto it=korisnici.begin();it!=korisnici.end();it++){
                        if(it->first==clanski_broj){
                            it1->second->ZaduziKnjigu(*(it->second));
                        }
                    }
                }
            }
        }
    }
    catch(std::logic_error e){
        throw;
    }
    }
    catch(std::logic_error e){
        throw;
    }
    
}
void Biblioteka::RazduziKnjigu(int ev_broj){
    try{
        Knjiga k=NadjiKnjigu(ev_broj);
        if(k.DaLiJeZaduzena()==false)throw std::logic_error("Knjiga nije zaduzena");
        else {
            for(auto it=knjige.begin();it!=knjige.end();it++){
                if(it->first==ev_broj)
                it->second->RazduziKnjigu();
            }
        }
    }
    catch(std::logic_error e){
        throw;
    }
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj){
    try{
        int i=0;
        for(auto it=korisnici.begin();it!=korisnici.end();it++){
            if(it->first==clanski_broj){
                for(auto it1=knjige.begin();it1!=knjige.end();it1++){
                    if(it->second->ime == it1->second->DajKodKogaJe()->ime && it->second->prezime == it1->second->DajKodKogaJe()->prezime && it->second->adresa == it1->second->DajKodKogaJe()->adresa && it->second->telefon == it1->second->DajKodKogaJe()->telefon) {
                        std::cout<<"Evidencijski broj: "<<it1->first<<std::endl;
                        std::cout<<"Naslov: "<<it1->second->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<it1->second->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<it1->second->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<it1->second->DajGodinuIzdavanja()<<std::endl;
        std::cout<<std::endl;
        i++;
                    }
                }
            }
        }
        if(i==0)throw std::logic_error("Nema zaduzenja za tog korisnika!");
    }
    catch(std::logic_error e){
        std::cout<<e.what();
    }
}

int main ()
{
    Biblioteka b;
    int x;
    std::cout<<">>> GLAVNI MENI <<<"<<std::endl
    <<"1 Registruj novog korisnika"<<std::endl
    <<"2 Registruj novu knjigu"<<std::endl
    <<"3 Zaduzi knjigu"<<std::endl
    <<"4 Razduzi knjigu"<<std::endl
    <<"5 Izlistaj korsnike"<<std::endl
    <<"6 Izlistaj knjige"<<std::endl
    <<"7 Prikazi zaduzenja za zeljenog korisnika"<<std::endl
    <<"0 KRAJ"<<std::endl;
    do{
        std::cout<<"Unesi komandu: ";
        std::cin>>x;
        if(x==1){
            std::cout<<std::endl<<">>> REGISTRACIJA NOVOG KORISNIKA <<<"<<std::endl;
            int clanski_broj;
            std::cout<<"Unesi clanski broj: ";
            std::cin>>clanski_broj;
            std::cin.ignore(100000,'\n');
            std::cin.clear();
            std::string ime,prezime,adresa,telefon;
            std::cout<<"Unesi ime: ";
            std::getline(std::cin,ime);
            std::cout<<"Unesi prezime: ";
            std::getline(std::cin,prezime);
            std::cout<<"Unesi adresu: ";
            std::getline(std::cin,adresa);
            std::cout<<"Unesi telefon: ";
            std::getline(std::cin,telefon);
            b.RegistrirajNovogKorisnika(clanski_broj,ime,prezime,adresa,telefon);
            std::cout<<"KORISNIK JE REGISTROVAN"<<std::endl;
        }
        else if(x==2){
            std::cout<<std::endl<<">>> REGISTRACIJA NOVE KNJIGE <<<"<<std::endl;
            int ev_broj,god_izdavanja;
            std::string naslov,ime_pisca,zanr;
            std::cout<<"Unesi evidencijski broj: ";
            std::cin>>ev_broj;
            std::cin.ignore(10000,'\n');
            std::cin.clear();
            std::cout<<"Unesi naslov knjige: ";
            std::getline(std::cin,naslov);
            std::cout<<"Unesi ime i prezime pisca: ";
            std::getline(std::cin,ime_pisca);
            std::cout<<"Unesi zanr: ";
            std::getline(std::cin,zanr);
            std::cout<<"Unesi godinu izdavanja: ";
            std::cin>>god_izdavanja;
            b.RegistrirajNovuKnjigu(ev_broj,naslov,ime_pisca,zanr,god_izdavanja);
            std::cout<<"KNJIGA JE REGISTROVANA"<<std::endl;
        }
        else if(x==3){
            std::cout<<std::endl<<">>> ZADUZENJE KNJIGE <<<"<<std::endl;
            int ev_broj,clanski_broj;
            std::cout<<"Unesi evidencijski broj knjige: ";
            std::cin>>ev_broj;
            std::cout<<"Unesi clanski broj korisnika: ";
            std::cin>>clanski_broj;
            b.ZaduziKnjigu(ev_broj,clanski_broj);
            std::cout<<"FILM JE ZADUZEN"<<std::endl;
        }
        else if(x==4){
            std::cout<<std::endl<<">>> RAZDUZENJE KNJIGE <<<"<<std::endl;
            int ev_broj;
            std::cout<<"Unesi evidencijski broj knjige: ";
            std::cin>>ev_broj;
            b.RazduziKnjigu(ev_broj);
            std::cout<<"KNJIGA RAZDUZENA"<<std::endl;
        }
        else if(x==5){
            std::cout<<std::endl<<">>> KORISNICI <<<"<<std::endl;
            b.IzlistajKorisnike();
            std::cout<<"KORISNICI IZLISTANI"<<std::endl;
        }
        else if(x==6){
            std::cout<<std::endl<<">>> KNJIGE <<<"<<std::endl;
            b.IzlistajKnjige();
            std::cout<<"KNJIGE IZLISTANE"<<std::endl;
        }
        else if(x==7){
            std::cout<<std::endl<<">>> PRIKAZ ZADUZENJA KORISNIKA <<<<"<<std::endl;
            int korisnik;
            std::cout<<"Unesi clanski broj korisnika: ";
            std::cin>>korisnik;
            std::cout<<"Korisnik: "<<std::endl;
            b.PrikaziZaduzenja(korisnik);
            std::cout<<"PRIKAZ ZADUZENJA"<<std::endl;
        }
        else if(x==0)std::cout<<"Dovidjenja!";
        else std::cout<<"Neispravna komanda";
    }while(x!=0);
	return 0;
}