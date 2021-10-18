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
#include <iomanip>

enum Smjer{Rastuci,Opadajuci};

bool StepenDvojke(int n){
	if(n==1) return true;
	for(int i=2; i<=n; i*=2){
		if(n==i) return true;
	}
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer smjer){
	std::deque<std::vector<int>> dek;
	if(smjer == Rastuci){
		int temp = v.at(0);
		std::vector<int> v_pomocni;
	
		for(int i=1; i<v.size(); i++){
			if(temp<=v.at(i) && StepenDvojke(temp)) v_pomocni.push_back(temp);
			else{
				if(StepenDvojke(temp)) v_pomocni.push_back(temp);
				if(v_pomocni.size()>1) dek.push_back(v_pomocni);
				v_pomocni.clear();
				
			}
			temp = v.at(i);
		}
	}
	
	else {
		int temp = v.at(0);
		
		std::vector<int> v_pomocni;
		
		for(int i=1; i<v.size(); i++){
	
			if((temp >= v.at(i)) && StepenDvojke(temp)) v_pomocni.push_back(temp);
			else{
				if(StepenDvojke(temp)) v_pomocni.push_back(temp);
				if(v_pomocni.size()>1) dek.push_back(v_pomocni);
				v_pomocni.clear();
				
			}
			
			temp = v.at(i);
		}
	}
	
	return dek;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		int broj;
		std::cin>>broj;
		v.push_back(broj);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int a;
	std::cin>>a;
	if(a==1){
		std::cout<<"Maksimalni rastuci podnizovi: ";
		std::cout<<std::endl;
		std::deque<std::vector<int>> dek(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
		for(int i=0; i<dek.size(); i++){
			for(int j=0; j<dek.at(i).size(); j++)
			std::cout<<dek.at(i).at(j)<<" ";
			std::cout<<std::endl;
		}
	}
	
	else if(a==2){
		std::cout<<"Maksimalni opadajuci podnizovi: ";
		std::cout<<std::endl;
		std::deque<std::vector<int>> dek(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci));
		for(int i=0; i<dek.size(); i++){
			for(int j=0; j<dek.at(i).size(); j++)
			std::cout<<dek.at(i).at(j)<<" ";
			std::cout<<std::endl;
		}
	}
	
	return 0;
}