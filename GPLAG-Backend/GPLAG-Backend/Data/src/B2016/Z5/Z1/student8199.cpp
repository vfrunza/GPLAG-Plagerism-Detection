/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Korisnik
{
    string ime, prezime, adresa, telefon;
    Korisnik(string i, string p, string a, string t)
    {
        ime = i;
        prezime = p;
        adresa = a;
        telefon = t;
    }
    Korisnik(){}
};

class Knjiga
{
    string naslov, pisac, zanr;
    int godina;
    Korisnik *pok;
    
    public:
    Knjiga(string n, string p, string z, int g):naslov(n), pisac(p), zanr(z), godina(g)
    {
        pok = nullptr;
    }
    
    ~Knjiga()
    {
        delete pok;
    }
    
    string DajNaslov() {return naslov;}
    string DajAutora() {return pisac;}
    string DajZanr() {return zanr;}
    int DajGodinuIzdavanja() {return godina;}
    Korisnik *DajKodKogaJe() {return pok;}
    
    void ZaduziKnjigu(Korisnik k)
    {
        pok = new Korisnik(k);
    }
    
    void RazduziKnjigu()
    {
        delete pok;
        pok = nullptr;
    }
    
    bool DaLiJeZaduzena()
    {
        return pok;
    }
};

class Biblioteka
{
    map<int, Korisnik*> korisnici;
    map<int, Knjiga*> knjige;
    
    public:
    Biblioteka() {}
    
    Biblioteka(Biblioteka &b)
    {
        auto iter1 = b.korisnici.begin();
        while (iter1 != b.korisnici.end())
        {
            korisnici.insert(*iter1);
            iter1++;
        }
        
        auto iter2 = b.knjige.begin();
        while (iter2 != b.knjige.end())
        {
            knjige.insert(*iter2);
            iter2++;
        }
    }
    
    void RegistrirajNovogKorisnika(int id, string i, string p, string a, string t)
    {
        if (korisnici.find(id) != korisnici.end()) throw logic_error ("Korisnik vec postoji");
        korisnici.insert(make_pair(id, new Korisnik(i, p, a, t)));
    }
    
    void RegistrirajNovuKnjigu(int id, string i, string p, string z, int g)
    {
        if (knjige.find(id) != knjige.end()) throw logic_error ("Knjiga vec postoji");
        knjige.insert(make_pair(id, new Knjiga(i, p, z, g)));
    }
    
    void IzlistajKorisnike()
    {
        auto iter = korisnici.begin();
        while (iter != korisnici.end())
        {
            cout << "Clanski broj: " << iter->first << endl;
            cout << "Ime i prezime: " << iter->second->ime << " " << iter->second->prezime << endl;
            cout << "Adresa: " << iter->second->adresa << endl;
            cout << "Broj telefona: " << iter->second->telefon << endl;
            iter++;
        }
    }
    
    void IzlistajKnjige()
    {
        auto iter = knjige.begin();
        while (iter != knjige.end())
        {
            cout << "Evidencijski broj: " << iter->first << endl;
            cout << "Naslov: " << iter->second->DajNaslov() << endl;
            cout << "Pisac: " << iter->second->DajAutora() << endl;
            cout << "Zanr: " << iter->second->DajZanr() << endl;
            cout << "Godina izdavanja: " << iter->second->DajGodinuIzdavanja() << endl;
            if (iter->second->DaLiJeZaduzena()) cout << "Zaduzena kod korisnika: " << iter->second->DajKodKogaJe()->ime << " " << iter->second->DajKodKogaJe()->prezime << endl;
            iter++;
        }
    }
    
    Korisnik NadjiKorisnika(int id)
    {
        if (korisnici.find(id) == korisnici.end()) throw logic_error ("Knjiga ne postoji");
        auto iter = korisnici.find(id);
        return *iter->second;
    }
    
    Knjiga NadjiKnjigu(int id)
    {
        if (knjige.find(id) == knjige.end()) throw logic_error ("Knjiga ne postoji");
        return *knjige.find(id)->second;
    }
    
