#include <stdio.h>

int main() {
	int matricaA[10][10], matricaB[10][10], i, j, sirinaA, sirinaB, visinaA, visinaB;
	
	/*unosi matricu A*/
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirinaA, &visinaA);
	
	printf("Unesite clanove matrice A: ");
	
	for(i=0; i<visinaA; i++)
	{
		for(j=0; j<sirinaA; j++)
		{
			scanf("%d", &matricaA[i][j]);
		}
	}
	
	/*unosi matricu B*/
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirinaB, &visinaB);
	
	printf("Unesite clanove matrice B: ");
	
	for(i=0; i<visinaB; i++)
	{
		for(j=0; j<sirinaB; j++)
		{
			scanf("%d", &matricaB[i][j]);
		}
	}
	
	if(sirinaA!=visinaB || sirinaB!=visinaA)
	{
		printf("NE\n");
		return 0;
	}
	
	for(i=0; i<visinaA; i++)
	{
		for(j=0; j<sirinaA; j++)
		{
			if(matricaA[i][j]!=matricaB[j][sirinaB-1-i])
			{
			printf("NE\n");
			return 0;
			}
		}
	}
	
	printf("DA\n");
	return 0;
}
