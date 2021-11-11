#include <stdio.h>

int main() {
	int n, i, j, k, l;
	int pk[19];
	int dk[19];
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	
	if(n<=0 || n>10){
	do {
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
	
	}while(n<=0 || n>10);}
	
	for(i=0; i<=n-1; i++){
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &pk[i], &dk[i] );
		if(pk[i]<0 || pk[i]>19 || dk[i]<0 || dk[i]>19 ){
			
		do{
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &pk[i], &dk[i] );
		
		}while(pk[i]<0 || pk[i]>19 || dk[i]<0 || dk[i]>19 );}
	}
	
	for(j=0; j<20; j++){
		for(k=0; k<20; k++){
			for(l=0; l<i; l++){
				if(j==dk[l] && k==pk[l]){
					printf("*");
					break;
				}
			}
			if(l==i)
			printf(" ");
			else
			continue;
		}
		printf("\n");
	}
	return 0;
}
