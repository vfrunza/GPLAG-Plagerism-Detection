/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <new>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>

struct Korisnik{
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};

class Knjiga{
    std::string naslov_knjige;
    std::string pisac;
    std::string zanr;
    int godina_izdavanja;
    Korisnik *zaduzio;
    public:
    Knjiga(std::string naslov,std::string ime_pisca,std::string tip_knjige,int godina){
        naslov_knjige=naslov; pisac=ime_pisca; zanr=tip_knjige; godina_izdavanja=godina;zaduzio=nullptr;}
    std::string DajNaslov(){return naslov_knjige;};
    std::string DajAutora(){return pisac;};
    std::string DajZanr(){return zanr;};
    int DajGodinuIzdavanja(){return godina_izdavanja;};
    Korisnik* DajKodKogaJe(){return zaduzio;}
    void ZaduziKnjigu(Korisnik &k){if(zaduzio==nullptr)zaduzio=&k; else throw std::logic_error ("Knjiga je vec zaduzena");};
    void RazduziKnjigu(){zaduzio=nullptr;};
    bool DaLiJeZaduzena(){if(zaduzio==nullptr)return false;else return true;};
};

class Biblioteka{
    std::map<int,Korisnik*> mapa1;
    std::map<int,Knjiga*> mapa2;
    public:
    Biblioteka(){};
    Biblioteka(const Biblioteka &bibl);
    Biblioteka(const Biblioteka &&bibl);
    ~Biblioteka(){
        for(auto it=mapa1.begin();it!=mapa1.end();it++) delete it->second;
        for(auto itt=mapa2.begin();itt!=mapa2.end();itt++) delete itt->second;
    };
    Biblioteka &operator=(const Biblioteka &b);
    Biblioteka &operator=(const Biblioteka &&b);
    void RegistrirajNovogKorisnika(int cl_broj,std::string naziv,std::string prez,std::string adr,std::string tel);
    void RegistrirajNovuKnjigu(int evidencijsk_broj,std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja);
    Korisnik &NadjiKorisnika(int cl_broj);
    Knjiga &NadjiKnjigu(int evidencijsk_broj);
    void IzlistajKorisnike()const;
    void IzlistajKnjige()const;
    void ZaduziKnjigu(int evidencijsk_broj,int clanski_broj);
    void RazduziKnjigu(int evidencijsk_broj);
    void PrikaziZaduzenja(int clanski_broj)const;
};
    
Biblioteka::Biblioteka(const Biblioteka &bibl){
        for(auto it=bibl.mapa1.begin();it!=bibl.mapa1.end();it++){
            Korisnik *pok(new Korisnik);
            (*pok).ime=it->second->ime;
            (*pok).prezime=it->second->prezime;
            (*pok).adresa=it->second->adresa;
            (*pok).telefon=it->second->telefon;
            mapa1.insert(std::make_pair(it->first,pok));
        }
        for(auto it=bibl.mapa2.begin();it!=bibl.mapa2.end();it++){
           Knjiga *pok1(new Knjiga(it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja()));
           mapa2.insert(std::make_pair(it->first,pok1));
        }
    }
Biblioteka::Biblioteka(const Biblioteka &&bibl){
        for(auto it=bibl.mapa1.begin();it!=bibl.mapa1.end();it++){
            mapa1.insert(std::make_pair(it->first,it->second));
        }
        for(auto it=bibl.mapa1.begin();it!=bibl.mapa1.end();it++){
            delete it->second;
        }
        for(auto it=bibl.mapa2.begin();it!=bibl.mapa2.end();it++){
            mapa2.insert(std::make_pair(it->first,it->second));
        }
        for(auto it=bibl.mapa2.begin();it!=bibl.mapa2.end();it++){
            delete it->second;
        }
    }
    
