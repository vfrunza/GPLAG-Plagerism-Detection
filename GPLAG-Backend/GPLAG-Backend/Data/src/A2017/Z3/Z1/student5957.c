#include <stdio.h>
#define MAX 100

int dva_od_tri(int niz1[MAX], int velicina1, int niz2[MAX], int velicina2, int niz3[MAX], int velicina3)
{
	int i,j,k,brojac1[1000]= {0},brojac2[1000]= {0},brojac3[1000]= {0},rez=0,b=0;
	for(i=0; i<velicina1; i++) {
		for(b=0; b<1000; b++) {
			if(niz1[i]==b) {
				brojac1[b]++;
			}
		}
	}

	for(j=0; j<velicina2; j++) {
		for(b=0; b<1000; b++) {
			if(niz2[j]==b) {
				brojac2[b]++;
			}
		}
	}
	for(k=0; k<velicina3; k++) {
		for(b=0; b<1000; b++) {
			if(niz3[k]==b) {
				brojac3[b]++;
			}
		}
	}
	for(b=0; b<1000; b++) {
		if((brojac3[b]==0 && ( brojac1[b]>=1 && brojac2[b]>=1)) || (brojac2[b]==0 && (brojac1[b]>=1 && brojac3[b]>=1)) || ( brojac1[b]==0 && (brojac2[b]>=1 && brojac3[b]>=1))) {
			rez++;

		}

	}
	return rez;

}

int main()
{
	int niz1[MAX],niz2[MAX],niz3[MAX],i,j,k,rez=0,velicina1=0,velicina2=0,velicina3=0;
	printf("Unesite clanove niza1: ");
	for(i=0; i<sizeof(niz1); ++i) {
		scanf("%d",&niz1[i]);
	}
	velicina1=sizeof(niz1);
	printf("Unesite clanove niza2: ");
	for(j=0; j<sizeof(niz2); ++j) {
		scanf("%d",&niz2[j]);

	}
	velicina2=sizeof(niz2);
	printf("Unesite clanove niza3: ");
	for(k=0; k<sizeof(niz3); ++k) {
		scanf("%d",&niz3[k]);
	}
	velicina3=sizeof(niz3);
	rez=dva_od_tri(niz1,velicina1,niz2,velicina2,niz3,velicina3);
	printf("%d",rez);

	return 0;
}
