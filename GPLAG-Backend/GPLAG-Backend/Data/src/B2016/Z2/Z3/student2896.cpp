/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

int SumaDjelilaca(long long int x)
{
	long long int i;
	int suma = 0;
	for(i=1; i<=x; i++)
	{
		if(x%i == 0) suma+=i;
	}
	return suma;
}
int BrojProstihFaktora(long long int x)
{
	long long int i;
	long long int j;
	int br = 0;
	for(i=1; i<=x; i++)
	{
		bool prost = true;
		for(j=2; j<i; j++)
		{
			if(i%j == 0) prost = false;
		}
		if(i==1) prost = false;
		if(prost && x%i == 0) br++;
	}
	return br;
}
int BrojSavrsenihDjelilaca(long long int x)
{
	long long int i;
	long long int j;
	int br = 0;
	for(i=1;i<=x;i++)
	{
		long long int a = i;
		long long int suma = 0;
		for(j=1;j<a;j++)
		{
			if(a%j==0)
			{
				suma += j;
			}
		}
		if(suma == i)
		{
			br++;
		}
	}
	return br;
}

template<typename tip1, typename tip2, typename tip3>
auto UvrnutiPresjek(tip1 p1, tip1 p2, tip2 p3, tip2 p4, auto funkcija(tip3) -> decltype(*p1)) -> std::vector<std::vector<decltype(*p1)>>
{
	typedef decltype(*p1) tip4;
	std::vector<std::vector<tip4>> vektor(0);
	tip1 p = p1;
	tip2 pp = p3;
	while(p != p2)
	{
		while(pp != p4)
		{
			if(funkcija(*p) == funkcija(*pp))
			{
				std::vector<tip4> pom(3);
				pom.at(0) = *p;
				pom.at(1) = *pp;
				pom.at(2) = funkcija(*p);
				vektor.push_back(pom);
			}
			pp++;
		}
		pp = p3;
		p++;
	}
	std::sort(vektor.begin(), vektor.end(), 
	[](std::vector<tip4> a, std::vector<tip4> b)
		{
			if(a.at(2) < b.at(2)) return true;
			if(a.at(0) < b.at(0)) return true;
			if(a.at(1) < b.at(1)) return true;
			return false;
		}
	);
	return vektor;
}
/*
template <typename tip1, typename tip2>
auto UvrnutiPresjek(tip1 p1, tip1 p2, tip2 p3, tip2 p4) -> std::vector<std::vector<decltype(*p1)>>
{
	std::vector<std::vector<decltype(*p1)>> vektor(0);
	tip1 p = p1;
	tip2 pp = p3;
	while(p != p2)
	{
		while(pp != p4)
		{
			if(*p == *pp)
			{
				std::vector<double> pom(3);
				pom.at(0) = *p;
				pom.at(1) = 0;
				pom.at(2) = 0;
				vektor.push_back(pom);
			}
			pp++;
		}
		p++;
		pp = p3;
	}
	std::sort(vektor.begin(), vektor.end(),
	[](std::vector<double> a, std::vector<double> b)
	{
		if(a.at(0) < b.at(0)) return true;
		return false;
	}
	);
	return vektor;
}*/

int kvad(int x)
{
	return x*x;
}
int main ()
{
	int n1, n2;
	std::deque<int> dek1(0); //
	std::deque<int> dek2(0);
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> n1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	for(int i=0; i<n1; i++)
	{
		int n;
		std::cin >> n;
		int ima = 0;
		for(int j=0; j<dek1.size(); j++)
		{
			if(n == dek1.at(j)) ima = 1;
		}
		if(ima == 1)
		{
			i--;
		}
		else
		{
			dek1.push_back(n);
		}
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i=0; i<n2; i++)
	{
		int n;
		std::cin >> n;
		int ima = 0;
		for(int j=0; j<dek2.size(); j++)
		{
			if(n==dek2.at(j)) ima = 1;
		}
		if(ima == 1)  i--;
		else dek2.push_back(n);
	}
	std::vector<std::vector<int>> v = UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(),  dek2.end() , BrojProstihFaktora);
	for(int i=0; i<v.size();i++)
	{
		for(int j=0; j<v.at(i).size(); j++)
		{
			std::cout << v.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}