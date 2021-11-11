#include <stdio.h>

int main() {	
	
	int m, n, i, j, c, d, A[70][70], B[70][70], x=0, y=0, C[70][70];
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &n, &m);
	printf("Unesite clanove matrice A: ");
	
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%d", &A[i][j]);
			
			printf("Unesite sirinu i visinu matrice B: ");
			scanf("%d %d", &d, &c);
			printf("Unesite clanove matrice B: ");
	
	for(i=0; i<c; i++)
		for(j=0; j<d; j++)
			scanf("%d", &B[i][j]);
			
			if(m!=d || n!=c)
			{
				printf("NE");
				return 0;
			}
			
			for(j=0; j<n; j++)
			{
				for(i=m-1; i>=0; i--)
				{
					C[y][x++]=A[i][j];
					if(x==m)
					{
						x=0;
						y++;
					}
				}
			}
	
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
				if(B[i][j]!=C[i][j])
				{
					printf("NE");
					return 0;
				}
		}
	printf("DA");
	
	return 0;
}
