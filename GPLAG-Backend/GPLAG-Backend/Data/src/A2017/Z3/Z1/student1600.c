#include <stdio.h>
int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3)
{
	int brojac=0;
	int i,j,k;

	for(i=0; i<vel1; i++) {
		if(vel2==0) goto treci;
		for(j=0; j<vel2; j++) {
			if (niz1[i]==niz2[j]) {
				if(vel3==0) brojac++;
				else
					for(k=0; k<vel3; k++) {
						if (niz1[i]==niz3[k])
							break;
						if (k==vel3-1)
							brojac++;
					}
			}
			if(j==vel2-1) {
treci:
				for(k=0; k<vel3; k++) {
					if(niz1[i]==niz3[k])
						brojac++;
				}
			}
		}
	}

	return brojac;
}

int main()
{
	int niz1[100], niz2[100], niz3[100], vel1, vel2, vel3;
	int i,j,k;

	printf("Unesite velicinu prvog niza: ");
	scanf("%d",&vel1);
	printf("Unesite velicinu drugog niza: ");
	scanf("%d",&vel2);
	printf("Unesite velicinu treceg niza: ");
	scanf("%d",&vel3);

	printf("Unesite clanove prvog niza: ");
	for(i=0; i<vel1; i++) {
		scanf("%d", &niz1[i]);
	}

	printf("Unesite clanove drugog niza: ");
	for(j=0; j<vel2; j++) {
		scanf("%d", &niz2[j]);
	}

	printf("Unesite clanove treceg niza: ");
	for(k=0; k<vel3; k++) {
		scanf("%d", &niz3[k]);
	}

	printf("Broj clanova koji se javljaju u 2 od 3 niza je : %d", dva_od_tri(niz1,niz2,niz3,vel1,vel2,vel3));

	return 0;
}
