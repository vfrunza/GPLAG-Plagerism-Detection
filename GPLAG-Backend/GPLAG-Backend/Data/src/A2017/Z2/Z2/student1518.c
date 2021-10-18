#include <stdio.h>
#include <math.h>
#define MAXVELICINA 100
#define MAXVELICINADRUGOG 1000
#define MAXVELICINANIZACIFARA 100000
#define CIFRE 10

int main() {
	
	int i, j, k, t, p, prethodna, brojactecifre, velicina, broj, brojcifarabroja, niz[MAXVELICINA], drugi[MAXVELICINADRUGOG], nizsvihcifara[MAXVELICINANIZACIFARA];
	long long int scimtrebadijeliti;
	
	do {
		printf("Unesite velicinu niza: ");
		scanf("%d", &velicina);
	} while (velicina<0 || velicina>100);
	
	printf("Unesite clanove niza: ");
	for (i=0; i<velicina; i++) {
		scanf("%d", &niz[i]);
	}
	
	k=0;
	
	for (i=0; i<velicina; i++) {
		if (niz[i]==0) {
			nizsvihcifara[k++]=0;
			continue;
		}
		broj=niz[i];
		brojcifarabroja=0;
		while (broj!=0) {
			broj=broj/10;
			brojcifarabroja++;
		}
		for (j=brojcifarabroja-1; j>=0; j--) {
			scimtrebadijeliti=1;
			for (p=0; p<j; p++) {
				scimtrebadijeliti*=10;
			}
			nizsvihcifara[k++]=niz[i]/scimtrebadijeliti;
			niz[i]=niz[i]%scimtrebadijeliti;
		}
	}
	
	drugi[0]=nizsvihcifara[0];
	t=1;
	brojactecifre=1;
	prethodna=nizsvihcifara[0];
	
	for (i=1; i<k; i++) {
		if (nizsvihcifara[i]==prethodna) {
			brojactecifre++;
		}
		else {
			drugi[t++]=brojactecifre;
			brojactecifre=1;
			drugi[t++]=nizsvihcifara[i];
		}
		if (i==k-1) {
			drugi[t++]=brojactecifre;
		}
		else {
			prethodna=nizsvihcifara[i];
		}
	}
	
	printf("Finalni niz glasi:\n");
	for (i=0; i<t; i++) {
		printf("%d ", drugi[i]);
	}
	
	return 0;
}
