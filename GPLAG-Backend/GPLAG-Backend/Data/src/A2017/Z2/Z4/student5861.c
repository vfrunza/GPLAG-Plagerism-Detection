#include <stdio.h>

int main() {
	int matA[100][100], matB[100][100], matC[100][100];
	int i, j, a, b, ii, jj;
	int tmpB, tmpC, brojacB=0,brojacC=0,brojacAC=0,brojacAB=0;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &a, &b);
	}while((a<0) || (b<0) || (a>100) || (b>100));
	
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<a;i++)
	for(j=0;j<b;j++)
	scanf("%d",&matA[i][j]);
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<a;i++)
	for(j=0;j<b;j++)
	scanf("%d",&matB[i][j]);
	
	printf("Unesite clanove matrice C: ");
	for(i=0;i<a;i++)
	for(j=0;j<b;j++)
	scanf("%d",&matC[i][j]);
	
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			ii=i;
			jj=j;
			tmpB=matB[ii][jj];
			
			for(i=0;i<a;i++){
				for(j=0;j<b;j++){
					if(matB[i][j]==tmpB)
					brojacB++;
				}
			}
			tmpC=matC[ii][jj];
			for(i=0;i<a;i++){
				for(j=0; j<b;j++){
					if(matC[i][j]==tmpC)
					brojacC++;
				}
			}
			for(i=0;i<a;i++){
				for(j=0;j<b;j++){
					if(matA[i][j]==tmpB)
					brojacAB++;
					if(matA[i][j]==tmpC)
					brojacAC++;
			}
			
		}
		
		if((brojacB!=brojacAB) || (brojacC!=brojacAC))
		{
			printf("NE"); 
			return 1;
		}
		
		brojacAC=0;
		brojacC=0;
		brojacAB=0;
		brojacB=0;
		i=ii;
		j=jj;
		}
		
	}
		printf("DA");
	return 0;
}
