#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <type_traits>
#include <iomanip>

enum class SmjerKretanja
{
	NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename Kont>
Kont PjescaniSat(Kont kont, SmjerKretanja smjer)
{
	int n(kont.size());
	if (n == 0) return kont;
	for (int i(0); i < n; i++)
	    if (kont.at(i).size() != n) throw std::domain_error("3D matrica nema oblik kocke");
	    else 
	        for (int j(0); j < kont.at(i).size(); j++)
	        	if (kont.at(i).at(j).size() != n) throw std::domain_error("3D matrica nema oblik kocke");
	if (n % 2 == 0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	Kont ret;
	for (int i(0); i < n; i++)
	{
		typename std::remove_reference<decltype(ret.at(0))>::type a;
	    for (int j(0); j < n; j++)
	    {
	    	typename std::remove_reference<decltype(ret.at(0).at(0))>::type b;
	        for(int k(0); k < n; k++)
	        	if (j <= n/2 ? (j <= k && k <= n-1-j) : (n-1-j <= k && k <= j))
	        	{
	        		int niz[][3] {{j, i, k}, {n-1-j, i, k}, {i, j, k}, {i, n-1-j, k}, {i, k, j}, {i, k, n-1-j}};
	        		b.push_back(kont.at(niz[int(smjer)][0]).at(niz[int(smjer)][1]).at(niz[int(smjer)][2]));
	        	}
	        a.push_back(b);
	    }
	    ret.push_back(a);
	}
	return ret;
}
int main()
{
	int n, smjer;
	std::cout << "Unesite dimenziju (x/y/z): ";
	while (std::cin >> n, n < 0)
	    std::cout << "Dimenzija nije ispravna, unesite opet: ";
	std::cout << "Unesite elemente kontejnera: ";
	try
	{
		std::vector<std::deque<std::deque<int>>> v(n, std::deque<std::deque<int>>(n, std::deque<int>(n)));
		for (auto &ploha : v)
	    	for (auto &red : ploha)
	    		for (int &x : red) std::cin >> x;
		std::cout << "Unesite smjer kretanja [0 - 5]: ";
		while (std::cin >> smjer, (smjer < 0 || smjer > 5))
	    	std::cout << "Smjer nije ispravan, unesite opet: ";
		v = PjescaniSat(v, SmjerKretanja(smjer));
		std::cout << "\nPjescani sat unesene matrice je:";
		for (const auto &a : v)
		{
			std::cout << std::endl;
			for (int i(0); i < a.size(); i++)
			{
				std::cout << std::endl << std::setw(4 * (i <= n/2 ? i+1 : n-i));
	       		for (int j(0); j < a.at(i).size(); j++)
	       			std::cout << a.at(i).at(j) << std::setw(4);
	       	}
		}
	}
	catch (const std::exception &e) { std::cout << "\nIzuzetak: " << e.what(); }
	catch (...) {}
	return 0;
}