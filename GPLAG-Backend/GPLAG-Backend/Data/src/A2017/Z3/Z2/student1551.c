/*Potrebno je najprije napraviti funkciju zaokruzi1 koja prima niz realnih brojeva i sve članove 
niza zaokružuje na 1 decimalu .

Zatim treba napraviti funkciju preslozi koja također prima niz realnih brojeva i jedan prirodan
broj k, poziva prvu funkciju, a zatim niz preslaže tako da se na početku niza nalaze svi članovi
niza čija je suma cifara veća ili jednaka k, a zatim oni članovi niza čija je suma cifara manja 
od k. Pri tome redoslijed unutar svake od ovih grupa treba ostati nepromijenjen.

Primjer: Neka je dat niz
	13.1 15.749999 15.75 9.222 78.1
Nakon zaokruživanja niz treba glasiti:
	13.1 15.7 15.8 9.2 78.1
Nakon poziva funkcije preslozi pri čemu je k=14 niz treba glasiti:
	15.8 78.1 13.1 15.7 9.2
Jer brojevi 15.8 i 78.1 imaju sumu cifara veću ili jednaku 14, a brojevi 13.1, 15.7 i 9.2 
imaju sumu cifara manju od 14. Dalje uočavamo da je unutar ove dvije grupe redoslijed ostao 
nepromijenjen: ako posmatramo samo brojeve čija je suma cifara veća ili jednaka 14, njihov 
redoslijed je u polaznom nizu bio: 15.8, 78.1. Ako posmatramo samo brojeve iz druge grupe, 
njihov redoslijed je u polaznom nizu bio: 13.1, 15.7, 9.2. 

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void zaokruzi1 (float niz[], int n){
	int i;
	for (i=0; i<n; i++){
		niz[i]=(round(niz[i]*10))/10;
	}
}


void preslozi (float niz[], int n, int k){
	
	int i,pom=1;
	int brojac1=0, brojac2=0,sum=0;
	float nizb2[100];
	float nizb1[100];
	
	for (i=0; i<100; i++)
	nizb1[i]=0;
	
	for (i=0; i<100; i++)
	nizb2[i]=0;
	
	for (i=0; i<n ;i++) {
	
	pom=niz[i]*10;
	while(abs(pom)>0){
		sum=sum+(abs(pom%10));
		pom=(pom/10);
	
	}
	
	
	zaokruzi1(niz,n);
	
	if(sum>=k){
		nizb1[brojac1]=niz[i];
		brojac1++;
	} 
	if (sum<k){
		nizb2[brojac2]=niz[i];
		brojac2++;
	}
	sum=0;
	}
	

	for (i=0; i<brojac1; i++) {
		niz[i]=nizb1[i];
	}
	for (i=0; i<brojac2; i++){
		niz[brojac1+i]=nizb2[i];
	
	}
}

int main() {
	
	float niz[100];
	int i,n,k;
	
	printf ("k=");
	scanf ("%d", &k);
	printf ("n=");
	scanf("%d",&n);
	printf ("Unesi niz: ");
	for (i=0; i<n; i++){
		scanf ("%f",&niz[i]);
	}
	
		preslozi(niz,n,k);
	printf("Niz glasi: ");
	
	for (i=0; i<n; i++)
		 printf("%g ", niz[i]);
		 
	return 0;
}
