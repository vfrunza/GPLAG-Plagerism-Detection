#include <stdio.h>
#include <math.h>

int main() {
	double matricaA[100][100],matricaB[100][100];
	int vA,sA,vB,sB;
	int i,j;
	int jednaki=1;
	double eps=0.001;
	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d",&sA,&vA);
	printf ("Unesite clanove matrice A: ");
	for (i=0;i<vA;i++)
	{
		for (j=0;j<sA;j++)
		scanf ("%lf",&matricaA[i][j]);
	}
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d",&sB,&vB);
	printf ("Unesite clanove matrice B: ");
	for (i=0;i<vB;i++)
	{
		for (j=0;j<sB;j++)
		scanf ("%lf",&matricaB[i][j]);
	}
	if (sA!=vB || vA!=sB)
	printf ("NE\n");
	else{

		for (i=0;i<sA;i++)
		{
			for (j=0;j<vA;j++)
			{
				if (fabs(matricaA[vA-j-1][i]-matricaB[i][j])>eps)
				{
					jednaki=0;
					break;
				}
				else
				jednaki=1;
			}
		}
		if (jednaki)
		printf ("DA\n");
		else
		printf ("NE\n");}


	return 0;
}
