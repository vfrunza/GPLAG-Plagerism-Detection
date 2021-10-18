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

bool prost(int a){
	if(a==0 || a==1) return false;
	for(int i(2);i<=std::sqrt(a);i++) if(a%i==0) return false;
	return true;
}

int brojcifara(int a){
	int brojac=0;
    while(a!=0){
    	brojac++;
    	a/=10;
    }
    return brojac;
}
bool simetrican(int a){ 
	int kopija=a; 
	int obrnuti=0;
	int brojic=1;
    for(int i(1);i<brojcifara(a);i++) brojic*=10; 
	while(a!=0){ 
		obrnuti=obrnuti+((a%10)*brojic); 
		brojic/=10; 
		a/=10; 
	}
	if(obrnuti==kopija) return true;
	return false;
}

int ternarni(int a){
	int ter=0;
	int brojic=1;
	//for(int i(0);i<brojcifara(a);i++) brojic*=10;
	while(a!=0){
		ter+=(a%3)*brojic;
		brojic*=10;
		a/=3;
	}
	return ter;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool dane){
	std::vector<int> novi;
	for(int i(0);i<v.size();i++){
		if(dane==true && prost(v.at(i))==true && simetrican(ternarni(v.at(i)))==true) novi.push_back(v.at(i));
		if(dane==false && prost(v.at(i))==false && simetrican(ternarni(v.at(i)))==true) novi.push_back(v.at(i));
	}
	
	for(int i(0);i<int(novi.size())-1;i++){
		for(int j(i+1);j>novi.size();j++){
			if(novi.at(j)==novi.at(i)) novi.erase(v.begin()+j);
		}
	}
	
	return novi;
}

int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	std::vector<int> novi;
	int x;
	for(;;){
		std::cin>>x;
		if(x==-1) break;
		v.push_back(x);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int p;
	for(;;){
		std::cin>>p;
		if(p!=0 && p!=1) std::cout<<"Neispravan unos! Unesite ponovo: ";
		else break;
	}
	if(p==0){ 
		try{
		novi=IzdvojiSimetricneTernarne(v,0);
		if(novi.size()==0){ std::cout<<"Nema slozenih simetricnih brojeva u vektoru."; return 0;}
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";}
		catch(...){}
	}
	else if(p==1){ 
		try{
			novi=IzdvojiSimetricneTernarne(v,1);
		if(novi.size()==0){ std::cout<<"Nema prostih simetricnih brojeva u vektoru."; return 0;}
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";}
		catch(...){}
	}
	if(novi.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	for(int i(0); i<novi.size(); i++){
		std::cout<<novi.at(i);
		if(i==int(novi.size())-1) std::cout<<".";
		else std::cout<<", ";
	}
	
	return 0;
}