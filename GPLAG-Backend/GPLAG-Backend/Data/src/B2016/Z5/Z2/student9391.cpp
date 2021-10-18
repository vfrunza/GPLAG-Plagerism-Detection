/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>
struct Korisnik {
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
} kor;

class Knjiga
{
    std::string naslov;
    std::string ime_pisca;
    std::string zanr;
    int godina_izdavanja;
   Korisnik* KorZaduzio {nullptr};
public:
    Knjiga (std::string n, std::string i_p, std::string zan, int god_izd);
    std::string DajNaslov() const;//napisano
    std::string DajAutora() const;//napisano
    std::string DajZanr() const;//napisano
    int DajGodinuIzdavanja() const;//napisano
    Korisnik *ZaduziKnjigu(Korisnik &kor); // napisano;
    void RazduziKnjigu(); //napisano
    Korisnik *DajKodKogaJe(); //napisano
    bool DaLiJeZaduzena() const;//napisano
};

Knjiga::Knjiga (std::string n, std::string i_p, std::string zan, int god_izd)
{
    naslov=n;
    ime_pisca=i_p;
    zanr=zan;
    godina_izdavanja=god_izd;
}

std::string Knjiga::DajNaslov() const
{
    return naslov;
}

std::string Knjiga::DajAutora() const
{
    return ime_pisca;
}

std::string Knjiga::DajZanr() const
{
    return zanr;
}

int Knjiga::DajGodinuIzdavanja() const
{
    return godina_izdavanja;
}

Korisnik *Knjiga::DajKodKogaJe()
{
    return KorZaduzio;
}

Korisnik *Knjiga::ZaduziKnjigu(Korisnik &kor)
{
    KorZaduzio=&kor;
    return KorZaduzio;
}

void Knjiga::RazduziKnjigu()
{
    //*KorZaduzio(nullptr);
    //delete KorZaduzio;
    KorZaduzio=nullptr;
}

bool Knjiga::DaLiJeZaduzena() const
{
    if (KorZaduzio==nullptr)
        return false;
    else
        return true;
}

/*void Videoteka::ZaduziFilm(int evbroj, int clbroj)
{

    int brojac(0); int i(0); int j(0);
    for(i=0; i<niz_filmova.size(); i++)
        if(evbroj==niz_filmova[i]->DajEvidencijskiBroj()) { brojac++; break; }
    if(brojac==0) throw logic_error("Ne postoji film sa takvim ev. brojem!");
    brojac=0;
    for(j=0; i<niz_korisnika.size();j++)
        if(clbroj==niz_korisnika[j]->DajClanskiBroj()) { brojac++; break; }
    if(brojac==0) throw logic_error("Ne postoji korisnik sa takvim cl. brojem!");

    if(niz_filmova[i]->DaLiJeZaduzen()) throw logic_error("Film je vec zaduzen!");
    niz_filmova[i]->ZaduziFilm(*niz_korisnika[j]);

}

void Videoteka::RazduziFilm(int evbroj)
{
    int brojac(0); int i(0);
    for(i=0; i<niz_filmova.size(); i++)
        if(evbroj==niz_filmova[i]->DajEvidencijskiBroj()) { brojac++; break; }
    if(brojac==0) throw logic_error("Ne postoji film sa takvim ev. brojem!");

    if(!niz_filmova[i]->DaLiJeZaduzen()) throw logic_error("Film je vec zaduzen!");
    niz_filmova[i]->RazduziFilm();
}*/

class Biblioteka
{
    std::map<int, std::shared_ptr<Korisnik>> Korisnici;
    std::map<int, std::shared_ptr<Knjiga>> Knjige;
public:
    Biblioteka();
    ~Biblioteka();
   std::shared_ptr<Korisnik>> &RegistrirajNovogKorisnika(int ev, std::string ime_kor, std::string prezime_kor, std::string adr, std::string br_tel);// const;
   std::shared_ptr<Knjiga>> &RegistrirajNovuKnjigu(int ev, std::string n, std::string i_p, std::string zan, int god_izd);
    std::shared_ptr<Korisnik>> &NadjiKorisnika(int clanski_broj_korisnika);
    std::shared_ptr<Knjiga>> &NadjiKnjigu(int);
    Biblioteka (const Biblioteka &B) {
        Korisnici=B.Korisnici;
        Knjige=B.Knjige;
    }

