#include <iostream>
#include <memory>
#include <cmath>
#include <map>
#include <string>
#include <stdexcept>

#define TijeloIzuzetka(izuzetak, tijelo) \
try tijelo catch(izuzetak e) { std::cout << e.what() << std::endl; }


struct Korisnik {
    std::string ime,prezime,adresa, telefon;
};

void Ispisi(const Korisnik &k)
{
    std::cout << "Ime i prezime: "<< k.ime <<" "<< k.prezime << std::endl;
    std::cout << "Adresa: "<< k.adresa << std::endl;
    std::cout << "Broj telefona: "<< k.telefon << std::endl<<std::endl;
}
class Knjiga
{
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik * zaduzenje;
public:
    Knjiga(std::string _naslov,std::string _ime_pisca, std::string _zanr, int _godina_izdavanja): naslov(_naslov),ime_pisca(_ime_pisca),zanr(_zanr),godina_izdavanja(_godina_izdavanja),zaduzenje(nullptr) {}
    ~Knjiga() {
        zaduzenje=nullptr;
    }
    std::string DajNaslov() const {
        return naslov;
    }
    std::string DajAutora() const {
        return ime_pisca;
    }
    std::string DajZanr() const {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return godina_izdavanja;
    }
    Korisnik* DajKodKogaJe()const {
        return zaduzenje;
    }
    void ZaduziKnjigu(Korisnik &K) {
        zaduzenje=&K;
    }
    void RazduziKnjigu() {
        zaduzenje=nullptr;
    }
    bool DaLiJeZaduzena()const {
        return zaduzenje;
    }
    
};

void Ispisi(const Knjiga &k)
{
    std::cout << "Naslov: "<< k.DajNaslov() << std::endl;
    std::cout << "Pisac: "<< k.DajAutora() << std::endl;
    std::cout << "Zanr: "<< k.DajZanr() << std::endl;
    std::cout <<"Godina izdavanja: "<< k.DajGodinuIzdavanja() << std::endl;
    if(k.DajKodKogaJe()!=nullptr) std::cout <<"Zaduzena kod korisnika: "<< k.DajKodKogaJe()->ime << " " << k.DajKodKogaJe()->prezime  << std::endl;
}

class Biblioteka
{
    std::map<int,Korisnik*> m_korisnik; //cl broj
    std::map<int,Knjiga*> m_knjiga; //ev broj
public:
    Biblioteka() {}
    ~Biblioteka() {
        for(auto it = m_korisnik.begin(); it != m_korisnik.end(); it++)
            delete it->second;
        for(auto it = m_knjiga.begin(); it != m_knjiga.end(); it++)
            delete it->second;
    }
    Biblioteka(const Biblioteka &B) {
        for(auto it = B.m_korisnik.begin(); it != B.m_korisnik.end(); it++)
            m_korisnik[it->first]=new Korisnik(*it->second);
        for(auto it = B.m_knjiga.begin(); it != B.m_knjiga.end(); it++)
            m_knjiga[it->first]=new Knjiga(*it->second);
    }
    Biblioteka(Biblioteka &&B) {
        m_korisnik=B.m_korisnik;
        m_knjiga=B.m_knjiga;
        B.m_knjiga.erase (B.m_knjiga.begin(),B.m_knjiga.end());
        B.m_korisnik.erase (B.m_korisnik.begin(), B.m_korisnik.end());
    }
    Biblioteka &operator =(const Biblioteka &B) {
        for(auto it = m_korisnik.begin(); it != m_korisnik.end(); it++) {
            delete it->second;
        }
        for(auto it = m_knjiga.begin(); it != m_knjiga.end(); it++) {
            delete it->second;
        }
        m_knjiga.erase (m_knjiga.begin(),m_knjiga.end());
        m_korisnik.erase (m_korisnik.begin(), m_korisnik.end());

        for(auto it = B.m_knjiga.begin(); it != B.m_knjiga.end(); it++)
            m_knjiga[it->first]=new Knjiga(*it->second);
        for(auto it = B.m_korisnik.begin(); it != B.m_korisnik.end(); it++)
            m_korisnik[it->first]=new Korisnik(*it->second);
        return *this;

    }

    Biblioteka &operator =(Biblioteka &&B) {
        m_korisnik=B.m_korisnik;
        m_knjiga=B.m_knjiga;
        B.m_knjiga.erase (B.m_knjiga.begin(),B.m_knjiga.end());
        B.m_korisnik.erase (B.m_korisnik.begin(), B.m_korisnik.end());
        return *this;
    }

