#include <iostream>
#include <vector>
#include <cmath>


int OpakiOdvratni(std::vector<int> broj){
	
	std::vector<int> cifre(3,0);
	bool paran(1), neparan(1);
	
	for(int j(0);j<broj.size();j++){
		cifre[abs(broj[j])]++;
	}
	
	for(int i(0);i<cifre.size();i++){
		if (cifre[i]==0) continue;
		
		if (cifre[i]%2==0)
		neparan=false;
		
		if(cifre[i]%2!=0)
		paran=false;
		
	}
	
	if(paran==true) return 1;
	if(neparan==true ) return 0;
	
	else return 3;
}

std::vector<int> TernarniZapis(int broj){
	std::vector<int> b;
	
	while(broj!=0){
		b.push_back(broj%3);
		broj=broj/3;
	}
	
	for(int i(0);i<b.size()/2;i++){
		
		int temp;
		temp=b[i];
		b[i]=b[b.size()-1-i];
		b[b.size()-1-i]=temp;
		
	}
	
	if(b.size()==0) 
		b.push_back(0);
	
	return b;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool l){
	std::vector<int> gadni, duplikat;
	
	for(int i(0);i<v.size();i++){
		
		int j;
		
		for(j=0;j<i;j++){
			
			if(v[i]==v[j]) break;
		}
		
		if(i!=j) continue;
		
		duplikat=TernarniZapis(v[i]);
		
		if(OpakiOdvratni(duplikat)==1 && l==true) 
			gadni.push_back(v[i]);
		
		else if(OpakiOdvratni(duplikat)==0 && l==false)
			gadni.push_back(v[i]);
	}
	
	return gadni; 
}

int main ()
{
	std::vector<int> pregadni,v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		
		int br;
		std::cin>>br;
		
		if(br==0) break;
		pregadni.push_back(br);
		
	}
	
	v=IzdvojiGadne(pregadni,1);
	std::cout<<"Opaki: ";
	
	for(int i(0);i<v.size();i++){
		std::cout<<v[i]<<" ";
	}
	
	std::cout<<std::endl;
	v=IzdvojiGadne(pregadni,0);
	
	std::cout<<"Odvratni: ";
	
	for(int j(0);j<v.size();j++){
		std::cout<<v[j]<<" ";
	}
	
	
	return 0;
}