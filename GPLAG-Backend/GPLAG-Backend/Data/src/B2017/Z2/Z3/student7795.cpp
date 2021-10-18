#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <string>
#include <type_traits>
#include <limits>

// predefined for 
using CustomType = unsigned long long;

enum class FillType {Increasing, Decreasing};
/*   user defined functions  	*/
/*	validity function		*/
template <class T>
void throwCustomException(const std::vector<T> &inputArr) {
	if(inputArr.empty()) 
		throw "Prazan vektor!";
     else if(std::find_if(inputArr.begin(), inputArr.end(), [](T value) -> bool { return value <= T(); }) != inputArr.end() ||
     		!std::numeric_limits<T>::is_integer) 
     	throw std::domain_error("Neispravan vektor!");
}
/*   funkcija za pronalazak perioda, radjena na Tutorijalu 2, zadatak 2	*/
template <class T>
bool TestPerioda(const std::vector<T> &inputArr, const CustomType &p) {
	/* 	find basic cylce 	*/
	CustomType cycle ((inputArr.size()-1) / p), pos(0);
	/* 	check array 	*/
	for(CustomType i(0); i < p; ++i) {
		for(CustomType j(0); j <= cycle; ++j) {
			pos = j * p + i;
			if(pos < inputArr.size()) 
				if(inputArr.at(i) != inputArr.at(pos)) return false;
		}
	}
	return true;
}
/*	function to return period for an array 	*/
template <class T>
CustomType PostaviPeriod(const std::vector<T> &inputArr) {
    	for(CustomType i(1); i < inputArr.size(); ++i) 
          if(TestPerioda(inputArr, i)) return i;
	return -1;
}
/*	find array data -> period and koliko_puta 	*/
template <class T>
CustomType SetSizeNPeriod(const std::vector<T> &inputArr, int &koliko_puta) {
     CustomType _period(PostaviPeriod(inputArr));			// set period
     /*	return values	*/
     koliko_puta = static_cast<int>(inputArr.size() / _period);
     if(_period == -1) {							koliko_puta  = 2; _period = inputArr.size(); }
     else if((inputArr.size() % _period) != 0)		koliko_puta += 1;
     return _period;
}
/*	fill an array with number based on fill type (Increasing - 1 2 3 | Decreasing - 3 2 1)	*/
template <class T>
void PopuniRed(T* red, const CustomType &period, const CustomType &velicina, const FillType &nacin, CustomType initialValue = CustomType()) {
	CustomType _element = (nacin == FillType::Decreasing) ? initialValue-velicina+1 : velicina;
	CustomType incrType = (nacin == FillType::Decreasing) ? 1:-1;
	for(CustomType i(0); i < velicina; ++i) {
		red[i] = _element;
		_element += incrType;
	}
}
/*                            */
/*   functions to implement   */
/*                            */
template <class T>
T** AlocirajFragmentirano(const std::vector<T> &inputArr, int &koliko_puta) {
	throwCustomException(inputArr);					// 	input validity check
	
     CustomType period (SetSizeNPeriod(inputArr, koliko_puta));	//   find period and create array with given period
     T** output (nullptr);
     try { output = new T*[koliko_puta * period]; }
     catch (...) { throw; }
     
     T _maxElement (*std::max_element(inputArr.begin(), inputArr.end())), _pos(0);
     /*	kreiraj elemente i popuni matricu	*/
     for(CustomType i(0); i < period * koliko_puta; ++i) {
		try {
     		output[i] = new T[inputArr.at((_pos = i % period))];
     		PopuniRed(output[i], period, inputArr.at(_pos), FillType::Decreasing, static_cast<CustomType>(_maxElement));
     	}
     	catch (std::exception& e) {
     		for(CustomType k(0); k < i; ++k) 
     			delete [] output[k];
     		delete [] output;
     		throw;
     	}
     }
     return output;
}
template <class T>
T** AlocirajKontinualno(const std::vector<T> &inputArr, int &koliko_puta) {
	throwCustomException(inputArr);					// 	input validity check
     
     CustomType period (SetSizeNPeriod(inputArr, koliko_puta));	//   find period and create array with given period
     T** output(nullptr);
     try { output = new T*[koliko_puta * period]{}; }
     catch (...) { throw; }
     
     CustomType _size(0);
     std::for_each(inputArr.begin(), inputArr.begin()+period, [&_size](T num) { _size += static_cast<CustomType>(num); });
     _size *= koliko_puta;
     try { output[0] = new T[_size]; }
     catch (std::exception& e) { 
     	delete [] output;
     	throw; 
     }
     
     for(CustomType i(0); i < koliko_puta * period; ++i) {
		if(i > 0) output[i] = output[i - 1] + inputArr.at((i - 1) % period);
		PopuniRed(output[i], period, inputArr.at(i % period), FillType::Increasing);
	}
	return output;
}
/* 	Unos broja funkcija koju smo pravili na tutorijalu 	*/
template <class T>
void UnosBroja(const std::string &promptText, const std::string &errorMessage, 
			T &var, const T &lowerBound, T upperBound = std::numeric_limits<T>::max()) {
     T tempInputVar;
     std::cout << promptText;
     for(;;) {
          std::cin >> tempInputVar;
          if(!std::cin || tempInputVar < lowerBound || tempInputVar > upperBound) {
               std::cin.clear();
               std::cin.ignore(10000, '\n');
               std::cout << errorMessage;
          }
          else {
               var = tempInputVar;
               break;
          }
     }
}
/*	function to print matrix		*/
template <class T>
void IspisiMatricu(const T *const *output, const std::vector<T> &inputArr, const CustomType &period, const int &koliko_puta) {
     for(CustomType i(0); i < koliko_puta * period; ++i) {
     	for(CustomType j(0); j < inputArr.at(i % period); ++j)
     		std::cout << std::setw(3) << std::left << output[i][j];
     	std::cout << std::endl;
     }
}
/*   main program logic */
int main () {
	int n, alokacija, koliko_puta(0);
	UnosBroja<int>("Unesite broj elemenata vektora: ", "Greska, unesite ponovo: ", n, 0);
	
	std::cout << "Unesite elemente vektora: ";
	int period(0);
	int** output(nullptr);
	std::vector<int> inputArr(n, 0);
	std::for_each(inputArr.begin(), inputArr.end(), [](int &num) { std::cin >> num; });
	
	UnosBroja<int>("Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ", "Greska, unesite ponovo: ", alokacija, 0, 1);
	try {
		output 	=  (alokacija == 0) ? AlocirajKontinualno(inputArr, koliko_puta): AlocirajFragmentirano(inputArr, koliko_puta);
		period 	=  SetSizeNPeriod(inputArr, koliko_puta);	
		std::cout << "Dinamicki alocirana matrica: " << std::endl;
		IspisiMatricu(output, inputArr, period, koliko_puta);
	}
	catch (const char greska[]) {
		std::cout << "Izuzetak: " << greska  << std::endl;
		delete [] output;
		return -1;
	}
	catch (std::exception& e) {
		std::cout << "Izuzetak: " << e.what() << std::endl;
		delete [] output;
		return -1;
	}
	
	// 	empty taken memory //
	if(alokacija == 1) 
		for(int i(0); i < koliko_puta * period; ++i)
			delete [] output[i];
	else delete [] output[0];
		
	delete [] output;
	return 0;
}