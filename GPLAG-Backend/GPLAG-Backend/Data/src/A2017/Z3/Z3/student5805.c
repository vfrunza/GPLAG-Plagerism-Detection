#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int izbaciCire(int broj, int cifra) {
	int noviBroj=0, k=0, j;
	int mnozac,negativan;
	if(broj<0) negativan=-1;
	else negativan=1;
	while(broj!=0) {
		if(abs(broj%10)==cifra) {
			broj/=10;
			continue;
		}
		if(broj%10<0) mnozac=(-1)*broj%10;
		else mnozac=broj%10;
		for(j=0; j<k; j++) mnozac*=10;
		noviBroj+=mnozac;
		k++;
		broj/=10;
	}
	return noviBroj*negativan;
}
int izbaci_cifre(int* niz, int velNiza, int* cifre, int velCifre) {
	int i=0,j=0,trenbroj;
	for(i=0; i<velCifre-1; i++) {
		for(j=i+1; j<velCifre; j++) {
			if(cifre[i]==cifre[j]) return 0;
			if(cifre[j]<0 || cifre[j]>9) return 0;
		}
		if(cifre[i]<0 || cifre[i]>9) return 0;
	}
	for(i=0; i<velNiza; i++) {
		trenbroj=niz[i];
		for(j=0; j<velCifre; j++) {
			trenbroj=izbaciCire(trenbroj,cifre[j]);
		}
	niz[i]=trenbroj;
}
return 1;
}
int main() {

	return 0;
}
