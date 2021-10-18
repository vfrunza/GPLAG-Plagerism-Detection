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

std::vector<int>Pretvori (int n) {
	std::vector<int> v;
	do {
		v.push_back(std::abs(n%3));
		n=n/3;
	} while(n!=0);
	return v;
}

int Ispitaj (std::vector<int> v) {
	int niz[3]={0,0,0};
	
	for (auto x: v) niz[x]++;
	
	if (niz[0]%2==0 && niz[1]%2==0 && niz[2]%2==0) return 1;
	
	std::vector<int> vbeznule;
	for (int i=0; i<3; i++)
	if (niz[i]!=0) vbeznule.push_back(niz[i]);
	
	bool SviNeparni=true;
	for (auto x: vbeznule)
	 if (x%2==0) SviNeparni=false;
	 if (SviNeparni) return 2;
	 
	return 3;
}

std::vector<int> ObrisiDuplikate (std::vector<int> v) {
	std::vector<int> rez;
	
	for (auto x: v) {
		bool pojaviose=false;
		for (auto y: rez)
		 if (x==y) pojaviose=true;
		 if (pojaviose==false) rez.push_back(x);
	}
	return rez;
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool t) {
	std::vector <int> rez;
	
	for (auto x: v)
	if ((Ispitaj(Pretvori(x))==1 && t) || (Ispitaj(Pretvori(x))==2 && !t))
	rez.push_back(x);
	
	rez=ObrisiDuplikate(rez);

return rez;
}

int main ()
{
	
	std::vector <int> vec; int x;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin >> x;
		if (x==0) break;
		vec.push_back(x);
	} while(x!=0);

	
	std::vector<int> a=IzdvojiGadne(vec,true);
	auto b = IzdvojiGadne(vec,false);
	
	std::cout << "Opaki: ";
	for(auto x: a) std::cout<< x <<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for (auto x: b) std::cout<< x << " ";
	return 0;
}