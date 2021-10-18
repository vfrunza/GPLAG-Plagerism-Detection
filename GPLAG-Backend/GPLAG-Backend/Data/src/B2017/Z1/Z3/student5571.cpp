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
#include <cmath>
enum Smjer {Rastuci=1, Opadajuci};

bool stepdvojke(int n)
{
	if(n<=0) return false;
	if((n & (n-1))==0) return true;
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s)
{
	std::deque<std::vector<int>> dv;

	if(s==Rastuci) {
		for(int i=0; i<v.size()-1; i++) {
			if(!stepdvojke(v.at(i)) || !stepdvojke(v.at(i+1))) continue;
			if(v.at(i)<=v.at(i+1)) {
				int j;
				std::vector<int> p;
				for(j=i; j<v.size()-1; j++) {
					p.push_back(v.at(j));
					if(v.at(j+1)<v.at(j)) break;
					if(!stepdvojke(v.at(j+1))) break;
					if(j==v.size()-2) p.push_back(v.at(j+1));
				}
				i=j;
				dv.push_back(p);
			}

		}
	} else {
		for(int i=0; i<v.size()-1; i++) {
			if(!stepdvojke(v.at(i)) || !stepdvojke(v.at(i+1))) continue;
			if(v.at(i)>=v.at(i+1)) {
				int j;
				std::vector<int> p;
				for(j=i; j<v.size()-1; j++) {
					p.push_back(v.at(j));
					if(v.at(j+1)>v.at(j)) break;
					if(!stepdvojke(v.at(j+1))) break;
					if(j==v.size()-2) p.push_back(v.at(j+1));
				}
				i=j;
				dv.push_back(p);
			}

		}
	}

	return dv;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> v;
	for(int i=0; i<n; i++) {
		int br;
		std::cin>>br;
		v.push_back(br);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int a;
	std::cin>>a;

	for(;;) {
		if(a==1 || a==2) break;
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>a;
	}

	if(a==1) {
		std::deque<std::vector<int>> dv(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		for(auto x : dv) {
			for(auto y : x) std::cout<<y<<" ";
			std::cout<<std::endl;
		}
	}

	if(a==2) {
		std::deque<std::vector<int>> dv(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci));
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		for(auto x : dv) {
			for(auto y : x) std::cout<<y<<" ";
			std::cout<<std::endl;
		}
	}

	return 0;
}