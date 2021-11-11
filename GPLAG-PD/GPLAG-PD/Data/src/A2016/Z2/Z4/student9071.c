#include <stdio.h>

int main() {
    double matrix[100][100]={{0}};
	int m=0,n=0,teplicova=0,cirkularna=0,i=0,j=0;
	do{
	    printf("Unesite M i N: ");
	    scanf("%d %d",&m,&n);
	    if (m>100||n>100||m<1||n<1){
	    printf("Pogresan unos!\n");
	    }
	}while(m>100||n>100||m<1||n<1);
	
	printf("Unesite elemente matrice: ");
		for(i=0;i<m;i++){           
	       for(j=0;j<n;j++){
	           scanf("%lf",&matrix[i][j]);
	       }
		}
	//radi do ovde

	for(i=0;i<m-1;i++){           //testiranje uslova da li je teplicova matrica
	    for(j=0;j<n-1;j++){
	        if (matrix[i][j]==matrix[i+1][j+1]){
	            teplicova=1;
	        } else {
	            teplicova=0;
	            break;
	        }
	        
	    }
	}
	
		for(i=0;i<m-1;i++){           //testiranje uslova da li je cirkularna matrica
	        for(j=0;j<n;j++){
	            if (matrix[i][n-1]==matrix[i+1][0]){
	            cirkularna=1;
	        } else {
	            cirkularna=0;
	            goto van;
	            
	        }
	        
	    }
	}
	van:
	
	if (m==1){
		cirkularna=1;
		teplicova=1;
	} else if (n==1){
		teplicova=1;
	}
	
	if ((cirkularna==1)&&(teplicova==1)){
	    printf("Matrica je cirkularna");
	}
	else if (teplicova==1){
	    printf("Matrica je Teplicova");
	}
	else {
	    printf("Matrica nije ni cirkularna ni Teplicova");
	}
	
	
	
	
	
	return 0;
}
