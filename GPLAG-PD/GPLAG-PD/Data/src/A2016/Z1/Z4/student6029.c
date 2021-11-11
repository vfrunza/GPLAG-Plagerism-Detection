#include <stdio.h>

int main() {
	int n=0,i=0,j=0;
	for(;;) {
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if(n>0 && n<=50) break;
		printf("Pogresan unos\n");
	} 
	if(n==1) {
		printf("***");
		return 0;
	}
	for(i=0;i<n;i++) {
		for(j=0;j<((n*4)-3);j++) {
			if((i==j) || (i+j)==((n*2)-2) || (j-i)==((n*2)-2) || (i+j)==(n*4)-4)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
