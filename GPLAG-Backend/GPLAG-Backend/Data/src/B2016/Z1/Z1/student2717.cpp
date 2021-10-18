/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne (std::vector<int> vektor, bool opak)
{
	std::vector<int> brojevi(vektor);
	std::vector<int> opaki_brojevi;
	std::vector<int> odvratni_brojevi;
	for(int i {0} ; i<brojevi.size() ; i++) {
		int broj(brojevi[i]);
		int nula {0},jedan {0},dva {0};
		while(broj!=0) {
			int cifra(broj%3);
			switch (cifra) {
			case 0: {
				nula++;
				break;
			}
			case 1: {
				jedan++;
				break;
			}
			case 2: {
				dva++;
				break;
			}
			default: {
				break;
			}
			}
			broj/=3;
		}
		//samo jedna cifra
		
		//dvije cifre
		
		//sve tri cifre
		if(nula%2==0 && jedan%2==0 && dva%2==0) {
			opaki_brojevi.push_back(vektor[i]);
		} else if (nula%2!=0 && jedan%2!=0 && dva%2!=0) {
			odvratni_brojevi.push_back(vektor[i]);
		}
	}
	for(int i {0} ; i<opaki_brojevi.size() ; i++) {
		for(int j {i+1} ; j<opaki_brojevi.size() ; j++) {
			if(opaki_brojevi[i]==opaki_brojevi[j]) {
				opaki_brojevi.erase(opaki_brojevi.begin()+j);
			}
		}
	}
	for(int i {0} ; i<odvratni_brojevi.size() ; i++) {
		for(int j {i+1} ; j<odvratni_brojevi.size() ; j++) {
			if(odvratni_brojevi[i]==odvratni_brojevi[j]) {
				odvratni_brojevi.erase(odvratni_brojevi.begin()+j);
			}
		}
	}
	if(opak) {
		return opaki_brojevi;
	}
	return odvratni_brojevi;
}

int main ()
{
	std::cin.ignore(10000,'\n');
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> ulazni_vektor;
	int element {-1};
	while(element!=0) {
		std::cin >> element;
		ulazni_vektor.push_back(element);
	}
	bool opaki(true);
	std::vector<int> izlazni_vektor(IzdvojiGadne(ulazni_vektor,opaki));
	std::cout << "Opaki: ";
	for(int element : izlazni_vektor) std::cout << element << " " << std::endl;

	opaki=false;
	izlazni_vektor=(IzdvojiGadne(ulazni_vektor,opaki));
	std::cout << "Odvratni: ";
	for(int element : izlazni_vektor) std::cout << element << " " << std::endl;
	return 0;
}
