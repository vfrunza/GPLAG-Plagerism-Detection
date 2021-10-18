#include <stdio.h>

int max(int matrica[100][100],int visina, int sirina)
{
	int i,j,m,n,maxmatr,maxbrm,brm1=0,brm2=0;
	maxmatr=matrica[0][0];
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(maxmatr==matrica[i][j]) {
				brm1++;
			}
		}
	}
	maxmatr=matrica[0][0];
	maxbrm=brm1;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			for(m=0; m<visina; m++) {
				for(n=0; n<sirina; n++) {
					if(matrica[m][n]==matrica[i][j] && i!=m || j!=n) {
						brm2++;
					}
				}
			}
			if(brm2>brm1) {
				maxbrm=brm2;
				maxmatr=matrica[i][j];
				brm1=brm2;
			} else if(brm2==brm1 && matrica[i][j]<maxmatr) {
				maxbrm=brm2;
				maxmatr=matrica[i][j];
				brm1=brm2;
			}
		}
	}
	return maxmatr ;

}

int izbaci_kolone(int matrica[100][100],int visina, int sirina, int brojN)
{
	int i,j,m,n,k;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(brojN==matrica[i][j]) {
				k=j;
				for(m=0; m<visina; m++) {
					for(n=k; n<sirina; n++) {
						matrica[m][k]==matrica[m][k+1];
					}
				}
				sirina--;
				j--;

			}
		}
	}
	return sirina;
}


int main()
{
	int visina, sirina, i,j, matrica[100][100];
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d",&matrica[i][j]);
		}
	}
	int p=1,br;
	while(sirina>0) {
		br=max(matrica,visina,sirina);
		sirina=izbaci_kolone(matrica,visina,sirina,br);
		if(sirina==0) {
			printf("\nNakon %d. prolaza matrica je prazna!",p);
			break;
		}
		printf("\nNakon %d. prolaza matrica glasi:\n", p);
		for (i=0; i<visina; i++) {
			for (j=0; j<sirina; j++) {
				printf("%5d",matrica[i][j]);
			}
			printf("\n");
		}
		p++;
	}

	return 0;
}
