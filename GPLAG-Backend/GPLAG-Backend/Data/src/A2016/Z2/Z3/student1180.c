#include <stdio.h>

int main() {
	int i,j,n,a,b;
	int mat[20][20]={{0}};
	
	do{
	    printf("Unesite broj tacaka: ");
    	scanf("%d", &n);
    	if(n>10 || n<=0) printf("Pogresan unos\n");
	}while(n>10 || n<=0);

	
	for(i=0;i<n;i++){
	    printf("Unesite %d. tacku: ", i+1);
	    scanf("%d %d", &a,&b);
	        if(a<0 || a>=20 || b<0 || b>=20) {
	            printf("Pogresan unos\n");
	            i--;
	        }
	        else mat[b][a]=1;
	        
	}
	   
	    for(i=0;i<20;i++){
			for(j=0;j<20;j++){
				if(mat[i][j]==1)  printf("*");
				else printf(" ");
			}
			printf("\n");
	    }
	
	
	return 0;
}
