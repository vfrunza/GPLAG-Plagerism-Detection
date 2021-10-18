#include <iostream>
#include <cmath>
#include <vector>

bool prostx(int x)
{
	bool prost(true);
	for(int i=2; i<=sqrt(x); i++) {
		if(x%i==0) prost=false;
	}
	if(x==2) prost=true;
	return prost;
}

long long ternarni(int x)
{
	long long ter(0);
	int i(1), ostatak;
	while(x!=0) {
		ostatak=x%3;
		x/=3;
		ter+=ostatak*i;
		i*=10;
	}
	return ter;
}

bool simetrican(long long x)
{
	long long y=abs(x), obrnuti(0);
	int ostatak;
	while(y!=0) {
		ostatak=y%10;
		obrnuti=obrnuti*10+ostatak;
		y/=10;
	}
	if(obrnuti==abs(x)) return true;
	return false;
}

void IzbaciDuple(std::vector<int> &v){
	for(int i=0; i<v.size()-1; i++){
		for(int j=i+1; j<v.size(); j++){
			if(v.at(i)==v.at(j)){ 
				v.erase(v.begin()+j);
			j--;	
			}
		}
	}
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool a)
{
	long long t;
	std::vector<int> w;
	IzbaciDuple(v);
	if(a==true) {
		for(int i=0; i<v.size(); i++) {
			if(v.at(i)==0 || v.at(i)==1) continue;
			if(prostx(v.at(i))) {
				t=ternarni(v.at(i));
				if(simetrican(t)) w.push_back(v.at(i));
			}
		}
	} else {
		for(int j=0; j<v.size(); j++) {
			if(!prostx(v.at(j))) {
				t=ternarni(v.at(j));
				if(simetrican(t)) w.push_back(v.at(j));
			}
		}
	}
	return w;
}

int main ()
{
	int x,a;
	std::vector<int> v,w;
	std::cout<<"Unesite elemente vektora (-1 za kraj): Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin>>x;
		if(x==-1) break;
		v.push_back(x);
	} while(x!=-1);
	std::cin>>a;
	if(a!=0 && a!=1) {
		while(a!=0 && a!=1) {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin>>a;
		}
	}
	w=IzdvojiSimetricneTernarne(v,a);
	if(w.size()==0 && a==1) {
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	} else if(w.size()==0 && a==0) {
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	} else {
		if(a==1) {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<w.size(); i++) {
				if(i!=w.size()-1) {
					std::cout<<w.at(i)<<", ";
				} else std::cout<<w.at(i)<<".";
			}
		} else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<w.size(); i++) {
				if(i!=w.size()-1) {
					std::cout<<w.at(i)<<", ";
				} else std::cout<<w.at(i)<<".";
			}
		}
	}
	return 0;
}