#include <stdio.h>
int main()
{
	int sirinaA, visinaA, sirinaB, visinaB, matricaA[100][100], matricaB[100][100], i, j;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirinaA, &visinaA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visinaA; i++) {
		for(j=0; j<sirinaA; j++) {
			scanf("%d", &matricaA[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirinaB, &visinaB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visinaB; i++) {
		for(j=0; j<sirinaB; j++) {
			scanf("%d", &matricaB[i][j]);
		}
	}
	if(sirinaA!=visinaB || sirinaB!=visinaA) {
		printf("NE");
		return 0;
	} 
		for(j=0; j<visinaA; j++) {
			for(i=0; i<sirinaA; i++) {
				if(matricaA[j][i]!=matricaB[i][sirinaB-j-1]) {
					printf("NE");
					return 0;
				}
			}
		}
		printf("DA");
	
	return 0;
}
