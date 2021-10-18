#include <iostream>
#include <fstream>
#include <stdexcept>
#include <functional>
#include <complex>
#include <iomanip>

using std::cout;
using std::endl;
template <typename TipElemenata>
class DatotecniKontejner
{
    std::fstream tok;
public:
    DatotecniKontejner(const std::string &ime_datoteke) {
        tok.open(ime_datoteke,std::ios::binary |std::ios::in);
        if(!tok) tok.open(ime_datoteke, std::ios::binary |std::ios::out);
        tok.close();
        tok.open(ime_datoteke, std::ios::binary | std::ios::in |std::ios::out);
        if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
        tok.seekg(0);
    }
    void DodajNoviElement(const TipElemenata &element) {
        tok.seekp(0,std::ios::end);
        if (!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        tok.write(reinterpret_cast<const char*>(&element), sizeof (TipElemenata));
        tok.seekg(0);
    }
    int DajBrojElemenata() {
        tok.seekg(0,std::ios::end);
        if (!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        return tok.tellg()/sizeof(TipElemenata);
        tok.seekg(0);
    }
    TipElemenata DajElement(int pozicija) {
        if(pozicija<0 || pozicija>=DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
        tok.seekg(pozicija*sizeof(TipElemenata));
        TipElemenata x;
        tok.read(reinterpret_cast<char*>(&x),sizeof(TipElemenata));
        if(tok.fail() && !tok.eof()) {
            tok.clear();
            throw std::logic_error("Probemi prilikom pristupa datoteci");
        }
        tok.seekg(0);
        return x;
    }
    void IzmijeniElement(int pozicija, const TipElemenata &element) {
        if(pozicija<0 || pozicija>=DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
        tok.seekp(pozicija*sizeof(TipElemenata));
        tok.write(reinterpret_cast<const char*>(&element),sizeof(TipElemenata));
        if(tok.fail() && !tok.eof()) {
            tok.clear();
            throw std::logic_error("Probemi prilikom pristupa datoteci");
        }
        tok.seekg(0);
    }
    void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij = std::less<TipElemenata>()) {
        tok.seekg(0);
        for(int i=0; i<DajBrojElemenata()-1; i++) {
            int k=i;
            for(int j=i+1; j<DajBrojElemenata(); j++) {
                if(kriterij(DajElement(j),DajElement(k)))
                    k=j;
            }
            TipElemenata temp = DajElement(k);
            IzmijeniElement(k,DajElement(i));
            IzmijeniElement(i,temp);
        }
    }
};

int main ()
{
    DatotecniKontejner<int> d("binarna.dat");
    d.DodajNoviElement(5);
    d.DodajNoviElement(4);
    d.DodajNoviElement(3);
    d.DodajNoviElement(55);
    d.DodajNoviElement(13);
    std::cout << d.DajBrojElemenata() << std::endl;
    d.IzmijeniElement(1,1);
    d.Sortiraj(std::greater<int>());
    for(int i=0; i<d.DajBrojElemenata(); i++)
        std::cout << d.DajElement(i) << " ";
    cout << endl <<endl;
    DatotecniKontejner<char> a("binchar.dat");
    a.DodajNoviElement('M');
    a.DodajNoviElement('A');
    a.DodajNoviElement('N');
    a.DodajNoviElement('D');
    a.DodajNoviElement('A');
    a.DodajNoviElement(' ');
    a.DodajNoviElement('T');
    a.DodajNoviElement('H');
    a.DodajNoviElement('E');
    a.DodajNoviElement(' ');
    a.DodajNoviElement('K');
    a.DodajNoviElement('I');
    a.DodajNoviElement('N');
    a.DodajNoviElement('G');
    for(int i=0; i<a.DajBrojElemenata(); i++)
        std::cout << static_cast<char>(a.DajElement(i)) << " ";

    a.Sortiraj(std::less<char>());
    cout << endl;
    for(int i=0; i<a.DajBrojElemenata(); i++)
        std::cout << static_cast<char>(a.DajElement(i)) << " ";
    a.Sortiraj(std::greater<char>());
    cout << endl;
    for(int i=0; i<a.DajBrojElemenata(); i++)
        std::cout << static_cast<char>(a.DajElement(i)) << " ";
    cout << endl <<endl;
    try {
        cout << a.DajElement(0) <<endl;
        a.IzmijeniElement(0,'P');
        cout << a.DajElement(0) <<endl;
        cout << a.DajElement(a.DajBrojElemenata())<< endl;
    } catch(std::exception &ex) {
        cout << ex.what() << endl;
    }
    return 0;
}
