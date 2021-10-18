#include <iostream>
#include<string>
#include<map>
#include<stdexcept>
struct Korisnik {
    std::string ime;
    std::string prezime; 
    std::string adresa;
    std::string telefon;
};
class Knjiga
{
    std::string naslov, imepisca,  zanr;
    int godina;
    Korisnik *zauzeta{nullptr};
public:
    Knjiga(std::string naslov1, std::string ime_pisca, std::string zanr1, int god) {
        naslov=naslov1;
        imepisca=ime_pisca;
        zanr=zanr1;
        godina=god;
        zauzeta=nullptr;
    }
    std::string DajNaslov() const {
        return naslov;
    }
    std::string DajAutora() const {
        return imepisca;
    }
    std::string DajZanr() const {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return godina;
    }
    Korisnik *DajKodKogaJe() const {
        return zauzeta;
    }
    void ZaduziKnjigu(Korisnik &k) {
        zauzeta=&k;
    }
    void RazduziKnjigu() {
        zauzeta=nullptr;
    }
    bool DaLiJeZaduzena() {
        return zauzeta!=nullptr;
    }
};
class Biblioteka
{
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
public:
    Biblioteka ()=default;
    Biblioteka (const Biblioteka &bib) {
        try {
            for(auto it=bib.korisnici.begin(); it!=bib.korisnici.end(); it++) {
                korisnici.insert(std::make_pair(it->first, new Korisnik(*it->second)));
            }

            try {
                for(auto it=bib.knjige.begin(); it!=bib.knjige.end(); it++) {
                    knjige.insert(std::make_pair(it->first, new Knjiga(*it->second)));
                }
            } catch(std::bad_alloc) {
                for(auto it=knjige.begin(); it!=knjige.end(); it++) {
                    delete it->second;
                    it->second=nullptr;
                }
            }
        }

        catch(std::bad_alloc) {
            for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
                delete it->second;
                it->second=nullptr;
            }
        }
    }
    ~Biblioteka() {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
            delete it->second;
            it->second=nullptr;
        }
        for(auto it=knjige.begin(); it!=knjige.end(); it++) {
            delete it->second;
            it->second=nullptr;
        }
    }
    Biblioteka &operator =(const Biblioteka &bib) {
        if(&bib!=this) {
            for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
                delete it->second;
                it->second=nullptr;
            }
            for(auto it=knjige.begin(); it!=knjige.end(); it++) {
                delete it->second;
                it->second=nullptr;
            }
            try {
                for(auto it=bib.korisnici.begin(); it!=bib.korisnici.end(); it++) {
                    korisnici.insert(std::make_pair(it->first, new Korisnik(*it->second)));
                }

                try {
                    for(auto it=bib.knjige.begin(); it!=bib.knjige.end(); it++) {
                        knjige.insert(std::make_pair(it->first, new Knjiga(*it->second)));
                    }
                } catch(std::bad_alloc) {
                    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
                        delete it->second;
                        it->second=nullptr;
                    }
                }
            }

            catch(std::bad_alloc) {
                for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
                    delete it->second;
                    it->second=nullptr;
                }
            }
        }
        return *this;
    }
