/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
 

int funkcija(int s) {
	long int broj(0), dvica(0), kec(0), nula(0);
		do {
		broj = s%3;
		if(broj < 0) broj *= -1;
		if (broj == 2) dvica++;
		else if (broj == 1) kec++;
		else if (broj == 0) nula++;
		s /= 3;
	}while(s != 0);
		if (dvica%2==0 && kec%2==0 && nula%2==0) return 0;
		else if ((dvica%2==1 && kec%2==1 && nula%2==1) || (dvica==0 && kec==0 && nula%2==1) || (nula==0 && kec==0 && dvica%2==1) || (dvica==0 && nula==0 && kec%2==1) || (nula==0 && kec%2==1 && dvica%2==1) || (nula%2==1 && kec==0 && dvica%2==1) || (nula%2==1 && kec%2==1 && dvica==0)) return 1;
		else return 2;
		}	

std::vector<int> IzdvojiGadne(std::vector<int> v, bool logika) {
	std::vector<int> v1;
	int d;
	for(int i(0); i < v.size(); i++) {
		d = funkcija(v[i]);
	if(logika == 1 && d == 0) { 
		v1.push_back(v[i]);
	}
	else if(logika == 0 && d == 1) {
		v1.push_back(v[i]);
	}
	else continue;
	}
	for(int i(0); i < v1.size(); i++) {
		for(int j(i+1); j < v1.size(); j++) {
			if(v1[i] == v1[j]) { v1.erase(v1.begin() + j);
			j--;
			}
		}
	}
	return v1;
}

int main () {
	std::vector<int> v;
	int n;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin >> n;
		if(n != 0) v.push_back(n);
	} while(n != 0);
	
	auto vektor1 = IzdvojiGadne(v, 1);
	std::cout << "Opaki: ";
	
	for(int i(0); i < vektor1.size(); i++) {
		std::cout << vektor1[i] << " ";
	}
	std::cout << std::endl;
	
	auto vektor2 = IzdvojiGadne(v, 0);
	std::cout << "Odvratni: ";
	for(int i(0); i < vektor2.size(); i++) {
		std::cout << vektor2[i] << " ";
	}

	return 0;
}