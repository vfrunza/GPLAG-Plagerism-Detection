/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <functional>
#include <vector>

template<typename TipElemenata> 
    class DatotecniKontejner{
      std::fstream tok;
    public:
      DatotecniKontejner(const std::string &ime_datoteke);
      void DodajNoviElement(const TipElemenata &element);
      int DajBrojElemenata();
      TipElemenata DajElement(int pozicija);
      void IzmijeniElement(int pozicija, const TipElemenata &element);
      void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij = std::less<TipElemenata>());
    };

template<typename TipElemenata>    
 DatotecniKontejner<TipElemenata>::DatotecniKontejner(const std::string &ime_datoteke){
     std::ifstream ulaz(ime_datoteke, std::ios::binary);
     if(!ulaz.is_open()) {
      ulaz.close();
      std::ofstream izlaz(ime_datoteke, std::ios::binary);
      izlaz.close();
     }else ulaz.close();
     tok.open(ime_datoteke, std::ios::binary | std::ios::in | std::ios::out);
 }

template<typename TipElemenata>
 void DatotecniKontejner<TipElemenata>::DodajNoviElement(const TipElemenata &element){
   tok.seekp(0, std::ios::end); 
   if(!tok.write(reinterpret_cast<const char*>(&element), sizeof(TipElemenata))) 
      throw std::logic_error("Problemi prilikom pristupa datoteci");
   tok.seekp(0, std::ios::end);
   tok.seekg(0, std::ios::end);
 }
 
template<typename TipElemenata>
  int DatotecniKontejner<TipElemenata>::DajBrojElemenata(){
   tok.seekg(0, std::ios::end);
   int duzina(tok.tellg());
   int broj_el(duzina/sizeof(TipElemenata));
   return broj_el;
 }
 
template<typename TipElemenata>
   TipElemenata DatotecniKontejner<TipElemenata>::DajElement(int pozicija){
    if(pozicija>=this->DajBrojElemenata() || pozicija<0) throw std::range_error("Neispravna pozicija");
    tok.seekg(pozicija*sizeof(TipElemenata), std::ios::beg);
    TipElemenata trazeni;
    if(!tok.read(reinterpret_cast<char*>(&trazeni), sizeof(TipElemenata))) 
       throw std::logic_error("Problemi prilikom pristupa datoteci");
    return trazeni;
 }
 
template<typename TipElemenata>
 void DatotecniKontejner<TipElemenata>::IzmijeniElement(int pozicija, const TipElemenata &element){
    if(pozicija>=this->DajBrojElemenata() || pozicija<0) throw std::range_error("Neispravna pozicija");
    tok.seekp(pozicija*sizeof(TipElemenata), std::ios::beg);
    if(!tok.write(reinterpret_cast<const char*>(&element), sizeof(TipElemenata)))
        throw std::logic_error("Problemi prilikom pristupa datoteci");
 }
 
template<typename TipElemenata>
 void DatotecniKontejner<TipElemenata>::Sortiraj
 (std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij){
  tok.seekp(0);
  tok.seekg(0);
  for(int i(0);i<this->DajBrojElemenata(); i++){
      TipElemenata naj(this->DajElement(i));
      int index(i);
      for(int j(0);j<this->DajBrojElemenata();j++){
          if(!kriterij(this->DajElement(j),naj)) {
              naj=this->DajElement(j);
              index=j;
                TipElemenata pomoc(this->DajElement(i));
                this->IzmijeniElement(i, naj);
                 this->IzmijeniElement(index, pomoc);
      }}
  }
}

int main ()
{
    DatotecniKontejner<double> brojevi("brojevi2.dat");
    brojevi.DodajNoviElement(15.78); brojevi.DodajNoviElement(20.5);
    brojevi.DodajNoviElement(17); brojevi.DodajNoviElement(22.1);
    brojevi.DodajNoviElement(3.9);
    for(int i(0);i<brojevi.DajBrojElemenata();i++){
        std::cout << brojevi.DajElement(i)<<" ";
    }
    std::cout << std::endl;
    brojevi.IzmijeniElement(2, 13.3);
    brojevi.IzmijeniElement(1,9.18);
    brojevi.Sortiraj(std::greater<double>());
    for(int i(0);i<brojevi.DajBrojElemenata();i++){
        std::cout << brojevi.DajElement(i)<<" ";
    }
	return 0;
}
