#include <stdio.h>

int main() {
	int niz[100], brojac[100]={0}, temp[100], cifre[1000];
	int vel, i=0, brcifri=0, brtemp, j=0;
	printf("Unesite velicinu niza: ");
	scanf("%d", &vel);
	printf("Unesite clanove niza: ");
	for(i=0; i<vel; i++) {
		scanf("%d", &niz[i]);
		if(niz[i]<0) {
			printf("Unijeli ste neispravnu veličinu. Ponovite unos.\n");
			i--;
		}
	}
	// dodjela niza niz nizu temp
	for(i=0; i<vel; i++) {
		temp[i]=niz[i];
	}
	// prebrojavanje cifri
	for(i=0; i<vel; i++) {
		do {
			niz[i]=niz[i]/10;
			brcifri++;
		} while(niz[i]>0);
	}
	brtemp=brcifri;
	// formiranje niza cifri
	for(i=0; i<vel; i++) {
		for(j=brcifri; j>0; j--) {
			while(temp[i]>0) {
				cifre[j]=temp[i]%10;
				temp[i]=temp[i]/10;
			} 
		}
	}
	for(i=0; i<brcifri; i++) printf("%d ", cifre[i]);
	return 0;
}
