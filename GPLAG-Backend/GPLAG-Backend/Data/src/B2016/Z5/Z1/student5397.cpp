/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::logic_error;
using std::getline;


struct Korisnik
{
    string ime, prezime, adresa, telefon;
};

static bool operator==(const Korisnik& k1, const Korisnik* k2)
{
    int broj(0);
    
    if (k1.ime==k2->ime)
    {
        broj++;
    }
    
    if (k1.prezime==k2->prezime)
    {
        broj++;
    }
    
    if (k1.adresa==k2->adresa)
    {
        broj++;
    }
    
    if(k1.telefon==k2->telefon)
    {
        broj++;
    }
    
    if (broj==4)
    {
        return true;
    }
    
    return false;
};

class Knjiga
{
    string naslov, pisac, zanr;
    int izdavanje;
    Korisnik *k;
    
    public:
    
    Knjiga (string n, string p, string z, int i)
    {
        naslov=n;
        pisac=p;
        zanr=z;
        izdavanje=i;
        k=nullptr;
    };
    
    string DajNaslov() const {return naslov;};
    string DajAutora() const {return pisac;};
    string DajZanr() const {return zanr;};
    int DajGodinuIzdavanja() const {return izdavanje;};
    Korisnik* DajKodKogaJe() const {return k;};
    
