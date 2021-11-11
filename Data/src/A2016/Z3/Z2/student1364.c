#include <stdio.h>
#include <math.h>

void ubaci (int *niz, int br_el) {
	int i, r_niz[500]={0}, broj=0, cifra=0, suma_c=0;
	
	for (i=0; i<br_el*2; i++) {
		if (i%2==0) r_niz[i] = *(niz+(i/2));
		else { 
			broj = fabs(*(niz+i/2));
			suma_c=0;
			do {
				cifra = broj%10;
				suma_c+= cifra;
				broj = broj/10;
			}
			while (broj!=0);
			r_niz[i] = suma_c;
		}
	}
	for (i=0; i<br_el*2; i++)
	*(niz+i)=r_niz[i];
	
}

int fibonaci (int clan_niza) {
	int br=0, fibonacijev_niz[100]={0}, broj=0;
	fibonacijev_niz[0]=1;
	fibonacijev_niz[1]=1;
	if (clan_niza==1)
	return 1;
	br=2;
	do {
			fibonacijev_niz[br]=fibonacijev_niz[br-1]+fibonacijev_niz[br-2];
			if (clan_niza==fibonacijev_niz[br])
			return 1;
			broj=fibonacijev_niz[br];
	br++;	
	}
	while (broj<=clan_niza);
	return 0;
}

int izbaci (int *niz, int velicina) {
	
	int j, i, br_clanova=0, clan=0;
	
		for (i=0; i<velicina; i++) {
		clan=*(niz+i);
			if (fibonaci(clan)==1) {
				for (j=i; j<velicina-1; j++) {
					*(niz+j)= *(niz+1+j);
				}
				velicina--;
				i--;
			}
		}
	br_clanova=velicina;
	return br_clanova;
}

int main() {
	
	int i, niz[20]={0}, br_clanova=0;
	printf("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++) {
		scanf ("%d", &niz[i]);
	}

	printf ("Modificirani niz glasi: ");
	
	ubaci (niz, 10);
	br_clanova=izbaci (niz, 20);

	for (i=0; i<br_clanova; i++) {
		if (i!=br_clanova-1)
		printf ("%d, ", niz[i]);
		else
		printf ("%d.", niz[i]);
	}
	
	return 0;
}
