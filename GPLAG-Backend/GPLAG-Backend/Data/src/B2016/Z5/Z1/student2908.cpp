#include <iostream>
#include <map>
#include <stdexcept>
#include <new>



struct Korisnik{
    std::string ime,prezime,adresa,telefon;
    Korisnik(std::string i,std::string p,std::string a,std::string tel){ ime=i;prezime=p; adresa=a; telefon=tel; }
};


class Knjiga{
    std::string naslov,ime_pisca,genre;
    int godina_izdavanja;
    Korisnik *kod_koga_je;
    public:
    friend class Biblioteka;
    Knjiga(std::string n,std::string ip,std::string g,int gi,Korisnik *neki);
    Knjiga(std::string n,std::string ip,std::string g,int gi);
    std::string DajNaslov() const{ return naslov;}
    std::string DajAutora() const{ return ime_pisca;}
    std::string DajZanr() const{ return genre;}
    int DajGodinuIzdavanja() const {return godina_izdavanja;}
    Korisnik DajKodKogaJe() const { return *kod_koga_je;}
    void ZaduziKnjigu(Korisnik &zaduzeni){zaduzeni=*kod_koga_je;}
    void RazduziKnjigu(){kod_koga_je=nullptr;}
    bool DaLiJeZaduzena(){return kod_koga_je;}
   
    
    
    
 
};

Knjiga::Knjiga(std::string n,std::string ip,std::string g,int gi,Korisnik *neki):
    naslov(n),ime_pisca(ip),genre(g),godina_izdavanja(gi),kod_koga_je(neki) {}
    
        

    
Knjiga::Knjiga(std::string n,std::string ip,std::string g,int gi):
    naslov(n),ime_pisca(ip),genre(g),godina_izdavanja(gi) {kod_koga_je=nullptr;}
    
class Biblioteka{
  
    std::map<int,Korisnik*>korisnici;
    std::map<int,Knjiga*>knjige;
    public:
    Biblioteka ( Biblioteka &&b);
    Biblioteka &operator =(const Biblioteka &b);
   
    ~Biblioteka();
    void RegistrirajNovogKorisnika(int clanski_broj,std::string ime,std::string prezime,std::string adresa,std::string broj_tel);
    void RegistrirajNovuKnjigu (int broj_knjige,std::string naslov,std::string pisac,std::string zz,int godina_izdavanja);
    Korisnik NadjiKorisnika(int broj){ if(!korisnici.count(broj)) {throw std::logic_error ("Korisnik nije nadjen"); }
    else return *korisnici[broj];}
    Knjiga NadjiKnjigu(int broi){if(!knjige.count(broi)) throw std::logic_error ("Knjiga nije nadjena");  else return *knjige[broi];}
void IzlistajKorisnike() const ;
void IzlistajKnjige() const;

    
    
    
};

Biblioteka &Biblioteka::operator =(Biblioteka b){
    std::swap(knjige,b.knjige); std::swap(korisnici,b.korisnici);
    return *this;
}


/*Biblioteka::Biblioteka(const Biblioteka &b):korisnici(new std::map<int,b.korisnici.second>),
knjige(new std::map<int,>)
{
    try{
        for(int i=0;i<b.korisnici.size();i++){
            korisnici[i]=std::make_pair(b.korisnici[i].first,new Korisnik(b.korisnici[i]->second->ime,b.korisnici[i]->second->prezime,
            b.korisnici[i].second->adresa,b.korisnici[i].second->telefon);
            
        }
        for(int j=0,j<b.knjige.size();j++){
            knjige[j]=std::make_pair(b.knjige[j].first,new Knjiga(b.knjige[j]->second->naslov,b.knjige[j]->second->ime_pisca,b.knjige[j]->second->genre,
            b.knjige[j]->second->godina_izdavanja))
        }
    }
    catch(...){
        for(int i=0;i<b.korisnici.size();i++) delete korisnici[i];
         for(int j=0;j<b.knjige.size();j++) delete knjige[j];
    }
}*/


   

  


Biblioteka::~Biblioteka(){
    for(int i=0;i<knjige.size();i++) delete knjige[i];
    for(int j=0;j<korisnici.size();j++) delete korisnici[j];
 
}

void Biblioteka::IzlistajKorisnike() const {
    for(auto it=korisnici.begin();it!=korisnici.end();it++){
         std::cout<<"Clanski broj: "<<it->first<<std::endl;
         std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
         std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
         std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
    }
     std::cout<<std::endl;
}

void Biblioteka::IzlistajKnjige() const  {
    for(auto it=knjige.begin();it!=knjige.end();it++){
         std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
         std::cout<<"Naslov: "<<it->second->naslov<<std::endl;
         std::cout<<"Pisac: "<<it->second->ime_pisca<<std::endl;
         std::cout<<"Zanr: "<<it->second->genre<<std::endl;
         std::cout<<"Godina izdavanja: "<<it->second->godina_izdavanja<<std::endl<<std::endl;
    }
    
   
}
void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj,std::string ime,std::string prezime,std::string adresa,std::string broj_tel){
            try{
        korisnici.insert(std::make_pair(clanski_broj,new Korisnik(ime,prezime,adresa,broj_tel)));
            }
            catch(std:: bad_alloc){
                std::cout<<"Nece ici...";
            }
        
       
    
}
    
void Biblioteka::RegistrirajNovuKnjigu(int broj_knjige,std::string naslov,std::string pisac,std::string zz,int godina_izdavanja){
        try{
       knjige.insert(std::make_pair(broj_knjige,new Knjiga(naslov,pisac,zz,godina_izdavanja)));
        }
        catch(std::bad_alloc){
            std::cout<<"Problemi sa memorijom";
        }
}

int main(){
Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
"Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
"Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
"Studenata 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);

Biblioteka a=b;
a.IzlistajKorisnike();


return 0;
}
    
