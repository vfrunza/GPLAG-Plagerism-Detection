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
typedef std::deque<std::vector<int>> Matrica;
enum Smjer {Rastuci=1, Opadajuci=2};
bool stepen_dvojke(int v)
{
	return  v && !(v & (v-1));
}
Matrica MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer smjer)
{	
	Matrica podnizovi;
	if(v.size()<2) return podnizovi;
	if(smjer==Rastuci) {
		for(int i=0; i<v.size()-1; i++) {
			if(!(v.at(i)<=v.at(i+1) && stepen_dvojke(v.at(i)) && stepen_dvojke(v.at(i+1)))) continue;
			std::vector<int> podniz;
			
			while(v.at(i)<=v.at(i+1) && stepen_dvojke(v.at(i)) && stepen_dvojke(v.at(i+1))) {
				podniz.push_back(v.at(i));
				i++;
				if(i==v.size()-1) break;
			}
			
			if(i==v.size()-1 || v.at(i)>=v.at(i-1))
				podniz.push_back(v.at(i));
			if(podniz.size()>1)
				podnizovi.push_back(podniz);
			
		}
	} else{
		for(int i=0; i<v.size()-1; i++) {
			if(!(v.at(i)>=v.at(i+1) && stepen_dvojke(v.at(i)) && stepen_dvojke(v.at(i+1)))) continue;
			std::vector<int> podniz;
			
			while(v.at(i)>=v.at(i+1) && stepen_dvojke(v.at(i)) && stepen_dvojke(v.at(i+1))) {
				podniz.push_back(v.at(i));
				i++;
				if(i==v.size()-1) break;
			}
			if(i==v.size()-1 || v.at(i)<=v.at(i-1)) {
				podniz.push_back(v.at(i));
			
			}
			if(podniz.size()>1)
				podnizovi.push_back(podniz);
			
		}
	}
	
	return podnizovi;

}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> v;
	for(int i=0; i<n; i++) {
		int k;
		std::cin>>k;
		v.push_back(k);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int k;
	
	std::cin>>k;
	
	if((Smjer)k==Rastuci) {
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		auto rastuci(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
		for(auto i : rastuci) {
			for(auto j : i)
				std::cout<<j<<" ";
			std::cout<<std::endl;
		}

	}else if((Smjer)k==Opadajuci || !k) {
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		auto opadajuci(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci));
		for(auto i : opadajuci) {
			for(auto j : i)
				std::cout<<j<<" ";
			std::cout<<std::endl;
		}

	}
	
	
	return 0;
}