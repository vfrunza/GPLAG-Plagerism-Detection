#include <stdio.h>

void ispis_r(int type, int width) {
	char c = (type==1 ? ' ':'-');
	char c2 = (type==1 ? '|':'+');
	int i = 0;
	printf("%c", c2);
	for(i = 1; i <= width; i++)
		printf("%c", c);
}

int main() {
	/* initial */
	int r, k, n;
	
	/* input */
	do {
		printf("Unesite broj redova: "); scanf("%d", &r);
	} while(r < 1 || r > 10);
	do {
		printf("Unesite broj kolona: "); scanf("%d", &k);
	} while(k < 1 || k > 10);
	do {
	printf("Unesite sirinu jedne kolone: "); scanf("%d", &n);
	} while(n < 1 || n > 10);
	
	/* output */
	int i, j;
	for(i = 0; i <= r*2; i++) {
		int tip = i%2;
		for(j = 1; j <= k; j++) 
			ispis_r(tip, n);
		printf("%c\n", (tip==1 ? '|':'+'));
	}
	return 0;
}