    void ZaduziKnjigu(Korisnik &zad){k=&zad;};
    void RazduziKnjigu(){k=nullptr;};
    bool DaLiJeZaduzena() const
    {
        if (k==nullptr)
        {
            return false;
        }
        
        else
        {
            return true;
        }
    };
};
    class Biblioteka
    {
        map<int,Korisnik*> korisnik;
        map<int,Knjiga*> knjiga;
        
        public:
        
        Biblioteka (){};
        
        Biblioteka (map<int,Korisnik*> kor)
        {
            for (auto it(kor.begin()); it!=kor.end(); it++)
            {
                korisnik[it->first]=new Korisnik (*it->second);
            }
        };
        
        Biblioteka (map<int,Knjiga*> knji)
        {
            for (auto it(knji.begin()); it!=knji.end(); it++)
            {
                knjiga[it->first]=new Knjiga (*it->second);
            }
        };
        
        Biblioteka &operator=(Biblioteka &b)
        {
            for (auto it(b.korisnik.begin()); it!=b.korisnik.end(); it++)
            {
                korisnik[it->first]=new Korisnik (*it->second);
            }
            
            for (auto it(b.knjiga.begin()); it!=b.knjiga.end(); it++)
            {
                knjiga[it->first]=new Knjiga (*it->second);
            }
            
            return *this;
        };
        
        Biblioteka &operator=(Biblioteka &&b)
        {
            korisnik=b.korisnik;
            knjiga=b.knjiga;
            
            for (auto it(b.korisnik.begin()); it!=b.korisnik.end(); it++)
            {
                it->second=nullptr;
            }
            
            for (auto it(b.knjiga.begin()); it!=b.knjiga.end(); it++)
            {
                it->second=nullptr;
            }
            return *this;
        }
        
        Biblioteka(const Biblioteka &b)
        {
            for (auto it(b.korisnik.begin()); it!=b.korisnik.end(); it++)
            {
                korisnik[it->first]=new Korisnik (*it->second);
            }
            
            for (auto it(b.knjiga.begin()); it!=b.knjiga.end(); it++)
            {
                knjiga[it->first]=new Knjiga (*it->second);
            }
        };
        
        Biblioteka(Biblioteka &&b)
        {
            korisnik=b.korisnik;
            knjiga=b.knjiga;
            
            for (auto it(b.korisnik.begin()); it!=b.korisnik.end(); it++)
            {
                it->second=nullptr;
            }
            
            for (auto it(b.knjiga.begin()); it!=b.knjiga.end(); it++)
            {
                it->second=nullptr;
            }
        };
        
        
        
        void RegistrirajNovogKorisnika(int broj, string ime1, string prezime1, string adresa1, string telefon1)
        {
            try
            {
                for (auto it(korisnik.begin()); it!=korisnik.end(); it++)
                {
                    if (it->first==broj) throw logic_error ("Korisnik vec postoji");
                }
                
                Korisnik *k=new Korisnik();
                k->ime=ime1;
                k->prezime=prezime1;
                k->adresa=adresa1;
                k->telefon=telefon1;
                
                korisnik[broj]=k;
            }
            
            catch (logic_error izuzetak)
            {
                cout<<izuzetak.what();
            }
        };
        
        void RegistrirajNovuKnjigu(int broj, string naslov1, string pisac1, string zanr1, int izdavanje1)
        {
            try
            {
                for (auto it(knjiga.begin()); it!=knjiga.end(); it++)
                {
                    if (it->first==broj) throw logic_error ("Knjiga vec postoji");
                }
                
                Knjiga *k=new Knjiga(naslov1, pisac1, zanr1, izdavanje1);
            
                knjiga[broj]=k;
            }
            
            catch (logic_error izuzetak)
            {
                cout<<izuzetak.what();
            }
        };
        
        Korisnik NadjiKorisnika (int broj)
        {
            auto it(korisnik.find(broj));
            if (it==korisnik.end()) throw logic_error ("Korisnik nije nadjen");
           
            return (*it->second);
        };
        
        Knjiga NadjiKnjigu (int broj)
        {
            auto it(knjiga.find(broj));
            if (it==knjiga.end()) throw logic_error ("Knjiga nije nadjena");
                
            return (*it->second);
        };
        
        void IzlistajKorisnike() const
        {
             for (auto it(korisnik.begin()); it!=korisnik.end(); it++)
             {
                Korisnik *k=it->second;
                cout<<"Clanski broj: "<<it->first<<endl;
                cout<<"Ime i prezime: "<<k->ime<<" "<<k->prezime<<endl;
                cout<<"Adresa: "<<k->adresa<<endl;
                cout<<"Broj telefona: "<<k->telefon<<endl;
                cout<<endl;
             }
        };

        void IzlistajKnjige() const
        {
             for (auto it(knjiga.begin()); it!=knjiga.end(); it++)
             {
                Knjiga *k=it->second;
                cout<<"Evidencijski broj: "<<it->first<<endl;
                cout<<"Naslov: "<<(*k).DajNaslov()<<endl;
                cout<<"Pisac: "<<(*k).DajAutora()<<endl;
                cout<<"Zanr: "<<(*k).DajZanr()<<endl;
                cout<<"Godina izdavanja: "<<(*k).DajGodinuIzdavanja()<<endl;
                if ((*k).DaLiJeZaduzena()==true)
                {
                     cout<<"Zaduzena kod korisnika: "<<(*k).DajKodKogaJe()->ime<<" "<<(*k).DajKodKogaJe()->prezime<<endl;
                }
                cout<<endl;
             }
        };
        
        void ZaduziKnjigu(int evidencija, int clan)
        {
            try
            {
                auto it1(knjiga.find(evidencija));
                if (it1==knjiga.end()) throw logic_error ("Knjiga nije nadjena");
                
                else
                {
                    
                    auto it2(korisnik.find(clan));
                    if (it2==korisnik.end()) throw logic_error ("Korisnik nije nadjen");
                    
                    else
                    {
                        Knjiga *k=it1->second;
                        if ((*k).DaLiJeZaduzena()==true) throw logic_error ("Knjiga vec zaduzena");
                        
                        else
                        {
                            Korisnik *kor(it2->second);
                            (*k).ZaduziKnjigu(*kor);
                        }
                    }
                }
            }
            
            catch (logic_error izuzetak)
            {
                cout<<izuzetak.what();
            }
        };
        
        void RazduziKnjigu(int evidencija)
        {
            try
            {
                auto it(knjiga.find(evidencija));
                if (it==knjiga.end()) throw logic_error ("Knjiga nije nadjena");
                
                else
                {
                    Knjiga *k=it->second;
                    if ((*k).DaLiJeZaduzena()==false) throw logic_error ("Knjiga nije zaduzena");
                        
                    else
                    {
                        (*k).RazduziKnjigu();
                    }
                }
            }
            
            
            catch (logic_error izuzetak)
            {
                cout<<izuzetak.what();
            }
        };
        
        void PrikaziZaduzenja(int clan)
        {
            try
            {
                int broj(0);
                
                auto it1(korisnik.find(clan));
                if (it1==korisnik.end()) throw logic_error ("Korisnik nije nadjen");
                
                else
                {
                    Korisnik *kor=it1->second;
                    
                    for (auto it(knjiga.begin()); it!=knjiga.end(); it++)
                    {
                        Knjiga *k=it->second;
                        if ((*k).DaLiJeZaduzena()==true)
                        {
                        
                            if (*kor==(*k).DajKodKogaJe())
                            {
                                cout<<"Evidencijski broj: "<<it->first<<endl;
                                cout<<"Naslov: "<<(*k).DajNaslov()<<endl;
                                cout<<"Pisac: "<<(*k).DajAutora()<<endl;
                                cout<<"Zanr: "<<(*k).DajZanr()<<endl;
                                cout<<"Godina izdavanja: "<<(*k).DajGodinuIzdavanja()<<endl;
                                broj++;
                            }
                        }
                    }
                    
                    if (broj==0) 
                    {
                        cout<<"Nema zaduzenja za tog korisnika!";
                    }
                }
            }
            
            catch (logic_error izuzetak)
            {
                cout<<izuzetak.what();
            }
        };
        
        ~Biblioteka() 
        {
            for (auto it(korisnik.begin()); it!=korisnik.end(); it++)
            {
                delete it->second;
            }
            
            for (auto it(knjiga.begin()); it!=knjiga.end(); it++)
            {
                delete it->second;
            }
        };
    };

