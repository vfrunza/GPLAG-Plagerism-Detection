#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>

int duzina__rijeci(std::string s){
    int brojac = 0;
    for(auto c: s){
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') )brojac++;
    }
    return brojac;
}

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete>sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k){
    
    if(k<1 || k>v.size())throw std::logic_error("Razvrstavanje nemoguce");
    
    int vel = v.size();                               //23 i 3
    int br_prvih_timova = vel%k;                     //2
    int br_clanova1 = vel/k+1;                       //8
    int br_clanova2 = vel/k;                         //7
   
    std::vector<std::set<std::string>> t;
    t.resize(k);
    
    std::shared_ptr<Dijete> pocetak(nullptr),prethodni(nullptr);
    for(int i=0;i<v.size();i++){
        std::shared_ptr<Dijete> novi(std::make_shared<Dijete>());
        novi->ime = v[i]; novi->sljedeci = nullptr; 
       
        if(pocetak == nullptr)pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
    }
    
    prethodni->sljedeci = pocetak;// zadnji pok na cvor postavljamo da pokazuje na pocetak
   
   int tr_vel = 0;
   std::shared_ptr<Dijete> trenutni = nullptr;
   for(int i=0;i<k;i++){
            for(int j=0;(i>=br_prvih_timova) ? (j<br_clanova2) : (j<br_clanova1);j++){
                //brisem pocetak, prethodni i dalje pokazuje prije pocetka !!
                if(i==0 && j==0){
                t[i].insert(pocetak->ime);
                tr_vel = duzina__rijeci(pocetak->ime);  
                prethodni->sljedeci = pocetak->sljedeci;
           
                pocetak = pocetak->sljedeci;
                
                trenutni = pocetak;
                
                }else{
                    std::shared_ptr<Dijete> prijetrenutnog = nullptr;
                for(int h=0;h<tr_vel-1;h++){
                    if(h==tr_vel-2)prijetrenutnog = trenutni;
                    trenutni = trenutni->sljedeci;
                    
                }
                
                t[i].insert(trenutni->ime);
                
                tr_vel = duzina__rijeci(trenutni->ime);
                prijetrenutnog->sljedeci = trenutni->sljedeci;
               
                trenutni = trenutni->sljedeci;
               
                }
            }
    }
   trenutni->sljedeci = nullptr;
   trenutni = nullptr;
   
    return t;
}


int main ()
{
    
//AT18 (skriveni) - testira da li su atributi strukture string i pametni pokazivac
//Takodjer se vrsi provjera da li su string i pametni pokazivac jedini atributi strukture.
//Test je eliminatoran, tj. ako ovaj test pada (zadatak se ne kompajlira) dobiva se 0 poena

    
    struct Dummy {
        std::string element;
        std::shared_ptr<Dummy> veza;
    };
    
    
    std::cout << (sizeof (Dummy) == sizeof (Dijete) ? "OK" : "NOT OK");
    
    Dijete d;
    d.ime = "Ana";
    std::shared_ptr<Dijete> pametniPok{nullptr};
    d.sljedeci = pametniPok;
    
	return 0;
}