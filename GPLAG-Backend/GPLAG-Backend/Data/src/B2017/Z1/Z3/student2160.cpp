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

bool StepenDvojke(int n){ 
	if(n<1) return false;
	while(n>1){
     if((n%2)!=0)  return false;
	    n/=2;
	}
	return true;
}

enum Smjer{Rastuci,Opadajuci};
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s){
if(s ==Rastuci){
		std::vector<int> pomocni;
		int brojac_j{};
		std::deque<std::vector<int>> d;
	for(int i=0; i<v.size()-1; i++){
		if(StepenDvojke(v.at(i)) == true && v.at(i)<=v.at(i+1)){
			pomocni.push_back(v.at(i));
			for(int j=i+1; j<v.size(); j++){
				if(v.at(j)>=v.at(j-1) && StepenDvojke(v.at(j))){
					brojac_j++;
					pomocni.push_back(v.at(j));
				}
				else{
					break;
				}
			}
			if(pomocni.size()>1){
				d.push_back(pomocni);
				pomocni.resize(0);
				i+=(brojac_j-1);
				brojac_j=0;
			}
		}
	}
	if(d.size()==0) return d;
return d;
}
	
	if(s==Opadajuci){
		std::vector<int> pomocni;
		int brojac_j{};
		std::deque<std::vector<int>> d;
		for(int i=0; i<v.size()-1; i++){
			brojac_j=0;
			if(StepenDvojke(v.at(i))==true && v.at(i)>=v.at(i+1)){
				for(int j=i+1; j<v.size(); j++){
					if(StepenDvojke(v.at(j))==true && v.at(j)<=v.at(j-1)){
						if(pomocni.size()==0) {
							pomocni.push_back(v.at(i));
							pomocni.push_back(v.at(j));
							brojac_j++;
						}
						else {
							pomocni.push_back(v.at(j));
							brojac_j++;
						}
				}
				else {
					break;
				}
			}
			if(pomocni.size()>1){
				d.push_back(pomocni);
				pomocni.resize(0);
				i=i+brojac_j-1;
			}
		}
	}
	if(d.size()==0) return d;
	return d;
	}
}
int main ()
{

int n,x;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> v;
	for(int i=0; i<n; i++){
		std::cin>>x;
		v.push_back(x);
	}
	int m;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>m;
	
	if(m==2){
	std::cout<<"Maksimalni opadajuci podnizovi: \n";
	std::deque<std::vector<int>> rezultat1 = MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
     for(auto x : rezultat1){
			for(auto y : x)
				std::cout<<y<<" ";
				std::cout<<std::endl;
		}
				
	}  
	else {
		std::cout<<"Maksimalni rastuci podnizovi:\n";
		std::deque<std::vector<int>> rezultat2 = MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
		for( auto d : rezultat2){
			for(auto f : d) 
			std::cout<<f<<" ";
			std::cout<<std::endl;
		}
	}
	
	return 0;
}