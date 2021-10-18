#include <stdio.h>

int main() {
	int i, j, sirinaA, visinaA, sirinaB, visinaB, br=1;
	float matA[10][10], rotA[10][10], matB[10][10];
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sirinaA,&visinaA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visinaA; i++){
	    for(j=0; j<sirinaA; j++)
	        scanf("%f",&matA[i][j]);
	    }

	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sirinaB,&visinaB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visinaB; i++){
	    for(j=0; j<sirinaB; j++)
	        scanf("%f",&matB[i][j]);
	    }
	    
	if(visinaA!=sirinaB || sirinaA!=visinaB){
		printf("NE");
		return 0;
	}
	
	for(i=0; i<sirinaA; i++){
		for(j=0; j<visinaA; j++){
		   rotA[i][j]=matA[visinaA-1-j][i];
		   if(matB[i][j]!=rotA[i][j]) br=0;
		}
	}
	
	
	if(br==0) printf("NE");
	else printf("DA");
	return 0;
}
