/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <algorithm>

bool prost(int br) {
	bool ok(true);
	for(int i = 2; i < br; i++) {
		if(br % i == 0) {
			ok = false;
			break;
		}
	}
	return ok;
}

int BrojProstihFaktora (long long int br) {
	int suma{};
	for(int i = 2; i <= br; i++) {
		if(prost(i)) {
			while(br % i == 0) {
				suma++;
				br /=i;
			}
		}
	}
	return suma;
}

int SumaDjelilaca(long long int br) {
	int suma{};
	for(int i = 1; i <= br; i++) {
		if(br % i == 0) suma+= i;
	}
	return suma;
}

bool savrsen(int br) {
	bool ok(true);
	int suma{};
	for(int i = 1; i <= br; i++) {
		if(br % i == 0) suma += i;
	}
	if(suma != br) ok = false;
	return ok;
}

int BrojSavrsenihDjelilaca (long long int br) {
	int brojac{};
	for(int i = 2; i <= br; i++) {
		if(savrsen(i) && br % i == 0) brojac++;
	}
	return brojac;
}

template <typename NekiTip1, NekiTip2, >

int main ()
{
	return 0;
}