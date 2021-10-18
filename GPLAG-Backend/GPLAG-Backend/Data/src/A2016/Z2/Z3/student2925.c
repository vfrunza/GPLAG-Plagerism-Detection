#include <stdio.h>

int main() {
	int mat[20][20];
	int n,i,j,x,y;
	for(i=0; i<20; i++)
	for(j=0; j<20; j++)
	mat[i][j]=0;
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	while(n<=0 || n>10)
	{
		printf("Pogresan unos\n");
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	}
	for(i=0;i<n;i++)
	{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d%d",&x,&y);
		if(x>=0 && x<20 && y<20 && y>=0)mat[y][x]=1;
		else
		{
			printf("Pogresan unos\n");
			i--;
		}
	}
	for(i=0; i<20; i++)
	{ 
	for(j=0; j<20; j++)
	   if(mat[i][j]==1) printf("*");
	   else  printf(" ");
	
	printf("\n");
	}
	return 0;
}
