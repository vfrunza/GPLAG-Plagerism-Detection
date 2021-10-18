#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> Pretvori(int n){
	long long tmp{n};
	if(tmp<0) tmp*=-1;
	std::vector<int> v;
	if(tmp==0) v.push_back(tmp);
	while (tmp!=0){
		int cifra=tmp%3;
		tmp/=3;
		v.push_back(cifra);
	}
    return v;
}
bool Provjeri (std::vector<int> v,bool statreba){
	std::vector<int> brojac(3,0);
    for(int i=0;i< v.size();i++) brojac[v[i]]++;
	if(brojac[0]%2==0&&brojac[1]%2==0&&brojac[2]%2==0&&statreba) return true;
	if((brojac[0]%2==1||brojac[0]==0)&&(brojac[1]%2==1||brojac[1]==0)&&(brojac[2]%2==1||brojac[2]==0)&&!statreba) return true;
	return false;
}
std::vector<int> IzdvojiGadne(std::vector<int> v, bool bla){
	std::vector<int>v2;
	for(int i=0;i<v.size();i++){
		bool bio{false};
		for(int j=0; j<i;j++){
			if(v[i]==v[j]) bio=true;
		}
		if(!bio){
			std::vector<int>broj=Pretvori(v[i]);
			if(Provjeri(broj,bla)) v2.push_back(v[i]);
		}
	}
	return v2;
}


int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	for(;;){
		int a;
		std::cin>>a;
	
		if(a==0) break;
		v.push_back(a);
		
	}
	std::vector<int> v2,v3;
	v2=IzdvojiGadne(v,true);
	v3=IzdvojiGadne(v,false);
	std::cout<<"Opaki: ";
	for(int i=0;i<v2.size();i++) std::cout<<v2[i]<<" "; 
	std::cout<<std::endl<<"Odvratni: ";
	for(int i=0;i<v3.size();i++) std::cout<<v3[i]<<" ";
	return 0;
}