int main()
{
    bool izlazak (false);
    int odabir;
    
    Biblioteka b;
try
{
    while (!izlazak)
    {
        cout<<"Odaberite jednu od sljedecih opcija: "<<endl;
        cout<<"1) Registriraj novog korisnika"<<endl;
        cout<<"2) Registriraj novu knjigu"<<endl;
        cout<<"3) Nadji nekog korisnika"<<endl;
        cout<<"4) Nadji neku knjigu"<<endl;
        cout<<"5) Izlistaj korisnike"<<endl;
        cout<<"6) Izlistaj knjige"<<endl;
        cout<<"7) Zaduzi knjigu"<<endl;
        cout<<"8) Razduzi knjigu"<<endl;
        cout<<"9) Prikazi zaduzenja korisnika"<<endl;
        cout<<"10) Izadji iz programa"<<endl;
        cin>>odabir;
        
        if (odabir==1)
        {  
            int broj;
            string ime, prezime, adresa, telefon;
            cout<<"Unesi clanski broj: ";
            cin>>broj;
            cout<<"Unesi ime: ";
            cin>>ime;
            cout<<"Unesi prezime: ";
            cin>>prezime;
            cin.ignore(10000,'\n');
            cout<<"Unesi adresu: ";
            getline(cin,adresa);
            cout<<"Unesi telefon: ";
            getline(cin,telefon);
            
            b.RegistrirajNovogKorisnika(broj, ime, prezime, adresa, telefon);
            cout<<endl;
        }
        
        if (odabir==2)
        {   
            int broj, izdavanje;
            string naslov, pisac, zanr;
            cout<<"Unesi evidencijski broj: ";
            cin>>broj;
            cin.ignore(10000,'\n');
            cout<<"Unesi naslov knjige: ";
            getline(cin,naslov);
            cout<<"Unesi ime pisca: ";
            getline(cin,pisac);
            cout<<"Unesi zanr: ";
            getline(cin,zanr);
            cout<<"Unesi godinu izdavanja: ";
            cin>>izdavanje;
            
            b.RegistrirajNovuKnjigu(broj, naslov, pisac, zanr, izdavanje);
            cout<<endl;
        }

        if (odabir==3)
        {
            int broj;
            
            cout<<"Unesi clanski broj: ";
            cin>>broj;
          
            Korisnik k(b.NadjiKorisnika(broj));
     
            cout<<"Ime i prezime: "<<k.ime<<" "<<k.prezime<<endl;
            cout<<"Adresa: "<<k.adresa<<endl;
            cout<<"Broj telefona: "<<k.telefon<<endl;
        }
        
        if (odabir==4)
        {
            int broj;
            
            cout<<"Unesi evidencijski broj: ";
            cin>>broj;
          
            Knjiga k(b.NadjiKnjigu(broj));
        
            cout<<"Naslov: "<<k.DajNaslov()<<endl;
            cout<<"Pisac: "<<k.DajAutora()<<endl;
            cout<<"Zanr: "<<k.DajZanr()<<endl;
            cout<<"Godina izdavanja: "<<k.DajGodinuIzdavanja()<<endl;
            if (k.DaLiJeZaduzena()==true)
            {
                cout<<"Zaduzena kod korisnika: "<<k.DajKodKogaJe()->ime<<" "<<k.DajKodKogaJe()->prezime<<endl;
            }
        }
        
        if (odabir==5)
        {
            b.IzlistajKorisnike();
        }
        
        if (odabir==6)
        {
            b.IzlistajKnjige();
        }
     
        if (odabir==7)
        {
            int evidencija, clan;
            cout<<"Unesi evidencijski broj knjige: ";
            cin>>evidencija;
            cout<<"Unesi clanski broj korisnika: ";
            cin>>clan;
            b.ZaduziKnjigu(evidencija,clan);
        }
 
        if (odabir==8)
        {
            int evidencija;
            cout<<"Unesi evidencijski broj knjige:";
            cin>>evidencija;
            b.RazduziKnjigu(evidencija);
        }
        
        if (odabir==9)
        {
            int clan;
            cout<<"Unesi clanski broj korisnika: ";
            cin>>clan;
            b.PrikaziZaduzenja(clan);
        }
        
        if (odabir==10)
        {
            izlazak=true;
        }
    }
}

catch (logic_error izuzetak)
{
    cout<<izuzetak.what();
}
    
	return 0;
}