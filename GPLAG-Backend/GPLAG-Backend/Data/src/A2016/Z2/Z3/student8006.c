#include <stdio.h>

int main()
{

	int b, x[10], y[10], i=0, j=0, k=0;
	char a[25][25];
	for(j=0; j<25; j++) {
		for(k=0; k<25; k++) {
			a[j][k]=' ';
		}
	}
	do {
		printf("Unesite broj tacaka: ");
		scanf("%i", &b);
		if(b>10 || b<=0)
			printf("Pogresan unos\n");
	} while(b>10 || b<=00);

	for(i=0; i<b; i++) {

		printf("Unesite %i. tacku: ", i+1);
		scanf("%i %i", &y[i], &x[i]);
		if(y[i]>19 || x[i]>19 || y[i]<0 || x[i]<0) {
			printf("Pogresan unos\n");
			i--;
		} else
			a[x[i]][y[i]]='*';
	}



	for(j=0; j<25; j++) {
		for(k=0; k<25; k++) {
			printf("%c", a[j][k]);
		}
		printf("\n");
	}
	return 0;
}
