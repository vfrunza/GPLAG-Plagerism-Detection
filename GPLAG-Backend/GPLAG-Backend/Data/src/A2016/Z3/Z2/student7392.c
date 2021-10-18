#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* PROVJERA DA LI JE BROJ FIBONACCIJEV */
int isFibonacci(int broj){
	int fib1=1, fib2=1, fib3=1;
	while(fib3<=broj && fib3>0){
		if(fib3==broj)return 1;
		fib1=fib2;
		fib2=fib3;
		fib3=fib1+fib2;
	}
	return 0;
}

/* UBACIVANJE SUMA CIFARA */
void ubaci(int niz[], int duzina){
	int i, temp, rezultat;
	for(i=duzina-1;i>=0;i--){
		niz[2*i]=niz[i];
		rezultat=0;
		temp=abs(niz[i]);
		while(temp){
			rezultat+=temp%10;
			temp/=10;
		}
		niz[2*i+1]=rezultat;
	}
}

/* IZBACIVANJE FIBONACCIJEVIH BROJEVA IZ NIZA */
int izbaci(int niz[], int duzina){
	int i, j;
	for(i=0;i<duzina;i++){
		if(isFibonacci(niz[i])){
			for(j=i;j<duzina-1;j++){
				niz[j]=niz[j+1];
			}
			duzina--;
			i--;
		}
	}
	return duzina;
}

int main() {
	int i, niz[20], duzina;
	/* UNOS */
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d", &niz[i]);
	}
	/* OBRADA */
	ubaci(niz, 10);
	duzina=izbaci(niz, 20);
	/* ISPIS */
	printf("Modificirani niz glasi:");
	for(i=0;i<duzina;i++){
		printf(" %d", niz[i]);
		if(i!=duzina-1)printf(","); else printf(".");
	}
	return 0;
}
