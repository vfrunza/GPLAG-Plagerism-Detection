#include <stdio.h>

int main() {
	int i,j,b,k,sk,r;
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&r);
	} while(r<=0 || r>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&k);
	} while(k<=0 || k>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sk);
	} while (sk<=0 || sk>10 );
	
	for(b=0; b<r; b++){
		
	printf("+");
		for(i=0; i<k; i++){
			for(j=0; j<sk; j++)
			printf("-");
		printf("+");
		}
	printf("\n");
	printf("|");
	    for(i=0; i<k; i++){
		   for(j=0; j<sk; j++)
		   printf(" ");
	    printf("|");
	}
	printf("\n");
	}
	printf("+");
	for(i=0; i<k; i++){
		for(j=0; j<sk;j++)
		printf("-");
	printf("+");
		}
	return 0;
}
