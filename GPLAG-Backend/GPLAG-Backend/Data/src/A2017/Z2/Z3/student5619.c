#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
int main()
{
	int i,j,sirinaA,sirinaB,visinaA,visinaB,temp=0;
	float matricaA[100][100],matricaB[100][100],rotiranamatricaA[100][100]={{0}};
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sirinaA,&visinaA);
	printf("Unesite clanove matrice A: ");
	for (i=0; i<sirinaA; i++)
		for (j=0; j<visinaA; j++) {
			scanf("%f",&matricaA[i][j]);
		}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sirinaB,&visinaB);
	printf("Unesite clanove matrice B: ");
	for (i=0; i<sirinaB; i++)
		for (j=0; j<visinaB; j++) {
			scanf("%f",&matricaB[i][j]);
		}
	if (visinaA==sirinaB && visinaB==sirinaA)
	{
	for (i=0; i<visinaA; i++) {
		for (j=0; j<sirinaA; j++) {
			rotiranamatricaA[i][j]=matricaA[sirinaA-j-1][i];
		}
	}
	for (i=0; i<sirinaB; i++) {
		for (j=0; j<visinaB; j++) {
			if (fabs(matricaB[i][j]-rotiranamatricaA[i][j])>epsilon) temp=1;
		}
		if (temp==1) break;
	}
	if (temp==0) printf("DA\n");
	else printf("NE\n");
	}
	return 0;
}
