#include <stdio.h>

int main() {
	int m,n,i,j;
	int jesteteplicova=1;
	int jestecirkularna=1;
	printf("Unesite M i N: ");
	do{
		scanf("%d %d",&m,&n);
		if(m<=0 || m>100 || n<=0 || n>100) { printf("Pogresan unos!\n");
		                                   printf("Unesite M i N: ");
		}
	} while(m<=0 || m>100 || n<=0 || n>100);
 float mat[100][100];
 printf("Unesite elemente matrice: ");
   for(i=0;i<m;i++){
 	 for(j=0;j<n;j++)
         	scanf("%f",&mat[i][j]);
   }
    for(i=0;i<m-1;i++) {
   	for(j=0;j<n-1;j++) {
   		if(mat[i][j]!=mat[i+1][j+1])  jesteteplicova=0;
   	}
   	
   }
    for(i=0;i<m;i++) {
   	for(j=0;j<n;j++) {
   		
   		if ( i!=0 && mat[i][0]!=mat[i-1][n-1])  jestecirkularna=0;
   		
   	}
   }
   if (jestecirkularna==1 && jesteteplicova==1) printf("Matrica je cirkularna");
   else if(jesteteplicova==1 && jestecirkularna==0) printf("Matrica je Teplicova");
   else printf("Matrica nije ni cirkularna ni Teplicova");
   
   
	return 0;
}