Biblioteka &Biblioteka::operator=(const Biblioteka &b){
        for(auto it=mapa1.begin();it!=mapa1.end();it++) delete it->second;
        for(auto it=mapa2.begin();it!=mapa2.end();it++) delete it->second;
        mapa1.clear();
        for(auto it=b.mapa1.begin();it!=b.mapa1.end();it++){
            Korisnik * pok(new Korisnik);
            pok->ime=it->second->ime;
            pok->prezime=it->second->prezime;
            pok->adresa=it->second->adresa;
            pok->telefon=it->second->telefon;
            mapa1.insert(std::make_pair(it->first,pok));
     
        }
        mapa2.clear();
        for(auto it=b.mapa2.begin();it!=b.mapa2.end();it++){
            Knjiga *poko(new Knjiga(it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja()));
            mapa2.insert(std::make_pair(it->first,poko));
            
        }
        return *this;
    }
Biblioteka &Biblioteka::operator=(const Biblioteka &&b){
    //destruktor
    for(auto it=mapa1.begin();it!=mapa1.end();it++) delete it->second;
    for(auto it=mapa2.begin();it!=mapa2.end();it++) delete it->second;
    //pomjerajuci konstruktor kopije
    for(auto it=b.mapa1.begin();it!=b.mapa1.end();it++)mapa1.insert(std::make_pair(it->first,it->second));
    for(auto it=b.mapa1.begin();it!=b.mapa1.end();it++)delete it->second;
    for(auto it=b.mapa2.begin();it!=b.mapa2.end();it++)mapa2.insert(std::make_pair(it->first,it->second));
    for(auto it=b.mapa2.begin();it!=b.mapa2.end();it++)delete it->second;
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int cl_broj,std::string naziv,std::string prez,std::string adr,std::string tel){
  if(mapa1.size()==0){
       Korisnik *pok(new Korisnik);
            (*pok).ime=naziv;
            (*pok).prezime=prez;
            (*pok).adresa=adr;
            (*pok).telefon=tel;
            mapa1.insert(std::make_pair(cl_broj,pok));
  }
  else{
   bool dodaj=true;
   for(auto it=mapa1.begin();it!=mapa1.end();it++){
     if(cl_broj==(it->first)) dodaj=false;
     if(dodaj==false) throw std::logic_error ("Korisnik vec postoji");
    }
    if(dodaj){
        Korisnik *pok(new Korisnik);
				(*pok).ime = naziv;
				(*pok).prezime = prez;
				(*pok).adresa = adr;
				(*pok).telefon = tel;
				mapa1.insert(std::make_pair(cl_broj, pok));
    }
  
  } 
}
void Biblioteka::RegistrirajNovuKnjigu(int evidencijsk_broj,std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja){
       if(mapa2.size()==0){
        Knjiga *pok(new Knjiga(naslov, ime_pisca, zanr, godina_izdavanja));
		mapa2.insert(std::make_pair(evidencijsk_broj, pok));
    }
    else{
        bool dodaj_knjigu=true;
        for(auto it=mapa2.begin();it!=mapa2.end();it++){
        if(evidencijsk_broj==(it->first)) dodaj_knjigu=false;
            if(dodaj_knjigu==false) throw std::logic_error ("Knjiga vec postoji");
        }
        if(dodaj_knjigu){
            Knjiga *pok(new Knjiga(naslov,ime_pisca,zanr,godina_izdavanja));
            mapa2.insert(std::make_pair(evidencijsk_broj,pok));
        }
    }
}
Korisnik& Biblioteka::NadjiKorisnika(int cl_broj){
    for(auto it=mapa1.begin();it!=mapa1.end();it++){
        if(cl_broj==(it->first))return *(it->second);
    }
    throw std::logic_error("Korisnik nije nadjen");
}
Knjiga& Biblioteka::NadjiKnjigu(int evidencijsk_broj){
    for(auto it=mapa2.begin();it!=mapa2.end();it++){
        if(evidencijsk_broj==(it->first)) return *(it->second);
    }
    throw std::logic_error("Knjiga nije nadjena");
}

