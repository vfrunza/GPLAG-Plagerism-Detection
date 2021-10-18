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
#include<vector>
#include<cmath>

bool JeLIProstBroj(int n){

	if(n==0)
	return false;
	
	if(n==1)
	return false;
	
	if(n<0) n*=-1;
	
	for(int i=2;i<=std::sqrt(n);i++){
		if(n%i==0)
		return false;
	}
	return true;
}

long long int PretvoriUTernarniBroj(int n){
	
	long long int c(0);
	long long int cifra;
	long long int i{1};
	
	if(n<0){
		n*=-1;
	}
		
	do{
		cifra=n%3;
		c=c+i*cifra;
		i=i*10;
		n/=3;
	}
	while(n!=0);

	return c;
}

bool JeLiSimetrican(long long int n){
	long long int c(n);
	long long int novi_broj(0);
	do{
		int cifra(n%10);
		novi_broj=novi_broj*10+cifra;
		n/=10;
	}
	while(n!=0);
	
	if(novi_broj==c)
	return true;
	
	return false;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool p){
	std::vector<int> novi_vektor;
	if(v.size()==0)
	return novi_vektor;
	
	
	for(int i=0;i<v.size();i++){
		int c(v.at(i));
		if(p){
			if(JeLIProstBroj(v.at(i))){
				bool ima_vec(false);
				for(int k: novi_vektor){
					if(v.at(i)==k){
					ima_vec=true;
					break;
					}
				}
				if(ima_vec==false){
				long long int ternarni_broj(PretvoriUTernarniBroj(v.at(i)));
				if(JeLiSimetrican(ternarni_broj)){
				novi_vektor.push_back(c);
			}
				}
			}
			else continue;
		}
		
		else {
			if(!(JeLIProstBroj(v.at(i)))){
				bool ima_vec(false);
				for(int k:novi_vektor){
					if(v.at(i)==k){
					ima_vec=true;
					break;
				}
				}
				if(ima_vec==false){
				long long int ternarni_broj(PretvoriUTernarniBroj(v.at(i)));
				if(JeLiSimetrican(ternarni_broj))
				novi_vektor.push_back(c);
			}
			}
		
			else continue;
		}
	}
	return novi_vektor;
}

				
				

int main ()
{
	std::vector<int> v, pomocni;
	int element;
	
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	for(;;){
		std::cin>>element;
		if(element==-1) break;
		else
		v.push_back(element);
	}
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int p;
	std::cin>>p;
	while(!(p==0 || p==1)){
		std::cout<<"Neispravan unos! ";
		std::cout<<"Unesite ponovo: ";
		std::cin.clear();
		std::cin>>p;
	}

	
	
	pomocni=IzdvojiSimetricneTernarne(v,p);
	
	if(p==1){
		if(pomocni.size()==0)
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else{
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0;i<pomocni.size();i++){
			if(i==pomocni.size()-1)
			std::cout<<pomocni.at(i)<<".";
			else
			std::cout<<pomocni.at(i)<<", ";
		}
	}
	}
	else if(p==0){
		if(pomocni.size()==0)
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else{
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<pomocni.size();i++){
			if(i==pomocni.size()-1)
			std::cout<<pomocni.at(i)<<".";
			else
			std::cout<<pomocni.at(i)<<", ";
		}
		}
		
	}

	
	

		
	return 0;
}