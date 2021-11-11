#include <stdio.h>
#define BROJ 100
#define CIFRE 1000

int main() {
	int nizBrojevi[BROJ], nizBrojeviClanovi_max=0, nizFinalni[CIFRE],
	nizPraviClanovi_max=0, i=0, number, q=0, w=0, e=0, a=0, c=0, nizBrojeviClanovi;
	do {
		printf("Unesite velicinu niza: ");
		scanf("%d", &nizBrojeviClanovi_max);
	} while(nizBrojeviClanovi<0);
	
	printf("Unesite clanove niza: ");
		for(i=0; i<nizBrojeviClanovi_max; i++) {
			scanf("%d", &nizBrojevi[i]);
			if(nizBrojevi[i]<0)
				i--;
		}
	
	number = nizBrojevi[i];
	e=0;
	while(number>=1) {
		number/=10;
		e++;
	}
	number=nizBrojevi[i];
	for(e=1; e>=0; e--) {
		number=nizBrojevi[i];
		for(w=0; w<e; w++) {
			number/=10;
		}
		nizFinalni[a++]=number%10;
	}
	
	printf("Finalni niz: ");
	for(i=0; i<a; i++)
		printf("%d ", nizFinalni[i]);
		
	return 0;
}
