/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <list>
#include <utility>
#include <map>
#include <stdexcept>
#include <queue>
#include <iterator>
#include <algorithm>

enum class Boje
{
    Pik,Tref, Herc, Karo
};

typedef std::list<std::pair<Boje, std::string>> Spil;
typedef std::queue<std::pair<Boje, std::string>> RedKarata;

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

Spil KreirajSpil ()
{
    Spil spil;
    spil.resize(52);  // Spil ima 52 karte
    Spil::iterator it(spil.begin());
    int boja(0),karta;     // karta je trnuetni broj/slovo karte u spilu (11=J, 12=Q, 13=K, 1=A)
    for (int j = 0; j<52; j=j+13) {    // Ova petlja ce se izvrsiti 4 puta za svaku boju respektivvno
        karta=2;
        for (int i = j; i<13+j; i++) {
            if (i==(12+j)) karta=1;      // Ovom naredbom postavljam Asa na zadnje mjesto u listi
            (*it).first=BojaKarte(boja);  // Postavljam prvi član na trenutnu boju
            (*it).second=BrojKarte(karta); // Postavljam drugi član na trenutni broj/slovo karte
            it++;
            karta++;
        }
        boja++;   // boja moze biti 0,1,2,3
    }
    return spil;
}

void SortirajSpil(Spil &spil)
{  // Ovdje sam koristio ideju da prvo pretvorim clanove spila koji nisu po redu ASCII tabele da budu po redu ASCII tabele
    for (auto &x:spil) { 
        if (x.second=="A") x.second="F";
        else if (x.second=="K") x.second="E";
        else if (x.second=="Q") x.second="D";
        else if (x.second=="J") x.second="C";
        else if (x.second=="10") x.second="B";
    } // Posto su sada sigurno clanovi spila od 2 do Asa poredani po velicini od najmanjeg to najveced po Ascii tabeli onda ih mogu sortirati
    spil.sort();
    for (auto &x:spil) {   // Sada vracam nazad nazive clanova spila na prvobitnu vrijednost
        if(x.second=="F") x.second="A";
        else if (x.second=="E") x.second="K";
        else if (x.second=="D") x.second="Q";
        else if (x.second=="C") x.second="J";
        else if (x.second=="B") x.second="10";
    }
} // Sortira spil

Spil SortirajSpilIVrati(Spil spil) // vrijedi isto kao i za gornju funkciju samo ona vraca spil, to mi je potrebno za funkciju Izuzetak
{             
    for (auto &x:spil) {
        if (x.second=="A") x.second="F";
        else if (x.second=="K") x.second="E";
        else if (x.second=="Q") x.second="D";
        else if (x.second=="J") x.second="C";
        else if (x.second=="10") x.second="B";
    }
    spil.sort();
    for (auto &x:spil) {
        if(x.second=="F") x.second="A";
        else if (x.second=="E") x.second="K";
        else if (x.second=="D") x.second="Q";
        else if (x.second=="C") x.second="J";
        else if (x.second=="B") x.second="10";
    }
    return spil;
} 

void IzuzetakZaSpil (Spil &spil) // Baca izuzetak u slucaju da spil na neki nacin ne valja
{
    if (spil.size()>52) throw std::logic_error ("Neispravna lista!");
    Spil sortiran (SortirajSpilIVrati(spil));    // vraca dupilakt prenesenog spila koji je sigurno sortiran kako treba
    auto it_sort(sortiran.begin()),it_spila(spil.begin());   
    while (it_spila!=spil.end()) {
        if (*it_spila!=*it_sort) throw std::logic_error ("Neispravna lista!");   // ako i-ti element prenesong spila nije jednak i-tom elementi sortiranog spila baca izuzetak
        it_sort++;
        it_spila++;
    }
    it_spila=spil.begin();
    it_spila++;
    Spil::iterator it_spila_karta(spil.begin());  // while petlja koja provjerava da li u spilu postoje elementi koji su ispravni ali su isti
    while (it_spila!=spil.end()){
        auto trenutno(it_spila);
        while (it_spila!=spil.end()){
            if (*it_spila==*it_spila_karta) throw std::logic_error("Neispravna lista!");
            it_spila++;
        }
        it_spila=trenutno;
        it_spila++;
        it_spila_karta++;
    }
    for (auto x : spil) {
        if (x.first!=Boje::Pik && x.first!=Boje::Tref && x.first!=Boje::Herc && x.first!=Boje::Karo)  // U slucaju da neka od Boja nija kako treba
            throw std::logic_error ("Neispravna lista!");
        if (!((x.second>="2" && x.second<="9") || x.second=="10" || x.second=="J" || x.second=="Q" || x.second=="K" || x.second=="A")) // u slucaju da ima element spila koji nije kako treba
            throw std::logic_error ("Neispravna lista!");
    }
}

