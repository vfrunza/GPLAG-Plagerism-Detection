#include <iostream>
#include <cmath>
#include <vector>

int opaki_broj(int broj){
	int cifra, nula(0), jedan(0), dva(0);
	broj=fabs(broj);
	for(int i=0; ; i++) {
		cifra=broj%3;
		if(cifra==0) nula++;
		if(cifra==1) jedan++;
		if(cifra==2) dva++;
		broj/=3;
		if(broj==0) break;
	}
	if(nula%2==0 && jedan%2==0 && dva%2==0) return 1;
	if((nula%2!=0 || nula==0) && (jedan%2!=0 || jedan==0) && (dva%2!=0 || dva==0)) return 2;
	else return 3;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool t) {
	std::vector<int> x;
	for(auto i : v) {
		if(t) {
			if(opaki_broj(i)==1) x.push_back(i);
		} else {
			if(opaki_broj(i)==2) x.push_back(i);
		}
	}
	for(int i=0; i<x.size(); i++){
		for(int j=i+1; j<x.size(); j++) {
			if(x[i]==x[j]) {
				x.erase(x.begin()+j);
				j--;
			}
		}
	}
	return x;
}

int main() {
	int broj;
	std::vector<int> v;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin >> broj;
		if(broj!=0) v.push_back(broj);
	}while (broj!=0);
	
	std::cout << "Opaki: ";
	for(auto i : IzdvojiGadne(v, true )) std::cout << i << " ";
	std::cout << std::endl << "Odvratni: ";
	for(auto i : IzdvojiGadne(v, false)) std::cout << i << " " ;

	return 0;
}