/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
using namespace std;


struct Korisnik{
    string ime, prezime, adresa, telefon;
};

class Knjiga{
    string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *zaduzen;
    public:
    Knjiga(string naslov, string ime_pisca, string zanr, int godina_izdavanja) //: naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), 
   // godina_izdavanja(godina_izdavanja)
   {
        Knjiga::naslov=naslov;
        Knjiga::ime_pisca=ime_pisca;
        Knjiga::zanr=zanr;
        Knjiga::godina_izdavanja=godina_izdavanja;
        Knjiga::zaduzen=nullptr;
    }
    string DajNaslov() const{
        return naslov;
    }
    string DajAutora() const{
        return ime_pisca;
    }
    string DajZanr() const{
        return zanr;
    }
    int DajGodinuIzdavanja() const{
        return godina_izdavanja;
    }
    Korisnik *DajKodKogaJe() const{
        //if(*zaduzen==nullptr) return 0;
        return zaduzen;
    }
    void ZaduziKnjigu(Korisnik &zaduzio_sam);
    void RazduziKnjigu();
    bool DaLiJeZaduzena() const;
    
};

void Knjiga::ZaduziKnjigu(Korisnik &zaduzio_sam){
   zaduzen=&zaduzio_sam;
}
void Knjiga::RazduziKnjigu(){
    zaduzen=0;
}
bool Knjiga::DaLiJeZaduzena()const{
    if(zaduzen!=0) return true;
    return false;
}

class Biblioteka{
    //int ev_br, cl_br;
    map<int, Korisnik*>mapa_korisnika;
    map<int, Knjiga*>mapa_knjiga;
    
    public:
    Biblioteka() {}
   ~Biblioteka(){
        for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
            delete it->second;
        for(auto it1=mapa_knjiga.begin(); it1!=mapa_knjiga.end(); it1++)
             delete it1->second;
    }
   
   Biblioteka(const Biblioteka &b){
       for(auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++){
           mapa_korisnika[it->first]=new Korisnik{it->second->ime, it->second->prezime, it->second->adresa, it->second->telefon};
       }
       for(auto it1=b.mapa_knjiga.begin(); it1!=b.mapa_knjiga.end(); it1++){
           mapa_knjiga[it1->first]=new Knjiga(it1->second->DajNaslov(), it1->second->DajAutora(), it1->second->DajZanr(), it1->second->DajGodinuIzdavanja());
       }
   }
   Biblioteka(Biblioteka &&b);
   Biblioteka &operator=(const Biblioteka &b);
   Biblioteka &operator=(Biblioteka &&b);
    void RegistrirajNovogKorisnika(int cl_br, string ime, string prezime, string adresa, string telefon);
    void RegistrirajNovuKnjigu(int ev_br, string naslov, string ime_pisca, string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int cl_br);
    Knjiga &NadjiKnjigu(int ev_br);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int ev_br, int cl_br);
    void RazduziKnjigu(int ev_br);
    void PrikaziZaduzenja(int cl_br);
};

Biblioteka::Biblioteka(Biblioteka &&b){
       move(b.mapa_knjiga.begin(), b.mapa_knjiga.end(), inserter(mapa_knjiga, mapa_knjiga.begin()));
       move(b.mapa_korisnika.begin(), b.mapa_korisnika.end(), inserter(mapa_korisnika, mapa_korisnika.begin()));
   }
