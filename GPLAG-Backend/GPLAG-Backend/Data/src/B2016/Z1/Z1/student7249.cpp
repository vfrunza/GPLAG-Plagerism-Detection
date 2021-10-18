/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool opaki) {
	std::vector<int> v1;
	if(opaki) {
		for(int i=0; i<v.size(); i++) {
			std::vector<int> brojaci(3);
			int x(v[i]);
			int c;
			do {
				c=x%3;
				if(x<0) c=-c;
				x/=3;
				brojaci[c]++;
			}while(x!=0);
			bool parnoponavljanje(true);
			for(int j=0; j<brojaci.size(); j++) {
				if(brojaci[j]%2!=0 && brojaci[j]!=0) {
					parnoponavljanje=false;
					break;
				}
			}
			if(parnoponavljanje) {
				if(v1.size()==0) v1.push_back(v[i]);
				else {
					for(int k=0; k<v1.size(); k++) {
						if(v[i]!=v1[k] && k==v1.size()-1) v1.push_back(v[i]);
						if(v[i]==v1[k]) break;
					}
				}
			}
		}
	}
	else {
		for(int i=0; i<v.size(); i++) {
			std::vector<int> brojaci(3);
			int x(v[i]);
			int c;
			do {
				c=x%3;
				if(x<0) c=-c;
				x/=3;
				brojaci[c]++;
			}while(x!=0);
			bool neparnoponavljanje(true);
			for(int j=0; j<brojaci.size(); j++) {
				if(brojaci[j]%2==0 && brojaci[j]!=0) {
					neparnoponavljanje=false;
					break;
				}
			}
			if(neparnoponavljanje) { 	
				if(v1.size()==0) v1.push_back(v[i]);
				else {
					for(int k=0; k<v1.size(); k++) {
						if(v[i]!=v1[k] && k==v1.size()-1) v1.push_back(v[i]);
						if(v[i]==v1[k]) break;
					}
				}
			}
		}
	}
	return v1;
}

int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	int i;
	do {
		std::cin >> i;
		if(i!=0) v.push_back(i);
	}while(i!=0);
	std::vector<int> opaki=IzdvojiGadne(v, true);
	std::vector<int> odvratni=IzdvojiGadne(v, false);
	std::cout << "Opaki: ";
	for(int x : opaki) std::cout << x << " ";
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	for(int x : odvratni) std::cout << x << " ";
	return 0;
}