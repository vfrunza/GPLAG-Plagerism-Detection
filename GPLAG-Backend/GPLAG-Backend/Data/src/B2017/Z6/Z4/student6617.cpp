/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <functional>

// mozda su pogresni autotestovi 2, 3 i 4, dk2 je prazna u pocetku, ali joj se dodaje 1 nepostojeci element (?)

template <typename TipElemenata>
class DatotecniKontejner
{
    std::fstream tok;
public:
    DatotecniKontejner(const std::string &ime_datoteke) {
        tok=std::fstream(ime_datoteke, std::ios::out | std::ios::app | std::ios::in | std::ios::binary); // moze i sa open i close
        if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    }
    void DodajNoviElement(const TipElemenata &element) {
        /*tok.seekp(0, std::ios::end);*/
        tok.write(reinterpret_cast<const char*>(&element), sizeof element);
    }
    int DajBrojElemenata() {
        tok.seekg(0, std::ios::end);
        return (int(tok.tellg())/(sizeof(TipElemenata)));
    }
    TipElemenata DajElement(int pozicija) {
        if(pozicija<0 || pozicija>=this->DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
        TipElemenata povratni;
        for(int i=0; i<this->DajBrojElemenata(); i++) { // prolazimo kroz datoteku
            tok.seekg(i*sizeof(TipElemenata), std::ios::beg);
            if(i==pozicija) {
                if(!tok.read(reinterpret_cast<char*>(&povratni), sizeof povratni)) throw std::logic_error("Problemi prilikom pristupa datoteci");
                break;
            }
        }
        return povratni;
    }
    void IzmijeniElement(int pozicija, const TipElemenata &element) {
        if(pozicija<0 || pozicija>=this->DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
        for(int i=0; i<this->DajBrojElemenata(); i++) {
            tok.seekp(i*sizeof(TipElemenata), std::ios::beg);
            if(i==pozicija) {
                if(!tok.write(reinterpret_cast<const char*>(&element), sizeof element)) throw std::logic_error("Problemi prilikom pristupa datoteci");
                break; // samo prepisemo preko elementa
            }
        }
    }
    void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)>kriterij = std::less<TipElemenata>()) {
        // nemoguce o(n) sortiranje, pokusaj sa pomocnim var
        TipElemenata e1, e2;
        for(int i=0; i<this->DajBrojElemenata()-1; i++) { 
            // citanje
            tok.seekg(i*sizeof(TipElemenata), std::ios::beg);
            tok.read(reinterpret_cast<char*>(&e1), sizeof e1);
            tok.seekg(i*sizeof(TipElemenata)+sizeof(TipElemenata), std::ios::beg); // zbog ovog ide -1 u for petlji
            tok.read(reinterpret_cast<char*>(&e1), std::ios::beg);
            // prebacivanje sa citanja na pisanje
            tok.seekp(0, std::ios::cur);
            // pisanje sa uslovima
            if(!kriterij(e1, e2)) { // ako e1 ne treba biti ispred e2
                // zamjena
                tok.seekp(i*sizeof(TipElemenata), std::ios::beg);
                tok.write(reinterpret_cast<char*>(&e2), sizeof e2);
                tok.seekp(i*sizeof(TipElemenata)+sizeof(TipElemenata), std::ios::beg);
                tok.write(reinterpret_cast<char*>(&e1), sizeof e1);
                tok.seekg(0, std::ios::cur); // smjena sa pisanja na citanje u novoj iteraciji, za svaki slucaj
            }
        }
    }
};


int main ()
{
	return 0;
}
