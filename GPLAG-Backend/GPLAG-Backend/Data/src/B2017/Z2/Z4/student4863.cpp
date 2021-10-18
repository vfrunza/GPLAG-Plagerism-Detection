/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <cmath>
#include <functional>

template<typename t1, typename t2>
t2 f(t1 a, t1 b){
	return -2*a+b;
}

template<typename a>
bool DaLiJeProst(a n){
	if(n<0) return false;
	bool prost(true);
	if(n==1){
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

template<typename tt1>
bool f1(tt1 a, tt1 b){
	int brojaca(0) ,brojacb(0), brojaca1, brojacb1;
	if(DaLiJeProst(a)){
	brojaca=1;
	goto kraj;
	}
    while(a!=2 || a!=3){
    	if(a%2==0){
    	brojaca++;
    	a/=2;
    	if(DaLiJeProst(a)){
    	brojaca++;
    	goto kraj;
    	}
    	}
    	
    	if(a%3==0){
    	brojaca++;
    	a/=3;
    	if(DaLiJeProst(a)){
    	brojaca++;
    	goto kraj;
    	}
    	}
    	
    }
    
    if(DaLiJeProst(b)){
	brojacb=1;
	goto kraj1;
	}
    while(b!=2 || b!=3){
    	if(b%2==0){
    	brojacb++;
    	b/=2;
    	if(DaLiJeProst(b)){
    	brojacb++;
    	goto kraj1;
    	}
    	}
    	
    	if(b%3==0){
    	brojacb++;
    	b/=3;
    	if(DaLiJeProst(b)){
    	brojacb++;
    	goto kraj1;
    	}
    	}
    	
    }
	kraj: brojaca1=brojaca;
	kraj1: brojacb1=brojacb;
	if(brojaca1==brojacb1) return a>b;
	return brojaca1>brojacb1;
}


template<typename tip1, typename tip2, typename tip3>
void SortirajPodrucjeVrijednosti(tip1 p1, tip1 p2, tip2 p3, tip3 p4, tip3 f(tip1 a, tip1 b), bool f1(tip1 c, tip1 d)){
	int n=p2-p1;
	std::sort(p1, p2, f1);
	std::sort(p3, p3+n, f1);
	int *p5=p4;
	try{
		while(p1!=p2){
			int k=f(*p1, *p3);
			p1++;
			p3++;
				if(!std::binary_search(p4, p4+n, k)) throw;
				else{
					*p5=k;
					p5++;
		}
	}
}
catch(...){
	std::cout<<"Vrijednost koja odgovara nekom  od parova nije nađena";
}
}


int main ()
{
	int n;
	std::cout << "Unesite broj elemenata: " << std::endl;
	std::cin>>n;
	std::vector<int> v1, v2, v3;
	std::cout << "Unesite elemete prvog vektora: " << std::endl;
	pocetak: for(int i=0; i<n; i++){
		int clan;
		std::cin>>clan;
		for(int x:v1){
			if(clan==x){
				i--;
				break;
			}else v1.push_back(clan);
		}
	}
	std::cout << "Unesite elemente drugog vektora: " << std::endl;
	for(int i=0; i<n; i++){
		int clan; 
		std::cin>>clan;
		
		v2.push_back(clan);
	}
	std::cout << "Unesite elemente treceg vektora: " << std::endl;
	for(int i=0; i<n; i++){
		int clan;
		std::cin >> clan;
		v3.push_back(clan);
	}
	SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), f, f1);
	return 0;
}