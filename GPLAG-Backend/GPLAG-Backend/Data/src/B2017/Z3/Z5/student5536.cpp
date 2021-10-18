/B2017/2018: Zadaća 3, Zadatak 5// Kopirao sam kod iz zadatka 4 u zadatak 5, također sam vrsio dosta copy-paste u programu jer nisam imao vremena sve fino ispisivati
#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <map>
#include <stack>

enum class Boje
{
    Pik,Tref, Herc, Karo
};

typedef std::stack<std::pair<Boje, std::string>> StekKarata;

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor *sljedeci;
};

Boje BojaKarte (int boja)
{
    if (boja==0)
        return Boje::Pik;
    else if (boja==1)
        return Boje::Tref;
    else if (boja==2)
        return Boje::Herc;
    return Boje::Karo;
}

std::string BrojKarte (int broj)
{
    if (broj==1)
        return "A";
    else if (broj>=2 && broj<=10)
        return std::to_string(broj);
    else if (broj==11)
        return "J";
    else if (broj==12)
        return "Q";
    return "K";
}

Cvor *KreirajSpil ()
{
    Cvor *pocetak(nullptr),*prethodni;
    int boja(0),karte;     // karta je trnuetni broj/slovo karte u spilu (11=J, 12=Q, 13=K, 1=A)
    for (int j = 0; j<52; j=j+13) {    // Ova petlja ce se izvrsiti 4 puta za svaku boju respektivvno
        karte=2;
        for (int i = j; i<13+j; i++) {
            if (i==(12+j)) karte=1;      // Ovom naredbom postavljam Asa na zadnje mjesto u listi
            Karta karta({BojaKarte(boja),BrojKarte(karte)});
            Cvor *novi (new Cvor {karta,nullptr}); // Postavljam prvi član na trenutnu boju  // Postavljam drugi član na trenutni broj/slovo karte
            if (!pocetak) pocetak=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
            karte++;
        }
        if (j==39) prethodni->sljedeci = pocetak;  // povezujem kraj i pocetak
        boja++;   // boja moze biti 0,1,2,3
    }
    return pocetak;
}

Cvor *ZadnjiCvor (Cvor *pocetak)
{
    if (pocetak==pocetak->sljedeci) return pocetak;
    Cvor *drugi(pocetak->sljedeci);
    while (1) {
        if (pocetak==drugi->sljedeci) break;
        drugi=drugi->sljedeci;
    }
    return drugi;
}

int DuzinaSpila (Cvor *pocetak)
{
    if (!pocetak) return 0;
    int broj_karata(0);
    for (Cvor *p=pocetak; ; p=p->sljedeci) {
        if (p==ZadnjiCvor(pocetak)) {
            broj_karata++;
            break;
        }
        broj_karata++;
    }
    return broj_karata;
}

void UnistiSpil (Cvor *pocetak)
{
    for (Cvor *p=pocetak->sljedeci; p!=pocetak; ) {   // postavim da p pokazuje na sljedeci cvor pa na kraju brisem taj cvor
        Cvor *pomoc(p->sljedeci);
        delete p;
        p=pomoc;
    }
    delete pocetak;
}

