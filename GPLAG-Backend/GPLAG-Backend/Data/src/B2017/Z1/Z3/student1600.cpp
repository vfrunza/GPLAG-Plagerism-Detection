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
#include<cmath>

enum Smjer {Rastuci=1, Opadajuci=2} ;

bool StepenBrojaDva (int n)
{
	if(n<=0)
		return false;

	for(int i=0; i<n; i++) {

		if(pow(2,i) == n)
			return true;
	}
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> a, Smjer b)
{
	std::deque<std::vector<int>> max_ra;
	std::deque<std::vector<int>> max_op;
	std::vector<int> pom;

	if(a.size()==0)
		return max_op;

	for(int i=0; i<a.size()-1; i++) {
		if(StepenBrojaDva(a.at(i))) {
			if(StepenBrojaDva(a.at(i+1)))
				if(a.at(i)<=a.at(i+1)) {
					if(pom.size()==0)
						pom.push_back(a.at(i));

					pom.push_back(a.at(i+1));
				}
		}
		if(!StepenBrojaDva(a.at(i+1)) || a.at(i+1)<a.at(i) || i==a.size()-2) {
			if(pom.size()!=0) max_ra.push_back(pom);
			pom.resize(0);
		}
	}
	pom.resize(0);

	for(int i=0; i<a.size()-1; i++) {
		if(StepenBrojaDva(a.at(i))) {
			if(StepenBrojaDva(a.at(i+1)))
				if(a.at(i)>=a.at(i+1)) {
					if(pom.size()==0)
						pom.push_back(a.at(i));
					pom.push_back(a.at(i+1));
				}
		}
		if(!StepenBrojaDva(a.at(i+1)) || a.at(i+1)>a.at(i) || i==a.size()-2) {
			if(pom.size()!=0)
				max_op.push_back(pom);
			pom.resize(0);
		}
	}

	if(b==1)
		return max_ra;
	return max_op;
}

int main ()
{
	std::vector<int> a;

	int br_el;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>br_el;

	std::cout<<"Unesite elemente vektora: ";

	for (int i=0; i<br_el; i++) {
		int broj;
		std::cin>>broj;
		a.push_back(broj);
	}

	int unos;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>unos;

	std::deque<std::vector<int>> max_ra=MaksimalniPodnizoviStepenaDvojke(a,Rastuci);
	std::deque<std::vector<int>> max_op=MaksimalniPodnizoviStepenaDvojke(a,Opadajuci);

	if(unos==1) {
		std::cout<<"Maksimalni rastuci podnizovi: \n";
		for(int i=0; i<max_ra.size(); i++) {
			for(int j=0; j<max_ra.at(i).size(); j++) {
				std::cout<<max_ra.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}

	else if(unos==2) {
		std::cout<<"Maksimalni opadajuci podnizovi: \n";
		for(int i=0; i<max_op.size(); i++) {
			for(int j=0; j<max_op.at(i).size(); j++) {
				std::cout<<max_op.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}
