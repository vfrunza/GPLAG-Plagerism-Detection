/*B 2017/2018, Zadaća 1, Zadatak 2
	
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

enum Smjer{Rastuci=true,Opadajuce=false};

bool StepenDvojke (int broj){
	bool p=false;
	for(int i(1);i<=broj;i*=2){
		if(broj==i) p=true
	}
	return p;
}
std::deque<std::vector<int>> MaksimalniPodnizStepenaDvojke (std::vector<int> v,Smjer m){
	std::deque<std::vector<int>> rezultat;
	std::vector<int> pomocni;
	
	for(int i{0};i<v.size();i++){
		if(i==0 && StepenDvojke(v[0])==true) pomocni.push_back(v[0]); 
		while(StepenDvojke(v[i])==true && v[i]>v[i-1]) pomocni.push_back(v[i]);
		rezultat.push_back(pomocni);
		
	

}


int main ()
{
	return 0;
}