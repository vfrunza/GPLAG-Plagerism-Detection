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

std::vector<int> IzdvojiGadne(std::vector<int>v, bool b){
	std::vector<int>gadni;
	std::vector<bool>parnost;
	
	for(int i : v){
		std::vector<int>coun(3,0);
		bool counter_true(false), counter_false(false);
		int konv=i;
		while(konv/3!=0){
			coun.at(abs(konv%3))++;
			konv/=3;
		}
		coun.at(abs(konv))++;
		
		for(int j=0; j<coun.size(); j++){
			if(coun.at(j)>0){
				if(coun.at(j)%2==0){
					parnost.push_back(true);
					counter_true=true;
				}else{
					parnost.push_back(false);
					counter_false=true;
				}
			}
		}
		int vec_unutra(false);
		for(int k=0; k<gadni.size(); k++){
			if(gadni.at(k)==i){vec_unutra=true; break;}
		}
		
		if(b && !vec_unutra && counter_true && !counter_false)
			gadni.push_back(i);
		else if (!b && !vec_unutra && counter_false && !counter_true)
			gadni.push_back(i);
	}
	return gadni;
}

int main (){
	int num;
	std::vector<int>a;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::cin>>num;
	while(num){
		a.push_back(num);
		std::cin>>num;
	}
	std::cout<<"Opaki: ";
	std::vector<int>b=IzdvojiGadne(a, true);
	for(int i=0; i<b.size(); i++){
		std::cout<<b.at(i)<<" ";
	}
	std::cout<<std::endl;
	b.resize(0);
	
	std::cout<<"Odvratni: ";
	b=IzdvojiGadne(a, false);
	for(int i=0; i<b.size(); i++){
		std::cout<<b.at(i)<<" ";
	}
	
	return 0;
}