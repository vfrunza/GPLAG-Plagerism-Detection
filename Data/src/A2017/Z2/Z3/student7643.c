#include <stdio.h>

int main (){
	int i,j,SA,SB,VA,VB, rotirana;
	float matA[100][100], matB[100][100];
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&SA, &VA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<VA; i++){
		for(j=0; j<SA; j++){
			scanf("%f", &matA[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &SB, &VB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<VB; i++){
		for(j=0; j<SB; j++){
			scanf("%f", &matB[i][j]);
		}
	}

	rotirana=1;
	for(i=0; i<VA; i++){
		rotirana=1;
		for(j=0; j<SA; j++){
			if(matA[i][j]!=matB[j][VA-i-1]) 
			rotirana=0;
	  }
     break;
	}
	if(rotirana) printf("DA");
	else printf("NE");
	return 0;
	
}