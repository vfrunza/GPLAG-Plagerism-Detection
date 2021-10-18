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
std::vector<int> IzdvojiGadne(std::vector<int> VektorBrojeva, bool Opake){
	std::vector<int> VektorGadnih;
	int ParNepar(1-Opake);
	for(auto x: VektorBrojeva){
		std::vector<int> VektorCifara(3,0);
		int y(x);
		do{
			VektorCifara.at(abs(y%3))++;
			y/=3;
		}while(y!=0);
		for(int i=0;i<VektorCifara.size();i++) if(VektorCifara[i]==0) VektorCifara[i]=ParNepar;
		if(VektorCifara.at(0)%2==ParNepar && VektorCifara.at(1)%2==ParNepar && VektorCifara.at(2)%2==ParNepar){
			bool vecPostoji(false);
			for(auto n: VektorGadnih) if(n==x){
				vecPostoji=true;
				break;
			}
			if(!vecPostoji) VektorGadnih.push_back(x);
		}
	}
	return VektorGadnih;
}

int main()
{
	std::vector<int> VektorBrojeva;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int x;
	while(std::cin>>x , x!=0) VektorBrojeva.push_back(x);
	std::vector<int> VektorOpakih(IzdvojiGadne(VektorBrojeva, true));
	std::vector<int> VektorOdvratnih(IzdvojiGadne(VektorBrojeva, false));
	std::cout<<"Opaki: ";
	for(auto x: VektorOpakih) std::cout<<x<<" ";
	std::cout<<"\nOdvratni: ";
	for(auto x: VektorOdvratnih) std::cout<<x<<" ";
	return 0;
}


