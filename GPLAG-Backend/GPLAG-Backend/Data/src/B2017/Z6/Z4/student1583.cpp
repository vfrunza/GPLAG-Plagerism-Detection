/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <functional>
#include <fstream>
#include <stdexcept>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

template <typename TipElemenata>   
class DatotecniKontejner 
{     
    std::fstream tok;
    /*
    Također, sve metode trebaju baciti izuzetak tipa “logic_error” uz prateći tekst 
    “Probemi prilikom pristupa datoteci” ukoliko dođe do bilo kakvih problema pri upisu u datoteku ili čitanja iz nje. 
    */
    public:     
    DatotecniKontejner(const std::string &ime_datoteke);//konstruktor za povezivanje toka sa datotekom
    
    void DodajNoviElement(const TipElemenata &element){
        tok.seekp(0,std::ios::cur);
        tok.seekp(0,std::ios::end);
        tok.write(reinterpret_cast<const char*>(&element),sizeof(element));
        if(!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        tok.seekg(0,std::ios::cur); // vracamo u metod za citanje
    }
    
    int DajBrojElemenata(){
        tok.seekg(0,std::ios::cur);
        tok.seekg(0,std::ios::end);
        int duzina_datoteke(tok.tellg()); // velicina u bajtovima
        if(!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        int br_elemenata(duzina_datoteke/sizeof(TipElemenata));
        return br_elemenata;
    }
    
    TipElemenata DajElement(int pozicija){
        
        int br_elemenata(DajBrojElemenata());
        if(pozicija<0 || pozicija>=br_elemenata) throw std::range_error("Neispravna pozicija");
        
        tok.seekg(0,std::ios::cur);
        tok.seekg(pozicija); // podrazumijevano od pocetka
        TipElemenata element;
        tok.read(reinterpret_cast<char*>(&element),sizeof(TipElemenata));
        if(!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        return element;
        
    }
    
    
    void IzmijeniElement(int pozicija, const TipElemenata &element){
        
        int br_elemenata(DajBrojElemenata());
        if(pozicija<0 || pozicija>=br_elemenata) throw std::range_error("Neispravna pozicija");
        
        tok.seekp(0,std::ios::cur);
        tok.seekp(pozicija);
        
        tok.write(reinterpret_cast<const char*>(&element),sizeof(element)); //da li ce trebati const char*???
        if(!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        tok.seekg(0,std::ios::cur);
        
    }
    
    
    void Sortiraj( std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij = std::less<TipElemenata>() ); 
    
    
}; 

template <typename TipElemenata>
DatotecniKontejner<TipElemenata>::DatotecniKontejner(const std::string &ime_datoteke){
    
    
    tok.open(ime_datoteke, std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
    if(!tok){ 
    //throw std::logic_error ("Problemi prilikom otvaranja ili kreiranja datoteke");
    std::ofstream izlazni_tok(ime_datoteke);
    izlazni_tok.close();
    tok.open(ime_datoteke, std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
    if(!tok) throw std::logic_error ("Problemi prilikom otvaranja ili kreiranja datoteke");
        
    
    }
    

} // konstruktor

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::Sortiraj( std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij ){
    
    int br_elemenata(DajBrojElemenata());
    TipElemenata temp1, temp2;
    
    for(int i=0;i<br_elemenata;i++){
    temp1=DajElement(i);
    for(int j=i+1;j<br_elemenata;j++){
        temp2=DajElement(j);
        if(kriterij(temp2,temp1)){
            TipElemenata temp3(temp1);
            IzmijeniElement(i,temp2);
            IzmijeniElement(j,temp3);
        }
    }
    }
    
}

 

int main ()
{
    //AT2 (c9) - Testiranje konstruktora
        DatotecniKontejner<double> dk1("ime3.DAT");
        DatotecniKontejner<double> dk2("ime3.DAT");
        DatotecniKontejner<double> dk3("ime4.DAT");
        
        dk1.DodajNoviElement(1.28);
        
        std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<" "<<dk3.DajBrojElemenata()<<std::endl;
    
	return 0;
}
