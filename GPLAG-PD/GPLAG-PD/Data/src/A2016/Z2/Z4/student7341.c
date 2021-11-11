#include <stdio.h>

int main() {
	int m,n,cirkularna=1,teplicova=1, i,j;
	double mat[100][100];


	do{printf("Unesite M i N: ");
		scanf("%d%d", &m, &n);
		if ((m<=0 || m>100)||(n<=0)||(n>100)){
			printf("Pogresan unos!\n");}
	}
	while((m<=0 || m>100)||(n<=0)||(n>100));
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&mat[i][j]);
		}
	}
	for (i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(mat[i][j]!=mat[i+1][j+1])
			teplicova=0;
		} 
	}
	if (teplicova==1){
		for(i=0;i<m-1;i++){
			for (j=0;j<n;j++){
				if (mat[i][n-1]!=mat[i+1][0])
				cirkularna=0;
			}
		}
	}
	else if (teplicova==0) cirkularna=0;
	
	if( teplicova==1 && cirkularna ==1)
	printf("Matrica je cirkularna");
	else if(teplicova==1 && cirkularna==0)
	printf("Matrica je Teplicova");
    else if ( teplicova==0 && cirkularna ==0){
    printf("Matrica nije ni cirkularna ni Teplicova");}
    
    
    return 0;
}
   
