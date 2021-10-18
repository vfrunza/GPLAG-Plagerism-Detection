#include <stdio.h>

int main() {
	int m, n, mat[200][200], i, j, k,a,brojac=0;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(n<=0 || n>200 || m<=0 || m>200) {
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	}
	while (n<=0 || n>200 || m<=0 || m>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	for(i=0;i<m;i++)
	{
		for(a=i+1;a<m;a++)
		{
			brojac=0;
			for(j=0;j<n;j++)
			{
				if(mat[i][j]==mat[a][j])
				brojac++;
			}
		if(brojac==n)
		{
			for(k=a;k<m-1;k++)
			{
				for(j=0;j<n;j++)
				{
					mat[k][j]=mat[k+1][j];
				}
			}
			m--;
			a--;
			brojac=0;
		}
		}
	}
	
	for(j=0;j<n;j++)
	{
		for(a=j+1;a<n;a++)
		{
			brojac=0;
			for(i=0;i<m;i++)
			{
				if(mat[i][j]==mat[i][a])
				brojac++;
			}
			if(brojac==m)
			{
				for(k=a;k<n-1;k++)
				{
					for(i=0;i<m;i++)
					{
						mat[i][k]=mat[i][k+1];
					}
				}
				n--;
				a--;
				brojac=0;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