    void ZaduziKnjigu(int id_knjige, int id_korisnika) {
        Knjiga knj=NadjiKnjigu(id_knjige);
        Korisnik k=NadjiKorisnika(id_korisnika);
        if (knj.DaLiJeZaduzena()==true) throw std::logic_error("Knjiga vec zaduzena");
        knj.ZaduziKnjigu(k);
    }
    void RazduziKnjigu(int id_knjige, int id_korisnika) {
        Knjiga knj=NadjiKnjigu(id_knjige);
        Korisnik k=NadjiKorisnika(id_korisnika);
        if (knj.DaLiJeZaduzena()==false) throw std::logic_error("Knjiga nije zaduzena");
        knj.RazduziKnjigu();
    }
    void IzlistajKorisnike()const {
        for (auto it=Korisnici.begin(); it!=Korisnici.end(); ++it) {
            std::cout << "Clanski broj: " << it->first << std::endl;
            std::cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl;
            std::cout << "Adresa: " << it->second->adresa << std::endl;
            std::cout << "Broj telefona: " << it->second->telefon  << std::endl;
        }
    }
    void IzlistajKnjige() {
        for (auto it=Knjige.begin(); it!=Knjige.end(); ++it) {
            std::cout << "Evidencijski broj: " << it->first << std::endl;
            std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
            std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
            std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja()  << std::endl;
            auto it2=it->second->DajKodKogaJe();
            if (it2!=nullptr) std::cout << "Zaduzena kod korisnika: " << it2->ime << " " << it2->prezime << std::endl;
        }
    }
    void PrikaziZaduzenja(int ev) {
        bool uhvacen=false;
        for (auto it=Korisnici.begin(); it!=Korisnici.end(); ++it) {
            if(it->first==ev) {
                for (auto it2=Knjige.begin(); it2!=Knjige.end(); ++it2)
                    if (it2->second->DajKodKogaJe()->ime==it->second->ime) {
                        std::cout << "Evidencijski broj: " << it2->first << std::endl;
                        std::cout << "Naslov: " << it2->second->DajNaslov() << std::endl;
                        std::cout << "Pisac: " << it2->second->DajAutora() << std::endl;
                        std::cout << "Zanr: " << it2->second->DajZanr() << std::endl;
                        std::cout << "Godina izdavanja: " << it2->second->DajGodinuIzdavanja()  << std::endl;
                    }
                bool uhvacen=true;
            }
        }
        if (uhvacen==false) std::cout << "Nema zaduzenja za tog korisnika!";
    }
};

Biblioteka::Biblioteka() {}
std::shared_ptr<Knjiga>>& Biblioteka::NadjiKnjigu(int a)
{
    for (auto it=Knjige.begin(); it!=Knjige.end(); ++it)
        if(it->first==a) return it->second;
    throw std::logic_error("Knjiga nije nadjena");
};
std::shared_ptr<Korisnik>>& Biblioteka::NadjiKorisnika(int a)
{
    for (auto it=Korisnici.begin(); it!=Korisnici.end(); ++it)
        if(it->first==a) return it->second;
    throw std::logic_error("Korisnik nije nadjen");
};
std::shared_ptr<Korisnik>> &Biblioteka::RegistrirajNovogKorisnika(int ev, std::string ime_kor, std::string prezime_kor, std::string adr, std::string br_tel)
{
    for (auto it=Korisnici.begin(); it!=Korisnici.end(); ++it)
        if(it->first==ev) throw std::logic_error("Korisnik vec postoji");
    Korisnik k {ime_kor,prezime_kor,adr, br_tel};
    Korisnici.insert (Korisnici.end(),std::pair<int,Korisnik>(ev,k));
    return Korisnici.end()->second;
}
std::shared_ptr<Knjiga>>a &Biblioteka::RegistrirajNovuKnjigu(int ev, std::string n, std::string i_p, std::string zan, int god_izd)
{
    for (auto it=Knjige.begin(); it!=Knjige.end(); ++it)
        if(it->first==ev) throw std::logic_error("Knjiga vec postoji");
    Knjiga k(n, i_p, zan, god_izd);
    Knjige.insert (Knjige.end(),std::pair<int,Knjiga>(ev,k));
    return Knjige.end()->second;
}
Biblioteka::~Biblioteka()
{
    Korisnici.clear();
    Knjige.clear();
}
int main ()
{



    return 0;
}