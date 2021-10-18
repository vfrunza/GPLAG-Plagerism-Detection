/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> Ternarni (int n)
{
	std::vector<int>v;
	while(n != 0)
	{
		int ostatak = n % 3;
		if (ostatak < 0)
			ostatak *= (-1);
		v.push_back(ostatak);
		n /= 3;
	}
	return v;
}

std::vector<int> Obrisi (std::vector<int>v)
{
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = 0; j < v.size(); j++)
		{
			if(v[i] == v[j] && i != j)
			{
				v.erase(v.begin() + j);
				j--;
			}	
		}
	}
	return v;
}

std::vector<int> IzdvojiGadne (std::vector<int>v, bool temp)
{
	std::vector<int>v1;
	for(int i = 0; i < v.size(); i++)
	{
		int pomocna = v[i];
		//if(pomocna < 0)
		//	pomocna *= (-1);
		if (pomocna == 0 && temp == true)
			continue;
		//int suma = 0;
		auto pomocni = Ternarni(pomocna);
		/*while(pomocna != 0)
		{
			int ostatak = pomocna % 3;
			pomocni.push_back(ostatak);
			pomocna /= 3;
			//std::cout<<suma;
		}*/
		int brojac0 = 0, brojac1 = 0, brojac2 = 0;
		for(int j = 0; j < pomocni.size(); j++)
		{
			if(pomocni[j] == 0)
				brojac0++;
			else if (pomocni[j] == 1)
				brojac1++;
			else if (pomocni[j] == 2)
				brojac2++;
				//std::cout<<pomocni[j]<<" ";
		}

		if(temp == 1 && brojac0 % 2 == 0 && brojac1 % 2 == 0 && brojac2 % 2 == 0)
			v1.push_back(v[i]);
		else if(temp == 0 && (brojac0 % 2 != 0 || brojac0 == 0) && (brojac1 % 2 != 0 || brojac1 == 0) && (brojac2 % 2 != 0 || brojac2 == 0))
			v1.push_back(v[i]);
	}
	/*for(int i = 0; i < v1.size(); i++)
	{
		for(int j = 0; j < v1.size(); j++)
		{
			if(v1[i] == v1[j] && i != j)
			{
				v1.erase(v1.begin() + j);
				j--;
			}
		}
	}*/
	auto v2 = Obrisi(v1);
	return v2;
}


int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int>v;
	int n;
	while(std::cin>>n, n!=0)
	{
		v.push_back(n);
	}
	auto v1 = IzdvojiGadne(v, 1);
	std::cout<<"Opaki: ";
	for(int x : v1)
	{
		std::cout<<x<<" ";
	}
	std::cout<<std::endl;
	auto v2 = IzdvojiGadne(v, 0);
	std::cout<<"Odvratni: ";
	for(int x : v2)
		std::cout<<x<<" ";
	/*for(const auto &a : IzdvojiGadne({0}, true))
	std::cout<<a<<" ";*/
	

	return 0;
}