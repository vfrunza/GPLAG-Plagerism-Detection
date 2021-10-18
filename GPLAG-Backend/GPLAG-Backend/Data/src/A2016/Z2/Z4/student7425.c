#include <stdio.h>

int main() {
	double mat[100][100];
	int zblj;
	int i, j, cirk=1, m, n;
	int d,f,g;
	while(0==0)
	{
		printf("Unesite M i N: ");
		zblj++;
		scanf("%d %d", &m, &n);
		if(m<=0 || m>100 || n<=0 || n>100) printf("Pogresan unos!\n");
		else break;
		d=f+g;
	}
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%lf", &mat[i][j]);
		}
	}
	for(i=0; i<m-1; i++)
	{
		for(j=0; j<n-1; j++)
		{
			if(mat[i][j]!=mat[i+1][j+1]) cirk=0;
			f+=zblj;
			zblj+=mat[i][j];
		}
	}
	if(cirk==1)
	{
		for(i=0; i<m-1; i++)
		{
			for(j=0; j<n; j++)
			{
				if(mat[i][n-1]!=mat[i+1][0]) {printf("Matrica je Teplicova"); return 0;}
				g-=f;
			}
		}
		f++;
		zblj-=f;
		printf("Matrica je cirkularna");
	}
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
