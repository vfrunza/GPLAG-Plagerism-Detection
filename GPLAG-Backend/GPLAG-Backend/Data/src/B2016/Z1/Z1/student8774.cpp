#include <iostream>
#include <vector>
typedef std::vector<int> vektor;

vektor IzdvojiGadne(vektor v,bool koji){
	vektor vopak,vodvratan;
	for(int i=0;i<v.size()-1;i++){
		for(int j=i+1;j<v.size();j++)
		if(v[i]==v[j]){
			v.erase(v.begin()+j);
			j--;
		}
	}
	for(int i=0;i<v.size();i++){
		int a=v[i];
		if(a<0) a*=(-1);
		vektor br(3);
		while(a!=0){
			if(a%3==0) br[0]++;
			else if(a%3==1) br[1]++;
			else if(a%3==2) br[2]++;
			a/=3;
		}
		for(int i=0;i<br.size();i++){
			if(br[i]==0){br.erase(br.begin()+i);
			i--;}
		}
		int sumaparna(0),sumaneparna(0); 
		for (int i=0;i<br.size();i++){
			if(br[i]%2==0) sumaparna++;
			else if(br[i]%2!=0) sumaneparna++;
		}
		if(sumaparna==br.size()) vopak.push_back(v[i]);
		else if(sumaneparna==br.size()) vodvratan.push_back(v[i]);
	}
	if (koji==true) return vopak;
	else return vodvratan;
}

int main ()
{
	vektor v,v1,v2;
	int n;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>n;
		if(n!=0) v.push_back(n);
	} while(n!=0);
	
	v1=IzdvojiGadne(v,true);
	v2=IzdvojiGadne(v,false);
	if(v1.size()!=0){
		std::cout<<"Opaki: ";
		for(int i=0;i<v1.size();i++){
			std::cout<<v1[i]<<" ";
		}
		std::cout<<std::endl;
	}
	if(v2.size()!=0){
		std::cout<<"Odvratni: ";
		for(int i=0;i<v2.size();i++){
			std::cout<<v2[i]<<" ";
		}
		std::cout<<std::endl;
	}
	
	
	
	return 0;
}