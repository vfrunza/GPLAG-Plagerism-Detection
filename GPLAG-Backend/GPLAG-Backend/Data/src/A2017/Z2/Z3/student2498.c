#include <stdio.h>

int main() {
	int sirinaA,visinaA,sirinaB,visinaB,i,j,nizA[100][100],nizB[100][100];
	int k=1;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sirinaA,&visinaA);
	printf("Unesite clanove matrice A: ");
	
	
	for(i=0;i<visinaA;i++)
	{
		for(j=0;j<sirinaA;j++)
		{
			scanf("%d",&nizA[i][j]);	
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sirinaB,&visinaB);
	
	
	
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visinaB;i++)
	{
		for(j=0;j<sirinaB;j++)
		{
			scanf("%d",&nizB[i][j]);
		}
	}
	
	
	
	if((visinaA==visinaB && sirinaA==sirinaB) || (visinaA==sirinaB && sirinaA==visinaB))
	{
		for(i=0;i<visinaA;i++)
			{
				for(j=0;j<sirinaA;j++)
				{	
					if(nizA[i][j]!=nizB[j][sirinaB-i-1]) 
					{	
						k=0;
					}	
				}		
			}	
	}			
	else k=0;			

	
	 if(k==1)
		printf("DA\n");
	else
		printf("NE\n");
		
	return 0;
}
