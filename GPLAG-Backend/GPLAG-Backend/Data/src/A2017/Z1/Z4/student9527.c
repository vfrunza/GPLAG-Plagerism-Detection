#include <stdio.h>
#include <stdlib.h>

int main() {
	int bkolona,bredova,sirinak,i,j,k;
	printf("Unesite broj redova: ");
	do {
		scanf("%d",&bredova);
	} while (bredova <=0 || bredova>10);
	printf("Unesite broj kolona: ");
	do {
		scanf("%d",&bkolona);
	} while (bkolona <=0 || bkolona>10);
	printf("Unesite sirinu jedne kolone: ");
	do {
		scanf("%d",&sirinak);
	} while(sirinak<=0 || sirinak>10);
	printf("+");
	for(i=0;i<bkolona;i++) {
		for(j=0;j<sirinak;j++) {
			printf("-");
		} printf("+");
	}
	printf("\n");
	for(i=0;i<bredova;i++){
		printf("|");
		for(j=0;j<bkolona;j++){
			for(k<0;k<sirinak;k++){
				printf("-");
			}
			printf("+");
		}
		if(i!=bredova-1){
			printf("\n");
		}
	}

	return 0;
}
