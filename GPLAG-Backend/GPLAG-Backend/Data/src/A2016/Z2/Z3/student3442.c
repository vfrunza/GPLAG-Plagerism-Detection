#include <stdio.h>

int main() {
	
	int n,j,i,X[20],Y[20],A[20][20] = {0};
	
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		
		if(n<=0 || n>10){
			printf("Pogresan unos\n");
			continue;
		} else break;
		
	}while(1);
	
	for(i=0; i<n; i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&X[i],&Y[i]);
		
		if(X[i]<0 || X[i]>19 || Y[i]<0 || Y[i]>19){
			printf("Pogresan unos\n");
			i--;
			continue;
		}
	}
	
	for(i=0;i<n;i++){
		A[X[i]][Y[i]]=5;
	}
	
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if(A[j][i]==5){
				printf("*");
			}
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
