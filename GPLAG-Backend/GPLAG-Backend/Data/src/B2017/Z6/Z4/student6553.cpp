/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <functional>

template <typename TipElemenata>
class DatotecniKontejner {
    std::fstream tok;
    void Izuzetak(){
    if(!tok && !tok.eof()) { tok.clear();throw std::logic_error("Problemi prilikom pristupa datoteci");}
}
    public:
    DatotecniKontejner(const std::string &ime_datoteke){
         tok.open(ime_datoteke, std::ios::in | std::ios::out|std::ios::binary);
        if(!tok) { tok.clear();
            tok.open(ime_datoteke,std::ios::binary | std::ios::out);
        tok.close();
        
        tok.open(ime_datoteke, std::ios::in | std::ios::out|std::ios::binary);
            tok.seekg(0);
        }
        
       if(!tok)throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
        
    }
    void DodajNoviElement(const TipElemenata& element){
       
        tok.seekp(0, std::ios::end);
        Izuzetak();
        tok.write(reinterpret_cast<const char*>(&element), sizeof(TipElemenata));
        tok.seekg(0,std::ios::beg);
    }
    int DajBrojElemenata(){
        tok.seekg(0, std::ios::end);
         Izuzetak();
        int pozicija(tok.tellg());
       return pozicija/(sizeof(TipElemenata));
    }
    //provjeriti je li parametar stvarna pozicija od 0, ili od 1
    TipElemenata DajElement(int pozicija){
        if(pozicija<0 || pozicija>=DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
        tok.seekg(pozicija*(sizeof(TipElemenata)),std::ios::beg);
        TipElemenata element;
      tok.read(reinterpret_cast<char*>(&element), sizeof(TipElemenata));
         Izuzetak();
        return element;
    }
    void IzmijeniElement(int pozicija, const TipElemenata& element){
         if(pozicija<0 || pozicija>=DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
         tok.seekp(pozicija*(sizeof(TipElemenata)));
          tok.write(reinterpret_cast<const char*>(&element), sizeof(TipElemenata));
         Izuzetak();
    }
    void Sortiraj(std::function<bool(const TipElemenata&, const TipElemenata&)>kriterij=std::less<TipElemenata>()){
        int velicina(DajBrojElemenata());
        TipElemenata pomocni=TipElemenata(),pomocna2=TipElemenata(); int pozicija(0);
        tok.seekg(0);
        for(int i=0;i<velicina-1;i++){
            tok.seekg(i*(sizeof(TipElemenata)));
        tok.read(reinterpret_cast<char*>(&pomocni), sizeof(TipElemenata));
            pozicija=i;
            for(int j=i+1;j<velicina;j++){ 
            
                tok.seekg(j*(sizeof(TipElemenata)));
                tok.read(reinterpret_cast<char*>(&pomocna2), sizeof(TipElemenata));
            if(!kriterij(pomocni, pomocna2)){
                pomocni=pomocna2; pozicija=j;
            }  
                }
                Izuzetak();
              
              
                TipElemenata tmp;
                 tok.seekg(i*sizeof(TipElemenata));
                 tok.read(reinterpret_cast<char*>(&tmp), sizeof(TipElemenata));
                  tok.seekp(i*sizeof(TipElemenata));
                tok.write(reinterpret_cast<char*>(&pomocni), sizeof(TipElemenata));
                  tok.seekp(pozicija*sizeof(TipElemenata));
                 tok.write(reinterpret_cast<char*>(&tmp), sizeof(TipElemenata));
                
            
        }
        
    }
    
};
int main ()
{
    double niz[]{4,5.6,4.5,2.1,-5,3.6,7.8};
    std::ofstream tok("dat1.bin", std::ios::binary);
    tok.write(reinterpret_cast<char*>(niz), sizeof(double)*7);
    tok.close();
    DatotecniKontejner<double> a("dat1.bin");
    double niz2[7];
    a.Sortiraj();
    std::ifstream tok1("dat1.bin", std::ios::binary);
    
    tok1.read(reinterpret_cast<char*>(niz2), sizeof(double)*7);
    for(int i=0;i<7;i++) std::cout<<niz2[i]<<" ";
     DatotecniKontejner<double> dk1("ime3.DAT");
        DatotecniKontejner<double> dk2("ime3.DAT");
        DatotecniKontejner<double> dk3("ime4.DAT");
        
        dk1.DodajNoviElement(1.28);
        dk2.DodajNoviElement(1.27);
        std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<" "<<dk3.DajBrojElemenata()<<std::endl;

	return 0;
	


}

