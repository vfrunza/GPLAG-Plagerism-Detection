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


enum Smjer {Rastuci,Opadajuci};

bool DaLiJeStpenDvojke (int n){
	if (n<0) return false;
	if (n==1 || n==2) return true;
	for(int k(2);k<15;k++){
		if (pow(2,k)==n) return true;
	}
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer x){
	std::deque<std::vector<int>> a,r;
	std::vector<int> b,c,k;
	bool w;
	
	for (int j(0);j<v.size();j++){
		w=DaLiJeStpenDvojke(v.at(j));
		if (!w && k.size()!=0) {
			r.push_back(k);
			k.resize(0);
		}
		else if (w)
			k.push_back(v.at(j));
		if(j==v.size()-1 && k.size()!=0){
			r.push_back(k);
		}
	} 
	
	if (x==Smjer::Rastuci){
		for(auto b:r){
			for (int i(0);i<b.size()-1;i++){
				if(c.size()==0)c.push_back(b.at(i));
				if (b.at(i)<=b.at(i+1) || (i==b.size()-1 && b.at(i-1)<b.at(i)))
					c.push_back(b.at(i+1));
				else {
					if (c.size()!=1) {
						a.push_back(c);
						c.resize(0);
					}
					else{
						c.resize(0);
					}
				}
				if(i==b.size()-2 && (c.size()!=0 || c.size() !=1)) {
					a.push_back(c);
					c.resize(0);
				}
			}
		}
	}
	else{
		for(auto b:r){
			for (int i(0);i<b.size()-1;i++){
				if (c.size()==0) c.push_back(b.at(i));
				if (b.at(i)>=b.at(i+1) || (i==b.size()-1 && b.at(i-1)>b.at(i))) 
					c.push_back(b.at(i+1));
				else {
					if (c.size()!=1) {
						a.push_back(c);
						c.resize(0);
					}
					else{
						c.resize(0);
					}
				}
				if(i==b.size()-2 && (c.size()!=0 || c.size()!=1)) {
					a.push_back(c);
					c.resize(0);
				}
			}
		}
	}
	return a;	
}

int main ()
{
	int a,b,k;
	std::vector<int> v;
	std::deque<std::vector<int>> xx;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> a;
	std::cout << "Unesite elemente vektora: ";
	for(int i(0);i<a;i++){
		std::cin >> b;
		v.push_back(b);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> k;

	if (k==1){
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		 std::deque<std::vector<int>> xx=MaksimalniPodnizoviStepenaDvojke(v,Smjer::Rastuci);
		 for (auto l:xx){
			for (int i(0);i<l.size();i++){
				std::cout << l.at(i) << " ";
			}
		std::cout << std::endl;
		}
	}
	
	else{
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		 std::deque<std::vector<int>> xx=MaksimalniPodnizoviStepenaDvojke(v,Smjer::Opadajuci);
		 for (auto l:xx){
			for (int i(0);i<l.size();i++){
				std::cout << l.at(i) << " ";
			}
			std::cout << std::endl;
		}
	}
	
	return 0;
}