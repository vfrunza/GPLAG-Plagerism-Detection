#include <stdio.h>

int main() {
	int N, half;
	int i, j;
	
	do {
		printf("Unesite broj N: ");
		scanf("%d", &N);
		
		if (N % 4 || N < 8)
			printf("Neispravno N!\n");
	}
	while (N % 4 || N < 8);
	
	/* Dijeljenje uradjeno right shift operatorom */
	half = N >> 1;
	
	/* Zbog autotestova je potrebno ispisati jos jedan novi red */
	printf("\n");
	
	/* Petlja za ispis gornje polovine (X i kvadrat) */
	for (i = 0; i < half; i++) {
		/* X */
		for (j = 0; j < half; j++)
			if (i == j)
				printf("\\");
			else if (i + j == half - 1)
				printf("/");
			else
				printf(" ");
		
		/* Kvadrat */
		for (j = 0; j < half; j++)
			if ((!i || i == half - 1) && (!j || j == half - 1))
				printf("+");
			else if (!i || i == half - 1)
				printf("-");
			else if (!j || j == half - 1)
				printf("|");
			else
				printf(" ");
		
		printf("\n");
	}
	
	/* Petlja za donji dio ispisa (kvadrat i plus) */
	for (i = 0; i < half; i++) {
		/* Kvadrat */
		for (j = 0; j < half; j++)
			if ((!i || i == half - 1) && (!j || j == half - 1))
				printf("+");
			else if (!i || i == half - 1)
				printf("-");
			else if (!j || j == half - 1)
				printf("|");
			else
				printf(" ");
		
		/* Plus */
		for (j = 0; j < half; j++)
			if ((i == half / 2 || i == half / 2 - 1) &&
				(j == half / 2 || j == half / 2 - 1))
				printf("+");
			else if (i == half / 2 || i == half / 2 - 1)
				printf("-");
			else if (j == half / 2 || j == half / 2 - 1)
				printf("|");
			else
				printf(" ");
				
		printf("\n");
	}
	
	return 0;
}
