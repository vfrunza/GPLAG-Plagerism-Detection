/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise


#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <map>
#include <iterator>
#include <memory>

struct Korisnik{
  std::string ime, prezime, adresa, telefon;
};


class Knjiga{
  std::string naslov, imepisca, zanr;
  int godinaizdavanja;
  Korisnik *budalacita;
public:
  Knjiga(std::string nas, std::string pisac, std::string tip, int godina): naslov(nas), imepisca(pisac), zanr(tip), godinaizdavanja(godina), budalacita(nullptr){}
  
  std::string DajNaslov() const{
      return naslov;
  }
  std::string DajAutora() const {
      return imepisca;
  } 
  std::string DajZanr() const {
      return zanr;
  }
  int DajGodinuIzdavanja() const {
      return godinaizdavanja;
  }
  
  Korisnik* DajKodKogaJe() const {
      return budalacita;
  }
  void ZaduziKnjigu(Korisnik &k);
  void RazduziKnjigu();
  bool DaLiJeZaduzena() const;

};

void Knjiga::ZaduziKnjigu(Korisnik &k){
    budalacita=&k;
}
void Knjiga::RazduziKnjigu(){
    budalacita=nullptr;
}
bool Knjiga::DaLiJeZaduzena() const {
    return budalacita!=nullptr;
}


class Biblioteka{
    std::map<int, std::shared_ptr<Korisnik>> mapakorisnika;
    std::map<int, std::shared_ptr<Knjiga>> mapaknjiga;
    bool dalisuisti(Korisnik konj, Korisnik koza){
        if(konj.ime!=koza.ime || konj.prezime!=koza.prezime || konj.adresa!=koza.adresa || konj.telefon!=koza.telefon) return false;
        else return true;
    }
    
public:
    Biblioteka()=default;
    
    Biblioteka(const Biblioteka &biblio){
        for(auto p=biblio.mapakorisnika.begin();p!=biblio.mapakorisnika.end();p++){
            mapakorisnika[p->first]=std::shared_ptr<Korisnik>(new Korisnik{p->second->ime,p->second->prezime, p->second->adresa, p->second->telefon});
        }
        
        for(auto p=biblio.mapaknjiga.begin();p!=biblio.mapaknjiga.end();p++){
            mapaknjiga[p->first]=std::shared_ptr<Knjiga>(new Knjiga(p->second->DajNaslov(), p->second->DajAutora(), p->second->DajZanr(), p->second->DajGodinuIzdavanja()));
            if(p->second->DajKodKogaJe()!=nullptr){
            Korisnik dajdatenadem= *(p->second->DajKodKogaJe());
            for(auto it=mapakorisnika.begin();it!=mapakorisnika.end();it++){
                if(dalisuisti(*(it->second),dajdatenadem)==true){
                    mapaknjiga[p->first]->ZaduziKnjigu(*it->second);
                    break;
                    }
                }
            }
        }
    }
    
    Biblioteka(Biblioteka &&biblio){
        mapakorisnika=biblio.mapakorisnika;
        mapaknjiga=biblio.mapaknjiga;
        for(auto it=biblio.mapaknjiga.begin();it!=biblio.mapaknjiga.end();it++) it->second=nullptr;
        for(auto it=biblio.mapakorisnika.begin();it!=biblio.mapakorisnika.end();it++) it->second=nullptr;
    }
    
    Biblioteka &operator =(const Biblioteka &biblio){
        if(&biblio!=this){
            for(auto p=mapaknjiga.begin();p!=mapaknjiga.end();p++) p->second=nullptr;
            for(auto p=mapakorisnika.begin();p!=mapakorisnika.end();p++) p->second=nullptr;
            
            for(auto p=biblio.mapakorisnika.begin();p!=biblio.mapakorisnika.end();p++){
                mapakorisnika[p->first]=std::shared_ptr<Korisnik>(new Korisnik{p->second->ime, p->second->prezime, p->second->adresa, p->second->telefon});
            }
        
        for(auto p=biblio.mapaknjiga.begin();p!=biblio.mapaknjiga.end();p++){
            mapaknjiga[p->first]=std::shared_ptr<Knjiga>(new Knjiga(p->second->DajNaslov(), p->second->DajAutora(), p->second->DajZanr(), p->second->DajGodinuIzdavanja()));
            if(p->second->DajKodKogaJe()!=nullptr){
            Korisnik dajdatenadem= *(p->second->DajKodKogaJe());
            for(auto it=mapakorisnika.begin();it!=mapakorisnika.end();it++){
                if(dalisuisti(*(it->second),dajdatenadem)==true){
                    mapaknjiga[p->first]->ZaduziKnjigu(*it->second);
                    break;
                }
            }
        }
        }
        }
    return *this;
}
    
