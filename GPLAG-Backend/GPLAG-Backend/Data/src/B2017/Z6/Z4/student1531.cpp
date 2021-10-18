/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <algorithm>
#include <stdexcept>

template <typename tip>
class DatotecniKontejner
{
    std::fstream tok;
public:
    DatotecniKontejner(const std::string &ime);
    void DodajNoviElement(const tip &element);
    int DajBrojElemenata();
    tip DajElement(int pozicija);
    void IzmijeniElement(int pozicija, const tip &element);
    void Sortiraj(std::function<bool(const tip &, const tip &)> kriterij = std::less<tip>());
};
template<typename tip>
DatotecniKontejner<tip>::DatotecniKontejner(const std::string &ime)
{
    tok.open(ime, std::ios::binary | std::ios::in | std::ios::out);
    if(!tok) {
        std::ofstream temp(ime, std::ios::binary);
        temp.close();
        tok.clear();
        tok.open(ime,std::ios::binary | std::ios::in | std::ios::out);
        if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    }
}
template<typename tip>
void DatotecniKontejner<tip>::DodajNoviElement(const tip &element)
{
    if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    tok.seekp(0,std::ios::end);
    tok.write(reinterpret_cast<const char*>(&element),sizeof(element));
    tok.seekg(0);
    tok.seekp(0);
}
template<typename tip>
int DatotecniKontejner<tip>::DajBrojElemenata()
{
    if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    /*tok.seekg(0,std::ios::end);
    int end(tok.tellg());
    return (end)/sizeof(tip);*/
    tok.seekg(0, std::ios::end);
    int temp(tok.tellg());
    int velicina(temp/(sizeof (tip)));
    return velicina;
}
template<typename tip>
tip DatotecniKontejner<tip>::DajElement(int pozicija)
{
    if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    if(pozicija>=DajBrojElemenata() || pozicija<0)throw std::range_error("Neispravna pozicija");
    tok.seekg(pozicija*sizeof(tip));
    tip x;
    tok.read(reinterpret_cast<char*>(&x),sizeof(tip));
    return x;
}
template<typename tip>
void DatotecniKontejner<tip>::IzmijeniElement(int pozicija,const tip &element)
{
    if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    if(pozicija>=DajBrojElemenata() || pozicija<0)throw std::range_error("Neispravna pozicija");
    tok.seekp(pozicija*sizeof(tip));
    tok.write(reinterpret_cast<const char*>(&element),sizeof(tip));
}
template<typename tip>
void DatotecniKontejner<tip>::Sortiraj(std::function<bool(const tip &, const tip &)>kriterij)
{
    if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    tok.seekg(0);
    tip prvi,drugi;
    for(int i=0; i<DajBrojElemenata(); i++) {
        for(int j=0; j<DajBrojElemenata()-1; j++) {
            tok.seekg(j*sizeof(tip));
            tok.read(reinterpret_cast<char*>(&prvi),sizeof(tip));
            tok.read(reinterpret_cast<char*>(&drugi),sizeof(tip));
            if(!kriterij(prvi,drugi)) {
                tok.seekp(j*sizeof(tip));
                tok.write(reinterpret_cast<char*>(&drugi),sizeof(tip));
                tok.write(reinterpret_cast<char*>(&prvi),sizeof(tip));
            }
        }
    }
}

int main ()
{
    int x;
    DatotecniKontejner<int> vektor("test.dat");
    for(int i=0;; i++) {
        std::cout<<"\nUnesite broj koji zelite dodati(0 za kraj): ";
        std::cin>>x;
        if(x==0)break;
        vektor.DodajNoviElement(x);
    }
    std::cout<<"\nSortirana datoteka glasi:";
    vektor.Sortiraj();
    for(int i=0; i<vektor.DajBrojElemenata(); i++) {
        std::cout<<" "<<vektor.DajElement(i);
    }
    std::cout<<"\nUnesite poziciju na kojoj zelite izmijeniti element: ";
    std::cin>>x;
    int a;
    std::cout<<"\nUnesite novu vrijednost: ";
    std::cin>>a;
    vektor.IzmijeniElement(x,a);
    std::cout<<"\nSortirana datoteka glasi:";
    vektor.Sortiraj();
    for(int i=0; i<vektor.DajBrojElemenata(); i++) {
        std::cout<<" "<<vektor.DajElement(i);
    }
    std::cout<<"\nElement na zadnjoj poziciji je: "<<vektor.DajElement(vektor.DajBrojElemenata()-1);
    // DatotecniKontejner<double> dk1("ime3.DAT");
    // DatotecniKontejner<double> dk2("ime3.DAT");
    // DatotecniKontejner<double> dk3("ime4.DAT");

    // dk1.DodajNoviElement(1.28);

    // std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<" "<<dk3.DajBrojElemenata()<<std::endl;

    return 0;
}