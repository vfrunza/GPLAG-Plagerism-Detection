#include <stdio.h>

int main() {
	int n,m;
	do
	{
	 printf("Unesite M i N: ");
	 scanf("%d %d",&m,&n);
	 if(n<=0 || n>100 || m<=0 || m>100)
	 {
	 	printf("Pogresan unos!\n");
	 }
	}
	while(n<=0 || n>100 || m<=0 || m>100);
	float mat[100][100];
	printf("Unesite elemente matrice: ");
	float unos=0;
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%f",&unos);
			mat[i][j]=unos;
		}
	}
	int postoji=1;
	for(i=1;i<m;i++)
	{
		if(mat[i][0]!=mat[i-1][n-1] || mat[i][1]!=mat[i-1][0])
		{
			postoji=0;
			break;
			for(j=2;j<n;j++)
			{
				if(mat[i][j]!=mat[i-1][j-1])
				{
					postoji=0;
					break;
				}
			}
			if(postoji==0)
			{
				break;
			}
		}
	}
	
	if(postoji==1)
	{
		printf("Matrica je cirkularna");
	}
	return 0;
}
