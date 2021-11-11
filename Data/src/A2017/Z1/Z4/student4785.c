#include <stdio.h>

int main() {
	int r,k,s;
	int i,j;
	
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&r);
	} while (r<1 || r>10);
	
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&k);
	} while (k<1 || k>10);
	
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&s);
	} while (s<1 || s>10);
	
	for (i=0;i<r*2+1;i++){
		for (j=0;j<k*(s+1)+1;j++){
			if (i%2==0){
				if(j%(s+1)==0){
					printf("+");
				}
				else{
					printf("-");
				}
			}
			else {
				if(j%(s+1)==0){
					printf("|");
				}
				else{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
