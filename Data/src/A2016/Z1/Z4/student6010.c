#include <stdio.h>

int main() {
	int n=2;
	int i, j;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	while(n<1 || n>50) {printf("Pogresan unos\n");
	printf("Unesite broj n: ");
	scanf("%d", &n);
	}
	if(n==1) {printf("***");}

else for(i=0; i<n; i++) {
		for(j=0; j<3*n+n-3; j++) {
			if(j==i || j==n*2-i-2 || i==j+2-n*2 || j==4*n-4-i) printf("*");
			else printf(" ");
		}
printf("\n");
}

return 0;
}