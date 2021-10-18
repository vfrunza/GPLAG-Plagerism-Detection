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
bool sadrziLiGa(std::vector<int> vektor, int broj){
	for(int j=0;j<vektor.size();j++)
		if(vektor[j]==broj) return true;
	return false;
}
std::vector<int> izdvojiOpake(std::vector<int> vektor){
	std::vector<int> vrati, brojaci(3),reset(3);
	for(int i=0;i<vektor.size();i++){
		if(sadrziLiGa(vrati,vektor[i])) continue;
		int broj=vektor[i];
		while(broj!=0){
			brojaci[std::abs(broj%3)]++;
			broj/=3;
		}
		if(brojaci[0]%2==0 && brojaci[1]%2==0 && brojaci[2]%2==0)
			vrati.push_back(vektor[i]);
		brojaci=reset;
	}
	return vrati;
}
std::vector<int> izdvojiOdvratne(std::vector<int> vektor){
	std::vector<int> vrati, brojaci(3),reset(3);
	for(int i=0;i<vektor.size();i++){
		if(sadrziLiGa(vrati,vektor[i])) continue;
		int broj=vektor[i];
		while (broj!=0){
			brojaci[std::abs(broj%3)]++;
			broj/=3;
		}
		if((brojaci[0]%2!=0 ||brojaci[0]==0) && (brojaci[1]%2!=0 || brojaci[1]==0) && (brojaci[2]%2!=0 ||brojaci[2]==0))
			vrati.push_back(vektor[i]);
		brojaci=reset;
	}
	return vrati;
}
std::vector<int> IzdvojiGadne(std::vector<int>v, bool bul){
	if(bul) return izdvojiOpake(v);
	return izdvojiOdvratne(v);
}

int main (){    
	std::vector<int> vektor;
	int broj;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(1){
		std::cin>>broj;
		if(broj==0) break;
		vektor.push_back(broj);
	}
	std::vector<int> temp(IzdvojiGadne(vektor, true));
	std::cout<<"Opaki: ";
	for(auto x: temp) std::cout<<x<<" ";
	temp=IzdvojiGadne(vektor,false);
	std::cout<<std::endl<<"Odvratni: ";
	for(auto x: temp) std::cout<<x<<" ";
	return 0;
}