    void RegistrirajNovogKorisnika(int cl_broj,std::string _ime, std::string _prezime,std::string _adresa, std::string _telefon) {
        auto it(m_korisnik.find(cl_broj));
        if(it!=m_korisnik.end()) throw std::logic_error ("Korisnik vec postoji");
        m_korisnik.insert(std::make_pair(cl_broj,new Korisnik({_ime,_prezime,_adresa,_telefon})));
    }
    void RegistrirajNovuKnjigu(int ev_broj, std::string _naslov, std::string _ime_pisca, std::string _zanr, int _godina_izdavanja) {
        auto it(m_knjiga.find(ev_broj));
        if(it!=m_knjiga.end()) throw std::logic_error ("Knjiga vec postoji");
        m_knjiga.insert(std::make_pair(ev_broj,new Knjiga({_naslov,_ime_pisca,_zanr,_godina_izdavanja})));
    }
    Korisnik& NadjiKorisnika(int cl_broj) {
        auto it(m_korisnik.find(cl_broj));
        if(it==m_korisnik.end()) throw std::logic_error ("Korisnik nije nadjen");
        return (*it->second);
    }
    Knjiga& NadjiKnjigu(int ev_broj) const {
        auto it(m_knjiga.find(ev_broj));
        if(it==m_knjiga.end()) throw std::logic_error ("Knjiga nije nadjena");
        return (*it->second);
    }
    void IzlistajKorisnike() const {
        for(auto it = m_korisnik.begin(); it != m_korisnik.end(); it++) {
            std::cout << "Clanski broj: "<<it->first<< std::endl;
            Ispisi(*it->second);
        }
    }
    void IzlistajKnjige() const {
        for(auto it = m_knjiga.begin(); it != m_knjiga.end(); it++) {
            std::cout << "Evidencijski broj: "<<it->first<< std::endl;
            Ispisi(*it->second);
            std::cout<<std::endl;
        }
    }
    void ZaduziKnjigu(int ev_broj,int cl_broj) {
        auto it1(m_knjiga.find(ev_broj));
        if(it1==m_knjiga.end()) throw std::logic_error ("Knjiga nije nadjena");
        auto it2(m_korisnik.find(cl_broj));
        if(it2==m_korisnik.end()) throw std::logic_error ("Korisnik nije nadjen");
        auto it3(m_knjiga.find(ev_broj));
        if(it3->second->DaLiJeZaduzena()) throw std::logic_error ("Knjiga vec zaduzena");
        it3->second->ZaduziKnjigu(*it2->second);
    }
    void RazduziKnjigu(int ev_broj) {
        auto it1(m_knjiga.find(ev_broj));
        if(it1==m_knjiga.end()) throw std::logic_error ("Knjiga nije nadjena");
        auto it3(m_knjiga.find(ev_broj));
        if(!it3->second->DaLiJeZaduzena()) throw std::logic_error ("Knjiga nije zaduzena");
        it1->second->RazduziKnjigu();

    }
    void PrikaziZaduzenja(int cl_broj) const {
        bool nadjen(false);
        auto it1(m_korisnik.find(cl_broj));
        if(it1==m_korisnik.end()) throw std::logic_error ("Korisnik nije nadjen");
        for(auto it = m_knjiga.begin(); it != m_knjiga.end(); it++)
        if((it->second->DajKodKogaJe()) == it1->second)
                nadjen=true;
        if(!nadjen) std::cout<<"Nema zaduzenja za tog korisnika!";
        else for(auto it = m_knjiga.begin(); it != m_knjiga.end(); it++) {
            if((it->second->DajKodKogaJe())==it1->second) {
                std::cout << "Evidencijski broj: "<<it->first<< std::endl;
            std::cout << "Naslov: "<< it->second->DajNaslov() << std::endl;
            std::cout << "Pisac: "<< it->second->DajAutora() << std::endl;
            std::cout << "Zanr: "<< it->second->DajZanr() << std::endl;
            std::cout <<"Godina izdavanja: "<< it->second->DajGodinuIzdavanja() << std::endl<<std::endl;
            }
        }
    }
};

void UnesiKnjigu(Biblioteka &b, const long long int &ev_broj)
{ 
    std::cin.ignore(1000, '\n');
    std::cin.clear();
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    std::cout << "Unesite naslov knjge: ";
    std::getline(std::cin, naslov);
    std::cout << "Unesite ime pisca: ";
    std::getline(std::cin, ime_pisca);
    std::cout << "Unesite zanr knjige: ";
    std::getline(std::cin, zanr);
    std::cout << "Unesite godinu_izdavanja: ";
    std::cin >> godina_izdavanja;
    b.RegistrirajNovuKnjigu(ev_broj, naslov, ime_pisca, zanr, godina_izdavanja);
}

