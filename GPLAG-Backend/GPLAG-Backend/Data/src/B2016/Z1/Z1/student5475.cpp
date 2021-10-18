/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

/*
std::vector<int> UVektor(int n) {
	std::vector<int> v;
	while(n != 0) {
		v.push_back(n % 3);
		n /= 3;
	}
	return v;
} 

int UBroj(int n) {
	int suma(0);
	std::vector<int> v(UVektor(n));
	for(int i = v.size() - 1; i >= 0; i--)
		suma = suma*10 + v[i];
	return suma;
} */

int ProvjeriGadne(int n) {
	if(n == 0) return 0;
	if(n < 0) n *= -1;
	int nul(0), kec(0), dva(0);
	while(n != 0) {
		if(n%3 == 0) nul++;
		else if(n%3 == 1) kec++;
		else dva++;
		n /= 3;
	}
	if((nul == 0 || nul%2 == 0) && (kec == 0 || kec%2 == 0) && (dva == 0 || dva%2 == 0)) return 1;
	else if((nul == 0 || nul%2 != 0) && (kec == 0 || kec%2 != 0) && (dva == 0 || dva%2 != 0)) return 0;
	return 3;
}

std::vector<int> IzbaciSuvisne(std::vector<int> v) {
	for(int i=0; i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++) {
			if(v[i] == v[j]) {
				v.erase(v.begin() + j);
				j--;
			}
			if(j == v.size()-1) break;
		}
		if(i == v.size()-1) break;
	}
	return v;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool a) {
	if(v.size() == 0) return v; 	
	std::vector<int> glavni;
	v = IzbaciSuvisne(v);
	for(int i=0; i<v.size(); i++) {
		if(ProvjeriGadne(v[i]) == a)
			glavni.push_back(v[i]);
		if(i == v.size()-1) break;
	}
	return glavni;
}

int main ()
{	
	std::vector<int> v;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(;;) {
		int n;
		std::cin >> n;
		if(!std::cin) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			continue;
		}
		if(n == 0) break;
		v.push_back(n);
	}
	std::vector<int> opaki(IzdvojiGadne(v, true));
	std::cout << "Opaki: ";
	for(int i=0; i<opaki.size(); i++) {
		std::cout << opaki[i] << " ";
		if(i == opaki.size()-1) break;
	}
	std::vector<int> odvratni(IzdvojiGadne(v, false));
	std::cout << std::endl << "Odvratni: ";
	for(int i=0; i<odvratni.size(); i++) {
		std::cout << odvratni[i] << " ";
		if(i == odvratni.size()-1) break;
	}
	return 0;
}