void Biblioteka::IzlistajKorisnike() const{
    for(auto it=mapa1.begin();it!=mapa1.end();it++){
    std::cout << "Clanski broj: "<< it->first << std::endl;
    std::cout << "Ime i prezime: "<< (it->second)->ime <<" "<< (it->second)->prezime << std::endl;
    std::cout << "Adresa: "<< (it->second)->adresa << std::endl;
    std::cout << "Broj telefona: "<< (it->second)->telefon <<std::endl;
    std::cout  << std::endl;
    }
}
void Biblioteka::IzlistajKnjige()const{
    for(auto it=mapa2.begin();it!=mapa2.end();it++){
        std::cout << "Evidencijski broj: "<<(it->first) << std::endl;
        std::cout << "Naslov: "<< (it->second)->DajNaslov()<< std::endl;
        std::cout << "Pisac: "<< (it->second)->DajAutora()<< std::endl;
        std::cout << "Zanr: "<< (it->second)->DajZanr()<< std::endl;
        std::cout << "Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja() << std::endl;
        if((it->second)->DajKodKogaJe()!=nullptr){
            std::cout << "Zaduzena kod korisnika: "<<((it->second)->DajKodKogaJe())->ime<<" "<<((it->second)->DajKodKogaJe())->prezime << std::endl;
            std::cout  << std::endl;
 
        }
    }
}

