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

bool Prosti (int a, bool b){
	if(b){if(a==1) return false;}
	else {if(a==1) return true;}
	if(a==0)return false;
	a=std::abs(a);
	for(int i=2;i<=std::sqrt(a);i++){
		if(a%i==0) return false;
	}
	return true;
}

bool Simetricni(int x){
	x=std::abs(x);
	std::vector<int> v;
	while(x!=0){
		int y=x/3;
		int z=x-3*y;
		x=y;
		v.push_back(z);
	}
	for(int i=0;i<v.size();i++){
		if(v.at(i)!=v.at(v.size()-1-i)) return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> a, bool b){
	if(b)   for(int i=0;i<a.size();i++){
			if(!Prosti(a.at(i),b)) {a.erase(a.begin()+i);i--;} 
		}
	else for(int i=0;i<a.size();i++){
		if(Prosti(a.at(i),b))  {a.erase(a.begin()+i);i--;} 
	}
	for(int i=0;i<a.size();i++){
		if(!Simetricni(a.at(i))) {a.erase(a.begin()+i);i--;} 
	}
	if(a.size()!=0){for(int i=0;i<a.size()-1;i++){
		for(int j=i+1;j<a.size();j++){
			if(a[i]==a[j]){
				a.erase(a.begin()+j);
				j--;
			}
		
	}
	}
	}
	
 return a;	
}

int main ()
{
	std::vector<int> a;
	int x,y;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::cin>>x;
	while(x!=-1){ a.push_back(x); std::cin>>x;}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>y;
	while(y!=0 && y!=1){
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>y;
		}
	a=IzdvojiSimetricneTernarne(a,y);
	if(a.size()==0 && y){std::cout<<"Nema prostih simetricnih brojeva u vektoru.";return 0;}
	if(a.size()==0 && !y){std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";return 0;}
	if(y){
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0;i<a.size();i++){
			if(i!=a.size()-1)std::cout<<a.at(i)<<", ";
			else std::cout<<a.at(i)<<".";
		}
	}
		else{
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<a.size();i++){
			if(i!=a.size()-1)std::cout<<a.at(i)<<", ";
			else std::cout<<a.at(i)<<".";
		}
	}
	return 0;
}