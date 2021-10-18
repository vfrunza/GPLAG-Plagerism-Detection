#include <stdio.h>

int main()
{
	int i, j, k, s, r;
	
	do {
	printf("Unesite broj redova: ");
	scanf("%d",&r);
	} while(r <= 0 || r >= 11);
	
	do {
	printf("Unesite broj kolona: ");
	scanf("%d",&k);
	} while(k <= 0 || k >= 11);
	
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&s);
	} while(s <= 0 || s >= 11);
	
	for (i=0; i<(2*r)+1; i++) {
		for (j=0; j<(1+(s+1)*k); j++) {
			if (i%2 == 0)
			{
				if (j%(s+1) == 0)
				{
					printf ("+");
				}
				else 
				{
					printf ("-");
				}
			}
			else
			{
				if (j%(s+1) == 0) 
				{
					printf ("|");
				}
				else
				{
					printf (" ");
				}
			}
		}
		printf ("\n");
	}
	
	return 0;
}