Biblioteka &Biblioteka::operator=(const Biblioteka &b){
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
        delete it->second;
    for(auto it1=mapa_korisnika.begin(); it1!=mapa_korisnika.end(); it1++)
        delete it1->second;
    for(auto it2=b.mapa_korisnika.begin(); it2!=b.mapa_korisnika.end(); it2++){
           mapa_korisnika[it2->first]=new Korisnik{it2->second->ime, it2->second->prezime, it2->second->adresa, it2->second->telefon};
       }
    for(auto it3=b.mapa_knjiga.begin(); it3!=b.mapa_knjiga.end(); it3++){
           mapa_knjiga[it3->first]=new Knjiga(it3->second->DajNaslov(), it3->second->DajAutora(), it3->second->DajZanr(), it3->second->DajGodinuIzdavanja());
       }
    return *this;   
}
Biblioteka &Biblioteka::operator=(Biblioteka &&b){
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
        delete it->second;
    for(auto it1=mapa_korisnika.begin(); it1!=mapa_korisnika.end(); it1++)
        delete it1->second;
    move(b.mapa_knjiga.begin(), b.mapa_knjiga.end(), inserter(mapa_knjiga, mapa_knjiga.begin()));
    move(b.mapa_korisnika.begin(), b.mapa_korisnika.end(), inserter(mapa_korisnika, mapa_korisnika.begin()));
    return *this;
        
}
void Biblioteka::RegistrirajNovogKorisnika(int cl_br, string ime, string prezime, string adresa, string telefon){
    bool postoji=false;
    for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++){
        if(it->first==cl_br) postoji=true;
    }
    if(postoji) throw logic_error("Korisnik vec postoji");
    else{
        Korisnik *novi=new Korisnik{ime, prezime, adresa, telefon};
        mapa_korisnika.insert(make_pair(cl_br, novi));
    }
}
void Biblioteka::RegistrirajNovuKnjigu(int ev_br, string naslov, string ime_pisca, string zanr, int godina_izdavanja){
    bool ima=false;
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
        if(it->first==ev_br) ima=true;
    }
    if(ima) throw logic_error("Knjiga vec postoji");
    else{
        Knjiga *nova=new Knjiga(naslov, ime_pisca, zanr, godina_izdavanja);
        mapa_knjiga.insert(make_pair(ev_br,nova));
    }
}

Korisnik &Biblioteka::NadjiKorisnika(int cl_br){
    if(mapa_korisnika.find(cl_br)==mapa_korisnika.end()) throw logic_error("Korisnik nije nadjen");
    for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++){
        if(it->first==cl_br) return *(it->second);
    }
}

Knjiga &Biblioteka::NadjiKnjigu(int ev_br){
    //if(mapa_knjiga.find(ev_br)==mapa_knjiga.end()) throw logic_error("Knjiga nije nadjena");
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
        if(it->first==ev_br) return *(it->second);
    }
  
}

void Biblioteka::IzlistajKorisnike() const{
    for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++){
        cout<<"Clanski broj: "<<it->first<<endl;
        cout<<"Ime i prezime: "<<it->second->ime<<" "; 
        cout<<it->second->prezime<<endl;
        cout<<"Adresa: "<<it->second->adresa<<endl;
        cout<<"Broj telefona: "<<it->second->telefon<<endl<<endl;
        }
}
void Biblioteka::IzlistajKnjige() const{
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
        cout<<"Evidencijski broj: "<<it->first<<endl;
        cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
        cout<<"Pisac: "<<it->second->DajAutora()<<endl;
        cout<<"Zanr: "<<it->second->DajZanr()<<endl;
        
        if(it->second->DaLiJeZaduzena()){
        cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;
        }
        if(it->second->DaLiJeZaduzena()==false) cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl<<endl;
    }
}

void Biblioteka::ZaduziKnjigu(int ev_br, int cl_br){
    if(mapa_knjiga.count(ev_br)==0) throw logic_error("Knjiga nije nadjena");
    auto zaduzii=mapa_knjiga.find(ev_br);
    if(zaduzii->second->DaLiJeZaduzena()) throw logic_error("Knjiga je zaduzena");
    if(mapa_korisnika.count(cl_br)==0) throw logic_error("Korisnik nije nadjen"); 
    for(auto it:mapa_korisnika){
        if (it.first==cl_br) {
            for(auto it2:mapa_knjiga){
                if(it2.first==ev_br){
                    it2.second->ZaduziKnjigu(*it.second);
                }
            }
        }
    }
}


void Biblioteka::RazduziKnjigu(int ev_br){
    if(mapa_knjiga.count(ev_br)==0) throw logic_error("Knjiga nije nadjena");
    auto itt=mapa_knjiga.find(ev_br);
    if(itt->second->DaLiJeZaduzena()==false) throw logic_error("Knjiga nije zaduzena");
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
        mapa_knjiga[ev_br]->RazduziKnjigu();
    }
}

