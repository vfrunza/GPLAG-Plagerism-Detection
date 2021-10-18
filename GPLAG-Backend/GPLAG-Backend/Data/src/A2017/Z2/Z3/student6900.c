#include <stdio.h>
#include <math.h>
#define BROJ_EL 100
#define e 0.0001

int main() {
	double nizA[BROJ_EL][BROJ_EL], nizB[BROJ_EL][BROJ_EL], temp[BROJ_EL][BROJ_EL];
	int i, j, sirinaA, visinaA, sirinaB, visinaB;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirinaA, &visinaA );
	
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < visinaA; i++)
		for (j = 0; j < sirinaA; j++)
			scanf("%lf",&nizA[i][j]);
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirinaB, &visinaB );
	
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < visinaB; i++)
		for (j = 0; j < sirinaB; j++)
			scanf("%lf",&nizB[i][j]);
	
	for (i = 0; i < sirinaA; i++)
		for (j = visinaA-1; j >= 0; j--)
			temp[i][visinaA-j-1]=nizA[j][i];

	
	if((visinaA!=sirinaB)||(sirinaA!=visinaB))
	{
		printf("NE");
		return 1;
	}
	
	for (i = 0; i < visinaB; i++) {
		for (j = 0; j < sirinaB; j++) {
			if (fabs(nizB[i][j]-temp[i][j])>=e)
			{
				printf("NE");
				return 1;
			}
		}
	}
	
	printf("DA");
	
	return 0;
}
