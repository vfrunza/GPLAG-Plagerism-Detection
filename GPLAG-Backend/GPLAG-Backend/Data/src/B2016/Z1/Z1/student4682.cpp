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

std::vector<int> IzdvojiGadne(std::vector<int> v, bool opaki) {
	std::vector<int> b;
	std::vector<int> c;
	int ostatak=0;
	std::vector<int> pom;
	
	for(int i=0; i<v.size(); i++) {
		bool nema_ga=true;
		for(auto x : pom) {
			if(x==v[i]) nema_ga=false;
		}
		if(nema_ga) pom.push_back(v[i]);
	}
	v=pom;
	
	for(int i=0; i<v.size(); i++) {
		std::vector<int> d;
		int nova=v[i];
		do {
		ostatak=nova%3;
		nova/=3;
		d.push_back(std::abs(ostatak));
		} while(nova!=0);
		
		int brojac_0=0, brojac_1=0, brojac_2=0;
		
		for(int i=0; i<d.size(); i++) {
			if(d[i]==0) brojac_0++;
			else if(d[i]==1) brojac_1++;
			else if(d[i]==2) brojac_2++;
		}
		
		if(brojac_0%2==0 && brojac_1%2==0 && brojac_2%2==0)
		b.push_back(v[i]);
	
		std::vector<int> pomocni;
		if(brojac_0!=0) pomocni.push_back(brojac_0);
		if(brojac_1!=0) pomocni.push_back(brojac_1);
		if(brojac_2!=0) pomocni.push_back(brojac_2);
		
		bool neparni=true;
		for(int i=0; i<pomocni.size(); i++) {
			if(pomocni[i]%2==0) neparni=false;
		}
		if(neparni) c.push_back(v[i]);
	
		
		if(i==v.size()) 
		break;
	}
	
	
	
	if(opaki) return b;
	else
	return c;
}


int main ()
{
	std::vector<int> a;
	int broj;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;) {
		std::cin>>broj;
		if(broj==0) break;
		a.push_back(broj);
	} 
	
	std::vector<int> b;
	std::vector<int> c;
	b=IzdvojiGadne(a,true);
	c=IzdvojiGadne(a,false);
	
	std::cout<<"Opaki: ";
	for(int x : b) {
		std::cout<<x<<" ";
	}
	std::cout<<std::endl;

	std::cout<<"Odvratni: ";
	for(int x : c) {
		std::cout<<x<<" ";
	}
	std::cout<<std::endl;
	return 0;
}