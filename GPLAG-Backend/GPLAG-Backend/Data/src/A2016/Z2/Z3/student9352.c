#include <stdio.h>
#define visina 20
#define sirina 20

int main() 
{
	int x,y,m,n,i,j,mat[visina][sirina]={0};
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	while(n>10 || n<1)
	{
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
	}
	for(m=1;m<=n;m++)
	{
		printf("Unesite %d. tacku: ",m);
		scanf("%d %d",&x,&y);
		while(x<0 || x>visina-1 || y<0 || y>sirina-1)
		{
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ",m);
	    	scanf("%d %d",&x,&y);
		}
		mat[x][y]=1;
	}
	for(i=0;i<sirina;i++)
	{
		for(j=0;j<visina;j++)
		{
			if(mat[j][i]==1)
			printf("*");
			else
			printf(" ");
		}
		printf("\n");
	}

	return 0;
}
