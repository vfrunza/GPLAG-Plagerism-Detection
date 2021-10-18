/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <functional>
#include <stdexcept>
#include <string>
#include <utility>


template <typename TipElemenata>
     class DatotecniKontejner {
     std::fstream tok;
  public:
     DatotecniKontejner(const std::string &ime_datoteke);
     void DodajNoviElement(const TipElemenata &element);
     int DajBrojElemenata();
     TipElemenata DajElement(int pozicija);
     void IzmijeniElement(int pozicija, const TipElemenata &element);
     void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij  = std::less<TipElemenata>());
 };

template <typename TipElemenata>
DatotecniKontejner<TipElemenata>::DatotecniKontejner(const std::string &ime_datoteke)
{
    tok.open(ime_datoteke, std::ios::binary | std::ios::out | std::ios::in | std::ios::ate);
    if(!tok.is_open()) {
        std::ofstream (ime_datoteke, std::ios::binary);
        tok.open(ime_datoteke, std::ios::binary | std::ios::in | std::ios::out | std::ios::ate);
    }
     if(!tok) {
          tok.clear();
          throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
     }
}
template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::DodajNoviElement(const TipElemenata &element)
{
     tok.write(reinterpret_cast<const char*> (&element), sizeof(element));
     if(!tok) {
          tok.clear();
          throw std::logic_error("Probemi prilikom pristupa datoteci");
     }
}

template <typename TipElemenata>
int DatotecniKontejner<TipElemenata>::DajBrojElemenata() { 
    tok.seekg(0, std::ios::end);
    int duzina(tok.tellg());
    int brojelem(duzina / sizeof (TipElemenata));
    return brojelem;
}

template <typename TipElemenata>
TipElemenata DatotecniKontejner<TipElemenata>::DajElement(int pozicija)
{
     if(pozicija < 0 || pozicija >= this->DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
      tok.seekg((pozicija) * sizeof(TipElemenata), std::ios::beg);
      TipElemenata tmp; 
      tok.read(reinterpret_cast<char*> (&tmp), sizeof tmp);
      if(!tok) {
          tok.clear();
          throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
     }
      return tmp;
}

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::IzmijeniElement(int pozicija, const TipElemenata &element)
{
    if(pozicija < 0 || pozicija >= this->DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
    tok.seekg((pozicija) * sizeof(element), std::ios::beg);
    tok.write(reinterpret_cast<const char*> (&element), sizeof element);
    if(!tok) {
          tok.clear();
          throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
     }
}

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij)
{
     TipElemenata tmp1, tmp2;
     for (int i = 0; i < this->DajBrojElemenata()-1; i++) { 
          
       for (int j = 0; j < this->DajBrojElemenata()-i-1; j++) {
         tok.seekg(j * sizeof(TipElemenata), std::ios::beg);
         tok.read(reinterpret_cast<char*> (&tmp1), sizeof tmp1);
         tok.seekg((j + 1) * sizeof(TipElemenata), std::ios::beg);
         tok.read(reinterpret_cast<char*> (&tmp2), sizeof tmp2);
           if (kriterij(tmp2,tmp1)) {
               tok.seekp(j * sizeof(TipElemenata), std::ios::beg);
               tok.write(reinterpret_cast<char*> (&tmp2), sizeof tmp2);
               tok.seekp((j + 1) * sizeof(TipElemenata), std::ios::beg);
               tok.write(reinterpret_cast<char*> (&tmp1), sizeof tmp1);
             }
          }
     }
}

int main ()
{
     /*DatotecniKontejner<int> dat("aki");
     dat.DodajNoviElement(1);
     dat.DodajNoviElement(2);
     dat.DodajNoviElement(5);
     dat.DodajNoviElement(10);
     dat.DodajNoviElement(7);
     dat.DodajNoviElement(3);
     dat.DodajNoviElement(11);
     dat.DodajNoviElement(17);
     dat.DodajNoviElement(8);
     std::cout << dat.DajElement(3) << " " << dat.DajBrojElemenata() << std::endl;
     dat.IzmijeniElement(1,6);
     std::cout << dat.DajElement(1) << " " << dat.DajBrojElemenata()<< std::endl;
    // dat.Sortiraj([](int x, int y) { return x > y; });
     std::cout << dat.DajElement(0) << " " << dat.DajElement(1) << " " << dat.DajElement(2) << " " << dat.DajElement(3) << " " << dat.DajElement(4) << " " <<
      dat.DajElement(5) << " " <<  dat.DajElement(6) << " " << dat.DajElement(7) << " " << dat.DajElement(8) << " " <<std::endl;*/
      DatotecniKontejner<int> dk1("ime5.DAT");
        DatotecniKontejner<int> dk2("ime5.DAT");
        DatotecniKontejner<int> dk3("ime6.DAT");
        
        dk1.DodajNoviElement(1);
                
        dk2.DodajNoviElement(1);
        
        std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<" "<<dk3.DajBrojElemenata()<<std::endl;
	return 0;
}
