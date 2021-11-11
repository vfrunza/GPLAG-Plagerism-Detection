#include <stdio.h>
#define size 200

int poredi_redove(int *red1, int *red2, int vel)
{
	int i;
	for(i=0; i<vel; i++)
		if(red1[i] != red2[i])
			return 0;
			
	return 1;
}
int izbaci_redove(int mat[size][size], int m, int n){
	int i, j, k, l;
	for(i=0; i<m-1; i++)
		for(j=i+1; j<m; j++)
		{
			if(poredi_redove(mat[i], mat[j], n))
			{
				for(l=j; l<m-1; l++)
					for(k=0; k<n; k++)
					mat[l][k] = mat[l+1][k];
				i--;
				m--;
			}
		}
		return m;
}
int poredi_kolone(int mat[size][size], int ind1, int ind2, int vel)
{
	int i;
	for(i=0; i<vel; i++)
		if(mat[i][ind1] != mat[i][ind2])
			return 0;
	return 1;
}
void izbaci_kolonu(int mat[size][size], int m, int n, int indeks)
{
	int i, j;
	for(i=0; i<n; i++)
		for(j=indeks; j<n-1; j++)
			mat[i][j] = mat[i][j+1];
}
int izbaci_kolone(int mat[size][size], int m, int n)
{
	int i, j;
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
		{
			if(poredi_kolone(mat, i, j, m)){
				izbaci_kolonu(mat, m, n, j);
				n--;
				i--;
			}
		}
	return n;
}
int main (){
	int m, n, i, j;
	int mat[200][200];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || n<=0 || m>200 || n>200)
			printf("Brojevi nisu u trazenom opsegu.\n");
	}while(m<=0 || n<=0 || m>200 || n>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%d", &mat[i][j]);
	m = izbaci_redove(mat, m, n);
	n = izbaci_kolone(mat, m, n);
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
			printf("%5d", mat[i][j]);
		printf("\n");
	}
	return 0;
}