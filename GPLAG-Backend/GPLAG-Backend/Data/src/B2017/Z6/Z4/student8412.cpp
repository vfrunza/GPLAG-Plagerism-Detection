#include <iostream>
#include<fstream>
#include<functional>
#include<stdexcept>
template <typename TipElemenata>
class DatotecniKontejner {
std::fstream tok;
public:
DatotecniKontejner(const std::string &ime_datoteke){
    tok.open(ime_datoteke, std::ios::out | std::ios::in | std::ios::binary);
    if(!tok){
    tok.clear();
    tok.close();
    tok.open(ime_datoteke,std::ios::out | std::ios::binary);
    if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    tok.close();
    tok.open(ime_datoteke, std::ios::out | std::ios::in | std::ios::binary);
    if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    }
}
void DodajNoviElement(const TipElemenata &element){
    tok.seekp(0,std::ios::end);
    tok.write(reinterpret_cast<const char*>(&element),sizeof element);
    if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
    tok.seekp(0);
}
int DajBrojElemenata(){
    tok.seekg(0,std::ios::end);
    if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
    int duzina_datoteke=(tok.tellg());
    //std::cout<<"duzina_datoteke"<<duzina_datoteke;
    tok.seekg(0);
    TipElemenata e;
    return (duzina_datoteke/(sizeof e));
}

TipElemenata DajElement(int pozicija){
    tok.seekg(0,std::ios::end);
    int duzina_datoteke=(tok.tellg());
    int br=duzina_datoteke/(sizeof(TipElemenata));
    if(pozicija<0 or pozicija>=br) throw std::range_error("Neispravna pozicija");
    TipElemenata element;
    tok.seekg(pozicija*(sizeof element));
    tok.read(reinterpret_cast<char*>(&element),sizeof element);
    if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
    tok.seekg(0);
    return element;
}
void IzmijeniElement(int pozicija, const TipElemenata &element){
    tok.seekg(0,std::ios::end);
    int duzina_datoteke=(tok.tellg());
    int br=duzina_datoteke/(sizeof(TipElemenata));
    if(pozicija<0 or pozicija>=br) throw std::range_error("Neispravna pozicija");
    tok.seekp(pozicija*(sizeof element));
    tok.write(reinterpret_cast<const char*>(&element),sizeof element);
    if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
    tok.seekp(0);
}
void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)>
kriterij = std::less<TipElemenata>()){
    tok.seekg(0,std::ios::end);
    int duzina_datoteke=(tok.tellg());
    int br=duzina_datoteke/(sizeof(TipElemenata));
    for(int i=0;i<br;i++){
        
        tok.seekg(i*sizeof(TipElemenata));
        TipElemenata element1,element2;
        tok.read(reinterpret_cast<char*>(&element1),sizeof element1);
        if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
        for(int j=i+1;j<br;j++){
        tok.seekg((j)*sizeof(TipElemenata));
        tok.read(reinterpret_cast<char*>(&element2),sizeof element2);
        if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
        if(!kriterij(element1,element2)){
            tok.seekp(i*sizeof(TipElemenata));
            tok.write(reinterpret_cast<char*> (&element2),sizeof element2);
            if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
            tok.seekp((j)*sizeof(TipElemenata));
            tok.write(reinterpret_cast<char*> (&element1),sizeof element1);
            if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
            element1=element2;
        }
        }
    }
    tok.seekp(0);
    tok.seekg(0);
    
}
};

int main ()
{
    double niz[] = {1, 2, 0.5, 0.2, 6.23};
   /* std::fstream f ("dat.bin",std::ios::in | std::ios::out | std::ios::binary);
    f.write((char *)niz, sizeof niz);*/
    std::string s="dat.bin";
    DatotecniKontejner<double> k(s);
    double a=3;
    k.DodajNoviElement(a);
    k.DodajNoviElement(niz[0]);
    k.DodajNoviElement(0);
    k.DodajNoviElement(2);
    k.Sortiraj();
   //std::cout<<k.DajBrojElemenata();
   std::cout<<k.DajElement(0);
   std::cout<<k.DajElement(1);
   std::cout<<k.DajElement(2);
   std::cout<<k.DajElement(3);
    
	return 0;
}