void SortirajSpil(Cvor *&pocetak)
{  // Ovdje sam koristio ideju da prvo pretvorim clanove spila koji nisu po redu ASCII tabele da budu po redu ASCII tabele
    int i(0);
    Cvor *pomoc1;
    for (Cvor *p=pocetak; i<DuzinaSpila(pocetak); p=p->sljedeci) {
        if (p->karta.vrijednost=="A") { p->karta.vrijednost="F"; pomoc1=p; }
        else if (p->karta.vrijednost=="K") p->karta.vrijednost="E";
        else if (p->karta.vrijednost=="Q") p->karta.vrijednost="D";
        else if (p->karta.vrijednost=="J") p->karta.vrijednost="C";
        else if (p->karta.vrijednost=="10") p->karta.vrijednost="B";
        i++;
    } // Posto su sada sigurno clanovi spila od 2 do Asa poredani po velicini od najmanjeg to najveced po Ascii tabeli onda ih mogu sortirati
    i=0;
    Karta pomoc;
    pomoc=pomoc1->karta;
    pomoc1->karta=ZadnjiCvor(pocetak)->karta;
    ZadnjiCvor(pocetak)->karta=pomoc;

    for (Cvor *p=pocetak; p->sljedeci != pocetak; p=p->sljedeci){
        for (Cvor *selekcija = p->sljedeci; selekcija->sljedeci!=pocetak; selekcija=selekcija->sljedeci){
            if (p->karta.vrijednost > selekcija->karta.vrijednost){
                Karta temp(p->karta);
                p->karta=selekcija->karta;
                selekcija->karta=temp;
            }
        }
    }
    i=0;
    for (Cvor *p=pocetak; i<DuzinaSpila(pocetak); p=p->sljedeci) {   // Sada vracam nazad nazive clanova spila na prvobitnu vrijednost
        if(p->karta.vrijednost=="F") p->karta.vrijednost="A";
        else if (p->karta.vrijednost=="E") p->karta.vrijednost="K";
        else if (p->karta.vrijednost=="D") p->karta.vrijednost="Q";
        else if (p->karta.vrijednost=="C") p->karta.vrijednost="J";
        else if (p->karta.vrijednost=="B") p->karta.vrijednost="10";
        i++;
    }
    /*
    std::cout<<"Nakon sortiranja"<<std::endl;
    i=0;
    for (Cvor *p=pocetak; i<DuzinaSpila(pocetak); p=p->sljedeci){
        std::cout<<"Boja: "<<int(p->karta.boja)<<" vrijednost: "<<p->karta.vrijednost<<std::endl;
        i++;
    }*/
} // Sortira spil

void IzuzetakZaSpil (Cvor *pocetak) // Baca izuzetak u slucaju da spil na neki nacin ne valja
{
    if (DuzinaSpila(pocetak)>52) throw std::logic_error ("Neispravna lista!");
    int i (0);
    for (Cvor *p=pocetak; i<DuzinaSpila(pocetak); p=p->sljedeci) {
        if (p->karta.boja !=Boje::Pik && p->karta.boja !=Boje::Tref && p->karta.boja!=Boje::Herc && p->karta.boja!=Boje::Karo)  // U slucaju da neka od Boja nija kako treba
            throw std::logic_error ("Neispravna lista!");
        if (!((p->karta.vrijednost>="2" && p->karta.vrijednost<="9") || p->karta.vrijednost=="10" || p->karta.vrijednost=="J" || p->karta.vrijednost=="Q" || p->karta.vrijednost=="K" || p->karta.vrijednost=="A")) // u slucaju da ima element spila koji nije kako treba
            throw std::logic_error ("Neispravna lista!");
            i++;
    }
}

void IzbaciKarte (Cvor *&pocetak, std::multimap<Boje,std::string> &multimapa)
{
    IzuzetakZaSpil(pocetak);  // provjerava da li je spil sortiran
    std::multimap<Boje,std::string>::iterator it_mape(multimapa.begin());
    Cvor *prethodni=ZadnjiCvor(pocetak);
    int i(0);
    for (Cvor *p=pocetak; i<DuzinaSpila(pocetak)+1; p=p->sljedeci) {
        while (it_mape!=multimapa.end()) {
            if (p->karta.boja==(*it_mape).first && p->karta.vrijednost==it_mape->second) {  // brise element ukoliko je element mape isti kao i element spila
                std::pair<Boje, std::string> uljez {p->karta.boja,p->karta.vrijednost};    // uljez je element koji treba brisati

                if (p==pocetak) pocetak=prethodni; // u slucaju da se izbaci prva karta
                prethodni->sljedeci=p->sljedeci; // prethodni postaje sljedeci a trenutni p se brise i p postaje prethodni
                delete p;
                p=prethodni;

                it_mape=multimapa.begin();
                while (it_mape!=multimapa.end()) {  // while petlja koja brise sve elemente iz mape koji su uljezi
                    if (it_mape->first==uljez.first && it_mape->second==uljez.second) {
                        it_mape=multimapa.erase(it_mape);   // brise element koji je uljez i uzima iterator na sebe koji poljae erase
                        break;

                    }
                    it_mape++;
                }
                break;
            }
            it_mape++;
        }
        it_mape=multimapa.begin();
        prethodni=p;
        i++;
    }
}

