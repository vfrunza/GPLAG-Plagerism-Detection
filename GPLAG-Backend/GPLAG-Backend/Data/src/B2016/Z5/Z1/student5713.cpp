/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <map>

using namespace std;

struct Korisnik{
    string ime, prezime, adresa, telefon;
    void IspisiKorisnika()const{
        cout<<"Ime i prezime: "<<ime<<" "<<prezime<<endl<<"Adresa: "<<adresa<<endl<<"Broj telefona: "<<telefon<<endl;
    }
    
    Korisnik (string imee, string prezimee, string adresaa, string telefonn)
    :ime(imee), prezime(prezimee), adresa(adresaa), telefon(telefonn)
    {}
};

class Knjiga {
    string naslov_knjige, pisac, zanr;
    int godina_izdavanja;
    Korisnik *zaduzivanje;
    
    public:
    Knjiga(string naslov, string pisac_k, string zanr_k, int godina):
    naslov_knjige(naslov), pisac(pisac_k), zanr(zanr_k), godina_izdavanja(godina), zaduzivanje(nullptr){}
    //u konstr listi mora ici mala zagrada ne moze znak jednakosti =
    string DajNaslov()const{
        return naslov_knjige;
    }
    string DajAutora()const{return pisac;
}
string DajZanr()const{return zanr;}
int DajGodinuIzdavanja()const{return godina_izdavanja;}

 Korisnik * DajKodKogaJe()const{
      return zaduzivanje;
  }
   
   void ZaduziKnjigu(Korisnik & neko){
       zaduzivanje=&neko;
   }
     void RazduziKnjigu(){
       zaduzivanje=nullptr;
   }
   
  bool DaLiJeZaduzena()const{
       return zaduzivanje!=nullptr;
   }
   
   void IspisiKnjigu()const{
        cout<<"Naslov: "<<naslov_knjige<<endl<<"Pisac: "<<pisac<<endl<<"Zanr: "<<zanr<<endl<<"Godina izdavanja: "<<godina_izdavanja<<endl;
    }
   
};

class Biblioteka{
    map<int, Korisnik *> mapa_korisnika;
    map<int, Knjiga *> mapa_knjiga;
    int clan_broj_korisnik, ev_br_knjige;
    
