#include <iostream>
#include<cmath>
#include<iomanip>
#include<deque> 
#include<limits>
#include<stdexcept>
#include<vector>
bool prost(int a){
	if(a==1)return true;
	if(a==0)return true;
	for(int i=a-1;i>1;i--){
		if(a%i==0)return false;
	}
	return true;
}
int brprts(int a){
	int i=0;
	while(a!=0){
		if(prost(a%10))i++;
		a/=10;
	}
	return i;
}
bool fk(int a,int b){
	if(brprts(a)==brprts(b)){
		if(a>b)return true;
		return false;
	}
	if(brprts(a)>brprts(b))return false;
	return true;
}
template <typename tip,typename funtip>
void sortiraj(tip p1,int distance,funtip f){
	for(int i=0;i<distance;i++){
		for(int j=0;j<distance;j++){
			if(f(p1[i],p1[j])){
				auto temp(p1[i]);p1[i]=p1[j];p1[j]=temp;
			}
		}
		}
	}


template <typename iter ,typename drugiiter,typename ftip,typename ftip2>
void SortirajPodrucjeVrijednosti(iter p1,iter p2,iter p3, drugiiter p4,ftip f1,ftip2 f2) {
	int distance(p2-p1);
	sortiraj(p1,distance,f2);
	sortiraj(p3,distance,f2);
	bool nesto = false;
	for(int i=0;i<distance;i++){
		nesto=false;
		for(int j=0;j<distance;j++){
			if(f1(p1[i],p3[i])==p4[j])nesto=true;
		}if(nesto==false){
			throw std::logic_error {"Vrijednost koja odgovara nekom od parova nije nadjena"};
		}
	}
	
	for(int i=0;i<distance;i++){
		p4[i]=f1(p1[i],p3[i]);
	}
	
}

int suma(int a){
	int suma=0;
	while(a!=0){
		suma+=a%10;
		a/=10;
	}
	return suma;
}
bool ima(std::vector<int>v,int a){
	for(int i=0;i<v.size();i++){
		if(v[i]==a)return true;
		
	}
	return false;
}

int brcfr(int a){
	int i=0;
	while(a!=0){
		i++;a/=10;
	}
	return i;
}
bool f2(int a,int b){
	if(suma(a)==suma(b)){
		if(brcfr(a)>brcfr(b))return false;
		return true;
	}
	if(suma(a)<suma(b))return true;
	return false;
}
int f1(int a,int b){
	return a+2*b;
}
int main (){
	std::vector<int> a;
	std::vector<int>b;
	std::vector<int>c;
	int n;
	std::cout << "Unesite broj elemenata: Unesite elemente prvog vektora: Unesite elemente drugog vektora: Unesite elemente treceg vektora:" << std::endl;
	std::cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		std::cin>>temp;
		if(ima(a,temp)){i--;continue;}
		a.push_back(temp);
	}
	for(int i=0;i<n;i++){
		
		int temp;
		std::cin>>temp;
		if(ima(b,temp)){i--;continue;}
		
		b.push_back(temp);
	}
	for(int i=0;i<n;i++){
		
		int temp;
		std::cin>>temp;
	if(ima(c,temp)){i--;continue;}
		c.push_back(temp);
	}
	try {
		SortirajPodrucjeVrijednosti(a.begin(),a.end(),b.begin(),c.begin(),[](int x,int y){return -2*x+y;},fk);
	std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:" << std::endl;
	for(int i=0;i<a.size();i++){
		std::cout << "f("<<a[i]<<", "<<b[i]<<") = " <<c[i]<< std::endl;
	}
		
	}
	catch (std::logic_error er)  {
		std::cout <<"Izuzetak: " <<er.what() << std::endl;
	}
	

	return 0;
}