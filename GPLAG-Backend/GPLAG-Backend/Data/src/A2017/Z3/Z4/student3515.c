#include <stdio.h>
int max(int matrica[100][100],int visina,int sirina)
{
	int max_pon,broj,i,j,k,l,pon2,broj2;
	broj=matrica[0][0];
	max_pon=0;
	/* Prebrojavanja prvog elementa*/
	for (i = 0; i < visina; i++) {
		for (j = 0; j < sirina; j++) {
			if(matrica[i][j]==matrica[0][0])
				max_pon++;
		}
	}
	/*Trazenje najmanje broja koji se najvise puta ponavlja */
	for (i = 0; i < visina; i++) {
		for (j = 0; j < sirina; j++) {
			broj2=matrica[i][j];
			pon2=0;
			for (k = 0; k < visina; k++) {
				for (l = 0; l < sirina; l++) {
					if(matrica[i][j]==matrica[k][l])
						pon2++;
				}
			}
			if (pon2==max_pon && broj2<broj) {
				max_pon=pon2;
				broj=broj2;
			}
			if(pon2>max_pon) {
				max_pon=pon2;
				broj=broj2;
			}

		}
	}
	return broj;
}

int izbaci_kolone(int matrica[100][100],int visina,int sirina,int broj)
{
	int i,j,k,l;

	for (i= 0; i <visina; i++) {
		for (j = 0; j < sirina; j++) {
			/*Trazenje unesenog broja*/
			if(matrica[i][j]==broj) {
				/*Izbacivanje kolone */
				if(j==sirina-1)
					sirina--;
				else {
				
					for(l=0; l<visina; l++) {
						for (k = j+1; k < sirina; k++) {
							matrica[l][k-1]=matrica[l][k];
						}
					}
					/*Nakon svakog izbacivanja provjeru pocinje od pocetka*/
					i=0;
					j=0;
					sirina--;
				}
			}
		}
	}
	return sirina;
}


int main()
{
	int i,j,sirina,visina,matrica[100][100],n,element;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for (i = 0; i < visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for (j = 0; j < sirina; j++) {
			scanf("%d",&matrica[i][j]);
		}
	}
	n=1;
	while(sirina!=0) {
		/*Trazenje maksimalnog elementa i unos u funkciju izbaci kolone sve dok matrica ne bude prazna*/
		element=max(matrica,visina,sirina);
		sirina=izbaci_kolone(matrica,visina,sirina,element);
		if(sirina==0)
			break;
		printf("\nNakon %d. prolaza matrica glasi:\n",n++);
		for (i = 0; i < visina; i++) {
			for (j = 0; j < sirina; j++) {
				printf("%5d",matrica[i][j]);
			}
			printf("\n");
		}


	}
	printf("\nNakon %d. prolaza matrica je prazna!",n);
	return 0;
}
