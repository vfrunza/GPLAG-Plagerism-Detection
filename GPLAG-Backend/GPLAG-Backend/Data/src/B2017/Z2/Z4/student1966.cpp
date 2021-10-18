/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <type_traits>

// PROTOTIPI
// Pomocne funckije
bool isPrime(int);
unsigned int numOfPrimeFactors(int);
void inputVector(std::vector<int>&, int);

template <typename IterType1, typename IterType2, typename IterType3, typename Func, typename Criteria>
void SortirajPodrucjeVrijednosti(IterType1, IterType1, IterType2, IterType3, Func, Criteria);

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	
	std::vector<int> x, y, z;
	
	std::cout << "Unesite elemente prvog vektora: ";
	inputVector(x, n);
	
	std::cout << "Unesite elemente drugog vektora: ";
	inputVector(y, n);
	
	std::cout << "Unesite elemente treceg vektora: ";
	inputVector(z, n);
	
	std::cout << std::endl;
	
	try {
		SortirajPodrucjeVrijednosti(x.begin(), x.end(), y.begin(), z.begin(),
				[](int x, int y) { return -2 * x + y; },
				[](int x, int y) {
					unsigned int numX{numOfPrimeFactors(x)}, numY{numOfPrimeFactors(y)};
					return numX > numY || (numX == numY && x > y);
				}
		);
	}
	catch (std::logic_error le) {
		std::cout << "Izuzetak: " << le.what() << std::endl;
		
		return 0;
	}
	
	std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:" << std::endl;
	for (int i{0}; i < n; i++)
		std::cout << "f(" << x[i] << ", " << y[i] << ") = " << z[i] << std::endl;
	
	return 0;
}

template <typename IterType1, typename IterType2, typename IterType3, typename Func, typename Criteria>
void SortirajPodrucjeVrijednosti(IterType1 p1, IterType1 p2, IterType2 p3, IterType3 p4, Func F, Criteria crit)
{
	// Prvo moramo pronaci kraj drugog i treceg bloka
	auto p3_end(p3);
	auto p4_end(p4);
	for (auto it(p1); it != p2; it++, p3_end++, p4_end++);
	
	// Sortiranje prva dva bloka
	try {
		std::sort(p1, p2, crit);
		std::sort(p3, p3_end, crit);
	}
	catch(...) {
		throw std::logic_error("Funkcija kriterija nije valjana");
	}
	
	for (auto it(p4); p1 != p2; p1++, p3++, it++)
	{
		auto pos(std::find(p4, p4_end, F(*p1, *p3)));
		
		if (pos == p4_end)
			throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
			
		std::swap(*it, *pos);
	}
}

void inputVector(std::vector<int> &v, int n)
{
	for (int i = 0; i < n; i++)
	{
		int tmp;
		std::cin >> tmp;
		
		if (find(v.begin(), v.end(), tmp) != v.end())
		{
			i--;
			continue;
		}
		
		v.push_back(tmp);
	}
}

unsigned int numOfPrimeFactors(int n)
{
	if (n == 1)
		return 0;
	
	int res{0};
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return 1 + numOfPrimeFactors(n / i);
			
	return res;
}