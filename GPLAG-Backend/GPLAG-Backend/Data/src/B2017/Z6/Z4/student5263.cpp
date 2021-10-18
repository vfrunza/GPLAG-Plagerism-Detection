/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <functional>
template <typename TipElemenata>   
class DatotecniKontejner {     
    std::fstream tok;  
    public:     
    DatotecniKontejner(const std::string &ime_datoteke){
        std::fstream izlazni_tok(ime_datoteke, std::ios::in | std::ios::out | std::ios::binary);
        if(!izlazni_tok){
            std::ofstream izlazni_tok(ime_datoteke, std::ios::binary);
        }
        //tok=izlazni_tok;
    }     
    void DodajNoviElement(const TipElemenata &element);     
    int DajBrojElemenata();     
    TipElemenata DajElement(int pozicija);     
    void IzmijeniElement(int pozicija, const TipElemenata &element);         
    void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)>       
    kriterij = std::less<TipElemenata>());    
}; 
int main ()
{
    std::string be="TEST.DAT";
    DatotecniKontejner<int> s(be);
	return 0;
}
