#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <type_traits>

enum class SmjerKretanja
{
	NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename Kont>
Kont PjescaniSat(Kont kont, SmjerKretanja smjer)
{
	for (int i(0); i < kont.size(); i++)
	    if (kont.at(i).size() != kont.size()) throw std::domain_error("3D matrica nema oblik kocke");
	    else 
	        for (int j(0); j < kont.at(i).size(); j++)
	        	if (kont.at(i).at(j).size() != kont.size()) 
	        		throw std::domain_error("3D matrica nema oblik kocke");
	int n(kont.size());
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

/*
int main()
{
	int n, x, smjer;
	std::cout << "Unesite dimenziju (x/y/z): ";
	while (std::cin >> n, n < 0)
	    std::cout << "Dimenzija nije ispravna, unesite opet: ";
	std::cout << "Unesite elemente kontejnera: ";
	std::vector<std::deque<std::deque<int>>> v;
	for (int i(0); i < n; i++)
	{
		std::deque<std::deque<int>> a;
	    for (int j(0); j < n; j++)
	    {
	    	std::deque<int> b;
	        for (int k(0); k < n; k++)
	        	b.push_back((std::cin >> x, x));
	        a.push_back(b);
	    }
	    v.push_back(a);
	}
	std::cout << "Unesite smjer kretanja [0 - 5]: ";
	while (std::cin >> smjer, (smjer < 0 || smjer > 5))
	    std::cout << "Smjer nije ispravan, unesite opet: ";
	std::cout << std::endl;
	try
	{
		std::vector<std::deque<std::deque<int>>> ps(PjescaniSat(v, static_cast<SmjerKretanja>(smjer)));
		std::cout << "Pjescani sat unesene matrice je:";
		for (const std::deque<std::deque<int>> &a : ps)
		{
			std::cout << std::endl;
			for (int i(0); i < a.size(); i++)
			{
				std::cout << std::endl;
				std::cout.width(4 * (i <= n/2 ? i+1 : n-i));
	        	for (int j(0); j < a.at(i).size(); j++)
	        	{
	        		std::cout << a.at(i).at(j);
	        		std::cout.width(4);
	        	}
			}
		}
	}
	catch (std::domain_error e)
	{
		std::cout << "Izuzetak: " << e.what();
	}
	catch (std::length_error e)
	{
		std::cout << "Izuzetak: " << e.what();
	}
	catch (...) {}
	return 0;
}*/