void IzbaciKarte (Spil &spil, std::multimap<Boje,std::string> &multimapa)
{
    IzuzetakZaSpil(spil);  // provjerava da li je spil sortiran
    Spil::iterator it_spila(spil.begin());
    std::multimap<Boje,std::string>::iterator it_mape(multimapa.begin());
    while (it_spila!=spil.end()) {
        while (it_mape!=multimapa.end()) {
            if ((*it_spila).first==(*it_mape).first && it_spila->second==it_mape->second) {  // brise element ukoliko je element mape isti kao i element spila
                std::pair<Boje, std::string> uljez(*it_spila);     // uljez je element koji treba brisati
                it_spila=spil.erase(it_spila);    // brise element koji je uljez i uzima iterator na sebe koji posalje erase funkcija
               // multimapa.erase(it_mape); ukoliko treba brisati samo jedan elemnt mape
                it_mape=multimapa.begin();   
                while (it_mape!=multimapa.end()) {  // while petlja koja brise sve elemente iz mape koji su uljezi
                    if (it_mape->first==uljez.first && it_mape->second==uljez.second)
                        it_mape=multimapa.erase(it_mape);   // brise element koji je uljez i uzima iterator na sebe koji poljae erase 
                    it_mape++;
                }
                break;
            }
            it_mape++;
        }
        it_mape=multimapa.begin();
        it_spila++;
    }
}