    public:
    Biblioteka(map<int, Korisnik*> korisnici, map<int, Knjiga *> knjige, int clanski_br, int ev_br):
    mapa_korisnika(korisnici), mapa_knjiga(knjige), clan_broj_korisnik(clanski_br), ev_br_knjige(ev_br){}
    Biblioteka()=default;
    ~Biblioteka(){
        for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++){
            //mapa_korisnika[i].second=nullptr;
            delete it->second;
        }
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
            //mapa_knjiga[i].second=nullptr;
            delete it->second;
        }
    }
    Biblioteka (const Biblioteka & neka)=default;
   Biblioteka & operator = ( Biblioteka druga){
        (*this).mapa_korisnika=druga.mapa_korisnika;
        (*this).mapa_knjiga=druga.mapa_knjiga;
        (*this).clan_broj_korisnik=druga.clan_broj_korisnik;
        (*this).ev_br_knjige=druga.ev_br_knjige;
        return *this;
    }
    void RegistrirajNovogKorisnika(int cl_br, string imee, string prezimee, string adresaa, string telefonn){
        auto it=mapa_korisnika.begin();
   //    if(( it=mapa_korisnika.find(cl_br))==mapa_korisnika.end()) throw logic_error("Korisnik vec postoji");
        
        mapa_korisnika.insert(make_pair(cl_br, (new Korisnik(imee, prezimee, adresaa, telefonn))));
        //mapa_korisnika.first=cl_br;
    }
    
      void RegistrirajNovuKnjigu(int ev_br, string naslov, string pisac, string zanr, int godina){
        auto it=mapa_knjiga.begin();
       // if(( it=mapa_knjiga.find(ev_br))==mapa_knjiga.end()) throw logic_error("Knjiga vec postoji");
        
        mapa_knjiga.insert(make_pair(ev_br, (new Knjiga(naslov, pisac, zanr, godina))));
        //mapa_korisnika.first=cl_br;
    }
    
    Korisnik & NadjiKorisnika(int cl_br)const{
         auto it=mapa_korisnika.begin();
        
       if(( it=mapa_korisnika.find(cl_br))==mapa_korisnika.end()) throw
        logic_error("Korisnik nije nadjen");
it=mapa_korisnika.find(cl_br);
return *it->second;
    }
    
     Knjiga & NadjiKnjigu(int ev_br){
         auto it=mapa_knjiga.begin();
       if(( it=mapa_knjiga.find(ev_br))==mapa_knjiga.end()) throw logic_error("Knjiga nije nadjena");
it=mapa_knjiga.find(ev_br);
return *(it->second);
    }
    
    void IzlistajKorisnike()const{
        for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++){
           cout<<"Clanski broj: "<<(*it).first<<endl;
           (*it->second).IspisiKorisnika();
            cout<<endl;
        }
        
    }
    
      void IzlistajKnjige()const{
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
            cout<<"Evidencijski broj: "<<(*it).first<<endl;
            (*it->second).IspisiKnjigu();
            if((*it->second).DaLiJeZaduzena())
            cout<<"Zaduzena kod korisnika: "<<(*(*(*it).second).DajKodKogaJe()).ime<<" "<<(*(*(*it).second).DajKodKogaJe()).prezime;
        
            cout<<endl;
        }
        
    }
    
    void ZaduziKnjigu(int ev_br, int cl_br){
        int testna=0, testna2=0, testna3=1;
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
        if((*it).first==ev_br) {
            testna=1;
            for(auto i=mapa_korisnika.begin(); i!=mapa_korisnika.end(); i++){
                if((*i).first==cl_br) {
                    testna2=1;
                    if((*(*it).second).DaLiJeZaduzena()==1) testna3=0;
                    
                    else (*(*it).second).ZaduziKnjigu(*(*i).second);
                    break;
            }
            
        }
    }
    }
    if(testna==0) throw logic_error("Knjiga nije nadjena");
    if(testna2==0) throw logic_error("Korisnik nije nadjen");
    if(testna3==0) throw logic_error("Knjiga vec zaduzena");
    }
    
     void RazduziKnjigu(int ev_br){
        int testna=0, testna2=0;
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
        if((*it).first==ev_br) {
            testna=1;
            if((*(*it).second).DaLiJeZaduzena()==1) testna2=1;
            else (*(*it).second).RazduziKnjigu();
             
            }
            
        }
    
    
    if(testna==0) throw logic_error("Knjiga nije nadjena");
   if(testna2==0) throw logic_error("Knjiga nije zaduzena");
    }
    
    
    void PrikaziZaduzenja(int cl_br)const{
        string imee="";
        int brojac=0;
        int nasao=0;
         Korisnik *p;
       for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++){
           if((*it).first==cl_br) 
           {imee=(*(*it).second).ime; nasao=1;
            p=it->second;
               break;
               
           }
       }
       if(nasao==0) throw logic_error ("Korisnik nije nadjen");
      
       for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
          // if((*(*it).second).DaLiJeZaduzena())
          // if((*(*(*it).second).DajKodKogaJe()).ime==imee)
          if(p==it->second->DajKodKogaJe()){
              cout<<"Evidencijski broj: "<<(*it).first<<endl;
              
           brojac++;
           (*(*it).second).IspisiKnjigu();
       }}
       if(brojac==0) cout<<"Nema zaduzenja za tog korisnika!";
       
    }
    
    
    
    
    
    
    
    
    
};




int main ()
{
    Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
"Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
"Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
"Studenata etfovaca 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
b.PrikaziZaduzenja(1234);

    /*
    
    Biblioteka bib5, bib1;
bib5.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "444 000");
bib5.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 222);
bib1.RegistrirajNovogKorisnika(15, "medi", "daci", "Zmaja od Bosne bb", "123 456");
bib1.RegistrirajNovuKnjigu(22, "grgine pustolovine", "neki pisac", "Roman", 555);

std::cout << bib5.NadjiKnjigu(2).DajNaslov();
cout<<endl;
bib1.IzlistajKorisnike();
bib1=bib5;
bib1.IzlistajKorisnike();
bib5.IzlistajKnjige();
bib1.IzlistajKnjige();
bib5.RegistrirajNovuKnjigu(78, "prvojera", "Mheheh", "Roman", 22552);
bib1.ZaduziKnjigu(2, 1);

cout<<"provjera"<<endl;
bib1.PrikaziZaduzenja(1);cout<<endl;
bib5.PrikaziZaduzenja(1);
bib1.RazduziKnjigu(2);
cout<<"nakon razduzenja: ";
bib1.PrikaziZaduzenja(1);cout <<endl;
bib5.PrikaziZaduzenja(1);

//bib5.IzlistajKnjige();
//bib1.IzlistajKnjige();
*/
	return 0;
}