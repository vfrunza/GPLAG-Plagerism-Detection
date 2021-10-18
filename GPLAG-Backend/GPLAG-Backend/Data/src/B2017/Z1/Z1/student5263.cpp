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
bool DaLiJeProst(long long int n){
	if(n ==2) return true;
	if(n<2) return false;
	bool prost=true;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0) prost=false;
	}
	return prost;
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v1, bool korekt){
	std::vector<int> novi;
	long long int k(0), broj(0), novibroj(0);
	std::vector<long long int> v;
	if(v1.size()==0) return novi;
	for(unsigned int i=0; i<v1.size()-1; i++){
		for(unsigned int j=i+1; j<v1.size(); j++){
			if(v1.at(i)==v1.at(j)){
				v1.erase(v1.begin()+j);
				j--;
			} 
		}
		
	}

//	for(int i=0; i<v1.size(); i++) std::cout<<v1.at(i)<<" ";
	for(unsigned int i=0; i<v1.size(); i++){
		if(v1.at(i) < 0) broj=-v1.at(i);
		else broj=v1.at(i);
		if(broj == 0 || broj==1) continue;
		if(korekt==true && DaLiJeProst(broj)) v.push_back(v1.at(i));
		if(korekt == false && DaLiJeProst(broj)==0) v.push_back(v1.at(i));
	}
	if(v.size()==1){
		for(int i=0; i<v.size(); i++) novi.push_back(v.at(i));
		return novi;
	}
	for(int i=0; i<v.size(); i++){
		broj=0;
		novibroj=0;
		if(v.at(i) < 0) k=-v.at(i);
		else k=v.at(i);
		long long int j(1);
		while(k!=0){
			int c=k%3;
			broj+=j*c;
			k=k/3;
			j*=10;
		}
		long long int m=broj;
		while(m!=0){
			int c=m%10;
			novibroj=novibroj*10+c;
			m=m/10;
		}
		if(broj == novibroj) novi.push_back(v.at(i));
	}
	return novi;
}
int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	while(1){
		int i(0);
		std::cin>>i;
		if(i==-1) break;
		v.push_back(i);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int n;
	do{
		std::cin>>n;
		if(n!=0 && n!=1){
			std::cout<<"Neispravan unos! Unesite ponovo: ";
		}
	}while (n!=0 && n!=1);
	auto v1=IzdvojiSimetricneTernarne(v,n);
	if(v1.size()==0 && n==1) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	if(v1.size()==0 && n==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	if(v1.size()!=0 && n==1){
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<v1.size(); i++){
			if(i!=v1.size()-1) std::cout<<v1.at(i)<<", ";
			else std::cout<<v1.at(i)<<"."<<std::endl;
		}
	}
	
	if(v1.size()!=0 && n==0){
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<v1.size(); i++){
			if(i!=v1.size()-1) std::cout<<v1.at(i)<<", ";
			else std::cout<<v1.at(i)<<"."<<std::endl;
		}
	}
	return 0;
}