Biblioteka &operator =(const Biblioteka &&bib){
    if(&bib!=this){
         korisnici=std::move(bib.korisnici); 
         knjige=std::move(bib.knjige); 
    }
    return *this;
}
Biblioteka(const Biblioteka &&bib){
     korisnici=std::move(bib.korisnici); 
        knjige=std::move(bib.knjige); 
}
void RegistrirajNovogKorisnika(int clanskibroj, std::string ime1, std::string prezime1, std::string adresa1, std::string brtelefona){
    Korisnik *pok=nullptr; 
    pok= new Korisnik; 
    pok->ime=ime1; pok->prezime=prezime1; pok->adresa=adresa1; pok->telefon=brtelefona; 
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) if(clanskibroj==it->first) throw std::logic_error("Korisnik vec postoji"); 
    korisnici.insert(std::make_pair(clanskibroj, pok)); 
    
}
void RegistrirajNovuKnjigu(int clanskibroj, std::string naslov, std::string ime, std::string zanr, int godina){
    Knjiga *pok=nullptr; 
    pok= new Knjiga(naslov, ime, zanr, godina); 
    for(auto it=knjige.begin(); it!=knjige.end(); it++) if(clanskibroj==it->first) throw std::logic_error("Knjiga vec postoji"); 
    knjige.insert(std::make_pair(clanskibroj, pok)); 
    
}
Korisnik& NadjiKorisnika(int clanskibroj){
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
    if(clanskibroj==it->first) return *(it->second); 
    throw std::logic_error("Korisnik nije nadjen"); 
}
Knjiga &NadjiKnjigu(int evidencijskibroj){
    for(auto it=knjige.begin(); it!=knjige.end(); it++)
    if(evidencijskibroj==it->first) return *(it->second); 
    throw std::logic_error("Knjiga nije nadjen"); 
   
}
void IzlistajKorisnike() const{
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
        std::cout<<"Clanski broj: "<<it->first<<std::endl; 
        std::cout<<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<std::endl; 
        std::cout<<"Adresa: "<<(it->second)->adresa<<std::endl; 
        std::cout<<"Broj telefona: "<<(it->second)->telefon<<std::endl; 
        std::cout<<std::endl; 
    }
}
void IzlistajKnjige() const{
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl; 
        std::cout<<"Naslov: "<<(*(it->second)).DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<(it->second)->DajAutora()<<std::endl; 
        std::cout<<"Zanr: "<<(it->second)->DajZanr()<<std::endl; 
        std::cout<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl; 
        if(it->second->DaLiJeZaduzena())
        std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<std::endl; 
        std::cout<<std::endl; 
    }
}
void ZaduziKnjigu(int evidencijskibroj, int clanskibroj){
    int ima=0; 
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        if(it->first == evidencijskibroj ) ima=1; 
        
    }
    if(ima==0) throw std::logic_error("Knjiga nije nadjena"); 
    ima=0; 
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        if(it->first == evidencijskibroj ) if(it->second->DaLiJeZaduzena()==0) ima=1;
        
    }
    if(ima==0) throw std::logic_error("Knjiga vec zaduzena"); 
    ima=0; 
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
        if(it->first == clanskibroj) ima=1; 
    }
    if(ima==0) throw std::logic_error("Korisnik nije nadjen"); 
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        if(it->first==evidencijskibroj){
            for(auto it1=korisnici.begin(); it1!=korisnici.end(); it1++){
                if(it1->first==clanskibroj){
                    it->second->ZaduziKnjigu(*(it1->second)); 
                }
            }
        }
    }
}
void RazduziKnjigu(int evidencijskibroj){
    int ima=0; 
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        if(it->first == evidencijskibroj ) ima=1; 
        
    }
    if(ima==0) throw std::logic_error("Knjiga nije nadjena");
    ima=0; 
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        if(it->first == evidencijskibroj) if(it->second->DaLiJeZaduzena()) ima=1;
        
    }
    if(ima==0) throw std::logic_error("Knjiga nije zaduzena"); 
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        if(it->first == evidencijskibroj ) it->second->RazduziKnjigu();  
    }
}
void PrikaziZaduzenja (int clanskibroj) const{
    int ima=0;
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
       if(it->first==clanskibroj){ima=1;}
    }
    if (ima==0) throw std::logic_error("Korisnik nije nadjen"); 
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
       if(it->first==clanskibroj){
           int ima1=0; 
           for(auto it1=knjige.begin(); it1!=knjige.end(); it1++){
               if(it1->second->DajKodKogaJe()==it->second){
                   ima1=1; 
                   std::cout<<"Evidencijski broj: "<<it1->first<<std::endl;
                        std::cout<<"Naslov: "<<it1->second->DajNaslov()<<std::endl;
                        std::cout<<"Pisac: "<<it1->second->DajAutora()<<std::endl;
                        std::cout<<"Zanr: "<<it1->second->DajZanr()<<std::endl;
                        std::cout<<"Godina izdavanja: "<<it1->second->DajGodinuIzdavanja()<<std::endl;
                        if(it1->second->DaLiJeZaduzena()) {
                            std::cout<<"Zaduzena kod korisnika: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
                        }
                        std::cout<<std::endl;
               }
           }
           if(ima1==0) std::cout<<"Nema zaduzenja za tog korisnika!"; 
       }
    }
}

};
int main ()
{
  
}