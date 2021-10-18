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
#include <iomanip>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool uzmi){
	int brojaci[3]={0};
	std::vector<int> vrati;
	for(int i=0; i<v.size(); i++){
		int stavi=v[i];
			v[i]=abs(v[i]);
		while(v[i]>0){
			int pom=v[i]%3;
			brojaci[pom]++;
			v[i]=v[i]/3;
		}
		if(uzmi==true) {
		for(int j=0; j<3; j++){
			if(brojaci[j]%2!=0 && brojaci[j]!=0) break;//dodala j
			if(j==2) {
				if(vrati.size()==0) vrati.push_back(stavi);
				for(int z=0; z<vrati.size();z++){
					if(stavi==vrati[z]) break;
					if(z==vrati.size()-1) vrati.push_back(stavi);
				}
			
			}
			}
		}
			else if(uzmi==false){
			for(int j=0; j<3; j++){
			if(brojaci[j]%2==0 && brojaci[j]!=0) break;
				if(j==2) {
				if(vrati.size()==0) vrati.push_back(stavi);
				for(int z=0; z<vrati.size();z++){
					if(stavi==vrati[z]) break;
					if(z==vrati.size()-1) vrati.push_back(stavi);
				}
			
			}
			}
			}
			for(int j=0; j<3; j++) brojaci[j]=0;
		
		}
		return vrati;
	}
	


int main ()
{
	std::vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int x;
	while(1==1){
		std::cin>>x;
		if(x==0) break;
		v.push_back(x);
	}
	std::vector<int> k;
	k=IzdvojiGadne(v,true);
	std::cout<<"Opaki: ";
	for(int i=0; i<k.size(); i++) std::cout<<k[i]<<" ";
	std::cout<<"\n";
	k=IzdvojiGadne(v,false);
	std::cout<<"Odvratni: ";
	for(int i=0; i<k.size(); i++) std::cout<<k[i]<<" ";
	return 0;
}