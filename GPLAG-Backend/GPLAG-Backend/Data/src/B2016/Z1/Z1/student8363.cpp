/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
std::vector<int> IzdvojiGadne(std::vector<int> niz,bool gadni) {
	std::vector<int> vrati;
	for (auto a : niz) {

		int tmp = a,cifre[3] {0,0,0};
		int b;
		while (tmp!=0) {
			b=std::abs(tmp%3);
			cifre[b]++;
			tmp/=3;
		}
		bool is = true;
		for (int i = 0; i < 3; i++) {
			if(cifre[i]!=0) {
				if(cifre[i]%2==0)is = false;
			}
		}
		bool isnt = true;
		for (int i = 0; i < 3; i++) {
			if(cifre[i]!=0) {
				if(cifre[i]%2!=0)isnt=false;
			}
		}
		if(!gadni) {
			if((is && !isnt) || a==0) {

				bool vecima = false;
				for (auto element : vrati) {
					if(element==a)vecima=true;
				}
				if(!vecima)vrati.push_back(a);
			}

		} else {

			if((!is && isnt)) {
				bool vecima = false;
				for (auto element : vrati) {
					if(element==a)vecima=true;
				}
				if(!vecima)vrati.push_back(a);
			}
		}
	}
	return vrati;
}
int main () {
	std::vector<int> test;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		int a;
		cin>>a;
		if(a==0)break;
		test.push_back(a);
	} while (true);
	std::vector<int> test2 = IzdvojiGadne(test,true);
	cout<<"Opaki: ";
	for (auto i : test2) {
		cout<<i<<" ";
	}
	cout<<endl<<"Odvratni: ";
	test = IzdvojiGadne(test,false);
	for (auto i : test) {
		cout<<i<<" ";
	}

	return 0;
}