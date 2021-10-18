#include <iostream>
#include <vector>
#include <stdexcept>
#include <type_traits>
#include <algorithm>
#include <new>
#include <cmath>
#include <array>
#include <deque>

/*   types of how to move an array when inserting an element     */
enum class ArrayMove {RIGHT = -1, LEFT = 1};

/*   paziti na overflow funkcije || PROVJERITI / EDIT  */
int  setFunction(int x, int y) { return (-2*x + y); }
/*   is prime function */     
bool isPrime(const int &num) {
     /* error check */
     if(std::abs(num) <= 1) return false;
     
	for(int i(2); i <= static_cast<int>(std::sqrt(std::abs(num))); ++i)
		if(num % i == 0) return false; 		
		
	return true;
}
/*   get number of prime factors of a number      */
int  primeFactors(int n) {
     if(n <= 0)          return 0;
     if(isPrime(n))      return 1;
     
     int _faktora {0};
     for(int i{2}; std::abs(n) > 1; ++i) {
          if(n % i == 0 && isPrime(i)) 
               for(;n % i == 0; ++_faktora)
                    n /= i;
     }
          
     return _faktora;
}
/*   check function for sort  */
bool sortNumbersByPrimeFactors(int a, int b) {
     if(primeFactors(a) == primeFactors(b)) return a > b;
     return (primeFactors(a) > primeFactors(b));
}
/*   function to return default value of specified variable type >> get underlying type function    */
template <typename T> 
auto getType(const T &x) -> typename std::iterator_traits<T>::value_type { 
     return typename std::iterator_traits<T>::value_type(); 
}
/*   function to print array       */
template <typename T> 
void IspisiArr(T poc, T kraj) {
     for(;poc!=kraj;poc++)
          std::cout << *poc << ' ';
     std::cout << std::endl;
}
/*   function to insert variable at a certain place in array     */
template <typename iterType>
void SwapValues(iterType _oldPos, iterType _newPos) {
     ArrayMove _where {_oldPos > _newPos ? ArrayMove::RIGHT : ArrayMove::LEFT};
     
     decltype(getType(_oldPos)) temp = *_oldPos;
     for(;; _oldPos += int(_where)) {
          if(_where == ArrayMove::RIGHT && !(_oldPos + int(_where) >= _newPos)) break;
          else if(_where == ArrayMove::LEFT && !(_oldPos + int(_where) <= _newPos)) break;
          
          *_oldPos = *(_oldPos + int(_where));
     }
     *_newPos = temp;
}

/*                            */
/*   function to implement    */
/*                            */
template <typename iterType1, typename iterType2, typename iterType3, typename F1, typename F2> 
void SortirajPodrucjeVrijednosti(iterType1 _startS1, iterType1 _endS1,
     iterType2 _startS2, iterType3 _startS3,
     F1 f, 
     F2 fSort)
{
     if(_startS1 >= _endS1) return;
     /*   intialising    */
     size_t _arrSize {static_cast<size_t>(_endS1 - _startS1)};
     std::sort(_startS1, _endS1, fSort);
     std::sort(_startS2, _startS2 + _arrSize, fSort);
     
     /*   start doing something      */
     for(int i {0};_startS1 < _endS1; ++i) {
          auto _pos = std::find(_startS3, _startS3 + _arrSize, f(*_startS1, *_startS2));
          if(_pos >= _startS3 + _arrSize) 
               throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
          
          SwapValues(_pos, _startS3 + i);
          
          ++_startS1;
          ++_startS2;
     }
}
/*   funkcija za unos vektora      */
void UnosVektora(std::vector<int> &vektor, int _size) {
     for(int num;;) {
          std::cin >> num;
          if(std::find(vektor.begin(), vektor.end(), num) == vektor.end())
               vektor.push_back(num);
          if(vektor.size() == _size) break;
     }
}

/*   program logic     */
int  main () {
     int n;
     std::cout << "Unesite broj elemenata: ";
     std::cin >> n;
     std::vector<int> S1, S2, S3;
     std::cout << "Unesite elemente prvog vektora: ";
     UnosVektora(S1, n);
     std::cout << "Unesite elemente drugog vektora: ";
     UnosVektora(S2, n);
     std::cout << "Unesite elemente treceg vektora: ";
     UnosVektora(S3, n);
     std::cout << std::endl;
     try {           
          SortirajPodrucjeVrijednosti(std::begin(S1), std::end(S1), std::begin(S2), std::begin(S3), 
              setFunction, sortNumbersByPrimeFactors);
              
          std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: \n";
          for(int i{0}; i < n; i++)
               std::cout << "f("<< S1.at(i) << ", " << S2.at(i) << ") = " << S3.at(i) << "\n";
     }
     catch(std::exception& e) {
          std::cout << "Izuzetak: " <<e.what();
          return -1;
     }
	return 0;
}