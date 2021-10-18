#include <stdio.h>

int main() {
	int sirA,visA,i,j;
	int matA1[100][100],matA2[100][100];
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&visA,&sirA);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<visA;i++) {
		for(j=0;j<sirA;j++) scanf("%d", &matA1[i][j]);
	}
	
	//KOPIRANJE ELEMENATA
	for(i=0;i<visA;i++) {
		for(j=0;j<sirA;j++) matA2[i][j]=matA1[i][j];
	}
	
	//PREBACIVANJE
	for(i=0;i<visA;i++) {
		for(j=0;j<sirA;j++) matA1[j][sirA-i-1]=matA2[i][j];
	}
	
	for(i=0;i<visA;i++) {
		for(j=0;j<sirA;j++) printf("%d ",matA1[i][j]);
	}
	
	return 0;
}
