/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>

template <typename NekiTip1, typename NekiTip2, typename NekiTip>
NekiTip** UvrnutiPresjek(NekiTip1 pocetak_prvog, NekiTip1 iza_kraja_prvog, NekiTip2 pocetak_drugog, NekiTip2 iza_kraja_drugog, NekiTip f(NekiTip)){
	NekiTip1 pom1(pocetak_prvog);
	NekiTip2 pom2(pocetak_drugog);
	int vel1(iza_kraja_prvog-pocetak_prvog), vel2(iza_kraja_drugog-pocetak_drugog);
	for(int i=0; i<vel1; i++){
		for(int j=0; j<vel2; j++){
			if(f(pom1+i)==f(pom2+j)){
				
			}
		}
	}
}
int main ()
{
	return 0;
}