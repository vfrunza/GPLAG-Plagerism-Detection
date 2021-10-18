#include <stdio.h>

int main() {
	int i,j,a,b;
	printf("Unesite stranice pravougaonika a,b: ");
scanf ("%d,%d", &a,&b);
	for (i=0; i<b; i++){
	for (j=0; j<a; j++){
		if (i==0 && (j==0 || j==a-1)){
			printf ("+");
	} else if (i==b-1 && (j==0 || j==a-1)){
		printf("+");
	} else if (i==0 && (j>0 || j<a-1)){
		printf("-");
	} else if (i==b-1 && (j>0 || j<a-1)){
		printf("-");
	} else if (j==0 || j==a-1) {
		printf("|");
	} else {
		printf(" ");
	}
	}
	printf("\n");
	}
	return 0;
}
