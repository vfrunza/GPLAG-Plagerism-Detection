/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>

int TerarniBr(int n)
{
	bool negtivan(false);
	if(n < 0)
	{
		negtivan = true;
		n *= -1;
	}
	int br(0), i(0);
	while(n != 0)
	{
		int x = n%3;
		br += (x * pow(10, i));
		i++;
		n /= 3;
	}
	if(negtivan)
	  br *= -1;
	return br;
}

bool Gadan(int n)

std::vector<int> IzdvojiGadne(std::vector<int> v, bool Gadnost)
{
	for(int i(0); i < v.size(); i++)
	  v[i] = TerarniBr(v[i]);
	
	std::vector<int> t;
	for(int i(0); i < v.size(); i++)
	{
		if(Gadnost)
		{
			if(Gadan(v[i]))
			  t.push_back(v[i]);
		}
		else
		{
			if(!Gadan)
			  t.push_back(v[i]);
		}
	}
	return t;
}

int main ()
{
	int n;
	std::cout << "Unesite broj n: ";
	std::cin >> n;
	std::cout << TerarniBr(n);
	
	return 0;
}