#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina)
{
	int i,j,k,l,brojac=0,c,maxbrojac=0,maxclan=0;

	for(i=0; i<visina; i++) {

		for(j=0; j<sirina; j++) {
			brojac=0;
			c=matrica[i][j];
			for(k=0; k<visina; k++) {
				for(l=0; l<sirina; l++) {
					if(matrica[k][l]==c) brojac++;

				}
			}


			if(brojac>maxbrojac) {
				maxbrojac=brojac;
				maxclan=c;
			} else if(brojac==maxbrojac && c<maxclan) maxclan=c;

		}

	}

	return maxclan;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina , int n )
{
	int i,j,k,l,tmp=0;

	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {

			if(matrica[i][j]==n) {
				for(l=j; l<sirina-1; l++) {
					for(k=0; k<visina; k++) {
						tmp=matrica[k][l];
						matrica[k][l]=matrica[k][l+1];
						matrica[k][l+1]=tmp;
					}
				}
				sirina--;
				if(i>0) i--;
			}

		}

	}
	return sirina;
}




int main() {
int matrica[100][100];
int visina,sirina,i,j,brojac=1;
printf("Unesite sirinu i visinu matrice: ");
scanf("%d %d",&sirina,&visina);
for(i=0;i<visina;i++)
{
	printf("Unesite elemente %d. reda: ",i+1);
	for(j=0;j<sirina;j++)
	{
		scanf("%d",&matrica[i][j]);
	}
}


do {
		sirina=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));

		if(sirina>0) {
			printf("\nNakon %d. prolaza matrica glasi:\n",brojac);
			for(i=0; i<visina; i++) {

				for(j=0; j<sirina; j++) {
					printf("%5.d",matrica[i][j]);
				}
				printf("\n");
			}
		} else printf("\nNakon %d. prolaza matrica je prazna!",brojac);
	brojac++;	
	} while (sirina>0) ;
	return 0;
}
