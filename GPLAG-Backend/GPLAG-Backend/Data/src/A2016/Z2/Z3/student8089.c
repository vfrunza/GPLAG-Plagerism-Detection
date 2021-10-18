#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	char mat[20][20];
	int i,j,k1,k2,n,b=1;
	for (i=0;i<20;i++){
		for(j=0;j<20;j++){
			mat[i][j]=' ';
		}
	}
	

			
			do {
				printf("Unesite broj tacaka: ");
				scanf("%d",&n);
				if(n<=0 || n>10){
				printf("Pogresan unos\n");}
				else
				break;
				}while(1);
			for (b=0;b<n;b++){
				printf("Unesite %d. tacku: ",b+1);
				scanf("%i %i",&k2,&k1);
				while (k1<0 || k1>19 || k2<0 || k2>19) {
					printf("Pogresan unos\n");
					printf("Unesite %d. tacku: ",b+1);
					scanf("%i %i",&k1,&k2);
				}
				
						mat[k1][k2]='*';
					}
			
                  
                for(i=0;i<20;i++){
                	for(j=0;j<20;j++){
                		printf("%c",mat[i][j]);
                	}
                	printf("\n");
                }
					
	
	return 0;
}