void Biblioteka::PrikaziZaduzenja(int cl_br){
    bool a=false;
    if(mapa_korisnika.count(cl_br)==0) throw logic_error("Korisnik nije nadjen");
    for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++){
        if(it->first==cl_br){
            Korisnik *nezlica; nezlica=it->second;
            for(auto it1=mapa_knjiga.begin(); it1!=mapa_knjiga.end(); it1++){
                if(it1->second->DajKodKogaJe()==nezlica){
                    cout<<"Evidencijski broj: "<<it1->first<<endl;
                    cout<<"Naslov: "<<it1->second->DajNaslov()<<endl;
                    cout<<"Pisac: "<<it1->second->DajAutora()<<endl;
                    cout<<"Zanr: "<<it1->second->DajZanr()<<endl;
                    cout<<"Godina izdavanja: "<<it1->second->DajGodinuIzdavanja()<<endl<<endl;
                    a=true;
                }
            }
        }
        if(a==false) cout<<"Nema zaduzenja za tog korisnika!"; break;
    }
}
int main ()
{
    Biblioteka bib;
    int opcija;

    for(;;){
        izlaz1:
        cout<<"Odaberite opciju koja Vam se najvise dopada.\n1: Regstriranje novog korisnika\n2: Registriranje nove knjige\n3: ";
        cout<<"Pronalazak korisnika\n4: Pronalazak knjige\n5: Ispis korisnika\n6: Ispis knjiga\n7: Zaduzivanje knjige\n8: Razduzivanje ";
        cout<<"knjige\n9: Ispis zaduzenja"<<endl;
        cin>>opcija;
        switch(opcija){
            case 0:{
                cout<<"ADIOS!";
                return 0;
            }
            case 1:{
                int cl_br;
                cout<<"Unesite clanski broj: ";
                cin>>cl_br;
                cout<<"Unesite ime korisnika: ";
                string ime;
                cin.ignore(1000, '\n');
                getline(cin, ime);
                string prezime, adresa, telefon;
                cout<<"Unesite prezime korisnika: ";
                getline(cin, prezime);
                cout<<"Unesite adresu korisnika: ";
                getline(cin, adresa);
                cout<<"Unesite telefon korisnika: ";
                getline(cin, telefon);
                bib.RegistrirajNovogKorisnika(cl_br,ime,prezime,adresa,telefon);
                cout<<"Korisnik je uspjesno registriran!"<<endl;
                goto izlaz1;
            }
            case 2:{
                int ev_br;
                cout<<"Unesite evidencijski broj knjige: ";
                cin>>ev_br;
                cout<<"Unesite naslov knjige: ";
                string naslov;
                cin.ignore(1000,'\n');
                string pisac, zanric;
                int godina;
                getline(cin, naslov);
                cout<<"Unesite ime pisca: ";
                getline(cin, pisac);
                cout<<"Unesite zanr knjige: ";
                getline(cin, zanric);
                cout<<"Unesite godinu izdavanja: ";
                cin>>godina;
                bib.RegistrirajNovuKnjigu(ev_br,naslov,pisac,zanric,godina);
                cout<<"Knjiga je uspjesno registrovana!"<<endl;
                goto izlaz1;
            }
            case 3:{
                int broj;
                cout<<"Unesite clanski broj: ";
                cin>>broj;
                cout<<bib.NadjiKorisnika(broj).ime;
                cout<<endl;
                goto izlaz1;
            }
            case 4:{
                int br;
                cout<<"Unesite evidencijski broj: ";
                cin>>br;
                cout<<bib.NadjiKnjigu(br).DajNaslov();
                cout<<endl;
                goto izlaz1;
            }
            case 5:{
                cout<<"Korisnici biblioteke su:"<<endl;
                bib.IzlistajKorisnike();
                //cout<<endl;
                goto izlaz1;
            }
            case 6:{
                cout<<"Knjige u biblioteci su:"<<endl;
                bib.IzlistajKnjige();
                //cout<<endl;
                goto izlaz1;
            }
            case 7:{
                cout<<"Unesite evidencijski broj knjige: ";
                int e,c;
                cin>>e;
                cout<<"Unesite clanski broj korisnika: ";
                cin>>c;
                bib.ZaduziKnjigu(e,c);
                cout<<"Knjiga sa evidencijskim brojem "<<e<<" je zaduzena!"<<endl;
                goto izlaz1;
            }
            case 8:{
                cout<<"Unesite evidencijski broj knjige koju zelite razduziti: ";
                int eeeh;
                cin>>eeeh;
                bib.RazduziKnjigu(eeeh);
                cout<<"Knjiga je razduzena!"<<endl;
                goto izlaz1;
            }
            case 9:{
                cout<<"Unesite clanski broj korisnika: ";
                int clb;
                cin>>clb;
                bib.PrikaziZaduzenja(clb);
                goto izlaz1;
            }
        }
    }
    return 0;
}