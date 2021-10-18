/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>
#include <utility>

struct Korisnik {
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};

class Knjiga {
    std::string naslovKnjige;
    std::string autorKnjige;
    std::string zanrKnjige;
    int godinaIzdavanjaKnjige;
    Korisnik *zaduzioKorisnik=nullptr;
    
    public:
    Knjiga(std::string naslovKnjige, std::string autorKnjige, std::string zanrKnjige, int godinaIzdavanjaKnjige){
        this->naslovKnjige=naslovKnjige;
        this->autorKnjige=autorKnjige;
        this->zanrKnjige=zanrKnjige;
        this->godinaIzdavanjaKnjige=godinaIzdavanjaKnjige;
    }
    
    std::string DajNaslov(){return naslovKnjige;}
    std::string DajAutora(){return autorKnjige;}
    std::string DajZanr(){return zanrKnjige;}
    int DajGodinuIzdavanja(){return godinaIzdavanjaKnjige;}
    Korisnik *DajKodKogaJe(){return zaduzioKorisnik;}
    void ZaduziKnjigu(Korisnik &korisnik){ zaduzioKorisnik=&korisnik;}
    void RazduziKnjigu(){zaduzioKorisnik=nullptr;}
    bool DaLiJeZaduzena(){
        if(zaduzioKorisnik==nullptr) return false;
        return true;
    }
    
};

class Biblioteka {
    std::map<int, Korisnik*> sviKorisnici;
    std::map<int, Knjiga*> sveKnjige;
    
    public:
    ~Biblioteka(){
         for(auto knjiga: sveKnjige){
            delete knjiga.second;
            knjiga.second=nullptr;
        }
        sveKnjige.erase(sveKnjige.begin(), sveKnjige.end());
        
        for(auto korisnik: sviKorisnici){
            delete korisnik.second;
            korisnik.second=nullptr;
        }
        sviKorisnici.erase(sviKorisnici.begin(), sviKorisnici.end());
    }
    Biblioteka() {}
    Biblioteka(Biblioteka &biblioteka){
        for(auto knjiga: biblioteka.sveKnjige){
            int id = knjiga.first;
            Knjiga *novaKnjiga=new Knjiga(knjiga.second->DajNaslov(), knjiga.second->DajAutora(), knjiga.second->DajZanr(), knjiga.second->DajGodinuIzdavanja());
        
            if(knjiga.second->DaLiJeZaduzena()==true){
                Korisnik kodKorisnika=*(knjiga.second->DajKodKogaJe());
                novaKnjiga->ZaduziKnjigu(kodKorisnika);
            }
            sveKnjige.insert(std::make_pair(id,novaKnjiga));
        }
        
        for(auto korisnik: biblioteka.sviKorisnici){
            int id=korisnik.first;
            Korisnik *noviKorisnik=new Korisnik();
            noviKorisnik->ime=korisnik.second->ime;
            noviKorisnik->prezime=korisnik.second->prezime;
            noviKorisnik->adresa=korisnik.second->adresa;
            noviKorisnik->telefon=korisnik.second->telefon;
            
            sviKorisnici.insert(std::make_pair(id,noviKorisnik));
        }
    }
    
