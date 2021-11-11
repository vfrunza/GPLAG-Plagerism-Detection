#include <stdio.h>

int main() {
	
	int m,n,i,j;
	double mat[100][100];
	int teplicova=1;
	int cirkularna=1;
	
	do{
		printf("\nUnesite M i N: ");
		scanf("%d%d", &m,&n);
		if(m<1 || n<1 || m>100 || n>100) printf("Pogresan unos!");
	} while(m<1 || n<1 || m>100 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%lf", &mat[i][j]);
		}
	}
	
for(i=0;i<m-1;i++)
{
		for(j=0;j<n-1;j++)
		{
			if((mat[i][j]!=mat[i+1][j+1]) || (mat[m-1][n-1]!=mat[m-2][n-2]) )
					teplicova=0;
					break;
		}
	}
	
	
	for(i=0;i<m-1;i++)
	{
		for(j=0;j<n-1;j++)
		if( (mat[i][j]!=mat[i+1][j+1]) || (mat[i][n-1]!=mat[i+1][0]) )
		{
			cirkularna=0;
			break;
		}
	}

if(teplicova==1 && cirkularna==1) printf("Matrica je cirkularna");
 else if(teplicova) printf("Matrica je Teplicova");
 else if(teplicova==0) printf("Matrica nije ni cirkularna ni Teplicova");
 
	
	
	return 0;
}
