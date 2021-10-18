/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <stdexcept>

struct Korisnik {
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};
class Knjiga {
    std::string naslov;
    std::string autor;
    std::string zanr;
    int god;
    Korisnik * zaduzio;
    public:
    //konstruktor
    Knjiga (std::string n, std::string i, std::string z, int g): 
    naslov(n), autor(i), zanr(z), god(g), zaduzio(nullptr) {}
    //fje 
    std::string DajNaslov() const {return naslov;}
    std::string DajAutora() const {return autor;}
    std::string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja () const {return god;}
    Korisnik* DajKodKogaJe() const {return zaduzio;}
    void ZaduziKnjigu (Korisnik &osoba){ zaduzio=&osoba;}
    void RazduziKnjigu () {zaduzio=nullptr;} 
    bool DaLiJeZaduzena () const { if(!zaduzio) return false; else return true; }    
    //~Knjiga() {delete zaduzio;}
    
};

class Biblioteka {
    std::map<int, std::shared_ptr<Korisnik> > korisnici;
    std::map<int, std::shared_ptr<Knjiga>> knjige;
    public:
    Biblioteka() {}
    //kopirajuci konstruktor
    Biblioteka(const Biblioteka &bib) {
        for(auto it=(bib.korisnici).begin(); it!=(bib.korisnici).end(); it++){
            int cl_broj=it->first;
            auto p(std::make_shared<Korisnik>());
            p->ime=((it->second)->ime);
            p->prezime=((it->second)->prezime);
            p->adresa=((it->second)->adresa);
            p->telefon=((it->second)->telefon);
            korisnici.insert(std::make_pair(cl_broj,p));
        }
        for(auto it=(bib.knjige).begin(); it!=(bib.knjige).end(); it++){
            int ev_broj=it->first;
            auto k(std::make_shared<Knjiga>((*(it->second)).DajNaslov(), (*(it->second)).DajAutora(),
                                  (*(it->second)).DajZanr(), (*(it->second)).DajGodinuIzdavanja()));
            
            knjige.insert(std::make_pair(ev_broj,k));
        }
    }
    
    //pomjerajuci konstruktor
    Biblioteka(Biblioteka &&bib) {
       
        for(auto it=(bib.korisnici).begin(); it!=(bib.korisnici).end(); it++){
            korisnici.insert(std::make_pair(it->first, it->second));
            (it->second)=nullptr;
        }
        for(auto it=(bib.knjige).begin(); it!=(bib.knjige).end(); it++){
            knjige.insert(std::make_pair(it->first, it->second));
            (it->second)=nullptr;
        }
    }
    
    
    //preklopljeni operator dodjele
    Biblioteka &operator =(const Biblioteka &bib){
    std::map<int, std::shared_ptr<Korisnik>> korisnici_privremena;  //AKO NE USPIJU ALOKACIJE 
    std::map<int, std::shared_ptr<Knjiga>> knjige_privremena;

    for(auto it=(bib.korisnici).begin(); it!=(bib.korisnici).end(); it++){
            int cl_broj=it->first;
            auto p=std::make_shared<Korisnik>(Korisnik(*(it->second)));
            korisnici_privremena.insert(std::make_pair(cl_broj,p));
        }
        for(auto it=(bib.knjige).begin(); it!=(bib.knjige).end(); it++){
            int ev_broj=it->first;
            auto k(std::make_shared<Knjiga>((*(it->second)).DajNaslov(), (*(it->second)).DajAutora(),
                                  (*(it->second)).DajZanr(), (*(it->second)).DajGodinuIzdavanja()));
            
            knjige_privremena.insert(std::make_pair(ev_broj,k));
        }
        
        //isprazni mapu
        korisnici.clear();
        knjige.clear();
        for(auto it=(korisnici_privremena).begin(); it!=(korisnici_privremena).end(); it++){
           korisnici.insert(*it);
       }
        for(auto it=(knjige_privremena).begin(); it!=(knjige_privremena).end(); it++){
          knjige.insert(*it);
       }
       
       return *this;
}

//preklopljeni operator dodjele
 Biblioteka &operator =(Biblioteka &&bib){
     if(&bib!=this){
        korisnici.clear();
        knjige.clear();
        for(auto it=(bib.korisnici).begin(); it!=(bib.korisnici).end(); it++){
           korisnici.insert(*it);
       }
       for(auto it=(bib.knjige).begin(); it!=(bib.knjige).end(); it++){
          knjige.insert(*it);
       }
    }
    
    return *this;
}

