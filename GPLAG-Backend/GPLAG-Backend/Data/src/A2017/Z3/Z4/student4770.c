#include <stdio.h>
int max(int matrica[100][100],int visina,int sirina)
{
	int i,j,m,n;
	int brojac = 0;
	int max = matrica[0][0], max_brojac = 0;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			for(m=0; m<visina; m++) {
				for(n=0; n<sirina; n++) {
					if(matrica[i][j]==matrica[m][n]) brojac++;
				}
			}
			if(brojac > max_brojac) {
				max=matrica[i][j];
				max_brojac=brojac;
			} else if(brojac==max_brojac) {
				if(matrica[i][j] < max) {
					max=matrica[i][j];
					max_brojac=brojac;
				}
			}
			brojac=0;
		}
	}
	return max;
}

int izbaci_kolone(int matrica[100][100],int visina,int sirina,int N)
{
	int i,j,n,m,s=sirina;
	for(i=0; i<visina; i++) {
		for(j=0; j<s; j++) {
			if(matrica[i][j]==N) {
				for(n=j; n<s-1; n++) {
					for(m=0; m<visina; m++) {
						matrica[m][n]=matrica[m][n+1];
					}
				}
				s--;
				j--;
			}
		}
	}
	return s;
}

int main()
{
	int sirina,visina,i,j,k,m;
	int matrica[100][100];
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d",&matrica[i][j]);
		}
	}
	i=1;
	for(;;) {
		m=max(matrica,visina,sirina);
		sirina=izbaci_kolone(matrica,visina,sirina,m);
		if(sirina==0) {
			printf("\nNakon %d. prolaza matrica je prazna!",i);
			return 0;
		}
		printf("\nNakon %d. prolaza matrica glasi:\n",i);
		for(j=0; j<visina; j++) {
			for(k=0; k<sirina; k++) {
				printf("%5d",matrica[j][k]);
			}
			printf("\n");
		}
		i++;
	}
	return 0;
}
