#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

int check (int x,int d,std::vector<int> v) {
	for(int i=0;i<v.size();i++) {
		if(i==d) continue;
		else if(x==v[i]) return i;
	}
	return -4;
}

std::vector<int> izbaci_izuzetke (std::vector<int> v) {
	for(int i=0;i<v.size();i++) {
		int k=check(v[i],i,v);
		if(check(v[i],i,v)!=-4) {
			for(int j=k;j<v.size()-1;j++) {
				v[j]=v[j+1];
			}
			v.resize(v.size()-1);
			i--;
		}
	}
	return v;
}

std::vector<int> Pretvori_u_ternarni (int x) {
	int a;
	std::vector<int> v1;
	if(x==0) {
		v1.resize(1);
		v1[0]=0;
		return v1;
	}
	x=fabs(x);
	while(x!=0) {
		a=x%3;
		v1.push_back(fabs(a));
		x/=3;
	}
	return v1;
}

std::vector<int> brojaccifara (std::vector<int> v) {
	std::vector<int> brojaci(v.size(),1) ;
	for(int i=0;i<v.size();i++) {
		for(int j=0;j<v.size();j++) {
			if(i==j) continue;
			else if (v[i]==v[j]) brojaci[i]++;
		}
	}
	return brojaci;
}

bool opaki (int x) {
	std::vector<int> v=Pretvori_u_ternarni(x);
	v=brojaccifara(v);
	for(int i=0;i<v.size();i++) {
		if(v[i]%2!=0) return false;
	}
	return true ;
}

bool odvratni (int x) {
	std::vector<int>v=Pretvori_u_ternarni(x);
	v=brojaccifara(v);
	for(int i=0;i<v.size();i++) {
		if(v[i]%2==0) return false;
	}
	return true;
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool istina) {
	std::vector<int> v1,v2;
	for(int i=0;i<v.size();i++) {
		if(opaki(v[i])==true) v1.push_back(v[i]);
		else if(odvratni(v[i])==true) v2.push_back(v[i]);
		else continue;
	}
	v1=izbaci_izuzetke(v1);
	v2=izbaci_izuzetke(v2);
	if(istina==true) return v1;
	else return v2;
}

int main () {
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v ;
	while(2) {
		int k;
		std::cin >> k ;
		if(k==0) break;
		v.push_back(k);
	}
	std::vector<int> v1=IzdvojiGadne(v,true);
	std::vector<int> v2=IzdvojiGadne(v,false);
	std::cout << "Opaki: " ;
	for(int x : v1) std::cout << x << " " ;
	std::cout << std::endl << "Odvratni: ";
	for(int x : v2) std::cout << x << " " ; 
	return 0;
}