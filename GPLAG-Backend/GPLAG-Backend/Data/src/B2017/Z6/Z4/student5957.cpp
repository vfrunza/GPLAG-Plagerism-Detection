/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <functional>
#include <string>
#include <stdexcept>
#include <fstream>

template <typename TipElemenata>
    class DatotecniKontejner {
        std::fstream tok;
        public:
        DatotecniKontejner(const std::string &ime_datoteke){
            std::fstream utok(ime_datoteke,std::ios::in | std::ios::out | std::ios::binary);
            if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
        }
        void DodajNoviElement(const TipElemenata &element){
            tok.write(reinterpret_cast<const char*>(&element), sizeof element);
        }
        int DajBrojElemenata(){
            int element;
            while(tok.read(reinterpret_cast<char*>(&element), sizeof element))
            std::cout<<element<<std::endl;
            
            return sizeof(*this)/sizeof(TipElemenata);
        }
        TipElemenata DajElement(int pozicija);
        void IzmijeniElement(int pozicija, const TipElemenata &element);
        void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)>
        kriterij = std::less<TipElemenata>());
    };

int main ()
{
    std::cout<<"DA";
    DatotecniKontejner <int>d("datoteka");
    d.DodajNoviElement(1);
    std::cout<<d.DajBrojElemenata();
    
	return 0;
}
