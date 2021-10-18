/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, pisac, zanr;
    int godina;
    Korisnik *pok;
    friend class Biblioteka;
    public:
    Knjiga(std::string naslov1, std::string pisac1, std::string zanr1, int godina1):
        naslov(naslov1), pisac(pisac1), zanr(zanr1), godina(godina1), pok(nullptr) {}
    std::string DajNaslov() const { return naslov;}
    std::string DajAutora() const { return pisac; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina; }
    Korisnik* DajKodKogaJe() const { return pok; }
    void ZaduziKnjigu(Korisnik &k){ pok=&k; }
    void RazduziKnjigu() { pok=nullptr; }
    bool DaLiJeZaduzena() const { return !(pok==nullptr);}
};

class Biblioteka {
    std::map<int, Korisnik*> m_korisnika;
    std::map<int, Knjiga*> m_knjiga;
    public:
    ~Biblioteka() {for(auto it=m_korisnika.begin(); it!=m_korisnika.end(); it++) delete it->second;  
        for(auto it=m_knjiga.begin(); it!=m_knjiga.end(); it++) delete it->second; 
    }
    void RegistrirajNovogKorisnika(int cl_broj, std::string ime1,std::string prezime1,std::string adresa1,std::string telefon1);
    void RegistrirajNovuKnjigu(int br_knjige, std::string naslov, std::string pisac1, std::string zanr, int godina1);
    Korisnik &NadjiKorisnika(int cl_broj);
    Knjiga &NadjiKnjigu(int br_knjige);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int br_knjige, int cl_broj);
    void RazduziKnjigu(int br_knjige) const;
    void PrikaziZaduzenja(int cl_broj) const;
    Biblioteka &operator=(const Biblioteka &b);
   // Biblioteka &operator=(Biblioteka &&b);
};
void Biblioteka::RegistrirajNovogKorisnika(int cl_broj, std::string ime1, std::string prezime1, std::string adresa1, std::string telefon1){
    
    Korisnik* k;
    try {
        k=new Korisnik;
    auto it(m_korisnika.find(cl_broj));
    if(it!=m_korisnika.end()) throw std::logic_error("Korisnik vec postoji");
    k->ime=ime1;
    k->prezime=prezime1;
    k->adresa=adresa1;
    k->telefon=telefon1;
    m_korisnika.insert(std::make_pair(cl_broj, k));
    }
    catch(std::bad_alloc){
        delete k;
    }
}
void Biblioteka::RegistrirajNovuKnjigu(int br_knjige, std::string naslov1, std::string pisac1, std::string zanr1, int godina1){
    auto it(m_knjiga.find(br_knjige));
    if(it!=m_knjiga.end()) throw std::logic_error("Knjiga vec postoji");
    Knjiga* k;
    try{
    k=new Knjiga(naslov1, pisac1, zanr1, godina1);
    m_knjiga.insert(std::make_pair(br_knjige, k));
    }
    catch(std::bad_alloc){
        delete k;
    }
}
 Korisnik &Biblioteka::NadjiKorisnika(int cl_broj){
     auto it(m_korisnika.find(cl_broj));
     if(it==m_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
     return *(it->second);
 }
 Knjiga &Biblioteka::NadjiKnjigu(int br_knjige){
     auto it(m_knjiga.find(br_knjige));
     if(it==m_knjiga.end()) throw std::logic_error ("Knjiga nije nadjena");
     return *(it->second);
 }
 void Biblioteka::IzlistajKorisnike() const{
     for(auto it=m_korisnika.begin(); it!=m_korisnika.end(); it++){
         std::cout << "Clanski broj: " << it->first << std::endl;
         std::cout << "Ime i prezime: " << (*(it->second)).ime << " " << (*(it->second)).prezime << std::endl;
         std::cout << "Adresa: " << (*(it->second)).adresa << std::endl;
         std::cout << "Broj telefona: " << (*(it->second)).telefon << std::endl << std::endl;
     }
 }
 void Biblioteka::IzlistajKnjige() const {
     for(auto it=m_knjiga.begin(); it!=m_knjiga.end(); it++){
         std::cout << "Evidencijski broj: " << it->first << std::endl;
         std::cout << "Naslov: " << (*(it->second)).naslov << std::endl;
         std::cout << "Pisac: " << (*(it->second)).pisac << std::endl;
         std::cout << "Zanr: " << (*(it->second)).zanr << std::endl;
         std::cout << "Godina izdavanja: " << (*(it->second)).godina << std::endl;
         if((*(it->second)).pok!=nullptr) 
           std::cout << "Zaduzena kod korisnika: " << (*((*(it->second)).pok)).ime << " " << (*((*(it->second)).pok)).prezime;
           std::cout << std::endl;
     }
 }
 void Biblioteka::ZaduziKnjigu(int br_knjige, int cl_broj){
     auto it(m_knjiga.find(br_knjige));
     if(it==m_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
     if((*(it->second)).pok!=nullptr) throw std::logic_error ("Knjiga vec zaduzena");
     auto it2(m_korisnika.find(cl_broj));
     if(it2==m_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
     (*(it->second)).pok=it2->second;
  }

void Biblioteka::RazduziKnjigu(int br_knjige) const{
    auto it(m_knjiga.find(br_knjige));
    if(it==m_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    if((*(it->second)).pok==nullptr) throw std::logic_error ("Knjiga nije zaduzena");
    delete (*(it->second)).pok;
    (*(it->second)).pok=nullptr;
}
void Biblioteka::PrikaziZaduzenja(int cl_broj) const {
    auto it(m_korisnika.find(cl_broj));
    int brojac(0);
    if(it==m_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    
    for(auto it2=m_knjiga.begin(); it2!=m_knjiga.end(); it2++){
        if((it->second)==(*(it2->second)).pok){
            std::cout << "Evidencijski broj: " << it2->first << std::endl;
            std::cout << "Naslov: " << (*(it2->second)).naslov << std::endl;
            std::cout << "Pisac: " << (*(it2->second)).pisac << std::endl;
            std::cout << "Zanr: " << (*(it2->second)).zanr << std::endl;
            std::cout << "Godina izdavanja: " << (*(it2->second)).godina << std::endl << std::endl;
            brojac++;
        }
    }
    if(brojac==0)
    std::cout << "Nema zaduzenja za tog korisnika!";
}

Biblioteka &Biblioteka::operator=(const Biblioteka &b){
  //  std::map<int,Korisnik*> x1;
    //std::map<int,Knjiga*> x2;
    
    int br_ko(b.m_korisnika.size());
    int br_knj(b.m_knjiga.size());
    Korisnik **ko=nullptr;
    Knjiga **knj=nullptr;
    try{
        ko=new Korisnik*[br_ko]{};
        knj=new Knjiga*[br_knj]{};
        for(int i=0; i<br_ko; i++){
            ko[i]=new Korisnik;
        }
        for(auto it=b.m_knjiga.begin(); it!=b.m_knjiga.end(); it++){
            this->=new Knjiga();
        
}
catch(...){
    for(int i=0; i<br_ko; i++){
        delete ko[i];
        delete[] ko;
}
}}

int main ()
{
    //AT4 (c9): testira DajKodKogaJe metodu

Biblioteka k;
Biblioteka d;
d=k;

	return 0;
}