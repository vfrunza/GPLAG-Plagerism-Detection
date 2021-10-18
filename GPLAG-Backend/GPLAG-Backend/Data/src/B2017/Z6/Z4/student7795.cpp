/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <string>
#include <utility>




/// DEFINITION OF CLASS DATCONTAINER
template <class T> 
class DatotecniKontejner {
private:
    std::fstream stream;
    //std::string filePath;
    
    void checkPosition(int pos) { if (pos < 0 || pos >= DajBrojElemenata()) throw std::range_error("Neispravna pozicija"); }
    void throwLogicError(const std::string& text) { throw std::logic_error(text); }
    void ReopenStream() {
        stream.sync();
    }
public:
    DatotecniKontejner(const std::string& file);
    
    int DajBrojElemenata();
    T DajElement(int pos);
    
    void DodajNoviElement(const T &element);
    void IzmijeniElement(int pos, const T &element);
    void Sortiraj(std::function<bool(const T&, const T&)> criteria = std::less<T>());
};

/// implementation of class interface
template <class T> 
DatotecniKontejner<T>::DatotecniKontejner(const std::string& file) : 
    stream(file, std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc) {
    if(!stream) throwLogicError("Problemi prilikom otvaranja ili kreiranja datoteke");
}

template <class T> 
void DatotecniKontejner<T>::DodajNoviElement(const T &element) {
    stream.seekp(0, std::ios::end);
    stream.write(reinterpret_cast<const char*>(&element), sizeof(element));
    ReopenStream();
    if(!stream) throwLogicError("Problemi prilikom pristupa datoteci");
}

template <class T> 
int DatotecniKontejner<T>::DajBrojElemenata() {
    ReopenStream();
    stream.seekg(0, std::ios::end);
    return stream.tellg() / int(sizeof(T));
}

template <class T> 
T DatotecniKontejner<T>::DajElement(int pos) {
    checkPosition(pos);
    ReopenStream();
    T element;
    stream.seekg(pos * int(sizeof(T)), std::ios::beg);
    stream.read(reinterpret_cast<char*>(&element), sizeof(T));
    if(!stream) throwLogicError("Problemi prilikom pristupa datoteci");
    return element;
}

template <class T>
void DatotecniKontejner<T>::IzmijeniElement(int pos, const T &element) {
    checkPosition(pos);
    ReopenStream();
    stream.seekg(pos * int(sizeof(T)), std::ios::beg);
	stream.write(reinterpret_cast<const char*>(&element), sizeof(T));
    if(!stream) throwLogicError("Problemi prilikom pristupa datoteci");
}

template <class T>
void DatotecniKontejner<T>::Sortiraj(std::function<bool(const T&, const T&)> criteria) {
    ReopenStream();
    int size (DajBrojElemenata()), bytes(sizeof(T));
    for(int i(0); i < size - 1; ++i) {
        for(int j(0); j < size - i - 1; ++j) {
            T elem1, elem2;
			stream.seekg(j * bytes, std::ios::beg);
			stream.read(reinterpret_cast<char*>(&elem1), bytes);
			stream.seekg((j + 1) * bytes, std::ios::beg);
			stream.read(reinterpret_cast<char*>(&elem2), bytes);
            if(!stream) throwLogicError("Problemi prilikom pristupa datoteci");
            if (!criteria(elem1, elem2)) {
				stream.seekp(j * bytes, std::ios::beg);
				stream.write(reinterpret_cast<char*>(&elem2), bytes);
				stream.seekp((j + 1) * bytes, std::ios::beg);
				stream.write(reinterpret_cast<char*>(&elem1), bytes);
                if(!stream) throwLogicError("Problemi prilikom pristupa datoteci");
            }
        }
    }
}

int main () {
	DatotecniKontejner<double> datoteka("podaci.dat");	
	datoteka.DodajNoviElement(6.5);
	datoteka.DodajNoviElement(1);
	datoteka.DodajNoviElement(1);
	datoteka.DodajNoviElement(87);
	datoteka.DodajNoviElement(271.12);
	int size(datoteka.DajBrojElemenata());
	
	for(int i(0); i < size; ++i)
		std::cout << datoteka.DajElement(i) << " ";
		
	std::cout << "\nSortirano: " << std::endl;
	datoteka.Sortiraj();
	for (int i(0); i < size; ++i)
		std::cout << datoteka.DajElement(i) << " ";
	return 0;
}
