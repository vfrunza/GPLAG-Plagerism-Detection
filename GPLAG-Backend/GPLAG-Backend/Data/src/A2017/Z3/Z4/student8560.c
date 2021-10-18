#include <stdio.h>
int max (int matrica[100][100], int visina, int sirina)
{
	int i,j,k=0,elementi[200],ponavljanja[200]= {0},vel,max_p,el,max_i=0;
	vel=sirina*visina;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			elementi[k]=matrica[i][j];
			k++;
		}
	}
	for(i=0; i<vel-1; i++) {
		for(j=i+1; j<vel; j++) {
			if(elementi[i]==elementi[j]) {
				for(k=j; k<vel-1; k++) elementi[k]=elementi[k+1];
				vel--;
				j--;
			}
		}
	}
	for(i=0; i<vel; i++) {
		for(j=0; j<visina; j++) {
			for(k=0; k<sirina; k++) {
				if(elementi[i]==matrica[j][k]) ponavljanja[i]++;
			}
		}
	}
	max_i=0;
	max_p=ponavljanja[0];
	el=elementi[0];
	for(i=0; i<vel; i++) {
		if(max_p<ponavljanja[i]) {
			max_p=ponavljanja[i];
			max_i=i;
		}
		else if(max_p==ponavljanja[i]) {
			if(elementi[i]<elementi[max_i]) max_i=i;
		}
	}
	return elementi[max_i];
}
int izbaci_kolone (int matrica[100][100], int visina, int sirina, int broj) {
	int i,j,k,l;
	for(i=0;i<visina;i++) {
		for(j=0;j<sirina;j++) {
			if(matrica[i][j]==broj) {
				for(k=0;k<visina;k++) {
					for(l=j;l<sirina-1;l++) {
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
int main() {
	int mat[100][100],redovi,kolone,i,j,prolaz,element;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&kolone,&redovi);
	for(i=0;i<redovi;i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<kolone;j++) {
			scanf("%d",&mat[i][j]);
		}
	}
	prolaz=1;
	while(kolone!=0) {
		element=max(mat,redovi,kolone);
		kolone=izbaci_kolone(mat,redovi,kolone,element);
		if(kolone==0) break;
		printf("\nNakon %d. prolaza matrica glasi:\n",prolaz);
		for(i=0;i<redovi;i++) {
			for(j=0;j<kolone;j++) {
				printf("%5d",mat[i][j]);
			}
			printf("\n");
		}
		prolaz++;
	}
	printf("\nNakon %d. prolaza matrica je prazna!",prolaz);
	return 0;
}
