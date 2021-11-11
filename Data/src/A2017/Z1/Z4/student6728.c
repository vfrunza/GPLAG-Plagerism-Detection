#include <stdio.h>

int main() {
	int i, j, r, k, s, br_redova, br_kolona;
	do {
		printf("Unesite broj redova: ");
		scanf("%d",&r);
	} while (r <= 0 || r > 10);
	
	do {
		printf("Unesite broj kolona: ");
		scanf("%d",&k);
	} while (k <= 0 || k > 10);
	
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&s);
	} while (s <= 0 || s > 10);
	
	
	br_redova = r*2 + 1;
	br_kolona = k*(s+1) + 1;
	for (i=0; i < br_redova; i++) {
		for (j = 0; j < br_kolona; j++) {
			if (i%2 == 0 && j % (s + 1) == 0)
			printf("+");
			else if (j % (s + 1) == 0)
			printf("|");
			else if (i % 2 == 0)
			printf("-");
			else printf (" ");
		}
		printf("\n");
	}
	return 0;
}
