/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

int Stepen (int x, int y) {																	// Zamjenjuje funkciju 'pow'
	int a(1);
	for (int i=0; i<y; i++) {
		a*=x;
	}
	return a;
}

std::vector<int> IzdvojiGadne (std::vector<int> x, bool y) {
	std::vector<int> v, v1(x);
	for (int i=0; i<x.size(); i++) {
		int br(0);
		if (v1[i]<0) {
			v1[i]=v1[i]*-1;
		}
		for (int k=1; k<100000000; k*=3) {													// Fakticki broji koliko ce cifara
			if (k/v1[i]==1 || k/v1[i]==2) {													// imati ternarna reprezentacija broja
				break;
			}
			br++;
		}
		long long int broj(0);																// Pretvara broj u ternarni zapis
		for (int j=0; j<br; j++) {
			broj+=(v1[i]%3)*Stepen(10,j);
			v1[i]/=3;
		}
		int br0(0), br1(0), br2(0);
		for (int a=0; a<br; a++) {															// Broji cifre 0, 1 i 2 u ternarnoj
			if (broj%10==0) {																// reprezentaciji
				br0++;
			}
			if (broj%10==1) {
				br1++;
			}
			if (broj%10==2) {
				br2++;
			}
			broj/=10;
		}
		if (y==true) {
			if (br0%2==0 && br1%2==0 && br2%2==0) {
				v.push_back(x[i]);
			}
		}
		else {
			if (br0==0) {
				br0=1;
			}
			if (br1==0) {
				br1=1;
			}
			if (br2==0) {
				br2=1;
			}
			if (br0%2!=0 && br1%2!=0 && br2%2!=0) {
				v.push_back(x[i]);
			}
		}
	}
	for (int i=0; i<v.size(); i++) {														// Uklanja elemente koji se 
		for (int j=i+1; j<v.size(); j++) {													// ponavljaju
			if (v[j]==v[i]) {
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
}

int main () {
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	for (;;) {
		int x;
		std::cin >> x;
		if (x==0) {
			break;
		}
		v.push_back(x);
	}
	std::cout << "Opaki: ";
	std::vector<int> opaki(IzdvojiGadne(v,true));
	for (int i=0; i<opaki.size(); i++) {
		std::cout << opaki[i] << " ";
	}
	std::cout << std::endl << "Odvratni: ";
	std::vector<int> odvratni(IzdvojiGadne(v,false));
	for (int i=0; i<odvratni.size(); i++) {
		std::cout << odvratni[i] << " ";
	}
	return 0;
}