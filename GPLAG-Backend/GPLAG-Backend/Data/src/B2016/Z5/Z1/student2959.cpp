#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};
bool operator ==(Korisnik& k1, Korisnik& k2){
    return k1.ime==k2.ime && k1.prezime==k2.prezime && k1.adresa==k2.adresa && k1.telefon==k2.telefon; 
}
class Knjiga{
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* ko_je_zaduzio;
    public:
    Knjiga(std::string naziv, std::string ime_p, std::string z, int god): 
            naslov(naziv), ime_pisca(ime_p), zanr(z), godina_izdavanja(god), ko_je_zaduzio(nullptr) {}
    std::string DajNaslov()  const { return naslov; }
    std::string DajAutora()  const { return ime_pisca; }
    std::string DajZanr()    const { return zanr; } 
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik* DajKodKogaJe() const { return ko_je_zaduzio; }
    void ZaduziKnjigu(Korisnik& korisnik) { ko_je_zaduzio=&korisnik; }
    void RazduziKnjigu() { ko_je_zaduzio=nullptr; }
    bool DaLiJeZaduzena() { if(ko_je_zaduzio) return true; else return false; }
};
class Biblioteka{
    std::map<int,Korisnik*> korisnici;
    std::map<int,Knjiga*> knjige;
    void UnistiMemoriju();
    public:
    Biblioteka(): korisnici(), knjige() {}
    ~Biblioteka() {
        UnistiMemoriju(); 
    }
    Biblioteka(const Biblioteka& b);
    Biblioteka(Biblioteka&& b);
    Biblioteka& operator =(const Biblioteka& b);
    Biblioteka& operator =(Biblioteka&& b);
    void RegistrirajNovogKorisnika(int cl_broj, std::string i, std::string p, std::string ad, std::string br_tel);
    void RegistrirajNovuKnjigu(int ev_br, std::string naz, std::string ime_p, std::string z, int god);
    Korisnik& NadjiKorisnika(int cl_br);
    Knjiga& NadjiKnjigu(int e_br);
    void IzlistajKorisnike();
    void IzlistajKnjige();
    void ZaduziKnjigu(int e_br, int c_br);
    void RazduziKnjigu(int e_br);
    void PrikaziZaduzenja(int c_br);
};

void Biblioteka::UnistiMemoriju(){
     for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
        { delete it->second; it->second=nullptr; }
     for(auto it=knjige.begin(); it!=knjige.end(); it++)
        { delete it->second; it->second=nullptr; }
}
Biblioteka::Biblioteka(const Biblioteka& b){
       UnistiMemoriju();
       korisnici=b.korisnici;
       auto it1=korisnici.begin(); auto it2=b.korisnici.begin();
       while(it1!=korisnici.end())
       {
           Korisnik* pok=new Korisnik(*(it2->second));
           it1->second=pok;
           it1++; it2++;
       }
       
       knjige=b.knjige;
       auto itk1=knjige.begin(); auto itk2=b.knjige.begin();
       while(itk1!=knjige.end())
       {
           Knjiga* pok=new Knjiga(*(itk2->second));
           itk1->second=pok;
           itk1++; itk2++;
       }
        
    }
