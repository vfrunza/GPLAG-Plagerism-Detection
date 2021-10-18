/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <new>
#include <stdexcept>
#include <iomanip>
#include <cstring>
#include <new>
#include <memory>
using std::string;
using std::cin;
using std::cout;
using std::endl;

struct Korisnik{
    
    string ime, prezime,adresa,telefon;
};

class Knjiga{ 
    const string nasl,imep,zanr;
    const int godina;
    Korisnik *zaduzen;
   
    public:

    Knjiga(string n={},string i={},string z={}, int g=0) : nasl(n),imep(i),zanr(z), godina(g), zaduzen(nullptr){}
    string DajNaslov() const {
        return nasl;
    }
    
    string DajAutora()const{
        return imep;
    }
    string DajZanr() const{
        return zanr;
    }
    int DajGodinuIzdavanja()const{
        return godina;
    }
    Korisnik* DajKodKogaJe() const {
        return zaduzen;
    }
    void ZaduziKnjigu(Korisnik &a){
        zaduzen=&a;
    }
    void RazduziKnjigu(){
        zaduzen=nullptr;
    }
    bool DaLiJeZaduzena()const{
        return zaduzen!=nullptr;
    }
  
};


class Biblioteka{
    std::map<int,std::shared_ptr<Knjiga>> kn;
    std::map<int,std::shared_ptr<Korisnik>>ko;
    public:
    Biblioteka(){}
    
    bool ProvjeriClanskiBroj(int clb)const{
        if(ko.find(clb)!=ko.end()) return true;
        return false;
    }
    bool ProvjeriClanskiBroj1(int clb)const{
        return ko.find(clb)==ko.end();
        
    }
    bool ProvjeriEvidenciskiBroj(int clb)const{
        if(kn.find(clb)!=kn.end()) return true;
        return false;
    }
    bool ProvjeriEvidenciskiBroj1(int clb)const{
        return kn.find(clb)==kn.end();
        
        
    }
    bool ProvjeriEvidenciskiBroj2(int clb)const{
          auto it(kn.find(clb));
          return it->second->DaLiJeZaduzena();
    }
    void RegistrirajNovogKorisnika(int clbroj,string ime,string prezime,string adresa,string brojtel){
        if(ProvjeriClanskiBroj(clbroj)) throw std::logic_error("Korisnik vec postoji");
        Korisnik kor;
        kor.ime=ime;kor.prezime=prezime;kor.adresa=adresa;kor.telefon=brojtel;
        ko.insert(std::make_pair(clbroj,std::make_shared<Korisnik>(Korisnik(kor))));
       
    }
    void RegistrirajNovuKnjigu(int evbroj,string naslov,string pisac,string zanr,int god){
        if(ProvjeriEvidenciskiBroj(evbroj)) throw std::logic_error("Knjiga vec postoji");
        Knjiga a(naslov,pisac,zanr,god);
        kn.insert(std::make_pair(evbroj,std::make_shared<Knjiga>(a)));
    }
    Korisnik& NadjiKorisnika(int clanski)const{
        auto it(ko.find(clanski));
        if(it==ko.end()) throw std::logic_error("Korisnik nije nadjen");
        return *(it->second);
    }
    Knjiga& NadjiKnjigu(int evbroj)const{
        auto it(kn.find(evbroj));
        if(it==kn.end()) throw std::logic_error("Knjiga nije nadjena");
        return *(it->second);
        
    }
    void IzlistajKorisnike()const{
        for(auto i(ko.begin());i!=ko.end();i++){
        cout <<endl;
        cout << "Clanski broj: " <<i->first;
        cout << "\nIme i prezime: " <<i->second->ime<<" "<<i->second->prezime;
        cout << "\nAdresa: " <<i->second->adresa;
        cout << "\nBroj telefona: " <<i->second->telefon<< endl;
        
    }}
    void IzlistajKnjige()const{
        for(auto i(kn.begin());i!=kn.end();i++){
        cout <<endl;
        cout << "Evidencijski broj: " <<i->first;
        cout << "\nNaslov: " <<i->second-> DajNaslov();
        cout << "\nPisac: " <<i->second->DajAutora();
        cout << "\nZanr: " <<i->second-> DajZanr(); 
        cout << "\nGodina izdavanja: " <<i->second->DajGodinuIzdavanja();
        if(i->second->DaLiJeZaduzena())
            cout<<"\nZaduzena kod korisnika: "<<i->second->DajKodKogaJe()->ime<<" "<<i->second->DajKodKogaJe()->prezime;
        cout<<endl;
    }}
    void ZaduziKnjigu(int evbroj,int clbroj){
        if(ProvjeriEvidenciskiBroj1(evbroj)) throw std::logic_error("Knjiga nije nadjena");
        if(ProvjeriEvidenciskiBroj2(evbroj)) throw std::logic_error("Knjiga vec zaduzena");
        if(ProvjeriClanskiBroj1(clbroj)) throw std::logic_error("Korisnik nije nadjen");
        auto it1(kn.find(evbroj));
        auto it2(ko.find(clbroj));
        it1->second->ZaduziKnjigu(*(it2->second));
    }
    void RazduziKnjigu(int evbroj){
        if(ProvjeriEvidenciskiBroj1(evbroj)) throw std::logic_error("Knjiga nije nadjena");
        if(!(ProvjeriEvidenciskiBroj2(evbroj))) throw std::logic_error("Knjiga nije zaduzena");
        auto it1(kn.find(evbroj));
        it1->second->Knjiga::RazduziKnjigu();
    }
    void PrikaziZaduzenja(int clbroj)const{
        if(ProvjeriClanskiBroj1(clbroj)) throw std::logic_error("Korisnik nije nadjen");
        
        bool dal_je(false);
        
        auto it(ko.find(clbroj));
        string ime1(it->second->ime);
        for(auto it1(kn.begin());it1!=kn.end();it1++){
            if(it1->second->DaLiJeZaduzena()==true){
                if(it1->second->DajKodKogaJe()->ime==ime1){
                    cout << "Evidencijski broj: " <<it1->first;
                    cout << "\nNaslov: " <<it1->second-> DajNaslov();
                    cout << "\nPisac: " <<it1->second->DajAutora();
                    cout << "\nZanr: " <<it1->second-> DajZanr(); 
                    cout << "\nGodina izdavanja: " <<it1->second->DajGodinuIzdavanja()<<endl;
                    dal_je=true;
                }
            }
        }
        if(!dal_je) cout<<"Nema zaduzenja za tog korisnika!";
    }
};


