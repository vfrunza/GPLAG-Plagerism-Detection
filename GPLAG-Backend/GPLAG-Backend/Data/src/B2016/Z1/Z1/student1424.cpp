/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

std::vector<int>IzvojiGadne(std::vector<int> x){
	for(int z:x){
		int z1,pamtilo;
		while(z1!=0){
			z1=z/3;
			pamtilo=z-(z1*3);
			x.push_back(pamtilo);
		}
	}
	return x;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	
	std::vector<int>a;
	std::cout<<"Unesite brojeve: ";
	for(int i=0;i<n;i++){
		int broj;
		std::cin>>broj;
		a.push_back(broj);
	}
	std::vector<int>b=IzvojiGadne(a);
	for(int i : b){
		std::cout<<"Elementi su: "<<i<<",";
	}
	return 0;
}