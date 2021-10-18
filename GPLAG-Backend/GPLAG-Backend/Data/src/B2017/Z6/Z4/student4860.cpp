/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <functional>

template<typename TipElemenata>
struct DatotecniKontejner
{
    
    void TestirajDatoteku() const {
        if(!tok.good()){
            throw std::logic_error("Probemi prilikom pristupa datoteci");
        }
    }
    
    void TestPozicije(int pozicija)
    {
        if(pozicija >= DajBrojElemenata() || pozicija < 0){
            throw std::range_error("Neispravna pozicija");
        }
    }
    
    std::fstream tok;
public:
    DatotecniKontejner(const std::string& ime) 
    {
            
        tok.open(ime.data(), std::ios::binary | std::ios::out);
        
        if(!tok.good()){
            throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
        }
        tok.close();
        tok.open(ime.data(), std::ios::binary | std::ios::in | std::ios::out);
    }
    
    void DodajNoviElement(const TipElemenata &element);
    int DajBrojElemenata(); 
    TipElemenata DajElement(int pozicija);
    void IzmijeniElement(int pozicija, const TipElemenata &element); 
    void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij = std::less<TipElemenata>()); 
};


template<typename TipElemenata>
void DatotecniKontejner<TipElemenata>::Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij)
{
    TestirajDatoteku();
    auto br_elem = DajBrojElemenata();
    
    if(br_elem == 0 || br_elem == 1){
        return;
    }
    
    for(int i = 0; i < br_elem - 1; ++i){
        for(int j = i + 1; j < br_elem; ++j){
            
            TipElemenata el1 = DajElement(i);
            TestirajDatoteku();
            
            TipElemenata el2 = DajElement(j);
            TestirajDatoteku();
            
            if(!kriterij(el1, el2)){
                IzmijeniElement(i, el2);
                IzmijeniElement(j, el1);
            }
        }
    }
    
}

template<typename TipElemenata>
void DatotecniKontejner<TipElemenata>::IzmijeniElement(int pozicija, const TipElemenata &element)
{
    TestPozicije(pozicija);
    tok.seekp(0, std::ios::beg);
    tok.seekp(pozicija * sizeof(TipElemenata));
    tok.write(reinterpret_cast<const char*>(&element), sizeof(TipElemenata));
    tok.flush();
    TestirajDatoteku();
}

template<typename TipElemenata>
TipElemenata DatotecniKontejner<TipElemenata>::DajElement(int pozicija)
{
    TestPozicije(pozicija);
    tok.seekg(0, std::ios::beg);
    tok.seekg(pozicija * sizeof(TipElemenata));
    TipElemenata element{};
    tok.read(reinterpret_cast<char*>(&element), sizeof(TipElemenata));
    TestirajDatoteku();
    return element;
}

template<typename TipElemenata>
void DatotecniKontejner<TipElemenata>::DodajNoviElement(const TipElemenata &element)
{
    TestirajDatoteku();
    tok.seekp(0, std::ios::end);
    tok.write(reinterpret_cast<const char*>(&element), sizeof(TipElemenata));
    tok.flush();
    TestirajDatoteku();
}

template<typename TipElemenata>
int DatotecniKontejner<TipElemenata>::DajBrojElemenata()
{
    TestirajDatoteku();
    tok.seekg(0, std::ios::end);
    TestirajDatoteku();
    return tok.tellg() / sizeof(TipElemenata);
}


int main ()
{
    
    //AT3 (c9) - Testiranje konstruktora
    {
        DatotecniKontejner<int> dk1("ime5.DAT");
        DatotecniKontejner<int> dk2("ime5.DAT");
        DatotecniKontejner<int> dk3("ime6.DAT");
        
        dk1.DodajNoviElement(1);
                
        dk2.DodajNoviElement(1);
        
        std::cout<<dk1.DajBrojElemenata()<<" ";
        std::cout<<dk2.DajBrojElemenata()<<" ";
        std::cout<<dk3.DajBrojElemenata()<<std::endl;
    // Ocekivani ipsis : 1 1 0
    // moj ispis       : 1 1 0
    
    
    
    }
    
    {
        //AT3 (c9) - Testiranje konstruktora
        DatotecniKontejner<int> dk1("ime5.DAT");
        DatotecniKontejner<int> dk2("ime5.DAT");
        DatotecniKontejner<int> dk3("ime6.DAT");
        
        dk1.DodajNoviElement(1);
                
        dk2.DodajNoviElement(1);
        
        std::cout<<dk1.DajBrojElemenata()<<" ";
        std::cout<<dk2.DajBrojElemenata()<<" ";
        std::cout<<dk3.DajBrojElemenata()<<std::endl;     

    // Ocekivani ipsis : 2 2 0
    // moj ispis       : 1 1 0
    }
    
    {
         //AT4 (c9) - Testiranje metode DodajNoviElement
        DatotecniKontejner<int> dk1("ime7.DAT");
        DatotecniKontejner<int> dk2("ime7.DAT");
        
        dk1.DodajNoviElement(6);
        dk2.DodajNoviElement(1);
        dk2.DodajNoviElement(3);
        dk2.DodajNoviElement(6);
        
        std::cout<<dk1.DajBrojElemenata()<<" ";
        std::cout<<dk2.DajBrojElemenata()<<std::endl;
        
        
        // Ocekivani ipsis : 4 4
        // moj ispis       : 2 3
        
        //! ovo iznad na c9 kada pokrenem
        //! kada otvorim test u novom tabu 
        
        // moj ispis       : 3 3
    }
   
}
