#include <stdio.h>

int main() {
	int m,n,i,j,tep,cirk,k,ima;
	double mat[100][100];
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(m<1 || m>100 || n<1 || n>100)
		{
			printf("Pogresan unos!\n");
		}
	} while(m>100 || m<1 || n>100 ||n<1);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf ",&mat[i][j]);
		}
	}
	tep = 1; cirk=1;
	for(i=0;i<m-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(mat[i][j] != mat[i+1][j+1])
			{
				tep=0;
				cirk=0;
			}
		}
	}
	if(tep==0 && cirk==0)
	{
		printf("Matrica nije ni cirkularna ni Teplicova");
		return 0;
	}
	if(m==1)
	{
		printf("Matrica je cirkularna");
		return 0;
	}
	else if(n==1)
	{
		printf("Matrica je Teplicova");
		return 0;
	}
	for(i=0;i<m-1;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=m-1 && j!=n-1)
			{
				if(mat[i][j] != mat[i+1][j+1]) cirk=0;
			}
			else if(j=n-1)
			{
				if(mat[i][j] != mat[i+1][0]) cirk=0;
			}
		}
	}
	if(cirk==0) printf("Matrica je Teplicova");
	else printf("Matrica je cirkularna");
	return 0;
}
