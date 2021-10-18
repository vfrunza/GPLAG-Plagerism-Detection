#include <iostream>
#include <map>
#include <memory>

struct Korisnik{
    std::string ime, prezime,adresa, telefon;
};

class Knjiga{
private:
  std::string naslov,ime_pisca,zanr;
  int godina_izdavanja;
  Korisnik*korisnik;
  public:
  Knjiga(std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja){
      Knjiga::naslov=naslov;
      Knjiga::ime_pisca=ime_pisca;
      Knjiga::zanr=zanr;
      Knjiga::godina_izdavanja=godina_izdavanja;
      korisnik=nullptr;
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
       return godina_izdavanja;
   }
    
   Korisnik *DajKodKogaJe(){
        return korisnik;
    }
    
   void ZaduziKnjigu(Korisnik &k){
       korisnik=&k;
   }
    
   void RazduziKnjigu(){
       korisnik=nullptr;
   }
   
   bool DaLiJeZaduzena()const{
       if(korisnik==nullptr)    return false;
       return true;
   }

};

class Biblioteka{
    std::map<int,std::shared_ptr<Korisnik>>m_korisnici;
    std::map<int,std::shared_ptr<Knjiga>>m_knjige;
     public:
 
   
    void RegistrirajNovogKorisnika(int cl_broj,std::string ime, std::string prezime, std::string adresa, std::string br_telefona){
        auto it=m_korisnici.find(cl_broj);
        if(it!=m_korisnici.end())   throw std::logic_error("Korisnik vec postoji");
        auto korisnik=std::make_shared<Korisnik>();
        korisnik->ime=ime;korisnik->prezime=prezime; korisnik->adresa=adresa; korisnik->telefon=br_telefona;
        m_korisnici.insert(std::make_pair(cl_broj,korisnik));
        
    }
    
    void RegistrirajNovuKnjigu(int ev_broj,std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja)
 {   
    auto it=m_knjige.find(ev_broj);
    if(it!=m_knjige.end())  throw std::logic_error("Knjiga vec postoji");
    auto knjiga=std::make_shared<Knjiga>(naslov,ime_pisca,zanr,godina_izdavanja);
    m_knjige.insert(std::make_pair(ev_broj,knjiga));

}
    
    Korisnik &NadjiKorisnika(int cl_broj)const;
    Knjiga &NadjiKnjigu(int ev_broj)const;
    void IzlistajKorisnike()const;
    void IzlistajKnjige()const;
    void ZaduziKnjigu(int ev_broj, int cl_broj);
    void RazduziKnjigu(int ev_broj);
    void PrikaziZaduzenja(int cl_broj)const;
    
};


Korisnik &Biblioteka::NadjiKorisnika(int cl_broj)const{
    auto it=m_korisnici.find(cl_broj);
    if(it==m_korisnici.end())   throw std::logic_error("Korisnik nije nadjen");
    
    return *(it->second);
}

Knjiga &Biblioteka::NadjiKnjigu(int ev_broj)const{
    
    auto it=m_knjige.find(ev_broj);
    if(it==m_knjige.end())  throw std::logic_error("Knjiga nije nadjena");
    
    return *(it->second);
    
}


void Biblioteka::IzlistajKorisnike()const{
    
    auto it=m_korisnici.begin();
    for(int i=0;i<m_korisnici.size();i++){
        std::cout<<"Clanski broj: "<<it->first<<std::endl;
        std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
        std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl<<std::endl;
        it++;
    }
    
}

void Biblioteka::IzlistajKnjige()const{
    
    auto it=m_knjige.begin();
    for(int i=0;i<m_knjige.size();i++){
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
        if((it->second->DaLiJeZaduzena())==true){
        std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime;
        std::cout<<" "<<it->second->DajKodKogaJe()->prezime;
        }
        std::cout<<std::endl<<std::endl;
        it++;
    }
}

void Biblioteka::ZaduziKnjigu(int ev_broj,int cl_broj){
    if(ev_broj<0 || ev_broj>m_knjige.size())
        throw std::logic_error("Knjiga nije nadjena");
    auto it=m_knjige.find(ev_broj);
    if((it->second->DaLiJeZaduzena())==true)  throw std::logic_error("Knjiga vec zaduzena");
    if(cl_broj<0 || cl_broj>m_korisnici.size())
        throw std::logic_error("Korisnik nije nadjen");
    auto itt=m_korisnici.find(cl_broj);
   it->second->ZaduziKnjigu(*(itt->second)); 
    
}

void Biblioteka::RazduziKnjigu(int ev_broj){
    if(ev_broj<0 || ev_broj>m_knjige.size())
        throw std::logic_error("Knjiga nije nadjena");
    auto it=m_knjige.find(ev_broj);
    if((it->second->DaLiJeZaduzena())==false)   throw std::logic_error("Knjiga nije zaduzena");
    it->second->RazduziKnjigu();

}

void Biblioteka::PrikaziZaduzenja(int cl_broj)const{
   
   int brojac(0);
    if(cl_broj<0 || cl_broj>m_korisnici.size()) throw std::logic_error("Korisnik nije nadjen");
    auto itt=m_korisnici.find(cl_broj);
    auto s=itt;
    auto it=m_knjige.begin();
    auto p=it;
    for(int i=0;i<m_knjige.size();i++){
        if((p->second.get())->DajKodKogaJe()==(s->second).get())   brojac++;
        p++;
    }
    
    if(brojac>0) std::cout<<"Nema zaduzenja za tog korisnika!";
    if(brojac==0){
    for(int i=0;i<m_knjige.size();i++){
       
        if((it->second.get())->DajKodKogaJe()==itt->second.get()){
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl<<std::endl;
    }
    
    it++;
    }}

}


int main(){
    
    int x;
    std::cout<<"Odaberi mogucnost: (1 za unos novog korisnika, 2 za prikaz liste korisnika biblioteke,3 za trazenje korisnika,0 za kraj)";
    std::cin>>x;
    Biblioteka s;
    s.RegistrirajNovogKorisnika(1,"Pero","Peric","Grbavica","789/890");
    s.RegistrirajNovogKorisnika(2,"Marica","Maric","Isaka Samokovlije","765/342");
    for(;;){
    if(x==0)    return 0;
    if(x==1){
           int cl_broj;
           std::string ime;
        try{
            while(ime!="kraj"){
        std::cout<<"Unesite clanski broj, ime, prezime,adresu i telefon korisnika"<<std::endl;
        std::string prezime,adresa,telefon;
        std::cin>>cl_broj;
        std::cin.ignore(100,'\n');
        std::getline(std::cin,ime);
        if(ime=="kraj") break;
        std::getline(std::cin,prezime);
        std::getline(std::cin,adresa);
        std::getline(std::cin,telefon);
        s.RegistrirajNovogKorisnika(cl_broj,ime,prezime,adresa,telefon);
    }
        }
    
    catch(std::logic_error e){
        std::cout<<e.what();
        return 0;
    }
    }
    
    else if(x==2){
        try{
        s.IzlistajKorisnike();}
        catch(std::logic_error e){
            std::cout<<e.what();
        }
    }
    
    else if(x==3){
       int x;
       std::cout<<"Unesite clanski broj trazenog korisnika: ";
       std::cin>>x;
       try{
       std::cout<<s.NadjiKorisnika(x).ime;
       std::cout<<" "<<s.NadjiKorisnika(x).prezime;    
       }
       catch(std::logic_error e){
           std::cout<<e.what();
           return 0;
       }
    }
    
    }
    
    return 0;
}