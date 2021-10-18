/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <functional>
#include <stdexcept>


template <typename TipElemenata>
class DatotecniKontejner {
    std::fstream tok;
  public:
    DatotecniKontejner(const std::string &ime_datoteke){
        tok.open(ime_datoteke, std::ios::binary);
        if(!tok){
            tok.clear();
            tok.close();
            tok.open(ime_datoteke, std::ios::binary | std::ios::out);
        }
        tok.close();
        tok.open(ime_datoteke, std::ios::binary | std::ios::in | std::ios::out);
        if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    }
    void DodajNoviElement(const TipElemenata &element){
        tok.seekg(0, std::ios::end);
        tok.write(reinterpret_cast<const char*>(&element), sizeof (TipElemenata));
        tok.seekg(0);
    }
    int DajBrojElemenata(){
        tok.seekg(0, std::ios::end);
        int duzina ( tok.tellg() / sizeof (TipElemenata) );
        tok.seekg(0);
        return duzina;
    }
    TipElemenata DajElement(int pozicija){
        if(pozicija >= DajBrojElemenata() || pozicija < 0)
            throw std::range_error("Neispravna pozicija");
        tok.seekg(pozicija*sizeof(TipElemenata));
        TipElemenata el;
        tok.read(reinterpret_cast<char*>(&el), sizeof (TipElemenata));
        tok.seekg(0);
        return el;
    }
    
    void IzmijeniElement(int pozicija, const TipElemenata &element){
        if(pozicija >= DajBrojElemenata() || pozicija < 0)
            throw std::range_error("Neispravna pozicija");
        tok.seekg(pozicija*sizeof(TipElemenata));
        tok.write(reinterpret_cast<const char*>(&element), sizeof element);
        tok.seekg(0);
    }
    void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)>
    kriterij = std::less<TipElemenata>()){
        
        for(int i(0); i < DajBrojElemenata(); i++){
            for(int j(0); j < DajBrojElemenata(); j++){
                TipElemenata a(DajElement(i));
                TipElemenata b(DajElement(j));
                if(kriterij(a,b)){
                    IzmijeniElement(i,b);
                    IzmijeniElement(j,a);
                }
            }
        }
    }
};



int main ()
{
    //AT1 (c9) - Testiranje konstruktora
    DatotecniKontejner<int> dk1("ime1.DAT");
    DatotecniKontejner<int> dk2("ime1.DAT");
    DatotecniKontejner<int> dk3("ime2.DAT");
        
    std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<std::endl;
    
    dk1.DodajNoviElement(3);
    dk2.DodajNoviElement(4);
    
    std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<" "<<dk3.DajBrojElemenata()<<std::endl;
    
    std::cout<<dk1.DajElement(0)<<" "<<dk1.DajElement(1);
	return 0;
}