void Biblioteka::ZaduziKnjigu(int evidencijsk_broj,int clanski_broj){
    Knjiga &knjiga=NadjiKnjigu(evidencijsk_broj);
    Korisnik &korisnik=NadjiKorisnika(clanski_broj);
    if(knjiga.DaLiJeZaduzena()){
        throw std::logic_error ("Knjiga vec zaduzena");
    }
    else{
        knjiga.ZaduziKnjigu(korisnik);
    }
    
}
void Biblioteka::RazduziKnjigu(int evidencijsk_broj){
    Knjiga &knjiga=NadjiKnjigu(evidencijsk_broj);
    if(knjiga.DaLiJeZaduzena()==false){
        throw std::logic_error("Knjiga nije zaduzena");
    }
    else{
        knjiga.RazduziKnjigu();
    }
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj)const{
    int br=0;
    for(auto it1=mapa1.begin();it1!=mapa1.end();it1++){
        if(it1->first==clanski_broj){
            for(auto it2=mapa2.begin();it2!=mapa2.end();it2++){
                if((it2->second)->DaLiJeZaduzena()==true){
                    if(((it2->second)->DajKodKogaJe())->ime==((it1->second)->ime)){
                        if(((it2->second)->DajKodKogaJe())->prezime==(it1->second)->prezime){
                            if(((it2->second)->DajKodKogaJe())->adresa==(it1->second)->adresa){
                                if(((it2->second)->DajKodKogaJe())->telefon==(it1->second)->telefon){
                                    br++;
                                    std::cout << "Evidencijski broj: "<<(it2->first)<< std::endl;
                                    std::cout << "Naslov: "<<(it2->second)->DajNaslov()<< std::endl;
                                    std::cout << "Pisac: "<<(it2->second)->DajAutora()<<std::endl;
                                    std::cout << "Zanr: "<<(it2->second)->DajZanr()<< std::endl;
                                    std::cout << "Godina izdavanja: "<<(it2->second)->DajGodinuIzdavanja() << std::endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(br==0)std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
}

int main ()
{
    Biblioteka biblioteka;
    for(;;){
    std::cout << "Unesite 1. za registraciju novog clana" << std::endl;
    std::cout << "Unesite 2. za registraciju nove knjige" << std::endl;
    std::cout << "Unesite 3. za prikaz clanova" << std::endl;
    std::cout << "Unesite 4. za prikaz knjiga" << std::endl;
    std::cout << "Unesite 5. ako zelite zaduziti knjigu" << std::endl;
    std::cout << "Unesite 6. ako zelite razduziti knjigu" << std::endl;
    std::cout << "Unesite 7. za prikaz zaduzenja clnova" << std::endl;
    std::cout << "Unesite 0 za prekid programa" << std::endl;
    std::cout << std::endl;
    
        std::cout << "Izaberite neku od opcija: " << std::endl;
        int m;
        std::cin >> m;
        if(m<0 || m>7){std::cout << "Pogresan unos" << std::endl; continue;}
        if(m==1){
            std::cout << "IZABRALI STE OPCIJU ZA REGISTRACIJU NOVOG CLANA"<< std::endl;
            std::cout << "Unesite clanski broj: ";
            int br;std::cin >> br;
            std::cin.ignore(1000,'\n');
            std::cout << "Unesite ime clana: ";
            std::string ime;
            std::getline(std::cin,ime);
            std::cout << "Unesite prezime clana: ";
            std::string prez;
            std::getline(std::cin,prez);
            std::cout << "Unesite adresu clana: ";
            std::string adre;
            std::getline(std::cin,adre);
            std::cout << "Unesite telefon clana: ";
            std::string telefon;
            std::getline(std::cin,telefon);
            std::cout  << std::endl;
            try{
                biblioteka.RegistrirajNovogKorisnika(br,ime,prez,adre,telefon);}
            catch(std::logic_error e){std::cout <<  e.what() <<std::endl;}
            continue;
        }
        if(m==2){
            std::cout << "IZABRALI STE OPCIJU ZA REGISTRACIJU NOVE KNJIGE" << std::endl;
            std::cout << "Unesite evidencijski broj: ";
            int br;
            std::cin >> br;
            std::cin.ignore(1000,'\n');
            std::cout << "Unesite naslov knjige: ";
            std::string naziv;
            std::getline(std::cin,naziv);
            std::cout << "Unesite autora knjige: ";
            std::string autor;
            std::getline(std::cin,autor);
            std::cout << "Unesite zanr knjige: ";
            std::string zanr;
            std::getline(std::cin,zanr);
            std::cout << "Unesite godinu izdavanja knjige: ";
            int god;
            std::cin >> god;
            try{
                biblioteka.RegistrirajNovuKnjigu(br,naziv,autor,zanr,god);}
                catch(std::logic_error e){std::cout << e.what() << std::endl;}
                continue;
        }
        if(m==3){std::cout<<"IZABRALI STE OPCIJU ZA PRIKAZ SVIH KORISNIKA"<<std::endl;biblioteka.IzlistajKorisnike();continue;}
        if(m==4){std::cout<<"IZABRALI STE OPCIJU ZA PRIKAZ SVIH KNJIGA" << std::endl;biblioteka.IzlistajKnjige();continue;}
        if(m==5){
            std::cout << "IZBARALI STE OPCIJU ZA ZADUZIVANJE KNJIGE " << std::endl;
            std::cout << "Unesite evidencijski broj knjige: ";
            int knj;std::cin >> knj;
            std::cout << "Unesite clanski broj: ";
            int vlf; std::cin >> vlf;
            try{biblioteka.ZaduziKnjigu(knj,vlf);}
            catch(std::logic_error e){std::cout << e.what() << std::endl;}
            continue;
        }
        if(m==6){
            std::cout << "IZABRALI STE OPCIJU ZA RAZDUZIVANJE KNJIGE " << std::endl;
            std::cout << "Unesite evidencijski broj knjige: ";
            int kds; std::cin >> kds;
            try{biblioteka.RazduziKnjigu(kds);}
            catch(std::logic_error e){std::cout << e.what() << std::endl;}
            continue;
        }
        if(m==7){
            std::cout << "IZABRALI STE OPCIJU ZA PRIKAZ ZADUZENJA CLANOVA "<< std::endl;
           std::cout << "Unesite clanski broj korisnika: " << std::endl;
           int k;
           std::cin >> k;
           try{biblioteka.PrikaziZaduzenja(k);} 
           catch(std::logic_error e){std::cout << e.what() << std::endl;}
           continue;
        }
        if(m==0){std::cout << "IZABRALI STE KRAJ ";break;}
    }
	return 0;
}

