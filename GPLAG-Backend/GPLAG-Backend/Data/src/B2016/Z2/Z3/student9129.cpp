#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <string>
#include <iomanip>

int SumaDjelilaca (long long int broj)
{
	long long int suma{0};
	for (long long int i{1}; i < std::abs(broj) / 2 + 1; i++)
		if (!(std::abs(broj) % i))
			suma += i;
	return suma + std::abs(broj);
}

int SumaCifara (long long int x) { return (!x) ? 0 : std::abs(x % 10) + SumaCifara(x / 10); }
bool DaLiJeSavrsen (long long int broj) { return (2 * broj == SumaDjelilaca(broj)) ? true : false; }

template <typename tip1> tip1 VratiNulu (tip1 varijabla) { return 0; }
std::string VratiNulu (std::string varijabla) { return std::to_string(0); }

bool DaLiJeProst (long long int broj)
{
	if (broj < 2)
		return false;
	for (long long int i{2}; i < std::sqrt(broj + 1); i++)
		if (!(broj % i))
			return false;
	return true;
}

int BrojSavrsenihDjelilaca (long long int broj)
{
	int brojac{0};
	for (long long int i{1}; i < broj + 1; i++)
		if (!(broj % i) && DaLiJeSavrsen(i))
			brojac++;
	return brojac;
}

int BrojProstihFaktora (long long int broj)
{
	int brojac{0};
	for (long long int i{2}; i < broj + 1; i++)
		if (!(broj % i) && DaLiJeProst(i))
			brojac++, broj /= i, i--;
	return brojac;
}

template <typename tip1, typename tip2, typename tip3, typename tip4>
std::vector<std::vector<tip3>> UvrnutaRazlika (tip1 p1, tip1 q1, tip2 p2, tip2 q2, tip3 funkcijaKriterija(tip4))
{
	std::vector<std::vector<tip3>> rezultujuciVektor(0, std::vector<tip3>(2));
	tip1 temp1{p1}, temp2{p2}; 
	while (p1 != q1)
	{
		bool PostojiLiPar{false};
		while (p2 != q2)
		{
			if (funkcijaKriterija(*p1) == funkcijaKriterija(*p2))
				PostojiLiPar = true;
			p2++;
		}
		if (!PostojiLiPar) 
			rezultujuciVektor.push_back({*p1, funkcijaKriterija(*p1)});
		p2 = temp2, p1++;
	}
	p2 = temp2, p1 = temp1;
	while (p2 != q2)
	{
		bool PostojiLiPar{false};
		while (p1 != q1)
		{
			if (funkcijaKriterija(*p2) == funkcijaKriterija(*p1))
				PostojiLiPar = true;
			p1++;
		}	
		if (!PostojiLiPar) 
			rezultujuciVektor.push_back({*p2, funkcijaKriterija(*p2)});
		p1 = temp1, p2++;
	}
	
	std::sort(rezultujuciVektor.begin(), rezultujuciVektor.end(),
            		[](const std::vector<tip3>& v1, const std::vector<tip3>& v2) {
            			return (v1.at(0) == v2.at(0)) ?  v1.at(1) > v2.at(1) : v1.at(0) > v2.at(0);
              		});
              		
	return rezultujuciVektor;
}

template <typename tip1, typename tip2, typename tip3, typename tip4>
std::vector<std::vector<tip3>> UvrnutiPresjek (tip1 p1, tip1 q1, tip2 p2, tip2 q2, tip3 funkcijaKriterija(tip4))
{
	std::vector<std::vector<tip3>> rezultujuciVektor(0, std::vector<tip3>(3));
	tip1 temp2{p2}; 
	while (p1 != q1)
	{
		p2 = temp2;
		while (p2 != q2)
		{
			if (funkcijaKriterija(*p1) == funkcijaKriterija(*p2))
			{
				bool postoji{false};
				for (auto red : rezultujuciVektor)
					if (red.at(0) == *p1 && red.at(1) == *p2)
						postoji = true;
				if (!postoji)
					rezultujuciVektor.push_back({*p1, *p2, funkcijaKriterija(*p1)});
			}
			p2++;
		}
		p1++;
	}
	
	std::sort(rezultujuciVektor.begin(), rezultujuciVektor.end(),
            			[](const std::vector<tip3>& v1, const std::vector<tip3>& v2) {
            				if (v1.at(2) == v2.at(2))
            					if (v1.at(0) == v2.at(0))
            						return v1.at(1) < v2.at(1);
            					else 
            						return v1.at(0) <= v2.at(0);
            				else 
            					return v1.at(2) < v2.at(2);});
              			
   return rezultujuciVektor;
}


