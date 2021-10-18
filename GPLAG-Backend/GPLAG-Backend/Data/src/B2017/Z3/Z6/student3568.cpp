/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
#include <memory>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    std::shared_ptr<Cvor> sljedeci;
};

typedef std::shared_ptr<Cvor> PokNaCvor;

PokNaCvor kraj_liste (PokNaCvor pocetak)
{
    if(pocetak == nullptr) return pocetak;
    PokNaCvor prethodni(nullptr);
    PokNaCvor trenutni(pocetak);
    do {
        prethodni = trenutni;
        trenutni=trenutni->sljedeci;
    } while (trenutni!=pocetak);

    return prethodni;
}

int velicina_liste (PokNaCvor pocetak)
{
    int lista_vel(0);
    PokNaCvor i(pocetak);
    do {
        lista_vel++;
        i=i->sljedeci;
    } while (i!=pocetak);

    return lista_vel;
}

void Ispisi_Listu(PokNaCvor p)
{
    const std::string boje[4] = {"Pik", "Tref", "Herc", "Karo"};
    for(int j=0; j<4; j++) {
        std::cout << boje[j] <<": ";
        PokNaCvor i(p);
        do {
            if(int(i->karta.boja) == j) std::cout << i->karta.vrijednost << " ";
            i=i->sljedeci;
        } while (i!=p);
        std::cout << std::endl;
    }
}

PokNaCvor KreirajSpil()
{
    const std::string vrijednosti[13]= {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    PokNaCvor pocetak(nullptr), prethodni(nullptr);
    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            PokNaCvor novi(std::make_shared<Cvor>()); 
            novi->karta.boja=Boje(i);
            novi->karta.vrijednost=vrijednosti[j];
            novi->sljedeci=nullptr;
            if(pocetak == nullptr) pocetak=novi;
            else prethodni->sljedeci = novi;
            prethodni = novi;
        }
    }
    prethodni->sljedeci = pocetak;

    return pocetak; 
}