RedKarata IzbaciKarteRazbrajanjem (Spil &spil,const short int &korak, const int &izbaci)
{
    IzuzetakZaSpil(spil);
    if (korak<=0 || korak>52 || izbaci<1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    int broj_izbacenih(0);
    RedKarata izbacene;  
    Spil::iterator it(spil.begin());
    while (broj_izbacenih<izbaci && spil.size()!=0) {
        int distanca(std::distance(it,spil.end()));    // Distanca sluzi ako je korak dosao do onog mjesta u spilu kada se sve vraca nazad na pocetak
        if (distanca<korak) {
            it=spil.begin();
           // novi_korak je korak kada ostane visak na kraju liste pa se vratimo na pocetak
            int novi_korak(korak-distanca-1);
            if (novi_korak>=spil.size()) novi_korak=(novi_korak%spil.size()); // u slucaju da je novi korak veci od velicine liste onda on trena biti ostatak pri djeljunju samog sebe sa trenutno velicinom liste
            
            //std::cout<<"Novi korak: "<<novi_korak<<"  Velicinia spila: "<<spil.size()<<std::endl;
            
            std::advance(it,novi_korak);  // funkcijom advance stavljam iterator na vrijednot koja je veca za jedan korak od prosle vrijesdnost iteratora ali postavljena na pocetak
            if (spil.size()==1) {  // ukoliko je ostala zadnja karta u spilu ubacujem tu kartu u red i postavljam velicinu spila na nulu
               izbacene.push(*spil.begin());
                spil.resize(0);
                break;
            }
            izbacene.push(*it);  // ubacujem u red kartu
            it=spil.erase(it);  // brisem tu kartu i postavljam iterator na vrijednost iteratora kojeg posalje funkcija erase
            broj_izbacenih++;
            continue;
        }
        
        std::advance(it,korak-1);  // povecavam iterator za vrijednost koraka
        izbacene.push(*it);
        it=spil.erase(it);
        broj_izbacenih++;
    }
    return izbacene;
}

void IzuzetakZaRed (RedKarata red)
{
    while (!red.empty()){
        if (red.front().first!=Boje::Pik && red.front().first!=Boje::Tref && red.front().first!=Boje::Herc && red.front().first!=Boje::Karo)
        throw std::logic_error ("Neispravne karte!");
        if (!((red.front().second>="2" && red.front().second<="9") || red.front().second=="10" || red.front().second=="J" || red.front().second=="Q" || red.front().second=="K" || red.front().second=="A"))
            throw std::logic_error ("Neispravne karte!");
            red.pop();
        }
} // Baca izutezak u slucaju da red karata ima kartu koja ne valja

bool NemaJeUListi (Spil spil, std::pair<Boje, std::string> karta)
{
    Spil::iterator it_spila(spil.begin());
    while (it_spila!=spil.end())
        if (*it_spila==karta) return false;
        else it_spila++;
        return true;
} // Funkcija koja provjerava da li se neka karta nalazi u spilu

void VratiPrvihNKarata (Spil &spil, RedKarata &red, int n)
{
    if (n<0) throw std::domain_error ("Broj n je besmislen!");
    else if (n>red.size()) throw std::range_error ("Nedovoljno karata u redu!");
    IzuzetakZaRed(red);
    IzuzetakZaSpil(spil);
    
    int i(0);
    Spil::iterator it(spil.begin());
    while (n>i) {
        while (NemaJeUListi(spil,red.front())) {
                spil.insert(it,red.front());  // jer ce na kraju funkcija SortirajSpil sortirati spil kako treba
            it++;
        }
        it=spil.begin();
        i++;
        red.pop();  // brisi element sa pocetka reda
    }
    SortirajSpil(spil); // sortira spil
}

void IspisiSpil (Spil spil)
{
    std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:\n";
    std::cout<<"Pik: ";
    for (auto x : spil)
    if (x.first==Boje::Pik) std::cout<<x.second<<" ";
    std::cout<<"\nTref: ";
    for (auto x : spil)
    if (x.first==Boje::Tref) std::cout<<x.second<<" ";
    std::cout<<"\nHerc: ";
    for (auto x : spil)
    if (x.first==Boje::Herc) std::cout<<x.second<<" ";
    std::cout<<"\nKaro: ";
    for (auto x : spil)
    if (x.first==Boje::Karo) std::cout<<x.second<<" ";
    

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
        Spil spil(KreirajSpil());
        auto kju(IzbaciKarteRazbrajanjem(spil,korak,n));
        IspisiSpil(spil);
        std::cout<<"\nUnesite broj karata koje zelite vratiti u spil: ";
        int k;
        std::cin>>k;
        VratiPrvihNKarata(spil,kju,k);
        IspisiSpil(spil);
        // za provjeru programa
        /*
        std::multimap<Boje,std::string> multimapa {{Boje::Pik,"3"},{Boje::Pik,"3"}};
        Spil spil(KreirajSpil());
        auto it(spil.begin());
        it->first=Boje::Pik;
        it->second="2";
        IzbaciKarte(spil,multimapa);
        for (auto x : multimapa){
            std::cout<<int(x.first)<<" "<<x.second<<std::endl;
        }
        auto kju(IzbaciKarteRazbrajanjem(spil,2,5));
        kju.push({Boje::Karo, "2"});
        kju.push({Boje::Karo, "2"});
        while (!kju.empty()){
            std::cout<<int(kju.front().first)<<" "<<kju.front().second<<std::endl;
            kju.pop();
        }
        VratiPrvihNKarata(spil,kju,14);
        IspisiSpil(spil);*/

    }
    catch (std::domain_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    catch (std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    catch (std::range_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    
    return 0;
} 
