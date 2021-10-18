#include <stdio.h>
#include <stdlib.h>
/*Funkcija "fibo" koja provjerava da li je neki član niza Fibonaccijev pri čemu
u funkciju "izbaci" šalje istinitosnu vrijednost 0 ili 1 u zavisnosti je li član
Fibonnacijev ili nije*/
int fibo(int n) {
	int a=1, b, c=1;
	if(n==1) return 1;
	for(;;) {
		b=a+c;
		if(n==b) return 1;
		if(b>n) break;
		a=c;
		c=b;
	}
	return 0;
}
/*Funkcija "ubaci" koja proširuje niz tako da ostavi prostor za nove članove
niza koji će biti suma cifara svojih prethodnika i ubacuje te sume kao nove člnaove niza*/
void ubaci(int *niz, int n) {
	int i, x, suma=0, num;
	for(i=n-1; i>=0; i--) {
		*(niz+2*i)=*(niz+i);
	}
	for(i=0; i<2*n; i++) {
		if(i%2==1) {
			x=*(niz+i-1);
			while(x!=0) {
				num=x%10;
				suma=suma+num;
				x=x/10;
			}
			suma=abs(suma);
			*(niz+i)=suma;
			suma=0;
		}
	}
	
}

/*Funkcija izbaci koja izbacuje članove Fibonaccijevog niza, a koristi pomoćnu
funkciju "fibo" koja ispistuje koji članovi niza su Fibonaccijevi*/
int izbaci(int *niz, int n) {
	int i, j;
	for(i=0; i<n; i++) {
		if(fibo(niz[i])) {
			for(j=i; j<n-1; j++) {
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
	}
	return n;
}

int main() {
	/*Dužina niza se uzima 20 zbog proširivanja niza u funkcijama*/
	int niz[20], i, n=0;
	/*Unos članova niza pri čemu se koristi i brojač n jer funkcije moraju raditi
	za proizvoljan broj članova, a ne samo za 10*/
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d", &niz[i]);
		n++;
	}
	ubaci(niz, n);
	n=izbaci(niz, 2*n);
	/*Ispis niza*/
	printf("Modificirani niz glasi: ");
	if(n==0) {
		printf("Prazan niz.");
		return 0;
	}
	for(i=0; i<n-1; i++) {
		printf("%d, ", niz[i]);
	}
	printf("%d.", niz[n-1]);
	return 0;
}
