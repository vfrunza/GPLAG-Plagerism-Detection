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
enum Smjer {Rastuci=1,Opadajuci=2} s;
bool StepenDvojke(int n)
{

	if(n==0) return false;
	while(n!=1) {
		if(n%2!=0) return false;
		n/=2;
	}
	return true;
}
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int>v,Smjer s)
{
	int ima(0),j(0);
	std::deque<std::vector<int>> d;
	std::deque<std::vector<int>> e{0};
	std::vector<int>a{1};
	if(s==1) { 
		for(int i=0; i<v.size()-1; i++) {
			if(StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1)) && v.at(i)<=v.at(i+1)) { 
				if(ima==0) {
					d.push_back(a);
					d.at(j).at(0)=v.at(i);
				}
				d.at(j).push_back(v.at(i+1));
				ima=1;
			} else if(ima==1) {
				j++;
				ima=0;
			}
		}
		return d;
	}
	if(s==2) {
		for(int i=0; i<v.size()-1; i++) {
			if(StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1)) && v.at(i)>=v.at(i+1)) {
				if(ima==0) {
					d.push_back(a);
					d.at(j).at(0)=v.at(i);
				}
				d.at(j).push_back(v.at(i+1));
				ima=1;
			} else if(ima==1) {
				j++;
				ima=0;
			}
		}
		return d;
	}
	return e;
}


int main ()
{
	int n,a;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int>v;
	for(int i=0; i<n; i++) {
		int broj;
		std::cin>>broj;
		v.push_back(broj);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>a;
	for(;;) {
		if(a==1 || a==2) break;
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	if(a==1) s=Rastuci;
	if(a==2) s=Opadajuci;
	std::deque<std::vector<int>> podnizovi= MaksimalniPodnizoviStepenaDvojke(v,s);
	if(podnizovi.size()==0 && s==Rastuci) {
		std::cout<<"Nema rastucih podnizova.";
		return 0;
	}
	if(podnizovi.size()==0 && s==Opadajuci) {
		std::cout<<"Nema opadajucih podnizova.";
		return 0;
	}
	if(s==Rastuci) {
		std::cout<<"Maksimalni rastuci podnizovi: ";
		for(int i=0; i<podnizovi.size(); i++) {
			std::cout<<std::endl;
			for(int j=0; j<podnizovi.at(i).size(); j++) {
				std::cout<<podnizovi.at(i).at(j)<<" ";
			}
		}
		return 1;
	} else if(s==Opadajuci) {
		std::cout<<"Maksimalni opadajuci podnizovi: ";
		for(int i=0; i<podnizovi.size(); i++) {
			std::cout<<std::endl;
			for(int j=0; j<podnizovi.at(i).size(); j++) {
				std::cout<<podnizovi.at(i).at(j)<<" ";
			}
		}
		return 2;
	}
	return 0;
}