/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne (std::vector<int> v, bool tacno){
	std::vector<int> noviv;
	int n;
	n=v.size();
	for(int i(0); i<n; i++){ int j;
		j=BrojGadan(i, tacno);
	}
}
int BrojGadan (int broj, bool gadan){
	
}
int main ()
{ 
	std::vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): "<<std::endl;
	int broj;
	while(std::cin>>broj, broj!=0) v.push_back(broj);
	
	return 0;
}