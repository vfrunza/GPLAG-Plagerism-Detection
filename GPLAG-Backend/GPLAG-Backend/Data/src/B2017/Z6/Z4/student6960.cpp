/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <functional>
#include <vector>

template <typename TipElemenata>
class DatotecniKontejner
{
    std::fstream tok;
public:
    DatotecniKontejner(const std::string &ime_datoteke);
    void DodajNoviElement (const TipElemenata &element);
    int DajBrojElemenata();
    TipElemenata DajElement (int pozicija);
    void IzmijeniElement (int pozicija, const TipElemenata &element);
    void Sortiraj(std::function<bool (const TipElemenata &, const TipElemenata &)> kriterij = std::less<TipElemenata> ());
};

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::Sortiraj(std::function<bool (const TipElemenata &, const TipElemenata &)> kriterij)
{
    tok.clear();
    tok.seekg(0);
    tok.seekp(0);
    TipElemenata a, b;
    int indeks_zamjene;
    int broj=DajBrojElemenata();
    try {
        for(int i=0; i<broj-1; i++) {
            indeks_zamjene=i;
            for(int j=i+1; j<broj; j++) {
                tok.seekg(j*sizeof(TipElemenata));
                tok.read(reinterpret_cast<char*> (&a), sizeof(TipElemenata));
                tok.seekg(indeks_zamjene*sizeof(TipElemenata));
                tok.read(reinterpret_cast<char*>(&b), sizeof(TipElemenata));
                if(kriterij(a,b)) indeks_zamjene=j;
            }
            if(indeks_zamjene!=i) {
                //std::cout<<"i= "<<i<<", indeks_zamjene "<<indeks_zamjene<<std::endl;
                tok.seekg(i*sizeof(TipElemenata));
                tok.read(reinterpret_cast<char*> (&a), sizeof (TipElemenata));
                tok.seekg(indeks_zamjene*sizeof(TipElemenata));
                tok.read(reinterpret_cast<char*> (&b), sizeof(TipElemenata));
                //std::cout<<"a = "<<a<<", b = "<<b<<std::endl;
                tok.seekp(0);
                tok.seekp(i*sizeof(TipElemenata));
                tok.write(reinterpret_cast<char*>(&b), sizeof(TipElemenata));
                tok.seekp(0);
                tok.seekp(indeks_zamjene*sizeof(TipElemenata));
                tok.write(reinterpret_cast<char*> (&a), sizeof(TipElemenata));
            }
        }
    } catch (...) {
        throw;
    }
    tok.seekp(0);
    tok.seekg(0);
}

template <typename TipElemenata>
DatotecniKontejner<TipElemenata>::DatotecniKontejner(const std::string &ime_datoteke)
{
    std::fstream pomocni (ime_datoteke, std::ios::in | std::ios::binary);
    if(!pomocni) {
        pomocni.clear();
        std::ofstream pomocni2(ime_datoteke, std::ios::out | std::ios::binary);
    }
    tok.open(ime_datoteke, std::ios::in | std::ios::out | std::ios::binary);
}

template <typename TipElemenata>
int DatotecniKontejner<TipElemenata>::DajBrojElemenata()
{
    tok.seekg(0, std::ios::end);
    int duzina(tok.tellg());
    tok.seekg(0);
    return duzina/sizeof(TipElemenata);
}

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::DodajNoviElement (const TipElemenata &element)
{
    tok.seekp(0, std::ios::end);
    TipElemenata pomocna(element);
    tok.write(reinterpret_cast<char*> (&pomocna), sizeof pomocna);
    tok.seekp(0);
}

template <typename TipElemenata>
TipElemenata DatotecniKontejner<TipElemenata>::DajElement (int pozicija)
{
    if(pozicija<0 || pozicija>DajBrojElemenata()-1)
        throw std::range_error("Neispravna pozicija");
    tok.seekg(0, std::ios::beg);
    tok.seekg(pozicija*sizeof(TipElemenata));
    TipElemenata element;
    tok.read(reinterpret_cast<char*> (&element), sizeof element);
    tok.seekg(0);
    return element;
}

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::IzmijeniElement (int pozicija, const TipElemenata &element)
{
    if(pozicija<0 || pozicija>DajBrojElemenata()-1)
        throw std::range_error("Neispravna pozicija");
    tok.seekg(0, std::ios::beg); tok.seekp(0);
    TipElemenata pomocna, element1(element);
    int brojac(0);
    while(tok.read(reinterpret_cast<char *> (&pomocna), sizeof pomocna)) {
        if(brojac==pozicija) {
            tok.write(reinterpret_cast<char*> (&element1), sizeof element1);
            break;
        }
        brojac++;
    }
    tok.seekg(0);
    tok.seekp(0);
}

int main ()
{

    /*DatotecniKontejner<double> dk1("ime14.DAT");
    std::vector<double> v {2.8,1.2,3,4,5.6};
    for(int i=0 ; i < v.size(); i++)
        dk1.DodajNoviElement(v[i]);

    std::cout<<"Sortiran niz: ";
    dk1.Sortiraj();
    std::ifstream ulazni_tok("ime14.DAT", std::ios::binary);
    double broj;
    while(ulazni_tok.read(reinterpret_cast<char*> (&broj), sizeof broj ))
        std::cout<<broj<<" ";*/

    try {
        DatotecniKontejner<int> kontejner("ELMIRA.DAT");
        std::ofstream izlazni_tok("ELMIRA.DAT", std::ios::binary);
        for(int i=0; i<3; i++) {
            int unos;
            std::cin>>unos;
            izlazni_tok.write(reinterpret_cast<char*> (&unos), sizeof unos);
        }
        izlazni_tok.close();
        kontejner.DodajNoviElement(55);
        kontejner.DodajNoviElement(13);
        std::cout<<"Broj elemenata: "<<kontejner.DajBrojElemenata()<<std::endl;
        std::ifstream ulazni_tok("ELMIRA.DAT", std::ios::binary);
        int broj;
        std::cout<<"Elementi su: ";
        while(ulazni_tok.read(reinterpret_cast<char*> (&broj), sizeof broj ))
            std::cout<<broj<<" ";
        kontejner.Sortiraj();
        ulazni_tok.close();
        ulazni_tok.open("ELMIRA.DAT", std::ios::binary);
        std::cout<<"\nSortirani elementi: ";
        while(ulazni_tok.read(reinterpret_cast<char*> (&broj), sizeof broj ))
            std::cout<<broj<<" ";
    } catch (std::logic_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }
    return 0;
}
