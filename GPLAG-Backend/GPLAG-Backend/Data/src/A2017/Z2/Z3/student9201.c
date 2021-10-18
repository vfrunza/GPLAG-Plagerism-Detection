#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001


int main() {
	int a, b, c, d;
	double A[100][100];
	double B[100][100];
	double C[100][100];
	int i,j,k,l;
	int brojac = 0;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &a, &b);
	
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < b; i++)
		{
			for (j = 0; j < a; j++)
				scanf("%lf", &A[i][j]);
				
		}
	
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &c, &d);
	
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < d; i++)
		{
			for (j = 0; j < c; j++)
				scanf("%lf", &B[i][j]);
				
		}
		
	if (a != d || b != c)
		{
			printf("NE");
			return 0;
		}
	
	k = c-1;
	for (i = 0; i < b; i++)
		{
			l = 0;
			for (j = 0; j < a; j++)
				C[l++][k] = A[i][j];
				
			k--;
		}
	
	
	for (i = 0; i < d; i++)
		{
			for (j = 0; j < c; j++)
				{
					if (fabs(C[i][j] - B[i][j]) < EPSILON)
						brojac++;
				}
		}
		
	if (brojac == a*b)
		printf("DA");
	else
		printf("NE");
	
	
	
	
	
	
	
	return 0;
}
