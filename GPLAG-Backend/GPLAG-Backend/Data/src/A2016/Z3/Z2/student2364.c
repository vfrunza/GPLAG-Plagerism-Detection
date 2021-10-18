#include <stdio.h>
#include <stdlib.h>

int main() {
	
	/* Prototipi funkcija koje cemo koristiti u programu */
	
	void ubaci(int *niz, int n);
	int izbaci(int *niz, int n);
	
	int niz[20]={0}, i, n=10;

	printf("Unesite niz od 10 brojeva: ");
	
	for(i=0; i<n; i++){
	    scanf("%d", &niz[i]);
	}
	ubaci(niz, n);
	n = izbaci(niz, 2*n);
	
	printf("Modificirani niz glasi: ");
	for(i=0; i<n; i++){
		if(i==n-1)
		printf("%d.", niz[i]);
else
	printf("%d, ", niz[i]);
	}
return 0;
}

void ubaci (int *niz, int n){
	int Suma(int broj);
	int i,s=2,prvi[10],drugi[20],parni;
	
	/* Prebacivanje clanova originalnog niza u nizove koje koristimo samo u funkciji ubaci */
	
	for(i=0; i<n; i++){
		prvi[i]= niz[i];
		drugi[i]=niz[i];
	}
	for(i=1; i<n; i++){
		drugi[s]=prvi[i];
		s+=2;
	}
	for(i=0; i<2*n; i+=2){
		parni=drugi[i];
		drugi[i+1] = abs(Suma(parni));
	}
	
	for(i=0; i<n*2; i++){
	*(niz+i)=drugi[i];
	}
}
/* Racunanje sume cifara broja koju koristimo u funkciji ubaci */

int Suma (int broj){
	int cifra,suma=0;
	while(broj!=0){
		cifra=broj%10;
		broj/=10;
		suma+=cifra;
	}
	return suma;
	}
	
	
	int izbaci(int *niz, int n){
		int k, j, prvi, drugi, temp=0;
		
		/* Provjeravamo da li je broj u nizu Fibonaccijev */
		
		for(k=0; k<n;){
			prvi=1;
			drugi=1;
			
			do{
				if(temp==1)
				k--;
				temp=0;
				if(k<0)k++;
				
		/* Ukoliko je broj u nizu Fibonaccijev, izbacujemo ga, i smanjujemo velicinu niza */
		/* Pritom pazimo da ne izadjemo iz opsega niza */
		
			if(niz[k]==prvi || niz[k]==drugi){
				for(j=k; j<n-1; j++){
				niz[j]=niz[j+1];
				}
				k--;
				n--;
			}
			prvi=prvi+drugi;
			drugi=prvi+drugi;
			
			if(k<0){k++;
			temp=1;
			}
			}while(prvi<=niz[k]);
			k++;
			if(k==n && temp==1)
			k--;
		}
		return n;
	}
			
	
	