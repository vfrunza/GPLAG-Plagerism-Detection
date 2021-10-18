#include <stdio.h>

int main() {
	int i,j,br,bk,sk;
	do {
	printf("Unesite broj redova: ");
	scanf("%d", &br);
	} while (br<1 || br>10);
	do {
	printf("Unesite broj kolona: ");
	scanf("%d", &bk);
	} while (bk<1 || bk>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sk);
	} while (sk<1 || sk>10);
	for(i=0; i<2*br+1; i++){
		for(j=0; j<bk*sk+bk+1; j++){
			if(i%2==0 && j%(sk+1)==0){
			printf("+");
			}
			else if(i%2==0 && j%(sk+1)!=0){
				printf("-");
			}
			else if(i%2==1 && j%(sk+1)==0){
				printf("|");
			}
			else if(i%2==1 && j%(sk+1)!=0){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