    Biblioteka &operator =(Biblioteka &&biblio){
        if(&biblio!=this){
            for(auto p=mapaknjiga.begin();p!=mapaknjiga.end();p++) p->second=nullptr;
            for(auto p=mapakorisnika.begin();p!=mapakorisnika.end();p++) p->second=nullptr;
            mapakorisnika=biblio.mapakorisnika;
            mapaknjiga=biblio.mapaknjiga;
            for(auto it=biblio.mapaknjiga.begin();it!=biblio.mapaknjiga.end();it++) it->second=nullptr;
            for(auto it=biblio.mapakorisnika.begin();it!=biblio.mapakorisnika.end();it++) it->second=nullptr;
        }
        
        return *this;
    }
    //ides mi na zivce 
    //daBog da proradio
    ~Biblioteka(){
        for(auto it=mapaknjiga.begin();it!=mapaknjiga.end();it++){
            it->second=nullptr;
        }
        for(auto it=mapakorisnika.begin();it!=mapakorisnika.end();it++){
            it->second=nullptr;
        }
        mapaknjiga.clear();
        mapakorisnika.clear();
    }
    
    void RegistrirajNovogKorisnika(int clanskibr, std::string ime, std::string prezime, std::string adresa, std::string telefon){
    
    if(!mapakorisnika.count(clanskibr)){
        std::shared_ptr<Korisnik> p=std::shared_ptr<Korisnik>(new Korisnik{ime, prezime, adresa, telefon});
        mapakorisnika.insert(std::make_pair(clanskibr,p));
    }
    else throw std::logic_error("Korisnik vec postoji");
}
    
    void RegistrirajNovuKnjigu(int evidbroj, std::string nas, std::string pis, std::string tip, int godina);
    Korisnik &NadjiKorisnika(int clanskibr);
    Knjiga &NadjiKnjigu(int evidbroj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidbroj, int clanskibr);
    void RazduziKnjigu(int evidbroj);
    void PrikaziZaduzenja(int clanskibr) const;
};



