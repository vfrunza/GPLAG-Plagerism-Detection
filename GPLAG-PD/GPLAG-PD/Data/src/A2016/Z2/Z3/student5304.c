#include <stdio.h>

int main() {
	int i, j, k;
	int n;
	int a[20];
	int b[20];	
	pocetak:
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n>10 || n<=0) {
		printf("Pogresan unos\n");
		goto pocetak;
	}
	for(i=0; i<n; i++) {
	
            nastavak:
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d",&a[i], &b[i]);
			
			if(a[i]>19 || b[i]>19 || a[i]<0 || b[i]<0) {
				printf("Pogresan unos\n");
				goto nastavak;
			} 
	}
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
				for(k=0; k<n; k++) {
	    if(i==b[k] && j==a[k]) {
		printf("*");
		goto kraj;
	    }
		}
		printf(" ");
		kraj:
		continue;
		}
			printf("\n");
	}
	return 0;
}
