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


int RastaviNaProsteFaktore(int n){
	int b, br_prostih(0);
	int k=n%2;
	while(k==0){
		b=n/2;
		n=b;
		k=n%2;
		br_prostih++;
	}
	
	for(int j=3; j<=n; j+=2){
		int k=n%j;
		while(k==0){
			b=n/j;
			n=b;
			k=n%j;
			br_prostih++;
		}
	}
	
return br_prostih;	
}




template <typename Tip1, typename Tip2, typename Tip3>

void SortirajPodrucjeVrijednosti(Tip1 p1, Tip1 p2,     Tip2 p3,      Tip3 p4,   decltype p4[0] f(decltype p1[0] x, decltype p1[0] y){return -2*x+y;},         bool Kriterij (decltype p1[0] a, decltype p1[0] b) {
	if(RastaviNaProsteFaktore(a)>RastaviNaProsteFaktore(b)) return true;
	else return false;
}){
	std::sort(p1, p2, Kriterij);
	std::sort(p3, p3+p1, Kriterij);
	
	
	
	
}

int main ()
{
	return 0;
}