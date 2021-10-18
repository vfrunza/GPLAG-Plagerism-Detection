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

enum Smjer {Rastuci=1,Opadajuci};

bool StepenDvojke (int a){
	bool istina(true);
	if (a<=0) istina=false;
	for (int i=1; i<a; i*=2){
		if (a%i!=0) istina=false;
	}
	return istina;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, enum Smjer a){
	std::vector<int>v1;
	std::deque<std::vector<int>> v2;
	int prvi(0);
	
	for (int i=1; i<v.size(); i++){
		if (a==1){
		if (StepenDvojke(v.at(prvi)) && StepenDvojke(v.at(i)) && v.at(prvi)<=v.at(i)){
			v1.push_back(v.at(prvi));
			prvi=i;
		}
			if (!StepenDvojke(v.at(i)) || v.at(i)<v.at(prvi) || prvi==v.size()-1){
				
			if (StepenDvojke(v.at(prvi)))
				v1.push_back(v.at(prvi));
				
			if (v1.size()>1)
			v2.push_back(v1);
				v1.erase(v1.begin(),v1.end());
				prvi=i;
				
			
		} else prvi=i;
		} 
		if (a==2){
			if (StepenDvojke (v.at(prvi)) && StepenDvojke(v.at(i)) && v.at(prvi)>=v.at(i)){
				v1.push_back(v.at(prvi));
				prvi=i;
			}
			if (!StepenDvojke(v.at(i)) || v.at(i)>v.at(prvi) || prvi==v.size()-1){
				
				if (StepenDvojke(v.at(prvi)))
				v1.push_back(v.at(prvi));
				
				if (v1.size()>1)
				v2.push_back(v1);
				v1.erase(v1.begin(),v1.end());
				prvi=i;
			}
			else prvi=i;
			
		}
	}
	
return v2;
}
int main ()
{
	std::vector<int> v1;
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: " ;
	for (int i=0; i<n; i++){
		int a;
		std::cin >> a;
		v1.push_back(a);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int b;
	std::cin >> b;
	std::deque<std::vector<int>> v2;
	if (b==1){ 
		v2=MaksimalniPodnizoviStepenaDvojke(v1,Rastuci);
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	}
	if (b==2){
		v2=MaksimalniPodnizoviStepenaDvojke(v1,Opadajuci);
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	}
	for (std::vector<int> x : v2){
	for (int i : x) std::cout << i << " ";
	std::cout << std::endl;
	}
	
	return 0;
}