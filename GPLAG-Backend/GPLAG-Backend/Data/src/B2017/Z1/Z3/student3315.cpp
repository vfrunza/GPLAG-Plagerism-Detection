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
#include <math.h>
bool stependvojke(int a){
	for(int i=0;i<16;i++){
		if(pow(2,i)==a) return true;
	}
	return false;
}
enum Smjer{Rastuci=1, Opadajuci=2};
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s){
	std::deque<std::vector<int>> zavrsni;
	if(s==Smjer::Rastuci){
		zavrsni.resize(1);
		int brojac(1);
		for(int i=0;i<v.size();i++){
			if(stependvojke(v.at(i))){
				if(i==v.size()-1){
					zavrsni.at(brojac-1).push_back(v.at(i));
					break;
				}
				if(v.at(i)<v.at(i+1)) zavrsni.at(brojac-1).push_back(v.at(i));
				else{
					zavrsni.at(brojac-1).push_back(v.at(i));
					zavrsni.resize(++brojac);
					continue;
				}
			}else{
					zavrsni.resize(++brojac);
					continue;
				}
		}
	}
	
	
	if(s==Smjer::Opadajuci){
		zavrsni.resize(1);
		int brojac(1);
		for(int i=0;i<v.size();i++){
			if(stependvojke(v.at(i))){
				if(i==v.size()-1){
					zavrsni.at(brojac-1).push_back(v.at(i));
					break;
				}
				if(v.at(i)>v.at(i+1)) zavrsni.at(brojac-1).push_back(v.at(i));
				else{
					zavrsni.at(brojac-1).push_back(v.at(i));
					zavrsni.resize(++brojac);
					continue;
				}
			}else{
					zavrsni.resize(++brojac);
					continue;
				}
		}
	}
	
	
	
	for(int i=0;i<zavrsni.size();i++){
		if(zavrsni.at(i).size()==1){ zavrsni.erase(zavrsni.begin()+i);i--;}
	}
	return zavrsni;
}


int main (){
	std::vector<int> v;
	std::deque<std::vector<int>> dek;
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	v.resize(n);
	for(int i=0;i<n;i++) std::cin>>v.at(i);
	int unos;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>unos;
	if(unos==1){
		std::cout<<"Maksimalni rastuci podnizovi: \n";
		dek=MaksimalniPodnizoviStepenaDvojke(v,Smjer::Rastuci);
		for(int i=0;i<dek.size();i++){
			for(int j=0;j<dek[i].size();j++)
				std::cout<<dek.at(i).at(j)<<" ";
			std::cout<<std::endl;
			
		}
	}
	if(unos==2){
		std::cout<<"Maksimalni opadajuci podnizovi: \n";
		dek=MaksimalniPodnizoviStepenaDvojke(v,Smjer::Opadajuci);
		for(int i=0;i<dek.size();i++){
			for(int j=0;j<dek[i].size();j++)
				std::cout<<dek.at(i).at(j)<<" ";
			std::cout<<std::endl;
			
		}
	}
	return 0;
}