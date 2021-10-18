/B2017/2018: ZSR 20, Zadatak 1
#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <algorithm>
#include <cmath>


template <typename TipElemenata>
class DatotecniKontejner
{
    std::fstream tok;
public:
    DatotecniKontejner(const std::string &ime_datoteke) {
        tok.open(ime_datoteke);
        if(!tok) {
            tok.clear();
            tok.open(ime_datoteke, std::ios::out | std::ios::binary);
        }
    } //Testiran
    void DodajNoviElement(const TipElemenata &element); //Testirano
    int DajBrojElemenata(); //Testirano
    TipElemenata DajElement(int pozicija); //Testirano
    void IzmijeniElement(int pozicija, const TipElemenata &element); //Testirano
    void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij = std::less<TipElemenata>()) {
        std::vector<TipElemenata> v;
        
         for(int i=0 ; i < DajBrojElemenata(); i++)
         {
    
            v.push_back(DajElement(i));

}

        std::sort(v.begin(),v.end(), kriterij);
        
         for(int i=0 ; i < DajBrojElemenata(); i++)
            IzmijeniElement(i,v.at(i));
    }


};
template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::DodajNoviElement(const TipElemenata &element)
{
    tok.seekp(0, std::ios::end); 
    tok.write(reinterpret_cast<const char*>(&element), sizeof element);
    tok.seekg(0,std::ios::beg); // Zašto ovo!?

}
template <typename TipElemenata>
TipElemenata DatotecniKontejner<TipElemenata>::DajElement(int pozicija)
{
    if(pozicija<0 || pozicija>=DajBrojElemenata())throw std::range_error ("Neispravna pozicija");

    int i=0;
    TipElemenata el;

    while (tok.read(reinterpret_cast<char*>(&el), sizeof el)) {
        if(i==pozicija) return el;
        i++;
    }
    
        if(pozicija<0 || pozicija>=DajBrojElemenata())throw std::range_error ("Neispravna pozicija");


}

template <typename TipElemenata>
int DatotecniKontejner<TipElemenata>::DajBrojElemenata()
{
        tok.seekg(0,std::ios::cur);
        tok.seekg(0,std::ios::end);
        int duzina_datoteke(tok.tellg()); 
        int br_elemenata(duzina_datoteke/sizeof(TipElemenata));
        return br_elemenata;

}

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::IzmijeniElement(int pozicija, const TipElemenata &element)
{
    TipElemenata el;
    tok.seekg(0, std::ios::beg);
    int i=0;    

     while (tok.read(reinterpret_cast<char*>(&el), sizeof el)) {
         if(i==pozicija){
            el=element;
            tok.seekp(- int(sizeof el),std::ios::cur);
            tok.write(reinterpret_cast<char*>(&el) , sizeof el);
            tok.seekg(0, std::ios::cur);
            break;
         }
         i++;
    }
    tok.seekg(0);
}

