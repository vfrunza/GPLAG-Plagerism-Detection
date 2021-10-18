#include <stdio.h>

int main() {
	int br,bk,sk,i=0, j=0, k=0; 
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &br); } while (br<=0 || br>10);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &bk);} while (bk<=0 || bk>10);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sk);} while (sk<=0 || sk>10);
	/* petlja za redove */
	for(i=0; i<2*br; i++){
		if(i%2==0){
			for(j=0; j<bk*(sk+1);j++){
				if(j%(sk+1)==0){
				printf("+");
			} else{
			printf("-");
			}
			} printf("+\n");
		} else {
			for(k=0;k<(bk)*(sk+1);k++){
				if(k%(sk+1)==0){
					printf("|");
				} else {
					printf(" ");
				}
			} printf("|\n");
		}
	}
	/* petlja za zadnji red */
	for(i=0; i<(bk)*(sk+1);i++){
		if(i%(sk+1)==0){
			printf("+");
		} else{
			printf("-");
		} 
		}
		printf("+\n");
	return 0;
}
