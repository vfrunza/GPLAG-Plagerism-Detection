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
using std::vector;

int Ternarni (int n) {
	n=abs(n);
	long long int suma(0),k(1);
	while (n!=0) {
		suma+=(n%3)*k;
		k*=10;
		n/=3;
	}
	int br0(0),br1(0),br2(0);
	while (suma!=0) {
		if (suma%10==0) br0++;
		else if (suma%10==1) br1++;
		else if (suma%10==2) br2++;
		suma/=10;
	}
	if (br0%2==0 && br1%2==0 && br2%2==0)
		return 1;
	else if ((br0%2==1 || br0==0) && (br1%2==1 || br1==0) && (br2%2==1 || br2==0))
		return 2;
	return 3;
}

vector<int> IzdvojiGadne (vector<int> v, bool a) {
	vector<int> opaki,odvratni;
	if (a) {
		for (int i=0; i<v.size(); i++) {
			if (Ternarni(v[i])==1) {
				bool isti_opaki(false);
				for (int j=0; j<opaki.size(); j++) {
					if (opaki[j]==v[i]) {
						isti_opaki=true;
						break;
					}
				}
				if (!isti_opaki)	
					opaki.push_back(v[i]);
			}
		}
		return opaki;
	}
	else {
		for (int i=0; i<v.size(); i++) {
			if (Ternarni(v[i])==2) {
				bool isti_odvratni(false);
				for (int j=0; j<odvratni.size(); j++) {
					if (odvratni[j]==v[i]) {
						isti_odvratni=true;
						break;
					}
				}
				if (!isti_odvratni)
					odvratni.push_back(v[i]);
			}
		}
		return odvratni;
	}
}

int main ()
{
	vector<int> brojevi;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int broj;
	for (;;) {
		std::cin >> broj;
		if (broj==0)
			break;
		brojevi.push_back(broj);
	}
	
	vector<int> opaki(IzdvojiGadne(brojevi, true));
	vector<int> odvratni(IzdvojiGadne(brojevi, false));
	std::cout << "Opaki: ";
	for (int i=0; i<opaki.size(); i++)
		std::cout << opaki[i] << " ";
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	for (int i=0; i<odvratni.size(); i++)
		std::cout << odvratni[i] << " ";
	return 0;
}