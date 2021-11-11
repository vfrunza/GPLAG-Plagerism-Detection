#include <stdio.h>
int main() {
	int nesto=0;
	int isti=1;
	int matrica[20][20];
	int broj_redova,broj_kolona;
	int j,k,l,m;
	int i=0;
	do{
		if(i==0){
			printf("Unesite brojeve M i N: ");
			scanf("%d %d",&broj_redova,&broj_kolona);
			i=5;
		}
		else {
			printf("Brojevi nisu u trazenom opsegu.\n");
			printf("Unesite brojeve M i N: ");
			scanf("%d %d",&broj_redova,&broj_kolona);
		}
	}while(broj_redova<=0 || broj_kolona<=0 || broj_kolona>200 || broj_redova>200);
	
	printf("Unesite elemente matrice: ");
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<broj_redova;i++){
		for(j=0;j<broj_kolona;j++){
			scanf("%d",&matrica[i][j]);
		}
	}

	for(i=0;i<broj_redova;i++){
		for(k=i+1;k<broj_redova;k++){
			isti=1;
			for(j=0;j<broj_kolona;j++){
				if((matrica[i][j])!=(matrica[k][j])) {
					isti=0;
				}
			}
		if(isti==1){
				for(j=k;j<broj_redova;j++){
					for(l=0;l<broj_kolona;l++){
						matrica[j][l]=matrica[j+1][l];

					}
				}
				k--;
				broj_redova--;
			}
		}
	}
	
	
	for(i=0;i<broj_kolona-1;i++){
		for(j=i+1;j<broj_kolona;j++){
			isti=1;
			for(k=0;k<broj_redova;k++){
				if((matrica[k][i])!=(matrica[k][j])) {
					isti=0;
				}
			}
			if(isti==1){
				for(m=j;m<broj_kolona;m++){
					for(l=0;l<broj_redova;l++){
						matrica[l][m]=matrica[l][m+1];
					}
				}
				j--;
				broj_kolona--;
			}
		}
	}

	for(i=0;i<broj_redova;i++){
		for(j=0;j<broj_kolona;j++){
			printf("%5d",matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
	}