Biblioteka::Biblioteka(Biblioteka&& b){
     UnistiMemoriju();
     korisnici=b.korisnici;
     for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++) it->second=nullptr;
     knjige=b.knjige;
     for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++) it->second=nullptr;
     
}
Biblioteka& Biblioteka::operator=(const Biblioteka& b){
    if(&b!= this){
         UnistiMemoriju();
       korisnici=b.korisnici;
       auto it1=korisnici.begin(); auto it2=b.korisnici.begin();
       while(it1!=korisnici.end())
       {
           Korisnik* pok=new Korisnik(*(it2->second));
           it1->second=pok;
           it1++; it2++;
       }
       
       knjige=b.knjige;
       auto itk1=knjige.begin(); auto itk2=b.knjige.begin();
       while(itk1!=knjige.end())
       {
           Knjiga* pok=new Knjiga(*(itk2->second));
           itk1->second=pok;
           itk1++; itk2++;
       }
    }
    return *this;
}
Biblioteka& Biblioteka::operator =(Biblioteka&& b){
    if(&b!=this)
    {UnistiMemoriju();
     korisnici=b.korisnici;
     for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++) it->second=nullptr;
     knjige=b.knjige;
     for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++) it->second=nullptr;}
     return *this;
}
    void Biblioteka::RegistrirajNovogKorisnika(int cl_broj, std::string i, std::string p, std::string ad, std::string br_tel){
        if(korisnici.count(cl_broj)) throw std::logic_error("Korisnik vec postoji");
        else{
            Korisnik* pok(new Korisnik({i, p, ad, br_tel}));
            korisnici.insert(std::make_pair(cl_broj, pok));
        }
    }
    void Biblioteka::RegistrirajNovuKnjigu(int ev_br, std::string naz, std::string ime_p, std::string z, int god){
        if(knjige.count(ev_br)) throw std::logic_error("Knjiga vec postoji");
        else{
            Knjiga* pok(new Knjiga({naz, ime_p, z, god}));
            knjige.insert(std::make_pair(ev_br, pok));
        }
    }
    Korisnik& Biblioteka::NadjiKorisnika(int cl_br){
        auto it(korisnici.find(cl_br));
        if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        else return *(it->second);
    }
    Knjiga& Biblioteka::NadjiKnjigu(int e_br){
        auto it(knjige.find(e_br));
        if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        else return *(it->second);
    }
    void Biblioteka::IzlistajKorisnike() {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
        {
            std::cout<<"Clanski broj: "<<it->first<<std::endl;
            std::cout<<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<std::endl;
            std::cout<<"Adresa: "<<(it->second)->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<(it->second)->telefon<<std::endl<<std::endl;
        }
    }
    void Biblioteka::IzlistajKnjige() {
        for(auto it=knjige.begin(); it!=knjige.end(); it++)
        {
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<(it->second)->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<(it->second)->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<(it->second)->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl;
            if(!((it->second)->DaLiJeZaduzena())) std::cout<<std::endl;
            else std::cout<<"Zaduzena kod korisnika: "<<(it->second)->DajKodKogaJe()->ime<<" "<<(it->second)->DajKodKogaJe()->prezime<<std::endl<<std::endl;
        }
    }
    void Biblioteka::ZaduziKnjigu(int e_br, int c_br) {
        if(!knjige.count(e_br)) throw std::logic_error("Knjiga nije nadjena");
        if(!korisnici.count(c_br)) throw std::logic_error("Korisnik nije nadjen");
        if(NadjiKnjigu(e_br).DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
        NadjiKnjigu(e_br).ZaduziKnjigu(NadjiKorisnika(c_br));
    }
    void Biblioteka::RazduziKnjigu(int e_br) { 
        if(!knjige.count(e_br)) throw std::logic_error("Knjiga nije nadjena");
        if(!NadjiKnjigu(e_br).DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
        NadjiKnjigu(e_br).RazduziKnjigu();
    }
    void Biblioteka::PrikaziZaduzenja(int c_br) {
        if(!korisnici.count(c_br)) throw std::logic_error("Korisnik nije nadjen");
        bool ima_li_zaduzenja(0);
        for(auto it=knjige.begin(); it!=knjige.end(); it++)
        {
            if((*(it->second)->DajKodKogaJe())==NadjiKorisnika(c_br)) {
                ima_li_zaduzenja=1;
                std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
                std::cout<<"Naslov: "<<(it->second)->DajNaslov()<<std::endl;
                std::cout<<"Pisac: "<<(it->second)->DajAutora()<<std::endl;
                std::cout<<"Zanr: "<<(it->second)->DajZanr()<<std::endl;
                std::cout<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl<<std::endl;
            }
        }
        if(!ima_li_zaduzenja) std::cout<<"Nema zaduzenja za tog korisnika!";
    }


int main() {
    Biblioteka b;
    for(;;){
    try{    std::cout<<"\nOdaberite opciju:\nRegistriraj novog korisnika: 1\nRegistriraj novu knjigu: 2\n";
        std::cout<<"Nadji korisnika: 3\nNadji knjigu: 4\nIzlistaj korisnike: 5\nIzlistaj knjige: 6\nZaduzi knjigu: 7\nRazduzi knjigu: 8\nPrikazi zaduzenja: 9\n";
        std::cout<<"Kraj: 0\n";
        int n;
        std::cin>>n;
        if(n==1) {
            Korisnik k;
            std::cout<<"Unesite clanski broj: "; int clbr; std::cin>>clbr;
            std::cout<<"Unesite ime korisnika: "; std::cin>>k.ime;
            std::cout<<"Unesite prezime: "; std::cin>>k.prezime;
            std::cout<<"Adresa: "; std::cin>>k.adresa;
            std::cout<<"Broj telefona: "; std::cin>>k.telefon;
            b.RegistrirajNovogKorisnika(clbr, k.ime, k.prezime, k.adresa, k.telefon);
        }
        if(n==2){
            std::cout<<"Evidencijski broj: "; int ebr; std::cin>>ebr;std::cin.ignore(10,'\n');
            std::cout<<"Unesite naziv knjige: "; std::string naz; std::getline(std::cin,naz); 
            std::cout<<"Unesite ime pisca: "; std::string pisac;  std::getline(std::cin,pisac);
            std::cout<<"Zanr: "; std::string zanrr; std::getline(std::cin,zanrr);
            std::cout<<"Godina izdanja: "; int god; std::cin>>god;
            b.RegistrirajNovuKnjigu(ebr, naz, pisac, zanrr, god);
        }
        if(n==3){
            std::cout<<"Unesite clanski broj korisnika: "; int br; std::cin>>br;
            Korisnik kor(b.NadjiKorisnika(br));
            std::cout<<"\nIme i prezime: "<<kor.ime<<" "<<kor.prezime;
            std::cout<<"\nAdresa: "<<kor.adresa;
            std::cout<<"\nBroj telefona: "<<kor.telefon;
        }
        if(n==4){
            std::cout<<"Unesite evidencijski broj knjige: "; int br; std::cin>>br;
            Knjiga knj(b.NadjiKnjigu(br));
            std::cout<<"\nNaziv: "<<knj.DajNaslov();
            std::cout<<"\nIme pisca: "<<knj.DajAutora();
            std::cout<<"\nZanr: "<<knj.DajZanr();
            std::cout<<"\nGodina izdavanja: "<<knj.DajGodinuIzdavanja();
        }
        if(n==5){
            b.IzlistajKorisnike();
        }
        if(n==6){
            b.IzlistajKnjige();
        }
        if(n==7){
            std::cout<<"Unesite evidencijski broj knjige i clanski broj korisnika: "; int evbr, clbr;
            std::cin>>evbr>>clbr;
            b.ZaduziKnjigu(evbr, clbr);
        }
        if(n==8){
            std::cout<<"Unesite evidencijski broj knjige: "; int ebr; std::cin>>ebr;
            b.RazduziKnjigu(ebr);
        }
        if(n==9){
            std::cout<<"Unesite clanski broj korisnika: "; int br; std::cin>>br;
            b.PrikaziZaduzenja(br);
        }
        if(n==0) break;
    } catch(std::logic_error por) { std::cout<<por.what(); }
    }
   
    return 0;
}
