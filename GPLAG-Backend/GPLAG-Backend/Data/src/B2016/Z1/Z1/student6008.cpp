#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<int> vec;

vec IzdvojiGadne(vec v, bool tacno){
	int d, brojac0(0), brojac1(0), brojac2(0);
	vec v1, v2, pomocni;
	for(int i=0; i<v.size(); i++){
		d=v[i];
		if(d<0)
			d=abs(d);
		while(d!=0){
			pomocni.push_back(d%3);
			d/=3;
		}
		
		for(int j=0; j<pomocni.size(); j++){
			if(pomocni[j]==0)
				brojac0++;
			else if(pomocni[j]==1)
				brojac1++;
			else brojac2++;
		}
		if((brojac0%2==0 || brojac0==0) && (brojac1%2==0 || brojac1==0) && (brojac2==0 || brojac2%2==0))
			v1.push_back(v[i]);
		else if((brojac0%2!=0 && brojac1%2!=0 && brojac2%2!=0) || (brojac0==0 && brojac1%2!=0 && brojac2%2!=0) || (brojac0%2!=0 && brojac1==0 && brojac2%2!=0) || (brojac0%2!=0 && brojac1%2!=0 && brojac2==0) ||(brojac0==0 && brojac1==0 && brojac2%2!=0)||(brojac0==0 && brojac1%2!=0 && brojac2==0)||(brojac0%2!=0 && brojac1==0 && brojac2==0))
			v2.push_back(v[i]);
		brojac0=0;
		brojac1=0;
		brojac2=0;
		pomocni.erase(pomocni.begin(), pomocni.begin()+pomocni.size());
		
		
	}
	if(v1.size()>1){
		for(int i=0; i<v1.size()-1; i++){
			for(int j=i+1; j<v1.size(); j++){
				if(v1[i]==v1[j]){
					v1.erase(v1.begin()+j);
					j--;
				}
			}
		}
	}
	if(v2.size()>1){
		for(int i=0; i<v2.size()-1; i++){
			for(int j=i+1; j<v2.size(); j++){
				if(v2[i]==v2[j]){
					v2.erase(v2.begin()+j);
					j--;
				}
			}
		}
	}
	if(tacno==true)
		return v1;
	return v2;
	
}


int main ()
{
	vec v, a, b;
	int j;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		std::cin>>j;
		if(j==0)
			break;
		v.push_back(j);
	}
	a=IzdvojiGadne(v,true);
	b=IzdvojiGadne(v,false);
	std::cout<<"Opaki: ";
	for(int i=0; i<a.size(); i++){
		std::cout<<a[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i=0; i<b.size(); i++){
		std::cout<<b[i]<<" ";
	}
	
	
	return 0;
}