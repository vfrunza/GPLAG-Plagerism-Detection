/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

enum class Boje {Pik, Tref, Herc, Karo};
static std::vector<std::string> naziviKarata{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor *sljedeci;
};

Cvor *KreirajSpil() {
    Cvor *el = new Cvor;
    el->karta.vrijednost = "2";
    el->karta.boja = Boje::Pik;
    el->sljedeci = nullptr;
    
   Cvor*prvi= el;
   
    
    
  
   
            for (auto x:naziviKarata) {
                Cvor *els = new Cvor;
                els->karta.boja = Boje::Pik;
                els->karta.vrijednost = x;
                el->sljedeci= els;
                els->sljedeci = nullptr;
                els = nullptr;
                el = el->sljedeci;
            }
            
     
            for (auto x:naziviKarata) {
                Cvor *els = new Cvor;
                els->karta.boja = Boje::Tref;
                els->karta.vrijednost = x;
                el->sljedeci = els;
                els->sljedeci = nullptr;
                els = nullptr;
                el = el->sljedeci;
            }
     
            for (auto x:naziviKarata) {
                Cvor *els = new Cvor;
                els->karta.boja = Boje::Herc;
                els->karta.vrijednost = x;
                el->sljedeci = els;
                els->sljedeci = nullptr;
                els= nullptr;
                el = el->sljedeci;
            }
      
            for (auto x:naziviKarata) {
                Cvor *els = new Cvor;
                els->karta.boja = Boje::Karo;
                els->karta.vrijednost = x;
                el->sljedeci = els;
                els=nullptr;
                el = el->sljedeci;
            }
          
    
    el->sljedeci = prvi;
    prvi= nullptr;
    return el-> sljedeci;
   
}

void ispisiNazive(Cvor *x, Boje b) {
        while (x->karta.boja == b) { std::cout<<x->karta.vrijednost<<" "; x = x->sljedeci; }
}

void ispisiSpil(Cvor *x) {
    std::cout<<"Pik: ";
    ispisiNazive(x, Boje::Pik);
    std::cout<<"\nTref: ";
    ispisiNazive(x, Boje::Tref);
    std::cout<<"\nHerc: ";
    ispisiNazive(x, Boje::Herc);
    std::cout<<"\nKaro: ";
    ispisiNazive(x, Boje::Karo);
}

int main ()
{
    Cvor *x = KreirajSpil();
    ispisiSpil(x);
	return 0;
}
