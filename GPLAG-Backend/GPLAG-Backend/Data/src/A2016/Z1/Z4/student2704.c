#include <stdio.h>

int main() {
	int i, j, broj;
	do {
	printf("Unesite broj n: ");
	scanf("%d", &broj);
	if(broj<=0 || broj>50)
	printf("Pogresan unos\n");
	} while (broj<=0 || broj>50);
	if(broj==1) {
		printf("**");
	}
	for(i=0; i<broj; i++) {
		for(j=0; j<(4*broj-3); j++) {
			if((i==j) || (j==2*broj-2-i) || (j==i+2*broj-2) || (j==4*broj-4-i))
			printf("*");
			else printf(" ");
	}
	printf("\n");
	}
	
	return 0;
}
