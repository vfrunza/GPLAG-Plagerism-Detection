#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	float A[100][100],B[100][100];
	int SA,VA,SB,VB,i,j;
	
	do{
		printf("Unesite sirinu i visinu matrice A: ");
		scanf("%d %d", &SA,&VA);
	}
	while(SA<0 || VA <0 || VA > 100 || SA > 100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<VA;i++)
	{
		for(j=0;j<SA;j++)
		{
			scanf("%f", &A[i][j]);
		}
	}	
	
		do{
			printf("Unesite sirinu i visinu matrice B: ");
			scanf("%d %d", &SB,&VB);
		} 	while(SB<0 || VB <0 || VB > 100 || SB > 100);
			printf("Unesite clanove matrice B: ");
			for(i=0;i<VB;i++)
		{
			for(j=0;j<SB;j++)
			{
				scanf("%f",&B[i][j]);
			}
		}
		
		if(SA!=VB || VA!=SB) {printf("NE"); return 0;}
		
		for(i=0;i<VA;i++)
		{
				for(j=0;j<SA;j++)
				{
					if( fabs(A[i][j] - B[j][SB-1-i])>0.0001) {printf("NE"); return 0;}
				}
		}
		printf("DA");
		return 0;
}