int Distanca (Cvor *pocetak, Cvor *kraj)
{
    int x(1);
    while (pocetak!=kraj) {
        x++;
        pocetak=pocetak->sljedeci;
    }
    return x;
}

StekKarata IzbaciKarteRazbrajanjem (Cvor *&pocetak,const short int &korak, const int &izbaci)
{
    //IzuzetakZaSpil(spil);
    if (korak<=0 || korak>52 || izbaci<1){ 
        UnistiSpil(pocetak);
        throw std::logic_error ("Neispravni elementi za izbacivanje!");
    }
    int broj_izbacenih(0);
    StekKarata izbacene;
    Cvor *prethodni=ZadnjiCvor(pocetak);
    for (Cvor *p=pocetak; ; p=p->sljedeci) {
        int distanca(Distanca(p,ZadnjiCvor(pocetak)));    // Distanca sluzi ako je korak dosao do onog mjesta u spilu kada se sve vraca nazad na pocetak
        if (distanca<korak) {
            p=pocetak;
            // novi_korak je korak kada ostane visak na kraju liste pa se vratimo na pocetak
            int novi_korak(korak-distanca-1);
            if (novi_korak>=DuzinaSpila(pocetak)) novi_korak=(novi_korak%DuzinaSpila(pocetak)); // u slucaju da je novi korak veci od velicine liste onda on trena biti ostatak pri djeljunju samog sebe sa trenutno velicinom liste

            for (int i = 0; i<novi_korak; p=p->sljedeci){
                if (i==(novi_korak-1)) prethodni = p;
                i++;
            }

            if (DuzinaSpila(pocetak)==1) {  // ukoliko je ostala zadnja karta u spilu ubacujem tu kartu u red i postavljam velicinu spila na nulu
                izbacene.push({pocetak->karta.boja,pocetak->karta.vrijednost});
                std::cout<<"1 je";
                break;
            }
            
            izbacene.push({p->karta.boja,p->karta.vrijednost});  // ubacujem u red kartu
            
            bool b(false);
            if (p==pocetak) { b=true; pocetak=prethodni; } // u slucaju da se izbaci prva karta
            prethodni->sljedeci=p->sljedeci; // prethodni postaje sljedeci a trenutni p se brise i p postaje prethodni
            delete p;
            p=prethodni;
             if (b && pocetak!=ZadnjiCvor(pocetak)) pocetak=prethodni->sljedeci;
            broj_izbacenih++;
            prethodni=p;
            if (broj_izbacenih==izbaci) break;
            continue;
        }

        for (int i = 0; i<(korak-1); p=p->sljedeci) {
            if (i==(korak-2)) prethodni=p;
            i++;
        } // ekvivalent funkcije advance
        if (DuzinaSpila(pocetak)==1) {pocetak->karta.vrijednost=""; pocetak=nullptr; break; } 

        izbacene.push({p->karta.boja,p->karta.vrijednost});
        bool a(false);
        if (p==pocetak){ a=true; pocetak=prethodni;} // u slucaju da se izbaci prva karta
        prethodni->sljedeci=p->sljedeci; // prethodni postaje sljedeci a trenutni p se brise i p postaje prethodni
        delete p;
        p=prethodni;
        if (a && pocetak!=ZadnjiCvor(pocetak)) pocetak=prethodni->sljedeci;
        broj_izbacenih++;
        prethodni=p;
        if (broj_izbacenih==izbaci)
             break;
    }
    return izbacene;
}

void IzuzetakZaStek (StekKarata stek)
{
    while (!stek.empty()){
        if (stek.top().first!=Boje::Pik && stek.top().first!=Boje::Tref && stek.top().first!=Boje::Herc && stek.top().first!=Boje::Karo)
        throw std::logic_error ("Neispravne karte!");
        if (!((stek.top().second>="2" && stek.top().second<="9") || stek.top().second=="10" || stek.top().second=="J" || stek.top().second=="Q" || stek.top().second=="K" || stek.top().second=="A"))
            throw std::logic_error ("Neispravne karte!");
            stek.pop();
        }
} // Baca izutezak u slucaju da red karata ima kartu koja ne valja

