#include <stdio.h>

int main() {
	int m,n,i,j, temp=1,cir=1; 
	double mat[100][100];
	do {
	printf("Unesite M i N: ");
	scanf("%d%d",&m,&n);
	if (m<=0 || m>=101 || n<=0 || n>=101)
	printf("Pogresan unos!\n");}
	while (m<=0 || m>=101 || n<=0 || n>=101);
	printf("Unesite elemente matrice: ");
		for (i=0;i<m;i++)
		{	for (j=0;j<n;j++)
			scanf("%lf",&mat[i][j]);}
			
	{ for (i=0;i<m-1;i++) 
		{for (j=0;j<n-1;j++)
			 if (mat[i][j]!=mat[i+1][j+1]) temp=0;}	}
			 
	if (temp==1){
		for (i=0;i<m-1;i++) 
		{for (j=0;j<n;j++)		
			{if  (mat[i][n-1]!=mat[i+1][0]) cir=0;}}}
			 
	if (temp==0) cir=0;
	if (cir==1) printf("Matrica je cirkularna");
	else if (temp==1) printf("Matrica je Teplicova");
	else printf ("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;}
