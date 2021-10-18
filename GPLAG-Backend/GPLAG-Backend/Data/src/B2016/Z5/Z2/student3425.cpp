#include <utility>
#include <stdexcept>
#include <iostream>
#include <map>
#include <memory>
#include <string>
struct Korisnik{
    std::string ime,prezime,adresa,telefon;
   friend class Knjiga;
   friend class Biblioteka;
};
class Knjiga{
  std::string naslov,zanr,autor;
  int izdana;
   Korisnik* zaduzena;
  public:
  Knjiga(std::string n,std::string pisac,std::string z,int g):naslov(n),zanr(z),autor(pisac),izdana(g) {zaduzena=nullptr; }
  std::string DajNaslov() const { return naslov; }
  std::string DajAutora() const { return autor; }
  std::string DajZanr() const { return zanr; }
  int DajGodinuIzdavanja() const { return izdana; }
  Korisnik* DajKodKogaJe() const { return zaduzena; }
  void ZaduziKnjigu(Korisnik &k){
      zaduzena=&k;
  }
  void RazduziKnjigu() {
      zaduzena=nullptr;
  }
  bool DaLiJeZaduzena(){
      if(this->zaduzena==nullptr)
      return false;
      return true;
  }
  friend class Biblioteka;
};
class Biblioteka{
    std::map<int,std::shared_ptr<Korisnik>> clanovi;
    std::map<int,std::shared_ptr<Knjiga>>    knjige;
    public:
    Biblioteka()=default;
    Biblioteka(const Biblioteka &b){
        for(auto p(b.clanovi.begin());p!=b.clanovi.end();p++){
            std::shared_ptr<Korisnik> k=std::make_shared<Korisnik>();
            k->ime=p->second->ime;
            k->prezime=p->second->prezime;
            k->adresa=p->second->adresa;
            k->telefon=p->second->telefon;
            clanovi.insert(std::make_pair(p->first,k));
        }
        for(auto p(b.knjige.begin());p!=b.knjige.end();p++){
            std::shared_ptr<Knjiga> k=std::make_shared<Knjiga>(p->second->naslov,p->second->autor,p->second->zanr,p->second->izdana);
            knjige.insert(std::make_pair(p->first,k));
        }
    }
    Biblioteka &operator=(Biblioteka b){
         for(auto p(b.clanovi.begin());p!=b.clanovi.end();p++){
            std::shared_ptr<Korisnik> k=std::make_shared<Korisnik>();
            k->ime=p->second->ime;
            k->prezime=p->second->prezime;
            k->adresa=p->second->adresa;
            k->telefon=p->second->telefon;
            clanovi.insert(std::make_pair(p->first,k));
        }
        for(auto p(b.knjige.begin());p!=b.knjige.end();p++){
            std::shared_ptr<Knjiga> k=std::make_shared<Knjiga>(p->second->naslov,p->second->autor,p->second->zanr,p->second->izdana);
            knjige.insert(std::make_pair(p->first,k));
        }
        return *this;
    }
    void RegistrirajNovogKorisnika(int br,std::string ki,std::string kp,std::string ka,std::string kb){
        auto trazi(clanovi.find(br));
        if(trazi!=clanovi.end())
        throw std::logic_error("Korisnik vec postoji!");
        std::shared_ptr<Korisnik> k= std::make_shared<Korisnik> ();
        k->ime=ki;
        k->prezime=kp;
        k->adresa=ka;
        k->telefon=kb;
        clanovi.insert(std::make_pair(br,k));
    }
    void RegistrirajNovuKnjigu(int br,std::string imee,std::string pisa,std::string znr,int godin){
        auto trazi(knjige.find(br));
        if(trazi!=knjige.end())
        throw std::logic_error("Knjiga vec postoji");
        auto k=std::make_shared<Knjiga>(imee,pisa,znr,godin);
        knjige.insert(std::make_pair(br,k));
    }
    Korisnik &NadjiKorisnika(int br){
        auto trazi(clanovi.find(br));
        if(trazi==clanovi.end())
        throw std::logic_error("Korisnik nije nadjen");
        return *(trazi->second);
    }
    Knjiga &NadjiKnjigu(int br){
        auto trazi(knjige.find(br));
        if(trazi==knjige.end())
        throw std::logic_error("Korisnik nije nadjen");
        return *(trazi->second);
    }
    void IzlistajKorisnike() const{
        for(auto p=clanovi.begin();p!=clanovi.end();p++){
            std::cout <<"Clanski broj: " <<p->first << std::endl;
            std::cout <<"Ime i prezime: " <<p->second->ime<<" ";
            std::cout << p->second->prezime << std::endl;
            std::cout <<"Adresa: "<< p->second->adresa << std::endl;
            std::cout <<"Broj telefona: " <<p->second->telefon << std::endl;
            std::cout  << std::endl;
        }
    }
    void IzlistajKnjige() const{
        for(auto p=knjige.begin();p!=knjige.end();p++){
            std::cout <<"Evidencijski broj: " <<p->first<< std::endl;
            std::cout <<"Naslov: " <<p->second->naslov<<std::endl;
            std::cout <<"Pisac: "<<p->second->autor << std::endl;
            std::cout <<"Zanr: " <<p->second->zanr << std::endl;
            std::cout <<"Godina izdavanja: "<< p->second->izdana << std::endl;
            if(p->second->zaduzena!=nullptr)
            std::cout << "Zaduzena kod korisnika: " <<p->second->zaduzena->ime<<" "<<p->second->zaduzena->prezime <<std::endl;
            std::cout  << std::endl;
        }
    }
    void ZaduziKnjigu(int knjiga,int korisnik){
        auto p(knjige.find(knjiga));
        auto s(clanovi.find(korisnik));
        if(p==knjige.end())
        throw std::logic_error("Knjiga nije nadjena!");
        if( s==clanovi.end() )
        throw std::logic_error("Korisnik nije nadjen");
        if(p->second->zaduzena!=nullptr)
        throw std::logic_error("Knjiga je vec zaduzena");
        p->second->zaduzena=s->second.get();
    }
    void RazduziKnjigu(int br){
        auto p(knjige.find(br));
        if(p==knjige.end())
        throw std::logic_error("Knjiga nije nadjena");
        if(p->second->zaduzena==nullptr)
        throw std::logic_error("Knjiga nije zaduzena");
        p->second->zaduzena=nullptr;
    }
    void PrikaziZaduzenja(int br){
        auto p(clanovi.find(br));
        for(auto pok(knjige.begin());pok!=knjige.end();pok++){
            if(pok->second->zaduzena==p->second.get()){
            std::cout <<"Evidencijski broj: " <<pok->first<< std::endl;
            std::cout <<"Naslov: " <<pok->second->naslov<<std::endl;
            std::cout <<"Pisac: "<<pok->second->autor << std::endl;
            std::cout <<"Zanr: " <<pok->second->zanr << std::endl;
            std::cout <<"Godina izdavanja: "<< pok->second->izdana << std::endl;
            std::cout  << std::endl;
            }
            
        }
    }
    
};
int main(){
    int br(1),hh(17);
    Biblioteka b;
      b.RegistrirajNovuKnjigu(1,"Harry Potter","J.K.Rowling","Roman",1997);
      b.RegistrirajNovuKnjigu(2,"Tvrdjava","Mesa Selimovic","Roman",1970);
      b.RegistrirajNovuKnjigu(3,"Prokleta avlija","Ivo Andric","Roman",1954);
      b.RegistrirajNovuKnjigu(4,"Gorski vijenac","P.P. Njegos","Poezija",1845);
      b.RegistrirajNovuKnjigu(5,"Crveno i crno","Stendal","Novela",1830);
      b.RegistrirajNovuKnjigu(6,"Bijeli ocnjak","Dzek London","Roman",1932);
      b.RegistrirajNovuKnjigu(7,"Dervis i smrt","Mesa Selimovic","Roman",1965);
      b.RegistrirajNovuKnjigu(8,"20000 milja ispod mora","Zil Vern","Roman",1800);
      b.RegistrirajNovuKnjigu(9,"100 godina samoce","G.G. Markez ","Psiholoski roman",1991);
      b.RegistrirajNovuKnjigu(10,"Jezeva kucica","Branko Copic","Bajke",1949);
      b.RegistrirajNovuKnjigu(11,"Jazavac pred sudom","Petar Kocic","Roman",1903);
      b.RegistrirajNovuKnjigu(12,"Spijuni su presli granicu","Djordje Licina","Roman",1972);
      b.RegistrirajNovuKnjigu(13,"Ana Karenjina","Lav Tolstoj","Roman",1877);
      b.RegistrirajNovuKnjigu(14,"Zlocin i kazna","F.Dostojevski","Roman",1932);
      b.RegistrirajNovuKnjigu(15,"Lovac u zitu","Selindzer","Roman",1932);
      b.RegistrirajNovuKnjigu(16,"Stepski vuk","Herman Hese","Roman",1927);
      std::cout << "Dobro dosli u biblioteku, izaberite opciju: " << std::endl;
       std::cout << "Uclaniti se u biblioteku...(1)"<< std::endl;
          std::cout << "Izlistati koje knjige imate na raspolaganju...(2)"<< std::endl;
          std::cout << "Zaduzenje knjige...(3)"<< std::endl;
          std::cout << "Povrat knjige...(4)"<< std::endl;
          std::cout << "Ukoliko zelite donirati knjigu...(5)"<< std::endl;
           std::cout << "Izlaz...(0)"<< std::endl;
      for(;;){
         
          int n; std::cin >> n;
          std::cin.clear();
          std::cin.ignore(10000,'\n');
          if(n==1){
              std::string ime,prezime,adresa,telefon;
              std::cout << "Unesite ime: " << std::endl;
              std::getline(std::cin,ime);
              std::cout << "Unesite prezime: " << std::endl;
              std::getline(std::cin,prezime);
              std::cout << "Unesite adresu: " << std::endl;
              std::getline(std::cin,adresa);
              std::cout << "Unesite broj telefona: " << std::endl;
              std::getline(std::cin,telefon);
              b.RegistrirajNovogKorisnika(br,ime,prezime,adresa,telefon);
              br++;
              std::cout << "Uclanili ste se, vas clanski broj je "<<br-1<<"."<< std::endl;
          }
          if(n==2)
          b.IzlistajKnjige();
          if(n==3){
          Ponovo:
          std::cout << "Unesite svoj id: " << std::endl;
          int id; std::cin >>  id;
          std::cout << "Unesite id knjige: " << std::endl;
          int ik; std::cin>> ik;
          try{
          b.ZaduziKnjigu(ik,id);
          }
          catch(...){
              std::cout << "Podaci nisu u redu,ponovite: " << std::endl;
              goto Ponovo;
          }
          std::cout << "Iznajmili ste: "<<b.NadjiKnjigu(ik).DajNaslov()<< std::endl;
          }
          if(n==4){
              std::cout << "Koju knjigu zelite razduziti: " << std::endl;
              int k; std::cin >>  k;
              b.RazduziKnjigu(k);
          }
          if(n==5){
              std::cout << "Unesite naslov,pisca,zanr i godinu izdanja(ENTER poslije svakog unosa): " << std::endl;
              std::string naslov,pisac,zanr;
              int godina;
              std::getline(std::cin,naslov);
               std::getline(std::cin,pisac);
                std::getline(std::cin,zanr);
                std::cin >> godina;
                std::cin.clear();
          std::cin.ignore(10000,'\n');
          b.RegistrirajNovuKnjigu(hh,naslov,pisac,zanr,godina);
          hh++;
          std::cout << "Hvala" << std::endl;
          }
     if(n==0)
     break;
     std::cout << "Izaberite neku drugu opciju ili 0 za izlaz!" << std::endl;
}
std::cout << "Dovidjenja!" << std::endl;
return 0;
}