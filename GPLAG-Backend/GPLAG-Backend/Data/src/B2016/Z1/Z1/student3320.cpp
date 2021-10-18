/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
/*  *** Zadaci za samostalan rad (ZSR 1, Zadatak 30) ***
	
	Autotestove napisao Adnan Arnautovic. Sva pitanja,
	nedoumice i prijave gresaka mozete slati na: aarnautovi1@etf.unsa.ba
	
	
	NAPOMENA: zadaci za samostalni rad po svojoj strukturi nisu pogodni
	za autotestiranje. Stoga autotestovi pokusavaju da na najracionalniji
	nacin *predloze* ocekivane nazive funkcija, ulaze i izlaze.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

std::vector<int>Provjera(long long int broj1) {
	long long int temp=broj1;
	std::vector<int>pomocni;
	long long int temp1;
	
	do{
		temp1=temp;
		temp=temp/3;
		temp1=abs(temp1%3);
		pomocni.push_back(temp1);
	}while(temp!=0);

	return pomocni;
}

std::vector<int>IzdvojiGadne(std::vector<int>brojevi1, bool pravilo) {
	std::vector<int>Odvratni;
	std::vector<int>Opaki;
	std::vector<int>temp;
	int provjera;
	int brojac;
	
	for(int i=0; i<brojevi1.size(); i++) {
		temp=Provjera(brojevi1[i]);
		int pomoc=1;
		if(pravilo) {
		for(int j=0; j<temp.size(); j++) {
			brojac=0;
			for(int k=0; k<temp.size(); k++) {
				if(temp[j]==temp[k]) {
					brojac++;
				}
			}
			if(brojac%2==0) {
				provjera=1;
			} else {
				provjera=0;
			}
			if(!provjera) break;
		}
		}
			if(!pravilo) {
			for(int j=0; j<temp.size(); j++) {
				brojac=0;
				for(int k=0; k<temp.size(); k++) {
					if(temp[j]==temp[k]) {
						brojac++;
					}
				}
				if(brojac%2!=0) {
					provjera=2;
				} else {
					provjera=0;
				}
				if(!provjera) break;
			}
		}
	
		if(provjera==1) {
			if(Opaki.size()>0) {
				for(int j=0; j<Opaki.size(); j++) {
					if(brojevi1[i]==Opaki[j]) {
						pomoc=0;
						break;
					} 
				}
			if(pomoc==1) {
			Opaki.push_back(brojevi1[i]);
			}
		} else {
			Opaki.push_back(brojevi1[i]);
			}
		} else {
			if(provjera==2) {
				if(Odvratni.size()>0) {
					for(int j=0; j<Odvratni.size(); j++) {
					if(brojevi1[i]==Odvratni[j]) {
						pomoc=0;
						break;
						}
					}
					if(pomoc==1) {
						Odvratni.push_back(brojevi1[i]);
					}
				} else {
				Odvratni.push_back(brojevi1[i]);
				}
			}
		}
	}
	
	
	if(pravilo) {
		return Opaki;
	} else {
		return Odvratni;
	}
}

int main () {
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int>brojevi;
	std::vector<int>temp;
	long long int broj;
	
	do {
		std::cin >> broj;
		if(broj!=0) brojevi.push_back(broj);
	}while(broj!=0);
	
	
	std::cout << "Opaki: ";
	temp=IzdvojiGadne(brojevi, true);
	for(int i=0; i<temp.size(); i++) {
		std::cout << temp[i] << " ";
	}
	
	std::cout << std::endl;
	
	temp.clear();
	std::cout << "Odvratni: ";
	temp=IzdvojiGadne(brojevi, false);
	for(int i=0; i<temp.size(); i++) {
		std::cout << temp[i] << " ";
	}
	return 0;
}