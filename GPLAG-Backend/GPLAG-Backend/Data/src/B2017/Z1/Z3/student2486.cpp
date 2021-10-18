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
#include <deque>
#include <vector>
#include <cmath>

enum Smjer {Rastuci, Opadajuci};

bool StepenBrojaDva (int n) {
	if (n==1) return true;
	int i(0), m;
	for (;;) {
		m=pow(2,i);
		if (n==m) return true;
		else if (m>n) return false;
		i++;
	}
}

std::vector<int> ObrniNiz(std::vector<int> v)
{
	for (int i=0; i<v.size()/2; i++) {
		int pomocna(v.at(i));
		v.at(i)=v.at(v.size()-1-i);
		v.at(v.size()-1-i)=pomocna;
	}
	return v;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer n)
{
	std::deque<std::vector<int>> d;
	if (n==Rastuci) {
		for (int i=0; i<v.size()-1; i++) {
			std::vector<int> v1;
			int j;
			if (StepenBrojaDva(v.at(i))==true && StepenBrojaDva(v.at(i+1))==true && (v.at(i+1)>=v.at(i))) {
				v1.push_back(v.at(i));
				for (j=i+1; j<v.size(); j++) {
					if ((j==v.size()) && StepenBrojaDva(v.at(j-1))==true && StepenBrojaDva(v.at(j))==true && v.at(j)>=v.at(j-1)) v1.push_back(v.at(j));
					else if (StepenBrojaDva(v.at(j))==true && v.at(j)>=v.at(j-1)) v1.push_back(v.at(j));
					else {
						j--;
						break;
					}
				}
				i=j;
				d.push_back(v1);
			}
		}
		return d;
	}
	else if (n==Opadajuci) {
		for (int i=0; i<v.size()-1; i++) {
			std::vector<int> v1;
			int j;
			if (StepenBrojaDva(v.at(i))==true && StepenBrojaDva(v.at(i+1))==true && (v.at(i+1)<=v.at(i))) {
				v1.push_back(v.at(i));
				for (j=i+1; j<v.size(); j++) {
					if (StepenBrojaDva(v.at(j))==true && StepenBrojaDva(v.at(j-1))==true && v.at(j)<=v.at(j-1)) v1.push_back(v.at(j));
					else {
						j--;
						break;
					}
				}
				i=j;
				d.push_back(v1);
			}
		}
		return d;
	}
	std::deque<std::vector<int>> nulti(0);
	return nulti;
}



int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> v(n);
	for (int i=0; i<v.size(); i++) {
		std::cin>>v.at(i);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int odluka;
	std::cin>>odluka;
	while (odluka!=1 && odluka!=2) {
		std::cout<<"Neispravan unos!";
		std::cout<<std::endl<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
		std::cin>>odluka;
	}
	std::deque<std::vector<int>> d(n);
	if (odluka==1) {
		d=(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		for (int i=0; i<d.size(); i++) {
			for (int j=0; j<d.at(i).size(); j++) {
				std::cout<<d.at(i).at(j)<<" ";
				if (j==d.at(i).size()-1) std::cout<<std::endl;
			}
		}
	} else if (odluka==2) {
		d=(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci));
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		for (int i=0; i<d.size(); i++) {
			for (int j=0; j<d.at(i).size(); j++) {
				std::cout<<d.at(i).at(j)<<" ";
				if (j==d.at(i).size()-1) std::cout<<std::endl;
			}
		}
	}


	return 0;
}
