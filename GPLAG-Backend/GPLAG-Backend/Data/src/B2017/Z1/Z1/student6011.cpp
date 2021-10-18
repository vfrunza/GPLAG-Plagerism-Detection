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
#include <iomanip>
#include <vector>

bool DaLiJeProst(int n){
	if(n==0) return false;
	int br=0;
	for(int i=2; i<n; i++){
		if(n%i==0) br++;
	}
	return br==0;
}

bool DaLiJeSimetrican(int n){
	std::vector<int> niz;
	if(n<0) n*=-1;
	while(n!=0){
		niz.push_back(n%3);
		n/=3;
	}
	int i(niz.size()-1);
	for(int j=0; j<niz.size()/2; j++){
		if(niz.at(i)!=niz.at(j)) return false;
		i--;
	}
	return true;
}

int BrojPuta(int n, std::vector<int> v){
    int broj = 0;
    for(int i=0; i<v.size(); i++){
        if(n==v.at(i)) broj++;
    }
    return broj;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool a){
	std::vector<int> novi_v;
	if(a){
		for(int i=0; i<v.size(); i++){
		if(v.at(i)==1) continue;
		if(DaLiJeProst(v.at(i)) && BrojPuta(v.at(i), novi_v)==0 && DaLiJeSimetrican(v.at(i))) {
			novi_v.push_back(v.at(i));
		}
		}
	}
	
	else{
		for(int i=0; i<v.size(); i++){
		if(v.at(i)==1) continue;
		if(!DaLiJeProst(v.at(i)) && BrojPuta(v.at(i), novi_v)==0 && DaLiJeSimetrican(v.at(i))) {
			novi_v.push_back(v.at(i));
		}
		}
	}
	
	return novi_v;
}
int main ()
{
	int n(0);
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	while(n!=-1){
		std::cin>>n;
		if(n!=-1) v.push_back(n);
	}
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	bool a;
	int a1(-1);
	while(a1!=1 && a1!=0){
		std::cin>>a1;
		if(a1==1 || a1==0) a=a1;
		else std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	std::vector<int> novi(IzdvojiSimetricneTernarne(v,a));
	if(a) {
		if(novi.size()==0)	std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	}
	else {
		if(novi.size()==0)	std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	}
	for(int i=0; i<novi.size(); i++){
		if(i!=novi.size()-1)std::cout<<novi.at(i)<<", ";
		else std::cout<<novi.at(i)<<".";
	}
	return 0;
}