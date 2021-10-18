/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <string>
#include <stdexcept>
#include <functional>
#include <fstream>

template <typename TipElementa>
class DatotecniKontejner {
    std::fstream tok;
    public:
    DatotecniKontejner (const std::string &ime_datoteke);
    void DodajNoviElement (const TipElementa &element);
    int DajBrojElemenata ();
    TipElementa DajElement (int pozicija);
    void IzmijeniElement (int pozicija, const TipElementa &element);
    void Sortiraj (std::function<bool(const TipElementa &, const TipElementa &)> kriterij = std::less<TipElementa>()){
        for (int i = 0; i<DajBrojElemenata(); i++)
    for (int j = i; j<DajBrojElemenata(); j++){
        if (i==j) continue;
        TipElementa e1,e2;
        tok.seekg(i*(sizeof (TipElementa)));
        tok.read(reinterpret_cast<char*>(&e1), sizeof (e1));
        tok.seekg(j*(sizeof (TipElementa)));
        tok.read(reinterpret_cast<char*>(&e2), sizeof (e2));
        
        if(!kriterij(e1,e2)){
            tok.seekp(i*(sizeof (TipElementa)));
            tok.write(reinterpret_cast<const char*>(&e2), sizeof e2);
            tok.seekp(j*(sizeof (TipElementa)));
            tok.write(reinterpret_cast<const char*>(&e1), sizeof e1);
        }
    }
    }
};

template <typename TipElementa>
DatotecniKontejner<TipElementa>::DatotecniKontejner (const std::string &ime) {
    try{
            tok.open(ime, std::ios::in | std::ios::out | std::ios::app | std::ios::binary);
            tok.close();
    tok.open(ime, std::ios::in | std::ios::out | std::ios::ate | std::ios::binary);
    if (!tok) throw std::logic_error ("Problemi prilikom otvaranja ili kreiranja datoteke");
    }
    catch (...) {
        throw std::logic_error ("Problemi prilikom otvaranja ili kreiranja datoteke");
    }
}

template <typename TipElementa>
void DatotecniKontejner<TipElementa>::DodajNoviElement (const TipElementa &element) {
    tok.seekp(0, std::ios::end);
    tok.write(reinterpret_cast<const char*>(&element), sizeof element); // mora biti const char¸
    if (!tok) throw std::logic_error ("Problemi prilikom pristupa datoteci");
    tok.seekg(0);
}

template <typename TipElementa>
int DatotecniKontejner<TipElementa>::DajBrojElemenata () {
    tok.seekp(0, std::ios::end);
    int duzina_dat(tok.tellg());
    tok.seekg(0);
    if (!tok) throw std::logic_error ("Problemi prilikom pristupa datoteci");
    return duzina_dat/sizeof(TipElementa);
}

template <typename TipElementa>
TipElementa DatotecniKontejner<TipElementa>::DajElement (int pozicija){
    if (pozicija<0 || pozicija>=DajBrojElemenata()) throw std::range_error ("Neispravna pozicija");
    tok.seekg(pozicija*(sizeof (TipElementa)));
    TipElementa element;
    tok.read(reinterpret_cast<char*>(&element), sizeof element);
    tok.seekp(0);
    if (!tok) throw std::logic_error ("Problemi prilikom pristupa datoteci");
    return element;
}

template <typename TipElementa>
void DatotecniKontejner<TipElementa>::IzmijeniElement (int pozicija,const TipElementa &element){
    if (pozicija<0 || pozicija>=DajBrojElemenata()) throw std::range_error ("Neispravna pozicija");
    tok.seekp(pozicija*(sizeof (TipElementa)));
    tok.write(reinterpret_cast<const char*>(&element), sizeof element);
    if (!tok) throw std::logic_error ("Problemi prilikom pristupa datoteci");
}

int main ()
{
    
    try {
       /* 
    std::ofstream tok ("gevikti.dat", std::ios::binary);
    int broj(2),broj2(9),e(89);
    tok.write (reinterpret_cast<char*>(&broj2), sizeof broj2);
    tok.close();

    DatotecniKontejner<int> kontejner ("gevikti.dat");
    kontejner.DodajNoviElement(broj);
    kontejner.DodajNoviElement(e);
    kontejner.DodajNoviElement(broj2);

    kontejner.IzmijeniElement(2,17);
    std::cout<<kontejner.DajBrojElemenata()<<std::endl<<std::endl;
    //kontejner.Sortiraj();
    for (int i = 0; i<kontejner.DajBrojElemenata(); i++)
    std::cout<<kontejner.DajElement(i)<<std::endl;
    */
              //AT1 (c9) - Testiranje konstruktora
  DatotecniKontejner<int> dk1("ime1.DAT");
        DatotecniKontejner<int> dk2("ime1.DAT");
        DatotecniKontejner<int> dk3("ime2.DAT");
        std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<std::endl;
    }
    catch (std::logic_error izuzetak){
        std::cout<<izuzetak.what();
    }
    catch (std::range_error izuzetak){
        std::cout<<izuzetak.what();
    }
	return 0;
}
