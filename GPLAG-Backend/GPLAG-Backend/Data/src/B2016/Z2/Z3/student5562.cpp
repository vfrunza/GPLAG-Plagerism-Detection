/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>

template <typename Tip1, typename Tip2>

auto UvrnutiPresjek(Tip1 a1, Tip1 a2, Tip2 b1, Tip2 b2, typename std::remove_reference<decltype(*a1)>::type f(typename std::remove_reference<decltype(*a1)>::type)) -> std::vector<std::vector<typename std::remove_reference<decltype(*a1)>::type>>
{
	typedef typename std::remove_reference<decltype(*a1)>::type TipPrvog;
	typedef std::vector<std::vector<TipPrvog>> Matrica;
	Matrica matrica;
	
	Tip1 p1(a1);
	Tip2 p2(b1);
	int br_redova(0);
	
	while (p1 != a2)
	{
		while (p2 != b2)
		{
			if (f(*p1) == f(*p2))
			{
				matrica.push_back(std::vector<TipPrvog>(0));
				matrica[br_redova].push_back(*p1);
				matrica[br_redova].push_back(*p2);
				matrica[br_redova].push_back(f(*p1));
				br_redova++;
			}
			p2++;
		}
		p2 = b1;
		p1++;
	}
	std::sort(matrica.begin(), matrica.end(), 
	[](std::vector<TipPrvog> v1, std::vector<TipPrvog> v2)
	{
		if (v1[2] != v2[2])
			return v1[2] < v2[2];
		else if (v1[0] != v2[0])
			return v1[0] < v2[0];
		else
			return v1[1] < v2[1];
		
	});
	
	return matrica;
}

template <typename Tip1, typename Tip2>

auto UvrnutaRazlika(Tip1 a1, Tip1 a2, Tip2 b1, Tip2 b2, typename std::remove_reference<decltype(*a1)>::type f(typename std::remove_reference<decltype(*a1)>::type)) -> std::vector<std::vector<typename std::remove_reference<decltype(*a1)>::type>>
{
	typedef typename std::remove_reference<decltype(*a1)>::type TipPrvog;
	typedef std::vector<std::vector<TipPrvog>> Matrica;
	Matrica matrica;
	
	Tip1 p1(a1);
	Tip2 p2(b1);
	int br_redova(0);
	
	while (p1 != a2)
	{
		bool jednistven(true);
		while(p2 != b2)
		{
			if (f(*p1) == f(*p2))
			{
				jednistven = false;
				break;
			}
			p2++;
		}
		if (jednistven)
		{
			matrica.push_back(std::vector<TipPrvog>(0));
			matrica[br_redova].push_back(*p1);
			matrica[br_redova].push_back(f(*p1));
			br_redova++;
		}
		p2 = b1;
		p1++;
	}
	p1 = a1;
	while (p2 != b2)
	{
		bool jednistven(true);
		while(p1 != a2)
		{
			if (f(*p2) == f(*p1))
			{
				jednistven = false;
				break;
			}
			p1++;
		}
		if (jednistven)
		{
			matrica.push_back(std::vector<TipPrvog>(0));
			matrica[br_redova].push_back(*p2);
			matrica[br_redova].push_back(f(*p2));
			br_redova++;
		}
		p1 = a1;
		p2++;
	}
	std::sort(matrica.begin(), matrica.end(), 
	[](std::vector<TipPrvog> v1, std::vector<TipPrvog> v2)
	{
		if (v1[0] != v2[0])
			return v1[0] > v2[0];
		else
			return v1[1] > v2[1]; 
	});
	return matrica;
}

//Preklopljene
template <typename Tip1, typename Tip2>

auto UvrnutiPresjek(Tip1 a1, Tip1 a2, Tip2 b1, Tip2 b2) -> std::vector<std::vector<typename std::remove_reference<decltype(*a1)>::type>>
{
	typedef typename std::remove_reference<decltype(*a1)>::type TipPrvog;
	typedef std::vector<std::vector<TipPrvog>> Matrica;
	Matrica matrica;
	
	Tip1 p1(a1);
	Tip2 p2(b1);
	int br_redova(0);
	
	while (p1 != a2)
	{
		while (p2 != b2)
		{
			if (*p1 == *p2)
			{
				matrica.push_back(std::vector<TipPrvog>(0));
				matrica[br_redova].push_back(*p1);
				matrica[br_redova].push_back(0);
				matrica[br_redova].push_back(0);
				br_redova++;
			}
			p2++;
		}
		p2 = b1;
		p1++;
	}
	std::sort(matrica.begin(), matrica.end(), 
	[](std::vector<TipPrvog> v1, std::vector<TipPrvog> v2)
	{
			return v1[0] < v2[0];
	});

return matrica;	
}

template <typename Tip1, typename Tip2>

