#include <stdio.h>


int main() {
	int mat[20][20];
	int x,y,i,j,n;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			mat[i][j]=0;
		}
	}
    printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	while(n>10 ||n<=0){
		printf("Pogresan unos\n");
    printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	}

	for(i=0;i<n;i++)
	{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d%d",&x,&y);
		if(x<0 || x>=20 || y<0 || y>=20)
		{
			printf("Pogresan unos\n");
			i--;
			continue;
		}
		mat[y][x]=1;
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(mat[i][j]==1)printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
