#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Funkcija ubaci koja prima niz cijelih brojeva te nakon svakog člana niza 
ubacuje u niz pozitivan broj koji predstavlja sumu cifara prethodnog člana*/
void ubaci (int* niz, int vel) {
	int ostatak=0, i, j, broj;
	int zbir=0;
	int niz_p[1000];
	int niz_a[1000];
	int novi_niz[1000];
	/* pomocni niz */
	for (i=0; i<vel; i++) {
		niz_p[i]=*(niz+i);
	}
	/* niz ciji su elementi jednaki apsolutnim vrijednostma elemanata niza kojeg funkcija prima */
	for (i=0; i<vel; i++) {
		niz_a[i]=abs(*(niz+i));
	}
	/* formiranje novog niza koji se sastoji od niza kojeg funkcija prima i suma cifara elemenata tog niza */
	for(i=0; i<vel*2; i++) {
		j=i/2;
		zbir=0;
		broj=niz_p[j];
		if(i%2==0) 
		novi_niz[i]=broj;
	    else {
	    	do {
				ostatak=(niz_a[j])%10;
				zbir+=ostatak;
				niz_a[j]=(niz_a[j])/10;
			}
			while ((niz_a[j])!=0);
			novi_niz[i]=zbir;
		}
	}
	/* dodjela elemenata novog niza elementima niza koeg funkcija prima */
	for(i=0; i<vel*2; i++) {
		*(niz+i)=novi_niz[i];
	}
}

/* funkcija fibonaci koja ispituje da li je neki broj Fibonacijev ili nije */
int fibonaci (int broj) {
	int fib[100], i;
	fib[0]=1;
	fib[1]=2;
	/* funkcija vraca vrijednost 1 ako je broj Fibonacijev, a vrijednost 0 ako nije */
	if (broj==1 || broj==2) 
		return 1;
	for (i=2; ; i++)  {
		fib[i]=fib[i-1]+fib[i-2];
		if(broj==fib[i])
			return 1;
		if(fib[i]>broj)
			break;
	}
	return 0;
}

/* funkcija izbaci koja prima niz cijelih brojeva i iz njega izbacuje sve članove niza koji su Fibonaccijevi brojevi */
int izbaci (int* niz, int vel) {
	int i, k;
	int brojac=0;
	int velicina;
	velicina=vel;
	for(i=0; i<vel; i++) {
			if(fibonaci(niz[i])==1) {
				for (k=i; k<vel-1; k++) {
					*(niz+k)=*(niz+k+1);
				}
				i--;
				vel--;
				brojac++;
			}
		}
	/* funkcija vraca broj članova niza nakon izbacivanja */
	return (velicina-brojac);
}
	
int main() {
	int niz[20];
	int i, velicina=20;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) 
		scanf("%d", &niz[i]);
		ubaci(niz,10);
		velicina=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for (i=0; i<velicina; i++) {
		if(i==(velicina-1))
			printf("%d.", niz[i]);
		else
			printf("%d, ", niz[i]);
	}
return 0;
}

