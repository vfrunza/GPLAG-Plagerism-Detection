#include <stdio.h>
#include <math.h>
#define eps 0.0001
int main()
{
	int sirinaA;
	int sirinaB;
	int visinaA;
	int visinaB;
	int i;
	int j;
	double nizA[100][100];
	double nizB[100][100];

	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirinaA,&visinaA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visinaA; i++) {
		for(j=0; j<sirinaA; j++) {
			scanf("%lf",&nizA[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sirinaB,&visinaB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visinaB; i++) {
		for(j=0; j<sirinaB; j++) {
			scanf("%lf",&nizB[i][j]);
		}
	}
	if(visinaA!=sirinaB || sirinaA!=visinaB) {
		printf("NE\n");
		return 1;

	} else {
		for(i=0; i<visinaB; i++) {

			for(j=0; j<sirinaB; j++) {
				if(fabs(nizA[visinaA-j-1][i]-nizB[i][j])>eps) {
					printf("NE\n");
					return 1;
				}
			}
		}
	}
	printf("DA\n");

	return 0;
}
