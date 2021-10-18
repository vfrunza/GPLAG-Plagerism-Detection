#include <stdio.h>

int main() {
	
	float matA[100][100],matB[100][100],pomocna[100][100];
	int i,j,vis_A,sir_A,vis_B,sir_B,jednaka=1;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sir_A,&vis_A);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<vis_A; i++){
		for(j=0; j<sir_A; j++){
			scanf("%f",&matA[i][j]);
		}
		
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sir_B,&vis_B);
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<vis_B; i++){
		for(j=0; j<sir_B; j++){
			scanf("%f",&matB[i][j]);
		}
		
	}	
	for(i=0; i<sir_A; i++){
		for(j=0; j<vis_A; j++){
			pomocna[i][j]=matA[vis_A-1-j][i];
		}
	}
	 
	 for(i=0; i<vis_B; i++){
		for(j=0; j<sir_B; j++){
			if(matB[i][j] != pomocna[i][j]) jednaka = 0; break;
		}
	}
	if (jednaka == 0) printf("NE\n");
	else if(jednaka == 1) printf("DA\n");

	return 0;
}
