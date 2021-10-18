#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

int duzina__rijeci(std::string s){
    int brojac = 0;
    for(auto c: s){
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') )brojac++;
    }
    return brojac;
}

struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k){
    
    try
    {
    if(k<1 || k>v.size())throw std::logic_error("Razvrstavanje nemoguce");
    
    int vel = v.size();                               //23 i 3
    int br_prvih_timova = vel%k;                     //2
    int br_clanova1 = vel/k+1;                       //8
    int br_clanova2 = vel/k;                         //7
   
    std::vector<std::set<std::string>> t;
    t.resize(k);
    
    Dijete *pocetak(nullptr),*prethodni(nullptr);
    for(int i=0;i<v.size();i++){
        Dijete *novi(new Dijete);
        novi->ime = v[i]; novi->sljedeci = nullptr; 
        
        if(pocetak == nullptr)pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
    }
    
    prethodni->sljedeci = pocetak;// zadnji pok na cvor postavljamo da pokazuje na pocetak
   
   
   /*
    int tr_vel = 0;
  //samo provjera kruznog ispisa elemenata
  int i = 0;
      for(Dijete *p = pocetak;;p=p->sljedeci){
       std::cout<<p->ime<<" ";
       i++;
       if(i==10)break;
   }
   std::cout<<std::endl;
   
   //PRIMJER ISPRAVNOG BRISANJA drugog poka!!
   
   //auto p = pocetak->sljedeci;
   //pocetak->sljedeci = p->sljedeci;
   //delete p;
    
    
    //sada provjera ispravnog brisanja pocetka!!
    prethodni->sljedeci = pocetak->sljedeci;
    auto p=  pocetak;
    pocetak = pocetak->sljedeci;
    delete p;
    i = 0;
    
    //poslije deleta trebalo bi da ipise sve elemente osim tog i to u krug
       for(Dijete *p = pocetak;;p=p->sljedeci){
       std::cout<<p->ime<<" ";
       i++;
       if(i==10)break;
   }
   
   */
   int tr_vel = 0;
   Dijete *trenutni = nullptr;
   for(int i=0;i<k;i++){
            for(int j=0;(i>=br_prvih_timova) ? (j<br_clanova2) : (j<br_clanova1);j++){
                //brisem pocetak, prethodni i dalje pokazuje prije pocetka !!
                if(i==0 && j==0){
                t[i].insert(pocetak->ime);
                tr_vel = duzina__rijeci(pocetak->ime);  
                prethodni->sljedeci = pocetak->sljedeci;
                auto p = pocetak;
                pocetak = pocetak->sljedeci;
                delete p;
                trenutni = pocetak;
                
                }else{
                    Dijete *prijetrenutnog = nullptr;
                for(int h=0;h<tr_vel-1;h++){
                    if(h==tr_vel-2)prijetrenutnog = trenutni;
                    trenutni = trenutni->sljedeci;
                    
                }
                
                t[i].insert(trenutni->ime);
                
                tr_vel = duzina__rijeci(trenutni->ime);
                prijetrenutnog->sljedeci = trenutni->sljedeci;
                auto p = trenutni;
                trenutni = trenutni->sljedeci;
                delete p;
                }
            }
    }
   
   
    return t;
    }
    catch(std::bad_alloc)
    {
        
    }
}

/*
#include <new>
#include <cstdlib>
const unsigned MAX_RAM = 15 * sizeof (Dijete);
static unsigned Alocirano;
void *operator new (size_t size)
    {
        Alocirano += size;
        if (Alocirano >= MAX_RAM)
            throw std::bad_alloc();
        return std::malloc(size);
    }

void operator delete (void *p) noexcept
    {
        std::free(p);
    }

*/
int main ()
{
    
//AT18 (skriveni) - testira da li su atributi strukture string i 'glupi pokazivac
//Takodjer se vrsi provjera da li su string i 'glupi' pokazivac JEDINI atributi strukture.
//Test je eliminatoran, tj. ako ovaj test pada (zadatak se ne kompajlira) dobiva se 0 poena

    
    struct Dummy {
        std::string element;
        Dummy* veza;
    };
    
    
    std::cout << (sizeof (Dummy) == sizeof (Dijete) ? "OK" : "NOT OK");
    
    Dijete d;
    d.ime = "Ana";
    Dijete* glupiPok{nullptr};
    d.sljedeci = glupiPok;
    
    
	return 0;
}