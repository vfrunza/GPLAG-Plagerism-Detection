//B 2017/2018, Zadaća 1, Zadatak 1
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

bool DalijeSlozen(int n){
	if(n<0) n=abs(n);
	if(n==1 || n==0) return false;
	for(unsigned int i=2; i<n; i++){
		if(n%i==0) return true;
	}
	return false;
}

bool DalijeProst(int n){
	if(n<0) n=abs(n);
	if(n==1 || n==0) return false;
	for(unsigned int i=2; i<=std::sqrt(n); i++){
		if(n%i==0) return false;
	}
	return true;
}

bool SimetricniTernari(int br){
	std::deque<int> d,v;
	if(br<0) br=abs(br);
	int pom(br);
	while(br!=0){
		int p=br%3;
		d.push_front(p);
		br/=3;
	}
	while(pom!=0){
		int p=pom%3;
		v.push_back(p);
		pom/=3;
	}
	if(v==d) return true;
	return false;
}

void IzbaciDuplikate(std::vector<int> &v){
	for(int i=0; i<v.size(); i++){
		for(int j=i+1; j<v.size(); j++){
			if(abs(v.at(i))==abs(v.at(j))){
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
}

std::vector<int> IzdvojiSimetricneTernare(std::vector<int> v, bool uvjet){
	std::vector<int> rez;
	if(uvjet){
		for(int i=0; i<v.size(); i++){
			if(SimetricniTernari(v.at(i)) && DalijeProst(v.at(i))){
				rez.push_back(v.at(i));
			}
		}
		IzbaciDuplikate(rez);
		return rez;
	}
	else {
		for(int i=0; i<v.size(); i++){
			if(SimetricniTernari(v.at(i)) && DalijeSlozen(v.at(i))){
				rez.push_back(v.at(i));
			}
		}
		IzbaciDuplikate(rez);
		return rez;
	}
	return rez;
}

int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	while(1){
		int br;
		std::cin>>br;
		if(br==-1){
			break;
		}
		else v.push_back(br);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int uvjet;
	while(1){
		std::cin>>uvjet;
		if(uvjet==1 || uvjet==0) break;
		else {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
	
	std::vector<int> sim_ternari( IzdvojiSimetricneTernare(v,uvjet));
	if(uvjet==1){
		if(sim_ternari.size()==0){
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<sim_ternari.size(); i++){
			if(i==sim_ternari.size()-1){
				std::cout<<sim_ternari.at(i)<<".";
			}
			else std::cout<<sim_ternari.at(i)<<", ";
		}
	}
	else if(uvjet==0) {
		if(sim_ternari.size()==0){
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<sim_ternari.size(); i++){
			if(i==sim_ternari.size()-1){
				std::cout<<sim_ternari.at(i)<<".";
			}
			else std::cout<<sim_ternari.at(i)<<", ";
		}
	}

	return 0;
}