#include<stdio.h>

int main() {
	
	int m,n;
	int i,j;
	int cir=1, tep=1;	
	double mat[100][100];
	
	do{printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
	
	if(m>100||n>100||m<=0||n<=0)
	printf("Pogresan unos!\n");
		

	}
	while(m>100||n>100||m<=0||n<=0);
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<m; i++){
		for(j=0;j<n;j++){
			
			scanf("%lf", &mat[i][j]);
			
		}
	}
	
	
	
	
	for(i=0;i<m-1;i++){
		
		if(mat[i][n-1]!=mat[i+1][0]) cir=0;
		
		for(j=0;j<n-1;j++){
			
			if(mat[i][j]!=mat[i+1][j+1]){tep=0; cir=0;}
			
		}}
	
	
	if(cir==1) printf("Matrica je cirkularna");
	else if(tep==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	
	
	
	return 0;
}