    Biblioteka &operator= (Biblioteka &biblioteka){
        if(&biblioteka==this) return *this;
        //desktruktor
        for(auto knjiga: sveKnjige){
            delete knjiga.second;
            knjiga.second=nullptr;
        }
        sveKnjige.erase(sveKnjige.begin(), sveKnjige.end());
        
        for(auto korisnik: sviKorisnici){
            delete korisnik.second;
            korisnik.second=nullptr;
        }
        sviKorisnici.erase(sviKorisnici.begin(), sviKorisnici.end());
        //kopirajuci konstruktor
        for(auto knjiga: biblioteka.sveKnjige){
            int id = knjiga.first;
            Knjiga *novaKnjiga=new Knjiga(knjiga.second->DajNaslov(), knjiga.second->DajAutora(), knjiga.second->DajZanr(), knjiga.second->DajGodinuIzdavanja());
        
            if(((knjiga.second)->DaLiJeZaduzena())==true){
                Korisnik kodKorisnika=*(knjiga.second->DajKodKogaJe());
                novaKnjiga->ZaduziKnjigu(kodKorisnika);
            }
            sveKnjige.insert(std::make_pair(id,novaKnjiga));
        }
        
        for(auto korisnik: biblioteka.sviKorisnici){
            int id=korisnik.first;
            Korisnik *noviKorisnik=new Korisnik();
            noviKorisnik->ime=korisnik.second->ime;
            noviKorisnik->prezime=korisnik.second->prezime;
            noviKorisnik->adresa=korisnik.second->adresa;
            noviKorisnik->telefon=korisnik.second->telefon;
            
            sviKorisnici.insert(std::make_pair(id,noviKorisnik));
        }
        return *this;
        
    }
    
    void RegistrirajNovogKorisnika(int clanskiBroj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
        for(auto korisnik: sviKorisnici){
            if(korisnik.first == clanskiBroj) throw std::logic_error("Korisnik vec postoji");
        }
        
            Korisnik *noviKorisnik=new Korisnik();
            noviKorisnik->ime=ime;
            noviKorisnik->prezime=prezime;
            noviKorisnik->adresa=adresa;
            noviKorisnik->telefon=telefon;
            
            sviKorisnici[clanskiBroj]=noviKorisnik;
            noviKorisnik=nullptr;
    }
    
    void RegistrirajNovuKnjigu(int evidencijskiBrojKnjige, std::string naslovKnjige, std::string autorKnjige, std::string zanrKnjige, int godinaIzdavanjaKnjige){
        for(auto knjiga: sveKnjige){
            if(knjiga.first==evidencijskiBrojKnjige) throw std::logic_error("Knjiga vec postoji");
        }
        Knjiga *novaKnjiga=new Knjiga(naslovKnjige,autorKnjige,zanrKnjige,godinaIzdavanjaKnjige);
        sveKnjige.insert(std::make_pair(evidencijskiBrojKnjige,novaKnjiga));
        novaKnjiga=nullptr;
        
        
        
    }
    
    Korisnik &NadjiKorisnika(int clanskiBroj){
        for(auto korisnik: sviKorisnici){
            if(korisnik.first==clanskiBroj) return *(sviKorisnici[clanskiBroj]);
        }
        throw std::logic_error("Korisnik nije nadjen");
    }
    
    Knjiga &NadjiKnjigu(int evidencijskiBrojKnjige){
        for(auto knjiga: sveKnjige){
            if(knjiga.first==evidencijskiBrojKnjige) return *(sveKnjige[evidencijskiBrojKnjige]);
        }
        throw std::logic_error("Knjiga nije nadjena");
    }
    
    void IzlistajKorisnike(){
        for(auto korisnik: sviKorisnici){
            std::cout<<"Clanski broj: "<<korisnik.first<<std::endl;
            //IspisiKorisnika(*(korisnik.second));
            std::cout<<"Ime i prezime: "<<(korisnik.second)->ime<<" "<<(korisnik.second)->prezime<<std::endl;
            std::cout<<"Adresa: "<<(korisnik.second)->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<(korisnik.second)->telefon<<std::endl;
           // std::cout<<std::endl;
        }
    }
    
