/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <cmath>
#include <vector>

int DaLiJeDjeljivo(int n){
	std::vector<int> vektor;
	if(n != 0) vektor.push_back(n);
	int brojac(0);
	if(vektor.size() == 1){
		for (int i = 0 ; i < 1 ; i++){
			for(int j = 0 ; j < 10 ; j++){
				int x = std::pow(3,j);
				if(vektor[i] % x == 0 ){
					brojac++;
					i--;
				} else continue;
			}
		}
	}
	if(brojac % 2 == 0) return true;
	else return false;
}

std::vector<int> IzdvojiGadne(std::vector<int> vektor, bool provjera){
	std::vector<int> vektoropakih;
	std::vector<int> vektorodvratnih;
	
	for(int i = 0 ; i < vektor.size(); i++){
		if(DaLiJeDjeljivo(vektor.at(i)) && provjera == true) vektoropakih.push_back(i);
		else if (DaLiJeDjeljivo(vektor.at(i)) && provjera == false) vektorodvratnih.push_back(i);
	}
	if(provjera) return vektoropakih;
	else return vektorodvratnih;
}

int main(){
	int n;
	std::vector<int> glavnivektor;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>n;
		if(n != 0)  glavnivektor.push_back(n);
	}while(n!=0);
	
	std::vector<int> vektoropakih(IzdvojiGadne(glavnivektor,true));
	std::vector<int> vektorodvratnih(IzdvojiGadne(glavnivektor,false));
	
	std::cout<<"Opaki: ";
	for(int i = 0; i < vektoropakih.size(); i++){
		if(vektoropakih.at(i) == vektoropakih.at(i+1)) vektoropakih.resize(vektoropakih.size()-1);
		std::cout<<vektoropakih.at(i)<<" ";
	}
	
	std::cout<<"\nOdvratni: ";
	for(int i = 0 ; i < vektorodvratnih.size();i++){
		if(vektorodvratnih.at(i) == vektorodvratnih.at(i+1)) vektorodvratnih.resize(vektorodvratnih.size()-1);
		std::cout<<vektorodvratnih.at(i)<<" ";
	}
	
	return 0;
}