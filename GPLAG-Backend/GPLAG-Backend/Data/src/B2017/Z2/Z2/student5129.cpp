/*B 2017/2018, Zadaća 2, Zadatak 2
	
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
#include <cstdlib>

#include <vector>
#include <deque>
#include <stdexcept>

enum class SmjerKretanja {
	NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Cont>
bool isCube(const Cont&);

template <typename Cont>
void reverseCont(Cont&);

template <typename Cont>
Cont PjescaniSat(Cont, SmjerKretanja);

int main ()
{
	int dim;
	std::cout << "Unesite dimenziju (x/y/z): ";
	std::cin >> dim;
	while(dim <= 0)
	{
		std::cout << "Dimenzija nije ispravna, unesite opet: ";
		std::cin >> dim;
	}
	
	std::vector<std::deque<std::deque<int>>> cont(dim, std::deque<std::deque<int>>(dim, std::deque<int>(dim)));
	std::cout << "Unesite elemente kontejnera: ";
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			for (int k = 0; k < dim; k++)
				std::cin >> cont.at(i).at(j).at(k);
				
	int dir;
	std::cout << "Unesite smjer kretanja [0 - 5]: ";
	std::cin >> dir;
	while (dir < 0 || dir > 5)
	{
		std::cout << "Smjer nije ispravan, unesite opet: ";
		std::cin >> dir;
	}
	
	std::vector<std::deque<std::deque<int>>> res;
	std::cout << std::endl;
	try {
		res = PjescaniSat(cont, static_cast<SmjerKretanja>(dir));
	}
	catch (const std::exception &ex) {
		std::cout << "Izuzetak: " << ex.what() << std::endl;
		return 0;
	}
	
	std::cout << "Pjescani sat unesene matrice je:" << std::endl;
	for (auto plane : res) {
		std::cout << std::endl;
		
		for (int j = 0; j < dim; j++) {
			for (auto element : plane[j])
				std::cout << std::setw(4 * (dim / 2 - std::abs(j - dim / 2) + 1)) << element;
				
			std::cout << std::endl;
		}
	}
	
	return 0;
}

template <typename Cont>
Cont PjescaniSat(Cont container, SmjerKretanja dir)
{
	if (container.size() == 0)
		return container;
	
	if (!isCube(container))
		throw std::domain_error("3D matrica nema oblik kocke");
		
	if (container.size() % 2 == 0)
		throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	
	typedef typename std::remove_reference<decltype(container.at(0))>::type TwoD;
	typedef typename std::remove_reference<decltype(container.at(0).at(0))>::type OneD;
	
	Cont ret;
	for (int i = 0; i < container.size(); i++)
	{
		TwoD tmp2;
		for (int j = 0; j < container.size(); j++)
		{
			OneD tmp1;
			for (int k = container.size() / 2 - std::abs(j - int(container.size()) / 2);
				 k < container.size() / 2 + 1 + abs(j - container.size() / 2); k++)
			{
				int firstDim{i}, secondDim{j}, thirdDim{k};
				if (dir == SmjerKretanja::LijevoDesno || dir == SmjerKretanja::DesnoLijevo)
					std::swap(secondDim, thirdDim);
				else if (dir == SmjerKretanja::NaprijedNazad || dir == SmjerKretanja::NazadNaprijed)
					std::swap(firstDim, secondDim);
				
				tmp1.push_back(container.at(firstDim).at(secondDim).at(thirdDim));
			}
			tmp2.push_back(tmp1);
		}
		if (static_cast<int>(dir) % 2 != 0)
			reverseCont(tmp2);
		
		ret.push_back(tmp2);
	}
	
	return ret;
}

template <typename Cont>
void reverseCont(Cont &container)
{
	for (int i = 0; i < container.size() / 2; i++)
		std::swap(container.at(i), container.at(container.size() - i - 1));
}

template <typename Cont>
bool isCube(const Cont &container)
{
	for (auto plane : container)
	{
		if (plane.size() != container.size())
			return false;
			
		for (auto row : plane)
			if (row.size() != plane.size())
				return false;
	}
	
	return true;
}