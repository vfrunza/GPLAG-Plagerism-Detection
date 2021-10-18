#include <stdio.h>
#include <stdlib.h>

void ubaci (int* niz, int vel) {
	int i,suma=0,temp;
	for (i=9; i>0; i--) {
		niz[2*i]=niz[i];
	}
	for (i=0; i<20; i+=2) {
		temp=niz[i];
		suma=0;
		while (temp!=0) {
			suma+=temp%10;
			temp/=10;
		}
		niz[i+1]=abs(suma);
	}
}

int izbaci (int* niz, int vel) {
	int fib[46],i,j,k;
	fib[0]=fib[1]=1;
	for (i=2; i<46; i++)
		fib[i]=fib[i-1]+fib[i-2];
	for (i=0; i<vel; i++) {
		for (j=1; j<46; j++) {
			if (niz[i]==fib[j]) {
				for (k=i; k<vel-1; k++) {
					niz[k]=niz[k+1];
				}
				vel--;
				i--;
				break;
			}
		}
	}
	return vel;
}

int main() {
	int niz[20],i,vel=20;
	printf("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++)
		scanf ("%d", &niz[i]);
	for (i=10; i<20; i++)
		niz[i]=0;
	ubaci(niz, vel);
	vel=izbaci(niz, vel);
	printf ("Modificirani niz glasi: ");
	for (i=0; i<vel; i++) {
		if (i!=vel-1)
			printf ("%d, ",niz[i]);
		else
			printf ("%d.",niz[i]);
	}
	return 0;
}
