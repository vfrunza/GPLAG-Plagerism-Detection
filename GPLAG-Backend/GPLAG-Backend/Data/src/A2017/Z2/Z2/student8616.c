#include <stdio.h>
#define BROJ_EL 1000

int main() {
	int velicina=0,i=0,k=0,cifra=0,j=0,pomocnavel=0,c=0,ponavljac=1, finalno=0,h=100;
	int niz[BROJ_EL], pomocni[BROJ_EL], niz2[BROJ_EL], niz3[BROJ_EL];
	printf("Unesite velicinu niza: ");
	do{
	scanf("%d", &velicina);
	} 
	while(velicina>100 || velicina <=0);
	printf("Unesite clanove niza: ");
	for(i=0; i<velicina; i++) {
		scanf("%d", &niz[i]);
	}
	for(i=0; i<velicina; i++){
		k=niz[i];
		if(k==0){
			niz2[cifra]=0;
			cifra++;
			continue;
		}
		else{
			while(k){
				c=k%10;
				pomocni[pomocnavel]=c;
				k=k/10;
				pomocnavel++;
			}
			for(j=pomocnavel-1; j>=0; j--){
				niz2[cifra]=pomocni[j];
				cifra++;
		}
		pomocnavel=0;
	}
	}
	finalno=0;
	printf("Finalni niz glasi:\n");
	h=cifra;
	finalno=0;
	for(i=0; i<h; i++){
		if(i==0) {
			niz3[finalno]=niz2[i];
			finalno++;
			continue;
		}
		else{
		if(niz2[i]==niz2[i-1]) {
				ponavljac++;
			}
			else {
				niz3[finalno]=ponavljac;
				++finalno;
				niz3[finalno]=niz2[i];
				++finalno;
				ponavljac=1;
			}
			if(i==h-1){
				niz3[finalno]=ponavljac;
			}
	}
	}
	for(i=0; i<=finalno; i++){
		printf("%d ", niz3[i]);
	}
	return 0;
}
