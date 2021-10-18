#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

struct Korisnik {
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
    Korisnik(std::string i, std::string p, std::string a, std::string t) { ime=i; prezime=p; adresa=a; telefon=t; }
};

class Knjiga {
    std::string naslov;
    std::string autor;
    std::string zanr;
    int god_izdavanja;
    Korisnik *zaduzeno;
public:
    Knjiga(std::string s1, std::string s2, std::string s3, int g) : naslov(s1), autor(s2), zanr(s3), god_izdavanja(g) {
        zaduzeno=nullptr;
    }
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return autor; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return god_izdavanja; }
    Korisnik *DajKodKogaJe() const { return zaduzeno; }
    void ZaduziKnjigu(Korisnik &k) { zaduzeno=&k; }
    void RazduziKnjigu() { zaduzeno=nullptr; }
    bool DaLiJeZaduzena() const { return zaduzeno; }
};

class Biblioteka {
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
    static void BezZaduzenja(Knjiga* it) {
        std::cout << "Naslov: " << (*it).DajNaslov() << std::endl
                  << "Pisac: " << (*it).DajAutora() << std::endl
                  << "Zanr: " << (*it).DajZanr() << std::endl
                  << "Godina izdavanja: " << (*it).DajGodinuIzdavanja() << std::endl;
    }
public:
    Biblioteka() {}
    ~Biblioteka() { for(auto it=korisnici.begin(); it!=korisnici.end(); it++) delete it->second;
                    for(auto it=knjige.begin(); it!=knjige.end(); it++) delete it->second; }



    void RegistrirajNovogKorisnika(int clanski_br, std::string ime, std::string prezime, std::string adresa, std::string br_tel) {
        auto it(korisnici.find(clanski_br));
        if(it!=korisnici.end()) throw std::logic_error ("Korisnik vec postoji");
        Korisnik* k=nullptr;
        try {
            k=new Korisnik(ime, prezime, adresa, br_tel);
            korisnici.insert(std::make_pair(clanski_br, k));
        } catch (...) {
            throw ("Nema dovoljno memorije");
        }
    }
    
    void RegistrirajNovuKnjigu(int ident_broj, std::string naslov, std::string autor, std::string zanr, int god) {
        auto it(knjige.find(ident_broj));
        if(it!=knjige.end()) throw std::logic_error ("Knjiga vec postoji");
        Knjiga* k=nullptr;
        try {
            k=new Knjiga(naslov, autor, zanr, god);
            knjige.insert(std::make_pair(ident_broj, k));
        } catch (...) {
            throw ("Nema dovoljno memorije");
        }
    }
    
    Korisnik &NadjiKorisnika (int clanski_br) const {
        auto it(korisnici.find(clanski_br));
        return *(it->second);
    }
    
    Knjiga &NadjiKnjigu (int ident_broj) const {
        auto it(knjige.find(ident_broj));
        return *(it->second);
    }

