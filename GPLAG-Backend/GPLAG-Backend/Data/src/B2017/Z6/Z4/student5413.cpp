/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;

template <typename TipElemenata>
class DatotecniKontejner 
{
    std::fstream tok;
public:
    DatotecniKontejner(const std::string &ime_datoteke) 
    {
        tok.open(ime_datoteke, ios::in | ios::out | ios::binary);
        
        if(!tok)
        {
            tok.open(ime_datoteke, ios::in | ios::out | ios::binary | ios::trunc);
        }
    }
    void DodajNoviElement(const TipElemenata &element)
    {
        tok.seekg(0, ios::end);
        tok.write(reinterpret_cast<const char*>(&element), sizeof element);
        tok.seekg(0, ios::end);
    }
    int DajBrojElemenata()
    {
        tok.seekg(0, ios::end);
        int duzina_datoteke(tok.tellg());
        int broj_elemenata(duzina_datoteke / sizeof(TipElemenata));
        return broj_elemenata;
    }
    TipElemenata DajElement(int pozicija)
    {
        if(pozicija < 0 || pozicija >= DajBrojElemenata())
            throw range_error("Neispravna pozicija");
        TipElemenata element;
        tok.seekg(pozicija * sizeof(element));
        tok.read(reinterpret_cast<char*>(&element), sizeof element);
        return element;
    }
    void IzmijeniElement(int pozicija, const TipElemenata &element)
    {
        if(pozicija < 0 || pozicija >= DajBrojElemenata())
            throw range_error("Neispravna pozicija");
        tok.seekg(pozicija * sizeof(element));
        tok.write(reinterpret_cast<const char*>(&element), sizeof element);
    }
    void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij = std::less<TipElemenata>())
    {
        
    }
};

int main ()
{
    try
    {
        DatotecniKontejner<int> test("test.DAT");
        test.DodajNoviElement(5);
        cout << test.DajBrojElemenata() <<endl;
        for(int i = 0; i < test.DajBrojElemenata(); i++) cout << test.DajElement(i) << " ";
        test.IzmijeniElement(2, 10);
        cout << endl << test.DajElement(2) << endl;
        for(int i = 0; i < test.DajBrojElemenata(); i++) cout << test.DajElement(i) << " ";    
    }catch(range_error e)
    {
        cout << e.what();
    }
    
	return 0;
}
