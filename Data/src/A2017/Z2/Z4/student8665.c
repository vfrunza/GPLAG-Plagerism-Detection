#include <stdio.h>

int main() {
	int m=0, n=0, i, j;
	int matA[m][n], matB[m][n], matC[m][n]; / * m je varijabla za visinu, a n za sirinu * /
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m, &n);
	}
	while(m>100 && n>100);

	return 0;
	
}
