#include <stdio.h>

int main() {
	int i,j,r,k;
	
	printf("Unesite broj redova: ");
	scanf("%d",&r);
	printf("Unesite broj kolona: ");
	scanf("%d",&k);

	
	for(i=0;i<r;i++){
		for(j=0;j<k;j++){
			printf("+");

		} printf("\n");
	}
	return 0;
}