auto UvrnutaRazlika(Tip1 a1, Tip1 a2, Tip2 b1, Tip2 b2) -> std::vector<std::vector<typename std::remove_reference<decltype(*a1)>::type>>
{
	typedef typename std::remove_reference<decltype(*a1)>::type TipPrvog;
	typedef std::vector<std::vector<TipPrvog>> Matrica;
	Matrica matrica;
	
	Tip1 p1(a1);
	Tip2 p2(b1);
	int br_redova(0);
	
	while (p1 != a2)
	{
		bool jednistven(true);
		while(p2 != b2)
		{
			if (*p1 == *p2)
			{
				jednistven = false;
				break;
			}
			p2++;
		}
		if (jednistven)
		{
			matrica.push_back(std::vector<TipPrvog>(0));
			matrica[br_redova].push_back(*p1);
			matrica[br_redova].push_back(0);
			br_redova++;
		}
		p2 = b1;
		p1++;
	}
	p1 = a1;
	while (p2 != b2)
	{
		bool jednistven(true);
		while(p1 != a2)
		{
			if (*p2 == *p1)
			{
				jednistven = false;
				break;
			}
			p1++;
		}
		if (jednistven)
		{
			matrica.push_back(std::vector<TipPrvog>(0));
			matrica[br_redova].push_back(*p2);
			matrica[br_redova].push_back(0);
			br_redova++;
		}
		p1 = a1;
		p2++;
	}
	std::sort(matrica.begin(), matrica.end(), 
	[](std::vector<TipPrvog> v1, std::vector<TipPrvog> v2)
	{
		if (v1[0] != v2[0])
			return v1[0] > v2[0];
		else
			return v1[1] > v2[1]; 
	});
	return matrica;
}

int SumaDjelilaca(int br)
{
	int suma(0);
	for (int i = 1; i <= std::abs(br); i++)
	{
		if (br%i == 0)
			suma += i;
	}
	return suma;
}

int BrojProstihFaktora(int br)
{
	int broj(0);
	for (int i = 2; i <= std::abs(br); i++)
	{
		if (br%i == 0)
		{
			bool prost(true);
			for (int j = 2; j < i; j++)
			{
				if (i%j == 0)
				{
					prost = false;
					break;
				}
			}
			if (prost)
			{
				broj++;
				br = br/i;
				i--;
			}
		}
	}
	return broj;
}

int BrojSavrsenihDjelilaca(int br)
{
	int broj(0);
	for (int i = 1; i <= std::abs(br); i++)
	{
		if (br%i == 0)
		{
			int suma(0);
			for (int j = 1; j < i; j++)
			{
				if (i%j == 0) suma += j;
			}
			if (suma == i) broj++;
		}
	}
	return broj;
}

int SumaCifara(int br)
{
	int suma(0);
	while (br != 0)
	{
		int cif(std::abs(br%10));
		suma += cif;
		br = br/10;
	}
	return suma;
}

template <typename Kont>
bool DaLiSePonavlja(int br, Kont dek)
{
	for (int i = 0; i < dek.size(); i++)
		if (dek.at(i) == br)
			return true;
	return false;
}

int main ()
{
	int n1;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> n1;
	std::deque<int> prvi;
	std::cout << "Unesite elemente prvog kontejnera: ";
	int i(0);
	while (i < n1)
	{
		int x;
		std::cin >> x;
		if (!DaLiSePonavlja(x, prvi))
		{
			prvi.push_back(x);
			i++;
		}
	}
	
	int n2;
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n2;
	std::deque<int> drugi;
	std::cout << "Unesite elemente drugog kontejnera: ";
	i = 0;
	while (i < n2)
	{
		int x;
		std::cin >> x;
		if (!DaLiSePonavlja(x, drugi))
		{
			drugi.push_back(x);
			i++;
		}
	}
		
	std::cout << "Uvrnuti presjek kontejnera:\n";
	std::vector<std::vector<int>> presjek(UvrnutiPresjek(prvi.begin(), prvi.end(), drugi.begin(), drugi.end(), SumaCifara));
	
	for (int i = 0; i < presjek.size(); i++)
	{
		for (int j = 0; j < presjek[i].size(); j++)
			std::cout << std::setw(6) << presjek[i][j] << " ";
		std::cout << "\n";
	}
	
	std::cout << "Uvrnuta razlika kontejnera:\n";
	std::vector<std::vector<int>> razlika(UvrnutaRazlika(prvi.begin(), prvi.end(), drugi.begin(), drugi.end(), BrojProstihFaktora));
	
	for (int i = 0; i < razlika.size(); i++)
	{
		for (int j = 0; j < razlika[i].size(); j++)
			std::cout << std::setw(6) << razlika[i][j] << " ";
		std::cout << "\n";
	}
	std::cout << "Dovidjenja!";

	return 0;
}