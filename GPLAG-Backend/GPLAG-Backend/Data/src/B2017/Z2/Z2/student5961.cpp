#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <type_traits>
#include <stdexcept>
#include <iomanip>
#include <limits>

/* 	types of legal movements 	*/
enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };

/*	function to throw exception with custom params 	*/
enum class ErrorType { NotOdd, NotCubeShape };
void throwCustomException(const ErrorType &_ERROR) {
	if(_ERROR == ErrorType::NotOdd) 			throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	else if(_ERROR == ErrorType::NotCubeShape) 	throw std::domain_error("3D matrica nema oblik kocke");
}
/* 	find location of an element that will be on position (x,y) based on trajectory path _path 	*/
void GiveNewPosition(const int& x, const int &y, const int &dim,
				 int &_newX, int &_newY, int &_newDim, const SmjerKretanja _path, const int &_size) {
	_newX = (_path == SmjerKretanja::GoreDolje) 		? y : x;
	_newY = (_path == SmjerKretanja::LijevoDesno) 	? y : x;
	_newDim = dim;
	if(_path == SmjerKretanja::DesnoLijevo) 		_newY = _size - y - 1;
	else if(_path == SmjerKretanja::DoljeGore) 		_newX = _size - y - 1;
	else if(_path == SmjerKretanja::NaprijedNazad || _path == SmjerKretanja::NazadNaprijed) {
		_newDim 	= 	(_path == SmjerKretanja::NaprijedNazad) ?  y : _size - 1 - y;
		_newX 		= 	dim; 
		_newY 		= 	x;
	}
}
/*						*/
/* 	function to implement 	*/
/*						*/
template <class kont> 
auto PjescaniSat(kont input3DContainer, SmjerKretanja _path) -> kont {
	// 	check validity of matrix		
	int _dim (input3DContainer.size());
	for(auto _matrix: input3DContainer) {
		if(_matrix.size() != _dim) 		throwCustomException(ErrorType::NotCubeShape);
		for(auto _line: _matrix) 
			if(_line.size() != _dim) 	throwCustomException(ErrorType::NotCubeShape);
	}
	if(!(_dim % 2)) throwCustomException(ErrorType::NotOdd);
	// initialise values
	typedef typename std::remove_reference<decltype(input3DContainer.at(0))>::type 				TwoDContainer;
	typedef typename std::remove_reference<decltype(input3DContainer.at(0).at(0))>::type		 	OneDContainer;
	
	kont outputContainer;
	int _newX(0), _newY(0), _newDim(0), _selectedRow, _incrValue;
	// create output 3D array
	for(int mat (0); mat < _dim; ++mat) {
		_selectedRow = 0;
		_incrValue = 1;
		TwoDContainer _addMatrix;			// create 2D array to add in 3D array
		for(int y (0); y < _dim; ++y) {
			OneDContainer _addRow;	// create 1D array to add in 2D array
			if(y >= _dim/2) _incrValue = -1;
			for(int x (_selectedRow); x < _dim - _selectedRow; ++x) {
				GiveNewPosition(x, y, mat, _newX, _newY, _newDim, _path, _dim);
				_addRow.push_back(input3DContainer.at(_newDim).at(_newX).at(_newY));
			}
			_addMatrix.push_back(_addRow);		// add 1D array in 2D array
			_selectedRow += _incrValue;
		}
		outputContainer.push_back(_addMatrix);		// add 2D array in final 3D output array
	}
	return outputContainer;
}
/* 	function to print 3D array 	*/
template <typename T>
void printTable(const T &matrice){
	int _dim (matrice.size()), _pos(0), _incrValue(1), _selectedRow(0);
   	for(auto matrix : matrice) {
   		_selectedRow = 0; _incrValue = 1; _pos = 0;
   		std::cout << std::endl;		
   		for(auto row:matrix) {
   			if(_pos >= _dim/2) _incrValue = -1;
   			std::cout << std::string(_selectedRow * 4, ' '); // set cursor so the output looks like sand clock
     		for(auto _val : row)
     			std::cout << std::setw(4) << std::right << _val;
     		++_pos; _selectedRow += _incrValue;
          	std::cout << std::endl;
		}	
   	}
}
/* 	unos broja funkcija koju smo pravili na tutorijalu 	*/
template <typename T>
void UnosBroja(std::string promptText, std::string errorMessage, 
			T &var, T lowerBound, T upperBound = std::numeric_limits<T>::max()) {
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
/*	main program logic		*/
int main () {
	int n;
	UnosBroja<int>("Unesite dimenziju (x/y/z): ", "Dimenzija nije ispravna, unesite opet: ", n, 1);
	
	typedef std::vector<std::deque<std::deque<int>>> contType;
	contType DInput;
	try {
		DInput = contType (n, std::deque<std::deque<int>>(n, std::deque<int>(n)));	
	}
	catch(std::exception& e) {
		std::cout << "Izuzetak: " << e.what();
		return -1;
	}
	
	std::cout << "Unesite elemente kontejnera: ";
	for(int mat (0); mat < n; mat++) 
		for(int red (0); red < n; red++) 
			for(int clan (0); clan < n; clan++)
				std::cin >> DInput.at(mat).at(red).at(clan);
	
	int smjer(0);
	UnosBroja<int>("Unesite smjer kretanja [0 - 5]: ", "Smjer nije ispravan, unesite opet: ", smjer, 0, 5);
	std::cout << std::endl;
	try {
		auto izlaz (PjescaniSat(DInput, static_cast<SmjerKretanja>(smjer)));
		std::cout << "Pjescani sat unesene matrice je:" <<  std::endl;
		printTable(izlaz);
	}
	catch(std::exception& e) {
		std::cout << "Izuzetak: " << e.what();
	}
 	return 0;
}