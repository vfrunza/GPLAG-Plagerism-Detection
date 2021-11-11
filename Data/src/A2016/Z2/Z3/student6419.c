#include <stdio.h>
int main() {
	int n, nizx[10], nizy[10], i, j, k;
	char nizdd[20][20], a=' ';
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<=0 || n>10)
			printf("Pogresan unos\n");
	}while(n<=0 || n>10);
	for(i=0; i<n; i++) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &nizx[i], &nizy[i]);
		if(nizx[i]<0 || nizx[i]>19 || nizy[i]<0 || nizy[i]>19) {
			printf("Pogresan unos\n");
			i--;
		}
	}
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			nizdd[i][j]=a;
		}
	}
	for(k=0; k<n; k++) {
		for(i=0; i<20; i++) {
			for(j=0; j<20; j++) {
				if(nizy[k]==i && nizx[k]==j)
					nizdd[i][j]='*';
			}
		}
	}
	for(i=0; i<20; i++) {		
		for(j=0; j<20; j++) {
			printf("%c", nizdd[i][j]);
		}
		printf("\n");
	}	
	return 0;
}