#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

int maxstepen(int broj){
	int brojac(0);
	while(broj!=0){
		broj=broj/3;
		if(broj==0)
			return brojac;
		brojac++;
	}
	return brojac;
}
std::vector<int> IzbaciIste(std::vector<int> v){
	for(int i(0);i<v.size()-1;i++){
		for(int j(i+1);j<v.size();j++){
		if(v[i]==v[j]){
			v.erase(v.begin()+j);
			j--;
		}
		}
	}
	return v;
}

std::vector<int> IzdvojiGadne(std::vector<int> v,bool L){
	int broj,stepen,x,a;
	int brojac0(0),brojac1(0),brojac2(0);
	std::vector<int> odvratni,opaki;
	v=IzbaciIste(v);
	for(int i(0);i<v.size();i++){
		brojac0=0;
		brojac1=0;
		brojac2=0;
		broj=v[i];
		stepen=maxstepen(broj);
		if(broj<0){
			x=broj/int(std::pow(3,stepen));
			if(x==-1) brojac1++;
			if(x==0) brojac0++;
			if(x==-2) brojac2++;
			a=broj-int(std::pow(3,stepen))*x;
			stepen--;
			broj=std::abs(a);
			}

		while(stepen!=-1){
			x=broj/int(std::pow(3,stepen));
			if(x==1) brojac1++;
			if(x==0) brojac0++;
			if(x==2) brojac2++;
			a=broj-int(std::pow(3,stepen))*x;
			stepen--;
			broj=a;
		}
	if((brojac0%2==0||brojac0==0)&&(brojac1==0||brojac1%2==0)&&(brojac2==0||brojac2%2==0))
			opaki.push_back(v[i]);
		else if((brojac0==0||brojac0%2!=0)&&(brojac1==0||brojac1%2!=0)&&(brojac2==0||brojac2%2!=0))
			odvratni.push_back(v[i]);
	}
	if(L==true)
		return opaki;
	return odvratni;
}
int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v,v1,v2;
	int x;
	do{
		std::cin>>x;
		if(x==0)
			break;
		v.push_back(x);
	}while(x!=0);
	std::cout<<"Opaki: ";
	v1=IzdvojiGadne(v,true);
	for(int i(0);i<v1.size();i++)
		std::cout<<v1[i]<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	v2=IzdvojiGadne(v,false);
	for(int i(0);i<v2.size();i++)
		std::cout<<v2[i]<<" ";
	return 0;
}