    void IzlistajKorisnike() const {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
            std::cout << "\nClanski broj: " << it->first << std::endl
                      << "Ime i prezime: " << (*(it->second)).ime << " " << (*(it->second)).prezime << std::endl
                      << "Adresa: " << (*(it->second)).adresa << std::endl
                      << "Broj telefona: " << (*(it->second)).telefon << std::endl;
        }
    }
    
    void IzlistajKnjige() const {
        for(auto it=knjige.begin(); it!=knjige.end(); it++) {
            std::cout << "\nEvidencijski broj: " << it->first << std::endl
                      << "Naslov: " << (*(it->second)).DajNaslov() << std::endl
                      << "Pisac: " << (*(it->second)).DajAutora() << std::endl
                      << "Zanr: " << (*(it->second)).DajZanr() << std::endl
                      << "Godina izdavanja: " << (*(it->second)).DajGodinuIzdavanja() << std::endl;
            if((it->second)->DaLiJeZaduzena())
                std::cout << "Zaduzena kod korisnika: " << ((*(it->second)).DajKodKogaJe())->ime << " " 
                            << ((*(it->second)).DajKodKogaJe())->prezime << std::endl;
        }
    }
    
    void ZaduziKnjigu(int ident_broj, int clanski_br) {
        auto it1(knjige.find(ident_broj));
        if(it1==knjige.end()) throw std::logic_error ("Knjiga nije nadjena");
        auto it2(korisnici.find(clanski_br));
        if(it2==korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
        if(NadjiKnjigu(ident_broj).DaLiJeZaduzena()) throw std::logic_error ("Knjiga vec zaduzena");
        NadjiKnjigu(ident_broj).ZaduziKnjigu(NadjiKorisnika(clanski_br));
    }

    void RazduziKnjigu(int ident_broj) {
        auto it(knjige.find(ident_broj));
        if(it==knjige.end()) throw std::logic_error ("Knjiga nije nadjena");
        if(!(NadjiKnjigu(ident_broj).DaLiJeZaduzena())) throw std::logic_error ("Knjiga nije zaduzena");
        NadjiKnjigu(ident_broj).RazduziKnjigu();
    }
    
    void PrikaziZaduzenja(int clanski_br) const {
        auto itk(korisnici.find(clanski_br));
        if(itk==korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
        Korisnik k(NadjiKorisnika(clanski_br));
        int brojac(0);
        for(auto it=knjige.begin(); it!=knjige.end(); it++) {
            Korisnik x(*((it->second)->DajKodKogaJe()));
            if(x.ime==k.ime && x.prezime==k.prezime && x.adresa==k.adresa && x.telefon==k.telefon) {
                    brojac++;
                    std::cout << "\nEvidencijski broj: " << it->first << std::endl;
                    BezZaduzenja(it->second);
            }
        }
        if(brojac==0) std::cout << "Nema zaduzenja za tog korisnika";
    }
};


int main () {
    
    Biblioteka b;
    int i(-1), j(0);
    do {
        std::cout << "Odaberite opciju: 1 za manipulaciju baze knjiga, 2 za manipulaciju baze korisnika, 0 za izlaz: " ; 
        std::cin >> i;
        if(i==0) break;
        if(i==1) {
            std::cout << "Odaberite opciju: 1 za vracanje na prethodni meni, 2 za registraciju nove knjige, 3 za zaduzenje knjige, "
            << "4 za razduzenje knjige, 5 za ispis knjiga u biblioteci: ";
            std::cin >> j;
            if(j==1) continue;
            
            else if(j==2) {
                std::string n, a, z;
                int br, god;
                std::cout << "Unesite identifikacijski broj: ";
                std::cin >> br;
                std::cout << "Unesite naslov: ";
                std::cin.ignore(10000, '\n');
                std::getline(std::cin, n);
                std::cout << "Unesite autora: ";
                std::getline(std::cin, a);
                std::cout << "Unesite zanr: ";
                std::getline(std::cin, z);
                std::cout << "Unesite godinu izdavanja: ";
                std::cin >> god;
                try {
                    b.RegistrirajNovuKnjigu(br, n, a, z, god);
                } catch(std::logic_error e) {
                    std::cout << "Greska: " << e.what() << "\n\n";
                } catch(...) {
                    std::cout << "Nije uspjela registracija nove knjige.\n\n";
                    continue;
                }
                std::cout << "Knjiga je uspjesno registrirana.\n\n";
            }
            
            else if(j==3) {
                int id(-1), cl(-1);
                std::cout << "Unesite identifikacijski broj knjige i clanski broj korisnika: ";
                std::cin >> id >> cl;
                try {
                    b.ZaduziKnjigu(id, cl);
                } catch(std::logic_error e) {
                    std::cout << "Greska: " << e.what() << std::endl << std::endl;
                    continue;
                }
                std::cout << "Knjiga je uspjesno zaduzena.\n\n";
            }
            
            else if(j==4) {
                int id(-1);
                std::cout << "Unesite identifikacijski broj knjige: ";
                std::cin >> id;
                try {
                    b.RazduziKnjigu(id);
                }catch(std::logic_error e) {
                    std::cout << "Greska: " << e.what() << std::endl << std::endl;
                    continue;
                }
                std::cout << "Knjiga je uspjesno razduzena.\n\n";
            }
            
            else if(j==5) {
                b.IzlistajKnjige();
                std::cout << "\n\n";
            }
            else {
                std::cout << "Pogresan unos, probajte ponovo.\n\n";
                continue;
            }
        }
        
        if(i==2) {
            std::cout << "Odaberite opciju: 1 za vracanje na prethodni meni, 2 za registraciju novog korisnika, 3 za zaduzenje korisnika, "
            << "4 za ispis zaduzenja korisnika, 5 za ispis svih korisnika biblioteke: ";
            std::cin >> j;
            if(j==1) continue;
            
            else if(j==2) {
                std::string i, p, a, tel;
                int cl;
                std::cout << "Unesite podatke novog korisika: \nClanski broj: ";
                std::cin >> cl;
                std::cout << "Ime: ";
                std::cin.ignore(10000, '\n');
                std::getline(std::cin, i);
                std::cout << "Prezime: ";
                std::getline(std::cin, p);
                std::cout << "Adresa: ";
                std::getline(std::cin, a);
                std::cout << "Broj telefona: ";
                std::getline(std::cin, tel);
                try {
                    b.RegistrirajNovogKorisnika(cl, i, p, a, tel);
                } catch(std::logic_error e) {
                    std::cout << "Greska: " << e.what() << "\n\n";
                } catch(...) {
                    std::cout << "Nije uspjela registracija novog korisnika.\n\n";
                    continue;
                }
                std::cout << "Korisnik je uspjesno registriran.\n\n";
            }
            
            else if(j==3) {
                int id(-1), cl(-1);
                std::cout << "Unesite identifikacijski broj knjige i clanski broj korisnika: ";
                std::cin >> id >> cl;
                try {
                    b.ZaduziKnjigu(id, cl);
                } catch(std::logic_error e) {
                    std::cout << "Greska: " << e.what() << std::endl << std::endl;
                    continue;
                }
                std::cout << "Korisnik je uspjesno zaduzio knjigu.\n\n";
            }
            
            else if(j==4) {
                int cl;
                std::cout << "Unesite clanski broj korisnika: ";
                std::cin >> cl;
                b.PrikaziZaduzenja(cl);
                std::cout << "\n\n";
            }
            
            else if(j==5) {
                b.IzlistajKorisnike();
                std::cout << "\n\n";
            }
            
            else {
                std::cout << "Pogresan unos, probajte ponovo.\n\n";
                continue;
            }
        }
        
        if(i!=1 && i!=2 && i!=0) {
            std::cout << "Pogresan unos, probajte ponovo.\n\n";
            i=-1;
            continue;
        }
    } while(i!=0);

	return 0;
}