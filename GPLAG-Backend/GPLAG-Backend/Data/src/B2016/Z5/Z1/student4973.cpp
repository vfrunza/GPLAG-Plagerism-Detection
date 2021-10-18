/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <iomanip>


using namespace std;

struct Korisnik {
    string ime;
    string prezime;
    string adresa;
    string telefon;
    
    Korisnik(string ime,string prezime,string adresa,string telefon):
        ime(ime),prezime(prezime),adresa(adresa),telefon(telefon){};
    
    void Ispisi() {
        cout<<"Ime i prezime: "<<ime<<" "<<prezime<<endl;
        cout<<"Adresa: "<<adresa<<endl;
        cout<<"Broj telefona: "<<telefon<<endl<<endl;
    }

};


class Knjiga
{
    string naslov;
    string imepisca;
    string zanr;
    int godinaizdavanja;
    Korisnik *kod_koga_je;

public:
    Knjiga(string naslov,string imepisca,string zanr,int godinaizdavanja):
        naslov(naslov),imepisca(imepisca),zanr(zanr),godinaizdavanja(godinaizdavanja),kod_koga_je(nullptr) {}
    string DajNaslov() const {
        return naslov;
    }
    string DajAutora() const {
        return imepisca;
    }
    string DajZanr() const {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return godinaizdavanja;
    }
    Korisnik *DajKodKogaJe()const {
        return kod_koga_je;
    }
    void ZaduziKnjigu(Korisnik &k) {
        kod_koga_je=&k;
    }
    void RazduziKnjigu() {
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzena() const {
        if(kod_koga_je==nullptr) return false;
        return true;
    }
    void Ispisi() const;
};

void Knjiga::Ispisi() const
{
    cout<<"Naslov: "<<DajNaslov()<<endl;
    cout<<"Pisac: "<<DajAutora()<<endl;
    cout<<"Zanr: "<<DajZanr()<<endl;
    cout<<"Godina izdavanja: "<<DajGodinuIzdavanja()<<endl;
    if(DajKodKogaJe()!=nullptr) 
    cout<<"Zaduzena kod korisnika: "<<DajKodKogaJe()->ime<<" "<<DajKodKogaJe()->prezime<<endl;
    cout<<endl;
}


class Biblioteka
{
    
