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
enum Smjer{Rastuci=1, Opadajuci=2};

bool DaLiJeStepenDvojke(int n){
	std::vector<int> v{1};
	v.resize(32);
	int k(v.size());
	for(int i=1; i<k; i++){
		if(i==32) break;
		v.at(i)=2*v.at(i-1);
		if(n==v.at(i) || n==v.at(0)) return true;
	}
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v,  Smjer hakala){
	std::vector<int>druga_faza;
	std::deque<std::vector<int>> treca_faza;
	
	if(hakala==Rastuci){
	for(int i=0; i<v.size(); i++){
		if(i==v.size()-1){
		treca_faza.push_back(druga_faza);	
		 break;
		}
		if(DaLiJeStepenDvojke(v.at(i))==false || DaLiJeStepenDvojke(v.at(i+1))==false){
			if(druga_faza.size()>=2){
				 treca_faza.push_back(druga_faza);
				 druga_faza.resize(0);
			}else druga_faza.resize(0);
		continue;
		}
		if(druga_faza.size()==0)druga_faza.push_back(v.at(i));
		if(v.at(i)<=v.at(i+1)){
			druga_faza.push_back(v.at(i+1));
		}else {
			if(druga_faza.size()==1){
			druga_faza.resize(0);
			continue;
			}
			treca_faza.push_back(druga_faza);
			druga_faza.resize(0);
		}
	}
	}
	if(hakala==Opadajuci){
	for(int i=0; i<v.size(); i++){
		if(i==v.size()-1){
			treca_faza.push_back(druga_faza);
			break;
		}
		if(DaLiJeStepenDvojke(v.at(i))==false || DaLiJeStepenDvojke(v.at(i+1))==false ){
			if(druga_faza.size()>=2){
				 treca_faza.push_back(druga_faza);
				 druga_faza.resize(0);
			}else druga_faza.resize(0);
		continue;
		}
		if(druga_faza.size()==0)druga_faza.push_back(v.at(i));
		if(v.at(i)>=v.at(i+1)){
			druga_faza.push_back(v.at(i+1));
		}else {
			if(druga_faza.size()==1){
			druga_faza.resize(0);
			continue;
			}
			treca_faza.push_back(druga_faza);
			druga_faza.resize(0);
		}
	}
	}
	for(auto &x:treca_faza){
		if(x.size()<2)
		x.resize(0);
	}
	return treca_faza;
	
}


int main(){
	int hakala;
	std::vector<int>v;
	int n, clan;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		std::cin>>clan;
		v.push_back(clan);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	for(;;){
		std::cin>>hakala;
		if(!std::cin){
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout<<"Neispravan unos! Unesite ponovo: ";
            continue;
		}else if(hakala!=1 && hakala!=2){
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			continue;
		}if(hakala==1 || hakala==2) break;
	}
	if(hakala==1){
		std::deque<std::vector<int>> pomocni=std::move(MaksimalniPodnizoviStepenaDvojke(v, Rastuci));
		if(hakala==1) std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		for(std::vector<int> k:pomocni){
		for(int x:k){
			std::cout<<x<<" ";
		}
          std::cout<<""<<std::endl;
	}
	 }else if(hakala==2){
	 	std::deque<std::vector<int>> pomocni=std::move(MaksimalniPodnizoviStepenaDvojke(v, Opadajuci));
	 std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	 for(std::vector<int> k:pomocni){
		for(int x:k){
			std::cout<<x<<" ";
		}
          std::cout<<""<<std::endl;
	}
	 }
	return 0;
} 

