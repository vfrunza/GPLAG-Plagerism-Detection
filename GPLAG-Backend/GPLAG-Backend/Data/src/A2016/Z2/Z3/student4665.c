#include <stdio.h>

int main() {
	int n,k1[10],k2[10],i,j, k;
	int ispisano=0;
	while(1) {
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=10 && n>0) break;
	else 
	printf("Pogresan unos\n");
	}
	for(k=0;k<n;k++){
		printf("Unesite %d. tacku: ", k+1);
		scanf("%d%d", &k1[k], &k2[k]);
		if(k1[k]<0 || k1[k]>19 || k2[k]<0 || k2[k]>19) {
			printf("Pogresan unos\n");
			k--;
		}
	}
	for(i=0;i<20; i++) {
		for(j=0;j<20;j++){
			ispisano=0;
			for(k=0; k<n; k++) {
				if(j==k1[k] && i==k2[k]) {
					printf("*");
					ispisano=1;
					break;
				}
			}
			if (ispisano==0)
				printf(" ");

		}
		printf("\n");
	}
	return 0;
}
