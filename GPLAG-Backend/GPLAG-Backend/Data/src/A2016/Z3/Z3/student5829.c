#include <stdio.h>

int main() {
	int m, n, i, j, k, q, x[200][200], s;
	do{
printf("Unesite brojeve M i N: ");
	scanf ("%d %d", &m, &n);
	if (n<=0||m<=0||n>200||m>200)	{
		printf ("Brojevi nisu u trazenom opsegu.\n");
	}
	
	
	}
	
	while(n<=0||m<=0||n>200||m>200);
	printf ("Unesite elemente matrice: ");
	for (i=0; i<m; i++){
		for (j=0; j<n; j++)
		{
			scanf ("%d", &x[i][j]);
		}
	}
	s=0;
	for (i=1; i<m; i++)
	{
		for (j=0; j<i; j++){
			s=0;
			for (k=0; k<n; k++){
				if (x[i][k]!=x[j][k]){
					s=1;
					break;
				}
			}
			
			if (s==0)	{
				for (q=i; q<m-1; q++)
				{
					for (k=0; k<n; k++)
					{
						x[q][k]=x[q+1][k];
					}
				}
				m--;
				i--;
			}}}
		for (k=1; k<n; k++)
		{
			for (j=0; j<k; j++)	{
				s=0;
				for (i=0; i<m; i++)	{
					if (x[i][k]!=x[i][j])
					{
						s=1;
						break;
					}
				}
				if (s==0)
				{
					for (q=k; q<n-1; q++)
					{
						for (i=0; i<m; i++)
						{
							x[i][q]=x[i][q+1];
						}
					}
					k--;
					n--;
				}
			}
		}
		printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
		for (i=0; i<m; i++)
		{
			printf (" ");
			for (j=0; j<n; j++)
			{
				printf ("%4d ", x[i][j]);
			}
			printf ("\n");
		}
	return 0;
}