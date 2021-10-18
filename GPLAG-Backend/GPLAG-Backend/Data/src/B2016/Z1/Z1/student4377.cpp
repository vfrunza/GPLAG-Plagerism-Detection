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

std::vector<int> PretvoriUTernarni(long long int v)
{
	if(v<0) v*=-1;
	std::vector<int> broj;
	if(v == 0) broj.push_back(0);
	else
	while(v!=0)
	{
		broj.push_back(v%3);
		v/=3;
	}
	
	//std::vector<int> obrnuti;
	//for(int i=broj.size()-1; i>=0; i--) obrnuti.push_back(broj[i]);
	
	return broj;
}

std::vector<int> Filtriraj(std::vector<int> v)
{
	for(int i=0; i<v.size(); i++)
	for(int j=i; j<v.size(); j++)
	{
		if(i == j) continue;
		else
		{
			if(v[i]==v[j])
			{
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool p)
{
	std::vector<int> gadni;
	if(p == true)
	{
		for(int i:v)
		{
			std::vector<int> broj(PretvoriUTernarni(i)), brojac(3);
			//std::cout << "0 u teranronm: " << broj[0] << std::endl;
			for(int j:broj) 
			{
				brojac[fabs(j)]++;
			}
			
			bool logika (true); // pretpostavka da su parni
			for(int k:brojac)
			{
				if(k != 0)
				if(k%2 != 0)
				{
					logika = false;
					break;
				}
			}
			if(logika) gadni.push_back(i); //opaki
		}
	}
	else
	{
		for(int i:v)
		{
			std::vector<int> broj(PretvoriUTernarni(i)), brojac(3);
			for(int j:broj) 
			{
				brojac[fabs(j)]++;
			}
			
			bool logika (true); // pretpostavka da su neparni
			for(int k:brojac)
			{
				if(k != 0)
				if(k%2 == 0)
				{
					logika = false;
					break;
				}
			}
			if(logika) gadni.push_back(i); // odvartni
		}	
	}
	return Filtriraj(gadni);
}

int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	std::vector<int> t;
	int br;
	while(std::cin >> br, br != 0)
	{
		v.push_back(br);
	}
	
	t = IzdvojiGadne(v, true);
	std::cout << "Opaki: ";
	for(int i:t) std::cout<< i << " ";
	std::cout << std::endl;
	
	t = IzdvojiGadne(v, false);
	std::cout << "Odvratni: ";
	for(int i:t) std::cout<< i << " ";
	std::cout << std::endl;

	return 0;
}