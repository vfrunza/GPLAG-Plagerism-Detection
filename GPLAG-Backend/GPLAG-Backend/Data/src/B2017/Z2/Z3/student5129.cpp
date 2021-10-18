/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

#include <vector>

#include <stdexcept>

template <typename IntType>
bool areValidDim(const std::vector<IntType> &);

template <typename IntType>
int findPeriod(const std::vector<IntType> &);

template <typename IntType>
IntType **AlocirajFragmentirano(const std::vector<IntType>&, int&);

template <typename IntType>
IntType **AlocirajKontinualno(const std::vector<IntType>&, int&);

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	std::vector<int> v(n);
	std::cout << "Unesite elemente vektora: ";
	for (auto &el : v)
		std::cin >> el;
	
	int fragmentation;
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin >> fragmentation;
	
	if (fragmentation != 0 && fragmentation != 1)
		return 0; // problem
	
	int **res{nullptr};
	int koliko{0};
	
	try {
		if (fragmentation == 0)
			res = AlocirajKontinualno(v, koliko);
		else
			res = AlocirajFragmentirano(v, koliko);
	}
	catch (std::domain_error er) {
		std::cout << "Izuzetak: " << er.what() << std::endl;
		return 0;
	}
	
	int period{findPeriod(v)};
	std::cout << "Dinamicki alocirana matrica:" << std::left << std::endl;
	for (int i = 0; i < koliko * period; i++)
	{
		for (int j = 0; j < v[i < period ? i : i - period]; j++)
			std::cout << std::setw(3) << res[i][j];

		std::cout << std::endl;
	}
	
	if (fragmentation == 0)
		delete[] res[0];
	else
		for (int i = 0; i < koliko * period; i++)
			delete[] res[i];
	
	delete[] res;
	
	return 0;
}

template <typename IntType>
IntType **AlocirajFragmentirano(const std::vector<IntType> &v, int &koliko_puta)
{
	if (!areValidDim(v))
		throw std::domain_error("Neispravan vektor!");
	
	int period{findPeriod(v)};
	koliko_puta = v.size() / period + (v.size() % period != 0 || v.size() == period ? 1 : 0);
	
	IntType **ret{nullptr};
	try {
		ret = new IntType*[koliko_puta * period]{};
		
		for (int i = 0; i < koliko_puta * period; i++)
			ret[i] = new IntType[i >= v.size() ? v[i - period] : v[i]]{};
	}
	catch (...) {
		if (ret != nullptr)
			for (int i = 0; i < koliko_puta * period; i++)
				delete[] ret[i];
				
		delete[] ret;
		
		throw;
	}
	
	IntType beginNumber = *std::max_element(v.begin(), v.end());
	for (int i = 0; i < koliko_puta * period; i++)
		for (int j = 0; j < v[i >= v.size() ? i - period : i]; j++)
			ret[i][j] = beginNumber - v[i >= v.size() ? i - period : i ] + j + 1;
	
	return ret;
}

template <typename IntType>
IntType **AlocirajKontinualno(const std::vector<IntType> &v, int &koliko_puta)
{
	if (!areValidDim(v))
		throw std::domain_error("Neispravan vektor!");
	
	int period{findPeriod(v)};
	koliko_puta = v.size() / period + (v.size() % period != 0 || v.size() == period ? 1 : 0);
	
	int howManySlots = 0;
	for (int i = 0; i < koliko_puta * period; i++)
		howManySlots += v[i < period ? i : i - period];
	
	IntType **ret{nullptr};
	try {
		ret = new IntType*[koliko_puta * period]{};
		ret[0] = new IntType[howManySlots];
	}
	catch (...) {
		if (ret != nullptr)
			delete[] ret[0];
			
		delete[] ret;
	}
	
	for (int i = 1; i < koliko_puta * period; i++)
		ret[i] = ret[i - 1] + v[i <= period ? i - 1 : i - period - 1];
		
	for (int i = 0; i < koliko_puta * period; i++)
		for (int j = 0; j < v[i < period ? i : i - period]; j++)
			ret[i][j] = v[i < period ? i : i - period] - j;
			
	return ret;
}

template <typename IntType>
int findPeriod(const std::vector<IntType> &v)
{
	auto searchBegin = v.begin(), found = v.begin();
	
	while ((found = std::find(searchBegin + 1, v.end(), v[0])) != v.end())
	{
		auto ptr1 = v.begin(), ptr2 = found;
		while (ptr2 != v.end() && *ptr1 == *ptr2)
		{
			ptr1++;
			ptr2++;
		}
		
		if (ptr2 == v.end())
			break;
			
		searchBegin = found;
	}
	
	return static_cast<int>(found - v.begin());
}

template <typename IntType>
bool areValidDim(const std::vector<IntType> &dims)
{
	if (dims.size() == 0)
		throw std::domain_error("Prazan vektor!");
	
	for (auto dim : dims)
		if (dim <= 0)
			return false;
			
	return true;
}