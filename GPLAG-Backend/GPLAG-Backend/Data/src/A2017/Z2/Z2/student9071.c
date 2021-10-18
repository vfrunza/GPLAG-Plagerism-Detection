#include <stdio.h>


int main()
{
	int i, j=0, POCETNI[100]= {0}, POMOCNI[1000]= {0}, FINALNI[1000]= {0}, n;
	int broj_obrnut, vel, suma=0, broj, pomocni, mjesto=0;

	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++)
		scanf("%d", &POCETNI[i]);
		
	for(i=0; i<n; i++) {
		broj = POCETNI[i];
		while( broj !=0) {
			broj_obrnut = broj%10;
			suma = suma*10 + broj_obrnut;
			broj= broj/10;
		}

		while (suma!=0) {
			POMOCNI[j] = suma%10;
			j++;
			suma/=10;
		}

	}
	vel=j;


	for(i=0; i<vel;) {
		pomocni=POMOCNI[i];
		broj=0;
		for(j=i;; j++) {
			if(pomocni==POMOCNI[j]) broj++;
			if(pomocni!=POMOCNI[j])break;

		}
		FINALNI[mjesto]=pomocni;
		mjesto++;
		FINALNI[mjesto]=broj;
		mjesto++;
		i=j;
	}
	printf("Finalni niz glasi:\n");
	for(i=0; i<mjesto; i++) printf("%d ", FINALNI[i]);

	return 0;

}