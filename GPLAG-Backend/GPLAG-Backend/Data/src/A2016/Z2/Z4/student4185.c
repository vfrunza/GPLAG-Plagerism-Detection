#include <stdio.h>

int main() {
	int m,n,cir=1, tep=1,i,j,k;
	double mat[100][100];
	do{
	printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
	if(m>100 || n>100 || n<=0 || m<=0){printf("Pogresan unos!\n");}
	} while(m>100 || n>100 || m<=0 || n<=0);
	
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%lf", &mat[i][j]);
		}
		
		
	}
	
	for(i=1; i<m; i++)
	{
		for(j=1; j<n; j++)
		{
			if(mat[i][j]!=mat[i-1][j-1]) {  tep=0;   }
			
		}
		
		
	}
	
	for(i=1; i<m; i++)
	{
		if(mat[i][0]!=mat[i-1][n-1]){  cir=0; break;  }
		
		
		
	}
		
	if(cir && tep){ printf("Matrica je cirkularna ");   }
	else if(tep && cir==0) { printf("Matrica je Teplicova ");}
	else  { printf("Matrica nije ni cirkularna ni Teplicova");}
	

	
	return 0;
}
