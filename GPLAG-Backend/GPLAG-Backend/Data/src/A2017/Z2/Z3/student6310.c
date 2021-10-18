#include <stdio.h>

int main() {
	int m, n, p, q, i, j, k, l;
	float A[50][50] = {{0}}, B[50][50] = {{0}};
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &n, &m);
	printf("Unesite clanove matrice A: ");
    for (i = 0; i < m; i++)
	    for (j = 0; j < n; j++)
	        scanf("%f", &A[i][j]);
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &q, &p);
	printf("Unesite clanove matrice B: ");
    for (i = 0; i < p; i++)
	    for (j = 0; j < q; j++)
	        scanf("%f", &B[i][j]);
	if (m != q || n != p)
	{
	    printf("NE\n");
	    return 0;
	}
	k = l = 0;
	for (j = 0; j < n; j++)
	    for (i = m - 1; i >= 0; i--)
	    {
	        if (B[k][l] != A[i][j])
	        {
	        	printf("NE\n");
	        	return 0;
	        }
	       	l++;
	       	if (l == m)
	       	{
	       	    l = 0;
	       	    k++;
	       	}
	    }
	printf("DA\n");
	return 0;
}