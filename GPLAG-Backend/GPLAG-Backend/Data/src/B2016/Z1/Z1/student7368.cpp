#include <iostream>
#include <vector>
#include <cmath>
int f1(long int a) {
	int br0=0, br1=0, br2=0;
	while (a!=0) {
		if (abs(a%3)==0) br0++; 
		if (abs(a%3)==1) br1++;
		if (abs(a%3)==2) br2++; 
		a=a/3; 
	}
	if (br0%2==0 && br1%2==0 && br2%2==0) return 1;
	if ((br0==0 || br0%2!=0) && (br1==0 || br1%2!=0) && (br2==0 || br2%2!=0)) return 0;
	return 2;
}

std::vector<int>IzdvojiGadne (std::vector<int>vek, bool a) {
std::vector<int>v;
if (vek.size()==0) {
	v.resize(0);
	return v;
}
	if (a==true) {
		for (int i=0; i<vek.size(); i++) {
			if (f1(vek[i])==1) 
			v.push_back(vek[i]);
		}
	}
	if (a==false) {
		for (int i=0; i<vek.size(); i++) {
			if (f1(vek[i])==0) 
			v.push_back(vek[i]);
		}}
		
		for (int i=0; i<v.size(); i++) {
			for (int j=i+1; j<v.size(); j++) {
				
				if (v[i]==v[j]) {
					for (int k=j; k<v.size()-1; k++) {
						v[k]=v[k+1];
					}
					v.resize(v.size()-1);
					i--;
					break;
				}
			}
		}
	return v;
}
int main (){
	int n;
	std::vector<int>a;
	std::vector<int>b;
	std::vector<int>c;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	while (1) {
		std::cin>>n;
		if (n==0) break;
		a.push_back(n);
	}
	b=IzdvojiGadne(a,true);
	int br=0;
	for (int i=0; i<b.size(); i++) br++;
	if (br>0) {
		std::cout<<"Opaki: ";
		for (int i=0; i<b.size(); i++) std::cout<<b[i]<<" ";
	}
		std::cout<<std::endl;
	c=IzdvojiGadne(a,false);
	int br1=0;
	for (int i=0; i<c.size(); i++) br1++;
	if (br1>0) {
		std::cout<<"Odvratni: ";
		for (int i=0; i<c.size(); i++) std::cout<<c[i]<<" ";
		std::cout<<std::endl;
	}
	return 0;
}