    void IzlistajKnjige(){
        for(auto knjiga: sveKnjige){
            std::cout<<"Evidencijski broj: "<<knjiga.first<<std::endl;
            
            //IspisiKorisnika(*(korisnik.second));
            std::cout<<"Naslov: "<<(knjiga.second)->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<(knjiga.second)->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<(knjiga.second)->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<(knjiga.second)->DajGodinuIzdavanja()<<std::endl;
            if((knjiga.second)->DaLiJeZaduzena()==true){
                Korisnik kodKorisnika=*(knjiga.second)->DajKodKogaJe();
                for(auto korisnik: sviKorisnici){
                    if((korisnik.second)->ime==kodKorisnika.ime && (korisnik.second)->prezime==kodKorisnika.prezime && (korisnik.second)->adresa==kodKorisnika.adresa && (korisnik.second)->telefon==kodKorisnika.telefon)
                        std::cout<<"Zaduzena kod korisnika: "<<kodKorisnika.ime<<" "<<kodKorisnika.prezime<<std::endl;
                }
            }
            std::cout<<std::endl;
        }
    }
    
    void ZaduziKnjigu(int evidencijskiBrojKnjige, int clanskiBroj){
        bool daLiPostoji=false;
        for(auto knjiga:sveKnjige){
            if(knjiga.first==evidencijskiBrojKnjige){
                daLiPostoji=true;
                break;
            }
        }
            if(daLiPostoji==false) throw std::logic_error("Knjiga nije nadjena");
            daLiPostoji=false;
            for(auto korisnik:sviKorisnici){
                if(korisnik.first==clanskiBroj){
                    daLiPostoji=true;
                    break;
                }
            }
                if(daLiPostoji==false) throw std::domain_error("Korisnik nije nadjen");
                if(sveKnjige[evidencijskiBrojKnjige]->DaLiJeZaduzena()==true) throw std::logic_error("Knjiga vec zaduzena");
                sveKnjige[evidencijskiBrojKnjige]->ZaduziKnjigu(*(sviKorisnici[clanskiBroj]));
            }
            
    void RazduziKnjigu(int evidencijskiBrojKnjige){
        bool daLiPostoji=false;
        for (auto knjiga:sveKnjige){
            if(knjiga.first==evidencijskiBrojKnjige){
                if(((knjiga.second)->DaLiJeZaduzena())==true) {
                    (knjiga.second)->RazduziKnjigu();
                    daLiPostoji=true;
                    break;
                }
                else throw std::logic_error("Knjiga nije zaduzena");
            }
        }
        if(daLiPostoji==false) throw std::logic_error("Knjiga nije nadjena");
    }
    
    void PrikaziZaduzenja(int clanskiBroj){
        bool daLiPostoji=false;
        for(auto korisnik:sviKorisnici){
            if(korisnik.first==clanskiBroj){
                daLiPostoji=true;
                break;
            }
        }
        if(daLiPostoji==false) throw std::logic_error("Korisnik nije nadjen");
        Korisnik k=*(sviKorisnici[clanskiBroj]);
        bool posjeduje=false;
        for(auto knjiga:sveKnjige){
               if((knjiga.second)->DaLiJeZaduzena()==true){
                Korisnik kodKorisnika=*(knjiga.second)->DajKodKogaJe();
               
                    if(k.ime==kodKorisnika.ime && k.prezime==kodKorisnika.prezime && k.adresa==kodKorisnika.adresa && k.telefon==kodKorisnika.telefon){
                        posjeduje=true;
                        std::cout<<"Evidencijski broj: "<<knjiga.first<<std::endl;
                        std::cout<<"Naslov: "<<(knjiga.second)->DajNaslov()<<std::endl;
                        std::cout<<"Pisac: "<<(knjiga.second)->DajAutora()<<std::endl;
                        std::cout<<"Zanr: "<<(knjiga.second)->DajZanr()<<std::endl;
                        std::cout<<"Godina izdavanja: "<<(knjiga.second)->DajGodinuIzdavanja()<<std::endl;
            
                        std::cout<<"Zaduzena kod korisnika: "<<k.ime<<" "<<k.prezime<<std::endl;
                }
            }
            std::cout<<std::endl;
        }
        if(posjeduje==false) std::cout<<"Nema zaduzenja za tog korisnika"<<std::endl;
    }
    
    
};
 


int main ()
{
	return 0;
}