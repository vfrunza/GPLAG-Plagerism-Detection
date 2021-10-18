#include <stdio.h>

int main() {
	int n, i, j, z;
	do{
		printf("Unesite broj n: "); scanf("%d", &n);
		if (n<1 || n>50) printf("Pogresan unos\n");
	} while (n<1 || n>50);
	
	if (n==1) {z=3;} else {z=((n-2)*4)+5;}
	
	for (i=0; i<n; i++){
		for (j=0; j<z; j++){
			if (i==j-(z-1)/2 || j==i) {printf("*");}
			else if (i+j==(z-1)/2 || i+j==z-1) {printf("*");}
			else {printf(" ");}
		}
		printf("\n");
	}
	return 0;
}