void ValidacijaSpila(PokNaCvor pocetak)
{

    const std::string vrijednosti[13]= {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    PokNaCvor prethodni(kraj_liste(pocetak));
    PokNaCvor trenutni(pocetak);
    do {
        if(int(trenutni->karta.boja) <0 || int(trenutni->karta.boja) >3 || std::find(vrijednosti, vrijednosti+13, trenutni->karta.vrijednost)==vrijednosti+13)
            throw std::logic_error ("Neispravna lista!");
        
        int i(std::find(vrijednosti, vrijednosti+13, prethodni->karta.vrijednost)-vrijednosti);
        int j(std::find(vrijednosti, vrijednosti+13, trenutni->karta.vrijednost)-vrijednosti);
        
        if(trenutni != pocetak && trenutni != kraj_liste(pocetak)) {
            if(!(((trenutni->karta.boja == prethodni->karta.boja && i<j ) || (trenutni->karta.boja > prethodni->karta.boja)))) throw std::logic_error("Neispravna lista!");
        } else if(trenutni == kraj_liste(pocetak)) {
            if(!((trenutni->karta.boja == prethodni->karta.boja && i<j ) || (trenutni->karta.boja > prethodni->karta.boja))) throw std::logic_error("Neispravna lista!");
        }
 
        prethodni = trenutni;
        trenutni=trenutni->sljedeci;
    } while (trenutni!=pocetak);
}

void IzbaciKarte (PokNaCvor &pocetak, std::multimap <Boje, std::string> &za_izbaciti)
{
    try{
        ValidacijaSpila(pocetak);
    }catch(...){
        throw;
    }

    auto it(za_izbaciti.begin());
    while (it != za_izbaciti.end()) {
        PokNaCvor prethodni(kraj_liste(pocetak));
        PokNaCvor trenutni(pocetak);
        do {

            if(trenutni->karta.boja == it->first && trenutni->karta.vrijednost == it->second) {
                if(trenutni == pocetak) {
                    pocetak = trenutni->sljedeci;
                } else prethodni->sljedeci = trenutni->sljedeci;
                break;
            }
            if(prethodni == nullptr) prethodni=pocetak;
            else prethodni = trenutni;
            trenutni=trenutni->sljedeci;
        } while (trenutni!=pocetak);
        if(trenutni != pocetak) it=za_izbaciti.erase(it);
        else it++;
        if(pocetak->sljedeci == pocetak) pocetak=nullptr;
    }

}

std::stack<std::pair<std::string, std::string>>
        IzbaciKarteRazbrajanjem(PokNaCvor &pocetak, const short int &r, const int &b)
 {
    
    if(r < 1 || r > 52 || b < 1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    
    try{
        ValidacijaSpila(pocetak);
    }catch(...){
        throw;
    }
    
    const std::string boje[4] = {"Pik", "Tref", "Herc", "Karo"};
    int br_izbacenih(0);
    PokNaCvor prethodni(kraj_liste(pocetak)); 
    PokNaCvor trenutni(pocetak);
    std::stack<std::pair<std::string, std::string>> izbacene_karte;
    do { 
        int r_tmp(0);
        for(r_tmp=0; r_tmp<r-1; r_tmp++) {
            prethodni=trenutni;
            trenutni=trenutni->sljedeci;
        }
        if(trenutni == pocetak) pocetak = trenutni->sljedeci; //azuriranje pocetka
        if(trenutni == pocetak) {
            pocetak=trenutni->sljedeci;
        } else prethodni->sljedeci = trenutni->sljedeci;
    
        br_izbacenih++;
        izbacene_karte.push(make_pair(boje[int(trenutni->karta.boja)], trenutni->karta.vrijednost));
        
        prethodni = trenutni;
        trenutni=trenutni->sljedeci;
    } while (br_izbacenih!=b);

    if(pocetak->sljedeci == pocetak) pocetak=nullptr; //ako je ostala prazna lista

    return izbacene_karte;
}

void VratiPosljednjihNKarata(PokNaCvor &pocetak, std::stack<std::pair<std::string, std::string>> &izbacene_karte, int n)
{
    if(n<0) throw std::domain_error ("Broj n je besmislen!");
    if(n>izbacene_karte.size()) throw std::range_error ("Nedovoljno karata u steku!");

    try{
        ValidacijaSpila(pocetak);
    }catch(...){
        throw;
    }
    
    const std::string boje[4] = {"Pik", "Tref", "Herc", "Karo"};
    const std::string vrijednosti[13]= {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int vraceno(0);
    while (vraceno != n) {

        int i(std::find(boje, boje+4, izbacene_karte.top().first)-boje);
        //indeks u nizu boja - int od enum vrijednosti

        PokNaCvor novi(std::make_shared<Cvor>());
        novi->karta.boja=Boje(i);
        novi->karta.vrijednost=izbacene_karte.top().second;
        novi->sljedeci=nullptr; 
        //alokacija novog elementa tipa cvor koji se treba ubaciti
        
        bool u_spilu(false); 
        if(pocetak==nullptr) {
            pocetak=novi; 
            pocetak->sljedeci = pocetak;
        } else {
            PokNaCvor trenutni(pocetak);
            PokNaCvor prethodni(kraj_liste(pocetak));
            int k(std::find(vrijednosti, vrijednosti+13, novi->karta.vrijednost)-vrijednosti);
            int x(0);
            do {
                x++;
                int j(std::find(vrijednosti, vrijednosti+13, trenutni->karta.vrijednost)-vrijednosti);
                if((novi->karta.boja == trenutni->karta.boja && k < j) || (novi->karta.boja < trenutni->karta.boja && k<j))
                    break;
                if(novi->karta.boja == trenutni->karta.boja && k == j){
                    u_spilu=true;
                }
                prethodni=trenutni;
                trenutni=trenutni->sljedeci;
            } while(trenutni != pocetak); //pronalazenje mjesta na koje se treba ubaciti
            if(!u_spilu){ //ubacuje ako nije vec u spilu
            if(x==1) pocetak=novi;
            prethodni->sljedeci = novi;
            novi->sljedeci = trenutni;
            }
            
        }
        
        vraceno++;
        izbacene_karte.pop(); //prelazak na sljedeci element stacka
    }
}

void PrekiniListu(PokNaCvor &pocetak)
{
   PokNaCvor prethodni(kraj_liste(pocetak));
   PokNaCvor trenutni(pocetak);
   int n(velicina_liste(pocetak));
   for(int i=0; i<n; i++){
       prethodni->sljedeci = nullptr;
       prethodni=trenutni;
       trenutni=trenutni->sljedeci;
   }
    
}



int main ()
{
    
    auto p(KreirajSpil());
    try { 
        std::cout << "Unesite korak razbrajanja: ";
        int r;
        std::cin >> r; 
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        int b;
        std::cin >> b;

        auto izbacene_karte(IzbaciKarteRazbrajanjem(p, r, b));
        std::cout << "U spilu trenutno ima " << velicina_liste(p) << " karata, i to:" << std::endl;
        Ispisi_Listu(p);

        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin >> n;
        
        VratiPosljednjihNKarata(p, izbacene_karte, n);
        std::cout << "U spilu trenutno ima " << velicina_liste(p) <<" karata, i to:" << std::endl;
        Ispisi_Listu(p);
 
        
        PrekiniListu(p);
    } catch(std::domain_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
        PrekiniListu(p);
    } catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
        PrekiniListu(p);
    } catch(std::range_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
        PrekiniListu(p);
    }
    return 0;
}

