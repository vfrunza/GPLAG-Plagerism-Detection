#include <stdio.h>
int main (){
	int n, i, j, prva, druga, matrica[20][20]={{0}};
	do {
		printf("Unesite broj tacaka: ");
	    scanf("%d", &n);
	    if(n<1 || n>10) {
	    	printf("Pogresan unos\n");
	    }
	} while (n<1 || n>10);

	
	for (i=1; i<=n; i++) {
		printf("Unesite %d. tacku: ", i);
		scanf("%d %d", &druga,&prva);
		while((druga<0 || druga>19) || (prva<0 || prva>19)) {
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ",i);
			scanf("%d %d", &druga,&prva);
		}
	    matrica[prva][druga]=1;
	}
	
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			if(matrica[i][j]==1) {
				printf("*");
		    } else {
		    	printf(" ");
		    }
		}
		printf("\n");
	}
	return 0;
}