int main ()
{
//AT1 (c9): testira da li je Korisnik struktura

Korisnik k1 { "Niko", "Nikic", "Zmaja od Bosne bb", "123 456"};
std::cout << k1.ime << " " << k1.prezime << " " << k1.adresa << " " << k1.telefon;
std::cout <<  std::endl;
Knjiga knj1("Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
std::cout << knj1.DajNaslov() << " " << knj1.DajAutora() << " " << knj1.DajZanr() << " " << knj1.DajGodinuIzdavanja();
if(!knj1.DaLiJeZaduzena()) std::cout << "\nKnjiga je slobodna";
else std::cout << "\nKnjiga je zaduzena";
std::cout <<  std::endl;

Korisnik k2 { "Niko", "Nikic", "Zmaja od Bosne bb", "123 456"};
Knjiga knj2("Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
knj2.ZaduziKnjigu(k2);
if(!knj2.DaLiJeZaduzena()) std::cout << "Knjiga je slobodna";
else std::cout << "Knjiga je zaduzena";
knj2.RazduziKnjigu();
if(!knj2.DaLiJeZaduzena()) std::cout << "\nKnjiga je slobodna";
else std::cout << "\nKnjiga je zaduzena";

std::cout <<  std::endl;

//AT4 (c9): testira DajKodKogaJe metodu

Korisnik kor{"Meho", "Mehic", "Dobojska 15", "033/123-456"};
Knjiga knj("Tvrdjava", "Mesa Selimovic", "Roman", 1965);
if(knj.DajKodKogaJe() == nullptr) std::cout << "Nije zaduzena\n";
std::cout << knj.DaLiJeZaduzena() << std::endl;
knj.ZaduziKnjigu(kor);
std::cout << "Knjigu je zaduzio " << knj.DajKodKogaJe()->ime << std::endl;
std::cout << knj.DaLiJeZaduzena() << std::endl;
std::cout <<  std::endl;
Biblioteka bib5;
bib5.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib5.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
std::cout << bib5.NadjiKnjigu(2).DajNaslov();
std::cout <<  std::endl;

//AT6 (c9): testira metodu NadjiKorisnika

Biblioteka bib6;
bib6.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib6.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
std::cout << bib6.NadjiKorisnika(1).ime;
std::cout << std::endl;
std::cout << std::endl;
  //AT9 (c9): testira IzlistajKnjige sa zaduzenim knjigama
  std::cout <<  std::endl;
  std::cout <<  std::endl;
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
b.IzlistajKorisnike();
std::cout <<  std::endl;
  std::cout <<  std::endl;
Biblioteka bib8;
bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
bib8.ZaduziKnjigu(2, 1);
bib8.IzlistajKnjige();

Biblioteka b1(bib8);
Biblioteka b2(std::move(bib8));
//Biblioteka b2;
b2=b1;
Biblioteka b3;
b3=std::move(bib8);

	return 0;
}

void Biblioteka::RegistrirajNovuKnjigu(int evidbroj, std::string nas, std::string pis, std::string tip, int godina){
    if(!mapaknjiga.count(evidbroj)){
    std::shared_ptr<Knjiga> p=std::shared_ptr<Knjiga>(new Knjiga(nas, pis, tip, godina));    
    mapaknjiga.insert(std::make_pair(evidbroj, p));
    }
    else throw std::logic_error("Knjiga vec postoji");
}

Korisnik &Biblioteka::NadjiKorisnika(int clanskibr){
    auto it(mapakorisnika.find(clanskibr));
    if(it==mapakorisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    else return *(it->second);
}

Knjiga &Biblioteka::NadjiKnjigu(int evidbroj){
    auto it(mapaknjiga.find(evidbroj));
    if(it==mapaknjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    else return *(it->second);
}

void Biblioteka::IzlistajKorisnike() const {
    for(auto it=mapakorisnika.begin();it!=mapakorisnika.end();it++) {
        std::cout<<"Clanski broj: "<< it->first<<std::endl<<"Ime i prezime: "<< (it->second)->ime<<" "<< (it->second)->prezime<<std::endl<<"Adresa: "<<(it->second)->adresa<<std::endl<<"Broj telefona: "<< (it->second)->telefon<<std::endl;
        std::cout <<  std::endl;
    }
}

void Biblioteka::IzlistajKnjige() const {
    for(auto it=mapaknjiga.begin();it!=mapaknjiga.end();it++){
        std::cout<<"Evidencijski broj: "<< it->first<<std::endl<<"Naslov: "<< (it->second)->DajNaslov()<<std::endl<<"Pisac: "<<(it->second)->DajAutora()<<std::endl<<"Zanr: "<< (it->second)->DajZanr()<<std::endl<<"Godina izdavanja: "<<
        (it->second)->DajGodinuIzdavanja()<<std::endl;
        if((it->second)->DaLiJeZaduzena()) std::cout<<"Zaduzena kod korisnika: "<< ((it->second)->DajKodKogaJe())->ime<<" "<<((it->second)->DajKodKogaJe())->prezime<<std::endl;
        std::cout<<std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int evidbroj, int clanskibr){
    if(!mapaknjiga.count(evidbroj)) throw std::logic_error("Knjiga nije nadjena: ");
    if(!mapakorisnika.count(clanskibr)) throw std::logic_error("Korisnik nije nadjen"); 
    auto it(mapaknjiga.find(evidbroj));
    if(it->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    auto pok(mapakorisnika.find(clanskibr));
    it->second->ZaduziKnjigu(*(pok->second));
}

void Biblioteka::RazduziKnjigu(int evidbroj){
    if(!mapaknjiga.count(evidbroj)) throw std::logic_error("Knjiga nije nadjena");
    auto it(mapaknjiga.find(evidbroj));
    if(!(it->second->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
    else it->second->RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int clanskibr) const {
    if(!mapakorisnika.count(clanskibr)) throw std::logic_error("Korisnik nije nadjen");
    std::string i,pr, a,t;
    auto it(mapakorisnika.find(clanskibr));
    i=it->second->ime;
    pr=it->second->prezime;
    a=it->second->adresa;
    t=it->second->telefon;
    int br(0);
        for(auto p(mapaknjiga.begin());p!=mapaknjiga.end();p++){
            bool seke=true;
            if(p->second->DajKodKogaJe()==nullptr) continue;
            if(p->second->DajKodKogaJe()->ime!=i || p->second->DajKodKogaJe()->prezime!=pr || p->second->DajKodKogaJe()->adresa!=a || p->second->DajKodKogaJe()->telefon!=t) seke=false;
            if(seke==true){
                br++;
                std::cout<<"Evidencijski broj: "<< it->first<<std::endl<<"Naslov: "<< (p->second)->DajNaslov()<<std::endl<<"Pisac: "<<(p->second)->DajAutora()<<std::endl<<"Zanr: "<< (p->second)->DajZanr()<<std::endl<<"Godina izdavanja: "<<
        (p->second)->DajGodinuIzdavanja()<<std::endl;
            }
            
        }
    
    if(br==0) std::cout<<"Nema zaduzenja za tog korisnika!";
}