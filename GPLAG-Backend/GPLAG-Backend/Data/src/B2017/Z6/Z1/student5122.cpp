#include <iostream> 
#include <iomanip> 
#include <fstream>
int main()
{
    std::ifstream datoteka_studenata("STUDENTI.TXT");
    char ime_studenta[100];
    int indeks_studenta;
    while(datoteka_studenata.getline(ime_studenta, sizeof ime_studenta)) {
        datoteka_studenata >> indeks_studenta;
        datoteka_studenata.ignore(10000, '\n');
        std::ifstream datoteka_ocjena("OCJENE.TXT");
        int suma_ocjena(0), broj_ocjena(0), tekuci_indeks, tekuca_ocjena;
        while(datoteka_ocjena >> tekuci_indeks >> tekuca_ocjena)
            if(tekuci_indeks == indeks_studenta) {
                suma_ocjena += tekuca_ocjena;
                broj_ocjena++;
            }
        std::cout << ime_studenta << " ";
        if(suma_ocjena == 0) std::cout << "NEOCIJENJEN";
        else
            std::cout << std::setprecision(3) << double(suma_ocjena) / broj_ocjena;
        std::cout << std::endl;
    }
    return 0;
}