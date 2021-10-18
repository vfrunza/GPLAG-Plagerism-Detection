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

std::vector<int> PretvoriUTernarni(int n) {
	std::vector<int> cifre;
	
	for(;;) {
		int cifra(n%3);
		if(cifra<0) cifra=-cifra;
		cifre.push_back(cifra);
		n/=3;
		if(n==0) break;
	}
	
	
	return cifre;
}

bool DaLiJeOpak(int n) {
	
	std::vector<int> ternarni(PretvoriUTernarni(n));
	std::vector<int> brojac(3,0);
	
	for(unsigned int i=0; i<ternarni.size(); i++)
		brojac[ternarni[i]]++;
	
	for(unsigned int i=0; i<brojac.size(); i++) {
		if(brojac[i]==0)
			continue;
		if(brojac[i]%2!=0)
			return false;
	}
	return true;
}

bool DaLiJeOdvratan(int n) {
	
	std::vector<int> ternarni(PretvoriUTernarni(n));
	std::vector<int> brojac(3,0);
	
	for(unsigned int i=0; i<ternarni.size(); i++)
		brojac[ternarni[i]]++;
	
	for(unsigned int i=0; i<brojac.size(); i++) {
		if(brojac[i]==0)
			continue;
		if(brojac[i]%2==0)
			return false;
	} 
	return true;
}

bool DaLiJeSadrzan(std::vector<int> v, int n) {
	for(unsigned int i=0; i<v.size(); i++) {
		if(v[i]==n)
			return true;
	}
	return false;	
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool opaki) {
	
	std::vector<int> novi;
	
	if(opaki) {
		for(unsigned int i=0; i<v.size(); i++) {
			if(DaLiJeOpak(v[i]) && !DaLiJeSadrzan(novi, v[i]))
				novi.push_back(v[i]);
		
		}
	}
	else {
		for(unsigned int i=0; i<v.size(); i++) {
			if(DaLiJeOdvratan(v[i]) && !DaLiJeSadrzan(novi, v[i]))
				novi.push_back(v[i]);
		
		}
	}
return novi;	
	
}



int main ()
{
	
	std::vector<int> v;

	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;) {
		int clan;
		std::cin>>clan;
		if(clan==0) break;
		v.push_back(clan);
	}
	
	std::vector<int> opaki(IzdvojiGadne(v,true)), odvratni(IzdvojiGadne(v,false));
	std::cout<<"Opaki: ";
	for(unsigned int i=0; i<opaki.size(); i++)
		std::cout<<opaki[i]<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for(unsigned int i=0; i<odvratni.size(); i++)
		std::cout<<odvratni[i]<<" ";
	return 0;
}