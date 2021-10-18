/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
struct Korisnik{
    std::string ime,prezime,adresa,telefon;
};

class Knjiga{
    std::string naslov,pisac,zanr;
    int godina;
    Korisnik *pok;
    public:
    Knjiga(std::string naslov,std::string pisac,std::string zanr,int godina);
    std::string DajNaslov() const{return naslov;}
    std::string DajAutora() const{return pisac;}
    std::string DajZanr() const{return zanr;}
    int DajGodinuIzdavanja() const{return godina;}
    Korisnik *DajKodKogaJe() const{return pok;}
    void ZaduziKnjigu(Korisnik &x){pok=&x;}
    void RazduziKnjigu(){pok=nullptr;}
    bool DaLiJeZaduzena() {if(pok!=nullptr) return true; return false;}
};
Knjiga::Knjiga(std::string naslov,std::string pisac,std::string zanr,int godina){
    this->naslov=naslov;
    this->pisac=pisac;
    this->zanr=zanr;
    this->godina=godina;
    pok=nullptr;
}
class Biblioteka{
    std::map<int, Korisnik*> korisnik;
    std::map<int, Knjiga*> knjiga;
    public:
    Biblioteka() {}
    Biblioteka(const Biblioteka &bibl); //po mogucnosti copy i swap da se ne mora pomjerajući pisat
    Biblioteka(Biblioteka &&bibl);
    Biblioteka &operator=(const Biblioteka &x);//po mogucnosti copy i swap da se ne mora pomjerajući pisat
    Biblioteka &operator=(Biblioteka &&bibl);
    ~Biblioteka();//ne zaboravi da knjiga ima konstrukot;
    void RegistrirajNovogKorisnika(int clanski, std::string ime, std::string prezime, std::string adresa, std::string tel);
    void RegistrirajNovuKnjigu(int clanski, std::string naslov,std::string pisac,std::string zanr,int godina);
    Korisnik &NadjiKorisnika(int clanski) const;
    Knjiga &NadjiKnjigu(int clanski) const;
    void IzlistajKorisnike() const ;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidencijski, int clanski);
    void RazduziKnjigu(int evidencijski);
    void PrikaziZaduzenja(int clanski) const;
};
Biblioteka &Biblioteka::operator =(Biblioteka &&bibl){
    if(&bibl!=this){
        for(auto it=korisnik.begin(); it!=korisnik.end(); it++) delete it->second;
        for(auto it=knjiga.begin(); it!=knjiga.end(); it++) {delete (it->second);}
        korisnik.erase( korisnik.begin(), korisnik.end() );                             //brisanje starog sadrzaja
        knjiga.erase( knjiga.begin(), knjiga.end() );
    }
    for(auto it=bibl.korisnik.begin(); it!=bibl.korisnik.end(); it++){
        korisnik[it->first]=it->second;
        it->second=nullptr;
    }
    for(auto it=bibl.knjiga.begin(); it!=bibl.knjiga.end(); it++){
        knjiga[it->first]=it->second;
        auto pok((it->second)->DajKodKogaJe());
        pok=nullptr;
        it->second=nullptr;
    }
    return *this;
}
Biblioteka &Biblioteka::operator=(const Biblioteka &bibl){
    if(&bibl!=this){
        for(auto it=korisnik.begin(); it!=korisnik.end(); it++) delete it->second;
        for(auto it=knjiga.begin(); it!=knjiga.end(); it++) {delete (it->second);}      //u ova 4 reda se vrsi dealociranje
        korisnik.erase( korisnik.begin(), korisnik.end() );                             //i brisanje starih clanova u *this
        knjiga.erase( knjiga.begin(), knjiga.end() );
        for(auto it=bibl.knjiga.begin(); it!=bibl.knjiga.end(); it++){
            this->RegistrirajNovuKnjigu(it->first,(it->second)->DajNaslov(),(it->second)->DajAutora(),(it->second)->DajZanr(),(it->second)->DajGodinuIzdavanja());
        }
        for(auto it=bibl.korisnik.begin(); it!=bibl.korisnik.end(); it++){
            this->RegistrirajNovogKorisnika(it->first, (it->second)->ime, (it->second)->prezime, (it->second)->adresa,(it->second)->telefon);
        }
    }
    for(auto it1=bibl.korisnik.begin(); it1!=bibl.korisnik.end(); it1++){
        for(auto it=bibl.knjiga.begin(); it!=bibl.knjiga.end(); it++){
            auto osoba((it->second)->DajKodKogaJe());
            if(osoba==it1->second){
                this->ZaduziKnjigu(it->first,it1->first);
            }
        }
    }
    return *this;
}
Biblioteka::Biblioteka(const Biblioteka &bibl){
    for(auto it=bibl.korisnik.begin(); it!=bibl.korisnik.end(); it++){
        this->RegistrirajNovogKorisnika(it->first, (it->second)->ime, (it->second)->prezime, (it->second)->adresa,(it->second)->telefon);
    }
    for(auto it=bibl.knjiga.begin(); it!=bibl.knjiga.end(); it++){
        this->RegistrirajNovuKnjigu(it->first,(it->second)->DajNaslov(),(it->second)->DajAutora(),(it->second)->DajZanr(),(it->second)->DajGodinuIzdavanja());
    }
    for(auto it1=bibl.korisnik.begin(); it1!=bibl.korisnik.end(); it1++){
        for(auto it=bibl.knjiga.begin(); it!=bibl.knjiga.end(); it++){
            auto osoba((it->second)->DajKodKogaJe());
            if(osoba==it1->second){                             //zaduzivanje knjige da isti korisnik ima zaduzenu istu knjigu
                this->ZaduziKnjigu(it->first,it1->first);
            }
        }
    }
    
}
Biblioteka::Biblioteka(Biblioteka &&bibl){
    for(auto it=bibl.korisnik.begin(); it!=bibl.korisnik.end(); it++){
        korisnik[it->first]=it->second;     //preusmjeravamo da *this pokazuje na alocirano mjesto korisnika
        it->second=nullptr;                 //korisnika postavljamo na nullptr  da ne vrsi kasnije duplo brisanje
    }
    for(auto it=bibl.knjiga.begin(); it!=bibl.knjiga.end(); it++){
        knjiga[it->first]=it->second;
        auto pok((it->second)->DajKodKogaJe());
        pok=nullptr;
        it->second=nullptr;
    }
}
Biblioteka::~Biblioteka(){
    for(auto it=korisnik.begin(); it!=korisnik.end(); it++) delete it->second;
    for(auto it=knjiga.begin(); it!=knjiga.end(); it++) {delete (it->second);}
}
void Biblioteka::RegistrirajNovogKorisnika(int clanski, std::string ime, std::string prezime, std::string adresa, std::string tel){
    auto it(korisnik.find(clanski));
    if(it!=korisnik.end()) throw std::logic_error("Korisnik vec postoji");
    Korisnik *pok(new Korisnik);
    pok->ime=ime; pok->prezime=prezime; pok->adresa=adresa; pok->telefon=tel;
    korisnik[clanski]=pok;
}
void Biblioteka::RegistrirajNovuKnjigu(int clanski,std::string naslov,std::string pisac,std::string zanr,int godina ){
    auto it(knjiga.find(clanski));
    if(it!=knjiga.end()) throw std::logic_error("Knjiga vec postoji");
    Knjiga *pok(new Knjiga(naslov, pisac, zanr, godina));
    knjiga[clanski]=pok;
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski) const{
    auto it(korisnik.find(clanski));
    if(it==korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
    return *(it->second);
}
Knjiga &Biblioteka::NadjiKnjigu(int clanski) const{
    auto it(knjiga.find(clanski));
    if(it==knjiga.end()) throw std::logic_error("Knjiga nije nadjen");
    return *(it->second);
}
void Biblioteka::IzlistajKorisnike() const{
    for(auto it=korisnik.begin(); it!=korisnik.end(); it++){
        std::cout<<"Clanski broj: "<<it->first<<std::endl;
        std::cout<<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<std::endl;
        std::cout<<"Adresa: "<<(it->second)->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<(it->second)->telefon<<std::endl;
        std::cout<<std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const{
    for(auto it=knjiga.begin(); it!=knjiga.end(); it++){
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<(it->second)->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<(it->second)->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<(it->second)->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl;
        if((it->second)->DaLiJeZaduzena()) {
            auto osoba((it->second)->DajKodKogaJe());
            std::cout<<"Zaduzena kod korisnika: "<<osoba->ime<<" "<<osoba->prezime<<std::endl;
        }
        std::cout<<std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int evidencijski, int clanski){
    auto it1(knjiga.find(evidencijski));
    if(it1==knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    auto it2(korisnik.find(clanski));
    if(it2==korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
    if((it1->second)->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    (it1->second)->ZaduziKnjigu(*(it2->second));
}
void Biblioteka::RazduziKnjigu(int evidencijski) {
    auto it1(knjiga.find(evidencijski));
    if(it1==knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    if(!((it1->second)->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
    (it1->second)->RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clanski) const{
    auto it1(korisnik.find(clanski));
    if(it1==korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
    int br(0);
    for(auto it=knjiga.begin(); it!=knjiga.end(); it++){
        auto osoba((it->second)->DajKodKogaJe());
        if(osoba==(it1->second)){
            br++;
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<(it->second)->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<(it->second)->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<(it->second)->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl;
        }
        std::cout<<std::endl;
    }
    if(br==0){
        std::cout<<"Nema zaduzenja za tog korisnika!"<<std::endl;
    }
}
int main (){
    int x;
    Biblioteka bib;
    do{
        std::cout<<"Unesite zeljenu opciju: 1-unos korisnika, 2-unos knjige, 3-pronadji korisnika, 4-nadji knjigu, 5-zaduzi knjigu, 6-razduzi knjigu, 7-prikaz zaduzenja \n";
        std::cin>>x;
        if(x==2){
            int broj(4);
            std::cout<<"Unos knjige//pokazni primjer";
            std::string nas("Juzni Vetar"), pis="Saban", zanr="muzika";
            int god=1976;
            try{
                bib.RegistrirajNovuKnjigu(broj,nas,pis,zanr,god);
            }
            catch(std::logic_error e){
                std::cout<<e.what();
            }
        }
        else if(x==1){
            std::cout<<"Unos korisnika //pokazni primjer\n";
            std::string ime("suljo"), prezime("suljic"), drzv("BIH");
            try{
                bib.RegistrirajNovogKorisnika(43,ime,prezime, drzv, "064569895");
            }
            catch(std::logic_error e){
                std::cout<<e.what();
            }
        }
        else if(x==3){
            std::cout<<"Pronalazak po clanskom broju: \n";
            try{
                Korisnik kor(bib.NadjiKorisnika(43));
                std::cout<<kor.ime<<" "<<kor.prezime<<" "<<kor.adresa;
            }
            catch(std::logic_error e){
                std::cout<<e.what();
            }
        }
            else if(x==4){
                std::cout<<"Pronalazak po evidencijskom broju: \n";
                try{
                    Knjiga k(bib.NadjiKnjigu(4));
                    std::cout<<k.DajNaslov()<<", napisao: "<<k.DajAutora()<<", a zanr: "<<k.DajZanr();
                    
                }
                catch(std::logic_error e){
                std::cout<<e.what();
            }
            }
            else if(x==5){
                std::cout<<"Zaduzivanje knjige: \n";
                try{
                    bib.ZaduziKnjigu(4,43);
                }
                catch(std::logic_error e){
                std::cout<<e.what();
            }
            }
            else if(x==6){
                std::cout<<"Razduzivanje: \n";
                try{
                    bib.RazduziKnjigu(4);
                }
                catch(std::logic_error e){
                std::cout<<e.what();
            }
            }
            else if(x==7){
                std::cout<<"\nIzlistajKorisnike: ";bib.IzlistajKorisnike();
                std::cout<<"\nIzlistajKnjige: ";bib.IzlistajKnjige(); std::cout<<std::endl;
                std::cout<<"Prikaz zaduznja po clanskom: ";
                try{
                    bib.PrikaziZaduzenja(43);
                }
                catch(std::logic_error e){
                std::cout<<e.what();
            }
            }
            
            
        }while(x!=0);
	return 0;
}