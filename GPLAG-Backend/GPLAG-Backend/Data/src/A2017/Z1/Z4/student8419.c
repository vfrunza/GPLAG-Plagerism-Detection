#include <stdio.h>

int main() {
	
	int br_redova, br_kolona, sirina, i, j;
	
	do { printf("Unesite broj redova: ");
		scanf("%d", &br_redova);
	}
	while(br_redova<=0 || br_redova>10);
	
	do { printf("Unesite broj kolona: ");
	     scanf("%d", &br_kolona);
	}
	while(br_kolona<=0 || br_kolona>10);
	
	do { printf("Unesite sirinu jedne kolone: ");
	       scanf("%d", &sirina);
	}
	while(sirina<=0 || sirina>10);
	
	for(i=0; i<(br_redova*2)+1; i++) {
		for(j=0; j<(br_kolona*(sirina+1))+1; j++) {
			if(i%2==0 && j%(sirina+1)==0)printf("+");
			else if(i%2==0 && j%(sirina+1)!=0) printf("-");
			else if(i%2!=0 && j%(sirina+1)==0) printf("|");
			else printf(" ");
		}
		printf("\n");
		
	}
	return 0;
}
