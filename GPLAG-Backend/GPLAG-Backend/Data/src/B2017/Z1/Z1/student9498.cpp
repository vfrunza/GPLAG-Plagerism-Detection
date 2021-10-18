/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <deque>

std::vector<int> IzdvojiSimetricneTernarne(std::vector<double> v, int t){
	std::vector<double> vp;
	std::vector<double> vs;
	std::vector<int> vpk;
	std::vector<int> v1;
	std::vector<int> v2;
	int prost=1;
	int i,j;
	int suma1;
	 double n, n1, s, suma=0;
	 int suma21;
	 int temp;
	for(i=1;i<v.size();i++){
		for(j=2;j<v[i];j++){
			if((int)(v[i])%j == 0) {
		prost=0;
		break;
		}
	}
	if(j==v[i]){
		vp.push_back(v[i]);
		}
	else{
		vs.push_back(v[i]);
	}

}
for(int i=0;i<vp.size();i++){
	do{
		v[i]=v[i]/3;
		n1=v[i]-(int)(v[i]);
		n1=n1*3;
		s=(int)(n1+0.001);
		suma=suma*10+s;
		suma1=(int)(suma);
	} while(v[i]>=1);
	v1.push_back(suma1);
	suma=0;
}


	
if(t==1){
	return v1;
}

	
}

int main() {
	int broj, m=3;
	bool t;
	std::cout<<"Unesite ele mente vektora (-1 za kraj): ";
	std::vector<double> v;
	std::vector<int> vk;
	do{
		std::cin >> broj;
		if(broj!=-1){
			v.push_back(broj);
		}
	}
	while(broj!=-1);
	std::cout <<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve:";
	std::cin >> t;
	vk=IzdvojiSimetricneTernarne(v,t);
	for(int i=0; i<vk.size(); i++){
		std::cout << vk[i] <<" ";
	}
	

	
	return 0;
}


