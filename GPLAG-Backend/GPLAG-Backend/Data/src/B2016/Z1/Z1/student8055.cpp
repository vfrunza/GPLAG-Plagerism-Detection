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

std::vector<int> Ternarni(int n) {
	std::vector<int> vektor(3);
	while(n > 0)
	{
		vektor[n % 3]++;
		n /= 3;
	}
	return vektor;
}

bool JeOpaki(int i) {
	std::vector<int> niz{Ternarni(std::abs(i))};
	if((niz[0]%2==0) && (niz[1]%2==0) && (niz[2]%2==0) && i)
		return true;
	return false;
}

bool JeOdvratni(int i) {
	std::vector<int> niz{Ternarni(std::abs(i))};
	if((niz[0]%2!=0 || niz[0] == 0) && (niz[1]%2!=0 || niz[1] == 0) && (niz[2]%2!=0 || niz[2] == 0))
		return true;
	return false;
}


std::vector<int>IzdvojiGadne(std::vector<int> v, bool opaki) {
	std::vector<int> pom;
		for(int element:v) {
		if(opaki)
		{
			if (JeOpaki(element))
				pom.push_back(element);
		}
		else if(!opaki)
		{
			if(JeOdvratni(element))
				pom.push_back(element);
		}
		}
		for(int i{}; i < pom.size(); i++)
			for(int j{i+ 1}; j < pom.size(); j++)
				if(pom[i] == pom[j])
				{
					pom.erase(pom.begin() + j);
					j--;
				}
		return pom;
}


int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	int x = 0;
	for(;;) {
		std::cin>> x;
		if(x==0) break;
		v.push_back(x);
	}
	std::vector<int> opaki{IzdvojiGadne(v, true)};
	std::vector<int> odvratni{IzdvojiGadne(v, false)};
	std::cout << "Opaki: ";
	for(int element : opaki)
		std::cout << element << " ";
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	for(int element : odvratni)
		std::cout << element << " ";
	return 0;
}/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