bool NemaJeUListi (Cvor *pocetak, std::pair<Boje, std::string> karta)
{
    int i(0);
    for (Cvor *p=pocetak; i<DuzinaSpila(pocetak); p=p->sljedeci){
        if (p->karta.boja==karta.first && p->karta.vrijednost==karta.second) return false;
        i++;
    }
        return true;
} // Funkcija koja provjerava da li se neka karta nalazi u spilu

void VratiPosljednjihNKarata (Cvor *&pocetak, StekKarata &stek, int n)
{
    if (n<0) {
        UnistiSpil(pocetak);
        throw std::domain_error ("Broj n je besmislen!");
    }
    else if (n>stek.size()){
    UnistiSpil(pocetak);
     throw std::range_error ("Nedovoljno karata u steku!");
    }
    IzuzetakZaStek(stek);
    //IzuzetakZaSpil(spil);
    if (n==0) return; // u slucaju da ne treba vratiti ni jednu karti samo prekini funkciju

    int i(0);
    Cvor *p(pocetak),*prethodni(ZadnjiCvor(pocetak));
    while (i<n) {
        while (NemaJeUListi(pocetak,stek.top())) {
            Karta karta ({stek.top().first,stek.top().second});
            Cvor *novi(new Cvor {karta,nullptr});
           // Cvor* pomoc(p);
            
            prethodni->sljedeci=novi;
            novi->sljedeci=p;
            prethodni=p;
            p=p->sljedeci;
        }
        i++;
        stek.pop();  // brisi element sa pocetka reda
    }
    /*
    i=0;
    for (Cvor *p=pocetak; i<DuzinaSpila(pocetak); p=p->sljedeci){
        std::cout<<"Boja: "<<int(p->karta.boja)<<" vrijednost: "<<p->karta.vrijednost<<std::endl;
        i++;
    }*/
    //std::cout<<std::endl;
    SortirajSpil(pocetak); // sortira spil
}

void IspisiSpil (Cvor *pocetak)
{
    std::cout<<"U spilu trenutno ima "<<DuzinaSpila(pocetak)<<" karata, i to:\n";
    std::cout<<"Pik: ";
    int i(0);
    for (Cvor *p=pocetak; i<DuzinaSpila(pocetak); p=p->sljedeci) {
        if (p->karta.boja==Boje::Pik) std::cout<<p->karta.vrijednost<<" ";
        i++;
    }

    std::cout<<"\nTref: ";
    i=0;
    for (Cvor *p=pocetak; i<DuzinaSpila(pocetak); p=p->sljedeci) {
        if (p->karta.boja==Boje::Tref) std::cout<<p->karta.vrijednost<<" ";
        i++;
    }

    std::cout<<"\nHerc: ";
    i=0;
    for (Cvor *p=pocetak; i<DuzinaSpila(pocetak); p=p->sljedeci) {
        if (p->karta.boja==Boje::Herc) std::cout<<p->karta.vrijednost<<" ";
        i++;
    }
    i=0;
    std::cout<<"\nKaro: ";
    for (Cvor *p=pocetak; i<DuzinaSpila(pocetak); p=p->sljedeci) {
        if (p->karta.boja==Boje::Karo) std::cout<<p->karta.vrijednost<<" ";
        i++;
    }
} // Ispisuje spil

int main ()
{
    try {
            short int korak;
            std::cout<<"Unesite korak razbrajanja: ";
            std::cin>>korak;
            std::cout<<"Unesite broj karata koje zelite izbaciti: ";
            int n;
            std::cin>>n;
            Cvor *spil(KreirajSpil());
            auto stek(IzbaciKarteRazbrajanjem(spil,korak,n));
            IspisiSpil(spil);
            std::cout<<"\nUnesite broj karata koje zelite vratiti u spil: ";
            int k;
            std::cin>>k;
            VratiPosljednjihNKarata(spil,stek,k);
            IspisiSpil(spil);
            UnistiSpil(spil);
    } catch (std::domain_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    } catch (std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    } catch (std::range_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }

    return 0;
}
