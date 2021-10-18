/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <deque>

enum Smjer { Rastuci = 1, Opadajuci };

// PROTOTIPI funkcija
// Pomocne funkcije
bool isPowerOfTwo(int);

// Funkcija zadata za implementaciju
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int>, Smjer);

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	std::vector<int> v;
	std::cout << "Unesite elemente vektora: ";
	for (int i{0}; i < n; i++)
	{
		int tmp;
		std::cin >> tmp;
		
		v.push_back(tmp);
	}
	
	int directReq;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> directReq;
	
	auto res = std::move(MaksimalniPodnizoviStepenaDvojke(v, static_cast<Smjer>(directReq)));
	
	std::cout << "Maksimalni "
		<< (directReq == 1 ? "rastuci" : "opadajuci")
		<< " podnizovi: " << std::endl;
	for (auto subseq : res)
	{
		for (auto num : subseq)
			std::cout << num << " ";
			
		std::cout << std::endl;
	}
	
	return 0;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> vect, Smjer direct)
{
	std::deque<std::vector<int>> res;
	
	// Ukolikoliko parametri nisu validni, vrati prazan vektor
	if (vect.size() == 0 ||
		(direct != Opadajuci && direct != Rastuci))
			return res;
	
	// Pomaze oko lakseg poredjenja smjera
	bool directReq = static_cast<bool>(direct % 2);
	
	for (int i{0}; i < vect.size() - 1; i++)
	{
		if (!isPowerOfTwo(vect.at(i)))
			continue;
		
		std::vector<int> tmp(1, vect.at(i));
		
		for (int j{i + 1}; j < vect.size(); j++)
		{
			if (((vect.at(j) > vect.at(i)) == directReq || vect.at(j) == vect.at(i)) &&
				isPowerOfTwo(vect.at(j)))
					tmp.push_back(vect.at(j));
			else
				break;
				
			i++;
		}
		
		// Ako je ovaj broj izoliran stepen dvojke, ne upada u nasu definiciju
		// podniza
		if (tmp.size() <= 1)
			continue;
		
		res.push_back(tmp);
	}
	
	return res;
}

// Funkcija vraca true ukoliko je parametar stepen dvojke,
// a false u suprotnom
bool isPowerOfTwo(int num)
{
	if (num == 1)
		return true;
		
	if (num % 2 != 0 || num == 0)
		return false;
		
	return isPowerOfTwo(num / 2);
}