int main(){
    //AT (zamger) - da li klasa sadrzi SAM
    DatotecniKontejner<int> dk("ime19.DAT");
    std::cout<<sizeof(dk)<<std::endl;
    //528
}
int fun ()
{
   {
        //AT1 (c9) - Testiranje konstruktora
      /*  DatotecniKontejner<int> dk1("ime1.DAT");
        DatotecniKontejner<int> dk2("ime1.DAT");
        DatotecniKontejner<int> dk3("ime2.DAT");
        std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<std::endl;*/

    }
    {
        //AT2 (c9) - Testiranje konstruktora
     /*  DatotecniKontejner<double> dk1("ime1.DAT");
        DatotecniKontejner<double> dk2("ime1.DAT");
        DatotecniKontejner<double> dk3("ime2.DAT");
        
        dk1.DodajNoviElement(1.28);
        
        std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<" "<<dk3.DajBrojElemenata()<<std::endl;*/

    }
   /* {
        //AT3 (c9) - Testiranje konstruktora
        DatotecniKontejner<int> dk1("ime1.DAT");
        DatotecniKontejner<int> dk2("ime1.DAT");
        DatotecniKontejner<int> dk3("ime2.DAT");
        
        dk1.DodajNoviElement(1);
                
        dk2.DodajNoviElement(1);
        
        std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<" "<<dk3.DajBrojElemenata()<<std::endl;

    }*/
    /* {
        //AT4 (c9) - Testiranje metode DodajNoviElement
        DatotecniKontejner<int> dk1("ime1.DAT");
        DatotecniKontejner<int> dk2("ime1.DAT");
        
        dk1.DodajNoviElement(6);
        dk2.DodajNoviElement(1);
        dk2.DodajNoviElement(3);
        dk2.DodajNoviElement(6);
        
        std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<std::endl;

    }*/
 
     
    /* 
      {
          //AT6 (c9) - Testiranje metode IzmijeniElement - Izuzetak

        DatotecniKontejner<double> dk2("ime10.DAT");
        DatotecniKontejner<double> dk1("ime10.DAT");
        
        dk1.DodajNoviElement(6.7);
        dk1.DodajNoviElement(1.7);
        dk1.DodajNoviElement(3.6);
        dk1.DodajNoviElement(6.2);
        try{

        std::cout<<dk1.DajElement(2)<<std::endl;
        
        dk1.IzmijeniElement(4,13.3);
        
        std::cout<<dk2.DajElement(4)<<std::endl;

        std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<std::endl;
        }
        catch(std::range_error e) {
            std::cout<<e.what()<<std::endl;
        }
                  //Neispravna pozicija

 
    }
    
        {
          //AT7 (zamger) - Testiranje metode DajElement - Izuzetak

        DatotecniKontejner<double> dk2("ime12.DAT");
        DatotecniKontejner<double> dk1("ime12.DAT");
        
        dk1.DodajNoviElement(6.7);
        dk1.DodajNoviElement(1.7);
        dk1.DodajNoviElement(3.6);
        dk1.DodajNoviElement(6.2);
        try{

        std::cout<<dk1.DajElement(4)<<std::endl;
        
        dk1.IzmijeniElement(4,13.3);
        
        std::cout<<dk2.DajElement(4)<<std::endl;

        std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<std::endl;
        }
        catch(std::range_error e) {
            std::cout<<e.what()<<std::endl;
        }
        
        //Neispravna pozicija


    }
    {
        //AT8 (zamger) - Testiranje metode DajElement - Izuzetak

        DatotecniKontejner<double> dk1("ime13.DAT");
        DatotecniKontejner<double> dk2("ime13.DAT");
        
        dk1.DodajNoviElement(6.7);
        dk2.DodajNoviElement(1.7);
        dk2.DodajNoviElement(3.6);
        dk2.DodajNoviElement(6.2);
        try{

        std::cout<<dk1.DajElement(-2)<<std::endl;
        
        dk1.IzmijeniElement(4,13.3);
        
        std::cout<<dk2.DajElement(4)<<std::endl;

        std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<std::endl;
        }
        catch(std::range_error e) {
            std::cout<<e.what()<<std::endl;
        }
               //Neispravna pozicija

    }
    */
    
      {       
        
        //AT11 (zamger) - Testiranje metode sortiraj sa custom funkcijom kriterija
        DatotecniKontejner<short> dk1("ime17.DAT");
        std::vector<short> v {4, 3, 5, 34, 1, 45, 54, 22, 1, 234, 43, 234, 532, 12, 100, 101};


        for(int i=0 ; i < v.size(); i++) dk1.DodajNoviElement(v[i]);
        std::cout<<"Sortiran niz: ";
        auto suma = [](short x) {int s = 0; while (x) s += x % 10, x /= 10; return s;};
    auto lambda = [suma](short a, short b) {if (suma(a) == suma(b)) return a < b; return suma (a) < suma (b);};
        dk1.Sortiraj(lambda);
        for(int i=0 ; i < v.size(); i++)
            std::cout<<dk1.DajElement(i)<<" ";
        //Sortiran niz: 1 1 100 101 3 12 4 22 5 34 43 45 54 234 234 532 


      
    }
    
    
    
    return 0;
}
