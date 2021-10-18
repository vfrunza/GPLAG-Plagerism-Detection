#include <iostream>
#include <vector>
#include <cmath>
std::vector<int> IzbaciIste(std::vector<int> v){
	
	for(int i(0);i < int(v.size())-1;i++){

		for(int j(i+1);j < v.size();j++){
			if(v[i] == v[j]){
				 v.erase(v.begin()+j);
				j--;
			}
		}
	}
	
	return v;
	
}
bool opaki(std::vector<int> v){
	if(!v.size()) return 0;
	for(int i(0);i < v.size();i++){
		int broj_pon(0);
		for(int j(0);j < v.size();j++){
			if(v[i] == v[j]) broj_pon++;
		}
		if(broj_pon % 2 != 0) return false;
	}
	
	return true;	
}
bool odvratni(std::vector<int> v){
	for(int i(0);i < v.size();i++){
		int broj_pon(0);
		for(int j(0);j < v.size();j++){
			if(v[i] == v[j]) broj_pon++;	
		}
		if(broj_pon % 2 == 0) return false;
	}
	return true;
}
std::vector<int> UTernarni(long long int x){
	if(x < 0) x*=-1;
	std::vector<int> v;
 	int i(pow(3,int(log(x)/log(3))));
	while(i){
	v.push_back(x/i);
	x-=(x/i)*i;
	i/=3;
	}
	
return v;	
}
std::vector<int> IzdvojiGadne(std::vector<int> v,bool gad){
	std::vector<int> a;
	if(gad){
		for(int x : v){
			auto v(UTernarni(x));
			if(opaki(v)){
				a.push_back(x);
			}
		}
	}else{
			for(int x : v){
			auto v(UTernarni(x));
			if(odvratni(v)){
				a.push_back(x);
			}
		}
	}
	return IzbaciIste(a);
}
int main ()
{
std::vector<int> v;
int x;
std::cout << "Unesite brojeve (0 za prekid unosa): ";
for(;;){
	
	std::cin >> x;
	if(x) v.push_back(x);
	if(!x) break;
	
	
}
auto v1(IzdvojiGadne(v,1));
auto v2(IzdvojiGadne(v,0));
std::cout << "Opaki: ";
for(auto x : v1) std::cout << x << " ";
std::cout << "\nOdvratni: ";
for(auto x : v2) std::cout << x << " ";
	return 0;
}