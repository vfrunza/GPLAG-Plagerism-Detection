#include<iostream>
#include<vector>
#include<cmath>
std::vector<int> IzdvojiGadne(std::vector<int> a, bool b){
	std::vector<int>rezo;
	std::vector<int>rezg; 
	std::vector<int>pom; 
	for(unsigned long int p=0; p<a.size(); p++){
	long long int broj=a[p];
	if(broj<0) broj=broj*(-1);
	if(b==1){
		if(broj==0) pom.push_back(broj); 
		else {
	while(broj!=0){
		pom.push_back(broj%3); 
		broj/=3; 
	}}
	int br=0;
	for(int i =0; i<pom.size(); i++){
		for(int j=0; j<pom.size(); j++){
			if(pom[i]==pom[j]) br++; 
		}
		if(br%2!=0) break; 
		else if(br%2==0 && i==pom.size()-1) rezo.push_back(a[p]); 
	}
	}
	else if(b==0){
		if(broj==0) pom.push_back(broj);
		else {
		while(broj!=0){
		pom.push_back(broj%3); 
		broj/=3; 
	} }
	int br=0;
	for(int i=0; i<pom.size(); i++){
		br=0;
		for(int j=0; j<pom.size(); j++){
			if(pom[i]==pom[j]) br++; 
		}
		if(br%2==0) break; 
		else if(br%2!=0  && i==pom.size()-1) rezg.push_back(a[p]); 
	}
	}
	pom.resize(0); 
	}
	if(b==1) {
	 		for(int i=0; i<rezo.size(); i++){
			for(int j=i+1; j<rezo.size(); j++){
				if(rezo[i]==rezo[j]) {rezo.erase(rezo.begin()+j); j--;}
			}
		}
		return rezo;
	} 
	else {
		for(int i=0; i<rezg.size(); i++){
			for(int j=i+1; j<rezg.size(); j++){
				if(rezg[i]==rezg[j]) {rezg.erase(rezg.begin()+j); j--;}
			}
		}
		return rezg;
	} 
}
int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): "; 
	std::vector<int> a; 
	int b; 
	for(;;){
		std::cin>>b; 
		if(b!=0)a.push_back(b); 
		else break; 
	}
	std::cout<<"Opaki: ";
	std::vector<int> c=IzdvojiGadne(a, 1);
	for(int i=0; i<c.size(); i++){
		std::cout<<c[i]<<" ";
	}
		std::cout<<"\nOdvratni: ";
	std::vector<int> d=IzdvojiGadne(a, 0);
	for(int i=0; i<d.size(); i++){
		std::cout<<d[i]<<" ";
	}
	return 0;
}