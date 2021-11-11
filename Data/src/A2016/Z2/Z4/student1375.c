#include <stdio.h>

int main() {
	float mat[100][100];
	int i, j, m, n, teplicova, cirkularna;
	
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		if((m>100 || m<=0) ||( n>100 || n<=0)) printf("Pogresan unos!\n");
	}while((m>100 || m<=0) || (n>100 || n<=0));
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
	for(j=0; j<n; j++) scanf("%f", &mat[i][j]);
    if(m==1) printf("Matrica je cirkularna");
    else if(n==1) printf("Matrica je Teplicova");
	else {
	teplicova=1;
	
	for(i=0; i<m-1; i++)
	{
		for(j=0; j<n-1; j++) 
		{   
			if(mat[i][j]!=mat[i+1][j+1]) { teplicova=0;  }
		}
	}
    if(teplicova==0) printf("Matrica nije ni cirkularna ni Teplicova");
    
    else {cirkularna=1;
	for(i=1; i<m; i++)
	{ 
		for(j=1; j<n; j++)
		{
			if(mat[i][0]!=mat[i-1][n-1] || mat[i][j]!=mat[i-1][j-1]) {cirkularna=0; }
			
		}
	}
    if(cirkularna==0)	printf("Matrica je Teplicova");
    
	if(cirkularna) printf("Matrica je cirkularna"); } }
	
	
	return 0;
}
