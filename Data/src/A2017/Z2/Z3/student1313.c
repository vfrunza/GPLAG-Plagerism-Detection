#include <stdio.h> Program treba ispisati DA ako je matrica B jednaka 
                  matrici A zarotiranoj za 90° u smjeru kazaljke na satu, a NE ako nije.
#include <math.h>
#define EPSILON 0.0001

int main() {
	double matA[100][100],matB[100][100],matC[100][100];
	int i,j,v1,s1,v2,s2,jesu_iste=1;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&s1,&v1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<v1;i++)
	{
		for(j=0;j<s1;j++)
		{
			scanf("%lf",&matA[i][j]);
		}
	}

	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&s2,&v2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<v2;i++)
	{
		for(j=0;j<s2;j++)
		{
			scanf("%lf",&matB[i][j]);
		}
	}
	
	if (v1!=s2 || s1!=v2)
	{
		printf("NE\n");
		return 0;
	}
	
	
	for(i=0;i<s1;i++)
		for(j=0;j<v1;j++)
			matC[i][j]=matA[v1-1-j][i];
	
	
	
	for(i=0;i<s1;i++)
	{
		for(j=0;j<v1;j++)
		{
			if (fabs(matC[i][j]-matB[i][j])>EPSILON)
			{
				jesu_iste=0;
				break;
			}
		}
	}
	
	if (jesu_iste==1)
		printf("DA\n");
	else 
		printf("NE\n");
	
	
	return 0;
}

