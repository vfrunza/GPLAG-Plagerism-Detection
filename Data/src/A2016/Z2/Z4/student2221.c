#include <stdio.h>

int main() 
{
	int m,n,i,j;
	do 
	{
		printf ("Unesite M i N: ");
		scanf ("%d %d", &m,&n);
	if (m <= 0 || m > 100 || n<0 || n>100)
	{
		printf ("Pogresan unos!\n");
	}
	}
	while (m <= 0  || m>100 || n<0 || n>100);
	float niz[100][100];
	printf ("Unesite elemente matrice: ");
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			float k;
			scanf ("%f", &k);
			niz[i][j]=k;
		}
	}
	int tcirk=1, tteplic = 1;
	for (i=0; i<m-1; i++)
	{
		for (j=0; j<n-1; j++)
		{
			if (niz[i+1][j+1] != niz[i][j]){
				tcirk = 0;
				tteplic = 0;
			}
		}
		if (niz[i][n-1] != niz[i+1][0])
			tcirk = 0;
	}
	if (tcirk == 1)
		printf ("Matrica je cirkularna\n");
	else if (tteplic==1)
    	printf ("Matrica je Teplicova\n");
    else 
    	printf ("Matrica nije ni cirkularna ni Teplicova\n");
    	
	return 0;
}
