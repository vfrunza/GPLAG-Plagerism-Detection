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


bool DaLiSiOpak (int n)
{
	if(n < 0)  n *= -1;
	int brojac_nula(0), brojac_jedinica(0), brojac_dvica(0);
	while(n != 0)
	{
		if(n % 3 == 0)
			brojac_nula++;
		else if(n % 3 == 1)
			brojac_jedinica++;
		else if(n % 3 == 2)
			brojac_dvica++;
		n = n/3;
	}
	if((brojac_nula % 2 == 0 || brojac_nula == 0) && (brojac_jedinica % 2 == 0 || brojac_jedinica == 0) && (brojac_dvica % 2 == 0 || brojac_dvica == 0))
		return true;
	else
		return false;
}
bool DaLiSiOdvratan (int n)
{
	if(n < 0 )  n *= -1;
	int brojac_nula(0), brojac_jedinica(0), brojac_dvica(0);
	while(n != 0)
	{
		if(n % 3 == 0)
			brojac_nula++;
		else if(n % 3 == 1)
			brojac_jedinica++;
		else if(n % 3 == 2)
			brojac_dvica++;
		n = n/3;
	}
	if((brojac_nula % 2 == 1 || brojac_nula == 0) && (brojac_jedinica % 2 == 1 || brojac_jedinica == 0) && (brojac_dvica % 2 == 1 || brojac_dvica == 0))
		return true;
	else
		return false;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool log_vrijednost)
{
	std::vector<int> gadni;
	for(int i=0; i<v.size(); i++)
	{
		if(DaLiSiOpak(v[i]) && log_vrijednost)
			gadni.push_back(v[i]);
		if(DaLiSiOdvratan(v[i]) && !(log_vrijednost)) 
			gadni.push_back(v[i]);
	}
	for(int i=0; i<gadni.size(); i++)
	{
		for(int j=i+1; j<gadni.size(); j++)
		{
			if(gadni[j] == gadni[i])
			{
				for(int k=j; k<gadni.size()-1; k++)
				{
					gadni[k] = gadni[k+1];
				}
				gadni.resize(gadni.size()-1);
				j--;
				
			}
		}
	}
	return gadni;
}

int main ()
{
	int n;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	std::cin >> n;
	while(n != 0)
	{
		if(n != 0) v.push_back(n);
		if(n == 0) break;
		std::cin >> n;
	}
	std::vector<int> opaki = IzdvojiGadne(v, true);
	std::cout << "Opaki: ";
	for(int i=0; i<opaki.size(); i++)
	{
		std::cout << opaki[i] << " ";
	}
	std::cout << std::endl << "Odvratni: ";
	std::vector<int> odvratni = IzdvojiGadne(v, false);
	for(int i=0; i<odvratni.size(); i++)
	{
		std::cout << odvratni[i] << " ";
	}
	
	return 0;
}