    void PrikaziZaduzenja(int id)
    {
        if (korisnici.find(id)==korisnici.end()) throw logic_error("Korisnik nije nadjen");
        auto iter = knjige.begin();
        int br = 0;
        while (iter != knjige.end())
        {
            if(iter->second->DaLiJeZaduzena())
            {
                if(iter->second->DajKodKogaJe() != korisnici[id])
                {
                    cout << "Evidencijski broj: " << iter->first << endl;
                    cout << "Naslov: " << iter->second->DajNaslov() << endl;
                    cout << "Pisac: " << iter->second->DajAutora() << endl;
                    cout << "Zanr: " << iter->second->DajZanr() << endl;
                    cout << "Godina izdavanja: " << iter->second->DajGodinuIzdavanja() << endl;
                    br++;
                }
            }
            iter++;
        }
        
        if (!br) throw logic_error("Nema zaduzenja za tog korisnika!");
    }
    
    ~Biblioteka()
    {
        auto iter1 = knjige.begin();
        while(iter1 != knjige.end())
        {
            delete iter1->second;
            iter1++;
        }
        auto iter2 = korisnici.begin();
        while(iter2 != korisnici.end())
        {
            delete iter2->second;
            iter2++;
        }
    }
    
    void ZaduziKnjigu(int id1, int id2)
    {
        if (korisnici.find(id2) == korisnici.end()) throw logic_error ("Knjiga ne postoji");
        if (knjige.find(id1) == knjige.end()) throw logic_error ("Knjiga ne postoji");
        if (knjige[id1]->DaLiJeZaduzena()) throw logic_error ("Knjiga vec zaduzena");
        knjige[id1]->ZaduziKnjigu(*korisnici[id2]);
    }
    
    void RazduziKnjigu(int id1, int id2)
    {
        if (korisnici.find(id2) == korisnici.end()) throw logic_error ("Knjiga ne postoji");
        if (knjige.find(id1) == knjige.end()) throw logic_error ("Knjiga ne postoji");
        knjige[id1]->RazduziKnjigu();
    }
};

int main ()
{
    Biblioteka b;
    try{
        do
        {
            cout << "0 - izlaz, 1 - dodajte knjigu, 2 - dodajte korisnika, 3 - zaduzite knjigu, 4 - razduzite knjigu, 5 - ispiste knjige, 6 - ispiste korisnike" << endl;
            int n;
            cin >> n;
            if (n == 0) return 0;
            
            if (n == 1)
            {
                cout << "Unesite evidencijski broj: ";
                int id;
                cin >> id;
                cin.ignore(10000, '\n');
                cout << "Unesite ime knjige: ";
                string knjiga;
                getline(cin, knjiga);
                cout << "Unesite ime autora: ";
                string autor;
                getline(cin, autor);
                cout << "Unesite zanr: ";
                string zanr;
                getline(cin, zanr);
                cout << "Unesite godinu izdavanja: ";
                int g;
                cin >> g;
                b.RegistrirajNovuKnjigu(id, knjiga, autor, zanr, g);
            }
            
            if (n == 2)
            {
                cout << "Unesite clanski broj: ";
                int id;
                cin >> id;
                cin.ignore(1000, '\n');
                cout << "Unesite ime korisnika: ";
                string ime, prezime;
                getline(cin, ime);
                cout << "Unesite prezime korisnika: ";
                getline(cin, prezime);
                cout << "Unesite adresu korisnika: ";
                string adresa;
                getline(cin, adresa);
                cout << "Unesite broj telefona korisnika: ";
                string telefon;
                getline(cin, telefon);
                
                b.RegistrirajNovogKorisnika(id, ime, prezime, adresa, telefon);
            }
            
            if (n == 3)
            {
                cout << "Unesite clanski broj korisnika: ";
                int id1;
                cin >> id1;
                cout << "Unesite evidencijski broj knjige: ";
                int id2;
                cin >> id2;
                
                b.ZaduziKnjigu(id2, id1);
            }
            
            if (n == 4)
            {
                cout << "Unesite clanski broj korisnika: ";
                int id1;
                cin >> id1;
                cout << "Unesite evidencijski broj knjige: ";
                int id2;
                cin >> id2;
                
                b.RazduziKnjigu(id2, id1);
            }
            
            if (n == 5) b.IzlistajKnjige();
            
            if (n == 6) b.IzlistajKorisnike();
        }
        while (true);
    }
    catch(logic_error e) {
        cout << e.what();
        
    }
	return 0;
}