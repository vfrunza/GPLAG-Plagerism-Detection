#include <stdio.h>
#include <math.h>

int main() {
	int ax1, ay1, bx1, by1;
	int i,j;
	double A1[100][100]={{0}},B1[100][100]={{0}};
	double x;
	int elemenata=0, brojac=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d",&ax1,&ay1);
	printf("Unesite clanove matrice A: ");
	for (j=(ax1-1);j>=0;j--)
	for (i=0;i<ay1;i++)
	{
		scanf("%lf",&x);
		A1[i][j]=x;
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &bx1, &by1);
	printf ("Unesite clanove matrice B: ");
	for (i=0;i<bx1;i++)
	for (j=0;j<by1;j++)
	{
		scanf ("%lf",&x);
		B1[i][j]=x;
	}
	for (i=0;i<bx1;i++)
	{
		for (j=0;j<by1;j++)
		{
		// printf ("%lfvs%lf"B1[i][j],A1[i][j]);
		if (fabs(A1[i][j]-B1[i][j])<0.000001) brojac++;
	}
	//printf ("\n");
	}
	
	if(ay1!=bx1 || ax1!=by1)
	{
		printf("NE\n"); return 0;
		
	}
	elemenata=ax1*ay1;
	if (brojac==elemenata)
	printf ("DA\n");
	else 
	printf ("NE\n");
	
	return 0;
}
