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
typedef std::vector<int> vektor;

bool DaLiJeProst(int n){
	if(n==0 || n==1) return false;
	if(n<0) n *= (-1);
	int t(1);
	for(int i=2 ; i<n ; i++){
		if(n%i==0) {
			t=0;
			break;
		}
	}
	if(t) return true;
	else return false;
}
bool DaLiJeSimetrican(vektor v){
	bool t(1);
	for(int i=0 ; i<v.size()/2 ; i++){
		if(v.at(i)!=v.at(v.size()-i-1)) 
		t=0;
	}
	if(t) return true;
	else return false;
}
vektor IzbaciElement(vektor v){
	for( int i=0 ; i<v.size() ; i++){
		for( int j=i+1 ; j<v.size() ; j++){
			if(v.at(i)==v.at(j)){
				v.erase(v.begin()+j);
			
				j--;
			} 
		}
	}
	return v;
}
vektor IzdvojiSimetricneTernarne (vektor v, bool n){
	vektor a,b;
	
	for(int x : v){
		int s(x);
		vektor t;
		if(s<0) s *= (-1);
		
		while(s!=0){
				t.push_back(s%3);
				s=s/3;
		}
		if(DaLiJeProst(x) && DaLiJeSimetrican(t)) a.push_back(x);
		if(!(DaLiJeProst(x)) && DaLiJeSimetrican(t)) b.push_back(x);
	}
	
	
	
	
	if(n==true) return IzbaciElement(a);
	else return IzbaciElement(b);
	
}
int main ()
{
	vektor v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int x;
	do{
		std::cin>>x;
		if(x!=(-1)) v.push_back(x);
	}while(x!=(-1));
	int n;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for( ; ; ){
	
	std::cin>>n;
	if(n==1 || n==0) break;
	 if(n!=0 || n!=1) std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	
	
	vektor v1=IzdvojiSimetricneTernarne(v,n);
	if(n) {
		if(v1.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0 ; i<v1.size() ; i++){
				if(i==v1.size()-1) std::cout<<v1.at(i)<<".";
				else std::cout<<v1.at(i)<<", ";
				
			}
		}
	}
	
	if(!n){
		if(v1.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0 ; i<v1.size() ; i++){
				if(i==v1.size()-1) std::cout<<v1.at(i)<<".";
				else std::cout<<v1.at(i)<<", ";
				
			}
		}
	}
	return 0;
}