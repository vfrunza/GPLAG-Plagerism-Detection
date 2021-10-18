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
enum Smjer{Rastuci=true, Opadajuci=false};
void IspisiFormu (std::deque<std::vector<int>>d) {
	for(auto red : d) {
		for(auto x: red) std::cout<<x<<" ";
		std::cout<<std::endl;
	}
}
bool DaLiJeStepenBroja2 (int n) {
	if(n==1) return true;
	int stepen(1);
	for(int i=0; i<n; i++) {
		stepen*=2;
		if(stepen==n) return true;
	}
	return false;
}

std::deque<std::vector<int>>RastuciPodnizovi(std::vector<int>v){
	std::deque<std::vector<int>>izlazni;
	std::vector<int>dio;
	for(int i=0; i<(v.size()-1); i++) {
		if(v.at(i+1)>v.at(i) && DaLiJeStepenBroja2(v.at(i)) && DaLiJeStepenBroja2(v.at(i+1))) {
		//	if(i==v.at(v.size()-1)) break;
			dio.push_back(v.at(i));
			
		}
		else {
			if(dio.size()>=1) {
				dio.push_back(v.at(i));
				izlazni.push_back(dio);
			}
			dio.clear();
		}
	}
	if(dio.size()>=1) {
		dio.push_back(v.at(v.size()-1));
		izlazni.push_back(dio);
	}
	return izlazni;
}

std::deque<std::vector<int>>OpadajuciPodnizovi(std::vector<int>v) {
	std::deque<std::vector<int>>izlazni;
	std::vector<int>dio;
	for(int i=0; i<(v.size()-1); i++) {
		if(v.at(i+1)<v.at(i) && DaLiJeStepenBroja2(v.at(i)) && DaLiJeStepenBroja2(v.at(i+1))) {
		//	if(i==v.at(v.size()-1)) break;
			dio.push_back(v.at(i));
		}
		else {
			if(dio.size()>=1) {
				dio.push_back(v.at(i));
				izlazni.push_back(dio);
			}
			dio.clear();
		}
	}
	if(dio.size()>=1) {
		dio.push_back(v.at(v.size()-1));
		izlazni.push_back(dio);
	}
	return izlazni;
}



std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int>v, enum Smjer a){

 	std::deque<std::vector<int>>izlaznirastuci;
 	std::deque<std::vector<int>>izlazniopadajuci;
 	izlaznirastuci=RastuciPodnizovi(v);
 	izlazniopadajuci=OpadajuciPodnizovi(v);
 	if(a) return izlaznirastuci;
 	return izlazniopadajuci;
 }

int main ()
{
	std::vector<int>v;
	int n(0);
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	int broj(0);
	for(int i=0; i<n; i++) {
		std::cin>>broj;
		v.push_back(broj);
	}
	int a;
    Smjer parametar;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>a;
	if(a==1) {
		parametar=Rastuci;
		auto d=MaksimalniPodnizoviStepenaDvojke(v, parametar);
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		IspisiFormu(d);
	}
	if(a==2) {
		parametar=Opadajuci;
		auto d=MaksimalniPodnizoviStepenaDvojke(v, parametar);
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		IspisiFormu(d);
	}
	return 0;
}