/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	.
*/

#include <iostream>
#include <vector>

bool daLiZadovoljava(int a, bool t) {
	long long int x(a);
	if(x<0) x*=-1;
	std::vector<int>cifre(3);
	if(!x) cifre[0]++;
	while(x) {
		cifre[x%3]++;
		x/=3;
	}
	if(t) {
		if(cifre[0]%2==0 && cifre[1]%2==0 && cifre[2]%2==0) return true;
		return false;
	}
	else {
		if(cifre[0]) if(cifre[0]%2==0) return false;
		if(cifre[1]) if(cifre[1]%2==0) return false;
		if(cifre[2]) if(cifre[2]%2==0) return false;
		return true;
	}
}

std::vector<int> IzdvojiGadne(std::vector<int>izvorni, bool t) {
	std::vector<int>vek;
	for(int x : izvorni) {
		if(daLiZadovoljava(x, t)) {
			bool ima(false);
			for(int y : vek) {
				if(y==x) {
					ima=true;
					break;
				}
			}
			if(!ima) vek.push_back(x);
		}
	}
	return vek;
}

int main () {
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int x; std::vector<int>v;
	for(;;) {
		std::cin >> x;
		if(!x) break;
		v.push_back(x);
	}
	std::cout << "Opaki: ";
	auto vek=IzdvojiGadne(v, true);
	for(int a : vek) std::cout << a << " ";
	vek=IzdvojiGadne(v, false);
	std::cout << "\nOdvratni: ";
	for(int a : vek) std::cout << a << " ";
	return 0;
}