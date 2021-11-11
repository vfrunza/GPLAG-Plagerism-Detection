#include <stdio.h>


/*Funkcija racuna sumu(zbir) cifara nekog broja koristeci niz*/
int suma (int x) {
	
	if (x<0) x*=(-1); 
	int niz[10]={0};
	
	while (x!=0) {
		int cifra;
		cifra=x%10;
		niz[cifra]++;
		x/=10;
	}
	
	int i,suma=0;
	for (i=0; i<10; i++) {
		suma=suma+i*niz[i];
	}
	return suma;
}
	
/*Funkcija nakon svakog clana niza ubacuje poz broj koji predstavlja sumu cifara prethodnog clana*/
void ubaci (int niz[], int vel) {
		int i,j;
		
		/*Ovom for petljom se clanovi niza pomjere za jedno mjesto udesno*/
		for (i=0; i<vel; i++) {
			for(j=vel; j>i; j--) {
				niz[j]=niz[j-1];
			}
			
		niz[i+1]=suma(niz[i]); /*pozivanje fje suma*/
		i++;
		vel++;
		}
	}
	
/*Funkcija provjerava Fibonacijeve brojeve*/
int fib (int x) {
	int niz[2]={1,1};
	int sljedeci=0;
	if (x==1) return 1; 
	while (sljedeci<=x) {
		if(niz[0]==x || niz[1]==x) return 1;
		sljedeci=niz[0] + niz[1];
		niz[0]=niz[1];
		niz[1]=sljedeci;
		if (sljedeci==x || niz[0]==x) return 1;
	}
	return 0;
}

/*Funkcija izbacuje sve clanove niza koji su Fibonacijevi brojevi*/
int izbaci(int niz[], int vel) {
	int i,j;
	for (i=0; i<vel; i++) {
		if (fib(niz[i])==1) { /*U uslovu se poziva funkcija fib*/
			for (j=i; j<vel-1; j++) {
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}
}

int main() {
	int niz[20],i,vr; /*Uzimamo 20 clanova niza jer ce ih toliko biti nakon fje ubaci i dodatnih clanova*/ 
	
	/*Unos niza*/
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d", &niz[i]);
	}
	
	ubaci(niz,10);
	vr=izbaci(niz,20);
	
	/*Ispis*/
	printf("Modificirani niz glasi: ");
	for (i=0; i<vr-1; i++) {
		printf("%d, ", niz[i]);
	}
	printf("%d.",niz[i]);
	
	return 0;
}