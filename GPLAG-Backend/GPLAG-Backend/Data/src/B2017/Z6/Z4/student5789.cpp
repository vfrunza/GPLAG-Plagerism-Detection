/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>


using namespace std;

template <typename TipElemenata>
class DatotecniKontejner
{
    std::fstream tok;
public:
    DatotecniKontejner(const std::string &ime_datoteke)
    {
        tok.open(ime_datoteke,fstream::out | fstream::in  | fstream::app | fstream::binary);
        if(!tok) 
            throw logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
        
    }
    void DodajNoviElement(const TipElemenata &element);
    int DajBrojElemenata();
    TipElemenata DajElement(int pozicija);
    void IzmijeniElement(int pozicija, const TipElemenata &element);
  /*  void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)>
                  kriterij = std::less<TipElemenata>());
*/
};

template<typename TipElemenata>
void DatotecniKontejner<TipElemenata>::DodajNoviElement(const TipElemenata &element)
{
    tok.write((char *) (&element),sizeof (TipElemenata));
}

template<typename TipElemenata>
int DatotecniKontejner<TipElemenata>::DajBrojElemenata()
{   
    int br=0;
    TipElemenata broj;
    while(tok.read(reinterpret_cast<char*>(&broj), sizeof broj))
         br++;
        
    tok.clear();
    tok.seekg(0,ios::beg);
  return br;
}

template<typename TipElemenata>
TipElemenata DatotecniKontejner<TipElemenata>::DajElement(int pozicija)
{   
    int br=0;
    if(pozicija>DajBrojElemenata()|| pozicija<0) throw range_error("Neispravna pozicija");
    
    TipElemenata broj;
    while(tok.read(reinterpret_cast<char*>(&broj), sizeof broj))
    {   
         if(br==pozicija) return broj;
         br++;
    }
    
    tok.clear();
    tok.seekg(0,ios::beg);
    throw logic_error("Problemi prilikom pristupa datoteci");
}

template<typename TipElemenata>
void DatotecniKontejner<TipElemenata>::IzmijeniElement(int pozicija, const TipElemenata &element)
{
    int br=0;
    if(pozicija>DajBrojElemenata()|| pozicija<0) throw range_error("Neispravna pozicija");
    
    vector<TipElemenata> v;
    
    for(int i=0;i<DajBrojElemenata();i++)
        v.push_back(DajElement(i));
        
    
    v[pozicija]=element;
    
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    
    tok.clear();
    tok.seekg(0,ios::beg);
    
    for(int i=0;i<v.size();i++)
        tok.write((char *) (&v[i]),sizeof (TipElemenata));
  //  throw logic_error("Problemi prilikom pristupa datoteci");
    
    tok.clear();
    tok.seekg(0,ios::beg);

}

int main ()
{   
    
    //AT2 (c9) - Testiranje konstruktora
        DatotecniKontejner<double> dk1("ime3.DAT");
        DatotecniKontejner<double> dk2("ime3.DAT");
        DatotecniKontejner<double> dk3("ime4.DAT");
        
        dk1.DodajNoviElement(1.28);
      // cout<<dk1.DajElement(0);
        std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<" "<<dk3.DajBrojElemenata()<<std::endl;

    cout<<"Ok";
    return 0;
}
