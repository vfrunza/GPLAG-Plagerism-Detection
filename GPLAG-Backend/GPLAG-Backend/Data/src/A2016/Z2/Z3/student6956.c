#include <stdio.h>

int main() {
	int x[20]={0}, y[20]={0},mat[20][20]={{0}};
	int i,j, n=1, k;
 	do {
 	 	if (n>10 || n<0 || n==0) printf("Pogresan unos\n");
 	printf("Unesite broj tacaka: ");
 	scanf("%d", &n);
 } while(n<0 || n>10 || n==0);
 
		for(k=0; k<n; k++){
		printf("Unesite %d. tacku: ", k+1);
		scanf("%d %d",&x[k], &y[k]);
		if(x[k]<0 || x[k]>19 || y[k]<0 || y[k]>19) {
			printf("Pogresan unos\n"); 
			k--;
		}
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			
			for(k=0;k<n;k++){
				if(j==x[k] && i==y[k]){
					 mat[i][j]=1;
					 if(mat[i][j]){
					 printf("*");
					break;}
				}
				 	}
			  if(mat[i][j]==0) printf(" ");
		}
		printf("\n");
	}
	

	return 0;
}
