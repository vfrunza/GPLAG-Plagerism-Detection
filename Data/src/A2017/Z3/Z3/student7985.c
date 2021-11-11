#include <stdio.h>

int obrni(int broj){
	int obrnuti=0;
	while(broj!=0){
		obrnuti = broj%10 + obrnuti*10;
		broj/=10;
	}
	return obrnuti;
}

void izmijeni(int* pok_na_broj, int cifra){
	int broj=*pok_na_broj;
	int temp=0;
	if(broj<0) broj=-broj;
	while(broj!=0){
		if(broj%10!=cifra) temp = broj%10 + temp*10;
		broj/=10;
	}
	if(*pok_na_broj<0) *pok_na_broj= -obrni(temp);
	else *pok_na_broj=obrni(temp);
}

int fun_brojac(int broj, int niz[], int vel){ /* koliko puta se "broj" ponavlja u nizu "niz"*/
	int i, brojac=0;
	for(i=0; i<vel; i++){
		if(broj==niz[i]) brojac++;
	}
	return brojac;
}

int izbaci_cifre(int niz[], int vel, int cifre[], int vel_c){
	int i, j;
	
	for(i=0; i<vel_c; i++){
		if(cifre[i]<0 || cifre[i]>9) return 0;
		else if(fun_brojac(cifre[i], &cifre[0], vel_c) > 1) return 0;
	}
	
	for(i=0; i<vel; i++){
		for(j=0; j<vel_c; j++){
			izmijeni(&niz[i], cifre[j]);
		}
	}
	
	return 1;	
}


int main() {
	int i;
	int niz[2]={-54321, 54321}, cifree[]={0,1,2,3,4,5,6,7,8};
	izbaci_cifre(niz, 2, cifree, 9);
	for(i=0; i<2; i++){
		printf("%d ", niz[i] );
	}
	return 0;
}
