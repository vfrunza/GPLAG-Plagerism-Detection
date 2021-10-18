/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
std::vector<int> IzdvojiGadne(std::vector<int> v, bool kakav) {
	std::vector<int> opaki;
	std::vector<int> odvratni;
	std::vector<int> pomocni;
	std::vector<int> brojac(3);													// za histogram
	for(int i(0); i<v.size(); i++) {
		int temp = v.at(i);
		int a = v.at(i);
		if(a<0) a=-a;
		pomocni.clear(); 
		while(a>0) {
			pomocni.push_back(a%3); 
			a/=3;
		}
		for(int b(0); b<3; b++) 
			brojac[b]=0;														// postavlja vraca inicijalizaciju na 0 u vektoru "brojac";
		for(int j(0); j<pomocni.size(); j++) {
			for(int k(0); k<3; k++) {
				if(pomocni[j]==k) brojac[k]++;
			}
		}
		int paran(0);
		int neparan(0);
		for(int j(0); j<brojac.size(); j++) {
			if(brojac[j]!=0 && brojac[j]%2==0) paran = 1;
			else if(brojac[j]!=0) neparan = 1;
		}
		if(paran == 1 && neparan == 0) {
			int nemoj(0); 														// u slucaju da ga ne treba stavljat u vektor jer vec postoji 
			if(opaki.size()==0) opaki.push_back(temp);
			else {
				for(int j(0); j<opaki.size(); j++) {
					if(temp==opaki[j]) nemoj=1;
				}
				if(nemoj==0) opaki.push_back(temp);
			}
		}
		else if(paran == 0 && neparan == 1) {
			int nemoj1(0);
			if(odvratni.size()==0) odvratni.push_back(temp);
			else {
				for(int j(0); j<odvratni.size(); j++) {
					if(temp==odvratni[j]) nemoj1=1;
				}
				if(nemoj1==0) odvratni.push_back(temp);
			}
		}
	}
	if(kakav)
		return opaki;
	return odvratni;
}
int main() {
	std::vector<int> v;
	std::vector<int> opaki;
	std::vector<int> odvratni;
	int element;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin >> element;
		if(element==0) break;
		v.push_back(element);
	}while(element!=0);
	std::cout << "Opaki: ";
	opaki=IzdvojiGadne(v, true);
	odvratni=IzdvojiGadne(v, false);
	for(int i(0); i<opaki.size(); i++) 
		std::cout << opaki[i] << " ";
	std::cout << std::endl << "Odvratni: ";
	for(int i(0); i<odvratni.size(); i++)
		std::cout << odvratni[i] << " ";
		
	return 0;
}