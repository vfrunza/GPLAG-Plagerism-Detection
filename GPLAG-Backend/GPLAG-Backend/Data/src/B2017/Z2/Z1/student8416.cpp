/*B 2017/2018, Zadaća 2, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <cmath>

bool DaLiJeProst(int n){
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

int f1(int n){
	int brojaca(0) ,brojacb(0);
	if(DaLiJeProst(n)){
	brojaca=1;
	goto kraj;
	}
    while(n!=2 || n!=3){
    	if(n%2==0){
    	brojaca++;
    	n/=2;
    	if(DaLiJeProst(n)){
    	brojaca++;
    	goto kraj;
    	}
    	}
    	
    	if(n%3==0){
    	brojaca++;
    	n/=3;
    	if(DaLiJeProst(n)){
    	brojaca++;
    	goto kraj;
    	}
    	}
    	
    }
	kraj: return brojaca;
}


int main ()
{
	std::cout << "unesi: " << std::endl;
	int n; 
	std::cin >> n;
	std::cout << f1(n) << std::endl;
	return 0;
}