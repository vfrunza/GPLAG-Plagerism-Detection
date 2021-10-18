/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>


std::vector<int> IzdvojiGadne (std::vector<int> v,bool b){
	

	std::vector <int> y;
		
    for(int i=0;i<v.size();i++){  //pretvaramo u ternarni oblik i provjeravamo koliko puta se pojavi 1,0,2
		int b0=0,b1=0,b2=0;
		int broj=abs(v[i]);
	while(broj!=0){
	int ostatak=broj%3;
		if(ostatak==0) b0++;
		else if(ostatak==1) b1++; 
		else if(ostatak==2) b2++;
		broj=broj/3;
}
	if(b){  //opaki
		if(b0%2==0 && b1%2==0 && b2%2==0 )
		y.push_back(v[i]);
	
	}
    if(!b){ //odvratni
			 
			if((b0%2==1 || b0==0) && (b1%2==1 || b1==0) && (b2%2==1 || b2==0) )
			y.push_back(v[i]);
		}}
		
	if(y.size()==1 || y.size()==0) return y;
		for(int i=0;i<y.size();i++){
		for(int j=i+1;j<y.size();j++){
			if(y.at(i)==y.at(j)){
				for(int k=j;k<y.size()-1;k++){
					y.at(k)=y.at(k+1);
				}
				y.resize(y.size()-1);
				j--;
			}
		}
		}
				
			
		
	return y;
}
int main ()
{
	
	std::cout <<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> a;
	int elementi;
		std::cin >>elementi;
	
	while(elementi!=0){
		a.push_back(elementi);
		std::cin >>elementi;}
		/*
	}
	for (int i=0;i<a.size();i++){

		a.push_back(elementi); 
					std::cin >>elementi;
	
	}*/
	auto b=IzdvojiGadne(a,1); //b su opaki 
	auto c=IzdvojiGadne(a,0); //c su odvratni
	
	std::cout <<"Opaki: ";
	for(int x: b) std::cout <<x<<" ";
	/*
	for(int i=0;i<a.size();i++){
		std::cout <<a[i]<<" ";
	}*/


	std::cout <<std::endl<<"Odvratni: ";
	for(int x: c)std::cout <<x<<" ";
	
	
	/*
	for(int j=0;j<a.size();j++){
		std::cout << a[j]<<" ";
	}
	*/
		return 0;
}