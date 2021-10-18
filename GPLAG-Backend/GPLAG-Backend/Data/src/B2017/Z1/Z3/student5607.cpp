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
#include<deque>
#include<vector>

typedef std::deque<std::vector<int>> DecVec;
typedef std::vector<int> Vec;
bool DaLiJeStepenDvojke(int broj)
{
	if(broj<=0) return false;
	do {
		if(broj%2==1 && broj!=1) return false;
		broj/=2;
	} while(broj!=0);
	return true;
}

enum Smjer
{
	Opadajuci,Rastuci
};
DecVec MaksimalniPodnizoviStepenaDvojke(Vec brojevi,Smjer pravac)
{
	DecVec dv;
	Vec v1;

	for(int i=0; i<brojevi.size(); i++) {
		if(DaLiJeStepenDvojke(brojevi.at(i))) {
			if(pravac) {
				if((v1.size())!=0) {
					if(brojevi.at(i)>=brojevi.at(i-1)) v1.push_back(brojevi.at(i));
					else if(v1.size()<2) {
						v1.clear();
					} else {
						dv.push_back(v1);
						v1.clear();
					}
					if(v1.size()==0) v1.push_back(brojevi.at(i));
				} else v1.push_back(brojevi.at(i));
			} else {
				if((v1.size())!=0) {
					if(brojevi.at(i)<=brojevi.at(i-1)) v1.push_back(brojevi.at(i));
					else if(v1.size()<2) {
						v1.clear();
					} else {
						dv.push_back(v1);
						v1.clear();
					}
					if(v1.size()==0) v1.push_back(brojevi.at(i));
				} else v1.push_back(brojevi.at(i));
			}
		} else {
			if(v1.size()<2) v1.clear();
			dv.push_back(v1);
			v1.clear();
		}
	}
	dv.push_back(v1);
		return dv;
}

int main ()
{
	int n,broj,izbor;
	Vec v;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin >> broj;
		v.push_back(broj);
	}
	do {
		std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
		std::cin >> izbor;
	} while(izbor!=1 && izbor!=2);
	if(izbor==1) {
		DecVec D(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		for(auto v:D) {
			for(int x:v) {
				std::cout<<x<<" ";
			}
			std::cout<<std::endl;
		}
	}
	if(izbor==2) {
		DecVec C(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci));
		std::cout <<"Maksimalni opadajuci podnizovi: "<<std::endl;
		for(auto v: C) {
			for(int x: v) {
				std::cout<<x<<" ";
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}