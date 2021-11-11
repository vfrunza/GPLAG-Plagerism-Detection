#include <stdio.h>

int main()
{
	int m, n, i, j, k, l;
	float A[100][100], B[100][100], C[100][100], v = 0.5, a = 0, b = 0, c = 0;
	do {
	    printf("Unesite brojeve M i N: ");
	    scanf("%d %d", &m, &n);
	} while (m < 0 || m > 100 || n < 0 || n > 100);
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < m; i++)
	    for (j = 0; j < n; j++)
	        scanf("%f", &A[i][j]);
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < m; i++)
	    for (j = 0; j < n; j++)
	        scanf("%f", &B[i][j]);
	printf("Unesite clanove matrice C: ");
	for (i = 0; i < m; i++)
	    for (j = 0; j < n; j++)
	        scanf("%f", &C[i][j]);
	
	for (i = 0; i < m; i++)
	    for(j = 0; j < n; j++)
	    {
	    	if (A[i][j] == 0.5)
	    	    continue;
	    	v = A[i][j];
	    	a = b = c = 0;
	    	for (k = i; k < m; k++)
	    	    for (l = 0; l < n; l++)
	    	        if (A[k][l] == v)
	    	        {
	    	            a++;
	    	            A[k][l] = 0.5;
	    	        }
	    	for (k = 0; k < m; k++)
	    	    for (l = 0; l < n; l++)
	    	    {
	    	    	if (B[k][l] == v)
	    	    	{
	    	    	    b++;
	    	    	    B[k][l] = 0.5;
	    	    	}
	    	    	if (C[k][l] == v)
	    	    	{
	    	    	    c++;
	    	    	    C[k][l] = 0.5;
	    	    	}
	    	    }
	    	if (b != a || c != a)
	    	{
	    	    printf("NE\n");
	    	    return 0;
	    	}
	    }
	printf("DA\n");
	return 0;
}
