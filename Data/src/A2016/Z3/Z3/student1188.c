#include <stdio.h>
int main() {
	int broj_m,broj_n,matrica[200][200],i,j,k,prvi,jednaki;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&broj_m,&broj_n);
			if((broj_m<=0)||(broj_m>200)||(broj_n<=0)||(broj_n>200))
			printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while((broj_m<=0)||(broj_m>200)||(broj_n<=0)||(broj_n>200));
	
	printf("Unesite elemente matrice: ");
	for(i=0 ; i<broj_m; i++){
		for(j=0; j<broj_n; j++){
			scanf("%d",&matrica[i][j]);
		}
	}
	/*Izbacivanje istog reda*/
	for(prvi=0; prvi<broj_m; prvi++){
	
		for(i=prvi+1; i<broj_m; i++){
			jednaki=1;
		
			for(j=0; j<broj_n; j++){
				if(matrica[prvi][j]!=matrica[i][j])
					jednaki=0;
			}
			if(jednaki){
				for(k=i; k<broj_m-1; k++){
					for(j=0; j<broj_n; j++){
						matrica[k][j]=matrica[k+1][j];
					}
				}
				i--;
				broj_m--;
			}
		}
	}	
	/*Izbacivanje istih kolona*/
	for(prvi=0; prvi<broj_n; prvi++){
	
		for(j=prvi+1; j<broj_n; j++){
			jednaki=1;
		
			for(i=0;i<broj_m; i++){
				if(matrica[i][prvi]!=matrica[i][j])
					jednaki=0;
			}
			if(jednaki){
				for(i=0; i<broj_m; i++){
					for(k=j; k<broj_n-1; k++){
						matrica[i][k]=matrica[i][k+1];
					}
				}
				j--;
				broj_n--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
		for(i=0; i<broj_m; i++){
			printf("");
			for(j=0; j<broj_n; j++){
				printf("%5d",matrica[i][j]);
			}
			printf("\n");
		}
	
	return 0;
}
