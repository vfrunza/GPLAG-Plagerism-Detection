#include <stdio.h>

int main() {
	int i,j,k,n,nizX[20],nizY[20];
	char mat[20][20];
	do {
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=0||n>10)
	printf("Pogresan unos\n");
	} while (n<=0||n>10);

	for(k=0;k<n;k++) {
	printf("Unesite %d. tacku: " ,k+1);
	scanf("%d %d", &nizX[k], &nizY[k]);
    while((nizX[k]<0 || nizX[k]>19) || (nizY[k]<0||nizY[k]>19)) {
    printf("Pogresan unos\n");
    printf("\nUnesite %d. tacku: " ,k+1);
    scanf("%d %d", &nizX[k], &nizY[k]);
		}
	}
	 

	for(i=0; i<20; i++) {
		for(j=0; j<20; j++)	{
			mat[i][j]=' ';
	}
	}
	
	for(k=0; k<n; k++)	{
		for(i=0; i<20; i++)	{
			for(j=0; j<20; j++)	{

				
		if(i==nizY[k] && j==nizX[k]) 
		mat[i][j]='*';

			}
		}
	}
	
	for(i=0; i<20; i++)	{
			for(j=0; j<20; j++)	{
				printf("%c", mat[i][j]);
			}
			printf("\n");
	}
	return 0;
}
