/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <limits>
	
	std::vector<int> IzdvojiGadne(std::vector<int>v, bool ima){
		std::vector<int>opaki;
		std::vector<int>odvratni;
		if(v.size()==0)
			return odvratni;
		
			
		for(int i=0; i<v.size(); i++){
			std::vector<int>ternarni;
			int tmp(v[i]);
			v[i] = abs(v[i]);
			while(v[i] != 0){
				int temp = v[i]%3;
				ternarni.push_back(temp);
				v[i]/=3;
			}
			int brojac0(0);
			int brojac1(0);
			int brojac2(0);
			for(int j=0; j<ternarni.size(); j++){
				if(ternarni[j]==2) brojac2++;
				else if(ternarni[j]==1) brojac1++;
				else if(ternarni[j]==0) brojac0++;
			}
		
	
			if(brojac0%2 == 0 && brojac1%2 == 0 && brojac2%2 == 0) 
				opaki.push_back(tmp);

			else if((brojac0%2 != 0 || brojac0==0) && (brojac1%2 != 0 || brojac1 == 0) && (brojac2%2 != 0 || brojac2 ==0)) odvratni.push_back(tmp);
		}
		
			for(int i=0; i<opaki.size(); i++){
				for(int j=i+1; j<opaki.size(); j++){
					if(opaki[i] == opaki[j]){
						opaki.erase(opaki.begin()+j);
						j--;
					}
				}
			}
	
			for(int i=0; i<odvratni.size(); i++){
				for(int j=i+1; j<odvratni.size(); j++){
					if(odvratni[i] == odvratni[j]){
						odvratni.erase(odvratni.begin()+j);
						j--;
					}
				}
			}

		if(ima) return opaki;
		else return odvratni;
	}
	
int main (){
	int broj;
	std::cout<< "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int>v;
	while(std::cin>>broj, broj != 0)
		v.push_back(broj);
	
	auto t = IzdvojiGadne(v,true);
	std::cout<< "Opaki: ";
	for(int i=0; i<t.size(); i++){
		std::cout<<t[i]<< " ";
	}
	std::cout<<std::endl<< "Odvratni: ";
	auto f = IzdvojiGadne(v,false);
	for(int i=0; i<f.size(); i++){
		std::cout<<f[i]<< " ";
	}
	return 0;
}
