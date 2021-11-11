#include <stdio.h>
#define VELMAT 200

int main() {
	int i,j,k;
	int A[VELMAT][VELMAT];
	int m,n;
	do {
		printf("Unesite brojeve M i N:");
		scanf("%d %d", &m, &n);
		if(m<1 || m>200)
		{
			printf(" Brojevi nisu u trazenom opsegu.\n");
		}
		 else if (n<1 || n>200)
		{
			printf(" Brojevi nisu u trazenom opsegu.\n");
		}
	}
		while(n<1 || n>200 || m<1 || m>200);
		printf(" Unesite elemente matrice:");
		for(i=0; i<m; i++) 
		{
			for(j=0; j<n; j++) 
			{
				scanf("%d", &A[i][j]);
			}
		}
		/* Redovi */
		int rm=0, usl, a, b;
		for(i=m-1; i>0; i--) 
		{
			for(k=rm; k<i; k++)
			{
				usl = 1;
				for(j=0; j<n; j++)
				{
					if ( A[i][j] != A[k][j] )
					usl = 0;
				}
				if(usl == 1) 
				{
					for(a=i; a<m-1; a++)
					{
						for(b=0; b<n; b++) 
						A[a][b] = A[a+1][b];
					}
					m--;
		break;
					
				}
			}
			rm = 0;
		}
		/* Kolone */
		int km=0, usl1, c, d;
		for(j=n-1; j>0; j--) 
		{
			for(k=km; k<j; k++) 
			{
				usl1 = 1;
				for(i=0; i<m; i++)
				{
					if ( A[i][j] != A[i][k] )
					usl1 = 0;
				}
				if(usl1 == 1)
				{
					for(c=0; c<m; c++) 
					{
						for(d=j; d<n-1; d++)
						A[c][d] = A[c][d+1];
					}
					n--;
					break;
					
				}
			}
			km = 0;
		}
		
		printf(" Nakon izbacivanja redova/kolona matrica glasi:\n");
		for(i=0; i<m; i++) 
		{
			for(j=0; j<n; j++)
			{
			printf("%5d", A[i][j]);	
			}
			printf("\n");
		}
		return 0;
}