int main ()
{
    Biblioteka b1;
    int n(10);
    while(n!=0){
        cout<<"Unesite komandu: "<<endl<<"1 - Za registraciju novog korisnika"<<endl<<"2 - Za registraciju nove knjige"<<endl<<"3 - Za izlistavanje svih njiga"<<endl;
        cout<<"4 - Za izlistavanje svih korisnika"<<endl<<"5 - Za zaduziti knjigu"<<endl<<"6 - Za razduziti knjigu"<<endl<<"7 - Za gledanje zaduzenja korisnika"<<endl;
        cout<<"0 - Za zavrsetak programa"<<endl;
        cin>>n;
   if(n==1){
        int clbroj;
        string ime,prezime,adresa,brojtel;
        cout<<"Clanski broj: ";
        cin>>clbroj;
        cout<<"Ime i prezime: ";
        cin.ignore(10000,'\n');
        cin>>ime;
        cin>>prezime;
        cout<<"Adresa: ";
        cin.ignore(10000,'\n');
        std::getline(cin,adresa);
        cout<<"Broj telefona: ";
        std::getline(cin,brojtel);
        try{
            b1.RegistrirajNovogKorisnika(clbroj,ime,prezime,adresa,brojtel);
        }catch(std::logic_error e){
            cout<<e.what()<<endl;
        }
    }
    else if(n==2){
        int evbroj;
        string naslov,pisac,zanr;
        cout<<"Evidencijski broj: ";
        cin>>evbroj;
        cout<<"Naslov: ";
        cin.ignore(10000,'\n');
        cin>>naslov;
        cout<<"Pisac: ";
        cin.ignore(10000,'\n');
        std::getline(cin,pisac);
        cout<<"Zanr: ";
        std::getline(cin,zanr);
        cout<<endl;
        cout<<"Godina izdavanja: ";
        int god;
        cin>>god;
        try{
           b1.RegistrirajNovuKnjigu(evbroj,naslov,pisac,zanr,god); 
        }catch(std::logic_error e){
        cout<<e.what()<<endl;
        }
    }
    else if(n==3){
        b1.IzlistajKnjige();
    }else if(n==4){
        b1.IzlistajKorisnike();
    }else if(n==5){
        cout<<"Unesite evidenciski broj knjige koj zelite zaduziti: ";
        int ev;
        cin>>ev;
        cout<<"Unesite clanski broj korisnika koji zaduzuje knjigu: ";
        int cb;
        cin>>cb;
        try{
            b1.ZaduziKnjigu(ev,cb);
        }catch(std::logic_error e){
        cout<<e.what()<<endl;
        }
    }
    else if(n==6){
        cout<<"Unesite evidenciski broj knjige koju zelite razduziti: ";
        int ev;
        cin>>ev;
        try{
            b1.RazduziKnjigu(ev);
        }catch(std::logic_error e){
        cout<<e.what()<<endl;
        }
    }else if(n==7){
      cout<<"Unesite clanski broj korisnika cija zaduzenja zelite pogledati: ";
      int cb;
      cin>>cb;
      try{
         b1.PrikaziZaduzenja(cb); 
      }catch(std::logic_error e){
        cout<<e.what()<<endl;
    }
    }else if(n==0) break;
    }
	return 0;
}