    map<int,Korisnik*>m1;
    map<int,Knjiga*>m2;


public:
    Biblioteka() {};
    Biblioteka(Biblioteka &b)=delete;
    Biblioteka &operator=(Biblioteka &b)=delete;
    ~Biblioteka()
    {
        for(auto i=m1.begin();i!=m1.end();i++)
            delete i->second;
            
        for(auto i=m2.begin();i!=m2.end();i++)
            delete i->second;
    }
    void RegistrirajNovogKorisnika(int clanski_broj,string ime,string prezime,string adresa,string telefon)
    {
        m1.insert(make_pair(clanski_broj,new Korisnik(ime,prezime,adresa,telefon)));
    }
    void RegistrirajNovuKnjigu(int evidencijski_broj,string naslov,string imepisca,string zanr,int godinaizdavanja)
    {
        m2.insert(make_pair(evidencijski_broj,new Knjiga(naslov,imepisca,zanr,godinaizdavanja)));
    }
    Korisnik &NadjiKorisnika(int clanski_broj)
    {
        return *m1[clanski_broj];
    }
    Knjiga &NadjiKnjigu(int evidencijski_broj) 
    {
        return *m2[evidencijski_broj];
    }
    void IzlistajKorisnike() const
    {
        for(auto i:m1) 
        {   cout<<"Clanski broj: "<<i.first<<endl;
            i.second->Ispisi();
        }
    }
    void IzlistajKnjige() const
    {
        for(auto i:m2) 
        {   cout<<"Evidencijski broj: "<<i.first<<endl;
            i.second->Ispisi();
        }
    }
    void ZaduziKnjigu(int indexa,int indexb)
    {
        m2[indexa]->ZaduziKnjigu(*m1[indexb]);
    }
    void RazduziKnjigu(int index)
    {
        m2[index]->RazduziKnjigu();
    }
    void PrikaziZaduzenje(int index)
    {
        for(auto i:m2)
        {
            if(m1[index]==i.second->DajKodKogaJe())
            {
                cout<<"Naslov: "<<i.second->DajNaslov()<<endl;
                cout<<"Pisac: "<<i.second->DajAutora()<<endl;
                cout<<"Zanr: "<<i.second->DajZanr()<<endl;
                cout<<"Godina izdavanja: "<<i.second->DajGodinuIzdavanja()<<endl;
                cout<<endl;
            }
        }
    }
};


int main ()
{

  /*  map<int,Korisnik*>m1;
    map<int,Knjiga*>m2;

    for(;;) {
        int n;
        cout<<"Odaberite jednu od opcija:\n 1-Registriraj novog korisnika\n 2-Registriraj novu knjigu\n3-Nadji korisnika\n 4-Nadji knjigu\n 5-Izlistaj korisnike\n 6-Izlistaj knjige\n 7-Zaduzi knjigu\n 8-Razduzi knjigu\n 9-Prikazi zaduzenja\n 10-Izlistaj korisnike1\n 11-Kraj rada";
        cout<<endl;
        cin>>n;
        cin.ignore(1000,'\n');
        if(n==1) { /*registracija novog korisnika
            string ime,prezime,telefon,adresa;
            int clanski_broj;

            cout<<"Clanski broj:->";
            cin>>clanski_broj;
            cout<<"Ime i prezime:->";
            getline(cin,ime);
            getline(cin,prezime);
            cout<<"Adresa->";
            getline(cin,adresa);
            cout<<"Telefon->";
            getline(cin,telefon);
            bool postoji(false);

            for(auto it=m1.begin(); it!=m1.end(); it++) {
                if(clanski_broj==it->key) {
                    postoji=true;
                    break;
                }
            }
            if(postoji) {
                throw logic_error("Korisnik vec postoji");
            } else {
                m1.insert(make_pair(clanski_broj,Korisnik));
                try {
                m1.insert[clanski_broj]=new Korisnik(k);
                } catch(...) {
                    delete 
                }
            }

        }

        if(n==2) { /*registracija nove knjige
            int evidencijski_broj;
            string naslov,imepisca,zanr;
            int godinaizdavanja;

            cout<<"Evidencijski broj:->";
            cin>>evidencijski_broj;
            cout<<"Naslov:->";
            getline(cin,naslov);
            cout<<"Pisac:->";
            getline(cin,imepisca);
            cout<<"Zanr:->";
            getline(cin,zanr);
            cout<<"Godina izdavanja:->";
            cin>>godinaizdavanja;
            bool postoji(false);

            for(auto it=m2.begin(); it!=m2.end(); i++) {
                if(evidencijski_broj==it->key) {
                    postoji=true;
                    break;
                }
            }
            if(postoji) {
                throw range_error("Knjiga vec postoji");
            } else {
                m2.insert(make_pair(evidencijski_broj,Knjiga));
                try {
                    m2[evidencijski_broj]=new Knjiga(k);
                } catch(...) {
                    delete m2[key,value];
                }
            }

        }

        if(n==3) { /*pretraga korisnika
            int clanski_broj;
            cout<<"Clanski broj:->";
            cin>>clanski_broj;
            bool ne_postoji(true);

            for(auto it=m1.begin(); it!=m1.end(); it++) {
                if(clanski_broj==it->key) {
                    it[key,value]->Ispisi;
                    ne_postoji=false;
                    break;
                }
            }
            if(ne_postoji) cout<<"Korisnik nije nadjen";
        }

        if(n==4) { /*pretraga knjiga
            int evidencijski_broj;
            cout<<"Evidencijski broj:->";
            cin>>evidencijski_broj;
            bool ne_postoji(true);
            for(auto it=m2.begin(); it!=m2.end(); it++) {
                if(evidencijski_broj==it->key {
                    ne_postoji=false;
                    m2[key,value]->Ispisi();
                    if(m2[key,value]->DaLiJeZaduzena()) {
                        cout<<"Zaduzena kod korisnika(clanski_broj,ime,prezime):\n"<<m2[key]->DajKodKogaJe()->clanski_broj<<" "<<m2[key]->DajKodKogaJe()->ime<<" "m2[key]->DajKodKogaJe()->prezime<<endl;
                    } else {
                        throw logic_error("Knjiga nije nadjena");
                    }
                }
            }
        }

        if(n==5) { /*izlistaj korisnike
            for(auto it=m1.begin(); it!=m1.end(); it++)
                m1[key,value]->Ispisi;
        }


        if(n==6) /izlistaj knnige/ {
            for(auto it=m2.begin(); it!=m2.end(); it++)
                m2[key,value]->Ispisi();
        }



        if(n==7) { /*zaduzivanje knjige
            int evidencijski_broj,clanski_broj;
            cout<<"Clanski broj:->";
            cin>>clanski_broj;
            cout<<"EvidencijskiBroj:->";
            cin>>evidencijski_broj;
            bool ne_postoji_clan(true);
            int sacuvaj_clana,br1=0;
            for(auto it=m1.begin(); it!=m1.end(); it++) {
                if(clanski_broj==it->key) {
                    br++;
                    ne_postoji_clan=false;
                    sacuvaj_clana=br;
                    break;
                }
            }
            if(ne_postoji_clan) throw logic_error("Korisnik nije nadjen");
            else {
                bool ne_postoji_knjiga(true);
                int sacuvaj_knjigu;
                for(auto it=m2.begin(); it!=m2.end(); it++) {
                    if(evidencijski_broj==it->key) {
                        ne_postoji_knjiga=false;
                        sacuvaj_knjigu=(*it);
                        break;
                    }
                }
                if(ne_postoji_knjiga) throw logic_error("Knjiga nije nadjena");
                else {
                    if(m2[sacuvaj_knjigu]->DaLiJeZaduzena()) throw logic_error("Knjiga vec zaduzena");
                    else {
                        m2[sacuvaj_knjigu]->ZaduziKnjigu(*m1[sacuvaj_clana]);
                    }
                }
            }
        }

        if(n==8) { /*razduzi knjige
            int evidencijski_broj;
            cout<<"Evidencijski broj:->";
            cin>>evidencijski_broj;
            bool ne_postoji(true);
            for(auto it=m2.begin(); it!=m2.end(); i++) {
                if(evidencijski_broj==it->key {
                    m2.i->RazduziKnjigu();
                    ne_postoji=false;
                    break;
                }
            }
            if(ne_postoji) throw logic_error("Knjiga nije nadjena");
        }


        if(n==9) { /*prikazi zaduzenja
            int clanski_broj;
            cout<<"Evidencijski broj:->";
            cin>>clanski_broj;
            bool ne_postoji(true);

            for(auto it=m1.begin(); it!=m1.end(); it++) {
                if(clanski_broj==it->key) {
                    ne_postoji=false;

                    for(auto it1=m2.begin(); itt1!=m2.end(); it1++) {
                        bool nema_zaduzenja(true);
                        if(it1->DajKodKogaJe()==it.Korisnik[i]) {
                            nema_zaduzenja=false;
                            cout<<endl<<"Zaduzena knjiga:->"<<endl;
                            m1.Knjiga[it]->Ispisi();
                        }
                        if(nema_zaduzenja) throw logic_error("Nema zaduzenih knjiga");
                    }
                }
            }
            if(ne_postoji) throw logic_error("Korisnik nije nadjen");
        }

        if(n==10) { /*izlistaj korisnike1
            throw("Izgbija");
        }

        if(n==11) /*kraj rada
            break;
    }

    for(auto it=m1.begin(); it!=m1.end(); it++) delete m1;
    for(auto it1=m2.begin(); it1!=m2.end(); it1) delete m2;
*/
    return 0;
}