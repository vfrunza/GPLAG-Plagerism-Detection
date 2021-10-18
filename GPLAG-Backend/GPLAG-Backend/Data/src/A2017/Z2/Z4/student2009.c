#include <stdio.h>

/* Funkcija za sortiranje niza putem selection sort-a */
void sortiraj(int p,int q,int niz[])
{
	int i,j,min,temp;
	for (i=0; i<p*q; i++) {
		min=i;
		for (j=i+1; j<p*q; j++) {
			if (niz[j]>niz[min])
				min=j;
		}
		temp=niz[i];
		niz[i]=niz[min];
		niz[min]=temp;
	}
}

int main()
{
	int A[101][101],B[101][101],C[101][101];
	int nizA[10001],nizB[10001],nizC[10001];
	int m,n,i,j,equal=1;

	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	} while(m<0 || m>100 || n<0 || n>100);

	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%d",&A[i][j]);

	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%d",&B[i][j]);

	printf("Unesite clanove matrice C: ");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%d",&C[i][j]);

	for(i=0; i<m; i++)
		for(j=0; j<n; j++) {
			nizA[i*n+j]=A[i][j];
			nizB[i*n+j]=B[i][j];
			nizC[i*n+j]=C[i][j];
		}

	sortiraj(m,n,nizA);
	sortiraj(m,n,nizB);
	sortiraj(m,n,nizC);

	for(i=0; i<m*n; i++)
		if(nizB[i]!=nizA[i] || nizC[i]!=nizA[i])
			equal=0;

	if(equal==1)
		printf("DA\n");
	else printf("NE\n");

	return 0;
}
