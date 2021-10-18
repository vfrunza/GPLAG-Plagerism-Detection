#include <stdio.h>
#include <math.h>

int main() {
	int i, j, nizA[100], nizB[10000], nizC[1000], temp, cifra, brojcifara=0, velicinaA, counter;
	printf("Unesite velicinu niza: ");
	scanf("%d", &velicinaA);
	printf("Unesite clanove niza: ");
	for (i=0;i<velicinaA;i++) {
		scanf("%d", &nizA[i]);
		if (nizA[i]<0)
			i--;
	}
	/* Nisam siguran da li ovo "U rješenju se obavezno treba koristiti jedan C niz za unos podataka i jedan za konačni rezultat" znaci da se ne smije koristiti 
	3. niz za cifre, ja sam tako radio, nadam se da je rjesenje prihvatljivo :) srednji niz (nizB) sam mogao staviti na 1000000 clanova, ali da ne uzimam puno 
	memorije ostavio sam ga na 10000 */
	for (i=0;i<velicinaA;i++) {
		cifra=0;
		temp=nizA[i];
		do {
			temp=temp/10;
			cifra++;
		} while(temp!=0);
		for (j=0;j<cifra;j++) {
			nizB[brojcifara+j]=nizA[i]/(int)(pow(10,cifra-j-1));
			nizA[i]%=(int)pow(10,cifra-j-1);
		}
		brojcifara+=cifra;
	}
	
	j=0;
	for (i=0;i<brojcifara;i++) {
		nizC[j]=nizB[i];
		counter=1;
		while(i<brojcifara-1 && nizB[i]==nizB[i+1]) {
			i++;
			counter++;
		}
		nizC[j+1]=counter;
		j+=2;
	}
	
	printf("Finalni niz glasi:\n");
	for(i=0;i<j;i++) 
		printf("%d ", nizC[i]);
	
	return 0;
}
