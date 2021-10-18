#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define brel 10
#define brel2 20
/* Funkcija ubaci */ 
void ubaci(int *niz,int velicina){
	int i,cifra,broj,broj2=0;
	for (i=velicina-1;i>=0;i--){    /* Pomjeranje clanova niza */ 
		*(niz+2*i)=*(niz+i);
	}
	for (i=0;i<velicina*2;i++){
		if (i%2==1){
			broj=*(niz+i-1);
			while (broj!=0){        /* Dodavanje clanova sabiranjem cifara prethodnog clana */ 
				cifra=broj%10;
				broj2+=cifra;
				broj/=10;
		    }
		    broj2=abs(broj2);
			*(niz+i)=broj2;
			broj2=0;
		}
	}
}
 
/* Funkcija izbaci */ 
/* Formiranje pretlji za prolazak po nizu i uporedivanje njegovih clanova sa Fibonaccijevim nizom, izbacivanje jednakih */
int izbaci(int *niz,int velicina){
	int i,j,m,prvi=0,drugi=1,slijedeci;
	for (i=0;i<velicina;i++){
		prvi=0;
		drugi=1;
		for (j=1;j<10000;j++){   
			if (j==1) slijedeci=j;                
			else {
				slijedeci=prvi+drugi;
				prvi=drugi;
				drugi=slijedeci;
			}
			if (*(niz+i)==slijedeci){
				for (m=i;m<velicina-1;m++){
						*(niz+m)=*(niz+m+1);
				}
				velicina--;
				i--;
				break;
			}
		}
	}
	return velicina;
}
 
int main() {
	int niz[20],i,n;
 
	/* Unos elemenata */ 
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
 
	/* Pozivanje funkcije ubaci */ 
 
	ubaci(niz,brel);
 
	/* Pozivanje funkcije izbaci */ 
 
	n=izbaci(niz,brel2);
 
	/* Ispis niza */
	printf ("Modificirani niz glasi: ");
	for (i=0;i<n;i++){
		if (i<(n-1)){
			printf ("%d, ",niz[i]);
	    }
	    else {
	    	printf ("%d. ",niz[i]);
	    }
	}
 
	return 0;
}