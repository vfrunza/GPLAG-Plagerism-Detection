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

enum Smjer{Rastuci=1,Opadajuci};

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer a) {
	std::deque<std::vector<int>> dek;
	if(a==Rastuci) {
		int k(-1);
		bool novi(true);
		for(int i=0; i<v.size(); i++) {
			if(novi) {
			if(v.at(i)>0 && std::log2(v.at(i))==int(std::log2(v.at(i))) && i!=v.size()-1) {
				if(v.at(i+1)>0 && std::log2(v.at(i+1))==int(std::log2(v.at(i+1)))) {
						if(v.at(i)<=v.at(i+1)) {
							k++;
							dek.resize(k+1);
							dek.at(k).push_back(v.at(i));
							novi=false;
						}
			}
			}
			}
			
		else {
			if(v.at(i)>0 && std::log2(v.at(i))==int(std::log2(v.at(i)))) {
			if(v.at(i)>=v.at(i-1) && v.at(i-1)>0 && std::log2(v.at(i-1))==int(std::log2(v.at(i-1)))) dek.at(k).push_back(v.at(i));
			if(i!=v.size()-1) {
				if(!(v.at(i+1)>0 && std::log2(v.at(i+1))==int(std::log2(v.at(i+1))) && v.at(i)<=v.at(i+1))) {
					novi=true;
				}
			}
			
		}
		}
	}

}

else {
	int k(-1);
	bool novi(true);
	for(int i=0; i<v.size(); i++) {
		if(novi) {
			if(v.at(i)>0 && std::log2(v.at(i))==int(std::log2(v.at(i))) && i!=v.size()-1) {
				if(v.at(i+1)>0 && std::log2(v.at(i+1))==int(std::log2(v.at(i+1)))) {
					if(v.at(i)>=v.at(i+1)) {
						k++;
						dek.resize(k+1);
						dek.at(k).push_back(v.at(i));
						novi=false;
					}
				}
			}
		}
		else {
			if(v.at(i)>0 && std::log2(v.at(i))==int(std::log2(v.at(i)))) {
				if(v.at(i)<=v.at(i-1) && v.at(i-1)>0 && std::log2(v.at(i-1))==int(std::log2(v.at(i-1)))) dek.at(k).push_back(v.at(i));
				if(i!=v.size()-1) {
					if(!(v.at(i+1)>0 && std::log2(v.at(i+1))==std::log2(v.at(i+1)) && v.at(i)>=v.at(i+1))) {
						novi=true;
					}
				}
			}
		}
	}
}

return dek;
}


int main ()
{
	int n; 
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora: ";
	int broj;
	for(int i=0; i<n; i++) {
		std::cin>>broj;
		v.push_back(broj);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int m;
	std::cin>>m;
	std::deque<std::vector<int>> dek;
	if(m==1) {
	 dek = MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	}
	else {
		dek = MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	}
	for(int i=0; i<dek.size(); i++) {
		for(int j=0; j<dek.at(i).size(); j++) {
			std::cout<<dek.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}

	return 0;
}