#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

int main() {
	
	double matrica[100][100]={{0}};
	int i, j, m, n;
	int teplicova=1, cirkularna=1; 
	
	do 
	{
		printf("Unesite M i N: ") ; 
		scanf("%d %d", &m, &n);
		if(m <= 0 || m > 100 || n <= 0 || n > 100)
		printf("Pogresan unos!\n");
	}
	while(m <= 0 || m > 100 || n <= 0 || n > 100); 

	printf("Unesite elemente matrice: ");
	for(i=0; i < m; i++) 
		for(j=0; j < n; j++)
			scanf("%lf", &matrica[i][j]);
			
	for(i = 0; i < m-1; i++)
	{ 
		for(j = 0; j < n-1; j++)
		 { 
		 	if(fabs(matrica[i][j] - matrica[i+1][j+1])>epsilon) { teplicova=0; break; }
		 }
	}
			
	for(i = 1; i < m; i++)
		{
			if(fabs(matrica[i-1][n-1] - matrica[i][0])>epsilon) cirkularna = 0;
		
			for(j = 1; j < n; j++) 
				if(fabs(matrica[i-1][j-1] - matrica[i][j])>epsilon) cirkularna = 0;
		}
	
	if(cirkularna) { printf("Matrica je cirkularna"); }
	else if(teplicova) { printf("Matrica je Teplicova"); }
	else { printf("Matrica nije ni cirkularna ni Teplicova"); }
	return 0;
}
