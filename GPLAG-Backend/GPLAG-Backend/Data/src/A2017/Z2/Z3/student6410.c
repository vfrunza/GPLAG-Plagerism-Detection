#include <stdio.h>

int main()
{
	int vA,sA,sB,vB,i,j,matA[100][100],matB[100][100],mat[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sA,&vA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<vA; i++) {
		for(j=0; j<sA; j++) {
			scanf("%d", &matA[i][j]);
		}
	}
  

	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sB,&vB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<vB; i++) {
		for(j=0; j<sB; j++) {
			scanf("%d", &matB[i][j]);
		}
	}
 if(vA!=sB || sA!=vB) {printf("NE\n");
  return 0;}

	for(i=0; i<sA; i++) {
		for(j=0; j<vA; j++) {
			mat[i][j]=matA[vA-1-j][i];
		}
	} 
	
	for(i=0; i<vB; i++) {
		for(j=0; j<sB; j++) {
			if(matB[i][j]!=mat[i][j] ){ printf("NE\n");return 0;}
		}
	}
	
	

	
		printf("DA\n");

	return 0;
}
