#include <stdio.h>

int dva_od_tri (int nizA[],int velA, int nizB[], int velB, int nizC[], int velC )

{
	int i,j,k,brojac=0,l;

	/*izbacivanje clanova koji se ponavljaju iz niza A*/
	for(i=0; i<velA; ++i) {
		for(j=i+1; j<velA;) {
			if(nizA[i]==nizA[j]) {
				for(k=j; k<velA-1; ++k)
					nizA[k]=nizA[k+1];

				--velA;
			} else
				++j;
		}
	}

	/*izbacivanje clanova koji se ponavljaju iz niza B*/
	for(i=0; i<velB; ++i) {
		for(j=i+1; j<velB;) {
			if(nizB[i]==nizB[j]) {
				for(k=j; k<velB-1; ++k)
					nizB[k]=nizB[k+1];

				--velB;
			} else
				++j;
		}
	}


	/*izbacivanje clanova koji se ponavljaju iz niza C*/
	for(i=0; i<velC; ++i) {
		for(j=i+1; j<velC;) {
			if(nizC[i]==nizC[j]) {
				for(k=j; k<velC-1; ++k)
					nizC[k]=nizC[k+1];

				--velC;
			} else
				++j;
		}
	}


	/*prebrojavanje clanova koji se nalaze u dva od tri niza*/
	for(i=0; i<velA; i++) {
		for(j=0; j<velB; j++) {

			if(nizA[i]==nizB[j]) {
				brojac++;
			}
		}

	}

	for(i=0; i<velA; i++) {
		for(k=0; k<velC; k++) {

			if(nizA[i]==nizC[k]) {
				brojac++;
			}
		}

	}


	for(j=0; j<velB; j++) {
		for(k=0; k<velC; k++) {

			if(nizC[k]==nizB[j]) {
				brojac++;
			}
		}
	}


	for(l=0; l<3; l++) {
		for(i=0; i<velA; i++) {
			for (j=0; j<velB; j++) {
				for(k=0; k<velC; k++) {
					if(nizA[i]==nizB[j] && nizB[j]==nizC[k]) {
						brojac--;
					}
				}
			}
		}
	}
	return brojac;
}

int main(void)
{
	int nizA[50],nizB[50],nizC[50],velA,velB,velC,i,j,k;

	/*unos clanova niza(-1 za kraj unosa)*/
	for(i=0; i<50; i++) {
		printf("Unesite element %d. niza A: ",i+1);
		scanf("%d",&nizA[i]);
		if(nizA[i]==-1) break;
	}

	for(j=0; j<50; j++) {
		printf("Unesite element %d. niza B: ",j+1);
		scanf("%d",&nizB[j]);
		if(nizB[j]==-1) break;
	}
	for(k=0; k<50; k++) {
		printf("Unesite element %d. niza C: ",k+1);
		scanf("%d",&nizC[k]);
		if(nizC[k]==-1) break;
	}

	velA=i;
	velB=j;
	velC=k;

	/*ispis broja clanova koji se javljaju u dva od tri niza*/
	printf("%d",dva_od_tri ( nizA,velA,nizB,velB,nizC,velC ));

	return 0;
}
