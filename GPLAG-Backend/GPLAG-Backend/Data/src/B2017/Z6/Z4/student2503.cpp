/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <cstdio>
#include <fstream>
#include <stdexcept>
#include <functional>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <iomanip>

template <typename TipElemenata>
 class DatotecniKontejner {
 std::fstream tok;
 public:
 DatotecniKontejner(const std::string &ime_datoteke) : tok(ime_datoteke,std::ios::binary | std::ios::app | std::ios::out | std::ios::in) {
    if(!tok) throw std::domain_error("Problemi prilikom otvaranja ili kreiranja datoteke");
 }
 void DodajNoviElement(const TipElemenata &element) {
     tok.write(reinterpret_cast<const char*>(&element), sizeof(element));
 }
 int DajBrojElemenata() {
 tok.seekg(0, std::ios::end);
  return (tok.tellg());
 }
 TipElemenata DajElement(int pozicija) {
  tok.seekg(pozicija);
  return (tok.read(reinterpret_cast<char*>(*this), sizeof(*this)));
 }
 void IzmijeniElement(int pozicija, const TipElemenata &element) {
   tok.seekp(pozicija);
tok.write(reinterpret_cast<char*>(*this), sizeof *this);
 }
 };

int main ()
{
      DatotecniKontejner<int> dk1("ime7.DAT");
        DatotecniKontejner<int> dk2("ime7.DAT");
        
        dk1.DodajNoviElement(6);
        dk2.DodajNoviElement(1);
        dk2.DodajNoviElement(3);
        dk2.DodajNoviElement(6);
        
        std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<std::endl;
	return 0;
}
