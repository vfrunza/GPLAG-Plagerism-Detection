#include <stdio.h>
#define a 100 
int main() {
	int i,j,m,n,k=0,c=0;
	double b[a][a]={0};
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
	if(m<=0 || m>100 || n<=0 || n>100) printf("Pogresan unos!\n");
		}while(m<=0 || m>100 || n<=0 || n>100);
		
		
		printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		scanf("%lf",&b[i][j]);
		
		}
	}for(i=0;i<m-1;i++){
		if(b[i][n-1]==b[i+1][0]) c++;
		for(j=0;j<n-1;j++){
		if(b[i][j]==b[i+1][j+1]) c++;
		if(b[i][j]==b[i+1][j+1]) k++;
		
		}
	}
	if(c==(m-1)*n) printf("Matrica je cirkularna\n");
	else if(k==(m-1)*(n-1)) printf("Matrica je Teplicova\n");
	else printf("Matrica nije ni cirkularna ni Teplicova\n");
			
		
	return 0;
}
