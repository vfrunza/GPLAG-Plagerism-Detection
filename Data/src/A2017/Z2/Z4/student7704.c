#include <stdio.h>

int main() {
	
int m,n,i,j,I,J,brojacA,brojacB,brojacC,clan,logicki=1;
int matA[101][101];
int matB[101][101];
int matC[101][101];
do
{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	
} while(m<0 || m>100 || n<0 || n>100 );
printf("Unesite clanove matrice A: ");
for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	scanf("%d",&matA[i][j]);
}
printf("Unesite clanove matrice B: ");
for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	scanf("%d",&matB[i][j]);
}
printf("Unesite clanove matrice C: ");
for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	scanf("%d",&matC[i][j]);
}
for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	{
		clan=matA[i][j];
		brojacA=0;
		brojacB=0;
		brojacC=0;
		for(I=0;I<m;I++)
		{
			for(J=0;J<n;J++)
			{
				if(matA[I][J]==clan)brojacA++;
				if(matB[I][J]==clan)brojacB++;
				if(matC[I][J]==clan)brojacC++;
			}
		}
	if(brojacA!=brojacB || brojacA!=brojacC)
	 	{ 
	 		printf("NE\n");
	 		return 1;
		 }
	}
}
if(logicki==1) printf("DA\n");
	return 0;
}
