#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int mat[20][20]={{0}},i,j,n;
	int x,y;
    
	    
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if (n<=0 || n>10) 
		printf("Pogresan unos\n");
	
	}while (n<=0 || n>10);
          for(i=0; i<n; i++){
          printf("Unesite %d. tacku: ",i+1);
          scanf("%d%d",&x,&y);
           if(x<0 || x>=20 || y<0 || y>=20){
           	printf("Pogresan unos\n");
           	i--;
            }
            else mat[x][y]=1;
          }	  
		  for(i=0;i<20;i++){
		  	for(j=0;j<20;j++){
		  		if (mat[j][i]==1) printf("*");
		  		else printf(" ");
		  	}
		  	printf("\n");
		   }
		 
		  return 0;
	
}
