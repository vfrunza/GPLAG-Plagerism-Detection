#include <stdio.h>

/* print the rectangle (line width, row type) */
void ispisi_red(int a, int t) {
	int j = 0; 
	char c_poc, c_kraj;
	c_poc = (t == 1 ? '+':'|');
	c_kraj = (t == 1 ? '-':' ');
	printf("%c", c_poc);
	for(j = 0; j < a-2; j++) 
		printf("%c", c_kraj);
	if(a > 1) printf("%c", c_poc);
}

/* important location on plus sign */
int okolina(int n, int eps) {
	if(n == eps || n == eps+1) return 1;
	else return 0;
}

int main() {
	/* initial */
	int i, j, n, SIZE, loc, _test;
	do {
		printf("Unesite broj N: "); scanf("%d", &n);
		if((_test = (n%4!=0 || n < 8))) printf("Neispravno N!\n");
	} while(_test);
	
	/* output */
	printf("\n");
	SIZE = n/2;
	for(i = 0; i < SIZE; i++) {
		/* x sign */
		for(j = 0; j < SIZE; j++) {
			if(i == j) printf("\\");
			else if(i == SIZE - j - 1) printf("/");
			else printf(" ");
		}
		/* rectangle */
		ispisi_red(SIZE, (i == SIZE-1 || i == 0));
		printf("\n");
	}
	loc = SIZE/2 - 1;
	for(i = 0; i < SIZE; i++) {
		/* rectangle */
		ispisi_red(SIZE, (i == SIZE-1 || i == 0)); 
		/* plus sign */
		for(j = 0; j < SIZE; j++) {
			if(okolina(i, loc) && okolina(j, loc)) printf("+");
			else if(okolina(i, loc) && !okolina(j, loc)) printf("-");
			else if(!okolina(i, loc) && okolina(j, loc)) printf("|");
			else printf(" ");
		} 
		printf("\n");
	}
	return 0;
}