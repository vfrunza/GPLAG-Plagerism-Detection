/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <cmath>
#include <vector>

bool ImaLiClana(std::vector<int> v1, std::vector<int> v2, int a){
	bool da_li_ga_ima(false);
		for(int i=0;i<v1.size();i++){
			if(v1[i]==a)return true;
		}
		for(int i=0;i<v2.size();i++){
			if(v2[i]==a)return true;
		}
	return da_li_ga_ima;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool lo){
	std::vector<int> opaki;
	std::vector<int> odvratni;
	int broj, brojac, cifra;
	bool paran, neparan;
	std::vector<int> tern;
	
	for(int i=0;i<v.size();i++){
		tern.resize(0);
		broj=v[i];
		while(broj!=0){
			cifra=abs(broj%3);
			tern.push_back(cifra);
			broj/=3;
		}

		paran=false;
		neparan=false;
		for(int j=0;j<tern.size();j++){
			brojac=0;
			for(int k=0;k<tern.size();k++){
				if(tern[j]==tern[k])brojac++;
			}
		if(j==0){if(brojac%2==0)paran=true;
			     else neparan=true;
		}
		if((paran && brojac%2!=0) || (neparan && brojac%2==0)){
			paran=false;
			neparan=false;
			break;
			}
		}
		bool da_li_ga_ima(ImaLiClana(opaki,odvratni,v[i]));
		if(!da_li_ga_ima){
		if(paran)opaki.push_back(v[i]);
		else if(neparan)odvratni.push_back(v[i]);
		}
	}
	if(lo)return opaki;
	else return odvratni;
	
}

int main (){
	std::vector<int> v;
	std::vector<int> opaki;
	std::vector<int> odvratni;
	
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int x(1);
	while(x!=0){
		std::cin>>x;
		if(x==0 || !std::cin)break;
		v.push_back(x);
	}
	if(v.size()==0)return 0;
	opaki=IzdvojiGadne(v,true);
	odvratni=IzdvojiGadne(v,false);
	std::cout<<"Opaki: ";
	for(auto w : opaki)std::cout<<w<<" ";
	std::cout<<"\nOdvratni: ";
	for(auto w : odvratni)std::cout<<w<<" ";
	return 0;
}