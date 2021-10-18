#include <stdio.h>
#include <stdlib.h>

int fibonacci (int n) {
	int broj=0, broj1=0, broj2=1;
	while(broj<n) {
		broj=broj1 + broj2;
		if(broj==n) return 1;
		broj1=broj2;
		broj2=broj;
	}
	return 0;
}

void ubaci(int niz[], int vel) {
	int niz2[20] = {0}, i,j=0,suma=0,n;
	for(i=0;i<vel;i++) {
		niz2[j] = niz[i];
		j+=2;
	}
	for(i=0;i<2*vel;i++) niz[i]=niz2[i];
	for(i=1;i<2*vel;i++) {
		suma=0; n=niz[i-1];
		while(n) {
			suma+=n%10;
			n/=10;
		}
		if(niz[i-1]<0) niz[i] = (suma*(-1));
		else niz[i]=suma;
		i++;
	}
}
int izbaci(int niz[], int vel) {
	int i,j=0;
	for(i=0;i<vel;i++) {
		if(fibonacci(niz[i])==1) {
			for(j=i;j<vel-1;j++) {
				niz[j]= niz[j+1];
			}
			vel--;
			i--;
		}
	}
	return vel;
}

int main () {
	int i, vel=20, brojac=0;
	int niz[20];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++) 
		scanf("%d", &niz[i]);
		ubaci(niz,vel);
		brojac=izbaci(niz,vel);
		printf("Modificirani niz glasi: ");
		for(i=0;i<brojac;i++) {
			if(i==brojac-1) {
				printf("%d.", niz[i]);
				return 0;
			}
			else printf("%d, ", niz[i]);
		}
		
	
	return 0;
}
