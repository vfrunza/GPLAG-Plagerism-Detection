#include <stdio.h>

int main() {
	int i, j, b, c, n, x;
	char a[20][20];
	x=20;
	printf("Unesite broj tacaka: ");
	scanf ("%d", &n);
	while (n>10||n<1)
	{
		printf ("Pogresan unos\n");
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &n);
	}
	for (i=0; i<x; i++)
	{
		for (j=0; j<x; j++)
		{
			a[i][j]=' ';
		}
	}
	for (i=1; i<=n; i++)
	{
			printf ("Unesite %d. tacku: ", i);
			scanf ("%d %d", &b, &c);
			while (b<0||b>19||c<0||c>19){
			printf ("Pogresan unos\n");
			printf ("Unesite %d. tacku: ", i);
			scanf ("%d %d", &b, &c);}
			a[b][c]='*';
	}
	for (j=0; j<x; j++)
	{
		for (i=0; i<x; i++)
		{
			printf ("%c", a[i][j]);
		}
		printf ("\n");
	}

	return 0;
}
