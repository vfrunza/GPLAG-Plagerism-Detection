#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool a) {
	std::vector<int> v2;
	for(int i(0); i<v.size(); i++) {
		int r, temp(v[i]);
		std::vector<int> v3;
		r=std::abs(temp%3);
		temp/=3;
		v3.push_back(r);
		temp=std::abs(temp);
		while(temp!=0) {
			r = temp%3;
        	temp /= 3;
        	v3.push_back(r);
		}
		int nula(0), jedan(0), dva(0);
		for(int j(0); j<v3.size(); j++) {
			if(v3[j]==0) nula++;
			if(v3[j]==1) jedan++;
			if(v3[j]==2) dva++;
		}
	
		bool b(false), n, j, d;
		if(nula!=0)
			n=nula%2!=0;
			else n=true;
		if(jedan!=0)
			j=jedan%2!=0;
			else j=true;
		if(dva!=0)
			d=dva%2!=0;
			else d=true;
		if((a and (nula%2==0 and jedan%2==0 and dva%2==0)) or (!a and n and j and d)) {
			for(int k(0); k<v2.size(); k++)
				if(v2[k]==v[i]) b=true;
			if(!b) v2.push_back(v[i]);
		}
	}
	return v2;
}

int main ()
{
	std::vector<int> v;
	int broj;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin >> broj;
		if(broj!=0) v.push_back(broj);
	} while(broj!=0);
	std::vector<int> b(IzdvojiGadne(v, true));
	std::vector<int> c(IzdvojiGadne(v, false));
	std::cout << "Opaki: ";
	for(int x : b) std::cout << x << " ";
	std::cout << std::endl << "Odvratni: ";
	for(int x : c) std::cout << x << " ";
	std::cout << std::endl;
	return 0;
}