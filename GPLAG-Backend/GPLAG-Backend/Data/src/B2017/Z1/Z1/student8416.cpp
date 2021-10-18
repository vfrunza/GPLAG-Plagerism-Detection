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

int ObrniBroj(int x){
	int c;int r=0;
	do{
		c=x%10;
		x=x/10;
		r=r*10+c;
	}while(x!=0);

	return r;
}

int PretvoriUTernarni(int x){
	int c, r=0;
	while(x!=0){
	c=x%3;
	x/=3;
	r=r*10+c;
	}
	int t(0);
	while(r!=0){
	c=r%10;
	r/=10;
	t=t*10+c;
	}
	return t;
}

bool DaLiJeProst(int n){
	if(n<0) n*=-1;
	bool prost(true);
	if(n<=1){
			prost=false;
			return prost;
		}
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0){ 
		prost=false;
		return prost;
		}
	}
	return prost;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool dalijeprost){
	std::vector<int>prost;
	std::vector<int>slozen;
	std::vector<int>krajnji_prost;
	std::vector<int>krajnji_slozen;

	for(int x : v){
		if(DaLiJeProst(x)==true) prost.push_back(x); else
		slozen.push_back(x);
	}
	for(int x:prost){
		if(PretvoriUTernarni(x)==ObrniBroj(PretvoriUTernarni(x))) krajnji_prost.push_back(x);
	}
	for(int x:slozen){
		if(PretvoriUTernarni(x)==ObrniBroj(PretvoriUTernarni(x))) krajnji_slozen.push_back(x);
	}
	for(int i=0; i<krajnji_prost.size(); i++){
		for(int j=(i+1); j<krajnji_prost.size(); j++){
			if(krajnji_prost.at(i)==krajnji_prost.at(j)){
				krajnji_prost.erase(krajnji_prost.begin()+j);
				j--;
			}
		}
		
		for(int i=0; i<krajnji_slozen.size(); i++){
		for(int j=(i+1); j<krajnji_slozen.size(); j++){
			if(krajnji_slozen.at(i)==krajnji_slozen.at(j)){
				krajnji_slozen.erase(krajnji_slozen.begin()+j);
				j--;
			}
		}
	}
	}
	if(dalijeprost==true) return krajnji_prost; else
	return krajnji_slozen;

}


int main ()
{
	int n, m;
	bool k; 
	std::vector<int>v ;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	for(;;){
		std::cin>>n;
		if(n==1 || n==0) continue;
		if(n==-1) break;
		v.push_back(n);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(;;){
		std::cin>>m;
		if(!std::cin){
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout<<"Neispravan unos! Unesite ponovo: ";
            continue;
		}else if(m!=0 && m!=1){
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			continue;
		}if(m==0 || m==1) break;
	}
	k=m;
	std::vector<int> pomocni(IzdvojiSimetricneTernarne(v, k)) ;
	if(k==true){
		if(pomocni.size()==0){ std::cout<<"Nema prostih simetricnih brojeva u vektoru."; return 0;}
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<pomocni.size(); i++){
			std::cout<<pomocni.at(i);
			if(i!=pomocni.size()-1) std::cout <<", ";
			else std::cout <<".";
		}
	}else if(k==false){
		if(pomocni.size()==0){std::cout<<"Nema slozenih simetricnih brojeva u vektoru."; return 0;}
	std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int i=0; i<pomocni.size(); i++){
			std::cout<<pomocni.at(i);
			if(i!=pomocni.size()-1) std::cout <<", ";
			else std::cout <<".";
	}
	}
	return 0;
}