    //fje
    void RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, 
    std::string adresa, std::string br_tel){
        bool ima(false);
        for( auto it=korisnici.begin(); it!=korisnici.end(); it++){
            if((it->first)==cl_broj) {ima=true; break;}
        }
        if(ima) throw std::logic_error ("Korisnik vec postoji");
        auto k(std::make_shared<Korisnik>());
        k->ime=ime; k->prezime=prezime; k->adresa=adresa; k->telefon=br_tel;
        korisnici.insert(std::make_pair(cl_broj,k));
    }
    
    void RegistrirajNovuKnjigu (int ev_br, std::string naslov, std::string pisac,
    std::string zanr, int god){
        bool ima (false);
        for(auto it=knjige.begin(); it!=knjige.end(); it++){
            if((it->first)==ev_br) {ima=true; break; }
        }
        if(ima) throw std::logic_error ("Knjiga vec postoji");
        knjige.insert(std::make_pair(ev_br, std::make_shared <Knjiga>(naslov, pisac, zanr, god)));
    }
    
    Korisnik & NadjiKorisnika (int cl_broj){
        auto it (korisnici.find(cl_broj));
        if(it==korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
        return (*(it->second));
    }
    
    Knjiga & NadjiKnjigu(int ev_broj)  {
        auto it(knjige.find(ev_broj));
        if(it==knjige.end()) throw std::logic_error ("Knjiga nije nadjena");
        return(*(it->second));
    }
    void IzlistajKorisnike() const {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
            std::cout<<"Clanski broj: "<<(it->first)<<std::endl;
            std::cout<<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<std::endl;
            std::cout<<"Adresa: "<<(it->second)->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<(it->second)->telefon<<std::endl<<std::endl;
        }
    }
    void IzlistajKnjige() const {
        for(auto it=knjige.begin(); it!=knjige.end(); it++){
            std::cout<<"Evidencijski broj: "<<(it->first)<<std::endl;
            std::cout<<"Naslov: "<<(it->second)->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<(it->second)->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<(it->second)->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl;
            if((it->second)->DaLiJeZaduzena()) {
                Korisnik * k( ((it->second)->DajKodKogaJe()) );
                std::cout<<"Zaduzena kod korisnika: "<<(*k).ime<<" "<<(*k). prezime<<std::endl<<std::endl;
            }
            std::cout<<std::endl;
        }
    }
    
    void ZaduziKnjigu(int ev_br /*knjiga*/, int cl_br/*korisnik*/ ){
        auto k(knjige.find(ev_br));
        if(k==knjige.end()) throw std::logic_error ("Knjiga nije nadjena");
        auto ko(korisnici.find(cl_br));
        if(ko==korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
        if(((k->second)->DajKodKogaJe())!=nullptr) throw std::logic_error ("Knjiga vec zaduzena");
        
        knjige[ev_br]->Knjiga::ZaduziKnjigu(*korisnici[cl_br]);
    }
    
    void RazduziKnjigu (int ev_br){
        auto k(knjige.find(ev_br));
        if(k==knjige.end()) throw std::logic_error ("Knjiga nije nadjena");
        if(((k->second)->DajKodKogaJe())==nullptr) throw std::logic_error ("Knjiga nije zaduzena");
        knjige[ev_br]->Knjiga::RazduziKnjigu();
    }
    
    void PrikaziZaduzenja (int cl_br) const {
        auto k(korisnici.find(cl_br)); //k je iterator na tog korisnika
        if(k==korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
        bool ima(false);
            for(auto it=knjige.begin(); it!=knjige.end(); it++){ //ide kroz knjige
            Korisnik Kor=((*(it->second)->DajKodKogaJe()));
            Korisnik Kor2=*(k->second);
                if(Kor.ime==Kor2.ime && Kor.prezime==Kor2.prezime && Kor.adresa==Kor2.adresa && Kor.telefon==Kor2.telefon) { //ako je knjiga zaduzena kod osobe k
                    ima=true;
                    std::cout<<(it->second)->DajNaslov(); //ispisuje naziv knjige
                }
            }
            if(!ima) throw std::logic_error ("Nema zaduzenja za tog korisnika!");
    }
        
    
    
    
};
int main (){
try {    
    Biblioteka bib6;
    bib6.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
    bib6.RegistrirajNovogKorisnika(1,"Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
}
catch(std::logic_error Izuzetak){
    std::cout<<Izuzetak.what()<<std::endl;
}    
try{
    Biblioteka bib6;
    bib6.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
    bib6.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
    std::cout << bib6.NadjiKorisnika(1).ime<<std::endl;
    
    Biblioteka bib8;
    bib8.RegistrirajNovogKorisnika(1, "Pero", "Periša", "Zmaja od Bosne bb", "123 444");
    bib8.RegistrirajNovogKorisnika(2, "Mirko", "Miki", "Čekaluša", "123 987");
    bib8.RegistrirajNovuKnjigu(1, "Pustolovine", "Mato Lovrak", "Roman2", 1941);
    bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
    bib8.RegistrirajNovuKnjigu(3, "A planine su odjekivale", "Khaled Hosseini", "Roman", 2012);
    bib8.RegistrirajNovuKnjigu(4, "Hiljadu čudesnih sunaca", "Khaled Hosseini", "Roman", 2007);
    bib8.ZaduziKnjigu(2, 1);
    bib8.ZaduziKnjigu(4, 2);
    bib8.IzlistajKnjige();
    std::cout<<"Nakon dodjele biblioteka: "<<std::endl;
    bib8=bib6;
    bib8.IzlistajKnjige();
    Biblioteka bib7(bib6);
    std::cout<<"Nova biblioteka: "<<std::endl;
    bib7.IzlistajKnjige();
} catch(std::logic_error Izuzetak){
    std::cout<<Izuzetak.what()<<std::endl;
}    
	return 0;
}