/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;

template<typename TipElemenata>
 class DatotecniKontejner {
 fstream tok;
 public:
     DatotecniKontejner(const string &ime_datoteke) {
      
     }
     void DodajNoviElement(const TipElemenata &element);
     int DajBrojElemenata();
     TipElemenata DajElement(int pozicija);
     void IzmijeniElement(int pozicija, const TipElemenata &element);
     void Sortiraj(function<bool(const TipElemenata &, const TipElemenata &)>
     kriterij = less<TipElemenata>());
 };


int main ()
{
	return 0;
}
