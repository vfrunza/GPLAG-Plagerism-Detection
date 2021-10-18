#include <stdio.h>

int main() {
	int sistem[20][20],n=0,i,j,x,y;
	do
	{
	     printf("Unesite broj tacaka: ");
	     scanf("%d",&n);
	     if (n>10 || n<=0)
	     printf("Pogresan unos\n");
	} while (n>10 || n<=0);

	for (i=0;i<20;i++)
	{
		for (j=0;j<20;j++)
		{
			sistem[i][j]=' ';
		}
	}

	for (i=0;i<n;i++)
	{
		do
		{
			printf("Unesite %d. tacku: ",i+1);
		    scanf("%d%d",&x,&y);
		    if (x<0 || y<0 || x>19 || y>19)
		    {
		     	printf("Pogresan unos\n");
	      	}
		} while (x<0 || y<0 || x>19 || y>19);
		
		sistem[x][y]='*';
	}
	
	for (i=0;i<20;i++)
	{
		for (j=0;j<20;j++)
		{
		printf("%c",sistem[j][i]);
		}
		printf("\n");
	}
	return 0;
}
