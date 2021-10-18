#include <stdio.h>
int main() {
	int i,j,k,redovi,kolone,sirina;
	do {
		printf("Unesite broj redova: ");
		scanf("%d",&redovi);
	} while(redovi<=0 || redovi>10);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &kolone);
	} while(kolone<=0 || kolone>10);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&sirina);
	} while (sirina<=0 || sirina>10);
	for(i=0; i<2*redovi+1; i++) {
		if(i%2==0) {
			for(k=0; k<((sirina*kolone)+kolone+1); k++) {
				if(k%(sirina+1)==0)printf("+");
				else printf("-");
			}
		}
		for(j=0; j<(sirina*kolone+kolone+1); j++) {
			if(i%2!=0 && j%(sirina+1)==0) printf("|");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