void UnesiKorisnika(Biblioteka &b, const long long int &ev_broj)
{ 
    std::cin.ignore(1000, '\n');
    std::cin.clear();
    std::string ime, prezime, adresa, telefon;
    std::cout << "Unesite ime korisnika:  ";
    std::getline(std::cin, ime);
    std::cout << "Unesite prezime korisnika: ";
    std::getline(std::cin, prezime);
    std::cout << "Unesite adresu korisnika: ";
    std::getline(std::cin, adresa);
    std::cout << "Unesite telefon korisnika: ";
    std::getline(std::cin, telefon);
    b.RegistrirajNovogKorisnika(ev_broj, ime, prezime, adresa, telefon);
}

void ZaduziKnjigu(Biblioteka &b)
{
    long long int ev_broj, cl_broj;
    std::cout << "Unesite evidencijski broj knjige: ";
    std::cin >> ev_broj;
    std::cout << "Unesite evidencijski broj korisnika: ";
    std::cin >> cl_broj;
    b.ZaduziKnjigu(ev_broj, cl_broj);
}

void RazduziKnjigu(Biblioteka &b)
{
    long long int ev_broj;
    std::cout << "Unesite evidencijski broj knjige: ";
    std::cin >> ev_broj;
    b.RazduziKnjigu(ev_broj);
}

void PrikaziZaduzenja(Biblioteka &b)
{
    long long int cl_broj;
    std::cout << "Unesite clanski broj korisnika: ";
    std::cin >> cl_broj;
    b.PrikaziZaduzenja(cl_broj);
}

void NadjiKnjigu(Biblioteka &b)
{
    long long int ev_broj;
    std::cout << "Unesite evidencijski broj knjige: ";
    std::cin >> ev_broj;
    Ispisi(b.NadjiKnjigu(ev_broj));
}

void NadjiKorisnika(Biblioteka &b)
{
    long long int cl_broj;
    std::cout << "Unesite clanski broj korisnika: ";
    std::cin >> cl_broj;
    Ispisi(b.NadjiKorisnika(cl_broj));
}


int main ()
{
    Biblioteka ETF;
    std::cout << "DOBRODOŠLI U ETF BIBLIOTEKU" << std::endl;
    long long int broj_knjiga{1}, broj_korisnika{1};
    while (true) 
    {
        int komanda{-1};
        std::cout << "1 - Dodaj novu knjigu" << std::endl;
        std::cout << "2 - Dodaj novog korisnika" << std::endl;
        std::cout << "3 - Zaduzi knjigu" << std::endl;
        std::cout << "4 - Razduzi knjigu" << std::endl;
        std::cout << "5 - Izlistaj sve knjige" << std::endl;
        std::cout << "6 - Izlistaj sve korisnike" << std::endl;
        std::cout << "7 - Pronadji knjigu" << std::endl;
        std::cout << "8 - Pronadji korisnika" << std::endl;
        std::cout << "9 - Prikazi zaduzenja" << std::endl;
        std::cout << "10 - Kraj" << std::endl;
        std::cout << "Izaberite opciju:";
        std::cin >> komanda;
        switch (komanda) {
        case 1:
            TijeloIzuzetka(std::logic_error, { UnesiKnjigu(ETF, broj_knjiga++); }); 
            break;
        case 2:
            TijeloIzuzetka(std::logic_error, { UnesiKorisnika(ETF, broj_korisnika++); }); 
            break;
        case 3:
            TijeloIzuzetka(std::logic_error, { ZaduziKnjigu(ETF); }); 
            break;
        case 4:
            TijeloIzuzetka(std::logic_error, { RazduziKnjigu(ETF); }); 
            break;
        case 5:
            ETF.IzlistajKnjige(); 
            break;
        case 6:
            ETF.IzlistajKorisnike(); 
            break;
        case 7:
            TijeloIzuzetka(std::logic_error, { NadjiKnjigu(ETF); });
            break;
        case 8:
            TijeloIzuzetka(std::logic_error, { NadjiKorisnika(ETF); });
            break;
        case 9:
            TijeloIzuzetka(std::logic_error, { PrikaziZaduzenja(ETF); });
            break;
        case 10:
            std::cout << "DOVIDJENJA!!!" << std::endl;
            break;
        default:
            std::cout << "Unijeli ste neispravnu komandu!!!" << std::endl;
            break;
        }
        if (komanda == 10) break;
        
    }
    return 0;
}
