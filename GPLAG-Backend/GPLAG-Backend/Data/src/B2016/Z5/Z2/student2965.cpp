/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <cstring>
#include <algorithm>
#include <utility>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};
class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int god_izd;
    Korisnik *pok;
    public:
    Knjiga (std::string Naslov, std::string pisac, std::string Zanr, int godina) {
        naslov=Naslov; ime_pisca=pisac; zanr=Zanr; god_izd=godina;
        pok=nullptr;
    }
    std::string DajNaslov()const {return naslov;}
    std::string DajAutora()const {return ime_pisca;}
    std::string DajZanr()const {return zanr;}
    int DajGodinuIzdavanja() const {return god_izd;}
    Korisnik *DajKodKogaJe() const {return pok;}
    void ZaduziKnjigu (Korisnik &korisnik) { pok=&korisnik;}
    void RazduziKnjigu() {pok=nullptr;}
    bool DaLiJeZaduzena() {
        if (pok==nullptr) return false;
        return true;
    }
};
class Biblioteka {
    std::map<int, std::shared_ptr<Korisnik> > korisnici;
    std::map<int, std::shared_ptr<Knjiga> >knjige;
    public:
    Biblioteka()=default;
    Biblioteka (const Biblioteka &bibl) {
        for(auto it=bibl.korisnici.begin(); it!=bibl.korisnici.end(); it++){
            korisnici.insert(std::make_pair(it->first,std::make_shared<Korisnik>(*(it->second))));
        }
        for (auto it=bibl.knjige.begin(); it!=bibl.knjige.end(); it++) {
            knjige.insert(std::make_pair(it->first,std::make_shared<Knjiga>(*(it->second))));
        }
        
    }
    Biblioteka(Biblioteka &&bibl){
        for (auto it=bibl.korisnici.begin(); it!=bibl.korisnici.end(); it++){
            korisnici.insert(std::make_pair(it->first,it->second));
            it->second=nullptr;
        }
        for (auto it=bibl.knjige.begin(); it!=bibl.knjige.end(); it++){
            knjige.insert(std::make_pair(it->first,it->second));
            it->second=nullptr;
        }
    }
    Biblioteka &operator = (const Biblioteka &bibl){
        if (this==&bibl) return *this;
        for (auto it=bibl.korisnici.begin(); it!=bibl.korisnici.end(); it++){
            //it->second(nullptr);
            korisnici.erase(it);
        }
        for (auto it=bibl.knjige.begin(); it!=bibl.knjige.end(); it++){
            //it->second=nullptr;
            knjige.erase(it);
        }
        for(auto it=bibl.korisnici.begin(); it!=bibl.korisnici.end(); it++){
            korisnici.insert(std::make_pair(it->first,std::make_shared<Korisnik>(*(it->second))));
        }
        for (auto it=bibl.knjige.begin(); it!=bibl.knjige.end(); it++){
            knjige.insert(std::make_pair(it->first,std::make_shared<Knjiga>(*(it->second))));
        }
        return *this;
    }
    Biblioteka &operator =(Biblioteka &&bibl){
        if (this==&bibl) return *this;
        for (auto it=bibl.korisnici.begin(); it!=bibl.korisnici.end(); it++){
            korisnici.insert(std::make_pair(it->first,it->second));
            it->second=nullptr;
        }
        for (auto it=bibl.knjige.begin(); it!=bibl.knjige.end(); it++){
            knjige.insert(std::make_pair(it->first,it->second));
            it->second=nullptr;
        }
        return *this;
    }
    void RegistrirajNovogKorisnika (int cl_br,std::string name,std::string surname,std::string address,std::string br_tel){
        for (auto it=korisnici.begin(); it!=korisnici.end(); it++){
            if (it->first==cl_br) throw std::logic_error ("Korisnik vec postoji");
        }
        Korisnik pok;
            pok.ime=name;
            pok.prezime=surname;
            pok.adresa=address;
            pok.telefon=br_tel;
            korisnici.insert(std::make_pair(cl_br,std::make_shared<Korisnik>(pok)));
    }
    void RegistrirajNovuKnjigu(int ev_br, std::string Naslov, std::string autor, std::string Zanr, int godina){
        for (auto it=knjige.begin(); it!=knjige.end(); it++){
            if (it->first==ev_br) throw std::logic_error ("Korisnik vec postoji");
        }
        knjige.insert(std::make_pair(ev_br,std::make_shared<Knjiga>(Naslov,autor,Zanr,godina)));
    }
    Korisnik &NadjiKorisnika(int cl_broj);
    Knjiga &NadjiKnjigu(int ev_broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int ev_br, int cl_broj);
    void RazduziKnjigu(int ev_br);
    void PrikaziZaduzenja(int cl_broj){
        std::string name="";
        bool ima=false,ima1=false;
        auto it_kor=korisnici.begin();
        for (; it_kor!=korisnici.end(); it_kor++){
            if (it_kor->first==cl_broj) {
                ima=true;
                break;
            }
        }
        if (ima==false) throw std::logic_error("Korisnik nije nadjen");
        for (auto it=knjige.begin(); it!=knjige.end(); it++){
            if (it_kor->second.get()==it->second->DajKodKogaJe()){
                std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
                std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
                std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
                std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
                std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
                std::cout<<std::endl;
                ima1=true;
            }
        }
        if (ima1==false ) std::cout<<"Nema zaduzenja za tog korisnika!";
    }
};
Korisnik &Biblioteka::NadjiKorisnika(int cl_broj){
    for (auto it=korisnici.begin(); it!=korisnici.end(); it++){
        if (it->first==cl_broj) return *it->second;
    }
    throw std::logic_error ("Korisnik nije nadjen");
}
Knjiga &Biblioteka::NadjiKnjigu(int ev_broj){
    for (auto it=knjige.begin(); it!=knjige.end(); it++){
        if (it->first==ev_broj) return *it->second;
    }
    throw std::logic_error ("Knjiga nije nadjena");
}
void Biblioteka::IzlistajKorisnike() const {
    int brojac=0;
    for (auto it=korisnici.begin(); it!=korisnici.end(); it++){
        std::cout<<"Clanski broj: "<<it->first<<std::endl;
        std::cout<<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<std::endl;
        std::cout<<"Adresa: "<<(it->second)->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<(it->second)->telefon<<std::endl;
        brojac++;
        if(brojac!=0 && (brojac%2==0)) std::cout<<std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const {
    int brojac=0;
    for (auto it=knjige.begin(); it!=knjige.end(); it++){
        brojac++;
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<(it->second)->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<(it->second)->DajAutora() <<std::endl;
        std::cout<<"Zanr: "<<(it->second)->DajZanr() <<std::endl;
        std::cout<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl;
        if((*it->second).DaLiJeZaduzena()) {
            std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "
            <<it->second->DajKodKogaJe()->prezime;
            std::cout<<std::endl;
        }
        if (brojac!=0 && (brojac%2==0)) std::cout<<std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int ev_broj, int cl_broj){
    bool ima=false,ima1=false;
    auto it=knjige.begin();
    for (it=knjige.begin(); it!=knjige.end(); it++){
        if (it->first==ev_broj) {ima=true;break;}
    }
    auto it1=korisnici.begin();
    if (ima==false) throw std::logic_error ("Knjiga nije nadjena");
    else {
        for (it1=korisnici.begin(); it1!=korisnici.end(); it1++){
            if (it1->first==cl_broj) {
                ima1=true;
                break;
            }
        }
        if (ima1==false) throw std::logic_error ("Korisnik nije nadjen");
        else {
            it->second->ZaduziKnjigu(*it1->second);
        }
    }
}
void Biblioteka::RazduziKnjigu(int ev_broj){
    auto it=knjige.begin();
    bool ima=false;
    for (it=knjige.begin(); it!=knjige.end(); it++){
        if (it->first==ev_broj){
            ima=true; break;
        } 
    }
    if (ima==false) throw std::logic_error ("Knjiga nije nadjena");
    bool Zaduzena=it->second->DaLiJeZaduzena();
    if (Zaduzena==false) throw std::logic_error ("Knjiga nije zaduzena");
    else {
        it->second->RazduziKnjigu();
    }
}

int main ()
{
    Biblioteka b;
    b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic","Zmaja od Bosne 30", "032/444-555");
    b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic","Trg neznalica 111", "030/111-222");
    b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic","Studenata 3b", "037/654-321");
    b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
    b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
    b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
    b.IzlistajKnjige();
    std::cout<<std::endl;
    Biblioteka b1;
    b1.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic","Zmaja od Bosne 30", "032/444-555");
    b1.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic","Trg neznalica 111", "030/111-222");
    b1.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic","Studenata etfovaca 3b", "037/654-321");
    b1.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
    b1.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
    b1.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
    b1.ZaduziKnjigu(231, 1234);
    b1.ZaduziKnjigu(136, 1234);
    b1.PrikaziZaduzenja(1234);

	return 0;
}