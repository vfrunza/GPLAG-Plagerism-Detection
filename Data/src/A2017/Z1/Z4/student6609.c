#include <stdio.h>

int main() {
	int i,j,br_redova,br_kolona,sirina_kolone;
	do {
	printf("Unesite broj redova: ");
	scanf("%d", &br_redova);
	} while(br_redova<=0 || br_redova>10);
	
	do {
	printf("Unesite broj kolona: ");
	scanf("%d", &br_kolona);
	} while(br_kolona<=0 || br_kolona>10);
	
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sirina_kolone);
	} while(sirina_kolone<=0 || sirina_kolone>10);
	
	for(i=0; i<=br_redova*2; i++) {
		for(j=0; j<=br_kolona*(sirina_kolone+1); j++) {
			if(i%2==0) {
				if(j%(sirina_kolone+1)==0) printf("+");
				else printf("-");
			}
			else {
				if(j%(sirina_kolone+1)==0) printf("|");
				else printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
