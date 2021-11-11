#include <stdio.h>

int main() {
	int m,n;
	int i,j;
	int x;
	int A[100][100], B[100][100], C[100][100];
	int a[10000], b[10000], c[10000];
	int t;
	int brojac=0, pom=0;
	do 
	{
	printf("Unesite brojeve M i N: ");
	scanf ("%d %d", &m, &n);
	}
	while (m>100 || n>100 || n<0 || m<0);
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<m; i++)
	for (j=0;j<n; j++)
	{
		scanf ("%d", &x);
		A[i][j]=x;
	}
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<m; i++)
	for (j=0; j<n; j++)
	{
		scanf ("%d", &x);
		B[i][j]=x;
	}
	printf ("Unesite clanove matrice C: ");
	for (i=0; i<m; i++)
	for (j=0; j<n; j++)
	{
		scanf ("%d", &x);
		C[i][j]=x;
	}
	for (i=0;i<m;i++)
	for (j=0;j<n;j++)
	{
		a[brojac]=A[i][j];
		b[brojac]=B[i][j];
		c[brojac]=C[i][j];
		brojac++;
	}
	for (j=0;j<(brojac-1);j++)
	{
		for (i=0;i<(brojac-1);i++)
		{
			if (a[i+1]<a[i])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
			if (b[i+1]<b[i])
			{
				t=b[i];
				b[i]=b[i+1];
				b[i+1]=t;
			}
			if (c[i+1]<c[i])
			{
				t=c[i];
				
				c[i]=c[i+1];
				c[i+1]=t;
			}
		}
	}
	for (i=0;i<brojac;i++)
	{
		if (a[i]==b[i] && a[i]==c[i])
		pom++;
	}
	if (pom==brojac)
	printf ("DA\n"); else
	printf ("NE\n");
	
	return 0;
}
