#include <stdio.h>

int main()
{
	int m, n, k, i, j;
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &m);
	} while (m <= 0 || m > 10);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &n);
    } while (n <= 0 || n > 10);
    do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &k);
	} while (k <= 0 || k > 10);
	for (i = 0; i < m * 2 + 1; i++)
	{
        for (j = 0; j < n * (k + 1) + 1; j++)
        {
        	if (i % 2)
        	    if (j % (k + 1))
        	        printf(" ");
        	    else
        	        printf("|");
        	else
        	    if (j % (k + 1))
        	        printf("-");
        	    else
        	        printf("+");
        }
        printf("\n");
	}
	return 0;
}