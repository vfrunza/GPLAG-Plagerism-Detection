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
#include <cmath>
#include <algorithm>
#include <vector>




bool Prost(int a){
	for(int i=2;i<=std::sqrt(a);i++){
		if(a%i==0)return false;
	}
	return true;
}

int BrojProstih(int n){
	int br{0};
	if(Prost(n)) return 1;
	for(int i=2;i<=n;i++){
		if(!Prost(i)) continue;
		if(n%i==0){
			while(n!=1&&n%i==0){
				br++;
				n=n/i;
				std::cout<<n<<" "<<br<<" ";
			}
		}
	}
	return br;

}

bool Sortiraj(int a, int b){
	return BrojProstih(a)>BrojProstih(b);
}


int main ()
{

	return 0;
}