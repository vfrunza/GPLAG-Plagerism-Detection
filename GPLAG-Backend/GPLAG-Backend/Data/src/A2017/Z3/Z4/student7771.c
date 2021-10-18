#include <stdio.h>
int max(int matrica[100][100],int visina,int sirina)
{
	int ponavljanje,clan,max=0,i,j,k,l;
	clan=matrica[0][0];
	for(i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			ponavljanje=0;
			for(k=0; k<visina; k++) {
				for(l=0; l<sirina; l++) {
					if(matrica[i][j]==matrica[k][l])
						ponavljanje++;
				}
			}

			if(ponavljanje>max) {
				max=ponavljanje;
				clan=matrica[i][j];
			}

			else if(ponavljanje==max && matrica[i][j]<clan)
				clan=matrica[i][j];
		}
	}
	return clan;
}
int izbaci_kolone(int matrica[100][100],int visina,int sirina, int N)
{
	int i,j,k,l,kolona;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==N) {
				kolona=j;
				for(k=0; k<visina; k++) {
					for(l=kolona; l<sirina-1; l++) {
						matrica[k][l]=matrica[k][l+1];
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
	int matrica[100][100],visina,sirina,j,i,red,n,prolaz=0;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0; i<visina; i++) {
		red=i+1;
		printf("Unesite elemente %d. reda: ",red);
		for(j=0; j<sirina; j++) {

			scanf("%d",&matrica[i][j]);

		}
	}
	while(sirina>0) {
		prolaz++;
		n=max(matrica,visina,sirina);
		sirina=izbaci_kolone(matrica,visina,sirina,n);
		if(sirina !=0) {
			printf("\nNakon %d. prolaza matrica glasi:\n",prolaz);
			for(i=0; i<visina; i++) {
				for(j=0; j<sirina; j++) {
					printf("%5d",matrica[i][j]);
				}
				printf("\n");
			}

		} else printf("\nNakon %d. prolaza matrica je prazna!",prolaz);

	}



	return 0;
}
