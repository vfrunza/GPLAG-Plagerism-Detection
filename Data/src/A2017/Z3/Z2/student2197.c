#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Funkcija "zaokruzi1" zaokruzuje sve clanove niza na jednu decimalu

void zaokruzi1(float niz[],int vel) {
	int i;
	for(i=0;i<vel;i++) 
		niz[i]=round(niz[i]*10)/10;
}

void preslozi(float niz[],int vel,unsigned k) {
	int i,j,temp,sumaCifara,brojac=0;
	float swap;
	zaokruzi1(niz,vel);
	for(i=0;i<vel;i++) {
		sumaCifara=0;
		temp = niz[i]*10;
		while(temp!=0) {
			sumaCifara+=abs(temp%10);
			temp/=10;
		}
		/* Kada naiđemo na član koji zadovoljava uslov onda ga swapujemo unazad do prvog slobodnog mjesta (zavisi od brojača) */
		if(sumaCifara >= k ) {
			for(j=i;j>brojac;j--) {
				swap=niz[j-1];
				niz[j-1]=niz[j];
				niz[j]=swap;
			}
			brojac++;
		}
	}
}

int main() {
	int i;
	float niz1[] = {-1.0, -0.1, -0.19999, -4.449999, -4.45001  };
	preslozi(niz1,5,8);
	printf("\n\n");
	for(i=0;i<5;i++) {
		printf("%g,",niz1[i]);
	}
	return 0;
}
