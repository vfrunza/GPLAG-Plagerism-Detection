#include <stdio.h>

int main() {
	int rows, columns, cWidth;
	int i, j, k;
	
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &rows);
	}
	while (rows <= 0 || rows > 10);
	
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &columns);
	}
	while (columns <= 0 || columns > 10);
	
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &cWidth);
	}
	while (cWidth <= 0 || cWidth > 10);
	
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			printf("+");
			for (k = 0; k < cWidth; k++)
				printf("-");
		}
		printf("+\n");
		
		for (j = 0; j < columns; j++) {
			printf("|");
			for (k = 0; k < cWidth; k++)
				printf(" ");
		}
		printf("|\n");
	}
	
	for (j = 0; j < columns; j++) {
		printf("+");
		for (k = 0; k < cWidth; k++)
			printf("-");
	}
	printf("+\n");
	
	return 0;
}
