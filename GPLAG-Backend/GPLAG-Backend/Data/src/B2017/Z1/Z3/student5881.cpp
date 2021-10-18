/*B 2017/2018, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include <vector>
#include <deque>
#define E 0.001

enum Smjer {
    Rastuci,
    Opadajuci
};

bool StepenDvojke(int b)
{
	
	
	
	if(b<1)return false;
	double a;
	a=b;
	do {
		if (abs(a*a-1<E))return true;
		a/=2;
	} while(a>=1);
	return false;
}
std::deque<std::vector <int>>MaksimalniPodnizoviStepenaDvojke(std::vector <int> niz,Smjer t)
{
	std::deque<std::vector <int>> dek;
	std::vector<int> pomocni;
	int brojac=0,j=0;
	if (t==Rastuci) {
		for(int i=0; i<niz.size(); i++) {
			if (StepenDvojke(niz.at(i))) {
				do {
					pomocni.push_back(niz.at(i));
					i++;
					brojac++;
				} while(i<niz.size()&&niz.at(i)>niz.at(i-1)&&(StepenDvojke(niz.at(i))));
			}
			if(brojac==1)
				i--;
			if(brojac>1) {
				dek.insert(dek.begin() + j, pomocni);
				j++;
				i--;
			}
			if(brojac>0)
				for(int j=0; j<brojac; j++) {
					pomocni.erase(pomocni.begin() + 0);
				}
			brojac=0;
		}
	} else  {

		for(int i=0; i<niz.size(); i++) {
			if (StepenDvojke(niz.at(i))) {
				do {
					pomocni.push_back(niz.at(i));
					i++;
					brojac++;
				} while(i<niz.size()&&niz.at(i)<niz.at(i-1)&&(StepenDvojke(niz.at(i))));
			}
			if(brojac==1)
				i--;
			if(brojac>1) {
				dek.insert(dek.begin() + j, pomocni);
				j++;
				i--;
			}
			if(brojac>0)
				for(int j=0; j<brojac; j++) {
					pomocni.erase(pomocni.begin() + 0);
				}
			brojac=0;
		}
	}
	return dek;
}
int main ()
{
	int a,b,c;
	std::vector<int> niz;
	std::deque<std::vector <int>> dek;
	Smjer t;

	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>a;

	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<a; i++) {
		std::cin>>b;
		niz.push_back(b);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>c;


	if(c==1) {
		std::cout<<"Maksimalni rastuci podnizovi: \n";
		t=Rastuci;
	} else if(c==2) {
		std::cout<<"Maksimalni opadajuci podnizovi: \n";
		t=Opadajuci;
	} else
		return 0;

	dek=MaksimalniPodnizoviStepenaDvojke(niz,t);
	for(int j=0; j<dek.size(); j++) {
		for(int k=0; k<dek[j].size(); k++) {

			std::cout<<dek[j][k]<<" ";
		}
		std::cout<<"\n";
	}
	return 0;
}