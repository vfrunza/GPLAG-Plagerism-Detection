#include <iostream>
#include <vector>
#include <climits>
#include <limits.h>
#include <limits>


using std::cout;
using std::cin;
using std::endl;

std::vector<int> okreni_ternarni(std::vector<int> v) {
	
	std::vector<int> okrenut;
	
	for (int i=v.size()-1; i>=0; i--) {
		okrenut.push_back(v[i]);
	}
	return okrenut;
}

std::vector<int> u_ternarni(int broj) {
	
	std::vector<int> ternarni;
	
	if(!broj)
		ternarni.push_back(broj);
	
	while (broj != 0) {
		ternarni.push_back(broj%3);
		broj = broj/3;
	}
	return okreni_ternarni(ternarni);
}
bool je_li_odvratan(int broj) {
	
	int koliko_puta;
	
	std::vector<int>ternarni{u_ternarni(broj)};
	
	for(int i=0; i<ternarni.size(); i++) {
		koliko_puta=0;
		for(int j=0; j<ternarni.size(); j++) {
			if(ternarni[i]==ternarni[j])
				koliko_puta++;
		}
		if(koliko_puta%2==0)
			return false;
	}	
	return true;		
}

bool je_li_opak(int broj) {
	
	int koliko_puta;
	
	std::vector<int>ternarni{u_ternarni(broj)};
	for(int i=0; i<ternarni.size(); i++) {
		koliko_puta=0;
		for(int j=0; j<ternarni.size(); j++) {
			if(ternarni[i]==ternarni[j])
				koliko_puta++;
		}
		if(koliko_puta%2!=0)
			return false;
	}
	return true;
}
bool ne_nalazi_se(std::vector<int>v, int broj) {
	
	for(int i=0; i<v.size(); i++) {
		if(v[i]==broj)
			return false;
	}
	return true;
}

std::vector<int> IzdvojiGadne(std::vector<int>v, bool paran) {
	
	std::vector<int>gadni;
	
	for(int i=0; i<v.size(); i++) {
		if((paran && je_li_opak(v[i])) || (!paran && je_li_odvratan(v[i])))
			if(ne_nalazi_se(gadni,v[i]))
				gadni.push_back(v[i]);
	}
	return gadni;
}

int main ()
{
	std::vector<int> v = {6,0,std::numeric_limits<int>::min()
};
    std::vector<int> a = IzdvojiGadne(v,1);
	//Ispisujemo opake brojeve
    std::cout << "Opaki: ";
	for(auto x : a) {
	        std::cout << x << " ";
	}
	
	std::cout << std::endl;
	
	std::vector<int> b = IzdvojiGadne(v,0);
	//Ispisujemo odvratne brojeve
	std::cout << "Odvratni: ";
	for(auto x : b) {
	        std::cout << x << " ";
	}
	
	return 0;
}