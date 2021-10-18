/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

using namespace std;

vector<int>IzdvojiGadne(vector<int>v, bool m){
	std::vector<int>v1;
	
	
	if(m == true) {
		for(int i = 0; i < v.size(); i++)
		{
			bool postoji = false;
			int broj = v.at(i);
			int broj2 = v.at(i);
			std::vector<int> pomocni = {0};
			pomocni.resize(3);
			
			if(broj < 0) broj *= (-1);
			
			while(broj > 0) {
				int cifra = broj % 3;
			//	std::cout << "cifra je " << cifra << std::endl;
				pomocni.at(cifra)++;
				broj /= 3;
			}
			
			int broj_parnih = 0;
			for(int j = 0; j < pomocni.size(); j++) {
				if(pomocni.at(j) % 2 == 0) broj_parnih++;
			}
			
			for(int k = 0; k < v1.size(); k++) {
				if(broj2 == v1.at(k)) {
					postoji = true;
				
					break;
				}
			}
	
			
			if(postoji == true) continue;
	
			if(broj_parnih == pomocni.size() && postoji == false) v1.push_back(broj2);
			
		}
		
		return v1;
	}
	else if (m == false) {

		for(int i = 0; i < v.size(); i++)
		{
			
			bool postoji = false;
			int broj = v.at(i);
			int broj2 = broj;
			std::vector<int> pomocni = {0};
			pomocni.resize(3);
			
			if(broj < 0) broj *= (-1);
			
			while(broj > 0) {
				int cifra = broj % 3;
			//	std::cout << "cifra je " << cifra << std::endl;
				pomocni.at(cifra)++;
				broj /= 3;
			}
			
			int broj_neparnih = 0;
			for(int j = 0; j < pomocni.size(); j++) {
				if(pomocni.at(j) % 2 != 0 || pomocni.at(j) == 0) broj_neparnih++;
			}
			
				for(int k = 0; k < v1.size(); k++) {
				if(broj2 == v1.at(k)) {
					postoji = true;
					break;
				}
			}
			
			if(postoji == true) continue;
			if(broj_neparnih == pomocni.size() ) v1.push_back(broj2);
			
		}
		return v1;
	}
	
	return v1;
}


int main (){ 
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	vector<int>v;
	vector<int>a;
	vector<int>b;
	
	int m;
	do{
		std::cin>>m;
		if(m==0)
		break;
		else v.push_back(m);
		
	} while(m!=0);
	a=IzdvojiGadne(v,true);
	b=IzdvojiGadne(v,false);
	std::cout<<"Opaki: ";
	for(int x:a) std::cout<<x<<" ";
	std::cout<<endl;
	std::cout<<"Odvratni: ";
	for(int x:b) std::cout<<x<<" ";
	
	


	return 0;
}