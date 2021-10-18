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

std::vector<int> IzbaciDuple(std::vector<int> v) {
	std::vector<int> pomocni;
	for (int x:v) {
		bool nema_ga=true;
		for (int y:pomocni) 
			if (x == y) nema_ga=false;
		if (nema_ga) pomocni.push_back(x);
	}
	return pomocni;
}

std::vector<int> IzdvojiGadne(std::vector<int> a, bool y) {
	std::vector<int> v1, v2, v3;
	//v3 je vektor u koji cemo smjestiti trenutni broj u ternarnom zapisu
	for (int k=0; k<a.size(); k++) {
		int x=a[k], c{};
		
		do {
			c = x % 3;
			v3.push_back(abs(c));
			x /= 3;
		}
		while (x != 0);
	
	
		int histogram[3]={0};
		
		for (int i=0; i<v3.size(); i++) histogram[v3[i]]++;
		
		v3.resize(0);
	
		if (y == true && histogram[0] % 2 == 0 && histogram[1] % 2 == 0 && histogram[2] % 2 == 0) v1.push_back(a[k]);
		
		std::vector<int> pom;
		for (int m=0; m<3; m++)
			if (histogram[m] != 0) pom.push_back(histogram[m]);
			
		bool svi_neparni=true;
		for (int j=0; j<pom.size(); j++)
			if (pom[j] % 2 == 0) svi_neparni=false;
		if (svi_neparni) v2.push_back(a[k]);
	}
	
	if (y) return IzbaciDuple(v1);
	else return IzbaciDuple(v2);
	
}

int main ()
{
	
	std::vector<int> a;
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	int broj{};
	
	do {
		std::cin>>broj;
		if (broj == 0) break;
		a.push_back(broj);
	}
	
	while (broj != 0);
	
	std::vector<int> b = IzdvojiGadne(a, true);
	std::vector<int> c = IzdvojiGadne(a, false);
	
	std::cout<<"Opaki: ";
	for (int x:b) std::cout<<x<<" ";
	
	std::cout<<std::endl;
	
	std::cout<<"Odvratni: ";
	for (int x:c) std::cout<<x<<" ";
	
	return 0;
}

