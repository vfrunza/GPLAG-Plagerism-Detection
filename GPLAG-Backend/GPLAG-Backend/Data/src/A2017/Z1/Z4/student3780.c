#include <stdio.h>

int main() {
/*	printf("Zadaća 1, Zadatak 4");*/
	int r,k,sk,i,j;
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&r);
	} while(r<1 || r>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&k);
	} while(k<1 || k>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sk);
	} while(sk<1 || sk>10);
	for(j=0; j<sk*k+k+1; j++){
		if(j%(sk+1)==0) printf("+");
		else printf("-");
	}
	for(i=0; i<r; i++){
		printf("\n");
		for(j=0; j<sk*k+k+1; j++) {
			if(j%(sk+1)==0) printf("|");
			else printf(" ");
		}
		printf("\n");
		for(j=0; j<sk*k+k+1; j++){
			if(j%(sk+1)==0) printf("+");
			else printf("-");
		}
	}
	return 0;
}
