#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int suma_cifara(int clan){
	int suma=0,br=0;
	clan=fabs(clan);
	if(clan<10)
		return clan;
	while(clan>0){
		br=clan%10;
		suma+=br;
		clan=clan/10;
	}
	return suma;
}
void ubaci(int *niz, int vel){
	int i;
	int *pok,*q,*zadnji;
	pok=niz+vel-1;
	zadnji=niz+2*vel-2;
	for(i=0; i<vel; i++){
		*zadnji=*pok;
		zadnji-=2;
		pok--;
	}
	pok=niz;
	q=niz;
	for(i=0; i<2*vel; i++){
		q=pok-1;
		if(i%2!=0)
			*pok=suma_cifara(*q);
		pok++;
	}
}
int izbaci(int *niz, int vel){
	int i,j,br1,fib,max;
	int *pok,*q,*snimi;
	pok=niz;
	max=*niz;
	pok=niz;
	/*Trazimo najveci clan niza*/ 
	for(i=0; i<vel; i++){
		if(*pok>max)
			max=*pok;
		pok++;
	}
	pok=niz;
	br1=1;
	fib=1;
	/*Iz niza izbacujemo clanove koji se pojavljuju u Fibonacijevom nizu*/ 
	while(fib<=max){
		pok=niz;
		for(i=0; i<vel; i++){
			q=pok;
			snimi=pok;
			if(*pok==fib){
				for(j=i; j<(vel-1); j++){
					pok++;
					*q=*pok;
					q++;
				}
				pok=snimi;
				pok--;
				vel--;
				i--;
			}
			pok++;
		}
		fib=br1+fib;
		br1=fib-br1;
	}
	return vel;
}
int main() {
	int DUZINA=10,i,vel;
	int niz[20];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<DUZINA; i++){
		scanf("%d",&niz[i]);
	}
	ubaci(niz,DUZINA);
	vel=izbaci(niz,2*DUZINA);
	printf("Modificirani niz glasi:");
	for(i=0; i<vel; i++){
		if(i==(vel-1)) 
			printf(" %d.",niz[i]);
		else
			printf(" %d,",niz[i]);
	}
	return 0;
}
