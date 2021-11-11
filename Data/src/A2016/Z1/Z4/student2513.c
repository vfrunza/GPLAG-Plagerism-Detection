#include <stdio.h>

int main() {
	int n, i, j, k, l, m, p, q;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<1 || n>50) {
		do{printf("Pogresan unos"); 
		printf("\nUnesite broj n: ");
		scanf("%d", &n);
		}
		while(n<0 || n>50);
			}
			if(n==1) {printf("***"); return 0;}
	printf("*");
	for(i=0; i<n+n-3;i++) printf(" ");
	printf("*");
	for(j=0; j<n+n-3;j++) printf(" ");
	printf("*\n");
	
	for(k=1;k<=n-2;k++){
		for(l=1;l<=k;l++) printf(" ");
		printf("*");
		for(m=n+n-4; m>=k+k;m--) printf(" ");
		printf("*");
		for(p=1;p<=k+k-1;p++) printf(" ");
		printf("*");
		for(q=n+n-4; q>=k+k;q--) printf(" ");
		printf("*");
		printf("\n");
	}

    for(k=1;k<=n-1;k++) printf(" ");
    printf("*");
    for(k=1;k<=n+n-3;k++) printf(" ");
    printf("*");
	return 0;
}
