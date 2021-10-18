/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <functional>
#include <stdexcept>
#include <string>
#include <vector>
template <typename TipElemenata>
class DatotecniKontejner 
{
    std::fstream tok;
public:
    DatotecniKontejner(const std::string &ime_datoteke)
    {
        tok.open(ime_datoteke.c_str(), std::ios::app);
        tok.close();
        tok.open(ime_datoteke.c_str(), std::ios::out | std::ios::in | std::ios::binary);
        if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    }
    void DodajNoviElement(const TipElemenata &element)
    {
        tok.seekp(0,std::ios::end);
        tok.write(reinterpret_cast<const char*>(&element), sizeof element);
        if(!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        tok.seekg(0);
    }
    int DajBrojElemenata()
    {
        tok.seekg(0, std::ios::end);
        int duzina_datoteke(tok.tellg());
        int broj_elemenata(duzina_datoteke / sizeof(TipElemenata));
        if(!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        return broj_elemenata;
    }
    TipElemenata DajElement(int pozicija)
    {
        if(pozicija < 0 || pozicija >= DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
        tok.seekg(pozicija*sizeof(TipElemenata));
        TipElemenata pom;
        tok.read(reinterpret_cast<char*>(&pom), sizeof(TipElemenata));
        if(!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        return pom;
    }
    void IzmijeniElement(int pozicija, const TipElemenata &element)
    {
        if(pozicija < 0 || pozicija >= DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
        tok.seekp(pozicija*sizeof(TipElemenata));
        tok.write(reinterpret_cast<const char*>(&element), sizeof(TipElemenata));
        if(!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
    }
    void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij = std::less<TipElemenata>())
    {
        tok.seekg(0, std::ios::end);
        int duzina_datoteke(tok.tellg());
        int broj_elemenata(duzina_datoteke / sizeof(TipElemenata));
        if(!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        tok.seekg(0);
        for(int i=0;i<broj_elemenata;i++)
        {
            TipElemenata pom1;
            tok.seekg(i*sizeof(TipElemenata));
            tok.read(reinterpret_cast<char*>(&pom1), sizeof(TipElemenata));
            for(int j=i+1;j<broj_elemenata;j++)
            {
                TipElemenata pom2;
                tok.read(reinterpret_cast<char*>(&pom2),sizeof(TipElemenata));
                if(kriterij(pom2,pom1)) 
                {
                    tok.seekp(i*sizeof(TipElemenata));
                    tok.write(reinterpret_cast<char*>(&pom2),sizeof(TipElemenata));
                    tok.seekp(j*sizeof(TipElemenata));
                    tok.write(reinterpret_cast<char*>(&pom1),sizeof(TipElemenata));
                    i--;
                    break;
                }
            }
        }
    }

};
int main ()
{
    //AT9 (zamger) - Testiranje metode sortiraj

        DatotecniKontejner<double> dk1("ime14.DAT");
        std::vector<double> v{2.8,1.2,3,4,5.6};
        for(int i=0 ; i < v.size(); i++)
            dk1.DodajNoviElement(v[i]);
        std::cout<<"Sortiran niz: ";
        dk1.Sortiraj();
        for(int i=0 ; i < v.size(); i++)
            std::cout<<dk1.DajElement(i)<<" ";
	return 0;
}
