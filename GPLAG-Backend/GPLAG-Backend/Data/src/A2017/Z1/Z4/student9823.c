#include <stdio.h>

int main() {
	int d,k,l,n;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	while(n<=0 || n>50) {
		printf("Pogresan unos \n"); 
		printf("Unesite broj n: ");
		scanf("%d", &n); }
		if (n==1) {
		printf("***"); return 0; } 
	d=n+3*(n-1);
		for (k=0;k<n;k++) {
		for(l=0;l<d;l++) {
		if(l==k || l==d/2+k || l==d/2-k || l==d-k-1 ) {
					printf ("*");
				} else { printf (" "); 
				}
		}
			
printf("\n");
}
	return 0;
}

