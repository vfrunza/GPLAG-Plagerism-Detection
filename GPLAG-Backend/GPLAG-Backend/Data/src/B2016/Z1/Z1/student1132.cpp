#include<iostream>
#include<vector>
#include<limits>
#include<cstdlib>
std::vector<int> IzdvojiGadne(std::vector<int> v,bool opaki) {
	std::vector<int> rez;
	for(auto e:v) {
		int niz[3]{};
		int pom = e;
		if(pom == 0) niz[0]++;
		while(pom != 0)	{
			niz[std::abs(pom % 3)]++;
			pom/=3;
		}
		if((niz[0]%2 == 1-opaki || !niz[0]) && (niz[1]%2 == 1-opaki || !niz[1]) && (niz[2]%2 == 1-opaki || !niz[2])) {
			bool nema = true;
			for(auto g:rez) if(g == e) nema = false;
			if(nema) rez.push_back(e);
		}
	}
	return rez;
}
int main () {
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int x;
	std::vector<int> v;
	for(;;)
	{
		std::cin>> x;
		if(x!=0) v.push_back(x);
		else break;
	}
	std::vector<int> res = IzdvojiGadne(v,true);
	std::cout<<"Opaki: ";
	for(auto e:res) std::cout<<e<<" ";
	res = IzdvojiGadne(v,false);
	std::cout<<"\nOdvratni: ";
	for(auto e:res) std::cout<<e<<" ";
	return 0;
}