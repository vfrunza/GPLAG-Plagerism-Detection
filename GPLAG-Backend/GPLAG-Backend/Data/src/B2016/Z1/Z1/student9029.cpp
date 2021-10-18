#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

bool ParNepar (int broj, bool vrsta){
	
	std::vector<int> ponavljanje(3,0);
	int temp=broj;	
	while(temp){
		ponavljanje[std::abs(temp%3)]++;
		temp/=3;
	}
	
	int par {}, nepar {};
	for(int x: ponavljanje){
		if(!x)continue;
		if(x%2)nepar++;	else par++;
	}
	if(broj==0) nepar++;
	
	if(!par && nepar && !vrsta) return true; 
		
	if(!nepar && par && vrsta) return true; 
	
	return false;
}

std::vector<int> IzdvojiGadne(std::vector<int> elementi, bool vrsta){
	
	std::vector<int> novi_elementi;

	for(int broj :  elementi){
		if(ParNepar(broj, vrsta))
			novi_elementi.push_back(broj);
	}
	
	for(int i=0;i<(int)novi_elementi.size();i++)
		for(int j=i+1;j<(int)novi_elementi.size();j++)
			if(novi_elementi[i]==novi_elementi[j]){
				novi_elementi.erase(novi_elementi.begin()+j);j--;}
	
	return novi_elementi;
}

int main ()
{
	std::vector<int> elementi;
	std::cout<< "Unesite brojeve (0 za prekid unosa): ";
	
	int broj;
	while(std::cin>>broj && broj!=0)
		elementi.push_back(broj);

	std::cout <<"Opaki: ";
	for(int x : IzdvojiGadne(elementi, 1)) std::cout<<x<<" ";
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int x: IzdvojiGadne(elementi, 0))std::cout<<x<<" ";
		
	return 0;
}