template <typename tip1, typename tip2>
auto UvrnutiPresjek (tip1 p1, tip1 q1, tip2 p2, tip2 q2) -> std::vector<std::vector<decltype(*p1+*p1)>>
{
	typedef decltype(*p1+*p1) tip3;
	std::vector<std::vector<tip3>> rezultujuciVektor(0, std::vector<tip3>(3));
	tip1 temp2{p2}; 
	while (p1 != q1)
	{
		p2 = temp2;
		while (p2 != q2)
		{
			if (*p1 == *p2)
			{
				bool postoji{false};
				for (auto red : rezultujuciVektor)
					if (red.at(0) == *p1 && red.at(1) == *p2)
						postoji = true;
				if (!postoji)
					rezultujuciVektor.push_back({*p1, *p2, VratiNulu(*p1)});
			}
			p2++;
		}
		p1++;
	}
	
	std::sort(rezultujuciVektor.begin(), rezultujuciVektor.end(),
            			[](const std::vector<tip3>& v1, const std::vector<tip3>& v2) {
            						return v1.at(0) < v2.at(0);});
              			
   return rezultujuciVektor;
}


template <typename tip1, typename tip2>
auto UvrnutaRazlika (tip1 p1, tip1 q1, tip2 p2, tip2 q2) -> std::vector<std::vector<decltype(*p1+*p1)>>
{
	typedef decltype(*p1+*p1) tip3;
	std::vector<std::vector<tip3>> rezultujuciVektor(0, std::vector<tip3>(2));
	tip1 temp1{p1}, temp2{p2}; 
	while (p1 != q1)
	{
		bool PostojiLiPar{false};
		while (p2 != q2)
		{
			if (*p1 == *p2)
				PostojiLiPar = true;
			p2++;
		}
		if (!PostojiLiPar) 
			rezultujuciVektor.push_back({*p1, VratiNulu(*p1)});
		p2 = temp2, p1++;
	}
	p2 = temp2, p1 = temp1;
	while (p2 != q2)
	{
		bool PostojiLiPar{false};
		while (p1 != q1)
		{
			if (*p2 == *p1)
				PostojiLiPar = true;
			p1++;
		}	
		if (!PostojiLiPar) 
			rezultujuciVektor.push_back({*p2, VratiNulu(*p2)});
		p1 = temp1, p2++;
	}
	
	std::sort(rezultujuciVektor.begin(), rezultujuciVektor.end(),
            		[](const std::vector<tip3>& v1, const std::vector<tip3>& v2) {
            			return (v1.at(0) == v2.at(0)) ?  v1.at(1) > v2.at(1) : v1.at(0) > v2.at(0);
              		});
              		
	return rezultujuciVektor;
}

int main ()
{

	int brojElemenata{0}, element;
	
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> brojElemenata;
	
	std::deque<int> d1, d2;
	
	std::cout << "Unesite elemente prvog kontejnera: ";
	while (brojElemenata != d1.size())
	{
		std::cin >> element;
		if (std::find(d1.begin(), d1.end(), element) == d1.end())
			d1.push_back(element);
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> brojElemenata;
	
	std::cout << "Unesite elemente drugog kontejnera: ";
	
	while (brojElemenata != d2.size())
	{
		std::cin >> element;
		if (std::find(d2.begin(), d2.end(), element) == d2.end())
			d2.push_back(element);
	}
	
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	for (const auto& red : UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara))
	{
		for (const auto & broj : red)
			std::cout << std::setw(6) << broj << " ";
		std::cout << std::endl;
	}
	
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	for (const auto& red : UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora))
	{
		for (const auto & broj : red)
			std::cout << std::setw(6) << broj << " ";
		std::cout << std::endl;
	}
	
	std::cout << "Dovidjenja!";	



/*
//AT7 - prazni dekovi
{
	std::deque<int> d1{}, d2{};
    std::vector<std::vector<int>> v1{UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora)};
	std::vector<std::vector<int>> v2{UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora)};
	
	for (std::vector<int>& red : v1)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (std::vector<int>& red : v2)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}
}




//AT7 - prazni dekovi
{
	std::deque<int> d1{}, d2{};
    std::vector<std::vector<int>> v1{UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora)};
	std::vector<std::vector<int>> v2{UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora)};
	
	for (std::vector<int>& red : v1)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (std::vector<int>& red : v2)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}
}




//AT7 - prazni dekovi
{
	std::deque<int> d1{}, d2{};
    std::vector<std::vector<int>> v1{UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora)};
	std::vector<std::vector<int>> v2{UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora)};
	
	for (std::vector<int>& red : v1)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (std::vector<int>& red : v2)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}
}



*/



	return 0;
}