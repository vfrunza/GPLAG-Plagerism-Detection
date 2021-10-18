#include <iostream>
#include <cmath>
#include <vector>
int Ternarni(int n){
	n=std::abs(n);
	std::vector<int> brojaci(3,0);
	while(n!=0){
		brojaci[n%3]++;
		n/=3;
	}
	if(brojaci[0]%2==0 && brojaci[1]%2==0 && brojaci[2]%2==0)
		return 1;
	else if((brojaci[0]%2!=0 || brojaci[0]==0) && (brojaci[1]%2!=0 || brojaci[1]==0) && (brojaci[2]%2!=0 || brojaci[2]==0))
		return -1;
	return 0;
}
std::vector<int> IzdvojiGadne(std::vector<int> v,bool a){
	std::vector<int> vrati;
	if(a){
		for(int i=0;i<v.size();i++){
			if(Ternarni(v[i])==1)
			 	vrati.push_back(v[i]);
		}
	}
	else 
		for(int i=0;i<v.size();i++){
			if(Ternarni(v[i])==-1)
			 	vrati.push_back(v[i]);
		}
		for(int i=0;i<vrati.size();i++){
		for(int j=i+1;j<vrati.size();j++){
			if(vrati[i]==vrati[j]){
				vrati.erase(vrati.begin()+j);
				j--;
			}
		}
	}
	return vrati;
}
int main (){
	std::vector<int> a;
	int s;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>s;
		if(s!=0) a.push_back(s);
	}while(s!=0);
	std::vector<int> b=IzdvojiGadne(a,true);
	std::vector<int> c=IzdvojiGadne(a,false);
	std::cout<<"Opaki: ";
	for(int i=0;i<b.size();i++)std::cout<<b[i]<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for(int i=0;i<c.size();i++)std::cout<<c[i]<<" ";
	return 0;
}