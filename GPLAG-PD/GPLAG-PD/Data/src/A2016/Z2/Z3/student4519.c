#include <stdio.h>

int main() {
	int n,i,j,x,y;
	int matrix[20][20]={{0}};
	
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	while(n<1 || n>10){
	     printf("Pogresan unos ");
	     printf("\nUnesite broj tacaka: ");
	     scanf("%d",&n);
	}
	
	for(i=1; i<=n; i++){
	     printf("Unesite %d. tacku: ", i);
	     scanf("%d %d",&x,&y);
         while((x<0 || x>19) || (y<0 || y>19)) {
               printf("Pogresan unos \n");
	           printf("Unesite %d. tacku: ", i);
	           scanf("%d %d",&x,&y);
         }
	  matrix[y][x]=1;
	}
	
	for(i=0; i<20; i++){
	   for(j=0; j<20; j++)
	      if(matrix[i][j]==1) printf("*");
	      else printf(" ");
	   printf("\n");   
	}

	return 0;
}
