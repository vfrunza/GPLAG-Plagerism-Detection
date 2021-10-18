#include <stdio.h>

int main() {
	double mat[100][100];
	int m,n,i,j,c=0,t=1,ct;
	
	do{
	    printf("Unesite M i N: ");
	    scanf("%d %d",&m,&n);
	    if(m<=0 || n<=0 || m>100 || n>100){printf("Pogresan unos!\n");}
	}while(m<=0 || n<=0 || m>100 || n>100);
	
	printf("Unesite elemente matrice: ");

	for(i=0;i<m;i++){
	    for(j=0;j<n;j++){
	        scanf("%lf",&mat[i][j]);
	    }
	
		
	}
	
	if(m==1){c=1;}
	else{
		for(i=0;i<m-1;i++){
			for(j=0;j<n-1;j++){
				if(mat[i][j]==mat[i+1][j+1]){t=1;ct=0;}
				else{ct=1;t=0;break;}
			}
		}
		
		if(t==1){
			for(i=0;i<m-1;i++){
				if(mat[i][n-1]==mat[i+1][0]){c=1;}
				else{c=0;break;}
			}
		}
	}
	
	if(c==1){printf("Matrica je cirkularna");}
	else if(t==1){printf("Matrica je Teplicova");}
	else if(ct==1){printf("Matrica nije ni cirkularna ni Teplicova");}
	
	
	
	
	
	
	return 0;
}
